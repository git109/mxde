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
 *   File: cbytefilet.hxx
 *
 * Author: $author$
 *   Date: 2/3/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTEFILET_HXX
#define _CBYTEFILET_HXX

#include "cfilet.hxx"
#include "cbytestream.hxx"
#include "cbytestreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cBYTEFileT
 *
 * Author: $author$
 *   Date: 2/3/2005
 **********************************************************************
 */
template<class TIs=cBYTEStream>
class cBYTEFileT
: virtual public cBYTEStreamInterface,
  public cFileT<BYTE, TIs>
{
public:
    typedef cFileT<BYTE, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cBYTEFileT
     *
     *      Author: $author$
     *        Date: 2/3/2005
     **********************************************************************
     */
    cBYTEFileT(FILE *handle=NULL, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cBYTEFileT
     *
     *      Author: $author$
     *        Date: 2/3/2005
     **********************************************************************
     */
    cBYTEFileT(const char *path) 
    : cIs(path) 
    {
    }
    /**
     **********************************************************************
     * Function: GetLength
     *
     *   Author: $author$
     *     Date: 9/8/2005
     **********************************************************************
     */
    virtual long GetLength() const
    {
        int err;
        struct stat st;

        if (m_handle)
        {
            if ((err = fstat(fileno(m_handle), &st)))
                return -e_ERROR_FAILED;

            return st.st_size;
        }
        return -e_ERROR_NOT_ATTACHED;
    }
    /**
     **********************************************************************
     * Function: Seek
     *
     * Author: $author$
     * Date:   9/8/2005
     **********************************************************************
     */
    virtual long Seek(long offset, int origin=e_SEEK_SET)
    {
        long told = 0;
        int err;

        if (m_handle)
        {
            if ((err = fseek
                (m_handle, offset, OriginToPlatform(origin))))
                return -e_ERROR_FAILED;

            told = ftell(m_handle);
            return told;
        }
        return -e_ERROR_NOT_ATTACHED;
    }
};

#endif /* _CBYTEFILET_HXX */