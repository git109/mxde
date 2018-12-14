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
 *   File: cpath.hxx
 *
 * Author: $author$
 *   Date: 3/4/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CPATH_HXX
#define _CPATH_HXX

#include "cpathinterface.hxx"
#include "ccharbuffer.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cPath
 *
 * Author: $author$
 *   Date: 3/4/2004
 **********************************************************************
 */
class cPath
: virtual public cPathInterface,
  virtual public cPathImplement,
  public cErrorInstance
{
public:
    typedef cErrorInstance cIs;

    cCharBuffer m_path;
    cCharBuffer m_host;
    cCharBuffer m_volume;
    cCharBuffer m_directory;
    cCharBuffer m_filename;
    cCharBuffer m_extension;
    bool m_is_absolute;
    bool m_is_root;

    /**
     **********************************************************************
     * Constructor: cPath
     *
     *      Author: $author$
     *        Date: 3/4/2004
     **********************************************************************
     */
    cPath(const char *path=0, int length=-1)
    : m_is_absolute(false),
      m_is_root(false)
    {
        eError error;

        if (path)
        if (0 > (length = SetPath(path, length)))
            throw(error = -length);
    }

    /**
     **********************************************************************
     * Function: SetPath
     *
     *   Author: $author$
     *     Date: 3/4/2004
     **********************************************************************
     */
    virtual int SetPath(cCharStream &stream, int length=-1)
    {
        const char *path;

        if (0 < (length = m_path.CopyStream(stream, length)))
        if ((path = m_path.GetBuffer(length)))
            length = SetPath(path, length);

        return length;
    }
    /**
     **********************************************************************
     * Function: SetPath
     *
     *   Author: $author$
     *     Date: 3/4/2004
     **********************************************************************
     */
    virtual int SetPath(const char *path, int length=-1)
    {
        enum eState
        {
            S_VOLUME,
            S_SUBDIR,
            S_FILENAME,
            S_EXTENSION,
            S_DOTDOT
        };
        char c;
        int first_char;
        int next_char;
        int ext_char;
        int dot_char;
        int count;
        eState state;

        m_is_absolute=false;
        m_is_root=false;

        if (m_path.GetBuffer() != path)
        if (0 >= (length = m_path.Copy(path, length)))
            return length;
        else if (!(path = m_path.GetBuffer()))
                return length = -e_ERROR_FAILED;

        if (0 <= (count = m_host.Clear()))
        if (0 <= (count = m_volume.Clear()))
        if (0 <= (count = m_directory.Clear()))
        if (0 <= (count = m_filename.Clear()))
        if (0 <= (count = m_extension.Clear()))
        {
            state=S_VOLUME;
            first_char=0;

            for (next_char=0; next_char<length; next_char++)
            {
                c=path[next_char];
                switch(state)
                {
                case S_VOLUME:
                    switch(c)
                    {
                    case '.':
                        dot_char = next_char;
                        ext_char = next_char;

                        if (next_char>first_char)
                            /* ?.
                             */
                            state=S_EXTENSION;

                        else /* .
                              */
                            state=S_DOTDOT;
                        break;

                    case '/':
                    case '\\':
                        if (next_char<1)
                        {
                            if (0 > (count=m_directory.Putc('/')))
                                return count;

                            m_is_absolute=true;
                            m_is_root=true;
                        }
                        else if (0 > (count=m_directory.Write
                                (path,next_char)))
                                return count;

                        first_char=next_char+1;
                        state=S_FILENAME;
                        break;

                    case ':':
                        if (next_char<1)
                            return -e_ERROR_FAILED;

                        if (0 > (count=m_volume.Copy
                            (path,next_char)))
                            return count;

                        first_char=next_char+1;
                        state=S_SUBDIR;
                        break;
                    }
                    break;

                case S_SUBDIR:
                    switch(c)
                    {
                    case '.':
                        dot_char=next_char;
                        ext_char=next_char;

                        if (next_char>first_char)
                            /* ?.
                             */
                            state=S_EXTENSION;

                        else /* .
                              */
                            state=S_DOTDOT;
                        break;

                    case '/':
                    case '\\':
                        if (next_char<=first_char)
                        {
                            if (0 > (count=m_directory.Putc('/')))
                                return count;

                            m_is_absolute=true;
                            m_is_root=true;
                        }
                        else if (0 > (count=m_directory.Write
                                (path+first_char,next_char-first_char)))
                                return count;

                        first_char=next_char+1;
                        state=S_FILENAME;
                        break;
                    }
                    break;

                case S_FILENAME:
                    switch(c)
                    {
                    case '.':
                        dot_char=next_char;
                        ext_char=next_char;

                        if (next_char>first_char)
                            /* ?.
                             */
                            state=S_EXTENSION;

                        else /* .
                              */
                            state=S_DOTDOT;
                        break;

                    case '/':
                    case '\\':
                        if (next_char<=first_char)
                            /* //
                             */
                            return -e_ERROR_FAILED;

                        /* ?/
                         */
                        if (!m_is_root)
                        if (0 > (count=m_directory.Putc('/')))
                            return count;

                        if (0> (count=m_directory.Write
                            (path+first_char,next_char-first_char)))
                            return count;

                        m_is_root=false;
                        first_char=next_char+1;
                        break;
                    }
                    break;

                case S_EXTENSION:
                    switch(c)
                    {
                    case '.':
                        if (next_char-ext_char<2)
                            /* ?..
                             */
                            return -e_ERROR_FAILED;

                        ext_char=next_char;
                        break;

                    case '/':
                    case '\\':
                        /* (?.)+/
                         */
                        if (m_directory.GetLength()>0)
                        if (0 > (count=m_directory.Putc('/')))
                            return count;

                        if (0 > (count=m_directory.Write
                            (path+first_char,next_char-first_char)))
                            return count;

                        m_is_root=false;
                        first_char=next_char+1;
                        state=S_FILENAME;
                        break;
                    }
                    break;

                case S_DOTDOT:
                    switch(c)
                    {
                    case '.':
                        if (next_char-ext_char>1)
                            /* .?.
                             */
                            state=S_EXTENSION;

                        else if (next_char-first_char>1)
                                /* ?..
                                 */
                                return -e_ERROR_FAILED;

                        dot_char=ext_char;
                        ext_char=next_char;
                        break;

                    case '/':
                    case '\\':
                        /* ((..)|(.?(.|((.?)*))))/
                         */
                        if (m_directory.GetLength()>0)
                        if (0 > (count=m_directory.Putc('/')))
                            return count;

                        if (0 > (count=m_directory.Write
                            (path+first_char,next_char-first_char)))
                            return count;

                        m_is_root=false;
                        first_char=next_char+1;
                        state=S_FILENAME;
                        break;

                    default:
                        if ((ext_char-dot_char)==1)
                            return -e_ERROR_FAILED;
                    }
                    break;
                }
            }

            if (next_char<=first_char)
                return -e_ERROR_FAILED;

            switch(state)
            {
            case S_EXTENSION:
                if (0 > (count=m_filename.Copy
                    (path+first_char,ext_char-first_char)))
                    return count;

                if (0 > (count=m_extension.Copy
                    (path+ext_char+1,next_char-ext_char-1)))
                    return count;
                break;

            default:
                if (0 > (count=m_filename.Copy
                    (path+first_char,next_char-first_char)))
                    return count;
            }

            count = length;
        }
        return count;
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
        return m_is_absolute;
    }

    /**
     **********************************************************************
     * Function: GetPathVolume
     *
     *   Author: $author$
     *     Date: 3/5/2004
     **********************************************************************
     */
    virtual const char *GetPathVolume(int &length) const
    {
        return m_volume.GetBuffer(length);
    }

    /**
     **********************************************************************
     * Function: GetPathDirectory
     *
     *   Author: $author$
     *     Date: 3/5/2004
     **********************************************************************
     */
    virtual const char *GetPathDirectory(int &length) const
    {
        return m_directory.GetBuffer(length);
    }

    /**
     **********************************************************************
     * Function: GetPathExtension
     *
     *   Author: $author$
     *     Date: 4/6/2005
     **********************************************************************
     */
    virtual const char *GetPathExtension(int &length) const
    {
        return m_extension.GetBuffer(length);
    }
};

#endif /* ndef _CPATH_HXX */
