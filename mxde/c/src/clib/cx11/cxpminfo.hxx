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
 *   File: cxpminfo.hxx
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
#if !defined(_CXPMINFO_HXX) || defined(CXPMINFO_MEMBERS_ONLY)
#if !defined(_CXPMINFO_HXX) && !defined(CXPMINFO_MEMBERS_ONLY)
#define _CXPMINFO_HXX
#endif /* !defined(_CXPMINFO_HXX) && !defined(CXPMINFO_MEMBERS_ONLY) */

#if !defined(CXPMINFO_MEMBERS_ONLY)
#include "cxpminfointerface.hxx"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cXpmInfoCreated;
/**
 **********************************************************************
 * Typedef: cXpmInfoCreatedExtends
 *
 *  Author: $author$           
 *    Date: 6/4/2010
 **********************************************************************
 */
typedef cCreatedT
<cXpmInfoCreated, 
 cXpmInfoCreatedImplement, 
 cBase>
cXpmInfoCreatedExtends;
/**
 **********************************************************************
 *  Class: cXpmInfoCreated
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXpmInfoCreated
: public cXpmInfoCreatedExtends
{
public:
    typedef cXpmInfoCreatedExtends cExtends;
    typedef cXpmInfoCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cXpmInfoCreated
     *
     *      Author: $author$           
     *        Date: 6/4/2010
     **********************************************************************
     */
    cXpmInfoCreated
    (bool isCreated=false) 
    : cExtends(isCreated) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXpmInfoCreated
     *
     *     Author: $author$           
     *       Date: 6/4/2010
     **********************************************************************
     */
    virtual ~cXpmInfoCreated()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
};
/**
 **********************************************************************
 * Typedef: cXpmInfoExtend
 *
 *  Author: $author$           
 *    Date: 6/4/2010
 **********************************************************************
 */
typedef cXpmInfoCreated
cXpmInfoExtend;
/**
 **********************************************************************
 *  Class: cXpmInfo
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXpmInfo
: virtual public cXpmInfoImplement,
  public cXpmInfoExtend
{
public:
    typedef cXpmInfoImplement cImplements;
    typedef cXpmInfoExtend cExtends;

    XpmInfo m_xpmInfo;

    /**
     **********************************************************************
     *  Constructor: cXpmInfo
     *
     *       Author: $author$           
     *         Date: 6/4/2010
     **********************************************************************
     */
    cXpmInfo
    (bool isCreated=false) 
    : cExtends(isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXpmInfo
     *
     *      Author: $author$           
     *        Date: 6/4/2010
     **********************************************************************
     */
    virtual ~cXpmInfo()
    {
        eError error;
        if ((error = Destroyed()))
        {
            DBE(("() throwing error = %d\n", error));
            throw (error);
        }
    }
#else /* !defined(CXPMINFO_MEMBERS_ONLY) */
#endif /* !defined(CXPMINFO_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Destroy
     *
     *    Author: $author$           
     *      Date: 6/4/2010
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated = false)
#if defined(CXPMINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPMINFO_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPMINFO_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;

        if ((IsCreated()))
        {
            DBI(("() XpmFreeXpmInfo()...\n"));
            XpmFreeXpmInfo(&m_xpmInfo);
            SetIsCreated(false);
        }
        else
        if ((onlyCreated))
            error = e_ERROR_NOT_CREATED;

#else /* !defined(CXPMINFO_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPMINFO_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPMINFO_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXPMINFO_MEMBER_FUNCS_IMPLEMENT)
    /**
     **********************************************************************
     *  Function: operator XpmInfo&
     *
     *    Author: $author$           
     *      Date: 6/4/2010
     **********************************************************************
     */
    virtual operator XpmInfo&() const
#if defined(CXPMINFO_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPMINFO_MEMBER_FUNCS_INTERFACE) */
    {
        XpmInfo& xpmInfo = (XpmInfo&)(m_xpmInfo);
        return xpmInfo;
    }
#endif /* defined(CXPMINFO_MEMBER_FUNCS_INTERFACE) */
#else /* !defined(CXPMINFO_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXPMINFO_MEMBER_FUNCS_IMPLEMENT) */

#if !defined(CXPMINFO_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXPMINFO_MEMBERS_ONLY) */
#endif /* !defined(CXPMINFO_MEMBERS_ONLY) */

#endif /* !defined(_CXPMINFO_HXX) || defined(CXPMINFO_MEMBERS_ONLY) */
