/**
 **********************************************************************
 * Copyright (c) 1988-2011 $organization$
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
 *   File: cMxdeCgiMainToHttpFormField.hxx
 *
 * Author: $author$
 *   Date: 9/30/2011
 **********************************************************************
 */
#ifndef _CMXDECGIMAINTOHTTPFORMFIELD_HXX
#define _CMXDECGIMAINTOHTTPFORMFIELD_HXX

#include "cMxdeCgiMainHttpFormField.hxx"
#include "chttpformfieldinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cMxdeCgiMainToHttpFormField
 *
 * Author: $author$
 *   Date: 9/30/2011
 **********************************************************************
 */
class c_INSTANCE_CLASS cMxdeCgiMainToHttpFormField
: virtual public cMxdeCgiMainHttpFormField
{
public:
    typedef cMxdeCgiMainHttpFormField cImplements;

    cHTTPFormFieldInterface* m_formField;

    /**
     **********************************************************************
     *  Constructor: cMxdeCgiMainToHttpFormField
     *
     *       Author: $author$
     *         Date: 9/30/2011
     **********************************************************************
     */
    cMxdeCgiMainToHttpFormField
    (cHTTPFormFieldInterface* formField=0)
    : m_formField(formField)
    {
    }
    /**
     **********************************************************************
     *  Function: Attach
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual cHTTPFormFieldInterface* Attach
    (cHTTPFormFieldInterface* toFormField)
    {
        m_formField  = toFormField;
        return m_formField;
    }
    /**
     **********************************************************************
     *  Function: Attached
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual cHTTPFormFieldInterface* Attached() const
    {
        return m_formField;
    }

    /**
     **********************************************************************
     *  Function: SetName
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual ssize_t SetName
    (const char* chars,
     ssize_t length=-1)
    {
        ssize_t count = 0;
        if ((m_formField))
            count = m_formField->SetName(chars, (TLENGTH)(length));
        return count;
    }
    /**
     **********************************************************************
     *  Function: GetName
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual const char* GetName
    (ssize_t& length) const
    {
        const char* chars = 0;
        TLENGTH count;
        if ((m_formField))
        if ((chars = m_formField->GetName(count)))
            length = (ssize_t)(count);
        return chars;
    }

    /**
     **********************************************************************
     *  Function: SetValue
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual ssize_t SetValue
    (const char* chars,
     ssize_t length=-1)
    {
        ssize_t count = 0;
        if ((m_formField))
            count = m_formField->SetValue(chars, (TLENGTH)(length));
        return count;
    }
    /**
     **********************************************************************
     *  Function: GetValue
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual const char* GetValue
    (ssize_t& length) const
    {
        const char* chars = 0;
        TLENGTH count;
        if ((m_formField))
        if ((chars = m_formField->GetValue(count)))
            length = (ssize_t)(count);
        return chars;
    }

    /**
     **********************************************************************
     *  Function: SetIsFromQueryString
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual bool SetIsFromQueryString
    (bool isTrue=true)
    {
        bool is = false;
        if ((m_formField))
            is = (0 < m_formField->SetIsFromQueryString(isTrue));
        return is;
    }
    /**
     **********************************************************************
     *  Function: GetIsFromQueryString
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual bool GetIsFromQueryString() const
    {
        bool is = false;
        if ((m_formField))
            is = m_formField->IsFromQueryString();
        return is;
    }
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CMXDECGIMAINTOHTTPFORMFIELD_HXX */
        

