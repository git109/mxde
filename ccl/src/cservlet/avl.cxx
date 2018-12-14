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
 *   File: avl.cxx
 *
 * Author: $author$
 *   Date: 10/7/2004
 *
 *    $Id$
 **********************************************************************
 */

#include <stdio.h>
#include "cavltree.hxx"

/**
 **********************************************************************
 *  Class: cCharAVLTreeBranch
 *
 * Author: $author$
 *   Date: 10/7/2004
 **********************************************************************
 */
class cCharAVLTreeBranch
: public cAVLTreeBranchT<cCharAVLTreeBranch>
{
public:
    typedef cAVLTreeBranchT<cCharAVLTreeBranch> cIs;

    char m_leaf;

    /**
     **********************************************************************
     * Constructor: cCharAVLTreeBranch
     *
     *      Author: $author$
     *        Date: 10/7/2004
     **********************************************************************
     */
    cCharAVLTreeBranch(char leaf=0) 
    : m_leaf(leaf) 
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 10/7/2004
     **********************************************************************
     */
    int Compare(char to) 
    {
        int result = (m_leaf<to)?-1:(m_leaf>to)?1:0;
        return result;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 10/7/2004
     **********************************************************************
     */
    int Compare(cCharAVLTreeBranch &to) 
    {
        int result = (m_leaf<to.m_leaf)?-1:(m_leaf>to.m_leaf)?1:0;
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cCharAVLTree
 *
 * Author: $author$
 *   Date: 10/7/2004
 **********************************************************************
 */
class cCharAVLTree
: public cAVLTreeT<char, cCharAVLTreeBranch, cCharAVLTree>
{
public:
    typedef cAVLTreeT<char, cCharAVLTreeBranch, cCharAVLTree> cIs;

    /**
     **********************************************************************
     * Constructor: cCharAVLTree
     *
     *      Author: $author$
     *        Date: 10/7/2004
     **********************************************************************
     */
    cCharAVLTree(cCharAVLTreeBranch *root=0) 
    : cIs(root) 
    {
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 10/7/2004
     **********************************************************************
     */
    void Print(cCharAVLTreeBranch *root=0)
    {
        cCharAVLTreeBranch *b;

        if (!root)
        {
            printf("\n");
            root = m_root;
        }

        if ((b = root->GetLeft()))
        {
            printf("<-");
            Print(b);
        }

        printf("%c[%d]", root->m_leaf, root->m_balance);

        if ((b = root->GetRight()))
        {
            printf("->");
            Print(b);
        }
    }
};

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 10/7/2004
 **********************************************************************
 */
int main(int argc,const char **argv)
{
    const char c[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cCharAVLTreeBranch b[26];
    cCharAVLTree t;
    int i;

    for (i=25; i>=0; --i)
    {
        b[i].m_leaf = c[i];
        t.Insert(b+i);
        t.Print();
    }
    return 0;
}
