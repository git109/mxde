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
 *   File: cpipehttpservlet.hxx
 *
 * Author: $author$
 *   Date: 11/3/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CPIPEHTTPSERVLET_HXX
#define _CPIPEHTTPSERVLET_HXX

#include "chttpservlet.hxx"
#include "chttpservletinterface.hxx"
#include "cpipeprocess.hxx"

/**
 **********************************************************************
 *  Class: cPipeHttpServlet
 *
 * Author: $author$
 *   Date: 11/3/2004
 **********************************************************************
 */
class cPipeHttpServlet
: public cHttpServlet
{
public:
    typedef cHttpServlet cIs;

    cCharString m_command;
    cPipeProcess m_process;
    cCharBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cPipeHttpServlet
     *
     *      Author: $author$
     *        Date: 11/3/2004
     **********************************************************************
     */
    cPipeHttpServlet
    (const char *name, const char *command,
     cVerboseInterface *verbose=0) 
    : cIs(name, -1, verbose) 
    {
        eError error;
        int length;

        if (command)
        if (0 > (length = m_command.SetChars(command)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual eError Service
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error2, error = e_ERROR_NONE;
        cInputStreamInterface &input = request.GetInputStream();
        cCharReaderInterface &reader = request.GetReader();
        cOutputStreamInterface &output = response.GetOutputStream();
        cCharWriterInterface &writer = response.GetWriter();
        const BYTE *bytes;
        const char *chars;
        const char *name;
        const char *command;
        int command_length;
        int n,count,length;
        BYTE b;

        response.SetStatusOK();
        response.SetContentType("text/plain");

        name = GetServletName(length);
        command = m_command.GetChars(command_length);

        if (command && (command_length > 0))
        {
            if (m_verbose)
                m_verbose->VerboseFormatted
                ("%s: Creating process \"%s\"...\n", name, command);

            error2 = m_process.Create(command);

            if (error2 && (e_ERROR_ALREADY_STARTED != error2))
            {
                writer.Write("error executing command \"");
                writer.Write(command, command_length);
                writer.Write("\"\n");
            }
            else
            {
                if (m_verbose)
                if (e_ERROR_ALREADY_STARTED != error2)
                    m_verbose->VerboseFormatted
                    ("%s: ...Created process \"%s\"\n", name, command);
                else m_verbose->VerboseFormatted
                    ("%s: ...Process \"%s\" already created\n", name, command);

                bytes = request.GetHeaderBytes(length);

                if (bytes && (length > 0))
                {
                    if (m_verbose)
                        m_verbose->VerboseFormatted
                        ("%s: Forwarding HTTP header to process \"%s\"...\n", 
                         name, command);

                    if (0 > (length = m_process.Write(bytes, length)))
                    {
                        writer.Write("error forwarding HTTP header to process \"");
                        writer.Write(command, command_length);
                        writer.Write("\"\n");
                        return error;
                    }

                    if (m_verbose)
                        m_verbose->VerboseFormatted
                        ("%s: ...Forwarded HTTP header to process \"%s\"\n", 
                         name, command);
                }

                if (m_verbose)
                    m_verbose->VerboseFormatted
                    ("%s: Forwarding HTTP content to process \"%s\"...\n", 
                     name, command);

                for (n=0; 0 < (count = reader.Read
                     ((char*)&b, sizeof(b))); n+=count)
                {
                    if (0 < (count = m_process.Write(&b, sizeof(b))))
                        continue;

                    writer.Write("error forwarding HTTP content to process \"");
                    writer.Write(command, command_length);
                    writer.Write("\"\n");
                    return error;
                    break;
                }

                if (m_verbose)
                    m_verbose->VerboseFormatted
                    ("%s: ...Forwarded HTTP content[%d] to process \"%s\"\n", 
                     name, n, command);

                response.SetIsCommitted(true);

                if (m_verbose)
                {
                    m_verbose->VerboseFormatted
                    ("%s: Reading response from process \"%s\"...\n", 
                     name, command);
                    m_buffer.Clear();
                }

                for (n=0; 0 < (count = m_process.Read
                     (&b, sizeof(b))); n+=count)
                {
                    if (m_verbose)
                        m_buffer.Write((char*)&b, sizeof(b));

                    output.Write(&b, sizeof(b));
                }

                if (m_verbose)
                {
                    if (!(chars = m_buffer.GetBuffer(length)))
                        chars = "";

                    m_verbose->VerboseFormatted
                    ("%s: ...Read response[%d] from process \"%s\"\n{\n%s\n}\n", 
                     name, n, command, chars);
                }
                m_process.Finish();
            }
        }
        else writer.Write("null command\n");
        return error;
    }
};

#endif /* ndef _CPIPEHTTPSERVLET_HXX */
