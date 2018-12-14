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
 *   File: cxtlparser.hxx
 *
 * Author: $author$
 *   Date: 12/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXTLPARSER_HXX
#define _CXTLPARSER_HXX

#include <stdio.h>
#include "cxtlparse.h"

#define yyIsParser cIsXTLParser
#define yyParser cXTLParser
#include "yyparser.hxx"

#include "clistt.hxx"
#include "cavltreet.hxx"
#include "cstringcharbuffer.hxx"
#include "curischeme.hxx"
#include "curi.hxx"
#include "cdom.hxx"
#include "cdomparser.hxx"

class cXTLTokenBranch;

/**
 **********************************************************************
 *  Class: cXTLTokenInterface
 *
 * Author: $author$
 *   Date: 12/21/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cXTLTokenInterface
{
public:
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetName() const = 0;
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual int GetType() const = 0;
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual cXTLTokenBranch& GetBranch() = 0;
};

/**
 **********************************************************************
 *  Class: cXTLTokenItem
 *
 * Author: $author$
 *   Date: 12/21/2004
 **********************************************************************
 */
class cXTLTokenItem
: public cListItemT<cXTLTokenItem>
{
public:
    typedef cListItemT<cXTLTokenItem> cIs;

    cXTLTokenInterface &m_token;

    /**
     **********************************************************************
     * Constructor: cXTLTokenItem
     *
     *      Author: $author$
     *        Date: 12/21/2004
     **********************************************************************
     */
    cXTLTokenItem(cXTLTokenInterface &token) 
    : m_token(token)
    {
    }
};

/**
 **********************************************************************
 *  Class: cXTLTokenList
 *
 * Author: $author$
 *   Date: 12/21/2004
 **********************************************************************
 */
class cXTLTokenList
: public cStaticListT
  <cXTLTokenItem, cXTLTokenList>
{
public:
    typedef cStaticListT
    <cXTLTokenItem, cXTLTokenList> cIs;
};

/**
 **********************************************************************
 *  Class: cXTLTokenBranch
 *
 * Author: $author$
 *   Date: 12/21/2004
 **********************************************************************
 */
class cXTLTokenBranch
: public cAVLTreeBranchT<cXTLTokenBranch>
{
public:
    typedef cAVLTreeBranchT<cXTLTokenBranch> cIs;

    cXTLTokenInterface& m_token;

    /**
     **********************************************************************
     * Constructor: cXTLTokenBranch
     *
     *      Author: $author$
     *        Date: 12/21/2004
     **********************************************************************
     */
    cXTLTokenBranch(cXTLTokenInterface& token)
    : m_token(token)
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    int Compare(cXTLTokenBranch &branch) const
    {
        const cStringInterface &name = branch.GetName();
        int unequal = Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    int Compare(const cStringInterface &name) const
    {
        const cStringInterface &m_name = GetName();
        int unequal = m_name.Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    const cStringInterface &GetName() const
    {
        return m_token.GetName();
    }
};

/**
 **********************************************************************
 *  Class: cXTLTokenTree
 *
 * Author: $author$
 *   Date: 12/21/2004
 **********************************************************************
 */
class cXTLTokenTree
: public cAVLTreeT
  <const cStringInterface, cXTLTokenBranch, cXTLTokenTree>
{
public:
    typedef cAVLTreeT
    <const cStringInterface, cXTLTokenBranch, cXTLTokenTree> cIs;

    /**
     **********************************************************************
     * Constructor: cXTLTokenTree
     *
     *      Author: $author$
     *        Date: 12/21/2004
     **********************************************************************
     */
    cXTLTokenTree() 
    {
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    cXTLTokenInterface *Find
    (const cDOMNamedNodeInterface& node) const
    {
        const cStringInterface &name = node.GetName();
        cXTLTokenInterface *token = 0;
        cXTLTokenBranch *branch;

        if ((branch = cIs::Find(name)))
            token = &branch->m_token;

        return token;
    }
};

/**
 **********************************************************************
 *  Class: cXTLToken
 *
 * Author: $author$
 *   Date: 12/21/2004
 **********************************************************************
 */
class cXTLToken
: virtual public cXTLTokenInterface
{
public:
    static cXTLTokenList m_list;

    int m_type;
    cString m_name;
    cXTLTokenItem m_item;
    cXTLTokenBranch m_branch;

    /**
     **********************************************************************
     * Constructor: cXTLToken
     *
     *      Author: $author$
     *        Date: 12/21/2004
     **********************************************************************
     */
    cXTLToken(const char *name, int type) 
    : m_name(name),
      m_type(type),
      m_item(*this),
      m_branch(*this)
    {
        m_list.Add(&m_item);
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetName() const
    {
        return m_name;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual int GetType() const
    {
        return m_type;
    }
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual cXTLTokenBranch& GetBranch()
    {
        return m_branch;
    }
};

/**
 **********************************************************************
 *  Class: cXTLLexer
 *
 * Author: $author$
 *   Date: 12/21/2004
 **********************************************************************
 */
class cXTLLexer
{
public:
    typedef int (cXTLLexer::*mYYLex)();

    /**
     **********************************************************************
     *  Class: cStateItem
     *
     * Author: $author$
     *   Date: 1/4/2005
     **********************************************************************
     */
    class cStateItem
    : public cDynamicListItemT<cStateItem>
    {
    public:
        typedef cDynamicListItemT<cStateItem> cIs;

        cDOMDocumentInterface &m_document;
        cDOMNodeListInterface *m_node_list;
        cDOMNodeInterface *m_node;
        cDOMTextInterface *m_text;
        cDOMElementInterface *m_element;
        cDOMAttrInterface *m_attr;
        const cStringInterface *m_yytext, *m_yytext2;
        mYYLex m_old_yylex, m_yylex;

        /**
         **********************************************************************
         * Constructor: cStateItem
         *
         *      Author: $author$
         *        Date: 1/4/2005
         **********************************************************************
         */
        cStateItem
        (cDOMDocumentInterface &document,
         cDOMNodeListInterface *node_list,
         cDOMNodeInterface *node,
         cDOMTextInterface *text,
         cDOMElementInterface *element,
         cDOMAttrInterface *attr,
         const cStringInterface *yytext, 
         const cStringInterface *yytext2,
         mYYLex old_yylex, 
         mYYLex yylex) 
        : m_document(document),
          m_node_list(node_list),
          m_node(node),
          m_text(text),
          m_element(element),
          m_attr(attr),
          m_yytext(yytext),
          m_yytext2(yytext2),
          m_old_yylex(old_yylex),
          m_yylex(yylex)
        {
        }
    };

    /**
     **********************************************************************
     *  Class: cStateList
     *
     * Author: $author$
     *   Date: 1/4/2005
     **********************************************************************
     */
    class cStateList
    : public cDynamicListT
      <cStateItem, cStateList>
    {
    public:
        typedef cDynamicListT
        <cStateItem, cStateList> cIs;
    };

    cDOMNamespaceInterface* m_namespace;
    cDOMNamespaceInterface* m_variable_namespace;

    cDOMNodeListInterface *m_node_list;
    cDOMNodeInterface *m_node;
    cDOMTextInterface *m_text;
    cDOMElementInterface *m_element;
    cDOMAttrInterface *m_attr;
    const cStringInterface *m_yytext,*m_yytext2;
    mYYLex m_old_yylex, m_yylex;

    cStateList m_state_list;
    cDOMNodeReferenceList m_stack;
    cXTLTokenTree m_token_tree;
    cCharBuffer m_buffer;
    cString m_string;

    /**
     **********************************************************************
     * Constructor: cXTLLexer
     *
     *      Author: $author$
     *        Date: 12/21/2004
     **********************************************************************
     */
    cXTLLexer
    (cDOMNodeListInterface &node_list,
     cDOMNamespaceInterface* p_namespace=0,
     cDOMNamespaceInterface* variable_namespace=0) 
    : m_node_list(&node_list),
      m_namespace(p_namespace),
      m_variable_namespace(variable_namespace),
      m_node(0),
      m_text(0),
      m_element(0),
      m_attr(0),
      m_old_yylex(YYLex),
      m_yylex(YYLex),
      m_yytext(0),
      m_yytext2(0)
    {
    }
    /**
     **********************************************************************
     * Function: Init
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    void Init()
    {
        cXTLTokenItem *item;

        if ((item = cXTLToken::m_list.GetFirst()))
        do
        {
            cXTLTokenBranch *branch = &item->m_token.GetBranch();

            m_token_tree.Insert(branch);
        }
        while ((item = item->GetNext()));
    }
    /**
     **********************************************************************
     * Function: Final
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    void Final()
    {
        m_stack.Clear();
        m_token_tree.Clear();
    }
    /**
     **********************************************************************
     * Function: PushDocument
     *
     *   Author: $author$
     *     Date: 1/4/2005
     **********************************************************************
     */
    eError PushDocument(cDOMDocumentInterface &document)
    {
        eError error = e_ERROR_NEW;
        cStateItem *item;

        if ((item = new cStateItem
            (document, m_node_list, 
             m_node, m_text, m_element, m_attr,
             m_yytext, m_yytext2, m_old_yylex, m_yylex)))
        {
            m_state_list.Push(item);
            m_node_list = &document;
            m_node = 0;
            m_text = 0;
            m_element = 0;
            m_attr = 0;
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
    cDOMDocumentInterface *PopDocument()
    {
        cDOMDocumentInterface *document = 0;
        cStateItem *item;

        if ((item = m_state_list.Pop()))
        {
            document = &item->m_document;
            m_node_list = item->m_node_list;
            m_node = item->m_node;
            m_text = item->m_text;
            m_element = item->m_element;
            m_attr = item->m_attr;
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
     *     Date: 12/21/2004
     **********************************************************************
     */
    int yylex() 
    {
        int token;
        cDOMDocumentInterface *document;
        
        while (!(token = (this->*m_yylex)()))
        {
            if (!(document = PopDocument()))
                break;
        }
        return token;
    }
    /**
     **********************************************************************
     * Function: yytext
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    const char *yytext()
    {
        const char *text = "";
        const cChar *chars;
        int i,length;
        const cStringInterface *yytext;

        if ((yytext = m_yytext))
        if (0 >= (length = m_buffer.Clear()))
        {
            do
            {
                if ((chars = yytext->GetChars(length)))
                    for (i=0; i<length; i++)
                        m_buffer.Put(chars[i].ToChar());

                if ((yytext == m_yytext) 
                    && (yytext != m_yytext2))
                if ((yytext = m_yytext2))
                if (0 < (length = yytext->Length()))
                {
                    m_buffer.Put(':');
                    continue;
                }

                yytext = 0;
            }
            while (yytext);

            text = m_buffer.GetBuffer();
        }
        return text;
    }
    /**
     **********************************************************************
     * Function: YYLex
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    int YYLex() 
    {
        int token = 0;

        if ((m_node = m_node_list->GetFirstChild()))
        do
        {
            if ((m_element = m_node->GetElementNode()))
                token = OnElement
                (AttrYYLex, BeginAttrYYLex, 
                 ChildYYLex, BeginYYLex);
            else if ((m_text = m_node->GetTextNode()))
                    token = OnText(NextYYLex);

            if (token)
                return token;
        }
        while ((m_node = m_node->GetNextSibling()));
        return token;
    }
    /**
     **********************************************************************
     * Function: NextYYLex
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    int NextYYLex() 
    {
        int token = 0;

        while ((m_node = m_node->GetNextSibling()))
        {
            if ((m_element = m_node->GetElementNode()))
                token = OnElement
                (AttrYYLex, BeginAttrYYLex, 
                 ChildYYLex, BeginYYLex);
            else if ((m_text = m_node->GetTextNode()))
                    token = OnText(NextYYLex);

            if (token)
                return token;
        }
        return token;
    }
    /**
     **********************************************************************
     * Function: ChildYYLex
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    int ChildYYLex() 
    {
        int token = 0;

        if ((m_node = m_element->GetFirstChild()))
        do
        {
            if ((m_element = m_node->GetElementNode()))
                token = OnElement
                (AttrYYLex, BeginAttrYYLex, 
                 ChildYYLex, BeginYYLex);
            else if ((m_text = m_node->GetTextNode()))
                    token = OnText(NextChildYYLex);

            if (token)
                return token;
        }
        while ((m_node = m_node->GetNextSibling()));

        token = OnEnd(NextChildYYLex, NextYYLex);
        return token;
    }
    /**
     **********************************************************************
     * Function: NextChildYYLex
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    int NextChildYYLex() 
    {
        int token = 0;

        while ((m_node = m_node->GetNextSibling()))
        {
            if ((m_element = m_node->GetElementNode()))
                token = OnElement
                (AttrYYLex, BeginAttrYYLex, 
                 ChildYYLex, BeginYYLex);
            else if ((m_text = m_node->GetTextNode()))
                    token = OnText(NextChildYYLex);

            if (token)
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
     *     Date: 12/21/2004
     **********************************************************************
     */
    int AttrYYLex() 
    {
        int token = OnAttr();
        m_yylex = NextAttrYYLex;
        return token;
    }
    /**
     **********************************************************************
     * Function: NextAttrYYLex
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    int NextAttrYYLex() 
    {
        int token = XX_END_ATTR;

        if ((m_attr = m_attr->GetNextAttribute()))
            token = OnAttr();
        else
        {
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
     *     Date: 12/21/2004
     **********************************************************************
     */
    int BeginAttrYYLex() 
    {
        int token = XX_BEGIN_ATTR;
        const cStringInterface &prefix = m_attr->GetPrefix();
        const cStringInterface &name = m_attr->GetName();

        SetYYText(prefix, name);
        m_yylex = m_old_yylex;
        return token;
    }
    /**
     **********************************************************************
     * Function: BeginYYLex
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    int BeginYYLex() 
    {
        int token = XX_BEGIN;
        m_string.SetChars(">");
        SetYYText(m_string);
        m_yylex = m_old_yylex;
        return token;
    }
    /**
     **********************************************************************
     * Function: EOFYYLex
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    int EOFYYLex() 
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnEnd
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    int OnEnd(mYYLex parent_yylex, mYYLex yylex) 
    {
        int token = XX_END;
        eError error;

        m_string.SetChars("<");
        SetYYText(m_string);

        if (!(m_node = m_stack.Pop(error)))
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
     *     Date: 12/21/2004
     **********************************************************************
     */
    int OnText(mYYLex yylex) 
    {
        int token = 0;
        cDOMNamespaceInterface& ns1 = GetNamespace();
        cDOMNamespaceInterface& ns2 = m_text->GetNamespace();
        const cStringInterface& data = m_text->GetData();
        cDOMElementInterface* parent = m_text->GetParentElement();

        if (!parent || (&ns1 == &ns2))
        if (IsWhiteSpace(data))
            return token;

        m_yylex = yylex;
        SetYYText(data);
        token = XX_TEXT_LITERAL;
        return token;
    }
    /**
     **********************************************************************
     * Function: OnElement
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    int OnElement
    (mYYLex old_attr_yylex, mYYLex attr_yylex, 
     mYYLex old_yylex, mYYLex yylex) 
    {
        int token = XX_ELEMENT_LITERAL;
        cDOMNamespaceInterface& ns1 = GetNamespace();
        cDOMNamespaceInterface& ns2 = m_element->GetNamespace();
        eError error;

        SetYYText(m_element->GetPrefix(), m_element->GetName());
        m_old_yylex = old_yylex;
        m_yylex = yylex;

        if ((m_attr = m_element->GetFirstAttribute()))
        {
            m_old_yylex = old_attr_yylex;
            m_yylex = attr_yylex;
        }

        if (&ns1 == &ns2)
        {
            cXTLTokenInterface *t;

            if ((t = m_token_tree.Find(*m_element)))
                token = t->GetType();
            else token = XX_INVALID;
        }

        if ((error = m_stack.Push(*m_node)))
            m_yylex = EOFYYLex;

        return token;
    }
    /**
     **********************************************************************
     * Function: OnAttr
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    int OnAttr() 
    {
        int token = XX_ATTR_LITERAL;
        cDOMNamespaceInterface& ns = GetNamespace();
        cDOMNamespaceInterface& vns = GetVariableNamespace();
        cDOMNamespaceInterface& ans = m_attr->GetNamespace();
        bool is_xmlns = m_attr->GetIsXmlns();

        SetYYText(m_attr->GetPrefix(), m_attr->GetName());

        if (&ns == &ans)
        {
            if (is_xmlns)
                token = XX_XMLNS_ATTR;
            else
            {
                cXTLTokenInterface *t;

                if ((t = m_token_tree.Find(*m_attr)))
                    token = t->GetType();
                else token = XX_INVALID;
            }
        }
        else if (&vns == &ans)
        {
            if (is_xmlns)
                token = XX_XMLNS_ATTR;
            else token = XX_VARIABLE_ATTR;
        }
        return token;
    }
    /**
     **********************************************************************
     * Function: IsWhiteSpace
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    bool IsWhiteSpace(const cStringInterface& string)
    {
        const cChar *chars;
        int i,length;
        char c;

        if ((chars = string.GetChars(length)))
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
     * Function: SetYYText
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    void SetYYText(const cStringInterface &text)
    {
        m_yytext = &text;
        m_yytext2 = 0;
    }
    /**
     **********************************************************************
     * Function: SetYYText
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    void SetYYText
    (const cStringInterface &text,
     const cStringInterface &text2)
    {
        if (0 < text.Length())
        {
            m_yytext = &text;
            m_yytext2 = &text2;
        }
        else
        {
            m_yytext = &text2;
            m_yytext2 = 0;
        }
    }
    /**
     **********************************************************************
     * Function: GetVariableNamespace
     *
     *   Author: $author$
     *     Date: 12/27/2004
     **********************************************************************
     */
    virtual cDOMNamespaceInterface& GetVariableNamespace() 
    {
        if (m_variable_namespace)
            return *m_variable_namespace;

        return cDOMNamespaceInterface::GetGlobalNamespace();
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual cDOMNamespaceInterface& GetNamespace() 
    {
        if (m_namespace)
            return *m_namespace;

        return cDOMNamespaceInterface::GetGlobalNamespace();
    }
    /**
     **********************************************************************
     * Function: GetAttribute
     *
     *   Author: $author$
     *     Date: 1/4/2005
     **********************************************************************
     */
    cDOMAttrInterface* GetAttribute() 
    {
        return m_attr;
    }
};

/**
 **********************************************************************
 *  Class: cXTLParser
 *
 * Author: $author$
 *   Date: 12/21/2004
 **********************************************************************
 */
class cXTLParser
: public cIsXTLParser
{
public:
    typedef cIsXTLParser cIs;

    cCharStream &m_err;
    cDOMParser &m_dom_parser;
    cXTLLexer m_lexer;
    cStaticURISchemeSet m_uri_scheme_set;
    cURI m_uri;
    eError m_error;

    /**
     **********************************************************************
     * Constructor: cXTLParser
     *
     *      Author: $author$
     *        Date: 12/21/2004
     **********************************************************************
     */
    cXTLParser
    (cCharStream &err,
     cDOMParser &dom_parser,
     cDOMNodeListInterface &node_list,
     cDOMNamespaceInterface* p_namespace=0,
     cDOMNamespaceInterface* variable_namespace=0)
    : m_err(err),
      m_dom_parser(dom_parser),
      m_lexer(node_list, p_namespace, variable_namespace),
      m_uri(m_uri_scheme_set)
    {
    }

    /**
     **********************************************************************
     * Function: Init
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    void Init()
    {
        m_lexer.Init();
    }
    /**
     **********************************************************************
     * Function: Final
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    void Final()
    {
        m_lexer.Final();
    }

    /**
     **********************************************************************
     * Function: OnIncludeLocation
     *
     *   Author: $author$
     *     Date: 12/28/2004
     **********************************************************************
     */
    virtual eError OnIncludeLocation()
    {
        eError error2, error = e_ERROR_NONE;
        cURLInterface *url;
        cCharStreamInterface *content;
        const char *content_type;
        int c, content_length;

        if ((url = m_uri.OpenURL()))
        {
            if ((content = url->GetContent
                (content_type, content_length)))
            {
                cDOMNodeFactoryInterface &factory = m_dom_parser.GetNodeFactory();
                cDOMDocumentInterface *document;

                if ((document = factory.CreateDocument()))
                {
                    cDOMEventInterface &event = m_dom_parser.GetEvent();
                    cDOMDocumentParserEvent document_event(event, factory, *document);
                    cXMLWriter document_writer(document_event);

                    if (!(error = document_writer.Initialize()))
                    {
                        while(0 < (c = content->Getc()))
                            if ((0 > (c = document_writer.Put(c))))
                            {
                                error = -c;
                                break;
                            }
                        if ((error2 = document_writer.Finalize()))
                        if (!error)
                            error = error2;
                    }

                    if (error)
                        factory.DestroyNode(*document);
                    else error = m_lexer.PushDocument(*document);
                }
            }
            m_uri.CloseURL(*url);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnLocationValue
     *
     *   Author: $author$
     *     Date: 12/28/2004
     **********************************************************************
     */
    virtual eError OnLocationValue()
    {
        eError error = e_ERROR_NONE;
        cDOMAttrInterface *attr;

        if ((attr = m_lexer.GetAttribute()))
        {
            const cString &location_string = attr->GetValue();
            cStringCharBuffer location_buffer;
            const char *location;
            int location_length;

            if (0 < (location_length = location_buffer.Set(location_string)))
            if ((location = location_buffer.GetBuffer(location_length)))
            if (0 > (location_length = m_uri.SetURI(location)))
                error = -location_length;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnMethodValue
     *
     *   Author: $author$
     *     Date: 12/28/2004
     **********************************************************************
     */
    virtual eError OnMethodValue()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnMatchValue
     *
     *   Author: $author$
     *     Date: 12/28/2004
     **********************************************************************
     */
    virtual eError OnMatchValue()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnNameValue
     *
     *   Author: $author$
     *     Date: 12/28/2004
     **********************************************************************
     */
    virtual eError OnNameValue()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnExpression
     *
     *   Author: $author$
     *     Date: 12/23/2004
     **********************************************************************
     */
    virtual eError OnExpression()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnVariableExpression
     *
     *   Author: $author$
     *     Date: 12/27/2004
     **********************************************************************
     */
    virtual eError OnVariableExpression()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnLiteralExpression
     *
     *   Author: $author$
     *     Date: 12/27/2004
     **********************************************************************
     */
    virtual eError OnLiteralExpression()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginAttr
     *
     *   Author: $author$
     *     Date: 12/27/2004
     **********************************************************************
     */
    virtual eError OnBeginAttr()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndAttr
     *
     *   Author: $author$
     *     Date: 12/27/2004
     **********************************************************************
     */
    virtual eError OnEndAttr()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnXmlnsAttr
     *
     *   Author: $author$
     *     Date: 12/27/2004
     **********************************************************************
     */
    virtual eError OnXmlnsAttr()
    {
        eError error = e_ERROR_NONE;
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
        int token = m_lexer.yylex();
        return token;
    }
    /**
     **********************************************************************
     * Function: yytext
     *
     *   Author: $author$
     *     Date: 8/26/2003
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
     *     Date: 8/26/2003
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
};

#endif /* _CXTLPARSER_HXX */