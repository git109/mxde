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
 *   File: cxtldocument.hxx
 *
 * Author: $author$
 *   Date: 2/15/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXTLDOCUMENT_HXX
#define _CXTLDOCUMENT_HXX

#define CXTLDOCUMENT_DOCUMENT_TYPE "xtl"
#define CXTLDOCUMENT_FILE_EXTENSION "xtl"

#include "cxmldocument.hxx"

/**
 **********************************************************************
 *  Class: cXTLDocumentType
 *
 * Author: $author$
 *   Date: 2/15/2004
 **********************************************************************
 */
class cXTLDocumentType
: public cDocumentType
{
public:
    typedef cDocumentType cIs;

    /**
     **********************************************************************
     * Constructor: cXTLDocumentType
     *
     *      Author: $author$
     *        Date: 2/15/2004
     **********************************************************************
     */
    cXTLDocumentType
    (const char *document_type = CXTLDOCUMENT_DOCUMENT_TYPE, 
     const char *content_type = CXMLDOCUMENT_CONTENT_TYPE,
     const char *file_extension = CXTLDOCUMENT_FILE_EXTENSION,
     bool is_default=false)
    : cIs(document_type,content_type,file_extension,is_default) 
    {
    }

    /**
     **********************************************************************
     * Function: CreateDocument
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocument();
};

/**
 **********************************************************************
 *  Class: cXTLDocument
 *
 * Author: $author$
 *   Date: 2/15/2004
 **********************************************************************
 */
class cXTLDocument
: public cXMLDocument
{
public:
    typedef cXMLDocument cIs;

    /**
     **********************************************************************
     * Constructor: cXTLDocument
     *
     *      Author: $author$
     *        Date: 2/15/2004
     **********************************************************************
     */
    cXTLDocument() 
    {
    }

    /**
     **********************************************************************
     * Function: ParseFromStream
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual eError ParseFromStream
    (cCharStream &stream, const char *filename=0, const char *uri=0);

    /**
     **********************************************************************
     * Function: PostParseElements
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual eError PostParseElements
    (cElementSetInterface &element_set)
    {
        eError error=e_ERROR_NONE;
        cElementInterface *element;

        if ((element = element_set.GetFirstParentElement()))
        do
        {
            const char *text=element->GetText();

            if ((error = PostParseAttributes(*element)))
                break;
        }
        while ((element = element->GetNextParentElement()));
        return error;
    }
    /**
     **********************************************************************
     * Function: PostParseAttributes
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual eError PostParseAttributes
    (cElementInterface &element)
    {
        eError error=e_ERROR_NONE;
        cAttributeInterface *attribute;
        cAttributeInterface *next_attribute;
        const char *argname="xtl:argument";
        const char *attrname="name";
        int argnamelen=-1;
        int attrnamelen=-1;

        if ((attribute = element.GetFirstAttribute()))
        do
        {
            const char *name=attribute->GetName();

            next_attribute = attribute->GetNextAttribute();

            if ((error = PostParseAttribute
                (element, *attribute,
                 argname, argnamelen,
                 attrname, attrnamelen)))
                return error;
        }
        while ((attribute = next_attribute));

        error = PostParseElements(element);
        return error;
    }
    /**
     **********************************************************************
     * Function: PostParseAttribute
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual eError PostParseAttribute
    (cElementInterface &element, 
     cAttributeInterface &attribute,
     const char *argname, int argnamelen,
     const char *attrname, int attrnamelen)
    {
        eError error=e_ERROR_NONE;
        cElementSet expressions;
        cElementInterface *expression;
        cElementInterface *argument;
        const char *name,*text;
        int namelen,textlen;

        if ((name = attribute.GetName(namelen)))
        if ((text = attribute.GetText(textlen)))
        if (0 < textlen)
        {
            enum eState
            {
                e_STATE_TEXT,
                e_STATE_LBRACE,
                e_STATE_QUOTE,
                e_STATE_QUOTES,
                e_STATE_BSLASH
            } old_state,state;
            const char *nextchar;
            const char *rbrace;
            const char *lbrace;
            int lbraces;
            char c;

            lbraces = 0;
            nextchar = text;

            for (state=e_STATE_TEXT; 0 < textlen; --textlen, ++nextchar)
            {
                switch((c=*nextchar))
                {
                case '{':
                    if (state < e_STATE_QUOTE)
                    {
                        if (0 >= (lbraces++))
                            lbrace = nextchar;

                        state = e_STATE_LBRACE;
                    }
                    break;

                case '}':
                    if (state < e_STATE_QUOTE)
                    {
                        if (0 < lbraces)
                        if (0 >= (--lbraces))
                        {
                            rbrace = nextchar;
                            state = e_STATE_TEXT;

                            if ((error = PostParseAttributeValue
                                (expressions, text, lbrace-text,
                                 lbrace+1, rbrace-lbrace-1)))
                                 return error;
                        }
                    }
                    break;
                }
            }

            if ((expression = expressions.GetFirstElement()))
            if ((argument = element.PushElement(argname, argnamelen)))
            if (argument->AddAttribute
                (attrname, attrnamelen, name, namelen))
            {
                do
                {
                    argument->AddReferenceElement(*expression);
                }
                while ((expression = expression->GetNextElement()));

                element.DeleteAttribute(&attribute);
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: PostParseAttributeValue
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual eError PostParseAttributeValue
    (cElementSetInterface &element_set,
     const char *text, int textlen, 
     const char *expr, int exprlen);
};

#endif /* ndef _CXTLDOCUMENT_HXX */
