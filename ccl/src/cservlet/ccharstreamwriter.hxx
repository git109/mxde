/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: ccharstreamwriter.hxx
 *
 * Author: $author$
 *   Date: 7/2/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARSTREAMWRITER_HXX
#define _CCHARSTREAMWRITER_HXX

#include "ccharwriter.hxx"
#include "ccharstream.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cCharStreamWriter
 *
 * Author: $author$
 *   Date: 7/2/2005
 **********************************************************************
 */
class cCharStreamWriter
: virtual public cInitializeImplement,
  virtual public cPutcImplement,
  virtual public cCharWriterImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    cCharStreamInterface &m_stream;

    /**
     **********************************************************************
     * Constructor: cCharStreamWriter
     *
     *      Author: $author$
     *        Date: 7/2/2005
     **********************************************************************
     */
    cCharStreamWriter(cCharStreamInterface &stream) 
    : m_stream(stream)
    {
    }

    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 7/2/2005
     **********************************************************************
     */
    virtual int Write(const char *buf, int len=-1) 
    {
        int result = -e_ERROR_FAILED;

        if (0 <= (len = m_stream.Write(buf, len)))
            result = len;

        return result;
    }
};

#endif /* _CCHARSTREAMWRITER_HXX */