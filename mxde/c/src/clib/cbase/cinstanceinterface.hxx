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
 *   File: cinstanceinterface.hxx
 *
 * Author: $author$
 *   Date: 8/16/2009
 **********************************************************************
 */
#if !defined(_CINSTANCEINTERFACE_HXX) || defined(CINSTANCEINTERFACE_MEMBERS_ONLY)
#if !defined(_CINSTANCEINTERFACE_HXX) && !defined(CINSTANCEINTERFACE_MEMBERS_ONLY)
#define _CINSTANCEINTERFACE_HXX
#endif /* !defined(_CINSTANCEINTERFACE_HXX) && !defined(CINSTANCEINTERFACE_MEMBERS_ONLY) */

#if !defined(CINSTANCEINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cInstanceInterface
 *
 * Author: $author$
 *   Date: 8/16/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cInstanceInterface
: virtual public cInterfaceBase
{
public:
    typedef cInterfaceBase cImplements;
#else /* !defined(CINSTANCEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CINSTANCEINTERFACE_MEMBERS_ONLY) */

#if !defined(CINSTANCEINTERFACE_MEMBERS_ONLY)
/* include cInstance member functions interface
 */
#define CINSTANCE_MEMBERS_ONLY
#define CINSTANCE_MEMBER_FUNCS_INTERFACE
#include "cinstance.hxx"
#undef CINSTANCE_MEMBER_FUNCS_INTERFACE
#undef CINSTANCE_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cInstanceImplement
 *
 * Author: $author$
 *   Date: 8/16/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cInstanceImplement
: virtual public cInstanceInterface
{
public:
    typedef cInstanceInterface cImplements;
    
/* include cInstance member functions implement
 */
#define CINSTANCE_MEMBERS_ONLY
#define CINSTANCE_MEMBER_FUNCS_IMPLEMENT
#include "cinstance.hxx"
#undef CINSTANCE_MEMBER_FUNCS_IMPLEMENT
#undef CINSTANCE_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CINSTANCEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CINSTANCEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CINSTANCEINTERFACE_HXX) || defined(CINSTANCEINTERFACE_MEMBERS_ONLY) */
