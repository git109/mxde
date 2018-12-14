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
 *   File: ctcplistenerinterface.hxx
 *
 * Author: $author$
 *   Date: 10/19/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTCPLISTENERINTERFACE_HXX
#define _CTCPLISTENERINTERFACE_HXX

#include "cinetsocketinterface.hxx"
#include "cverboseinterface.hxx"

/**
 **********************************************************************
 *  Class: cTcpListenerInterfaceT
 *
 * Author: $author$
 *   Date: 10/19/2004
 **********************************************************************
 */
template <class TIs=cVerboseContainerInterface>
class c_INTERFACE_CLASS cTcpListenerInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Start
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError Start() = 0;
    /**
     **********************************************************************
     * Function: Stop
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError Stop() = 0;
    /**
     **********************************************************************
     * Function: Finish
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError Finish() = 0;
    /**
     **********************************************************************
     * Function: Pause
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError Pause() = 0;
    /**
     **********************************************************************
     * Function: Resume
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError Resume() = 0;
    /**
     **********************************************************************
     * Function: IsConcurrent
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual bool IsConcurrent() const = 0;
    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError Accept
    (cInetSocketInterface &socket) = 0;
};

/**
 **********************************************************************
 *  Class: cTcpListenerInterface
 *
 * Author: $author$
 *   Date: 10/19/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cTcpListenerInterface
: virtual public cTcpListenerInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cTcpListenerImplementT
 *
 * Author: $author$
 *   Date: 11/2/2004
 **********************************************************************
 */
template 
<class TInterfaceIs=cTcpListenerInterface, 
 class TIs=cVerboseContainerImplement>

class cTcpListenerImplementT
: virtual public TInterfaceIs,
  virtual public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     * Constructor: cTcpListenerImplementT
     *
     *      Author: $author$
     *        Date: 11/13/2004
     **********************************************************************
     */
    cTcpListenerImplementT(cVerboseInterface *verbose=0)
    : cIs(verbose)
    {
    }
    /**
     **********************************************************************
     * Function: Start
     *
     *   Author: $author$
     *     Date: 11/2/2004
     **********************************************************************
     */
    virtual eError Start() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Stop
     *
     *   Author: $author$
     *     Date: 11/2/2004
     **********************************************************************
     */
    virtual eError Stop() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finish
     *
     *   Author: $author$
     *     Date: 11/2/2004
     **********************************************************************
     */
    virtual eError Finish() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Pause
     *
     *   Author: $author$
     *     Date: 11/2/2004
     **********************************************************************
     */
    virtual eError Pause() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Resume
     *
     *   Author: $author$
     *     Date: 11/2/2004
     **********************************************************************
     */
    virtual eError Resume() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: IsConcurrent
     *
     *   Author: $author$
     *     Date: 11/2/2004
     **********************************************************************
     */
    virtual bool IsConcurrent() const
    {
        bool is = false;
        return is;
    }
    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 11/2/2004
     **********************************************************************
     */
    virtual eError Accept
    (cInetSocketInterface &socket) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cTcpListenerImplement
 *
 * Author: $author$
 *   Date: 11/2/2004
 **********************************************************************
 */
class cTcpListenerImplement
: virtual public cTcpListenerImplementT<>
{
public:
    typedef cTcpListenerImplementT<> cIs;

    /**
     **********************************************************************
     * Constructor: cTcpListenerImplement
     *
     *      Author: $author$
     *        Date: 11/13/2004
     **********************************************************************
     */
    cTcpListenerImplement(cVerboseInterface *verbose)
    : cIs(verbose)
    {
    }
};

#endif /* ndef _CTCPLISTENERINTERFACE_HXX */
