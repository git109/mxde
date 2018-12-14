/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: cfileurischeme.hxx
 *
 * Author: $author$
 *   Date: 1/4/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEURISCHEME_HXX
#define _CFILEURISCHEME_HXX

#include "curischeme.hxx"
#include "curiinterface.hxx"
#include "ccharfile.hxx"

/**
 **********************************************************************
 *  Class: cFileURL
 *
 * Author: $author$
 *   Date: 1/4/2005
 **********************************************************************
 */
class cFileURL
: virtual public cURLInterface,
  virtual public cURLImplement,
  public cErrorInstance
{
public:
    typedef cErrorInstance cIs;

    int m_path_length;
    const char *m_path;
    cCharBuffer m_path_buffer;
    cCharFile m_file;

    /**
     **********************************************************************
     * Constructor: cFileURL
     *
     *      Author: $author$
     *        Date: 1/4/2005
     **********************************************************************
     */
    cFileURL(const char *drive, const char *path) 
    {
        eError error;
        int length;

        if (0 > (length = m_path_buffer.Write(drive)))
            throw(error = -length);

        if (0 < length)
        if (0 > (length = m_path_buffer.Write(":")))
            throw(error = -length);

        if (0 > (length = m_path_buffer.Write(path)))
            throw(error = -length);

        if (!(m_path = m_path_buffer.GetBuffer(m_path_length)))
            throw(error = e_ERROR_FAILED);
    }
    /**
     **********************************************************************
     *  Destructor: ~cFileURL
     *
     *      Author: $author$
     *        Date: 1/4/2005
     **********************************************************************
     */
    virtual ~cFileURL()
    {
        eError error;

        if (m_file.GetIsOpen())
        if ((error = m_file.Close()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 1/4/2005
     **********************************************************************
     */
    virtual eError Open()
    {
        eError error = m_file.Open(m_path);
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 1/4/2005
     **********************************************************************
     */
    virtual eError Close()
    {
        return m_file.Close();
    }
    /**
     **********************************************************************
     * Function: GetContent
     *
     *   Author: $author$
     *     Date: 1/4/2005
     **********************************************************************
     */
    virtual cCharStream *GetContent
    (const char *&content_type, int &content_length) const
    {
        content_type = "";
        content_length = -1;
        return (cCharStream*)&m_file;
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 1/4/2005
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        delete this;
        return e_ERROR_NONE;
    }
};

/**
 **********************************************************************
 *  Class: cFileURIScheme
 *
 * Author: $author$
 *   Date: 1/4/2005
 **********************************************************************
 */
class cFileURIScheme
: public cURIScheme
{
public:
    typedef cURIScheme cIs;

    /**
     **********************************************************************
     * Constructor: cFileURIScheme
     *
     *      Author: $author$
     *        Date: 1/4/2005
     **********************************************************************
     */
    cFileURIScheme(const char *name)
    : cIs(name) 
    {
    }
    /**
     **********************************************************************
     * Function: OnURISchemeSpecific
     *
     *   Author: $author$
     *     Date: 1/4/2005
     **********************************************************************
     */
    virtual eError OnURISchemeSpecific
    (cURIInterface &uri, const char *scheme, int scheme_length,
     const char *scheme_specific, int scheme_specific_length)
    {
        return uri.OnGenericURISchemeSpecific
        (scheme_specific, scheme_specific_length);
    }
    /**
     **********************************************************************
     * Function: OpenURL
     *
     *   Author: $author$
     *     Date: 1/4/2005
     **********************************************************************
     */
    virtual cURLInterface *OpenURL(cURIInterface &uri)
    {
        cFileURL *url = 0;
        eError error;
        int host_length,path_length;
        const char *host,*path;

        if ((path = uri.GetURIPath(path_length)))
        if ((host = uri.GetURIHost(host_length)))
        {
            if ((url = new cFileURL(host, path)))
            if ((error = url->Open()))
            {
                delete url;
                url = 0;
            }
        }
        return url;
    }
    /**
     **********************************************************************
     * Function: CloseURL
     *
     *   Author: $author$
     *     Date: 1/4/2005
     **********************************************************************
     */
    virtual eError CloseURL(cURLInterface &url)
    {
        eError error,error2;

        error = url.Close();

        if ((error2 = url.FreeInstance()))
        if (!error)
            error = error2;

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cStaticFileURIScheme
 *
 * Author: $author$
 *   Date: 1/4/2005
 **********************************************************************
 */
class cStaticFileURIScheme
: public cFileURIScheme
{
public:
    typedef cFileURIScheme cIs;

    static cStaticFileURIScheme m_instance;

    /**
     **********************************************************************
     * Constructor: cStaticFileURIScheme
     *
     *      Author: $author$
     *        Date: 1/4/2005
     **********************************************************************
     */
    cStaticFileURIScheme(const char *name)
    : cIs(name) 
    {
        cStaticURISchemeSet::m_instance.Add(this);
    }
    /**
     **********************************************************************
     *  Destructor: ~cStaticFileURIScheme
     *
     *      Author: $author$
     *        Date: 1/4/2005
     **********************************************************************
     */
    virtual ~cStaticFileURIScheme()
    {
        cStaticURISchemeSet::m_instance.Delete(this);
    }
};

#endif /* _CFILEURISCHEME_HXX */