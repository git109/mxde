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
 *   File: cxpixelattached.hxx
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
#if !defined(_CXPIXELATTACHED_HXX) || defined(CXPIXELATTACHED_MEMBERS_ONLY)
#if !defined(_CXPIXELATTACHED_HXX) && !defined(CXPIXELATTACHED_MEMBERS_ONLY)
#define _CXPIXELATTACHED_HXX
#endif /* !defined(_CXPIXELATTACHED_HXX) && !defined(CXPIXELATTACHED_MEMBERS_ONLY) */

#if !defined(CXPIXELATTACHED_MEMBERS_ONLY)
#include "cxbaseinterface.hxx"
#include "cxbase.hxx"
#include "cattached.hxx"
#include "callocated.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */


class c_INTERFACE_CLASS cXPixelAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXPixelAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 7/5/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXPixelAttachedInterface, 
 Pixel, UINT, NULL, cXBaseInterface>
cXPixelAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXPixelAttachedInterface
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXPixelAttachedInterface
: virtual public cXPixelAttachedInterfaceImplements
{
public:
    typedef cXPixelAttachedInterfaceImplements cImplements;
    typedef cXPixelAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXPixelAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXPixelAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 7/5/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cXPixelAttachedImplement, 
 cXPixelAttachedInterface, 
 Pixel, UINT, NULL>
cXPixelAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXPixelAttachedImplement
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXPixelAttachedImplement
: virtual public cXPixelAttachedImplementImplements
{
public:
    typedef cXPixelAttachedImplementImplements cImplements;
    typedef cXPixelAttachedImplement cDerives;
};
class c_EXPORT_CLASS cXPixelAttached;
/**
 **********************************************************************
 * Typedef: cXPixelAttachedExtends
 *
 *  Author: $author$           
 *    Date: 7/5/2009
 **********************************************************************
 */
typedef cAttachedT
<cXPixelAttached, 
 cXPixelAttachedImplement, 
 cXPixelAttachedInterface,
 Pixel, UINT, NULL, cXBase>
cXPixelAttachedExtends;
/**
 **********************************************************************
 *  Class: cXPixelAttached
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXPixelAttached
: public cXPixelAttachedExtends
{
public:
    typedef cXPixelAttachedExtends cExtends;
    typedef cXPixelAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXPixelAttached
     *
     *      Author: $author$           
     *        Date: 7/5/2009
     **********************************************************************
     */
    cXPixelAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cXPixelAllocatedInterface;
/**
 **********************************************************************
 * Typedef: cXPixelAllocatedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 7/5/2009
 **********************************************************************
 */
typedef cAllocatedInterfaceT
<cXPixelAllocatedInterface, cXPixelAttachedInterface>
cXPixelAllocatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXPixelAllocatedInterface
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXPixelAllocatedInterface
: virtual public cXPixelAllocatedInterfaceImplements
{
public:
    typedef cXPixelAllocatedInterfaceImplements cImplements;
    typedef cXPixelAllocatedInterface cDerives;
};
class c_EXPORT_CLASS cXPixelAllocatedImplement;
/**
 **********************************************************************
 * Typedef: cXPixelAllocatedImplementImplements
 *
 *  Author: $author$           
 *    Date: 7/5/2009
 **********************************************************************
 */
typedef cAllocatedImplementT
<cXPixelAllocatedImplement, cXPixelAllocatedInterface>
cXPixelAllocatedImplementImplements;
/**
 **********************************************************************
 *  Class: cXPixelAllocatedImplement
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXPixelAllocatedImplement
: virtual public cXPixelAttachedImplement,
  virtual public cXPixelAllocatedImplementImplements
{
public:
    typedef cXPixelAllocatedImplementImplements cImplements;
    typedef cXPixelAllocatedImplement cDerives;
};
class c_EXPORT_CLASS cXPixelAllocated;
/**
 **********************************************************************
 * Typedef: cXPixelAllocatedExtends
 *
 *  Author: $author$           
 *    Date: 7/5/2009
 **********************************************************************
 */
typedef cAllocatedT
<cXPixelAllocated, 
 cXPixelAllocatedImplement, 
 cXPixelAttached>
cXPixelAllocatedExtends;
#if !defined(CXPIXELALLOCATED_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXPixelAllocated
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXPixelAllocated
: public cXPixelAllocatedExtends
{
public:
    typedef cXPixelAllocatedExtends cExtends;
    typedef cXPixelAllocated cDerives;

    /**
     **********************************************************************
     * Constructor: cXPixelAllocated
     *
     *      Author: $author$           
     *        Date: 7/5/2009
     **********************************************************************
     */
    cXPixelAllocated
    (Pixel attached=0,
     bool isAllocated=false) 
    : cExtends(isAllocated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cXPixelAllocated
     *
     *     Author: $author$           
     *       Date: 7/5/2009
     **********************************************************************
     */
    virtual ~cXPixelAllocated()
    {
        eError error;
        if ((error = Freed()))
        {
            DBE(("()\n throwing error=%d\n", (int)(error)));
            throw (error);
        }
    }
#else /* !defined(CXPIXELALLOCATED_MEMBERS_ONLY) */
#endif /* !defined(CXPIXELALLOCATED_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: AttachIsAllocated
     *
     *    Author: $author$           
     *      Date: 6/8/2010
     **********************************************************************
     */
    virtual int AttachIsAllocated
    (Pixel detached, bool isAllocated = true)
#if defined(CXPIXELALLOCATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPIXELALLOCATED_MEMBER_FUNCS_INTERFACE) */
    {
        int isTrue = -e_ERROR_FAILED;

        if (detached == (Attach(detached)))
        if (0 <= (SetIsAllocated(isAllocated)))
            return detached;
        else
        Detach();
#if !defined(CXPIXELALLOCATED_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXPIXELALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXPIXELALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
        return isTrue;
    }
#endif /* defined(CXPIXELALLOCATED_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXPIXELALLOCATED_MEMBERS_ONLY)
};
#else /* !defined(CXPIXELALLOCATED_MEMBERS_ONLY) */
#endif /* !defined(CXPIXELALLOCATED_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXPIXELATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXPIXELATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXPIXELATTACHED_HXX) || defined(CXPIXELATTACHED_MEMBERS_ONLY) */
