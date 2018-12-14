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
 *   File: cdocumentnodefactoryimplement.hxx
 *
 * Author: $author$
 *   Date: 11/1/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTNODEFACTORYIMPLEMENT_HXX
#define _CDOCUMENTNODEFACTORYIMPLEMENT_HXX

#include "cdocumentfactoryinterface.hxx"
#include "cdocumentnodefactoryinterface.hxx"
#include "cdocumentartifactimplement.hxx"

/**
 **********************************************************************
 *  Class: cDocumentNodeFactoryImplement
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class cDocumentNodeFactoryImplement
: virtual public cDocumentNodeFactoryInterface
{
public:
    /**
     **********************************************************************
     * Function: GetDocumentFactory
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual cDocumentFactoryInterface& GetDocumentFactory() const 
    {
        return cDocumentFactoryInterface::GetNullFactory();
    }
    /**
     **********************************************************************
     * Function: CreateNode
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* CreateNode
    (eError &error, int type) 
    {
        cDocumentNodeInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;

        switch(type)
        {
        case cDocumentNodeInterface::e_TYPE_DATA:
            node = CreateData(error);
            break;

        case cDocumentNodeInterface::e_TYPE_TEXT:
            node = CreateText(error);
            break;

        case cDocumentNodeInterface::e_TYPE_COMMENT:
            node = CreateComment(error);
            break;

        case cDocumentNodeInterface::e_TYPE_ATTRIBUTE:
            node = CreateAttribute(error);
            break;

        case cDocumentNodeInterface::e_TYPE_ELEMENT:
            node = CreateElement(error);
            break;

        case cDocumentNodeInterface::e_TYPE_BEGIN_ELEMENT:
            node = CreateBeginElement(error);
            break;

        case cDocumentNodeInterface::e_TYPE_END_ELEMENT:
            node = CreateEndElement(error);
            break;
        }
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateEntityReference
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentEntityReferenceInterface* CreateEntityReference
    (eError &error, const char *name, int namelen=-1) 
    {
        cDocumentEntityReferenceInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;

        if ((node = CreateEntityReference(error)))
            error = node->SetNameChars(name, namelen);
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateEntityReference
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual cDocumentEntityReferenceInterface* 
    CreateEntityReference(eError &error) 
    {
        cDocumentEntityReferenceInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateNamspaceAttribute
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* 
    CreateNamspaceAttribute
    (eError &error, 
     const char* name=0, int namelen=-1,
     const char* value=0, int valuelen=-1) 
    {
        cDocumentAttributeInterface* node;
        int is;

        if ((node = CreateAttribute
            (error, name, namelen, value, valuelen)))
        if (0 > (is = node->SetIsNamespaceAttribute(true)))
            error = -is;

        return node;
    }
    /**
     **********************************************************************
     * Function: CreateNamspacePrefixAttribute
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* 
    CreateNamspacePrefixAttribute
    (eError &error,
     const char* prefix=0, int prefixlen=-1, 
     const char* name=0, int namelen=-1,
     const char* value=0, int valuelen=-1) 
    {
        cDocumentAttributeInterface* node;
        int is;

        if ((node = CreateAttribute
            (error, name, namelen, 
             value, valuelen, prefix, prefixlen)))
        if (0 > (is =node->SetIsNamespacePrefixAttribute(true)))
            error = -is;

        return node;
    }
    /**
     **********************************************************************
     * Function: CreateAttribute
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* 
    CreateAttribute
    (eError &error, const cCCharBuffer* name,
     const cCCharBuffer* value=0,
     const cCCharBuffer* prefix=0) 
    {
        cDocumentAttributeInterface* node = 0;
        int namelen, valuelen, prefixlen;

        if ((node = CreateAttribute(error)))
        {
            if (name)
            if (0 > (namelen = node->SetName(*name)))
                error = -namelen;

            if (!error && value)
            if (0 > (valuelen = node->SetValue(*value)))
                error = -valuelen;

            if (!error && prefix)
            if (0 > (prefixlen = node->SetNamespacePrefix(*prefix)))
                error = -prefixlen;
        }
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateAttribute
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* 
    CreateAttribute
    (eError &error, const char* name, int namelen=-1,
     const char* value=0, int valuelen=-1,
     const char* prefix=0, int prefixlen=-1) 
    {
        cDocumentAttributeInterface* node = 0;

        if ((node = CreateAttribute(error)))
        {
            if (name)
            if (0 > (namelen = node->SetNameChars(name, namelen)))
                error = -namelen;

            if (!error && value)
            if (0 > (valuelen = node->SetValueChars(value, valuelen)))
                error = -valuelen;

            if (!error && prefix)
            if (0 > (prefixlen = node->
                SetNamespacePrefixChars(prefix, prefixlen)))
                error = -prefixlen;
        }
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateAttribute
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* 
    CreateAttribute
    (eError &error, const cChar* name, int namelen=-1,
     const cChar* value=0, int valuelen=-1,
     const cChar* prefix=0, int prefixlen=-1) 
    {
        cDocumentAttributeInterface* node = 0;

        if ((node = CreateAttribute(error)))
        {
            if (name)
            if (0 > (namelen = node->SetNameCChars(name, namelen)))
                error = -namelen;

            if (!error && value)
            if (0 > (valuelen = node->SetValueCChars(value, valuelen)))
                error = -valuelen;

            if (!error && prefix)
            if (0 > (prefixlen = node->
                SetNamespacePrefixCChars(prefix, prefixlen)))
                error = -prefixlen;
        }
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateAttribute
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* CreateAttribute(eError &error) 
    {
        cDocumentAttributeInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateEndElement
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentEndElementInterface* CreateEndElement
    (eError &error, const cCCharBuffer *name,
     const cCCharBuffer* prefix=0) 
    {
        cDocumentEndElementInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        int namelen, prefixlen;

        if ((node = CreateEndElement(error)))
        if (0 > (namelen = node->SetName(*name)))
            error = -namelen;
        else 
        {
            if (prefix)
            if (0 > (prefixlen = node->
                SetNamespacePrefix(*prefix)))
                error = -prefixlen;
        }
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateBeginElement
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentBeginElementInterface* CreateBeginElement
    (eError &error, const cCCharBuffer *name,
     const cCCharBuffer* prefix=0) 
    {
        cDocumentBeginElementInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        int namelen, prefixlen;

        if ((node = CreateBeginElement(error)))
        if (0 > (namelen = node->SetName(*name)))
            error = -namelen;
        else 
        {
            if (prefix)
            if (0 > (prefixlen = node->
                SetNamespacePrefix(*prefix)))
                error = -prefixlen;
        }
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateElement
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* CreateElement
    (eError &error, const cCCharBuffer *name,
     const cCCharBuffer* prefix=0) 
    {
        cDocumentElementInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        int namelen, prefixlen;

        if ((node = CreateElement(error)))
        if (0 > (namelen = node->SetName(*name)))
            error = -namelen;
        else 
        {
            if (prefix)
            if (0 > (prefixlen = node->
                SetNamespacePrefix(*prefix)))
                error = -prefixlen;
        }
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateElement
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* CreateElement
    (eError &error, const char *name, int namelen=-1,
     const char* prefix=0, int prefixlen=-1) 
    {
        cDocumentElementInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;

        if ((node = CreateElement(error)))
        if (0 > (namelen = node->SetNameChars(name, namelen)))
            error = -namelen;
        else 
        {
            if (prefix)
            if (0 > (prefixlen = node->
                SetNamespacePrefixChars(prefix, prefixlen)))
                error = -prefixlen;
        }
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateElement
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* CreateElement
    (eError &error, const cChar *name, int namelen=-1,
     const cChar* prefix=0, int prefixlen=-1) 
    {
        cDocumentElementInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;

        if ((node = CreateElement(error)))
        if (0 > (namelen = node->SetNameCChars(name, namelen)))
            error = -namelen;
        else 
        {
            if (prefix)
            if (0 > (prefixlen = node->
                SetNamespacePrefixCChars(prefix, prefixlen)))
                error = -prefixlen;
        }
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateElement
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* CreateElement(eError &error) 
    {
        cDocumentElementInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateBeginElement
     *
     *   Author: $author$
     *     Date: 12/12/2005
     **********************************************************************
     */
    virtual cDocumentBeginElementInterface* 
    CreateBeginElement(eError &error) 
    {
        cDocumentBeginElementInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateEndElement
     *
     *   Author: $author$
     *     Date: 12/12/2005
     **********************************************************************
     */
    virtual cDocumentEndElementInterface* 
    CreateEndElement(eError &error) 
    {
        cDocumentEndElementInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateComment
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentCommentInterface* CreateComment
    (eError &error, const char *text, int textlen=-1) 
    {
        cDocumentCommentInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;

        if ((node = CreateComment(error)))
        if (0 > (textlen = node->SetTextChars(text, textlen)))
            error = -textlen;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateComment
     *
     *   Author: $author$
     *     Date: 1/2/2006
     **********************************************************************
     */
    virtual cDocumentCommentInterface* CreateComment
    (eError &error, const cCCharBuffer *text) 
    {
        cDocumentCommentInterface* node = 0;
        int textlen;

        error = e_ERROR_NOT_IMPLEMENTED;

        if ((node = CreateComment(error)))
        if (0 > (textlen = node->SetText(*text)))
            error = -textlen;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateComment
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentCommentInterface* CreateComment(eError &error) 
    {
        cDocumentCommentInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataInterface* CreateData
    (eError &error, const cBYTEBuffer& data, int datalen=-1) 
    {
        cDocumentDataInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;

        if ((node = CreateData(error)))
        if (0 > (datalen = node->SetData(data, datalen)))
            error = -datalen;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataInterface* CreateData
    (eError &error, const BYTE* data, int datalen=-1) 
    {
        cDocumentDataInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;

        if ((node = CreateData(error)))
        if (0 > (datalen = node->SetDataBytes(data, datalen)))
            error = -datalen;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataInterface* CreateData(eError &error) 
    {
        cDocumentDataInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateText
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* CreateText
    (eError &error, const cCCharBuffer& text, int textlen=-1) 
    {
        cDocumentTextInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;

        if ((node = CreateText(error)))
        if (0 > (textlen = node->SetText(text, textlen)))
            error = -textlen;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateText
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* CreateText
    (eError &error, const cChar *text, int textlen=-1) 
    {
        cDocumentTextInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;

        if ((node = CreateText(error)))
        if (0 > (textlen = node->SetTextCChars(text, textlen)))
            error = -textlen;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateText
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* CreateText
    (eError &error, const char *text, int textlen=-1) 
    {
        cDocumentTextInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;

        if ((node = CreateText(error)))
        if (0 > (textlen = node->SetTextChars(text, textlen)))
            error = -textlen;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateText
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* CreateText(eError &error) 
    {
        cDocumentTextInterface* node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateReferenceNode
     *
     *   Author: $author$
     *     Date: 12/15/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* CreateReferenceNode
    (eError &error, cDocumentNodeInterface& node)
    {
        cDocumentNodeInterface* new_node = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return new_node;
    }
    /**
     **********************************************************************
     * Function: HoldNode
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual eError HoldNode
    (cDocumentNodeInterface& node) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: FreeNode
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual eError FreeNode
    (cDocumentNodeInterface& node) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: DestroyNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError DestroyNode
    (cDocumentNodeInterface& node) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: CreateNodeList
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* 
    CreateNodeList(eError &error) 
    {
        cDocumentNodeListInterface* node_list = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return node_list;
    }
    /**
     **********************************************************************
     * Function: DestroyNodeList
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual eError DestroyNodeList
    (cDocumentNodeListInterface& node_list) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface* GetNamespace
    (const cCCharBuffer& name) 
    {
        cDocumentNamespaceInterface* ns = 0;
        return ns;
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface* GetNamespace
    (const cChar *chars, int length=-1) 
    {
        cDocumentNamespaceInterface* ns = 0;
        return ns;
    }
    /**
     **********************************************************************
     * Function: FreeNamespace
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual eError FreeNamespace
    (cDocumentNamespaceInterface& ns) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer* GetName
    (const cCCharBuffer& name) 
    {
        const cCCharBuffer* l_name = 0;
        return l_name;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer* GetName
    (const cChar* chars, int length=-1) 
    {
        const cCCharBuffer* name = 0;
        return name;
    }
    /**
     **********************************************************************
     * Function: FreeName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual eError FreeName
    (const cCCharBuffer& m_name) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

#endif /* _CDOCUMENTNODEFACTORYIMPLEMENT_HXX */
