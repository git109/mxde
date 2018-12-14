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
 *   File: curcinterface.hxx
 *
 * Author: $author$
 *   Date: 6/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CURCINTERFACE_HXX
#define _CURCINTERFACE_HXX

#include "cinterface.hxx"
#include "ccharstream.hxx"

/**
 **********************************************************************
 *  Class: cURCInterface
 *
 * Author: $author$
 *   Date: 6/21/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cURCInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: SetContentType
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual int SetContentType
    (const char *content_type, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetContentType
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual const char *GetContentType(int &length) const = 0;

    /**
     **********************************************************************
     * Function: SetContentLength
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual eError SetContentLength(int content_length) = 0;
    /**
     **********************************************************************
     * Function: GetContentLength
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual int GetContentLength() const = 0;

    /**
     **********************************************************************
     * Function: SetContent
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual eError SetContent
    (cCharStream *content, const char *content_type=0, int content_length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetContent
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual cCharStream *GetContent
    (const char *&content_type, int &content_length) const = 0;
};

/**
 **********************************************************************
 *  Class: cURCImplement
 *
 * Author: $author$
 *   Date: 6/21/2004
 **********************************************************************
 */
class cURCImplement
: virtual public cURCInterface
{
public:
    /**
     **********************************************************************
     * Function: SetContentType
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual int SetContentType
    (const char *content_type, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetContentType
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual const char *GetContentType(int &length) const
    {
        length = -e_ERROR_NOT_IMPLEMENTED;
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetContentLength
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual eError SetContentLength(int content_length)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetContentLength
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual int GetContentLength() const
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: SetContent
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual eError SetContent
    (cCharStream *content, const char *content_type=0, int content_length=-1)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetContent
     *
     *   Author: $author$
     *     Date: 6/8/2004
     **********************************************************************
     */
    virtual cCharStream *GetContent
    (const char *&content_type, int &content_length) const
    {
        content_length = -e_ERROR_NOT_IMPLEMENTED;
        content_type = 0;
        return 0;
    }
};

#endif /* ndef _CURCINTERFACE_HXX */
