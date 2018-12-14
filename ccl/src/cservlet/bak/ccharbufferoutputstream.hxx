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
 *   File: ccharbufferoutputstream.hxx
 *
 * Author: $author$
 *   Date: 11/14/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARBUFFEROUTPUTSTREAM_HXX
#define _CCHARBUFFEROUTPUTSTREAM_HXX

#include "coutputstreaminterface.hxx"
#include "ccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cCharBufferOutputStream
 *
 * Author: $author$
 *   Date: 11/14/2004
 **********************************************************************
 */
class cCharBufferOutputStream
: virtual public cOutputStreamInterface,
  virtual public cOutputStreamImplement,
  public cImplement
{
public:
    typedef cImplement cIs;

    cCharBuffer &m_buffer;

    /**
     **********************************************************************
     * Constructor: cCharBufferOutputStream
     *
     *      Author: $author$
     *        Date: 11/14/2004
     **********************************************************************
     */
    cCharBufferOutputStream(cCharBuffer &buffer) 
    : m_buffer(buffer) 
    {
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 11/14/2004
     **********************************************************************
     */
    virtual int Write(const BYTE *buf,  int len=-1) 
    {
        int result = m_buffer.Write((char*)buf, len);
        return result;
    }
};

#endif /* ndef _CCHARBUFFEROUTPUTSTREAM_HXX */
