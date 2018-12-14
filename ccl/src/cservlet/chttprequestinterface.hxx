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
 *   File: chttprequestinterface.hxx
 *
 * Author: $author$
 *   Date: 10/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPREQUESTINTERFACE_HXX
#define _CHTTPREQUESTINTERFACE_HXX

#include "ccontentrequestinterface.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequestInterfaceT
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
template <class TIs=cContentRequestInterface>
class c_INTERFACE_CLASS cHttpRequestInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: SetMethod
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual int SetMethod(int method) = 0;
    /**
     **********************************************************************
     * Function: SetPathInfo
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual int SetPathInfo
    (const char* buf,  int len=-1) = 0;
    /**
     **********************************************************************
     * Function: SetIsChunkedContent
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual bool SetIsChunkedContent(bool is=true) = 0;
    /**
     **********************************************************************
     * Function: ClearHeaders
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual eError ClearHeaders() = 0;
    /**
     **********************************************************************
     * Function: AddHeader
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual eError AddHeader
    (const char *name,  int namelen=-1,
     const char *value=0, int valuelen=-1) = 0;
    /**
     **********************************************************************
     * Function: SetHeaderChars
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual int SetHeaderChars
    (const char* chars,  int length=-1) = 0;
};

/**
 **********************************************************************
 *  Class: cHttpRequestInterface
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cHttpRequestInterface
: virtual public cHttpRequestInterfaceT<>
{
public:
};

#endif /* ndef _CHTTPREQUESTINTERFACE_HXX */
