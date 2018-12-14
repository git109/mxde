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
 *   File: cbytestreamconnectioninterface.hxx
 *
 * Author: $author$
 *   Date: 9/11/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTESTREAMCONNECTIONINTERFACE_HXX
#define _CBYTESTREAMCONNECTIONINTERFACE_HXX

#include "cconnectioninterface.hxx"
#include "cbytestreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cBYTEStreamConnectionInterfaceT
 *
 * Author: $author$
 *   Date: 9/11/2005
 **********************************************************************
 */
template
<class TIs=cConnectionInterface>
class c_INTERFACE_CLASS cBYTEStreamConnectionInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: GetStream
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual cBYTEStreamInterface& GetStream() const = 0;
};

/**
 **********************************************************************
 *  Class: cBYTEStreamConnectionInterface
 *
 * Author: $author$
 *   Date: 9/11/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEStreamConnectionInterface
: public cBYTEStreamConnectionInterfaceT<>
{
public:
    typedef cBYTEStreamConnectionInterfaceT<> cIs;
};

#endif /* _CBYTESTREAMCONNECTIONINTERFACE_HXX */
