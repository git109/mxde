/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$  
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
 *   File: cxwindowmaininterface.hxx
 *
 * Author: $author$           
 *   Date: 4/21/2010
 **********************************************************************
 */
#if !defined(_CXWINDOWMAININTERFACE_HXX) || defined(CXWINDOWMAININTERFACE_MEMBERS_ONLY)
#if !defined(_CXWINDOWMAININTERFACE_HXX) && !defined(CXWINDOWMAININTERFACE_MEMBERS_ONLY)
#define _CXWINDOWMAININTERFACE_HXX
#endif /* !defined(_CXWINDOWMAININTERFACE_HXX) && !defined(CXWINDOWMAININTERFACE_MEMBERS_ONLY) */

#if !defined(CXWINDOWMAININTERFACE_MEMBERS_ONLY)
#include "cxmaininterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXWindowMainInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 4/21/2010
 **********************************************************************
 */
typedef cXMainInterface
cXWindowMainInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXWindowMainInterface
 *
 * Author: $author$           
 *   Date: 4/21/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXWindowMainInterface
: virtual public cXWindowMainInterfaceImplement
{
public:
    typedef cXWindowMainInterfaceImplement cImplements;
#else /* !defined(CXWINDOWMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXWINDOWMAININTERFACE_MEMBERS_ONLY) */

#if !defined(CXWINDOWMAININTERFACE_MEMBERS_ONLY)
};

/**
 **********************************************************************
 *  Class: cXWindowMainImplement
 *
 * Author: $author$           
 *   Date: 4/21/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXWindowMainImplement
: virtual public cXWindowMainInterface
{
public:
    typedef cXWindowMainInterface cImplements;

};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXWINDOWMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXWINDOWMAININTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXWINDOWMAININTERFACE_HXX) || defined(CXWINDOWMAININTERFACE_MEMBERS_ONLY) */
