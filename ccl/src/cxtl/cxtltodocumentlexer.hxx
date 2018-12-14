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
 *   File: cxtltodocumentlexer.hxx
 *
 * Author: $author$
 *   Date: 11/20/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CXTLTODOCUMENTLEXER_HXX
#define _CXTLTODOCUMENTLEXER_HXX

#include <stdio.h>
#include "cxtltodocumenttoken.hxx"
#include "cxtlparse.hxx"
#include "cdocumentnodereferencelist.hxx"
#include "cdocument.hxx"
#include "ccchartocharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cXTLToDocumentLexer
 *
 * Author: $author$
 *   Date: 11/20/2005
 **********************************************************************
 */
class cXTLToDocumentLexer
{
public:
    typedef cXTLToDocumentLexer cAs;
    typedef int (cAs::*mYYLex)();

    /**
     **********************************************************************
     *  Class: cState
     *
     * Author: $author$
     *   Date: 11/21/2005
     **********************************************************************
     */
    class cState
    : public cDynamicListItemT<cState>
    {
    public:
        typedef cDynamicListItemT<cState> cIs;

        cDocumentInterface &m_document;
        cDocumentNodeListInterface* m_node_list;
        cDocumentNodeInterface* m_node;
        cDocumentTextInterface* m_text;
        cDocumentCommentInterface* m_comment;
        cDocumentElementInterface* m_element;
        cDocumentAttributeInterface* m_attribute;
        const cCCharBuffer *m_yytext, *m_yytext2;
        mYYLex m_old_yylex, m_yylex;

        /**
         **********************************************************************
         * Constructor: cState
         *
         *      Author: $author$
         *        Date: 11/21/2005
         **********************************************************************
         */
        cState
        (cDocumentInterface &document,
         cDocumentNodeListInterface* node_list,
         cDocumentNodeInterface* node,
         cDocumentTextInterface* text,
         cDocumentCommentInterface* comment,
         cDocumentElementInterface* element,
         cDocumentAttributeInterface* attribute,
         const cCCharBuffer *yytext,
         const cCCharBuffer *yytext2,
         mYYLex old_yylex,
         mYYLex yylex) 
        : m_document(document),
          m_attribute(attribute),
          m_element(element),
          m_comment(comment),
          m_text(text),
          m_node(node),
          m_node_list(node_list),
          m_yytext(yytext),
          m_yytext2(yytext2),
          m_old_yylex(old_yylex),
          m_yylex(yylex)
        {
        }
    };

    /**
     **********************************************************************
     *  Class: cStateStack
     *
     * Author: $author$
     *   Date: 11/21/2005
     **********************************************************************
     */
    class cStateStack
    : public cDynamicListT
      <cState, cStateStack>
    {
    public:
        typedef cDynamicListT
        <cState, cStateStack> cIs;

        /**
         **********************************************************************
         * Destructor: ~cStateStack
         *
         *     Author: $author$
         *       Date: 11/21/2005
         **********************************************************************
         */
        virtual ~cStateStack() 
        {
        }
    };

    cCharStream& m_err;

    cStateStack m_state_stack;
    cXTLToDocumentTokenTree m_token_tree;
    cDocumentNodeReferenceList m_node_stack;

    cDocumentNamespaceInterface* m_language_namespace;
    cDocumentNamespaceInterface* m_variable_namespace;
    cDocumentNamespaceInterface* m_expression_namespace;

    cDocumentNodeListInterface* m_node_list;
    cDocumentNodeInterface* m_node;
    cDocumentTextInterface* m_text;
    cDocumentCommentInterface* m_comment;
    cDocumentElementInterface* m_element;
    cDocumentAttributeInterface* m_attribute;
    const cCCharBuffer *m_yytext, *m_yytext2;
    mYYLex m_old_yylex, m_yylex;

    cCCharBuffer m_cchar_buffer;
    cCCharToCharBuffer m_char_buffer;

    /**
     **********************************************************************
     * Constructor: cXTLToDocumentLexer
     *
     *      Author: $author$
     *        Date: 11/20/2005
     **********************************************************************
     */
    cXTLToDocumentLexer(cCharStream& err) 
    : m_err(err),
      m_language_namespace(0),
      m_variable_namespace(0),
      m_expression_namespace(0),
      m_attribute(0),
      m_element(0),
      m_comment(0),
      m_text(0),
      m_node(0),
      m_node_list(0),
      m_yytext(0),
      m_yytext2(0),
      m_old_yylex(YYLex),
      m_yylex(YYLex)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXTLToDocumentLexer
     *
     *      Author: $author$
     *        Date: 11/20/2005
     **********************************************************************
     */
    virtual ~cXTLToDocumentLexer()
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
        eError error = e_ERROR_NONE;
        cXTLToDocumentTokenItem *item;

        if ((item = cXTLToDocumentTokenList::m_instance.GetFirst()))
        do
        {
            cXTLToDocumentTokenBranch &branch = item->m_token.GetBranch();

            m_token_tree.Insert(&branch);
        }
        while ((item = item->GetNext()));
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
        eError error = e_ERROR_NONE;
        m_node_stack.Clear();
        m_token_tree.Clear();
        return error;
    }

    /**
     **********************************************************************
     * Function: PushDocument
     *
     *   Author: $author$
     *     Date: 11/26/2005
     **********************************************************************
     */
    eError PushDocument(cDocumentInterface &document)
    {
        eError error = e_ERROR_NEW;
        cState *state;

        if ((state = new cState
            (document, m_node_list, m_node, m_text, 
             m_comment, m_element, m_attribute,
             m_yytext, m_yytext2, m_old_yylex, m_yylex)))
        {
            m_state_stack.Push(state);
            m_node_list = &document;
            m_node = 0;
            m_text = 0;
            m_comment = 0;
            m_element = 0;
            m_attribute = 0;
            m_yytext = 0;
            m_yytext2 = 0;
            m_yylex = YYLex;
            m_old_yylex = YYLex;
            error = e_ERROR_NONE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: PopDocument
     *
     *   Author: $author$
     *     Date: 1/4/2005
     **********************************************************************
     */
    cDocumentInterface *PopDocument()
    {
        cDocumentInterface *document = 0;
        cState *item;

        if ((item = m_state_stack.Pop()))
        {
            document = &item->m_document;
            m_node_list = item->m_node_list;
            m_node = item->m_node;
            m_text = item->m_text;
            m_element = item->m_element;
            m_attribute = item->m_attribute;
            m_old_yylex = item->m_old_yylex;
            m_yylex = item->m_yylex;
            m_yytext = item->m_yytext;
            m_yytext2 = item->m_yytext2;
            delete item;
        }
        return document;
    }

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
        int token = 0;
        cDocumentInterface *document;
        
        while (!(token = (this->*m_yylex)()))
        {
            if (!(document = PopDocument()))
                break;
        }

        if (token)
            m_err.PrintFormatted
            ("token = %d \"%s\"\n", token, yytext());

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
    const char* yytext() 
    {
        const char* chars = "";
        const cChar* cchars;
        int length;
        const cCCharBuffer* yytext;

        if ((yytext = m_yytext))
        if (0 <= (m_char_buffer.Clear()))
        {
            do
            {
                if ((cchars = yytext->GetBuffer(length)))
                    m_char_buffer.WriteCChar(cchars, length);

                if ((yytext == m_yytext) 
                    && (yytext != m_yytext2))
                if ((yytext = m_yytext2))
                if (0 < (length = yytext->GetLength()))
                {
                    m_char_buffer.Putc(':');
                    continue;
                }

                yytext = 0;
            }
            while (yytext);

            chars = m_char_buffer.GetBuffer();
        }
        return chars;
    }

    /**
     **********************************************************************
     * Function: YYNode
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    int YYNode(mYYLex next_yylex) 
    {
        int token = 0;
        int type = m_node->GetType();

        if ((m_element = m_node->GetElementInterface()))
            token = OnElement
            (AttrYYLex, BeginAttrYYLex, 
             ChildYYLex, BeginYYLex);

        else if ((m_comment = m_node->GetCommentInterface()))
                token = OnComment(next_yylex);

        else if ((m_text = m_node->GetTextInterface()))
                    token = OnText(next_yylex);

        return token;
    }

    /**
     **********************************************************************
     * Function: YYLex
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    int YYLex() 
    {
        int token = 0;

        m_err.Write("YYLex()...\n");

        if ((m_node = m_node_list->GetFirstNode()))
        do
        {
            if ((token = YYNode(NextYYLex)))
                return token;
        }
        while ((m_node = m_node->GetNextNode()));
        return token;
    }
    /**
     **********************************************************************
     * Function: NextYYLex
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    int NextYYLex() 
    {
        int token = 0;

        m_err.Write("NextYYLex()...\n");

        while ((m_node = m_node->GetNextNode()))
        {
            if ((token = YYNode(NextYYLex)))
                return token;
        }
        return token;
    }
    /**
     **********************************************************************
     * Function: BeginYYLex
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    int BeginYYLex() 
    {
        int token = XX_BEGIN;

        m_err.Write("BeginYYLex()...\n");

        SetYYText("<>...");
        m_yylex = m_old_yylex;
        return token;
    }
    /**
     **********************************************************************
     * Function: ChildYYLex
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    int ChildYYLex() 
    {
        int token = 0;

        m_err.Write("ChildYYLex()...\n");

        if ((m_node = m_element->GetFirstNode()))
        do
        {
            if ((token = YYNode(NextChildYYLex)))
                return token;
        }
        while ((m_node = m_node->GetNextNode()));

        token = OnEnd(NextChildYYLex, NextYYLex);
        return token;
    }
    /**
     **********************************************************************
     * Function: NextChildYYLex
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    int NextChildYYLex() 
    {
        int token = 0;

        m_err.Write("NextChildYYLex()...\n");

        while ((m_node = m_node->GetNextNode()))
        {
            if ((token = YYNode(NextChildYYLex)))
                return token;
        }

        token = OnEnd(NextChildYYLex, NextYYLex);
        return token;
    }
    /**
     **********************************************************************
     * Function: AttrYYLex
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    int AttrYYLex() 
    {
        int token;
        
        m_err.Write("AttrYYLex()...\n");

        token = OnAttribute();
        m_yylex = NextAttrYYLex;
        return token;
    }
    /**
     **********************************************************************
     * Function: NextAttrYYLex
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    int NextAttrYYLex() 
    {
        int token = XX_END_ATTR;

        m_err.Write("NextAttrYYLex()...\n");

        if ((m_attribute = m_attribute->GetNextAttribute()))
            token = OnAttribute();
        else
        {
            SetYYText("...>");
            m_yylex = BeginYYLex;
            m_old_yylex = ChildYYLex;
        }
        return token;
    }
    /**
     **********************************************************************
     * Function: BeginAttrYYLex
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    int BeginAttrYYLex() 
    {
        int token = XX_BEGIN_ATTR;

        m_err.Write("BeginAttrYYLex()...\n");

        SetYYText("<...");
        m_yylex = m_old_yylex;
        return token;
    }
    /**
     **********************************************************************
     * Function: EOFYYLex
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    int EOFYYLex() 
    {
        int token = 0;

        m_err.Write("EOFYYLex()...\n");
        return token;
    }

    /**
     **********************************************************************
     * Function: OnEnd
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual int OnEnd(mYYLex parent_yylex, mYYLex yylex) 
    {
        int token = XX_END;
        eError error;

        SetYYText("...</>");

        if (!(m_node = m_node_stack.Pop(error)))
            m_yylex = EOFYYLex;

        if (m_node->GetParentElement())
            m_yylex = parent_yylex;
        else m_yylex = yylex;

        return token;
    }
    /**
     **********************************************************************
     * Function: OnText
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual int OnText(mYYLex yylex) 
    {
        int token = XX_TEXT_LITERAL;
        cDocumentNamespaceInterface& lns = GetLanguageNamespace();
        cDocumentNamespaceInterface& ns = m_text->GetNamespace();
        const cCCharBuffer& text = m_text->GetText();
        cDocumentElementInterface* parent = m_text->GetParentElement();

        if (!parent || (&lns == &ns))
        if (IsWhiteSpace(text))
            return 0;

        SetYYText(text);
        m_yylex = yylex;
        return token;
    }
    /**
     **********************************************************************
     * Function: OnComment
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual int OnComment(mYYLex yylex) 
    {
        int token = 0;
        return token;
    }
    /**
     **********************************************************************
     * Function: OnElement
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    virtual int OnElement
    (mYYLex old_attr_yylex, mYYLex attr_yylex, 
     mYYLex old_yylex, mYYLex yylex) 
    {
        int token = XX_ELEMENT_LITERAL;
        cDocumentNamespaceInterface& lns = GetLanguageNamespace();
        cDocumentNamespaceInterface& ns = m_element->GetNamespace();
        const cCCharBuffer& prefix = m_element->GetNamespacePrefix();
        const cCCharBuffer& name = m_element->GetName();
        const cURIInterface& uri = ns.GetNamespaceURI();
        int uri_length = 0;
        const cChar* uri_cchars = uri.GetURICChars(uri_length);
        eError error;

        SetYYText(prefix, name);
        m_old_yylex = old_yylex;
        m_yylex = yylex;

        if ((m_attribute = m_element->GetFirstAttribute()))
        {
            m_old_yylex = old_attr_yylex;
            m_yylex = attr_yylex;
        }

        if (&lns == &ns)
        {
            cXTLToDocumentTokenInterface *t;

            if ((t = m_token_tree.Find(name)))
                token = t->GetType();
            else token = XX_INVALID;
        }

        if ((error = m_node_stack.Push(*m_node)))
            m_yylex = EOFYYLex;

        return token;
    }
    /**
     **********************************************************************
     * Function: OnAttribute
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual int OnAttribute() 
    {
        int token = XX_ATTR_LITERAL;
        cDocumentNamespaceInterface& lns = GetLanguageNamespace();
        cDocumentNamespaceInterface& vns = GetVariableNamespace();
        cDocumentNamespaceInterface& xns = GetExpressionNamespace();
        cDocumentNamespaceInterface& ns = m_attribute->GetNamespace();
        bool is_ns_attribute = m_attribute->GetIsNamespaceAttribute();
        bool is_ns_prefix_attribute = m_attribute->GetIsNamespacePrefixAttribute();
        const cCCharBuffer& prefix = m_attribute->GetNamespacePrefix();
        const cCCharBuffer& name = m_attribute->GetName();

        SetYYText(prefix, name);

        if (is_ns_attribute)
            token = XX_XMLNS_ATTR;

        else if (is_ns_prefix_attribute)
                token = XX_XMLNS_PREFIX_ATTR;

        else if (&lns == &ns)
        {
            cXTLToDocumentTokenInterface *t;

            if ((t = m_token_tree.Find(name)))
                token = t->GetType();
            else token = XX_INVALID;
        }
        else if (&vns == &ns)
            token = XX_VARIABLE_ATTR;

        else if (&xns == &ns)
            token = XX_EXPRESSION_ATTR;

        return token;
    }

    /**
     **********************************************************************
     * Function: SetNodeList
     *
     *   Author: $author$
     *     Date: 11/20/2005
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
     *     Date: 11/20/2005
     **********************************************************************
     */
    cDocumentNodeListInterface* GetNodeList() const 
    {
        return m_node_list;
    }

    /**
     **********************************************************************
     * Function: SetYYText
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    void SetYYText
    (const char* chars, int length=-1) 
    {
        if (0 < (length = m_cchar_buffer.Copyc(chars, length)))
            SetYYText(m_cchar_buffer);
    }
    /**
     **********************************************************************
     * Function: SetYYText
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    void SetYYText
    (const cCCharBuffer& yytext) 
    {
        m_yytext = &yytext;
        m_yytext2 = 0;
    }
    /**
     **********************************************************************
     * Function: SetYYText
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    void SetYYText
    (const cCCharBuffer& yytext,
     const cCCharBuffer& yytext2) 
    {
        if (0 < yytext.GetLength())
        {
            m_yytext = &yytext;
            m_yytext2 = &yytext2;
        }
        else
        {
            m_yytext = &yytext2;
            m_yytext2 = 0;
        }
    }

    /**
     **********************************************************************
     * Function: SetLanguageNamespace
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface& SetLanguageNamespace
    (cDocumentNamespaceInterface* document_namespace) 
    {
        if ((m_language_namespace = document_namespace))
            return *m_language_namespace;

        return cDocumentNamespaceInterface::GetGlobalNamespace();
    }
    /**
     **********************************************************************
     * Function: GetLanguageNamespace
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface& GetLanguageNamespace() const 
    {
        if (m_language_namespace)
            return *m_language_namespace;

        return cDocumentNamespaceInterface::GetGlobalNamespace();
    }
    /**
     **********************************************************************
     * Function: SetVariableNamespace
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface& SetVariableNamespace
    (cDocumentNamespaceInterface* document_namespace) 
    {
        if ((m_variable_namespace = document_namespace))
            return *m_variable_namespace;

        return cDocumentNamespaceInterface::GetGlobalNamespace();
    }
    /**
     **********************************************************************
     * Function: GetVariableNamespace
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface& GetVariableNamespace() const 
    {
        if (m_variable_namespace)
            return *m_variable_namespace;

        return cDocumentNamespaceInterface::GetGlobalNamespace();
    }
    /**
     **********************************************************************
     * Function: SetExpressionNamespace
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface& SetExpressionNamespace
    (cDocumentNamespaceInterface* document_namespace) 
    {
        if ((m_expression_namespace = document_namespace))
            return *m_expression_namespace;

        return cDocumentNamespaceInterface::GetGlobalNamespace();
    }
    /**
     **********************************************************************
     * Function: GetExpressionNamespace
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface& GetExpressionNamespace() const 
    {
        if (m_expression_namespace)
            return *m_expression_namespace;

        return cDocumentNamespaceInterface::GetGlobalNamespace();
    }

    /**
     **********************************************************************
     * Function: IsWhiteSpace
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    bool IsWhiteSpace(const cCCharBuffer& buffer)
    {
        const cChar *chars;
        int i,length;
        char c;

        if ((chars = buffer.GetBuffer(length)))
        for (i=0; i<length; i++)
        switch(c = chars[i].ToChar())
        {
        case ' ':
        case '\n':
        case '\r':
        case '\t':
        case '\v':
            break;
        default:
            return false;
        }
        return true;
    }

    /**
     **********************************************************************
     * Function: SetAttribute
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    cDocumentInterface* SetAttribute
    (cDocumentInterface* node) 
    {
        return node;
    }
    /**
     **********************************************************************
     * Function: GetAttribute
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    cDocumentAttributeInterface* GetAttribute() const 
    {
        cDocumentAttributeInterface* node = m_attribute;
        return node;
    }
    /**
     **********************************************************************
     * Function: SetElement
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    cDocumentInterface* SetElement
    (cDocumentInterface* node) 
    {
        return node;
    }
    /**
     **********************************************************************
     * Function: GetElement
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    cDocumentInterface* GetElement() const 
    {
        cDocumentInterface* node = 0;
        return node;
    }
    /**
     **********************************************************************
     * Function: SetComment
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    cDocumentInterface* SetComment
    (cDocumentInterface* node) 
    {
        return node;
    }
    /**
     **********************************************************************
     * Function: GetComment
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    cDocumentInterface* GetComment() const 
    {
        cDocumentInterface* node = 0;
        return node;
    }
    /**
     **********************************************************************
     * Function: SetText
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    cDocumentInterface* SetText
    (cDocumentInterface* node) 
    {
        return node;
    }
    /**
     **********************************************************************
     * Function: GetText
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    cDocumentInterface* GetText() const 
    {
        cDocumentInterface* node = 0;
        return node;
    }
};

#endif /* _CXTLTODOCUMENTLEXER_HXX */
