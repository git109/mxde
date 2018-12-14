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
 *   File: curi.hxx
 *
 * Author: $author$
 *   Date: 3/15/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CURI_HXX
#define _CURI_HXX

#include "curischemeinterface.hxx"
#include "curiinterface.hxx"
#include "ccharbuffer.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cURI
 *
 * Author: $author$
 *   Date: 3/15/2004
 **********************************************************************
 */
class cURI
: virtual public cURIInterface,
  virtual public cURIImplement,
  public cErrorInstance
{
public:
    typedef cErrorInstance cIs;

    cURISchemeSetInterface &m_scheme_set;
    cURISchemeInterface *m_scheme_interface;

    cCharBuffer m_uri;
    cCharBuffer m_scheme;
    cCharBuffer m_scheme_specific;
    cCharBuffer m_authority;
    cCharBuffer m_user;
    cCharBuffer m_host;
    cCharBuffer m_port;
    cCharBuffer m_path;
    cCharBuffer m_query;
    cCharBuffer m_fragment;

    /**
     **********************************************************************
     * Constructor: cURI
     *
     *      Author: $author$
     *        Date: 3/15/2004
     **********************************************************************
     */
    cURI
    (cURISchemeSetInterface &scheme_set, 
     const char *uri=0, int length=-1)
    : m_scheme_set(scheme_set),
      m_scheme_interface(0)
    {
        eError error;

        if (uri)
        if (0 > (length = SetURI(uri)))
            throw(error = -length);
    }

    /**
     **********************************************************************
     * Function: SetURISchemeInterface
     *
     *   Author: $author$
     *     Date: 6/7/2004
     **********************************************************************
     */
    virtual eError SetURISchemeInterface(cURISchemeInterface *scheme)
    {
        m_scheme_interface = scheme;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetURISchemeInterface
     *
     *   Author: $author$
     *     Date: 6/7/2004
     **********************************************************************
     */
    virtual cURISchemeInterface &GetURISchemeInterface() const
    {
        if (m_scheme_interface)
            return *m_scheme_interface;

        return cURISchemeInterface::GetGenericScheme();
    }

    /**
     **********************************************************************
     * Function: SetURI
     *
     *   Author: $author$
     *     Date: 3/15/2004
     **********************************************************************
     */
    virtual int SetURI(const char *uri, int length=-1)
    {
        eError error;
        const char *scheme,*scheme_specific;
        int scheme_length,scheme_specific_length;
        int count;
        char c;

        if (0 > (count = m_scheme.Clear()))
            return count;

        if (0 > (count = m_scheme_specific.Clear()))
            return count;

        if (0 > (count = m_authority.Clear()))
            return count;

        if (0 > (count = m_user.Clear()))
            return count;

        if (0 > (count = m_host.Clear()))
            return count;

        if (0 > (count = m_port.Clear()))
            return count;

        if (0 > (count = m_path.Clear()))
            return count;

        if (0 > (count = m_query.Clear()))
            return count;

        if (0 > (count = m_fragment.Clear()))
            return count;

        if (0 > (length = m_uri.Copy(uri, length)))
            return length;

        for (int i=0; i<length; i++)
        {
            switch(c = uri[i])
            {
            case ':':
                if (0 > (scheme_length = m_scheme.Copy(uri, i)))
                    return scheme_length;

                if (!(scheme = m_scheme.GetBuffer(scheme_length)))
                    return -e_ERROR_FAILED;

                if (0 > (scheme_specific_length = m_scheme_specific.
                    Copy(uri+i+1, length-i-1)))
                    return scheme_specific_length;

                if (!(scheme_specific = m_scheme_specific.
                    GetBuffer(scheme_specific_length)))
                    return -e_ERROR_FAILED;

                if ((error = OnURIScheme
                    (scheme, scheme_length)))
                    return -error;

                if ((error = OnURISchemeSpecific
                    (scheme, scheme_length,
                     scheme_specific, scheme_specific_length)))
                    return -error;

                return length;
                break;
            }
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: GetURI
     *
     *   Author: $author$
     *     Date: 3/15/2004
     **********************************************************************
     */
    virtual const char *GetURI(int &length) const
    {
        return m_uri.GetBuffer(length);
    }
    /**
     **********************************************************************
     * Function: GetURIHost
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual const char *GetURIHost(int &length) const
    {
        return m_host.GetBuffer(length);
    }
    /**
     **********************************************************************
     * Function: GetURIPort
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual const char *GetURIPort(int &length) const
    {
        return m_port.GetBuffer(length);
    }
    /**
     **********************************************************************
     * Function: GetURIPath
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual const char *GetURIPath(int &length) const
    {
        return m_path.GetBuffer(length);
    }
    /**
     **********************************************************************
     * Function: GetURIQuery
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual const char *GetURIQuery(int &length) const
    {
        return m_query.GetBuffer(length);
    }

    /**
     **********************************************************************
     * Function: OnURIScheme
     *
     *   Author: $author$
     *     Date: 3/15/2004
     **********************************************************************
     */
    virtual eError OnURIScheme
    (const char *scheme, int scheme_length)
    {
        m_scheme_interface = m_scheme_set.GetFirstURISchemeByName
        (scheme, scheme_length);
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: OnURISchemeSpecific
     *
     *   Author: $author$
     *     Date: 6/5/2004
     **********************************************************************
     */
    virtual eError OnURISchemeSpecific
    (const char *scheme, int scheme_length,
     const char *scheme_specific, int scheme_specific_length)
    {
        eError error=e_ERROR_INVALID_PARAMETER;

        if (m_scheme_interface)
            error = m_scheme_interface->OnURISchemeSpecific
            (*this, scheme, scheme_length, 
             scheme_specific, scheme_specific_length);
/*
        else error = OnGenericURISchemeSpecific
            (scheme_specific, scheme_specific_length);
*/
        return error;
    }
    /**
     **********************************************************************
     * Function: OnGenericURISchemeSpecific
     *
     *   Author: $author$
     *     Date: 6/4/2004
     **********************************************************************
     */
    virtual eError OnGenericURISchemeSpecific
    (const char *scheme_specific, int scheme_specific_length)
    {
        eError error;
        const char *authority;
        int authority_length;
        int i,j;
        char c;

        for (i=0; i<scheme_specific_length; i++)
        {
            switch(c = scheme_specific[i])
            {
            case '/': 
                if (0 == i)
                {
                    for (j=++i; i<scheme_specific_length; i++)
                    {
                        switch(c = scheme_specific[i])
                        {
                        case '/':
                            if (j == i)
                            {
                                for (authority=scheme_specific+(j=++i); i<scheme_specific_length; i++)
                                {
                                    switch(c = scheme_specific[i])
                                    {
                                    case '/':
                                        if (j < i)
                                        {
                                            if (0 > (authority_length = m_authority.Copy(authority, i-j)))
                                                return -authority_length;

                                            if (!(authority = m_authority.GetBuffer(authority_length)))
                                                return e_ERROR_FAILED;

                                            if ((error = OnURIAuthority
                                                (authority, authority_length)))
                                                return error;

                                            error = OnURIPathQueryFragment
                                            (scheme_specific+i, scheme_specific_length-i);
                                            return error;
                                        }
                                        return e_ERROR_INVALID_PARAMETER;
                                    }
                                }
                            }
                            return e_ERROR_INVALID_PARAMETER;
                        }
                    }
                }
                else if (i > 0)
                {
                    if (0 > (authority_length = m_authority.Copy(scheme_specific, i)))
                        return -authority_length;

                    if (!(authority = m_authority.GetBuffer(authority_length)))
                        return e_ERROR_FAILED;

                    if ((error = OnURIAuthority
                        (authority, authority_length)))
                        return error;

                    error = OnURIPathQueryFragment
                    (scheme_specific+i, scheme_specific_length-i);
                    return error;
                }
                return e_ERROR_INVALID_PARAMETER;
            }
        }

        return e_ERROR_INVALID_PARAMETER;
    }
    /**
     **********************************************************************
     * Function: OnURIAuthority
     *
     *   Author: $author$
     *     Date: 3/15/2004
     **********************************************************************
     */
    virtual eError OnURIAuthority
    (const char *authority, int authority_length)
    {
        eError error;
        const char *host,*port,*user;
        int host_length,port_length,user_length,i,j;
        char c;

        for (i=0; i<authority_length; i++)
        {
            switch(c = authority[i])
            {
            case '@':
                if ((i > 0) && (i+1 < authority_length))
                {
                    if (0 > (user_length = m_user.Copy(authority, i)))
                        return -user_length;

                    if (!(user = m_user.GetBuffer(user_length)))
                        return e_ERROR_FAILED;

                    if ((error = OnURIUser(user, user_length)))
                        return error;

                    for (host = authority+(j=++i); i<authority_length; i++)
                    {
                        switch(c = authority[i])
                        {
                        case ':':
                            if ((i > j) && (i+1 < authority_length))
                            {
                                if (0 > (host_length = m_host.Copy(host, i-j)))
                                    return -host_length;

                                if (!(host = m_host.GetBuffer(host_length)))
                                    return e_ERROR_FAILED;

                                if ((error = OnURIHost(host, host_length)))
                                    return error;

                                port = authority+(j=++i);

                                if (0 > (port_length = m_port.Copy(port, authority_length-j)))
                                    return -port_length;

                                if (!(port = m_port.GetBuffer(port_length)))
                                    return e_ERROR_FAILED;

                                error = OnURIPort(port, port_length);
                                return error;
                            }
                            return e_ERROR_INVALID_PARAMETER;
                        }
                    }

                    if (0 > (host_length = m_host.Copy(host, authority_length-j)))
                        return -host_length;

                    if (!(host = m_host.GetBuffer(host_length)))
                        return e_ERROR_FAILED;

                    error = OnURIHost(host, host_length);
                    return error;
                }
                return e_ERROR_INVALID_PARAMETER;

            case ':':
                if ((i > 0))
                {
                    if (0 > (host_length = m_host.Copy(authority, i)))
                        return -host_length;

                    if (!(host = m_host.GetBuffer(host_length)))
                        return e_ERROR_FAILED;

                    if ((error = OnURIHost(host, host_length)))
                        return error;

                    if ((i+1 < authority_length))
                    {
                        port = authority+(j=++i);

                        if (0 > (port_length = m_port.Copy(port, authority_length-j)))
                            return -port_length;

                        if (!(port = m_port.GetBuffer(port_length)))
                            return e_ERROR_FAILED;

                        error = OnURIPort(port, port_length);
                    }
                    return error;
                }
                return e_ERROR_INVALID_PARAMETER;
            }
        }

        if (0 > (host_length = m_host.Copy
            (authority, authority_length)))
            return -host_length;

        if (!(host = m_host.GetBuffer(host_length)))
            return e_ERROR_FAILED;

        error = OnURIHost(host, host_length);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnURIPathQueryFragment
     *
     *   Author: $author$
     *     Date: 6/3/2004
     **********************************************************************
     */
    virtual eError OnURIPathQueryFragment
    (const char *path_query_fragment, int path_query_fragment_length)
    {
        eError error;
        const char *path,*query,*fragment;
        int path_length,query_length,fragment_length,i,j;
        char c;

        for (i=0; i<path_query_fragment_length; i++)
        {
            switch(c = path_query_fragment[i])
            {
            case '?':
                if ((i > 0) && (i+1 < path_query_fragment_length))
                {
                    if (0 > (path_length = m_path.Copy
                        (path_query_fragment, i)))
                        return -path_length;

                    if (!(path = m_path.GetBuffer(path_length)))
                        return e_ERROR_FAILED;

                    if ((error = OnURIPath(path, path_length)))
                        return error;

                    for (query = path_query_fragment+(j=++i); 
                         i<path_query_fragment_length; i++)
                    {
                        switch(c = path_query_fragment[i])
                        {
                        case '#':
                            if ((i > j) && (i+1 < path_query_fragment_length))
                            {
                                if (0 > (query_length = m_query.Copy(query, i-j)))
                                    return -query_length;

                                if (!(query = m_query.GetBuffer(query_length)))
                                    return e_ERROR_FAILED;

                                if ((error = OnURIQuery
                                    (query, query_length)))
                                    return error;

                                fragment = path_query_fragment+i+1;

                                if (0 > (fragment_length = m_fragment.Copy
                                    (fragment, path_query_fragment_length-i-1)))
                                    return -fragment_length;

                                if (!(fragment = m_fragment.GetBuffer(fragment_length)))
                                    return e_ERROR_FAILED;

                                error = OnURIFragment(fragment, fragment_length);
                                return error;
                            }
                            return e_ERROR_INVALID_PARAMETER;
                        }
                    }

                    if (0 > (query_length = m_query.Copy(query, path_query_fragment_length-j)))
                        return -query_length;

                    if (!(query = m_query.GetBuffer(query_length)))
                        return e_ERROR_FAILED;

                    error = OnURIQuery(query, query_length);
                    return error;
                }
                return e_ERROR_INVALID_PARAMETER;
            }
        }

        if (0 > (path_length = m_path.Copy
            (path_query_fragment, i)))
            return -path_length;

        if (!(path = m_path.GetBuffer(path_length)))
            return e_ERROR_FAILED;

        error = OnURIPath(path, path_length);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnURIUser
     *
     *   Author: $author$
     *     Date: 6/4/2004
     **********************************************************************
     */
    virtual eError OnURIUser
    (const char *user, int user_length)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: OnURIHost
     *
     *   Author: $author$
     *     Date: 6/4/2004
     **********************************************************************
     */
    virtual eError OnURIHost
    (const char *host, int host_length)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: OnURIPort
     *
     *   Author: $author$
     *     Date: 6/4/2004
     **********************************************************************
     */
    virtual eError OnURIPort
    (const char *port, int port_length)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: OnURIPath
     *
     *   Author: $author$
     *     Date: 6/4/2004
     **********************************************************************
     */
    virtual eError OnURIPath
    (const char *path, int path_length)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: OnURIQuery
     *
     *   Author: $author$
     *     Date: 6/4/2004
     **********************************************************************
     */
    virtual eError OnURIQuery
    (const char *query, int query_length)
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: OnURIFragment
     *
     *   Author: $author$
     *     Date: 6/4/2004
     **********************************************************************
     */
    virtual eError OnURIFragment
    (const char *fragment, int fragment_length)
    {
        return e_ERROR_NONE;
    }
};

#endif /* ndef _CURI_HXX */
