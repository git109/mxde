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
 *   File: cdominterface.hxx
 *
 * Author: $author$
 *   Date: 12/2/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOMINTERFACE_HXX
#define _CDOMINTERFACE_HXX

#include "cstring.hxx"
#include "cinterface.hxx"

class c_INTERFACE_CLASS cDOMNamespaceInterface;
class c_INTERFACE_CLASS cDOMNodeInterface;
class c_INTERFACE_CLASS cDOMNamespaceNodeInterface;
class c_INTERFACE_CLASS cDOMNamedNodeInterface;
class c_INTERFACE_CLASS cDOMNodeFactoryInterface;
class c_INTERFACE_CLASS cDOMNodeListInterface;
class c_INTERFACE_CLASS cDOMCharacterDataInterface;
class c_INTERFACE_CLASS cDOMTextInterface;
class c_INTERFACE_CLASS cDOMAttrInterface;
class c_INTERFACE_CLASS cDOMElementInterface;
class c_INTERFACE_CLASS cDOMDocumentInterface;

class cDOMNamespace;
class cDOMNode;
class cDOMNamespaceNode;
class cDOMNamedNode;
class cDOMNodeFactory;
class cDOMNodeList;
class cDOMCharacterData;
class cDOMText;
class cDOMAttr;
class cDOMElement;
class cDOMDocument;

/**
 **********************************************************************
 *  Class: cDOMEventInterface
 *
 * Author: $author$
 *   Date: 12/5/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMEventInterface
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
    (cDOMElementInterface& element) = 0;
    /**
     **********************************************************************
     * Function: OnEndElement
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError OnEndElement
    (cDOMElementInterface& element) = 0;

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
     cDOMElementInterface& element) = 0;
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
     cDOMElementInterface& element) = 0;

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
     cDOMAttrInterface &attr) = 0;
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
     cDOMAttrInterface &attr) = 0;

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
     cDOMTextInterface& text) = 0;
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
     cDOMTextInterface& text) = 0;
};

/**
 **********************************************************************
 *  Class: cDOMNodeFactoryInterface
 *
 * Author: $author$
 *   Date: 12/1/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMNodeFactoryInterface
{
public:
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual cDOMNamespaceInterface* GetNamespace
    (const cStringInterface& namespace_uri) = 0;
    /**
     **********************************************************************
     * Function: CreateNamespace
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual cDOMNamespaceInterface* CreateNamespace
    (const cStringInterface& namespace_uri) = 0;
    /**
     **********************************************************************
     * Function: DestroyNamespace
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual eError DestroyNamespace
    (cDOMNamespaceInterface& p_namespace) = 0;
    /**
     **********************************************************************
     * Function: DestroyNode
     *
     *   Author: $author$
     *     Date: 12/1/2004
     **********************************************************************
     */
    virtual eError DestroyNode
    (cDOMNodeInterface& node) = 0;
    /**
     **********************************************************************
     * Function: CreateText
     *
     *   Author: $author$
     *     Date: 12/18/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* CreateText
    (cDOMElementInterface* parent=0) = 0;
    /**
     **********************************************************************
     * Function: CreateAttribute
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* CreateAttribute
    (cDOMElementInterface& parent) = 0;
    /**
     **********************************************************************
     * Function: CreateElement
     *
     *   Author: $author$
     *     Date: 12/1/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* CreateElement
    (cDOMElementInterface* parent=0) = 0;
    /**
     **********************************************************************
     * Function: CreateDocument
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual cDOMDocumentInterface* CreateDocument() = 0;
};

/**
 **********************************************************************
 *  Class: cDOMNodeListInterface
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMNodeListInterface
: virtual public cInterfaceBase
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
    (cDOMElementInterface& element) = 0;
    /**
     **********************************************************************
     * Function: RemoveElement
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError RemoveElement
    (cDOMElementInterface& element) = 0;

    /**
     **********************************************************************
     * Function: AppendText
     *
     *   Author: $author$
     *     Date: 12/18/2004
     **********************************************************************
     */
    virtual eError AppendText
    (cDOMTextInterface& text) = 0;
    /**
     **********************************************************************
     * Function: RemoveText
     *
     *   Author: $author$
     *     Date: 12/18/2004
     **********************************************************************
     */
    virtual eError RemoveText
    (cDOMTextInterface& text) = 0;

    /**
     **********************************************************************
     * Function: AppendChild
     *
     *   Author: $author$
     *     Date: 12/3/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface& AppendChild
    (cDOMNodeInterface& child) = 0;
    /**
     **********************************************************************
     * Function: RemoveChild
     *
     *   Author: $author$
     *     Date: 12/3/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface& RemoveChild
    (cDOMNodeInterface& child) = 0;

    /**
     **********************************************************************
     * Function: GetFirstChild
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface* GetFirstChild() const = 0;
    /**
     **********************************************************************
     * Function: GetLastChild
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface* GetLastChild() const = 0;

    /**
     **********************************************************************
     * Function: GetFirstText
     *
     *   Author: $author$
     *     Date: 12/20/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* GetFirstText() const = 0;
    /**
     **********************************************************************
     * Function: GetLastText
     *
     *   Author: $author$
     *     Date: 12/20/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* GetLastText() const = 0;

    /**
     **********************************************************************
     * Function: GetFirstElement
     *
     *   Author: $author$
     *     Date: 12/3/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetFirstElement() const = 0;
    /**
     **********************************************************************
     * Function: GetLastElement
     *
     *   Author: $author$
     *     Date: 12/3/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetLastElement() const = 0;

    /**
     **********************************************************************
     * Function: GetFirstAttribute
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* GetFirstAttribute() const = 0;
    /**
     **********************************************************************
     * Function: GetLastAttribute
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* GetLastAttribute() const = 0;
};

/**
 **********************************************************************
 *  Class: cDOMNodeCreatorInterface
 *
 * Author: $author$
 *   Date: 12/7/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMNodeCreatorInterface
: virtual public cInterfaceBase
{
public:
    /**
     **********************************************************************
     * Function: GetFactory
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual cDOMNodeFactoryInterface& GetFactory() = 0;
};

/**
 **********************************************************************
 *  Class: cDOMNodeInterface
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMNodeInterface
: virtual public cDOMNodeListInterface
{
public:
    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 11/26/2004
     **********************************************************************
     */
    enum
    {
        e_FIRST_TYPE,

        e_TYPE_NONE = e_FIRST_TYPE,

        e_TYPE_PROCESSING_INSTRUCTION_NODE,
        e_TYPE_ENTITY_NODE,
        e_TYPE_ENTITY_REFERENCE_NODE,
        e_TYPE_CDATA_SECTION_NODE,

        e_TYPE_COMMENT_NODE,
        e_TYPE_TEXT_NODE,
        e_TYPE_ELEMENT_NODE,
        e_TYPE_ATTRIBUTE_NODE,
        e_TYPE_DOCUMENT_NODE,

        e_TYPE_DOCUMENT_FRAGMENT_NODE,
        e_TYPE_DOCUMENT_TYPE_NODE,
        e_TYPE_NOTATION_NODE,

        e_NEXT_TYPE,
        e_LAST_TYPE=e_NEXT_TYPE-1
    };

    /**
     **********************************************************************
     * Function: GetNodeType
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual int GetNodeType() const = 0;

    /**
     **********************************************************************
     * Function: GetNextSibling
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface* GetNextSibling() const = 0;
    /**
     **********************************************************************
     * Function: GetPreviousSibling
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface* GetPreviousSibling() const = 0;

    /**
     **********************************************************************
     * Function: GetNextText
     *
     *   Author: $author$
     *     Date: 12/20/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* GetNextText() const = 0;
    /**
     **********************************************************************
     * Function: GetPreviousText
     *
     *   Author: $author$
     *     Date: 12/20/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* GetPreviousText() const = 0;

    /**
     **********************************************************************
     * Function: GetNextElement
     *
     *   Author: $author$
     *     Date: 12/19/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetNextElement() const = 0;
    /**
     **********************************************************************
     * Function: GetPreviousElement
     *
     *   Author: $author$
     *     Date: 12/19/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetPreviousElement() const = 0;

    /**
     **********************************************************************
     * Function: GetNextAttribute
     *
     *   Author: $author$
     *     Date: 12/23/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* GetNextAttribute() const = 0;
    /**
     **********************************************************************
     * Function: GetPreviousAttribute
     *
     *   Author: $author$
     *     Date: 12/23/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* GetPreviousAttribute() const = 0;

    /**
     **********************************************************************
     * Function: GetParentElement
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetParentElement() const = 0;

    /**
     **********************************************************************
     * Function: GetNamespaceNode
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual cDOMNamespaceNodeInterface* GetNamespaceNode() const = 0;
    /**
     **********************************************************************
     * Function: GetNamedNode
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual cDOMNamedNodeInterface* GetNamedNode() const = 0;

    /**
     **********************************************************************
     * Function: GetCharacterDataNode
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMCharacterDataInterface* GetCharacterDataNode() const = 0;
    /**
     **********************************************************************
     * Function: GetTextNode
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* GetTextNode() const = 0;
    /**
     **********************************************************************
     * Function: GetAttrNode
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMAttrInterface* GetAttrNode() const = 0;
    /**
     **********************************************************************
     * Function: GetElementNode
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetElementNode() const = 0;
    /**
     **********************************************************************
     * Function: GetDocumentNode
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMDocumentInterface* GetDocumentNode() const = 0;

    /**
     **********************************************************************
     * Function: GetDOMNode
     *
     *   Author: $author$
     *     Date: 12/2/2004
     **********************************************************************
     */
    virtual cDOMNode& GetDOMNode() = 0;
};

/**
 **********************************************************************
 *  Class: cDOMNamespaceInterface
 *
 * Author: $author$
 *   Date: 12/6/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMNamespaceInterface
{
public:
    /**
     **********************************************************************
     * Function: GetGlobalNamespace
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    static cDOMNamespaceInterface& GetGlobalNamespace();
    /**
     **********************************************************************
     * Function: GetGlobalNamespaceURI
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    static const cStringInterface& GetGlobalNamespaceURI();
    /**
     **********************************************************************
     * Function: GetNamespaceURI
     *
     *   Author: $author$
     *     Date: 12/2/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetNamespaceURI() const = 0;
    /**
     **********************************************************************
     * Function: GetDOMNamespace
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual cDOMNamespace& GetDOMNamespace() = 0;
};

/**
 **********************************************************************
 *  Class: cDOMNamespaceNodeInterface
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMNamespaceNodeInterface
: virtual public cDOMNodeInterface,
  virtual public cDOMNamespaceInterface
{
public:
    /**
     **********************************************************************
     * Function: SetHasNamespace
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual int SetHasNamespace(bool has=true) = 0;
    /**
     **********************************************************************
     * Function: GetHasNamespace
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual bool GetHasNamespace() = 0;
    /**
     **********************************************************************
     * Function: SetNamespace
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError SetNamespace
    (cDOMNamespaceInterface* p_namespace) = 0;
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual cDOMNamespaceInterface& GetNamespace() const = 0;
    /**
     **********************************************************************
     * Function: SetNamespaceURI
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual eError SetNamespaceURI
    (const cStringInterface* namespace_uri) = 0;
    /**
     **********************************************************************
     * Function: GetDOMNamespaceNode
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual cDOMNamespaceNode& GetDOMNamespaceNode() = 0;
};

/**
 **********************************************************************
 *  Class: cDOMNamedNodeInterface
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMNamedNodeInterface
: virtual public cDOMNamespaceNodeInterface
{
public:
    /**
     **********************************************************************
     * Function: SetPrefix
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual int SetPrefix
    (const char *text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetPrefix
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetPrefix() const = 0;
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual int SetName
    (const char *text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetName() const = 0;
    /**
     **********************************************************************
     * Function: GetDOMNamedNode
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual cDOMNamedNode& GetDOMNamedNode() = 0;
};

/**
 **********************************************************************
 *  Class: cDOMCharacterDataInterface
 *
 * Author: $author$
 *   Date: 12/16/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMCharacterDataInterface
: virtual public cDOMNamespaceNodeInterface
{
public:
    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 12/17/2004
     **********************************************************************
     */
    virtual int SetChars
    (const char *chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: SetData
     *
     *   Author: $author$
     *     Date: 12/16/2004
     **********************************************************************
     */
    virtual eError SetData
    (const cStringInterface& data) = 0;
    /**
     **********************************************************************
     * Function: GetData
     *
     *   Author: $author$
     *     Date: 12/16/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetData() const = 0;
};

/**
 **********************************************************************
 *  Class: cDOMTextInterface
 *
 * Author: $author$
 *   Date: 12/16/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMTextInterface
: virtual public cDOMCharacterDataInterface
{
public:
};

/**
 **********************************************************************
 *  Class: cDOMAttrInterface
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMAttrInterface
: virtual public cDOMNamedNodeInterface
{
public:
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual int SetValue
    (const char *text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetValue() const = 0;
    /**
     **********************************************************************
     * Function: SetIsXmlns
     *
     *   Author: $author$
     *     Date: 12/23/2004
     **********************************************************************
     */
    virtual int SetIsXmlns(bool is=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsXmlns
     *
     *   Author: $author$
     *     Date: 12/23/2004
     **********************************************************************
     */
    virtual bool GetIsXmlns() const = 0;
    /**
     **********************************************************************
     * Function: GetDOMAttr
     *
     *   Author: $author$
     *     Date: 12/2/2004
     **********************************************************************
     */
    virtual cDOMAttr& GetDOMAttr() = 0;
};

/**
 **********************************************************************
 *  Class: cDOMElementInterface
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMElementInterface
: virtual public cDOMNodeCreatorInterface,
  virtual public cDOMNamedNodeInterface
{
public:
    /**
     **********************************************************************
     * Function: AppendAttribute
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual eError AppendAttribute
    (cDOMAttrInterface& attr) = 0;
    /**
     **********************************************************************
     * Function: RemoveAttribute
     *
     *   Author: $author$
     *     Date: 12/4/2004
     **********************************************************************
     */
    virtual eError RemoveAttribute
    (cDOMAttrInterface& attr) = 0;

    /**
     **********************************************************************
     * Function: GetAttribute
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual const cStringInterface* GetAttribute
    (const cStringInterface &name) const = 0;
    /**
     **********************************************************************
     * Function: GetDOMElement
     *
     *   Author: $author$
     *     Date: 12/2/2004
     **********************************************************************
     */
    virtual cDOMElement& GetDOMElement() = 0;
};

/**
 **********************************************************************
 *  Class: cDOMDocumentInterface
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMDocumentInterface
: virtual public cDOMNodeCreatorInterface,
  virtual public cDOMNodeInterface
{
public:
    /**
     **********************************************************************
     * Function: GetDocumentElement
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMElementInterface* GetDocumentElement() const = 0;
    /**
     **********************************************************************
     * Function: GetDOMDocument
     *
     *   Author: $author$
     *     Date: 12/2/2004
     **********************************************************************
     */
    virtual cDOMDocument& GetDOMDocument() = 0;
};

#endif /* _CDOMINTERFACE_HXX */