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
 *   File: copened.hxx
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
#if !defined(_COPENED_HXX) || defined(COPENED_MEMBERS_ONLY)
#if !defined(_COPENED_HXX) && !defined(COPENED_MEMBERS_ONLY)
#define _COPENED_HXX
#endif /* !defined(_COPENED_HXX) && !defined(COPENED_MEMBERS_ONLY) */

#if !defined(COPENED_MEMBERS_ONLY)
#include "copenedinterface.hxx"
#include "cinterfacebase.hxx"
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/* cOpened definition
 */
class c_INSTANCE_CLASS cOpened;

#define CDB_CLASS "cOpenedT"
/**
 **********************************************************************
 *  Class: cOpenedT
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
template
<class TDerives=cOpened,
 class TOpenedImplement=cOpenedImplement,
 class TBase=cBase,
 class TImplements=TOpenedImplement,
 class TExtends=TBase>
 
class c_INSTANCE_CLASS cOpenedT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cOpenedT cDerives;

/* include cOpened interface member definitions
 */
#define COPENEDINTERFACE_MEMBERS_ONLY
#include "copenedinterface.hxx"
#undef COPENEDINTERFACE_MEMBERS_ONLY

    bool m_isOpen;

    /**
     **********************************************************************
     * Constructor: cOpenedT
     *
     *      Author: $author$
     *        Date: 5/11/2009
     **********************************************************************
     */
    cOpenedT
    (bool isOpen=false) 
    : m_isOpen(isOpen)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cOpenedT
     *
     *     Author: $author$
     *       Date: 5/11/2009
     **********************************************************************
     */
    virtual ~cOpenedT()
    {
        eError error;
        if ((error = Closed()))
            throw(error);
    }
#else /* !defined(COPENED_MEMBERS_ONLY) */
#endif /* !defined(COPENED_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Opened
     *
     *   Author: $author$
     *     Date: 6/21/2009
     **********************************************************************
     */
    virtual eError Opened
    (bool onlyOpen=false,
     bool dontOpen=false) 
#if defined(COPENED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* COPENED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        bool isOpen;

        if (!(isOpen = IsOpen()))
        if (onlyOpen)
            return e_ERROR_NOT_OPEN;
        else
        if (!dontOpen)
            error = Open(true);

        return error;
    }
#endif /* defined(COPENED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Closed
     *
     *   Author: $author$
     *     Date: 5/11/2009
     **********************************************************************
     */
    virtual eError Closed
    (bool onlyClosed=false) 
#if defined(COPENED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* COPENED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        bool isOpen;

        if ((isOpen = IsOpen()))
        if (onlyClosed)
            return e_ERROR_ALREADY_OPEN;
        else
        error = Close(true);

        return error;
    }
#endif /* defined(COPENED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 6/21/2009
     **********************************************************************
     */
    virtual eError Open
    (bool onlyClosed=false) 
#if defined(COPENED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* COPENED_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(COPENED_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        int isOpen;

        if ((error = Closed(onlyClosed)))
            return error;

        if (0 > (isOpen = SetIsOpen()))
            return error = -isOpen;

        error = e_ERROR_NONE;
#else /* !defined(COPENED_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(COPENED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(COPENED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 5/11/2009
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpen=false) 
#if defined(COPENED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* COPENED_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(COPENED_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        int isOpen;

        if ((error = Opened(onlyOpen, true)))
            return error;

        if (0 > (isOpen = SetIsOpen(false)))
            return error = -isOpen;

        error = e_ERROR_NONE;
#else /* !defined(COPENED_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(COPENED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(COPENED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetIsOpen
     *
     *   Author: $author$
     *     Date: 5/11/2009
     **********************************************************************
     */
    virtual int SetIsOpen
    (bool is=true) 
#if defined(COPENED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* COPENED_MEMBER_FUNCS_INTERFACE */
    {
        int isOpen = false;
#if !defined(COPENED_MEMBER_FUNCS_IMPLEMENT) 
        isOpen = (m_isOpen = is);
#else /* !defined(COPENED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(COPENED_MEMBER_FUNCS_IMPLEMENT) */
        return isOpen;
    }
#endif /* defined(COPENED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: IsOpen
     *
     *   Author: $author$
     *     Date: 5/11/2009
     **********************************************************************
     */
    virtual bool IsOpen() const 
#if defined(COPENED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* COPENED_MEMBER_FUNCS_INTERFACE */
    {
        bool isOpen = false;
#if !defined(COPENED_MEMBER_FUNCS_IMPLEMENT) 
        isOpen = m_isOpen;
#else /* !defined(COPENED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(COPENED_MEMBER_FUNCS_IMPLEMENT) */
        return isOpen;
    }
#endif /* defined(COPENED_MEMBER_FUNCS_INTERFACE) */

#if !defined(COPENED_MEMBERS_ONLY) 
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(COPENED_MEMBERS_ONLY) */
#endif /* !defined(COPENED_MEMBERS_ONLY) */

#endif /* !defined(_COPENED_HXX) || defined(COPENED_MEMBERS_ONLY) */
