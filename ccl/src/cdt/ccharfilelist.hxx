/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: ccharfilelist.hxx
 *
 * Author: $author$
 *   Date: 12/4/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CCHARFILELIST_HXX
#define _CCHARFILELIST_HXX

#include "ccharfile.hxx"

/**
 **********************************************************************
 *  Class: cCharFileItem
 *
 * Author: $author$
 *   Date: 3/5/2004
 **********************************************************************
 */
class cCharFileItem
: public cDynamicListItemT<cCharFileItem>
{
public:
    typedef cDynamicListItemT<cCharFileItem> cIs;

    cCharFile m_file;

    /**
     **********************************************************************
     * Constructor: cCharFileItem
     *
     *      Author: $author$
     *        Date: 3/5/2004
     **********************************************************************
     */
    cCharFileItem() 
    {
    }
    /**
     **********************************************************************
     * Function: GetFile
     *
     *   Author: $author$
     *     Date: 3/5/2004
     **********************************************************************
     */
    inline cCharFile &GetFile() 
    {
        return m_file;
    }
};

/**
 **********************************************************************
 *  Class: cCharFileList
 *
 * Author: $author$
 *   Date: 3/5/2004
 **********************************************************************
 */
class cCharFileList
: public cDynamicListT<cCharFileItem,cCharFileList>
{
public:
    typedef cDynamicListT<cCharFileItem,cCharFileList> cIs;
};

#endif /* _CCHARFILELIST_HXX */
