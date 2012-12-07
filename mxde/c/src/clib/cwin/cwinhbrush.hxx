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
 *   File: cwinhbrush.hxx
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
#ifndef _CWINHBRUSH_HXX
#define _CWINHBRUSH_HXX

#include "cwininterfacebase.hxx"
#include "cwinbase.hxx"
#include "cattached.hxx"
#include "ccreated.hxx"

class c_INTERFACE_CLASS cWinHBRUSHAttachedInterface;
/**
 **********************************************************************
 * Typedef: cWinHBRUSHAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/28/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cWinHBRUSHAttachedInterface, 
 HBRUSH, UINT, NULL, cWinInterfaceBase>
cWinHBRUSHAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinHBRUSHAttachedInterface
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHBRUSHAttachedInterface
: virtual public cWinHBRUSHAttachedInterfaceImplements
{
public:
    typedef cWinHBRUSHAttachedInterfaceImplements cImplements;
    typedef cWinHBRUSHAttachedInterface cDerives;
};
class c_EXPORT_CLASS cWinHBRUSHAttachedImplement;
/**
 **********************************************************************
 * Typedef: cWinHBRUSHAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 5/28/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cWinHBRUSHAttachedImplement, 
 cWinHBRUSHAttachedInterface, 
 HBRUSH, UINT, NULL>
cWinHBRUSHAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cWinHBRUSHAttachedImplement
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHBRUSHAttachedImplement
: virtual public cWinHBRUSHAttachedImplementImplements
{
public:
    typedef cWinHBRUSHAttachedImplementImplements cImplements;
    typedef cWinHBRUSHAttachedImplement cDerives;

    /**
     **********************************************************************
     * Function: CreateDetached
     *
     *   Author: $author$
     *     Date: 5/28/2009
     **********************************************************************
     */
    virtual HBRUSH CreateDetached
    (eError& error,
     const COLORREF& color) const 
    {
        HBRUSH detached = NULL;
        if ((detached = CreateSolidBrush(color)))
            error = e_ERROR_NONE;
        else
        error = e_ERROR_FAILED;
        return detached;
    }
    /**
     **********************************************************************
     * Function: DestroyDetached
     *
     *   Author: $author$
     *     Date: 5/28/2009
     **********************************************************************
     */
    virtual eError DestroyDetached
    (HBRUSH detached) const 
    {
        eError error = e_ERROR_FAILED;
        if (detached)
        if (DeleteObject(detached))
            error = e_ERROR_NONE;
        return error;
    }
};
class c_EXPORT_CLASS cWinHBRUSHAttached;
/**
 **********************************************************************
 * Typedef: cWinHBRUSHAttachedExtends
 *
 *  Author: $author$
 *    Date: 5/28/2009
 **********************************************************************
 */
typedef cAttachedT
<cWinHBRUSHAttached, 
 cWinHBRUSHAttachedImplement, 
 cWinHBRUSHAttachedInterface,
 HBRUSH, UINT, NULL, cWinBase>
cWinHBRUSHAttachedExtends;
/**
 **********************************************************************
 *  Class: cWinHBRUSHAttached
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHBRUSHAttached
: public cWinHBRUSHAttachedExtends
{
public:
    typedef cWinHBRUSHAttachedExtends cExtends;
    typedef cWinHBRUSHAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cWinHBRUSHAttached
     *
     *      Author: $author$
     *        Date: 5/28/2009
     **********************************************************************
     */
    cWinHBRUSHAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cWinHBRUSHInterface;
/**
 **********************************************************************
 * Typedef: cWinHBRUSHInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/28/2009
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cWinHBRUSHInterface, cWinHBRUSHAttachedInterface>
cWinHBRUSHInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinHBRUSHInterface
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHBRUSHInterface
: virtual public cWinHBRUSHInterfaceImplements
{
public:
    typedef cWinHBRUSHInterfaceImplements cImplements;
    typedef cWinHBRUSHInterface cDerives;
};
class c_EXPORT_CLASS cWinHBRUSHImplement;
/**
 **********************************************************************
 * Typedef: cWinHBRUSHImplementImplements
 *
 *  Author: $author$
 *    Date: 5/28/2009
 **********************************************************************
 */
typedef cCreatedImplementT
<cWinHBRUSHImplement, cWinHBRUSHInterface>
cWinHBRUSHImplementImplements;
/**
 **********************************************************************
 *  Class: cWinHBRUSHImplement
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHBRUSHImplement
: virtual public cWinHBRUSHAttachedImplement,
  virtual public cWinHBRUSHImplementImplements
{
public:
    typedef cWinHBRUSHImplementImplements cImplements;
    typedef cWinHBRUSHImplement cDerives;
};
class c_EXPORT_CLASS cWinHBRUSH;
/**
 **********************************************************************
 * Typedef: cWinHBRUSHExtends
 *
 *  Author: $author$
 *    Date: 5/28/2009
 **********************************************************************
 */
typedef cCreatedT
<cWinHBRUSH, 
 cWinHBRUSHImplement, 
 cWinHBRUSHAttached>
cWinHBRUSHExtends;
/**
 **********************************************************************
 *  Class: cWinHBRUSH
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHBRUSH
: public cWinHBRUSHExtends
{
public:
    typedef cWinHBRUSHExtends cExtends;
    typedef cWinHBRUSH cDerives;

    /**
     **********************************************************************
     * Constructor: cWinHBRUSH
     *
     *      Author: $author$
     *        Date: 5/28/2009
     **********************************************************************
     */
    cWinHBRUSH
    (HBRUSH attached=NULL,
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
};
#endif /* _CWINHBRUSH_HXX */
