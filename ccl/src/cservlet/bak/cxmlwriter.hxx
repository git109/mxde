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
 *   File: cxmlwriter.hxx
 *
 * Author: $author$
 *   Date: 11/23/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXMLWRITER_HXX
#define _CXMLWRITER_HXX

#include "cxmlparserinterface.hxx"
#include "ccharbuffer.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cXMLTagWriter
 *
 * Author: $author$
 *   Date: 11/25/2004
 **********************************************************************
 */
class cXMLTagWriter
: public cXMLTagParserEventProxy
{
public:
    typedef cXMLTagParserEventProxy cIs;

    typedef int (cXMLTagWriter::*mPut)(int c);

    mPut m_old_put, m_put;
    cCharBuffer m_buffer;
    const char *m_text;
    int m_length;
    int m_quote;

    /**
     **********************************************************************
     * Constructor: cXMLTagWriter
     *
     *      Author: $author$
     *        Date: 11/25/2004
     **********************************************************************
     */
    cXMLTagWriter
    (cXMLTagParserEventInterface &proxy) 
    : cIs(proxy),
      m_old_put(TagPut),
      m_put(TagPut)
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;

        m_old_put = TagPut;
        m_put = TagPut;

        if (0 > (m_length = m_buffer.Clear()))
            error = -m_length;
        return error;
    }
    /**
     **********************************************************************
     * Function: EndInitialize
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    virtual eError EndInitialize() 
    {
        eError error = e_ERROR_NONE;

        m_old_put = EndTagPut;
        m_put = EndTagPut;

        if (0 > (m_length = m_buffer.Clear()))
            error = -m_length;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        Put(-e_ERROR_ENDOF);
        return error;
    }

    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    int Put(int c) 
    {
        int count = (this->*m_put)(c);
        return count;
    }
    /**
     **********************************************************************
     * Function: TagPut
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    int TagPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case -e_ERROR_ENDOF:
        case '\n':
        case '\r':
        case '\t':
        case '\v':
        case ' ':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnElementName(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_old_put = NamePut;
            m_put = SpacePut;
            break;

        case ':':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnElementPrefix(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_put = PrefixTagPut;
            break;

        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: PrefixTagPut
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    int PrefixTagPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case -e_ERROR_ENDOF:
        case '\n':
        case '\r':
        case '\t':
        case '\v':
        case ' ':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnElementName(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_old_put = NamePut;
            m_put = SpacePut;
            break;

        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: EndTagPut
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    int EndTagPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case -e_ERROR_ENDOF:
        case '\n':
        case '\r':
        case '\t':
        case '\v':
        case ' ':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnEndElementName(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_old_put = SpacePut;
            m_put = SpacePut;
            break;

        case ':':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnEndElementPrefix(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_put = PrefixEndTagPut;
            break;

        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: PrefixEndTagPut
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    int PrefixEndTagPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case -e_ERROR_ENDOF:
        case '\n':
        case '\r':
        case '\t':
        case '\v':
        case ' ':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnEndElementName(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_old_put = SpacePut;
            m_put = SpacePut;
            break;

        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: NamePut
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    int NamePut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case -e_ERROR_ENDOF:
        case '\n':
        case '\r':
        case '\t':
        case '\v':
        case ' ':
        case '=':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnAttributeName(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();

            if ('=' != c)
                m_put = EqualPut;
            else m_put = ValuePut;
            break;

        case ':':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnAttributePrefix(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_put = PrefixNamePut;
            break;

        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: PrefixNamePut
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    int PrefixNamePut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case -e_ERROR_ENDOF:
        case '\n':
        case '\r':
        case '\t':
        case '\v':
        case ' ':
        case '=':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnAttributeName(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();

            if ('=' != c)
                m_put = EqualPut;
            else m_put = ValuePut;
            break;

        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: EqualPut
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    int EqualPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '\n':
        case '\r':
        case '\t':
        case '\v':
        case ' ':
            break;

        case '=':
            m_put = ValuePut;
            break;

        default:
            count = -e_ERROR_INVALID_SYNTAX;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: ValuePut
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    int ValuePut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '\n':
        case '\r':
        case '\t':
        case '\v':
        case ' ':
            break;

        case '"':
            m_put = QuotesValuePut;
            break;

        case '\'':
            m_put = QuoteValuePut;
            break;

        default:
            count = -e_ERROR_INVALID_SYNTAX;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: QuotesValuePut
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    int QuotesValuePut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '"':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 <= m_length)
            if (0  > (m_length = OnAttributeValue(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();

            m_old_put = NamePut;
            m_put = SpacePut;
            break;

        case '\'':
            m_old_put = m_put;
            m_put = QuotePut;
        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: QuoteValuePut
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    int QuoteValuePut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '\'':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 <= m_length)
            if (0  > (m_length = OnAttributeValue(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();

            m_old_put = NamePut;
            m_put = SpacePut;
            break;

        case '"':
            m_old_put = m_put;
            m_put = QuotesPut;
        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: QuotesPut
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    int QuotesPut(int c) 
    {
        int count = m_buffer.Put(c);

        if ('"' == c)
            m_put = m_old_put;
        return count;
    }
    /**
     **********************************************************************
     * Function: QuotePut
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    int QuotePut(int c) 
    {
        int count = m_buffer.Put(c);

        if ('\'' == c)
            m_put = m_old_put;
        return count;
    }
    /**
     **********************************************************************
     * Function: SpacePut
     *
     *   Author: $author$
     *     Date: 11/25/2004
     **********************************************************************
     */
    int SpacePut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '\n':
        case '\r':
        case '\t':
        case '\v':
        case ' ':
            break;

        default:
            count = m_buffer.Put(c);
            m_put = m_old_put;
        }
        return count;
    }
};

/**
 **********************************************************************
 *  Class: cXMLWriter
 *
 * Author: $author$
 *   Date: 11/23/2004
 **********************************************************************
 */
class cXMLWriter
: /*virtual public cXMLParserEventImplementT<cBase>,
  */public cXMLParserEventProxy
{
public:
    typedef cXMLParserEventProxy cIs;

    typedef int (cXMLWriter::*mPut)(int c);

    cXMLTagWriter m_tag_writer;
    mPut m_old_put, m_put;
    cCharBuffer m_buffer;
    const char *m_text;
    int m_length;

    /**
     **********************************************************************
     * Constructor: cXMLWriter
     *
     *      Author: $author$
     *        Date: 11/23/2004
     **********************************************************************
     */
    cXMLWriter
    (cXMLParserEventInterface &proxy) 
    : cIs(proxy),
      m_tag_writer(*this),
      m_old_put(TextPut),
      m_put(TextPut)
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;

        m_old_put = TextPut;
        m_put = TextPut;

        if (0 > (m_length = m_buffer.Clear()))
            error = -m_length;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = OnDocument();
        return error;
    }

    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int Put(int c) 
    {
        int count = 1;

        count = (this->*m_put)(c);
        return count;
    }
    /**
     **********************************************************************
     * Function: TextPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int TextPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '<':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnText(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_put = LessPut;
            break;

        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: LessPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int LessPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '>':
            m_put = TextPut;
            break;

        case '?':
            m_put = QuestionPut;
            break;

        case '!':
            m_put = ExclaimPut;
            break;

        case '/':
            m_put = SlashTagPut;
            break;

        default:
            count = m_buffer.Put(c);
            m_put = TagPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: QuestionPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int QuestionPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '?':
            m_put = ProcessorQuestionPut;
            break;

        default:
            count = m_buffer.Put(c);
            m_put = QuestionProcessorPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: QuestionProcessorPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int QuestionProcessorPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '?':
            m_put = ProcessorQuestionPut;
            break;

        case '"':
            count = m_buffer.Put(c);
            m_old_put = m_put;
            m_put = QuotesPut;
            break;

        case '\'':
            count = m_buffer.Put(c);
            m_old_put = m_put;
            m_put = QuotePut;
            break;

        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: ProcessorQuestionPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int ProcessorQuestionPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '>':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnProcessor(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_put = TextPut;
            break;

        case '"':
            if (0 > (m_length = m_buffer.Put('?')))
                count = m_length;
            else count = m_buffer.Put(c);
            m_old_put = QuestionProcessorPut;
            m_put = QuotesPut;
            break;

        case '\'':
            if (0 > (m_length = m_buffer.Put('?')))
                count = m_length;
            else count = m_buffer.Put(c);
            m_old_put = QuestionProcessorPut;
            m_put = QuotePut;
            break;

        default:
            if (0 > (m_length = m_buffer.Put('?')))
                count = m_length;
            else count = m_buffer.Put(c);
            m_put = QuestionProcessorPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: ExclaimPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int ExclaimPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '-':
            m_put = ExclaimDashPut;
            break;

        default:
            count = m_buffer.Put(c);
            m_put = ExclaimProcessorPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: ExclaimProcessorPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int ExclaimProcessorPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '>':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnEntity(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_put = TextPut;
            break;

        case '[':
            count = m_buffer.Put(c);
            m_old_put = m_put;
            m_put = BracketPut;
            break;

        case '"':
            count = m_buffer.Put(c);
            m_old_put = m_put;
            m_put = QuotesPut;
            break;

        case '\'':
            count = m_buffer.Put(c);
            m_old_put = m_put;
            m_put = QuotePut;
            break;

        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: ExclaimDashPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int ExclaimDashPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '-':
            m_put = CommentPut;
            break;

        default:
            count = m_buffer.Put(c);
            m_put = TagPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: CommentPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int CommentPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '-':
            m_put = CommentDashPut;
            break;

        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: CommentDashPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int CommentDashPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '-':
            m_put = CommentDashDashPut;
            break;

        default:
            if (0 > (m_length = m_buffer.Put('-')))
                count = m_length;
            else count = m_buffer.Put(c);
            m_put = CommentPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: CommentDashDashPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int CommentDashDashPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '>':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnComment(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_put = TextPut;
            break;

        case '-':
            count = m_buffer.Put('-');
            break;

        default:
            if (0 > (m_length = m_buffer.Put('-')))
                count = m_length;
            else if (0 > (m_length = m_buffer.Put('-')))
                    count = m_length;
            else count = m_buffer.Put(c);
            m_put = CommentPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: TagPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int TagPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '>':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnBeginTag(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_put = TextPut;
            break;

        case '/':
            m_put = TagSlashPut;
            break;

        case '"':
            count = m_buffer.Put(c);
            m_old_put = m_put;
            m_put = QuotesPut;
            break;

        case '\'':
            count = m_buffer.Put(c);
            m_old_put = m_put;
            m_put = QuotePut;
            break;

        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: TagSlashPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int TagSlashPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '>':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnTag(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_put = TextPut;
            break;

        case '"':
            if (0 > (m_length = m_buffer.Put('/')))
                count = m_length;
            else count = m_buffer.Put(c);
            m_old_put = TagPut;
            m_put = QuotesPut;
            break;

        case '\'':
            if (0 > (m_length = m_buffer.Put('/')))
                count = m_length;
            else count = m_buffer.Put(c);
            m_old_put = TagPut;
            m_put = QuotePut;
            break;

        default:
            if (0 > (m_length = m_buffer.Put('/')))
                count = m_length;
            else count = m_buffer.Put(c);
            m_put = TagPut;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: SlashTagPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int SlashTagPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '>':
            if ((m_text = m_buffer.GetBuffer(m_length)))
            if (0 < m_length)
            if (0  > (m_length = OnEndTag(m_text, m_length)))
                count = m_length;

            m_buffer.Clear();
            m_put = TextPut;
            break;

        case '"':
            count = m_buffer.Put(c);
            m_old_put = m_put;
            m_put = QuotesPut;
            break;

        case '\'':
            count = m_buffer.Put(c);
            m_old_put = m_put;
            m_put = QuotePut;
            break;

        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: BracketPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int BracketPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case ']':
            m_put = m_old_put;
        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: QuotePut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int QuotePut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '\'':
            m_put = m_old_put;
        default:
            count = m_buffer.Put(c);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: QuotesPut
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int QuotesPut(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '"':
            m_put = m_old_put;
        default:
            count = m_buffer.Put(c);
        }
        return count;
    }

    /**
     **********************************************************************
     * Function: OnParseTag
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnParseTag
    (const char *text, int length=-1) 
    {
        int i;

        if (0 > length)
            length = strlen(text);

        m_tag_writer.Initialize();

        for (i=0; i<length; i++)
            m_tag_writer.Put(text[i]);

        m_tag_writer.Finalize();
        return length;
    }
    /**
     **********************************************************************
     * Function: OnParseEndTag
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnParseEndTag
    (const char *text, int length=-1) 
    {
        int i;

        if (0 > length)
            length = strlen(text);

        m_tag_writer.EndInitialize();

        for (i=0; i<length; i++)
            m_tag_writer.Put(text[i]);

        m_tag_writer.Finalize();
        return length;
    }
    /**
     **********************************************************************
     * Function: OnTag
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnTag
    (const char *text, int length=-1) 
    {
        eError error;

        if (0 < (length = OnParseTag(text, length)))
        if ((error = OnElement()))
            length = -error;

        return length;
    }
    /**
     **********************************************************************
     * Function: OnBeginTag
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnBeginTag
    (const char *text, int length=-1) 
    {
        eError error;

        if (0 < (length = OnParseTag(text, length)))
        if ((error = OnBeginElement()))
            length = -error;

        return length;
    }
    /**
     **********************************************************************
     * Function: OnEndTag
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnEndTag
    (const char *text, int length=-1) 
    {
        eError error;

        if (0 < (length = OnParseEndTag(text, length)))
        if ((error = OnEndElement()))
            length = -error;

        return length;
    }
};

#endif /* ndef _CXMLWRITER_HXX */
