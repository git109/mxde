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
 *   File: cbytestreamhandle.hxx
 *
 * Author: $author$
 *   Date: 9/11/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTESTREAMHANDLE_HXX
#define _CBYTESTREAMHANDLE_HXX

#include "cbytestream.hxx"
#include "chandlet.hxx"

/**
 **********************************************************************
 *  Class: cBYTEStreamHandle
 *
 * Author: $author$
 *   Date: 9/11/2005
 **********************************************************************
 */
class cBYTEStreamHandle
: public cHandleT<cBYTEStreamInterface*, 0, cBYTEStream>
{
public:
    typedef cHandleT<cBYTEStreamInterface*, 0, cBYTEStream> cIs;

    /**
     **********************************************************************
     * Constructor: cBYTEStreamHandle
     *
     *      Author: $author$
     *        Date: 9/11/2005
     **********************************************************************
     */
    cBYTEStreamHandle(cBYTEStreamInterface *handle=0) 
    : cIs(handle)
    {
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual int Read
    (BYTE *buffer,  int size=-1) 
    {
        int result = -e_ERROR_NOT_ATTACHED;

        if (m_handle)
            result = m_handle->Read(buffer, size);
        return result;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual int Write
    (const BYTE *buffer,  int size=-1) 
    {
        int result = -e_ERROR_NOT_ATTACHED;

        if (m_handle)
            result = m_handle->Write(buffer, size);
        return result;
    }

    /**
     **********************************************************************
     * Function: WaitWrite
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual int WaitWrite
    (const BYTE *buffer, int size=-1, DWORD miliseconds=0) 
    {
        int result = -e_ERROR_NOT_ATTACHED;

        if (m_handle)
            result = m_handle->WaitWrite(buffer, size, miliseconds);
        return result;
    }
    /**
     **********************************************************************
     * Function: WaitRead
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual int WaitRead
    (BYTE *buffer, int size=-1, DWORD miliseconds=0) 
    {
        int result = -e_ERROR_NOT_ATTACHED;

        if (m_handle)
            result = m_handle->WaitRead(buffer, size, miliseconds);
        return result;
    }

    /**
     **********************************************************************
     * Function: Flush
     *
     *   Author: $author$
     *     Date: 9/13/2003
     **********************************************************************
     */
    virtual int Flush()
    {
        int result = -e_ERROR_NOT_ATTACHED;

        if (m_handle)
            result = m_handle->Flush();
        return result;
    }
};

#endif /* _CBYTESTREAMHANDLE_HXX */