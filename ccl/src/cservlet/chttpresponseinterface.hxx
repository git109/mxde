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
 *   File: chttpresponseinterface.hxx
 *
 * Author: $author$
 *   Date: 10/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPRESPONSEINTERFACE_HXX
#define _CHTTPRESPONSEINTERFACE_HXX

#include "ccontentresponseinterface.hxx"
#include "ccharwriterinterface.hxx"
#include "chttp11header.hxx"

/**
 **********************************************************************
 *  Class: cHttpResponseInterfaceT
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
template <class TIs=cContentResponseInterface>
class c_INTERFACE_CLASS cHttpResponseInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: GetStatus
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    virtual eHttpResponseHeaderStatus GetStatus() const = 0;
    /**
     **********************************************************************
     * Function: SetIsChunkedContent
     *
     *   Author: $author$
     *     Date: 11/14/2004
     **********************************************************************
     */
    virtual bool SetIsChunkedContent(bool is=true) = 0;
    /**
     **********************************************************************
     * Function: IsChunkedContent
     *
     *   Author: $author$
     *     Date: 11/14/2004
     **********************************************************************
     */
    virtual bool IsChunkedContent() const = 0;
};

/**
 **********************************************************************
 *  Class: cHttpResponseInterface
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cHttpResponseInterface
: virtual public cHttpResponseInterfaceT<>
{
public:
};

#endif /* ndef _CHTTPRESPONSEINTERFACE_HXX */
