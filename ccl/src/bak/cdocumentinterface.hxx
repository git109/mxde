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
 *   File: cdocumentinterface.hxx
 *
 * Author: $author$
 *   Date: 8/22/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTINTERFACE_HXX
#define _CDOCUMENTINTERFACE_HXX

#include "cinterface.hxx"
#include "ccharstream.hxx"

#define CDOCUMENTINTERFACE_TYPE_ATTRIBUTE_TEXT "attribute"
#define CDOCUMENTINTERFACE_TYPE_PARENT_ELEMENT_TEXT "element"
#define CDOCUMENTINTERFACE_TYPE_TEXT_ELEMENT_TEXT "text"
#define CDOCUMENTINTERFACE_TYPE_COMMENT_ELEMENT_TEXT "comment"

class c_INTERFACE_CLASS cAttributeInterface;
class c_INTERFACE_CLASS cElementInterface;
class c_INTERFACE_CLASS cDocumentInterface;

/**
 **********************************************************************
 *  Class: cArtifactInterface
 *
 * Author: $author$
 *   Date: 8/19/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cArtifactInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 8/23/2003
     **********************************************************************
     */
    enum
    {
        e_FIRST_ERROR=::e_NEXT_ERROR,
        e_ERROR_SET_TEXT=e_FIRST_ERROR,
        e_ERROR_SET_NAME,
        e_NEXT_ERROR,
        e_LAST_ERROR=e_NEXT_ERROR-1
    };

    /**
     **********************************************************************
     * Function: SetParentDocument
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError SetParentDocument(cDocumentInterface *document)=0;
    /**
     **********************************************************************
     * Function: GetParentDocument
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cDocumentInterface *GetParentDocument() const=0;

    /**
     **********************************************************************
     * Function: SetParentElement
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError SetParentElement(cElementInterface *element)=0;
    /**
     **********************************************************************
     * Function: GetParentElement
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cElementInterface *GetParentElement() const=0;

    /**
     **********************************************************************
     * Function: GetDocument
     *
     *   Author: $author$
     *     Date: 8/31/2003
     **********************************************************************
     */
    virtual cDocumentInterface *GetDocument() const=0;
    /**
     **********************************************************************
     * Function: GetElement
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cElementInterface *GetElement() const=0;
    /**
     **********************************************************************
     * Function: GetAttribute
     *
     *   Author: $author$
     *     Date: 2/16/2004
     **********************************************************************
     */
    virtual cAttributeInterface *GetAttribute() const=0;
};

/**
 **********************************************************************
 *  Class: cAtomInterface
 *
 * Author: $author$
 *   Date: 8/19/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cAtomInterface
: virtual public cArtifactInterface
{
public:

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 8/19/2003
     **********************************************************************
     */
    enum
    {
        e_TYPE_UNDEFINED       = 0,
        e_TYPE_ATTRIBUTE       = 1,
        e_TYPE_PARENT_ELEMENT  = 2,
        e_TYPE_TEXT_ELEMENT    = 4,
        e_TYPE_COMMENT_ELEMENT = 8
    };

    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError SetType(unsigned type)=0;
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
	virtual unsigned GetType() const=0;

    /**
     **********************************************************************
     * Function: SetText
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual int SetText(const char *text,int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetText
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
	virtual const char *GetText(int &length) const=0;
    /**
     **********************************************************************
     * Function: GetTextLength
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
	virtual int GetTextLength() const=0;
    /**
     **********************************************************************
     * Function: GetTextStream
     *
     *   Author: $author$
     *     Date: 2/17/2004
     **********************************************************************
     */
	virtual cCharStream *GetTextStream(int &length)=0;
    /**
     **********************************************************************
     * Function: GetTextNamespacePrefix
     *
     *   Author: $author$
     *     Date: 2/9/2004
     **********************************************************************
     */
	virtual const char *GetTextNamespacePrefix(int &length) const=0;
    /**
     **********************************************************************
     * Function: GetTextAfterNamespacePrefix
     *
     *   Author: $author$
     *     Date: 8/14/2004
     **********************************************************************
     */
	virtual const char *GetTextAfterNamespacePrefix(int &length) const=0;
    /**
     **********************************************************************
     * Function: GetTextNamespace
     *
     *   Author: $author$
     *     Date: 2/9/2004
     **********************************************************************
     */
	virtual const char *GetTextNamespace(int &length) const=0;
    /**
     **********************************************************************
     * Function: CompareText
     *
     *   Author: $author$
     *     Date: 1/1/2004
     **********************************************************************
     */
	virtual int CompareText(const char *text, int textlen=-1) const=0;

    /**
     **********************************************************************
     * Function: GetTypeText
     *
     *   Author: $author$
     *     Date: 2/10/2004
     **********************************************************************
     */
	const char *GetTypeText(int &length) const;
    /**
     **********************************************************************
     * Function: PutTypeTextToStream
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    int PutTypeTextToStream(cCharStream &stream) const;

    /**
     **********************************************************************
     * Function: GetText
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    inline const char *GetText() const
    {
        int length;
        return GetText(length);
    }
};

/**
 **********************************************************************
 *  Class: cElementSetInterface
 *
 * Author: $author$
 *   Date: 8/19/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cElementSetInterface
: virtual public cArtifactInterface
{
public:
    /**
     **********************************************************************
     * Function: GetFirstElement
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cElementInterface *GetFirstElement() const=0;
    /**
     **********************************************************************
     * Function: GetLastElement
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cElementInterface *GetLastElement() const=0;

    /**
     **********************************************************************
     * Function: CreateElement
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cElementInterface *CreateElement
    (const char *text="",int textlen=-1,
     unsigned type=cAtomInterface::e_TYPE_PARENT_ELEMENT)=0;
    /**
     **********************************************************************
     * Function: PushElement
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual cElementInterface *PushElement
    (const char *text="",int textlen=-1,
     unsigned type=cAtomInterface::e_TYPE_PARENT_ELEMENT)=0;
    /**
     **********************************************************************
     * Function: AddElement
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cElementInterface *AddElement
    (const char *text="",int textlen=-1,
     unsigned type=cAtomInterface::e_TYPE_PARENT_ELEMENT)=0;
    /**
     **********************************************************************
     * Function: PushReferenceElement
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual cElementInterface *PushReferenceElement(cElementInterface &element)=0;
    /**
     **********************************************************************
     * Function: AddReferenceElement
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual cElementInterface *AddReferenceElement(cElementInterface &element)=0;
    /**
     **********************************************************************
     * Function: DeleteElement
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError DeleteElement(cElementInterface *element)=0;
    /**
     **********************************************************************
     * Function: DeleteAllElements
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError DeleteAllElements()=0;

    /**
     **********************************************************************
     * Function: PutToStream
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
     virtual int PutToStream
     (cCharStream &stream,
      bool exclude_whitespace=false,
      bool exclude_comments=false,
      bool exclude_multiple_root_elements=false) const=0;

    /**
     **********************************************************************
     * Function: AddElementCopy
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    cElementInterface *AddElementCopy
    (cElementInterface &element,
     bool exclude_attributes=false,
     bool exclude_child_elements=false);

    /**
     **********************************************************************
     * Function: ReferenceElements
     *
     *   Author: $author$
     *     Date: 8/29/2003
     **********************************************************************
     */
    int ReferenceElements(cElementSetInterface &element_set);

    /**
     **********************************************************************
     * Function: GetFirstElementByType
     *
     *   Author: $author$
     *     Date: 1/1/2004
     **********************************************************************
     */
    cElementInterface *GetFirstElementByType(unsigned type) const;
    /**
     **********************************************************************
     * Function: GetLastElementByType
     *
     *   Author: $author$
     *     Date: 1/1/2004
     **********************************************************************
     */
    cElementInterface *GetLastElementByType(unsigned type) const;

    /**
     **********************************************************************
     * Function: GetFirstElementByText
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    cElementInterface *GetFirstElementByText
    (const char *text, int textlen=-1) const;
    /**
     **********************************************************************
     * Function: GetLastElementByText
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    cElementInterface *GetLastElementByText
    (const char *text, int textlen=-1) const;

    /**
     **********************************************************************
     * Function: GetFirstElementByTypeAndText
     *
     *   Author: $author$
     *     Date: 1/1/2004
     **********************************************************************
     */
    cElementInterface *GetFirstElementByTypeAndText
    (unsigned type, const char *text, int textlen=-1) const;
    /**
     **********************************************************************
     * Function: GetLastElementByTypeAndText
     *
     *   Author: $author$
     *     Date: 1/1/2004
     **********************************************************************
     */
    cElementInterface *GetLastElementByTypeAndText
    (unsigned type, const char *text, int textlen=-1) const;

    /**
     **********************************************************************
     * Function: GetFirstParentElement
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    inline cElementInterface *GetFirstParentElement() const
    {
        return GetFirstElementByType
        (cAtomInterface::e_TYPE_PARENT_ELEMENT);
    }
    /**
     **********************************************************************
     * Function: GetLastParentElement
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    inline cElementInterface *GetLastParentElement() const
    {
        return GetLastElementByType
        (cAtomInterface::e_TYPE_PARENT_ELEMENT);
    }
    /**
     **********************************************************************
     * Function: GetFirstParentElementByText
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    inline cElementInterface *GetFirstParentElementByText
    (const char *text, int textlen=-1) const
    {
        return GetFirstElementByTypeAndText
        (cAtomInterface::e_TYPE_PARENT_ELEMENT, text, textlen);
    }
    /**
     **********************************************************************
     * Function: GetLastParentElementByText
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    inline cElementInterface *GetLastParentElementByText
    (const char *text, int textlen=-1) const
    {
        return GetLastElementByTypeAndText
        (cAtomInterface::e_TYPE_PARENT_ELEMENT, text, textlen);
    }

    /**
     **********************************************************************
     * Function: GetElementByAttributeValue
     *
     *   Author: $author$
     *     Date: 8/30/2003
     **********************************************************************
     */
     cElementInterface *GetElementByAttributeValue
     (const char *name, const char *value) const;

    /**
     **********************************************************************
     * Function: PutTextToStream
     *
     *   Author: $author$
     *     Date: 8/30/2003
     **********************************************************************
     */
     int PutTextToStream
     (cCharStream &stream,
      bool exclude_whitespace=false,
      bool include_attributes=false) const;

    /**
     **********************************************************************
     * Function: PutXMLToStream
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
     int PutXMLToStream
     (cCharStream &stream,
      bool exclude_whitespace=false,
      bool exclude_comments=false,
      bool exclude_multiple_root_elements=false) const;

    /**
     **********************************************************************
     * Function: AddCommentElement
     *
     *   Author: $author$
     *     Date: 8/24/2003
     **********************************************************************
     */
    inline cElementInterface *AddCommentElement
    (const char *text="",int textlen=-1,
     unsigned type=cAtomInterface::e_TYPE_COMMENT_ELEMENT)
    {
        return AddElement(text, textlen, type);
    }
    /**
     **********************************************************************
     * Function: AddTextElement
     *
     *   Author: $author$
     *     Date: 8/24/2003
     **********************************************************************
     */
    inline cElementInterface *AddTextElement
    (const char *text="",int textlen=-1,
     unsigned type=cAtomInterface::e_TYPE_TEXT_ELEMENT)
    {
        return AddElement(text, textlen, type);
    }
    /**
     **********************************************************************
     * Function: AddParentElement
     *
     *   Author: $author$
     *     Date: 8/24/2003
     **********************************************************************
     */
    inline cElementInterface *AddParentElement
    (const char *text="",int textlen=-1,
     unsigned type=cAtomInterface::e_TYPE_PARENT_ELEMENT)
    {
        return AddElement(text, textlen, type);
    }
};

/**
 **********************************************************************
 *  Class: cAttributeSetInterface
 *
 * Author: $author$
 *   Date: 8/19/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cAttributeSetInterface
: virtual public cArtifactInterface
{
public:
    /**
     **********************************************************************
     * Function: GetFirstAttribute
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetFirstAttribute() const=0;
    /**
     **********************************************************************
     * Function: GetLastAttribute
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetLastAttribute() const=0;

    /**
     **********************************************************************
     * Function: GetFirstAttributeByName
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetFirstAttributeByName
    (const char *name, int namelen=-1) const=0;
    /**
     **********************************************************************
     * Function: GetLastAttributeByName
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetLastAttributeByName
    (const char *name, int namelen=-1) const=0;

    /**
     **********************************************************************
     * Function: AddAttribute
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cAttributeInterface *AddAttribute
    (const char *name="",int namelen=-1,
     const char *text="",int textlen=-1)=0;
    /**
     **********************************************************************
     * Function: DeleteAttribute
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError DeleteAttribute
    (cAttributeInterface *attribute)=0;
    /**
     **********************************************************************
     * Function: DeleteAllAttributes
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError DeleteAllAttributes()=0;

    /**
     **********************************************************************
     * Function: GetFirstAttributeByNameAndValue
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    cAttributeInterface *GetFirstAttributeByNameAndValue
    (const char *name, const char *value) const;
};

/**
 **********************************************************************
 *  Class: cAttributeInterface
 *
 * Author: $author$
 *   Date: 8/19/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cAttributeInterface
: virtual public cAtomInterface
{
public:
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual int SetName(const char *name,int namelen=-1)=0;
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual const char *GetName(int &length) const=0;
    /**
     **********************************************************************
     * Function: GetNameLength
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual int GetNameLength() const=0;

    /**
     **********************************************************************
     * Function: GetNextAttribute
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetNextAttribute() const=0;
    /**
     **********************************************************************
     * Function: GetPreviousAttribute
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetPreviousAttribute() const=0;

    /**
     **********************************************************************
     * Function: GetNextAttributeByName
     *
     *   Author: $author$
     *     Date: 8/31/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetNextAttributeByName
    (const char *name, int namelen=-1) const=0;
    /**
     **********************************************************************
     * Function: GetPreviousAttributeByName
     *
     *   Author: $author$
     *     Date: 8/31/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetPreviousAttributeByName
    (const char *name, int namelen=-1) const=0;

    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    inline const char *GetName() const
    {
        int length;
        return GetName(length);
    }
};

/**
 **********************************************************************
 *  Class: cElementInterface
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cElementInterface
: virtual public cAttributeSetInterface,
  virtual public cElementSetInterface,
  virtual public cAtomInterface
{
public:
    /**
     **********************************************************************
     * Function: GetNextElement
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual cElementInterface *GetNextElement() const=0;
    /**
     **********************************************************************
     * Function: GetPreviousElement
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual cElementInterface *GetPreviousElement() const=0;

    /**
     **********************************************************************
     * Function: PutToStream
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
     virtual int PutToStream
     (cCharStream &stream,
      bool exclude_whitespace=false,
      bool exclude_comments=false) const=0;

    /**
     **********************************************************************
     * Function: GetNextElementByType
     *
     *   Author: $author$
     *     Date: 1/1/2004
     **********************************************************************
     */
    cElementInterface *GetNextElementByType(unsigned type) const;
    /**
     **********************************************************************
     * Function: GetPreviousElementByType
     *
     *   Author: $author$
     *     Date: 1/1/2004
     **********************************************************************
     */
    cElementInterface *GetPreviousElementByType(unsigned type) const;

    /**
     **********************************************************************
     * Function: GetNextElementByText
     *
     *   Author: $author$
     *     Date: 1/1/2004
     **********************************************************************
     */
    cElementInterface *GetNextElementByText
    (const char *text, int textlen=-1) const;
    /**
     **********************************************************************
     * Function: GetPreviousElementByText
     *
     *   Author: $author$
     *     Date: 1/1/2004
     **********************************************************************
     */
    cElementInterface *GetPreviousElementByText
    (const char *text, int textlen=-1) const;

    /**
     **********************************************************************
     * Function: GetNextElementByTypeAndText
     *
     *   Author: $author$
     *     Date: 1/1/2004
     **********************************************************************
     */
    cElementInterface *GetNextElementByTypeAndText
    (unsigned type, const char *text, int textlen=-1) const;
    /**
     **********************************************************************
     * Function: GetPreviousElementByTypeAndText
     *
     *   Author: $author$
     *     Date: 1/1/2004
     **********************************************************************
     */
    cElementInterface *GetPreviousElementByTypeAndText
    (unsigned type, const char *text, int textlen=-1) const;

    /**
     **********************************************************************
     * Function: GetNextParentElement
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    inline cElementInterface *GetNextParentElement() const
    {
        return GetNextElementByType
        (e_TYPE_PARENT_ELEMENT);
    }
    /**
     **********************************************************************
     * Function: GetNextParentElementByText
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    inline cElementInterface *GetNextParentElementByText
    (const char *text, int textlen=-1) const
    {
        return GetNextElementByTypeAndText
        (e_TYPE_PARENT_ELEMENT, text, textlen);
    }
    /**
     **********************************************************************
     * Function: GetPreviousParentElementByText
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    inline cElementInterface *GetPreviousParentElementByText
    (const char *text, int textlen=-1) const
    {
        return GetPreviousElementByTypeAndText
        (e_TYPE_PARENT_ELEMENT, text, textlen);
    }

    /**
     **********************************************************************
     * Function: PutTextToStream
     *
     *   Author: $author$
     *     Date: 8/30/2003
     **********************************************************************
     */
     int PutTextToStream
     (cCharStream &stream,
      bool exclude_whitespace=false,
      bool include_attributes=false) const;

    /**
     **********************************************************************
     * Function: PutXMLToStream
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
     int PutXMLToStream
     (cCharStream &stream,
      bool exclude_whitespace=false,
      bool exclude_comments=false) const;
};

/**
 **********************************************************************
 *  Class: cDocumentCreatorInterface
 *
 * Author: $author$
 *   Date: 9/1/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentCreatorInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: CreateDocument
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocument()=0;
    /**
     **********************************************************************
     * Function: DestroyDocument
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError DestroyDocument(cDocumentInterface *document)=0;
};

/**
 **********************************************************************
 *  Class: cDocumentTypeInterface
 *
 * Author: $author$
 *   Date: 9/1/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentTypeInterface
: virtual public cDocumentCreatorInterface
{
public:
    /**
     **********************************************************************
     * Function: GetDocumentType
     *
     *   Author: $author$
     *     Date: 9/1/2003
     **********************************************************************
     */
    virtual const char *GetDocumentType(int &length) const=0;
    /**
     **********************************************************************
     * Function: GetContentType
     *
     *   Author: $author$
     *     Date: 9/1/2003
     **********************************************************************
     */
    virtual const char *GetContentType(int &length) const=0;

    /**
     **********************************************************************
     * Function: GetFirstFileExtension
     *
     *   Author: $author$
     *     Date: 9/2/2003
     **********************************************************************
     */
    virtual const char *GetFirstFileExtension(int &length) const=0;
    /**
     **********************************************************************
     * Function: GetNextFileExtension
     *
     *   Author: $author$
     *     Date: 9/2/2003
     **********************************************************************
     */
    virtual const char *GetNextFileExtension
    (int &length, const char *file_extension) const=0;
};

/**
 **********************************************************************
 *  Class: cDocumentFactoryInterface
 *
 * Author: $author$
 *   Date: 9/1/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentFactoryInterface
: virtual public cDocumentCreatorInterface
{
public:
    /**
     **********************************************************************
     * Function: CreateDocumentByFileExtension
     *
     *   Author: $author$
     *     Date: 9/3/2003
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocumentByFileExtension
    (const char *file_extension, int file_extensionlen=-1)=0;
    /**
     **********************************************************************
     * Function: CreateDocumentByContentType
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocumentByContentType
    (const char *content_type, int content_typelen=-1)=0;
    /**
     **********************************************************************
     * Function: CreateDocumentByType
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocumentByType
    (const char *document_type, int document_typelen=-1)=0;
};

class c_INTERFACE_CLASS cTransformInterface;

/**
 **********************************************************************
 *  Class: cDocumentInterface
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentInterface
: virtual public cElementSetInterface,
  virtual public cDocumentTypeInterface,
  virtual public cDocumentFactoryInterface
{
public:
    /**
     **********************************************************************
     * Function: ParseFromFile
     *
     *   Author: $author$
     *     Date: 5/19/2003
     **********************************************************************
     */
    virtual eError ParseFromFile
    (const char *filename, const char *uri=0)=0;
    /**
     **********************************************************************
     * Function: ParseFromStream
     *
     *   Author: $author$
     *     Date: 8/29/2003
     **********************************************************************
     */
    virtual eError ParseFromStream
    (cCharStream &stream, const char *filename=0, const char *uri=0)=0;

    /**
     **********************************************************************
     * Function: TransformToStream
     *
     *   Author: $author$
     *     Date: 9/5/2003
     **********************************************************************
     */
    virtual eError TransformToStream
    (cCharStream &stream, cDocumentInterface *document=0)=0;

    /**
     **********************************************************************
     * Function: SetTransform
     *
     *   Author: $author$
     *     Date: 9/5/2003
     **********************************************************************
     */
    virtual cTransformInterface *SetTransform(cTransformInterface *transform)=0;
    /**
     **********************************************************************
     * Function: GetTransform
     *
     *   Author: $author$
     *     Date: 9/5/2003
     **********************************************************************
     */
    virtual cTransformInterface *GetTransform() const=0;

    /**
     **********************************************************************
     * Function: SetFileName
     *
     *   Author: $author$
     *     Date: 1/16/2004
     **********************************************************************
     */
    virtual const char *SetFileName(const char *filename)=0;
    /**
     **********************************************************************
     * Function: GetFileName
     *
     *   Author: $author$
     *     Date: 1/16/2004
     **********************************************************************
     */
    virtual const char *GetFileName() const=0;

    /**
     **********************************************************************
     * Function: SetURI
     *
     *   Author: $author$
     *     Date: 1/16/2004
     **********************************************************************
     */
    virtual const char *SetURI(const char *uri)=0;
    /**
     **********************************************************************
     * Function: GetURI
     *
     *   Author: $author$
     *     Date: 1/16/2004
     **********************************************************************
     */
    virtual const char *GetURI() const=0;

    /**
     **********************************************************************
     * Function: SetNamespaceDesignator
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual eError SetNamespaceDesignator(const char *value, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetNamespaceDesignator
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual const char *GetNamespaceDesignator(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetNamespaceSeparator
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual eError SetNamespaceSeparator(const char *value, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetNamespaceSeparator
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual const char *GetNamespaceSeparator(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetIsXMLContentType
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual bool SetIsXMLContentType(bool is_xml_content_type=true)=0;
    /**
     **********************************************************************
     * Function: GetIsXMLContentType
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual bool GetIsXMLContentType() const=0;

    /**
     **********************************************************************
     * Function: SetIsTextContentType
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual bool SetIsTextContentType(bool is_xml_content_type=true)=0;
    /**
     **********************************************************************
     * Function: GetIsTextContentType
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual bool GetIsTextContentType() const=0;
};

#endif
