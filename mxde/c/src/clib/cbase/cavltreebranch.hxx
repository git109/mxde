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
 *   File: cavltreebranch.hxx
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
#if !defined(_CAVLTREEBRANCH_HXX) || defined(CAVLTREEBRANCH_MEMBERS_ONLY)
#if !defined(_CAVLTREEBRANCH_HXX) && !defined(CAVLTREEBRANCH_MEMBERS_ONLY)
#define _CAVLTREEBRANCH_HXX
#endif /* !defined(_CAVLTREEBRANCH_HXX) && !defined(CAVLTREEBRANCH_MEMBERS_ONLY) */

#if !defined(CAVLTREEBRANCH_MEMBERS_ONLY)
#include "ctreebranch.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cAVLTreeBranch;

#undef CDB_CLASS
#define CDB_CLASS "cAVLTreeBranchT"
/**
 **********************************************************************
 *  Class: cAVLTreeBranchT
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
template
<class TDerives=cAVLTreeBranch,
 class TLeaf=CHAR,
 class TInt=INT,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TUndefinedLength=TLength,
 TUndefinedLength VUndefinedLength=UNDEFINED_LENGTH,
 class TBranchExtend=cTreeBranchT
 <TDerives, TLeaf, TSize, TLength, 
  TUndefinedLength, VUndefinedLength>,
 class TExtends=TBranchExtend>

class c_EXPORT_CLASS cAVLTreeBranchT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives TBranch;
    
/* include cAVLTreeBranch interface member definitions
 */
#define CAVLTREEBRANCHINTERFACE_MEMBERS_ONLY
#include "cavltreebranchinterface.hxx"
#undef CAVLTREEBRANCHINTERFACE_MEMBERS_ONLY

    TInt m_depth;
    
    /**
     **********************************************************************
     *  Constructor: cAVLTreeBranchT
     *
     *       Author: $author$
     *         Date: 9/3/2009
     **********************************************************************
     */
    cAVLTreeBranchT
    (TInt depth=1,
     TBranch* tree=0,
     TBranch* leftBranch=0,
     TBranch* rightBranch=0)
    : cExtends(tree,leftBranch,rightBranch), 
      m_depth(0)
    {
    }
#else /* !defined(CAVLTREEBRANCH_MEMBERS_ONLY) */
#endif /* !defined(CAVLTREEBRANCH_MEMBERS_ONLY) */

#if !defined(CAVLTREEBRANCH_MEMBER_FUNCS_INTERFACE)
#if !defined(CAVLTREEBRANCH_MEMBER_FUNCS_IMPLEMENT) 
    /**
     **********************************************************************
     * Function: SetDepth
     *
     *   Author: $author$
     *     Date: 9/4/2009
     **********************************************************************
     */
    TInt SetDepth
    (TInt depth) 
    {
        m_depth = depth;
        return m_depth;
    }
    /**
     **********************************************************************
     * Function: GetDepth
     *
     *   Author: $author$
     *     Date: 9/4/2009
     **********************************************************************
     */
    TInt GetDepth() const 
    {
        return m_depth;
    }
#endif /* !defined(CAVLTREEBRANCH_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CAVLTREEBRANCH_MEMBER_FUNCS_INTERFACE) */
    
#if !defined(CAVLTREEBRANCH_MEMBERS_ONLY)
};
#undef CDB_CLASS
/**
 **********************************************************************
 * Typedef: cAVLTreeBranchExtends
 *
 *  Author: $author$
 *    Date: 9/3/2009
 **********************************************************************
 */
typedef cAVLTreeBranchT<>
cAVLTreeBranchExtends;
/**
 **********************************************************************
 *  Class: cAVLTreeBranch
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cAVLTreeBranch
: public cAVLTreeBranchExtends
{
public:
    typedef cAVLTreeBranchExtends cExtends;
    typedef cAVLTreeBranch cDerives;
    
    tLeaf m_leaf;
    
    /**
     **********************************************************************
     * Constructor: cAVLTreeBranch
     *
     *      Author: $author$
     *        Date: 9/3/2009
     **********************************************************************
     */
    cAVLTreeBranch
    (tLeaf leaf=0,
     tInt depth=1,
     tBranch* tree=0,
     tBranch* leftBranch=0,
     tBranch* rightBranch=0) 
    : cExtends(depth, tree, leftBranch, rightBranch),
      m_leaf(leaf) 
    {
    }
};

/*
 * Export
 */
class c_EXPORT_CLASS cExportAVLTreeBranch;

#undef CDB_CLASS
#define CDB_CLASS "cExportAVLTreeBranchT"
/**
 **********************************************************************
 *  Class: cExportAVLTreeBranchT
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
template
<class TDerives=cExportAVLTreeBranch,
 class TLeaf=CHAR,
 class TInt=INT,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TUndefinedLength=TLength,
 TUndefinedLength VUndefinedLength=UNDEFINED_LENGTH,
 class TBranchExtend=cExportTreeBranchT
 <TDerives, TLeaf, TSize, TLength, 
  TUndefinedLength, VUndefinedLength>,
 class TExtends=TBranchExtend>

class c_EXPORT_CLASS cExportAVLTreeBranchT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives TBranch;
    
/* include cAVLTreeBranch interface member definitions
 */
#define CAVLTREEBRANCHINTERFACE_MEMBERS_ONLY
#include "cavltreebranchinterface.hxx"
#undef CAVLTREEBRANCHINTERFACE_MEMBERS_ONLY

    TInt m_depth;
    
    /**
     **********************************************************************
     *  Constructor: cExportAVLTreeBranchT
     *
     *       Author: $author$
     *         Date: 9/3/2009
     **********************************************************************
     */
    cExportAVLTreeBranchT
    (TInt depth=1,
     TBranch* tree=0,
     TBranch* leftBranch=0,
     TBranch* rightBranch=0)
    : cExtends(tree,leftBranch,rightBranch), 
      m_depth(0)
    {
    }

/* include cAVLTreeBranch member definitions
 */
#define CAVLTREEBRANCH_MEMBERS_ONLY
#include "cavltreebranch.hxx"
#undef CAVLTREEBRANCH_MEMBERS_ONLY

};
#undef CDB_CLASS
/**
 **********************************************************************
 * Typedef: cExportAVLTreeBranchExtends
 *
 *  Author: $author$
 *    Date: 9/3/2009
 **********************************************************************
 */
typedef cExportAVLTreeBranchT<>
cExportAVLTreeBranchExtends;
/**
 **********************************************************************
 *  Class: cExportAVLTreeBranch
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cExportAVLTreeBranch
: public cExportAVLTreeBranchExtends
{
public:
    typedef cExportAVLTreeBranchExtends cExtends;
    typedef cExportAVLTreeBranch cDerives;
    
    tLeaf m_leaf;
    
    /**
     **********************************************************************
     * Constructor: cExportAVLTreeBranch
     *
     *      Author: $author$
     *        Date: 9/3/2009
     **********************************************************************
     */
    cExportAVLTreeBranch
    (tLeaf leaf=0,
     tInt depth=1,
     tBranch* tree=0,
     tBranch* leftBranch=0,
     tBranch* rightBranch=0) 
    : cExtends(depth, tree, leftBranch, rightBranch),
      m_leaf(leaf) 
    {
    }
};
 
/*
 * Instance
 */
class c_INSTANCE_CLASS cInstanceAVLTreeBranch;

#undef CDB_CLASS
#define CDB_CLASS "cInstanceAVLTreeBranchT"
/**
 **********************************************************************
 *  Class: cInstanceAVLTreeBranchT
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
template
<class TDerives=cInstanceAVLTreeBranch,
 class TLeaf=CHAR,
 class TInt=INT,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TUndefinedLength=TLength,
 TUndefinedLength VUndefinedLength=UNDEFINED_LENGTH,
 class TBranchExtend=cInstanceTreeBranchT
 <TDerives, TLeaf, TSize, TLength, 
  TUndefinedLength, VUndefinedLength>,
 class TExtends=TBranchExtend>

class c_INSTANCE_CLASS cInstanceAVLTreeBranchT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives TBranch;
    
/* include cAVLTreeBranch interface member definitions
 */
#define CAVLTREEBRANCHINTERFACE_MEMBERS_ONLY
#include "cavltreebranchinterface.hxx"
#undef CAVLTREEBRANCHINTERFACE_MEMBERS_ONLY

    TInt m_depth;
    
    /**
     **********************************************************************
     *  Constructor: cInstanceAVLTreeBranchT
     *
     *       Author: $author$
     *         Date: 9/3/2009
     **********************************************************************
     */
    cInstanceAVLTreeBranchT
    (TInt depth=1,
     TBranch* tree=0,
     TBranch* leftBranch=0,
     TBranch* rightBranch=0)
    : cExtends(tree,leftBranch,rightBranch), 
      m_depth(0)
    {
    }

/* include cAVLTreeBranch member definitions
 */
#define CAVLTREEBRANCH_MEMBERS_ONLY
#include "cavltreebranch.hxx"
#undef CAVLTREEBRANCH_MEMBERS_ONLY

};
#undef CDB_CLASS
/**
 **********************************************************************
 * Typedef: cInstanceAVLTreeBranchExtends
 *
 *  Author: $author$
 *    Date: 9/3/2009
 **********************************************************************
 */
typedef cInstanceAVLTreeBranchT<>
cInstanceAVLTreeBranchExtends;
/**
 **********************************************************************
 *  Class: cInstanceAVLTreeBranch
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cInstanceAVLTreeBranch
: public cInstanceAVLTreeBranchExtends
{
public:
    typedef cInstanceAVLTreeBranchExtends cExtends;
    typedef cInstanceAVLTreeBranch cDerives;
    
    tLeaf m_leaf;
    
    /**
     **********************************************************************
     * Constructor: cInstanceAVLTreeBranch
     *
     *      Author: $author$
     *        Date: 9/3/2009
     **********************************************************************
     */
    cInstanceAVLTreeBranch
    (tLeaf leaf=0,
     tInt depth=1,
     tBranch* tree=0,
     tBranch* leftBranch=0,
     tBranch* rightBranch=0) 
    : cExtends(depth, tree, leftBranch, rightBranch),
      m_leaf(leaf) 
    {
    }
};
 
#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CAVLTREEBRANCH_MEMBERS_ONLY) */
#endif /* !defined(CAVLTREEBRANCH_MEMBERS_ONLY) */

#endif /* !defined(_CAVLTREEBRANCH_HXX) || defined(CAVLTREEBRANCH_MEMBERS_ONLY) */
