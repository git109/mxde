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
 *   File: ccgicatch.cxx
 *
 * Author: $author$
 *   Date: 12/5/2003
 *
 *    $Id$
 **********************************************************************
 */

#include <stdlib.h>

#include "ccgi.hxx"
#include "ccharfile.hxx"
#include "ccharbuffer.hxx"
#include "cmaint.hxx"
#include "htmlmacro.h"

#if defined(WIN32)
#define CR "\r"
#else /* defined(WIN32) */
#define CR ""
#endif /* defined(WIN32) */

/**
 **********************************************************************
 *  Class: cCGICatch
 *
 * Author: $author$
 *   Date: 12/5/2003
 **********************************************************************
 */
class cCGICatch
: public cMainT<cCGICatch, cCGI>
{
public:
    typedef cMainT<cCGICatch, cCGI> cIs;

    const char *m_argc_name;
    const char *m_argv_name;
    const char *m_stdin_name;
    const char *m_content_name;
    const char *m_cgicatch_name;
    const char *m_argv_filename;
    const char *m_env_filename;
    const char *m_stdin_filename;
    const char *m_content_filename;

    const char *m_request_method;
    const char *m_content_length;
    const char *m_env[e_NUMBEROF_ENV];

    char m_buffer[1024];

    /**
     **********************************************************************
     * Constructor: cCGICatch
     *
     *      Author: $author$
     *        Date: 12/5/2003
     **********************************************************************
     */
    cCGICatch() 
    : cIs(this),
      m_argc_name("argc"),
      m_argv_name("argv"),
      m_stdin_name("stdin"),
      m_content_name("content"),
      m_cgicatch_name("cgicatch"),
      m_argv_filename("cgiargv.txt"),
      m_env_filename("cgienv.txt"),
      m_stdin_filename("cgistdin.txt"),
      m_content_filename("cgicatch.html"),
      m_request_method(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cCGICatch
     *
     *     Author: $author$
     *       Date: 12/5/2003
     **********************************************************************
     */
    virtual ~cCGICatch()
    {
    }

    /**
     **********************************************************************
     * Function: OnMain
     *
     *   Author: $author$
     *     Date: 12/5/2003
     **********************************************************************
     */
    virtual int OnMain(int argc, char **argv)
    {
        cCharFile out(stdout);
        cCharFile err(stderr);
        cCharFile content_file;
        cCharBuffer cgicatch_buffer;
        cCharStreamForkStream content(out, content_file);
        cCharStream *old_out=GetOut();
        cCharStream *old_err=GetErr();
        const char* cgicatch_pattern;
        FILE *file;
        eError error;
        int size,length,count;
        char decimal[32];

        SetOut(&out);
        SetErr(&err);

        OutputContentType(GetContentTypeHTML());

        if (0 < (count = cgicatch_buffer.WriteL
            (H1, m_cgicatch_name, 0)))
        if ((cgicatch_pattern = cgicatch_buffer.GetBuffer()))
        if (NULL != (file = SafeOpenFile
            (m_content_filename, cgicatch_pattern)))
        if ((error = content_file.Attach(file)))
            fclose(file);
        else SetOut(&content);

        OutputL(H1, m_cgicatch_name, H1_, 0);

        OutputL
        (BOLD,"Environment (file is ",BOLD_,"\"",
         m_env_filename,"\"", BOLD,")",BOLD_,UL,BR,0);

        /* Get the CGI environment variables.
         */
        for (count=0; count<e_NUMBEROF_ENV; count++)
        {
            m_env[count]=getenv(m_env_name[count]);

            OutputL
            (BOLD,m_env_name[count], BOLD_," = \"",
             m_env[count]?m_env[count]:"","\"",BR,0);
        }

        OutputL(UL_,BR,0);

        /* Write the CGI environment variables to a file.
         */
        if (NULL != (file = SafeOpenFile
            (m_env_filename, m_env_name[e_FIRST_ENV])))
        {
            for (count=0; count<e_NUMBEROF_ENV; count++)
                fprintf
                (file,"%s=%s\n",m_env_name[count],
                 m_env[count]?m_env[count]:"");

            fclose(file);
        }

        sprintf(decimal, "%d", argc);

        OutputL
        (BOLD,"Arguments (file is ",BOLD_,"\"",
         m_argv_filename,"\"", BOLD,")",BOLD_,UL,BR,0);

        OutputL
        (BOLD,m_argc_name," = ",BOLD_,decimal,BR,0);

        /* Get the standard argments passed to main.
         */
        for (count=0; count<argc; count++)
        {
            sprintf(decimal, "%d", count);

            OutputL
            (BOLD,m_argv_name,"[",decimal,"]",BOLD_,
             " = \"",argv[count],"\"",BR,0);
        }

        OutputL(UL_,BR,0);

        /* Write the standard argments to a file.
         */
        if (NULL != (file = SafeOpenFile
            (m_argv_filename, m_argc_name)))
        {
            fprintf(file, "%s=%d\n", m_argc_name, argc);

            for (count=0; count<argc; count++)
                fprintf
                (file,"%s[%d]=%s\n", 
                 m_argv_name, count, argv[count]);

            fclose(file);
        }

        /* If the request method is "POST" then write
         * the contents of stdin to a file.
         */
        if ((m_content_length = m_env[e_ENV_CONTENT_LENGTH]))
        if (0 <= (length = atoi(m_content_length)))
        if ((m_request_method = m_env[e_ENV_REQUEST_METHOD]))
        if (0 == strcmp
            (m_request_method, 
             m_request_method_name[e_REQUEST_METHOD_POST]))
        {
            OutputL
            (BOLD,"Input (file is ",BOLD_,"\"",
             m_stdin_filename,"\"", BOLD,")",BOLD_,UL,BR,0);

            OutputL
            (BOLD,m_env_name[e_ENV_CONTENT_LENGTH],
             " = ",BOLD_,m_content_length,BR,0);

            OutputL(UL_,BR,0);

            /* Write stdin to a file.
             */
            if (NULL != (file = SafeOpenFile
                (m_stdin_filename, m_env_name[e_ENV_CONTENT_LENGTH])))
#if defined(WIN32)
            /* Set the file mode to binary for WIN32.
             */
            if (0 <= _setmode(_fileno(stdin),_O_BINARY))
            if (0 <= _setmode(_fileno(file),_O_BINARY))
#endif /* defined(WIN32) */
            {

                fprintf
                (file, "%s=%s\n", 
                 m_env_name[e_ENV_CONTENT_LENGTH], 
                 m_content_length);

                do
                {
                    if (length < (size = sizeof(m_buffer)))
                        size = length;

                    if (1 > (size = fread
                        (m_buffer, 1, size, stdin)))
                        break;
            
                    if (size > (count = fwrite
                        (m_buffer, 1, size, file)))
                        break;
                }
                while (0 < (length -= size));

                fclose(file);
            }
        }

        OutputL
        (BOLD,"Content (file is ",BOLD_,"\"",
         m_content_filename,"\"", BOLD,")",BOLD_,UL,BR,0);

        OutputL(UL_,BR,0);

        SetErr(old_err);
        SetOut(old_out);
        return 0;
    }
    /**
     **********************************************************************
     * Function: SafeOpenFile
     *
     *   Author: $author$
     *     Date: 12/5/2003
     **********************************************************************
     */
    FILE *SafeOpenFile
    (const char *filename, const char *pattern)
    {
        bool cant_open=false;
        int count,length;
        FILE *file;
        char buffer[1024];

        if (NULL != (file = fopen(filename, "r")))
        {
            cant_open = true;

            if (0 < (count = fread
                (buffer, 1, sizeof(buffer)-1, file)))
            if (count >= (length = strlen(pattern)))
            if (0 == strncmp(buffer, pattern, length))
                cant_open = false;

            fclose(file);

            if (cant_open)
                return NULL;
        }

        file = fopen(filename, "w");
        return file;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 12/5/2003
     **********************************************************************
     */
} g_cgi_catch;

cCGICatch *cCGICatch::cInstanceIs::m_instance = 0;

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 12/5/2003
 **********************************************************************
 */
int main(int argc, char **argv)
{
    cCGICatch *instance;

    if ((instance = cCGICatch::GetInstance()))
        return instance->OnMain(argc, argv);

    return 1;
}
