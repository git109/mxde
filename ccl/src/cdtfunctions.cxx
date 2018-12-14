/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: cdtfunctions.cxx
 *
 * Author: $author$
 *   Date: 2/13/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "ctransform.hxx"

/**
 **********************************************************************
 *  Class: cTransformImplement::cStaticFunctionList
 *
 * Author: $author$
 *   Date: 2/9/2004
 **********************************************************************
 */
cTransformImplement::cStaticFunctionList cTransformImplement::cStaticFunctionList::m_instance;
cTransformImplement::cFunctionItem *cTransformImplement::cStaticFunctionList::cIs::m_first=0;
cTransformImplement::cFunctionItem *cTransformImplement::cStaticFunctionList::cIs::m_last=0;

/**
 **********************************************************************
 *  Class: cDTFunctionTransform
 *
 * Author: $author$
 *   Date: 2/10/2004
 **********************************************************************
 */
class cDTFunctionTransform
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionTransform
     *
     *      Author: $author$
     *        Date: 2/10/2004
     **********************************************************************
     */
    cDTFunctionTransform(const char *name, int length=-1)
    : cIs(name, length),
      m_item(*this)
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        cTransformInterface &transform=transform_context.GetTransform();
        eError error;

        error = transform.TransformElementSetByType
        (output_element_set, template_element, 
         document_factory, transform_context);
        return error;
    }
} g_dt_function_transform("transform") ;

/**
 **********************************************************************
 *  Class: cDTFunctionText
 *
 * Author: $author$
 *   Date: 2/11/2004
 **********************************************************************
 */
class cDTFunctionText
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionText
     *
     *      Author: $author$
     *        Date: 2/11/2004
     **********************************************************************
     */
    cDTFunctionText(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();

        error = transform.TransformElementSet
        (output_element_set, template_element, 
         document_factory, transform_context);
        return error;
    }
} g_dt_function_text("text") ;

/**
 **********************************************************************
 *  Class: cDTFunctionEscapedText
 *
 * Author: $author$
 *   Date: 2/13/2004
 **********************************************************************
 */
class cDTFunctionEscapedText
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionEscapedText
     *
     *      Author: $author$
     *        Date: 2/13/2004
     **********************************************************************
     */
    cDTFunctionEscapedText(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/13/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cCharBuffer buffer;
        cCharBuffer escaped;
        const char *text;
        int textlen;

        if (!(error = transform.TransformElementSetToStream
            (buffer, template_element, 
             document_factory, transform_context)))
        if ((text = buffer.GetBuffer(textlen)))
        if (0 < textlen)
        if (0 < (textlen = escaped.CopyEscaped(text, textlen)))
        if ((text = escaped.GetBuffer(textlen)))
        if (0 < textlen)
            output_element_set.AddTextElement(text, textlen);

        return error;
    }
} g_dt_function_escapedtext("escaped-text") ;

/**
 **********************************************************************
 *  Class: cDTFunctionUpperText
 *
 * Author: $author$
 *   Date: 2/13/2004
 **********************************************************************
 */
class cDTFunctionUpperText
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionUpperText
     *
     *      Author: $author$
     *        Date: 2/13/2004
     **********************************************************************
     */
    cDTFunctionUpperText(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/13/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cCharBuffer buffer;
        cCharBuffer upper;
        const char *text;
        int textlen;

        if (!(error = transform.TransformElementSetToStream
            (buffer, template_element, 
             document_factory, transform_context)))
        if ((text = buffer.GetBuffer(textlen)))
        if (0 < textlen)
        if (0 < (textlen = upper.CopyUpper(text, textlen)))
        if ((text = upper.GetBuffer(textlen)))
        if (0 < textlen)
            output_element_set.AddTextElement(text, textlen);

        return error;
    }
} g_dt_function_uppertext("upper-text") ;

/**
 **********************************************************************
 *  Class: cDTFunctionNewline
 *
 * Author: $author$
 *   Date: 2/13/2004
 **********************************************************************
 */
class cDTFunctionNewline
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionNewline
     *
     *      Author: $author$
     *        Date: 2/13/2004
     **********************************************************************
     */
    cDTFunctionNewline(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/13/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();

        output_element_set.AddTextElement("\n");

        error = transform.TransformElementSet
        (output_element_set, template_element, 
         document_factory, transform_context);
        return error;
    }
} g_dt_function_newline("newline") ;

/**
 **********************************************************************
 *  Class: cDTFunctionTab
 *
 * Author: $author$
 *   Date: 2/13/2004
 **********************************************************************
 */
class cDTFunctionTab
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionTab
     *
     *      Author: $author$
     *        Date: 2/13/2004
     **********************************************************************
     */
    cDTFunctionTab(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/13/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();

        output_element_set.AddTextElement("\t");

        error = transform.TransformElementSet
        (output_element_set, template_element, 
         document_factory, transform_context);
        return error;
    }
} g_dt_function_tab("tab") ;

/**
 **********************************************************************
 *  Class: cDTFunctionT
 *
 * Author: $author$
 *   Date: 2/11/2004
 **********************************************************************
 */
class cDTFunctionT
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionT
     *
     *      Author: $author$
     *        Date: 2/11/2004
     **********************************************************************
     */
    cDTFunctionT(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cCharBuffer buffer;
        const char *text;
        int textlen;

        if (!(error = transform.TransformElementSetToStream
            (buffer, template_element, 
             document_factory, transform_context, false)))
        if ((text = buffer.GetBuffer(textlen)))
        if (0 < textlen)
            error = transform.TransformText
            (output_element_set, document_factory,
             transform_context, text, textlen);

        return error;
    }
} g_dt_function_t("t") ;

/**
 **********************************************************************
 *  Class: cDTFunctionVariable
 *
 * Author: $author$
 *   Date: 2/12/2004
 **********************************************************************
 */
class cDTFunctionVariable
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionVariable
     *
     *      Author: $author$
     *        Date: 2/12/2004
     **********************************************************************
     */
    cDTFunctionVariable(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/12/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cAttributeInterface *name_attr=template_element.GetFirstAttributeByName("name");
        cAttributeInterface *value_attr=template_element.GetFirstAttributeByName("value");
        cElementInterface *argument=template_element.GetFirstParentElement();
        cElementInterface *statements;
        cVariableInterface *variable;
        cValueInterface *value;
        cCharBuffer buffer;
        const char *text;
        int textlen;

        if (name_attr)
        {
            if ((text = name_attr->GetText(textlen)))
            if (0 < textlen)
            if (!(error = transform.TransformTextToStream
                (buffer, document_factory, 
                 transform_context, text, textlen)))
            if ((text = buffer.GetBuffer(textlen)))
            if (0 < textlen)
            if ((variable = transform.GetVariable(text, textlen)))
            if (value_attr)
            {
                if ((text = value_attr->GetText(textlen)))
                if (0 <= (buffer.Clear()))
                if (!(error = transform.TransformTextToStream
                    (buffer, document_factory, 
                     transform_context, text, textlen)))
                if ((text = buffer.GetBuffer(textlen)))
                if ((value = variable->NewValue()))
                {
                    if (0 < textlen)
                    {
                        cElementSetInterface &es=value->GetElementSet();
                        es.AddTextElement(text, textlen);
                    }
                    if (!(error = value->Update()))
                        return error;
                    value->Release();
                }
            }
            else if ((value = variable->NewValue()))
            {
                if (!(error = transform.TransformElementSetByType
                    (value->GetElementSet(), template_element, 
                     document_factory, transform_context)))
                if (!(error = value->Update()))
                    return error;

                value->Release();
            }
            return error;
        }

        if (argument)
        if ((statements = argument->GetNextParentElement()))
        if (!(error = transform.TransformElementToStream
            (buffer, *argument, 
             document_factory, transform_context)))
        if ((text = buffer.GetBuffer(textlen)))
        if (0 < textlen)
        if ((variable = transform.GetVariable(text, textlen)))
        if ((value = variable->NewValue()))
        {
            if (!(error = transform.TransformElementSiblingsByType
                (value->GetElementSet(), *argument, 
                 document_factory, transform_context)))
            if (!(error = value->Update()))
                return error;

            value->Release();
        }
        return error;
    }
} g_dt_function_variable("variable") ;

/**
 **********************************************************************
 *  Class: cDTFunctionGetVariable
 *
 * Author: $author$
 *   Date: 2/12/2004
 **********************************************************************
 */
class cDTFunctionGetVariable
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetVariable
     *
     *      Author: $author$
     *        Date: 2/12/2004
     **********************************************************************
     */
    cDTFunctionGetVariable(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/12/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *argument=template_element.GetFirstParentElement();
        cVariableInterface *variable;
        cValueInterface *value;
        cCharBuffer buffer;
        const char *text;
        int textlen;

        if (argument)
        if (!(error = transform.TransformElementSetByTypeToStream
            (buffer, template_element, 
             document_factory, transform_context)))
        if ((text = buffer.GetBuffer(textlen)))
        if (0 < textlen)
        if ((variable = transform.GetVariable(text, textlen)))
        if ((value = variable->GetValue()))
            output_element_set.ReferenceElements
            (value->GetElementSet());

        return error;
    }
} g_dt_function_getvariable("get-variable") ;

/**
 **********************************************************************
 *  Class: cDTFunctionWithDocument
 *
 * Author: $author$
 *   Date: 2/13/2004
 **********************************************************************
 */
class cDTFunctionWithDocument
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionWithDocument
     *
     *      Author: $author$
     *        Date: 2/13/2004
     **********************************************************************
     */
    cDTFunctionWithDocument(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/13/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cDocumentInterface *document=transform_context.GetDocument();

        if (document)
        {
            cElementSetInterface *old_element_set=transform_context.SetElementSet(document);

            error = transform.TransformElementSetByType
            (output_element_set, template_element, 
             document_factory, transform_context);

            transform_context.SetElementSet(old_element_set);
        }
        return error;
    }
} g_dt_function_withdocument("with-document") ;

/**
 **********************************************************************
 *  Class: cGetDocumentDTFunction
 *
 * Author: $author$
 *   Date: 2/17/2004
 **********************************************************************
 */
class cGetDocumentDTFunction
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cGetDocumentDTFunction
     *
     *      Author: $author$
     *        Date: 2/17/2004
     **********************************************************************
     */
    cGetDocumentDTFunction(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/17/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cDocumentInterface *document=transform_context.GetDocument();
        cElementInterface *uri_argument=template_element.GetFirstParentElement();
        cElementInterface *type_argument;
        cElementInterface *name_argument;
        cElementInterface *value_argument;
        cElementInterface *arguments;
        cElementInterface *argument;
        cCharBuffer buffer;
        const char *text;
        int textlen;

        if (uri_argument)
        if (!(error = transform.TransformElementToStream
            (buffer, *uri_argument, document_factory, transform_context)))
        if ((text = buffer.GetBuffer(textlen)))
        if (0 < textlen)
        {
            if ((type_argument = uri_argument->GetNextParentElement()))
            {
                buffer.Clear();
                if (!(error = transform.TransformElementToStream
                    (buffer, *type_argument, document_factory, transform_context)))
                if ((text = buffer.GetBuffer(textlen)))
                if (0 < textlen)
                {
                }

                if ((arguments = type_argument->GetNextParentElement()))
                if ((argument = arguments->GetFirstParentElement()))
                {
                    do
                    {
                        if ((name_argument = argument->GetFirstParentElement()))
                        if ((value_argument = name_argument->GetNextParentElement()))
                        {
                            buffer.Clear();
                            if ((error = transform.TransformElementToStream
                                (buffer, *name_argument, 
                                 document_factory, transform_context)))
                                 return error;

                            if ((text = buffer.GetBuffer(textlen)))
                            if (0 < textlen)
                            {
                                buffer.Clear();
                                if ((error = transform.TransformElementToStream
                                    (buffer, *value_argument, 
                                     document_factory, transform_context)))
                                     return error;

                                if ((text = buffer.GetBuffer(textlen)))
                                if (0 < textlen)
                                {
                                }
                            }
                        }
                    }
                    while ((argument = argument->GetNextParentElement()));
                }
            }
        }

        if (document)
            error = WithDocument
            (output_element_set, template_element,
             document_factory, transform_context,
             transform, *document);

        return error;
    }

    /**
     **********************************************************************
     * Function: WithDocument
     *
     *   Author: $author$
     *     Date: 2/17/2004
     **********************************************************************
     */
    virtual eError WithDocument
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cDocumentInterface &document)
    {
        eError error=e_ERROR_NONE;
        output_element_set.ReferenceElements(document);
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDTFunctionGetFirstDocumentElement
 *
 * Author: $author$
 *   Date: 2/21/2004
 **********************************************************************
 */
class cDTFunctionGetFirstDocumentElement
: public cGetDocumentDTFunction
{
public:
    typedef cGetDocumentDTFunction cIs;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetFirstDocumentElement
     *
     *      Author: $author$
     *        Date: 2/21/2004
     **********************************************************************
     */
    cDTFunctionGetFirstDocumentElement(const char *name, int length=-1)
    : cIs(name, length) 
    {
    }
    /**
     **********************************************************************
     * Function: WithDocument
     *
     *   Author: $author$
     *     Date: 2/21/2004
     **********************************************************************
     */
    virtual eError WithDocument
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cDocumentInterface &document)
    {
        eError error=e_ERROR_NONE;
        cElementInterface *element;

        if ((element = document.GetFirstParentElement()))
            output_element_set.AddReferenceElement(*element);

        return error;
    }
} g_dt_function_getfirstdocumentelement("get-first-document-element") ;

/**
 **********************************************************************
 *  Class: cDTFunctionGetLastDocumentElement
 *
 * Author: $author$
 *   Date: 2/21/2004
 **********************************************************************
 */
class cDTFunctionGetLastDocumentElement
: public cGetDocumentDTFunction
{
public:
    typedef cGetDocumentDTFunction cIs;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetLastDocumentElement
     *
     *      Author: $author$
     *        Date: 2/21/2004
     **********************************************************************
     */
    cDTFunctionGetLastDocumentElement(const char *name, int length=-1)
    : cIs(name, length) 
    {
    }
    /**
     **********************************************************************
     * Function: WithDocument
     *
     *   Author: $author$
     *     Date: 2/21/2004
     **********************************************************************
     */
    virtual eError WithDocument
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cDocumentInterface &document)
    {
        eError error=e_ERROR_NONE;
        cElementInterface *element;

        if ((element = document.GetLastParentElement()))
            output_element_set.AddReferenceElement(*element);

        return error;
    }
} g_dt_function_getlastdocumentelement("get-last-document-element") ;

/**
 **********************************************************************
 *  Class: cDTFunctionGetDocument
 *
 * Author: $author$
 *   Date: 2/17/2004
 **********************************************************************
 */
class cDTFunctionGetDocument
: public cGetDocumentDTFunction
{
public:
    typedef cGetDocumentDTFunction cIs;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetDocument
     *
     *      Author: $author$
     *        Date: 2/17/2004
     **********************************************************************
     */
    cDTFunctionGetDocument(const char *name, int length=-1)
    : cIs(name, length) 
    {
    }
} g_dt_function_getdocument("get-document") ;

/**
 **********************************************************************
 *  Class: cGetElementDTFunction
 *
 * Author: $author$
 *   Date: 2/11/2004
 **********************************************************************
 */
class cGetElementDTFunction
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cGetElementDTFunction
     *
     *      Author: $author$
     *        Date: 2/11/2004
     **********************************************************************
     */
    cGetElementDTFunction(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementSetInterface *element_set=transform_context.GetElementSet();
        cElementInterface *element=transform_context.GetElement();
        cElementInterface *argument=template_element.GetFirstParentElement();
        cCharBuffer buffer;
        const char *text;
        int textlen;

        if (element_set)
        {
            if (argument)
            {
                do
                {
                    if (!(error = transform.TransformElementToStream
                        (buffer, *argument, 
                         document_factory, transform_context)))
                    if ((text = buffer.GetBuffer(textlen)))
                    if (textlen > 0)
                    if ((element_set = (element = element_set->
                        GetFirstParentElementByText(text, textlen))))
                    {
                        buffer.Clear();
                        continue;
                    }
                    return error;
                }
                while ((argument = argument->GetNextParentElement()));
            }
        }

        if (element)
        {
            text=element->GetText(textlen);

            error = WithElement
            (output_element_set, template_element,
             document_factory, transform_context,
             transform, *element);
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: WithElement
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError WithElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cElementInterface &element)
    {
        eError error=e_ERROR_NONE;
        output_element_set.AddReferenceElement(element);
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDTFunctionGetElement
 *
 * Author: $author$
 *   Date: 2/13/2004
 **********************************************************************
 */
class cDTFunctionGetElement
: public cGetElementDTFunction
{
public:
    typedef cGetElementDTFunction cIs;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetElement
     *
     *      Author: $author$
     *        Date: 2/13/2004
     **********************************************************************
     */
    cDTFunctionGetElement(const char *name, int length=-1)
    : cIs(name, length) 
    {
    }
} g_dt_function_getelement("get-element") ;

/**
 **********************************************************************
 *  Class: cDTFunctionGetElementOf
 *
 * Author: $author$
 *   Date: 2/21/2004
 **********************************************************************
 */
class cDTFunctionGetElementOf
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetElementOf
     *
     *      Author: $author$
     *        Date: 2/21/2004
     **********************************************************************
     */
    cDTFunctionGetElementOf(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/21/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *argument=template_element.GetFirstParentElement();
        cElementSetInterface *ofelements=0;
        cElementInterface *ofelement;
        cElementInterface *element;
        cElementSet element_set;
        cElementSet element_set2;
        cCharBuffer buffer;
        const char *text;
        int textlen;

        if (argument)
        {
            if ((error = transform.TransformElement
                (element_set, *argument,
                 document_factory, transform_context)))
                return error;

            if ((argument = argument->GetNextParentElement()))
            if ((ofelement = element_set.GetFirstParentElement()))
            {
                ofelements = &element_set2;

                do
                {
                    if ((error = transform.TransformElementToStream
                        (buffer, *argument,
                         document_factory, transform_context)))
                        return error;

                    if ((text = buffer.GetBuffer(textlen)))
                    if (0 < textlen)
                    {
                        do
                        {
                            const char *oftext=ofelement->GetText();

                            if ((element = ofelement->
                                GetFirstParentElementByText(text, textlen)))
                            do
                            {
                                ofelements->AddReferenceElement(*element);
                            }
                            while ((element = element->
                                   GetNextParentElementByText(text, textlen)));
                        }
                        while ((ofelement = ofelement->GetNextParentElement()));

                        if ((argument = argument->GetNextParentElement()))
                        {
                            if (0 > (textlen = buffer.Clear()))
                                return -textlen;

                            if ((ofelement = ofelements->GetFirstParentElement()))
                            {
                                if (ofelements != &element_set)
                                {
                                    ofelements = &element_set;
                                    element_set.DeleteAllElements();
                                }
                                else
                                {
                                    ofelements = &element_set2;
                                    element_set2.DeleteAllElements();
                                }
                                continue;
                            }
                            break;
                        }
                        continue;
                    }
                    break;
                }
                while (argument);
            }

            if (ofelements)
                output_element_set.ReferenceElements(*ofelements);
        }
        return error;
    }
} g_dt_function_getelementof("get-element-of") ;

/**
 **********************************************************************
 *  Class: cDTFunctionGetFirstElementOf
 *
 * Author: $author$
 *   Date: 2/21/2004
 **********************************************************************
 */
class cDTFunctionGetFirstElementOf
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetFirstElementOf
     *
     *      Author: $author$
     *        Date: 2/21/2004
     **********************************************************************
     */
    cDTFunctionGetFirstElementOf(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/21/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *argument=template_element.GetFirstParentElement();
        cElementInterface *ofelement;
        cElementInterface *element;
        cElementSet element_set;

        if (argument)
        {
            if ((error = transform.TransformElement
                (element_set, *argument,
                 document_factory, transform_context)))
                return error;

            if ((ofelement = element_set.GetFirstParentElement()))
            do
            {
                if ((element = ofelement->GetFirstParentElement()))
                    output_element_set.AddReferenceElement(*element);
            }
            while ((ofelement = ofelement->GetNextParentElement()));
        }

        return error;
    }
} g_dt_function_getfirstelementof("get-first-element-of") ;

/**
 **********************************************************************
 *  Class: cDTFunctionGetLastElementOf
 *
 * Author: $author$
 *   Date: 2/21/2004
 **********************************************************************
 */
class cDTFunctionGetLastElementOf
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetLastElementOf
     *
     *      Author: $author$
     *        Date: 2/21/2004
     **********************************************************************
     */
    cDTFunctionGetLastElementOf(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/21/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *argument=template_element.GetFirstParentElement();
        cElementInterface *ofelement;
        cElementInterface *element;
        cElementSet element_set;

        if (argument)
        {
            if ((error = transform.TransformElement
                (element_set, *argument,
                 document_factory, transform_context)))
                return error;

            if ((ofelement = element_set.GetFirstParentElement()))
            do
            {
                if ((element = ofelement->GetLastParentElement()))
                    output_element_set.AddReferenceElement(*element);
            }
            while ((ofelement = ofelement->GetNextParentElement()));
        }

        return error;
    }
} g_dt_function_getlsstelementof("get-last-element-of") ;

/**
 **********************************************************************
 *  Class: cDTFunctionGetFirstElementOfSet
 *
 * Author: $author$
 *   Date: 2/21/2004
 **********************************************************************
 */
class cDTFunctionGetFirstElementOfSet
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetFirstElementOfSet
     *
     *      Author: $author$
     *        Date: 2/21/2004
     **********************************************************************
     */
    cDTFunctionGetFirstElementOfSet(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/21/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *argument=template_element.GetFirstParentElement();
        cElementInterface *element;
        cElementSet element_set;

        if (argument)
        {
            if ((error = transform.TransformElement
                (element_set, *argument,
                 document_factory, transform_context)))
                return error;

            if ((element = element_set.GetFirstParentElement()))
                output_element_set.AddReferenceElement(*element);
        }

        return error;
    }
} g_dt_function_getfirstelementofset("get-first-element-of-set") ;

/**
 **********************************************************************
 *  Class: cDTFunctionGetLastElementOfSet
 *
 * Author: $author$
 *   Date: 2/21/2004
 **********************************************************************
 */
class cDTFunctionGetLastElementOfSet
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetLastElementOfSet
     *
     *      Author: $author$
     *        Date: 2/21/2004
     **********************************************************************
     */
    cDTFunctionGetLastElementOfSet(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/21/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *argument=template_element.GetFirstParentElement();
        cElementInterface *element;
        cElementSet element_set;

        if (argument)
        {
            if ((error = transform.TransformElement
                (element_set, *argument,
                 document_factory, transform_context)))
                return error;

            if ((element = element_set.GetLastParentElement()))
                output_element_set.AddReferenceElement(*element);
        }

        return error;
    }
} g_dt_function_getlastelementofset("get-last-element-of-set") ;

/**
 **********************************************************************
 *  Class: cDTFunctionGetElementOfSetWhere
 *
 * Author: $author$
 *   Date: 2/25/2004
 **********************************************************************
 */
class cDTFunctionGetElementOfSetWhere
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetElementOfSetWhere
     *
     *      Author: $author$
     *        Date: 2/25/2004
     **********************************************************************
     */
    cDTFunctionGetElementOfSetWhere(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/25/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *argument=template_element.GetFirstParentElement();
        cElementInterface *test_argument;
        cElementInterface *test_element;
        cElementInterface *element;
        cElementSet element_set;
        cElementSet test_element_set;

        if (argument)
        if ((test_argument = argument->GetNextElement()))
        {
            if ((error = transform.TransformElement
                (element_set, *argument,
                 document_factory, transform_context)))
                return error;

            if ((element = element_set.GetFirstParentElement()))
            do
            {
                cElementInterface *old_element=transform_context.SetElement(element);
                cElementSetInterface *old_element_set=transform_context.SetElementSet(element);

                error = transform.TransformElement
                (test_element_set, *test_argument,
                 document_factory, transform_context);

                transform_context.SetElementSet(old_element_set);
                transform_context.SetElement(old_element);

                if (error)
                    return error;

                if ((test_element = test_element_set.GetFirstElement()))
                {
                    test_element_set.DeleteAllElements();
                    output_element_set.AddReferenceElement(*element);
                }
            }
            while ((element = element->GetNextParentElement()));
        }

        return error;
    }
} g_dt_function_getelementofsetwhere("get-element-of-set-where") ;

/**
 **********************************************************************
 *  Class: cDTFunctionGetElementsOf
 *
 * Author: $author$
 *   Date: 2/21/2004
 **********************************************************************
 */
class cDTFunctionGetElementsOf
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetElementsOf
     *
     *      Author: $author$
     *        Date: 2/21/2004
     **********************************************************************
     */
    cDTFunctionGetElementsOf(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/21/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *argument=template_element.GetFirstParentElement();
        cElementInterface *element;
        cElementSet element_set;

        if (argument)
        {
            if ((error = transform.TransformElement
                (element_set, *argument,
                 document_factory, transform_context)))
                return error;

            if ((element = element_set.GetFirstElement()))
            do
            {
                const char *text=element->GetText();

                output_element_set.ReferenceElements(*element);
            }
            while ((element = element->GetNextElement()));
        }

        return error;
    }
} g_dt_function_getelementsof("get-elements-of") ;

/**
 **********************************************************************
 *  Class: cDTFunctionGetElementText
 *
 * Author: $author$
 *   Date: 2/13/2004
 **********************************************************************
 */
class cDTFunctionGetElementText
: public cGetElementDTFunction
{
public:
    typedef cGetElementDTFunction cIs;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetElementText
     *
     *      Author: $author$
     *        Date: 2/13/2004
     **********************************************************************
     */
    cDTFunctionGetElementText(const char *name, int length=-1)
    : cIs(name, length) 
    {
    }
    /**
     **********************************************************************
     * Function: WithElement
     *
     *   Author: $author$
     *     Date: 2/13/2004
     **********************************************************************
     */
    virtual eError WithElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cElementInterface &element)
    {
        eError error=e_ERROR_NONE;
        const char *text;
        int textlen;

        if ((text = element.GetText(textlen)))
        if (0 < textlen)
            output_element_set.AddTextElement(text, textlen);
        return error;
    }
} g_dt_function_getelementtext("get-element-text") ;

/**
 **********************************************************************
 *  Class: cWithElementDTFunction
 *
 * Author: $author$
 *   Date: 2/11/2004
 **********************************************************************
 */
class cWithElementDTFunction
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cWithElementDTFunction
     *
     *      Author: $author$
     *        Date: 2/11/2004
     **********************************************************************
     */
    cWithElementDTFunction(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementSetInterface *element_set=transform_context.GetElementSet();
        cElementInterface *element=transform_context.GetElement();
        cElementInterface *arguments=template_element.GetFirstParentElement();
        cElementInterface *argument;
        cElementInterface *argument2;
        cCharBuffer buffer;
        const char *text;
        int textlen;

        if (element_set)
        {
            if (arguments)
            if ((argument = arguments->GetNextParentElement()))
            {
                do
                {
                    if (!(error = transform.TransformElementToStream
                        (buffer, *arguments, 
                         document_factory, transform_context)))
                    if ((text = buffer.GetBuffer(textlen)))
                    if (textlen > 0)
                    if ((element_set = (element = element_set->
                        GetFirstParentElementByText(text, textlen))))
                    {
                        if ((argument2 = argument->GetNextParentElement()))
                        {
                            arguments = argument;
                            argument = argument2;
                        }
                        buffer.Clear();
                        continue;
                    }
                    return error;
                }
                while (argument2);
            }
            else arguments = 0;
        }

        if (element)
            error = WithElement
            (output_element_set, template_element,
             document_factory, transform_context,
             transform, *element, arguments);

        return error;
    }
    /**
     **********************************************************************
     * Function: WithElement
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError WithElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cElementInterface &element,
     cElementInterface *arguments)
    {
        eError error=e_ERROR_NONE;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDTFunctionGetAttribute
 *
 * Author: $author$
 *   Date: 2/11/2004
 **********************************************************************
 */
class cDTFunctionGetAttribute
: public cWithElementDTFunction
{
public:
    typedef cWithElementDTFunction cIs;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetAttribute
     *
     *      Author: $author$
     *        Date: 2/11/2004
     **********************************************************************
     */
    cDTFunctionGetAttribute(const char *name, int length=-1)
    : cIs(name, length)
    {
    }
    /**
     **********************************************************************
     * Function: WithElement
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError WithElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cElementInterface &element,
     cElementInterface *arguments)
    {
        eError error=e_ERROR_NONE;
        cCharBuffer output_buffer;
        cAttributeInterface *attr;
        const char *text;
        int textlen;

        if (arguments)
            error = transform.
            TransformElementSiblingsByTypeToStream
            (output_buffer, *arguments, 
             document_factory, transform_context);

        else error = transform.
             TransformElementSetByTypeToStream
             (output_buffer, template_element,
              document_factory, transform_context);

        if (!error)
        if ((text = output_buffer.GetBuffer(textlen)))
        if (0 < textlen)
        {
            if ((attr = element.GetFirstAttributeByName(text, textlen)))
            if ((text = attr->GetText(textlen)))
            if (0 < textlen)
                output_element_set.AddTextElement(text, textlen);
        }
        return error;
    }
} g_dt_function_getattribute("get-attribute") ;

/**
 **********************************************************************
 *  Class: cDTFunctionGetAttributeOf
 *
 * Author: $author$
 *   Date: 2/24/2004
 **********************************************************************
 */
class cDTFunctionGetAttributeOf
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetAttributeOf
     *
     *      Author: $author$
     *        Date: 2/24/2004
     **********************************************************************
     */
    cDTFunctionGetAttributeOf(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/24/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *argument=template_element.GetFirstParentElement();
        cAttributeInterface *attribute;
        cElementInterface *element;
        cElementSet element_set;
        cCharBuffer buffer;
        const char *text,*name;
        int textlen,namelen;

        if (argument)
        {
            if ((error = transform.TransformElement
                (element_set, *argument,
                 document_factory, transform_context)))
                return error;

            if ((argument = argument->GetNextParentElement()))
            if ((element = element_set.GetFirstParentElement()))
            if (!(error = transform.TransformElementToStream
                (buffer, *argument,
                 document_factory, transform_context)))
            if ((name = buffer.GetBuffer(namelen)))
            if (0 < namelen)
            do
            {
                text=element->GetText();

                if ((attribute = element->
                    GetFirstAttributeByName(name, namelen)))
                if ((text = attribute->GetText(textlen)))
                if (0 < textlen)
                    output_element_set.
                    AddTextElement(text, textlen);
            }
            while ((element = element->GetNextParentElement()));
        }

        return error;
    }
} g_dt_function_getattributeof("get-attribute-of") ;

/**
 **********************************************************************
 *  Class: cDTFunctionWithElement
 *
 * Author: $author$
 *   Date: 2/13/2004
 **********************************************************************
 */
class cDTFunctionWithElement
: public cWithElementDTFunction
{
public:
    typedef cWithElementDTFunction cIs;

    /**
     **********************************************************************
     * Constructor: cDTFunctionWithElement
     *
     *      Author: $author$
     *        Date: 2/13/2004
     **********************************************************************
     */
    cDTFunctionWithElement(const char *name, int length=-1)
    : cIs(name, length)
    {
    }
    /**
     **********************************************************************
     * Function: WithElement
     *
     *   Author: $author$
     *     Date: 2/13/2004
     **********************************************************************
     */
    virtual eError WithElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cElementInterface &element,
     cElementInterface *arguments)
    {
        eError error=e_ERROR_NONE;
        cElementInterface *old_element=transform_context.SetElement(&element);
        cElementSetInterface *old_element_set=transform_context.SetElementSet(&element);

        if (arguments)
            error = transform.TransformElementSiblingsByType
            (output_element_set, *arguments, 
             document_factory, transform_context);

        else error = transform.TransformElementSetByType
             (output_element_set, template_element, 
              document_factory, transform_context);

        transform_context.SetElementSet(old_element_set);
        transform_context.SetElement(old_element);
        return error;
    }
} g_dt_function_withelement("with-element") ;

/**
 **********************************************************************
 *  Class: cWithElementSetDTFunction
 *
 * Author: $author$
 *   Date: 2/11/2004
 **********************************************************************
 */
class cWithElementSetDTFunction
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cWithElementSetDTFunction
     *
     *      Author: $author$
     *        Date: 2/11/2004
     **********************************************************************
     */
    cWithElementSetDTFunction(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementSetInterface *element_set=transform_context.GetElementSet();
        cElementInterface *arguments=template_element.GetFirstParentElement();

        if (element_set)
        if (arguments)
            error = WithElementSet
            (output_element_set, template_element,
             document_factory, transform_context,
             transform, *element_set);

        return error;
    }
    /**
     **********************************************************************
     * Function: WithElementSet
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError WithElementSet
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cElementSetInterface &element_set)
    {
        eError error=e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: TransformWithElement
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError TransformWithElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cElementInterface &element)
    {
        eError error=e_ERROR_NONE;
        cElementInterface *old_element=transform_context.SetElement(&element);
        cElementSetInterface *old_element_set=transform_context.SetElementSet(&element);

        error = transform.TransformElementSetByType
        (output_element_set, template_element, 
         document_factory, transform_context);

        transform_context.SetElementSet(old_element_set);
        transform_context.SetElement(old_element);
        return error;
    }
    /**
     **********************************************************************
     * Function: TransformSiblingsWithElement
     *
     *   Author: $author$
     *     Date: 2/21/2004
     **********************************************************************
     */
    virtual eError TransformSiblingsWithElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cElementInterface &element)
    {
        eError error=e_ERROR_NONE;
        cElementInterface *old_element=transform_context.SetElement(&element);
        cElementSetInterface *old_element_set=transform_context.SetElementSet(&element);

        error = transform.TransformElementSiblingsByType
        (output_element_set, template_element, 
         document_factory, transform_context);

        transform_context.SetElementSet(old_element_set);
        transform_context.SetElement(old_element);
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDTFunctionWithFirstElement
 *
 * Author: $author$
 *   Date: 2/11/2004
 **********************************************************************
 */
class cDTFunctionWithFirstElement
: public cWithElementSetDTFunction
{
public:
    typedef cWithElementSetDTFunction cIs;

    /**
     **********************************************************************
     * Constructor: cDTFunctionWithFirstElement
     *
     *      Author: $author$
     *        Date: 2/11/2004
     **********************************************************************
     */
    cDTFunctionWithFirstElement(const char *name, int length=-1)
    : cIs(name, length)
    {
    }
    /**
     **********************************************************************
     * Function: WithElementSet
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError WithElementSet
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cElementSetInterface &element_set,
     cElementInterface *arguments)
    {
        eError error=e_ERROR_NONE;
        cElementInterface *element;

        if ((element = element_set.GetFirstElement()))
            error = TransformWithElement
            (output_element_set, template_element,
             document_factory, transform_context,
             transform, *element);
        return error;
    }
} g_dt_function_withfirstelement("with-first-element") ;

/**
 **********************************************************************
 *  Class: cDTFunctionWithFirstParentElement
 *
 * Author: $author$
 *   Date: 2/13/2004
 **********************************************************************
 */
class cDTFunctionWithFirstParentElement
: public cWithElementSetDTFunction
{
public:
    typedef cWithElementSetDTFunction cIs;

    /**
     **********************************************************************
     * Constructor: cDTFunctionWithFirstParentElement
     *
     *      Author: $author$
     *        Date: 2/13/2004
     **********************************************************************
     */
    cDTFunctionWithFirstParentElement(const char *name, int length=-1)
    : cIs(name, length)
    {
    }
    /**
     **********************************************************************
     * Function: WithElementSet
     *
     *   Author: $author$
     *     Date: 2/13/2004
     **********************************************************************
     */
    virtual eError WithElementSet
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cElementSetInterface &element_set)
    {
        eError error=e_ERROR_NONE;
        cElementInterface *element;

        if ((element = element_set.GetFirstParentElement()))
            error = TransformWithElement
            (output_element_set, template_element,
             document_factory, transform_context,
             transform, *element);
        return error;
    }
} g_dt_function_withfirstparentelement("with-first-parent-element") ;

/**
 **********************************************************************
 *  Class: cDTFunctionForEachElement
 *
 * Author: $author$
 *   Date: 2/13/2004
 **********************************************************************
 */
class cDTFunctionForEachElement
: public cWithElementSetDTFunction
{
public:
    typedef cWithElementSetDTFunction cIs;

    /**
     **********************************************************************
     * Constructor: cDTFunctionForEachElement
     *
     *      Author: $author$
     *        Date: 2/13/2004
     **********************************************************************
     */
    cDTFunctionForEachElement(const char *name, int length=-1)
    : cIs(name, length)
    {
    }
    /**
     **********************************************************************
     * Function: WithElementSet
     *
     *   Author: $author$
     *     Date: 2/13/2004
     **********************************************************************
     */
    virtual eError WithElementSet
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cElementSetInterface &element_set)
    {
        eError error=e_ERROR_NONE;
        cElementInterface *element;

        if ((element = element_set.GetFirstElement()))
        do
        {
            if ((error = TransformWithElement
                (output_element_set, template_element,
                 document_factory, transform_context,
                 transform, *element)))
                break;
        }
        while ((element = element->GetNextElement()));
        return error;
    }
} g_dt_function_foreachelement("for-each-element");

/**
 **********************************************************************
 *  Class: cDTFunctionForEachElementOf
 *
 * Author: $author$
 *   Date: 2/17/2004
 **********************************************************************
 */
class cDTFunctionForEachElementOf
: public cWithElementSetDTFunction
{
public:
    typedef cWithElementSetDTFunction cIs;

    /**
     **********************************************************************
     * Constructor: cDTFunctionForEachElementOf
     *
     *      Author: $author$
     *        Date: 2/17/2004
     **********************************************************************
     */
    cDTFunctionForEachElementOf(const char *name, int length=-1)
    : cIs(name, length) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/17/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *argument=template_element.GetFirstParentElement();
        cElementInterface *element;
        cElementSet element_set;

        if (argument)
        {
            if ((error = transform.TransformElement
                (element_set, *argument,
                 document_factory, transform_context)))
                return error;

            if ((element = element_set.GetFirstElement()))
            do
            {
                const char *text=element->GetText();

                if ((error = TransformSiblingsWithElement
                    (output_element_set, *argument,
                     document_factory, transform_context,
                     transform, *element)))
                    break;
            }
            while ((element = element->GetNextElement()));
        }
        return error;
    }
} g_dt_function_foreachelementof("for-each-element-of") ;

/**
 **********************************************************************
 *  Class: cDTFunctionForEachParentElement
 *
 * Author: $author$
 *   Date: 2/13/2004
 **********************************************************************
 */
class cDTFunctionForEachParentElement
: public cWithElementSetDTFunction
{
public:
    typedef cWithElementSetDTFunction cIs;

    /**
     **********************************************************************
     * Constructor: cDTFunctionForEachParentElement
     *
     *      Author: $author$
     *        Date: 2/13/2004
     **********************************************************************
     */
    cDTFunctionForEachParentElement(const char *name, int length=-1)
    : cIs(name, length)
    {
    }
    /**
     **********************************************************************
     * Function: WithElementSet
     *
     *   Author: $author$
     *     Date: 2/13/2004
     **********************************************************************
     */
    virtual eError WithElementSet
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     cTransformInterface &transform,
     cElementSetInterface &element_set)
    {
        eError error=e_ERROR_NONE;
        cElementInterface *element;

        if ((element = element_set.GetFirstParentElement()))
        do
        {
            if ((error = TransformWithElement
                (output_element_set, template_element,
                 document_factory, transform_context,
                 transform, *element)))
                break;
        }
        while ((element = element->GetNextParentElement()));
        return error;
    }
} g_dt_function_foreachparentelement("for-each-parent-element");

/**
 **********************************************************************
 *  Class: cDTFunctionApply
 *
 * Author: $author$
 *   Date: 2/25/2004
 **********************************************************************
 */
class cDTFunctionApply
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionApply
     *
     *      Author: $author$
     *        Date: 2/25/2004
     **********************************************************************
     */
    cDTFunctionApply(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/25/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *arguments=template_element.GetFirstParentElement();
        cElementInterface *statements;
        cElementInterface *argument;
        cElementInterface *name_argument;
        cElementInterface *value_argument;
        cValueInterface *value;
        cVariableInterface *variable;
        cVariableInterfaceItem *variable_item;
        cVariableInterfaceList variable_list;
        cCharBuffer buffer;
        const char *text;
        int textlen;

        if (arguments)
        if ((statements = arguments->GetNextParentElement()))
        if ((argument = arguments->GetFirstParentElement()))
        {
            do
            {
                text=argument->GetText();

                if ((name_argument = argument->GetFirstParentElement()))
                {
                    text=name_argument->GetText();

                    if ((value_argument = name_argument->GetNextParentElement()))
                    {
                        text=value_argument->GetText();

                        buffer.Clear();
                        if ((error = transform.TransformElementToStream
                            (buffer, *name_argument,
                             document_factory, transform_context)))
                             return error;

                        if ((text = buffer.GetBuffer(textlen)))
                        if (0 < textlen)
                        if ((variable = transform.GetVariable(text, textlen)))
                        if ((value = variable->NewValue()))
                        {
                            cElementSetInterface &value_element_set=value->GetElementSet();

                            if (!(error=transform.TransformElement
                                (value_element_set, *value_argument,
                                 document_factory, transform_context)))
                            if ((variable_item = new cVariableInterfaceItem(*variable)))
                            {
                                variable_list.Add(variable_item);
                                value->Push();
                                continue;
                            }

                            value->Release();

                            while ((variable_item = variable_list.Pull()))
                            {
                                cVariableInterface &variable=variable_item->GetVariable();

                                if ((value = variable.PopValue()))
                                    value->Release();

                                delete variable_item;
                            }
                            return error;
                        }
                    }
                }
            }
            while ((argument = argument->GetNextParentElement()));

            error = transform.
            TransformElementSiblingsByType
            (output_element_set, *arguments, 
             document_factory, transform_context);

            while ((variable_item = variable_list.Pull()))
            {
                cVariableInterface &variable=variable_item->GetVariable();

                if ((value = variable.PopValue()))
                    value->Release();

                delete variable_item;
            }
        }
        return error;
    }
} g_dt_function_apply("apply");

/**
 **********************************************************************
 *  Class: cDTFunctionApplyTemplate
 *
 * Author: $author$
 *   Date: 3/7/2004
 **********************************************************************
 */
class cDTFunctionApplyTemplate
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionApplyTemplate
     *
     *      Author: $author$
     *        Date: 3/7/2004
     **********************************************************************
     */
    cDTFunctionApplyTemplate(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 3/7/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *name_argument=template_element.GetFirstParentElement();
        cElementInterface *arguments;
        cElementInterface *argument;
        cElementInterface *value_argument;
        cValueInterface *value;
        cValueInterface *template_value;
        cVariableInterface *variable;
        cVariableInterfaceItem *variable_item;
        cVariableInterfaceList variable_list;
        cCharBuffer buffer;
        const char *text;
        int textlen;

        if (name_argument)
        if (!(error = transform.TransformElementToStream
            (buffer, *name_argument, document_factory, transform_context)))
        if ((text = buffer.GetBuffer(textlen)))
        if (0 < textlen)
        if ((variable = transform.GetVariable(text, textlen)))
        if ((template_value = variable->GetTemplateValue()))
        {
            cElementSetInterface &template_element_set=template_value->GetElementSet();

            if ((arguments = name_argument->GetNextParentElement()))
            if ((argument = arguments->GetFirstParentElement()))
            do
            {
                text=argument->GetText();

                if ((name_argument = argument->GetFirstParentElement()))
                {
                    text=name_argument->GetText();

                    if ((value_argument = name_argument->GetNextParentElement()))
                    {
                        text=value_argument->GetText();

                        buffer.Clear();
                        if ((error = transform.TransformElementToStream
                            (buffer, *name_argument,
                             document_factory, transform_context)))
                             return error;

                        if ((text = buffer.GetBuffer(textlen)))
                        if (0 < textlen)
                        if ((variable = transform.GetVariable(text, textlen)))
                        if ((value = variable->NewValue()))
                        {
                            cElementSetInterface &value_element_set=value->GetElementSet();

                            if (!(error=transform.TransformElement
                                (value_element_set, *value_argument,
                                 document_factory, transform_context)))
                            if ((variable_item = new cVariableInterfaceItem(*variable)))
                            {
                                variable_list.Add(variable_item);
                                value->Push();
                                continue;
                            }

                            value->Release();

                            while ((variable_item = variable_list.Pull()))
                            {
                                cVariableInterface &variable=variable_item->GetVariable();

                                if ((value = variable.PopValue()))
                                    value->Release();

                                delete variable_item;
                            }
                            return error;
                        }
                    }
                }
            }
            while ((argument = argument->GetNextParentElement()));

            error = transform.
            TransformElementSetByType
            (output_element_set, template_element_set, 
             document_factory, transform_context);

            while ((variable_item = variable_list.Pull()))
            {
                cVariableInterface &variable=variable_item->GetVariable();

                if ((value = variable.PopValue()))
                    value->Release();

                delete variable_item;
            }
        }

        return error;
    }
} g_dt_function_applytemplate("apply-template");

/**
 **********************************************************************
 *  Class: cDTFunctionTemplate
 *
 * Author: $author$
 *   Date: 3/7/2004
 **********************************************************************
 */
class cDTFunctionTemplate
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionTemplate
     *
     *      Author: $author$
     *        Date: 3/7/2004
     **********************************************************************
     */
    cDTFunctionTemplate(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 3/7/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cDocumentInterface *template_document=template_element.GetParentDocument();
        cElementInterface *name_argument=template_element.GetFirstParentElement();
        cElementInterface *argument;
        cElementInterface *element;
        cValueInterface *template_value;
        cVariableInterface *variable;
        const char *text;
        int textlen;

        if (name_argument)
        if ((text = name_argument->GetText(textlen)))
        if (0 < textlen)
        if ((variable = transform.GetVariable(text, textlen)))
        if ((template_value = variable->GetTemplateValue()))
        {
            cElementSetInterface &template_element_set=template_value->GetElementSet();

            if (!(error = template_element_set.DeleteAllElements()))
            if ((argument = name_argument->GetNextParentElement()))
            do
            {
                text=argument->GetText();

                if ((element = template_element_set.AddReferenceElement(*argument)))
                    element->SetParentDocument(template_document);
            }
            while ((argument = argument->GetNextParentElement()));
        }
        return error;
    }
} g_dt_function_template("template");

/**
 **********************************************************************
 *  Class: cDTFunctionIf
 *
 * Author: $author$
 *   Date: 2/10/2004
 **********************************************************************
 */
class cDTFunctionIf
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionIf
     *
     *      Author: $author$
     *        Date: 2/10/2004
     **********************************************************************
     */
    cDTFunctionIf(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *test=template_element.GetFirstParentElement();
        cElementInterface *then;
        cElementSet element_set;

        if (test)
        if ((then = test->GetNextParentElement()))
        {
            if (!(error = transform.TransformElement
                (element_set, *test, 
                 document_factory, transform_context)))

            if ((test = element_set.GetFirstElement()))
                error = transform.TransformElement
                (output_element_set, *then,
                 document_factory, transform_context);

            else error = transform.TransformElementSiblingsByType
                (output_element_set, *then,
                 document_factory, transform_context);
        }
        return error;
    }
} g_dt_function_if("if") ;

/**
 **********************************************************************
 *  Class: cDTFunctionDo
 *
 * Author: $author$
 *   Date: 2/25/2004
 **********************************************************************
 */
class cDTFunctionDo
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionDo
     *
     *      Author: $author$
     *        Date: 2/25/2004
     **********************************************************************
     */
    cDTFunctionDo(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/25/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();

        error = transform.TransformElementSetByType
        (output_element_set, template_element, 
         document_factory, transform_context);
        return error;
    }
} g_dt_function_do("do") ;

/**
 **********************************************************************
 *  Class: cDTFunctionEqual
 *
 * Author: $author$
 *   Date: 2/13/2004
 **********************************************************************
 */
class cDTFunctionEqual
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionEqual
     *
     *      Author: $author$
     *        Date: 2/13/2004
     **********************************************************************
     */
    cDTFunctionEqual(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/13/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *compare=template_element.GetFirstParentElement();
        cElementInterface *to;

        if (compare)
        if ((to = compare->GetNextParentElement()))
        {
            cCharBuffer buffer;
            const char *text;
            int textlen;

            if (!(error = transform.TransformElementToStream
                (buffer, *compare,
                 document_factory,transform_context)))
            if ((text = buffer.GetBuffer(textlen)))
            {
                cCharBuffer tobuffer;
                const char *totext;
                int totextlen;

                if (!(error = transform.TransformElementToStream
                    (tobuffer, *to,
                     document_factory,transform_context)))
                if ((totext = tobuffer.GetBuffer(totextlen)))
                if (textlen == totextlen)
                if (0 == strncmp(text, totext, textlen))
                    output_element_set.AddTextElement(text, textlen);
            }
        }
        return error;
    }
} g_dt_function_equal("equal") ;

/**
 **********************************************************************
 *  Class: cDTFunctionNotEqual
 *
 * Author: $author$
 *   Date: 4/15/2004
 **********************************************************************
 */
class cDTFunctionNotEqual
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionNotEqual
     *
     *      Author: $author$
     *        Date: 4/15/2004
     **********************************************************************
     */
    cDTFunctionNotEqual(const char *name, int length=-1)
    : cIs(name, length) ,
      m_item(*this) 
    {
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 4/15/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        eError error=e_ERROR_NONE;
        cTransformInterface &transform=transform_context.GetTransform();
        cElementInterface *compare=template_element.GetFirstParentElement();
        cElementInterface *to;

        if (compare)
        if ((to = compare->GetNextParentElement()))
        {
            cCharBuffer buffer;
            const char *text;
            int textlen;

            if (!(error = transform.TransformElementToStream
                (buffer, *compare,
                 document_factory,transform_context)))
            if ((text = buffer.GetBuffer(textlen)))
            {
                cCharBuffer tobuffer;
                const char *totext;
                int totextlen;

                if (!(error = transform.TransformElementToStream
                    (tobuffer, *to,
                     document_factory,transform_context)))
                if ((totext = tobuffer.GetBuffer(totextlen)))
                if (textlen == totextlen)
                if (strncmp(text, totext, textlen))
                    output_element_set.AddTextElement(text, textlen);
            }
        }
        return error;
    }
} g_dt_function_notequal("not-equal") ;

