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
 *   File: cwinatomattached.hxx
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
#ifndef _CWINATOMATTACHED_HXX
#define _CWINATOMATTACHED_HXX

#include "cwininterfacebase.hxx"
#include "cwinbase.hxx"
#include "cattached.hxx"
#include "ccreated.hxx"
#include "cdebug.hxx"

class c_INTERFACE_CLASS cWinATOMAttachedInterface;
/**
 **********************************************************************
 * Typedef: cWinATOMAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/8/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cWinATOMAttachedInterface, 
 ATOM, UINT, NULL, cWinInterfaceBase>
cWinATOMAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinATOMAttachedInterface
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinATOMAttachedInterface
: virtual public cWinATOMAttachedInterfaceImplements
{
public:
    typedef cWinATOMAttachedInterfaceImplements cImplements;
    typedef cWinATOMAttachedInterface cDerives;
};
class c_EXPORT_CLASS cWinATOMAttachedImplement;
/**
 **********************************************************************
 * Typedef: cWinATOMAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 5/8/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cWinATOMAttachedImplement, 
 cWinATOMAttachedInterface, 
 ATOM, UINT, NULL>
cWinATOMAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cWinATOMAttachedImplement
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinATOMAttachedImplement
: virtual public cWinATOMAttachedImplementImplements
{
public:
    typedef cWinATOMAttachedImplementImplements cImplements;
    typedef cWinATOMAttachedImplement cDerives;
};
class c_EXPORT_CLASS cWinATOMAttached;
/**
 **********************************************************************
 * Typedef: cWinATOMAttachedExtends
 *
 *  Author: $author$
 *    Date: 5/8/2009
 **********************************************************************
 */
typedef cAttachedT
<cWinATOMAttached, 
 cWinATOMAttachedImplement, 
 cWinATOMAttachedInterface,
 ATOM, UINT, NULL, cWinBase>
cWinATOMAttachedExtends;
/**
 **********************************************************************
 *  Class: cWinATOMAttached
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinATOMAttached
: public cWinATOMAttachedExtends
{
public:
    typedef cWinATOMAttachedExtends cExtends;
    typedef cWinATOMAttached cDerives;
    /**
     **********************************************************************
     * Constructor: cWinATOMAttached
     *
     *      Author: $author$
     *        Date: 5/8/2009
     **********************************************************************
     */
    cWinATOMAttached
    (ATOM attached=NULL) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cWinATOMInterface;
/**
 **********************************************************************
 * Typedef: cWinATOMInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/8/2009
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cWinATOMInterface, cWinATOMAttachedInterface>
cWinATOMInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinATOMInterface
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinATOMInterface
: virtual public cWinATOMInterfaceImplements
{
public:
    typedef cWinATOMInterfaceImplements cImplements;
    typedef cWinATOMInterface cDerives;
};
class c_EXPORT_CLASS cWinATOMImplement;
/**
 **********************************************************************
 * Typedef: cWinATOMImplementImplements
 *
 *  Author: $author$
 *    Date: 5/8/2009
 **********************************************************************
 */
typedef cCreatedImplementT
<cWinATOMImplement, cWinATOMInterface>
cWinATOMImplementImplements;
/**
 **********************************************************************
 *  Class: cWinATOMImplement
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinATOMImplement
: virtual public cWinATOMImplementImplements
{
public:
    typedef cWinATOMImplementImplements cImplements;
    typedef cWinATOMImplement cDerives;
};
class c_EXPORT_CLASS cWinATOM;
/**
 **********************************************************************
 * Typedef: cWinATOMExtends
 *
 *  Author: $author$
 *    Date: 5/8/2009
 **********************************************************************
 */
typedef cCreatedT
<cWinATOM, 
 cWinATOMImplement, 
 cWinATOMAttached>
cWinATOMExtends;
/**
 **********************************************************************
 *  Class: cWinATOM
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinATOM
: public cWinATOMExtends
{
public:
    typedef cWinATOMExtends cExtends;
    typedef cWinATOM cDerives;
    /**
     **********************************************************************
     * Constructor: cWinATOM
     *
     *      Author: $author$
     *        Date: 5/8/2009
     **********************************************************************
     */
    cWinATOM
    (ATOM attached=NULL,
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    virtual eError Create
    (LPCTSTR name,
     bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_FAILED;
        eError error2;
        ATOM unattached, attached;

        if ((error2 = Destroyed(onlyDestroyed)))
            return error2;

        if (!(unattached = AddAtom(name)))
            DBE(("() failed on AddAtom()\n"));
        else
        if (unattached != (attached = Attach(unattached, true)))
            DestroyAttached(unattached);
        else
        error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
    {
        eError error = e_ERROR_NONE;
        ATOM attached;
        ATOM detached;
        bool isCreated;

        if (!(attached = Attached()))
        if (onlyCreated)
            return e_ERROR_NOT_ATTACHED;
        else
        if ((isCreated = IsCreated()))
            return e_ERROR_ALREADY_CREATED;
        else
        return e_ERROR_NONE;

        if (attached != (detached = Detach()))
            return e_ERROR_NOT_ATTACHED;

        error = DestroyAttached(attached);
        SetIsCreated(false);
        return error;
    }
    /**
     **********************************************************************
     * Function: DestroyAttached
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    virtual eError DestroyAttached
    (ATOM attached) 
    {
        eError error = e_ERROR_FAILED;
        ATOM detached;

        if ((detached = DeleteAtom(attached)))
            DBE(("() failed on DeleteAtom()\n"));
        else
        error = e_ERROR_NONE;
        return error;
    }
};
#endif /* _CWINATOMATTACHED_HXX */
