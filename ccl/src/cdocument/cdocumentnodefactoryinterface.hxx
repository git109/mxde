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
 *   File: cdocumentnodefactoryinterface.hxx
 *
 * Author: $author$
 *   Date: 11/1/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTNODEFACTORYINTERFACE_HXX
#define _CDOCUMENTNODEFACTORYINTERFACE_HXX

#include "cdocumentartifactinterface.hxx"
#include "cccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cDocumentNodeFactoryInterface
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentNodeFactoryInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: GetNullFactory
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    static cDocumentNodeFactoryInterface& GetNullNodeFactory();
    /**
     **********************************************************************
     * Function: GetDocumentFactory
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual cDocumentFactoryInterface& GetDocumentFactory() const = 0;

    /**
     **********************************************************************
     * Function: CreateNode
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* CreateNode
    (eError &error, int type) = 0;
    /**
     **********************************************************************
     * Function: CreateEntityReference
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentEntityReferenceInterface* CreateEntityReference
    (eError &error, const char *name, int namelen=-1) = 0;
    /**
     **********************************************************************
     * Function: CreateEntityReference
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual cDocumentEntityReferenceInterface* 
    CreateEntityReference(eError &error) = 0;
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
     const char* value=0, int valuelen=-1) = 0;
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
     const char* value=0, int valuelen=-1) = 0;
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
     const cCCharBuffer* prefix=0) = 0;
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
     const char* prefix=0, int prefixlen=-1) = 0;
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
     const cChar* prefix=0, int prefixlen=-1) = 0;
    /**
     **********************************************************************
     * Function: CreateAttribute
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* CreateAttribute(eError &error) = 0;
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
     const cCCharBuffer* prefix=0) = 0;
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
     const cCCharBuffer* prefix=0) = 0;
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
     const cCCharBuffer* prefix=0) = 0;
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
     const char* prefix=0, int prefixlen=-1) = 0;
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
     const cChar* prefix=0, int prefixlen=-1) = 0;
    /**
     **********************************************************************
     * Function: CreateElement
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* CreateElement(eError &error) = 0;
    /**
     **********************************************************************
     * Function: CreateBeginElement
     *
     *   Author: $author$
     *     Date: 12/12/2005
     **********************************************************************
     */
    virtual cDocumentBeginElementInterface* 
    CreateBeginElement(eError &error) = 0;
    /**
     **********************************************************************
     * Function: CreateEndElement
     *
     *   Author: $author$
     *     Date: 12/12/2005
     **********************************************************************
     */
    virtual cDocumentEndElementInterface* 
    CreateEndElement(eError &error) = 0;
    /**
     **********************************************************************
     * Function: CreateComment
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentCommentInterface* CreateComment
    (eError &error, const char *text, int textlen=-1) = 0;
    /**
     **********************************************************************
     * Function: CreateComment
     *
     *   Author: $author$
     *     Date: 1/2/2006
     **********************************************************************
     */
    virtual cDocumentCommentInterface* CreateComment
    (eError &error, const cCCharBuffer *text) = 0;
    /**
     **********************************************************************
     * Function: CreateComment
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentCommentInterface* CreateComment(eError &error) = 0;
    /**
     **********************************************************************
     * Function: CreateData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataInterface* CreateData
    (eError &error, const cBYTEBuffer& data, int datalen=-1) = 0;
    /**
     **********************************************************************
     * Function: CreateData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataInterface* CreateData
    (eError &error, const BYTE* data, int datalen=-1) = 0;
    /**
     **********************************************************************
     * Function: CreateData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataInterface* CreateData(eError &error) = 0;
    /**
     **********************************************************************
     * Function: CreateText
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* CreateText
    (eError &error, const cCCharBuffer& text, int textlen=-1) = 0;
    /**
     **********************************************************************
     * Function: CreateText
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* CreateText
    (eError &error, const cChar *text, int textlen=-1) = 0;
    /**
     **********************************************************************
     * Function: CreateText
     *
     *   Author: $author$
     *     Date: 11/28/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* CreateText
    (eError &error, const char *text, int textlen=-1) = 0;
    /**
     **********************************************************************
     * Function: CreateText
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* CreateText(eError &error) = 0;
    /**
     **********************************************************************
     * Function: CreateReferenceNode
     *
     *   Author: $author$
     *     Date: 12/15/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* CreateReferenceNode
    (eError &error, cDocumentNodeInterface& node) = 0;
    /**
     **********************************************************************
     * Function: HoldNode
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual eError HoldNode
    (cDocumentNodeInterface& node) = 0;
    /**
     **********************************************************************
     * Function: FreeNode
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual eError FreeNode
    (cDocumentNodeInterface& node) = 0;
    /**
     **********************************************************************
     * Function: DestroyNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError DestroyNode
    (cDocumentNodeInterface& node) = 0;

    /**
     **********************************************************************
     * Function: CreateNodeList
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* 
    CreateNodeList(eError &error) = 0;
    /**
     **********************************************************************
     * Function: DestroyNodeList
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual eError DestroyNodeList
    (cDocumentNodeListInterface& node_list) = 0;

    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface* GetNamespace
    (const cCCharBuffer& name) = 0;
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface* GetNamespace
    (const cChar *chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: FreeNamespace
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual eError FreeNamespace
    (cDocumentNamespaceInterface& ns) = 0;

    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer* GetName
    (const cCCharBuffer& name) = 0;
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer* GetName
    (const cChar* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: FreeName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual eError FreeName
    (const cCCharBuffer& name) = 0;
};

#endif /* _CDOCUMENTNODEFACTORYINTERFACE_HXX */
