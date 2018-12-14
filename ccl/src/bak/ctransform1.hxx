/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   Date: 8/18/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTRANSFORM_HXX
#define _CTRANSFORM_HXX

#include "ctransformimplement.hxx"
#include "ctransforminterface.hxx"
#include "cinstance.hxx"
#include "cdocument.hxx"
#include "cavltreet.hxx"

/**
 **********************************************************************
 *  Class: cTransform
 *
 * Author: $author$
 *   Date: 8/18/2003
 **********************************************************************
 */
class cTransform
: virtual public cTransformInterface,
  virtual public cTransformImplement,
  public cErrorInstance
{
public:
    typedef cErrorInstance cIs;
    typedef cTransformInterface::cValueInterface cValueInterface;
    typedef cTransformInterface::cVariableInterface cVariableInterface;
    typedef cTransformInterface::cVariableInterfaceItem cVariableInterfaceItem;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 8/18/2003
     **********************************************************************
     */
    enum
    {
        e_FIRST_ERROR=cIs::e_NEXT_ERROR,
        e_NEXT_ERROR=e_FIRST_ERROR,
        e_LAST_ERROR=e_NEXT_ERROR-1
    };

    class cVariable;

    /**
     **********************************************************************
     *  Class: cValue
     *
     * Author: $author$
     *   Date: 8/30/2003
     **********************************************************************
     */
    class cValue
    : virtual public cValueInterface,
      public cListItemT<cValue,cInstance>
    {
    public:
        typedef cListItemT<cValue,cInstance> cIs;

        cVariable &m_variable;
        cVariableInterfaceItem m_variable_item;
        cElementSet m_element_set;

        /**
         **********************************************************************
         * Constructor: cValue
         *
         *      Author: $author$
         *        Date: 8/30/2003
         **********************************************************************
         */
        cValue(cVariable &variable)
        : m_variable(variable),
          m_variable_item(variable) 
        {
        }

        /**
         **********************************************************************
         * Function: ElementSet
         *
         *   Author: $author$
         *     Date: 8/30/2003
         **********************************************************************
         */
        virtual cElementSetInterface &ElementSet()
        {
            return m_element_set;
        }
        /**
         **********************************************************************
         * Function: Push
         *
         *   Author: $author$
         *     Date: 8/30/2003
         **********************************************************************
         */
        virtual eError Push(cVariableInterfaceStack &stack)
        {
            eError error;

            if (!(error=m_variable.PushValue(this)))
            {
                stack.Push(&m_variable_item);
                return error;
            }
            return e_ERROR_FAILED;
        }
        /**
         **********************************************************************
         * Function: Update
         *
         *   Author: $author$
         *     Date: 8/30/2003
         **********************************************************************
         */
        virtual eError Update()
        {
            eError error;

            if (!(error=m_variable.UpdateValue(this)))
                return error;

            return e_ERROR_FAILED;
        }
        /**
         **********************************************************************
         * Function: Release
         *
         *   Author: $author$
         *     Date: 8/30/2003
         **********************************************************************
         */
        virtual eError Release()
        {
            eError error;

            if (!(error=m_variable.ReleaseValue(this)))
                return error;

            return e_ERROR_FAILED;
        }
    };

    /**
     **********************************************************************
     *  Class: cValueList
     *
     * Author: $author$
     *   Date: 8/30/2003
     **********************************************************************
     */
    class cValueList
    : public cListT<cValue,cValueList>
    {
    public:
    };

    /**
     **********************************************************************
     *  Class: cVariable
     *
     * Author: $author$
     *   Date: 8/30/2003
     **********************************************************************
     */
    class cVariable
    : virtual public cVariableInterface,
      public cAVLTreeBranchT<cVariable,cInstance>
    {
    public:
        typedef cAVLTreeBranchT<cVariable,cInstance> cIs;

        cCharBuffer m_name;
        cValue m_value;
        cValueList m_value_list;
        cValueList m_old_value_list;

        /**
         **********************************************************************
         * Constructor: cVariable
         *
         *      Author: $author$
         *        Date: 8/30/2003
         **********************************************************************
         */
        cVariable(const char *name,int namelen=-1)
        : m_value(*this) 
        {
            int count;
            eError error;

            m_value_list.Add(&m_value);

            if ((count=m_name.Write(name,namelen)) < 0)
                throw(error=e_ERROR_WRITE);
        }

        /**
         **********************************************************************
         * Function: ElementSet
         *
         *   Author: $author$
         *     Date: 9/1/2003
         **********************************************************************
         */
        virtual cElementSetInterface &ElementSet()
        {
            cValue *value;

            if ((value=m_value_list.GetFirst()))
                return value->ElementSet();

            return m_value.ElementSet();
        }
        /**
         **********************************************************************
         * Function: GetNewValue
         *
         *   Author: $author$
         *     Date: 9/1/2003
         **********************************************************************
         */
        virtual cValueInterface *GetNewValue()
        {
            eError error;
            cValue *value;

            if ((value=m_old_value_list.Pop()))
            {
                if ((error=value->ElementSet().DeleteAllElements()))
                {
                    if (value!=&m_value)
                        delete value;

                    value=0;
                }
            }
            else value=new cValue(*this);

            return value;
        }
        /**
         **********************************************************************
         * Function: PopValue
         *
         *   Author: $author$
         *     Date: 9/1/2003
         **********************************************************************
         */
        virtual eError PopValue()
        {
            cValue *value;

            if ((value=m_value_list.GetFirst()))
            if (value->GetNext())
            if ((value=m_value_list.Pop()))
            {
                m_old_value_list.Push(value);
                return e_ERROR_NONE;
            }
            return e_ERROR_FAILED;
        }
        /**
         **********************************************************************
         * Function: UpdateValue
         *
         *   Author: $author$
         *     Date: 9/1/2003
         **********************************************************************
         */
        eError UpdateValue(cValue *value)
        {
            cValue *old_value;

            if ((old_value=m_value_list.Pop()))
            {
                m_old_value_list.Push(old_value);
                m_value_list.Push(value);
                return e_ERROR_NONE;
            }
            return e_ERROR_FAILED;
        }
        /**
         **********************************************************************
         * Function: PushValue
         *
         *   Author: $author$
         *     Date: 9/1/2003
         **********************************************************************
         */
        eError PushValue(cValue *value)
        {
            m_value_list.Push(value);
            return e_ERROR_NONE;
        }
        /**
         **********************************************************************
         * Function: ReleaseValue
         *
         *   Author: $author$
         *     Date: 9/1/2003
         **********************************************************************
         */
        eError ReleaseValue(cValue *value)
        {
            m_old_value_list.Push(value);
            return e_ERROR_NONE;
        }
        /**
         **********************************************************************
         * Function: Compare
         *
         *   Author: $author$
         *     Date: 9/1/2003
         **********************************************************************
         */
        int Compare(cVariable &branch) const
        {
            return strcmp(branch.GetName(),GetName());
        }
        /**
         **********************************************************************
         * Function: Compare
         *
         *   Author: $author$
         *     Date: 9/1/2003
         **********************************************************************
         */
        int Compare(const char *leaf) const
        {
            return strcmp(leaf,GetName());
        }
        /**
         **********************************************************************
         * Function: Compare
         *
         *   Author: $author$
         *     Date: 9/1/2003
         **********************************************************************
         */
        int Compare(const char *leaf,int length) const
        {
            const char *name;
            int namelen;
            int lendiff;
            int result;

            if (length < 0)
                length = strlen(leaf);

            if ((lendiff=(length-(namelen=strlen(name=GetName())))>0))
                length=namelen;

            if (!(result=strncmp(leaf,name,length)))
                return lendiff;

            return result;
        }
        /**
         **********************************************************************
         * Function: GetName
         *
         *   Author: $author$
         *     Date: 9/1/2003
         **********************************************************************
         */
        inline const char *GetName() const
        {
            return m_name.GetBuffer();
        }
    };

    /**
     **********************************************************************
     *  Class: cVariableTree
     *
     * Author: $author$
     *   Date: 9/14/2003
     **********************************************************************
     */
    class cVariableTree
    : public cAVLTreeT<const char *,cVariable,cVariableTree>
    {
    public:
        typedef cAVLTreeT<const char *,cVariable,cVariableTree> cIs;
    };

    cVariableTree m_variable_tree;

    cDocumentInterface *m_template_document;
    cDocumentInterface *m_document;
    cElementSetInterface *m_element_set;
    cElementInterface *m_element;
    cAttributeInterface *m_attribute;

    cElementInterface *m_element_true;
    cElementInterface *m_element_less;
    cElementInterface *m_element_greater;

    /**
     **********************************************************************
     * Constructor: cTransform
     *
     *      Author: $author$
     *        Date: 8/18/2003
     **********************************************************************
     */
    cTransform()
    : m_element_true(0),
      m_element_less(0),
      m_element_greater(0),
      m_template_document(0),
      m_document(0),
      m_element_set(0),
      m_element(0),
      m_attribute(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cTransform
     *
     *     Author: $author$
     *       Date: 8/18/2003
     **********************************************************************
     */
    virtual ~cTransform()
    {
    }

    /**
     **********************************************************************
     * Function: GetVariable
     *
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cVariableInterface *GetVariable
    (const char *name,int namelen=-1)
    {
        cVariable *variable;

        if (!(variable=m_variable_tree.Find(name,namelen)))

        if ((variable=new cVariable(name, namelen)))
            m_variable_tree.Insert(variable);

        return variable;
    }
    /**
     **********************************************************************
     * Function: GetTemplate
     *
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cElementInterface *GetTemplate
    (const char *name,int namelen=-1) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetTemplateDocument
     *
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cDocumentInterface *SetTemplateDocument
    (cDocumentInterface *document)
    {
        cDocumentInterface *old_document = m_document;
        m_template_document = document;
        return old_document;
    }
    /**
     **********************************************************************
     * Function: GetTemplateDocument
     *
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cDocumentInterface *GetTemplateDocument() const
    {
        return m_template_document;
    }

    /**
     **********************************************************************
     * Function: SetDocument
     *
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cDocumentInterface *SetDocument
    (cDocumentInterface *document)
    {
        cDocumentInterface *old_document = m_document;
        m_document = document;
        return old_document;
    }
    /**
     **********************************************************************
     * Function: GetDocument
     *
     *   Author: $author$
     *     Date: 9/14/2003
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
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cElementSetInterface *SetElementSet
    (cElementSetInterface *element_set)
    {
        cElementSetInterface *old_element_set = m_element_set;
        m_element_set = element_set;
        return old_element_set;
    }
    /**
     **********************************************************************
     * Function: GetElementSet
     *
     *   Author: $author$
     *     Date: 9/14/2003
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
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cElementInterface *SetElement
    (cElementInterface *element)
    {
        cElementInterface *old_element = m_element;
        m_element = element;
        return old_element;
    }
    /**
     **********************************************************************
     * Function: GetElement
     *
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cElementInterface *GetElement() const
    {
        return m_element;
    }
    /**
     **********************************************************************
     * Function: GetElementTrue
     *
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cElementInterface *GetElementTrue() const
    {
        return m_element_true;
    }
    /**
     **********************************************************************
     * Function: GetElementLess
     *
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cElementInterface *GetElementLess() const
    {
        return m_element_less;
    }
    /**
     **********************************************************************
     * Function: GetElementGreater
     *
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cElementInterface *GetElementGreater() const
    {
        return m_element_greater;
    }
    
    /**
     **********************************************************************
     * Function: SetAttribute
     *
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cAttributeInterface *SetAttribute
    (cAttributeInterface *attribute)
    {
        cAttributeInterface *old_attribute = m_attribute;
        m_attribute = attribute;
        return old_attribute;
    }
    /**
     **********************************************************************
     * Function: GetAttribute
     *
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetAttribute() const
    {
        return m_attribute;
    }
};


#endif
