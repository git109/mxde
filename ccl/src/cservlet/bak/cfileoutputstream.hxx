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
 *   File: cfileoutputstream.hxx
 *
 * Author: $author$
 *   Date: 10/27/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEOUTPUTSTREAM_HXX
#define _CFILEOUTPUTSTREAM_HXX

#include "coutputstreaminterface.hxx"
#include "cfilehandle.hxx"

/**
 **********************************************************************
 *  Class: cFileOutputStream
 *
 * Author: $author$
 *   Date: 10/27/2004
 **********************************************************************
 */
class cFileOutputStream
: virtual public cOutputStreamInterface,
  virtual public cOutputStreamImplement,
  public cFileHandleT<cImplement>
{
public:
    typedef cFileHandleT<cImplement> cIs;

    /**
     **********************************************************************
     * Constructor: cFileOutputStream
     *
     *      Author: $author$
     *        Date: 10/27/2004
     **********************************************************************
     */
    cFileOutputStream(FILE* handle=NULL) 
    : cIs(handle) 
    {
    }
    /**
     **********************************************************************
     * Function: Flush
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    virtual int Flush() 
    {
        int err, result = -e_ERROR_FAILED;

        if (NULL != m_handle)
        if (!(err = fflush(m_handle)))
            result = err;

        return result;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    virtual int Write(const BYTE *buf, int len=-1)
    {
        int result = -e_ERROR_FAILED;

        if (0 > len)
            len = strlen((const char*)buf);

        if (NULL != m_handle)
        if (0 <= (len = fwrite(buf, 1, len, m_handle)))
            result = len;

        return result;
    }
};

#endif /* ndef _CFILEOUTPUTSTREAM_HXX */
