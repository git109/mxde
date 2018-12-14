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
 *   File: cconnectioninterface.hxx
 *
 * Author: $author$
 *   Date: 10/25/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCONNECTIONINTERFACE_HXX
#define _CCONNECTIONINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cConnectionInterfaceT
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cConnectionInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: SetKeepAlive
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual bool SetKeepAlive(bool on=true) = 0;
    /**
     **********************************************************************
     * Function: KeepAlive
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual bool KeepAlive() const = 0;
};

/**
 **********************************************************************
 *  Class: cConnectionInterface
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cConnectionInterface
: virtual public cConnectionInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cConnectionImplementT
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
template <class TIs=cConnectionInterface>
class cConnectionImplementT
: virtual public TIs
{
public:
    bool m_keep_alive_on;

    /**
     **********************************************************************
     * Constructor: cConnectionImplementT
     *
     *      Author: $author$
     *        Date: 10/25/2004
     **********************************************************************
     */
    cConnectionImplementT(bool keep_alive_on=false) 
    : m_keep_alive_on(keep_alive_on)
    {
    }
    /**
     **********************************************************************
     * Function: SetKeepAlive
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual bool SetKeepAlive(bool on=true) 
    {
        m_keep_alive_on = on;
        return m_keep_alive_on;
    }
    /**
     **********************************************************************
     * Function: KeepAlive
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual bool KeepAlive() const
    {
        return m_keep_alive_on;
    }
};

/**
 **********************************************************************
 *  Class: cConnectionImplement
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
class cConnectionImplement
: virtual public cConnectionImplementT<>
{
public:
    typedef cConnectionImplementT<> cIs;

    /**
     **********************************************************************
     * Constructor: cConnectionImplement
     *
     *      Author: $author$
     *        Date: 10/25/2004
     **********************************************************************
     */
    cConnectionImplement(bool keep_alive_on=false) 
    : cIs(keep_alive_on) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cConnectionT
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
template 
<class TInterfaceIs=cConnectionInterface, 
 class TImplementIs=cConnectionImplement, 
 class TIs=cImplement>

class cConnectionT
: virtual public TInterfaceIs,
  virtual public TImplementIs,
  public TIs
{
public:
    typedef TInterfaceIs cInterfaceIs;
    typedef TImplementIs cImplementIs;
    typedef TIs cIs;

    /**
     **********************************************************************
     * Constructor: cConnectionT
     *
     *      Author: $author$
     *        Date: 11/4/2004
     **********************************************************************
     */
    cConnectionT(bool keep_alive_on=false) 
    : cImplementIs(keep_alive_on) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cConnection
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
class cConnection
: public cConnectionT<>
{
public:
    typedef cConnectionT<> cIs;

    /**
     **********************************************************************
     * Constructor: cConnection
     *
     *      Author: $author$
     *        Date: 11/4/2004
     **********************************************************************
     */
    cConnection(bool keep_alive_on=false) 
    : cIs(keep_alive_on) 
    {
    }
};

#endif /* ndef _CCONNECTIONINTERFACE_HXX */
