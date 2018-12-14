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
 *   File: cbinarytreet.hxx
 *
 * Author: $author$
 *   Date: 7/7/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBINARYTREET_HXX
#define _CBINARYTREET_HXX

#include "cerror.h"

/**
 **********************************************************************
 *  Class: cBinaryTreeTBase
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
class cBinaryTreeTBase
{
public:
    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 7/7/2003
     **********************************************************************
     */
    enum
    {
        e_FIRST_ERROR=::e_NEXT_ERROR,
        e_NEXT_ERROR=e_FIRST_ERROR,
        e_LAST_ERROR=e_NEXT_ERROR-1
    };
};

/**
 **********************************************************************
 *  Class: cBinaryTreeBranchT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
template <class TAs,class TIs=cBinaryTreeTBase>
class cBinaryTreeBranchT
: public TIs
{
public:
    typedef TIs cIs;

    TAs *m_tree,*m_left,*m_right;

    /**
     **********************************************************************
     * Constructor: cBinaryTreeBranchT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cBinaryTreeBranchT
    (TAs *tree=0, TAs *left=0, TAs *right=0) 
    : m_tree(tree),
      m_left(left),
      m_right(right)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cBinaryTreeBranchT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cBinaryTreeBranchT()
    {
    }
    /**
     **********************************************************************
     * Function: SetTree
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TAs *SetTree(TAs *tree)
    {
        return m_tree=tree;
    }
    /**
     **********************************************************************
     * Function: GetTree
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TAs *GetTree() const
    {
        return m_tree;
    }
    /**
     **********************************************************************
     * Function: SetLeft
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TAs *SetLeft(TAs *left)
    {
        return m_left=left;
    }
    /**
     **********************************************************************
     * Function: GetLeft
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TAs *GetLeft() const
    {
        return m_left;
    }
    /**
     **********************************************************************
     * Function: SetRight
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TAs *SetRight(TAs *right)
    {
        return m_right=right;
    }
    /**
     **********************************************************************
     * Function: GetRight
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TAs *GetRight() const
    {
        return m_right;
    }
};

/**
 **********************************************************************
 *  Class: cBinaryTreeT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
template <class THas,class TOf,class TAs,class TIs=cBinaryTreeTBase>
class cBinaryTreeT
: public TIs
{
public:
    typedef TIs cIs;

    TOf *m_root;

    /**
     **********************************************************************
     * Constructor: cBinaryTreeT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cBinaryTreeT(TOf *root=0) 
    : m_root(root) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cBinaryTreeT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cBinaryTreeT()
    {
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Clear()
    {
        m_root=0;
    }
    /**
     **********************************************************************
     * Function: Insert
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Insert(TOf *branch)
    {
        TOf *next, *tree;
        int unequal;

        if (!(next=GetRoot()))
            SetRoot(branch);

        else
        {
            do
            {
                tree=next;

                if ((unequal = branch->Compare(*tree)) < 0)
                {
                    if (!(next=tree->GetLeft()))
                        tree->SetLeft(branch);
                }
                else
                {
                    if (!(next=tree->GetRight()))
                        tree->SetRight(branch);
                }
            }
            while(next);

            branch->SetTree(tree);
        }
    }
    /**
     **********************************************************************
     * Function: Delete
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Delete(TOf *branch)
    {
        TOf *next, *deleted;

        /* find branch to splice out
         */
        if (!branch->GetLeft() || !branch->GetRight())
            deleted = branch;

        else deleted = GetNext(branch);

        /* find next with which to replace deleted
         */
        if (!(next = deleted->GetLeft()))
            next = deleted->GetRight();

        if (next)
            /* splice next onto tree
             */
            next->SetTree(deleted->GetTree());

        if (!deleted->GetTree())
            /* replace root
             */
            SetRoot(next);

        else
        {
            /* splice in next branch
             */
            if (deleted == deleted->GetTree()->GetLeft())
                deleted->GetTree()->SetLeft(next);

            else deleted->GetTree()->SetRight(next);
        }

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
        }
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf *Find(unsigned &compares, const THas &leaf) const
    {
        TOf *branch;
        int unequal;
        unsigned count=0;

        if ((branch=GetRoot()))
        do
        {
            count++;

            if ((unequal = branch->Compare(leaf)) < 0)
                branch = branch->GetRight();

            else if (unequal > 0)
                    branch = branch->GetLeft();

            else break;
        }
        while(branch);

        compares = count;
        return branch;
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf *Find(const THas &leaf) const
    {
        TOf *branch;
        int unequal;

        if ((branch=GetRoot()))
        do
        {
            if ((unequal = branch->Compare(leaf)) < 0)
                branch = branch->GetRight();

            else if (unequal > 0)
                    branch = branch->GetLeft();

            else break;
        }
        while(branch);

        return branch;
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf *Find(const THas &leaf, int length) const
    {
        TOf *branch;
        int unequal;

        if ((branch=GetRoot()))
        do
        {
            if ((unequal = branch->Compare(leaf, length)) < 0)
                branch = branch->GetRight();

            else if (unequal > 0)
                    branch = branch->GetLeft();

            else break;
        }
        while(branch);

        return branch;
    }
    /**
     **********************************************************************
     * Function: GetFirst
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf *GetFirst() const
    {
        return GetFirstOf(GetRoot());
    }
    /**
     **********************************************************************
     * Function: GetLast
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf *GetLast() const
    {
        return GetLastOf(GetRoot());
    }
    /**
     **********************************************************************
     * Function: GetNext
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf *GetNext(TOf *branch) const
    {
        TOf *tree;

        if ((tree=branch->GetRight()))
            return GetFirstOf(tree);

        if ((tree = branch->GetTree()))
        do
        {
            if (branch != tree->GetRight())
                break;

            branch = tree;
            tree = tree->GetTree();
        }
        while(tree);

        return tree;
    }
    /**
     **********************************************************************
     * Function: GetPrevious
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf *GetPrevious(TOf *branch) const
    {
        TOf *tree;

        if ((tree=branch->GetLeft()))
            return GetLastOf(tree);

        if ((tree = branch->GetTree()))
        do
        {
            if (branch != tree->GetLeft())
                break;

            branch = tree;
            tree = tree->GetTree();
        }
        while(tree);

        return tree;
    }
    /**
     **********************************************************************
     * Function: SetRoot
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TOf *SetRoot(TOf *root)
    {
        return m_root=root;
    }
    /**
     **********************************************************************
     * Function: GetRoot
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TOf *GetRoot() const
    {
        return m_root;
    }

protected:

    /**
     **********************************************************************
     * Function: GetFirstOf
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf *GetFirstOf(TOf *branch) const
    {
        TOf *next;

        while ((next=branch->GetLeft()))
            branch=next;
        return branch;
    }
    /**
     **********************************************************************
     * Function: GetLastOf
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf *GetLastOf(TOf *branch) const
    {
        TOf *next;

        while ((next=branch->GetRight()))
            branch=next;
        return branch;
    }
    /**
     **********************************************************************
     * Function: GetLeftOf
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf *GetLeftOf(TOf *branch) const
    {
        if (branch)
            return branch->GetLeft();
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetRightOf
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TOf *GetRightOf(TOf *branch) const
    {
        if (branch)
            return branch->GetRight();
        return 0;
    }
};


#endif
