/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: dtprint.cxx
 *
 * Author: $author$
 *   Date: 1/7/2006
 *
 *    $Id$
 **********************************************************************
 */

#include "cdtparse.h"
#include "cdtlexer.hxx"
#include "cdocumenttransformcgi.hxx"
#include "ccgi.hxx"
#include "ccontentstream.hxx"
#include "ccharstreamhandle.hxx"

/**
 **********************************************************************
 *  Class: cDTPrintLexer
 *
 * Author: $author$
 *   Date: 1/8/2006
 **********************************************************************
 */
class cDTPrintLexer
: public cDTLexer
{
public:
    typedef cDTLexer cIs;

    bool m_is_include;
    cCharBuffer m_literal;

    /**
     **********************************************************************
     * Constructor: cDTPrintLexer
     *
     *      Author: $author$
     *        Date: 1/8/2006
     **********************************************************************
     */
    cDTPrintLexer
    (cCharStream &out, cCharStream &in, cSource &source)
    : cIs(out, in, source),
      m_is_include(false)
    {
    }
    /**
     **********************************************************************
     * Function: OnPushState
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnPushState
    (const char* text, int token) 
    {
        m_out.Write("<q class=\"comment\">");
        OnText(text);
        cIs::OnPushState(text, token);
    }
    /**
     **********************************************************************
     * Function: OnPopState
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnPopState
    (const char* text, int token) 
    {
        OnText(text);
        m_out.Write("</q>");
        cIs::OnPopState(text, token);
    }
    /**
     **********************************************************************
     * Function: OnComment
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnComment
    (const char* text, int token=-1) 
    {
        OnText(text);
        cIs::OnComment(text, token);
    }
    /**
     **********************************************************************
     * Function: OnText
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnText
    (const char* text) 
    {
        char c;

        for (c=*text; c; c=*++text)
        {
            switch (c)
            {
            case '<':
                m_out.Write("&lt;");
                break;

            case '>':
                m_out.Write("&gt;");
                break;

            default:
                m_out.Put(c);
            }
        }
    }
    /**
     **********************************************************************
     * Function: OnPunctuation
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnPunctuation
    (const char* text, int token=-1) 
    {
        switch(token)
        {
        case XX_PERCENT_LESS:
        case XX_GREATER_PERCENT:
        case XX_PERCENT_GREATER:
        case XX_LESS_PERCENT:
            m_out.Write("<q class=\"punctuation\">");
            OnText(text);
            m_out.Write("</q>");
            break;

        default:
            OnText(text);
        }
        cIs::OnPunctuation(text, token);
    }
    /**
     **********************************************************************
     * Function: OnReserved
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnReserved
    (const char* text, int token=-1) 
    {
        switch(token)
        {
        case XX_INCLUDE:
            m_is_include = true;
            break;
        }
        m_out.WriteL
        ("<q class=\"reserved\">", text, "</q>", 0);
        cIs::OnReserved(text, token);
    }
    /**
     **********************************************************************
     * Function: OnIdentifier
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual eError OnIdentifier
    (const char* text, int beginchars, int endchars, int token=-1) 
    {
        eError error;
        
        m_out.WriteL
        ("<q class=\"identifier\">", text, "</q>", 0);
        error = cIs::OnIdentifier(text, beginchars, endchars, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnLiteral
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual eError OnLiteral
    (const char* text, int beginchars, int endchars, int token=-1) 
    {
        eError error;
        
        switch(token)
        {
        case XX_FLOAT_LITERAL:
        default:
            m_out.WriteL("<q class=\"literal\">", text, "</q>", 0);
        }
        error = cIs::OnLiteral(text, beginchars, endchars, token);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnStringLiteral
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual eError OnStringLiteral
    (const char* text, int beginchars, int endchars, int token=-1) 
    {
        const char* inside = text+(beginchars+endchars);
        eError error;
        
        switch(token)
        {
        case XX_TEXT_LITERAL:
            if (m_is_include)
            {
                m_is_include = false;
                m_out.Write
                ("<a class=\"literal\""
                 "href=\"dtprint.exe?document_file=../xen/dt/");
                m_out.Write(inside, strlen(inside)-endchars);
                m_out.WriteL("\">",text,"</a>", 0);
            }
            else m_out.WriteL
            ("<q class=\"literal\">", text, "</q>", 0);
            break;

        default:
            m_out.WriteL("<q class=\"literal\">", text, "</q>", 0);
        }
        error = cIs::OnStringLiteral
        (text, beginchars, endchars, token);
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDTPrintCGI
 *
 * Author: $author$
 *   Date: 1/7/2006
 **********************************************************************
 */
class cDTPrintCGI
: public cDocumentTransformCGI
{
public:
    typedef cDocumentTransformCGI cIs;

    cContentStream m_content_stream;
    cCharStreamHandle m_input_stream;
    cCharStreamHandle m_output_stream;
    cCharFile m_input_file;
    cDTLexer::cSource m_dt_lexer_source;
    cDTPrintLexer m_dt_lexer;

    /**
     **********************************************************************
     * Constructor: cDTPrintCGI
     *
     *      Author: $author$
     *        Date: 1/7/2006
     **********************************************************************
     */
    cDTPrintCGI
    (const char *name="dtprint") 
    : cIs(name), 
      m_content_stream(*this),
      m_dt_lexer
      (m_content_stream, 
       m_input_stream, m_dt_lexer_source)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDTPrintCGI
     *
     *      Author: $author$
     *        Date: 1/7/2006
     **********************************************************************
     */
    virtual ~cDTPrintCGI()
    {
    }
    /**
     **********************************************************************
     * Function: OnCommandOrCGI
     *
     *   Author: $author$
     *     Date: 1/7/2006
     **********************************************************************
     */
    virtual int OnCommandOrCGI() 
    {
        int result;
        
        m_requires_document_filename = true;
        m_requires_template_filename = false;
        m_requires_input_filename = false;

        result = cIs::OnCommandOrCGI();
        return result;
    }
    /**
     **********************************************************************
     * Function: OnTransform
     *
     *   Author: $author$
     *     Date: 1/7/2006
     **********************************************************************
     */
    virtual int OnTransform() 
    {
        int result = 0;

        if (!(result = OnParseDocumentFile()))
        {
            SetContentType(m_output_content_type);

            OutputContentType();
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnParseDocumentFile
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int OnParseDocumentFile() 
    {
        int result=0;
        eError error;

        if ((error = OpenDocumentFile
            (m_input_file, m_document_filename)))
            result = 1;
        else
        {
            if (!(error = m_input_stream.Attach(&m_input_file)))
            {
                result = OnParseDocumentFile(m_document_filename);

                if ((error = m_input_stream.Detach()))
                    result = 1;
            }

            if ((error = CloseDocumentFile
                (m_input_file, m_document_filename)))
                result = 1;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnParseDocumentFile
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual int OnParseDocumentFile(const char* filename) 
    {
        const char* header =
"<html><head><link rel=\"stylesheet\" type=\"text/css\""
" href=\"../xen/dt/dt-print.css\">"
"</link></head><body><pre>";

        const char* footer = 
"</pre></body></html>";

        int result = 0;
        int err;
/*
        if (0 > (result = m_dt_lexer.SetFilename(filename)))
            return result = 1;
*/
        m_content_stream.Write(header);

        while (0 < (err = m_dt_lexer.yylex()))
        {
        }
        m_content_stream.Write(footer);
        return result;
    }
} g_cgi;
