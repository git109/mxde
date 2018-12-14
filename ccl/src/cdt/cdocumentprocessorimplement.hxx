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
 *   File: cdocumentprocessorimplement.hxx
 *
 * Author: $author$
 *   Date: 12/7/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTPROCESSORIMPLEMENT_HXX
#define _CDOCUMENTPROCESSORIMPLEMENT_HXX

#include "cdocumentprocessorinterface.hxx"

/**
 **********************************************************************
 *  Class: cDocumentProcessorImplement
 *
 * Author: $author$
 *   Date: 12/7/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentProcessorImplement
: virtual public cDocumentProcessorInterface
{
public:
    /**
     **********************************************************************
     * Function: PreprocessDocument
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual eError PreprocessDocument
    (cDocumentNodeListInterface& result,
     cDocumentNodeListInterface& function,
     cDocumentInterface& parameter) 
    {
        cDocumentInterface* document = SetDocumentInterface(&parameter);
        eError error = Preprocess(result, function, parameter);
        SetDocumentInterface(document);
        return error;
    }
    /**
     **********************************************************************
     * Function: Preprocess
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual eError Preprocess
    (cDocumentNodeListInterface& result,
     cDocumentNodeListInterface& function,
     cDocumentNodeListInterface& parameter) 
    {
        cDocumentNodeListInterface* nodes = SetNodeListInterface(&parameter);
        eError error = PreprocessFunction(result, function);
        SetNodeListInterface(nodes);
        return error;
    }
    /**
     **********************************************************************
     * Function: PreprocessFunction
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual eError PreprocessFunction
    (cDocumentNodeListInterface& result,
     cDocumentNodeListInterface& function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeInterface* node;

        if ((node = function.GetFirstNode()))
        do
        {
            if ((error = PreprocessFunctionNode
                (result, *node)))
                break;
        }
        while ((node = node->GetNextNode()));
        return error;
    }
    /**
     **********************************************************************
     * Function: PreprocessFunctionNode
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual eError PreprocessFunctionNode
    (cDocumentNodeListInterface& result,
     cDocumentNodeInterface& function) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: ProcessDocument
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual eError ProcessDocument
    (cDocumentNodeListInterface& result,
     cDocumentNodeListInterface& function,
     cDocumentInterface& parameter) 
    {
        cDocumentInterface* document = SetDocumentInterface(&parameter);
        eError error = Process(result, function, parameter);
        SetDocumentInterface(document);
        return error;
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
    (cDocumentNodeListInterface& result,
     cDocumentNodeListInterface& function,
     cDocumentNodeListInterface& parameter) 
    {
        cDocumentNodeListInterface* nodes = SetNodeListInterface(&parameter);
        eError error = ProcessFunction(result, function);
        SetNodeListInterface(nodes);
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessFunction
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    virtual eError ProcessFunction
    (cDocumentNodeListInterface& result,
     cDocumentNodeListInterface& function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeInterface* node;

        if ((node = function.GetFirstNode()))
        do
        {
            if ((error = ProcessFunctionNode
                (result, *node)))
                break;
        }
        while ((node = node->GetNextNode()));
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessFunctionToText
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual int ProcessFunctionToText
    (cCCharBuffer& result,
     cDocumentNodeListInterface& function,
     bool clear_result=false) 
    {
        int count,length = 0;
        cDocumentNodeInterface* node;

        if (clear_result)
        if (0 > (length = result.Clear()))
            return length;

        if ((node = function.GetFirstNode()))
        do
        {
            if (0 > (count = ProcessFunctionNodeToText
                (result, *node)))
                return count;

            length += count;
        }
        while ((node = node->GetNextNode()));
        return length;
    }
    /**
     **********************************************************************
     * Function: ProcessFunctionNode
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    virtual eError ProcessFunctionNode
    (cDocumentNodeListInterface& result,
     cDocumentNodeInterface& function) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessFunctionNodeToText
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual int ProcessFunctionNodeToText
    (cCCharBuffer& result,
     cDocumentNodeInterface& function,
     bool clear_result=false) 
    {
        int length = 0;
        eError error;
        cDocumentNodeListInterface* op1;

        if ((op1 = CreateNodeList(error)))
        {
            if ((error = ProcessFunctionNode
                (*op1, function)))
                length = -error;

            else 
            {
                if (clear_result)
                if (0 < (length = result.Clear()))
                    length = 0;

                if (0 <= length)
                    length = PrintToText(result, *op1);
            }

            if ((error = DestroyNodeList(*op1)))
            if (0 <= length)
                length = -error;
        }
        else length = -error;
        return length;
    }
    /**
     **********************************************************************
     * Function: ProcessFunctionElement
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual eError ProcessFunctionElement
    (cDocumentNodeListInterface& result,
     cDocumentElementInterface& function) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessFunctionElementToInteger
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual int ProcessFunctionElementToInteger
    (cDocumentElementInterface& function) 
    {
        int length, value = 0;
        const cChar* chars;
        cCCharBuffer result;

        if (0 < (length = ProcessFunctionElementToText
            (result, function)))
        if ((chars = result.GetBuffer(length)))
        for (; 0<length; --length, chars++)
        {
            char c = chars->ToChar();

            if (('0' <= c) && ('9' >= c))
                value = value*10 + (c-'0');
        }
        return value;
    }
    /**
     **********************************************************************
     * Function: ProcessFunctionElementToText
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual int ProcessFunctionElementToText
    (cCCharBuffer& result,
     cDocumentElementInterface& function,
     bool clear_result=false) 
    {
        int length = 0;
        eError error;
        cDocumentNodeListInterface* op1;

        if ((op1 = CreateNodeList(error)))
        {
            if ((error = ProcessFunctionElement
                (*op1, function)))
                length = -error;

            else 
            {
                if (clear_result)
                if (0 < (length = result.Clear()))
                    length = 0;

                if (0 <= length)
                    length = PrintToText(result, *op1);
            }

            if ((error = DestroyNodeList(*op1)))
            if (0 <= length)
                length = -error;
        }
        else length = -error;
        return length;
    }
    /**
     **********************************************************************
     * Function: ProcessTextToText
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int ProcessTextToText
    (cCCharBuffer& result,
     const cCCharBuffer& function,
     cDocumentNodeListInterface& parameter) 
    {
        int length = result.Write(function);
        return length;
    }
    /**
     **********************************************************************
     * Function: PrintToText
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int PrintToText
    (cCCharBuffer& result,
     cDocumentNodeListInterface& function) 
    {
        int count, length = 0;
        cDocumentNodeInterface* node;
        cDocumentTextInterface* text;
        cDocumentAttributeInterface* attribute;
        cDocumentElementInterface* element;

        if ((node = function.GetFirstNode()))
        do
        {
            if ((element = node->GetElementInterface()))
            {
                if (0 > (count = PrintToText(result, *element)))
                    return count;

                length += count;
            }
            else if ((text = node->GetTextInterface()))
            {
                const cCCharBuffer& buffer = text->GetText();

                if (0 > (count = result.Write(buffer)))
                    return count;

                length += count;
            }
            else if ((attribute = node->GetAttributeInterface()))
            {
                const cCCharBuffer& buffer = attribute->GetValue();

                if (0 > (count = result.Write(buffer)))
                    return count;

                length += count;
            }
        }
        while ((node = node->GetNextNode()));
        return length;
    }

    /**
     **********************************************************************
     * Function: SetVariableToText
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual eError SetVariableToText
    (const cCCharBuffer& name, 
     const cCCharBuffer& value) 
    {
        eError error = e_ERROR_FAILED;
        cDocumentNodeListInterface* nodes;

        if ((nodes = GetSetVariableToText(error, name, value)))
            error = DestroyNodeList(*nodes);
        return error;
    }
    /**
     **********************************************************************
     * Function: GetSetVariableToText
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* GetSetVariableToText
    (eError& error,
     const cCCharBuffer& name, 
     const cCCharBuffer& value) 
    {
        cDocumentNodeListInterface* old_node_list = 0;
        cDocumentNodeListInterface* node_list;
        cDocumentTextInterface* text;

        if ((node_list = CreateNodeList(error)))
        {
            if ((text = node_list->AddText(error, value)))
            if (!error)
            {
                old_node_list = GetSetVariable
                (error, name, node_list);
                return old_node_list;
            }
            DestroyNodeList(*node_list);
        }
        return old_node_list;
    }
    /**
     **********************************************************************
     * Function: SetVariable
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual eError SetVariable
    (const cCCharBuffer& name, 
     cDocumentNodeListInterface* value) 
    {
        eError error = e_ERROR_FAILED;
        cDocumentNodeListInterface* nodes;

        if ((nodes = GetSetVariable(error, name, value)))
            error = DestroyNodeList(*nodes);
        return error;
    }
    /**
     **********************************************************************
     * Function: GetSetVariable
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* GetSetVariable
    (eError& error,
     const cCCharBuffer& name, 
     cDocumentNodeListInterface* node_list) 
    {
        cDocumentNodeListInterface* old_node_list = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return old_node_list;
    }
    /**
     **********************************************************************
     * Function: GetVariable
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* GetVariable
    (const cCCharBuffer& name) const 
    {
        cDocumentNodeListInterface* node_list = 0;
        return node_list;
    }

    /**
     **********************************************************************
     * Function: GetElementInterface
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetElementInterface() const
    {
        cDocumentElementInterface* element = 0;
        cDocumentNodeInterface* node;

        if ((node = GetNodeInterface()))
            element = node->GetElementInterface();
        return element;
    }

    /**
     **********************************************************************
     * Function: GetFirstRootElementByName
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetFirstRootElementByName
    (const cCCharBuffer& name) const 
    {
        cDocumentNodeListInterface& nodes = GetDocumentInterface();
        cDocumentElementInterface* node = nodes.GetFirstElementByName(name);
        return node;
    }
    /**
     **********************************************************************
     * Function: GetFirstElementByName
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetFirstElementByName
    (const cCCharBuffer& name) const 
    {
        cDocumentNodeListInterface& nodes = GetNodeListInterface();
        cDocumentElementInterface* node = nodes.GetFirstElementByName(name);
        return node;
    }

    /**
     **********************************************************************
     * Function: RegisterTemplateElement
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual eError RegisterTemplateElement
    (const cCCharBuffer& name,
     cDocumentElementInterface& element) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: UnregisterTemplateElement
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual eError UnregisterTemplateElement
    (const cCCharBuffer& name) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: FindTemplateElement
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* FindTemplateElement
    (const cCCharBuffer& name) const 
    {
        cDocumentElementInterface* element = 0;
        return element;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNodeProcessorImplement
 *
 * Author: $author$
 *   Date: 12/7/2005
 **********************************************************************
 */
class cDocumentNodeProcessorImplement
: virtual public cDocumentNodeProcessorInterface
{
public:
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    virtual eError Initialize
    (cDocumentProcessorInterface& processor) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    virtual eError Finalize
    (cDocumentProcessorInterface& processor) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface& processor,
     cDocumentNodeListInterface& result,
     cDocumentNodeListInterface& function) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetElementProcessor
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual cDocumentElementProcessorInterface* 
    GetElementProcessor() const
    {
        cDocumentElementProcessorInterface *processor = 0;
        return processor;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentElementProcessorImplement
 *
 * Author: $author$
 *   Date: 12/7/2005
 **********************************************************************
 */
class cDocumentElementProcessorImplement
: virtual public cDocumentElementProcessorInterface
{
public:
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface& processor,
     cDocumentNodeListInterface& result,
     cDocumentElementInterface& function) 
    {
        eError error = processor.ProcessFunction
        (result, function);
        return error;
    }
};

#endif /* _CDOCUMENTPROCESSORIMPLEMENT_HXX */
