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
 *   File: cpipeprocess.hxx
 *
 * Author: $author$
 *   Date: 10/31/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CPIPEPROCESS_HXX
#define _CPIPEPROCESS_HXX

#include "cpipe.hxx"
#include "cprocess.hxx"

/**
 **********************************************************************
 *  Class: cPipeProcessT
 *
 * Author: $author$
 *   Date: 10/31/2004
 **********************************************************************
 */
template <class TIs=cProcess>
class cPipeProcessT
: public TIs
{
public:
    typedef TIs cIs;

    cPipe m_in, m_out, m_err;

    /**
     **********************************************************************
     * Constructor: cPipeProcessT
     *
     *      Author: $author$
     *        Date: 10/31/2004
     **********************************************************************
     */
    cPipeProcessT
    (PROCESS process=INVALID_PROCESS, 
     bool opened=false, bool created=false, 
     bool started=false, bool suspended=false,
     HANDLE in_read=INVALID_HANDLE, HANDLE in_write=INVALID_HANDLE,
     HANDLE out_read=INVALID_HANDLE, HANDLE out_write=INVALID_HANDLE,
     HANDLE err_read=INVALID_HANDLE, HANDLE err_write=INVALID_HANDLE) 
    : cIs(process, opened, created, started, suspended),
      m_in(in_read, in_write),
      m_out(out_read, out_write),
      m_err(err_read, err_write)
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 10/31/2004
     **********************************************************************
     */
    virtual eError Create
    (const char *command, 
     bool suspended=false, bool detached=false) 
    {
        eError error = e_ERROR_FAILED;
        HANDLE in, out, err;

        if (m_started)
            return e_ERROR_ALREADY_STARTED;

        if (!(error = m_in.Create()))
        {
            if (!(error = m_out.Create()))
            {
                if (!(error = m_err.Create()))
                {
                    error = e_ERROR_FAILED;

                    if (INVALID_HANDLE != (in = m_in.GetReadHandle()))
                    if (INVALID_HANDLE != (out = m_out.GetWriteHandle()))
                    if (INVALID_HANDLE != (err = m_err.GetWriteHandle()))
                    if (!(error = cIs::Create
                        (command, suspended, detached, in, out, err)))
                    {
                        m_in.CloseRead();
                        m_out.CloseWrite();
                        m_err.CloseWrite();
                        return error;
                    }

                    m_err.Close();
                }
                m_out.Close();
            }
            m_in.Close();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 10/31/2004
     **********************************************************************
     */
    virtual eError Close() 
    {
        eError error = e_ERROR_FAILED;

        cIs::Close();
        m_err.Close();
        m_out.Close();
        m_in.Close();
        return error;
    }

    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 11/1/2004
     **********************************************************************
     */
    virtual size_t Write(const void *buffer, size_t size) 
    {
        size_t result = m_in.Write(buffer, size);
        return result;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/1/2004
     **********************************************************************
     */
    virtual size_t Read(void *buffer, size_t size) 
    {
        size_t result = m_out.Read(buffer, size);
        return result;
    }
    /**
     **********************************************************************
     * Function: ReadErr
     *
     *   Author: $author$
     *     Date: 11/1/2004
     **********************************************************************
     */
    virtual size_t ReadErr(void *buffer, size_t size) 
    {
        size_t result = m_err.Read(buffer, size);
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cPipeProcess
 *
 * Author: $author$
 *   Date: 10/31/2004
 **********************************************************************
 */
class cPipeProcess
: public cPipeProcessT<>
{
public:
    typedef cPipeProcessT<> cIs;

    /**
     **********************************************************************
     * Constructor: cPipeProcess
     *
     *      Author: $author$
     *        Date: 10/31/2004
     **********************************************************************
     */
    cPipeProcess
    (PROCESS process=INVALID_PROCESS,
     bool opened=false, bool created=false, 
     bool started=false, bool suspended=false,
     HANDLE in_read=INVALID_HANDLE, HANDLE in_write=INVALID_HANDLE,
     HANDLE out_read=INVALID_HANDLE, HANDLE out_write=INVALID_HANDLE,
     HANDLE err_read=INVALID_HANDLE, HANDLE err_write=INVALID_HANDLE) 
    : cIs
      (process, opened, created, started, suspended,
       in_read, in_write, out_read, out_write, 
       err_read, err_write) 
    {
    }
};

#endif /* ndef _CPIPEPROCESS_HXX */
