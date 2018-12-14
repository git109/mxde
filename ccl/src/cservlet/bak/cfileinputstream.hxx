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
 *   File: cfileinputstream.hxx
 *
 * Author: $author$
 *   Date: 11/4/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEINPUTSTREAM_HXX
#define _CFILEINPUTSTREAM_HXX

#include "cinputstreaminterface.hxx"
#include "cfilehandle.hxx"

/**
 **********************************************************************
 *  Class: cFileInputStream
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
class cFileInputStream
: virtual public cInputStreamInterface,
  virtual public cInputStreamImplement,
  public cFileHandleT<cImplement>
{
public:
    typedef cFileHandleT<cImplement> cIs;

    /**
     **********************************************************************
     * Constructor: cFileInputStream
     *
     *      Author: $author$
     *        Date: 11/4/2004
     **********************************************************************
     */
    cFileInputStream(FILE* handle=NULL) 
    : cIs(handle) 
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual int Read
    (BYTE *buf,  int len=-1) 
    {
        int result = -e_ERROR_FAILED;

        if (0 > len)
            len = strlen((const char*)buf);

        if (NULL != m_handle)
        if (0 <= (len = fread(buf, 1, len, m_handle)))
            result = len;

        return result;
    }
};

#endif /* ndef _CFILEINPUTSTREAM_HXX */
