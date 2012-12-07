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
 *   File: copenedinterface.hxx
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
#if !defined(_COPENEDINTERFACE_HXX) || defined(COPENEDINTERFACE_MEMBERS_ONLY)
#if !defined(_COPENEDINTERFACE_HXX) && !defined(COPENEDINTERFACE_MEMBERS_ONLY)
#define _COPENEDINTERFACE_HXX
#endif /* !defined(_COPENEDINTERFACE_HXX) && !defined(COPENEDINTERFACE_MEMBERS_ONLY) */

#if !defined(COPENEDINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/* cOpened interface definition
 */
class c_INTERFACE_CLASS cOpenedInterface;

#undef CDB_CLASS
#define CDB_CLASS "cOpenedInterfaceT"
/**
 **********************************************************************
 *  Class: cOpenedInterfaceT
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
template
<class TDerives=cOpenedInterface,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>
 
class c_INTERFACE_CLASS cOpenedInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cOpenedInterfaceT cDerives;
#else /* !defined(COPENEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(COPENEDINTERFACE_MEMBERS_ONLY) */

#if !defined(COPENEDINTERFACE_MEMBERS_ONLY) 
/* include cOpened member functions interface
 */
#define COPENED_MEMBERS_ONLY
#define COPENED_MEMBER_FUNCS_INTERFACE
#include "copened.hxx"
#undef COPENED_MEMBER_FUNCS_INTERFACE
#undef COPENED_MEMBERS_ONLY
};
#undef CDB_CLASS

/* cOpened implement definition
 */
class c_IMPLEMENT_CLASS  cOpenedImplement;

#undef CDB_CLASS
#define CDB_CLASS "cOpenedImplementT"
/**
 **********************************************************************
 *  Class: cOpenedImplementT
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
template
<class TDerives=cOpenedImplement,
 class TOpenedInterface=cOpenedInterface,
 class TImplements=TOpenedInterface>
 
class c_IMPLEMENT_CLASS  cOpenedImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cOpenedImplementT cDerives;

/* include cOpened interface member definitions
 */
#define COPENEDINTERFACE_MEMBERS_ONLY
#include "copenedinterface.hxx"
#undef COPENEDINTERFACE_MEMBERS_ONLY

/* include cOpened member functions implement
 */
#define COPENED_MEMBERS_ONLY
#define COPENED_MEMBER_FUNCS_IMPLEMENT
#include "copened.hxx"
#undef COPENED_MEMBER_FUNCS_IMPLEMENT
#undef COPENED_MEMBERS_ONLY
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(COPENEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(COPENEDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_COPENEDINTERFACE_HXX) || defined(COPENEDINTERFACE_MEMBERS_ONLY) */
