 
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
 *   File: cxtextproperty.hxx
 *
 * Author: $author$           
 *   Date: 4/13/2010
 **********************************************************************
 */
#if !defined(_CXTEXTPROPERTY_HXX) || defined(CXTEXTPROPERTY_MEMBERS_ONLY)
#if !defined(_CXTEXTPROPERTY_HXX) && !defined(CXTEXTPROPERTY_MEMBERS_ONLY)
#define _CXTEXTPROPERTY_HXX
#endif /* !defined(_CXTEXTPROPERTY_HXX) && !defined(CXTEXTPROPERTY_MEMBERS_ONLY) */

#if !defined(CXTEXTPROPERTY_MEMBERS_ONLY)
#include "cxbase.hxx"
#include "cbuffer.hxx"
#include "cdebug.hxx"
#include "ctypes.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXTextPropertyExtend
 *
 *  Author: $author$           
 *    Date: 4/13/2010
 **********************************************************************
 */
typedef cXBase
cXTextPropertyExtend;
/**
 **********************************************************************
 *  Class: cXTextProperty
 *
 * Author: $author$           
 *   Date: 4/13/2010
 **********************************************************************
 */
class cXTextProperty
: public cXTextPropertyExtend
{
public:
    typedef cXTextPropertyExtend cExtends;
    
protected:
    XTextProperty m_xTextProperty;
    cBuffer m_buffer;
    
public:
        
    /**
     **********************************************************************
     *  Constructor: cXTextProperty
     *
     *       Author: $author$           
     *         Date: 4/13/2010
     **********************************************************************
     */
    cXTextProperty
    (const CHAR* chars = 0, 
     TLENGTH length = UNDEFINED_LENGTH)
    {
        cBYTES::Set((BYTE*)(&m_xTextProperty), 0, sizeof(XTextProperty));
        if (chars)
        if (0 > (length = Assign(chars, length)))
        {
            eError error = -length;
            DBE(("() throwing error = %d\n", (int)(error)));
            throw (error);
        }
    }
    /**
     **********************************************************************
     *  Destructor: ~cXTextProperty
     *
     *      Author: $author$           
     *        Date: 4/13/2010
     **********************************************************************
     */
    virtual ~cXTextProperty()
    {
        void* data;
        if ((data = (void*)(m_xTextProperty.value)))
            XFree(data);
    }
#else /* !defined(CXTEXTPROPERTY_MEMBERS_ONLY) */
#endif /* !defined(CXTEXTPROPERTY_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Assign
     *
     *    Author: $author$           
     *      Date: 4/13/2010
     **********************************************************************
     */
    virtual TLENGTH Assign
    (const CHAR* chars, 
     TLENGTH length = UNDEFINED_LENGTH,
     bool onlyFreed = false)
#if defined(CXTEXTPROPERTY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTEXTPROPERTY_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTEXTPROPERTY_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = -e_ERROR_FAILED;
        eError error;
        Status status;
        void* data;
        
        DBI(("()...\n"));
        
        if ((data = (void*)(m_xTextProperty.value)))
        if (onlyFreed)
            return -e_ERROR_ALREADY_ALLOCATED;
        else
        if ((error = Freed(true)))
            return -error;
        
        if (0 < length)
            return count;
        
        DBI(("()...\n"));
        
        if ((status = XStringListToTextProperty
            ((char**)(&chars), 1, &m_xTextProperty)))
            count = 0;
        else
        DBE(("() failed on status = %d\n", status));
#else /* !defined(CXTEXTPROPERTY_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTEXTPROPERTY_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXTEXTPROPERTY_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Freed
     *
     *    Author: $author$           
     *      Date: 4/13/2010
     **********************************************************************
     */
    virtual eError Freed
    (bool onlyAllocated = false)
#if defined(CXTEXTPROPERTY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTEXTPROPERTY_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTEXTPROPERTY_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        void* data;
        if ((data = (void*)(m_xTextProperty.value)))
        {
            XFree(data);
            m_xTextProperty.value = 0;
        }
        else
        if (onlyAllocated)
            error = e_ERROR_FAILED;
#else /* !defined(CXTEXTPROPERTY_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTEXTPROPERTY_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEXTPROPERTY_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: operator XTextProperty&
     *
     *    Author: $author$           
     *      Date: 4/13/2010
     **********************************************************************
     */
    virtual operator XTextProperty& () const
#if defined(CXTEXTPROPERTY_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTEXTPROPERTY_MEMBER_FUNCS_INTERFACE) */
#if !defined(CXTEXTPROPERTY_MEMBER_FUNCS_IMPLEMENT)
    {
        XTextProperty& xTextProperty = (XTextProperty&)(m_xTextProperty);
        return xTextProperty;
    }
#else /* !defined(CXTEXTPROPERTY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEXTPROPERTY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* defined(CXTEXTPROPERTY_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTEXTPROPERTY_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTEXTPROPERTY_MEMBERS_ONLY) */
#endif /* !defined(CXTEXTPROPERTY_MEMBERS_ONLY) */

#endif /* !defined(_CXTEXTPROPERTY_HXX) || defined(CXTEXTPROPERTY_MEMBERS_ONLY) */
