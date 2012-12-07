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
 *   File: cmidpointcircleimageobject.hxx
 *
 * Author: $author$
 *   Date: 8/10/2009
 **********************************************************************
 */
#if !defined(_CMIDPOINTCIRCLEIMAGEOBJECT_HXX) || defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_CMIDPOINTCIRCLEIMAGEOBJECT_HXX) && !defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY)
#define _CMIDPOINTCIRCLEIMAGEOBJECT_HXX
#endif /* !defined(_CMIDPOINTCIRCLEIMAGEOBJECT_HXX) && !defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY)
#include "cimageobject.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cMidpointCircleImageObject
 *
 * Author: $author$
 *   Date: 8/10/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cMidpointCircleImageObject
: public cImageObject
{
public:
    typedef cImageObject cExtends;
    
    /**
     **********************************************************************
     *  Constructor: cMidpointCircleImageObject
     *
     *       Author: $author$
     *         Date: 8/10/2009
     **********************************************************************
     */
    cMidpointCircleImageObject
    (cImageInterface& image)
    : cExtends(image)
    {
    }
#else /* !defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 8/10/2009
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x,tOffset y) 
#if defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 8/10/2009
     **********************************************************************
     */
    virtual eError Fill
    (tOffset x,tOffset y,
     tSize w,tSize h) 
#if defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_INTERFACE) */
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CMIDPOINTCIRCLEIMAGEOBJECT_HXX) || defined(CMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY) */
