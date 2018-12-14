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
 *   File: cdom.hxx
 *
 * Author: $author$
 *   Date: 12/2/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOM_HXX
#define _CDOM_HXX

#include "clistt.hxx"
#include "cavltreet.hxx"
#include "cdominterface.hxx"

/**
 **********************************************************************
 *  Class: cDOMNodeListImplement
 *
 * Author: $author$
 *   Date: 12/3/2004
 **********************************************************************
 */
class cDOMNodeListImplement
: virtual public cDOMNodeListInterface
{
public:
    /**
     **********************************************************************
     * Function: AppendElement
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError AppendElement
    (cDOMElementInterface& element) 
    {
        eError error = e_ERROR_NOT_ALLOWED;
        return error;
    }
    /**
     **********************************************************************
     * Function: RemoveElement
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError RemoveElement
    (cDOMElementInterface& element) 
    {
        eError error = e_ERROR_NOT_ALLOWED;
        return error;
    }
    /**
     **********************************************************************
     * Function: AppendText
     *
     *   Author: $author$
     *     Date: 12/18/2004
     **********************************************************************
     */
    virtual eError AppendText
    (cDOMTextInterface& text) 
    {
        eError error = e_ERROR_NOT_ALLOWED;
        return error;
    }
    /**
     **********************************************************************
     * Function: RemoveText
     *
     *   Author: $author$
     *     Date: 12/18/2004
     **********************************************************************
     */
    virtual eError RemoveText
    (cDOMTextInterface& text) 
    {
        eError error = e_ERROR_NOT_ALLOWED;
        return error;
    }
    /**
     **********************************************************************
     * Function: AppendChild
     *
     *   Author: $author$
     *     Date: 12/3/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface& AppendChild
    (cDOMNodeInterface& child) 
    {
        return child;
    }
    /**
     **********************************************************************
     * Function: RemoveChild
     *
     *   Author: $author$
     *     Date: 12/3/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface& RemoveChild
    (cDOMNodeInterface& child) 
    {
        return child;
    }

    /**
     **********************************************************************
     * Function: GetFirstChild
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface* GetFirstChild() const
    {
        cDOMNodeInterface* child = 0;
        return child;
    }
    /**
     **********************************************************************
     * Function: GetLastChild
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface* GetLastChild() const
    {
        cDOMNodeInterface* child = 0;
        return child;
    }

    /**
     **********************************************************************
     * Function: GetFirstText
     *
     *   Author: $author$
     *     Date: 12/20/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* GetFirstText() const
    {
        cDOMNodeInterface* node = GetFirstChild();
        cDOMTextInterface* element = 0;

        while (node)
        {
            if ((element = node->GetTextNode()))
                break;
            node = node->GetNextSibling();
        }
        return element;
    }
    /**
     **********************************************************************
     * Function: GetLastText
     *
     *   Author: $author$
     *     Date: 12/20/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* GetLastText() const
    {
        cDOMNodeInterface* node = GetLastChild();
        cDOMTextInterface* element = 0;

        while (node)
        {
            if ((element = node->GetTextNode()))
                break;
            node = node->GetPreviousSibling();
        }
        return element;
    }

    /**
     **********************************************************************
     * Function: GetFirstElement
     *
     *   Author: $author$
     *     Date: 12/3/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetFirstElement() const
    {
        cDOMNodeInterface* node = GetFirstChild();
        cDOMElementInterface* element = 0;

        while (node)
        {
            if ((element = node->GetElementNode()))
                break;
            node = node->GetNextSibling();
        }
        return element;
    }
    /**
     **********************************************************************
     * Function: GetLastElement
     *
     *   Author: $author$
     *     Date: 12/3/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetLastElement() const
    {
        cDOMNodeInterface* node = GetLastChild();
        cDOMElementInterface* element = 0;

        while (node)
        {
            if ((element = node->GetElementNode()))
                break;
            node = node->GetPreviousSibling();
        }
        return element;
    }

    /**
     **********************************************************************
     * Function: GetFirstAttribute
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* GetFirstAttribute() const
    {
        cDOMNodeInterface* node = GetFirstChild();
        cDOMAttrInterface* attr = 0;

        while (node)
        {
            if ((attr = node->GetAttrNode()))
                break;
            node = node->GetNextSibling();
        }
        return attr;
    }
    /**
     **********************************************************************
     * Function: GetLastAttribute
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* GetLastAttribute() const
    {
        cDOMNodeInterface* node = GetLastChild();
        cDOMAttrInterface* attr = 0;

        while (node)
        {
            if ((attr = node->GetAttrNode()))
                break;
            node = node->GetPreviousSibling();
        }
        return attr;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNodeReferenceItem
 *
 * Author: $author$
 *   Date: 12/22/2004
 **********************************************************************
 */
class cDOMNodeReferenceItem
: public cDynamicListItemT<cDOMNodeReferenceItem>
{
public:
    typedef cDynamicListItemT<cDOMNodeReferenceItem> cIs;

    cDOMNodeInterface &m_node;

    /**
     **********************************************************************
     * Constructor: cDOMNodeReferenceItem
     *
     *      Author: $author$
     *        Date: 12/22/2004
     **********************************************************************
     */
    cDOMNodeReferenceItem(cDOMNodeInterface &node) 
    : m_node(node)
    {
    }
    /**
     **********************************************************************
     * Function: GetDOMNode
     *
     *   Author: $author$
     *     Date: 12/22/2004
     **********************************************************************
     */
    cDOMNodeInterface& GetDOMNode() 
    {
        return m_node;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNodeReferenceList
 *
 * Author: $author$
 *   Date: 12/22/2004
 **********************************************************************
 */
class cDOMNodeReferenceList
: public cDynamicListT
  <cDOMNodeReferenceItem, cDOMNodeReferenceList>
{
public:
    typedef cDynamicListT
    <cDOMNodeReferenceItem, cDOMNodeReferenceList> cIs;

    /**
     **********************************************************************
     * Function: Push
     *
     *   Author: $author$
     *     Date: 12/22/2004
     **********************************************************************
     */
    eError Push(cDOMNodeInterface& node) 
    {
        eError error = e_ERROR_NONE;
        cDOMNodeReferenceItem *item;

        if ((item = new cDOMNodeReferenceItem(node)))
            cIs::Push(item);
        else error = e_ERROR_NEW;

        return error;
    }
    /**
     **********************************************************************
     * Function: Pop
     *
     *   Author: $author$
     *     Date: 12/22/2004
     **********************************************************************
     */
    cDOMNodeInterface* Pop(eError &error) 
    {
        error = e_ERROR_NONE;
        cDOMNodeInterface* node = 0;
        cDOMNodeReferenceItem *item;

        if ((item = cIs::Pop()))
        {
            node = &item->GetDOMNode();
            delete item;
        }
        return node;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNode
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
class cDOMNode
: virtual public cDOMNodeInterface,
  virtual public cDOMNodeListImplement,
  public cDynamicListItemT<cDOMNode>
{
public:
    typedef cDynamicListItemT<cDOMNode> cIs;

    cDOMElementInterface *m_parent_element;


    /**
     **********************************************************************
     * Constructor: cDOMNode
     *
     *      Author: $author$
     *        Date: 12/4/2004
     **********************************************************************
     */
    cDOMNode(cDOMElementInterface *parent_element=0) 
    : m_parent_element(parent_element) 
    {
    }
    /**
     **********************************************************************
     * Function: GetNodeType
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual int GetNodeType() const
    {
        int type = e_TYPE_NONE;
        return type;
    }
    /**
     **********************************************************************
     * Function: GetNextSibling
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface* GetNextSibling() const
    {
        cDOMNodeInterface* sibling = GetNext();
        return sibling;
    }
    /**
     **********************************************************************
     * Function: GetPreviousSibling
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface* GetPreviousSibling() const
    {
        cDOMNodeInterface* sibling = GetPrevious();
        return sibling;
    }

    /**
     **********************************************************************
     * Function: GetNextText
     *
     *   Author: $author$
     *     Date: 12/20/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* GetNextText() const
    {
        cDOMNodeInterface* node = GetNextSibling();
        cDOMTextInterface* element = 0;

        while (node)
        {
            if ((element = node->GetTextNode()))
                break;
            node = node->GetNextSibling();
        }
        return element;
    }
    /**
     **********************************************************************
     * Function: GetPreviousText
     *
     *   Author: $author$
     *     Date: 12/20/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* GetPreviousText() const
    {
        cDOMNodeInterface* node = GetPreviousSibling();
        cDOMTextInterface* element = 0;

        while (node)
        {
            if ((element = node->GetTextNode()))
                break;
            node = node->GetPreviousSibling();
        }
        return element;
    }

    /**
     **********************************************************************
     * Function: GetNextElement
     *
     *   Author: $author$
     *     Date: 12/19/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetNextElement() const
    {
        cDOMNodeInterface* node = GetNextSibling();
        cDOMElementInterface* element = 0;

        while (node)
        {
            if ((element = node->GetElementNode()))
                break;
            node = node->GetNextSibling();
        }
        return element;
    }
    /**
     **********************************************************************
     * Function: GetPreviousElement
     *
     *   Author: $author$
     *     Date: 12/19/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetPreviousElement() const
    {
        cDOMNodeInterface* node = GetPreviousSibling();
        cDOMElementInterface* element = 0;

        while (node)
        {
            if ((element = node->GetElementNode()))
                break;
            node = node->GetPreviousSibling();
        }
        return element;
    }

    /**
     **********************************************************************
     * Function: GetNextAttribute
     *
     *   Author: $author$
     *     Date: 12/23/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* GetNextAttribute() const
    {
        cDOMNodeInterface* node = GetNextSibling();
        cDOMAttrInterface* element = 0;

        while (node)
        {
            if ((element = node->GetAttrNode()))
                break;
            node = node->GetNextSibling();
        }
        return element;
    }
    /**
     **********************************************************************
     * Function: GetPreviousAttribute
     *
     *   Author: $author$
     *     Date: 12/23/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* GetPreviousAttribute() const
    {
        cDOMNodeInterface* node = GetPreviousSibling();
        cDOMAttrInterface* element = 0;

        while (node)
        {
            if ((element = node->GetAttrNode()))
                break;
            node = node->GetPreviousSibling();
        }
        return element;
    }

    /**
     **********************************************************************
     * Function: GetParentElement
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetParentElement() const
    {
        return m_parent_element;
    }

    /**
     **********************************************************************
     * Function: GetNamespaceNode
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual cDOMNamespaceNodeInterface* GetNamespaceNode() const
    {
        cDOMNamespaceNodeInterface* node = 0;
        return node;
    }
    /**
     **********************************************************************
     * Function: GetNamedNode
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual cDOMNamedNodeInterface* GetNamedNode() const
    {
        cDOMNamedNodeInterface* node = 0;
        return node;
    }

    /**
     **********************************************************************
     * Function: GetCharacterDataNode
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMCharacterDataInterface* GetCharacterDataNode() const 
    {
        cDOMCharacterDataInterface* characterdata = 0;
        return characterdata;
    }
    /**
     **********************************************************************
     * Function: GetTextNode
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* GetTextNode() const 
    {
        cDOMTextInterface* text = 0;
        return text;
    }
    /**
     **********************************************************************
     * Function: GetAttrNode
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* GetAttrNode() const 
    {
        cDOMAttrInterface* attr = 0;
        return attr;
    }
    /**
     **********************************************************************
     * Function: GetElementNode
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetElementNode() const 
    {
        cDOMElementInterface* element = 0;
        return element;
    }
    /**
     **********************************************************************
     * Function: GetDocumentNode
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMDocumentInterface* GetDocumentNode() const 
    {
        cDOMDocumentInterface* document = 0;
        return document;
    }

    /**
     **********************************************************************
     * Function: GetDOMNode
     *
     *   Author: $author$
     *     Date: 12/2/2004
     **********************************************************************
     */
    virtual cDOMNode& GetDOMNode()
    {
        return *this;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNodeListT
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
template <class TAs, class TIs=cBase>
class cDOMNodeListT
: virtual public cDOMNodeCreatorInterface,
  virtual public cDOMNodeListImplement,
  public cDynamicListT<cDOMNode, TAs, TIs>
{
public:
    typedef cDynamicListT<cDOMNode, TAs, TIs> cIs;

    cDOMEventInterface &m_event;
    cDOMNodeFactoryInterface &m_factory;

    /**
     **********************************************************************
     * Constructor: cDOMNodeListT
     *
     *      Author: $author$
     *        Date: 12/1/2004
     **********************************************************************
     */
    cDOMNodeListT
    (cDOMEventInterface &event,
     cDOMNodeFactoryInterface &factory)
    : m_event(event),
      m_factory(factory)
    {
    }
    /**
     **********************************************************************
     * Constructor: cDOMNodeListT
     *
     *      Author: $author$
     *        Date: 12/1/2004
     **********************************************************************
     */
    cDOMNodeListT(TAs &list)
    : m_event(list.GetEvent()),
      m_factory(list.GetFactory())
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDOMNodeListT
     *
     *      Author: $author$
     *        Date: 12/1/2004
     **********************************************************************
     */
    virtual ~cDOMNodeListT()
    {
        eError error;

        if ((error = Clear()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: AppendElement
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError AppendElement
    (cDOMElementInterface& element) 
    {
        cDOMNode& dom_child = element.GetDOMNode();
        eError error;
        Add(&dom_child);
        error = m_event.OnAppendElement(*this, element);
        return error;
    }
    /**
     **********************************************************************
     * Function: RemoveElement
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError RemoveElement
    (cDOMElementInterface& element) 
    {
        cDOMNode& dom_child = element.GetDOMNode();
        eError error = m_event.OnRemoveElement(*this, element);
        Delete(&dom_child);
        return error;
    }

    /**
     **********************************************************************
     * Function: AppendText
     *
     *   Author: $author$
     *     Date: 12/18/2004
     **********************************************************************
     */
    virtual eError AppendText
    (cDOMTextInterface& text) 
    {
        cDOMNode& dom_child = text.GetDOMNode();
        eError error;
        Add(&dom_child);
        error = m_event.OnAppendText(*this, text);
        return error;
    }
    /**
     **********************************************************************
     * Function: RemoveText
     *
     *   Author: $author$
     *     Date: 12/18/2004
     **********************************************************************
     */
    virtual eError RemoveText
    (cDOMTextInterface& text) 
    {
        cDOMNode& dom_child = text.GetDOMNode();
        eError error = m_event.OnRemoveText(*this, text);
        Delete(&dom_child);
        return error;
    }

    /**
     **********************************************************************
     * Function: AppendChild
     *
     *   Author: $author$
     *     Date: 12/3/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface& AppendChild
    (cDOMNodeInterface& child) 
    {
        cDOMNode& dom_child = child.GetDOMNode();
        Add(&dom_child);
        return child;
    }
    /**
     **********************************************************************
     * Function: RemoveChild
     *
     *   Author: $author$
     *     Date: 12/3/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface& RemoveChild
    (cDOMNodeInterface& child) 
    {
        cDOMNode& dom_child = child.GetDOMNode();
        Delete(&dom_child);
        return child;
    }

    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual eError Free(cDOMNode *node)
    {
        eError error = m_factory.DestroyNode(*node);
        return error;
    }
    /**
     **********************************************************************
     * Function: GetFirstChild
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface* GetFirstChild() const
    {
        cDOMNodeInterface* child = GetFirst();
        return child;
    }
    /**
     **********************************************************************
     * Function: GetLastChild
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface* GetLastChild() const
    {
        cDOMNodeInterface* child = GetLast();
        return child;
    }
    /**
     **********************************************************************
     * Function: GetEvent
     *
     *   Author: $author$
     *     Date: 12/1/2004
     **********************************************************************
     */
    cDOMEventInterface& GetEvent() 
    {
        return m_event;
    }
    /**
     **********************************************************************
     * Function: GetFactory
     *
     *   Author: $author$
     *     Date: 12/1/2004
     **********************************************************************
     */
    virtual cDOMNodeFactoryInterface& GetFactory() 
    {
        return m_factory;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNodeList
 *
 * Author: $author$
 *   Date: 12/2/2004
 **********************************************************************
 */
class cDOMNodeList
: public cDOMNodeListT<cDOMNodeList>
{
public:
    typedef cDOMNodeListT<cDOMNodeList> cIs;

    /**
     **********************************************************************
     * Constructor: cDOMNodeList
     *
     *      Author: $author$
     *        Date: 12/2/2004
     **********************************************************************
     */
    cDOMNodeList
    (cDOMEventInterface &event,
     cDOMNodeFactoryInterface &factory)
    : cIs(event, factory) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cDOMNodeList
     *
     *      Author: $author$
     *        Date: 12/2/2004
     **********************************************************************
     */
    cDOMNodeList(cDOMNodeList &list)
    : cIs(list)
    {
    }
};

class cDOMNamespacePrefixNamespaceStack;

/**
 **********************************************************************
 *  Class: cDOMNamespacePrefixNamespaceItem
 *
 * Author: $author$
 *   Date: 12/7/2004
 **********************************************************************
 */
class cDOMNamespacePrefixNamespaceItem
: public cListItemT<cDOMNamespacePrefixNamespaceItem>
{
public:
    typedef cListItemT<cDOMNamespacePrefixNamespaceItem> cIs;

    cDOMNamespaceInterface &m_namespace;
    cDOMNamespacePrefixNamespaceStack *m_stack;

    /**
     **********************************************************************
     * Constructor: cDOMNamespacePrefixNamespaceItem
     *
     *      Author: $author$
     *        Date: 12/7/2004
     **********************************************************************
     */
    cDOMNamespacePrefixNamespaceItem
    (cDOMNamespaceInterface &p_namespace) 
    : m_namespace(p_namespace),
      m_stack(0)
    {
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    cDOMNamespaceInterface& GetNamespace() 
    {
        return m_namespace;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamespacePrefixNamespaceStack
 *
 * Author: $author$
 *   Date: 12/7/2004
 **********************************************************************
 */
class cDOMNamespacePrefixNamespaceStack
: public cListT
  <cDOMNamespacePrefixNamespaceItem, 
   cDOMNamespacePrefixNamespaceStack>
{
public:
    typedef cListT
    <cDOMNamespacePrefixNamespaceItem, 
     cDOMNamespacePrefixNamespaceStack> cIs;

    cDOMNamespaceInterface &m_bottom;

    /**
     **********************************************************************
     * Constructor: cDOMNamespacePrefixNamespaceStack
     *
     *      Author: $author$
     *        Date: 12/7/2004
     **********************************************************************
     */
    cDOMNamespacePrefixNamespaceStack
    (cDOMNamespaceInterface &bottom) 
    : m_bottom(bottom)
    {
    }
    /**
     **********************************************************************
     * Function: Push
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    void Push(cDOMNamespacePrefixNamespaceItem *item)
    {
        cIs::Push(item);
        item->m_stack = this;
    }
    /**
     **********************************************************************
     * Function: GetTop
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    cDOMNamespaceInterface& GetTop() const
    {
        eError error = e_ERROR_NONE;
        cDOMNamespacePrefixNamespaceItem* l_namespace;

        if ((l_namespace = cIs::GetFirst()))
            return l_namespace->GetNamespace();

        return m_bottom;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamespacePrefixBranch
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMNamespacePrefixBranch
: public cAVLTreeBranchT<cDOMNamespacePrefixBranch>
{
public:
    typedef cAVLTreeBranchT<cDOMNamespacePrefixBranch> cIs;

    const cStringInterface &m_prefix;
    cDOMNamespacePrefixNamespaceItem m_item;
    cDOMNamespacePrefixNamespaceStack m_stack;

    /**
     **********************************************************************
     * Constructor: cDOMNamespacePrefixBranch
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cDOMNamespacePrefixBranch
    (const cStringInterface &prefix,
     cDOMNamespaceInterface &p_namespace)
    : m_prefix(prefix),
      m_item(p_namespace),
      m_stack(p_namespace)
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    int Compare(const cDOMNamespacePrefixBranch &branch) const
    {
        const cStringInterface &prefix = branch.GetPrefix();
        int unequal = m_prefix.Compare(prefix);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    int Compare(const cStringInterface &prefix) const
    {
        int unequal = m_prefix.Compare(prefix);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetPrefix
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetPrefix() const
    {
        return m_prefix;
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual cDOMNamespaceInterface& GetNamespace()
    {
        return m_stack.GetTop();
    }
    /**
     **********************************************************************
     * Function: GetItem
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual cDOMNamespacePrefixNamespaceItem& GetItem()
    {
        return m_item;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamespacePrefixTree
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMNamespacePrefixTree
: public cAVLTreeT
  <const cStringInterface, 
   cDOMNamespacePrefixBranch, 
   cDOMNamespacePrefixTree>
{
public:
    typedef cAVLTreeT
    <const cStringInterface, 
     cDOMNamespacePrefixBranch, 
     cDOMNamespacePrefixTree> cIs;

    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    cDOMNamespaceInterface* FindNamespace
    (const cStringInterface &prefix) const
    {
        cDOMNamespaceInterface* l_namespace = 0;
        cDOMNamespacePrefixBranch* branch;

        if ((branch = cIs::Find(prefix)))
            l_namespace = &branch->GetNamespace();
        return l_namespace;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamespacePrefixItem
 *
 * Author: $author$
 *   Date: 12/7/2004
 **********************************************************************
 */
class cDOMNamespacePrefixItem
: public cDynamicListItemT<cDOMNamespacePrefixItem>
{
public:
    typedef cDynamicListItemT<cDOMNamespacePrefixItem> cIs;

    cDOMNamespacePrefixBranch m_branch;

    /**
     **********************************************************************
     * Constructor: cDOMNamespacePrefixItem
     *
     *      Author: $author$
     *        Date: 12/7/2004
     **********************************************************************
     */
    cDOMNamespacePrefixItem
    (const cStringInterface& prefix,
     cDOMNamespaceInterface &p_namespace) 
    : m_branch(prefix, p_namespace)
    {
    }
    /**
     **********************************************************************
     * Function: GetPrefix
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    const cStringInterface& GetPrefix() const
    {
        return m_branch.GetPrefix();
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    cDOMNamespaceInterface& GetNamespace() 
    {
        return m_branch.GetNamespace();
    }
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    cDOMNamespacePrefixBranch& GetBranch() 
    {
        return m_branch;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamespacePrefixList
 *
 * Author: $author$
 *   Date: 12/6/2004
 **********************************************************************
 */
class cDOMNamespacePrefixList
: public cDynamicListT
  <cDOMNamespacePrefixItem, cDOMNamespacePrefixList>
{
public:
    typedef cDynamicListT
    <cDOMNamespacePrefixItem, cDOMNamespacePrefixList> cIs;

    /**
     **********************************************************************
     * Function: Add
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    eError Add
    (const cStringInterface &prefix,
     cDOMNamespaceInterface& p_namespace) 
    {
        eError error = e_ERROR_NONE;
        cDOMNamespacePrefixItem* l_namespace;

        if ((l_namespace = new cDOMNamespacePrefixItem(prefix, p_namespace)))
            cIs::Add(l_namespace);
        else error = e_ERROR_NEW;

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamespaceStackItem
 *
 * Author: $author$
 *   Date: 12/7/2004
 **********************************************************************
 */
class cDOMNamespaceStackItem
: public cDynamicListItemT<cDOMNamespaceStackItem>
{
public:
    typedef cDynamicListItemT<cDOMNamespaceStackItem> cIs;

    cDOMNamespaceInterface &m_namespace;
    cDOMNamespacePrefixList m_prefix_list;

    /**
     **********************************************************************
     * Constructor: cDOMNamespaceStackItem
     *
     *      Author: $author$
     *        Date: 12/7/2004
     **********************************************************************
     */
    cDOMNamespaceStackItem
    (cDOMNamespaceInterface &p_namespace,
     cDOMNamespacePrefixList &prefix_list) 
    : m_namespace(p_namespace)
    {
        cDOMNamespacePrefixItem *item;

        while ((item = prefix_list.Pop()))
            m_prefix_list.Push(item);
    }
    /**
     **********************************************************************
     *  Destructor: ~cDOMNamespaceStackItem
     *
     *      Author: $author$
     *        Date: 12/7/2004
     **********************************************************************
     */
    virtual ~cDOMNamespaceStackItem()
    {
        eError error;

        if ((error = m_prefix_list.Clear()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    cDOMNamespaceInterface& GetNamespace() 
    {
        return m_namespace;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamespaceStack
 *
 * Author: $author$
 *   Date: 12/7/2004
 **********************************************************************
 */
class cDOMNamespaceStack
: public cDynamicListT
  <cDOMNamespaceStackItem, cDOMNamespaceStack>
{
public:
    typedef cDynamicListT
    <cDOMNamespaceStackItem, cDOMNamespaceStack> cIs;

    /**
     **********************************************************************
     * Function: Push
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    eError Push
    (cDOMNamespaceInterface& p_namespace,
     cDOMNamespacePrefixList &prefix_list) 
    {
        eError error = e_ERROR_NONE;
        cDOMNamespaceStackItem* l_namespace;

        if ((l_namespace = new 
            cDOMNamespaceStackItem(p_namespace, prefix_list)))
            cIs::Push(l_namespace);
        else error = e_ERROR_NEW;

        return error;
    }
    /**
     **********************************************************************
     * Function: Pop
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    eError Pop(cDOMNamespacePrefixList &prefix_list) 
    {
        eError error = e_ERROR_NONE;
        cDOMNamespaceStackItem* l_namespace;
        cDOMNamespacePrefixItem *item;

        if ((l_namespace = cIs::Pop()))
        {
            while ((item = l_namespace->m_prefix_list.Pop()))
                prefix_list.Push(item);

            error = cIs::Free(l_namespace);
        }
        else error = e_ERROR_FAILED;

        return error;
    }
    /**
     **********************************************************************
     * Function: GetTop
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    cDOMNamespaceInterface& GetTop() const
    {
        eError error = e_ERROR_NONE;
        cDOMNamespaceStackItem* l_namespace;

        if ((l_namespace = cIs::GetFirst()))
            return l_namespace->GetNamespace();

        return cDOMNamespaceInterface::GetGlobalNamespace();
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamespaceBranch
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMNamespaceBranch
: public cAVLTreeBranchT<cDOMNamespaceBranch>
{
public:
    typedef cAVLTreeBranchT<cDOMNamespaceBranch> cIs;

    cDOMNamespaceInterface &m_namespace;

    /**
     **********************************************************************
     * Constructor: cDOMNamespaceBranch
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cDOMNamespaceBranch(cDOMNamespaceInterface &p_namespace)
    : m_namespace(p_namespace)
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    int Compare(const cDOMNamespaceBranch &branch) const
    {
        const cStringInterface &m_name = GetNamespaceURI();
        const cStringInterface &name = branch.GetNamespaceURI();
        int unequal = m_name.Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    int Compare(const cStringInterface &name) const
    {
        const cStringInterface &m_name = GetNamespaceURI();
        int unequal = m_name.Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetNamespaceURI
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetNamespaceURI() const
    {
        const cStringInterface& name = m_namespace.GetNamespaceURI();
        return name;
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual cDOMNamespaceInterface& GetNamespace() const
    {
        return m_namespace;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamespace
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMNamespace
: virtual public cDOMNamespaceInterface,
  public cDynamicListItemT<cDOMNamespace>
{
public:
    typedef cDynamicListItemT<cDOMNamespace> cIs;

    static cDOMNamespace m_global_namespace;
    static cString m_global_namespace_uri;

    cDOMNamespaceBranch m_branch;
    cString m_namespace_uri;

    /**
     **********************************************************************
     * Constructor: cDOMNamespace
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cDOMNamespace()
    : m_branch(*this)
    {
    }
    /**
     **********************************************************************
     * Constructor: cDOMNamespace
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cDOMNamespace(const cStringInterface &namespace_uri)
    : m_branch(*this),
      m_namespace_uri(namespace_uri)
    {
    }
    /**
     **********************************************************************
     * Function: GetDOMNamespace
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual cDOMNamespace& GetDOMNamespace()
    {
        return *this;
    }
    /**
     **********************************************************************
     * Function: GetNamespaceURI
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetNamespaceURI() const
    {
        const cStringInterface& namespace_uri = m_namespace_uri;
        return namespace_uri;
    }
    /**
     **********************************************************************
     * Function: GetGlobalNamespaceURI
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    static const cStringInterface& GetGlobalNamespaceURI()
    {
        return m_global_namespace_uri;
    }
    /**
     **********************************************************************
     * Function: GetGlobalNamespace
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    static cDOMNamespace& GetGlobalNamespace()
    {
        return m_global_namespace;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamespaceList
 *
 * Author: $author$
 *   Date: 12/6/2004
 **********************************************************************
 */
class cDOMNamespaceList
: public cDynamicListT<cDOMNamespace, cDOMNamespaceList>
{
public:
    typedef cDynamicListT<cDOMNamespace, cDOMNamespaceList> cIs;

    cDOMNodeFactoryInterface &m_factory;

    /**
     **********************************************************************
     * Constructor: cDOMNamespaceList
     *
     *      Author: $author$
     *        Date: 12/6/2004
     **********************************************************************
     */
    cDOMNamespaceList(cDOMNodeFactoryInterface &factory)
    : m_factory(factory) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDOMNamespaceList
     *
     *      Author: $author$
     *        Date: 12/6/2004
     **********************************************************************
     */
    virtual ~cDOMNamespaceList()
    {
        eError error;

        if ((error = Clear()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual eError Free(cDOMNamespace *n)
    {
        eError error = m_factory.DestroyNamespace(*n);
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamespaceTree
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMNamespaceTree
: public cAVLTreeT
  <const cStringInterface, cDOMNamespaceBranch, cDOMNamespaceTree>
{
public:
    typedef cAVLTreeT
    <const cStringInterface, cDOMNamespaceBranch, cDOMNamespaceTree> cIs;

    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    cDOMNamespaceInterface* Find
    (const cStringInterface &namespace_uri) const
    {
        cDOMNamespaceInterface* l_namespace = 0;
        cDOMNamespaceBranch* branch;

        if ((branch = cIs::Find(namespace_uri)))
            l_namespace = &branch->GetNamespace();
        return l_namespace;
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    void Insert(cDOMNamespace* p_namespace)
    {
        cIs::Insert(&p_namespace->m_branch);
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamespaceNode
 *
 * Author: $author$
 *   Date: 12/18/2004
 **********************************************************************
 */
class cDOMNamespaceNode
: virtual public cDOMNamespaceNodeInterface,
  public cDOMNode
{
public:
    typedef cDOMNode cIs;

    cDOMNamespaceInterface *m_namespace;
    const cStringInterface *m_namespace_uri;
    bool m_has_namespace;

    /**
     **********************************************************************
     * Constructor: cDOMNamespaceNode
     *
     *      Author: $author$
     *        Date: 12/18/2004
     **********************************************************************
     */
    cDOMNamespaceNode
    (cDOMElementInterface *parent_element=0,
     cDOMNamespaceInterface *p_namespace=0,
     const cStringInterface *namespace_uri=0,
     bool has_namespace=false)
    : cIs(parent_element),
      m_namespace(p_namespace),
      m_namespace_uri(namespace_uri),
      m_has_namespace(has_namespace)
    {
    }
    /**
     **********************************************************************
     * Function: SetHasNamespace
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual int SetHasNamespace(bool has=true) 
    {
        m_has_namespace = has;
        return m_has_namespace;
    }
    /**
     **********************************************************************
     * Function: GetHasNamespace
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual bool GetHasNamespace() 
    {
        return m_has_namespace;
    }
    /**
     **********************************************************************
     * Function: SetNamespace
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError SetNamespace
    (cDOMNamespaceInterface* p_namespace)
    {
        eError error = e_ERROR_NONE;
        const cStringInterface* namespace_uri = 0;

        if ((m_namespace = p_namespace))
           namespace_uri = &m_namespace->GetNamespaceURI();

        m_namespace_uri = namespace_uri;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual cDOMNamespaceInterface& GetNamespace() const
    {
        if (m_namespace)
            return *m_namespace;
        return cDOMNamespace::GetGlobalNamespace();
    }
    /**
     **********************************************************************
     * Function: SetNamespaceURI
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual eError SetNamespaceURI
    (const cStringInterface* namespace_uri)
    {
        eError error = e_ERROR_NONE;
        m_namespace_uri = namespace_uri;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetNamespaceURI
     *
     *   Author: $author$
     *     Date: 12/2/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetNamespaceURI() const
    {
        if (m_namespace_uri)
            return *m_namespace_uri;
        return cDOMNamespace::GetGlobalNamespaceURI();
    }
    /**
     **********************************************************************
     * Function: GetNamespaceNode
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual cDOMNamespaceNodeInterface* GetNamespaceNode() const
    {
        return (cDOMNamespaceNodeInterface*)this;
    }
    /**
     **********************************************************************
     * Function: GetDOMNamespaceNode
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual cDOMNamespaceNode& GetDOMNamespaceNode()
    {
        return *this;
    }
    /**
     **********************************************************************
     * Function: GetDOMNamespace
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual cDOMNamespace& GetDOMNamespace()
    {
        if (m_namespace)
            return m_namespace->GetDOMNamespace();

        return cDOMNamespace::GetGlobalNamespace();
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamedNode
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
class cDOMNamedNode
: virtual public cDOMNamedNodeInterface,
  public cDOMNamespaceNode
{
public:
    typedef cDOMNamespaceNode cIs;

    cString m_prefix, m_name;

    /**
     **********************************************************************
     * Constructor: cDOMNamedNode
     *
     *      Author: $author$
     *        Date: 11/28/2004
     **********************************************************************
     */
    cDOMNamedNode
    (cDOMElementInterface *parent_element=0,
     cDOMNamespaceInterface *p_namespace=0,
     const cStringInterface *namespace_uri=0,
     bool has_namespace=false)
    : cIs
      (parent_element, p_namespace, 
       namespace_uri, has_namespace)
    {
    }
    /**
     **********************************************************************
     * Function: SetPrefix
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual int SetPrefix
    (const char *text, int length=-1) 
    {
        length = m_prefix.SetChars(text, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetPrefix
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetPrefix() const
    {
        return m_prefix;
    }
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual int SetName
    (const char *text, int length=-1) 
    {
        length = m_name.SetChars(text, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetName() const
    {
        return m_name;
    }
    /**
     **********************************************************************
     * Function: GetNamedNode
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual cDOMNamedNodeInterface* GetNamedNode() const
    {
        return (cDOMNamedNodeInterface*)this;
    }
    /**
     **********************************************************************
     * Function: GetDOMNamedNode
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual cDOMNamedNode& GetDOMNamedNode()
    {
        return *this;
    }
};

/**
 **********************************************************************
 *  Class: cDOMCharacterData
 *
 * Author: $author$
 *   Date: 12/16/2004
 **********************************************************************
 */
class cDOMCharacterData
: virtual public cDOMCharacterDataInterface,
  public cDOMNamespaceNode
{
public:
    typedef cDOMNamespaceNode cIs;

    cString m_data;

    /**
     **********************************************************************
     * Constructor: cDOMCharacterData
     *
     *      Author: $author$
     *        Date: 12/16/2004
     **********************************************************************
     */
    cDOMCharacterData
    (cDOMElementInterface *parent_element=0,
     cDOMNamespaceInterface *p_namespace=0,
     const cStringInterface *namespace_uri=0)
    : cIs(parent_element, p_namespace, namespace_uri)
    {
    }
    /**
     **********************************************************************
     * Constructor: cDOMCharacterData
     *
     *      Author: $author$
     *        Date: 12/16/2004
     **********************************************************************
     */
    cDOMCharacterData
    (const cStringInterface& data,
     cDOMElementInterface *parent_element=0,
     cDOMNamespaceInterface *p_namespace=0,
     const cStringInterface *namespace_uri=0) 
    : cIs(parent_element, p_namespace, namespace_uri),
      m_data(data)
    {
    }
    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 12/17/2004
     **********************************************************************
     */
    virtual int SetChars
    (const char *chars, int length=-1)
    {
        length = m_data.SetChars(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: SetData
     *
     *   Author: $author$
     *     Date: 12/16/2004
     **********************************************************************
     */
    virtual eError SetData
    (const cStringInterface& data) 
    {
        eError error = e_ERROR_NONE;
        int count;

        if (0 > (count = m_data.Set(data)))
            error = -count;

        return error;
    }
    /**
     **********************************************************************
     * Function: GetData
     *
     *   Author: $author$
     *     Date: 12/16/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetData() const
    {
        return m_data;
    }
};

/**
 **********************************************************************
 *  Class: cDOMText
 *
 * Author: $author$
 *   Date: 12/16/2004
 **********************************************************************
 */
class cDOMText
: virtual public cDOMTextInterface,
  public cDOMCharacterData
{
public:
    typedef cDOMCharacterData cIs;

    /**
     **********************************************************************
     * Constructor: cDOMText
     *
     *      Author: $author$
     *        Date: 12/16/2004
     **********************************************************************
     */
    cDOMText
    (cDOMElementInterface *parent_element=0,
     cDOMNamespaceInterface *p_namespace=0,
     const cStringInterface *namespace_uri=0) 
    : cIs(parent_element, p_namespace, namespace_uri)
    {
    }
    /**
     **********************************************************************
     * Constructor: cDOMText
     *
     *      Author: $author$
     *        Date: 12/16/2004
     **********************************************************************
     */
    cDOMText
    (const cStringInterface& data,
     cDOMElementInterface *parent_element=0,
     cDOMNamespaceInterface *p_namespace=0,
     const cStringInterface *namespace_uri=0) 
    : cIs(data, parent_element, p_namespace, namespace_uri) 
    {
    }
    /**
     **********************************************************************
     * Function: GetTextNode
     *
     *   Author: $author$
     *     Date: 12/19/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* GetTextNode() const 
    {
        return (cDOMTextInterface*)this;
    }
    /**
     **********************************************************************
     * Function: GetDOMText
     *
     *   Author: $author$
     *     Date: 12/19/2004
     **********************************************************************
     */
    virtual cDOMText& GetDOMText() 
    {
        return *this;
    }
};

/**
 **********************************************************************
 *  Class: cDOMAttrBranch
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMAttrBranch
: public cAVLTreeBranchT<cDOMAttrBranch>
{
public:
    typedef cAVLTreeBranchT<cDOMAttrBranch> cIs;

    cDOMAttrInterface &m_attr;

    /**
     **********************************************************************
     * Constructor: cDOMAttrBranch
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cDOMAttrBranch(cDOMAttrInterface &attr)
    : m_attr(attr)
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    int Compare(cDOMAttrBranch &branch) const
    {
        const cStringInterface &name = branch.GetName();
        int unequal = Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    int Compare(const cStringInterface &name) const
    {
        const cStringInterface &m_name = GetName();
        int unequal = m_name.Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    const cStringInterface& GetName() const
    {
        return m_attr.GetName();
    }
};

/**
 **********************************************************************
 *  Class: cDOMAttrTree
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMAttrTree
: public cAVLTreeT
  <const cStringInterface, cDOMAttrBranch, cDOMAttrTree>
{
public:
    typedef cAVLTreeT
    <const cStringInterface, cDOMAttrBranch, cDOMAttrTree> cIs;

    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    cDOMAttrInterface *Find(const cStringInterface &name) const
    {
        cDOMAttrInterface *a = 0;
        cDOMAttrBranch *b;

        if ((b = cIs::Find(name)))
            a = &b->m_attr;

        return a;
    }
};

/**
 **********************************************************************
 *  Class: cDOMAttr
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
class cDOMAttr
: virtual public cDOMAttrInterface,
  public cDOMNamedNode
{
public:
    typedef cDOMNamedNode cIs;

    cDOMAttrBranch m_branch;
    cString m_value;
    bool m_is_xmlns;

    /**
     **********************************************************************
     * Constructor: cDOMAttr
     *
     *      Author: $author$
     *        Date: 11/28/2004
     **********************************************************************
     */
    cDOMAttr
    (cDOMElementInterface& parent,
     bool is_xmlns=false) 
    : cIs(&parent),
      m_branch(*this),
      m_is_xmlns(is_xmlns)
    {
    }
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual int SetValue
    (const char *text, int length=-1) 
    {
        length = m_value.SetChars(text, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetValue() const
    {
        return m_value;
    }
    /**
     **********************************************************************
     * Function: SetIsXmlns
     *
     *   Author: $author$
     *     Date: 12/23/2004
     **********************************************************************
     */
    virtual int SetIsXmlns(bool is=true) 
    {
        return m_is_xmlns = is;
    }
    /**
     **********************************************************************
     * Function: GetIsXmlns
     *
     *   Author: $author$
     *     Date: 12/23/2004
     **********************************************************************
     */
    virtual bool GetIsXmlns() const
    {
        return m_is_xmlns;
    }
    /**
     **********************************************************************
     * Function: GetAttrNode
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* GetAttrNode() const 
    {
        return (cDOMAttrInterface*)this;
    }
    /**
     **********************************************************************
     * Function: GetDOMAttr
     *
     *   Author: $author$
     *     Date: 12/2/2004
     **********************************************************************
     */
    virtual cDOMAttr& GetDOMAttr() 
    {
        return *this;
    }
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    cDOMAttrBranch& GetBranch() 
    {
        return m_branch;
    }
};

/**
 **********************************************************************
 *  Class: cDOMElement
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
class cDOMElement
: virtual public cDOMElementInterface,
  public cDOMNodeListT<cDOMElement, cDOMNamedNode>
{
public:
    typedef cDOMNodeListT<cDOMElement, cDOMNamedNode> cIs;

    cDOMNodeList m_attr_list;
    cDOMAttrTree m_attr_tree;

    /**
     **********************************************************************
     * Constructor: cDOMElement
     *
     *      Author: $author$
     *        Date: 11/28/2004
     **********************************************************************
     */
    cDOMElement
    (cDOMEventInterface &event,
     cDOMNodeFactoryInterface &factory, 
     cDOMElementInterface *parent_element=0)
    : cIs(event, factory),
      m_attr_list(event, factory)
    {
        m_parent_element = parent_element;
    }
    /**
     **********************************************************************
     * Function: AppendAttribute
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual eError AppendAttribute
    (cDOMAttrInterface& attr) 
    {
        cDOMAttr& dom_attr = attr.GetDOMAttr();
        eError error = m_event.OnAppendAttribute(*this, attr);

        if (!error)
        {
            m_attr_tree.Insert(&dom_attr.GetBranch());
            m_attr_list.AppendChild(attr);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: RemoveAttribute
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual eError RemoveAttribute
    (cDOMAttrInterface& attr) 
    {
        cDOMAttr& dom_attr = attr.GetDOMAttr();
        eError error = m_event.OnRemoveAttribute(*this, attr);
        return error;
    }
    /**
     **********************************************************************
     * Function: GetAttribute
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual const cStringInterface* GetAttribute
    (const cStringInterface &name) const
    {
        const cStringInterface* value = 0;
        cDOMAttrInterface *a;

        if ((a = m_attr_tree.Find(name)))
            value = &a->GetValue();

        return value;
    }
    /**
     **********************************************************************
     * Function: GetFirstAttribute
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* GetFirstAttribute() const
    {
        cDOMAttrInterface* attr = m_attr_list.GetFirstAttribute();
        return attr;
    }
    /**
     **********************************************************************
     * Function: GetLastAttribute
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* GetLastAttribute() const
    {
        cDOMAttrInterface* attr = m_attr_list.GetLastAttribute();
        return attr;
    }
    /**
     **********************************************************************
     * Function: GetNodeType
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual int GetNodeType() const
    {
        int type = e_TYPE_ELEMENT_NODE;
        return type;
    }
    /**
     **********************************************************************
     * Function: GetElementNode
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetElementNode() const 
    {
        return (cDOMElementInterface*)this;
    }
    /**
     **********************************************************************
     * Function: GetDOMElement
     *
     *   Author: $author$
     *     Date: 12/2/2004
     **********************************************************************
     */
    virtual cDOMElement& GetDOMElement() 
    {
        return *this;
    }
};

/**
 **********************************************************************
 *  Class: cDOMDocument
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
class cDOMDocument
: virtual public cDOMDocumentInterface,
  public cDOMNodeListT<cDOMDocument, cDOMNode>
{
public:
    typedef cDOMNodeListT<cDOMDocument, cDOMNode> cIs;

    /**
     **********************************************************************
     * Constructor: cDOMDocument
     *
     *      Author: $author$
     *        Date: 11/28/2004
     **********************************************************************
     */
    cDOMDocument
    (cDOMEventInterface &event,
     cDOMNodeFactoryInterface &factory)
    : cIs(event, factory) 
    {
    }
    /**
     **********************************************************************
     * Function: GetDocumentElement
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetDocumentElement() const
    {
        cDOMElementInterface* element = GetFirstElement();
        return element;
    }
    /**
     **********************************************************************
     * Function: GetDOMDocument
     *
     *   Author: $author$
     *     Date: 12/2/2004
     **********************************************************************
     */
    virtual cDOMDocument& GetDOMDocument() 
    {
        return *this;
    }
};

/**
 **********************************************************************
 *  Class: cDOMEvent
 *
 * Author: $author$
 *   Date: 12/5/2004
 **********************************************************************
 */
class cDOMEvent
: virtual public cDOMEventInterface
{
public:
    /**
     **********************************************************************
     * Function: OnBeginElement
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError OnBeginElement
    (cDOMElementInterface& element) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndElement
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError OnEndElement
    (cDOMElementInterface& element) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: OnAppendElement
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError OnAppendElement
    (cDOMNodeListInterface& list,
     cDOMElementInterface& element) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRemoveElement
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError OnRemoveElement
    (cDOMNodeListInterface& list,
     cDOMElementInterface& element) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: OnAppendAttribute
     *
     *   Author: $author$
     *     Date: 12/5/2004
     **********************************************************************
     */
    virtual eError OnAppendAttribute
    (cDOMElementInterface& element,
     cDOMAttrInterface &attr) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRemoveAttribute
     *
     *   Author: $author$
     *     Date: 12/5/2004
     **********************************************************************
     */
    virtual eError OnRemoveAttribute
    (cDOMElementInterface& element,
     cDOMAttrInterface &attr) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: OnAppendText
     *
     *   Author: $author$
     *     Date: 12/17/2004
     **********************************************************************
     */
    virtual eError OnAppendText
    (cDOMNodeListInterface& list,
     cDOMTextInterface& text) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRemoveText
     *
     *   Author: $author$
     *     Date: 12/17/2004
     **********************************************************************
     */
    virtual eError OnRemoveText
    (cDOMNodeListInterface& list,
     cDOMTextInterface& text) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNodeFactory
 *
 * Author: $author$
 *   Date: 12/1/2004
 **********************************************************************
 */
class cDOMNodeFactory
: virtual public cDOMNodeFactoryInterface
{
public:
    cDOMEventInterface& m_event;

    cDOMNamespaceList m_namespace_list;
    cDOMNamespaceTree m_namespace_tree;

    /**
     **********************************************************************
     * Constructor: cDOMNodeFactory
     *
     *      Author: $author$
     *        Date: 12/5/2004
     **********************************************************************
     */
    cDOMNodeFactory(cDOMEventInterface& event) 
    : m_event(event),
      m_namespace_list(*this)
    {
    }
    /**
     **********************************************************************
     * Constructor: ~cDOMNodeFactory
     *
     *      Author: $author$
     *        Date: 12/6/2004
     **********************************************************************
     */
    virtual ~cDOMNodeFactory() 
    {
        m_namespace_list.Clear();
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual cDOMNamespaceInterface* GetNamespace
    (const cStringInterface& namespace_uri)
    {
        cDOMNamespaceInterface* l_namespace;

        if (&namespace_uri == &cDOMNamespaceInterface::GetGlobalNamespaceURI())
            return &cDOMNamespaceInterface::GetGlobalNamespace();

        if (!(l_namespace = m_namespace_tree.Find(namespace_uri)))
            l_namespace = CreateNamespace(namespace_uri);

        return l_namespace;
    }
    /**
     **********************************************************************
     * Function: CreateNamespace
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual cDOMNamespaceInterface* CreateNamespace
    (const cStringInterface& namespace_uri)
    {
        cDOMNamespace* l_namespace;

        if ((l_namespace = new cDOMNamespace(namespace_uri)))
        {
            m_namespace_list.Add(l_namespace);
            m_namespace_tree.Insert(l_namespace);
        }
        return l_namespace;
    }
    /**
     **********************************************************************
     * Function: DestroyNamespace
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual eError DestroyNamespace
    (cDOMNamespaceInterface& p_namespace)
    {
        eError error = e_ERROR_NONE;
        cDOMNamespace &dom_namespace = p_namespace.GetDOMNamespace();

        delete &dom_namespace;
        return error;
    }
    /**
     **********************************************************************
     * Function: DestroyNode
     *
     *   Author: $author$
     *     Date: 12/1/2004
     **********************************************************************
     */
    virtual eError DestroyNode
    (cDOMNodeInterface& node) 
    {
        eError error = e_ERROR_NONE;
        cDOMNode &dom_node = node.GetDOMNode();

        delete &dom_node;
        return error;
    }
    /**
     **********************************************************************
     * Function: CreateText
     *
     *   Author: $author$
     *     Date: 12/19/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* CreateText
    (cDOMElementInterface* parent=0) 
    {
        cDOMText* text = new cDOMText(parent);
        return text;
    }
    /**
     **********************************************************************
     * Function: CreateAttribute
     *
     *   Author: $author$
     *     Date: 12/1/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* CreateAttribute
    (cDOMElementInterface& parent) 
    {
        cDOMAttr* attr = new cDOMAttr(parent);
        return attr;
    }
    /**
     **********************************************************************
     * Function: CreateElement
     *
     *   Author: $author$
     *     Date: 12/1/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* CreateElement
    (cDOMElementInterface* parent=0) 
    {
        cDOMElement* element = new 
            cDOMElement(m_event, *this, parent);
        return element;
    }
    /**
     **********************************************************************
     * Function: CreateDocument
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual cDOMDocumentInterface* CreateDocument() 
    {
        cDOMDocument* document = new 
            cDOMDocument(m_event, *this);
        return document;
    }
};

#endif /* _CDOM_HXX */