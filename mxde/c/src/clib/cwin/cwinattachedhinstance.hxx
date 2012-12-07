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
 *   File: cwinattachedhinstance.hxx
 *
 * Author: $author$
 *   Date: 12/13/2009
 **********************************************************************
 */
#if !defined(_CWINATTACHEDHINSTANCE_HXX) || defined(CWINATTACHEDHINSTANCE_MEMBERS_ONLY)
#if !defined(_CWINATTACHEDHINSTANCE_HXX) && !defined(CWINATTACHEDHINSTANCE_MEMBERS_ONLY)
#define _CWINATTACHEDHINSTANCE_HXX
#endif /* !defined(_CWINATTACHEDHINSTANCE_HXX) && !defined(CWINATTACHEDHINSTANCE_MEMBERS_ONLY) */

#if !defined(CWINATTACHEDHINSTANCE_MEMBERS_ONLY)
#include "cwinattachedhinstanceinterface.hxx"
#include "cwinbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinAttachedHINSTANCEImplements
 *
 *  Author: $author$
 *    Date: 12/13/2009
 **********************************************************************
 */
typedef cWinAttachedHINSTANCEImplement
cWinAttachedHINSTANCEImplements;
/**
 **********************************************************************
 * Typedef: cWinAttachedHINSTANCEExtends
 *
 *  Author: $author$
 *    Date: 12/13/2009
 **********************************************************************
 */
typedef cWinBase
cWinAttachedHINSTANCEExtends;
/**
 **********************************************************************
 *  Class: cWinAttachedHINSTANCE
 *
 * Author: $author$
 *   Date: 12/13/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinAttachedHINSTANCE
: virtual public cWinAttachedHINSTANCEImplements,
  public cWinAttachedHINSTANCEExtends
{
public:
    typedef cWinAttachedHINSTANCEExtends cExtends;
    
    HINSTANCE m_hInstance;
    
    /**
     **********************************************************************
     *  Constructor: cWinAttachedHINSTANCE
     *
     *       Author: $author$
     *         Date: 12/13/2009
     **********************************************************************
     */
    cWinAttachedHINSTANCE
    (HINSTANCE hInstance=NULL)
    : m_hInstance(hInstance)
    {
    }
#else /* !defined(CWINATTACHEDHINSTANCE_MEMBERS_ONLY) */
#endif /* !defined(CWINATTACHEDHINSTANCE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: AttachInstance
     *
     *   Author: $author$
     *     Date: 12/13/2009
     **********************************************************************
     */
    virtual HINSTANCE AttachInstance
    (HINSTANCE hToInstance,
     bool onlyDetached=false) 
#if defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_INTERFACE) */
    {
        HINSTANCE hInstance = NULL;
#if !defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_IMPLEMENT)
        hInstance = (m_hInstance = hToInstance); 
#else /* !defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_IMPLEMENT) */
        return hInstance;
    }
#endif /* defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DetachInstance
     *
     *   Author: $author$
     *     Date: 12/13/2009
     **********************************************************************
     */
    virtual HINSTANCE DetachInstance() 
#if defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_INTERFACE) */
    {
        HINSTANCE hInstance = NULL;
#if !defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_IMPLEMENT) 
        hInstance = (m_hInstance);
        m_hInstance = NULL; 
#else /* !defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_IMPLEMENT) */
        return hInstance;
    }
#endif /* defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AttachedInstance
     *
     *   Author: $author$
     *     Date: 12/13/2009
     **********************************************************************
     */
    virtual HINSTANCE AttachedInstance() const
#if defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_INTERFACE) */
    {
        HINSTANCE hInstance = NULL;
#if !defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_IMPLEMENT) 
        hInstance = (m_hInstance);
#else /* !defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_IMPLEMENT) */
        return hInstance;
    }
#endif /* defined(CWINATTACHEDHINSTANCE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINATTACHEDHINSTANCE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINATTACHEDHINSTANCE_MEMBERS_ONLY) */
#endif /* !defined(CWINATTACHEDHINSTANCE_MEMBERS_ONLY) */

#endif /* !defined(_CWINATTACHEDHINSTANCE_HXX) || defined(CWINATTACHEDHINSTANCE_MEMBERS_ONLY) */
