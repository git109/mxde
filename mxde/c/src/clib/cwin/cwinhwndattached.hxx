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
 *   File: cwinhwndattached.hxx
 *
 * Author: $author$
 *   Date: 5/7/2009
 **********************************************************************
 */
#if !defined(_CWINHWNDATTACHED_HXX) || defined(CWINHWND_MEMBERS_ONLY)
#if !defined(_CWINHWNDATTACHED_HXX) && !defined(CWINHWND_MEMBERS_ONLY)
#define _CWINHWNDATTACHED_HXX
#endif /* !defined(_CWINHWNDATTACHED_HXX) && !defined(CWINHWND_MEMBERS_ONLY) */

#include "cwininterfacebase.hxx"
#include "cwinbase.hxx"
#include "cattached.hxx"

class c_INTERFACE_CLASS cWinHWNDAttachedInterface;
/**
 **********************************************************************
 * Typedef: cWinHWNDAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/7/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cWinHWNDAttachedInterface, 
 HWND, UINT, NULL, cWinInterfaceBase>
cWinHWNDAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinHWNDAttachedInterface
 *
 * Author: $author$
 *   Date: 5/7/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHWNDAttachedInterface
: virtual public cWinHWNDAttachedInterfaceImplements
{
public:
    typedef cWinHWNDAttachedInterfaceImplements cImplements;
    typedef cWinHWNDAttachedInterface cDerives;
};
class c_EXPORT_CLASS cWinHWNDAttachedImplement;
/**
 **********************************************************************
 * Typedef: cWinHWNDAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 5/7/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cWinHWNDAttachedImplement, 
 cWinHWNDAttachedInterface, 
 HWND, UINT, NULL>
cWinHWNDAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cWinHWNDAttachedImplement
 *
 * Author: $author$
 *   Date: 5/7/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHWNDAttachedImplement
: virtual public cWinHWNDAttachedImplementImplements
{
public:
    typedef cWinHWNDAttachedImplementImplements cImplements;
    typedef cWinHWNDAttachedImplement cDerives;
};
class c_EXPORT_CLASS cWinHWNDAttached;
/**
 **********************************************************************
 * Typedef: cWinHWNDAttachedExtends
 *
 *  Author: $author$
 *    Date: 5/7/2009
 **********************************************************************
 */
typedef cAttachedT
<cWinHWNDAttached, 
 cWinHWNDAttachedImplement, 
 cWinHWNDAttachedInterface,
 HWND, UINT, NULL, cWinBase>
cWinHWNDAttachedExtends;
/**
 **********************************************************************
 *  Class: cWinHWNDAttached
 *
 * Author: $author$
 *   Date: 5/7/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHWNDAttached
: public cWinHWNDAttachedExtends
{
public:
    typedef cWinHWNDAttachedExtends cExtends;
    typedef cWinHWNDAttached cDerives;

    cWinHWNDAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};
#endif /* !defined(_CWINHWNDATTACHED_HXX) || defined(CWINHWND_MEMBERS_ONLY) */
