/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: cxercesxmlchstreamt.hxx
 *
 * Author: $author$
 *   Date: 11/5/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXERCESXMLCHSTREAMT_HXX
#define _CXERCESXMLCHSTREAMT_HXX

#include <sax/InputSource.hpp>

#include "cstream.hxx"
#include "cstreamt.hxx"

/**
 **********************************************************************
 *  Class: cXercesXMLChStreamT
 *
 * Author: $author$
 *   Date: 11/5/2003
 **********************************************************************
 */
template <class TIs=cStream>
class cXercesXMLChStreamT
: public cStreamT<XMLCh, TIs>
{
public:
    typedef cStreamT<XMLCh, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cXercesXMLChStreamT
     *
     *      Author: $author$
     *        Date: 11/5/2003
     **********************************************************************
     */
    cXercesXMLChStreamT() 
    : cStreamT<XMLCh, TIs>() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXercesXMLChStreamT
     *
     *     Author: $author$
     *       Date: 11/5/2003
     **********************************************************************
     */
    virtual ~cXercesXMLChStreamT()
    {
    }

    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 11/5/2003
     **********************************************************************
     */
    virtual int Write(const XMLCh *buffer, int size=-1)
    {
        return cIs::Write(buffer, size);
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 11/5/2003
     **********************************************************************
     */
    virtual int Write(const char *buffer, int size=-1)
    {
        int i,count;
        XMLCh xmlch;

        if (size < 0)
            size = strlen(buffer);

        for (i = 0; i < size; i++)
        {
            xmlch = (unsigned char)buffer[i];

            if (1 > (count = Write(&xmlch, 1)))
                return -e_ERROR_WRITE;
        }

        return size;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 11/5/2003
     **********************************************************************
     */
    virtual int Copy(const char *buffer, int size=-1)
    {
        int count;

        if ((count = Clear()) < 0)
            return count;

        return Write(buffer, size);
    }
};

#endif
