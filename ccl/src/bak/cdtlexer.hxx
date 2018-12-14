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
 *   File: cdtlexer.hxx
 *
 * Author: $author$
 *   Date: 8/25/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDTLEXER_HXX
#define _CDTLEXER_HXX

#define yyIsLexer cDTLIsLexer
#define yyLexer cDTLexer
#include "yylexer.hxx"

#include "clistt.hxx"
#include "ccharbuffer.hxx"
#include "ccharfile.hxx"

/**
 **********************************************************************
 *  Class: cDTLexer
 *
 * Author: $author$
 *   Date: 8/25/2003
 **********************************************************************
 */
class cDTLexer
: public yyIsLexer
{
public:
    typedef yyIsLexer cIs;

    /**
     **********************************************************************
     *  Class: cToken
     *
     * Author: $author$
     *   Date: 8/25/2003
     **********************************************************************
     */
    class cToken
    : public cDynamicListItemT<cToken>
    {
    public:
        typedef cDynamicListItemT<cToken> cIs;

        cCharBuffer m_buffer;

        /**
         **********************************************************************
         * Constructor: cToken
         *
         *      Author: $author$
         *        Date: 8/25/2003
         **********************************************************************
         */
        cToken(const char *token=0,int len=-1) 
        {
            if (token)
                Set(token,len);
        }
        /**
         **********************************************************************
         * Function: Set
         *
         *   Author: $author$
         *     Date: 8/25/2003
         **********************************************************************
         */
        int Set(const char *token,int len=-1)
        {
            return m_buffer.Copy(token,len);
        }
        /**
         **********************************************************************
         * Function: SetEscaped
         *
         *   Author: $author$
         *     Date: 8/25/2003
         **********************************************************************
         */
        int SetEscaped(const char *token,int len=-1)
        {
            return m_buffer.CopyEscaped(token,len);
        }
        /**
         **********************************************************************
         * Function: Add
         *
         *   Author: $author$
         *     Date: 8/25/2003
         **********************************************************************
         */
        int Add(const char *token,int len=-1)
        {
            return m_buffer.Write(token,len);
        }
        /**
         **********************************************************************
         * Function: AddEscaped
         *
         *   Author: $author$
         *     Date: 8/25/2003
         **********************************************************************
         */
        int AddEscaped(const char *token,int len=-1)
        {
            return m_buffer.WriteEscaped(token,len);
        }
        /**
         **********************************************************************
         * Function: GetBuffer
         *
         *   Author: $author$
         *     Date: 8/25/2003
         **********************************************************************
         */
        inline const char *Get()
        {
            return m_buffer.GetBuffer();
        }
        /**
         **********************************************************************
         * Function: GetStream
         *
         *   Author: $author$
         *     Date: 8/25/2003
         **********************************************************************
         */
        inline cCharStream &GetStream()
        {
            return m_buffer;
        }
    };

    /**
     **********************************************************************
     *  Class: cEscapedToken
     *
     * Author: $author$
     *   Date: 8/25/2003
     **********************************************************************
     */
    class cEscapedToken
    : public cToken
    {
    public:
        typedef cToken cIs;

        /**
         **********************************************************************
         * Constructor: cEscapedToken
         *
         *      Author: $author$
         *        Date: 8/25/2003
         **********************************************************************
         */
        cEscapedToken(const char *token,int len=-1) 
        {
            if (token)
                SetEscaped(token,len);
        }
    };

    /**
     **********************************************************************
     *  Class: cTokens
     *
     * Author: $author$
     *   Date: 8/25/2003
     **********************************************************************
     */
    class cTokens
    : public cDynamicListT<cToken,cTokens>
    {
    public:
        typedef cDynamicListT<cToken,cTokens> cIs;
    };

    /**
     **********************************************************************
     *  Class: cSource
     *
     * Author: $author$
     *   Date: 3/3/2004
     **********************************************************************
     */
    class cSource
    {
    public:
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
            error=e_ERROR_NOT_IMPLEMENTED;
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
            eError error=e_ERROR_NOT_IMPLEMENTED;
            return error;
        }
    };

    /**
     **********************************************************************
     *  Class: cInclude
     *
     * Author: $author$
     *   Date: 8/25/2003
     **********************************************************************
     */
    class cInclude
    : public cDynamicListItemT<cInclude>
    {
    public:
        typedef cDynamicListItemT<cInclude> cIs;

        cSource &m_source;
        cCharStream &m_stream;
        void *m_state;

        /**
         **********************************************************************
         * Constructor: cInclude
         *
         *      Author: $author$
         *        Date: 8/25/2003
         **********************************************************************
         */
        cInclude(cSource &source, cCharStream &stream)
        : m_source(source),
          m_stream(stream)
        {
        }
        /**
         **********************************************************************
         * Destructor: ~cInclude
         *
         *     Author: $author$
         *       Date: 3/3/2004
         **********************************************************************
         */
        virtual ~cInclude()
        {
            eError error;

            if ((error = m_source.Close(m_stream)))
                throw(error);
        }
    };

    /**
     **********************************************************************
     *  Class: cIncludes
     *
     * Author: $author$
     *   Date: 8/25/2003
     **********************************************************************
     */
    class cIncludes
    : public cDynamicListT<cInclude,cIncludes>
    {
    public:
        typedef cDynamicListT<cInclude,cIncludes> cIs;
    };

    cSource &m_source;
    cTokens m_tokens,m_free_tokens;
    cIncludes m_includes;

    /**
     **********************************************************************
     * Constructor: cDTLexer
     *
     *      Author: $author$
     *        Date: 8/25/2003
     **********************************************************************
     */
    cDTLexer(cCharStream &out, cCharStream &in, cSource &source)
    : cIs(out, in),
      m_source(source)
    {
    }
    /**
     **********************************************************************
     * Function: yylex
     *
     *   Author: $author$
     *     Date: 8/25/2003
     *
     * This function is generated by flex.
     **********************************************************************
     */
	virtual int yylex();
    /**
     **********************************************************************
     * Function: yywrap
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    virtual int yywrap()
    {
        cInclude *include;

        if ((include=m_includes.Pop()))
        {
            yy_restore_scan_state(include->m_state);
            delete include;
            return 0;
        }
        return 1;
    }

    /**
     **********************************************************************
     * Function: OnInclude
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    virtual eError OnInclude()
    {
        int count;
        eError error;
        cToken *token;
        cInclude *include;
        cCharStream *stream;
        cCharBuffer buffer;

        if ((token=PopToken()))
        {            
            if ((stream = m_source.OpenFile(error, token->Get())))
            {
                if (!(include=new cInclude(m_source, *stream)))
                {
                    m_source.Close(*stream);
                    return e_ERROR_NEW;
                }

                include->m_state=yy_save_scan_state(&include->m_stream);
                m_includes.Push(include);
            }
            else 
            {
                if (0< (count = buffer.CopyL
                    ("Unable to open include file \"",token->Get(),"\"",0)))
                    SetLastError
                    (e_ERROR_OPEN,buffer.GetBuffer());

                error=e_ERROR_OPEN;
            }
            return error;
        }
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnIncludeURI
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    virtual eError OnIncludeURI()
    {
        int count;
        eError error;
        cToken *token;
        cInclude *include;
        cCharStream *stream;
        cCharBuffer buffer;

        if ((token=PopToken()))
        {            
            if ((stream = m_source.OpenURI(error, token->Get())))
            {
                if (!(include=new cInclude(m_source, *stream)))
                {
                    m_source.Close(*stream);
                    return e_ERROR_NEW;
                }

                include->m_state=yy_save_scan_state(&include->m_stream);
                m_includes.Push(include);
            }
            else 
            {
                if (0< (count = buffer.CopyL
                    ("Unable to open include URI \"",token->Get(),"\"",0)))
                    SetLastError
                    (e_ERROR_OPEN,buffer.GetBuffer());

                error=e_ERROR_OPEN;
            }
            return error;
        }
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OnToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    eError OnToken(const char *token,int ends=0)
    {
        cToken *ctoken;

        if ((ctoken=NewToken
            (token+ends,strlen(token+ends)-ends)))
        {
            m_tokens.Add(ctoken);
            return e_ERROR_NONE;
        }
        return e_ERROR_NEW;
    }
    /**
     **********************************************************************
     * Function: OnStringToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    eError OnStringToken(const char *token,int ends=1)
    {
        cToken *ctoken;

        if ((ctoken=NewEscapedToken
            (token+ends,strlen(token+ends)-ends)))
        {
            m_tokens.Add(ctoken);
            return e_ERROR_NONE;
        }
        return e_ERROR_NEW;
    }
    /**
     **********************************************************************
     * Function: NewToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    cToken *NewToken(const char *token,int len=-1)
    {
        cToken *ctoken;

        if (!(ctoken=m_free_tokens.Pop()))
            return new cToken(token,len);

        ctoken->Set(token,len);
        return ctoken;
    }
    /**
     **********************************************************************
     * Function: NewEscapedToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    cToken *NewEscapedToken(const char *token,int len=-1)
    {
        cToken *ctoken;

        if (!(ctoken=m_free_tokens.Pop()))
            return new cEscapedToken(token,len);

        ctoken->SetEscaped(token,len);
        return ctoken;
    }
    /**
     **********************************************************************
     * Function: TopToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    cToken *TopToken()
    {
        return m_tokens.GetFirst();
    }
    /**
     **********************************************************************
     * Function: BottomToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    cToken *BottomToken()
    {
        return m_tokens.GetLast();
    }
    /**
     **********************************************************************
     * Function: PopToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    cToken *PopToken()
    {
        cToken *token;

        if ((token=m_tokens.Pop()))
            m_free_tokens.Push(token);

        return token;
    }
    /**
     **********************************************************************
     * Function: PullToken
     *
     *   Author: $author$
     *     Date: 8/25/2003
     **********************************************************************
     */
    cToken *PullToken()
    {
        cToken *token;

        if ((token=m_tokens.Pull()))
            m_free_tokens.Push(token);

        return token;
    }
};


#endif
