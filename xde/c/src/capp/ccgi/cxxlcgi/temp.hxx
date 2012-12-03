/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: ccxxcgi.hxx
 *
 * Author: $author$
 *   Date: 5/1/2008
 **********************************************************************
 */
#ifndef _CCXXCGI_HXX
#define _CCXXCGI_HXX

#include "cdocumenttemplatecgi.hxx"
#include "ccxxlexer.hxx"

#define DEFAULT_DOCUMENT_FILENAME_EXTENSION "cxx"
#define DEFAULT_TEMPLATE_FILENAME_EXTENSION "cxxt"

#define DEFAULT_DOCUMENT_FILENAME_NAME "cxx_filename"
#define DEFAULT_TEMPLATE_FILENAME_NAME "cxxt_filename"

#define DEFAULT_DOCUMENT_URI_NAME "cxx_uri"
#define DEFAULT_TEMPLATE_URI_NAME "cxxt_uri"

#define DEFAULT_CGI_NAME "cxxcgi"

#define DEFAULT_DOCUMENT_FILENAME \
    DEFAULT_CGI_NAME \
    PLATFORM_EXTENSION_SEPARATOR \
    DEFAULT_DOCUMENT_FILENAME_EXTENSION

#define DEFAULT_TEMPLATE_FILENAME \
    DEFAULT_CGI_NAME \
    PLATFORM_EXTENSION_SEPARATOR \
    DEFAULT_TEMPLATE_FILENAME_EXTENSION

/**
 **********************************************************************
 *  Class: cCXXCGI
 *
 * Author: $author$
 *   Date: 5/1/2008
 **********************************************************************
 */
class cCXXCGI
: virtual public cCXXLexer::cDelegate,
  public cDocumentTemplateCGI
{
public:
    typedef cDocumentTemplateCGI cExtends;
    typedef cCXXCGI cDerives;

    cCharFile m_file;

    cCXXLexer::cSource m_source;
    cCXXLexer m_lexer;

    /**
     **********************************************************************
     * Constructor: cCXXCGI
     *
     *      Author: $author$
     *        Date: 5/1/2008
     **********************************************************************
     */
    cCXXCGI
    (const tChar* cgiNameChars=DEFAULT_CGI_NAME,
     const tChar* documentFileNameExtensionChars,
     const tChar* documentFileNameNameChars,
     const tChar* documentURINameChars,
     const tChar* templateFileNameExtensionChars,
     const tChar* templateFileNameNameChars,
     const tChar* templateURINameChars)
    : cExtends
      (documentFileNameExtensionChars,
       documentFileNameNameChars,
       documentURINameChars,
       templateFileNameExtensionChars,
       templateFileNameNameChars,
       templateURINameChars,
       cgiNameChars),
      m_lexer(*this, m_stdOut, m_file, m_source) 
    {
    }
    /**
     **********************************************************************
     * Function: RunCommandOrCGI
     *
     *   Author: $author$
     *     Date: 3/2/2008
     **********************************************************************
     */
    virtual int RunCommandOrCGI
    (int argc,
     const char** argv,
     const char** env) 
    {
        int err = 0;
        eError error;
        tLength length;
        const char* fileNameChars;

        if ((fileNameChars = GetFileName(length)))
        if (0 < (m_fileName.Assign(fileNameChars, length)))
        if ((fileNameChars = m_fileName.HasChars(length)))
            m_fileNameChars = fileNameChars;

        OutputContentType(GetContentTypeHTML());

        OutputContent("<html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"/doc/css/cxxcgi.css\"></head><body><pre>");

        if (!(error = m_file.Open(m_fileNameChars)))
        {
            m_lexer.yylex();
            m_file.Close();
        }
        OutputContent("</pre><body></html>");
        return err;
    }
    /**
     **********************************************************************
     * Function: OnBeginComment
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnBeginComment
    (const char* text, int token=-1) 
    {
        OutputContentL
        ("<font class=\"comment\">", text, NULL_POINTER);
    }
    /**
     **********************************************************************
     * Function: OnEndComment
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnEndComment
    (const char* text, int token=-1) 
    {
        OutputContentL
        (text, "</font>", NULL_POINTER);
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
        OutputContent(text);
    }
    /**
     **********************************************************************
     * Function: OnProcessor
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnProcessor
    (const char* text, int token=-1) 
    {
        OutputContentL
        ("<font class=\"processor\">", text, "</font>", NULL_POINTER);
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
        OutputContentL
        ("<font class=\"keyword\">", text, "</font>", NULL_POINTER);
    }
    /**
     **********************************************************************
     * Function: OnStringLiteral
     *
     *   Author: $author$
     *     Date: 5/2/2008
     **********************************************************************
     */
    virtual void OnStringLiteral
    (const char* text,
     int token=-1) 
    {
        OutputContentL
        ("<font class=\"string\">", text, "</font>", NULL_POINTER);
    }
    /**
     **********************************************************************
     * Function: OnCharLiteral
     *
     *   Author: $author$
     *     Date: 5/2/2008
     **********************************************************************
     */
    virtual void OnCharLiteral
    (const char* text,
     int token=-1) 
    {
        OutputContentL
        ("<font class=\"char\">", text, "</font>", NULL_POINTER);
    }
    /**
     **********************************************************************
     * Function: OnLT
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnLT
    (const char* text, int token=-1) 
    {
        OutputContent("&lt;");
    }
    /**
     **********************************************************************
     * Function: OnGT
     *
     *   Author: $author$
     *     Date: 1/8/2006
     **********************************************************************
     */
    virtual void OnGT
    (const char* text, int token=-1) 
    {
        OutputContent("&gt;");
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
    (const char* text, int token=-1) 
    {
        OutputContent(text);
    }
};

#endif /* _CCXXCGI_HXX */
