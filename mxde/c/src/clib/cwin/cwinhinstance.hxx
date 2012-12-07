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
 *   File: cwinhinstance.hxx
 *
 * Author: $author$
 *   Date: 5/5/2009
 **********************************************************************
 */
#ifndef _CWINHINSTANCE_HXX
#define _CWINHINSTANCE_HXX

#include "cwininterfacebase.hxx"
#include "cwinbase.hxx"
#include "cattached.hxx"

class c_INTERFACE_CLASS cWinHINSTANCEAttachedInterface;
/**
 **********************************************************************
 * Typedef: cWinHINSTANCEAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/5/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cWinHINSTANCEAttachedInterface, 
 HINSTANCE, UINT, NULL, cWinInterfaceBase>
cWinHINSTANCEAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinHINSTANCEAttachedInterface
 *
 * Author: $author$
 *   Date: 5/5/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHINSTANCEAttachedInterface
: virtual public cWinHINSTANCEAttachedInterfaceImplements
{
public:
    typedef cWinHINSTANCEAttachedInterfaceImplements cImplements;
    typedef cWinHINSTANCEAttachedInterface cDerives;
};
class c_EXPORT_CLASS cWinHINSTANCEAttachedImplement;
/**
 **********************************************************************
 * Typedef: cWinHINSTANCEAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 5/6/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cWinHINSTANCEAttachedImplement, cWinHINSTANCEAttachedInterface, 
 HINSTANCE, UINT, NULL, cWinInterfaceBase>
cWinHINSTANCEAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cWinHINSTANCEAttachedImplement
 *
 * Author: $author$
 *   Date: 5/6/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHINSTANCEAttachedImplement
: virtual public cWinHINSTANCEAttachedImplementImplements
{
public:
    typedef cWinHINSTANCEAttachedImplementImplements cImplements;
    typedef cWinHINSTANCEAttachedImplement cDerives;
};
class c_EXPORT_CLASS cWinHINSTANCEAttached;
/**
 **********************************************************************
 * Typedef: cWinHINSTANCEAttachedExtends
 *
 *  Author: $author$
 *    Date: 5/6/2009
 **********************************************************************
 */
typedef cAttachedT
<cWinHINSTANCEAttached, 
 cWinHINSTANCEAttachedImplement, 
 cWinHINSTANCEAttachedInterface,
 HINSTANCE, UINT, NULL, cWinBase>
cWinHINSTANCEAttachedExtends;
/**
 **********************************************************************
 *  Class: cWinHINSTANCEAttached
 *
 * Author: $author$
 *   Date: 5/6/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHINSTANCEAttached
: public cWinHINSTANCEAttachedExtends
{
public:
    typedef cWinHINSTANCEAttachedExtends cExtends;
    typedef cWinHINSTANCEAttached cDerives;

    cWinHINSTANCEAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#endif /* _CWINHINSTANCE_HXX */
