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
 *   File: curischemeinterface.hxx
 *
 * Author: $author$
 *   Date: 5/31/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CURISCHEMEINTERFACE_HXX
#define _CURISCHEMEINTERFACE_HXX

#include "curlinterface.hxx"
#include "cinterface.hxx"

class c_INTERFACE_CLASS cURIInterface;

/**
 **********************************************************************
 *  Class: cURISchemeInterface
 *
 * Author: $author$
 *   Date: 5/31/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cURISchemeInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: GetGenericScheme
     *
     *   Author: $author$
     *     Date: 1/3/2005
     **********************************************************************
     */
    static cURISchemeInterface &GetGenericScheme();

    /**
     **********************************************************************
     * Function: GetSchemeName
     *
     *   Author: $author$
     *     Date: 6/1/2004
     **********************************************************************
     */
    virtual const char *GetSchemeName(int &length) const = 0;

    /**
     **********************************************************************
     * Function: OnURISchemeSpecific
     *
     *   Author: $author$
     *     Date: 6/1/2004
     **********************************************************************
     */
    virtual eError OnURISchemeSpecific
    (cURIInterface &uri, const char *scheme, int scheme_length,
     const char *scheme_specific, int scheme_specific_length) = 0;

    /**
     **********************************************************************
     * Function: OpenURL
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual cURLInterface *OpenURL(cURIInterface &uri) = 0;
    /**
     **********************************************************************
     * Function: CloseURL
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual eError CloseURL(cURLInterface &url) = 0;

};

/**
 **********************************************************************
 *  Class: cURISchemeImplement
 *
 * Author: $author$
 *   Date: 6/5/2004
 **********************************************************************
 */
class cURISchemeImplement
: virtual public cURISchemeInterface
{
public:
    /**
     **********************************************************************
     * Function: GetSchemeName
     *
     *   Author: $author$
     *     Date: 6/1/2004
     **********************************************************************
     */
    virtual const char *GetSchemeName(int &length) const
    {
        length = 0;
        return 0;
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
    (cURIInterface &uri, const char *scheme, int scheme_length,
     const char *scheme_specific, int scheme_specific_length)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: OpenURL
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual cURLInterface *OpenURL(cURIInterface &uri)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: CloseURL
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual eError CloseURL(cURLInterface &url)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
};

/**
 **********************************************************************
 *  Class: cURISchemeSetInterface
 *
 * Author: $author$
 *   Date: 6/1/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cURISchemeSetInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: GetFirstURISchemeByName
     *
     *   Author: $author$
     *     Date: 6/1/2004
     **********************************************************************
     */
    virtual cURISchemeInterface *GetFirstURISchemeByName
    (const char *name, int namelen=-1) const = 0;
    /**
     **********************************************************************
     * Function: GetLastURISchemeByName
     *
     *   Author: $author$
     *     Date: 6/1/2004
     **********************************************************************
     */
    virtual cURISchemeInterface *GetLastURISchemeByName
    (const char *name, int namelen=-1) const = 0;
};

/**
 **********************************************************************
 *  Class: cURISchemeSetImplement
 *
 * Author: $author$
 *   Date: 6/1/2004
 **********************************************************************
 */
class cURISchemeSetImplement
: virtual public cURISchemeSetInterface
{
public:
    /**
     **********************************************************************
     * Function: GetFirstURISchemeByName
     *
     *   Author: $author$
     *     Date: 6/1/2004
     **********************************************************************
     */
    virtual cURISchemeInterface *GetFirstURISchemeByName
    (const char *name, int namelen=-1) const
    {
        cURISchemeInterface *scheme=0;
        return scheme;
    }
    /**
     **********************************************************************
     * Function: GetLastURISchemeByName
     *
     *   Author: $author$
     *     Date: 6/1/2004
     **********************************************************************
     */
    virtual cURISchemeInterface *GetLastURISchemeByName
    (const char *name, int namelen=-1) const
    {
        cURISchemeInterface *scheme=0;
        return scheme;
    }
};

#endif /* ndef _CURISCHEMEINTERFACE_HXX */
