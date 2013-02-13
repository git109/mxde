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
 *   File: cxmwmhints.hxx
 *
 * Author: $author$           
 *   Date: 4/15/2010
 **********************************************************************
 */
#if !defined(_CXMWMHINTS_HXX) || defined(CXMWMHINTS_MEMBERS_ONLY)
#if !defined(_CXMWMHINTS_HXX) && !defined(CXMWMHINTS_MEMBERS_ONLY)
#define _CXMWMHINTS_HXX
#endif /* !defined(_CXMWMHINTS_HXX) && !defined(CXMWMHINTS_MEMBERS_ONLY) */

#if !defined(CXMWMHINTS_MEMBERS_ONLY)
#include "cxmwmhintsinterface.hxx"
#include "cxproperty.hxx"
#include "cxbase.hxx"
#include "cxatom.hxx"
#include "ctypes.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXMwmHintsExtend
 *
 *  Author: $author$           
 *    Date: 4/15/2010
 **********************************************************************
 */
typedef cXProperty 
cXMwmHintsExtend;
/**
 **********************************************************************
 *  Class: cXMwmHints
 *
 * Author: $author$           
 *   Date: 4/15/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXMwmHints
: virtual public cXMwmHintsImplement,
  public cXMwmHintsExtend
{
public:
    typedef cXMwmHintsImplement cImplements;
    typedef cXMwmHintsExtend cExtends;

    MwmHints m_defaultXMwmHints;
    MwmHints& m_xMwmHints;
    BYTE& m_propertyByte;

    /**
     **********************************************************************
     *  Constructor: cXMwmHints
     *
     *       Author: $author$           
     *         Date: 4/15/2010
     **********************************************************************
     */
    cXMwmHints
    (const CHAR* atomName = _XA_MOTIF_WM_HINTS,
     int propertyFormat = 32)
    : cExtends
      (atomName, propertyFormat, 
       (sizeof(MwmHints))/(propertyFormat/8)),
      m_xMwmHints(m_defaultXMwmHints),
      m_propertyByte((BYTE&)(m_xMwmHints))
    {
        cBYTES::Set(&m_propertyByte, 0 , sizeof(MwmHints));
    }
#else /* !defined(CXMWMHINTS_MEMBERS_ONLY) */
#endif /* !defined(CXMWMHINTS_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: ChangeHints
     *
     *    Author: $author$           
     *      Date: 4/16/2010
     **********************************************************************
     */
    virtual eError ChangeHints
    (Display& xDisplay, Window xWindow,
     CARD32 flags = 0, CARD32 functions = 0, 
     CARD32 decorations = 0, INT32 input_mode = 0)
#if defined(CXMWMHINTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMWMHINTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CXMWMHINTS_MEMBER_FUNCS_IMPLEMENT)

        m_xMwmHints.flags = flags;

        if (flags & MWM_HINTS_FUNCTIONS)
            m_xMwmHints.functions = functions;

        if (flags & MWM_HINTS_DECORATIONS)
            m_xMwmHints.decorations = decorations;

        if (flags & MWM_HINTS_INPUT_MODE)
            m_xMwmHints.input_mode = input_mode;

        error = ChangeProperty(xDisplay, xWindow);
#else /* !defined(CXMWMHINTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMWMHINTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMWMHINTS_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXMWMHINTS_MEMBER_FUNCS_IMPLEMENT)
    /**
     **********************************************************************
     *  Function: operator MwmHints
     *
     *    Author: $author$           
     *      Date: 4/16/2010
     **********************************************************************
     */
    virtual operator MwmHints&() const
#if defined(CXMWMHINTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMWMHINTS_MEMBER_FUNCS_INTERFACE) */
    {
        return (MwmHints&)(m_xMwmHints);
    }
#endif /* defined(CXMWMHINTS_MEMBER_FUNCS_INTERFACE) */
#else /* !defined(CXMWMHINTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMWMHINTS_MEMBER_FUNCS_IMPLEMENT) */

#if !defined(CXMWMHINTS_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: PropertyByte
     *
     *    Author: $author$           
     *      Date: 4/17/2010
     **********************************************************************
     */
    virtual BYTE& PropertyByte() const
    {
        return (BYTE&)(m_propertyByte);
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMWMHINTS_MEMBERS_ONLY) */
#endif /* !defined(CXMWMHINTS_MEMBERS_ONLY) */

#endif /* !defined(_CXMWMHINTS_HXX) || defined(CXMWMHINTS_MEMBERS_ONLY) */
