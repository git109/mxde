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
#include "cplatform_MwmUtil.h"
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
typedef cXBase
cXMwmHintsExtend;
/**
 **********************************************************************
 *  Class: cXMwmHints
 *
 * Author: $author$           
 *   Date: 4/15/2010
 **********************************************************************
 */
class c_X11_CLASS cXMwmHints
: public cXMwmHintsExtend
{
public:
    typedef cXMwmHintsExtend cExtends;

    MwmHints m_defaultXMwmHints;
    MwmHints& m_xMwmHints;
    BYTE& m_property;
    int m_propertyFormat;
    int m_propertyLength;
    const CHAR* m_atomName;

    /**
     **********************************************************************
     *  Constructor: cXMwmHints
     *
     *       Author: $author$           
     *         Date: 4/15/2010
     **********************************************************************
     */
    cXMwmHints
    (const CHAR* atomName = _XA_MOTIF_WM_HINTS)
    : m_xMwmHints(m_defaultXMwmHints),
      m_property((BYTE&)(m_xMwmHints)),
      m_propertyFormat(32),
      m_propertyLength((sizeof(MwmHints))/(m_propertyFormat/8)),
      m_atomName(atomName)
    {
        cBYTES::Set(&m_property, 0 , sizeof(MwmHints));
    }
    /**
     **********************************************************************
     *  Constructor: cXMwmHints
     *
     *       Author: $author$           
     *         Date: 4/15/2010
     **********************************************************************
     */
    cXMwmHints
    (MwmHints& xMwmHints,
     const CHAR* atomName = _XA_MOTIF_WM_HINTS)
    : m_xMwmHints(xMwmHints),
      m_property((BYTE&)(m_xMwmHints)),
      m_propertyFormat(32),
      m_propertyLength((sizeof(MwmHints))/(m_propertyFormat/8)),
      m_atomName(atomName)
    {
        cBYTES::Set(&m_property, 0 , sizeof(MwmHints));
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

    /**
     **********************************************************************
     *  Function: ChangeProperty
     *
     *    Author: $author$           
     *      Date: 4/16/2010
     **********************************************************************
     */
    virtual eError ChangeProperty
    (Display& xDisplay, Window xWindow,
     int propMode = PropModeReplace) const
#if defined(CXMWMHINTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMWMHINTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CXMWMHINTS_MEMBER_FUNCS_IMPLEMENT)
        UINT32* prop = (UINT32*)(&m_property);
        cXAtom atom;
        Atom xAtom;
        Status status;

        DBT(("() atom name = \"%s\"\n", m_atomName));
        DBT(("() format = %u\n", m_propertyFormat));
        for (int i = 0; i < m_propertyLength; i++)
        DBT(("() prop[%u] = %u\n", i, (prop)[i]));

        if (None != (xAtom = atom.AttachIntern(xDisplay, m_atomName)))
        if ((status = XChangeProperty
            (&xDisplay, xWindow, xAtom, xAtom, 
             m_propertyFormat, propMode, &m_property, m_propertyLength)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on XChangeProperty()\n"));
#else /* !defined(CXMWMHINTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMWMHINTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMWMHINTS_MEMBER_FUNCS_INTERFACE) */

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
#if !defined(CXMWMHINTS_MEMBER_FUNCS_IMPLEMENT)
    {
        return (MwmHints&)(m_xMwmHints);
    }
#else /* !defined(CXMWMHINTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXMWMHINTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* defined(CXMWMHINTS_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXMWMHINTS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMWMHINTS_MEMBERS_ONLY) */
#endif /* !defined(CXMWMHINTS_MEMBERS_ONLY) */

#endif /* !defined(_CXMWMHINTS_HXX) || defined(CXMWMHINTS_MEMBERS_ONLY) */
