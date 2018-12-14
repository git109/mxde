/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: cdocumentartifactinterface.hxx
 *
 * Author: $author$
 *   Date: 4/6/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTARTIFACTINTERFACE_HXX
#define _CDOCUMENTARTIFACTINTERFACE_HXX

#include "cinterface.hxx"
#include "cbytebuffer.hxx"
#include "ccharbuffer.hxx"
#include "cccharbuffer.hxx"
#include "cchar.hxx"

class c_INTERFACE_CLASS cDocumentNodeInterface;
class c_INTERFACE_CLASS cDocumentNodeListInterface;
class c_INTERFACE_CLASS cDocumentNamespaceInterface;
class c_INTERFACE_CLASS cDocumentNamespaceNodeInterface;
class c_INTERFACE_CLASS cDocumentNamedNodeInterface;
class c_INTERFACE_CLASS cDocumentTextNodeInterface;
class c_INTERFACE_CLASS cDocumentDataNodeInterface;
class c_INTERFACE_CLASS cDocumentEntityReferenceInterface;
class c_INTERFACE_CLASS cDocumentAttributeInterface;
class c_INTERFACE_CLASS cDocumentAttributeListInterface;
class c_INTERFACE_CLASS cDocumentElementInterface;
class c_INTERFACE_CLASS cDocumentBeginElementInterface;
class c_INTERFACE_CLASS cDocumentEndElementInterface;
class c_INTERFACE_CLASS cDocumentCommentInterface;
class c_INTERFACE_CLASS cDocumentTextInterface;
class c_INTERFACE_CLASS cDocumentDataInterface;
class c_INTERFACE_CLASS cDocumentInterface;
class c_INTERFACE_CLASS cDocumentParserInterface;
class c_INTERFACE_CLASS cDocumentEventInterface;
class c_INTERFACE_CLASS cDocumentFactoryInterface;
class c_INTERFACE_CLASS cDocumentNodeFactoryInterface;

class cDocumentNode;
class cDocumentNamedNode;
class cDocumentNamespaceNode;
class cDocumentTextNode;
class cDocumentEntityReference;
class cDocumentAttribute;
class cDocumentElement;
class cDocumentComment;
class cDocumentText;
class cDocument;
class cDocumentFactory;
class cDocumentNodeFactory;

/**
 **********************************************************************
 *  Class: cDocumentArtifactInterface
 *
 * Author: $author$
 *   Date: 4/6/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentArtifactInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: SetParentDocument
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual eError SetParentDocument(cDocumentInterface *document) = 0;
    /**
     **********************************************************************
     * Function: GetParentDocument
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentInterface *GetParentDocument() const = 0;

    /**
     **********************************************************************
     * Function: SetParentElement
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual eError SetParentElement(cDocumentElementInterface *element) = 0;
    /**
     **********************************************************************
     * Function: GetParentElement
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface *GetParentElement() const = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentNodeFactoryArtifactInterface
 *
 * Author: $author$
 *   Date: 11/23/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentNodeFactoryArtifactInterface
: virtual public cDocumentArtifactInterface
{
public:
    /**
     **********************************************************************
     * Function: GetNodeFactory
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual cDocumentNodeFactoryInterface& GetNodeFactory() const = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentEventArtifactInterface
 *
 * Author: $author$
 *   Date: 11/24/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentEventArtifactInterface
: virtual public cDocumentNodeFactoryArtifactInterface
{
public:
    /**
     **********************************************************************
     * Function: GetEvent
     *
     *   Author: $author$
     *     Date: 11/24/2005
     **********************************************************************
     */
    virtual cDocumentEventInterface& GetEvent() const = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentNodeInterface
 *
 * Author: $author$
 *   Date: 10/8/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentNodeInterface
: virtual public cDocumentNodeFactoryArtifactInterface
{
public:
    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 10/8/2005
     **********************************************************************
     */
    enum
    {
        e_TYPE_NONE                   = 0x0,
        e_TYPE_TEXT                   = 0x1,
        e_TYPE_COMMENT                = 0x2,
        e_TYPE_ATTRIBUTE              = 0x4,
        e_TYPE_ELEMENT                = 0x8,
        e_TYPE_BEGIN_ELEMENT          = 0x10,
        e_TYPE_END_ELEMENT            = 0x20,
        e_TYPE_DATA                   = 0x40,

        e_TYPE_DOCUMENT               = 0x80,
        e_TYPE_DOCUMENT_FRAGMENT      = 0x100,
        e_TYPE_DOCUMENT_TYPE          = 0x200,

        e_TYPE_CDATA                  = 0x400,
        e_TYPE_NOTATION               = 0x800,
        e_TYPE_ENTITY                 = 0x1000,
        e_TYPE_ENTITY_REFERENCE       = 0x2000,
        e_TYPE_PROCESSING_INSTRUCTION = 0x4000
    };

    /**
     **********************************************************************
     * Function: GetNodeListInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* GetNodeListInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetAttributeListInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentAttributeListInterface* 
    GetAttributeListInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetDocumentInterface
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentInterface* GetDocumentInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetAttributeInterface
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetAttributeInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetElementInterface
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetElementInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetBeginElementInterface
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentBeginElementInterface* 
    GetBeginElementInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetEndElementInterface
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentEndElementInterface* 
    GetEndElementInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetCommentInterface
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentCommentInterface* GetCommentInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetEntityReferenceInterface
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual cDocumentEntityReferenceInterface* 
    GetEntityReferenceInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetDataInterface
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataInterface* GetDataInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetDataNodeInterface
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataNodeInterface* GetDataNodeInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetTextInterface
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* GetTextInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetNamedNodeInterface
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual cDocumentNamedNodeInterface* GetNamedNodeInterface() const = 0;
    /**
     **********************************************************************
     * Function: GetTextNodeInterface
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual cDocumentTextNodeInterface* GetTextNodeInterface() const = 0;
    /**
     **********************************************************************
     * Function: DereferenceNodeInterface
     *
     *   Author: $author$
     *     Date: 12/15/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface& 
    DereferenceNodeInterface() const = 0;

    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual int SetType(unsigned type) = 0;
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
	virtual int GetType() const = 0;
    /**
     **********************************************************************
     * Function: GetTypeName
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
	virtual const cCCharBuffer& GetTypeName() const = 0;

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual int Compare
    (const cDocumentNodeInterface& node) const = 0;

    /**
     **********************************************************************
     * Function: GetNextAttributeByName
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* 
    GetNextAttributeByName(const cCCharBuffer& name) const = 0;
    /**
     **********************************************************************
     * Function: GetNextAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetNextAttribute() const = 0;
    /**
     **********************************************************************
     * Function: GetPreviousAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetPreviousAttribute() const = 0;

    /**
     **********************************************************************
     * Function: GetNextElementByName
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* 
    GetNextElementByName(const cCCharBuffer& name) const = 0;
    /**
     **********************************************************************
     * Function: GetNextElement
     *
     *   Author: $author$
     *     Date: 11/9/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetNextElement() const = 0;
    /**
     **********************************************************************
     * Function: GetPreviousElement
     *
     *   Author: $author$
     *     Date: 11/9/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetPreviousElement() const = 0;

    /**
     **********************************************************************
     * Function: GetNextText
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentTextInterface* GetNextText() const = 0;
    /**
     **********************************************************************
     * Function: GetPreviousText
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentTextInterface* GetPreviousText() const = 0;

    /**
     **********************************************************************
     * Function: GetNextNode
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* GetNextNode(int type=0) const = 0;
    /**
     **********************************************************************
     * Function: GetPreviousNode
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* GetPreviousNode(int type=0) const = 0;

    /**
     **********************************************************************
     * Function: AsDocumentNode
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual cDocumentNode& AsDocumentNode() = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentAttributeListInterface
 *
 * Author: $author$
 *   Date: 12/12/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentAttributeListInterface
: virtual public cDocumentNodeFactoryArtifactInterface
{
public:
    /**
     **********************************************************************
     * Function: AddAttribute
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* AddAttribute
    (eError &error, const cCCharBuffer* name,
     const cCCharBuffer* value=0, 
     const cCCharBuffer* prefix=0) = 0;
    /**
     **********************************************************************
     * Function: AddAttribute
     *
     *   Author: $author$
     *     Date: 12/2/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* AddAttribute
    (eError &error, const char* name, int namelen=-1,
     const char* value=0, int valuelen=-1,
     const char* prefix=0, int prefixlen=-1) = 0;
    /**
     **********************************************************************
     * Function: AddAttribute
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual eError AddAttribute
    (cDocumentAttributeInterface& node) = 0;
    /**
     **********************************************************************
     * Function: GetFirstAttributeByName
     *
     *   Author: $author$
     *     Date: 12/22/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* 
    GetFirstAttributeByName(const cCCharBuffer& name) const = 0;
    /**
     **********************************************************************
     * Function: GetFirstAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetFirstAttribute() const = 0;
    /**
     **********************************************************************
     * Function: GetLastAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetLastAttribute() const = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentNodeListInterface
 *
 * Author: $author$
 *   Date: 10/10/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentNodeListInterface
: virtual public cDocumentAttributeListInterface
{
public:
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual int Compare
    (const cDocumentNodeListInterface& node_list) const = 0;
    /**
     **********************************************************************
     * Function: AddReferenceNodeList
     *
     *   Author: $author$
     *     Date: 12/15/2005
     **********************************************************************
     */
    virtual int AddReferenceNodeList
    (const cDocumentNodeListInterface& node_list) = 0;
    /**
     **********************************************************************
     * Function: AddReferenceNode
     *
     *   Author: $author$
     *     Date: 12/15/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* AddReferenceNode
    (eError &error, cDocumentNodeInterface& node) = 0;
    /**
     **********************************************************************
     * Function: AddData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataInterface* AddData
    (eError &error, const cBYTEBuffer& data, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: AddData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataInterface* AddData
    (eError &error, const BYTE* data, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: AddText
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* AddText
    (eError &error, const cCCharBuffer& text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: AddText
     *
     *   Author: $author$
     *     Date: 12/2/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* AddText
    (eError &error, const cChar* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: AddText
     *
     *   Author: $author$
     *     Date: 12/2/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* AddText
    (eError &error, const char* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: AddComment
     *
     *   Author: $author$
     *     Date: 12/2/2005
     **********************************************************************
     */
    virtual cDocumentCommentInterface* AddComment
    (eError &error, const char* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: AddComment
     *
     *   Author: $author$
     *     Date: 1/2/2006
     **********************************************************************
     */
    virtual cDocumentCommentInterface* AddComment
    (eError &error, const cCCharBuffer* text) = 0;
    /**
     **********************************************************************
     * Function: AddEntityReference
     *
     *   Author: $author$
     *     Date: 12/2/2005
     **********************************************************************
     */
    virtual cDocumentEntityReferenceInterface* AddEntityReference
    (eError &error, const char* chars, int length=-1) = 0;

    /**
     **********************************************************************
     * Function: AddBeginElement
     *
     *   Author: $author$
     *     Date: 12/2/2005
     **********************************************************************
     */
    virtual cDocumentBeginElementInterface* AddBeginElement
    (eError &error, const cCCharBuffer* name, 
     const cCCharBuffer* prefix=0) = 0;
    /**
     **********************************************************************
     * Function: AddEndElement
     *
     *   Author: $author$
     *     Date: 12/2/2005
     **********************************************************************
     */
    virtual cDocumentEndElementInterface* AddEndElement
    (eError &error, const cCCharBuffer* name, 
     const cCCharBuffer* prefix=0) = 0;
    /**
     **********************************************************************
     * Function: AddElement
     *
     *   Author: $author$
     *     Date: 12/2/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* AddElement
    (eError &error, const cCCharBuffer* name, 
     const cCCharBuffer* prefix=0) = 0;
    /**
     **********************************************************************
     * Function: AddElement
     *
     *   Author: $author$
     *     Date: 12/2/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* AddElement
    (eError &error, const cChar* name, int namelen=-1,
     const cChar* prefix=0, int prefixlen=-1) = 0;
    /**
     **********************************************************************
     * Function: AddElement
     *
     *   Author: $author$
     *     Date: 12/2/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* AddElement
    (eError &error, const char* name, int namelen=-1,
     const char* prefix=0, int prefixlen=-1) = 0;

    /**
     **********************************************************************
     * Function: AddText
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual eError AddText
    (cDocumentTextInterface& node) = 0;
    /**
     **********************************************************************
     * Function: AddComment
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual eError AddComment
    (cDocumentCommentInterface& node) = 0;
    /**
     **********************************************************************
     * Function: AddBeginElement
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual eError AddBeginElement
    (cDocumentBeginElementInterface& node) = 0;
    /**
     **********************************************************************
     * Function: AddEndElement
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual eError AddEndElement
    (cDocumentEndElementInterface& node) = 0;
    /**
     **********************************************************************
     * Function: AddElement
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual eError AddElement
    (cDocumentElementInterface& node) = 0;
    /**
     **********************************************************************
     * Function: AddEntityReference
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual eError AddEntityReference
    (cDocumentEntityReferenceInterface& node) = 0;
    /**
     **********************************************************************
     * Function: PushNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError PushNode
    (cDocumentNodeInterface& node) = 0;
    /**
     **********************************************************************
     * Function: AddNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError AddNode
    (cDocumentNodeInterface& node) = 0;
    /**
     **********************************************************************
     * Function: DeleteNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError DeleteNode
    (cDocumentNodeInterface& node) = 0;
    /**
     **********************************************************************
     * Function: DeleteAllNodes
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError DeleteAllNodes() = 0;

    /**
     **********************************************************************
     * Function: PopNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* PopNode() = 0;
    /**
     **********************************************************************
     * Function: PullNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* PullNode() = 0;

    /**
     **********************************************************************
     * Function: GetFirstElementByName
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* 
    GetFirstElementByName(const cCCharBuffer& name) const = 0;
    /**
     **********************************************************************
     * Function: GetFirstElement
     *
     *   Author: $author$
     *     Date: 11/9/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetFirstElement() const = 0;
    /**
     **********************************************************************
     * Function: GetLastElement
     *
     *   Author: $author$
     *     Date: 11/9/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetLastElement() const = 0;

    /**
     **********************************************************************
     * Function: GetFirstText
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentTextInterface* GetFirstText() const = 0;
    /**
     **********************************************************************
     * Function: GetLastText
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentTextInterface* GetLastText() const = 0;

    /**
     **********************************************************************
     * Function: GetFirstNode
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* GetFirstNode(int type=0) const = 0;
    /**
     **********************************************************************
     * Function: GetLastNode
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* GetLastNode(int type=0) const = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentNamespaceNodeInterface
 *
 * Author: $author$
 *   Date: 10/10/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentNamespaceNodeInterface
: virtual public cDocumentNodeInterface
{
public:
    /**
     **********************************************************************
     * Function: SetNamespace
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError SetNamespace
    (cDocumentNamespaceInterface* ns) = 0;
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface& GetNamespace() const = 0;

    /**
     **********************************************************************
     * Function: GetHasNamespace
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual bool GetHasNamespace() const = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentNamedNodeInterface
 *
 * Author: $author$
 *   Date: 10/10/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentNamedNodeInterface
: virtual public cDocumentNamespaceNodeInterface
{
public:
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual int Compare
    (const cDocumentNamedNodeInterface& node) const = 0;
    /**
     **********************************************************************
     * Function: SetNamespacePrefixChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetNamespacePrefixChars
    (const char* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: SetNamespacePrefixCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetNamespacePrefixCChars
    (const cChar* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetNamespacePrefixCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual const cChar* GetNamespacePrefixCChars(int &length) const = 0;

    /**
     **********************************************************************
     * Function: SetNameChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetNameChars
    (const char* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: SetNameCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetNameCChars
    (const cChar* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetNameCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual const cChar* GetNameCChars(int &length) const = 0;

    /**
     **********************************************************************
     * Function: SetNamespacePrefix
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetNamespacePrefix
    (const cCCharBuffer& name, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetNamespacePrefix
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetNamespacePrefix() const = 0;
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetName
    (const cCCharBuffer& name, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetName() const = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentDataNodeInterface
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentDataNodeInterface
: virtual public cDocumentNamespaceNodeInterface
{
public:
    /**
     **********************************************************************
     * Function: SetData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual int SetData
    (const cBYTEBuffer& data, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual const cBYTEBuffer& GetData() const = 0;
    /**
     **********************************************************************
     * Function: SetDataBytes
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual int SetDataBytes
    (const BYTE* bytes, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetDataBytes
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual const BYTE* GetDataBytes(int &length) const = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentDataInterface
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentDataInterface
: virtual public cDocumentDataNodeInterface
{
public:
};

/**
 **********************************************************************
 *  Class: cDocumentTextNodeInterface
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentTextNodeInterface
: virtual public cDocumentNamespaceNodeInterface
{
public:
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual int Compare
    (const cDocumentTextNodeInterface& node) const = 0;
    /**
     **********************************************************************
     * Function: SetTextChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetTextChars
    (const char* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: SetTextCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetTextCChars
    (const cChar* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetTextCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual const cChar* GetTextCChars(int &length) const = 0;
    /**
     **********************************************************************
     * Function: SetText
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetText
    (const cCCharBuffer& text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetText
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetText() const = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentEntityReferenceInterface
 *
 * Author: $author$
 *   Date: 11/14/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentEntityReferenceInterface
: virtual public cDocumentNamedNodeInterface
{
public:
    /**
     **********************************************************************
     * Function: AsDocumentEntityReference
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual cDocumentEntityReference& AsDocumentEntityReference() = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentAttributeInterface
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentAttributeInterface
: virtual public cDocumentNamedNodeInterface
{
public:
    /**
     **********************************************************************
     * Function: AsDocumentAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     *
    virtual cDocumentAttribute& AsDocumentAttribute() = 0;
     */
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual int SetValue
    (const cCCharBuffer& value, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: SetValueChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetValueChars
    (const char* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: SetValueCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetValueCChars
    (const cChar* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetValueCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual const cChar* GetValueCChars(int &length) const = 0;

    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetValue() const = 0;

    /**
     **********************************************************************
     * Function: SetIsNamespaceAttribute
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual eError SetIsNamespaceAttribute(bool is=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsNamespaceAttribute
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual bool GetIsNamespaceAttribute() const = 0;

    /**
     **********************************************************************
     * Function: SetIsNamespacePrefixAttribute
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual eError SetIsNamespacePrefixAttribute(bool is=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsNamespacePrefixAttribute
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual bool GetIsNamespacePrefixAttribute() const = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentEndElementInterface
 *
 * Author: $author$
 *   Date: 12/12/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentEndElementInterface
: virtual public cDocumentNamedNodeInterface
{
public:
};

/**
 **********************************************************************
 *  Class: cDocumentBeginElementInterface
 *
 * Author: $author$
 *   Date: 12/12/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentBeginElementInterface
: virtual public cDocumentEndElementInterface,
  virtual public cDocumentAttributeListInterface
{
public:
};

/**
 **********************************************************************
 *  Class: cDocumentElementInterface
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentElementInterface
: virtual public cDocumentBeginElementInterface,
  virtual public cDocumentNodeListInterface
{
public:
    /**
     **********************************************************************
     * Function: AsDocumentElement
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     *
    virtual cDocumentElement& AsDocumentElement() = 0;
    */
};

/**
 **********************************************************************
 *  Class: cDocumentTextInterface
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentTextInterface
: virtual public cDocumentTextNodeInterface
{
public:
    /**
     **********************************************************************
     * Function: AsDocumentText
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     *
    virtual cDocumentText& AsDocumentText() = 0;
    */
};

/**
 **********************************************************************
 *  Class: cDocumentCommentInterface
 *
 * Author: $author$
 *   Date: 10/13/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentCommentInterface
: virtual public cDocumentTextNodeInterface
{
public:
    /**
     **********************************************************************
     * Function: AsDocumentComment
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual cDocumentComment& AsDocumentComment() = 0;
};

#endif /* _CDOCUMENTARTIFACTINTERFACE_HXX */
