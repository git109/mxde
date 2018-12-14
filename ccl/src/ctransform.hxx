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
 *   File: ctransform.hxx
 *
 * Author: $author$
 *   Date: 2/2/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTRANSFORM_HXX
#define _CTRANSFORM_HXX

#include "ct.hxx"
#include "ctransformtypeinterface.hxx"
#include "ctransforminterface.hxx"
#include "cdocument.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class:  cTransform
 *
 * Author: $author$
 *   Date: 2/2/2004
 **********************************************************************
 */
class cTransform
: virtual public cTransformInterface,
  virtual public cTransformImplement,
  public cDynamicErrorInstance
{
public:
    typedef cDynamicErrorInstance cIs;
    typedef cTransformInterface::cTransformContextInterface cTransformContextInterface;
    typedef cTransformInterface::cFunctionInterface cFunctionInterface;
    typedef cTransformImplement::cFunctionImplement cFunctionImplement;
    typedef cTransformImplement::cStaticFunctionList cStaticFunctionList;
    typedef cTransformInterface::cValueInterface cValueInterface;
    typedef cTransformInterface::cVariableInterface cVariableInterface;
    typedef cTransformImplement::cValueInterfaceItem cValueInterfaceItem;
    typedef cTransformImplement::cValueInterfaceStack cValueInterfaceStack;

    class cVariable;

    /**
     **********************************************************************
     *  Class: cValue
     *
     * Author: $author$
     *   Date: 2/12/2004
     **********************************************************************
     */
    class cValue
    : virtual public cValueInterface,
      public cInstance
    {
    public:
        typedef cInstance cIs;

        cValueInterfaceItem m_item;
        cVariable &m_variable;
        cElementSet m_element_set;

        /**
         **********************************************************************
         * Constructor: cValue
         *
         *      Author: $author$
         *        Date: 2/12/2004
         **********************************************************************
         */
        cValue(cVariable &variable) 
        : m_item(*this),
          m_variable(variable)
        {
        }
        /**
         **********************************************************************
         * Function: GetElementSet
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual cElementSetInterface &GetElementSet()
        {
            return m_element_set;
        }
        /**
         **********************************************************************
         * Function: Push
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual void Push()
        {
            m_variable.PushValueItem(m_item);
        }
        /**
         **********************************************************************
         * Function: Update
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual eError Update()
        {
            eError error=e_ERROR_NONE;
            cValueInterface *value;

            if ((value = m_variable.PopValue()))
            if ((error = value->Release()))
                return error;

            m_variable.PushValueItem(m_item);
            return error;
        }
        /**
         **********************************************************************
         * Function: Release
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual eError Release()
        {
            eError error=e_ERROR_NONE;

            delete this;
            return error;
        }
    };

    /**
     **********************************************************************
     *  Class: cTemplateValue
     *
     * Author: $author$
     *   Date: 3/7/2004
     **********************************************************************
     */
    class cTemplateValue
    : public cValue
    {
    public:
        typedef cValue cIs;

        /**
         **********************************************************************
         * Constructor: cTemplateValue
         *
         *      Author: $author$
         *        Date: 3/7/2004
         **********************************************************************
         */
        cTemplateValue(cVariable &variable) 
        : cIs(variable) 
        {
        }
        /**
         **********************************************************************
         * Function: Push
         *
         *   Author: $author$
         *     Date: 3/7/2004
         **********************************************************************
         */
        virtual void Push()
        {
            m_variable.PushTemplateValueItem(m_item);
        }
        /**
         **********************************************************************
         * Function: Update
         *
         *   Author: $author$
         *     Date: 3/7/2004
         **********************************************************************
         */
        virtual eError Update()
        {
            eError error=e_ERROR_NONE;
            cValueInterface *value;

            if ((value = m_variable.PopTemplateValue()))
            if ((error = value->Release()))
                return error;

            m_variable.PushTemplateValueItem(m_item);
            return error;
        }
    };

    /**
     **********************************************************************
     *  Class: cTVariable
     *
     * Author: $author$
     *   Date: 2/14/2004
     **********************************************************************
     */
    class cTVariable
    : virtual public cTInterface::cVariableInterface,
      public cInstance
    {
    public:
        typedef cInstance cIs;

        cVariable &m_variable;
        mutable cCharBuffer m_value;

        /**
         **********************************************************************
         * Constructor: cTVariable
         *
         *      Author: $author$
         *        Date: 2/14/2004
         **********************************************************************
         */
        cTVariable(cVariable &variable) 
        : m_variable(variable) 
        {
        }
        /**
         **********************************************************************
         * Function: SetValue
         *
         *   Author: $author$
         *     Date: 2/14/2004
         **********************************************************************
         */
        virtual eError SetValue(const char *value,int valuelen=-1)
        {
            eError error;
            cValueInterface *ivalue;

            if ((ivalue = m_variable.GetValue()))
            {
                cElementSetInterface &element_set=ivalue->GetElementSet();
                cElementInterface *element;

                if (!(error = element_set.DeleteAllElements()))
                if ((element = element_set.AddTextElement
                    (value, valuelen)))
                    return error;
            }
            return e_ERROR_FAILED;
        }
        /**
         **********************************************************************
         * Function: GetValue
         *
         *   Author: $author$
         *     Date: 2/14/2004
         **********************************************************************
         */
        virtual const char *GetValue() const
        {
            int length;
            const char *value;
            cValueInterface *ivalue;

            if ((ivalue = m_variable.GetValue()))
            {
                cElementSetInterface &element_set=ivalue->GetElementSet();

                if (0 <= (length = m_value.Clear()))
                if (0 < (length = element_set.PutTextToStream(m_value)))
                if ((value = m_value.GetBuffer(length)))
                    return value;
            }
            return 0;
        }
        /**
         **********************************************************************
         * Function: PushValue
         *
         *   Author: $author$
         *     Date: 2/14/2004
         **********************************************************************
         */
        virtual eError PushValue(const char *value,int valuelen=-1)
        {
            cValueInterface *ivalue;

            if ((ivalue = m_variable.NewValue()))
            {
                cElementSetInterface &element_set=ivalue->GetElementSet();
                cElementInterface *element;

                if ((element = element_set.AddTextElement
                    (value, valuelen)))
                {
                    ivalue->Push();
                    return e_ERROR_NONE;
                }
                ivalue->Release();
            }
            return e_ERROR_FAILED;
        }
        /**
         **********************************************************************
         * Function: PopValue
         *
         *   Author: $author$
         *     Date: 2/14/2004
         **********************************************************************
         */
        virtual eError PopValue()
        {
            eError error;
            cValueInterface *ivalue;

            if ((ivalue = m_variable.PopValue()))
            if (!(error = ivalue->Release()))
                return error;

            return e_ERROR_FAILED;
        }
        /**
         **********************************************************************
         * Function: SetElement
         *
         *   Author: $author$
         *     Date: 2/14/2004
         **********************************************************************
         */
        virtual cElementInterface *SetElement(cElementInterface *element)
        {
            return 0;
        }
        /**
         **********************************************************************
         * Function: GetElement
         *
         *   Author: $author$
         *     Date: 2/14/2004
         **********************************************************************
         */
        virtual cElementInterface *GetElement() const
        {
            return 0;
        }
    };

    /**
     **********************************************************************
     *  Class: cVariable
     *
     * Author: $author$
     *   Date: 2/12/2004
     **********************************************************************
     */
    typedef class cVariable
    : virtual public cVariableInterface,
      public cAVLTreeBranchT<cVariable,cInstance>
    {
    public:
        typedef cAVLTreeBranchT<cVariable,cInstance> cIs;

        cTVariable m_t_variable;
        cCharBuffer m_name;
        cValueInterfaceStack m_value_stack;
        cValueInterfaceStack m_template_value_stack;

        /**
         **********************************************************************
         * Constructor: cVariable
         *
         *      Author: $author$
         *        Date: 2/12/2004
         **********************************************************************
         */
        cVariable(const char *name, int namelen=-1)
        : m_t_variable(*this)
        {
            eError error;

            if (0 > (namelen = m_name.Write(name, namelen)))
                throw(error = -namelen);
        }
        /**
         **********************************************************************
         * Function: SetValue
         *
         *   Author: $author$
         *     Date: 2/14/2004
         **********************************************************************
         */
        virtual eError SetValue(const char *value,int valuelen=-1)
        {
            eError error;

            if (!(error = m_t_variable.SetValue(value, valuelen)))
                return error;
            return e_ERROR_FAILED;
        }
        /**
         **********************************************************************
         * Function: GetValue
         *
         *   Author: $author$
         *     Date: 2/12/2004
         **********************************************************************
         */
        virtual cValueInterface *GetValue()
        {
            cValueInterface *value=0;
            cValueInterfaceItem *item;

            if ((item = m_value_stack.GetFirst()))
                value = &item->GetValue();

            else if ((value = NewValue()))
                    value->Push();

            return value;
        }
        /**
         **********************************************************************
         * Function: NewValue
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual cValueInterface *NewValue()
        {
            cValueInterface *value=new cValue(*this);
            return value;
        }
        /**
         **********************************************************************
         * Function: PopValue
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual cValueInterface *PopValue()
        {
            cValueInterface *value=0;
            cValueInterfaceItem *item;

            if ((item = m_value_stack.Pop()))
                value = &item->GetValue();

            return value;
        }
        /**
         **********************************************************************
         * Function: PushValueItem
         *
         *   Author: $author$
         *     Date: 2/12/2004
         **********************************************************************
         */
        void PushValueItem(cValueInterfaceItem &item)
        {
            m_value_stack.Push(&item);
        }

        /**
         **********************************************************************
         * Function: GetTemplateValue
         *
         *   Author: $author$
         *     Date: 3/6/2004
         **********************************************************************
         */
        virtual cValueInterface *GetTemplateValue()
        {
            cValueInterface *value=0;
            cValueInterfaceItem *item;

            if ((item = m_template_value_stack.GetFirst()))
                value = &item->GetValue();

            else if ((value = NewTemplateValue()))
                    value->Push();

            return value;
        }
        /**
         **********************************************************************
         * Function: NewTemplateValue
         *
         *   Author: $author$
         *     Date: 3/6/2004
         **********************************************************************
         */
        virtual cValueInterface *NewTemplateValue()
        {
            cValueInterface *value=new cTemplateValue(*this);
            return value;
        }
        /**
         **********************************************************************
         * Function: PopTemplateValue
         *
         *   Author: $author$
         *     Date: 3/6/2004
         **********************************************************************
         */
        virtual cValueInterface *PopTemplateValue()
        {
            cValueInterface *value=0;
            cValueInterfaceItem *item;

            if ((item = m_template_value_stack.Pop()))
                value = &item->GetValue();

            return value;
        }
        /**
         **********************************************************************
         * Function: PushTemplateValueItem
         *
         *   Author: $author$
         *     Date: 3/6/2004
         **********************************************************************
         */
        void PushTemplateValueItem(cValueInterfaceItem &item)
        {
            m_template_value_stack.Push(&item);
        }

        /**
         **********************************************************************
         * Function: Compare
         *
         *   Author: $author$
         *     Date: 2/12/2004
         **********************************************************************
         */
        int Compare(cVariable &branch) const
        {
            int length;
            return Compare(branch.GetName(length));
        }
        /**
         **********************************************************************
         * Function: Compare
         *
         *   Author: $author$
         *     Date: 2/12/2004
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
         *     Date: 2/12/2004
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
         *     Date: 2/12/2004
         **********************************************************************
         */
        const char *GetName(int &length) const
        {
            return m_name.GetBuffer(length);
        }
    } cTransformVariable;

    /**
     **********************************************************************
     *  Class: cVariableTree
     *
     * Author: $author$
     *   Date: 2/8/2004
     **********************************************************************
     */
    typedef class cVariableTree
    : public cAVLTreeT<const char *,cVariable,cVariableTree>
    {
    public:
        typedef cAVLTreeT<const char *,cVariable,cVariableTree> cIs;

        /**
         **********************************************************************
         * Function: Find
         *
         *   Author: $author$
         *     Date: 2/8/2004
         **********************************************************************
         */
        cVariable *Find(const char *name,int namelen=-1) const
        {
            cVariable *branch;

            if (namelen<0)
            {
                if ((branch=cIs::Find(name)))
                    return branch;
            }
            else if (namelen>0)
            {
                if ((branch=cIs::Find(name,namelen)))
                    return branch;
            }

            return 0;
        }
        /**
         **********************************************************************
         * Function: GetVariable
         *
         *   Author: $author$
         *     Date: 2/14/2004
         **********************************************************************
         */
        virtual cTInterface::cVariableInterface *GetTVariable
        (const char *name, int namelen=-1,
         const char *value=0,int valuelen=-1)
        {
            eError error;
            cVariable *variable;

            if (!(variable = Find(name, namelen)))
            if ((variable = new cVariable(name, namelen)))
            {
                if (value)
                if ((error = variable->SetValue(value, valuelen)))
                {
                    delete variable;
                    return 0;
                }
                Insert(variable);
            }
            else return 0;

            return &variable->m_t_variable;
        }
    } cTransformVariableTree;

    /**
     **********************************************************************
     *  Class: cTransformContext
     *
     * Author: $author$
     *   Date: 2/8/2004
     **********************************************************************
     */
    class cTransformContext
    : virtual public cTransformContextInterface,
      public cErrorInstance
    {
    public:
        typedef cErrorInstance cIs;

        cTransformInterface &m_transform;
        cDocumentInterface *m_document;
        cElementSetInterface *m_element_set;
        cElementInterface *m_element;
        cAttributeSetInterface *m_attribute_set;
        cAttributeInterface *m_attribute;

        /**
         **********************************************************************
         * Constructor: cTransformContext
         *
         *      Author: $author$
         *        Date: 2/8/2004
         **********************************************************************
         */
        cTransformContext(cTransformInterface &transform) 
        : m_transform(transform),
          m_document(0),
          m_element_set(0),
          m_element(0),
          m_attribute_set(0),
          m_attribute(0)
        {
        }

        /**
         **********************************************************************
         * Function: GetTransform
         *
         *   Author: $author$
         *     Date: 2/8/2004
         **********************************************************************
         */
        virtual cTransformInterface &GetTransform()
        {
            return m_transform;
        }
        /**
         **********************************************************************
         * Function: SetDocument
         *
         * Author: $author$
         *   Date: 2/8/2004
         **********************************************************************
         */
        virtual cDocumentInterface *SetDocument(cDocumentInterface *instance)
        {
            cDocumentInterface *old_document=m_document;

            m_document = instance;
            return old_document;
        }
        /**
         **********************************************************************
         * Function: GetDocument
         *
         * Author: $author$
         *   Date: 2/8/2004
         **********************************************************************
         */
        virtual cDocumentInterface *GetDocument() const
        {
            return m_document;
        }

        /**
         **********************************************************************
         * Function: SetElementSet
         *
         * Author: $author$
         *   Date: 2/8/2004
         **********************************************************************
         */
        virtual cElementSetInterface *SetElementSet(cElementSetInterface *instance)
        {
            cElementSetInterface *old_element_set=m_element_set;

            m_element_set = instance;
            return old_element_set;
        }
        /**
         **********************************************************************
         * Function: GetElementSet
         *
         * Author: $author$
         *   Date: 2/8/2004
         **********************************************************************
         */
        virtual cElementSetInterface *GetElementSet() const
        {
            return m_element_set;
        }

        /**
         **********************************************************************
         * Function: SetElement
         *
         * Author: $author$
         *   Date: 2/8/2004
         **********************************************************************
         */
        virtual cElementInterface *SetElement(cElementInterface *instance)
        {
            cElementInterface *old_element=m_element;

            m_element = instance;
            return old_element;
        }
        /**
         **********************************************************************
         * Function: GetElement
         *
         * Author: $author$
         *   Date: 2/8/2004
         **********************************************************************
         */
        virtual cElementInterface *GetElement() const
        {
            return m_element;
        }

        /**
         **********************************************************************
         * Function: SetAttributeSet
         *
         * Author: $author$
         *   Date: 2/8/2004
         **********************************************************************
         */
        virtual cAttributeSetInterface *SetAttributeSet(cAttributeSetInterface *instance)
        {
            cAttributeSetInterface *old_attribute_set=m_attribute_set;

            m_attribute_set = instance;
            return old_attribute_set;
        }
        /**
         **********************************************************************
         * Function: GetAttributeSet
         *
         * Author: $author$
         *   Date: 2/8/2004
         **********************************************************************
         */
        virtual cAttributeSetInterface *GetAttributeSet() const
        {
            return m_attribute_set;
        }

        /**
         **********************************************************************
         * Function: SetAttribute
         *
         * Author: $author$
         *   Date: 2/8/2004
         **********************************************************************
         */
        virtual cAttributeInterface *SetAttribute(cAttributeInterface *instance)
        {
            cAttributeInterface *old_attribute=m_attribute;

            m_attribute = instance;
            return old_attribute;
        }
        /**
         **********************************************************************
         * Function: GetAttribute
         *
         * Author: $author$
         *   Date: 2/8/2004
         **********************************************************************
         */
        virtual cAttributeInterface *GetAttribute() const
        {
            return m_attribute;
        }
    };

    /**
     **********************************************************************
     *  Class: cFunction
     *
     * Author: $author$
     *   Date: 2/8/2004
     **********************************************************************
     */
    class cFunction
    : virtual public cFunctionInterface,
      virtual public cFunctionImplement,
      public cErrorInstance
    {
    public:
        typedef cErrorInstance cIs;
        typedef cValueInterface cValueInterface;
        typedef cVariableInterface cVariableInterface;
        typedef cVariableInterfaceItem cVariableInterfaceItem;
        typedef cVariableInterfaceList cVariableInterfaceList;
        typedef cTransformContextInterface cTransformContextInterface;
        typedef cTransformImplement::cStaticFunctionItem cStaticFunctionItem;

        cCharBuffer m_name;

        /**
         **********************************************************************
         * Constructor: cFunction
         *
         *      Author: $author$
         *        Date: 2/8/2004
         **********************************************************************
         */
        cFunction(const char *name, int length=-1) 
        {
            eError error;

            if (name)
            if (0 > (length = m_name.Write(name, length)))
                throw(error = -length);
        }

        /**
         **********************************************************************
         * Function: SetName
         *
         *   Author: $author$
         *     Date: 2/8/2004
         **********************************************************************
         */
        virtual int SetName(const char *name, int length=-1)
        {
            return m_name.Write(name, length);
        }
        /**
         **********************************************************************
         * Function: GetName
         *
         *   Author: $author$
         *     Date: 2/8/2004
         **********************************************************************
         */
        virtual const char *GetName(int &length) const
        {
            return m_name.GetBuffer(length);
        }
    };

    /**
     **********************************************************************
     *  Class: cT
     *
     * Author: $author$
     *   Date: 2/14/2004
     **********************************************************************
     */
    class cT
    : virtual public cTInterface,
      public cTImplement
    {
    public:
        typedef cTImplement cIs;

        cTransformVariableTree &m_variable_tree;

        /**
         **********************************************************************
         * Constructor: cT
         *
         *      Author: $author$
         *        Date: 2/14/2004
         **********************************************************************
         */
        cT(cTransformVariableTree &variable_tree,char mark='%')
        : cIs(mark),
          m_variable_tree(variable_tree)
        {
        }
        /**
         **********************************************************************
         * Function: SetVariable
         *
         *   Author: $author$
         *     Date: 2/14/2004
         **********************************************************************
         */
        virtual cVariableInterface *SetVariable
        (const char *name,int namelen=-1,
         const char *value=0,int valuelen=-1)
        {
            eError error;
            cVariableInterface *variable;

            if ((variable = m_variable_tree.GetTVariable(name, namelen)))
            if ((error = variable->SetValue(value, valuelen)))
                return 0;

            return variable;
        }
        /**
         **********************************************************************
         * Function: GetVariable
         *
         *   Author: $author$
         *     Date: 2/14/2004
         **********************************************************************
         */
        virtual cVariableInterface *GetVariable
        (const char *name,int namelen=-1,
         const char *value=0,int valuelen=-1)
        {
            cVariableInterface *variable;

            variable = m_variable_tree.GetTVariable
            (name, namelen, value, valuelen);
            return variable;
        }
        /**
         **********************************************************************
         * Function: ExpandVariable
         *
         *   Author: $author$
         *     Date: 2/14/2004
         **********************************************************************
         */
        virtual eError ExpandVariable
        (cCharStream &out,const char *name)
        {
            cVariableInterface *variable;
            const char *value;
            int count;

            if ((variable = GetVariable(name)))
            if ((value = variable->GetValue()))
            if ((count = out.Write(value)) < 0)
                return e_ERROR_WRITE;

            return e_ERROR_NONE;
        }
    };

    cTransformTypeInterface *m_type;
    cDynamicFunctionList m_function_list;
    cFunctionTree m_function_tree;
    cVariableTree m_variable_tree;
    cT m_t;

    /**
     **********************************************************************
     * Constructor: cTransform
     *
     *      Author: $author$
     *        Date: 2/2/2004
     **********************************************************************
     */
    cTransform(cTransformTypeInterface *type=0) 
    : m_type(type),
      m_t(m_variable_tree)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cTransform
     *
     *     Author: $author$
     *       Date: 2/2/2004
     **********************************************************************
     */
    virtual ~cTransform()
    {
    }

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
        eError error;
        cDynamicFunctionItem *dynamic_item;
        cFunctionItem *item;
        const char *name;
        int namelen;

        if ((error = m_t.Initialize()))
            return SetLastError
            (e_ERROR_FAILED,"failed to initialize \"t\"");

        for (item=cStaticFunctionList::m_instance.GetFirst(); 
             item; item=item->GetNext())
        {
            cFunctionInterface &function=item->GetFunction();

            name = function.GetName(namelen);

            if (name && (namelen > 0))
            if ((error = function.Initialize(*this)))
            {
                Finalize(1);
                return SetLastErrorL
                (e_ERROR_FAILED, 
                 "failed to initialize function \"", name, "\"", 0);
            }
            else if (!(dynamic_item = new 
                     cDynamicFunctionItem(function)))
            {
                Finalize(1);
                return SetLastErrorL
                (e_ERROR_NEW, 
                 "failed to allocate new function item\"", name, "\"", 0);
            }
            else
            {
                m_function_tree.Insert(&dynamic_item->m_branch);
                m_function_list.Add(dynamic_item);
            }
        }
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
    virtual eError Finalize(int errors=0)
    {
        eError error;
        cFunctionItem *item;
        const char *name;
        int namelen;

        m_function_tree.Clear();

        for (item=m_function_list.GetLast(); 
             item; item=item->GetPrevious())
        {
            cFunctionInterface &function=item->GetFunction();

            name = function.GetName(namelen);

            if (name && (namelen > 0))
            if ((error = function.Finalize(*this)))
            {
                if ((errors++) < 1)
                    SetLastErrorL
                    (e_ERROR_FAILED, 
                     "failed to finalize function \"", name, "\"", 0);
            }
        }

        m_function_list.Clear();

        if ((error = m_t.Finalize()))
        if ((errors++) < 1)
            SetLastError
            (e_ERROR_FAILED,"failed to finalize \"t\"");

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
        cVariable *variable;

        if (!(variable = m_variable_tree.Find(name, namelen)))
        if ((variable = new cVariable(name, namelen)))
            m_variable_tree.Insert(variable);

        return variable;
    }
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
     cDocumentFactoryInterface &document_factory)
    {
        eError error=e_ERROR_NONE;
        const char *error_text;
        const char *document_type;
        const char *document_uri;
        const char *document_filename;
        int document_typelen;
        int document_urilen;
        int document_filenamelen;
        cDocumentInterface *input_document;
        cCharStreamInterfaceStream input_stream(input_document_source);
        cCharStreamInterfaceStream output_stream(output_document_source);

        document_type = input_document_source.GetType(document_typelen);
        document_uri = input_document_source.GetURI(document_urilen);
        document_filename = input_document_source.GetPath(document_filenamelen);

        if (!document_type || (0 >= document_typelen))
            return SetLastError
            (e_ERROR_FAILED, "unspecified document type");

        if (!(input_document = document_factory.
            CreateDocumentByType(document_type)))
            return SetLastErrorL
            (e_ERROR_FAILED,
             "unable to create document of type \"",
             document_type, "\"", 0);

        else
        {
            if ((error = input_document->
                ParseFromStream
                (input_stream, document_filename, document_uri)))
            {
                if (0 >= (error = input_document->
                    GetLastError(error_text)))
                    error_text = 0;

                error = SetLastErrorL
                (e_ERROR_FAILED,
                 "unable to parse document of type \"",
                 document_type, "\" from stream", 
                 error_text?"(":"", error_text, error_text?")":"", 0);
            }
            else input_document->PutToStream(output_stream);

            input_document->FreeInstance();
        }
        return error;
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
        eError error=e_ERROR_NONE;
        const char *template_type;
        const char *template_filename;
        const char *template_uri;
        const char *document_type;
        const char *document_uri;
        const char *document_filename;
        int document_typelen;
        int document_urilen;
        int document_filenamelen;
        int template_typelen;
        int template_urilen;
        int template_filenamelen;
        cDocumentInterface *input_document;
        cDocumentInterface *template_document;
        cCharStreamInterfaceStream input_stream(input_document_source);
        cCharStreamInterfaceStream template_stream(template_document_source);

        document_uri = input_document_source.GetURI(document_urilen);
        document_filename = input_document_source.GetPath(document_filenamelen);

        template_type = template_document_source.GetType(template_typelen);
        template_uri = template_document_source.GetURI(template_urilen);
        template_filename = template_document_source.GetPath(template_filenamelen);

        if (!template_type || (0 >= template_typelen))
            return SetLastError
            (e_ERROR_FAILED, "unspecified template type");

        document_type = input_document_source.GetType(document_typelen);

        if (!document_type || (0 >= document_typelen))
            return SetLastError
            (e_ERROR_FAILED, "unspecified document type");

        if (!(template_document = document_factory.
            CreateDocumentByType(template_type)))
            return SetLastErrorL
            (e_ERROR_FAILED,
             "unable to create template document of type \"",
             template_type, "\"", 0);

        else
        {
            if ((error = template_document->
                ParseFromStream
                (template_stream, template_filename, template_uri)))
                error = SetLastErrorL
                (e_ERROR_FAILED,
                 "unable to parse template document of type \"",
                 template_type, "\" from stream", 0);

            else
            {
                if (!(input_document = document_factory.
                    CreateDocumentByType(document_type)))
                    error = SetLastErrorL
                    (e_ERROR_FAILED,
                     "unable to create input document of type \"",
                     document_type, "\"", 0);

                else
                {
                    if ((error = input_document->
                        ParseFromStream
                        (input_stream, document_filename, document_uri)))
                        error = SetLastErrorL
                        (e_ERROR_FAILED,
                         "unable to parse input document of type \"",
                         document_type, "\" from stream", 0);

                    else error = TransformDocument
                    (output_document_source, *input_document, 
                     *template_document, document_factory);

                    input_document->FreeInstance();
                }
            }
            template_document->FreeInstance();
        }
        return error;
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
        int count;
        int output_typelen;
        const char *output_type;
        eError error=e_ERROR_NONE;
        cDocumentInterface *output_document=&input_document;
        cCharStreamInterfaceStream output_stream(output_document_source);

        output_type = output_document_source.GetType(output_typelen);

        if (!output_type || (0 >= output_typelen))
            return SetLastError
            (e_ERROR_FAILED, "unspecified output type");

        if (!(output_document = document_factory.
            CreateDocumentByType(output_type)))
            return SetLastErrorL
            (e_ERROR_FAILED,
             "unable to create output document of type \"",
             output_type, "\"", 0);

        else if (!(error = TransformDocument
                 (*output_document,input_document,
                  template_document,document_factory)))
        {
            if (0 > (count = output_document->
                PutToStream(output_stream)))
                error = SetLastError
                (e_ERROR_FAILED,
                 "unable to output document to stream");

            output_document->FreeInstance();
        }
        return error;
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
        eError error=e_ERROR_NONE;
        cTransformContext transform_context(*this);
        cElementInterface *template_element;
        const char *text;
        int textlen;

        transform_context.SetDocument(&input_document);
        transform_context.SetElementSet(&input_document);

        if ((template_element = template_document.GetFirstElement()))
        do
        {
            if ((error = TransformElement
                (output_document, *template_element, 
                 document_factory, transform_context)))
            {
                if (!(text = template_element->GetText(textlen)))
                    text = "";

                error = SetLastErrorL
                (error, "unable to transform template element \"",
                 text, "\"", 0);
                break;
            }
        }
        while ((template_element = template_element->GetNextElement()));
        return error;
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
        eError error=e_ERROR_NONE;
        cElementInterface *template_element;

        if ((template_element = template_element_set.GetFirstElement()))
        do
        {
            if ((error = TransformElement
                (output_element_set, *template_element,
                 document_factory, transform_context,
                 transform_text_elements)))
                break;
        }
        while ((template_element = template_element->GetNextElement()));

        return error;
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
        eError error=e_ERROR_NONE;
        cElementInterface *template_element;

        if ((template_element = template_element_set.GetFirstElement()))
        do
        {
            if ((error = TransformElementToStream
                (stream, *template_element,
                 document_factory, transform_context,
                 transform_text_elements)))
                break;
        }
        while ((template_element = template_element->GetNextElement()));

        return error;
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
        eError error=e_ERROR_NONE;
        cElementSet element_set;
        int count;

        if (!(error = TransformElementSetByType
            (element_set, template_element_set, 
             document_factory, transform_context,
             type, transform_text_elements)))
        if (0 > (count = element_set.PutTextToStream(stream)))
            error = -count;

        return error;
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
        eError error=e_ERROR_NONE;
        cElementInterface *template_element;

        if ((template_element = template_element_set.
            GetFirstElementByType(type)))
        do
        {
            if ((error = TransformElement
                (output_element_set, *template_element,
                 document_factory, transform_context,
                 transform_text_elements)))
                break;
        }
        while ((template_element = template_element->
               GetNextElementByType(type)));

        return error;
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
        eError error=e_ERROR_NONE;
        cElementSet element_set;
        int count;

        if (!(error = TransformElementSiblingsByType
            (element_set, template_element, 
             document_factory, transform_context,
             type, transform_text_elements)))
        if (0 > (count = element_set.PutTextToStream(stream)))
            error = -count;

        return error;
    }
    /**
     **********************************************************************
     * Function: TransformElementSiblingsByType
     *
     *   Author: $author$
     *     Date: 2/6/2004
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
        eError error=e_ERROR_NONE;
        cElementInterface *element;

        if ((element = template_element.
            GetNextElementByType(type)))
        do
        {
            if ((error = TransformElement
                (output_element_set, *element,
                 document_factory, transform_context,
                 transform_text_elements)))
                break;
        }
        while ((element = element->
               GetNextElementByType(type)));

        return error;
    }
    /**
     **********************************************************************
     * Function: TransformElement
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual eError TransformElement
    (cElementSetInterface &output_element_set,
     cElementInterface &template_element,
     cDocumentFactoryInterface &document_factory,
     cTransformContextInterface &transform_context,
     bool transform_text_elements=true)
    {
        eError error=e_ERROR_NONE;
        cElementInterface *output_element;
        cDocumentInterface *template_document;
        const char *function_name=template_element.GetText();
        const char *ns_separator,*ns_prefix,*ns,*template_ns="xtl";
        int ns_separatorlen,ns_prefixlen,nslen,template_nslen=3;
        unsigned type;

        ns_separatorlen = 0;

        if ((template_document = template_element.GetParentDocument()))
            ns_separator = template_document->GetNamespaceSeparator(ns_separatorlen);

        if ((ns_prefix = (ns = template_element.GetPrefixText(nslen))))
        if (template_nslen == (ns_prefixlen = nslen))
        if (0 == (strncmp(template_ns, ns, nslen)))
        {
            cFunctionInterface *function;

            function_name = ns_prefix+ns_prefixlen+ns_separatorlen;

            if ((function = m_function_tree.Find(function_name)))
                error = function->TransformElement
                (output_element_set, template_element,
                 document_factory, transform_context);

            return error;
        }

        if (transform_text_elements &&
            ((type = template_element.GetType())
             == cElementInterface::e_TYPE_TEXT_ELEMENT))
            error = TransformTextElement
            (output_element_set, template_element, 
             document_factory, transform_context);

        else if ((output_element = output_element_set.AddElementCopy
                (template_element, false, true)))
                error = TransformElementSet
                (*output_element, template_element, 
                 document_factory, transform_context);

        return error;
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
        eError error=e_ERROR_NONE;
        cCharBuffer output_buffer;
        const char *text;
        int textlen;

        if ((text = template_element.GetText(textlen)))
        if (0 < textlen)
        if (!(error = TransformTextToStream
            (output_buffer, document_factory,
             transform_context, text, textlen)))
        if ((text = output_buffer.GetBuffer(textlen)))
        if (0 < textlen)
            output_element_set.AddTextElement(text, textlen);

        return error;
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
        eError error=e_ERROR_NONE;
        cCharBuffer output_buffer;

        if (!(error = TransformTextToStream
            (output_buffer, document_factory,
             transform_context, text, textlen)))
        if ((text = output_buffer.GetBuffer(textlen)))
        if (0 < textlen)
            output_element_set.AddTextElement(text, textlen);

        return error;
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
        eError error=e_ERROR_NONE;
        cCharBuffer buffer(text, textlen, textlen);

        if ((error = m_t.Expand(stream, buffer)))
            error = SetLastError
            (e_ERROR_FAILED, "failed to expand text");

        return error;
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
        eError error=e_ERROR_NONE;
        cElementSet element_set;
        int count;

        if (!(error = TransformElement
            (element_set, template_element, 
             document_factory, transform_context,
             transform_text_elements)))
        if (0 > (count = element_set.PutTextToStream(stream)))
            error = -count;

        return error;
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
        m_type = type;
        return e_ERROR_NONE;
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
        return m_type;
    }

    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        delete this;
        return e_ERROR_NONE;
    }
};

#endif /* ndef _CTRANSFORM_HXX */
