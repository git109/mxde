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
 *   File: cdocumentprocessor.cxx
 *
 * Author: $author$
 *   Date: 12/7/2005
 *
 *    $Id$
 **********************************************************************
 */

#include <stdio.h>
#include "cdocumentprocessor.hxx"

cDocumentNodeProcessorItem* cDocumentNodeProcessorList::m_first = 0;
cDocumentNodeProcessorItem* cDocumentNodeProcessorList::m_last = 0;
cDocumentNodeProcessorList cDocumentNodeProcessor::m_list;

cDocumentNodeProcessorItem* cDocumentNodePreprocessorList::m_first = 0;
cDocumentNodeProcessorItem* cDocumentNodePreprocessorList::m_last = 0;
cDocumentNodePreprocessorList cDocumentNodeProcessor::m_prelist;

cDocumentElementProcessorInterface* 
cDocumentElementProcessorInterface::m_default = 0;

cDefaultDocumentElementProcessor m_instance;

/**
 **********************************************************************
 *  Class: cTransformDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/19/2005
 **********************************************************************
 */
class cTransformDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cTransformDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/19/2005
     **********************************************************************
     */
    cTransformDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen, &m_prelist)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = processor.
        PreprocessFunction(result, function);
        return error;
    }
} g_transform_processor("transform");

/**
 **********************************************************************
 *  Class: cVariableDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/21/2005
 **********************************************************************
 */
class cVariableDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    cNullDocumentElementProcessor m_null_processor;

    /**
     **********************************************************************
     * Constructor: cVariableDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/21/2005
     **********************************************************************
     */
    cVariableDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen, &m_prelist),
      m_null_processor(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/21/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        int length;
        cDocumentElementInterface* name_expr;
        cDocumentElementInterface* value_expr;
        cDocumentNodeListInterface* value;
        cCCharBuffer name;

        if ((name_expr = function.GetFirstElement()))
        if ((value_expr = name_expr->GetNextElement()))
        if (0 > (length = processor.
            PrintToText(name, *name_expr)))
            error = -length;
        else if (0 < length)
        {
            if ((value = processor.CreateNodeList(error)))
            {
                if (!(error = processor.
                    ProcessFunctionElement(*value, *value_expr)))
                if ((value = processor.GetSetVariable(error, name, value)))
                    processor.DestroyNodeList(*value);
            }
        }
        return error;
    }
} g_variable_processor("variable");

/**
 **********************************************************************
 *  Class: cTemplateDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/19/2005
 **********************************************************************
 */
class cTemplateDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    cNullDocumentElementProcessor m_null_processor;

    /**
     **********************************************************************
     * Constructor: cTemplateDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/19/2005
     **********************************************************************
     */
    cTemplateDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen, &m_prelist),
      m_null_processor(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterface* element;

        if ((element = function.GetFirstElement()))
        {
            const cCCharBuffer& name = element->GetName();
            error = processor.RegisterTemplateElement
            (name, function);
        }
        return error;
    }
} g_template_preprocessor("template");

/**
 **********************************************************************
 *  Class: cApplyTemplateDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/19/2005
 **********************************************************************
 */
class cApplyTemplateDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cApplyTemplateDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/19/2005
     **********************************************************************
     */
    cApplyTemplateDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterface* template_element;
        cDocumentElementInterface* name_expr;
        cDocumentElementInterface* expr;
        cCCharBuffer name;
        int length;

        if ((name_expr = function.GetFirstElement()))
        if (0 > (length = processor.
            ProcessFunctionElementToText(name, *name_expr)))
            error = -length;
        else if (0 < length)
        {
            cCCharToCharBuffer cname(&name);

            if ((template_element = processor.
                FindTemplateElement(name)))
            if ((name_expr = template_element->GetFirstElement()))
            if ((expr = name_expr->GetNextElement()))
                error = processor.
                ProcessFunctionElement(result, *expr);
        }
        return error;
    }
} g_applytemplate_processor("apply-template");

/**
 **********************************************************************
 *  Class: cForEachDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/8/2005
 **********************************************************************
 */
class cForEachDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cForEachDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/8/2005
     **********************************************************************
     */
    cForEachDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        cDocumentNodeListInterface &nodes = processor.GetNodeListInterface();
        eError error = e_ERROR_NONE;
        cDocumentElementInterface* expr;
        
        if ((expr = function.GetFirstElement()))
            error = ProcessNodes
            (processor, result, *expr, nodes);
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessNodes
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual eError ProcessNodes
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function,
     cDocumentNodeListInterface &nodes) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeInterface* old_node;
        cDocumentNodeListInterface* old_nodes;
        cDocumentNodeListInterface* new_nodes;
        cDocumentNodeInterface* node;

        if ((node = nodes.GetFirstNode()))
        do
        {
            new_nodes = node->GetNodeListInterface();
            old_nodes = processor.SetNodeListInterface(new_nodes);
            old_node = processor.SetNodeInterface(node);
            error = ProcessNode(processor, result, function, *node);
            processor.SetNodeInterface(old_node);
            processor.SetNodeListInterface(old_nodes);
        }
        while((node = node->GetNextNode()));
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessNode
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual eError ProcessNode
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function,
     cDocumentNodeInterface &node) 
    {
        eError error = processor.
        ProcessFunctionElement(result, function);
        return error;
    }
} g_foreach_processor("for-each");

/**
 **********************************************************************
 *  Class: cForEachOfDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/17/2005
 **********************************************************************
 */
class cForEachOfDocumentElementProcessor
: public cForEachDocumentElementProcessor
{
public:
    typedef cForEachDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cForEachOfDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/17/2005
     **********************************************************************
     */
    cForEachOfDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterface* of_expr;
        cDocumentElementInterface* each_expr;
        cDocumentNodeListInterface* of;

        if ((of_expr = function.GetFirstElement()))
        if ((each_expr = of_expr->GetNextElement()))
        if ((of = processor.CreateNodeList(error)))
        {
            if (!(error = processor.ProcessFunctionElement
                (*of, *of_expr)))
                error = ProcessNodes
                (processor, result, *each_expr, *of);

            processor.DestroyNodeList(*of);
        }
        return error;
    }
} g_foreachof_processor("for-each-of");

/**
 **********************************************************************
 *  Class: cIfDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/10/2005
 **********************************************************************
 */
class cIfDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cIfDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/10/2005
     **********************************************************************
     */
    cIfDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeInterface* test;
        cDocumentElementInterface* cond_expr;
        cDocumentElementInterface* if_expr;
        cDocumentElementInterface* else_expr;
        cDocumentNodeListInterface* cond;

        if ((cond_expr = function.GetFirstElement()))
        if ((if_expr = cond_expr->GetNextElement()))
        if ((cond = processor.CreateNodeList(error)))
        {
            if (!(error = processor.ProcessFunctionElement
                (*cond, *cond_expr)))

            if ((test = cond->GetFirstNode()))
                error = processor.ProcessFunctionElement
                (result, *if_expr);

            else if ((else_expr = if_expr->GetNextElement()))
                    error = processor.ProcessFunctionElement
                    (result, *else_expr);

            processor.DestroyNodeList(*cond);
        }
        return error;
    }
} g_if_processor("if");

/**
 **********************************************************************
 *  Class: cDoDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/9/2005
 **********************************************************************
 */
class cDoDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cDoDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/9/2005
     **********************************************************************
     */
    cDoDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = processor.ProcessFunction
        (result, function);
        return error;
    }
} g_do_processor("do"),
  g_comma_processor("comma");

/**
 **********************************************************************
 *  Class: cTextDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/9/2005
 **********************************************************************
 */
class cTextDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    cCCharBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cTextDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/9/2005
     **********************************************************************
     */
    cTextDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function)
    {
        cDocumentNodeListInterface &parameter = processor.GetNodeListInterface();
        eError error = e_ERROR_NONE;
        cDocumentNodeInterface* function_node;
        cDocumentTextInterface* function_text;
        int length;

        if ((function_node = function.GetFirstNode()))
        do
        {
            if ((function_text = function_node->GetTextInterface()))
            {
                const cCCharBuffer& text = function_text->GetText();

                if (0 <= (length = m_buffer.Clear()))
                if (0 <= (length = processor.ProcessTextToText
                    (m_buffer, text, parameter)))
                    result.AddText(error, text, length);
            }
        }
        while((function_node = function_node->GetNextNode()));
        return error;
    }
} g_text_processor("text"),
  g_decimal_processor("decimal");

/**
 **********************************************************************
 *  Class: cElementTypeDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/10/2005
 **********************************************************************
 */
class cElementTypeDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cElementTypeDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/10/2005
     **********************************************************************
     */
    cElementTypeDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeInterface* node;

        if ((node = processor.GetNodeInterface()))
        {
            const cCCharBuffer& type = node->GetTypeName();
            result.AddText(error, type);
        }
        return error;
    }
} g_elementtype_processor("element-type");

/**
 **********************************************************************
 *  Class: cElementNameDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/17/2005
 **********************************************************************
 */
class cElementNameDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cElementNameDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/17/2005
     **********************************************************************
     */
    cElementNameDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeInterface* node;
        cDocumentNamedNodeInterface* named;

        if ((node = processor.GetNodeInterface()))
        if ((named = node->GetNamedNodeInterface()))
        {
            const cCCharBuffer& name = named->GetName();
            result.AddText(error, name);
        }
        return error;
    }
} g_elementname_processor("element-name");

/**
 **********************************************************************
 *  Class: cBinaryOpDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/11/2005
 **********************************************************************
 */
class cBinaryOpDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cBinaryOpDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/11/2005
     **********************************************************************
     */
    cBinaryOpDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterface* op1_expr;
        cDocumentElementInterface* op2_expr;
        cDocumentNodeListInterface* op1;
        cDocumentNodeListInterface* op2;

        if ((op1_expr = function.GetFirstElement()))
        if ((op2_expr = op1_expr->GetNextElement()))
        if ((op1 = processor.CreateNodeList(error)))
        {
            if ((op2 = processor.CreateNodeList(error)))
            {
                if (!(error = processor.ProcessFunctionElement
                    (*op1, *op1_expr)))

                if (!(error = processor.ProcessFunctionElement
                    (*op2, *op2_expr)))

                    error = Process
                    (processor, result, *op1, *op2);

                processor.DestroyNodeList(*op2);
            }
            processor.DestroyNodeList(*op1);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentNodeListInterface &op1,
     cDocumentNodeListInterface &op2) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cCompareOpDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/11/2005
 **********************************************************************
 */
class cCompareOpDocumentElementProcessor
: public cBinaryOpDocumentElementProcessor
{
public:
    typedef cBinaryOpDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cCompareOpDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/11/2005
     **********************************************************************
     */
    cCompareOpDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentNodeListInterface &op1, 
     cDocumentNodeListInterface &op2) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeInterface* node;
        int equal;

        if ((equal = Equal(op1, op2)))

        while ((node = op1.PopNode()))
        {
            if ((error = result.AddNode(*node)))
            {
                node->FreeInstance();
                break;
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Equal
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int Equal
    (cDocumentNodeListInterface &op1, 
     cDocumentNodeListInterface &op2) 
    {
        int equal = 0;
        return equal;
    }
};

/**
 **********************************************************************
 *  Class: cEqualDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/10/2005
 **********************************************************************
 */
class cEqualDocumentElementProcessor
: public cCompareOpDocumentElementProcessor
{
public:
    typedef cCompareOpDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cEqualDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/10/2005
     **********************************************************************
     */
    cEqualDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Equal
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int Equal
    (cDocumentNodeListInterface &op1, 
     cDocumentNodeListInterface &op2) 
    {
        int equal = !op1.Compare(op2);
        return equal;
    }
} g_equal_processor("equal");

/**
 **********************************************************************
 *  Class: cNotEqualDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/11/2005
 **********************************************************************
 */
class cNotEqualDocumentElementProcessor
: public cCompareOpDocumentElementProcessor
{
public:
    typedef cCompareOpDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cNotEqualDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/11/2005
     **********************************************************************
     */
    cNotEqualDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Equal
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int Equal
    (cDocumentNodeListInterface &op1, 
     cDocumentNodeListInterface &op2) 
    {
        int equal = op1.Compare(op2);
        return equal;
    }
} g_notequal_processor("not-equal");

/**
 **********************************************************************
 *  Class: cLessDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/11/2005
 **********************************************************************
 */
class cLessDocumentElementProcessor
: public cCompareOpDocumentElementProcessor
{
public:
    typedef cCompareOpDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cLessDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/11/2005
     **********************************************************************
     */
    cLessDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Equal
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int Equal
    (cDocumentNodeListInterface &op1, 
     cDocumentNodeListInterface &op2) 
    {
        int equal = (0 > op1.Compare(op2));
        return equal;
    }
} g_less_processor("less");

/**
 **********************************************************************
 *  Class: cLessOrEqualDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/11/2005
 **********************************************************************
 */
class cLessOrEqualDocumentElementProcessor
: public cCompareOpDocumentElementProcessor
{
public:
    typedef cCompareOpDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cLessOrEqualDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/11/2005
     **********************************************************************
     */
    cLessOrEqualDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Equal
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int Equal
    (cDocumentNodeListInterface &op1, 
     cDocumentNodeListInterface &op2) 
    {
        int equal = (0 >= op1.Compare(op2));
        return equal;
    }
} g_lessorequal_processor("less-or-equal");

/**
 **********************************************************************
 *  Class: cGreaterDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/11/2005
 **********************************************************************
 */
class cGreaterDocumentElementProcessor
: public cCompareOpDocumentElementProcessor
{
public:
    typedef cCompareOpDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGreaterDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/11/2005
     **********************************************************************
     */
    cGreaterDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Equal
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int Equal
    (cDocumentNodeListInterface &op1, 
     cDocumentNodeListInterface &op2) 
    {
        int equal = (0 < op1.Compare(op2));
        return equal;
    }
} g_greater_processor("greater");

/**
 **********************************************************************
 *  Class: cGreaterOrEqualDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/11/2005
 **********************************************************************
 */
class cGreaterOrEqualDocumentElementProcessor
: public cCompareOpDocumentElementProcessor
{
public:
    typedef cCompareOpDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGreaterOrEqualDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/11/2005
     **********************************************************************
     */
    cGreaterOrEqualDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Equal
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int Equal
    (cDocumentNodeListInterface &op1, 
     cDocumentNodeListInterface &op2) 
    {
        int equal = (0 <= op1.Compare(op2));
        return equal;
    }
} g_greaterorequal_processor("greater-or-equal");

/**
 **********************************************************************
 *  Class: cCommentDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 1/2/2006
 **********************************************************************
 */
class cCommentDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cCommentDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 1/2/2006
     **********************************************************************
     */
    cCommentDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 1/2/2006
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        int length;
        cDocumentElementInterface* op1_expr;
        cDocumentCommentInterface* comment;
        cCCharBuffer m_text;
        
        if ((op1_expr = function.GetFirstElement()))
        if (0 > (length = processor.ProcessFunctionElementToText
            (m_text, *op1_expr, true)))
            error = -length;

        if (!error)
            comment = result.AddComment(error, &m_text);

        return error;
    }
} g_comment_processor("comment");

/**
 **********************************************************************
 *  Class: cEndElementDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/12/2005
 **********************************************************************
 */
class cEndElementDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cEndElementDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/12/2005
     **********************************************************************
     */
    cEndElementDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/12/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentEndElementInterface* element;
        cDocumentElementInterface* name_expr;
        cDocumentElementInterface* attrs_expr;
        cDocumentElementInterface* nodes_expr;

        if ((name_expr = function.GetFirstElement()))
        {
            if ((attrs_expr = name_expr->GetNextElement()))
                nodes_expr = attrs_expr->GetNextElement();
            else nodes_expr = 0;

            if ((element = ProcessElement
                (error, processor, result, *name_expr)))
            {
                if (attrs_expr)
                    error = ProcessAttributes
                    (processor, *element, *attrs_expr);

                if (nodes_expr && !error)
                    error = ProcessNodes
                    (processor, *element, *nodes_expr);
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessElement
     *
     *   Author: $author$
     *     Date: 1/5/2006
     **********************************************************************
     */
    virtual cDocumentEndElementInterface* ProcessElement
    (eError& error,
     cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &name_expr) 
    {
        cDocumentEndElementInterface* element = 0;
        cDocumentElementInterface* op1_expr;
        int length;
        cCCharBuffer buffer1;
        cCCharBuffer buffer2;

        if ((op1_expr = name_expr.GetFirstElement()))
        if (0 > (length = processor.
            ProcessFunctionElementToText(buffer1, *op1_expr)))
            error = -length;
        else
        {
            if ((op1_expr = op1_expr->GetNextElement()))
            {
                if (0 > (length = processor.
                    ProcessFunctionElementToText(buffer2, *op1_expr)))
                    error = -length;
                else element = AddElement
                     (error, result, &buffer2, &buffer1);
            }
            else element = AddElement
                 (error, result, &buffer1);
        }
        return element;
    }
    /**
     **********************************************************************
     * Function: ProcessAttributes
     *
     *   Author: $author$
     *     Date: 1/5/2006
     **********************************************************************
     */
    virtual eError ProcessAttributes
    (cDocumentProcessorInterface &processor,
     cDocumentEndElementInterface &element,
     cDocumentElementInterface &attrs_expr) 
    {
        eError error = e_ERROR_NONE;
        int length;
        cDocumentAttributeInterface* attribute;
        cDocumentAttributeListInterface* alist;
        cDocumentElementInterface* op1_expr;
        cDocumentElementInterface* op2_expr;
        cDocumentElementInterface* op3_expr;
        cCCharBuffer buffer1;
        cCCharBuffer buffer2;

        if ((op2_expr = attrs_expr.GetFirstElement()))
        if ((alist = element.GetAttributeListInterface()))
        do
        {
            if ((op1_expr = op2_expr->GetFirstElement()))
            {
                op3_expr = op1_expr->GetNextElement();

                if ((op1_expr = op1_expr->GetFirstElement()))
                {
                    if (0 > (length = processor.ProcessFunctionElementToText
                        (buffer1, *op1_expr, true)))
                        error = -length;
                    else if ((op1_expr = op1_expr->GetNextElement()))
                    {
                        if (0 > (length = processor.ProcessFunctionElementToText
                            (buffer2, *op1_expr, true)))
                            error = -length;
                        else attribute = alist->AddAttribute
                             (error, &buffer2, 0, &buffer1);
                    }
                    else attribute = alist->AddAttribute
                         (error, &buffer1);

                    if (op3_expr && !error)
                    if (0 > (length = processor.ProcessFunctionElementToText
                        (buffer1, *op3_expr, true)))
                        error = -length;
                    else if (0 > (length = attribute->SetValue(buffer1)))
                            error = -length;
                }
            }
        }
        while ((op2_expr = op2_expr->GetNextElement()));
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessNodes
     *
     *   Author: $author$
     *     Date: 1/5/2006
     **********************************************************************
     */
    virtual eError ProcessNodes
    (cDocumentProcessorInterface &processor,
     cDocumentEndElementInterface &element,
     cDocumentElementInterface &nodes_expr) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: AddElement
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentEndElementInterface* AddElement
    (eError& error,
     cDocumentNodeListInterface &result, 
     const cCCharBuffer* name=0,
     const cCCharBuffer* prefix=0) 
    {
        cDocumentEndElementInterface* element 
        = result.AddEndElement(error, name, prefix);
        return element;
    }
} g_endelement_processor("end-element");

/**
 **********************************************************************
 *  Class: cBeginElementDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/12/2005
 **********************************************************************
 */
class cBeginElementDocumentElementProcessor
: public cEndElementDocumentElementProcessor
{
public:
    typedef cEndElementDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cBeginElementDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/12/2005
     **********************************************************************
     */
    cBeginElementDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: AddElement
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentEndElementInterface* AddElement
    (eError& error,
     cDocumentNodeListInterface &result, 
     const cCCharBuffer* name=0,
     const cCCharBuffer* prefix=0) 
    {
        cDocumentEndElementInterface* element 
        = result.AddBeginElement(error, name, prefix);
        return element;
    }
} g_beginelement_processor("begin-element");

/**
 **********************************************************************
 *  Class: cSimpleElementDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/12/2005
 **********************************************************************
 */
class cSimpleElementDocumentElementProcessor
: public cBeginElementDocumentElementProcessor
{
public:
    typedef cBeginElementDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cSimpleElementDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/12/2005
     **********************************************************************
     */
    cSimpleElementDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: AddElement
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentEndElementInterface* AddElement
    (eError& error,
     cDocumentNodeListInterface &result, 
     const cCCharBuffer* name=0,
     const cCCharBuffer* prefix=0) 
    {
        cDocumentEndElementInterface* element 
        = result.AddElement(error, name, prefix);
        return element;
    }
} g_simpleelement_processor("simple-element");

/**
 **********************************************************************
 *  Class: cCompoundElementDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 1/5/2006
 **********************************************************************
 */
class cCompoundElementDocumentElementProcessor
: public cSimpleElementDocumentElementProcessor
{
public:
    typedef cSimpleElementDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cCompoundElementDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 1/5/2006
     **********************************************************************
     */
    cCompoundElementDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: ProcessNodes
     *
     *   Author: $author$
     *     Date: 1/5/2006
     **********************************************************************
     */
    virtual eError ProcessNodes
    (cDocumentProcessorInterface &processor,
     cDocumentEndElementInterface &element,
     cDocumentElementInterface &nodes_expr) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterface* expr = &nodes_expr;
        cDocumentNodeListInterface* nodes;

        if ((nodes = element.GetNodeListInterface()))
        do
        {
            if ((error = processor.
                ProcessFunctionElement(*nodes, *expr)))
                break;
        }
        while ((expr = expr->GetNextElement()));
        return error;
    }
} g_compoundelement_processor("compound-element");

/**
 **********************************************************************
 *  Class: cGetVariableDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/14/2005
 **********************************************************************
 */
class cGetVariableDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGetVariableDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/14/2005
     **********************************************************************
     */
    cGetVariableDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        int length;
        cDocumentNodeListInterface* nodes;
        cCCharBuffer name;

        if ((nodes = function.GetNodeListInterface()))
        if (0 > (length = processor.
            ProcessFunctionToText(name, *nodes)))
            error = -length;
        else
        {
            if (0 < length)
            if ((nodes = processor.GetVariable(name)))
            if (0 > (length = result.AddReferenceNodeList(*nodes)))
                error = -length;
        }
        return error;
    }
} g_getvariable_processor("get-variable");

/**
 **********************************************************************
 *  Class: cGetElementOfRootDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/17/2005
 **********************************************************************
 */
class cGetElementOfRootDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGetElementOfRootDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/17/2005
     **********************************************************************
     */
    cGetElementOfRootDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        int length;
        cDocumentElementInterface* node;
        cDocumentNodeListInterface* nodes;
        cCCharBuffer name;

        if ((nodes = function.GetNodeListInterface()))
        if (0 > (length = processor.
            ProcessFunctionToText(name, *nodes)))
            error = -length;
        else if (0 < length)
        {
            if ((node = processor.GetFirstRootElementByName(name)))
            do
            {
                result.AddReferenceNode(error, *node);
            }
            while ((node = node->GetNextElementByName(name)));
        }
        return error;
    }
} g_getelementofroot_processor("get-element-of-root");

/**
 **********************************************************************
 *  Class: cGetElementOfDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/17/2005
 **********************************************************************
 */
class cGetElementOfDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGetElementOfDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/17/2005
     **********************************************************************
     */
    cGetElementOfDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeListInterface* of;
        cDocumentElementInterface* of_expr;
        cDocumentElementInterface* name_expr;
        cDocumentElementInterface* element;
        cCCharBuffer name;
        int length;

        if ((of_expr = function.GetFirstElement()))
        if ((name_expr = of_expr->GetNextElement()))
        if ((of = processor.CreateNodeList(error)))
        {
            if (!(error = processor.
                ProcessFunctionElement(*of, *of_expr)))
            if (0 > (length = processor.
                ProcessFunctionElementToText(name, *name_expr)))
                error = -length;
            else if (0 < length)
            {            
                if ((element = of->GetFirstElement()))
                do
                {
                    if ((error = ProcessElementOf
                        (processor, result, *element, name)))
                        break;
                }
                while ((element = element->GetNextElement()));
            }

            processor.DestroyNodeList(*of);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessElementOf
     *
     *   Author: $author$
     *     Date: 12/22/2005
     **********************************************************************
     */
    virtual eError ProcessElementOf
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function,
     const cCCharBuffer& name) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeInterface* node;

        if ((node = function.GetFirstElementByName(name)))
        do
        {
            result.AddReferenceNode(error, *node);
        }
        while ((node = node->GetNextElementByName(name)));
        return error;
    }
} g_getelementof_processor("get-element-of");

/**
 **********************************************************************
 *  Class: cGetElementDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class cGetElementDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGetElementDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 1/4/2006
     **********************************************************************
     */
    cGetElementDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterface* element;

        if ((element = processor.GetElementInterface()))
            result.AddReferenceNode(error, *element);
        return error;
    }
} g_getelement_processor("get-element");

/**
 **********************************************************************
 *  Class: cElementParentDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class cElementParentDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cElementParentDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 1/4/2006
     **********************************************************************
     */
    cElementParentDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterface* element;

        if ((element = processor.GetElementInterface()))
        if ((element = element->GetParentElement()))
            result.AddReferenceNode(error, *element);
        return error;
    }
} g_elementparent_processor("element-parent");

/**
 **********************************************************************
 *  Class: cGetElementTextDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class cGetElementTextDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGetElementTextDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 1/4/2006
     **********************************************************************
     */
    cGetElementTextDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterface* element;
        cDocumentTextInterface* text;

        if ((element = processor.GetElementInterface()))
        if ((text = element->GetFirstText()))
        do
        {
            result.AddReferenceNode(error, *text);
        }
        while ((text = text->GetNextText()));
        return error;
    }
} g_getelementtext_processor("get-element-text");

/**
 **********************************************************************
 *  Class: cGetAttributeDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class cGetAttributeDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGetAttributeDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 1/4/2006
     **********************************************************************
     */
    cGetAttributeDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterface* name_expr;
        cDocumentElementInterface* element;
        cDocumentNodeInterface* node;
        cCCharBuffer name;
        int length;

        if ((name_expr = function.GetFirstElement()))
        if ((element = processor.GetElementInterface()))
        if (0 > (length = processor.
            ProcessFunctionElementToText(name, *name_expr)))
            error = -length;
        else if (0 < length)
        {
            if ((node = element->GetFirstAttributeByName(name)))
            do
            {
                result.AddReferenceNode(error, *node);
            }
            while ((node = node->GetNextAttributeByName(name)));
        }
        return error;
    }
} g_getattribute_processor("get-attribute");

/**
 **********************************************************************
 *  Class: cGetAttributeOfDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/22/2005
 **********************************************************************
 */
class cGetAttributeOfDocumentElementProcessor
: public cGetElementOfDocumentElementProcessor
{
public:
    typedef cGetElementOfDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGetAttributeOfDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/22/2005
     **********************************************************************
     */
    cGetAttributeOfDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: ProcessElementOf
     *
     *   Author: $author$
     *     Date: 12/22/2005
     **********************************************************************
     */
    virtual eError ProcessElementOf
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function,
     const cCCharBuffer& name) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeInterface* node;

        if ((node = function.GetFirstAttributeByName(name)))
        do
        {
            result.AddReferenceNode(error, *node);
        }
        while ((node = node->GetNextAttributeByName(name)));
        return error;
    }
} g_getattributeof_processor("get-attribute-of");

/**
 **********************************************************************
 *  Class: cGetElementOfSetAtDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/17/2005
 **********************************************************************
 */
class cGetElementOfSetAtDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGetElementOfSetAtDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/17/2005
     **********************************************************************
     */
    cGetElementOfSetAtDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeListInterface* of;
        cDocumentElementInterface* of_expr;
        cDocumentElementInterface* at_expr;
        int at;

        if ((of_expr = function.GetFirstElement()))
        if ((at_expr = of_expr->GetNextElement()))
        if ((of = processor.CreateNodeList(error)))
        {
            if (!(error = processor.ProcessFunctionElement
                (*of, *of_expr)))
            if (0 <= (at = processor.ProcessFunctionElementToInteger
                (*at_expr)))
                error = ProcessNodesAt
                (processor, result, *of, at);

            processor.DestroyNodeList(*of);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessNodesAt
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual eError ProcessNodesAt
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentNodeListInterface &nodes,
     int at) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeInterface* node;

        if ((node = nodes.GetFirstNode()))
        do
        {
            if (0 < at)
            {
                --at;
                continue;
            }
            result.AddReferenceNode(error, *node);
            break;
        }
        while ((node = node->GetNextNode()));
        return error;
    }
} g_getelementofsetat_processor("get-element-of-set-at");

/**
 **********************************************************************
 *  Class: cGetElementOfAtDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/17/2005
 **********************************************************************
 */
class cGetElementOfAtDocumentElementProcessor
: public cGetElementOfSetAtDocumentElementProcessor
{
public:
    typedef cGetElementOfSetAtDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGetElementOfAtDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/17/2005
     **********************************************************************
     */
    cGetElementOfAtDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: ProcessNodesAt
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual eError ProcessNodesAt
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentNodeListInterface &nodes,
     int at) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterface* element;

        if ((element = nodes.GetFirstElement()))
            error = cIs::ProcessNodesAt
            (processor, result, *element, at);
        return error;
    }
} g_getelementofat_processor("get-element-of-at");

/**
 **********************************************************************
 *  Class: cGetElementsOfDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/17/2005
 **********************************************************************
 */
class cGetElementsOfDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGetElementsOfDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/17/2005
     **********************************************************************
     */
    cGetElementsOfDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeListInterface* of;
        cDocumentElementInterface* of_expr;
        cDocumentElementInterface* element;

        if ((of_expr = function.GetFirstElement()))
        if ((of = processor.CreateNodeList(error)))
        {
            if (!(error = processor.ProcessFunctionElement
                (*of, *of_expr)))
            if ((element = of->GetFirstElement()))
                result.AddReferenceNodeList(*element);

            processor.DestroyNodeList(*of);
        }
        return error;
    }
} g_getelementsof_processor("get-elements-of");

/**
 **********************************************************************
 *  Class: cGetElementsOfSetDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/17/2005
 **********************************************************************
 */
class cGetElementsOfSetDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGetElementsOfSetDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/17/2005
     **********************************************************************
     */
    cGetElementsOfSetDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = processor.ProcessFunction(result, function);
        return error;
    }
} g_getelementsofset_processor("get-elements-of-set");

/**
 **********************************************************************
 *  Class: cGetElementsOfSetWhereDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/17/2005
 **********************************************************************
 */
class cGetElementsOfSetWhereDocumentElementProcessor
: public cForEachDocumentElementProcessor
{
public:
    typedef cForEachDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGetElementsOfSetWhereDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/17/2005
     **********************************************************************
     */
    cGetElementsOfSetWhereDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeListInterface* of;
        cDocumentElementInterface* of_expr;
        cDocumentElementInterface* where_expr;

        if ((of_expr = function.GetFirstElement()))
        if ((where_expr = of_expr->GetNextElement()))
        if ((of = processor.CreateNodeList(error)))
        {
            if (!(error = processor.ProcessFunctionElement
                (*of, *of_expr)))
                error = ProcessNodes
                (processor, result, *where_expr, *of);

            processor.DestroyNodeList(*of);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessNode
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual eError ProcessNode
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function,
     cDocumentNodeInterface &node) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeInterface* at;
        cDocumentNodeListInterface* where;

        if ((where = processor.CreateNodeList(error)))
        {
            if (!(error = processor.ProcessFunctionElement
                (*where, function)))
            if ((at = where->GetFirstNode()))
                result.AddReferenceNode(error, node);

            processor.DestroyNodeList(*where);
        }
        return error;
    }
} g_getelementsofsetwhere_processor("get-elements-of-set-where");

/**
 **********************************************************************
 *  Class: cGetElementsOfWhereDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/17/2005
 **********************************************************************
 */
class cGetElementsOfWhereDocumentElementProcessor
: public cGetElementsOfSetWhereDocumentElementProcessor
{
public:
    typedef cGetElementsOfSetWhereDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cGetElementsOfWhereDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/17/2005
     **********************************************************************
     */
    cGetElementsOfWhereDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: ProcessNodes
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual eError ProcessNodes
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function,
     cDocumentNodeListInterface &nodes) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterface* element;

        if ((element = nodes.GetFirstElement()))
            error = cIs::ProcessNodes
            (processor, result, function, *element);
        return error;
    }
} g_getelementsofwhere_processor("get-elements-of-where");
