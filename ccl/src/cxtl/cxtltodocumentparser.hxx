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
 *   File: cxtltodocumentparser.hxx
 *
 * Author: $author$
 *   Date: 11/19/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CXTLTODOCUMENTPARSER_HXX
#define _CXTLTODOCUMENTPARSER_HXX

#define yyIsParser cIsXTLToDocumentParser
#define yyParser cXTLToDocumentParser
#include "yyparser.hxx"

#include "cdocumentfactoryinterface.hxx"
#include "cxtltodocumentlexer.hxx"
#include "cfilepatht.hxx"
#include "ccharfile.hxx"

/**
 **********************************************************************
 *  Class: cXTLToDocumentParser
 *
 * Author: $author$
 *   Date: 11/20/2005
 **********************************************************************
 */
class cXTLToDocumentParser
: public cIsXTLToDocumentParser
{
public:
    typedef cIsXTLToDocumentParser cIs;

    cCharStream& m_err;
    cXTLToDocumentLexer m_lexer;
    cCharFile m_file;
    cFilePath m_path;
    cDocumentNodeListInterface* m_node_list;

    /**
     **********************************************************************
     * Constructor: cXTLToDocumentParser
     *
     *      Author: $author$
     *        Date: 11/20/2005
     **********************************************************************
     */
    cXTLToDocumentParser
    (cCharStream& err) 
    : m_err(err),
      m_lexer(err),
      m_node_list(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXTLToDocumentParser
     *
     *      Author: $author$
     *        Date: 11/20/2005
     **********************************************************************
     */
    virtual ~cXTLToDocumentParser()
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    eError Initialize() 
    {
        eError error = m_lexer.Initialize();
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    eError Finalize() 
    {
        eError error = m_lexer.Finalize();
        return error;
    }

    /**
     **********************************************************************
     * Function: Parse
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    int Parse(cDocumentNodeListInterface& node_list)
    {
        cDocumentNodeListInterface* old_node_list = GetNodeList();
        cDocumentNodeListInterface* old_lexer_node_list = m_lexer.GetNodeList();
        int result;

        SetNodeList(&node_list);
        m_lexer.SetNodeList(&node_list);
        result = yyparse();
        m_lexer.SetNodeList(old_lexer_node_list);
        SetNodeList(old_node_list);
        return result;
    }


    /**
     **********************************************************************
     * Function: SetNodeList
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    cDocumentNodeListInterface* SetNodeList
    (cDocumentNodeListInterface* node_list) 
    {
        return m_node_list = node_list;
    }
    /**
     **********************************************************************
     * Function: GetNodeList
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    cDocumentNodeListInterface* GetNodeList() const 
    {
        return m_node_list;
    }

    /*
     **********************************************************************
     * yy member functions
     **********************************************************************
     */

    /**
     **********************************************************************
     * Function: yyparse
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    int yyparse();
    /**
     **********************************************************************
     * Function: yylex
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    int yylex()
    {
        int token = m_lexer.yylex();
        return token;
    }
    /**
     **********************************************************************
     * Function: yytext
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    const char *yytext()
    {
        const char *text = m_lexer.yytext();
        return text;
    }
    /**
     **********************************************************************
     * Function: yyerror
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual void yyerror(const char *msg)
    {
        const char *text;

        m_err.WriteL(msg," at \"",0);

        if ((text = yytext()))
            m_err.Write(text);

        m_err.Write("\"\n");
    }

    /*
     **********************************************************************
     * OnRule member functions
     **********************************************************************
     */

    /**
     **********************************************************************
     * Function: OnIncludeLocation
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual eError OnIncludeLocation() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnIncludeLocation()\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: CreateIncludeDocument
     *
     *   Author: $author$
     *     Date: 11/26/2005
     **********************************************************************
     */
    virtual cDocumentInterface* CreateIncludeDocument() 
    {
        cDocumentInterface* document = 0;

        if (m_node_list)
        {
            cDocumentNodeFactoryInterface& node_factory = m_node_list->GetNodeFactory();
            cDocumentFactoryInterface& factory = node_factory.GetDocumentFactory();

            document = factory.CreateDocument();
        }
        return document;
    }
    /**
     **********************************************************************
     * Function: DestroyIncludeDocument
     *
     *   Author: $author$
     *     Date: 11/26/2005
     **********************************************************************
     */
    virtual eError DestroyIncludeDocument
    (cDocumentInterface& document) 
    {
        eError error = e_ERROR_FAILED;

        if (m_node_list)
        {
            cDocumentNodeFactoryInterface& node_factory = m_node_list->GetNodeFactory();
            cDocumentFactoryInterface& factory = node_factory.GetDocumentFactory();

            error = factory.DestroyDocument(document);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseIncludeDocumentFile
     *
     *   Author: $author$
     *     Date: 11/26/2005
     **********************************************************************
     */
    virtual eError ParseIncludeDocumentFile
    (cDocumentInterface& document) 
    {
        cDocumentParserInterface& parser = document.GetParser();
        eError error;
        FILE* file;

        if (!(error = m_path.Open()))
        {
            if ((file = m_path.GetHandle()))
            if (!(error = m_file.Attach(file)))
            {
                error = parser.ParseStream(m_file);
                m_file.Detach(file);
            }
            m_path.Close();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnIncludeFile
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual eError OnIncludeFile() 
    {
        eError error = e_ERROR_FAILED;
        cDocumentInterface* document;

        m_err.Write("OnIncludeFile()\n");

        if ((document = CreateIncludeDocument()))
        {
            if (!(error = ParseIncludeDocumentFile(*document)))
            if (!(error = m_lexer.PushDocument(*document)))
                return error;

            DestroyIncludeDocument(*document);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnIncludeFTP
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual eError OnIncludeFTP() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnIncludeFTP()\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnIncludeHTTP
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual eError OnIncludeHTTP() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnIncludeHTTP()\n");
        return error;
    }

    /**
     **********************************************************************
     * Function: OnLocationValue
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual eError OnLocationValue() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnLocationValue()\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnFileValue
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual eError OnFileValue() 
    {
        eError error = e_ERROR_NONE;
        cDocumentAttributeInterface* node;
        const cChar* path;
        int path_length;

        m_err.Write("OnFileValue()\n");

        if ((node = m_lexer.GetAttribute()))
        if ((path = node->GetValueCChars(path_length)))
        if (0 < path_length)
        if (0 > (path_length = m_path.SetPath(path, path_length)))
            error = -path_length;

        return error;
    }
    /**
     **********************************************************************
     * Function: OnFTPValue
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual eError OnFTPValue() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnFTPValue()\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnHTTPValue
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual eError OnHTTPValue() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnHTTPValue()\n");
        return error;
    }

    /**
     **********************************************************************
     * Function: OnMethodValue
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual eError OnMethodValue() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnMethodValue()\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnMatchValue
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual eError OnMatchValue() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnMatchValue()\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnNameValue
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual eError OnNameValue() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnNameValue()\n");
        return error;
    }

    /**
     **********************************************************************
     * Function: OnTextLiteral
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual eError OnTextLiteral() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnTextLiteral()\n");
        return error;
    }

    /**
     **********************************************************************
     * Function: OnXmlnsAttr
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual eError OnXmlnsAttr() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnXmlnsAttr()\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnXmlnsPrefixAttr
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual eError OnXmlnsPrefixAttr() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnXmlnsPrefixAttr()\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginAttr
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual eError OnBeginAttr() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnBeginAttr()\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndAttr
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual eError OnEndAttr() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnEndAttr()\n");
        return error;
    }

    /**
     **********************************************************************
     * Function: OnExpression
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual eError OnExpression() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnExpression()\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnVariableExpression
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual eError OnVariableExpression() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnVariableExpression()\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnLiteralExpression
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual eError OnLiteralExpression() 
    {
        eError error = e_ERROR_NONE;
        m_err.Write("OnLiteralExpression()\n");
        return error;
    }

    /**
     **********************************************************************
     * Function: SetLanguageNamespace
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    cDocumentNamespaceInterface& SetLanguageNamespace
    (cDocumentNamespaceInterface* document_namespace) 
    {
        cDocumentNamespaceInterface& ns = m_lexer.SetLanguageNamespace(document_namespace);
        return ns;
    }
    /**
     **********************************************************************
     * Function: SetVariableNamespace
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    cDocumentNamespaceInterface& SetVariableNamespace
    (cDocumentNamespaceInterface* document_namespace) 
    {
        cDocumentNamespaceInterface& ns = m_lexer.SetVariableNamespace(document_namespace);
        return ns;
    }
    /**
     **********************************************************************
     * Function: SetExpressionNamespace
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    cDocumentNamespaceInterface& SetExpressionNamespace
    (cDocumentNamespaceInterface* document_namespace) 
    {
        cDocumentNamespaceInterface& ns = m_lexer.SetExpressionNamespace(document_namespace);
        return ns;
    }
};

#endif /* _CXTLTODOCUMENTPARSER_HXX */
