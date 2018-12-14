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
 *   File: cxmltodocumentparsert.hxx
 *
 * Author: $author$
 *   Date: 1/14/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXMLTODOCUMENTPARSERT_HXX
#define _CXMLTODOCUMENTPARSERT_HXX

#include "cdocumentinterface.hxx"

/**
 **********************************************************************
 *  Class: cXMLToDocumentParserT
 *
 * Author: $author$
 *   Date: 1/14/2004
 **********************************************************************
 */
template <class TIs>
class cXMLToDocumentParserT
: public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 8/24/2003
     **********************************************************************
     */
    enum
    {
        e_FIRST_ERROR=cIs::e_NEXT_ERROR,
        e_ERROR_ADD_ELEMENT=e_FIRST_ERROR,
        e_ERROR_ADD_ATTRIBUTE,
        e_NEXT_ERROR,
        e_LAST_ERROR=e_NEXT_ERROR-1
    };

    cDocumentInterface *m_document;
    cElementSetInterface *m_element_set;

    /**
     **********************************************************************
     * Constructor: cXMLToDocumentParserT
     *
     *      Author: $author$
     *        Date: 1/14/2004
     **********************************************************************
     */
    cXMLToDocumentParserT
    (cDocumentInterface *document=0,
     bool include_multiple_root_elements=false,
     bool include_whitespace=false,
     bool include_comments=false) 
    : TIs
      (include_multiple_root_elements,
       include_whitespace,include_comments),
      m_element_set(document), 
      m_document(document) 
    {
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/24/2003
     **********************************************************************
     */
    eError ParseFromStream(cCharStream &source)
    {
        if (!m_document)
            return e_ERROR_NOT_ATTACHED;

        m_element_set = m_document;
        return cIs::ParseFromStream(source);
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/24/2003
     **********************************************************************
     */
    cDocumentInterface *SetDocument(cDocumentInterface *document)
    {
        cDocumentInterface *old_document=m_document;

        m_document=document;
        return old_document;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/24/2003
     **********************************************************************
     */
    cDocumentInterface *GetDocument() const
    {
        return m_document;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/24/2003
     **********************************************************************
     */
    virtual eError OnTextElement(typename TIs::cLexicon &lexicon)
    {
        int textlen;
        const char *text;
        cElementInterface *element;

        if ((text = lexicon.GetText(textlen)))
        if (!(element=m_element_set->AddTextElement(text, textlen)))
            return e_ERROR_ADD_ELEMENT;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/24/2003
     **********************************************************************
     */
    virtual eError OnElementAttributes
    (cElementInterface &element,typename TIs::cLexicon &lexicon)
    {
        int namelen,valuelen;
        const char *name,*value;
        cAttribute *attr;
        cAttributeInterface *attribute;

        if ((attr=lexicon.GetFirstAttribute()))
        do
        {
            if ((name = attr->GetName(namelen)))
            if ((value = attr->GetValue(valuelen)))
            if (!(attribute=element.AddAttribute
                (name, namelen, value, valuelen)))
             return e_ERROR_ADD_ATTRIBUTE;
        }
        while ((attr=attr->GetNext()));

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/24/2003
     **********************************************************************
     */
    virtual eError OnElement
    (cElementInterface *&element,typename TIs::cLexicon &lexicon)
    {
        int textlen;
        const char *text;

        if ((text = lexicon.GetText(textlen)))
        if (!(element=m_element_set->AddParentElement(text, textlen)))
            return e_ERROR_ADD_ELEMENT;

        OnElementAttributes(*element,lexicon);

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/24/2003
     **********************************************************************
     */
    virtual eError OnElement(typename TIs::cLexicon &lexicon)
    {
        eError error;
        cElementInterface *element;

        error=OnElement(element,lexicon);
        return error;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/24/2003
     **********************************************************************
     */
    virtual eError OnBeginElement(typename TIs::cLexicon &lexicon)
    {
        eError error;
        cElementInterface *element;

        if (!(error=OnElement(element,lexicon)))
        {
            m_element_set=element;
            m_depth++;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/24/2003
     **********************************************************************
     */
    virtual eError OnEndElement(typename TIs::cLexicon &lexicon)
    {
        const char *text=lexicon.GetText();
        cElementInterface *element;

        if (m_element_set)
        if ((element=m_element_set->GetElement()))
        {
            const char *text=element->GetText();

        if ((m_element_set=(element=element->GetParentElement())))
        {
            const char *text=element->GetText();

            --m_depth;
            return e_ERROR_NONE;
        }
        }

        m_element_set=m_document;
        return e_ERROR_NONE;
    }
};

#endif /* ndef _CXMLTODOCUMENTPARSERT_HXX */
