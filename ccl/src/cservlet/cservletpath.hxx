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
 *   File: cservletpath.hxx
 *
 * Author: $author$
 *   Date: 4/17/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSERVLETPATH_HXX
#define _CSERVLETPATH_HXX

#include "chttpservlet.hxx"
#include "cservletpathinterface.hxx"

/**
 **********************************************************************
 *  Class: cServletPathItem
 *
 * Author: $author$
 *   Date: 11/23/2004
 **********************************************************************
 */
class cServletPathItem
: public cListItemT<cServletPathItem>
{
public:
    typedef cListItemT<cServletPathItem> cIs;

    cServletPathInterface &m_servlet_path;

    /**
     **********************************************************************
     * Constructor: cServletPathItem
     *
     *      Author: $author$
     *        Date: 11/23/2004
     **********************************************************************
     */
    cServletPathItem(cServletPathInterface &servlet_path)
    : m_servlet_path(servlet_path)
    {
    }
};

/**
 **********************************************************************
 *  Class: cServletPathList
 *
 * Author: $author$
 *   Date: 11/23/2004
 **********************************************************************
 */
class cServletPathList
: public cListT
  <cServletPathItem, cServletPathList>
{
public:
    typedef cListT
    <cServletPathItem, cServletPathList> cIs;
};


/**
 **********************************************************************
 *  Class: cServletPathBranch
 *
 * Author: $author$
 *   Date: 11/23/2004
 **********************************************************************
 */
class cServletPathBranch
: public cAVLTreeBranchT<cServletPathBranch>
{
public:
    typedef cAVLTreeBranchT<cServletPathBranch> cIs;

    cServletPathInterface &m_servlet_path;
    cCharString m_name;

    /**
     **********************************************************************
     * Constructor: cServletPathBranch
     *
     *      Author: $author$
     *        Date: 11/23/2004
     **********************************************************************
     */
    cServletPathBranch
    (cServletPathInterface &servlet_path, 
     const char* name, int namelen=-1)
    : m_servlet_path(servlet_path)
    {
        eError error;

        if (name)
        if (0 > (namelen = m_name.SetChars(name, namelen)))
            throw(error = -namelen);
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int Compare(cServletPathBranch &branch) const
    {
        int length1, length2, unequal = -1;
        const char *name1,*name2;

        if ((name1 = branch.GetName(length1)))
        if ((name2 = GetName(length2)))
            unequal = strcmp(name1, name2);

        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int Compare(const char* name) const
    {
        int length2, unequal = -1;
        const char *name2;

        if ((name2 = GetName(length2)))
            unequal = strcmp(name, name2);

        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    const char* GetName(int &length) const
    {
        const char* name = m_name.GetChars(length);
        return name;
    }
};

/**
 **********************************************************************
 *  Class: cServletPathTree
 *
 * Author: $author$
 *   Date: 11/23/2004
 **********************************************************************
 */
class cServletPathTree
: public cAVLTreeT
  <const char*, cServletPathBranch, cServletPathTree>
{
public:
    typedef cAVLTreeT
    <const char*, cServletPathBranch, cServletPathTree> cIs;
};

#endif /* _CSERVLETPATH_HXX */