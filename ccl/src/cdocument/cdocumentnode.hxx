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
 *   File: cdocumentnode.hxx
 *
 * Author: $author$
 *   Date: 11/24/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTNODE_HXX
#define _CDOCUMENTNODE_HXX

#include "cdocumentartifact.hxx"
#include "cdocumenteventinterface.hxx"
#include "clistt.hxx"

/**
 **********************************************************************
 *  Class: cDocumentNode
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class cDocumentNode
: virtual public cDocumentNodeFactoryArtifactImplement,
  virtual public cDocumentNodeImplement,
  public cDynamicListItemT
  <cDocumentNode, cIsDynamicDocumentArtifact>
{
public:
    typedef cDynamicListItemT
    <cDocumentNode, cIsDynamicDocumentArtifact> cIs;

    unsigned m_type;

    /**
     **********************************************************************
     * Constructor: cDocumentNode
     *
     *      Author: $author$
     *        Date: 10/17/2005
     **********************************************************************
     */
    cDocumentNode
    (unsigned type=e_TYPE_NONE, 
     bool is_dynamic=false) 
    : m_type(type)
    {
        m_is_dynamic = is_dynamic;
    }
    /**
     **********************************************************************
     * Function: AsDocumentNode
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual cDocumentNode& AsDocumentNode() 
    {
        cDocumentNode& node = *this;
        return node;
    }
    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int SetType(unsigned type)
    {
        return m_type = type;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
	virtual int GetType() const
    {
        return m_type;
    }
    /**
     **********************************************************************
     * Function: GetTypeName
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
	virtual const cCCharBuffer& GetTypeName() const;

    /**
     **********************************************************************
     * Function: GetNextAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetNextAttribute() const 
    {
        cDocumentNodeInterface* node = 0;
        cDocumentAttributeInterface* attribute = 0;

        if ((node = GetNextNode()))
        do
        {
            if ((attribute = node->GetAttributeInterface()))
                break;
        }
        while ((node = node->GetNextNode()));
        return attribute;
    }
    /**
     **********************************************************************
     * Function: GetPreviousAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetPreviousAttribute() const 
    {
        cDocumentNodeInterface* node = 0;
        cDocumentAttributeInterface* attribute = 0;

        if ((node = GetPreviousNode()))
        do
        {
            if ((attribute = node->GetAttributeInterface()))
                break;
        }
        while ((node = node->GetPreviousNode()));
        return attribute;
    }

    /**
     **********************************************************************
     * Function: GetNextNode
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* GetNextNode(int type=0) const 
    {
        cDocumentNode* node = cIs::GetNext();
        int node_type;

        if (node)
        if (0 < type)
        do
        {
            if (0 < (node_type = node->GetType()))
            if (type & node_type)
                return node;

            node = node->GetNext();
        }
        while (node);
        return node;
    }
    /**
     **********************************************************************
     * Function: GetPreviousNode
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* GetPreviousNode(int type=0) const 
    {
        cDocumentNode* node = cIs::GetPrevious();
        int node_type;

        if (node)
        if (0 < type)
        do
        {
            if (0 < (node_type = node->GetType()))
            if (type & node_type)
                return node;

            node = node->GetPrevious();
        }
        while(node);
        return node;
    }

    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 10/20/2005
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        eError error = e_ERROR_NOT_ALLOWED;
        int is_dynamic;

        if (0 < (is_dynamic = GetIsDynamic()))
        {
            delete this;
            error = e_ERROR_NONE;
        }
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceNode
 *
 * Author: $author$
 *   Date: 11/29/2005
 **********************************************************************
 */
class cDocumentReferenceNode
: public cDocumentNode
{
public:
    typedef cDocumentNode cIs;

    const cDocumentNodeInterface &m_node;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceNode
     *
     *      Author: $author$
     *        Date: 11/29/2005
     **********************************************************************
     */
    cDocumentReferenceNode
    (const cDocumentNodeInterface &node, 
     bool is_dynamic=false) 
    : cIs(e_TYPE_NONE, is_dynamic),
      m_node(node)
    {
    }
    /**
     **********************************************************************
     * Function: GetParentElement
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetParentElement() const
    {
        cDocumentElementInterface* element = m_node.GetParentElement();
        return element;
    }
    /**
     **********************************************************************
     * Function: GetNodeListInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* GetNodeListInterface() const
    {
        return m_node.GetNodeListInterface();
    }
    /**
     **********************************************************************
     * Function: GetAttributeListInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentAttributeListInterface* 
    GetAttributeListInterface() const 
    {
        return m_node.GetAttributeListInterface();
    }
    /**
     **********************************************************************
     * Function: DereferenceNodeInterface
     *
     *   Author: $author$
     *     Date: 12/15/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface& 
    DereferenceNodeInterface() const 
    {
        return m_node.DereferenceNodeInterface();
    }
    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int SetType(unsigned type)
    {
        type = -e_ERROR_NOT_ALLOWED;
        return type;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
	virtual int GetType() const
    {
        int type = m_node.GetType();
        return type;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceNamespaceNode
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceNamespaceNode
: virtual public cDocumentNamespaceNodeImplement,
  public cDocumentReferenceNode
{
public:
    typedef cDocumentReferenceNode cIs;

    const cDocumentNamespaceNodeInterface &m_namespace_node;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceNamespaceNode
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceNamespaceNode
    (const cDocumentNamespaceNodeInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_namespace_node(node) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceNamedNode
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceNamedNode
: virtual public cDocumentNamedNodeImplement,
  public cDocumentReferenceNamespaceNode
{
public:
    typedef cDocumentReferenceNamespaceNode cIs;

    const cDocumentNamedNodeInterface &m_named_node;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceNamedNode
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceNamedNode
    (const cDocumentNamedNodeInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_named_node(node)
    {
    }
    /**
     **********************************************************************
     * Function: GetNamedNodeInterface
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual cDocumentNamedNodeInterface* GetNamedNodeInterface() const 
    {
        return (cDocumentNamedNodeInterface*)this;
    }
    /**
     **********************************************************************
     * Function: GetNamespacePrefixCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual const cChar* GetNamespacePrefixCChars(int &length) const
    {
        const cChar* chars = m_named_node.GetNamespacePrefixCChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetNamespacePrefix
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetNamespacePrefix() const
    {
        return m_named_node.GetNamespacePrefix();
    }
    /**
     **********************************************************************
     * Function: GetNameCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual const cChar* GetNameCChars(int &length) const
    {
        const cChar* chars = m_named_node.GetNameCChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetName() const
    {
        return m_named_node.GetName();
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceTextNode
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceTextNode
: virtual public cDocumentTextNodeImplement,
  public cDocumentReferenceNamespaceNode
{
public:
    typedef cDocumentReferenceNamespaceNode cIs;

    const cDocumentTextNodeInterface &m_text_node;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceTextNode
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceTextNode
    (const cDocumentTextNodeInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_text_node(node) 
    {
    }
    /**
     **********************************************************************
     * Function: GetTextNodeInterface
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual cDocumentTextNodeInterface* GetTextNodeInterface() const 
    {
        return (cDocumentTextNodeInterface*)this;
    }
    /**
     **********************************************************************
     * Function: GetTextCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual const cChar* GetTextCChars(int &length) const 
    {
        const cChar* chars = m_text_node.GetTextCChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetText
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetText() const
    {
        return m_text_node.GetText();
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceText
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceText
: virtual public cDocumentTextImplement,
  public cDocumentReferenceTextNode
{
public:
    typedef cDocumentReferenceTextNode cIs;

    const cDocumentTextNodeInterface &m_text;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceText
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceText
    (const cDocumentTextNodeInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_text(node) 
    {
    }
    /**
     **********************************************************************
     * Function: GetTextInterface
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* GetTextInterface() const 
    {
        return (cDocumentTextInterface*)this;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceEndElement
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceEndElement
: virtual public cDocumentEndElementImplement,
  public cDocumentReferenceNamedNode
{
public:
    typedef cDocumentReferenceNamedNode cIs;

    const cDocumentEndElementInterface &m_end_element;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceEndElement
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceEndElement
    (const cDocumentEndElementInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_end_element(node) 
    {
    }
    /**
     **********************************************************************
     * Function: GetEndElementInterface
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentEndElementInterface* 
    GetEndElementInterface() const 
    {
        return (cDocumentEndElementInterface*)this;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceBeginElement
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceBeginElement
: virtual public cDocumentAttributeListImplement,
  virtual public cDocumentBeginElementImplement,
  public cDocumentReferenceEndElement
{
public:
    typedef cDocumentReferenceEndElement cIs;

    const cDocumentBeginElementInterface &m_begin_element;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceBeginElement
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceBeginElement
    (const cDocumentBeginElementInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_begin_element(node) 
    {
    }
    /**
     **********************************************************************
     * Function: GetBeginElementInterface
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentBeginElementInterface* 
    GetBeginElementInterface() const 
    {
        return (cDocumentBeginElementInterface*)this;
    }
    /**
     **********************************************************************
     * Function: GetFirstAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetFirstAttribute() const
    {
        return m_begin_element.GetFirstAttribute();
    }
    /**
     **********************************************************************
     * Function: GetLastAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetLastAttribute() const
    {
        return m_begin_element.GetLastAttribute();
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceElement
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceElement
: virtual public cDocumentNodeListImplement,
  virtual public cDocumentElementImplement,
  public cDocumentReferenceBeginElement
{
public:
    typedef cDocumentReferenceBeginElement cIs;

    const cDocumentElementInterface &m_element;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceElement
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceElement
    (const cDocumentElementInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_element(node)
    {
    }
    /**
     **********************************************************************
     * Function: GetElementInterface
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetElementInterface() const 
    {
        return (cDocumentElementInterface*)this;
    }
    /**
     **********************************************************************
     * Function: GetFirstNode
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* GetFirstNode(int type=0) const
    {
        return m_element.GetFirstNode(type);
    }
    /**
     **********************************************************************
     * Function: GetLastNode
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* GetLastNode(int type=0) const
    {
        return m_element.GetLastNode(type);
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceAttribute
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceAttribute
: virtual public cDocumentAttributeImplement,
  public cDocumentReferenceNamedNode
{
public:
    typedef cDocumentReferenceNamedNode cIs;

    const cDocumentAttributeInterface &m_attribute;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceAttribute
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceAttribute
    (const cDocumentAttributeInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_attribute(node) 
    {
    }
    /**
     **********************************************************************
     * Function: GetAttributeInterface
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetAttributeInterface() const 
    {
        return (cDocumentAttributeInterface*)this;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetValue() const 
    {
        return m_attribute.GetValue();
    }
    /**
     **********************************************************************
     * Function: GetValueCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual const cChar* GetValueCChars(int &length) const
    {
        const cChar* chars = m_attribute.GetValueCChars(length);
        return chars;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNamespaceNode
 *
 * Author: $author$
 *   Date: 10/13/2005
 **********************************************************************
 */
class cDocumentNamespaceNode
: virtual public cDocumentNamespaceNodeImplement,
  public cDocumentNode
{
public:
    typedef cDocumentNode cIs;

    cDocumentNamespaceInterface* m_ns;

    /**
     **********************************************************************
     * Constructor: cDocumentNamespaceNode
     *
     *      Author: $author$
     *        Date: 10/13/2005
     **********************************************************************
     */
    cDocumentNamespaceNode
    (unsigned type=e_TYPE_NONE,
     cDocumentNamespaceInterface* ns=0) 
    : cIs(type),
      m_ns(ns)
    {
    }
    /**
     **********************************************************************
     * Function: SetNamespace
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError SetNamespace
    (cDocumentNamespaceInterface* ns) 
    {
        eError error = e_ERROR_NONE;
        m_ns = ns;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface& GetNamespace() const
    {
        if (m_ns)
            return *m_ns;

        return cDocumentNamespaceInterface::GetGlobalNamespace();
    }
    /**
     **********************************************************************
     * Function: GetHasNamespace
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual bool GetHasNamespace() const 
    {
        return (m_ns != 0);
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNamedNode
 *
 * Author: $author$
 *   Date: 10/13/2005
 **********************************************************************
 */
class cDocumentNamedNode
: virtual public cDocumentNamedNodeImplement,
  public cDocumentNamespaceNode
{
public:
    typedef cDocumentNamespaceNode cIs;

    cCCharBuffer m_namespace_prefix;
    cCCharBuffer m_name;

    /**
     **********************************************************************
     * Constructor: cDocumentNamedNode
     *
     *      Author: $author$
     *        Date: 10/13/2005
     **********************************************************************
     */
    cDocumentNamedNode
    (unsigned type=e_TYPE_NONE, const cChar* chars=0, int length=-1,
     const cChar* prefix_chars=0, int prefix_length=-1) 
    : cIs(type)
    {
        eError error;

        if (chars)
        if (0 > (length = SetNameCChars(chars, length)))
            throw(error = -length);

        if (prefix_chars)
        if (0 > (prefix_length = SetNamespacePrefixCChars
            (prefix_chars, prefix_length)))
            throw(error = -prefix_length);
    }
    /**
     **********************************************************************
     * Constructor: cDocumentNamedNode
     *
     *      Author: $author$
     *        Date: 10/13/2005
     **********************************************************************
     */
    cDocumentNamedNode
    (unsigned type, const char* chars, int length=-1,
     const char* prefix_chars=0, int prefix_length=-1) 
    : cIs(type)
    {
        eError error;

        if (chars)
        if (0 > (length = SetNameChars(chars, length)))
            throw(error = -length);

        if (prefix_chars)
        if (0 > (prefix_length = SetNamespacePrefixChars
            (prefix_chars, prefix_length)))
            throw(error = -prefix_length);
    }

    /**
     **********************************************************************
     * Function: GetNamedNodeInterface
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual cDocumentNamedNodeInterface* 
    GetNamedNodeInterface() const 
    {
        return (cDocumentNamedNodeInterface*)this;
    }

    /**
     **********************************************************************
     * Function: SetNamespacePrefixChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetNamespacePrefixChars
    (const char* chars, int length=-1) 
    {
        length = m_namespace_prefix.Copyc(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: SetNamespacePrefixCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetNamespacePrefixCChars
    (const cChar* chars, int length=-1) 
    {
        length = m_namespace_prefix.Copy(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetNamespacePrefixCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual const cChar* GetNamespacePrefixCChars(int &length) const
    {
        const cChar* chars = m_namespace_prefix.GetBuffer(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetNameChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetNameChars
    (const char* chars, int length=-1) 
    {
        length = m_name.Copyc(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: SetNameCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetNameCChars
    (const cChar* chars, int length=-1) 
    {
        length = m_name.Copy(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetNameCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual const cChar* GetNameCChars(int &length) const 
    {
        const cChar* chars = m_name.GetBuffer(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: GetNamespacePrefix
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetNamespacePrefix() const 
    {
        return m_namespace_prefix;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetName() const 
    {
        return m_name;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentTextNode
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class cDocumentTextNode
: virtual public cDocumentNodeFactoryArtifactImplement,
  virtual public cDocumentTextNodeImplement,
  public cDocumentNamespaceNode
{
public:
    typedef cDocumentNamespaceNode cIs;

    cCCharBuffer m_text;

    cDocumentNodeFactoryInterface& m_node_factory;

    /**
     **********************************************************************
     * Constructor: cDocumentTextNode
     *
     *      Author: $author$
     *        Date: 10/17/2005
     **********************************************************************
     */
    cDocumentTextNode
    (cDocumentNodeFactoryInterface& node_factory,
     const char* chars=0, int length=-1, 
     unsigned type=e_TYPE_NONE) 
    : cIs(type),
      m_node_factory(node_factory)
    {
        eError error;

        if (chars)
        if (0 > (length = SetTextChars(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cDocumentTextNode
     *
     *      Author: $author$
     *        Date: 10/17/2005
     **********************************************************************
     */
    cDocumentTextNode
    (cDocumentNodeFactoryInterface& node_factory,
     const cChar* chars, int length=-1, 
     unsigned type=e_TYPE_NONE) 
    : cIs(type),
      m_node_factory(node_factory)
    {
        eError error;

        if (chars)
        if (0 > (length = SetTextCChars(chars, length)))
            throw(error = -length);
    }

    /**
     **********************************************************************
     * Function: GetTextNodeInterface
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual cDocumentTextNodeInterface* GetTextNodeInterface() const 
    {
        return (cDocumentTextNodeInterface*)this;
    }

    /**
     **********************************************************************
     * Function: SetTextChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetTextChars
    (const char* chars, int length=-1) 
    {
        length = m_text.Copyc(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: SetTextCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetTextCChars
    (const cChar* chars, int length=-1) 
    {
        length = m_text.Copy(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetTextCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual const cChar* GetTextCChars(int &length) const 
    {
        const cChar* chars = m_text.GetBuffer(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetText
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetText() const 
    {
        return m_text;
    }
    /**
     **********************************************************************
     * Function: GetNodeFactory
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual cDocumentNodeFactoryInterface& GetNodeFactory() const 
    {
        return m_node_factory;
    }
};

#endif /* _CDOCUMENTNODE_HXX */
