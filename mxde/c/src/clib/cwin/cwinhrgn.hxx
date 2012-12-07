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
 *   File: cwinhrgn.hxx
 *
 * Author: $author$
 *   Date: 5/20/2009
 **********************************************************************
 */
#if !defined(_CWINHRGN_HXX) || defined(CWINHRGNATTACHED_MEMBERS_ONLY)
#if !defined(_CWINHRGN_HXX) && !defined(CWINHRGNATTACHED_MEMBERS_ONLY)
#define _CWINHRGN_HXX
#endif /* !defined(_CWINHRGN_HXX) && !defined(CWINHRGNATTACHED_MEMBERS_ONLY) */

#include "cwinhrgnattached.hxx"
#include "ccreated.hxx"

class c_INTERFACE_CLASS cWinHRGNInterface;
/**
 **********************************************************************
 * Typedef: cWinHRGNInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/20/2009
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cWinHRGNInterface, cWinHRGNAttachedInterface>
cWinHRGNInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinHRGNInterface
 *
 * Author: $author$
 *   Date: 5/20/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHRGNInterface
: virtual public cWinHRGNInterfaceImplements
{
public:
    typedef cWinHRGNInterfaceImplements cImplements;
    typedef cWinHRGNInterface cDerives;
};
class c_EXPORT_CLASS cWinHRGNImplement;
/**
 **********************************************************************
 * Typedef: cWinHRGNImplementImplements
 *
 *  Author: $author$
 *    Date: 5/20/2009
 **********************************************************************
 */
typedef cCreatedImplementT
<cWinHRGNImplement, cWinHRGNInterface>
cWinHRGNImplementImplements;
/**
 **********************************************************************
 *  Class: cWinHRGNImplement
 *
 * Author: $author$
 *   Date: 5/20/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHRGNImplement
: virtual public cWinHRGNImplementImplements
{
public:
    typedef cWinHRGNImplementImplements cImplements;
    typedef cWinHRGNImplement cDerives;
};
class c_EXPORT_CLASS cWinHRGN;
/**
 **********************************************************************
 * Typedef: cWinHRGNExtends
 *
 *  Author: $author$
 *    Date: 5/20/2009
 **********************************************************************
 */
typedef cCreatedT
<cWinHRGN, 
 cWinHRGNImplement, 
 cWinHRGNAttached>
cWinHRGNExtends;
/**
 **********************************************************************
 *  Class: cWinHRGN
 *
 * Author: $author$
 *   Date: 5/20/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHRGN
: public cWinHRGNExtends
{
public:
    typedef cWinHRGNExtends cExtends;
    typedef cWinHRGN cDerives;

    cWinHRGN
    (HRGN attached=NULL,
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        eError error;
        if (attached)
        if (attached != (Attach(attached)))
            throw(error = e_ERROR_NOT_ATTACHED);
    }
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 5/20/2009
     **********************************************************************
     */
    virtual tAttachedTo Detach() 
#if defined(CWINHRGN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINHRGN_MEMBER_FUNCS_INTERFACE */
    {
       tAttachedTo  attached = (tAttachedTo)(vUnattached);
#if !defined(CWINHRGN_MEMBER_FUNCS_IMPLEMENT) 
        SetIsCreated(false);
        attached = cExtends::Detach();
#else /* !defined(CWINHRGN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINHRGN_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
    }
#endif /* defined(CWINHRGN_MEMBER_FUNCS_INTERFACE) */
};
#endif /* !defined(_CWINHRGN_HXX) || defined(CWINHRGNATTACHED_MEMBERS_ONLY) */
