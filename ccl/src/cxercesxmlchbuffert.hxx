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
 *   File: cxercesxmlchbuffert.hxx
 *
 * Author: $author$
 *   Date: 11/5/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXERCESXMLCHBUFFERT_HXX
#define _CXERCESXMLCHBUFFERT_HXX

#include "cbuffert.hxx"
#include "cxercesxmlchstreamt.hxx"

/**
 **********************************************************************
 *  Class: cXercesXMLChBufferT
 *
 * Author: $author$
 *   Date: 11/5/2003
 **********************************************************************
 */
template <int VDefaultSize, class TIs=cXercesXMLChStreamT<cStream> >
class cXercesXMLChBufferT
: public cBufferT<VDefaultSize, XMLCh, 0, TIs>
{
public:
    typedef cBufferT<VDefaultSize, XMLCh, 0, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cXercesXMLChBufferT
     *
     *      Author: $author$
     *        Date: 11/5/2003
     **********************************************************************
     */
    cXercesXMLChBufferT
    (const XMLCh *buffer=0, int size=-1, int length=-1) 
    : cIs(buffer, size, length) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cXercesXMLChBufferT
     *
     *      Author: $author$
     *        Date: 11/5/2003
     **********************************************************************
     */
    cXercesXMLChBufferT
    (const char *buffer, int length=-1) 
    {
        eError error;

        if (0 > (length = Write(buffer, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Destructor: ~cXercesXMLChBufferT
     *
     *     Author: $author$
     *       Date: 11/5/2003
     **********************************************************************
     */
    virtual ~cXercesXMLChBufferT()
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
    virtual int Write(const char *buffer, int size=-1)
    {
        return TIs::Write(buffer, size);
    }
    /**
     **********************************************************************
     * Function: operator const XMLCh*
     *
     *   Author: $author$
     *     Date: 11/5/2003
     **********************************************************************
     */
    virtual operator const XMLCh*() const
    {
        return m_read_buffer;
    }
};

#endif
