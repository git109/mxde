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
 *   File: cxmlparser.hxx
 *
 * Author: $author$
 *   Date: 8/23/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXMLPARSER_HXX
#define _CXMLPARSER_HXX

#include "clistt.hxx"
#include "credblacktreet.hxx"
#include "cinstance.hxx"
#include "ccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cXMLParser
 *
 * Author: $author$
 *   Date: 8/23/2003
 **********************************************************************
 */
class cXMLParser
: public cErrorInstance
{
public:
    typedef cErrorInstance cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 8/23/2003
     **********************************************************************
     */
    enum
    {
        e_FIRST_ERROR=cIs::e_NEXT_ERROR,
        e_NEXT_ERROR=e_FIRST_ERROR,
        e_LAST_ERROR=e_NEXT_ERROR-1
    };

    /**
     **********************************************************************
     *  Class: cAttribute
     *
     * Author: $author$
     *   Date: 8/23/2003
     **********************************************************************
     */
    class cAttribute
    : public cDynamicListItemT<cAttribute>
    {
    public:
        typedef cDynamicListItemT<cAttribute> cIs;

        cCharBuffer m_name, m_value;

        /**
         **********************************************************************
         * Constructor: cAttribute
         *
         *      Author: $author$
         *        Date: 8/23/2003
         **********************************************************************
         */
        cAttribute
        (const char *name=0,int namelen=-1,
         const char *value=0,int valuelen=-1)
        {
            eError error;

            if (name)
            if ((namelen=m_name.Write(name,namelen)) < 0)
                throw(error=e_ERROR_WRITE);

            if (value)
            if ((valuelen=m_value.Write(value,valuelen)) < 0)
                throw(error=e_ERROR_WRITE);
        }
        /**
         **********************************************************************
         * Function: GetName
         *
         *   Author: $author$
         *     Date: 8/23/2003
         **********************************************************************
         */
        inline const char *GetName(int &namelen)
        {
            namelen=m_name.GetLength();
            return m_name.GetBuffer();
        }
        /**
         **********************************************************************
         * Function: GetValue
         *
         *   Author: $author$
         *     Date: 8/23/2003
         **********************************************************************
         */
        inline const char *GetValue(int &valuelen)
        {
            valuelen=m_value.GetLength();
            return m_value.GetBuffer();
        }
    };

    /**
     **********************************************************************
     *  Class: cAttributeList
     *
     * Author: $author$
     *   Date: 8/23/2003
     **********************************************************************
     */
    class cAttributeList
    : public cDynamicListT<cAttribute,cAttributeList>
    {
    public:
        typedef cDynamicListT<cAttribute,cAttributeList> cIs;
    };

    /**
     **********************************************************************
     *  Class: cLexicon
     *
     * Author: $author$
     *   Date: 8/23/2003
     **********************************************************************
     */
    class cLexicon
    : public cDynamicListItemT<cLexicon>
    {
    public:
        typedef cDynamicListItemT<cLexicon> cIs;

        /**
         **********************************************************************
         *   Enum: 
         *
         * Author: $author$
         *   Date: 8/23/2003
         **********************************************************************
         */
        enum
        {
            e_TYPE_PRAGMA,
            e_TYPE_COMMENT,
            e_TYPE_TEXT,
            e_TYPE_TAG,
            e_TYPE_SIMPLE_TAG,
            e_TYPE_END_TAG
        };

        /**
         **********************************************************************
         *  Class: cItem
         *
         * Author: $author$
         *   Date: 8/23/2003
         **********************************************************************
         */
        class cItem
        : public cListItemT<cItem>
        {
        public:
            typedef cListItemT<cItem> cIs;

            cLexicon &m_lexicon;

            /**
             **********************************************************************
             * Constructor: cItem
             *
             *      Author: $author$
             *        Date: 8/23/2003
             **********************************************************************
             */
            cItem(cLexicon &lexicon)
            : m_lexicon(lexicon) 
            {
            }
        };

        /**
         **********************************************************************
         *  Class: cStack
         *
         * Author: $author$
         *   Date: 8/23/2003
         **********************************************************************
         */
        class cStack
        : public cListT<cItem,cStack>
        {
        public:
            typedef cListT<cItem,cStack> cIs;

            /**
             **********************************************************************
             * Function: Push
             *
             *   Author: $author$
             *     Date: 8/23/2003
             **********************************************************************
             */
            inline void Push(cLexicon &lexicon)
            {
                cIs::Push(&lexicon.m_item);
            }
            /**
             **********************************************************************
             * Function: Pop
             *
             *   Author: $author$
             *     Date: 8/23/2003
             **********************************************************************
             */
            cLexicon *Pop()
            {
                cItem *item;

                if ((item=cIs::Pop()))
                    return &item->m_lexicon;
                return 0;
            }
        };

        /**
         **********************************************************************
         *  Class: cBranch
         *
         * Author: $author$
         *   Date: 12/30/2003
         **********************************************************************
         */
        class cBranch
        : public cRedBlackTreeBranchT<cBranch>
        {
        public:
            typedef cRedBlackTreeBranchT<cBranch> cIs;

            cLexicon &m_lexicon;

            /**
             **********************************************************************
             * Constructor: cBranch
             *
             *      Author: $author$
             *        Date: 12/30/2003
             **********************************************************************
             */
            cBranch(cLexicon &lexicon)
            : m_lexicon(lexicon) 
            {
            }

            /**
             **********************************************************************
             * Function: Compare
             *
             *   Author: $author$
             *     Date: 12/30/2003
             **********************************************************************
             */
            int Compare(const cBranch &branch) const
            {
                return stricmp
                (branch.m_lexicon.m_text.GetBuffer(), 
                 m_lexicon.m_text.GetBuffer());
            }
            /**
             **********************************************************************
             * Function: Compare
             *
             *   Author: $author$
             *     Date: 12/30/2003
             **********************************************************************
             */
            int Compare(const cCharBuffer &leaf) const
            {
                return stricmp
                (leaf.GetBuffer(), m_lexicon.m_text.GetBuffer());
            }
        };

        /**
         **********************************************************************
         *  Class: cTree
         *
         * Author: $author$
         *   Date: 12/30/2003
         **********************************************************************
         */
        class cTree
        : public cRedBlackTreeT<cCharBuffer, cBranch, cTree>
        {
        public:
            typedef cRedBlackTreeT<cCharBuffer, cBranch, cTree> cIs;

            /**
             **********************************************************************
             * Function: Clear
             *
             *   Author: $author$
             *     Date: 12/30/2003
             **********************************************************************
             */
            inline void Clear()
            {
                SetRoot(0);
            }
            /**
             **********************************************************************
             * Function: Insert
             *
             *   Author: $author$
             *     Date: 12/30/2003
             **********************************************************************
             */
            inline void Insert(cLexicon &lexicon)
            {
                cIs::Insert(&lexicon.m_branch);
            }
            /**
             **********************************************************************
             * Function: Find
             *
             *   Author: $author$
             *     Date: 12/30/2003
             **********************************************************************
             */
            cLexicon *Find(cLexicon &lexicon) const
            {
                cBranch *branch;

                if ((branch=cIs::Find(lexicon.m_text)))
                    return &branch->m_lexicon;

                return 0;
            }
        };

        cItem m_item;
        cBranch m_branch;
        unsigned m_type;
        cCharBuffer m_text;
        cAttributeList m_attribute_list;

        /**
         **********************************************************************
         * Constructor: cLexicon
         *
         *      Author: $author$
         *        Date: 8/23/2003
         **********************************************************************
         */
        cLexicon(unsigned type,const char *text=0,int textlen=-1)
        : m_item(*this),
          m_branch(*this),
          m_type(type)
        {
            eError error;

            if (text)
            if ((textlen=m_text.Write(text,textlen)) < 0)
                throw(error=e_ERROR_WRITE);
        }
        /**
         **********************************************************************
         * Function: ParseTag
         *
         *   Author: $author$
         *     Date: 8/23/2003
         **********************************************************************
         */
        eError ParseTag()
        {
            enum eState
            {
                e_STATE_TAG,
                e_STATE_NAME,
                e_STATE_EQUAL,
                e_STATE_VALUE,
                e_STATE_QUOTE_VALUE,
                e_STATE_QUOTES_VALUE,
                e_STATE_SPACE,
                e_STATE_QUOTE,
                e_STATE_QUOTES
            };

            int taglen;
            int namelen;
            int valuelen;
            int *lenptr;
            const char *c;
            const char *name;
            const char *value;
            const char **bufptr;
            eState state;
            eState nextstate;

            taglen=0;
            namelen=0;
            valuelen=0;
            state=e_STATE_TAG;

            for (c=m_text.GetBuffer(); *c; c++)
            {
                switch(state)
                {
                case e_STATE_TAG:
                    switch(*c)
                    {
                    case ' ':
                    case '\t':
                    case '\r':
                    case '\n':
                        bufptr=&name;
                        lenptr=&namelen;
                        nextstate=e_STATE_NAME;
                        state=e_STATE_SPACE;
                        break;

                    default:
                        taglen++;
                    }
                    break;

                case e_STATE_NAME:
                    switch(*c)
                    {
                    case ' ':
                    case '\t':
                    case '\r':
                    case '\n':
                        state=e_STATE_EQUAL;
                        break;

                    case '=':
                        bufptr=&value;
                        lenptr=&valuelen;
                        nextstate=e_STATE_VALUE;
                        state=e_STATE_SPACE;
                        break;

                    case '\'':
                        OnAttribute(name,namelen);
                        nextstate=e_STATE_NAME;
                        state=e_STATE_QUOTE;
                        break;

                    case '"':
                        OnAttribute(name,namelen);
                        nextstate=e_STATE_NAME;
                        state=e_STATE_QUOTES;
                        break;

                    default:
                        namelen++;
                    }
                    break;

                case e_STATE_EQUAL:
                    switch(*c)
                    {
                    case ' ':
                    case '\t':
                    case '\r':
                    case '\n':
                        break;

                    case '=':
                        bufptr=&value;
                        lenptr=&valuelen;
                        nextstate=e_STATE_VALUE;
                        state=e_STATE_SPACE;
                        break;

                    case '\'':
                        OnAttribute(name,namelen);
                        nextstate=e_STATE_NAME;
                        state=e_STATE_QUOTE;
                        break;

                    case '"':
                        OnAttribute(name,namelen);
                        nextstate=e_STATE_NAME;
                        state=e_STATE_QUOTES;
                        break;

                    default:
                        OnAttribute(name,namelen);
                        name=c;
                        namelen=1;
                        state=e_STATE_NAME;
                    }
                    break;

                case e_STATE_VALUE:
                    switch(*c)
                    {
                    case ' ':
                    case '\r':
                    case '\t':
                    case '\n':
                        OnAttribute(name,namelen,value,valuelen);
                        namelen=0;
                        valuelen=0;
                        bufptr=&name;
                        lenptr=&namelen;
                        nextstate=e_STATE_NAME;
                        state=e_STATE_SPACE;
                        break;

                    default:
                        valuelen++;
                    }
                    break;

                case e_STATE_SPACE:
                    switch(*c)
                    {
                    case ' ':
                    case '\r':
                    case '\t':
                    case '\n':
                        break;

                    case '\'':
                        switch(nextstate)
                        {
                        case e_STATE_VALUE:
                            *bufptr=c+1;
                            valuelen=0;
                            state=e_STATE_QUOTE_VALUE;
                            break;

                        default:
                            state=e_STATE_QUOTE;
                        }
                        break;

                    case '"':
                        switch(nextstate)
                        {
                        case e_STATE_VALUE:
                            *bufptr=c+1;
                            valuelen=0;
                            state=e_STATE_QUOTES_VALUE;
                            break;

                        default:
                            state=e_STATE_QUOTES;
                        }
                        break;

                    default:
                        *bufptr=c;
                        *lenptr=1;
                        state=nextstate;
                    }
                    break;

                case e_STATE_QUOTE_VALUE:
                    switch(*c)
                    {
                    case '\'':
                        OnAttribute(name,namelen,value,valuelen);
                        namelen=0;
                        valuelen=0;
                        bufptr=&name;
                        lenptr=&namelen;
                        nextstate=e_STATE_NAME;
                        state=e_STATE_SPACE;

                    default:
                        (*lenptr)++;
                    }
                    break;

                case e_STATE_QUOTES_VALUE:
                    switch(*c)
                    {
                    case '"':
                        OnAttribute(name,namelen,value,valuelen);
                        namelen=0;
                        valuelen=0;
                        bufptr=&name;
                        lenptr=&namelen;
                        nextstate=e_STATE_NAME;
                        state=e_STATE_SPACE;

                    default:
                        (*lenptr)++;
                    }
                    break;

                case e_STATE_QUOTE:
                    switch(*c)
                    {
                    case '\'':
                        state=e_STATE_SPACE;
                    }
                    break;

                case e_STATE_QUOTES:
                    switch(*c)
                    {
                    case '"':
                        state=e_STATE_SPACE;
                    }
                    break;
                }
            }

            switch(state)
            {
            case e_STATE_NAME:
            case e_STATE_EQUAL:
                OnAttribute(name,namelen);
                break;

            case e_STATE_SPACE:
                switch(nextstate)
                {
                case e_STATE_VALUE:
                    OnAttribute(name,namelen);
                    break;
                }
                break;

            case e_STATE_VALUE:
            case e_STATE_QUOTE_VALUE:
            case e_STATE_QUOTES_VALUE:
                OnAttribute(name,namelen,value,valuelen);
                break;
            }

            m_text.SetLength(taglen);
            return e_ERROR_NONE;
        }
        /**
         **********************************************************************
         * Function: ParseEndTag
         *
         *   Author: $author$
         *     Date: 8/23/2003
         **********************************************************************
         */
        eError ParseEndTag()
        {
            int taglen;
            const char *c;

            taglen=0;

            for (c=m_text.GetBuffer(); *c; c++)
            {
                switch(*c)
                {
                case ' ':
                case '\r':
                case '\t':
                case '\n':
                    m_text.SetLength(taglen);
                    return e_ERROR_NONE;
                    break;

                default:
                    taglen++;
                }
            }
            return e_ERROR_NONE;
        }

        /**
         **********************************************************************
         * Function: OnAttribute
         *
         *   Author: $author$
         *     Date: 8/23/2003
         **********************************************************************
         */
        virtual eError OnAttribute
        (const char *name,int namelen,
         const char *value=0,int valuelen=0)
        {
            cAttribute *attr;

            if (!(attr=new cAttribute
                (name,namelen,value,valuelen)))
                return e_ERROR_NEW;

            m_attribute_list.Add(attr);
            return e_ERROR_NONE;
        }

        /**
         **********************************************************************
         * Function: GetFirstAttribute
         *
         *   Author: $author$
         *     Date: 8/23/2003
         **********************************************************************
         */
        inline cAttribute *GetFirstAttribute() const
        {
            return m_attribute_list.GetFirst();
        }
        /**
         **********************************************************************
         * Function: GetLastAttribute
         *
         *   Author: $author$
         *     Date: 8/23/2003
         **********************************************************************
         */
        inline cAttribute *GetLastAttribute() const
        {
            return m_attribute_list.GetLast();
        }
        /**
         **********************************************************************
         * Function: GetType
         *
         *   Author: $author$
         *     Date: 8/23/2003
         **********************************************************************
         */
        inline int GetType() const
        {
            return m_type;
        }
        /**
         **********************************************************************
         * Function: GetText
         *
         *   Author: $author$
         *     Date: 8/23/2003
         **********************************************************************
         */
        inline const char *GetText(int &length) const
        {
            length=m_text.GetLength();
            return m_text.GetBuffer();
        }
        /**
         **********************************************************************
         * Function: GetText
         *
         *   Author: $author$
         *     Date: 8/23/2003
         **********************************************************************
         */
        inline const char *GetText() const
        {
            return m_text.GetBuffer();
        }
    };

    /**
     **********************************************************************
     *  Class: cLexiconList
     *
     * Author: $author$
     *   Date: 8/23/2003
     **********************************************************************
     */
    class cLexiconList
    : public cDynamicListT<cLexicon,cLexiconList>
    {
    public:
        typedef cDynamicListT<cLexicon,cLexiconList> cIs;
    };

    bool m_include_multiple_root_elements;
    bool m_include_whitespace;
    bool m_include_comments;

    int m_depth;
    cLexicon::cStack m_begin_tags;
    cLexiconList m_lexicon_list;

    /**
     **********************************************************************
     * Constructor: cXMLParser
     *
     *      Author: $author$
     *        Date: 8/23/2003
     **********************************************************************
     */
    cXMLParser
    (bool include_multiple_root_elements=false,
     bool include_whitespace=false,
     bool include_comments=false)
    : m_include_multiple_root_elements(include_multiple_root_elements),
      m_include_whitespace(include_whitespace),
      m_include_comments(include_comments) 
    {
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError ParseFromStream(cCharStream &source)
    {
        eError error;
        cLexicon *begin;
        cLexicon *lexicon;
        int type;

        if ((error=ParseLexiconsFromStream(source)))
            return error;

        m_depth=0;

        if ((lexicon=m_lexicon_list.GetFirst()))
        do
        {
            switch((type=lexicon->GetType()))
            {
            case cLexicon::e_TYPE_COMMENT:
                if (!m_include_comments)
                    break;

                if (m_depth<1)
                if (!m_include_multiple_root_elements)
                    break;

                if ((error=OnCommentElement(*lexicon)))
                    return error;
                break;

            case cLexicon::e_TYPE_TEXT:
                if (m_depth<1)
                if (!m_include_multiple_root_elements)
                    break;

                if ((error=OnTextElement(*lexicon)))
                    return error;
                break;

            case cLexicon::e_TYPE_SIMPLE_TAG:
                if ((error=OnElement(*lexicon)))
                    return error;

                if (m_depth<1)
                if (!m_include_multiple_root_elements)
                    return e_ERROR_NONE;

                break;

            case cLexicon::e_TYPE_TAG:
                if ((error=OnParseTag(*lexicon)))
                    return error;

                break;

            case cLexicon::e_TYPE_END_TAG:
                while(begin=m_begin_tags.Pop())
                {
                    if ((error=OnEndElement(*begin)))
                        return error;

                    if (!CompareTags(lexicon->m_text, begin->m_text))
                        break;
                }

                if (m_depth<1)
                if (!m_include_multiple_root_elements)
                    return e_ERROR_NONE;

                break;
            }
        }
        while((lexicon=lexicon->GetNext()));

        while(begin=m_begin_tags.Pop())
            if ((error=OnEndElement(*begin)))
                return error;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: CompareTags
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual int CompareTags
    (cCharBuffer &tag1, cCharBuffer &tag2) const
    {
        return strcmp(tag1.GetBuffer(), tag2.GetBuffer());
    }
    /**
     **********************************************************************
     * Function: OnParseTag
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnParseTag(cLexicon &lexicon)
    {
        eError error;

        if ((error=OnBeginElement(lexicon)))
            return error;

        m_begin_tags.Push(lexicon);
        return error;
    }

    /**
     **********************************************************************
     * Function: ParseLexiconsFromStream
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError ParseLexiconsFromStream(cCharStream &source)
    {
        enum eState
        {
            e_STATE_TEXT,
            e_STATE_LESS,
            e_STATE_QUESTION,
            e_STATE_QUESTION_PRAGMA,
            e_STATE_PRAGMA_QUESTION,
            e_STATE_EXCLAIM,
            e_STATE_DASH,
            e_STATE_COMMENT,
            e_STATE_COMMENT_DASH,
            e_STATE_COMMENT_DASHDASH,
            e_STATE_PRAGMA,
            e_STATE_TAG,
            e_STATE_TAG_SLASH,
            e_STATE_SLASH_TAG,
            e_STATE_QUOTES,
            e_STATE_QUOTE
        };        
        char c;
        int count;
        eState state;
        eState oldstate;
        cCharBuffer buffer;

        m_begin_tags.Clear();
        m_lexicon_list.Clear();

        for (state=e_STATE_TEXT; (count=source.Get(c))>0;)
        {
            switch(state)
            {
            case e_STATE_TEXT:
                switch(c)
                {
                case '<':
                    if (buffer.GetLength()>0)
                    {
                        OnText(buffer);
                        buffer.Clear();
                    }
                    state=e_STATE_LESS;
                    break;

                default:
                    buffer.Put(c);
                }
                break;

            case e_STATE_LESS:
                switch(c)
                {
                case '>':
                    state=e_STATE_TEXT;
                    break;
                case '?':
                    state=e_STATE_QUESTION;
                    break;
                case '!':
                    state=e_STATE_EXCLAIM;
                    break;
                case '/':
                    state=e_STATE_SLASH_TAG;
                    break;
                default:
                    buffer.Put(c);
                    state=e_STATE_TAG;
                }
                break;

            case e_STATE_QUESTION:
                switch(c)
                {
                case '>':
                    state=e_STATE_TEXT;
                    break;
                default:
                    buffer.Put(c);
                    state=e_STATE_QUESTION_PRAGMA;
                }
                break;

            case e_STATE_QUESTION_PRAGMA:
                switch(c)
                {
                case '?':
                    state=e_STATE_PRAGMA_QUESTION;
                    break;

                case '>':
                    OnPragma(buffer);
                    buffer.Clear();
                    state=e_STATE_TEXT;
                    break;

                case '"':
                    buffer.Put(c);
                    oldstate=state;
                    state=e_STATE_QUOTES;
                    break;

                case '\'':
                    buffer.Put(c);
                    oldstate=state;
                    state=e_STATE_QUOTE;
                    break;

                default:
                    buffer.Put(c);
                }
                break;

            case e_STATE_PRAGMA_QUESTION:
                switch(c)
                {
                case '>':
                    OnPragma(buffer);
                    buffer.Clear();
                    state=e_STATE_TEXT;
                    break;

                case '"':
                    buffer.Put('?');
                    buffer.Put(c);
                    oldstate=e_STATE_QUESTION_PRAGMA;
                    state=e_STATE_QUOTES;
                    break;

                case '\'':
                    buffer.Put('?');
                    buffer.Put(c);
                    oldstate=e_STATE_QUESTION_PRAGMA;
                    state=e_STATE_QUOTE;
                    break;

                default:
                    buffer.Put('?');
                    buffer.Put(c);
                    state=e_STATE_QUESTION_PRAGMA;
                }
                break;

            case e_STATE_EXCLAIM:
                switch(c)
                {
                case '-':
                    state=e_STATE_DASH;
                    break;
                default:
                    buffer.Put(c);
                    state=e_STATE_PRAGMA;
                }
                break;

            case e_STATE_DASH:
                switch(c)
                {
                case '-':
                    state=e_STATE_COMMENT;
                    break;
                default:
                    buffer.Put(c);
                    state=e_STATE_TAG;
                }
                break;

            case e_STATE_COMMENT:
                switch(c)
                {
                case '-':
                    state=e_STATE_COMMENT_DASH;
                    break;
                default:
                    buffer.Put(c);
                }
                break;

            case e_STATE_COMMENT_DASH:
                switch(c)
                {
                case '-':
                    state=e_STATE_COMMENT_DASHDASH;
                    break;
                default:
                    buffer.Put('-');
                    buffer.Put(c);
                    state=e_STATE_COMMENT;
                }
                break;

            case e_STATE_COMMENT_DASHDASH:
                switch(c)
                {
                case '>':
                    OnComment(buffer);
                    buffer.Clear();
                    state=e_STATE_TEXT;
                    break;
                case '-':
                    buffer.Put('-');
                    break;
                default:
                    buffer.Put('-');
                    buffer.Put('-');
                    buffer.Put(c);
                    state=e_STATE_COMMENT;
                }
                break;

            case e_STATE_PRAGMA:
                switch(c)
                {
                case '>':
                    OnPragma(buffer);
                    buffer.Clear();
                    state=e_STATE_TEXT;
                    break;

                case '"':
                    buffer.Put(c);
                    oldstate=state;
                    state=e_STATE_QUOTES;
                    break;

                case '\'':
                    buffer.Put(c);
                    oldstate=state;
                    state=e_STATE_QUOTE;
                    break;

                default:
                    buffer.Put(c);
                }
                break;

            case e_STATE_TAG:
                switch(c)
                {
                case '>':
                    OnTag(buffer);
                    buffer.Clear();
                    state=e_STATE_TEXT;
                    break;

                case '/':
                    state=e_STATE_TAG_SLASH;
                    break;

                case '"':
                    buffer.Put(c);
                    oldstate=state;
                    state=e_STATE_QUOTES;
                    break;

                case '\'':
                    buffer.Put(c);
                    oldstate=state;
                    state=e_STATE_QUOTE;
                    break;

                default:
                    buffer.Put(c);
                }
                break;

            case e_STATE_TAG_SLASH:
                switch(c)
                {
                case '>':
                    OnSimpleTag(buffer);
                    buffer.Clear();
                    state=e_STATE_TEXT;
                    break;

                case '"':
                    buffer.Put(c);
                    oldstate=e_STATE_TAG;
                    state=e_STATE_QUOTES;
                    break;

                case '\'':
                    buffer.Put(c);
                    oldstate=e_STATE_TAG;
                    state=e_STATE_QUOTE;
                    break;

                default:
                    buffer.Put(c);
                    state=e_STATE_TAG;
                }
                break;

            case e_STATE_SLASH_TAG:
                switch(c)
                {
                case '>':
                    OnEndTag(buffer);
                    buffer.Clear();
                    state=e_STATE_TEXT;
                    break;

                case '"':
                    buffer.Put(c);
                    oldstate=state;
                    state=e_STATE_QUOTES;
                    break;

                case '\'':
                    buffer.Put(c);
                    oldstate=state;
                    state=e_STATE_QUOTE;
                    break;

                default:
                    buffer.Put(c);
                }
                break;

            case e_STATE_QUOTES:
                switch(c)
                {
                case '"':
                    buffer.Put(c);
                    state=oldstate;
                    break;
                default:
                    buffer.Put(c);
                }
                break;

            case e_STATE_QUOTE:
                switch(c)
                {
                case '\'':
                    buffer.Put(c);
                    state=oldstate;
                    break;
                default:
                    buffer.Put(c);
                }
                break;
            }
        }
        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnCommentElement(cLexicon &lexicon)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnTextElement(cLexicon &lexicon)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnElement(cLexicon &lexicon)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnBeginElement(cLexicon &lexicon)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnEndElement(cLexicon &lexicon)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnPragma(cCharBuffer &buffer)
    {
        cLexicon *lexicon;

        if (!(lexicon=new cLexicon
            (cLexicon::e_TYPE_PRAGMA,
             buffer.GetBuffer(),buffer.GetLength())))
             return e_ERROR_NEW;

        m_lexicon_list.Add(lexicon);
        return OnPragmaLexicon(*lexicon);
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnComment(cCharBuffer &buffer)
    {
        cLexicon *lexicon;

        if (!(lexicon=new cLexicon
            (cLexicon::e_TYPE_COMMENT,
             buffer.GetBuffer(),buffer.GetLength())))
             return e_ERROR_NEW;

        m_lexicon_list.Add(lexicon);
        return OnCommentLexicon(*lexicon);
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnText(cCharBuffer &buffer)
    {
        cLexicon *lexicon;

        if (!(lexicon=new cLexicon
            (cLexicon::e_TYPE_TEXT,
             buffer.GetBuffer(),buffer.GetLength())))
             return e_ERROR_NEW;

        m_lexicon_list.Add(lexicon);
        return OnTextLexicon(*lexicon);
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnTag(cCharBuffer &buffer)
    {
        cLexicon *lexicon;
        eError error;

        if (!(lexicon=new cLexicon
            (cLexicon::e_TYPE_TAG,
             buffer.GetBuffer(),buffer.GetLength())))
             return e_ERROR_NEW;

        if ((error=lexicon->ParseTag()))
        {
            delete lexicon;
            return e_ERROR_FAILED;
        }

        m_lexicon_list.Add(lexicon);
        return OnTagLexicon(*lexicon);
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnSimpleTag(cCharBuffer &buffer)
    {
        cLexicon *lexicon;
        eError error;

        if (!(lexicon=new cLexicon
            (cLexicon::e_TYPE_SIMPLE_TAG,
             buffer.GetBuffer(),buffer.GetLength())))
             return e_ERROR_NEW;

        if ((error=lexicon->ParseTag()))
        {
            delete lexicon;
            return e_ERROR_FAILED;
        }

        m_lexicon_list.Add(lexicon);
        return OnSimpleTagLexicon(*lexicon);
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnEndTag(cCharBuffer &buffer)
    {
        cLexicon *lexicon;
        eError error;

        if (!(lexicon=new cLexicon
            (cLexicon::e_TYPE_END_TAG,
             buffer.GetBuffer(),buffer.GetLength())))
             return e_ERROR_NEW;

        if ((error=lexicon->ParseEndTag()))
        {
            delete lexicon;
            return e_ERROR_FAILED;
        }

        m_lexicon_list.Add(lexicon);
        return OnEndTagLexicon(*lexicon);
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnPragmaLexicon(cLexicon &lexicon)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnCommentLexicon(cLexicon &lexicon)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnTextLexicon(cLexicon &lexicon)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnTagLexicon(cLexicon &lexicon)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnSimpleTagLexicon(cLexicon &lexicon)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError OnEndTagLexicon(cLexicon &lexicon)
    {
        return e_ERROR_NONE;
    }
};


#endif
