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
 *   File: cavltree.hxx
 *
 * Author: $author$
 *   Date: 10/7/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CAVLTREE_HXX
#define _CAVLTREE_HXX

#include "cbinarytreet.hxx"

/**
 **********************************************************************
 *  Class: cAVLTreeBranchT
 *
 * Author: $author$
 *   Date: 10/7/2004
 **********************************************************************
 */
template <class TAs,class TIs=cBinaryTreeBranchT<TAs> >
class cAVLTreeBranchT
: public TIs
{
public:
    typedef TIs cIs;

    int m_balance;

    /**
     **********************************************************************
     * Constructor: cAVLTreeBranchT
     *
     *      Author: $author$
     *        Date: 10/7/2004
     **********************************************************************
     */
    cAVLTreeBranchT
    (int balance=0, TAs *tree=0, TAs *left=0, TAs *right=0) 
    : cIs(tree,left,right),
      m_balance(balance) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cAVLTreeT
 *
 * Author: $author$
 *   Date: 10/7/2004
 **********************************************************************
 */
template 
<class THas,class TOf,class TAs,
 class TIs=cBinaryTreeT<THas,TOf,TAs> >
class cAVLTreeT
: public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     * Constructor: cAVLTreeT
     *
     *      Author: $author$
     *        Date: 10/7/2004
     **********************************************************************
     */
    cAVLTreeT(TOf *root=0) 
    : cIs(root) 
    {
    }
    virtual void Print(TOf *root=0)
    {
    }
    /**
     **********************************************************************
     * Function: Insert
     *
     *   Author: $author$
     *     Date: 10/7/2004
     **********************************************************************
     */
    void Insert(TOf *branch)
    {
        TOf *tree;

        cIs::Insert(branch);

        Print();

        if ((tree = branch->GetTree()))
        do
        {
            if (tree->GetLeft() != branch)
                ++tree->m_balance;
            else --tree->m_balance;

            if (tree->m_balance>1)
            {
                if (tree->m_right->m_balance<0)
                    tree->m_right=Right(tree->m_right);

                tree=Left(tree);
            }
            else if (tree->m_balance<-1)
            {
                if (tree->m_left->m_balance>0)
                    tree->m_left=Left(tree->m_left);

                tree=Right(tree);
            }
            branch = tree;

            if (!(tree = branch->GetTree()))
            if (branch != GetRoot())
                m_root = branch;
        }
        while(tree);
    }
    /**
     **********************************************************************
     * Function: Left
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Perform AVL rotation left to adjust the tree.
     **********************************************************************
     */
    TOf *Left(TOf *tree)
    {
        TOf *right;

        if (tree)
        if ((right=tree->m_right))
        {
            if ((tree->m_right=right->m_left))
                tree->m_right->m_tree=tree;

            tree->m_balance=Balance(tree->m_right)
                           -Balance(tree->m_left);

            right->m_left=tree;
            right->m_tree=tree->m_tree;

            right->m_balance=Balance(right->m_right)
                            -Balance(right->m_left);

            tree->m_tree=right;

            return right;
        }

        return 0;
    }
    /**
     **********************************************************************
     * Function: Right
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Perform AVL rotation right to adjust the tree.
     **********************************************************************
     */
    TOf *Right(TOf *tree)
    {
        TOf *left;

        if (tree)
        if ((left=tree->m_left))
        {
            if ((tree->m_left=left->m_right))
                tree->m_left->m_tree=tree;

            tree->m_balance=Balance(tree->m_right)
                           -Balance(tree->m_left);

            left->m_right=tree;
            left->m_tree=tree->m_tree;

            left->m_balance=Balance(left->m_right)
                           -Balance(left->m_left);

            tree->m_tree=left;

            return left;
        }

        return 0;
    }
    /**
     **********************************************************************
     * Function: Balance
     *
     *   Author: $author$
     *     Date: 10/7/2004
     **********************************************************************
     */
    int Balance(TOf *tree) const
    {
        if (tree)
            if (tree->m_balance>0)
                return tree->m_balance+1;

            else if (tree->m_balance<0)
                    return -tree->m_balance+1;

        return 0;
    }
};

#endif /* ndef _CAVLTREE_HXX */
