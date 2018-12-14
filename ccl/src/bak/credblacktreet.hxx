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
 *   File: credblacktreet.hxx
 *
 * Author: $author$
 *   Date: 7/8/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CREDBLACKTREET_HXX
#define _CREDBLACKTREET_HXX

#include "cbinarytreet.hxx"

/**
 **********************************************************************
 *  Class: cRedBlackTreeBranchT
 *
 * Author: $author$
 *   Date: 7/8/2003
 **********************************************************************
 */
template <class TAs,class TIs=cBinaryTreeTBase>
class cRedBlackTreeBranchT
: public cBinaryTreeBranchT<TAs,TIs>
{
public:
    typedef cBinaryTreeBranchT<TAs,TIs> cIs;

    bool m_is_red;

    /**
     **********************************************************************
     * Constructor: cRedBlackTreeBranchT
     *
     *      Author: $author$
     *        Date: 7/8/2003
     **********************************************************************
     */
    cRedBlackTreeBranchT
    (bool is_red=false, TAs *tree=0, TAs *left=0, TAs *right=0) 
    : cIs(tree,left,right),
      m_is_red(is_red)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cRedBlackTreeBranchT
     *
     *     Author: $author$
     *       Date: 7/8/2003
     **********************************************************************
     */
    virtual ~cRedBlackTreeBranchT()
    {
    }
    /**
     **********************************************************************
     * Function: SetIsRed
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    inline bool SetIsRed(bool is_red=true)
    {
        return m_is_red=is_red;
    }
    /**
     **********************************************************************
     * Function: GetIsRed
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    inline bool GetIsRed() const
    {
        return m_is_red;
    }
};

/**
 **********************************************************************
 *  Class: cRedBlackTreeT
 *
 * Author: $author$
 *   Date: 7/8/2003
 **********************************************************************
 */
template <class THas,class TOf,class TAs,class TIs=cBinaryTreeTBase>
class cRedBlackTreeT
: public cBinaryTreeT<THas,TOf,TAs,TIs>
{
public:
    typedef cBinaryTreeT<THas,TOf,TAs,TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cRedBlackTreeT
     *
     *      Author: $author$
     *        Date: 7/8/2003
     **********************************************************************
     */
    cRedBlackTreeT(TOf *root=0) 
    : cIs(root) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cRedBlackTreeT
     *
     *     Author: $author$
     *       Date: 7/8/2003
     **********************************************************************
     */
    virtual ~cRedBlackTreeT()
    {
    }
    /**
     **********************************************************************
     * Function: Insert
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    void Insert(TOf *branch)
    {
        TOf *tree;

        cIs::Insert(branch);

        /* Balance the tree after the new branch has been inserted.
         */

        branch->SetIsRed();

        while ((branch != GetRoot()) 
               && (GetIsRed(branch->GetTree())))
        {
            if (branch->GetTree() 
                == branch->GetTree()->GetTree()->GetLeft())
             {
                tree = branch->GetTree()->GetTree()->GetRight();

                if (GetIsRed(tree))
                {
                    tree->SetIsRed(false);
                    branch->GetTree()->SetIsRed(false);
                    branch->GetTree()->GetTree()->SetIsRed();
                    branch = branch->GetTree()->GetTree();
                }
                else
                {
                    if (branch == branch->GetTree()->GetRight())
                    {
                        branch = branch->GetTree();
                        RotateLeft(branch);
                    }

                    branch->GetTree()->SetIsRed(false);
                    branch->GetTree()->GetTree()->SetIsRed();
                    RotateRight(branch->GetTree()->GetTree());
                }
            }
            else
            {
                tree = branch->GetTree()->GetTree()->GetLeft();

                if (GetIsRed(tree))
                {
                    tree->SetIsRed(false);
                    branch->GetTree()->SetIsRed(false);
                    branch->GetTree()->GetTree()->SetIsRed();
                    branch = branch->GetTree()->GetTree();
                }
                else
                {
                    if (branch == branch->GetTree()->GetLeft())
                    {
                        branch = branch->GetTree();
                        RotateRight(branch);
                    }

                    branch->GetTree()->SetIsRed(false);
                    branch->GetTree()->GetTree()->SetIsRed();
                    RotateLeft(branch->GetTree()->GetTree());
                }
            }
        }

        GetRoot()->SetIsRed(false);
    }
    /**
     **********************************************************************
     * Function: Delete
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    void Delete(TOf *branch)
    {
        TOf *next, *deleted, *child;

        /* find branch to splice out
         */
        if (!branch->GetLeft() || !branch->GetRight())
            deleted = branch;

        else deleted = GetNext(branch);

        /* find child with which to replace deleted
         */
        if (!(child = deleted->GetLeft()))
            child = deleted->GetRight();

        if (!deleted->GetTree())
            /* replace root
             */
            SetRoot(child);

        else
        {
            /* splice in child branch
             */
            if (deleted == deleted->GetTree()->GetLeft())
                deleted->GetTree()->SetLeft(child);

            else deleted->GetTree()->SetRight(child);
        }

        if (child)
            /* splice child onto parent
             */
            child->SetTree(deleted->GetTree());

        else child = deleted->GetTree();

        /* if needed, save deleted data
         */
        if (deleted != branch)
        {
            if ((next = deleted->SetTree(branch->GetTree())))
                if (next->GetRight() == branch)
                    next->SetRight(deleted);
                else next->SetLeft(deleted);

            if ((next = deleted->SetLeft(branch->GetLeft())))
                next->SetTree(deleted);

            if ((next = deleted->SetRight(branch->GetRight())))
                next->SetTree(deleted);

            deleted->SetIsRed(branch->GetIsRed());
        }

        /* adjust tree under red-black rules
         */
        if (child)
        {
            while ((child != GetRoot()) && (!child->GetIsRed()))
            {
                if (child->GetTree()->GetLeft() == child)
                {
                    next = child->GetTree()->GetRight();

                    if (GetIsRed(next))
                    {
                        next->SetIsRed(false);
                        child->GetTree()->SetIsRed();
                        RotateLeft(child->GetTree());
                        next = child->GetTree()->GetRight();
                    }

                    if (!next)
                        child = child->GetTree();

                    else if ((!GetIsRed(next->GetLeft()))
                             && (!GetIsRed(next->GetRight())))
                    {
                        next->SetIsRed();
                        child = child->GetTree();
                    }
                    else
                    {
                        if (!GetIsRed(next->GetRight()))
                        {
                            SetIsRed(next->GetLeft(),false);
                            next->SetIsRed();
                            RotateRight(next);
                            next = child->GetTree()->GetRight();
                        }

                        next->SetIsRed(child->GetTree()->GetIsRed());
                        SetIsRed(next->GetRight(),false);
                        child->GetTree()->SetIsRed(false);
                        RotateLeft(child->GetTree());
                        child = GetRoot();
                    }
                }
                else
                {
                    next = child->GetTree()->GetLeft();

                    if (GetIsRed(next))
                    {
                        next->SetIsRed(false);
                        child->GetTree()->SetIsRed();
                        RotateRight(child->GetTree());
                        next = child->GetTree()->GetLeft();
                    }

                    if (!next)
                        child = child->GetTree();

                    else if ((!GetIsRed(next->GetRight()))
                             && (!GetIsRed(next->GetLeft())))
                    {
                        next->SetIsRed();
                        child = child->GetTree();
                    }
                    else
                    {
                        if (!GetIsRed(next->GetLeft()))
                        {
                            SetIsRed(next->GetRight(),false);
                            next->SetIsRed();
                            RotateLeft(next);
                            next = child->GetTree()->GetLeft();
                        }

                        next->SetIsRed(child->GetTree()->GetIsRed());
                        SetIsRed(next->GetLeft(),false);
                        child->GetTree()->SetIsRed(false);
                        RotateRight(child->GetTree());
                        child = GetRoot();
                    }
                }
            }

            child->SetIsRed(false);
        }
    }

protected:

    /**
     **********************************************************************
     * Function: RotateLeft
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    void RotateLeft(TOf *branch)
    {
        TOf *right = branch->GetRight();

        /* turn right's left subtree into branch's right subtree
         */
        branch->SetRight(right->GetLeft());

        if (right->GetLeft())
            right->GetLeft()->SetTree(branch);

        /* link branch's parent to right
         */
        right->SetTree(branch->GetTree());

        if (!branch->GetTree())
            SetRoot(right);
        else
        {
            if (branch == branch->GetTree()->GetLeft())
                branch->GetTree()->SetLeft(right);
            else
                branch->GetTree()->SetRight(right);
        }

        /* put branch on right's left
         */
        right->SetLeft(branch);
        branch->SetTree(right);
    }
    /**
     **********************************************************************
     * Function: RotateRight
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    void RotateRight(TOf *branch)
    {
        TOf *left = branch->GetLeft();

        /* turn left's right subtree into branch's left subtree
         */
        branch->SetLeft(left->GetRight());

        if (left->GetRight())
            left->GetRight()->SetTree(branch);

        /* link branch's parent to left
         */
        left->SetTree(branch->GetTree());

        if (!branch->GetTree())
            SetRoot(left);
        else
        {
            if (branch == branch->GetTree()->GetRight())
                branch->GetTree()->SetRight(left);
            else
                branch->GetTree()->SetLeft(left);
        }

        /* put branch on left's right
         */
        left->SetRight(branch);
        branch->SetTree(left);
    }
    /**
     **********************************************************************
     * Function: SetIsRed
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    bool SetIsRed(TOf *branch,bool is_red=true)
    {
        if (branch)
            return branch->SetIsRed(is_red);
        return false;
    }
    /**
     **********************************************************************
     * Function: GetIsRed
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    bool GetIsRed(TOf *branch) const
    {
        if (branch)
            return branch->GetIsRed();
        return false;
    }
};

#endif
