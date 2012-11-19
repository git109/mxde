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
 *   File: cMxdeCgiMainCgiHttpFormFields.hxx
 *
 * Author: $author$
 *   Date: 10/1/2011
 **********************************************************************
 */
#if !defined(_CMXDECGIMAINCGIHTTPFORMFIELDS_HXX) || defined(CMXDECGIMAINCGIHTTPFORMFIELDS_MEMBERS_ONLY)
#if !defined(_CMXDECGIMAINCGIHTTPFORMFIELDS_HXX) && !defined(CMXDECGIMAINCGIHTTPFORMFIELDS_MEMBERS_ONLY)
#define _CMXDECGIMAINCGIHTTPFORMFIELDS_HXX
#endif /* !defined(_CMXDECGIMAINCGIHTTPFORMFIELDS_HXX) && !defined(CMXDECGIMAINCGIHTTPFORMFIELDS_MEMBERS_ONLY) */

#if !defined(CMXDECGIMAINCGIHTTPFORMFIELDS_MEMBERS_ONLY)
#include "cMxdeCgiMainCgiHttpFormField.hxx"
#include "cMxdeCgiMainHttpFormFields.hxx"
#include "cHttpFormFieldsInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cHttpFormFieldsIterator
 *
 * Author: $author$
 *   Date: 10/1/2011
 **********************************************************************
 */
class c_INSTANCE_CLASS cHttpFormFieldsIterator
{
public:
    cMxdeCgiMainHttpFormFieldsIterator* m_atField;
    /**
     **********************************************************************
     *  Constructor: cHttpFormFieldsIterator
     *
     *       Author: $author$
     *         Date: 10/1/2011
     **********************************************************************
     */
    cHttpFormFieldsIterator()
    : m_atField(0)
    {}
    /**
     **********************************************************************
     *  Function: operator cMxdeCgiMainHttpFormFieldsIterator*&
     *
     *    Author: $author$
     *      Date: 10/2/2011
     **********************************************************************
     */
    operator cMxdeCgiMainHttpFormFieldsIterator*& () const
    { return (cMxdeCgiMainHttpFormFieldsIterator*&)(m_atField); }
};

/**
 **********************************************************************
 * Typedef: cMxdeCgiMainCgiHttpFormFieldsImplement
 *
 *  Author: $author$
 *    Date: 10/1/2011
 **********************************************************************
 */
typedef cHttpFormFieldsImplement
cMxdeCgiMainCgiHttpFormFieldsImplement;
/**
 **********************************************************************
 * Typedef: cMxdeCgiMainCgiHttpFormFieldsExtend
 *
 *  Author: $author$
 *    Date: 10/1/2011
 **********************************************************************
 */
typedef cInstanceBase
cMxdeCgiMainCgiHttpFormFieldsExtend;
/**
 **********************************************************************
 *  Class: cMxdeCgiMainCgiHttpFormFields
 *
 * Author: $author$
 *   Date: 10/1/2011
 **********************************************************************
 */
class c_INSTANCE_CLASS cMxdeCgiMainCgiHttpFormFields
: virtual public cMxdeCgiMainCgiHttpFormFieldsImplement,
  public cMxdeCgiMainCgiHttpFormFieldsExtend
{
public:
    typedef cMxdeCgiMainCgiHttpFormFieldsImplement cImplements;
    typedef cMxdeCgiMainCgiHttpFormFieldsExtend cExtends;

    cMxdeCgiMainHttpFormFields& m_formFields;
    mutable cMxdeCgiMainCgiHttpFormField m_formField;
    cHttpFormFieldsIterator m_atFormField;

    /**
     **********************************************************************
     *  Constructor: cMxdeCgiMainCgiHttpFormFields
     *
     *       Author: $author$
     *         Date: 10/1/2011
     **********************************************************************
     */
    cMxdeCgiMainCgiHttpFormFields
    (cMxdeCgiMainHttpFormFields& formFields)
    : m_formFields(formFields)
    {
    }
#else /* !defined(CMXDECGIMAINCGIHTTPFORMFIELDS_MEMBERS_ONLY) */
#endif /* !defined(CMXDECGIMAINCGIHTTPFORMFIELDS_MEMBERS_ONLY) */

#if !defined(CMXDECGIMAINCGIHTTPFORMFIELDS_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: FindFirst
     *
     *    Author: $author$
     *      Date: 10/4/2011
     **********************************************************************
     */
    virtual cHttpFormFieldInterface* FindFirst
    (cHttpFormFieldsIterator& atField,
     const cString& named,
     bool isFromQueryString=false) const
    {
        cHttpFormFieldInterface* formField = 0;
        cMxdeCgiMainHttpFormField* detached;
        const char* namedChars;

        if ((namedChars = named.Chars()))
        if ((detached = m_formFields.FindFirstFormField(atField, namedChars)))
        if ((m_formField.Attach(detached)))
            formField = (cHttpFormFieldInterface*)(&m_formField);
        return formField;
    }
    /**
     **********************************************************************
     *  Function: FindNext
     *
     *    Author: $author$
     *      Date: 10/4/2011
     **********************************************************************
     */
    virtual cHttpFormFieldInterface* FindNext
    (cHttpFormFieldsIterator& atField,
     const cString& named,
     bool isFromQueryString=false) const
    {
        cHttpFormFieldInterface* formField = 0;
        cMxdeCgiMainHttpFormField* detached;
        const char* namedChars;

        if ((namedChars = named.Chars()))
        if ((detached = m_formFields.FindNextFormField(atField, namedChars)))
        if ((m_formField.Attach(detached)))
            formField = (cHttpFormFieldInterface*)(&m_formField);
        return formField;
    }

    /**
     **********************************************************************
     *  Function: GetFirst
     *
     *    Author: $author$
     *      Date: 10/1/2011
     **********************************************************************
     */
    virtual cHttpFormFieldInterface* GetFirst
    (cHttpFormFieldsIterator& atField,
     bool isFromQueryString=false) const
    {
        cHttpFormFieldInterface* formField = 0;
        cMxdeCgiMainHttpFormField* detached;

        if ((detached = m_formFields.GetFirstFormField(atField)))
        if ((m_formField.Attach(detached)))
            formField = (cHttpFormFieldInterface*)(&m_formField);
        return formField;
    }
    /**
     **********************************************************************
     *  Function: GetNext
     *
     *    Author: $author$
     *      Date: 10/1/2011
     **********************************************************************
     */
    virtual cHttpFormFieldInterface* GetNext
    (cHttpFormFieldsIterator& atField,
     bool isFromQueryString=false) const
    {
        cHttpFormFieldInterface* formField = 0;
        cMxdeCgiMainHttpFormField* detached;

        if ((detached = m_formFields.GetNextFormField(atField)))
        if ((m_formField.Attach(detached)))
            formField = (cHttpFormFieldInterface*)(&m_formField);
        return formField;
    }

    /**
     **********************************************************************
     *  Function: Iterator
     *
     *    Author: $author$
     *      Date: 10/1/2011
     **********************************************************************
     */
    virtual cHttpFormFieldsIterator& Iterator() const
    {
        return (cHttpFormFieldsIterator&)(m_atFormField);
    };
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CMXDECGIMAINCGIHTTPFORMFIELDS_MEMBERS_ONLY) */
#endif /* !defined(CMXDECGIMAINCGIHTTPFORMFIELDS_MEMBERS_ONLY) */

#endif /* !defined(_CMXDECGIMAINCGIHTTPFORMFIELDS_HXX) || defined(CMXDECGIMAINCGIHTTPFORMFIELDS_MEMBERS_ONLY) */
        

