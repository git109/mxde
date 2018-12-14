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
 *   File: cdocumenttype.hxx
 *
 * Author: $author$
 *   Date: 1/2/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTTYPE_HXX
#define _CDOCUMENTTYPE_HXX

#include "cdocumentimplement.hxx"
#include "cinstance.hxx"

#define CDOCUMENTTYPE_MAX_FILE_EXTENSIONS 10

/**
 **********************************************************************
 *  Class: cDocumentType
 *
 * Author: $author$
 *   Date: 9/3/2003
 **********************************************************************
 */
class cDocumentType
: virtual public cDocumentTypeInterface,
  virtual public cDocumentTypeImplement
{
public:
    const char *m_document_type;
    const char *m_content_type;
    int m_document_type_length;
    int m_content_type_length;
    bool m_is_default;

    int m_file_extensions;
    int m_file_extension_length[CDOCUMENTTYPE_MAX_FILE_EXTENSIONS];
    const char *m_file_extension[CDOCUMENTTYPE_MAX_FILE_EXTENSIONS];

    /**
     **********************************************************************
     * Constructor: cDocumentType
     *
     *      Author: $author$
     *        Date: 9/3/2003
     **********************************************************************
     */
    cDocumentType
    (const char *document_type=0, 
     const char *content_type=0,
     const char *file_extension=0,
     bool is_default=false)
    : m_document_type(document_type),
      m_content_type(content_type),
      m_is_default(is_default),
      m_document_type_length(0),
      m_content_type_length(0),
      m_file_extensions(0)
    {
        if (document_type)
            m_document_type_length = strlen(document_type);

        if (content_type)
            m_content_type_length = strlen(content_type);

        if (file_extension)
        {
            m_file_extension[0] = file_extension;
            m_file_extension_length[0] = strlen(file_extension);
            m_file_extensions = 1;
        }
    }

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
        return m_is_default;
    }
    /**
     **********************************************************************
     * Function: GetDocumentType
     *
     *   Author: $author$
     *     Date: 9/2/2003
     **********************************************************************
     */
    virtual const char *GetDocumentType(int &length) const
    {
        length = m_document_type_length;
        return m_document_type;
    }
    /**
     **********************************************************************
     * Function: GetContentType
     *
     *   Author: $author$
     *     Date: 9/2/2003
     **********************************************************************
     */
    virtual const char *GetContentType(int &length) const
    {
        length = m_content_type_length;
        return m_content_type;
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
        if (m_file_extensions > 0)
        {
            length = m_file_extension_length[0];
            return m_file_extension[0];
        }
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
        int x;

        for (x=0; x < m_file_extensions; x++)
        {
            if (file_extension == m_file_extension[x])
            if (x+1 < m_file_extensions)
            {
                length = m_file_extension_length[x+1];
                return m_file_extension[x+1];
            }
        }
        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cStaticDocumentType
 *
 * Author: $author$
 *   Date: 9/1/2003
 **********************************************************************
 */
class cStaticDocumentType
: virtual public cDocumentTypeInterface,
  virtual public cDocumentType,
  public cListItemT<cStaticDocumentType,cErrorInstance>
{
public:
    typedef cDocumentType cDocumentTypeIs;
    typedef cListItemT<cStaticDocumentType,cErrorInstance> cListItemIs;

    /**
     **********************************************************************
     *  Class: cList
     *
     * Author: $author$
     *   Date: 9/1/2003
     **********************************************************************
     */
    class cList
    : public cStaticListT<cStaticDocumentType, cList>
    {
    public:
        typedef cStaticListT<cStaticDocumentType ,cList> cIs;
    };

    static cList m_list;

    /**
     **********************************************************************
     * Constructor: cStaticDocumentType
     *
     *      Author: $author$
     *        Date: 9/1/2003
     **********************************************************************
     */
    cStaticDocumentType
    (const char *document_type=0, 
     const char *content_type=0,
     const char *file_extension=0,
     const char *another_file_extension=0,...)
    : cDocumentTypeIs(document_type,content_type,file_extension)
    {
        va_list va;

        if ((file_extension = another_file_extension))
        {
            va_start(va,file_extension);

            do
            {
                m_file_extension[m_file_extensions] = file_extension;
                m_file_extension_length[m_file_extensions] = strlen(file_extension);
                m_file_extensions++;
            }
            while ((file_extension=va_arg(va,const char *)));

            va_end(va);
        }

        m_list.Add(this);
    }
    /**
     **********************************************************************
     * Destructor: ~cStaticDocumentType
     *
     *     Author: $author$
     *       Date: 9/1/2003
     **********************************************************************
     */
    ~cStaticDocumentType()
    {
        m_list.Delete(this);
    }

    /**
     **********************************************************************
     * Function: GetDefault
     *
     *   Author: $author$
     *     Date: 1/7/2004
     **********************************************************************
     */
    static cStaticDocumentType *GetDefault()
    {
        cStaticDocumentType *ctype;
        bool is_default;

        if ((ctype=m_list.GetFirst()))
        {
            do
            {
                if ((is_default = ctype->GetIsDefault()))
                    return ctype;
            }
            while ((ctype = ctype->GetNext()));
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetByFileExtension
     *
     *   Author: $author$
     *     Date: 9/1/2003
     **********************************************************************
     */
    static cStaticDocumentType *GetByFileExtension
    (const char *file_extension, int file_extensionlen=-1)
    {
        int extensionlen;
        const char *extension;
        cStaticDocumentType *ctype;

        if ((ctype=m_list.GetFirst()))
        {
            if (file_extensionlen < 0)
                file_extensionlen = strlen(file_extension);

            do
            {
                if ((extension = ctype->GetFirstFileExtension(extensionlen)))
                do
                {
                    if (extensionlen == file_extensionlen)
                    if (!strncmp(file_extension, extension, extensionlen))
                        return ctype;
                }
                while ((extension = ctype->GetNextFileExtension
                        (extensionlen, extension)));
            }
            while ((ctype = ctype->GetNext()));
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetByContentType
     *
     *   Author: $author$
     *     Date: 9/1/2003
     **********************************************************************
     */
    static cStaticDocumentType *GetByContentType
    (const char *content_type, int content_typelen=-1)
    {
        int typelen;
        const char *type;
        cStaticDocumentType *ctype;

        if ((ctype=m_list.GetFirst()))
        {
            if (content_typelen < 0)
                content_typelen = strlen(content_type);

            do
            {
                if ((type = ctype->GetContentType(typelen)))
                if (typelen == content_typelen)
                if (!strncmp(content_type, type, typelen))
                    return ctype;
            }
            while ((ctype = ctype->GetNext()));
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetByDocumentType
     *
     *   Author: $author$
     *     Date: 9/1/2003
     **********************************************************************
     */
    static cStaticDocumentType *GetByDocumentType
    (const char *document_type, int document_typelen=-1)
    {
        int typelen;
        const char *type;
        cStaticDocumentType *ctype;

        if ((ctype=m_list.GetFirst()))
        {
            if (document_typelen < 0)
                document_typelen = strlen(document_type);

            do
            {
                if ((type = ctype->GetDocumentType(typelen)))
                if (typelen == document_typelen)
                if (!strncmp(document_type, type, typelen))
                    return ctype;
            }
            while ((ctype = ctype->GetNext()));
        }
        return 0;
    }
};

#endif /* ndef _CDOCUMENTTYPE_HXX */
