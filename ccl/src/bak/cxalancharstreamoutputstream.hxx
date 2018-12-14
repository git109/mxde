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
 *   File: cxalancharstreamoutputstream.hxx
 *
 * Author: $author$
 *   Date: 11/20/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXALANCHARSTREAMOUTPUTSTREAM_HXX
#define _CXALANCHARSTREAMOUTPUTSTREAM_HXX

#include <PlatformSupport/XalanOutputStream.hpp>

#include "ccharstreaminterface.hxx"
#include "nsxalan.hxx"

/**
 **********************************************************************
 *  Class: cXalanCharStreamOutputStream
 *
 * Author: $author$
 *   Date: 11/20/2003
 **********************************************************************
 */
class cXalanCharStreamOutputStream
: public nsXalan::XalanOutputStream
{
public:
    typedef nsXalan::XalanOutputStream cIs;

    cCharStreamInterface &m_stream;

    /**
     **********************************************************************
     * Constructor: cXalanCharStreamOutputStream
     *
     *      Author: $author$
     *        Date: 11/20/2003
     **********************************************************************
     */
    cXalanCharStreamOutputStream(cCharStreamInterface &stream) 
    : m_stream(stream) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXalanCharStreamOutputStream
     *
     *     Author: $author$
     *       Date: 11/20/2003
     **********************************************************************
     */
    virtual ~cXalanCharStreamOutputStream()
    {
    }

    /**
     **********************************************************************
     * Function: writeData
     *
     *   Author: $author$
     *     Date: 11/20/2003
     **********************************************************************
     */
    virtual void writeData
    (const char *theBuffer, size_type theBufferLength)
    {
        m_stream.Write(theBuffer, theBufferLength);
    }
    /**
     **********************************************************************
     * Function: doFlush
     *
     *   Author: $author$
     *     Date: 11/20/2003
     **********************************************************************
     */
    virtual void doFlush()
    {
        m_stream.Flush();
    }
};

#endif
