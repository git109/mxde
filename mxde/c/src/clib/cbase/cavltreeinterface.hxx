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
 *   File: cavltreeinterface.hxx
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
#if !defined(_CAVLTREEINTERFACE_HXX) || defined(CAVLTREEINTERFACE_MEMBERS_ONLY)
#if !defined(_CAVLTREEINTERFACE_HXX) && !defined(CAVLTREEINTERFACE_MEMBERS_ONLY)
#define _CAVLTREEINTERFACE_HXX
#endif /* !defined(_CAVLTREEINTERFACE_HXX) && !defined(CAVLTREEINTERFACE_MEMBERS_ONLY) */

#if !defined(CAVLTREEINTERFACE_MEMBERS_ONLY)
#include "ctreeinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cAVLTreeInterface;

#undef CDB_CLASS
#define CDB_CLASS "cAVLTreeInterfaceT"
/**
 **********************************************************************
 *  Class: cAVLTreeInterfaceT
 *
 * Author: $author$
 *   Date: 9/3/2009
 **********************************************************************
 */
template
<class TDerives=cAVLTreeInterface,
 class TTreeInterface=cTreeInterface,
 class TBranch=cTreeBranch,
 class TLeaf=CHAR,
 class TInt=INT,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TUndefinedLength=TLength,
 TUndefinedLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TTreeInterface>

class c_INTERFACE_CLASS cAVLTreeInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
#else /* !defined(CAVLTREEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CAVLTREEINTERFACE_MEMBERS_ONLY) */

/* include cAVLTreeBranch interface member definitions
 */
#define CAVLTREEBRANCHINTERFACE_MEMBERS_ONLY
#include "cavltreebranchinterface.hxx"
#undef CAVLTREEBRANCHINTERFACE_MEMBERS_ONLY

#if !defined(CAVLTREEINTERFACE_MEMBERS_ONLY)
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CAVLTREEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CAVLTREEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CAVLTREEINTERFACE_HXX) || defined(CAVLTREEINTERFACE_MEMBERS_ONLY) */
