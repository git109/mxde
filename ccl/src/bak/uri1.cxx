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
 *   File: uri.cxx
 *
 * Author: $author$
 *   Date: 3/15/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "curischeme.hxx"
#include "curi.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Main: cURIMain
 *
 * Author: $author$
 *   Date: 3/15/2004
 **********************************************************************
 */
class cURIMain
: public cMain
{
public:
    typedef cMain cIs;

    const char *m_uri_value;
    cURI m_uri;

    /**
     **********************************************************************
     * Constructor: cURIMain
     *
     *      Author: $author$
     *        Date: 3/15/2004
     **********************************************************************
     */
    cURIMain(const char *uri_value="http:user@localhost:80/?parameter=value#here")
    : m_uri(cStaticURISchemeSet::m_instance),
      m_uri_value(uri_value)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 3/15/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        //cURI uri(cStaticURISchemeSet::m_instance, "http:user@localhost:80/?parameter=value#here");
        cURISchemeInterface *scheme;
        int length;

        if (0 < (length = m_uri.SetURI(m_uri_value)))
        if ((scheme = m_uri.GetURISchemeInterface()))
        {
            int scheme_name_length;
            const char *scheme_name=scheme->GetSchemeName(scheme_name_length);
            cURLInterface *url;

            //if ((url = scheme->OpenURL(uri)))
            if ((url = m_uri.OpenURL()))
            {
                cCharStream *content;
                int content_length;

                if ((content = url->GetContent(content_length)))
                if (content_length > 0)
                {
                    cCharBuffer cbuffer;
                    char *buffer;
                    int size,length;

                    if ((buffer = cbuffer.GetWriteBuffer(size, length)))
                    for (--size; content_length > 0; content_length -= length)
                    {
                        if (size > content_length)
                            size = content_length;

                        if (0 > (length = content->Read(buffer, size)))
                            break;

                        cbuffer.SetLength(length);

                        printf("%s", buffer);
                    }
                }
                //scheme->CloseURL(*url);
                m_uri.CloseURL(*url);
            }
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 3/9/2004
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, char *arg, int argc, char **argv)
    {
        if (argn < argc)
        {
            if (!strcmp(arg,"u"))
            {
                if ((arg = argv[++argn]))
                    m_uri_value = arg;
            }
        }
        return argn;
    }
} g_uri_main;
