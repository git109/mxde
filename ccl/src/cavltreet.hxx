/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: cavltreet.hxx
 *
 * Author: $author$
 *   Date: 7/7/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CAVLTREET_HXX
#define _CAVLTREET_HXX

#include "cbinarytreet.hxx"

/**
 **********************************************************************
 *  Class: cAVLTreeBranchT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
template <class TAs,class TIs=cBinaryTreeTBase>
class cAVLTreeBranchT
: public cBinaryTreeBranchT<TAs,TIs>
{
public:
    typedef cBinaryTreeBranchT<TAs,TIs> cIs;

    int m_depth;

    /**
     **********************************************************************
     * Constructor: cAVLTreeBranchT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cAVLTreeBranchT
    (int depth=1, TAs *tree=0, TAs *left=0, TAs *right=0) 
    : cIs(tree,left,right),
      m_depth(depth)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cAVLTreeBranchT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cAVLTreeBranchT()
    {
    }
};

/**
 **********************************************************************
 *  Class: cAVLTreeT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
template <class THas,class TOf,class TAs,class TIs=cBinaryTreeTBase>
class cAVLTreeT
: public cBinaryTreeT<THas,TOf,TAs,TIs>
{
public:
    typedef cBinaryTreeT<THas,TOf,TAs,TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cAVLTreeT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cAVLTreeT(TOf *root=0) 
    : cIs(root) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cAVLTreeT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cAVLTreeT()
    {
    }

    /**
     **********************************************************************
     * Function: Insert
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Insert an item into the tree and return the root.
     *
     **********************************************************************
     */
    TOf *Insert(TOf *branch)
    {
        branch->m_left=0;
        branch->m_right=0;
        return this->m_root=Inserted(this->m_root,branch);
    }
    /**
     **********************************************************************
     * Function: Delete
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Delete an item from the tree and return the root.
     *
     **********************************************************************
     */
    TOf *Delete(TOf *branch)
    {
        return this->m_root=Deleted(this->m_root,branch);
    }

protected:

    /**
     **********************************************************************
     * Function: Inserted
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Perform recursive AVL insertion of an item into the
     * current subtree. Return the new root of the subtree.
     * 
     **********************************************************************
     */
    TOf *Inserted(TOf *tree,TOf *branch)
    {
        if (tree==0)
            return branch;

        if (branch!=0)
        if (branch->Compare(*tree)<0)
        {
            tree->m_left=Inserted(tree->m_left,branch);
            tree->m_left->m_tree=tree;
            if (Depth(tree->m_left)-Depth(tree->m_right)>1)
            {
                if (Depth(tree->m_left->m_right)
                    >Depth(tree->m_left->m_left))
                    tree->m_left=Left(tree->m_left);
                return Right(tree);
            }
            else tree->m_depth=tree->m_left->m_depth+1;
        }
        else
        {
            tree->m_right=Inserted(tree->m_right,branch);
            tree->m_right->m_tree=tree;
            if (Depth(tree->m_right)-Depth(tree->m_left)>1)
            {
                if (Depth(tree->m_right->m_left)
                    >Depth(tree->m_right->m_right))
                    tree->m_right=Right(tree->m_right);
                return Left(tree);
            }
            else tree->m_depth=tree->m_right->m_depth+1;
        }

        return tree;
    }
    /**
     **********************************************************************
     * Function: Deleted
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Perform recursive AVL deletion of an item from the
     * current subtree. Return the new root of the subtree.
     *
     **********************************************************************
     */
    TOf *Deleted(TOf *tree,TOf *branch)
    {
        int c;

        if ((tree==0)||(branch==0))
            return tree;

        if ((c=branch->Compare(*tree))>0)
        {
            tree->m_right=Deleted(tree->m_right,branch);
            if (Depth(tree->m_left)-Depth(tree->m_right)>1)
            {
                if (Depth(tree->m_left->m_right)
                    >Depth(tree->m_left->m_left))
                    tree->m_left=Left(tree->m_left);
                tree=Right(tree);
            }
            else tree->m_depth=NewDepth(tree);
        }
        else if (c<0)
        {
            tree->m_left=Deleted(tree->m_left,branch);
            if (Depth(tree->m_right)-Depth(tree->m_left)>1)
            {
                if (Depth(tree->m_right->m_left)
                    >Depth(tree->m_right->m_right))
                    tree->m_right=Right(tree->m_right);
                tree=Left(tree);
            }
            else tree->m_depth=NewDepth(tree);
        }
        else if (branch->m_depth>1)
        {
            if (Depth(branch->m_right)>Depth(branch->m_left))
                tree=Least(&branch->m_right);
            else tree=Greatest(&branch->m_left);
            tree->m_depth=NewDepth(branch);
            if ((tree->m_left=branch->m_left)!=0)
                tree->m_left->m_tree=tree;
            if ((tree->m_right=branch->m_right)!=0)
                tree->m_right->m_tree=tree;
        }
        else tree=0;

        return tree;
    }
    /**
     **********************************************************************
     * Function: Least
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Recusively raise the least item in the subtree to
     * the top of the tree.
     *
     **********************************************************************
     */
    TOf *Least(TOf **tree)
    {
        TOf *t;

        if ((*tree)->m_left!=0)
        {
            t=Least(&(*tree)->m_left);
            if (Depth((*tree)->m_right)-Depth((*tree)->m_left)>1)
            {
                if (Depth((*tree)->m_right->m_left)
                    >Depth((*tree)->m_right->m_right))
                    (*tree)->m_right=Right((*tree)->m_right);
                *tree=Left(*tree);
            }
            else (*tree)->m_depth=NewDepth(*tree);
        }
        else if ((*tree)->m_right!=0)
        {
            t=*tree;
            *tree=t->m_right;
        }
        else
        {
            t=*tree;
            *tree=0;
        }

        return t;
    }
    /**
     **********************************************************************
     * Function: Greatest
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Recusively raise the greatest item in the subtree to
     * the top of the tree.
     *
     **********************************************************************
     */
    TOf *Greatest(TOf **tree)
    {
        TOf *t;

        if ((*tree)->m_right!=0)
        {
            t=Greatest(&(*tree)->m_right);
            if (Depth((*tree)->m_left)-Depth((*tree)->m_right)>1)
            {
                if (Depth((*tree)->m_left->m_right)
                    >Depth((*tree)->m_left->m_left))
                    (*tree)->m_left=Left((*tree)->m_left);
                *tree=Right(*tree);
            }
            else (*tree)->m_depth=NewDepth(*tree);
        }
        else if ((*tree)->m_left!=0)
        {
            t=*tree;
            *tree=t->m_left;
        }
        else
        {
            t=*tree;
            *tree=0;
        }

        return t;
    }
    /**
     **********************************************************************
     * Function: Left
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Perform AVL rotation left to adjust the tree.
     *
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

            tree->m_depth=Depth(tree->m_left)+1;

            if (Depth(tree->m_right)>=tree->m_depth)
                tree->m_depth=tree->m_right->m_depth+1;

            right->m_depth=tree->m_depth+1;
            right->m_left=tree;
            right->m_tree=tree->m_tree;
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
     *
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

            tree->m_depth=Depth(tree->m_right)+1;

            if (Depth(tree->m_left)>=tree->m_depth)
                tree->m_depth=tree->m_left->m_depth+1;

            left->m_depth=tree->m_depth+1;
            left->m_right=tree;
            left->m_tree=tree->m_tree;
            tree->m_tree=left;

            return left;
        }

        return 0;
    }
    /**
     **********************************************************************
     * Function: NewDepth
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Return the new depth of tree.
     *
     **********************************************************************
     */
    int NewDepth(TOf *tree)
    {
        int ld,gd;

        if (tree!=0)
        if ((ld=Depth(tree->m_left))
            >(gd=Depth(tree->m_right)))
            return ld+1;
        else return gd+1;

        return 0;
    }
    /**
     **********************************************************************
     * Function: Depth
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    int Depth(TOf *tree) const
    {
        if (tree)
        if (tree->m_depth>0)
            return tree->m_depth;
        else return 1;

        return 0;
    }
};


#endif
