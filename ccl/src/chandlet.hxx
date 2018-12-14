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
 *   File: chandlet.hxx
 *
 * Author: $author$
 *   Date: 7/3/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHANDLET_HXX
#define _CHANDLET_HXX

#include "cerror.h"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cHandleT
 *
 * Author: $author$
 *   Date: 7/3/2003
 **********************************************************************
 */
template <class THandle, int VNull=0, class TIs=cBase>
class cHandleT
: public TIs
{
protected:
    
public:
    typedef TIs cIs;
    typedef THandle tHandle;

    THandle m_handle;
    /**
     **********************************************************************
     * Constructor: cHandleT
     *
     *      Author: $author$
     *        Date: 7/3/2003
     **********************************************************************
     */
    cHandleT(THandle handle=((THandle)VNull))
    : m_handle(handle) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cHandleT
     *
     *     Author: $author$
     *       Date: 7/3/2003
     **********************************************************************
     */
    virtual ~cHandleT()
    {
        eError error;
        
        if (((THandle)VNull) != m_handle)
        if ((error = Detach()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 7/3/2003
     **********************************************************************
     */
    virtual eError Attach(THandle handle)
    {
        m_handle=handle;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 7/3/2003
     **********************************************************************
     */
    virtual eError Detach(THandle &handle)
    {
        if (((THandle)VNull) == m_handle)
            return e_ERROR_NOT_ATTACHED;
        
        handle=m_handle;
        m_handle=(THandle)VNull;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 7/3/2003
     **********************************************************************
     */
    virtual eError Detach()
    {
        if (((THandle)VNull) == m_handle)
            return e_ERROR_NOT_ATTACHED;
        
        m_handle=(THandle)VNull;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: SetIsAttached
     *
     *   Author: $author$
     *     Date: 4/3/2004
     **********************************************************************
     */
    virtual bool SetIsAttached(bool is_attached=true)
    {
        return false;
    }
    /**
     **********************************************************************
     * Function: GetIsAttached
     *
     *   Author: $author$
     *     Date: 11/16/2003
     **********************************************************************
     */
    virtual bool GetIsAttached() const
    {
        return (((THandle)VNull) != m_handle);
    }

    /**
     **********************************************************************
     * Function: GetHandle
     *
     *   Author: $author$
     *     Date: 7/3/2003
     **********************************************************************
     */
    inline THandle GetHandle() const
    {
        return m_handle;
    };
};

/**
 **********************************************************************
 *  Class: cOpenedHandleT
 *
 * Author: $author$
 *   Date: 7/3/2003
 **********************************************************************
 */
template <class THandle, int VNull=0, class TIs=cBase>
class cOpenedHandleT
: public cHandleT<THandle, VNull, TIs>
{
public:
    typedef cHandleT<THandle, VNull, TIs> cIs;

    bool m_opened;

    /**
     **********************************************************************
     * Constructor: cOpenedHandleT
     *
     *      Author: $author$
     *        Date: 7/3/2003
     **********************************************************************
     */
    cOpenedHandleT
    (THandle handle=((THandle)VNull), bool opened=false)
    : cIs(handle),
      m_opened(opened)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cOpenedHandleT
     *
     *     Author: $author$
     *       Date: 7/3/2003
     **********************************************************************
     */
    virtual ~cOpenedHandleT()
    {
        eError error;
        
        if (((THandle)VNull) != cIs::m_handle)
        if (m_opened)
        if ((error = Close()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 11/1/2003
     **********************************************************************
     */
    virtual eError Attach(THandle handle, bool opened = false)
    {
        eError error;

        if (m_opened)
            return e_ERROR_ALREADY_OPEN;

        if (!(error = cIs::Attach(handle)))
            m_opened = opened;

        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 7/3/2003
     **********************************************************************
     */
    virtual eError Close()
    {
        if (!m_opened)
            return e_ERROR_NOT_OPEN;

        m_opened = false;
        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: SetIsOpen
     *
     *   Author: $author$
     *     Date: 4/4/2004
     **********************************************************************
     */
    virtual bool SetIsOpen(bool is_open=true)
    {
        return m_opened = is_open;
    }
    /**
     **********************************************************************
     * Function: GetIsOpen
     *
     *   Author: $author$
     *     Date: 11/16/2003
     **********************************************************************
     */
    virtual bool GetIsOpen() const
    {
        return m_opened;
    }
};

/**
 **********************************************************************
 *  Class: cCreatedHandleT
 *
 * Author: $author$
 *   Date: 11/16/2003
 **********************************************************************
 */
template <class THandle, int VNull=0, class TIs=cBase>
class cCreatedHandleT
: public cHandleT<THandle, VNull, TIs>
{
public:
    typedef cHandleT<THandle, VNull, TIs> cIs;

    bool m_created;

    /**
     **********************************************************************
     * Constructor: cCreatedHandleT
     *
     *      Author: $author$
     *        Date: 11/16/2003
     **********************************************************************
     */
    cCreatedHandleT
    (THandle handle=((THandle)VNull), bool created=false)
    : cIs(handle),
      m_created(created) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cCreatedHandleT
     *
     *     Author: $author$
     *       Date: 11/16/2003
     **********************************************************************
     */
    virtual ~cCreatedHandleT()
    {
        eError error;
        
        if (((THandle)VNull) != cIs::m_handle)
        if (m_created)
        if ((error = Destroy()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 11/16/2003
     **********************************************************************
     */
    virtual eError Attach(THandle handle, bool created = false)
    {
        eError error;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (!(error = cIs::Attach(handle)))
            m_created = created;

        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 11/16/2003
     **********************************************************************
     */
    virtual eError Destroy()
    {
        if (!m_created)
            return e_ERROR_NOT_CREATED;

        m_created = false;
        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: SetIsCreated
     *
     *   Author: $author$
     *     Date: 4/3/2004
     **********************************************************************
     */
    virtual bool SetIsCreated(bool is_created=true)
    {
        return m_created = is_created;
    }
    /**
     **********************************************************************
     * Function: GetIsCreated
     *
     *   Author: $author$
     *     Date: 11/16/2003
     **********************************************************************
     */
    virtual bool GetIsCreated() const
    {
        return m_created;
    }
};

/**
 **********************************************************************
 *  Class: cHandleIsHandleT
 *
 * Author: $author$
 *   Date: 1/25/2004
 **********************************************************************
 */
template 
<class THandle, int VNull=0, 
 class TIs=cHandleT<THandle, VNull> >
class cHandleIsHandleT
: public TIs
{
protected:
    THandle m_handle;
    
public:
    typedef TIs cIs;
    typedef cIs cHandleIs;

    /**
     **********************************************************************
     * Constructor: cHandleIsHandleT
     *
     *      Author: $author$
     *        Date: 1/25/2004
     **********************************************************************
     */
    cHandleIsHandleT(THandle handle, bool created)
    : cIs(handle, created),
      m_handle(handle) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cHandleIsHandleT
     *
     *      Author: $author$
     *        Date: 1/25/2004
     **********************************************************************
     */
    cHandleIsHandleT(THandle handle=((THandle)VNull))
    : cIs(handle),
      m_handle(handle) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cHandleIsHandleT
     *
     *     Author: $author$
     *       Date: 1/25/2004
     **********************************************************************
     */
    virtual ~cHandleIsHandleT()
    {
        eError error;

        if (this->GetIsCreated())
        if ((error = this->Destroy()))
            throw(error);

        if (((THandle)VNull) != cIs::m_handle)
        if ((error = Detach()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError Attach(THandle handle)
    {
        eError error;

        if ((error = cIs::Attach(handle)))
            return error;

        m_handle=handle;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError Detach()
    {
        eError error=e_ERROR_NONE;

        if (((THandle)VNull) == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (cIs::GetIsAttached())
            error = cIs::Detach();

        m_handle=(THandle)VNull;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetIsAttached
     *
     *   Author: $author$
     *     Date: 4/3/2004
     **********************************************************************
     */
    virtual bool SetIsAttached(bool is_attached=true)
    {
        return false;
    }
    /**
     **********************************************************************
     * Function: GetIsAttached
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual bool GetIsAttached() const
    {
        return (((THandle)VNull) != m_handle);
    }

    /**
     **********************************************************************
     * Function: GetHandle
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    inline THandle GetHandle() const
    {
        return m_handle;
    };
};

#endif
