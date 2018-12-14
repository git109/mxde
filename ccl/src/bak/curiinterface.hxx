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
 *   File: curiinterface.hxx
 *
 * Author: $author$
 *   Date: 2/4/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CURIINTERFACE_HXX
#define _CURIINTERFACE_HXX

#include "curischemeinterface.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cURIInterface
 *
 * Author: $author$
 *   Date: 2/4/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cURIInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: OpenURL
     *
     *   Author: $author$
     *     Date: 6/10/2004
     **********************************************************************
     */
    virtual cURLInterface *OpenURL() = 0;
    /**
     **********************************************************************
     * Function: CloseURL
     *
     *   Author: $author$
     *     Date: 6/10/2004
     **********************************************************************
     */
    virtual eError CloseURL(cURLInterface &url) = 0;

    /**
     **********************************************************************
     * Function: SetURISchemeInterface
     *
     *   Author: $author$
     *     Date: 6/4/2004
     **********************************************************************
     */
    virtual eError SetURISchemeInterface(cURISchemeInterface *scheme)=0;
    /**
     **********************************************************************
     * Function: GetURISchemeInterface
     *
     *   Author: $author$
     *     Date: 6/4/2004
     **********************************************************************
     */
    virtual cURISchemeInterface &GetURISchemeInterface() const=0;

    /**
     **********************************************************************
     * Function: SetURI
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetURI(const char *uri, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetURI
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetURI(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetURIScheme
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetURIScheme(const char *scheme, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetURIScheme
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetURIScheme(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetURISchemeSpecific
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetURISchemeSpecific(const char *specific, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetURISchemeSpecific
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetURISchemeSpecific(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetURIAuthority
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual int SetURIAuthority(const char *authority, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetURIAuthority
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual const char *GetURIAuthority(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetURIUser
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual int SetURIUser(const char *user, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetURIUser
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual const char *GetURIUser(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetURIHost
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual int SetURIHost(const char *host, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetURIHost
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual const char *GetURIHost(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetURIPort
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual int SetURIPort(const char *port, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetURIPort
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual const char *GetURIPort(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetURIPath
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual int SetURIPath(const char *path, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetURIPath
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual const char *GetURIPath(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetURIQuery
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetURIQuery(const char *query, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetURIQuery
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetURIQuery(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetURIFragment
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetURIFragment(const char *fragment, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetURIFragment
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetURIFragment(int &length) const=0;

    /**
     **********************************************************************
     * Function: OnGenericURISchemeSpecific
     *
     *   Author: $author$
     *     Date: 6/4/2004
     **********************************************************************
     */
    virtual eError OnGenericURISchemeSpecific
    (const char *scheme_specific, int scheme_specific_length)=0;
};

/**
 **********************************************************************
 *  Class: cURIImplement
 *
 * Author: $author$
 *   Date: 2/4/2004
 **********************************************************************
 */
class cURIImplement
: virtual public cURIInterface
{
public:
    /**
     **********************************************************************
     * Function: OpenURL
     *
     *   Author: $author$
     *     Date: 6/10/2004
     **********************************************************************
     */
    virtual cURLInterface *OpenURL()
    {
        cURISchemeInterface &scheme = GetURISchemeInterface();
        cURLInterface *url = scheme.OpenURL(*this);
        return url;
    }
    /**
     **********************************************************************
     * Function: CloseURL
     *
     *   Author: $author$
     *     Date: 6/10/2004
     **********************************************************************
     */
    virtual eError CloseURL(cURLInterface &url)
    {
        cURISchemeInterface &scheme = GetURISchemeInterface();
        eError error = scheme.CloseURL(url);
        return error;
    }

    /**
     **********************************************************************
     * Function: SetURISchemeInterface
     *
     *   Author: $author$
     *     Date: 6/4/2004
     **********************************************************************
     */
    virtual eError SetURISchemeInterface(cURISchemeInterface *scheme)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetURISchemeInterface
     *
     *   Author: $author$
     *     Date: 6/4/2004
     **********************************************************************
     */
    virtual cURISchemeInterface &GetURISchemeInterface() const
    {
        return cURISchemeInterface::GetGenericScheme();
    }

    /**
     **********************************************************************
     * Function: SetURI
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetURI(const char *uri, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetURI
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetURI(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetURIScheme
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetURIScheme(const char *scheme, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetURIScheme
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetURIScheme(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetURISchemeSpecific
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetURISchemeSpecific(const char *specific, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetURISchemeSpecific
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetURISchemeSpecific(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetURIAuthority
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual int SetURIAuthority(const char *authority, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetURIAuthority
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual const char *GetURIAuthority(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetURIUser
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual int SetURIUser(const char *user, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetURIUser
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual const char *GetURIUser(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetURIHost
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual int SetURIHost(const char *host, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetURIHost
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual const char *GetURIHost(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetURIPort
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual int SetURIPort(const char *port, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetURIPort
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual const char *GetURIPort(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetURIPath
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual int SetURIPath(const char *path, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetURIPath
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual const char *GetURIPath(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetURIQuery
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetURIQuery(const char *query, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetURIQuery
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetURIQuery(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetURIFragment
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetURIFragment(const char *fragment, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetURIFragment
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetURIFragment(int &length) const
    {
        return 0;
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
        return e_ERROR_NOT_IMPLEMENTED;
    }
};

#endif /* ndef _CURIINTERFACE_HXX */
