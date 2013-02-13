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
 *   File: cxttextwidget.hxx
 *
 * Author: $author$           
 *   Date: 5/16/2010
 **********************************************************************
 */
#if !defined(_CXTTEXTWIDGET_HXX) || defined(CXTTEXTWIDGET_MEMBERS_ONLY)
#if !defined(_CXTTEXTWIDGET_HXX) && !defined(CXTTEXTWIDGET_MEMBERS_ONLY)
#define _CXTTEXTWIDGET_HXX
#endif /* !defined(_CXTTEXTWIDGET_HXX) && !defined(CXTTEXTWIDGET_MEMBERS_ONLY) */

#if !defined(CXTTEXTWIDGET_MEMBERS_ONLY)
#include "cxtwidget.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtTextWidgetExtend
 *
 *  Author: $author$           
 *    Date: 5/16/2010
 **********************************************************************
 */
typedef cXtWidget
cXtTextWidgetExtend;
/**
 **********************************************************************
 *  Class: cXtTextWidget
 *
 * Author: $author$           
 *   Date: 5/16/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtTextWidget
: /*virtual public cXtTextWidgetImplement,
  */public cXtTextWidgetExtend
{
public:
    /*typedef cXtTextWidgetImplement cImplements;
    */typedef cXtTextWidgetExtend cExtends;

    cXtString m_string;

    /**
     **********************************************************************
     *  Constructor: cXtTextWidget
     *
     *       Author: $author$           
     *         Date: 5/16/2010
     **********************************************************************
     */
    cXtTextWidget
    (cXDisplayInterface& display,
     const XtChar* name = CXTWIDGET_NAME,
     WidgetClass widgetClassAttached = 0,
     Widget attached = None,
     bool isCreated = false)
    : cExtends
      (display, name, 
       widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtTextWidget
     *
     *      Author: $author$           
     *        Date: 5/16/2010
     **********************************************************************
     */
    virtual ~cXtTextWidget()
    {
    }
#else /* !defined(CXTTEXTWIDGET_MEMBERS_ONLY) */
#endif /* !defined(CXTTEXTWIDGET_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: SetString
     *
     *    Author: $author$           
     *      Date: 5/16/2010
     **********************************************************************
     */
    virtual TLENGTH SetString
    (const XtChar* chars, 
     TLENGTH length = UNDEFINED_LENGTH)
#if defined(CXTTEXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTTEXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTTEXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = 0;
        XtArgVal argVal;

        if (0 <= (length = m_string.assign(chars, length)))
        if ((argVal = (XtArgVal)(m_string.str())))
        if (0 < (SetValuesL(XtNstring, argVal, 0)))
            count = length;

#else /* !defined(CXTTEXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTTEXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXTTEXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetString
     *
     *    Author: $author$           
     *      Date: 5/16/2010
     **********************************************************************
     */
    virtual const XtChar* GetString
    (TLENGTH& length)
#if defined(CXTTEXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTTEXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        const XtChar* xChars = 0;
#if !defined(CXTTEXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        XtArgVal argVal = 0;
        TLENGTH count;

        length = 0;

        if (0 < (count = GetValuesL(XtNstring, &argVal, 0)))
        if ((xChars = (const XtChar*)(argVal)))
        if (0 <= (count = m_string.assign(xChars)))
            xChars = m_string.c_str(length);
        else
        xChars = 0;

#else /* !defined(CXTTEXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTTEXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return xChars;
    }
#endif /* defined(CXTTEXTWIDGET_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: GetFont
     *
     *    Author: $author$           
     *      Date: 5/16/2010
     **********************************************************************
     */
    virtual XFontStruct* GetFont
    (eError& error)
#if defined(CXTTEXTWIDGET_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTTEXTWIDGET_MEMBER_FUNCS_INTERFACE) */
    {
        XFontStruct* xFont = 0;
#if !defined(CXTTEXTWIDGET_MEMBER_FUNCS_IMPLEMENT)
        XtArgVal argVal = 0;
        TLENGTH count;

        error = e_ERROR_FAILED;

        if (0 < (count = GetValuesL(XtNfont, &argVal, 0)))
        if ((xFont = (XFontStruct*)(argVal)))
            error = e_ERROR_NONE;
#else /* !defined(CXTTEXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTTEXTWIDGET_MEMBER_FUNCS_IMPLEMENT) */
        return xFont;
    }
#endif /* defined(CXTTEXTWIDGET_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTTEXTWIDGET_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTTEXTWIDGET_MEMBERS_ONLY) */
#endif /* !defined(CXTTEXTWIDGET_MEMBERS_ONLY) */

#endif /* !defined(_CXTTEXTWIDGET_HXX) || defined(CXTTEXTWIDGET_MEMBERS_ONLY) */
