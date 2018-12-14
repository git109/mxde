/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: ctdocumentfunctions.cxx
 *
 * Author: $author$
 *   Date: 11/9/2005
 *
 *    $Id$
 *
 **********************************************************************
 */

#include "ctimplement.hxx"
#include "ccchartocharstream.hxx"

/**
 **********************************************************************
 *  Class: cTFunctionForEachElement
 *
 * Author: $author$
 *   Date: 11/9/2005
 **********************************************************************
 */
class cTFunctionForEachElement
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionForEachElement
     *
     *      Author: $author$
     *        Date: 11/9/2005
     **********************************************************************
     */
    cTFunctionForEachElement
    (const char *name, const char *description)
    : cIs(name, description)
    {
        static cParameter parameter[1] = {{0,0}};

        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 11/9/2005
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result, 
     cArgumentList &arglist, cTInterface &t) const
    {
        eError error = e_ERROR_NONE;
        cArgument *first_expr,*expr;
        cDocumentInterface *document;
        cDocumentElementInterface *old_element,*element;

        if ((element = t.GetElement()))
            element = element->GetFirstElement();

        else if ((document = t.GetDocument()))
                element = document->GetFirstElement();

        if (element)
        if ((first_expr = arglist.GetFirst()))
        {
            old_element = t.GetElement();

            do
            {
                t.SetElement(element);

                for (expr=first_expr; expr; expr=expr->GetNext())
                {
                    if ((error = t.Expand(result, *expr)))
                        break;

                    expr->Seek(0);
                }

                if (error)
                    break;
            }
            while((element = element->GetNextElement()));

            t.SetElement(old_element);
        }
        return error;
    }
} ct_function_foreachelement
("for-each-element","for-each-element((expr),...)");

/**
 **********************************************************************
 *  Class: cTFunctionElementName
 *
 * Author: $author$
 *   Date: 11/9/2005
 **********************************************************************
 */
class cTFunctionElementName
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionElementName
     *
     *      Author: $author$
     *        Date: 11/9/2005
     **********************************************************************
     */
    cTFunctionElementName(const char *name, const char *description)
    : cIs(name, description)
    {
        static cParameter parameter[1] = {{0,0}};

        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 11/9/2005
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result, 
     cArgumentList &arglist, cTInterface &t) const
    {
        cCCharToCharStream cchar_to_result(result);
        cDocumentElementInterface *node;
        const cChar *chars;
        int length;

        if ((node = t.GetElement()))
        if ((chars = node->GetNameCChars(length)))
            cchar_to_result.WriteCChar(chars, length);

        return e_ERROR_NONE;
    }
} ct_function_elementname
("element-name","element-name()");

/**
 **********************************************************************
 *  Class: cTFunctionFullElementName
 *
 * Author: $author$
 *   Date: 11/10/2005
 **********************************************************************
 */
class cTFunctionFullElementName
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionFullElementName
     *
     *      Author: $author$
     *        Date: 11/10/2005
     **********************************************************************
     */
    cTFunctionFullElementName
    (const char *name, const char *description)
    : cIs(name, description)
    {
        static cParameter parameter[1] = {{0,0}};

        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 11/10/2005
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result, 
     cArgumentList &arglist, cTInterface &t) const
    {
        cCCharToCharStream cchar_to_result(result);
        cDocumentElementInterface *node;
        const cChar *chars;
        int length;

        if ((node = t.GetElement()))
        {
            if ((chars = node->GetNamespacePrefixCChars(length)))
            if (0 < length)
            if (0 < (length = cchar_to_result.WriteCChar(chars, length)))
                result.Write(":");

            if ((chars = node->GetNameCChars(length)))
                cchar_to_result.WriteCChar(chars, length);
        }

        return e_ERROR_NONE;
    }
} ct_function_fullelementname
("full-element-name","full-element-name()");

/**
 **********************************************************************
 *  Class: cTFunctionForEachAttribute
 *
 * Author: $author$
 *   Date: 11/10/2005
 **********************************************************************
 */
class cTFunctionForEachAttribute
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionForEachAttribute
     *
     *      Author: $author$
     *        Date: 11/10/2005
     **********************************************************************
     */
    cTFunctionForEachAttribute(const char *name, const char *description)
    : cIs(name, description)
    {
        static cParameter parameter[1] = {{0,0}};

        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 11/10/2005
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result, 
     cArgumentList &arglist, cTInterface &t) const
    {
        eError error = e_ERROR_NONE;
        cArgument *first_expr,*expr;
        cDocumentInterface *document;
        cDocumentElementInterface *element;
        cDocumentAttributeInterface *old_attribute,*attribute;

        if (!(element = t.GetElement()))
        if ((document = t.GetDocument()))
            element = document->GetFirstElement();

        if (element)
        if ((attribute = element->GetFirstAttribute()))
        if ((first_expr = arglist.GetFirst()))
        {
            old_attribute = t.GetAttribute();

            do
            {
                t.SetAttribute(attribute);

                for (expr=first_expr; expr; expr=expr->GetNext())
                {
                    if ((error = t.Expand(result, *expr)))
                        break;

                    expr->Seek(0);
                }

                if (error)
                    break;
            }
            while((attribute = attribute->GetNextAttribute()));

            t.SetAttribute(old_attribute);
        }
        return error;
    }
} ct_function_foreachattribute
("for-each-attribute","for-each-attribute()");

/**
 **********************************************************************
 *  Class: cTFunctionForEachNSPrefixAttribute
 *
 * Author: $author$
 *   Date: 11/10/2005
 **********************************************************************
 */
class cTFunctionForEachNSPrefixAttribute
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionForEachNSPrefixAttribute
     *
     *      Author: $author$
     *        Date: 11/10/2005
     **********************************************************************
     */
    cTFunctionForEachNSPrefixAttribute
    (const char *name, const char *description)
    : cIs(name, description)
    {
        static cParameter parameter[1] = {{0,0}};

        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 11/10/2005
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result, 
     cArgumentList &arglist, cTInterface &t) const
    {
        eError error = e_ERROR_NONE;
        cArgument *first_expr,*expr;
        cDocumentInterface *document;
        cDocumentElementInterface *element;
        cDocumentAttributeInterface *old_attribute,*attribute;

        if (!(element = t.GetElement()))
        if ((document = t.GetDocument()))
            element = document->GetFirstElement();

        if (element)
        if ((attribute = element->GetFirstAttribute()))
        if ((first_expr = arglist.GetFirst()))
        {
            old_attribute = t.GetAttribute();

            do
            {
                if (attribute->GetIsNamespacePrefixAttribute())
                {
                    t.SetAttribute(attribute);

                    for (expr=first_expr; expr; expr=expr->GetNext())
                    {
                        if ((error = t.Expand(result, *expr)))
                            break;

                        expr->Seek(0);
                    }

                    if (error)
                        break;
                }
            }
            while((attribute = attribute->GetNextAttribute()));

            t.SetAttribute(old_attribute);
        }
        return error;
    }
} ct_function_foreachnsprefixattribute
("for-each-ns-prefix-attribute","for-each-ns-prefix-attribute()");

/**
 **********************************************************************
 *  Class: cTFunctionForEachNSAttribute
 *
 * Author: $author$
 *   Date: 11/10/2005
 **********************************************************************
 */
class cTFunctionForEachNSAttribute
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionForEachNSAttribute
     *
     *      Author: $author$
     *        Date: 11/10/2005
     **********************************************************************
     */
    cTFunctionForEachNSAttribute
    (const char *name, const char *description)
    : cIs(name, description)
    {
        static cParameter parameter[1] = {{0,0}};

        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 11/10/2005
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result, 
     cArgumentList &arglist, cTInterface &t) const
    {
        eError error = e_ERROR_NONE;
        cArgument *first_expr,*expr;
        cDocumentInterface *document;
        cDocumentElementInterface *element;
        cDocumentAttributeInterface *old_attribute,*attribute;

        if (!(element = t.GetElement()))
        if ((document = t.GetDocument()))
            element = document->GetFirstElement();

        if (element)
        if ((attribute = element->GetFirstAttribute()))
        if ((first_expr = arglist.GetFirst()))
        {
            old_attribute = t.GetAttribute();

            do
            {
                if (attribute->GetIsNamespaceAttribute())
                {
                    t.SetAttribute(attribute);

                    for (expr=first_expr; expr; expr=expr->GetNext())
                    {
                        if ((error = t.Expand(result, *expr)))
                            break;

                        expr->Seek(0);
                    }

                    if (error)
                        break;
                }
            }
            while((attribute = attribute->GetNextAttribute()));

            t.SetAttribute(old_attribute);
        }
        return error;
    }
} ct_function_foreachnsattribute
("for-each-ns-attribute","for-each-ns-attribute()");

/**
 **********************************************************************
 *  Class: cTFunctionAttributeName
 *
 * Author: $author$
 *   Date: 11/10/2005
 **********************************************************************
 */
class cTFunctionAttributeName
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionAttributeName
     *
     *      Author: $author$
     *        Date: 11/10/2005
     **********************************************************************
     */
    cTFunctionAttributeName
    (const char *name, const char *description)
    : cIs(name, description)
    {
        static cParameter parameter[1] = {{0,0}};

        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 11/10/2005
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result, 
     cArgumentList &arglist, cTInterface &t) const
    {
        cCCharToCharStream cchar_to_result(result);
        cDocumentAttributeInterface *node;
        const cChar *chars;
        int length;

        if ((node = t.GetAttribute()))
        if ((chars = node->GetNameCChars(length)))
            cchar_to_result.WriteCChar(chars, length);

        return e_ERROR_NONE;
    }
} ct_function_attributename
("attribute-name","attribute-name()");

/**
 **********************************************************************
 *  Class: cTFunctionFullAttributeName
 *
 * Author: $author$
 *   Date: 11/10/2005
 **********************************************************************
 */
class cTFunctionFullAttributeName
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionFullAttributeName
     *
     *      Author: $author$
     *        Date: 11/10/2005
     **********************************************************************
     */
    cTFunctionFullAttributeName
    (const char *name, const char *description)
    : cIs(name, description)
    {
        static cParameter parameter[1] = {{0,0}};

        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 11/10/2005
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result, 
     cArgumentList &arglist, cTInterface &t) const
    {
        cCCharToCharStream cchar_to_result(result);
        cDocumentAttributeInterface *node;
        const cChar *chars;
        int length;

        if ((node = t.GetAttribute()))
        {
            if ((chars = node->GetNamespacePrefixCChars(length)))
            if (0 < length)
            if (0 < (length = cchar_to_result.WriteCChar(chars, length)))
                result.Write(":");

            if ((chars = node->GetNameCChars(length)))
                cchar_to_result.WriteCChar(chars, length);
        }
        return e_ERROR_NONE;
    }
} ct_function_fullattributename
("full-attribute-name","full-attribute-name()");

/**
 **********************************************************************
 *  Class: cTFunctionAttributeValue
 *
 * Author: $author$
 *   Date: 11/10/2005
 **********************************************************************
 */
class cTFunctionAttributeValue
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionAttributeValue
     *
     *      Author: $author$
     *        Date: 11/10/2005
     **********************************************************************
     */
    cTFunctionAttributeValue(const char *name, const char *description)
    : cIs(name, description)
    {
        static cParameter parameter[1] = {{0,0}};

        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 11/10/2005
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result, 
     cArgumentList &arglist, cTInterface &t) const
    {
        cCCharToCharStream cchar_to_result(result);
        cDocumentAttributeInterface *node;
        const cChar *chars;
        int length;

        if ((node = t.GetAttribute()))
        if ((chars = node->GetValueCChars(length)))
            cchar_to_result.WriteCChar(chars, length);

        return e_ERROR_NONE;
    }
} ct_function_attributevalue
("attribute-value","attribute-value()");
