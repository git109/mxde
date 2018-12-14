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
 *   File: cpathinterface.hxx
 *
 * Author: $author$
 *   Date: 2/4/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CPATHINTERFACE_HXX
#define _CPATHINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cPathInterface
 *
 * Author: $author$
 *   Date: 2/4/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cPathInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: SetIsAbsolute
     *
     *   Author: $author$
     *     Date: 3/5/2004
     **********************************************************************
     */
    virtual bool SetIsAbsolute(bool is_absolute=true)=0;
    /**
     **********************************************************************
     * Function: GetIsAbsolute
     *
     *   Author: $author$
     *     Date: 3/5/2004
     **********************************************************************
     */
    virtual bool GetIsAbsolute() const=0;

    /**
     **********************************************************************
     * Function: SetPath
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetPath(const char *path, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetPath
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetPath(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetPathHost
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetPathHost(const char *host, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetPathHost
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetPathHost(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetPathVolume
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetPathVolume(const char *drive, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetPathVolume
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetPathVolume(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetPathDirectory
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetPathDirectory(const char *directory, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetPathDirectory
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetPathDirectory(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetPathFilename
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetPathFilename(const char *filename, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetPathFilename
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetPathFilename(int &length) const=0;

    /**
     **********************************************************************
     * Function: SetPathExtension
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetPathExtension(const char *extension, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetPathExtension
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetPathExtension(int &length) const=0;
};

/**
 **********************************************************************
 *  Class: cPathImplement
 *
 * Author: $author$
 *   Date: 2/4/2004
 **********************************************************************
 */
class cPathImplement
: virtual public cPathInterface
{
public:
    /**
     **********************************************************************
     * Function: SetIsAbsolute
     *
     *   Author: $author$
     *     Date: 3/5/2004
     **********************************************************************
     */
    virtual bool SetIsAbsolute(bool is_absolute=true)
    {
        return false;
    }
    /**
     **********************************************************************
     * Function: GetIsAbsolute
     *
     *   Author: $author$
     *     Date: 3/5/2004
     **********************************************************************
     */
    virtual bool GetIsAbsolute() const
    {
        return false;
    }

    /**
     **********************************************************************
     * Function: SetPath
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetPath(const char *path, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetPath
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetPath(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetPathHost
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetPathHost(const char *host, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetPathHost
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetPathHost(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetPathVolume
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetPathVolume(const char *drive, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetPathVolume
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetPathVolume(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetPathDirectory
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetPathDirectory(const char *directory, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetPathDirectory
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetPathDirectory(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetPathFilename
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetPathFilename(const char *filename, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetPathFilename
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetPathFilename(int &length) const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetPathExtension
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual int SetPathExtension(const char *extension, int length=-1)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetPathExtension
     *
     *   Author: $author$
     *     Date: 2/4/2004
     **********************************************************************
     */
    virtual const char *GetPathExtension(int &length) const
    {
        return 0;
    }
};

#endif /* ndef _CPATHINTERFACE_HXX */
