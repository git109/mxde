/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: cfilepatht.hxx
 *
 * Author: $author$
 *   Date: 11/23/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CFILEPATHT_HXX
#define _CFILEPATHT_HXX

#include "cfilepathparser.hxx"
#include "cfilepathparserevent.hxx"
#include "cfilepathinterface.hxx"
#include "cfiledirectoryentry.hxx"
#include "cfilehandle.hxx"
#include "cfilehandlet.hxx"
#include "ccharbuffer.hxx"
#include "cccharbuffer.hxx"
#include "ccchartocharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cFilePathT
 *
 * Author: $author$
 *   Date: 11/23/2005
 **********************************************************************
 */
template
<class TIs=cFileHandle>
class cFilePathT
: public TIs
{
public:
    typedef TIs cIs;

    int m_type;
    cChar m_directory_separator;

    cCCharBuffer m_path;
    cCCharBuffer m_host;
    cCCharBuffer m_device;
    cCCharBuffer m_directory;
    cCCharBuffer m_file;
    cCCharBuffer m_extension;

    /**
     **********************************************************************
     * Constructor: cFilePathT
     *
     *      Author: $author$
     *        Date: 11/23/2005
     **********************************************************************
     */
    cFilePathT(FILE *file=0, bool opened=false) 
    : cIs(file, opened),
      m_type(e_TYPE_NONE),
      m_directory_separator(DIRECTORY_SEPARATOR_CHAR)
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        int length;

        m_type = e_TYPE_NONE;

        if (0 <= (length = m_path.Clear()))
        if (0 <= (length = m_host.Clear()))
        if (0 <= (length = m_device.Clear()))
        if (0 <= (length = m_directory.Clear()))
        if (0 <= (length = m_file.Clear()))
        if (0 <= (length = m_extension.Clear()))
            return error;

        error = -length;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual eError Open(const char *mode="r") 
    {
        eError error = e_ERROR_NONE;
        cCCharToCharBuffer path;
        const cChar *path_cchars;
        const char *path_chars;
        int length;

        if (m_opened)
            return e_ERROR_ALREADY_OPEN;

        if (!(path_cchars = m_path.GetBuffer(length)))
            return e_ERROR_FAILED;

        if (0 > (length = path.WriteCChar(path_cchars, length)))
            return error = -length;

        if (!(path_chars = path.GetBuffer(length)))
            return e_ERROR_FAILED;

        if (!(m_handle = fopen(path_chars, mode)))
            return e_ERROR_OPEN;

        m_opened = true;
        return error;
    }
    /**
     **********************************************************************
     * Function: Exist
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual eError Exist() const
    {
        eError error = e_ERROR_NONE;
        struct stat st;
        cCCharToCharBuffer path;
        const cChar *path_cchars;
        const char *path_chars;
        int length;
        int err;

        if (!(path_cchars = m_path.GetBuffer(length)))
            return e_ERROR_FAILED;

        if (0 > (length = path.WriteCChar(path_cchars, length)))
            return error = -length;

        if (!(path_chars = path.GetBuffer(length)))
            return e_ERROR_FAILED;

        if ((err = stat(path_chars, &st)))
            return e_ERROR_EXIST;

        return error;
    }

    /**
     **********************************************************************
     * Function: SetPath
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual int SetPath(const cChar* chars, int length=-1) 
    {
        length = m_path.Copy(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: SetPathc
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual int SetPathc(const char* chars, int length=-1) 
    {
        length = m_path.Copyc(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetPath
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual const cChar* GetPath(int &length) const
    {
        const cChar* chars = m_path.GetBuffer(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetHost
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int SetHost
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_host.Copy(chars,length);
        return result;
    }
    /**
     **********************************************************************
     * Function: GetHost
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual const cChar* GetHost
    (int& length) const 
    {
        const cChar* chars = m_host.GetBuffer(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetDevice
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int SetDevice
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_device.Copy(chars,length);
        return result;
    }
    /**
     **********************************************************************
     * Function: GetDevice
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual const cChar* GetDevice
    (int& length) const 
    {
        const cChar* chars = m_device.GetBuffer(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: WriteDirectory
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int WriteDirectory
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_directory.Write(chars,length);
        return result;
    }
    /**
     **********************************************************************
     * Function: SetDirectory
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int SetDirectory
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_directory.Copy(chars,length);
        return result;
    }
    /**
     **********************************************************************
     * Function: GetDirectory
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual const cChar* GetDirectory
    (int& length) const 
    {
        const cChar* chars = m_directory.GetBuffer(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetDirectorySeparator
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual const cChar& GetDirectorySeparator
    () const 
    {
        const cChar& cchar = m_directory_separator;
        return cchar;
    }
    /**
     **********************************************************************
     * Function: GetDirectoryLength
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int GetDirectoryLength
    () const 
    {
        int length = m_directory.GetLength();
        return length;
    }
    /**
     **********************************************************************
     * Function: SetFile
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int SetFile
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_file.Copy(chars,length);
        return result;
    }
    /**
     **********************************************************************
     * Function: GetFile
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual const cChar* GetFile
    (int& length) const 
    {
        const cChar* chars = m_file.GetBuffer(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetExtension
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int SetExtension
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_extension.Copy(chars,length);
        return result;
    }
    /**
     **********************************************************************
     * Function: GetExtension
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual const cChar* GetExtension
    (int& length) const 
    {
        const cChar* chars = m_extension.GetBuffer(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int SetType(int type) 
    {
        m_type = type;
        return m_type;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int GetType() const 
    {
        return m_type;
    }
};

/**
 **********************************************************************
 *  Class: cFilePathFileHandle
 *
 * Author: $author$
 *   Date: 1/16/2006
 **********************************************************************
 */
class cFilePathFileHandle
: virtual public cFilePathImplement,
  public cFileHandleInstance
{
public:
    typedef cFileHandleInstance cIs;

    /**
     **********************************************************************
     * Constructor: cFilePathFileHandle
     *
     *      Author: $author$
     *        Date: 1/16/2006
     **********************************************************************
     */
    cFilePathFileHandle(FILE *file=0, bool opened=false) 
    : cIs(file, opened) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cFilePath
 *
 * Author: $author$
 *   Date: 11/23/2005
 **********************************************************************
 */
class cFilePath
: public cFilePathT<cFilePathFileHandle>
{
public:
    typedef cFilePathT<cFilePathFileHandle> cIs;

    cFilePathParserEvent m_event;
    cFilePathParser m_parser;

    /**
     **********************************************************************
     * Constructor: cFilePath
     *
     *      Author: $author$
     *        Date: 11/23/2005
     **********************************************************************
     */
    cFilePath(FILE *file=0, bool opened=false) 
    : cIs(file, opened),
      m_event(*this),
      m_parser(m_event)
    {
    }
    /**
     **********************************************************************
     * Function: SetPath
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int SetPath(const cChar* chars, int length=-1) 
    {
        eError error;

        if ((error = m_parser.Parse(chars, length)))
            return length = -error;

        length = m_path.Copy(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: SetPathc
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int SetPathc(const char* chars, int length=-1) 
    {
        eError error;

        if ((error = m_parser.Parsec(chars, length)))
            return length = -error;

        length = m_path.Copyc(chars, length);
        return length;
    }
};

#endif /* _CFILEPATHT_HXX */
