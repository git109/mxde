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
 *   File: ccharstreamhandle.hxx
 *
 * Author: $author$
 *   Date: 12/5/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CCHARSTREAMHANDLE_HXX
#define _CCHARSTREAMHANDLE_HXX

#include "ccharstream.hxx"
#include "chandlet.hxx"

/**
 **********************************************************************
 *  Class: cCharStreamHandleT
 *
 * Author: $author$
 *   Date: 12/5/2005
 **********************************************************************
 */
template
<class TCharStreamIs=cCharStream,
 class TIs=cCharStream>

class cCharStreamHandleT
: public cOpenedHandleT<TCharStreamIs*,0,TIs>
{
public:
    typedef cOpenedHandleT<TCharStreamIs*,0,TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cCharStreamHandleT
     *
     *      Author: $author$
     *        Date: 12/5/2005
     **********************************************************************
     */
    cCharStreamHandleT
    (TCharStreamIs* handle=0, bool opened=false) 
    : cIs(handle, opened)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cCharStreamHandleT
     *
     *      Author: $author$
     *        Date: 12/5/2005
     **********************************************************************
     */
    virtual ~cCharStreamHandleT()
    {
        eError error;
        bool opened;

        if ((opened = GetIsOpen()))
        if ((error = Close()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 12/5/2005
     **********************************************************************
     */
    virtual int Read(char *buffer, int size)
    {
        int count = -e_ERROR_NOT_ATTACHED;

        if (m_handle)
            count = m_handle->Read(buffer, size);
        return count;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 12/5/2005
     **********************************************************************
     */
    virtual int Write(const char *buffer, int size=-1)
    {
        int count = -e_ERROR_NOT_ATTACHED;

        if (m_handle)
            count = m_handle->Write(buffer, size);
        return count;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 12/5/2005
     **********************************************************************
     */
    virtual eError Close() 
    {
        eError error = e_ERROR_NOT_ATTACHED;

        if (m_handle)
            error = m_handle->Close();
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cCharStreamHandle
 *
 * Author: $author$
 *   Date: 12/5/2005
 **********************************************************************
 */
class cCharStreamHandle
: public cCharStreamHandleT<>
{
public:
    typedef cCharStreamHandleT<> cIs;

    /**
     **********************************************************************
     * Constructor: cCharStreamHandle
     *
     *      Author: $author$
     *        Date: 12/5/2005
     **********************************************************************
     */
    cCharStreamHandle
    (cCharStream* handle=0, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cCharStreamHandle
     *
     *      Author: $author$
     *        Date: 12/5/2005
     **********************************************************************
     */
    virtual ~cCharStreamHandle()
    {
    }
};

#endif /* _CCHARSTREAMHANDLE_HXX */
