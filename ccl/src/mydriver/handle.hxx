/*
 ************************************************************
 *
 *    $Id$
 *
 *   file: handle.hxx
 * 
 * author: $author$
 *   date: 4/4/2003
 *
 * This file provides a class wrapper to handle objects
 * created by other means such as opening a file.
 ************************************************************
 */

#ifndef _HANDLE_HXX
#define _HANDLE_HXX

#include "error.hxx"

/*
 ************************************************************
 *
 *  class: HandleBase
 * 
 * author: $author$
 *   date: 4/4/2003
 *
 * This is an empty base class for Handle.
 ************************************************************
 */
class HandleBase
{
};

/*
 ************************************************************
 *
 *  class: HandleT
 * 
 * author: $author$
 *   date: 4/4/2003
 *
 ************************************************************
 */
template <class THandle, int VNull=0, class TIs=HandleBase>
class HandleT: public TIs
{
protected:
    THandle m_handle;
    
public:
    typedef TIs Is;

    /*
     ************************************************************
     *
     * function: HandleT
     * 
     *   author: $author$
     *     date: 4/4/2003
     *
     ************************************************************
     */
    HandleT(THandle handle=((THandle)VNull))
    : m_handle(handle)
    {
    }
    /*
     ************************************************************
     *
     * function: ~HandleT
     * 
     *   author: $author$
     *     date: 4/4/2003
     *
     ************************************************************
     */
    virtual ~HandleT()
    {
    }
    /*
     ************************************************************
     *
     * function: Attach
     * 
     *   author: $author$
     *     date: 4/4/2003
     *
     ************************************************************
     */
    virtual Error Attach(THandle handle)
    {
        if (((THandle)VNull) != m_handle)
            return ENUM_ERROR_ALREADY_ATTACHED;
            
        m_handle=handle;
        return ENUM_ERROR_NONE;
    }
    /*
     ************************************************************
     *
     * function: Detach
     * 
     *   author: $author$
     *     date: 4/4/2003
     *
     ************************************************************
     */
    virtual Error Detach(THandle &handle)
    {
        if (((THandle)VNull) == m_handle)
            return ENUM_ERROR_NOT_ATTACHED;
        
        handle=m_handle;
        m_handle=VNull;
        return ENUM_ERROR_NONE;
    }
    /*
     ************************************************************
     *
     * function: Detach
     * 
     *   author: $author$
     *     date: 4/4/2003
     *
     ************************************************************
     */
    inline Error Detach(void)
    {
        THandle handle;
        return Detach(handle);
    }
    /*
     ************************************************************
     *
     * function: GetHandle
     * 
     *   author: $author$
     *     date: 4/4/2003
     *
     ************************************************************
     */
    inline THandle GetHandle(void)
    {
        return m_handle;
    };
};

/*
 ************************************************************
 *
 *  class: OpenedHandleT
 * 
 * author: $author$
 *   date: 4/4/2003
 *
 ************************************************************
 */
template 
<class THandle, int VNull=0,
 class TError=int, TError VNone=0, class TIs=HandleBase>
class OpenedHandleT: public HandleT<THandle, VNull, TIs>
{
public:
    typedef HandleT<THandle, VNull, TIs> Is;

    /*
     ************************************************************
     *
     * function: OpenedHandleT
     * 
     *   author: $author$
     *     date: 4/4/2003
     *
     ************************************************************
     */
    OpenedHandleT(THandle handle=((THandle)VNull))
    : Is(handle)
    {
    }
    /*
     ************************************************************
     *
     * function: ~OpenedHandleT
     * 
     *   author: $author$
     *     date: 4/4/2003
     *
     ************************************************************
     */
    virtual ~OpenedHandleT()
    {
        TError error;
        
        if (((THandle)VNull) != m_handle)
        if ((error = Close()) != VNone)
            throw(error);
    }
    /*
     ************************************************************
     *
     * function: Close
     * 
     *   author: $author$
     *     date: 4/4/2003
     *
     ************************************************************
     */
    virtual TError Close(void)
    {
        return VNone;
    }
};
#endif
