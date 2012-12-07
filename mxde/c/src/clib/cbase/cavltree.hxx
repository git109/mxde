/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cavltree.hxx
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
#if !defined(_CAVLTREE_HXX) || defined(CAVLTREE_MEMBERS_ONLY)
#if !defined(_CAVLTREE_HXX) && !defined(CAVLTREE_MEMBERS_ONLY)
#define _CAVLTREE_HXX
#endif /* !defined(_CAVLTREE_HXX) && !defined(CAVLTREE_MEMBERS_ONLY) */

#if !defined(CAVLTREE_MEMBERS_ONLY)
#include "cavltreebranch.hxx"
#include "ctree.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cAVLTree;

#undef CDB_CLASS
#define CDB_CLASS "cAVLTreeT"
/**
 **********************************************************************
 *  Class: cAVLTreeT
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
template
<class TDerives=cAVLTree,
 class TBranch=cAVLTreeBranch,
 class TLeaf=CHAR,
 class TInt=INT,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TUndefinedLength=TLength,
 TUndefinedLength VUndefinedLength=UNDEFINED_LENGTH,
 class TTreeExtend=cTreeT
 <TDerives, TBranch, TLeaf, TSize, TLength, 
  TUndefinedLength, VUndefinedLength>,
 class TExtends=TTreeExtend>

class c_EXPORT_CLASS cAVLTreeT
: public TExtends
{
public:
    typedef TExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cAVLTreeT
     *
     *       Author: $author$
     *         Date: 9/3/2009
     **********************************************************************
     */
    cAVLTreeT
    (TBranch* root=0)
    : cExtends(root)
    {
    }
#else /* !defined(CAVLTREE_MEMBERS_ONLY) */
#endif /* !defined(CAVLTREE_MEMBERS_ONLY) */

#if !defined(CAVLTREE_MEMBER_FUNCS_INTERFACE)
#if !defined(CAVLTREE_MEMBER_FUNCS_IMPLEMENT) 
    /**
     **********************************************************************
     * Function: Insert
     *
     *   Author: $author$
     *     Date: 9/3/2009
     *
     * Insert a branch into the tree.
     **********************************************************************
     */
    TBranch* Insert
    (TBranch* branch) 
    {
        if (branch)
        {
            branch->m_depth = 1;
            branch->m_tree = 0;
            branch->m_leftBranch = 0;
            branch->m_rightBranch = 0;
            CTHIS m_root = Inserted(CTHIS m_root, branch);
        }
        return branch;
    }
    /**
     **********************************************************************
     * Function: Delete
     *
     *   Author: $author$
     *     Date: 9/3/2009
     *
     * Delete a branch from the tree.
     **********************************************************************
     */
    TBranch* Delete
    (TBranch* branch) 
    {
        if (branch)
        {
            CTHIS m_root = Deleted(CTHIS m_root, branch);
            branch->m_depth = 1;
            branch->m_tree = 0;
            branch->m_leftBranch = 0;
            branch->m_rightBranch = 0;
        }
        return branch;
    }
    
    /**
     **********************************************************************
     * Function: Inserted
     *
     *   Author: $author$
     *     Date: 9/3/2009
     *
     * Perform recursive AVL insertion of an item into the
     * current subtree. Return the new root of the subtree.
     **********************************************************************
     */
    TBranch* Inserted
    (TBranch* tree,
     TBranch* branch) 
    {
        if (!tree)
            return branch;

        if (branch)
        if (branch->Compare(*tree)<0)
        {
            tree->m_leftBranch=Inserted(tree->m_leftBranch,branch);
            tree->m_leftBranch->m_tree=tree;
            if (Depth(tree->m_leftBranch)-Depth(tree->m_rightBranch)>1)
            {
                if (Depth(tree->m_leftBranch->m_rightBranch)
                    >Depth(tree->m_leftBranch->m_leftBranch))
                    tree->m_leftBranch=Left(tree->m_leftBranch);
                return Right(tree);
            }
            else tree->m_depth=tree->m_leftBranch->m_depth+1;
        }
        else
        {
            tree->m_rightBranch=Inserted(tree->m_rightBranch,branch);
            tree->m_rightBranch->m_tree=tree;
            if (Depth(tree->m_rightBranch)-Depth(tree->m_leftBranch)>1)
            {
                if (Depth(tree->m_rightBranch->m_leftBranch)
                    >Depth(tree->m_rightBranch->m_rightBranch))
                    tree->m_rightBranch=Right(tree->m_rightBranch);
                return Left(tree);
            }
            else tree->m_depth=tree->m_rightBranch->m_depth+1;
        }
        return tree;
    }
    /**
     **********************************************************************
     * Function: Deleted
     *
     *   Author: $author$
     *     Date: 9/3/2009
     *
     * Perform recursive AVL deletion of an item from the
     * current subtree. Return the new root of the subtree.
     **********************************************************************
     */
    TBranch* Deleted
    (TBranch* tree,
     TBranch* branch) 
    {
        int c;

        if ((!tree)||(!branch))
            return tree;

        if ((c=branch->Compare(*tree))>0)
        {
            tree->m_rightBranch=Deleted(tree->m_rightBranch,branch);
            if (Depth(tree->m_leftBranch)-Depth(tree->m_rightBranch)>1)
            {
                if (Depth(tree->m_leftBranch->m_rightBranch)
                    >Depth(tree->m_leftBranch->m_leftBranch))
                    tree->m_leftBranch=Left(tree->m_leftBranch);
                tree=Right(tree);
            }
            else tree->m_depth=NewDepth(tree);
        }
        else if (c<0)
        {
            tree->m_leftBranch=Deleted(tree->m_leftBranch,branch);
            if (Depth(tree->m_rightBranch)-Depth(tree->m_leftBranch)>1)
            {
                if (Depth(tree->m_rightBranch->m_leftBranch)
                    >Depth(tree->m_rightBranch->m_rightBranch))
                    tree->m_rightBranch=Right(tree->m_rightBranch);
                tree=Left(tree);
            }
            else tree->m_depth=NewDepth(tree);
        }
        else if (branch->m_depth>1)
        {
            if (Depth(branch->m_rightBranch)>Depth(branch->m_leftBranch))
                tree=Least(&branch->m_rightBranch);
            else tree=Greatest(&branch->m_leftBranch);
            tree->m_depth=NewDepth(branch);
            if ((tree->m_leftBranch=branch->m_leftBranch)!=0)
                tree->m_leftBranch->m_tree=tree;
            if ((tree->m_rightBranch=branch->m_rightBranch)!=0)
                tree->m_rightBranch->m_tree=tree;
        }
        else tree=0;
        
        return tree;
    }
    
    /**
     **********************************************************************
     * Function: Least
     *
     *   Author: $author$
     *     Date: 9/3/2009
     *
     * Recusively raise the least item in the subtree to
     * the top of the tree.
     **********************************************************************
     */
    TBranch* Least
    (TBranch** tree) 
    {
        TBranch* t = 0;

        if ((*tree)->m_leftBranch!=0)
        {
            t=Least(&(*tree)->m_leftBranch);
            if (Depth((*tree)->m_rightBranch)-Depth((*tree)->m_leftBranch)>1)
            {
                if (Depth((*tree)->m_rightBranch->m_leftBranch)
                    >Depth((*tree)->m_rightBranch->m_rightBranch))
                    (*tree)->m_rightBranch=Right((*tree)->m_rightBranch);
                *tree=Left(*tree);
            }
            else (*tree)->m_depth=NewDepth(*tree);
        }
        else if ((*tree)->m_rightBranch!=0)
        {
            t=*tree;
            *tree=t->m_rightBranch;
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
     *     Date: 9/3/2009
     *
     * Recusively raise the greatest item in the subtree to
     * the top of the tree.
     **********************************************************************
     */
    TBranch* Greatest
    (TBranch** tree) 
    {
        TBranch* t = 0;

        if ((*tree)->m_rightBranch!=0)
        {
            t=Greatest(&(*tree)->m_rightBranch);
            if (Depth((*tree)->m_leftBranch)-Depth((*tree)->m_rightBranch)>1)
            {
                if (Depth((*tree)->m_leftBranch->m_rightBranch)
                    >Depth((*tree)->m_leftBranch->m_leftBranch))
                    (*tree)->m_leftBranch=Left((*tree)->m_leftBranch);
                *tree=Right(*tree);
            }
            else (*tree)->m_depth=NewDepth(*tree);
        }
        else if ((*tree)->m_leftBranch!=0)
        {
            t=*tree;
            *tree=t->m_leftBranch;
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
     *     Date: 9/3/2009
     *
     * Perform AVL rotation left to adjust the tree.
     **********************************************************************
     */
    TBranch* Left
    (TBranch* tree) 
    {
        TBranch *rightBranch = 0;

        if (tree)
        if ((rightBranch=tree->m_rightBranch))
        {
            if ((tree->m_rightBranch=rightBranch->m_leftBranch))
                tree->m_rightBranch->m_tree=tree;

            tree->m_depth=Depth(tree->m_leftBranch)+1;

            if (Depth(tree->m_rightBranch)>=tree->m_depth)
                tree->m_depth=tree->m_rightBranch->m_depth+1;

            rightBranch->m_depth=tree->m_depth+1;
            rightBranch->m_leftBranch=tree;
            rightBranch->m_tree=tree->m_tree;
            tree->m_tree=rightBranch;
        }
        return rightBranch;
    }
    /**
     **********************************************************************
     * Function: Right
     *
     *   Author: $author$
     *     Date: 9/3/2009
     *
     * Perform AVL rotation right to adjust the tree.
     **********************************************************************
     */
    TBranch* Right
    (TBranch* tree) 
    {
        TBranch* leftBranch = 0;

        if (tree)
        if ((leftBranch=tree->m_leftBranch))
        {
            if ((tree->m_leftBranch=leftBranch->m_rightBranch))
                tree->m_leftBranch->m_tree=tree;

            tree->m_depth=Depth(tree->m_rightBranch)+1;

            if (Depth(tree->m_leftBranch)>=tree->m_depth)
                tree->m_depth=tree->m_leftBranch->m_depth+1;

            leftBranch->m_depth=tree->m_depth+1;
            leftBranch->m_rightBranch=tree;
            leftBranch->m_tree=tree->m_tree;
            tree->m_tree=leftBranch;
        }
        return leftBranch;
    }
    
    /**
     **********************************************************************
     * Function: NewDepth
     *
     *   Author: $author$
     *     Date: 9/3/2009
     *
     * Return the new depth of tree.
     **********************************************************************
     */
    inline TInt NewDepth
    (const TBranch* tree) const 
    {
        TInt depth = 0;
        TInt rDepth;
        
        if (tree)
        if ((depth = Depth(tree->m_leftBranch))
            >(rDepth = Depth(tree->m_rightBranch)))
            depth += 1;
        else depth = rDepth+1;
        return depth;
    }
    /**
     **********************************************************************
     * Function: Depth
     *
     *   Author: $author$
     *     Date: 9/3/2009
     *
     * Return the depth of tree.
     **********************************************************************
     */
    inline TInt Depth
    (const TBranch* tree) const 
    {
        TInt depth = 0;
        
        if (tree)
        if (1 > (depth = tree->m_depth))
            depth = 1;
        return depth;
    }
#endif /* !defined(CAVLTREE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CAVLTREE_MEMBER_FUNCS_INTERFACE) */
    
#if !defined(CAVLTREE_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cAVLTreeExtends
 *
 *  Author: $author$
 *    Date: 9/3/2009
 **********************************************************************
 */
typedef cAVLTreeT<>
cAVLTreeExtends;
/**
 **********************************************************************
 *  Class: cAVLTree
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cAVLTree
: public cAVLTreeExtends
{
public:
    typedef cAVLTreeExtends cExtends;
    typedef cAVLTree cDerives;
    /**
     **********************************************************************
     * Constructor: cAVLTree
     *
     *      Author: $author$
     *        Date: 9/3/2009
     **********************************************************************
     */
    cAVLTree
    (tBranch* root=0) 
    : cExtends(root)
    {
    }
};

/*
 * Export
 */
class c_EXPORT_CLASS cExportAVLTree;

#undef CDB_CLASS
#define CDB_CLASS "cExportAVLTreeT"
/**
 **********************************************************************
 *  Class: cExportAVLTreeT
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
template
<class TDerives=cExportAVLTree,
 class TBranch=cExportAVLTreeBranch,
 class TLeaf=CHAR,
 class TInt=INT,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TUndefinedLength=TLength,
 TUndefinedLength VUndefinedLength=UNDEFINED_LENGTH,
 class TTreeExtend=cExportTreeT
 <TDerives, TBranch, TLeaf, TSize, TLength, 
  TUndefinedLength, VUndefinedLength>,
 class TExtends=TTreeExtend>

class c_EXPORT_CLASS cExportAVLTreeT
: public TExtends
{
public:
    typedef TExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cExportAVLTreeT
     *
     *       Author: $author$
     *         Date: 9/3/2009
     **********************************************************************
     */
    cExportAVLTreeT
    (TBranch* root=0)
    : cExtends(root)
    {
    }
/* include cAVLTree member definitions
 */
#define CAVLTREE_MEMBERS_ONLY
#include "cavltree.hxx"
#undef CAVLTREE_MEMBERS_ONLY
};
#undef CDB_CLASS
/**
 **********************************************************************
 * Typedef: cExportAVLTreeExtends
 *
 *  Author: $author$
 *    Date: 9/3/2009
 **********************************************************************
 */
typedef cExportAVLTreeT<>
cExportAVLTreeExtends;
/**
 **********************************************************************
 *  Class: cExportAVLTree
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cExportAVLTree
: public cExportAVLTreeExtends
{
public:
    typedef cExportAVLTreeExtends cExtends;
    typedef cExportAVLTree cDerives;
    /**
     **********************************************************************
     * Constructor: cExportAVLTree
     *
     *      Author: $author$
     *        Date: 9/3/2009
     **********************************************************************
     */
    cExportAVLTree
    (tBranch* root=0) 
    : cExtends(root)
    {
    }
};

/*
 * Instance
 */
class c_INSTANCE_CLASS cInstanceAVLTree;

#undef CDB_CLASS
#define CDB_CLASS "cInstanceAVLTreeT"
/**
 **********************************************************************
 *  Class: cInstanceAVLTreeT
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
template
<class TDerives=cInstanceAVLTree,
 class TBranch=cInstanceAVLTreeBranch,
 class TLeaf=CHAR,
 class TInt=INT,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TUndefinedLength=TLength,
 TUndefinedLength VUndefinedLength=UNDEFINED_LENGTH,
 class TTreeExtend=cInstanceTreeT
 <TDerives, TBranch, TLeaf, TSize, TLength, 
  TUndefinedLength, VUndefinedLength>,
 class TExtends=TTreeExtend>

class c_INSTANCE_CLASS cInstanceAVLTreeT
: public TExtends
{
public:
    typedef TExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cInstanceAVLTreeT
     *
     *       Author: $author$
     *         Date: 9/3/2009
     **********************************************************************
     */
    cInstanceAVLTreeT
    (TBranch* root=0)
    : cExtends(root)
    {
    }
/* include cAVLTree member definitions
 */
#define CAVLTREE_MEMBERS_ONLY
#include "cavltree.hxx"
#undef CAVLTREE_MEMBERS_ONLY
};
#undef CDB_CLASS
/**
 **********************************************************************
 * Typedef: cInstanceAVLTreeExtends
 *
 *  Author: $author$
 *    Date: 9/3/2009
 **********************************************************************
 */
typedef cInstanceAVLTreeT<>
cInstanceAVLTreeExtends;
/**
 **********************************************************************
 *  Class: cInstanceAVLTree
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cInstanceAVLTree
: public cInstanceAVLTreeExtends
{
public:
    typedef cInstanceAVLTreeExtends cExtends;
    typedef cInstanceAVLTree cDerives;
    /**
     **********************************************************************
     * Constructor: cInstanceAVLTree
     *
     *      Author: $author$
     *        Date: 9/3/2009
     **********************************************************************
     */
    cInstanceAVLTree
    (tBranch* root=0) 
    : cExtends(root)
    {
    }
};
#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CAVLTREE_MEMBERS_ONLY) */
#endif /* !defined(CAVLTREE_MEMBERS_ONLY) */

#endif /* !defined(_CAVLTREE_HXX) || defined(CAVLTREE_MEMBERS_ONLY) */
