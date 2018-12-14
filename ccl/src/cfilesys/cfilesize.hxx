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
 *   File: cfilesize.hxx
 *
 * Author: $author$
 *   Date: 6/12/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILESIZE_HXX
#define _CFILESIZE_HXX

#include "cfilesizeimplement.hxx"

/**
 **********************************************************************
 *  Class: cFileSizeT
 *
 * Author: $author$
 *   Date: 6/12/2005
 **********************************************************************
 */
template
<class TIs=cInstance>
class cFileSizeT
: virtual public cFileSizeImplement,
  public TIs
{
public:
    typedef TIs cIs;

    LONGLONG m_file_size;

    /**
     **********************************************************************
     * Constructor: cFileSizeT
     *
     *      Author: $author$
     *        Date: 6/12/2005
     **********************************************************************
     */
    cFileSizeT(LONGLONG file_size=-1) 
    : m_file_size(file_size)
    {
    }
    /**
     **********************************************************************
     * Function: SetFileSize
     *
     *   Author: $author$
     *     Date: 6/12/2005
     **********************************************************************
     */
    virtual LONGLONG SetFileSize(LONGLONG size) 
    {
        return m_file_size = size;
    }
    /**
     **********************************************************************
     * Function: GetFileSize
     *
     *   Author: $author$
     *     Date: 6/12/2005
     **********************************************************************
     */
    virtual LONGLONG GetFileSize() const
    {
        return m_file_size;
    }
};

/**
 **********************************************************************
 *  Class: cFileSize
 *
 * Author: $author$
 *   Date: 6/12/2005
 **********************************************************************
 */
class cFileSize
: public cFileSizeT<cInstance>
{
public:
    typedef cFileSizeT<cInstance> cIs;

    /**
     **********************************************************************
     * Constructor: cFileSize
     *
     *      Author: $author$
     *        Date: 6/12/2005
     **********************************************************************
     */
    cFileSize(LONGLONG file_size=-1) 
    : cIs(file_size) 
    {
    }
};

#endif /* _CFILESIZE_HXX */