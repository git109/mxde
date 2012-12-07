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
 *   File: ctreebranchinterface.hxx
 *
 * Author: $author$
 *   Date: 9/2/2009
 **********************************************************************
 */
#if !defined(_CTREEBRANCHINTERFACE_HXX) || defined(CTREEBRANCHINTERFACE_MEMBERS_ONLY)
#if !defined(_CTREEBRANCHINTERFACE_HXX) && !defined(CTREEBRANCHINTERFACE_MEMBERS_ONLY)
#define _CTREEBRANCHINTERFACE_HXX
#endif /* !defined(_CTREEBRANCHINTERFACE_HXX) && !defined(CTREEBRANCHINTERFACE_MEMBERS_ONLY) */

#if !defined(CTREEBRANCHINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cTreeBranchInterface;

#undef CDB_CLASS
#define CDB_CLASS "cTreeBranchInterfaceT"
/**
 **********************************************************************
 *  Class: cTreeBranchInterfaceT
 *
 * Author: $author$
 *   Date: 9/2/2009
 **********************************************************************
 */
template
<class TDerives=cTreeBranchInterface,
 class TLeaf=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TUndefinedLength=TLength,
 TUndefinedLength VUndefinedLength=UNDEFINED_LENGTH,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>

class c_INTERFACE_CLASS cTreeBranchInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
#else /* !defined(CTREEBRANCHINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CTREEBRANCHINTERFACE_MEMBERS_ONLY) */

    typedef TLeaf tLeaf;
    typedef TSize tSize;
    typedef TLength tLength;
    enum { vUndefinedLength = VUndefinedLength};
    
#if !defined(CTREEBRANCHINTERFACE_MEMBERS_ONLY)
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTREEBRANCHINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CTREEBRANCHINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CTREEBRANCHINTERFACE_HXX) || defined(CTREEBRANCHINTERFACE_MEMBERS_ONLY) */
