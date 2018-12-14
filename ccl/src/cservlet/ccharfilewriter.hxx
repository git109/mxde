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
 *   File: ccharfilewriter.hxx
 *
 * Author: $author$
 *   Date: 6/30/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARFILEWRITER_HXX
#define _CCHARFILEWRITER_HXX

#include "ccharwriter.hxx"
#include "cfilehandle.hxx"

/**
 **********************************************************************
 *  Class: cCharFileWriter
 *
 * Author: $author$
 *   Date: 6/30/2005
 **********************************************************************
 */
class cCharFileWriter
: virtual public cCharWriterInterface,
  virtual public cCharWriterImplement,
  public cFileHandleInstance
{
public:
    typedef cFileHandleInstance cIs;

    /**
     **********************************************************************
     * Constructor: cCharFileWriter
     *
     *      Author: $author$
     *        Date: 6/30/2005
     **********************************************************************
     */
    cCharFileWriter(FILE* handle=NULL) 
    : cIs(handle) 
    {
    }

    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 6/30/2005
     **********************************************************************
     */
    virtual int Write(const char *buf,  int len=-1) 
    {
        int result = -e_ERROR_FAILED;

        if (NULL != m_handle)
        if (0 <= (len = fwrite(buf, 1, len, m_handle)))
            result = len;

        return result;
    }
};

#endif /* _CCHARFILEWRITER_HXX */