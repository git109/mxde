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
 *   File: cbytebufferoutputstream.hxx
 *
 * Author: $author$
 *   Date: 11/14/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTEBUFFEROUTPUTSTREAM_HXX
#define _CBYTEBUFFEROUTPUTSTREAM_HXX

#include "coutputstreaminterface.hxx"
#include "cbytebuffer.hxx"

/**
 **********************************************************************
 *  Class: cBYTEBufferOutputStream
 *
 * Author: $author$
 *   Date: 11/14/2004
 **********************************************************************
 */
class cBYTEBufferOutputStream
: public cImplement
{
public:
    typedef cImplement cIs;

    cBYTEBuffer &m_buffer;

    /**
     **********************************************************************
     * Constructor: cBYTEBufferOutputStream
     *
     *      Author: $author$
     *        Date: 11/14/2004
     **********************************************************************
     */
    cBYTEBufferOutputStream() 
    : cImplement() 
    {
    }
};

#endif /* ndef _CBYTEBUFFEROUTPUTSTREAM_HXX */
