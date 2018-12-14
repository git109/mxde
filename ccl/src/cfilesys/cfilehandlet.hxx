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
 *   File: cfilehandlet.hxx
 *
 * Author: $author$
 *   Date: 11/23/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CFILEHANDLET_HXX
#define _CFILEHANDLET_HXX

#include <stdio.h>
#include "chandlet.hxx"

/**
 **********************************************************************
 *  Class: cFileHandleT
 *
 * Author: $author$
 *   Date: 11/23/2005
 **********************************************************************
 */
template<class TIs=cBase>
class cFileHandleT
: public cOpenedHandleT<FILE*, 0, TIs>
{
public:
    typedef cOpenedHandleT<FILE*, 0, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cFileHandleT
     *
     *      Author: $author$
     *        Date: 11/23/2005
     **********************************************************************
     */
    cFileHandleT(FILE *file=0, bool opened=false) 
    : cIs(file, opened) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cFileHandleT
     *
     *      Author: $author$
     *        Date: 11/23/2005
     **********************************************************************
     */
    virtual ~cFileHandleT()
    {
        eError error;

        if (m_opened)
        if ((error = Close()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    eError Close() 
    {
        eError error = e_ERROR_NONE;
        int err;

        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (!m_opened)
            return e_ERROR_NOT_OPEN;

        if ((err = fclose(m_handle)))
            return e_ERROR_CLOSE;

        m_opened = false;
        m_handle = 0;
        return error;
    }
};

#endif /* _CFILEHANDLET_HXX */
