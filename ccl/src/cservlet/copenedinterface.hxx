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
 *   File: copenedinterface.hxx
 *
 * Author: $author$
 *   Date: 10/15/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _COPENEDINTERFACE_HXX
#define _COPENEDINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cOpenedInterfaceT
 *
 * Author: $author$
 *   Date: 10/15/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cOpenedInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 10/15/2004
     **********************************************************************
     */
    virtual eError Close() = 0;

    /**
     **********************************************************************
     * Function: SetIsOpen
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual bool SetIsOpen(bool opened=true) = 0;
    /**
     **********************************************************************
     * Function: IsOpen
     *
     *   Author: $author$
     *     Date: 10/15/2004
     **********************************************************************
     */
    virtual bool IsOpen() const = 0;
    /**
     **********************************************************************
     * Function: SetIsClosed
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual bool SetIsClosed(bool closed=true) = 0;
    /**
     **********************************************************************
     * Function: IsClosed
     *
     *   Author: $author$
     *     Date: 10/15/2004
     **********************************************************************
     */
    virtual bool IsClosed() const = 0;
};

/**
 **********************************************************************
 *  Class: cOpenedInterface
 *
 * Author: $author$
 *   Date: 10/16/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cOpenedInterface
: virtual public cOpenedInterfaceT<cInterface>
{
public:
};

/**
 **********************************************************************
 *  Class: cOpenedImplementT
 *
 * Author: $author$
 *   Date: 10/15/2004
 **********************************************************************
 */
template <class TIs=cOpenedInterface>
class cOpenedImplementT
: virtual public TIs
{
public:
    bool m_opened;

    /**
     **********************************************************************
     * Constructor: cOpenedImplementT
     *
     *      Author: $author$
     *        Date: 10/15/2004
     **********************************************************************
     */
    cOpenedImplementT(bool opened=false)
    : m_opened(opened)
    {
    }

    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 10/15/2004
     **********************************************************************
     */
    virtual eError Close() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: SetIsOpen
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual bool SetIsOpen(bool opened=true) 
    {
        bool is = m_opened;
        m_opened = opened;
        return is;
    }
    /**
     **********************************************************************
     * Function: IsOpen
     *
     *   Author: $author$
     *     Date: 10/15/2004
     **********************************************************************
     */
    virtual bool IsOpen() const
    {
        bool is = m_opened;
        return is;
    }

    /**
     **********************************************************************
     * Function: SetIsClosed
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual bool SetIsClosed(bool closed=true) 
    {
        bool is = !m_opened;
        m_opened = !closed;
        return is;
    }
    /**
     **********************************************************************
     * Function: IsClosed
     *
     *   Author: $author$
     *     Date: 10/15/2004
     **********************************************************************
     */
    virtual bool IsClosed() const
    {
        bool is = !m_opened;
        return is;
    }
};

/**
 **********************************************************************
 *  Class: cOpenedImplement
 *
 * Author: $author$
 *   Date: 10/16/2004
 **********************************************************************
 */
class cOpenedImplement
: virtual public cOpenedImplementT<>
{
public:
    typedef cOpenedImplementT<> cIs;

    /**
     **********************************************************************
     * Constructor: cOpenedImplement
     *
     *      Author: $author$
     *        Date: 10/16/2004
     **********************************************************************
     */
    cOpenedImplement(bool opened=false)
    : cIs(opened) 
    {
    }
};

#endif /* ndef _COPENEDINTERFACE_HXX */
