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
 *   File: ccharfilereader.hxx
 *
 * Author: $author$
 *   Date: 9/29/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARFILEREADER_HXX
#define _CCHARFILEREADER_HXX

#include "ccharreader.hxx"
#include "cfilehandle.hxx"

/**
 **********************************************************************
 *  Class: cCharFileReader
 *
 * Author: $author$
 *   Date: 9/29/2004
 **********************************************************************
 */
class cCharFileReader
: virtual public cCharReaderInterface,
  virtual public cCharReaderImplement,
  public cFileHandle
{
public:
    typedef cFileHandle cIs;

    /**
     **********************************************************************
     * Constructor: cCharFileReader
     *
     *      Author: $author$
     *        Date: 9/29/2004
     **********************************************************************
     */
    cCharFileReader(FILE* handle=NULL) 
    : cIs(handle) 
    {
    }
    /**
     **********************************************************************
     * Function: Reset
     *
     *   Author: $author$
     *     Date: 9/29/2004
     **********************************************************************
     */
    virtual int Reset()
    {
        int len, result = -e_ERROR_FAILED;

        if (NULL != m_handle)
        if (0 == (len = fseek(m_handle, 0, SEEK_SET)))
            result = len;

        return result;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 9/29/2004
     **********************************************************************
     */
    virtual int Read(char *buf, int len=-1)
    {
        int result = -e_ERROR_FAILED;

        if (NULL != m_handle)
        if (0 <= (len = fread(buf, 1, len, m_handle)))
            result = len;

        return result;
    }
};

#endif /* ndef _CCHARFILEREADER_HXX */
