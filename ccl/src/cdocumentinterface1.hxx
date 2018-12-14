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
 *   Date: 7/15/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTINTERFACE_HXX
#define _CDOCUMENTINTERFACE_HXX

#include "cinterface.hxx"
#include "ccharbuffer.hxx"
#include "clistt.hxx"

class c_INTERFACE_CLASS cTransformInterface;

/**
 **********************************************************************
 *  Class: cDocumentInterface
 *
 * Author: $author$
 *   Date: 7/15/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentInterface
: virtual public cInterface
{
public:
    class c_INTERFACE_CLASS cAttributeInterface;
    class c_INTERFACE_CLASS cElementInterface;
    class c_INTERFACE_CLASS cElementSetInterface;

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
         * Function: SetParentDocument
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual eError SetParentDocument(cDocumentInterface *parent_document)=0;
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
        virtual eError SetParentElement(cElementInterface *parent_element)=0;
        /**
         **********************************************************************
         * Function: GetParentElement
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual cElementInterface *GetParentElement() const=0;
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
         * Function: GetTypeText
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
		virtual const char *GetTypeText() const=0;
        /**
         **********************************************************************
         * Function: SetText
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual eError SetText(const char *text,int length=-1)=0;
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
         * Function: GetTextPrefix
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
		virtual const char *GetTextPrefix
        (int &length,char separator=':') const=0;
        /**
         **********************************************************************
         * Function: SetTextBuffer
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
		virtual eError SetTextBuffer(cCharBuffer *buffer)=0;
        /**
         **********************************************************************
         * Function: GetTextBuffer
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
		virtual cCharBuffer *GetTextBuffer() const=0;
        /**
         **********************************************************************
         * Function: SetData
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual eError SetData(void *data)=0;
        /**
         **********************************************************************
         * Function: GetDat
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual void *GetData() const=0;
        /**
         **********************************************************************
         * Function: SetStream
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual eError SetStream(cCharStream *stream)=0;
        /**
         **********************************************************************
         * Function: GetStream
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual cCharStream *GetStream() const=0;
        /**
         **********************************************************************
         * Function: SetTransform
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual eError SetTransform(cTransformInterface *transform)=0;
        /**
         **********************************************************************
         * Function: GetTransform
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual cTransformInterface *GetTransform() const=0;
        /**
         **********************************************************************
         * Function: GetNamespacePrefix
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
		virtual const char *GetNamespacePrefix(int &length) const=0;
        /**
         **********************************************************************
         * Function: CreateDocument
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual cDocumentInterface *CreateDocument() const=0;

        /**
         **********************************************************************
         * Function: CompareText
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        int CompareText(cAtomInterface &to) const
        {
            int cmp;
            int textlen;
            const char *text;
            const char *text2;

            if ((text=GetText(textlen)))
                if ((text2=to.GetText()))
                {
                    if ((cmp=strcmp(text,text2)))
                        return cmp;
                }
                else
                {
                    if (textlen>0)
                        return 1;
                }
            else
            {
                if (to.GetTextLength()>0)
                    return -1;
            }

            return 0;
        }

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
         * Function: AddAttribute
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual eError AddAttribute
        (cAttributeInterface *&attribute,
         const char *name="",int namelen=-1,
         const char *text="",int textlen=-1)=0;
        /**
         **********************************************************************
         * Function: AddQualifiedAttribute
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual eError AddQualifiedAttribute
        (cAttributeInterface *&attribute,
         const char *prefix="",int prefixlen=-1,
         const char *name="",int namelen=-1,
         const char *text="",int textlen=-1,
         char separator=':')=0;
        /**
         **********************************************************************
         * Function: AddQualifiedAttributeWithQualifiedText
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual eError AddQualifiedAttributeWithQualifiedText
        (cAttributeInterface *&attribute,
         const char *prefix="",int prefixlen=-1,
         const char *name="",int namelen=-1,
         const char *text_prefix="",int text_prefixlen=-1,
         const char *text="",int textlen=-1,
         char separator=':')=0;

        /**
         **********************************************************************
         * Function: DeleteAttribute
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual eError DeleteAttribute(cAttributeInterface &attribute)=0;
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
        (const char *name,int namelen=-1) const=0;
        /**
         **********************************************************************
         * Function: GetLastAttributeByName
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual cAttributeInterface *GetLastAttributeByName
        (const char *name,int namelen=-1) const=0;
        /**
         **********************************************************************
         * Function: GetFirstAttributeByText
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual cAttributeInterface *GetFirstAttributeByText
        (const char *text,int textlen=-1) const=0;
        /**
         **********************************************************************
         * Function: GetLastAttributeByText
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual cAttributeInterface *GetLastAttributeByText
        (const char *text,int textlen=-1) const=0;
        /**
         **********************************************************************
         * Function: 
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
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
        virtual eError SetName(const char *name,int namelen=-1)=0;
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
         * Function: GetNamePrefix
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
	    virtual const char *GetNamePrefix
        (int &length,char separator=':') const=0;
        /**
         **********************************************************************
         * Function: GetNamespacePrefixName
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
	    virtual const char *GetNamespacePrefixName
        (int &length,char separator=':') const=0;

        /**
         **********************************************************************
         * Function: GetNext
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual cAttributeInterface *GetNext() const=0;
        /**
         **********************************************************************
         * Function: GetPrevious
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual cAttributeInterface *GetPrevious() const=0;
        /**
         **********************************************************************
         * Function: GetNextByName
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual cAttributeInterface *GetNextByName
        (const char *name,int namelen=-1) const=0;
        /**
         **********************************************************************
         * Function: GetPreviousByName
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual cAttributeInterface *GetPreviousByName
        (const char *name,int namelen=-1) const=0;
        /**
         **********************************************************************
         * Function: GetNextByText
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual cAttributeInterface *GetNextByText
        (const char *text,int textlen=-1) const=0;
        /**
         **********************************************************************
         * Function: GetPreviousByText
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual cAttributeInterface *GetPreviousByText
        (const char *text,int textlen=-1) const=0;

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
     *  Class: cAttributeInterfaceItem
     *
     * Author: $author$
     *   Date: 8/19/2003
     **********************************************************************
     */
    class cAttributeInterfaceItem
    : virtual public cAttributeInterface,
      public cDynamicListItemT
      <cAttributeInterfaceItem, cDynamicImplement>
    {
    public:
        typedef cDynamicListItemT
        <cAttributeInterfaceItem, cDynamicImplement> cListItemIs;
    };

    /**
     **********************************************************************
     *  Class: cAttributeInterfaceList
     *
     * Author: $author$
     *   Date: 8/19/2003
     **********************************************************************
     */
    class cAttributeInterfaceList
    : public cDynamicListT
      <cAttributeInterfaceItem, cAttributeInterfaceList>
    {
    public:
        typedef cDynamicListT
        <cAttributeInterfaceItem, cAttributeInterfaceList> cIs;

        /**
         **********************************************************************
         * Function: Free
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual eError Free(cAttributeInterfaceItem *item)
        {
            eError error;

            if ((error = item->FreeInstance()))
                return e_ERROR_FREE;

            return e_ERROR_NONE;
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
         * Function: 
         *
         *   Author: $author$
         *     Date: 8/19/2003
         **********************************************************************
         */
        virtual cElementInterface *GetFirstElement() const=0;
        virtual cElementInterface *GetLastElement() const=0;

        virtual eError CreateElement
        (cElementInterface *&element,
         const char *text="",int textlen=-1,
         unsigned type=cAtomInterface::e_TYPE_PARENT_ELEMENT)=0;
        virtual eError AddElement
        (cElementInterface *&element,
         const char *text="",int textlen=-1,
         unsigned type=cAtomInterface::e_TYPE_PARENT_ELEMENT)=0;
        virtual eError AddReferenceElement
        (cElementInterface *&reference,cElementInterface &element)=0;
        virtual eError DeleteElement(cElementInterface &element)=0;
        virtual eError DeleteAllElements()=0;
        virtual cElementInterface *GetFirstElementByType(unsigned type) const=0;
        virtual cElementInterface *GetLastElementByType(unsigned type) const=0;
        virtual cElementInterface *GetFirstElementByText(const char *text,int textlen=-1) const=0;
        virtual cElementInterface *GetLastElementByText(const char *text,int textlen=-1) const=0;
        virtual cElementInterface *GetFirstElementByTypeAndText
        (unsigned type,const char *text,int textlen=-1) const=0;
        virtual cElementInterface *GetLastElementByTypeAndText
        (unsigned type,const char *text,int textlen=-1) const=0;
        virtual eError AddQualifiedParentElement
        (cElementInterface *&element,
         const char *prefix="",int prefixlen=-1,
         const char *text="",int textlen=-1,
         char separator=':')=0;
        virtual eError PutToStream
        (cCharStream &stream,
         bool exclude_multiple_root_elements=false,
         bool exclude_whitespace=false,
         bool exclude_comments=false) const=0;
        virtual eError PutXMLToStream
        (cCharStream &stream,
         bool exclude_multiple_root_elements=false,
         bool exclude_whitespace=false,
         bool exclude_comments=false) const=0;
        virtual eError PutTextToStream
        (cCharStream &stream,
         bool exclude_whitespace=false,
         bool include_attributes=false) const=0;
        virtual eError ParseFromStream
        (cCharStream &stream,
         bool include_multiple_elements=false,
         bool include_whitespace=false,
         bool include_comments=false)=0;

        int CompareAllText(cElementSetInterface &to) const
        {
            int cmp;
            cElementInterface *element;
            cElementInterface *element2;

            if ((element=GetFirstElement()))
                if ((element2=to.GetFirstElement()))
                {
                    do
                    {
                        if ((cmp=element->CompareAllText(*element2)))
                            return cmp;

                        if (!(element=element->GetNext()))
                        {
                            while ((element2=element2->GetNext()))
                                if ((cmp=element2->CompareBlankText()))
                                    return -cmp;
                            break;
                        }
                        else if (!(element2=element2->GetNext()))
                        {
                            while ((element=element->GetNext()))
                                if ((cmp=element->CompareBlankText()))
                                    return cmp;
                            break;
                        }
                    }
                    while (element && element2);
                }
                else
                {
                    while ((element=element->GetNext()))
                        if ((cmp=element->CompareBlankText()))
                            return cmp;
                }
            else if ((element2=to.GetFirstElement()))
            {
                while ((element2=element2->GetNext()))
                    if ((cmp=element2->CompareBlankText()))
                        return -cmp;
            }

            return 0;
        }

        inline cElementInterface *GetFirstParentElement()
        {
            return GetFirstElementByType
            (cAtomInterface::e_TYPE_PARENT_ELEMENT);
        }
        inline cElementInterface *GetLastParentElement()
        {
            return GetLastElementByType
            (cAtomInterface::e_TYPE_PARENT_ELEMENT);
        }
        inline cElementInterface *GetFirstTextElement()
        {
            return GetFirstElementByType
            (cAtomInterface::e_TYPE_TEXT_ELEMENT);
        }
        inline cElementInterface *GetLastTextElement()
        {
            return GetLastElementByType
            (cAtomInterface::e_TYPE_TEXT_ELEMENT);
        }
        inline cElementInterface *GetFirstCommentElement()
        {
            return GetFirstElementByType
            (cAtomInterface::e_TYPE_COMMENT_ELEMENT);
        }
        inline cElementInterface *GetLastCommentElement()
        {
            return GetLastElementByType
            (cAtomInterface::e_TYPE_COMMENT_ELEMENT);
        }
        inline cElementInterface *GetFirstTextOrParentElement()
        {
            return GetFirstElementByType
            (cAtomInterface::e_TYPE_TEXT_ELEMENT|
             cAtomInterface::e_TYPE_PARENT_ELEMENT);
        }
        inline cElementInterface *GetLastTextOrParentElement()
        {
            return GetLastElementByType
            (cAtomInterface::e_TYPE_TEXT_ELEMENT|
             cAtomInterface::e_TYPE_PARENT_ELEMENT);
        }

        inline cElementInterface *GetFirstParentElementByText
        (const char *text,int textlen=-1)
        {
            return GetFirstElementByTypeAndText
            (cAtomInterface::e_TYPE_PARENT_ELEMENT,text,textlen);
        }
        inline cElementInterface *GetLastParentElementByText
        (const char *text,int textlen=-1)
        {
            return GetLastElementByTypeAndText
            (cAtomInterface::e_TYPE_PARENT_ELEMENT,text,textlen);
        }

        inline eError AddUndefinedElement
        (cElementInterface *&element,
         const char *text="",int textlen=-1)
        {
            return AddElement
            (element,text,textlen,
             cAtomInterface::e_TYPE_UNDEFINED);
        }
        inline eError AddParentElement
        (const char *text="",int textlen=-1)
        {
            cElementInterface *element;
            return AddParentElement(element,text,textlen);
        }
        inline eError AddParentElement
        (cElementInterface *&element,
         const char *text="",int textlen=-1)
        {
            return AddElement
            (element,text,textlen,
             cAtomInterface::e_TYPE_PARENT_ELEMENT);
        }
        inline eError AddTextElement
        (const char *text="",int textlen=-1)
        {
            cElementInterface *element;
            return AddTextElement(element,text,textlen);
        }
        inline eError AddTextElement
        (cElementInterface *&element,
         const char *text="",int textlen=-1)
        {
            return AddElement
            (element,text,textlen,
             cAtomInterface::e_TYPE_TEXT_ELEMENT);
        }
        inline eError AddCommentElement
        (const char *text="",int textlen=-1)
        {
            cElementInterface *element;
            return AddCommentElement(element,text,textlen);
        }
        inline eError AddCommentElement
        (cElementInterface *&element,
         const char *text="",int textlen=-1)
        {
            return AddElement
            (element,text,textlen,
             cAtomInterface::e_TYPE_COMMENT_ELEMENT);
        }

        inline eError ReferenceElements
        (cElementSetInterface &element_set)
        {
            eError error;
            cElementInterface *element;

            for (element=element_set.GetFirstElement(); 
                 element; element=element->GetNext())
            {
                if ((error=ReferenceElement(*element)))
                    return error;
            }
            return e_ERROR_NONE;
        }
        inline eError ReferenceElement(cElementInterface &element)
        {
            cElementInterface *reference;

            return AddReferenceElement(reference,element);
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
         * Function: 
         *
         *   Author: $author$
         *     Date: 8/22/2003
         **********************************************************************
         */
        virtual cElementInterface *GetNext() const=0;
        virtual cElementInterface *GetPrevious() const=0;
        virtual cElementInterface *GetNextByType(unsigned type) const=0;
        virtual cElementInterface *GetPreviousByType(unsigned type) const=0;
        virtual cElementInterface *GetNextByText(const char *text,int textlen=-1) const=0;
        virtual cElementInterface *GetPreviousByText(const char *text,int textlen=-1) const=0;
        virtual cElementInterface *GetNextByTypeAndText
        (unsigned type,const char *text,int textlen=-1) const=0;
        virtual cElementInterface *GetPreviousByTypeAndText
        (unsigned type,const char *text,int textlen=-1) const=0;

        virtual const char *GetNamespace
        (int &length,const char *parent_namespace=0,int parent_namespacelen=-1,
         const char *parent_namespace_prefix=0,int parent_namespace_prefixlen=-1,
         char separator=':') const=0;
        virtual const char *GetUnqualifiedName
        (int &length,char separator=':') const=0;
        virtual eError SetQualifiedName
        (const char *element_prefix,int element_prefixlen,
         const char *element_name,int element_namelen=-1,
         const char *element_namespace=0,int element_namespacelen=-1,
         const char *namespace_prefix=0,int namespace_prefixlen=-1,
         char separator=':')=0;
        virtual eError SetQualifiedNameWithQualifiedNamespace
        (const char *element_prefix,int element_prefixlen,
         const char *element_name,int element_namelen,
         const char *element_namespace_prefix,int element_namespace_prefixlen,
         const char *element_namespace,int element_namespacelen,
         const char *namespace_prefix=0,int namespace_prefixlen=-1,
         char separator=':')=0;
        virtual bool MatchQualifiedName
        (const char *element_namespace,int element_namespacelen,
         const char *element_name,int element_namelen,
         const char *parent_namespace=0,int parent_namespacelen=-1,
         const char *parent_namespace_prefix=0,int parent_namespace_prefixlen=-1,
         char separator=':') const=0;

        virtual eError PutToStream
        (cCharStream &stream,
         bool exclude_whitespace=false,
         bool exclude_comments=false) const=0;
        virtual eError PutTextToStream
        (cCharStream &stream,
         bool exclude_whitespace=false,
         bool include_attributes=false) const=0;
        virtual eError PutXMLToStream
        (cCharStream &stream,
         bool exclude_whitespace=false,
         bool exclude_comments=false) const=0;

        eError CopyAttributes(cElementInterface &element)
        {
            eError error;
            cAttributeInterface *attribute;
            cAttributeInterface *new_attribute;

            if ((attribute=element.GetFirstAttribute()))
            do
            {
                if ((error=AddAttribute
                    (new_attribute,
                     attribute->GetName(),attribute->GetNameLength(),
                     attribute->GetText(),attribute->GetTextLength())))
                     return e_ERROR_FAILED;
            }
            while ((attribute=attribute->GetNext()));

            return e_ERROR_NONE;
        }

        int CompareBlankText() const
        {
            int cmp;
            cElementInterface *element;

            if (GetTextLength()>0)
                return 1;

            if ((element=GetFirstElement()))
            do
            {
                if ((cmp=element->CompareBlankText()))
                    return cmp;
            }
            while ((element=element->GetNext()));

            return 0;
        }
        int CompareAllText(cElementInterface &to) const
        {
            int cmp;

            if ((cmp=cAtomInterface::CompareText(to)))
                return cmp;

            return cElementSetInterface::CompareAllText(to);
        }

        inline cElementInterface *GetNextParent() const
        {
            return GetNextByType(e_TYPE_PARENT_ELEMENT);
        }
        inline cElementInterface *GetPreviousParent() const
        {
            return GetPreviousByType(e_TYPE_PARENT_ELEMENT);
        }
        inline cElementInterface *GetNextText() const
        {
            return GetNextByType(e_TYPE_TEXT_ELEMENT);
        }
        inline cElementInterface *GetPreviousText() const
        {
            return GetPreviousByType(e_TYPE_TEXT_ELEMENT);
        }
        inline cElementInterface *GetNextTextOrParent() const
        {
            return GetNextByType
            (e_TYPE_TEXT_ELEMENT | e_TYPE_PARENT_ELEMENT);
        }
        inline cElementInterface *GetPreviousTextOrParent() const
        {
            return GetPreviousByType
            (e_TYPE_TEXT_ELEMENT | e_TYPE_PARENT_ELEMENT);
        }

        inline cElementInterface *GetNextParentByText
        (const char *text,int textlen=-1)
        {
            return GetNextByTypeAndText
            (e_TYPE_PARENT_ELEMENT,text,textlen);
        }
        inline cElementInterface *GetPreviousParentByText
        (const char *text,int textlen=-1)
        {
            return GetPreviousByTypeAndText
            (e_TYPE_PARENT_ELEMENT,text,textlen);
        }
    };

    /**
     **********************************************************************
     *  Class: cElementInterfaceItem
     *
     * Author: $author$
     *   Date: 8/22/2003
     **********************************************************************
     */
    class cElementInterfaceItem
    : virtual public cElementInterface,
      public cDynamicListItemT
      <cElementInterfaceItem, cDynamicImplement>
    {
    public:
        typedef cDynamicListItemT
        <cElementInterfaceItem, cDynamicImplement> cListItemIs;
    };

    /**
     **********************************************************************
     *  Class: cElementInterfaceList
     *
     * Author: $author$
     *   Date: 8/22/2003
     **********************************************************************
     */
    class cElementInterfaceList
    : public cDynamicListT
      <cElementInterfaceItem, cElementInterfaceList>
    {
    public:
        typedef cDynamicListT
        <cElementInterfaceItem, cElementInterfaceList> cIs;

        /**
         **********************************************************************
         * Function: Free
         *
         *   Author: $author$
         *     Date: 8/22/2003
         **********************************************************************
         */
        virtual eError Free(cElementInterfaceItem *item)
        {
            eError error;

            if ((error=item->FreeInstance()))
                return e_ERROR_FREE;

            return e_ERROR_NONE;
        }
    };

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual cElementSetInterface &GetElementSet()=0;
    virtual cTransformInterface *SetTransform
    (cTransformInterface *transform)=0;
    virtual cTransformInterface *GetTransform() const=0;
    virtual cDocumentInterface *CreateDocument() const=0;
    virtual eError TransformDocumentToStream
    (cCharStream &stream,
     cDocumentInterface &document,
     const char *document_uri=0,
     const char *document_filename=0,
     const char *template_uri=0,
     const char *template_filename=0)=0;
    virtual eError TransformToStream
    (cCharStream &stream,
     const char *template_uri=0,
     const char *template_filename=0)=0;
    virtual eError ParseFromStream
    (cCharStream &stream,
     bool include_multiple_elements=false,
     bool include_whitespace=false,
     bool include_comments=false)=0;
    virtual eError ParseFromFile
    (const char *filename,
     bool include_multiple_elements=false,
     bool include_whitespace=false,
     bool include_comments=false)=0;

    virtual eError PutToStream
    (cCharStream &stream,
     bool exclude_multiple_elements=false,
     bool exclude_whitespace=false,
     bool exclude_comments=false) const=0;
    virtual eError PutTextToStream
    (cCharStream &stream,
     bool exclude_multiple_elements=false,
     bool exclude_whitespace=false,
     bool exclude_comments=false) const=0;
    virtual eError PutXMLToStream
    (cCharStream &stream,
     bool exclude_multiple_elements=false,
     bool exclude_whitespace=false,
     bool exclude_comments=false) const=0;

    inline operator cElementSetInterface&()
    {
        return GetElementSet();
    }
};


#endif
