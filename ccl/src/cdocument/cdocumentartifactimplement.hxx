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
 *   File: cdocumentartifactimplement.hxx
 *
 * Author: $author$
 *   Date: 10/8/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTARTIFACTIMPLEMENT_HXX
#define _CDOCUMENTARTIFACTIMPLEMENT_HXX

#include <stdio.h>
#include "cdocumentnamespaceinterface.hxx"
#include "cdocumenteventinterface.hxx"
#include "cdocumentnodefactoryinterface.hxx"
#include "cdocumentartifactinterface.hxx"

/**
 **********************************************************************
 *  Class: cDocumentArtifactImplement
 *
 * Author: $author$
 *   Date: 10/8/2005
 **********************************************************************
 */
class cDocumentArtifactImplement
: virtual public cDocumentArtifactInterface
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
    virtual eError SetParentDocument(cDocumentInterface *document)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetParentDocument
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentInterface *GetParentDocument() const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetParentElement
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual eError SetParentElement
    (cDocumentElementInterface *element)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetParentElement
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface *GetParentElement() const
    {
        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNodeFactoryArtifactImplement
 *
 * Author: $author$
 *   Date: 11/23/2005
 **********************************************************************
 */
class cDocumentNodeFactoryArtifactImplement
: virtual public cDocumentNodeFactoryArtifactInterface
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
    virtual cDocumentNodeFactoryInterface& GetNodeFactory() const 
    {
        return cDocumentNodeFactoryInterface::GetNullNodeFactory();
    }
};

/**
 **********************************************************************
 *  Class: cDocumentEventArtifactImplement
 *
 * Author: $author$
 *   Date: 11/24/2005
 **********************************************************************
 */
class cDocumentEventArtifactImplement
: virtual public cDocumentEventArtifactInterface
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
    virtual cDocumentEventInterface& GetEvent() const 
    {
        return cDocumentEventInterface::GetNullEvent();
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNodeImplement
 *
 * Author: $author$
 *   Date: 10/8/2005
 **********************************************************************
 */
class cDocumentNodeImplement
: virtual public cDocumentNodeInterface
{
public:
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
        cDocumentNodeListInterface* list = 0;
        return list;
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
        cDocumentNodeListInterface* list = 0;
        return list;
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
        cDocumentAttributeInterface* node = 0;
        return node;
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
        cDocumentElementInterface* node = 0;
        return node;
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
        cDocumentBeginElementInterface* node = 0;
        return node;
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
        cDocumentEndElementInterface* node = 0;
        return node;
    }
    /**
     **********************************************************************
     * Function: GetEntityReferenceInterface
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual cDocumentEntityReferenceInterface* 
    GetEntityReferenceInterface() const
    {
        cDocumentEntityReferenceInterface* node = 0;
        return node;
    }
    /**
     **********************************************************************
     * Function: GetDataInterface
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataInterface* GetDataInterface() const 
    {
        cDocumentDataInterface* node = 0;
        return node;
    }
    /**
     **********************************************************************
     * Function: GetDataNodeInterface
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataNodeInterface* GetDataNodeInterface() const 
    {
        cDocumentDataNodeInterface* node = 0;
        return node;
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
        cDocumentTextInterface* node = 0;
        return node;
    }
    /**
     **********************************************************************
     * Function: GetCommentInterface
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentCommentInterface* GetCommentInterface() const 
    {
        cDocumentCommentInterface* node = 0;
        return node;
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
        cDocumentNamedNodeInterface* node = 0;
        return node;
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
        cDocumentTextNodeInterface* node = 0;
        return node;
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
        return (cDocumentNodeInterface&)(*this);
    }
    /**
     **********************************************************************
     * Function: GetDocumentInterface
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentInterface* GetDocumentInterface() const 
    {
        cDocumentInterface* node = 0;
        return node;
    }

    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual int SetType(unsigned type)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
	virtual int GetType() const
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual int Compare
    (const cDocumentNodeInterface& node) const 
    {
        int unequal = -e_ERROR_FAILED-1;
        int t1, t2;
        const cDocumentTextNodeInterface* text_node1;
        const cDocumentTextNodeInterface* text_node2;
        const cDocumentNamedNodeInterface* named_node1;
        const cDocumentNamedNodeInterface* named_node2;

        if (0 <= (t1 = GetType()))
        if (0 <= (t2 = node.GetType()))
        if (t1 < t2)
            unequal = -1;

        else if (t1 > t2)
                unequal = 1;

        else if (((named_node1 = GetNamedNodeInterface()))
                 && ((named_node2 = node.GetNamedNodeInterface())))
                 unequal = named_node1->Compare(*named_node2);

        else if (((text_node1 = GetTextNodeInterface()))
                 && ((text_node2 = node.GetTextNodeInterface())))
                 unequal = text_node1->Compare(*text_node2);

        else unequal = 0;
        return unequal;
    }

    /**
     **********************************************************************
     * Function: GetNextAttributeByName
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* 
    GetNextAttributeByName(const cCCharBuffer& name) const 
    {
        cDocumentAttributeInterface* element = 0;
        int unequal;

        if ((element = GetNextAttribute()))
        do
        {
            const cCCharBuffer& ename = element->GetName();

            if (!(unequal = ename.Compare(name)))
                break;
        }
        while ((element = element->GetNextAttribute()));
        return element;
    }
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
        cDocumentAttributeInterface* node = 0;
        return node;
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
        cDocumentAttributeInterface* node = 0;
        return node;
    }

    /**
     **********************************************************************
     * Function: GetNextElementByName
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* 
    GetNextElementByName(const cCCharBuffer& name) const 
    {
        cDocumentElementInterface* element = 0;
        int unequal;

        if ((element = GetNextElement()))
        do
        {
            const cCCharBuffer& ename = element->GetName();

            if (!(unequal = ename.Compare(name)))
                break;
        }
        while ((element = element->GetNextElement()));
        return element;
    }
    /**
     **********************************************************************
     * Function: GetNextElement
     *
     *   Author: $author$
     *     Date: 11/9/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetNextElement() const 
    {
        cDocumentElementInterface* element = 0;
        cDocumentNodeInterface* node = 0;

        if ((node = GetNextNode(cDocumentNodeInterface::e_TYPE_ELEMENT)))
            element = node->GetElementInterface();

        return element;
    }
    /**
     **********************************************************************
     * Function: GetPreviousElement
     *
     *   Author: $author$
     *     Date: 11/9/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetPreviousElement() const 
    {
        cDocumentElementInterface* element = 0;
        cDocumentNodeInterface* node = 0;

        if ((node = GetPreviousNode(cDocumentNodeInterface::e_TYPE_ELEMENT)))
            element = node->GetElementInterface();

        return element;
    }

    /**
     **********************************************************************
     * Function: GetNextText
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentTextInterface* GetNextText() const
    {
        cDocumentTextInterface* text = 0;
        cDocumentNodeInterface* node = 0;

        if ((node = GetNextNode(cDocumentNodeInterface::e_TYPE_TEXT)))
            text = node->GetTextInterface();
        return text;
    }
    /**
     **********************************************************************
     * Function: GetPreviousText
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentTextInterface* GetPreviousText() const
    {
        cDocumentTextInterface* text = 0;
        cDocumentNodeInterface* node = 0;

        if ((node = GetPreviousNode(cDocumentNodeInterface::e_TYPE_TEXT)))
            text = node->GetTextInterface();
        return text;
    }

    /**
     **********************************************************************
     * Function: GetNextNode
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* GetNextNode(int type=0) const 
    {
        cDocumentNodeInterface* node = 0;
        return node;
    }
    /**
     **********************************************************************
     * Function: GetPreviousNode
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* GetPreviousNode(int type=0) const 
    {
        cDocumentNodeInterface* node = 0;
        return node;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentAttributeListImplement
 *
 * Author: $author$
 *   Date: 12/12/2005
 **********************************************************************
 */
class cDocumentAttributeListImplement
: virtual public cDocumentAttributeListInterface
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
     const cCCharBuffer* prefix=0) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentAttributeInterface* node = 0;

        if ((node = node_factory.CreateAttribute
            (error, name, value, prefix)))
            error = AddAttribute(*node);
        return node;
    }
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
     const char* prefix=0, int prefixlen=-1) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentAttributeInterface* node = 0;

        if ((node = node_factory.CreateAttribute
            (error, name, namelen, 
             value, valuelen, prefix, prefixlen)))
            error = AddAttribute(*node);
        return node;
    }
    /**
     **********************************************************************
     * Function: AddAttribute
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual eError AddAttribute
    (cDocumentAttributeInterface& node) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetFirstAttributeByName
     *
     *   Author: $author$
     *     Date: 12/22/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* 
    GetFirstAttributeByName(const cCCharBuffer& name) const 
    {
        cDocumentAttributeInterface* element = 0;
        int unequal;

        if ((element = GetFirstAttribute()))
        {
            const cCCharBuffer& ename = element->GetName();

            if ((unequal = ename.Compare(name)))
                element = element->GetNextAttributeByName(name);
        }
        return element;
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
        cDocumentAttributeInterface* node = 0;
        return node;
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
        cDocumentAttributeInterface* node = 0;
        return node;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNodeListImplement
 *
 * Author: $author$
 *   Date: 10/10/2005
 **********************************************************************
 */
class cDocumentNodeListImplement
: virtual public cDocumentNodeListInterface
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
    (const cDocumentNodeListInterface& node_list) const 
    {
        int unequal = 0;
        const cDocumentNodeInterface* node1;
        const cDocumentNodeInterface* node2;

        if ((node1 = GetFirstNode()))
        {
            if ((node2 = node_list.GetFirstNode()))
            {
                do
                {
                    if (!(unequal = node1->Compare(*node2)))
                    if ((node1 = node1->GetNextNode()))
                    {
                        if (!(node2 = node2->GetNextNode()))
                        {
                            unequal = 1;
                            break;
                        }
                    }
                    else
                    {
                        if ((node2 = node2->GetNextNode()))
                            unequal = -1;
                        break;
                    }
                }
                while(!unequal);
            }
            else unequal = 1;
        }
        else if ((node2 = node_list.GetFirstNode()))
                unequal = -1;

        return unequal;
    }
    /**
     **********************************************************************
     * Function: AddReferenceNodeList
     *
     *   Author: $author$
     *     Date: 12/15/2005
     **********************************************************************
     */
    virtual int AddReferenceNodeList
    (const cDocumentNodeListInterface& node_list) 
    {
        int count = 0;
        eError error;
        cDocumentNodeInterface* node;
        cDocumentNodeInterface* new_node;

        if ((node = node_list.GetFirstNode()))
        do
        {
            if ((new_node = AddReferenceNode(error, *node)))
                ++count;
            else
            {
                count = -error;
                break;
            }
        }
        while ((node = node->GetNextNode()));
        return count;
    }
    /**
     **********************************************************************
     * Function: AddReferenceNode
     *
     *   Author: $author$
     *     Date: 12/15/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* AddReferenceNode
    (eError &error, cDocumentNodeInterface& node) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentNodeInterface* new_node = 0;

        if ((new_node = node_factory.
            CreateReferenceNode(error, node)))
            error = AddNode(*new_node);
        return new_node;
    }
    /**
     **********************************************************************
     * Function: AddData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataInterface* AddData
    (eError &error, const cBYTEBuffer& data, int length=-1) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentDataInterface* node = 0;

        if ((node = node_factory.CreateData(error, data, length)))
            error = AddNode(*node);
        return node;
    }
    /**
     **********************************************************************
     * Function: AddData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataInterface* AddData
    (eError &error, const BYTE* data, int length=-1) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentDataInterface* node = 0;

        if ((node = node_factory.CreateData(error, data, length)))
            error = AddNode(*node);
        return node;
    }
    /**
     **********************************************************************
     * Function: AddText
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* AddText
    (eError &error, const cCCharBuffer& text, int length=-1) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentTextInterface* node = 0;

        if ((node = node_factory.CreateText(error, text, length)))
            error = AddText(*node);
        return node;
    }
    /**
     **********************************************************************
     * Function: AddText
     *
     *   Author: $author$
     *     Date: 12/2/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* AddText
    (eError &error, const cChar* chars, int length=-1) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentTextInterface* node = 0;

        if ((node = node_factory.CreateText(error, chars, length)))
            error = AddText(*node);
        return node;
    }
    /**
     **********************************************************************
     * Function: AddText
     *
     *   Author: $author$
     *     Date: 12/2/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* AddText
    (eError &error, const char* chars, int length=-1) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentTextInterface* node = 0;

        if ((node = node_factory.CreateText(error, chars, length)))
            error = AddText(*node);
        return node;
    }
    /**
     **********************************************************************
     * Function: AddComment
     *
     *   Author: $author$
     *     Date: 12/2/2005
     **********************************************************************
     */
    virtual cDocumentCommentInterface* AddComment
    (eError &error, const char* chars, int length=-1) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentCommentInterface* node = 0;

        if ((node = node_factory.CreateComment(error, chars, length)))
            error = AddComment(*node);
        return node;
    }
    /**
     **********************************************************************
     * Function: AddComment
     *
     *   Author: $author$
     *     Date: 1/2/2006
     **********************************************************************
     */
    virtual cDocumentCommentInterface* AddComment
    (eError &error, const cCCharBuffer* text) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentCommentInterface* node = 0;

        if ((node = node_factory.CreateComment(error, text)))
            error = AddComment(*node);
        return node;
    }
    /**
     **********************************************************************
     * Function: AddEntityReference
     *
     *   Author: $author$
     *     Date: 12/2/2005
     **********************************************************************
     */
    virtual cDocumentEntityReferenceInterface* AddEntityReference
    (eError &error, const char* chars, int length=-1) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentEntityReferenceInterface* node = 0;

        if ((node = node_factory.CreateEntityReference(error, chars, length)))
            error = AddEntityReference(*node);
        return node;
    }

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
     const cCCharBuffer* prefix=0) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentBeginElementInterface* node = 0;

        if ((node = node_factory.CreateBeginElement
            (error, name, prefix)))
            error = AddBeginElement(*node);
        return node;
    }
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
     const cCCharBuffer* prefix=0) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentEndElementInterface* node = 0;

        if ((node = node_factory.CreateEndElement
            (error, name, prefix)))
            error = AddEndElement(*node);
        return node;
    }
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
     const cCCharBuffer* prefix=0) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentElementInterface* node = 0;

        if ((node = node_factory.CreateElement
            (error, name, prefix)))
            error = AddElement(*node);
        return node;
    }
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
     const cChar* prefix=0, int prefixlen=-1) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentElementInterface* node = 0;

        if ((node = node_factory.CreateElement
            (error, name, namelen, prefix, prefixlen)))
            error = AddElement(*node);
        return node;
    }
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
     const char* prefix=0, int prefixlen=-1) 
    {
        cDocumentNodeFactoryInterface& node_factory = GetNodeFactory();
        cDocumentElementInterface* node = 0;

        if ((node = node_factory.CreateElement
            (error, name, namelen, prefix, prefixlen)))
            error = AddElement(*node);
        return node;
    }

    /**
     **********************************************************************
     * Function: AddText
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual eError AddText
    (cDocumentTextInterface& node) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: AddComment
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual eError AddComment
    (cDocumentCommentInterface& node) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: AddBeginElement
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual eError AddBeginElement
    (cDocumentBeginElementInterface& node) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: AddEndElement
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual eError AddEndElement
    (cDocumentEndElementInterface& node) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: AddElement
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual eError AddElement
    (cDocumentElementInterface& node) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: AddEntityReference
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual eError AddEntityReference
    (cDocumentEntityReferenceInterface& node) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: PushNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError PushNode
    (cDocumentNodeInterface& node) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: AddNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError AddNode
    (cDocumentNodeInterface& node) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError DeleteNode
    (cDocumentNodeInterface& node) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteAllNodes
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError DeleteAllNodes() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: PopNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* PopNode() 
    {
        cDocumentNodeInterface* node = 0;
        return node;
    }
    /**
     **********************************************************************
     * Function: PullNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* PullNode() 
    {
        cDocumentNodeInterface* node = 0;
        return node;
    }

    /**
     **********************************************************************
     * Function: GetFirstElementByName
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* 
    GetFirstElementByName(const cCCharBuffer& name) const 
    {
        cDocumentElementInterface* element = 0;
        int unequal;

        if ((element = GetFirstElement()))
        {
            const cCCharBuffer& ename = element->GetName();

            if ((unequal = ename.Compare(name)))
                element = element->GetNextElementByName(name);
        }
        return element;
    }
    /**
     **********************************************************************
     * Function: GetFirstElement
     *
     *   Author: $author$
     *     Date: 11/9/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetFirstElement() const 
    {
        cDocumentElementInterface* element = 0;
        cDocumentNodeInterface* node = 0;

        if ((node = GetFirstNode(cDocumentNodeInterface::e_TYPE_ELEMENT)))
            element = node->GetElementInterface();

        return element;
    }
    /**
     **********************************************************************
     * Function: GetLastElement
     *
     *   Author: $author$
     *     Date: 11/9/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetLastElement() const 
    {
        cDocumentElementInterface* element = 0;
        cDocumentNodeInterface* node = 0;

        if ((node = GetLastNode(cDocumentNodeInterface::e_TYPE_ELEMENT)))
            element = node->GetElementInterface();

        return element;
    }

    /**
     **********************************************************************
     * Function: GetFirstText
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentTextInterface* GetFirstText() const
    {
        cDocumentTextInterface* text = 0;
        cDocumentNodeInterface* node = 0;

        if ((node = GetFirstNode(cDocumentNodeInterface::e_TYPE_TEXT)))
            text = node->GetTextInterface();
        return text;
    }
    /**
     **********************************************************************
     * Function: GetLastText
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentTextInterface* GetLastText() const
    {
        cDocumentTextInterface* text = 0;
        cDocumentNodeInterface* node = 0;

        if ((node = GetLastNode(cDocumentNodeInterface::e_TYPE_TEXT)))
            text = node->GetTextInterface();
        return text;
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
        cDocumentNodeInterface* node = 0;
        return node;
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
        cDocumentNodeInterface* node = 0;
        return node;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNamespaceNodeImplement
 *
 * Author: $author$
 *   Date: 10/13/2005
 **********************************************************************
 */
class cDocumentNamespaceNodeImplement
: virtual public cDocumentNamespaceNodeInterface
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
    (cDocumentNamespaceInterface* ns) 
    {
        eError error = -e_ERROR_NOT_IMPLEMENTED;
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
        cDocumentNamespaceInterface& ns = cDocumentNamespaceInterface::GetGlobalNamespace();
        return ns;
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
        bool has = false;
        return has;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNamedNodeImplement
 *
 * Author: $author$
 *   Date: 10/10/2005
 **********************************************************************
 */
class cDocumentNamedNodeImplement
: virtual public cDocumentNamedNodeInterface
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
    (const cDocumentNamedNodeInterface& node) const 
    {
        int unequal = -e_ERROR_FAILED-1;
        const cCCharBuffer& ns1 = GetNamespacePrefix();
        const cCCharBuffer& n1 = GetName();
        const cCCharBuffer& ns2 = node.GetNamespacePrefix();
        const cCCharBuffer& n2 = node.GetName();

        if (!(unequal = ns2.Compare(ns1)))
            unequal = n2.Compare(n1);
        return unequal;
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
        length = -e_ERROR_NOT_IMPLEMENTED;
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
        length = -e_ERROR_NOT_IMPLEMENTED;
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
        const cChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
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
        length = -e_ERROR_NOT_IMPLEMENTED;
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
        length = -e_ERROR_NOT_IMPLEMENTED;
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
        const cChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetNamespacePrefix
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetNamespacePrefix
    (const cCCharBuffer& name, int length=-1)
    {
        int count = -e_ERROR_FAILED;
        int charslen;
        const cChar* chars;

        if ((chars = name.GetBuffer(charslen)))
        {
            if ((0 > length) || (length > charslen))
                length = charslen;

            count = SetNamespacePrefixCChars(chars, length);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetName
    (const cCCharBuffer& name, int length=-1)
    {
        int count = -e_ERROR_FAILED;
        int charslen;
        const cChar* chars;

        if ((chars = name.GetBuffer(charslen)))
        {
            if ((0 > length) || (length > charslen))
                length = charslen;

            count = SetNameCChars(chars, length);
        }
        return count;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentDataNodeImplement
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class cDocumentDataNodeImplement
: virtual public cDocumentDataNodeInterface
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
    (const cBYTEBuffer& data, int length=-1) 
    {
        int count = -e_ERROR_FAILED;
        int byteslen;
        const BYTE* bytes;

        if ((bytes = data.GetBuffer(byteslen)))
        {
            if ((0 > length) || (length > byteslen))
                length = byteslen;

            count = SetDataBytes(bytes, length);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: SetDataBytes
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual int SetDataBytes
    (const BYTE* bytes, int length=-1) 
    {
        length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: GetDataBytes
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual const BYTE* GetDataBytes(int &length) const
    {
        const BYTE* bytes = 0;
        return bytes;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentDataImplement
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class cDocumentDataImplement
: virtual public cDocumentDataInterface
{
public:
};

/**
 **********************************************************************
 *  Class: cDocumentTextNodeImplement
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class cDocumentTextNodeImplement
: virtual public cDocumentTextNodeInterface
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
    (const cDocumentTextNodeInterface& node) const 
    {
        int unequal = -e_ERROR_FAILED-1;
        const cCCharBuffer& text1 = GetText();
        const cCCharBuffer& text2 = node.GetText();

        unequal = text2.Compare(text1);
        return unequal;
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
        length = -e_ERROR_NOT_IMPLEMENTED;
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
        length = -e_ERROR_NOT_IMPLEMENTED;
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
        const cChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetText
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetText
    (const cCCharBuffer& text, int length=-1)
    {
        int count = -e_ERROR_FAILED;
        int textlen;
        const cChar* chars;

        if ((chars = text.GetBuffer(textlen)))
        {
            if ((0 > length) || (length > textlen))
                length = textlen;

            count = SetTextCChars(chars, length);
        }
        return count;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentEntityReferenceImplement
 *
 * Author: $author$
 *   Date: 11/14/2005
 **********************************************************************
 */
class cDocumentEntityReferenceImplement
: virtual public cDocumentEntityReferenceInterface
{
public:
};

/**
 **********************************************************************
 *  Class: cDocumentAttributeImplement
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class cDocumentAttributeImplement
: virtual public cDocumentAttributeInterface
{
public:
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual int SetValue
    (const cCCharBuffer& value, int length=-1) 
    {
        int count = -e_ERROR_FAILED;
        int charslen;
        const cChar* chars;

        if ((chars = value.GetBuffer(charslen)))
        {
            if ((0 > length) || (length > charslen))
                length = charslen;

            count = SetValueCChars(chars, length);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: SetValueChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetValueChars
    (const char* chars, int length=-1) 
    {
        length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: SetValueCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetValueCChars
    (const cChar* chars, int length=-1) 
    {
        length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
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
        const cChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetIsNamespaceAttribute
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual eError SetIsNamespaceAttribute(bool is=true) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetIsNamespaceAttribute
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual bool GetIsNamespaceAttribute() const 
    {
        bool is = false;
        return is;
    }

    /**
     **********************************************************************
     * Function: SetIsNamespacePrefixAttribute
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual eError SetIsNamespacePrefixAttribute(bool is=true) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetIsNamespacePrefixAttribute
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual bool GetIsNamespacePrefixAttribute() const 
    {
        bool is = false;
        return is;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentEndElementImplement
 *
 * Author: $author$
 *   Date: 12/12/2005
 **********************************************************************
 */
class cDocumentEndElementImplement
: virtual public cDocumentEndElementInterface
{
public:
};

/**
 **********************************************************************
 *  Class: cDocumentBeginElementImplement
 *
 * Author: $author$
 *   Date: 12/12/2005
 **********************************************************************
 */
class cDocumentBeginElementImplement
: virtual public cDocumentBeginElementInterface
{
public:
};

/**
 **********************************************************************
 *  Class: cDocumentElementImplement
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class cDocumentElementImplement
: virtual public cDocumentElementInterface
{
public:
};

/**
 **********************************************************************
 *  Class: cDocumentTextImplement
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class cDocumentTextImplement
: virtual public cDocumentTextInterface
{
public:
};

/**
 **********************************************************************
 *  Class: cDocumentCommentImplement
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class cDocumentCommentImplement
: virtual public cDocumentCommentInterface
{
public:
};

#endif /* _CDOCUMENTARTIFACTIMPLEMENT_HXX */
