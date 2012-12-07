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
 *   File: cwinhpen.hxx
 *
 * Author: $author$
 *   Date: 6/5/2009
 **********************************************************************
 */
#if !defined(_CWINHPEN_HXX) || defined(CWINHPENATTACHED_MEMBERS_ONLY)
#if !defined(_CWINHPEN_HXX) && !defined(CWINHPENATTACHED_MEMBERS_ONLY)
#define _CWINHPEN_HXX
#endif /* !defined(_CWINHPEN_HXX) && !defined(CWINHPENATTACHED_MEMBERS_ONLY) */

#include "cwininterfacebase.hxx"
#include "cwinbase.hxx"
#include "cattached.hxx"
#include "ccreated.hxx"

class c_INTERFACE_CLASS cWinHPENAttachedInterface;
/**
 **********************************************************************
 * Typedef: cWinHPENAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 6/5/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cWinHPENAttachedInterface, 
 HPEN, UINT, NULL, cWinInterfaceBase>
cWinHPENAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinHPENAttachedInterface
 *
 * Author: $author$
 *   Date: 6/5/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHPENAttachedInterface
: virtual public cWinHPENAttachedInterfaceImplements
{
public:
    typedef cWinHPENAttachedInterfaceImplements cImplements;
    typedef cWinHPENAttachedInterface cDerives;
};
class c_EXPORT_CLASS cWinHPENAttachedImplement;
/**
 **********************************************************************
 * Typedef: cWinHPENAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 6/5/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cWinHPENAttachedImplement, 
 cWinHPENAttachedInterface, 
 HPEN, UINT, NULL>
cWinHPENAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cWinHPENAttachedImplement
 *
 * Author: $author$
 *   Date: 6/5/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHPENAttachedImplement
: virtual public cWinHPENAttachedImplementImplements
{
public:
    typedef cWinHPENAttachedImplementImplements cImplements;
    typedef cWinHPENAttachedImplement cDerives;
};
class c_EXPORT_CLASS cWinHPENAttached;
/**
 **********************************************************************
 * Typedef: cWinHPENAttachedExtends
 *
 *  Author: $author$
 *    Date: 6/5/2009
 **********************************************************************
 */
typedef cAttachedT
<cWinHPENAttached, 
 cWinHPENAttachedImplement, 
 cWinHPENAttachedInterface,
 HPEN, UINT, NULL, cWinBase>
cWinHPENAttachedExtends;
/**
 **********************************************************************
 *  Class: cWinHPENAttached
 *
 * Author: $author$
 *   Date: 6/5/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHPENAttached
: public cWinHPENAttachedExtends
{
public:
    typedef cWinHPENAttachedExtends cExtends;
    typedef cWinHPENAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cWinHPENAttached
     *
     *      Author: $author$
     *        Date: 6/5/2009
     **********************************************************************
     */
    cWinHPENAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cWinHPENInterface;
/**
 **********************************************************************
 * Typedef: cWinHPENInterfaceImplements
 *
 *  Author: $author$
 *    Date: 6/5/2009
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cWinHPENInterface, cWinHPENAttachedInterface>
cWinHPENInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinHPENInterface
 *
 * Author: $author$
 *   Date: 6/5/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHPENInterface
: virtual public cWinHPENInterfaceImplements
{
public:
    typedef cWinHPENInterfaceImplements cImplements;
    typedef cWinHPENInterface cDerives;
};
class c_EXPORT_CLASS cWinHPENImplement;
/**
 **********************************************************************
 * Typedef: cWinHPENImplementImplements
 *
 *  Author: $author$
 *    Date: 6/5/2009
 **********************************************************************
 */
typedef cCreatedImplementT
<cWinHPENImplement, cWinHPENInterface>
cWinHPENImplementImplements;
/**
 **********************************************************************
 *  Class: cWinHPENImplement
 *
 * Author: $author$
 *   Date: 6/5/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHPENImplement
: virtual public cWinHPENImplementImplements
{
public:
    typedef cWinHPENImplementImplements cImplements;
    typedef cWinHPENImplement cDerives;
};
class c_EXPORT_CLASS cWinHPEN;
/**
 **********************************************************************
 * Typedef: cWinHPENExtends
 *
 *  Author: $author$
 *    Date: 6/5/2009
 **********************************************************************
 */
typedef cCreatedT
<cWinHPEN, 
 cWinHPENImplement, 
 cWinHPENAttached>
cWinHPENExtends;
/**
 **********************************************************************
 *  Class: cWinHPEN
 *
 * Author: $author$
 *   Date: 6/5/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHPEN
: public cWinHPENExtends
{
public:
    typedef cWinHPENExtends cExtends;
    typedef cWinHPEN cDerives;

    /**
     **********************************************************************
     * Constructor: cWinHPEN
     *
     *      Author: $author$
     *        Date: 6/5/2009
     **********************************************************************
     */
    cWinHPEN
    (HPEN attached=NULL,
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }

    /**
     **********************************************************************
     * Function: CreateDetached
     *
     *   Author: $author$
     *     Date: 6/5/2009
     **********************************************************************
     */
    virtual HPEN CreateDetached
    (eError& error,
     const COLORREF& color,
     int style=PS_SOLID,
     int width=1) 
    {
        HPEN hPen = NULL;
        if ((hPen = CreatePen(style, width, color)))
            error = e_ERROR_NONE;
        else
        error = e_ERROR_FAILED;
        return hPen;
    }
    /**
     **********************************************************************
     * Function: DestroyDetached
     *
     *   Author: $author$
     *     Date: 6/5/2009
     **********************************************************************
     */
    virtual eError DestroyDetached
    (HPEN hPen) 
    {
        eError error = e_ERROR_FAILED;
        if (hPen)
        if ((DeleteObject(hPen)))
            error = e_ERROR_NONE;
        return error;
    }
};
#endif /* !defined(_CWINHPEN_HXX) || defined(CWINHPENATTACHED_MEMBERS_ONLY) */
