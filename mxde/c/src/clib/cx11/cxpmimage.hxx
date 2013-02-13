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
 *   File: cxpmimage.hxx
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
#if !defined(_CXPMIMAGE_HXX) || defined(CXPMIMAGE_MEMBERS_ONLY)
#if !defined(_CXPMIMAGE_HXX) && !defined(CXPMIMAGE_MEMBERS_ONLY)
#define _CXPMIMAGE_HXX
#endif /* !defined(_CXPMIMAGE_HXX) && !defined(CXPMIMAGE_MEMBERS_ONLY) */

#if !defined(CXPMIMAGE_MEMBERS_ONLY)
#include "cxpmimageinterface.hxx"
#include "cxbase.hxx"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cXpmImageCreated;
/**
 **********************************************************************
 * Typedef: cXpmImageCreatedExtends
 *
 *  Author: $author$           
 *    Date: 6/4/2010
 **********************************************************************
 */
typedef cCreatedT
<cXpmImageCreated, 
 cXpmImageCreatedImplement, 
 cXBase>
cXpmImageCreatedExtends;
/**
 **********************************************************************
 *  Class: cXpmImageCreated
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXpmImageCreated
: public cXpmImageCreatedExtends
{
public:
    typedef cXpmImageCreatedExtends cExtends;
    typedef cXpmImageCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cXpmImageCreated
     *
     *      Author: $author$           
     *        Date: 6/4/2010
     **********************************************************************
     */
    cXpmImageCreated
    (bool isCreated=false) 
    : cExtends(isCreated) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXpmImageCreated
     *
     *     Author: $author$           
     *       Date: 6/4/2010
     **********************************************************************
     */
    virtual ~cXpmImageCreated()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
};
/**
 **********************************************************************
 * Typedef: cXpmImageExtend
 *
 *  Author: $author$           
 *    Date: 6/4/2010
 **********************************************************************
 */
typedef cXpmImageCreated
cXpmImageExtend;
/**
 **********************************************************************
 *  Class: cXpmImage
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXpmImage
: virtual public cXpmImageImplement,
  public cXpmImageExtend
{
public:
    typedef cXpmImageImplement cImplements;
    typedef cXpmImageExtend cExtends;

    XpmImage m_xpmImage;

    /**
     **********************************************************************
     *  Constructor: cXpmImage
     *
     *       Author: $author$           
     *         Date: 6/4/2010
     **********************************************************************
     */
    cXpmImage
    (bool isCreated=false) 
    : cExtends(isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXpmImage
     *
     *      Author: $author$           
     *        Date: 6/4/2010
     **********************************************************************
     */
    virtual ~cXpmImage()
    {
        eError error;
        if ((error = Destroyed()))
        {
            DBE(("() throwing error = %d\n", error));
            throw (error);
        }
    }
#else /* !defined(CXPMIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CXPMIMAGE_MEMBERS_ONLY) */

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
#if defined(CXPMIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPMIMAGE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPMIMAGE_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;

        if ((IsCreated()))
        {
            DBI(("() XpmFreeXpmImage()...\n"));
            XpmFreeXpmImage(&m_xpmImage);
            SetIsCreated(false);
        }
        else
        if ((onlyCreated))
            error = e_ERROR_NOT_CREATED;

#else /* !defined(CXPMIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPMIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPMIMAGE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXPMIMAGE_MEMBER_FUNCS_IMPLEMENT)
    /**
     **********************************************************************
     *  Function: operator XpmImage&
     *
     *    Author: $author$           
     *      Date: 6/4/2010
     **********************************************************************
     */
    virtual operator XpmImage&() const
#if defined(CXPMIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPMIMAGE_MEMBER_FUNCS_INTERFACE) */
    {
        XpmImage& xpmImage = (XpmImage&)(m_xpmImage);
        return xpmImage;
    }
#endif /* defined(CXPMIMAGE_MEMBER_FUNCS_INTERFACE) */
#else /* !defined(CXPMIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXPMIMAGE_MEMBER_FUNCS_IMPLEMENT) */

#if !defined(CXPMIMAGE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXPMIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CXPMIMAGE_MEMBERS_ONLY) */

#endif /* !defined(_CXPMIMAGE_HXX) || defined(CXPMIMAGE_MEMBERS_ONLY) */
