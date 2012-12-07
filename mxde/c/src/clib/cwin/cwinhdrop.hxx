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
 *   File: cwinhdrop.hxx
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
#ifndef _CWINHDROP_HXX
#define _CWINHDROP_HXX

#include "cwininterfacebase.hxx"
#include "cwinbase.hxx"
#include "cattached.hxx"
#include "copened.hxx"

/**
 **********************************************************************
 * cWinHDROPAttached
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHDROPAttachedInterface;
/**
 **********************************************************************
 * Typedef: cWinHDROPAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/11/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cWinHDROPAttachedInterface, 
 HDROP, UINT, NULL, cWinInterfaceBase>
cWinHDROPAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinHDROPAttachedInterface
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHDROPAttachedInterface
: virtual public cWinHDROPAttachedInterfaceImplements
{
public:
    typedef cWinHDROPAttachedInterfaceImplements cImplements;
    typedef cWinHDROPAttachedInterface cDerives;
};
class c_EXPORT_CLASS cWinHDROPAttachedImplement;
/**
 **********************************************************************
 * Typedef: cWinHDROPAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 5/11/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cWinHDROPAttachedImplement, 
 cWinHDROPAttachedInterface, 
 HDROP, UINT, NULL>
cWinHDROPAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cWinHDROPAttachedImplement
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHDROPAttachedImplement
: virtual public cWinHDROPAttachedImplementImplements
{
public:
    typedef cWinHDROPAttachedImplementImplements cImplements;
    typedef cWinHDROPAttachedImplement cDerives;
};
class c_EXPORT_CLASS cWinHDROPAttached;
/**
 **********************************************************************
 * Typedef: cWinHDROPAttachedExtends
 *
 *  Author: $author$
 *    Date: 5/11/2009
 **********************************************************************
 */
typedef cAttachedT
<cWinHDROPAttached, 
 cWinHDROPAttachedImplement, 
 cWinHDROPAttachedInterface,
 HDROP, UINT, NULL, cWinBase>
cWinHDROPAttachedExtends;
/**
 **********************************************************************
 *  Class: cWinHDROPAttached
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHDROPAttached
: public cWinHDROPAttachedExtends
{
public:
    typedef cWinHDROPAttachedExtends cExtends;
    typedef cWinHDROPAttached cDerives;

    cWinHDROPAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

/**
 **********************************************************************
 * cWinHDROP
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHDROPInterface;
/**
 **********************************************************************
 * Typedef: cWinHDROPInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/11/2009
 **********************************************************************
 */
typedef cOpenedInterfaceT
<cWinHDROPInterface, cWinHDROPAttachedInterface>
cWinHDROPInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinHDROPInterface
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHDROPInterface
: virtual public cWinHDROPInterfaceImplements
{
public:
    typedef cWinHDROPInterfaceImplements cImplements;
    typedef cWinHDROPInterface cDerives;
};
class c_EXPORT_CLASS cWinHDROPImplement;
/**
 **********************************************************************
 * Typedef: cWinHDROPImplementImplements
 *
 *  Author: $author$
 *    Date: 5/11/2009
 **********************************************************************
 */
typedef cOpenedImplementT
<cWinHDROPImplement, cWinHDROPInterface>
cWinHDROPImplementImplements;
/**
 **********************************************************************
 *  Class: cWinHDROPImplement
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHDROPImplement
: virtual public cWinHDROPImplementImplements
{
public:
    typedef cWinHDROPImplementImplements cImplements;
    typedef cWinHDROPImplement cDerives;
};
class c_EXPORT_CLASS cWinHDROP;
/**
 **********************************************************************
 * Typedef: cWinHDROPExtends
 *
 *  Author: $author$
 *    Date: 5/11/2009
 **********************************************************************
 */
typedef cOpenedT
<cWinHDROP, 
 cWinHDROPImplement, 
 cWinHDROPAttached>
cWinHDROPExtends;
/**
 **********************************************************************
 *  Class: cWinHDROP
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHDROP
: public cWinHDROPExtends
{
public:
    typedef cWinHDROPExtends cExtends;
    typedef cWinHDROP cDerives;

    cWinHDROP
    (HDROP attached=NULL,
     bool isOpen=false) 
    : cExtends(isOpen) 
    {
        m_attached = attached;
    }
};
#endif /* _CWINHDROP_HXX */
