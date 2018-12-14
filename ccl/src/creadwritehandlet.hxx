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
 *   File: creadwritehandlet.hxx
 *
 * Author: $author$
 *   Date: 6/9/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CREADWRITEHANDLET_HXX
#define _CREADWRITEHANDLET_HXX

#include "cerror.h"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cReadWriteHandleT
 *
 * Author: $author$
 *   Date: 6/9/2004
 **********************************************************************
 */
template <class THandle, int VNull=0, class TIs=cBase>
class cReadWriteHandleT
: public TIs
{
protected:
    THandle m_read_handle, m_write_handle;
    
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     * Constructor: cReadWriteHandleT
     *
     *      Author: $author$
     *        Date: 6/9/2004
     **********************************************************************
     */
    cReadWriteHandleT
    (THandle read_handle=((THandle)VNull),
     THandle write_handle=((THandle)VNull))
    : m_read_handle(read_handle),
      m_write_handle(write_handle)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cReadWriteHandleT
     *
     *     Author: $author$
     *       Date: 6/9/2004
     **********************************************************************
     */
    virtual ~cReadWriteHandleT()
    {
    }

    /**
     **********************************************************************
     * Function: AttachRead
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual eError AttachRead(THandle handle)
    {
        m_read_handle=handle;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: DetachRead
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual eError DetachRead()
    {
        if (((THandle)VNull) == m_read_handle)
            return e_ERROR_NOT_ATTACHED;
        
        m_read_handle=(THandle)VNull;
        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: AttachWrite
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual eError AttachWrite(THandle handle)
    {
        m_write_handle=handle;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: DetachWrite
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual eError DetachWrite()
    {
        if (((THandle)VNull) == m_write_handle)
            return e_ERROR_NOT_ATTACHED;
        
        m_write_handle=(THandle)VNull;
        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: GetReadHandle
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    inline THandle GetReadHandle() const
    {
        return m_read_handle;
    };
    /**
     **********************************************************************
     * Function: GetWriteHandle
     *
     *   Author: $author$
     *     Date: 6/9/2006
     **********************************************************************
     */
    inline THandle GetWriteHandle() const
    {
        return m_write_handle;
    };
};

#endif /* ndef _CREADWRITEHANDLET_HXX */
