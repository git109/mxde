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
 *   File: cxtrectobj.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTRECTOBJ_HXX) || defined(CXTRECTOBJ_MEMBERS_ONLY)
#if !defined(_CXTRECTOBJ_HXX) && !defined(CXTRECTOBJ_MEMBERS_ONLY)
#define _CXTRECTOBJ_HXX
#endif /* !defined(_CXTRECTOBJ_HXX) && !defined(CXTRECTOBJ_MEMBERS_ONLY) */

#if !defined(CXTRECTOBJ_MEMBERS_ONLY)
#include "cxtrectobjinterface.hxx"
#include "cxtobject.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtRectObjExtend
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtObject
cXtRectObjExtend;
/**
 **********************************************************************
 *  Class: cXtRectObj
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtRectObj
: virtual public cXtRectObjImplement,
  public cXtRectObjExtend
{
public:
    typedef cXtRectObjImplement cImplements;
    typedef cXtRectObjExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtRectObj
     *
     *       Author: $author$           
     *         Date: 6/23/2010
     **********************************************************************
     */
    cXtRectObj
    (cXDisplayInterface& display,
     const XtChar* name = 0,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cXtRectObj
     *
     *       Author: $author$           
     *         Date: 6/23/2010
     **********************************************************************
     */
    cXtRectObj
    (cXDisplayInterface& display,
     const XtChar* name,
     WidgetClass widgetClassAttached,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtRectObj
     *
     *      Author: $author$           
     *        Date: 6/23/2010
     **********************************************************************
     */
    virtual ~cXtRectObj()
    {
    }
#else /* !defined(CXTRECTOBJ_MEMBERS_ONLY) */
#endif /* !defined(CXTRECTOBJ_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: SetRectangle
     *
     *    Author: $author$           
     *      Date: 6/19/2010
     **********************************************************************
     */
    virtual eError SetRectangle
    (XRectangle& rect)
#if defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        ArgList values = 0;
        XtArgVal argValX = rect.x;
        XtArgVal argValY = rect.y;
        XtArgVal argValWidth = rect.width;
        XtArgVal argValHeight = rect.height;

        DBF(("()...\n"));

        if (!(values = SetValuesL
            (XtNx, argValX, XtNy, argValY, 
             XtNwidth, argValWidth, XtNheight, argValHeight, 0)))
             error = error = e_ERROR_FAILED;
#else /* !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetRectangle
     *
     *    Author: $author$           
     *      Date: 6/19/2010
     **********************************************************************
     */
    virtual eError GetRectangle
    (XRectangle& rect)
#if defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        TLENGTH values = 0;
        XtArgVal argValX = 0;
        XtArgVal argValY = 0;
        XtArgVal argValWidth = 0;
        XtArgVal argValHeight = 0;

        DBF(("()...\n"));

        if (0 > (values = GetValuesL
            (XtNx, &argValX, XtNy, &argValY, 
             XtNwidth, &argValWidth, XtNheight, &argValHeight, 0)))
             error = -values;
        else
        {
            rect.x = (XOffset)(argValX);
            rect.y = (XOffset)(argValY);
            rect.width = (XSize)(argValWidth);
            rect.height = (XSize)(argValHeight);
        }
#else /* !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetX
     *
     *    Author: $author$           
     *      Date: 5/17/2010
     **********************************************************************
     */
    virtual TLENGTH GetX()
#if defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH value = 0;
        XtArgVal argVal = 0;
        if (0 <= (value = GetValuesL(XtNx, &argVal, 0)))
            value = (TLENGTH)(argVal);
#else /* !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetY
     *
     *    Author: $author$           
     *      Date: 5/17/2010
     **********************************************************************
     */
    virtual TLENGTH GetY()
#if defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH value = 0;
        XtArgVal argVal = 0;
        if (0 <= (value = GetValuesL(XtNy, &argVal, 0)))
            value = (TLENGTH)(argVal);
#else /* !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetWidth
     *
     *    Author: $author$           
     *      Date: 5/17/2010
     **********************************************************************
     */
    virtual TLENGTH GetWidth()
#if defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH value = 0;
        XtArgVal argVal = 0;
        if (0 <= (value = GetValuesL(XtNwidth, &argVal, 0)))
            value = (TLENGTH)(argVal);
#else /* !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetHeight
     *
     *    Author: $author$           
     *      Date: 5/17/2010
     **********************************************************************
     */
    virtual TLENGTH GetHeight()
#if defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH value = 0;
        XtArgVal argVal = 0;
        if (0 <= (value = GetValuesL(XtNheight, &argVal, 0)))
            value = (TLENGTH)(argVal);
#else /* !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CXTRECTOBJ_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTRECTOBJ_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTRECTOBJ_MEMBERS_ONLY) */
#endif /* !defined(CXTRECTOBJ_MEMBERS_ONLY) */

#endif /* !defined(_CXTRECTOBJ_HXX) || defined(CXTRECTOBJ_MEMBERS_ONLY) */
