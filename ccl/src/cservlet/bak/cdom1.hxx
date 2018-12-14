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
 *   Date: 11/28/2004
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
 *  Class: cDOMNamespace
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMNamespace
: public cAVLTreeBranchT<cDOMNamespace>
{
public:
    typedef cAVLTreeBranchT<cDOMNamespace> cIs;

    static cDOMNamespace m_global;

    cString m_name;

    /**
     **********************************************************************
     * Constructor: cDOMNamespace
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cDOMNamespace()
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
    cDOMNamespace(const cStringInterface &name)
    : m_name(name)
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
    int Compare(const cDOMNamespace &branch) const
    {
        const cStringInterface &name = branch.GetName();
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
        const cStringInterface& name = m_name;
        return name;
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
  <const cStringInterface, cDOMNamespace, cDOMNamespaceTree>
{
public:
    typedef cAVLTreeT
    <const cStringInterface, cDOMNamespace, cDOMNamespaceTree> cIs;
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
  public cDynamicListItemT<cDOMNode>
{
public:
    typedef cDynamicListItemT<cDOMNode> cIs;

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
     * Function: GetFirstChild
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface* GetFirstChild() 
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
    virtual cDOMNodeInterface* GetLastChild() 
    {
        cDOMNodeInterface* child = 0;
        return child;
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
};

class cDOMElement;

/**
 **********************************************************************
 *  Class: cDOMNodeFactoryInterface
 *
 * Author: $author$
 *   Date: 12/1/2004
 **********************************************************************
 */
class cDOMNodeFactoryInterface
{
public:
    /**
     **********************************************************************
     * Function: DestroyNode
     *
     *   Author: $author$
     *     Date: 12/1/2004
     **********************************************************************
     */
    virtual eError DestroyNode
    (cDOMNode& node) = 0;
    /**
     **********************************************************************
     * Function: CreateElement
     *
     *   Author: $author$
     *     Date: 12/1/2004
     **********************************************************************
     */
    virtual cDOMElement* CreateElement
    (cDOMElement* parent=0) = 0;
};

/**
 **********************************************************************
 *  Class: cDOMNodeList
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
class cDOMNodeList
: virtual public cDOMNodeListInterface,
  public cDynamicListT
  <cDOMNode, cDOMNodeList>
{
public:
    typedef cDynamicListT
    <cDOMNode, cDOMNodeList> cIs;

    cDOMNodeFactoryInterface &m_factory;

    /**
     **********************************************************************
     * Constructor: cDOMNodeList
     *
     *      Author: $author$
     *        Date: 12/1/2004
     **********************************************************************
     */
    cDOMNodeList(cDOMNodeFactoryInterface &factory)
    : m_factory(factory)
    {
    }
    /**
     **********************************************************************
     * Constructor: cDOMNodeList
     *
     *      Author: $author$
     *        Date: 12/1/2004
     **********************************************************************
     */
    cDOMNodeList(cDOMNodeList &list)
    : m_factory(list.GetFactory())
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDOMNodeList
     *
     *      Author: $author$
     *        Date: 12/1/2004
     **********************************************************************
     */
    virtual ~cDOMNodeList()
    {
        eError error;

        if ((error = Clear()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: GetFirstChild
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
    virtual cDOMNodeInterface* GetFirstChild() 
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
    virtual cDOMNodeInterface* GetLastChild() 
    {
        cDOMNodeInterface* child = GetLast();
        return child;
    }
    /**
     **********************************************************************
     * Function: GetFactory
     *
     *   Author: $author$
     *     Date: 12/1/2004
     **********************************************************************
     */
    cDOMNodeFactoryInterface& GetFactory() 
    {
        return m_factory;
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
  public cDOMNode
{
public:
    typedef cDOMNode cIs;

    cString m_prefix, m_name;
    const cStringInterface *m_namespace_uri;

    /**
     **********************************************************************
     * Constructor: cDOMNamedNode
     *
     *      Author: $author$
     *        Date: 11/28/2004
     **********************************************************************
     */
    cDOMNamedNode(const cStringInterface *namespace_uri=0)
    : m_namespace_uri(namespace_uri)
    {
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
        return cDOMNamespace::m_global.GetName();
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
 *  Class: cDOMAttrNamespace
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMAttrNamespace
: public cAVLTreeBranchT<cDOMAttrNamespace>
{
public:
    typedef cAVLTreeBranchT<cDOMAttrNamespace> cIs;

    cDOMNamespace &m_name_space;

    /**
     **********************************************************************
     * Constructor: cDOMAttrNamespace
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cDOMAttrNamespace(cDOMNamespace &name_space)
    : m_name_space(name_space)
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
    int Compare(cDOMAttrNamespace &branch) const
    {
        const cDOMNamespace &name_space = branch.GetNamespace();
        int unequal = Compare(name_space);
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
    int Compare(const cDOMNamespace &name_space) const
    {
        int unequal = 0;

        if (&m_name_space > &name_space)
            unequal = 1;
        else if (&m_name_space < &name_space)
                unequal = -1;

        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    const cDOMNamespace& GetNamespace() const
    {
        return m_name_space;
    }
};

/**
 **********************************************************************
 *  Class: cDOMAttrNamespaceTree
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMAttrNamespaceTree
: public cAVLTreeT
  <const cDOMNamespace, cDOMAttrNamespace, cDOMAttrNamespaceTree>
{
public:
    typedef cAVLTreeT
    <const cDOMNamespace, cDOMAttrNamespace, cDOMAttrNamespaceTree> cIs;
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

    /**
     **********************************************************************
     * Constructor: cDOMAttr
     *
     *      Author: $author$
     *        Date: 11/28/2004
     **********************************************************************
     */
    cDOMAttr() 
    : m_branch(*this)
    {
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
  public cDOMNamedNode,
  public cDOMNodeList
{
public:
    typedef cDOMNodeList cListIs;

    cDOMElement *m_parent;
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
    (cDOMNodeFactoryInterface &factory, cDOMElement *parent=0)
    : cListIs(factory),
      m_attr_list(factory),
      m_parent(parent) 
    {
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
        cDOMElementInterface* element = (cDOMElementInterface*)this;
        return element;
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
: virtual public cDOMDocumentImplement,
  public cDOMNode,
  public cDOMNodeList
{
public:
    typedef cDOMNodeList cListIs;

    /**
     **********************************************************************
     * Constructor: cDOMDocument
     *
     *      Author: $author$
     *        Date: 11/28/2004
     **********************************************************************
     */
    cDOMDocument(cDOMNodeFactoryInterface& factory)
    : cListIs(factory)
    {
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
    /**
     **********************************************************************
     * Function: DestroyNode
     *
     *   Author: $author$
     *     Date: 12/1/2004
     **********************************************************************
     */
    virtual eError DestroyNode
    (cDOMNode& node) 
    {
        eError error = e_ERROR_NONE;
        delete &node;
        return error;
    }
    /**
     **********************************************************************
     * Function: CreateElement
     *
     *   Author: $author$
     *     Date: 12/1/2004
     **********************************************************************
     */
    virtual cDOMElement* CreateElement
    (cDOMElement* parent=0) 
    {
        cDOMElement* element = new cDOMElement(*this,parent);
        return element;
    }
};

#endif /* ndef _CDOM_HXX */

