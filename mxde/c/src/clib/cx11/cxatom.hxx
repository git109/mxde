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
 *   File: cxatom.hxx
 *
 * Author: $author$           
 *   Date: 4/14/2010
 **********************************************************************
 */
#if !defined(_CXATOM_HXX) || defined(CXATOM_MEMBERS_ONLY)
#if !defined(_CXATOM_HXX) && !defined(CXATOM_MEMBERS_ONLY)
#define _CXATOM_HXX
#endif /* !defined(_CXATOM_HXX) && !defined(CXATOM_MEMBERS_ONLY) */

#if !defined(CXATOM_MEMBERS_ONLY)
#include "cxatomattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXAtomExtend
 *
 *  Author: $author$           
 *    Date: 4/14/2010
 **********************************************************************
 */
typedef cXAtomCreated
cXAtomExtend;
/**
 **********************************************************************
 *  Class: cXAtom
 *
 * Author: $author$           
 *   Date: 4/14/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXAtom
: public cXAtomExtend
{
public:
    typedef cXAtomExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXAtom
     *
     *       Author: $author$           
     *         Date: 4/14/2010
     **********************************************************************
     */
    cXAtom
    (Display* xDisplay = 0,
     tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : cExtends(xDisplay, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXAtom
     *
     *      Author: $author$           
     *        Date: 4/14/2010
     **********************************************************************
     */
    virtual ~cXAtom()
    {
    }
#else /* !defined(CXATOM_MEMBERS_ONLY) */
#endif /* !defined(CXATOM_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: AttachIntern
     *
     *    Author: $author$           
     *      Date: 4/14/2010
     **********************************************************************
     */
    virtual Atom AttachIntern
    (cXDisplayInterface& display,
     const CHAR* name, 
     Bool onlyExists = False, 
     bool onlyDetached = false)
#if defined(CXATOM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXATOM_MEMBER_FUNCS_INTERFACE) */
    {
        Atom xAtom = None;
#if !defined(CXATOM_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        if ((xDisplay = display.Attached()))
            xAtom = AttachIntern
            (*xDisplay, name, onlyExists, onlyDetached);
#else /* !defined(CXATOM_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXATOM_MEMBER_FUNCS_IMPLEMENT) */
        return xAtom;
    }
#endif /* defined(CXATOM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AttachIntern
     *
     *    Author: $author$           
     *      Date: 4/14/2010
     **********************************************************************
     */
    virtual Atom AttachIntern
    (Display& xDisplay,
     const CHAR* name, 
     Bool onlyExists = False,
     bool onlyDetached = false)
#if defined(CXATOM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXATOM_MEMBER_FUNCS_INTERFACE) */
    {
        Atom xAtom = None;
#if !defined(CXATOM_MEMBER_FUNCS_IMPLEMENT)

        if (None != (Attached()))
        if (onlyDetached)
            return None;

        DBT(("() XInternAtom(%p, \"%s\", %s)...\n", 
            &xDisplay, name, (onlyExists)?("True"):("False")));

        if (None != (xAtom = XInternAtom
            (&xDisplay, name, onlyExists)))
        {
            m_display.Attach(&xDisplay);
            Attach(xAtom);
        }
        else
        DBE(("() failed on XInternAtom(%p, \"%s\", %s)\n", 
            &xDisplay, name, (onlyExists)?("True"):("False")));

#else /* !defined(CXATOM_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXATOM_MEMBER_FUNCS_IMPLEMENT) */
        return xAtom;
    }
#endif /* defined(CXATOM_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXATOM_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXATOM_MEMBERS_ONLY) */
#endif /* !defined(CXATOM_MEMBERS_ONLY) */

#endif /* !defined(_CXATOM_HXX) || defined(CXATOM_MEMBERS_ONLY) */
