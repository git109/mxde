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
 *   File: ccontentstream.hxx
 *
 * Author: $author$
 *   Date: 8/17/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCONTENTSTREAM_HXX
#define _CCONTENTSTREAM_HXX

#include "ccharstream.hxx"
#include "ccontentinterface.hxx"

/**
 **********************************************************************
 *  Class: cContentStreamT
 *
 * Author: $author$
 *   Date: 8/17/2003
 **********************************************************************
 */
template <class TIs=cCharStream>
class cContentStreamT
: public TIs
{
public:
    typedef TIs cIs;

    cContentInterface &m_content;

    /**
     **********************************************************************
     * Constructor: cContentStreamT
     *
     *      Author: $author$
     *        Date: 8/17/2003
     **********************************************************************
     */
    cContentStreamT(cContentInterface &content) 
    : m_content(content) 
    {
    }

    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 8/17/2003
     **********************************************************************
     */
    virtual int Write(const char *buffer, int size=-1)
    {
        return m_content.Output(buffer, size);
    }
    /**
     **********************************************************************
     * Function: VPrintFormatted
     *
     *   Author: $author$
     *     Date: 11/22/2003
     **********************************************************************
     */
    virtual int VPrintFormatted(const char *format, va_list va)
    {
        return m_content.VOutputFormatted(format, va);
    }
};

/**
 **********************************************************************
 *  Class: cContentStream
 *
 * Author: $author$
 *   Date: 2/5/2004
 **********************************************************************
 */
class cContentStream
: public cContentStreamT<cCharStream>
{
public:
    typedef cContentStreamT<cCharStream> cIs;

    /**
     **********************************************************************
     * Constructor: cContentStream
     *
     *      Author: $author$
     *        Date: 2/5/2004
     **********************************************************************
     */
    cContentStream(cContentInterface &content) 
    : cIs(content) 
    {
    }
};

#endif
