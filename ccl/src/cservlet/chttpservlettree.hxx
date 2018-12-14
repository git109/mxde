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
 *   File: chttpservlettree.hxx
 *
 * Author: $author$
 *   Date: 10/26/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPSERVLETTREE_HXX
#define _CHTTPSERVLETTREE_HXX

#include "cavltreet.hxx"
#include "ccharstring.hxx"
#include "chttpservletinterface.hxx"

class cHttpServletBranch;

/**
 **********************************************************************
 *  Class: cHttpServletTree
 *
 * Author: $author$
 *   Date: 10/26/2004
 **********************************************************************
 */
class cHttpServletTree
: public cAVLTreeT
  <const char*, cHttpServletBranch, cHttpServletTree>
{
public:
    typedef cAVLTreeT
    <const char*, cHttpServletBranch, cHttpServletTree> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpServletTree
     *
     *      Author: $author$
     *        Date: 10/26/2004
     **********************************************************************
     */
    cHttpServletTree() 
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttpServletBranch
 *
 * Author: $author$
 *   Date: 10/26/2004
 **********************************************************************
 */
class cHttpServletBranch
: public cAVLTreeBranchT<cHttpServletBranch>
{
public:
    typedef cAVLTreeBranchT<cHttpServletBranch> cIs;

    cCharString m_name;
    cHttpServletTree m_sub_tree;
    cHttpServletInterface *m_servlet;

    /**
     **********************************************************************
     * Constructor: cHttpServletBranch
     *
     *      Author: $author$
     *        Date: 10/26/2004
     **********************************************************************
     */
    cHttpServletBranch
    (cHttpServletInterface *servlet=0,
     const char *name=0, int length=-1)
    : m_servlet(servlet)
    {
        eError error;

        if (name)
        if (0 > (length = m_name.SetChars(name, length)))
            throw(error = -length);
    }

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    int Compare(cHttpServletBranch &branch) const
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
     *     Date: 10/26/2004
     **********************************************************************
     */
    int Compare(const char *name) const
    {
        int length2, unequal = -1;
        const char *name2;

        if ((name2 = GetName(length2)))
            unequal = strcmp(name, name2);

        return unequal;
    }
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 12/10/2004
     **********************************************************************
     */
    int SetName(const char* chars, int length=-1)
    {
        length = m_name.SetChars(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    const char* GetName(int &length) const
    {
        const char* chars = m_name.GetChars(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetServlet
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    cHttpServletInterface* SetServlet
    (cHttpServletInterface *servlet) 
    {
        m_servlet = servlet;
        return m_servlet;
    }
    /**
     **********************************************************************
     * Function: GetServlet
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    cHttpServletInterface* GetServlet() const
    {
        return m_servlet;
    }

    /**
     **********************************************************************
     * Function: GetSubTree
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    cHttpServletTree& GetSubTree() 
    {
        return m_sub_tree;
    }
};

#endif /* ndef _CHTTPSERVLETTREE_HXX */
