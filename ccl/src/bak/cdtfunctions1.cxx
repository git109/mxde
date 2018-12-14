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
 *   Date: 2/8/2004
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
                        arguments = argument;
                        buffer.Clear();
                        continue;
                    }
                    return error;
                }
                while ((argument = argument->GetNextParentElement()));
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
        cElementInterface *statements;
        cElementInterface *element;
        cCharBuffer buffer;
        const char *text;
        int textlen;

        if (element_set)
        if (arguments)
        {
            if ((statements = arguments->GetNextParentElement()))
            {
                if ((element = arguments->GetFirstParentElement()))
                do
                {
                    if (!(error = transform.TransformElementToStream
                        (buffer, *element, 
                         document_factory, transform_context)))
                    if ((text = buffer.GetBuffer(textlen)))
                    if (textlen > 0)
                    if ((element_set = element_set->
                        GetFirstParentElementByText(text, textlen)))
                    {
                        buffer.Clear();
                        continue;
                    }
                    return error;
                }
                while ((element = element->GetNextParentElement()));
            }
            else arguments = 0;

            error = WithElementSet
            (output_element_set, template_element,
             document_factory, transform_context,
             transform, *element_set, arguments);
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
     cElementInterface *element,
     cElementInterface *arguments)
    {
        eError error=e_ERROR_NONE;
        cElementInterface *old_element=transform_context.SetElement(element);
        cElementSetInterface *old_element_set=transform_context.SetElementSet(element);

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

        return error;
    }
};

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

        error = transform.TransformElementSet
        (output_element_set, template_element, 
         document_factory, transform_context);
        return error;
    }
} g_dt_function_transform("transform") ;

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
        cElementInterface *argument=template_element.GetFirstParentElement();
        cElementInterface *statements;
        cVariableInterface *variable;
        cValueInterface *value;
        cCharBuffer buffer;
        const char *text;
        int textlen;

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
 *  Class: cDTFunctionElement
 *
 * Author: $author$
 *   Date: 2/10/2004
 **********************************************************************
 */
class cDTFunctionElement
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionElement
     *
     *      Author: $author$
     *        Date: 2/10/2004
     **********************************************************************
     */
    cDTFunctionElement(const char *name, int length=-1)
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
        cElementInterface *output_element;
        const char *text="element";
        int textlen=-1;
        unsigned type=cElementInterface::e_TYPE_PARENT_ELEMENT;

        if ((output_element = output_element_set.
            AddElement(text, textlen, type)))
        {
        }
        return error;
    }
} g_dt_function_element("element") ;

/**
 **********************************************************************
 *  Class: cDTFunctionGetElementText
 *
 * Author: $author$
 *   Date: 2/10/2004
 **********************************************************************
 */
class cDTFunctionGetElementText
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetElementText
     *
     *      Author: $author$
     *        Date: 2/10/2004
     **********************************************************************
     */
    cDTFunctionGetElementText(const char *name, int length=-1)
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
        cElementSetInterface *element_set=transform_context.GetElementSet();
        cElementInterface *element=transform_context.GetElement();
        const char *text;
        int textlen;

        if (element)
        if ((text = element->GetText(textlen)))
        if (0 < textlen)
            output_element_set.AddTextElement(text, textlen);

        return error;
    }
} g_dt_function_getelementtext("get-element-text") ;

/**
 **********************************************************************
 *  Class: cDTFunctionGetElementType
 *
 * Author: $author$
 *   Date: 2/10/2004
 **********************************************************************
 */
class cDTFunctionGetElementType
: public cTransform::cFunction
{
public:
    typedef cTransform::cFunction cIs;

    cStaticFunctionItem m_item;

    /**
     **********************************************************************
     * Constructor: cDTFunctionGetElementType
     *
     *      Author: $author$
     *        Date: 2/10/2004
     **********************************************************************
     */
    cDTFunctionGetElementType(const char *name, int length=-1)
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
        cElementSetInterface *element_set=transform_context.GetElementSet();
        cElementInterface *element=transform_context.GetElement();
        const char *text;
        int textlen;

        if (element)
        if ((text = element->GetTypeText(textlen)))
        if (0 < textlen)
            output_element_set.AddTextElement(text, textlen);

        return error;
    }
} g_dt_function_getelementtype("get-element-type") ;

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
            error = WithElement
            (output_element_set, template_element,
             document_factory, transform_context,
             transform, element, arguments);

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
     cElementSetInterface &element_set,
     cElementInterface *arguments)
    {
        eError error=e_ERROR_NONE;
        cElementInterface *element;

        if ((element = element_set.GetFirstParentElement()))
            error = WithElement
            (output_element_set, template_element,
             document_factory, transform_context,
             transform, element, arguments);

        return error;
    }
} g_dt_function_withfirstparentelement("with-first-parent-element") ;


/**
 **********************************************************************
 *  Class: cDTFunctionForEachElement
 *
 * Author: $author$
 *   Date: 2/11/2004
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
     *        Date: 2/11/2004
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
        do
        {
            if ((error = WithElement
                (output_element_set, template_element,
                 document_factory, transform_context,
                 transform, element, arguments)))
                break;
        }
        while ((element = element->GetNextElement()));

        return error;
    }
} g_dt_function_foreachelement("for-each-element") ;

/**
 **********************************************************************
 *  Class: cDTFunctionForEachParentElement
 *
 * Author: $author$
 *   Date: 2/11/2004
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
     *        Date: 2/11/2004
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

        if ((element = element_set.GetFirstParentElement()))
        do
        {
            if ((error = WithElement
                (output_element_set, template_element,
                 document_factory, transform_context,
                 transform, element, arguments)))
                break;
        }
        while ((element = element->GetNextParentElement()));

        return error;
    }
} g_dt_function_foreachparentelement("for-each-parent-element") ;


