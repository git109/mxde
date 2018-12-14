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
 *   Date: 11/26/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOMINTERFACE_HXX
#define _CDOMINTERFACE_HXX

#include "cstring.hxx"
#include "cinterface.hxx"

class c_INTERFACE_CLASS cDOMNodeInterface;
class c_INTERFACE_CLASS cDOMCharacterDataInterface;
class c_INTERFACE_CLASS cDOMTextInterface;
class c_INTERFACE_CLASS cDOMAttrInterface;
class c_INTERFACE_CLASS cDOMElementInterface;
class c_INTERFACE_CLASS cDOMDocumentInterface;

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
     * Function: GetFirstChild
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface* GetFirstChild() = 0;
    /**
     **********************************************************************
     * Function: GetLastChild
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMNodeInterface* GetLastChild() = 0;
};

/**
 **********************************************************************
 *  Class: cDOMNodeListImplement
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class cDOMNodeListImplement
: virtual public cDOMNodeListInterface
{
public:
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
};

/**
 **********************************************************************
 *  Class: cDOMNodeImplement
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class cDOMNodeImplement
: virtual public cDOMNodeInterface,
  virtual public cDOMNodeListImplement
{
public:
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
        cDOMNodeInterface* sibling = 0;
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
        cDOMNodeInterface* sibling = 0;
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

/**
 **********************************************************************
 *  Class: cDOMCharacterDataInterface
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMCharacterDataInterface
: virtual public cDOMNodeInterface
{
public:
    /**
     **********************************************************************
     * Function: GetData
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual const cStringInterface* GetData() = 0;
};

/**
 **********************************************************************
 *  Class: cDOMCharacterDataImplement
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class cDOMCharacterDataImplement
: virtual public cDOMCharacterDataInterface
{
public:
    /**
     **********************************************************************
     * Function: GetData
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual const cStringInterface* GetData() 
    {
        const cStringInterface* data = 0;
        return data;
    }
};

/**
 **********************************************************************
 *  Class: cDOMTextInterface
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMTextInterface
: virtual public cDOMCharacterDataInterface
{
public:
    /**
     **********************************************************************
     * Function: SplitText
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* SplitText(int offset) = 0;
};

/**
 **********************************************************************
 *  Class: cDOMTextImplement
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class cDOMTextImplement
: virtual public cDOMTextInterface
{
public:
    /**
     **********************************************************************
     * Function: SplitText
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual cDOMTextInterface* SplitText(int offset) 
    {
        cDOMTextInterface* text = 0;
        return text;
    }
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
: virtual public cDOMNodeInterface
{
public:
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
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetName() const = 0;
    /**
     **********************************************************************
     * Function: GetNamespaceURI
     *
     *   Author: $author$
     *     Date: 12/2/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetNamespaceURI() const = 0;
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
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 11/26/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetValue() const = 0;
};

/**
 **********************************************************************
 *  Class: cDOMAttrImplement
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class cDOMAttrImplement
: virtual public cDOMAttrInterface
{
public:
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
: virtual public cDOMNamedNodeInterface
{
public:
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
};

/**
 **********************************************************************
 *  Class: cDOMElementImplement
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class cDOMElementImplement
: virtual public cDOMElementInterface
{
public:
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
        return value;
    }
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
: virtual public cDOMNodeInterface
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
    virtual cDOMElementInterface* GetDocumentElement() = 0;
};

/**
 **********************************************************************
 *  Class: cDOMDocumentImplement
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class cDOMDocumentImplement
: virtual public cDOMDocumentInterface
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
    virtual cDOMElementInterface* GetDocumentElement() 
    {
        cDOMElementInterface* element = 0;
        return element;
    }
};

/**
 **********************************************************************
 *  Class: cDOMInterface
 *
 * Author: $author$
 *   Date: 11/26/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMInterface
: virtual public cInterfaceBase
{
public:
};

#endif /* ndef _CDOMINTERFACE_HXX */
