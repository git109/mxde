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
 *   File: cdtparser.hxx
 *
 * Author: $author$
 *   Date: 8/26/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDTPARSER_HXX
#define _CDTPARSER_HXX

#define yyIsParser cIsDTParser
#define yyParser cDTParser
#include "yyparser.hxx"

#include "cdtlexer.hxx"
#include "cdocumentinterface.hxx"

/**
 **********************************************************************
 *  Class: cDTParser
 *
 * Author: $author$
 *   Date: 8/26/2003
 **********************************************************************
 */
class cDTParser
: public cIsDTParser
{
public:
    typedef cIsDTParser cIs;

    /**
     **********************************************************************
     *  Class: cElementItem
     *
     * Author: $author$
     *   Date: 8/26/2003
     **********************************************************************
     */
    class cElementItem
    : public cDynamicListItemT<cElementItem>
    {
    public:
        typedef cDynamicListItemT<cElementItem> cIs;

        cElementInterface *m_element;

        /**
         **********************************************************************
         * Constructor: cElementItem
         *
         *      Author: $author$
         *        Date: 8/26/2003
         **********************************************************************
         */
        cElementItem(cElementInterface *element)
        : m_element(element) 
        {
        }
        /**
         **********************************************************************
         * Destructor: ~cElementItem
         *
         *     Author: $author$
         *       Date: 8/26/2003
         **********************************************************************
         */
        virtual ~cElementItem()
        {
            if (m_element)
                m_element->FreeInstance();
        }
    };

    /**
     **********************************************************************
     *  Class: cElementList
     *
     * Author: $author$
     *   Date: 8/26/2003
     **********************************************************************
     */
    class cElementList
    : public cDynamicListT<cElementItem,cElementList>
    {
    public:
        typedef cDynamicListT<cElementItem,cElementList> cIs;
    };

    const char *m_default_document_type;
    const char *m_element_namespace_prefix;
    const char *m_element_namespace;
    const char *m_namespace_prefix;

    eError m_error;
    cDTLexer m_lexer;
    cElementList m_element_list;
    cDocumentInterface &m_document;
    cCharStream &m_output;

    /**
     **********************************************************************
     * Constructor: cDTParser
     *
     *      Author: $author$
     *        Date: 8/26/2003
     **********************************************************************
     */
    cDTParser
    (cDocumentInterface &document,
     cCharStream &output,
     cCharStream &input,
     const char *default_document_type="xml",
     const char *element_namespace_prefix="dt",
     const char *element_namespace="http://www.hydras.org/DT/Transform",
     const char *namespace_prefix="xmlns")
    : m_lexer(&input,&output),
      m_output(output),
      m_document(document),
      m_default_document_type(default_document_type),
      m_element_namespace_prefix(element_namespace_prefix),
      m_element_namespace(element_namespace),
      m_namespace_prefix(namespace_prefix) 
    {
    }

    /**
     **********************************************************************
     * Function: yyparse
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    int yyparse();
    /**
     **********************************************************************
     * Function: yylex
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    int yylex()
    {
        return m_lexer.yylex();
    }
    /**
     **********************************************************************
     * Function: yyerror
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual void yyerror(const char *msg)
    {
        const char *yytext;
        char lineno[32];

        yytext=m_lexer.yy_text();
        sprintf(lineno,"%d",m_lexer.yy_lineno());

        m_output.WriteL
        (msg," at ",(yytext[0]?"\"":""), 
         (yytext[0]?yytext:"<EOF>"),
         (yytext[0]?"\"":"")," on line ",lineno,"\n",0);
    }
};


#endif
