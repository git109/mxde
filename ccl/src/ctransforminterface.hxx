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
 *   File: ctransforminterface.hxx
 *
 * Author: $author$
 *   Date: 2/1/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTRANSFORMINTERFACE_HXX
#define _CTRANSFORMINTERFACE_HXX

#include "clistt.hxx"
#include "cavltreet.hxx"
#include "cdocumentsourceinterface.hxx"
#include "cdocumentinterface.hxx"
#include "cinterface.hxx"

class c_INTERFACE_CLASS cTransformTypeInterface;

/**
 **********************************************************************
 *  Class: cTransformInterface
 *
 * Author: $author$
 *   Date: 2/1/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cTransformInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     *  Class: cValueInterface
     *
     * Author: $author$
     *   Date: 8/18/2003
     **********************************************************************
     */
    class c_INTERFACE_CLASS cValueInterface
    : virtual public cInterface
    {
    public:
        /**
         **********************************************************************
         * Function: GetElementSet
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual cElementSetInterface &GetElementSet()=0;
        /**
         **********************************************************************
         * Function: Push
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual void Push()=0;
        /**
         **********************************************************************
         * Function: Update
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual eError Update()=0;
        /**
         **********************************************************************
         * Function: Release
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual eError Release()=0;
    };

    /**
     **********************************************************************
     *  Class: cVariableInterface
     *
     * Author: $author$
     *   Date: 8/18/2003
     **********************************************************************
     */
    class c_INTERFACE_CLASS cVariableInterface
    : virtual public cInterface
    {
    public:
        /**
         **********************************************************************
         * Function: GetValue
         *
         *   Author: $author$
         *     Date: 2/12/2004
         **********************************************************************
         */
        virtual cValueInterface *GetValue()=0;
        /**
         **********************************************************************
         * Function: NewValue
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual cValueInterface *NewValue()=0;
        /**
         **********************************************************************
         * Function: PopValue
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual cValueInterface *PopValue()=0;

        /**
         **********************************************************************
         * Function: GetTemplateValue
         *
         *   Author: $author$
         *     Date: 3/7/2004
         **********************************************************************
         */
        virtual cValueInterface *GetTemplateValue()=0;
        /**
         **********************************************************************
         * Function: NewTemplateValue
         *
         *   Author: $author$
         *     Date: 3/7/2004
         **********************************************************************
         */
        virtual cValueInterface *NewTemplateValue()=0;
        /**
         **********************************************************************
         * Function: PopTemplateValue
         *
         *   Author: $author$
         *     Date: 3/7/2004
         **********************************************************************
         */
        virtual cValueInterface *PopTemplateValue()=0;
    };

    /**
     **********************************************************************
     *  Class: cTransformContextInterface
     *
     * Author: $author$
     *   Date: 2/7/2004
     **********************************************************************
     */
    class c_INTERFACE_CLASS cTransformContextInterface
    : virtual public cInterface
    {
    public:
        /**
         **********************************************************************
         * Function: GetTransform
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual cTransformInterface &GetTransform()=0;

        /**
         **********************************************************************
         * Function: SetDocument
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual cDocumentInterface *SetDocument(cDocumentInterface *instance)=0;
        /**
         **********************************************************************
         * Function: GetDocument
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual cDocumentInterface *GetDocument() const=0;

        /**
         **********************************************************************
         * Function: SetElementSet
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual cElementSetInterface *SetElementSet(cElementSetInterface *instance)=0;
        /**
         **********************************************************************
         * Function: GetElementSet
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual cElementSetInterface *GetElementSet() const=0;

        /**
         **********************************************************************
         * Function: SetElement
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual cElementInterface *SetElement(cElementInterface *instance)=0;
        /**
         **********************************************************************
         * Function: GetElement
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual cElementInterface *GetElement() const=0;

        /**
         **********************************************************************
         * Function: SetAttributeSet
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual cAttributeSetInterface *SetAttributeSet(cAttributeSetInterface *instance)=0;
        /**
         **********************************************************************
         * Function: GetAttributeSet
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual cAttributeSetInterface *GetAttributeSet() const=0;

        /**
         **********************************************************************
         * Function: SetAttribute
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual cAttributeInterface *SetAttribute(cAttributeInterface *instance)=0;
        /**
         **********************************************************************
         * Function: GetAttribute
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual cAttributeInterface *GetAttribute() const=0;
    };

    /**
     **********************************************************************
     *  Class: cFunctionInterface
     *
     * Author: $author$
     *   Date: 2/7/2004
     **********************************************************************
     */
    class c_INTERFACE_CLASS cFunctionInterface
    : virtual public cInterface
    {
    public:
        /**
         **********************************************************************
         * Function: Initialize
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual eError Initialize
        (cTransformInterface &transform)=0;
        /**
         **********************************************************************
         * Function: Finalize
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual eError Finalize
        (cTransformInterface &transform)=0;

        /**
         **********************************************************************
         * Function: TransformElement
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual eError TransformElement
        (cElementSetInterface &output_element_set,
         cElementInterface &template_element,
         cDocumentFactoryInterface &document_factory,
         cTransformContextInterface &transform_context)=0;

        /**
         **********************************************************************
         * Function: SetName
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual int SetName(const char *name, int length=-1)=0;
        /**
         **********************************************************************
         * Function: GetName
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual const char *GetName(int &length) const=0;
    };

    /*
     **********************************************************************
     * cTransformInterface Functions
     **********************************************************************
     */

    /**
     **********************************************************************
     * Function: GetVariable
     *
     *   Author: $author$
     *     Date: 2/12/2004
     **********************************************************************
     */
    virtual cVariableInterface *GetVariable
    (const char *name, int namelen=-1)=0;

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/8/2004
     **********************************************************************
     */
    virtual eError Initialize()=0;
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 2/8/2004
     **********************************************************************
     */
    virtual eError Finalize()=0;

    /**
     **********************************************************************
     * Function: EchoDocument
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual eError EchoDocument
    (cDocumentSourceInterface &output_document_source,
     cDocumentSourceInterface &input_document_source,
     cDocumentFactoryInterface &document_factory)=0;
    /**
     **********************************************************************
     * Function: TransformDocument
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    virtual eError TransformDocument
    (cDocumentSourceInterface &output_document_source,
     cDocumentSourceInterface &input_document_source,
     cDocumentSourceInterface &template_document_source,
     cDocumentFactoryInterface &document_factory)=0;
    /**
     **********************************************************************
     * Function: TransformDocument
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    virtual eError TransformDocument
    (cDocumentInterface &output_document,
     cDocumentSourceInterface &input_document_source,
     cDocumentSourceInterface &template_document_source,
     cDocumentFactoryInterface &document_factory)=0;
    /**
     **********************************************************************
     * Function: TransformDocument
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual eError TransformDocument
    (cDocumentSourceInterface &output_document_source,
     cDocumentInterface &input_document,
     cDocumentInterface &template_document,
     cDocumentFactoryInterface &document_factory)=0;
    /**
     **********************************************************************
     * Function: TransformDocument
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    virtual eError TransformDocument
    (cDocumentInterface &output_document,
     cDocumentInterface &input_document,
     cDocumentInterface &template_document,
     cDocumentFactoryInterface &document_factory)=0;
    /**
     **********************************************************************
     * Function: TransformElementSet
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformElementSet
    (cElementSetInterface &output_element_set,
     cElementSetInterface &template_element_set,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     bool transform_text_elements=true)=0;
    /**
     **********************************************************************
     * Function: TransformElementSetToStream
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformElementSetToStream
    (cCharStream &stream,
     cElementSetInterface &template_element_set,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     bool transform_text_elements=true)=0;
    /**
     **********************************************************************
     * Function: TransformElementSetByTypeToStream
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformElementSetByTypeToStream
    (cCharStream &stream,
     cElementSetInterface &template_element_set,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     unsigned type=cElementInterface::e_TYPE_PARENT_ELEMENT,
     bool transform_text_elements=true)=0;
    /**
     **********************************************************************
     * Function: TransformElementSetByType
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformElementSetByType
    (cElementSetInterface &output_element_set,
     cElementSetInterface &template_element_set,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     unsigned type=cElementInterface::e_TYPE_PARENT_ELEMENT,
     bool transform_text_elements=true)=0;
    /**
     **********************************************************************
     * Function: TransformElementSiblingsByTypeToStream
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError TransformElementSiblingsByTypeToStream
    (cCharStream &stream,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     unsigned type=cElementInterface::e_TYPE_PARENT_ELEMENT,
     bool transform_text_elements=true)=0;
    /**
     **********************************************************************
     * Function: TransformElementSiblingsByType
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformElementSiblingsByType
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     unsigned type=cElementInterface::e_TYPE_PARENT_ELEMENT,
     bool transform_text_elements=true)=0;
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
     cTransformContextInterface &transform_context,
     bool transform_text_elements=true)=0;
    /**
     **********************************************************************
     * Function: TransformTextElement
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformTextElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)=0;
    /**
     **********************************************************************
     * Function: TransformText
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError TransformText
    (cElementSetInterface &output_element_set,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     const char *text, int textlen=-1)=0;
    /**
     **********************************************************************
     * Function: TransformTextToStream
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError TransformTextToStream
    (cCharStream &stream,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     const char *text, int textlen=-1)=0;
    /**
     **********************************************************************
     * Function: TransformElementToStream
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformElementToStream
    (cCharStream &stream,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     bool transform_text_elements=true)=0;

    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    virtual eError SetType(cTransformTypeInterface *type)=0;
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    virtual cTransformTypeInterface *GetType() const=0;
};

/**
 **********************************************************************
 *  Class: cTransformImplement
 *
 * Author: $author$
 *   Date: 2/1/2004
 **********************************************************************
 */
class cTransformImplement
: virtual public cTransformInterface
{
public:
    typedef cTransformInterface::cFunctionInterface cFunctionInterface;

    /**
     **********************************************************************
     *  Class: cValueInterfaceItem
     *
     * Author: $author$
     *   Date: 2/12/2004
     **********************************************************************
     */
    class cValueInterfaceItem
    : public cListItemT<cValueInterfaceItem>
    {
    public:
        typedef cListItemT<cValueInterfaceItem> cIs;

        cValueInterface &m_value;

        /**
         **********************************************************************
         * Constructor: cValueInterfaceItem
         *
         *      Author: $author$
         *        Date: 2/12/2004
         **********************************************************************
         */
        cValueInterfaceItem(cValueInterface &value) 
        :  m_value(value) 
        {
        }
        /**
         **********************************************************************
         * Function: GetValue
         *
         *   Author: $author$
         *     Date: 2/12/2004
         **********************************************************************
         */
        cValueInterface &GetValue()
        {
            return m_value;
        }
    };

    /**
     **********************************************************************
     *  Class: cValueInterfaceStack
     *
     * Author: $author$
     *   Date: 2/12/2004
     **********************************************************************
     */
    class cValueInterfaceStack
    : public cListT<cValueInterfaceItem, cValueInterfaceStack>
    {
    public:
        typedef cListT<cValueInterfaceItem, cValueInterfaceStack> cIs;
    };

    /**
     **********************************************************************
     *  Class: cVariableInterfaceItem
     *
     * Author: $author$
     *   Date: 2/25/2004
     **********************************************************************
     */
    class cVariableInterfaceItem
    : public cListItemT<cVariableInterfaceItem>
    {
    public:
        typedef cListItemT<cVariableInterfaceItem> cIs;

        cVariableInterface &m_variable;

        /**
         **********************************************************************
         * Constructor: cVariableInterfaceItem
         *
         *      Author: $author$
         *        Date: 2/25/2004
         **********************************************************************
         */
        cVariableInterfaceItem(cVariableInterface &variable) 
        :  m_variable(variable) 
        {
        }
        /**
         **********************************************************************
         * Function: GetVariable
         *
         *   Author: $author$
         *     Date: 2/25/2004
         **********************************************************************
         */
        cVariableInterface &GetVariable()
        {
            return m_variable;
        }
    };

    /**
     **********************************************************************
     *  Class: cVariableInterfaceList
     *
     * Author: $author$
     *   Date: 2/25/2004
     **********************************************************************
     */
    class cVariableInterfaceList
    : public cListT<cVariableInterfaceItem, cVariableInterfaceList>
    {
    public:
        typedef cListT<cVariableInterfaceItem, cVariableInterfaceList> cIs;
    };

    /**
     **********************************************************************
     *  Class: cFunctionImplement
     *
     * Author: $author$
     *   Date: 2/7/2004
     **********************************************************************
     */
    class cFunctionImplement
    : virtual public cFunctionInterface,
      virtual public cImplement
    {
    public:
        /**
         **********************************************************************
         * Function: Initialize
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual eError Initialize
        (cTransformInterface &transform)
        {
            return e_ERROR_NONE;
        }
        /**
         **********************************************************************
         * Function: Finalize
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual eError Finalize
        (cTransformInterface &transform)
        {
            return e_ERROR_NONE;
        }

        /**
         **********************************************************************
         * Function: TransformElement
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual eError TransformElement
        (cElementSetInterface &output_element_set,
         cElementInterface &template_element,
         cDocumentFactoryInterface &document_factory,
         cTransformContextInterface &transform_context)
        {
            return e_ERROR_NONE;
        }

        /**
         **********************************************************************
         * Function: SetName
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual int SetName(const char *name, int length=-1)
        {
            return -e_ERROR_NOT_ALLOWED;
        }
        /**
         **********************************************************************
         * Function: GetName
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        virtual const char *GetName(int &length) const
        {
            length = -e_ERROR_NOT_DEFINED;
            return 0;
        }
    };

    /**
     **********************************************************************
     *  Class: cFunctionItem
     *
     * Author: $author$
     *   Date: 2/7/2004
     **********************************************************************
     */
    class cFunctionItem
    : public cDynamicListItemT<cFunctionItem>
    {
    public:
        typedef cDynamicListItemT<cFunctionItem> cIs;

        cFunctionInterface &m_function;

        /**
         **********************************************************************
         * Constructor: cFunctionItem
         *
         *      Author: $author$
         *        Date: 2/7/2004
         **********************************************************************
         */
        cFunctionItem(cFunctionInterface &function)
        : m_function(function) 
        {
        }
        /**
         **********************************************************************
         * Function: GetFunction
         *
         *   Author: $author$
         *     Date: 2/7/2004
         **********************************************************************
         */
        inline cFunctionInterface &GetFunction()
        {
            return m_function;
        }
    };

    /**
     **********************************************************************
     *  Class: cStaticFunctionList
     *
     * Author: $author$
     *   Date: 2/7/2004
     **********************************************************************
     */
    class cStaticFunctionList
    : public cStaticDynamicListT<cFunctionItem,cStaticFunctionList>
    {
    public:
        typedef cStaticDynamicListT<cFunctionItem,cStaticFunctionList> cIs;

        static cStaticFunctionList m_instance;
    };

    /**
     **********************************************************************
     *  Class: cStaticFunctionItem
     *
     * Author: $author$
     *   Date: 2/8/2004
     **********************************************************************
     */
    class cStaticFunctionItem
    : public cFunctionItem
    {
    public:
        typedef cFunctionItem cIs;

        /**
         **********************************************************************
         * Constructor: cStaticFunctionItem
         *
         *      Author: $author$
         *        Date: 2/8/2004
         **********************************************************************
         */
        cStaticFunctionItem(cFunctionInterface &function)
        : cIs(function) 
        {
            m_is_static = true;
            cStaticFunctionList::m_instance.Add(this);
        }
    };

    /**
     **********************************************************************
     *  Class: cFunctionBranch
     *
     * Author: $author$
     *   Date: 2/8/2004
     **********************************************************************
     */
    class cFunctionBranch
    : public cAVLTreeBranchT<cFunctionBranch>
    {
    public:
        typedef cAVLTreeBranchT<cFunctionBranch> cIs;

        cFunctionInterface &m_function;

        /**
         **********************************************************************
         * Constructor: cFunctionBranch
         *
         *      Author: $author$
         *        Date: 2/8/2004
         **********************************************************************
         */
        cFunctionBranch(cFunctionInterface &function)
        : m_function(function) 
        {
        }
        /**
         **********************************************************************
         * Function: Compare
         *
         *   Author: $author$
         *     Date: 2/8/2004
         **********************************************************************
         */
        int Compare(cFunctionBranch &branch) const
        {
            int length;
            return Compare(branch.GetName(length));
        }
        /**
         **********************************************************************
         * Function: Compare
         *
         *   Author: $author$
         *     Date: 2/8/2004
         **********************************************************************
         */
        int Compare(const char *name) const
        {
            int result=-1;
            int length;
            const char *fname;

            if ((fname = GetName(length)))
                result = strcmp(name, fname);

            return result;
        }
        /**
         **********************************************************************
         * Function: Compare
         *
         *   Author: $author$
         *     Date: 2/8/2004
         **********************************************************************
         */
        int Compare(const char *name,int length) const
        {
            int result=-1;
            int namelen;
            int lendiff;
            const char *fname;
                
                
            if ((fname = GetName(namelen)))
            {
                if (0 < (lendiff=(length-namelen)))
                    length=namelen;

                if (!(result=strncmp(name,fname,length)))
                    return lendiff;
            }
            return result;
        }
        /**
         **********************************************************************
         * Function: GetName
         *
         *   Author: $author$
         *     Date: 2/8/2004
         **********************************************************************
         */
        const char *GetName(int &length) const
        {
            return m_function.GetName(length);
        }
    };

    /**
     **********************************************************************
     *  Class: cFunctionTree
     *
     * Author: $author$
     *   Date: 2/8/2004
     **********************************************************************
     */
    class cFunctionTree
    : public cAVLTreeT<const char *,cFunctionBranch,cFunctionTree>
    {
    public:
        typedef cAVLTreeT<const char *,cFunctionBranch,cFunctionTree> cIs;

        /**
         **********************************************************************
         * Function: Find
         *
         *   Author: $author$
         *     Date: 2/8/2004
         **********************************************************************
         */
        cFunctionInterface *Find(const char *name,int namelen=-1) const
        {
            cFunctionBranch *branch;

            if (namelen<0)
            {
                if ((branch=cIs::Find(name)))
                    return &branch->m_function;
            }
            else if (namelen>0)
            {
                if ((branch=cIs::Find(name,namelen)))
                    return &branch->m_function;
            }

            return 0;
        }
    };

    /**
     **********************************************************************
     *  Class: cDynamicFunctionItem
     *
     * Author: $author$
     *   Date: 2/9/2004
     **********************************************************************
     */
    class cDynamicFunctionItem
    : public cFunctionItem
    {
    public:
        typedef cFunctionItem cIs;

        cFunctionBranch m_branch;

        /**
         **********************************************************************
         * Constructor: cDynamicFunctionItem
         *
         *      Author: $author$
         *        Date: 2/9/2004
         **********************************************************************
         */
        cDynamicFunctionItem(cFunctionInterface &function)
        : cIs(function),
          m_branch(function)
        {
        }
    };

    /**
     **********************************************************************
     *  Class: cDynamicFunctionList
     *
     * Author: $author$
     *   Date: 2/7/2004
     **********************************************************************
     */
    class cDynamicFunctionList
    : public cDynamicListT<cFunctionItem,cDynamicFunctionList>
    {
    public:
        typedef cDynamicListT<cFunctionItem,cDynamicFunctionList> cIs;
    };

    /*
     **********************************************************************
     * cTransformImplement Functions
     **********************************************************************
     */

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/8/2004
     **********************************************************************
     */
    virtual eError Initialize()
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 2/8/2004
     **********************************************************************
     */
    virtual eError Finalize()
    {
        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: GetVariable
     *
     *   Author: $author$
     *     Date: 2/12/2004
     **********************************************************************
     */
    virtual cVariableInterface *GetVariable
    (const char *name, int namelen=-1)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: TransformDocument
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    virtual eError TransformDocument
    (cDocumentSourceInterface &output_document_source,
     cDocumentSourceInterface &input_document_source,
     cDocumentSourceInterface &template_document_source,
     cDocumentFactoryInterface &document_factory)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: TransformDocument
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    virtual eError TransformDocument
    (cDocumentInterface &output_document,
     cDocumentSourceInterface &input_document_source,
     cDocumentSourceInterface &template_document_source,
     cDocumentFactoryInterface &document_factory)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: TransformDocument
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual eError TransformDocument
    (cDocumentSourceInterface &output_document_source,
     cDocumentInterface &input_document,
     cDocumentInterface &template_document,
     cDocumentFactoryInterface &document_factory)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: TransformDocument
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    virtual eError TransformDocument
    (cDocumentInterface &output_document,
     cDocumentInterface &input_document,
     cDocumentInterface &template_document,
     cDocumentFactoryInterface &document_factory)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: TransformElementSet
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformElementSet
    (cElementSetInterface &output_element_set,
     cElementSetInterface &template_element_set,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     bool transform_text_elements=true)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: TransformElementSetToStream
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformElementSetToStream
    (cCharStream &stream,
     cElementSetInterface &template_element_set,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     bool transform_text_elements=true)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: TransformElementSetByTypeToStream
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformElementSetByTypeToStream
    (cCharStream &stream,
     cElementSetInterface &template_element_set,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     unsigned type=cElementInterface::e_TYPE_PARENT_ELEMENT,
     bool transform_text_elements=true)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: TransformElementSetByType
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformElementSetByType
    (cElementSetInterface &output_element_set,
     cElementSetInterface &template_element_set,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     unsigned type=cElementInterface::e_TYPE_PARENT_ELEMENT,
     bool transform_text_elements=true)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: TransformElementSiblingsByTypeToStream
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError TransformElementSiblingsByTypeToStream
    (cCharStream &stream,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     unsigned type=cElementInterface::e_TYPE_PARENT_ELEMENT,
     bool transform_text_elements=true)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: TransformElementSiblingsByType
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformElementSiblingsByType
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     unsigned type=cElementInterface::e_TYPE_PARENT_ELEMENT,
     bool transform_text_elements=true)
    {
        return e_ERROR_NOT_IMPLEMENTED;
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
     cTransformContextInterface &transform_context,
     bool transform_text_elements=true)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: TransformTextElement
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformTextElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: TransformText
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError TransformText
    (cElementSetInterface &output_element_set,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     const char *text, int textlen=-1)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: TransformTextToStream
     *
     *   Author: $author$
     *     Date: 2/11/2004
     **********************************************************************
     */
    virtual eError TransformTextToStream
    (cCharStream &stream,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     const char *text, int textlen=-1)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: TransformElementToStream
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
    virtual eError TransformElementToStream
    (cCharStream &stream,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     bool transform_text_elements=true)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    virtual eError SetType(cTransformTypeInterface *type)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    virtual cTransformTypeInterface *GetType() const
    {
        return  0;
    }
};

#endif /* ndef _CTRANSFORMINTERFACE_HXX */
