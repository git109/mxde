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
 *   File: ctree.hxx
 *
 * Author: $author$
 *   Date: 9/2/2009
 **********************************************************************
 */
#if !defined(_CTREE_HXX) || defined(CTREE_MEMBERS_ONLY)
#if !defined(_CTREE_HXX) && !defined(CTREE_MEMBERS_ONLY)
#define _CTREE_HXX
#endif /* !defined(_CTREE_HXX) && !defined(CTREE_MEMBERS_ONLY) */

#if !defined(CTREE_MEMBERS_ONLY)
#include "ctreebranch.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cTree;

#undef CDB_CLASS
#define CDB_CLASS "cTreeT"
/**
 **********************************************************************
 *  Class: cTreeT
 *
 * Author: $author$
 *   Date: 9/2/2009
 **********************************************************************
 */
template
<class TDerives=cTree,
 class TBranch=cTreeBranch,
 class TLeaf=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TUndefinedLength=TLength,
 TUndefinedLength VUndefinedLength=UNDEFINED_LENGTH,
 class TTreeBase=cTreeBase,
 class TExtends=TTreeBase>

class c_EXPORT_CLASS cTreeT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TBranch tBranch;
    
/* include cTreeBranch interface member definitions
 */
#define CTREEBRANCHINTERFACE_MEMBERS_ONLY
#include "ctreebranchinterface.hxx"
#undef CTREEBRANCHINTERFACE_MEMBERS_ONLY

    TBranch *m_root;

    /**
     **********************************************************************
     *  Constructor: cTreeT
     *
     *       Author: $author$
     *         Date: 9/2/2009
     **********************************************************************
     */
    cTreeT
    (TBranch *root=0) 
    : m_root(root)
    {
    }
#else /* !defined(CTREE_MEMBERS_ONLY) */
#endif /* !defined(CTREE_MEMBERS_ONLY) */

#if !defined(CTREE_MEMBER_FUNCS_INTERFACE)
#if !defined(CTREE_MEMBER_FUNCS_IMPLEMENT) 
    /**
     **********************************************************************
     * Function: Insert
     *
     *   Author: $author$
     *     Date: 9/2/2009
     **********************************************************************
     */
    TBranch* Insert
    (TBranch* branch) 
    {
        TBranch *next, *tree;
        int unequal;
        
        if (branch)
        if ((next=GetRoot()))
        {
            do
            {
                tree=next;
                
                /* compare branch to one in the tree
                 */
                if ((unequal = branch->Compare(*tree)) < 0)
                {
                    /* goto the left branch
                     */
                    if (!(next=tree->GetLeftBranch()))
                        tree->SetLeftBranch(branch);
                }
                else
                {
                    /* goto the right branch
                     */
                    if (!(next=tree->GetRightBranch()))
                        tree->SetRightBranch(branch);
                }
            }
            while(next);

            branch->SetTree(tree);
        }
        else
        /* set as root
         */
        SetRoot(branch);
        
        return branch;
    }
    /**
     **********************************************************************
     * Function: Delete
     *
     *   Author: $author$
     *     Date: 9/2/2009
     **********************************************************************
     */
    TBranch* Delete
    (TBranch* branch) 
    {
        TBranch *tree, *next, *deleted;
        
        if ((deleted = branch))
        {
            if ((deleted->GetLeftBranch()) && (deleted->GetRightBranch()))
                /* get branch to replace one deleted
                 */
                deleted = GetNext(branch);

            /* get tree of one deleted
             */
            tree = deleted->GetTree();
            
            /* get branch next to one deleted
             */
            if (!(next = deleted->GetLeftBranch()))
                next = deleted->GetRightBranch();

            if (next)
                /* insert branch next to one deleted onto tree
                 */
                next->SetTree(tree);

            if (tree)
            {
                /* insert next branch
                 */
                if (deleted != tree->GetLeftBranch())
                    tree->SetRightBranch(next);
                else tree->SetLeftBranch(next);
            }
            else
            /* set root to next
             */
            SetRoot(next);

            if (deleted != branch)
            {
                /* set replaced branch tree
                 */
                if ((next = deleted->SetTree(branch->GetTree())))
                    if (branch != next->GetLeftBranch())
                        next->SetRightBranch(deleted);
                    else next->SetLeftBranch(deleted);

                /* set replaced branch left branch
                 */
                if ((next = deleted->SetLeftBranch(branch->GetLeftBranch())))
                    next->SetTree(deleted);

                /* set replaced branch right branch
                 */
                if ((next = deleted->SetRightBranch(branch->GetRightBranch())))
                    next->SetTree(deleted);
            }
        }
        return branch;
    }
    
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 9/2/2009
     **********************************************************************
     */
    TBranch* Find
    (const TLeaf& leaf) const
    {
        TBranch* branch = 0;        
        int unequal;

        if ((branch=GetRoot()))
        do
        {
            if ((unequal = branch->Compare(leaf)) < 0)
                branch = branch->GetRightBranch();

            else if (unequal > 0)
                    branch = branch->GetLeftBranch();

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
     *     Date: 9/2/2009
     **********************************************************************
     */
    TBranch* Find
    (const TLeaf& leaf,
     TLength length) const
    {
        TBranch* branch = 0;        
        int unequal;

        if ((branch=GetRoot()))
        do
        {
            if ((unequal = branch->Compare(leaf, length)) < 0)
                branch = branch->GetRightBranch();

            else if (unequal > 0)
                    branch = branch->GetLeftBranch();

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
     *     Date: 9/2/2009
     **********************************************************************
     */
    TBranch* GetFirst() const 
    {
        TBranch* branch = GetFirstOf(GetRoot());
        return branch;
    }
    /**
     **********************************************************************
     * Function: GetLast
     *
     *   Author: $author$
     *     Date: 9/2/2009
     **********************************************************************
     */
    TBranch* GetLast() const 
    {
        TBranch* branch = GetLastOf(GetRoot());
        return branch;
    }
    
    /**
     **********************************************************************
     * Function: GetNext
     *
     *   Author: $author$
     *     Date: 9/2/2009
     **********************************************************************
     */
    TBranch* GetNext
    (const TBranch* branch) const 
    {
        TBranch* tree = 0;
        
        if (branch)
        if ((tree=branch->GetRightBranch()))
            return GetFirstOf(tree);            
        else
        if ((tree = branch->GetTree()))
        do
        {
            if (branch != tree->GetRightBranch())
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
     *     Date: 9/2/2009
     **********************************************************************
     */
    TBranch* GetPrevious
    (const TBranch* branch) const 
    {
        TBranch* tree = 0;
        
        if (branch)
        if ((tree=branch->GetLeftBranch()))
            return GetLastOf(tree);
        else
        if ((tree = branch->GetTree()))
        do
        {
            if (branch != tree->GetLeftBranch())
                break;

            branch = tree;
            tree = tree->GetTree();
        }
        while(tree);

        return tree;
    }

    /**
     **********************************************************************
     * Function: GetFirstOf
     *
     *   Author: $author$
     *     Date: 9/2/2009
     **********************************************************************
     */
    TBranch* GetFirstOf
    (const TBranch* branch) const 
    {
        TBranch *current, *next;

        if ((current = (tBranch*)(branch)))
        while ((next = branch->GetLeftBranch()))
            current = (tBranch*)(branch = next);
        return current;
    }
    /**
     **********************************************************************
     * Function: GetLastOf
     *
     *   Author: $author$
     *     Date: 9/2/2009
     **********************************************************************
     */
    TBranch* GetLastOf
    (const TBranch* branch) const 
    {
        TBranch *current, *next;

        if ((current = (tBranch*)(branch)))
        while ((next = branch->GetRightBranch()))
            current = (tBranch*)(branch = next);
        return current;
    }
    
    /**
     **********************************************************************
     * Function: GetLeftOf
     *
     *   Author: $author$
     *     Date: 9/2/2009
     **********************************************************************
     */
    TBranch* GetLeftOf
    (const TBranch* branch) const 
    {
        if (branch)
            return branch->GetLeftBranch();
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetRightOf
     *
     *   Author: $author$
     *     Date: 9/2/2009
     **********************************************************************
     */
    TBranch* GetRightOf
    (const TBranch* branch) const 
    {
        if (branch)
            return branch->GetRightBranch();
        return 0;
    }
    
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 9/10/2009
     **********************************************************************
     */
    TBranch* Clear() 
    {
        TBranch* root = (m_root);
        m_root = 0;
        return root;
    }
    
    /**
     **********************************************************************
     * Function: SetRoot
     *
     *   Author: $author$
     *     Date: 9/2/2009
     **********************************************************************
     */
    inline TBranch* SetRoot
    (TBranch* branch) 
    {
        TBranch* root = (m_root = branch);
        return root;
    }
    /**
     **********************************************************************
     * Function: GetRoot
     *
     *   Author: $author$
     *     Date: 9/2/2009
     **********************************************************************
     */
    inline TBranch* GetRoot() const 
    {
        TBranch* root = (m_root);
        return root;
    }
#endif /* !defined(CTREE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTREE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CTREE_MEMBERS_ONLY)
};
#undef CDB_CLASS
/**
 **********************************************************************
 * Typedef: cTreeExtends
 *
 *  Author: $author$
 *    Date: 9/3/2009
 **********************************************************************
 */
typedef cTreeT<>
cTreeExtends;
/**
 **********************************************************************
 *  Class: cTree
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cTree
: public cTreeExtends
{
public:
    typedef cTreeExtends cExtends;
    typedef cTree cDerives;
    /**
     **********************************************************************
     * Constructor: cTree
     *
     *      Author: $author$
     *        Date: 9/3/2009
     **********************************************************************
     */
    cTree
    (tBranch* root=0) 
    : cExtends(root)
    {
    }
};

/*
 * Export
 */
class c_EXPORT_CLASS cExportTree;

#undef CDB_CLASS
#define CDB_CLASS "cExportTreeT"
/**
 **********************************************************************
 *  Class: cExportTreeT
 *
 * Author: $author$
 *   Date: 9/2/2009
 **********************************************************************
 */
template
<class TDerives=cExportTree,
 class TBranch=cExportTreeBranch,
 class TLeaf=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TUndefinedLength=TLength,
 TUndefinedLength VUndefinedLength=UNDEFINED_LENGTH,
 class TTreeBase=cExportBase,
 class TExtends=TTreeBase>

class c_EXPORT_CLASS cExportTreeT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TBranch tBranch;
    
/* include cTreeBranch interface member definitions
 */
#define CTREEBRANCHINTERFACE_MEMBERS_ONLY
#include "ctreebranchinterface.hxx"
#undef CTREEBRANCHINTERFACE_MEMBERS_ONLY

    TBranch *m_root;

    /**
     **********************************************************************
     *  Constructor: cExportTreeT
     *
     *       Author: $author$
     *         Date: 9/2/2009
     **********************************************************************
     */
    cExportTreeT
    (TBranch *root=0) 
    : m_root(root)
    {
    }
/* include cTree member definitions
 */
#define CTREE_MEMBERS_ONLY
#include "ctree.hxx"
#undef CTREE_MEMBERS_ONLY
};
#undef CDB_CLASS
/**
 **********************************************************************
 * Typedef: cExportTreeExtends
 *
 *  Author: $author$
 *    Date: 9/3/2009
 **********************************************************************
 */
typedef cExportTreeT<>
cExportTreeExtends;
/**
 **********************************************************************
 *  Class: cExportTree
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cExportTree
: public cExportTreeExtends
{
public:
    typedef cExportTreeExtends cExtends;
    typedef cExportTree cDerives;
    /**
     **********************************************************************
     * Constructor: cExportTree
     *
     *      Author: $author$
     *        Date: 9/3/2009
     **********************************************************************
     */
    cExportTree
    (tBranch* root=0) 
    : cExtends(root)
    {
    }
};

/*
 * Instance
 */
class c_INSTANCE_CLASS cInstanceTree;

#undef CDB_CLASS
#define CDB_CLASS "cInstanceTreeT"
/**
 **********************************************************************
 *  Class: cInstanceTreeT
 *
 * Author: $author$
 *   Date: 9/2/2009
 **********************************************************************
 */
template
<class TDerives=cInstanceTree,
 class TBranch=cInstanceTreeBranch,
 class TLeaf=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TUndefinedLength=TLength,
 TUndefinedLength VUndefinedLength=UNDEFINED_LENGTH,
 class TTreeBase=cInstanceBase,
 class TExtends=TTreeBase>

class c_INSTANCE_CLASS cInstanceTreeT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TBranch tBranch;
    
/* include cTreeBranch interface member definitions
 */
#define CTREEBRANCHINTERFACE_MEMBERS_ONLY
#include "ctreebranchinterface.hxx"
#undef CTREEBRANCHINTERFACE_MEMBERS_ONLY

    TBranch *m_root;

    /**
     **********************************************************************
     *  Constructor: cInstanceTreeT
     *
     *       Author: $author$
     *         Date: 9/2/2009
     **********************************************************************
     */
    cInstanceTreeT
    (TBranch *root=0) 
    : m_root(root)
    {
    }
/* include cTree member definitions
 */
#define CTREE_MEMBERS_ONLY
#include "ctree.hxx"
#undef CTREE_MEMBERS_ONLY
};
#undef CDB_CLASS
/**
 **********************************************************************
 * Typedef: cInstanceTreeExtends
 *
 *  Author: $author$
 *    Date: 9/3/2009
 **********************************************************************
 */
typedef cInstanceTreeT<>
cInstanceTreeExtends;
/**
 **********************************************************************
 *  Class: cInstanceTree
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cInstanceTree
: public cInstanceTreeExtends
{
public:
    typedef cInstanceTreeExtends cExtends;
    typedef cInstanceTree cDerives;
    /**
     **********************************************************************
     * Constructor: cInstanceTree
     *
     *      Author: $author$
     *        Date: 9/3/2009
     **********************************************************************
     */
    cInstanceTree
    (tBranch* root=0) 
    : cExtends(root)
    {
    }
};
#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTREE_MEMBERS_ONLY) */
#endif /* !defined(CTREE_MEMBERS_ONLY) */

#endif /* !defined(_CTREE_HXX) || defined(CTREE_MEMBERS_ONLY) */
