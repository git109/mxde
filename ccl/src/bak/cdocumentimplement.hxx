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
 *   File: cdocumentimplement.hxx
 *
 * Author: $author$
 *   Date: 8/22/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTIMPLEMENT_HXX
#define _CDOCUMENTIMPLEMENT_HXX

#include "ctransforminterface.hxx"
#include "cdocumentinterface.hxx"
#include "ccharfile.hxx"

/**
 **********************************************************************
 *  Class: cArtifactImplement
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cArtifactImplement
: virtual public cArtifactInterface
{
public:
    /**
     **********************************************************************
     * Function: GetDocument
     *
     *   Author: $author$
     *     Date: 8/31/2003
     **********************************************************************
     */
    virtual cDocumentInterface *GetDocument() const
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetElement
     *
     *   Author: $author$
     *     Date: 8/31/2003
     **********************************************************************
     */
    virtual cElementInterface *GetElement() const
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetAttribute
     *
     *   Author: $author$
     *     Date: 2/16/2004
     **********************************************************************
     */
    virtual cAttributeInterface *GetAttribute() const
    {
        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cAtomImplement
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cAtomImplement
: virtual public cAtomInterface,
  virtual public cArtifactImplement
{
public:
    /**
     **********************************************************************
     * Function: GetTextNamespacePrefix
     *
     *   Author: $author$
     *     Date: 2/9/2004
     **********************************************************************
     */
	virtual const char *GetTextNamespacePrefix(int &length) const
    {
        int separator_length,text_length;
        const char *separator,*text;
        cDocumentInterface *document;

        if ((text = GetText(text_length)))
        if ((document = GetParentDocument()))
        if ((separator = document->GetNamespaceSeparator(separator_length)))
        if ((separator = strstr(text, separator)))
        {
            length = separator-text;
            return text;
        }
        length=0;
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetTextAfterNamespacePrefix
     *
     *   Author: $author$
     *     Date: 8/14/2004
     **********************************************************************
     */
	virtual const char *GetTextAfterNamespacePrefix(int &length) const
    {
        int separator_length,text_length;
        const char *separator,*text;
        cDocumentInterface *document;

        if ((text = GetText(text_length)))
        if ((document = GetParentDocument()))
        if ((separator = document->GetNamespaceSeparator(separator_length)))
        if ((separator = strstr(text, separator)))
        {
            length = text_length-separator_length-(separator-text);
            return text+separator_length+(separator-text);
        }
        length=0;
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetTextNamespace
     *
     *   Author: $author$
     *     Date: 2/9/2004
     **********************************************************************
     */
	virtual const char *GetTextNamespace(int &length) const
    {
        length=0;
        return 0;
    }
    /**
     **********************************************************************
     * Function: CompareText
     *
     *   Author: $author$
     *     Date: 1/1/2004
     **********************************************************************
     */
	virtual int CompareText(const char *text, int textlen=-1) const
    {
        int unequal,equal;
        int etextlen;
        const char *etext;

        if ((etext = GetText(etextlen)))
        {
            if (textlen < 0)
                textlen = strlen(text);

            if ((equal = (textlen > etextlen)))
                textlen = etextlen;

            else if (textlen < etextlen)
                    equal = -1;

            if ((unequal = strncmp(text, etext, textlen)))
                return unequal;

            return equal;
        }
        else if (text)
                return 1;

        else return -1;
    }
};

/**
 **********************************************************************
 *  Class: cAttributeImplement
 *
 * Author: $author$
 *   Date: 8/31/2003
 **********************************************************************
 */
class cAttributeImplement
: virtual public cAttributeInterface,
  virtual public cArtifactImplement,
  virtual public cAtomImplement
{
public:
    /**
     **********************************************************************
     * Function: GetNextAttributeByName
     *
     *   Author: $author$
     *     Date: 8/31/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetNextAttributeByName
    (const char *name, int namelen) const
    {
        int atnamelen;
        const char *atname;
        cAttributeInterface *at;

        if ((at = GetNextAttribute()))
        {
            if (namelen < 0)
                namelen = strlen(name);

            do
            {
                if ((atname=at->GetName(atnamelen)))
                if (atnamelen == namelen)
                if (!strncmp(atname, name, namelen))
                    return at;
            }
            while((at = at->GetNextAttribute()));
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetPreviousAttributeByName
     *
     *   Author: $author$
     *     Date: 8/31/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetPreviousAttributeByName
    (const char *name, int namelen) const
    {
        int atnamelen;
        const char *atname;
        cAttributeInterface *at;

        if ((at = GetPreviousAttribute()))
        {
            if (namelen < 0)
                namelen = strlen(name);

            do
            {
                if ((atname=at->GetName(atnamelen)))
                if (atnamelen == namelen)
                if (!strncmp(atname, name, namelen))
                    return at;
            }
            while((at = at->GetPreviousAttribute()));
        }
        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cAttributeSetImplement
 *
 * Author: $author$
 *   Date: 8/31/2003
 **********************************************************************
 */
class cAttributeSetImplement
: virtual public cAttributeSetInterface,
  virtual public cArtifactImplement
{
public:
    /**
     **********************************************************************
     * Function: GetFirstAttributeByName
     *
     *   Author: $author$
     *     Date: 8/31/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetFirstAttributeByName
    (const char *name, int namelen) const
    {
        int atnamelen;
        const char *atname;
        cAttributeInterface *at;

        if ((at = GetFirstAttribute()))
        {
            if (namelen < 0)
                namelen = strlen(name);

            if ((atname=at->GetName(atnamelen)))
            if (atnamelen == namelen)
            if (!strncmp(atname, name, namelen))
                return at;

            return at->GetNextAttributeByName(name, namelen);
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetLastAttributeByName
     *
     *   Author: $author$
     *     Date: 8/31/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetLastAttributeByName
    (const char *name, int namelen) const
    {
        int atnamelen;
        const char *atname;
        cAttributeInterface *at;

        if ((at = GetLastAttribute()))
        {
            if (namelen < 0)
                namelen = strlen(name);

            if ((atname=at->GetName(atnamelen)))
            if (atnamelen == namelen)
            if (!strncmp(atname, name, namelen))
                return at;

            return at->GetPreviousAttributeByName(name, namelen);
        }
        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cElementSetImplement
 *
 * Author: $author$
 *   Date: 9/3/2003
 **********************************************************************
 */
class cElementSetImplement
: virtual public cElementSetInterface,
  virtual public cArtifactImplement
{
public:
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
      bool exclude_multiple_root_elements=false) const
     {
         cDocumentInterface *parent;

         if ((parent = GetParentDocument()))
         {
             if (parent->GetIsXMLContentType())
                 return PutXMLToStream
                 (stream,exclude_whitespace,
                  exclude_comments,exclude_multiple_root_elements);

             if (parent->GetIsTextContentType())
                 return PutTextToStream
                 (stream,exclude_whitespace);
         }

         return -e_ERROR_NOT_DEFINED;
     }
};

/**
 **********************************************************************
 *  Class: cElementImplement
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cElementImplement
: virtual public cElementInterface,
  virtual public cArtifactImplement,
  virtual public cAtomImplement,
  virtual public cElementSetImplement,
  virtual public cAttributeSetImplement
{
public:
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
      bool exclude_comments=false) const
     {
         cDocumentInterface *parent;

         if ((parent = GetParentDocument()))
         if (parent->GetIsXMLContentType())
             return PutXMLToStream
             (stream,exclude_whitespace,exclude_comments);

         return -e_ERROR_NOT_DEFINED;
     }
};

/**
 **********************************************************************
 *  Class: cDocumentCreatorImplement
 *
 * Author: $author$
 *   Date: 9/1/2003
 **********************************************************************
 */
class cDocumentCreatorImplement
: virtual public cDocumentCreatorInterface
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
    virtual cDocumentInterface *CreateDocument()
    {
        SetLastError(e_ERROR_NOT_IMPLEMENTED);
        return 0;
    }
    /**
     **********************************************************************
     * Function: DestroyDocument
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError DestroyDocument(cDocumentInterface *document)
    {
        eError error;

        if ((error = document->FreeInstance()))
            return e_ERROR_FREE_INSTANCE;

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentTypeImplement
 *
 * Author: $author$
 *   Date: 9/1/2003
 **********************************************************************
 */
class cDocumentTypeImplement
: virtual public cDocumentTypeInterface,
  virtual public cDocumentCreatorImplement
{
public:
    /**
     **********************************************************************
     * Function: GetIsDefault
     *
     *   Author: $author$
     *     Date: 9/2/2003
     **********************************************************************
     */
    virtual bool GetIsDefault() const
    {
        return false;
    }
    /**
     **********************************************************************
     * Function: GetDocumentType
     *
     *   Author: $author$
     *     Date: 9/1/2003
     **********************************************************************
     */
    virtual const char *GetDocumentType(int &length) const
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetContentType
     *
     *   Author: $author$
     *     Date: 9/1/2003
     **********************************************************************
     */
    virtual const char *GetContentType(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: GetFirstFileExtension
     *
     *   Author: $author$
     *     Date: 9/2/2003
     **********************************************************************
     */
    virtual const char *GetFirstFileExtension(int &length) const
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetNextFileExtension
     *
     *   Author: $author$
     *     Date: 9/2/2003
     **********************************************************************
     */
    virtual const char *GetNextFileExtension
    (int &length, const char *file_extension) const
    {
        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentFactoryImplement
 *
 * Author: $author$
 *   Date: 9/1/2003
 **********************************************************************
 */
class cDocumentFactoryImplement
: virtual public cDocumentFactoryInterface,
  virtual public cDocumentCreatorImplement
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
    (const char *file_extension, int file_extensionlen=-1)
    {
        SetLastError(e_ERROR_NOT_IMPLEMENTED);
        return 0;
    }
    /**
     **********************************************************************
     * Function: CreateDocumentByContentType
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocumentByContentType
    (const char *content_type, int content_typelen=-1)
    {
        SetLastError(e_ERROR_NOT_IMPLEMENTED);
        return 0;
    }
    /**
     **********************************************************************
     * Function: CreateDocumentByType
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocumentByType
    (const char *document_type, int document_typelen=-1)
    {
        SetLastError(e_ERROR_NOT_IMPLEMENTED);
        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentImplement
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cDocumentImplement
: virtual public cDocumentInterface,
  virtual public cArtifactImplement,
  virtual public cElementSetImplement,
  virtual public cDocumentCreatorImplement,
  virtual public cDocumentTypeImplement,
  virtual public cDocumentFactoryImplement
{
public:
    /**
     **********************************************************************
     * Function: GetDocument
     *
     *   Author: $author$
     *     Date: 8/31/2003
     **********************************************************************
     */
    virtual cDocumentInterface *GetDocument() const
    {
        return (cDocumentInterface*)this;
    }

    /**
     **********************************************************************
     * Function: ParseFromFile
     *
     *   Author: $author$
     *     Date: 8/29/2003
     **********************************************************************
     */
    virtual eError ParseFromFile
    (const char *filename, const char *uri=0)
    {
        eError error;
        cCharFile file;

        if (!(error = file.Open(filename)))
        {
            error = ParseFromStream(file, filename, uri);
            file.Close();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseFromStream
     *
     *   Author: $author$
     *     Date: 8/29/2003
     **********************************************************************
     */
    virtual eError ParseFromStream
    (cCharStream &stream, const char *filename, const char *uri)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: TransformToStream
     *
     *   Author: $author$
     *     Date: 9/5/2003
     **********************************************************************
     */
    virtual eError TransformToStream
    (cCharStream &stream, cDocumentInterface *document=0)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: SetTransform
     *
     *   Author: $author$
     *     Date: 9/5/2003
     **********************************************************************
     */
    virtual cTransformInterface *SetTransform(cTransformInterface *transform)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetTransform
     *
     *   Author: $author$
     *     Date: 9/5/2003
     **********************************************************************
     */
    virtual cTransformInterface *GetTransform() const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetFileName
     *
     *   Author: $author$
     *     Date: 1/16/2004
     **********************************************************************
     */
    virtual const char *SetFileName(const char *filename)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetFileName
     *
     *   Author: $author$
     *     Date: 1/16/2004
     **********************************************************************
     */
    virtual const char *GetFileName() const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetURI
     *
     *   Author: $author$
     *     Date: 1/16/2004
     **********************************************************************
     */
    virtual const char *SetURI(const char *uri)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetURI
     *
     *   Author: $author$
     *     Date: 1/16/2004
     **********************************************************************
     */
    virtual const char *GetURI() const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetNamespaceDesignator
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual eError SetNamespaceDesignator(const char *value, int length=-1)
    {
        return e_ERROR_NOT_ALLOWED;
    }
    /**
     **********************************************************************
     * Function: GetNamespaceDesignator
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual const char *GetNamespaceDesignator(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetNamespaceSeparator
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual eError SetNamespaceSeparator(const char *value, int length=-1)
    {
        return e_ERROR_NOT_ALLOWED;
    }
    /**
     **********************************************************************
     * Function: GetNamespaceSeparator
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual const char *GetNamespaceSeparator(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetIsXMLContentType
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual bool SetIsXMLContentType(bool is_xml_content_type=true)
    {
        return false;
    }
    /**
     **********************************************************************
     * Function: GetIsXMLContentType
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual bool GetIsXMLContentType() const
    {
        return false;
    }

    /**
     **********************************************************************
     * Function: SetIsTextContentType
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual bool SetIsTextContentType(bool is_xml_content_type=true)
    {
        return false;
    }
    /**
     **********************************************************************
     * Function: GetIsTextContentType
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual bool GetIsTextContentType() const
    {
        return false;
    }
};


#endif
