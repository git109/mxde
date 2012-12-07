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
 *   File: cloaded.hxx
 *
 * Author: $author$
 *   Date: 6/14/2010
 **********************************************************************
 */
#if !defined(_CLOADED_HXX) || defined(CLOADED_MEMBERS_ONLY)
#if !defined(_CLOADED_HXX) && !defined(CLOADED_MEMBERS_ONLY)
#define _CLOADED_HXX
#endif /* !defined(_CLOADED_HXX) && !defined(CLOADED_MEMBERS_ONLY) */

#if !defined(CLOADED_MEMBERS_ONLY)
#include "cloadedinterface.hxx"
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cLoadedExtend
 *
 *  Author: $author$
 *    Date: 6/14/2010
 **********************************************************************
 */
typedef cBase
cLoadedExtend;

class c_INSTANCE_CLASS cLoaded;

#undef CDB_CLASS
#define CDB_CLASS "cLoadedT"
/**
 **********************************************************************
 *  Class: cLoadedT
 *
 * Author: $author$
 *   Date: 6/14/2010
 **********************************************************************
 */
template
<class TDerives=cLoaded,
 class TLoadedImplement=cLoadedImplement,
 class TLoadedExtend=cLoadedExtend,
 class TBool=bool,
 TBool VTrue=true,
 TBool VFalse=false,
 class TInt=int,
 class TImplements=TLoadedImplement,
 class TExtends=TLoadedExtend>

class c_INSTANCE_CLASS cLoadedT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    
/* include cLoaded interface member definitions
 */
#define CLOADEDINTERFACE_MEMBERS_ONLY
#include "cloadedinterface.hxx"
#undef CLOADEDINTERFACE_MEMBERS_ONLY

    tBool m_isLoaded;

    /**
     **********************************************************************
     *  Constructor: cLoadedT
     *
     *       Author: $author$
     *         Date: 6/14/2010
     **********************************************************************
     */
    cLoadedT
    (tBool isLoaded = vFalse)
    : m_isLoaded(isLoaded)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cLoadedT
     *
     *      Author: $author$
     *        Date: 6/14/2010
     **********************************************************************
     */
    virtual ~cLoadedT()
    {
    }
#else /* !defined(CLOADED_MEMBERS_ONLY) */
#endif /* !defined(CLOADED_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: UnLoaded
     *
     *    Author: $author$
     *      Date: 6/14/2010
     **********************************************************************
     */
    virtual eError UnLoaded
    (bool onlyUnLoaded = false,
     bool dontUnLoad = false)
#if defined(CLOADED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CLOADED_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;

        if ((IsLoaded()))
        if (onlyUnLoaded)
            error = e_ERROR_ALREADY_LOADED;
        else
        if (!dontUnLoad)
            error = UnLoad(true);

#if !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CLOADED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Load
     *
     *    Author: $author$
     *      Date: 6/15/2010
     **********************************************************************
     */
    virtual eError Load
    (bool onlyUnLoaded = false)
#if defined(CLOADED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CLOADED_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CLOADED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: UnLoad
     *
     *    Author: $author$
     *      Date: 6/15/2010
     **********************************************************************
     */
    virtual eError UnLoad
    (bool onlyLoaded = false)
#if defined(CLOADED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CLOADED_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CLOADED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetIsLoaded
     *
     *    Author: $author$
     *      Date: 6/14/2010
     **********************************************************************
     */
    virtual tInt SetIsLoaded
    (tBool isTrue = vTrue)
#if defined(CLOADED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CLOADED_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT)
        tInt isLoaded = (tInt)(m_isLoaded = isTrue);
#else /* !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT) */
        int isLoaded = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT) */
        return isLoaded;
    }
#endif /* defined(CLOADED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: IsLoaded
     *
     *    Author: $author$
     *      Date: 6/15/2010
     **********************************************************************
     */
    virtual tBool IsLoaded() const
#if defined(CLOADED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CLOADED_MEMBER_FUNCS_INTERFACE) */
    {
        tBool isTrue = vFalse;
#if !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT)
        isTrue = (m_isLoaded);
#else /* !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CLOADED_MEMBER_FUNCS_IMPLEMENT) */
        return isTrue;
    }
#endif /* defined(CLOADED_MEMBER_FUNCS_INTERFACE) */

#if !defined(CLOADED_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cLoadedExtends
 *
 *  Author: $author$
 *    Date: 6/14/2010
 **********************************************************************
 */
typedef cLoadedT<>
cLoadedExtends;
/**
 **********************************************************************
 *  Class: cLoaded
 *
 * Author: $author$
 *   Date: 6/14/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cLoaded
: public cLoadedExtends
{
public:
    typedef cLoadedExtends cExtends;
    typedef cLoaded cDerives;
    /**
     **********************************************************************
     * Constructor: cLoaded
     *
     *      Author: $author$
     *        Date: 6/14/2010
     **********************************************************************
     */
    cLoaded
    (tBool isLoaded = vFalse) 
    : cExtends(isLoaded)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CLOADED_MEMBERS_ONLY) */
#endif /* !defined(CLOADED_MEMBERS_ONLY) */

#endif /* !defined(_CLOADED_HXX) || defined(CLOADED_MEMBERS_ONLY) */
