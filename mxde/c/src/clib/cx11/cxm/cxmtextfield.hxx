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
 *   File: cxmtextfield.hxx
 *
 * Author: $author$           
 *   Date: 7/15/2010
 **********************************************************************
 */
#if !defined(_CXMTEXTFIELD_HXX) || defined(CXMTEXTFIELD_MEMBERS_ONLY)
#if !defined(_CXMTEXTFIELD_HXX) && !defined(CXMTEXTFIELD_MEMBERS_ONLY)
#define _CXMTEXTFIELD_HXX
#endif /* !defined(_CXMTEXTFIELD_HXX) && !defined(CXMTEXTFIELD_MEMBERS_ONLY) */

#if !defined(CXMTEXTFIELD_MEMBERS_ONLY)
#include "cxmtextfieldinterface.hxx"
#include "cxmprimitive.hxx"
#include "cstringbase.hxx"
#include "ctypes.hxx"

#define CXMTEXTFIELD_WIFGET_NAME "cXmTextField"
#define CXMTEXTFIELD_WIFGET_CLASS xmTextFieldWidgetClass

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmTextFieldExtend
 *
 *  Author: $author$           
 *    Date: 7/15/2010
 **********************************************************************
 */
typedef cXmPrimitive
cXmTextFieldExtend;
/**
 **********************************************************************
 *  Class: cXmTextField
 *
 * Author: $author$           
 *   Date: 7/15/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmTextField
: virtual public cXmTextFieldImplement,
  public cXmTextFieldExtend
{
public:
    typedef cXmTextFieldImplement cImplements;
    typedef cXmTextFieldExtend cExtends;
    
    cStringBase m_value;
    
    /**
     **********************************************************************
     *  Constructor: cXmTextField
     *
     *       Author: $author$           
     *         Date: 7/15/2010
     **********************************************************************
     */
    cXmTextField
    (cXDisplayInterface& display,
     const XtChar* name = CXMTEXTFIELD_WIFGET_NAME,
     WidgetClass widgetClassAttached = CXMTEXTFIELD_WIFGET_CLASS,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmTextField
     *
     *      Author: $author$           
     *        Date: 7/15/2010
     **********************************************************************
     */
    virtual ~cXmTextField()
    {
    }
#else /* !defined(CXMTEXTFIELD_MEMBERS_ONLY) */
#endif /* !defined(CXMTEXTFIELD_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: SetValue
     *
     *    Author: $author$           
     *      Date: 7/16/2010
     **********************************************************************
     */
    virtual TLENGTH SetValue
    (String chars,
     tLength length = vUndefinedLength)
#if defined(CXMTEXTFIELD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMTEXTFIELD_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXMTEXTFIELD_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = -e_ERROR_NOT_ATTACHED;
        Widget attached;
        
        if ((chars))
        if ((attached = Attached()))
        {
            if (0 > (length = m_value.assign(chars, length)))
            if ((chars = m_value.str(length)))
                XmTextFieldSetString(attached, chars);
                
            count = length;
        }
#else /* !defined(CXMTEXTFIELD_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMTEXTFIELD_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXMTEXTFIELD_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetValue
     *
     *    Author: $author$           
     *      Date: 7/16/2010
     **********************************************************************
     */
    virtual String GetValue
    (tLength& length)
#if defined(CXMTEXTFIELD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMTEXTFIELD_MEMBER_FUNCS_INTERFACE) */
    {
        String value = 0;
#if !defined(CXMTEXTFIELD_MEMBER_FUNCS_IMPLEMENT)
        Widget attached;
        String chars;

        length = -e_ERROR_NOT_ATTACHED;
        
        if ((attached = Attached()))
        if ((chars = XmTextFieldGetString(attached)))
        {
            if (0 <= (length = m_value.assign(chars)))
                value = m_value.str(length);
                
            XtFree(chars);
        }
#else /* !defined(CXMTEXTFIELD_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMTEXTFIELD_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CXMTEXTFIELD_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetMargin
     *
     *    Author: $author$           
     *      Date: 7/16/2010
     **********************************************************************
     */
    virtual tInt SetMargin
    (tSize toValue)
#if defined(CXMTEXTFIELD_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMTEXTFIELD_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXMTEXTFIELD_MEMBER_FUNCS_IMPLEMENT)
        tInt value = -e_ERROR_NOT_ATTACHED;
        ArgList xArgList;
        
        if ((xArgList = SetValuesL
             (XmNmarginWidth,(toValue), 
              XmNmarginHeight,(toValue), 0)))
            value = toValue;
            
#else /* !defined(CXMTEXTFIELD_MEMBER_FUNCS_IMPLEMENT) */
        tInt value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMTEXTFIELD_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CXMTEXTFIELD_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXMTEXTFIELD_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMTEXTFIELD_MEMBERS_ONLY) */
#endif /* !defined(CXMTEXTFIELD_MEMBERS_ONLY) */

#endif /* !defined(_CXMTEXTFIELD_HXX) || defined(CXMTEXTFIELD_MEMBERS_ONLY) */
