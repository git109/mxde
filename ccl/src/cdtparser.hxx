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
#include "cpath.hxx"

/**
 **********************************************************************
 *  Class: cDTParser
 *
 * Author: $author$
 *   Date: 8/26/2003
 **********************************************************************
 */
class cDTParser
: virtual public cDTLexer::cSource,
  public cIsDTParser
{
public:
    typedef cIsDTParser cIs;
    typedef cDTLexer::cToken cToken;

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

    /**
     **********************************************************************
     *  Class: cFileItem
     *
     * Author: $author$
     *   Date: 3/5/2004
     **********************************************************************
     */
    class cFileItem
    : public cDynamicListItemT<cFileItem>
    {
    public:
        typedef cDynamicListItemT<cFileItem> cIs;

        cCharFile m_file;

        /**
         **********************************************************************
         * Constructor: cFileItem
         *
         *      Author: $author$
         *        Date: 3/5/2004
         **********************************************************************
         */
        cFileItem() 
        {
        }
        /**
         **********************************************************************
         * Function: GetFile
         *
         *   Author: $author$
         *     Date: 3/5/2004
         **********************************************************************
         */
        inline cCharFile &GetFile() 
        {
            return m_file;
        }
    };

    /**
     **********************************************************************
     *  Class: cFileList
     *
     * Author: $author$
     *   Date: 3/5/2004
     **********************************************************************
     */
    class cFileList
    : public cDynamicListT<cFileItem,cFileList>
    {
    public:
        typedef cDynamicListT<cFileItem,cFileList> cIs;
    };

    const char *m_default_document_type;
    const char *m_element_namespace_designator;
    const char *m_element_namespace_separator;
    const char *m_element_namespace_prefix;
    const char *m_element_namespace_uri;

    eError m_error;
    cDTLexer m_lexer;
    cElementList m_element_list;
    cDocumentInterface &m_document;
    cElementSetInterface &m_element_set;
    cCharStream &m_output;
    cCharFile *m_opened_file;
    cCharFile m_file;
    cPath m_filename;
    cFileList m_opened_file_list;
    cFileList m_free_file_list;

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
     cElementSetInterface &element_set,
     cCharStream &output,
     cCharStream &input,
     const char *default_document_type="xml",
     const char *element_namespace_designator="xmlns",
     const char *element_namespace_separator=":",
     const char *element_namespace_prefix="xtl",
     const char *element_namespace_uri="transform")
    : m_lexer(output,input, *this),
      m_output(output),
      m_document(document),
      m_element_set(element_set),
      m_default_document_type(default_document_type),
      m_element_namespace_designator(element_namespace_designator),
      m_element_namespace_separator(element_namespace_separator),
      m_element_namespace_prefix(element_namespace_prefix),
      m_element_namespace_uri(element_namespace_uri),
      m_opened_file(0)
    {
    }

    /**
     **********************************************************************
     * Function: SetFilename
     *
     *   Author: $author$
     *     Date: 3/5/2004
     **********************************************************************
     */
    virtual int SetFilename(const char *filename, int length=-1)
    {
        length = m_filename.SetPath(filename, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: OnParsedDocument
     *
     *   Author: $author$
     *     Date: 2/16/2004
     **********************************************************************
     */
    virtual eError OnParsedDocument()
    {
        cElementInterface *root_element,*element;
        cAttributeInterface *namespace_attribute;
        cCharBuffer buffer;
        const char *text;
        int textlen;

        if (0 < (textlen = buffer.WriteL
            (m_element_namespace_prefix, 
             m_element_namespace_separator,
             "transform", 0)))
        if ((text = buffer.GetBuffer(textlen)))
        if (0 < textlen)
        if ((root_element = m_element_set.AddElement
            (text, textlen)))
        if (0 < (textlen = buffer.CopyL
            (m_element_namespace_designator, 
             m_element_namespace_separator,
             m_element_namespace_prefix, 0)))
        if ((text = buffer.GetBuffer(textlen)))
        if (0 < textlen)
        if ((namespace_attribute = root_element->AddAttribute
            (text, textlen, m_element_namespace_uri)))
        if ((element=PullElement(m_element_list)))
        {
            do
            {
                if ((element=root_element->AddReferenceElement(*element)))
                if (!(element=PullElement(m_element_list)))
                    return e_ERROR_NONE;
            }
            while(element);
        }
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnParsed
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnParsed()
    {
        cElementInterface *element;

        if ((element=PullElement(m_element_list)))
        {
            do
            {
                if ((element=m_element_set.AddReferenceElement(*element)))
                if (!(element=PullElement(m_element_list)))
                    return e_ERROR_NONE;
            }
            while(element);
        }
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnInclude
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnInclude()
    {
        const char *descr;
        eError error;

        if (!(error = m_lexer.OnInclude()))
            return error;

        if (0 <= (error = m_lexer.GetLastError(descr)))
            yyerror(descr);

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnIncludeURI
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnIncludeURI()
    {
        const char *descr;
        eError error;

        if (!(error = m_lexer.OnIncludeURI()))
            return error;

        if (0 <= (error = m_lexer.GetLastError(descr)))
            yyerror(descr);

        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: OnIf
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnIf(bool not=false)
    {
        int count;
        cCharBuffer buffer;

        if ((count=buffer.CopyL
            (m_element_namespace_prefix,
             m_element_namespace_separator,(not)?"else":"if",0)) >= 0)
            return PushElement
            (buffer.GetBuffer(),buffer.GetLength());

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnIfNot
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnIfNot()
    {
        return OnIf(true);
    }
    /**
     **********************************************************************
     * Function: OnIfThen
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnIfThen()
    {
        return OnFunctionArgs(2);
    }
    /**
     **********************************************************************
     * Function: OnIfElse
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnIfElse()
    {
        return OnFunctionArgs(3);
    }
    /**
     **********************************************************************
     * Function: OnLoop
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnLoop()
    {
        return OnFunctionArgs(2);
    }
    /**
     **********************************************************************
     * Function: OnDoWhile
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnDoWhile()
    {
        eError error;

        if (!(error=OnFunction("do-while")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnWhile
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnWhile()
    {
        return OnFunction("while");
    }
    /**
     **********************************************************************
     * Function: OnUntil
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnUntil()
    {
        return OnFunction("until");
    }
    /**
     **********************************************************************
     * Function: OnDoUntil
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnDoUntil()
    {
        eError error;

        if (!(error=OnFunction("do-until")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnWith
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnWith()
    {
        eError error;

        if (!(error=OnFunction("apply")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnFor
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnFor()
    {
        eError error;

        if (!(error=OnFunction("for")))
            return OnArgsFunction(4);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnForEach
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnForEach()
    {
        eError error;

        if (!(error=OnFunction("for-each")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnForEachOf
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnForEachOf()
    {
        eError error;

        if (!(error=OnFunction("for-each-element-of")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnForEachAttribute
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnForEachAttribute()
    {
        eError error;

        if (!(error=OnFunction("for-each-attribute")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnForEachAttributeOf
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnForEachAttributeOf()
    {
        eError error;

        if (!(error=OnFunction("for-each-attribute-of")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnSwitchCondition
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnSwitchCondition()
    {
        eError error;

        if (!(error=OnFunction("case")))
        if (!(error=OnArgsFunction(1)))
            return OnFunction("case-list");

        return error;
    }
    /**
     **********************************************************************
     * Function: OnSwitchCaseList
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnSwitchCaseList()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function: OnSwitchDefault
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnSwitchDefault()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function: OnSwitchCaseStatement
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnSwitchCaseStatement()
    {
        eError error;

        if (!(error=OnFunction("case-do")))
        if (!(error=OnArgsFunction(2)))
            return OnFunctionArgs(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnSwitchCaseMatch
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnSwitchCaseMatch()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function: OnSwitchCase
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnSwitchCase()
    {
        eError error;

        if (!(error=OnFunction("case-when")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnCase
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnCase()
    {
        eError error;

        if (!(error=OnFunction("when")))
            return OnFunction("when-list");

        return error;
    }
    /**
     **********************************************************************
     * Function: OnCaseList
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnCaseList()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function: OnCaseDefault
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnCaseDefault()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnCaseWhenStatement()
    {
        eError error;

        if (!(error=OnFunction("when-do")))
        if (!(error=OnArgsFunction(2)))
            return OnFunctionArgs(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnCaseWhenList()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnCaseWhen()
    {
        eError error;

        if (!(error=OnFunction("when-case")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnCompoundStatementBegin()
    {
        int count;
        eError error;
        cCharBuffer buffer;

        if ((count=buffer.CopyL
            (m_element_namespace_prefix,":do",0)) >= 0)
        if (!(error=PushElement
            (buffer.GetBuffer(),buffer.GetLength())))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnCompoundStatementItem()
    {
        eError error;
        cElementInterface *op;
        cElementInterface *arg;

        if ((arg=PopElement()))
        {
            if (!(error=!(op=TopElement())))
                error=!op->AddReferenceElement(*arg);

            arg->FreeInstance();

            if (!error)
                return e_ERROR_NONE;
        }
        return e_ERROR_FAILED;
    }


    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnConditionalExpr()
    {
        eError error;

        if (!(error=OnIf()))
            return OnArgsFunction(3);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElseConditionalExpr()
    {
        eError error;

        if (!(error=OnFunction("if-else")))
            return OnArgsFunction(2);

        return error;
    }


    /**
     **********************************************************************
     * Function: OnNativeCall
     *
     *   Author: $author$
     *     Date: 2/25/2004
     **********************************************************************
     */
    virtual eError OnNativeCall()
    {
        return OnArgsFunction(2,"call-function");
    }
    /**
     **********************************************************************
     * Function: OnCall
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnCall()
    {
        return OnArgsFunction(2,"apply-template");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnMethodCall()
    {
        return OnArgsFunction(2,"apply-method");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnMethodOfCall()
    {
        return OnArgsFunction(3,"apply-method-of");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnMethodIdentifierCall()
    {
        return OnArgsFunction(2,"apply-method-template");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnDocumentMethodIdentifierCall()
    {
        return OnArgsFunction(2,"apply-document-class-method-template");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURIMethodCall()
    {
        return OnArgsFunction(3,"get-document-from-service");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURIRequestMethodCall()
    {
        return OnArgsFunction(2,"get-document-from-service-request");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURIMethodIdentifierCall()
    {
        return OnFunctionArgs(2);
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURINativeCall()
    {
        return OnArgsFunction(3,"apply-template-extension");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURIForeignCall()
    {
        return OnArgsFunction(3,"apply-foreign-template-extension");
    }


    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnEmptyArguments()
    {
        eError error;

        if (!(error=OnFunction("arguments")))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnFirstArgument()
    {
        eError error;

        if (!(error=OnFunction("arguments")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnNextArgument()
    {
        eError error;

        if (!(error=OnFunctionArgs(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTypedArgument()
    {
        eError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnReverseArgs(3)))
        if (!(error=OnFunction("argument")))
        if (!(error=OnArgsFunction(3)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTypeArgument()
    {
        eError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunction(GetLiteralName())))
        if (!(error=OnFunction("argument")))
        if (!(error=OnArgsFunction(1)))
        if (!(error=OnArgsFunction(2)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnArgument()
    {
        eError error;

        if (!(error=OnFunction("argument")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return e_ERROR_FAILED;
    }


    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnMethodIdentifierList()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnObjectMethodIdentifierPair()
    {
        eError error;

        if (!(error=OnFunction("select")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnRequestMethodIdentifierList()
    {
        eError error;

        if (!(error=OnFunction("create-service-request")))
        if (!(error=OnFunction("null")))
        if (!(error=OnFunctionArgs(1)))
        if (!(error=OnReverseArgs(2)))
            return error;

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnMethodURI()
    {
        eError error;

        if (!(error=OnFunction("get-document-from-service")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnRequestMethodURI()
    {
        eError error;

        if (!(error=OnFunction("create-service-request")))
            return OnArgsFunction(1);

        return error;
    }


    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnGetMember()
    {
        eError error;

        if (!(error=OnFunction("get-member")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnGetMemberOf()
    {
        eError error;

        if (!(error=OnFunction("get-element-of")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnGetMembersWhere()
    {
        eError error;

        if (!(error=OnFunction("get-members-where")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnGetMembersOfWhere()
    {
        eError error;

        if (!(error=OnFunction("get-elements-of-where")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return e_ERROR_FAILED;
    }


    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnVariable()
    {
        eError error;
        cElementInterface *op;
        cElementInterface *arg;

        if ((arg=PopElement()))
        {
            if (!(error=OnFunction(op,"get-variable")))
                error=!op->AddReferenceElement(*arg);

            arg->FreeInstance();

            if (!error)
                return error;
        }

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnIdentifier()
    {
        eError error;
        cToken *token;

        if ((token=m_lexer.PopToken()))
        if (!(error=PushTextElement(token->Get())))
        if (!(error=OnFunction("id")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnIdentifierExpr()
    {
        eError error;
        cToken *token;
        cElementInterface *op;
        cElementInterface *arg;

        if ((token=m_lexer.PopToken()))
        if (!(error=OnFunction(op,GetLiteralName())))
        if ((arg=op->AddTextElement(token->Get())))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnCallIdentifier()
    {
        eError error;
        cToken *token;

        if ((token=m_lexer.PopToken()))
        if (!(error=PushElement(token->Get())))
            return error;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURIdentifier()
    {
        eError error;
        cToken *token;

        if ((token=m_lexer.PopToken()))
        if (!(error=PushTextElement(token->Get())))
        if (!(error=OnFunction("uri")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURIObjectIdentifier()
    {
        eError error;

        if (!(error=OnFunction("select")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnRequestURIObjectIdentifier()
    {
        eError error;

        if (!(error=OnFunction("select")))
        if (!(error=OnArgsFunction(1)))
        if (!(error=OnFunction("create-service-request")))
        if (!(error=OnFunction("null")))
        if (!(error=OnFunctionArgs(1)))
        if (!(error=OnReverseArgs(2)))
            return error;

        return error;
    }


    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURIURITransform()
    {
        eError error;

        if (!(error=OnFunction("transform-document")))
        if (!(error=OnArgsFunction(3)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURIContent()
    {
        eError error;

        if (!(error=OnFunctionArgs(2)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnIdentifierURIContent()
    {
        eError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunctionArgs(3)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURIArguments()
    {
        eError error;

        if (!(error=OnFunctionArgs(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnIdentifierURIExpr()
    {
        eError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunction("get-document")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURIExpr()
    {
        eError error;

        if (!(error=OnFunction(GetLiteralName())))
        if (!(error=OnFunction("get-document")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return e_ERROR_FAILED;
    }


    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementWhereExpr()
    {
        eError error;

        if (!(error=OnFunction("get-elements-of-where")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnElementRangeSetExpr
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementRangeSetExpr()
    {
        eError error;

        if (!(error=OnFunction("get-elements-of-set-range")))
            return OnArgsFunction(3);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementRangeExpr()
    {
        eError error;

        if (!(error=OnFunction("get-elements-of-range")))
            return OnArgsFunction(3);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnFirstElementSetExpr
     *
     *   Author: $author$
     *     Date: 2/21/2004
     **********************************************************************
     */
    virtual eError OnFirstElementSetExpr()
    {
        eError error;

        if (!(error=OnFunction("get-first-element-of-set")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnFirstElementExpr
     *
     *   Author: $author$
     *     Date: 2/21/2004
     **********************************************************************
     */
    virtual eError OnFirstElementExpr()
    {
        eError error;

        if (!(error=OnFunction("get-first-element-of")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnLastElementSetExpr
     *
     *   Author: $author$
     *     Date: 2/21/2004
     **********************************************************************
     */
    virtual eError OnLastElementSetExpr()
    {
        eError error;

        if (!(error=OnFunction("get-last-element-of-set")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnLastElementExpr
     *
     *   Author: $author$
     *     Date: 2/21/2004
     **********************************************************************
     */
    virtual eError OnLastElementExpr()
    {
        eError error;

        if (!(error=OnFunction("get-last-element-of")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnAllElementsSetExpr
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAllElementsSetExpr()
    {
        eError error;

        if (!(error=OnFunction("get-elements-of-set")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnAllElementsExpr
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAllElementsExpr()
    {
        eError error;

        if (!(error=OnFunction("get-elements-of")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnElementWhereSetExpr
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementWhereSetExpr()
    {
        eError error;

        if (!(error=OnFunction("get-element-of-set-where")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnElementAtSetExpr
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementAtSetExpr()
    {
        eError error;

        if (!(error=OnFunction("get-element-of-set-at")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementAtExpr()
    {
        eError error;

        if (!(error=OnFunction("get-element-of-at")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnRootElementRange()
    {
        eError error;

        if (!(error=OnFunction("get-document-elements-in")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementRange()
    {
        eError error;

        if (!(error=OnFunction("get-elements-in")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnRootElementAt()
    {
        eError error;

        if (!(error=OnFunction("get-document-element-at")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementAt()
    {
        eError error;

        if (!(error=OnFunction("get-element-at")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnRootElementWhere()
    {
        eError error;

        if (!(error=OnFunction("get-document-elements-where")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementWhere()
    {
        eError error;

        if (!(error=OnFunction("get-elements-where")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnFirstRootElement
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnFirstRootElement()
    {
        return OnFunction("get-first-document-element");
    }
    /**
     **********************************************************************
     * Function: OnLastRootElement
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnLastRootElement()
    {
        return OnFunction("get-last-document-element");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAllRootElements()
    {
        return OnFunction("get-document");
    }
    /**
     **********************************************************************
     * Function: OnFirstElement
     *
     *   Author: $author$
     *     Date: 2/26/2004
     **********************************************************************
     */
    virtual eError OnFirstElement()
    {
        return OnFunction("get-first-element");
    }
    /**
     **********************************************************************
     * Function: OnLastElement
     *
     *   Author: $author$
     *     Date: 2/26/2004
     **********************************************************************
     */
    virtual eError OnLastElement()
    {
        return OnFunction("get-last-element");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAllElements()
    {
        return OnFunction("get-element");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnParentElementExpr()
    {
        eError error;

        if (!(error=OnFunction("get-parent-element-of")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementExpr()
    {
        eError error;

        if (!(error=OnFunction("get-element-of")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnRootElementExpr()
    {
        eError error;

        if (!(error=OnFunction("get-element-of-root")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnRootElement()
    {
        return OnFunction("get-document-element");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementIs()
    {
        return OnFunction("get-element");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnParentElement()
    {
        return OnFunction("element-parent");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementSize()
    {
        return OnFunction("element-count");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementType()
    {
        return OnFunction("element-type");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementPosition()
    {
        return OnFunction("element-position");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementText()
    {
        return OnFunction("get-element-text");
    }


    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAttribute()
    {
        eError error;

        if (!(error=OnFunction("get-attribute")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAttributeOf()
    {
        eError error;

        if (!(error=OnFunction("get-attribute-of")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAttributesOfWhere()
    {
        eError error;

        if (!(error=OnFunction("get-attributes-of-where")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAttributeOfAt()
    {
        eError error;

        if (!(error=OnFunction("get-attribute-of-at")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAttributesOfRange()
    {
        eError error;

        if (!(error=OnFunction("get-attributes-of-in")))
            return OnArgsFunction(3);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnFirstAttributeOf
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnFirstAttributeOf()
    {
        eError error;

        if (!(error=OnFunction("get-first-attribute-of")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnLastAttributeOf
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnLastAttributeOf()
    {
        eError error;

        if (!(error=OnFunction("get-last-attribute-of")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAllAttributesOf()
    {
        eError error;

        if (!(error=OnFunction("get-attributes-of")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAttributeRange()
    {
        eError error;

        if (!(error=OnFunction("get-attributes-in")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAttributeAt()
    {
        eError error;

        if (!(error=OnFunction("get-attributes-at")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAttributeWhere()
    {
        eError error;

        if (!(error=OnFunction("get-attributes-where")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnFirstAttribute
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnFirstAttribute()
    {
        return OnFunction("get-first-attribute");
    }
    /**
     **********************************************************************
     * Function: OnLastAttribute
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnLastAttribute()
    {
        return OnFunction("get-last-attribute");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAllAttributes()
    {
        return OnFunction("get-attributes");
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnAttributeIs()
    {
        return OnFunction("get-attribute");
    }


    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTypeReference()
    {
        eError error;

        if (!(error=OnFunction("reference")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnDimentionedTypeReference
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnDimentionedTypeReference()
    {
        eError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunctionArgs(1)))
            return error;

        return error;
    }
    /**
     **********************************************************************
     * Function: OnDimentionedTypeDefinition
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnDimentionedTypeDefinition()
    {
        eError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunction("definition")))
        if (!(error=OnArgsFunction(1)))
        if (!(error=OnFunctionArgs(1)))
            return error;

        return error;
    }
    /**
     **********************************************************************
     * Function: OnTypeDefinition
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTypeDefinition()
    {
        eError error;

        if (!(error=OnFunction("definition")))
            return OnArgsFunction(1);

        return error;
    }


    /**
     **********************************************************************
     * Function: OnDimentions
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnDimentions()
    {
        eError error;

        if (!(error=OnFunction("array")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnOfDimentions
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnOfDimentions()
    {
        eError error;

        if (!(error=OnFunctionArgs(1)))
            return error;

        return error;
    }
    /**
     **********************************************************************
     * Function: OnDimention
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnDimention()
    {
        eError error;

        if (!(error=OnFunction("dimensions")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnDimentionList
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnDimentionList()
    {
        eError error;

        if (!(error=OnFunctionArgs(1)))
            return error;

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnUnboundDimentions()
    {
        eError error;

        if (!(error=OnFunction("dimensions")))
            return error;

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnUnboundDimention()
    {
        eError error;

        if (!(error=OnFunction("dimension")))
        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunction("dimensions")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnDimentionExpr()
    {
        eError error;

        if (!(error=OnFunction("dimention")))
            return OnArgsFunction(1);

        return error;
    }


    /**
     **********************************************************************
     * Function: OnStruct
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnStruct()
    {
        eError error;

        if (!(error=OnFunction("struct")))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnUnion
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnUnion()
    {
        eError error;

        if (!(error=OnFunction("union")))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnIntrinsicType
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnIntrinsicType(const char *name)
    {
        eError error;
        cElementInterface *op;

        if (!(error=OnFunction("intrinsic")))
        if ((op=TopElement()))
        if ((op=op->AddElement(name)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnMember
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnMember()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function: OnVariableDeclaration
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnVariableDeclaration()
    {
        eError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunction("variable")))
            return OnArgsFunction(2);

        return e_ERROR_FAILED;
    }


    /**
     **********************************************************************
     * Function: OnTemplateName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTemplateName()
    {
        eError error;

        if (!(error=OnFunction("template")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnTypedTemplateName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTypedTemplateName()
    {
        eError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunction("return")))
        if (!(error=OnArgsFunction(1)))
        if (!(error=OnFunction("prototype")))
        if (!(error=OnArgsFunction(2)))
        if (!(error=OnFunction("template")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTemplateParameters()
    {
        eError error;
        cElementInterface *op;
        cElementInterface *arg;
        cElementInterface *name;

        if ((arg=PopElement()))
        {
            if (!(error=!(op=TopElement())))
            if (!(error=!(name=op->GetFirstElement())))
                error=!name->AddReferenceElement(*arg);

            arg->FreeInstance();

            if (!error)
                return error;
        }

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnTemplateParameter
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnFirstTemplateParameter()
    {
        eError error;

        if (!(error=OnFunction("parameters")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnTemplateParameter
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTemplateParameter()
    {
        eError error;

        if (!(error=OnFunctionArgs(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnTemplateParameterName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTemplateParameterName()
    {
        eError error;

        if (!(error=OnFunction("parameter")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnTypedTemplateParameterName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTypedTemplateParameterName()
    {
        eError error;

        if (!(error=OnFunction(GetLiteralName())))
        if (!(error=OnFunction("parameter")))
        if (!(error=OnArgsFunction(2)))
        if (!(error=OnArgsFunction(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnTemplateParameterValue
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTemplateParameterValue()
    {
        eError error;

        if (!(error=OnFunction("parameter")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnTypedTemplateParameterValue
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTypedTemplateParameterValue()
    {
        eError error;

        if (!(error=OnFunction("parameter")))
        if (!(error=OnArgsFunction(2)))
        if (!(error=OnArgsFunction(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnTemplate
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTemplate()
    {
        eError error;
        cElementInterface *op;
        cElementInterface *arg;

        if ((arg=PopElement()))
        {
            if (!(error=!(op=TopElement())))
                error=!op->AddReferenceElement(*arg);

            arg->FreeInstance();

            if (!error)
                return error;
        }

        return e_ERROR_FAILED;
    }


    /**
     **********************************************************************
     * Function: OnInterfaceName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnInterfaceName()
    {
        eError error;

        if (!(error=OnFunction("named")))
        if (!(error=OnArgsFunction(1)))
        if (!(error=OnFunction("interface")))
            return OnArgsFunction(1);

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnNamespaceName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnNamespaceName()
    {
        eError error;

        if (!(error=OnFunction("namespace")))
            return OnArgsFunction(1);

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnClassName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnClassName()
    {
        eError error;

        if (!(error=OnFunction("extends")))
        if (!(error=OnFunction("implements")))
        if (!(error=OnFunction("class")))
            return OnArgsFunction(3);

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnClassIs
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnClassIs()
    {
        eError error;
        cElementInterface *arg;
        cElementInterface *op;

        if (!(error=!(arg=PopElement())))
        {
            if (!(error=!(op=TopElement())))
            if (!(error=!(op=op->GetFirstElement())))
            if (!(error=!(op=op->GetNextElement())))
                error=!op->AddReferenceElement(*arg);

            arg->FreeInstance();

            if (!error)
                return error;
        }

        return e_ERROR_FAILED;
    }


    /**
     **********************************************************************
     * Function: OnURILevelName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURILevelName()
    {
        eError error;

        if (!(error=OnFunction("location")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnURIQualifiedName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURIQualifiedName()
    {
        eError error;

        if (!(error=OnFunction("location")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnDocumentLevelName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnDocumentLevelName()
    {
        eError error;

        if (!(error=OnFunction("document")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnDocumentQualifiedName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnDocumentQualifiedName()
    {
        eError error;

        if (!(error=OnFunction("document")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnElementLevelName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementLevelName()
    {
        eError error;

        if (!(error=OnFunction("element")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnElementQualifiedName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementQualifiedName()
    {
        eError error;

        if (!(error=OnFunctionArgs(1)))
            return error;

        return e_ERROR_FAILED;
    }


    /**
     **********************************************************************
     * Function: OnBinaryExpr
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnBinaryExpr()
    {
        eError error;
        cElementInterface *op;
        cElementInterface *arg1;
        cElementInterface *arg2;

        if (!(error=!(arg2=PopElement())))
        {
            if (!(error=!(op=PopElement())))
            {
                if (!(error=!(arg1=PopElement())))
                {
                    if (!(error=!op->AddReferenceElement(*arg1)))
                    if (!(error=!op->AddReferenceElement(*arg2)))
                        error=PushElement(op);

                    arg1->FreeInstance();
                }
                if (error)
                    op->FreeInstance();
            }
            arg2->FreeInstance();

            if (!error)
                return error;
        }

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnUnaryExpr
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnUnaryExpr()
    {
        eError error;
        cElementInterface *op;
        cElementInterface *arg;

        if (!(error=!(arg=PopElement())))
        {
            if (!(error=!(op=TopElement())))
                error=!op->AddReferenceElement(*arg);

            arg->FreeInstance();

            if (!error)
                return error;
        }

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnPostfixExpr
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnPostfixExpr()
    {
        eError error;
        cElementInterface *op;
        cElementInterface *arg;

        if (!(error=!(op=PopElement())))
        {
            if (!(error=!(arg=PopElement())))
            {
                if (!(error=!op->AddReferenceElement(*arg)))
                    error=PushElement(op);

                arg->FreeInstance();
            }
            if (!error)
                return error;

            op->FreeInstance();
        }
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnCastExpr
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnCastExpr()
    {
        eError error;

        if (!(error=OnFunction("as-class")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return e_ERROR_FAILED;
    }


    /**
     **********************************************************************
     * Function: OnPostfixOperator
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnPostfixOperator()
    {
        int count;
        cElementInterface *element;
        cCharBuffer buffer;

        if ((element=TopElement()))
        if ((count=buffer.CopyL
            (element->GetText(),"-after",0)) >= 0)
        if ((count=element->SetText
            (buffer.GetBuffer(),buffer.GetLength())) >= 0)
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnBinaryOperator
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnBinaryOperator(int yychar)
    {
        return OnArgsFunction(2,GetOperatorName(yychar));
    }
    /**
     **********************************************************************
     * Function: OnOperator
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnOperator(int yychar)
    {
        return OnFunction(GetOperatorName(yychar));
    }


    /**
     **********************************************************************
     * Function: OnIdentifierURILiteralExpr
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnIdentifierURILiteralExpr()
    {
        eError error;
        cToken *token;
        cElementInterface *op;

        if ((token=m_lexer.PopToken()))
        if (!(error=OnFunction(op,GetLiteralName())))
        if (op->AddTextElement(token->Get()))
        if ((token=m_lexer.PopToken()))
        if (!(error=OnFunction("get-document")))
        if (!(error=OnFunctionFunction(op,GetLiteralName())))
        if (op->AddTextElement(token->Get()))
        if (!(error=OnArgsFunction(1)))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnURILiteralExpr
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURILiteralExpr()
    {
        eError error;
        cToken *token;
        cElementInterface *op;

        if ((token=m_lexer.PopToken()))
        if (!(error=OnFunction("get-document")))
        if (!(error=OnFunctionFunction(op,GetLiteralName())))
        if ((op->AddTextElement(token->Get())))
        if (!(error=OnFunctionFunction(op,GetLiteralName())))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnIdentifierURILiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnIdentifierURILiteral()
    {
        eError error;
        cToken *token;
        cElementInterface *op;
        cElementInterface *arg;

        if ((token=m_lexer.PopToken()))
        if (!(error=OnURILiteral()))
        if (!(error=OnFunctionFunction(op,"encoding")))
        if ((arg=op->AddTextElement(token->Get())))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnURILiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnURILiteral()
    {
        eError error;
        cToken *token;
        cElementInterface *op;
        cElementInterface *arg;

        if ((token=m_lexer.PopToken()))
        if (!(error=OnFunction("document")))
        if (!(error=OnFunctionFunction(op,"location")))
        if ((arg=op->AddTextElement(token->Get())))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnIdentifierTemplateLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnIdentifierTemplateLiteral()
    {
        eError error;
        cToken *token,*token2;
        cElementInterface *op;
        cElementInterface *arg;

        if ((token=m_lexer.PopToken()))
        if ((token2=m_lexer.PopToken()))
        if (!(error=OnFunction("transform-template-is")))
        if ((op=TopElement()))
        if ((arg=op->AddElement(token->Get())))
        if ((arg=arg->AddTextElement(token2->Get())))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnTemplateLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTemplateLiteral()
    {
        eError error;
        cToken *token;
        cElementInterface *op;
        cElementInterface *arg;

        if ((token=m_lexer.PopToken()))
        if (!(error=OnFunction("text")))
        if ((op=TopElement()))
        if ((arg=op->AddTextElement(token->Get())))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnExternIdentifierLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnExternIdentifierLiteral()
    {
        cToken *uri_token;
        cToken *identifier_token;

        if ((identifier_token=m_lexer.PopToken()))
        if ((uri_token=m_lexer.PopToken()))
            return OnExternLiteral
            (uri_token->Get(),identifier_token->Get());

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnExternLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnExternLiteral()
    {
        cToken *token;

        if ((token=m_lexer.PopToken()))
            return OnExternLiteral(token->Get());

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnExternLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnExternLiteral
    (const char *uri_literal,
     const char *document_type=0)
    {
        eError error;
        cCharFile uri;

        if (!(error=uri.Open(uri_literal)))
            return OnElementLiteral(uri,document_type);

        yyerrorl("Unable to open URI \"",uri_literal,"\"",0);
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnElementLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementLiteral()
    {
        int count;
        cToken *token;

        if ((token=m_lexer.PopToken()))
        if ((count=token->GetStream().Seek(0)) >= 0)
            return OnElementLiteral(token->GetStream());

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnIdentifierElementLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnIdentifierElementLiteral()
    {
        int count;
        cToken *token;
        cToken *identifier_token;

        if ((identifier_token=m_lexer.PopToken()))
        if ((token=m_lexer.PopToken()))
        if ((count=token->GetStream().Seek(0)) >= 0)
            return OnElementLiteral
            (token->GetStream(),identifier_token->Get());

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnElementLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnElementLiteral
    (cCharStream &stream,const char *document_type=0)
    {
        const char *error_description;
        eError error,error2;
        cDocumentInterface *document;
        cElementInterface *op;

        if (!document_type)
            document_type=m_default_document_type;

        if (!(document=m_document.CreateDocumentByType(document_type)))
        {
            yyerrorl
            ("Unable to create \"",document_type,"\" document literal",0);
            return e_ERROR_FAILED;
        }

        if ((error=document->ParseFromStream(stream)))
        {
            error2=document->GetLastError(error_description);

            yyerrorl
            ("Unable to parse \"",document_type,"\" document literal",
             error2?"":"(",error2?"":error_description,error2?"":")",0);
        }
        else
        {
            if (!(error=OnFunction(op,"text")))
            if (op->ReferenceElements(*document) < 0)
                error = e_ERROR_FAILED;
        }

        m_document.DestroyDocument(document);

        if (!error)
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnConcatTextLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnConcatTextLiteral()
    {
        int length;
        cToken *token;
        cToken *token2;

        if ((token2=m_lexer.PullToken()))
        if ((token=m_lexer.BottomToken()))
        if (0 <= (length=token->Add(token2->Get())))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnTextLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnTextLiteral(const char *function="text")
    {
        int textlen;
        const char *text;
        eError error;
        cToken *token;
        cElementInterface *op;
        cElementInterface *arg;
        cCharBuffer buffer;

        if ((token=m_lexer.PopToken()))
        if ((text=FunctionName(buffer,textlen,function)))
        if (!(error=PushElement(op,text,textlen)))
        if (!(error=!(arg=op->AddTextElement(token->Get()))))
            return error;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnDecimalLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnDecimalLiteral(const char *function="decimal")
    {
        return OnTextLiteral(function);
    }
    /**
     **********************************************************************
     * Function: OnBinaryLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnBinaryLiteral(const char *function="binary")
    {
        return OnTextLiteral(function);
    }
    /**
     **********************************************************************
     * Function: OnOctalLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnOctalLiteral(const char *function="octal")
    {
        return OnTextLiteral(function);
    }
    /**
     **********************************************************************
     * Function: OnHexLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnHexLiteral(const char *function="hex")
    {
        return OnTextLiteral(function);
    }
    /**
     **********************************************************************
     * Function: OnFloatLiteral
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnFloatLiteral(const char *function="float")
    {
        return OnTextLiteral(function);
    }


    /**
     **********************************************************************
     * Function: OnArgsFunction 
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnArgsFunction(int args,const char *function)
    {
        eError error;

        if (!(error=OnFunction(function)))
            return OnArgsFunction(args);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnReverseArgs
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnReverseArgs(int args)
    {
        int argpop;
        eError error;
        cElementInterface *arg;
        cElementList list;

        for (argpop=args; argpop>0; --argpop)
        {
            if (!(error=!(arg=PopElement())))
            {
                if (!(error=PushElement(list,arg)))
                    continue;

                arg->FreeInstance();
            }
            break;
        }

        if (!error)
        {
            for (argpop=0; argpop<args; argpop++)
            {
                if (!(error=!(arg=PullElement(list))))
                {
                    if (!(error=PushElement(arg)))
                        continue;

                    arg->FreeInstance();
                }
                break;
            }

            if (!error)
                return error;
        }

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnArgsFunction
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnArgsFunction(int args)
    {
        int argpop;
        eError error;
        cElementInterface *op;
        cElementInterface *arg;
        cElementInterface *ref;
        cElementList list;

        if ((op=PopElement()))
        {
            for (argpop=args; argpop>0; --argpop)
            {
                if (!(error=!(arg=PopElement())))
                {
                    if (!(error=PushElement(list,arg)))
                        continue;

                    arg->FreeInstance();
                }
                break;
            }

            for (argpop=0; argpop<args; argpop++)
            {
                if (!(error=!(arg=PopElement(list))))
                {
                    if (!(error=!(ref=op->AddReferenceElement(*arg))))
                        continue;

                    arg->FreeInstance();
                }
                break;
            }

            if (!error)
            if (!(error=PushElement(op)))
                return error;

            op->FreeInstance();
        }

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnFunctionArgs
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnFunctionArgs(int args)
    {
        int argpop;
        eError error;
        cElementInterface *op;
        cElementInterface *arg;
        cElementInterface *ref;
        cElementList list;

        for (argpop=args; argpop>0; --argpop)
        {
            if (!(error=!(arg=PopElement())))
            {
                if (!(error=PushElement(list,arg)))
                    continue;

                arg->FreeInstance();
            }
            break;
        }

        if (!error)
        if ((op=TopElement()))
        {
            for (argpop=0; argpop<args; argpop++)
            {
                if (!(error=!(arg=PopElement(list))))
                {
                    if (!(error=!(ref=op->AddReferenceElement(*arg))))
                        continue;

                    arg->FreeInstance();
                }
                break;
            }

            if (!error)
                return error;
        }

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnFunctionFunction
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnFunctionFunction
    (cElementInterface *&arg,const char *name)
    {
        int textlen;
        const char *text;
        cElementInterface *op;
        cCharBuffer buffer;

        if ((op=TopElement()))

        if ((text=FunctionName(buffer,textlen,name)))

        if ((arg=op->AddElement(text,textlen)))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnFunction
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnFunction(const char *name)
    {
        cElementInterface *element;
        return OnFunction(element,name);
    }
    /**
     **********************************************************************
     * Function: OnFunction
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual eError OnFunction 
    (cElementInterface *&element,const char *name)
    {
        int textlen;
        const char *text;
        cCharBuffer buffer;

        if ((text=FunctionName(buffer,textlen,name)))
            return PushElement(element,text,textlen);

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: FunctionName
     *
     *   Author: $author$
     *     Date: 8/29/2003
     **********************************************************************
     */
    virtual const char *FunctionName
    (cCharBuffer &buffer,int &length,const char *name)
    {
        if ((length=buffer.CopyL
            (m_element_namespace_prefix,
             m_element_namespace_separator,name,0)) >= 0)
            return buffer.GetBuffer(length);

        return 0;
    }

    /**
     **********************************************************************
     * Function: GetLiteralName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual const char *GetLiteralName()
    {
        return "text";
    }
    /**
     **********************************************************************
     * Function: GetOperatorName
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    virtual const char *GetOperatorName(int yychar)
    {
        switch(yychar)
        {
        case ',':
            return "comma";
        case '+':
            return "add";
        case '-':
            return "subtract";
        case '*':
            return "multiply";
        case '/':
            return "divide";

        case XX_POW_OP:
            return "exponent";
        case XX_ROO_OP:
            return "root";
        case XX_LOG_OP:
            return "log";

        case XX_SIZEOF:
            return "element-count-of";
        case XX_TEXTOF:
            return "element-text-of";
        case XX_TYPEOF:
            return "element-type-of";

        case '!':
        case XX_LNOT_OP:
            return "not";
        case XX_LAND_OP:
            return "and";
        case XX_LOR_OP:
            return "or";

        case '<':
            return "less";
        case '>':
            return "greater";
        case XX_EQ_OP:
            return "equal";
        case XX_NE_OP:
            return "not-equal";
        case XX_LE_OP:
            return "less-or-equal";
        case XX_GE_OP:
            return "greater-or-equal";

        case '=':
            return "set-variable";
        case XX_ASSIGN:
            return "assign-variable";
        case XX_ADD_ASSIGN:
            return "add-variable";
        case XX_SUB_ASSIGN:
            return "subtract-variable";
        case XX_MUL_ASSIGN:
            return "multiply-variable";
        case XX_DIV_ASSIGN:
            return "divide-variable";
        case XX_INC_OP:
            return "increment-variable";
        case XX_DEC_OP:
            return "decrement-variable";
        case XX_COM_OP:
            return "complement-variable";
        case XX_LCOM_OP:
            return "not-variable";
        case XX_LAND_ASSIGN:
            return "and-variable";
        case XX_LOR_ASSIGN:
            return "or-variable";
        case XX_RIGHT_OP:
            return "right-shift-variable";
        case XX_LEFT_OP:
            return "left-shift-variable";
        }
        return "operator";
    }


    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    eError PushTextElement
    (const char *text,int textlen=-1)
    {
        return PushElement
        (text,textlen,cElementInterface::e_TYPE_TEXT_ELEMENT);
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    eError PushElement
    (const char *text,int textlen=-1,
     unsigned type=cElementInterface::e_TYPE_PARENT_ELEMENT)
    {
        cElementInterface *element;
        return PushElement(element,text,textlen,type);
    }
    /**
     **********************************************************************
     * Function: PushElement
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    eError PushElement
    (cElementInterface *&element,const char *text,int textlen=-1,
     unsigned type=cElementInterface::e_TYPE_PARENT_ELEMENT)
    {
        eError error;

        if ((element=m_document.CreateElement(text,textlen,type)))
        {
            if (!(error=PushElement(element)))
                return error;

            element->FreeInstance();
        }
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: PushElement
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    eError PushElement(cElementInterface *element)
    {
        return PushElement(m_element_list,element);
    }
    /**
     **********************************************************************
     * Function: PopElement
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    cElementInterface *PopElement()
    {
        return PopElement(m_element_list);
    }
    /**
     **********************************************************************
     * Function: PullElement
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    cElementInterface *PullElement()
    {
        return PullElement(m_element_list);
    }
    /**
     **********************************************************************
     * Function: TopElement
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    cElementInterface *TopElement()
    {
        return TopElement(m_element_list);
    }
    /**
     **********************************************************************
     * Function: PushElement
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    eError PushElement
    (cElementList &element_list,cElementInterface *element)
    {
        cElementItem *item;

        if ((item=new cElementItem(element)))
        {
            element_list.Push(item);
            return e_ERROR_NONE;
        }
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: PopElement
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    cElementInterface *PopElement(cElementList &element_list)
    {
        cElementItem *item;
        cElementInterface *element;

        if ((item=element_list.Pop()))
        {
            element=item->m_element;
            item->m_element=0;
            delete item;
            return element;
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: PullElement
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    cElementInterface *PullElement(cElementList &element_list)
    {
        cElementItem *item;
        cElementInterface *element;

        if ((item=element_list.Pull()))
        {
            element=item->m_element;
            item->m_element=0;
            delete item;
            return element;
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: TopElement
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    cElementInterface *TopElement(cElementList &element_list) const
    {
        cElementItem *item;

        if ((item=element_list.GetFirst()))
            return item->m_element;
        return 0;
    }

    /*
     **********************************************************************
     * cDTLexer::cSource member functions
     **********************************************************************
     */

    /**
     **********************************************************************
     * Function: OpenFile
     *
     *   Author: $author$
     *     Date: 3/3/2004
     **********************************************************************
     */
    virtual cCharStream *OpenFile
    (eError &error, const char *filename)
    {
        int volumelen,directorylen;
        const char *volume=m_filename.GetPathVolume(volumelen);
        const char *directory=m_filename.GetPathDirectory(directorylen);
        bool is_volume,is_directory;
        cCharFile *file;
        cCharBuffer buffer;

        error = e_ERROR_FAILED;
        is_volume = (volume && (volumelen>0));
        is_directory = (directory && (directorylen>0));

        if (is_volume || is_directory)
        {
            int pathlen;
            cPath path;

            if (0 > (pathlen = path.SetPath(filename)))
                return 0;

            if (!path.GetIsAbsolute())
            {
                if (is_volume)
                if (0 >  (pathlen = buffer.WriteL(volume,":",0)))
                    return 0;

                if (is_directory)
                if (0 >  (pathlen = buffer.WriteL(directory,"/",0)))
                    return 0;

                if (0 >  (pathlen = buffer.Write(filename)))
                    return 0;

                if (!(filename = buffer.GetBuffer()))
                    return 0;
            }
        }

        if ((file = GetFile()))
        {
            if (!(error = file->Open(filename)))
                return file;

            FreeFile(*file);
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OpenURI
     *
     *   Author: $author$
     *     Date: 3/3/2004
     **********************************************************************
     */
    virtual cCharStream *OpenURI
    (eError &error, const char *uri)
    {
        error=e_ERROR_NOT_IMPLEMENTED;
        return 0;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 3/3/2004
     **********************************************************************
     */
    virtual eError Close(cCharStream &stream)
    {
        eError error=e_ERROR_NOT_OPEN;
        cCharFile *file;

        if ((file = GetOpenedFile(stream)))
        {
            error = file->Close();
            FreeFile(*file);
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: GetOpenedFile
     *
     *   Author: $author$
     *     Date: 3/5/2004
     **********************************************************************
     */
    virtual cCharFile *GetOpenedFile(cCharStream &stream)
    {
        cFileItem *item;
        cCharFile *file;

        if (&stream == m_opened_file)
            return &m_file;

        if ((item = m_opened_file_list.GetFirst()))
        do
        {
            if (&stream == (file = &item->GetFile()))
                return file;
        }
        while ((item = item->GetNext()));
        
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetFile
     *
     *   Author: $author$
     *     Date: 3/5/2004
     **********************************************************************
     */
    virtual cCharFile *GetFile()
    {
        cFileItem *item;

        if (!m_opened_file)
            return m_opened_file = &m_file;

        if (!(item = m_free_file_list.Pop()))
            item = new cFileItem;

        if (item)
        {
            m_opened_file_list.Push(item);
            return &item->GetFile();
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: FreeFile
     *
     *   Author: $author$
     *     Date: 3/5/2004
     **********************************************************************
     */
    virtual eError FreeFile(cCharFile &file)
    {
        eError error=e_ERROR_NOT_OPEN;
        cFileItem *item;

        if (&file == m_opened_file)
        {
            m_opened_file = 0;
            error = e_ERROR_NONE;
        }
        else if ((item = m_opened_file_list.GetFirst()))
        {
            do
            {
                if (&file == &item->GetFile())
                {
                    m_opened_file_list.Delete(item);
                    m_free_file_list.Push(item);
                    error = e_ERROR_NONE;
                    break;
                }
            }
            while ((item = item->GetNext()));
        }
        return error;
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
     * Function: yyerrorl
     *
     *   Author: $author$
     *     Date: 8/29/2003
     **********************************************************************
     */
    void yyerrorl(const char *msg,...)
    {
        va_list va;

        va_start(va,msg);
        yyerror(msg);
        yyerrorv(va);
        va_end(va);
    }
    /**
     **********************************************************************
     * Function: yyerrorv
     *
     *   Author: $author$
     *     Date: 8/29/2003
     **********************************************************************
     */
    void yyerrorv(va_list va)
    {
        const char *msg;

        while ((msg=va_arg(va,const char *)))
            yyerror(msg);
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
