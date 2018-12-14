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
 *   File: creadwritefilet.hxx
 *
 * Author: $author$
 *   Date: 6/9/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CREADWRITEFILET_HXX
#define _CREADWRITEFILET_HXX

#include <stdio.h>

#include "creadwritehandlet.hxx"
#include "cstreamt.hxx"

/**
 **********************************************************************
 *  Class: cReadWriteFileT
 *
 * Author: $author$
 *   Date: 6/9/2004
 **********************************************************************
 */
template <class TOf, class TIs=cStreamT<TOf, cStream> >
class cReadWriteFileT
: public cReadWriteHandleT<FILE*, 0, TIs>
{
public:
    typedef cReadWriteHandleT<FILE*, 0, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cReadWriteFileT
     *
     *      Author: $author$
     *        Date: 6/9/2004
     **********************************************************************
     */
    cReadWriteFileT(FILE *read_file=0, FILE *write_file=0) 
    : cIs(read_file, write_file) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cReadWriteFileT
     *
     *     Author: $author$
     *       Date: 6/9/2004
     **********************************************************************
     */
    virtual ~cReadWriteFileT()
    {
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual int Read(TOf *buffer, int size)
    {
        int count;

        if (size < 0)
            return -e_ERROR_INVALID_PARAMETER_SIZE;

        if (m_read_handle != NULL)
        {
            if ((count = fread
                (buffer, sizeof(TOf), size, m_read_handle)) >= 0)
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
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual int Write(const TOf *buffer, int size=-1)
    {
        int count;

        if (size < 0)
            size = GetLengthOf(buffer);

        if (size < 1)
            return 0;

        if (m_write_handle != NULL)
        {
            if ((count = fwrite
                (buffer, sizeof(TOf), size, m_write_handle)) >= 0)
                return count;

            return -e_ERROR_WRITE;
        }
        return -e_ERROR_NOT_OPEN;
    }
};

#endif /* ndef _CREADWRITEFILET_HXX */
