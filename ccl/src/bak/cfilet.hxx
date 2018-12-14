/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: cfilet.hxx
 *
 * Author: $author$
 *   Date: 7/4/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILET_HXX
#define _CFILET_HXX

#include <stdio.h>

#include "chandlet.hxx"
#include "cstreamt.hxx"

/**
 **********************************************************************
 *  Class: cFileT
 *
 * Author: $author$
 *   Date: 7/4/2003
 **********************************************************************
 */
template <class TOf, class TIs=cStreamT<TOf, cStream> >
class cFileT
: public cOpenedHandleT<FILE*, 0, TIs>
{
public:
    typedef cOpenedHandleT<FILE*, 0, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cFileT
     *
     *      Author: $author$
     *        Date: 7/4/2003
     **********************************************************************
     */
    cFileT(FILE *file=0, bool opened=false) 
    : cIs(file, opened) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cFileT
     *
     *      Author: $author$
     *        Date: 7/4/2003
     **********************************************************************
     */
    cFileT(const char *path) 
    {
        eError error;

        if ((error = Open(path)))
            throw(error);
    }
    /**
     **********************************************************************
     * Destructor: ~cFileT
     *
     *     Author: $author$
     *       Date: 7/4/2003
     **********************************************************************
     */
    virtual ~cFileT()
    {
        eError error;

        if (m_opened)
        if ((error = Close()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Exist
     *
     *   Author: $author$
     *     Date: 8/18/2003
     **********************************************************************
     */
    virtual eError Exist(const char *path)
    {
        int err;
        struct stat st;

        if ((err=stat(path, &st)))
            return e_ERROR_NOT_EXIST;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 8/9/2003
     **********************************************************************
     */
    virtual eError Open(const char *path, const char *mode="r")
    {
        if (m_opened)
            return e_ERROR_ALREADY_OPEN;

        if (!(m_handle = fopen(path, mode)))
            return e_ERROR_OPEN;

        m_opened = true;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 8/9/2003
     **********************************************************************
     */
    virtual eError Close()
    {
        int err;

        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (!m_opened)
            return e_ERROR_NOT_OPEN;

        if ((err = fclose(m_handle)))
            return e_ERROR_CLOSE;

        m_opened = false;
        m_handle = 0;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 7/4/2003
     **********************************************************************
     */
    virtual int Read(TOf *buffer, int size)
    {
        int count;

        if (size < 0)
            return -e_ERROR_INVALID_PARAMETER_SIZE;

        if (m_handle != NULL)
        {
            if ((count = fread
                (buffer, sizeof(TOf), size, m_handle)) >= 0)
                return count;

            return -e_ERROR_READ;
        }
        return -e_ERROR_NOT_OPEN;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 7/4/2003
     **********************************************************************
     */
    virtual int Write(const TOf *buffer, int size=-1)
    {
        int count;

        if (size < 0)
            size = GetLengthOf(buffer);

        if (size < 1)
            return 0;

        if (m_handle != NULL)
        {
            if ((count = fwrite
                (buffer, sizeof(TOf), size, m_handle)) >= 0)
                return count;

            return -e_ERROR_WRITE;
        }
        return -e_ERROR_NOT_OPEN;
    }
    /**
     **********************************************************************
     * Function: Flush
     *
     *   Author: $author$
     *     Date: 3/9/2004
     **********************************************************************
     */
    virtual int Flush()
    {
        int count;

        if (m_handle != NULL)
        {
            if (0 == (count = fflush(m_handle)))
                return count;

            return -e_ERROR_FLUSH;
        }
        return -e_ERROR_NOT_OPEN;
    }
};


#endif
