/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: random.cxx
 *
 * Author: $author$
 *   Date: 8/4/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "ccharstream.hxx"
#include "ccgimain.hxx"
#include <time.h>
#include <stdlib.h>

/**
 **********************************************************************
 *  Class: cPseudoRandomStream
 *
 * Author: $author$
 *   Date: 8/4/2004
 **********************************************************************
 */
class cPseudoRandomStream
: public cCharStream
{
public:
    typedef cCharStream cIs;

    unsigned m_random;
    unsigned m_remain;

    /**
     **********************************************************************
     * Constructor: cPseudoRandomStream
     *
     *      Author: $author$
     *        Date: 8/4/2004
     **********************************************************************
     */
    cPseudoRandomStream() 
    : m_remain(0)
    {
        time_t t;

        srand(time(&t));
    }
    /**
     **********************************************************************
     * Function: Getc
     *
     *   Author: $author$
     *     Date: 8/4/2004
     **********************************************************************
     */
    virtual int Getc()
    {
        unsigned char c;

        if (m_remain<1)
        {
            m_random=(unsigned)rand();
            m_remain=sizeof(m_random);
        }

        c=(m_random&255);
        m_random>>=8;
        --m_remain;
        return c;
    }
};

/**
 **********************************************************************
 *  Main: cRandomMain
 *
 * Author: $author$
 *   Date: 8/4/2004
 **********************************************************************
 */
class cRandomMain
: public cCGIMain
{
public:
    typedef cCGIMain cIs;

    const char *m_size_name;
    int m_size;

    /**
     **********************************************************************
     * Constructor: cRandomMain
     *
     *      Author: $author$
     *        Date: 8/4/2004
     **********************************************************************
     */
    cRandomMain() 
    : m_size_name("size"),
      m_size(32) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cRandomMain
     *
     *     Author: $author$
     *       Date: 8/4/2004
     **********************************************************************
     */
    virtual ~cRandomMain()
    {
    }
    /**
     **********************************************************************
     * Function: OnCommand
     *
     *   Author: $author$
     *     Date: 8/4/2004
     **********************************************************************
     */
    virtual int OnCommand()
    {
        return OnCommandOrCGI();
    }
    /**
     **********************************************************************
     * Function: OnCGI
     *
     *   Author: $author$
     *     Date: 8/4/2004
     **********************************************************************
     */
    virtual int OnCGI()
    {
        OutputContentType(GetContentTypeText());

        return OnCommandOrCGI();
    }
    /**
     **********************************************************************
     * Function: OnCommandOrCGI
     *
     *   Author: $author$
     *     Date: 8/4/2004
     **********************************************************************
     */
    virtual int OnCommandOrCGI()
    {
        int i,c,count;
        const char *value;
        cPseudoRandomStream prs;

        cHTTPForm::cField *field;

        if ((field = GetFirstFormFieldByName(m_size_name)))
        if ((value = field->GetValue()))
        if (value[0])
            m_size = atoi(value);

        for (i=0; i<m_size;)
        {
            if (0 < (c = prs.Getc()))
            if (0 < (count = m_out.Putx(c)))
                i++;
        }
        return 0;
    }
} g_random;

