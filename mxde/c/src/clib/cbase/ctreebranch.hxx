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
 *   File: ctreebranch.hxx
 *
 * Author: $author$
 *   Date: 9/1/2009
 **********************************************************************
 */
#if !defined(_CTREEBRANCH_HXX) || defined(CTREEBRANCH_MEMBERS_ONLY)
#if !defined(_CTREEBRANCH_HXX) && !defined(CTREEBRANCH_MEMBERS_ONLY)
#define _CTREEBRANCH_HXX
#endif /* !defined(_CTREEBRANCH_HXX) && !defined(CTREEBRANCH_MEMBERS_ONLY) */

#if !defined(CTREEBRANCH_MEMBERS_ONLY)
#include "ctreebase.hxx"
#include "cexportbase.hxx"
#include "cinstancebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cTreeBranch;

#undef CDB_CLASS
#define CDB_CLASS "cTreeBranchT"
/**
 **********************************************************************
 *  Class: cTreeBranchT
 *
 * Author: $author$
 *   Date: 9/1/2009
 **********************************************************************
 */
template
<class TDerives=cTreeBranch,
 class TLeaf=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TUndefinedLength=TLength,
 TUndefinedLength VUndefinedLength=UNDEFINED_LENGTH,
 class TTreeBase=cTreeBase,
 class TExtends=TTreeBase>

class c_EXPORT_CLASS cTreeBranchT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives TBranch;
    typedef TBranch tBranch;

/* include cTreeBranch interface member definitions
 */
#define CTREEBRANCHINTERFACE_MEMBERS_ONLY
#include "ctreebranchinterface.hxx"
#undef CTREEBRANCHINTERFACE_MEMBERS_ONLY

    TBranch *m_tree, 
            *m_leftBranch, 
            *m_rightBranch;
    
    /**
     **********************************************************************
     *  Constructor: cTreeBranchT
     *
     *       Author: $author$
     *         Date: 9/1/2009
     **********************************************************************
     */
    cTreeBranchT
    (TBranch *tree=0, 
     TBranch *leftBranch=0, 
     TBranch *rightBranch=0) 
    : m_tree(tree),
      m_leftBranch(leftBranch),
      m_rightBranch(rightBranch)
    {
    }
#else /* !defined(CTREEBRANCH_MEMBERS_ONLY) */
#endif /* !defined(CTREEBRANCH_MEMBERS_ONLY) */

#if !defined(CTREEBRANCH_MEMBER_FUNCS_INTERFACE)
#if !defined(CTREEBRANCH_MEMBER_FUNCS_IMPLEMENT) 
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 9/1/2009
     **********************************************************************
     */
    virtual int Compare
    (const TBranch& toBranch) const 
    {
        int unequal = 1;
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 9/1/2009
     **********************************************************************
     */
    virtual int Compare
    (const TLeaf& toLeaf, 
     TLength toLength=VUndefinedLength) const 
    {
        int unequal = 1;
        return unequal;
    }
    /**
     **********************************************************************
     * Function: SetTree
     *
     *   Author: $author$
     *     Date: 9/1/2009
     **********************************************************************
     */
    inline TBranch* SetTree
    (TBranch* branch) 
    {
        TBranch* treeBranch = (CTHIS m_treeBranch = branch);
        return treeBranch;
    }
    /**
     **********************************************************************
     * Function: GetTree
     *
     *   Author: $author$
     *     Date: 9/1/2009
     **********************************************************************
     */
    inline TBranch* GetTree() const 
    {
        TBranch* treeBranch = (CTHIS m_tree);
        return treeBranch;
    }
    /**
     **********************************************************************
     * Function: SetLeftBranch
     *
     *   Author: $author$
     *     Date: 9/1/2009
     **********************************************************************
     */
    inline TBranch* SetLeftBranch
    (TBranch* branch) 
    {
        TBranch* leftBranch = (CTHIS m_leftBranch = branch);
        return leftBranch;
    }
    /**
     **********************************************************************
     * Function: GetLeftBranch
     *
     *   Author: $author$
     *     Date: 9/1/2009
     **********************************************************************
     */
    inline TBranch* GetLeftBranch() const 
    {
        TBranch* leftBranch = (CTHIS m_leftBranch);
        return leftBranch;
    }
    /**
     **********************************************************************
     * Function: SetRightBranch
     *
     *   Author: $author$
     *     Date: 9/1/2009
     **********************************************************************
     */
    inline TBranch* SetRightBranch
    (TBranch* branch) 
    {
        TBranch* rightBranch = (CTHIS m_rightBranch = branch);
        return rightBranch;
    }
    /**
     **********************************************************************
     * Function: GetRightBranch
     *
     *   Author: $author$
     *     Date: 9/1/2009
     **********************************************************************
     */
    inline TBranch* GetRightBranch() const 
    {
        TBranch* rightBranch = (CTHIS m_rightBranch);
        return rightBranch;
    }
#endif /* !defined(CTREEBRANCH_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTREEBRANCH_MEMBER_FUNCS_INTERFACE) */
    
#if !defined(CTREEBRANCH_MEMBERS_ONLY)
};
#undef CDB_CLASS
/**
 **********************************************************************
 * Typedef: cTreeBranchExtends
 *
 *  Author: $author$
 *    Date: 9/2/2009
 **********************************************************************
 */
typedef cTreeBranchT<>
cTreeBranchExtends;
/**
 **********************************************************************
 *  Class: cTreeBranch
 *
 * Author: $author$
 *   Date: 9/2/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cTreeBranch
: public cTreeBranchExtends
{
public:
    typedef cTreeBranchExtends cExtends;
    typedef cTreeBranch cDerives;
    
    tLeaf m_leaf;
    
    /**
     **********************************************************************
     * Constructor: cTreeBranch
     *
     *      Author: $author$
     *        Date: 9/2/2009
     **********************************************************************
     */
    cTreeBranch
    (tLeaf leaf=0,
     tBranch* tree=0,
     tBranch* left=0,
     tBranch* right=0) 
    : cExtends(tree, left, right),
      m_leaf(leaf)
    {
    }
};

/*
 * Export
 */
class c_EXPORT_CLASS cExportTreeBranch;

#undef CDB_CLASS
#define CDB_CLASS "cExportTreeBranchT"
/**
 **********************************************************************
 *  Class: cExportTreeBranchT
 *
 * Author: $author$
 *   Date: 9/1/2009
 **********************************************************************
 */
template
<class TDerives=cExportTreeBranch,
 class TLeaf=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TUndefinedLength=TLength,
 TUndefinedLength VUndefinedLength=UNDEFINED_LENGTH,
 class TTreeBase=cExportBase,
 class TExtends=TTreeBase>

class c_EXPORT_CLASS cExportTreeBranchT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives TBranch;
    typedef TBranch tBranch;

/* include cTreeBranch interface member definitions
 */
#define CTREEBRANCHINTERFACE_MEMBERS_ONLY
#include "ctreebranchinterface.hxx"
#undef CTREEBRANCHINTERFACE_MEMBERS_ONLY

    TBranch *m_tree, 
            *m_leftBranch, 
            *m_rightBranch;
    
    /**
     **********************************************************************
     *  Constructor: cExportTreeBranchT
     *
     *       Author: $author$
     *         Date: 9/1/2009
     **********************************************************************
     */
    cExportTreeBranchT
    (TBranch *tree=0, 
     TBranch *leftBranch=0, 
     TBranch *rightBranch=0) 
    : m_tree(tree),
      m_leftBranch(leftBranch),
      m_rightBranch(rightBranch)
    {
    }

/* include cTreeBranch member definitions
 */
#define CTREEBRANCH_MEMBERS_ONLY
#include "ctreebranch.hxx"
#undef CTREEBRANCH_MEMBERS_ONLY

    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 9/4/2009
     **********************************************************************
     */
    virtual eError Free() 
    {
        eError error = DeleteThis();
        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 9/4/2009
     **********************************************************************
     */
    virtual eError DeleteThis() 
    {
        eError error = e_ERROR_NOT_ALLOWED;
        return error;
    }
};
#undef CDB_CLASS
/**
 **********************************************************************
 * Typedef: cExportTreeBranchExtends
 *
 *  Author: $author$
 *    Date: 9/2/2009
 **********************************************************************
 */
typedef cExportTreeBranchT<>
cExportTreeBranchExtends;
/**
 **********************************************************************
 *  Class: cExportTreeBranch
 *
 * Author: $author$
 *   Date: 9/2/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cExportTreeBranch
: public cExportTreeBranchExtends
{
public:
    typedef cExportTreeBranchExtends cExtends;
    typedef cExportTreeBranch cDerives;
    
    tLeaf m_leaf;
    
    /**
     **********************************************************************
     * Constructor: cExportTreeBranch
     *
     *      Author: $author$
     *        Date: 9/2/2009
     **********************************************************************
     */
    cExportTreeBranch
    (tLeaf leaf=0,
     tBranch* tree=0,
     tBranch* left=0,
     tBranch* right=0) 
    : cExtends(tree, left, right),
      m_leaf(leaf)
    {
    }
};
 
/*
 * Instance
 */
class c_INSTANCE_CLASS cInstanceTreeBranch;

#undef CDB_CLASS
#define CDB_CLASS "cInstanceTreeBranchT"
/**
 **********************************************************************
 *  Class: cInstanceTreeBranchT
 *
 * Author: $author$
 *   Date: 9/1/2009
 **********************************************************************
 */
template
<class TDerives=cInstanceTreeBranch,
 class TLeaf=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TUndefinedLength=TLength,
 TUndefinedLength VUndefinedLength=UNDEFINED_LENGTH,
 class TTreeBase=cInstanceBase,
 class TExtends=TTreeBase>

class c_INSTANCE_CLASS cInstanceTreeBranchT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives TBranch;
    typedef TBranch tBranch;

/* include cTreeBranch interface member definitions
 */
#define CTREEBRANCHINTERFACE_MEMBERS_ONLY
#include "ctreebranchinterface.hxx"
#undef CTREEBRANCHINTERFACE_MEMBERS_ONLY

    TBranch *m_tree, 
            *m_leftBranch, 
            *m_rightBranch;
    
    /**
     **********************************************************************
     *  Constructor: cInstanceTreeBranchT
     *
     *       Author: $author$
     *         Date: 9/1/2009
     **********************************************************************
     */
    cInstanceTreeBranchT
    (TBranch *tree=0, 
     TBranch *leftBranch=0, 
     TBranch *rightBranch=0) 
    : m_tree(tree),
      m_leftBranch(leftBranch),
      m_rightBranch(rightBranch)
    {
    }

/* include cTreeBranch member definitions
 */
#define CTREEBRANCH_MEMBERS_ONLY
#include "ctreebranch.hxx"
#undef CTREEBRANCH_MEMBERS_ONLY

    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 9/4/2009
     **********************************************************************
     */
    virtual eError Free() 
    {
        eError error = DeleteThis();
        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 9/4/2009
     **********************************************************************
     */
    virtual eError DeleteThis() 
    {
        eError error = e_ERROR_NOT_ALLOWED;
        return error;
    }
};
#undef CDB_CLASS
/**
 **********************************************************************
 * Typedef: cInstanceTreeBranchExtends
 *
 *  Author: $author$
 *    Date: 9/2/2009
 **********************************************************************
 */
typedef cInstanceTreeBranchT<>
cInstanceTreeBranchExtends;
/**
 **********************************************************************
 *  Class: cInstanceTreeBranch
 *
 * Author: $author$
 *   Date: 9/2/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cInstanceTreeBranch
: public cInstanceTreeBranchExtends
{
public:
    typedef cInstanceTreeBranchExtends cExtends;
    typedef cInstanceTreeBranch cDerives;
    
    tLeaf m_leaf;
    
    /**
     **********************************************************************
     * Constructor: cInstanceTreeBranch
     *
     *      Author: $author$
     *        Date: 9/2/2009
     **********************************************************************
     */
    cInstanceTreeBranch
    (tLeaf leaf=0,
     tBranch* tree=0,
     tBranch* left=0,
     tBranch* right=0) 
    : cExtends(tree, left, right),
      m_leaf(leaf)
    {
    }
};
 
#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTREEBRANCH_MEMBERS_ONLY) */
#endif /* !defined(CTREEBRANCH_MEMBERS_ONLY) */

#endif /* !defined(_CTREEBRANCH_HXX) || defined(CTREEBRANCH_MEMBERS_ONLY) */
