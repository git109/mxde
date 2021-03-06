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
 *   File: ccharbufferinputstream.hxx
 *
 * Author: $author$
 *   Date: 11/3/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARBUFFERINPUTSTREAM_HXX
#define _CCHARBUFFERINPUTSTREAM_HXX

#include "cinputstreaminterface.hxx"
#include "ccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cCharBufferInputStream
 *
 * Author: $author$
 *   Date: 11/3/2004
 **********************************************************************
 */
class cCharBufferInputStream
: virtual public cInputStreamInterface,
  virtual public cInputStreamImplement,
  public cImplement
{
public:
    typedef cImplement cIs;

    cCharBuffer &m_buffer;

    /**
     **********************************************************************
     * Constructor: cCharBufferInputStream
     *
     *      Author: $author$
     *        Date: 11/3/2004
     **********************************************************************
     */
    cCharBufferInputStream(cCharBuffer &buffer) 
    : m_buffer(buffer) 
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual int Read(BYTE *buf,  int len=-1) 
    {
        int result = m_buffer.Read((char*)buf, len);
        return result;
    }
};

#endif /* ndef _CCHARBUFFERINPUTSTREAM_HXX */
