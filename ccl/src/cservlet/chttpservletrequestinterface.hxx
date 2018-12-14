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
 *   File: chttpservletrequestinterface.hxx
 *
 * Author: $author$
 *   Date: 10/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPSERVLETREQUESTINTERFACE_HXX
#define _CHTTPSERVLETREQUESTINTERFACE_HXX

#include "cservletrequestinterface.hxx"

/**
 **********************************************************************
 *  Class: cHttpServletRequestInterfaceT
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
template <class TIs=cServletRequestInterface>
class c_INTERFACE_CLASS cHttpServletRequestInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: GetMethod
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual int GetMethod() const = 0;
    /**
     **********************************************************************
     * Function: GetMethodName
     *
     *   Author: $author$
     *     Date: 5/24/2014
     **********************************************************************
     */
    virtual const char* GetMethodName() const = 0;
    /**
     **********************************************************************
     * Function: GetPathInfo
     *
     *   Author: $author$
     *     Date: 5/24/2014
     **********************************************************************
     */
    virtual const char* GetPathInfo() const = 0;
    /**
     **********************************************************************
     * Function: GetPathInfo
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual const char* GetPathInfo(int &length) const = 0;
    /**
     **********************************************************************
     * Function: IsChunkedContent
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual bool IsChunkedContent() const = 0;
    /**
     **********************************************************************
     * Function: GetHeader
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual const char* GetHeader
    (int &valuelen, const char *name, int namelen=-1) const = 0;
    /**
     **********************************************************************
     * Function: GetHeaderByType
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual const char* GetHeaderByType
    (int &valuelen, int type) const = 0;
    /**
     **********************************************************************
     * Function: GetHeaderChars
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual const char* GetHeaderChars(int &length) const = 0;
    /**
     **********************************************************************
     * Function: GetHeaderBytes
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual const BYTE* GetHeaderBytes(int &length) const = 0;
};

/**
 **********************************************************************
 *  Class: cHttpServletRequestInterface
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cHttpServletRequestInterface
: virtual public cHttpServletRequestInterfaceT<>
{
public:
};

#endif /* ndef _CHTTPSERVLETREQUESTINTERFACE_HXX */
