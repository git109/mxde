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
 *   File: cdocumentprocessorinterface.hxx
 *
 * Author: $author$
 *   Date: 12/7/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTPROCESSORINTERFACE_HXX
#define _CDOCUMENTPROCESSORINTERFACE_HXX

#include "cdocumentinterface.hxx"
#include "cinitializeinterface.hxx"

class cDocumentNodeProcessorItem;
class cDocumentNodeProcessorList;

class cDocumentElementProcessorBranch;
class cDocumentElementProcessorTree;

class c_INTERFACE_CLASS cDocumentTextProcessorInterface;
class c_INTERFACE_CLASS cDocumentCommentProcessorInterface;
class c_INTERFACE_CLASS cDocumentElementProcessorInterface;

/**
 **********************************************************************
 *  Class: cDocumentProcessorInterface
 *
 * Author: $author$
 *   Date: 12/7/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentProcessorInterface
: virtual public cInitializeInterface
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
     cDocumentInterface& parameter) = 0;
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
     cDocumentNodeListInterface& parameter) = 0;
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
     cDocumentNodeListInterface& function) = 0;
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
     cDocumentNodeInterface& function) = 0;
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
     cDocumentInterface& parameter) = 0;
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
     cDocumentNodeListInterface& parameter) = 0;
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
     cDocumentNodeListInterface& function) = 0;
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
     bool clear_result=false) = 0;
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
     cDocumentNodeInterface& function) = 0;
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
     bool clear_result=false) = 0;
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
     cDocumentElementInterface& function) = 0;
    /**
     **********************************************************************
     * Function: ProcessFunctionElementToInteger
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual int ProcessFunctionElementToInteger
    (cDocumentElementInterface& function) = 0;
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
     bool clear_result=false) = 0;
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
     cDocumentNodeListInterface& parameter) = 0;
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
     cDocumentNodeListInterface& function) = 0;
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
     const cCCharBuffer& value) = 0;
    /**
     **********************************************************************
     * Function: GetSetVariable
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* GetSetVariableToText
    (eError& error,
     const cCCharBuffer& name, 
     const cCCharBuffer& value) = 0;
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
     cDocumentNodeListInterface* value) = 0;
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
     cDocumentNodeListInterface* node_list) = 0;
    /**
     **********************************************************************
     * Function: GetVariable
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* GetVariable
    (const cCCharBuffer& name) const = 0;
    /**
     **********************************************************************
     * Function: CreateNodeList
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* 
    CreateNodeList(eError &error) = 0;
    /**
     **********************************************************************
     * Function: DestroyNodeList
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual eError DestroyNodeList
    (cDocumentNodeListInterface& node_list) = 0;
    /**
     **********************************************************************
     * Function: SetDocumentInterface
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual cDocumentInterface* SetDocumentInterface
    (cDocumentInterface* document) = 0;
    /**
     **********************************************************************
     * Function: GetDocumentInterface
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual cDocumentInterface& GetDocumentInterface() const = 0;
    /**
     **********************************************************************
     * Function: SetNodeListInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* SetNodeListInterface
    (cDocumentNodeListInterface* node_list) = 0;
    /**
     **********************************************************************
     * Function: GetNodeListInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface& GetNodeListInterface() const = 0;
    /**
     **********************************************************************
     * Function: SetNodeInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* SetNodeInterface
    (cDocumentNodeInterface* node) = 0;
    /**
     **********************************************************************
     * Function: GetNodeInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* GetNodeInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetElementInterface
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetElementInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetFirstRootElementByName
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetFirstRootElementByName
    (const cCCharBuffer& name) const = 0;
    /**
     **********************************************************************
     * Function: GetFirstElementByName
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetFirstElementByName
    (const cCCharBuffer& name) const = 0;

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
     cDocumentElementInterface& element) = 0;
    /**
     **********************************************************************
     * Function: UnregisterTemplateElement
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual eError UnregisterTemplateElement
    (const cCCharBuffer& name) = 0;
    /**
     **********************************************************************
     * Function: FindTemplateElement
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* FindTemplateElement
    (const cCCharBuffer& name) const = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentNodeProcessorInterface
 *
 * Author: $author$
 *   Date: 12/7/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentNodeProcessorInterface
: virtual public cInterface
{
public:
    static cDocumentNodeProcessorInterface* m_default;

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    virtual eError Initialize
    (cDocumentProcessorInterface& processor) = 0;
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    virtual eError Finalize
    (cDocumentProcessorInterface& processor) = 0;
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
     cDocumentNodeListInterface& function) = 0;
    /**
     **********************************************************************
     * Function: GetElementProcessor
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual cDocumentElementProcessorInterface* 
    GetElementProcessor() const = 0;
    /**
     **********************************************************************
     * Function: GetItem
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual cDocumentNodeProcessorItem &GetItem() const = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentElementProcessorInterface
 *
 * Author: $author$
 *   Date: 12/7/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentElementProcessorInterface
: virtual public cDocumentNodeProcessorInterface
{
public:
    static cDocumentElementProcessorInterface* m_default;

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
     cDocumentElementInterface& function) = 0;
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual cDocumentElementProcessorBranch& GetBranch() const = 0;
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetName() const = 0;
};

#endif /* _CDOCUMENTPROCESSORINTERFACE_HXX */
