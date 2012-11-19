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
 *   File: cMxdeCgiMainHttpFormFields.hxx
 *
 * Author: $author$
 *   Date: 9/17/2011
 **********************************************************************
 */
#ifndef _CMXDECGIMAINHTTPFORMFIELDS_HXX
#define _CMXDECGIMAINHTTPFORMFIELDS_HXX

#include "cMxdeCgiMainHttpFormField.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cMxdeCgiMainHttpFormFieldsIterator;

/**
 **********************************************************************
 *  Class: cMxdeCgiMainHttpFormFields
 *
 * Author: $author$
 *   Date: 9/17/2011
 **********************************************************************
 */
class c_INTERFACE_CLASS cMxdeCgiMainHttpFormFields
{
public:
    /**
     **********************************************************************
     *  Function: FindFirstFormField
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual cMxdeCgiMainHttpFormField* FindFirstFormField
    (cMxdeCgiMainHttpFormFieldsIterator*& i,
     const char* nameChars, ssize_t nameLength=-1)
    {
        cMxdeCgiMainHttpFormField* formField = 0;
        return formField;
    }
    /**
     **********************************************************************
     *  Function: FindNextFormField
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual cMxdeCgiMainHttpFormField* FindNextFormField
    (cMxdeCgiMainHttpFormFieldsIterator* i,
     const char* nameChars, ssize_t nameLength=-1)
    {
        cMxdeCgiMainHttpFormField* formField = 0;
        return formField;
    }

    /**
     **********************************************************************
     *  Function: GetFirstFormField
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual cMxdeCgiMainHttpFormField* GetFirstFormField
    (cMxdeCgiMainHttpFormFieldsIterator*& i)
    {
        cMxdeCgiMainHttpFormField* formField = 0;
        return formField;
    }
    /**
     **********************************************************************
     *  Function: GetNextFormField
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual cMxdeCgiMainHttpFormField* GetNextFormField
    (cMxdeCgiMainHttpFormFieldsIterator* i)
    {
        cMxdeCgiMainHttpFormField* formField = 0;
        return formField;
    }

    /**
     **********************************************************************
     *  Function: GetLastFormField
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual cMxdeCgiMainHttpFormField* GetLastFormField
    (cMxdeCgiMainHttpFormFieldsIterator*& i)
    {
        cMxdeCgiMainHttpFormField* formField = 0;
        return formField;
    }
    /**
     **********************************************************************
     *  Function: GetPrevFormField
     *
     *    Author: $author$
     *      Date: 9/30/2011
     **********************************************************************
     */
    virtual cMxdeCgiMainHttpFormField* GetPrevFormField
    (cMxdeCgiMainHttpFormFieldsIterator* i)
    {
        cMxdeCgiMainHttpFormField* formField = 0;
        return formField;
    }
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CMXDECGIMAINHTTPFORMFIELDS_HXX */
        

