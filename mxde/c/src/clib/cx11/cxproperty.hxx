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
 *   File: cxproperty.hxx
 *
 * Author: $author$           
 *   Date: 4/17/2010
 **********************************************************************
 */
#if !defined(_CXPROPERTY_HXX) || defined(CXPROPERTY_MEMBERS_ONLY)
#if !defined(_CXPROPERTY_HXX) && !defined(CXPROPERTY_MEMBERS_ONLY)
#define _CXPROPERTY_HXX
#endif /* !defined(_CXPROPERTY_HXX) && !defined(CXPROPERTY_MEMBERS_ONLY) */

#if !defined(CXPROPERTY_MEMBERS_ONLY)
#include "cxatom.hxx"
#include "cxbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXPropertyExtend
 *
 *  Author: $author$           
 *    Date: 4/17/2010
 **********************************************************************
 */
typedef cXAtom
cXPropertyExtend;
/**
 **********************************************************************
 *  Class: cXProperty
 *
 * Author: $author$           
 *   Date: 4/17/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXProperty
: public cXPropertyExtend
{
public:
    typedef cXPropertyExtend cExtends;

    BYTE m_propertyByte;
    int m_propertyFormat;
    int m_propertyLength;
    const CHAR* m_atomName;

    /**
     **********************************************************************
     *  Constructor: cXProperty
     *
     *       Author: $author$           
     *         Date: 4/17/2010
     **********************************************************************
     */
    cXProperty
    (const CHAR* atomName = 0,
     int propertyFormat = 8,
     int propertyLength = 1)
    : m_propertyByte(0),
      m_propertyFormat(propertyFormat),
      m_propertyLength(propertyLength),
      m_atomName(atomName)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cXProperty
     *
     *       Author: $author$           
     *         Date: 5/18/2010
     **********************************************************************
     */
    cXProperty
    (BYTE propertyByte,
     const CHAR* atomName = 0)
    : m_propertyByte(propertyByte),
      m_propertyFormat(8),
      m_propertyLength(1),
      m_atomName(atomName)
    {
    }
#else /* !defined(CXPROPERTY_MEMBERS_ONLY) */
#endif /* !defined(CXPROPERTY_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: ChangeProperty
     *
     *    Author: $author$           
     *      Date: 4/17/2010
     **********************************************************************
     */
    virtual eError ChangeProperty
    (Display& xDisplay, Window xWindow,
     int propertyMode = PropModeReplace)
#if defined(CXPROPERTY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPROPERTY_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CXPROPERTY_MEMBER_FUNCS_IMPLEMENT)
        BYTE& propertyByte = PropertyByte();
        Atom xAtom;
        Status status;

        DBT(("() XChangeProperty()...\n"));

        if (!(None != (xAtom = Attached())))
        if (!(None != (xAtom = AttachIntern(xDisplay))))
            return e_ERROR_FAILED;

        if ((status = XChangeProperty
            (&xDisplay, xWindow, xAtom, xAtom, 
             m_propertyFormat, propertyMode, 
             &propertyByte, m_propertyLength)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on XChangeProperty()\n"));

#else /* !defined(CXPROPERTY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXPROPERTY_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPROPERTY_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: AttachIntern
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual Atom AttachIntern
    (cXDisplayInterface& display,
     Bool onlyExists = False, 
     bool onlyDetached = false)
#if defined(CXPROPERTY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPROPERTY_MEMBER_FUNCS_INTERFACE) */
    {
        Atom xAtom = None;
#if !defined(CXPROPERTY_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        if ((xDisplay = display.Attached()))
            xAtom = AttachIntern(*xDisplay, onlyExists, onlyDetached);
#else /* !defined(CXPROPERTY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXPROPERTY_MEMBER_FUNCS_IMPLEMENT) */
        return xAtom;
    }
#endif /* defined(CXPROPERTY_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AttachIntern
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual Atom AttachIntern
    (Display& xDisplay,
     Bool onlyExists = False,
     bool onlyDetached = false)
#if defined(CXPROPERTY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPROPERTY_MEMBER_FUNCS_INTERFACE) */
    {
        Atom xAtom = None;
#if !defined(CXPROPERTY_MEMBER_FUNCS_IMPLEMENT)
        if ((m_atomName))
            xAtom = cExtends::AttachIntern
            (xDisplay, m_atomName, onlyExists, onlyDetached);
#else /* !defined(CXPROPERTY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXPROPERTY_MEMBER_FUNCS_IMPLEMENT) */
        return xAtom;
    }
#endif /* defined(CXPROPERTY_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: PropertyByte
     *
     *    Author: $author$           
     *      Date: 4/17/2010
     **********************************************************************
     */
    virtual BYTE& PropertyByte() const
#if defined(CXPROPERTY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPROPERTY_MEMBER_FUNCS_INTERFACE) */
#if !defined(CXPROPERTY_MEMBER_FUNCS_IMPLEMENT)
    {
        return (BYTE&)(m_propertyByte);
    }
#else /* !defined(CXPROPERTY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXPROPERTY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* defined(CXPROPERTY_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXPROPERTY_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXPROPERTY_MEMBERS_ONLY) */
#endif /* !defined(CXPROPERTY_MEMBERS_ONLY) */

#endif /* !defined(_CXPROPERTY_HXX) || defined(CXPROPERTY_MEMBERS_ONLY) */
