/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: chttprequestinterface.hxx
 *
 * Author: $author$
 *   Date: 2/24/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPREQUESTINTERFACE_HXX
#define _CHTTPREQUESTINTERFACE_HXX

#include "cinputstreaminterface.hxx"
#include "cinitializerinterface.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequestInterfaceT
 *
 * Author: $author$
 *   Date: 2/24/2006
 **********************************************************************
 */
template
<class TIs=cInitializerInterface>

class c_INTERFACE_CLASS cHttpRequestInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: SetContentType
     *
     *   Author: $author$
     *     Date: 2/24/2006
     **********************************************************************
     */
    virtual int SetContentType
    (const char* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetContentType
     *
     *   Author: $author$
     *     Date: 2/24/2006
     **********************************************************************
     */
    virtual const char* GetContentType
    (int& length) const = 0;

    /**
     **********************************************************************
     * Function: SetContentLength
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int SetContentLength
    (int length) = 0;
    /**
     **********************************************************************
     * Function: GetContentLength
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int GetContentLength() const = 0;

    /**
     **********************************************************************
     * Function: SetIsChunkedContent
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int SetIsChunkedContent
    (bool is=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsChunkedContent
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual bool GetIsChunkedContent() const = 0;

    /**
     **********************************************************************
     * Function: SetMethod
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int SetMethod
    (int method) = 0;
    /**
     **********************************************************************
     * Function: GetMethod
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int GetMethod() const = 0;

    /**
     **********************************************************************
     * Function: SetPathInfo
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int SetPathInfo
    (const char* chars=0,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetPathInfo
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual const char* GetPathInfo
    (int& length) const = 0;

    /**
     **********************************************************************
     * Function: SetServerName
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int SetServerName
    (const char* chars=0,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetServerName
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual const char* GetServerName
    (int& length) const = 0;

    /**
     **********************************************************************
     * Function: SetServerPort
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int SetServerPort
    (int port) = 0;
    /**
     **********************************************************************
     * Function: GetServerPort
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int GetServerPort() const = 0;

    /**
     **********************************************************************
     * Function: SetContentIsConsumed
     *
     *   Author: $author$
     *     Date: 2/27/2006
     **********************************************************************
     */
    virtual int SetContentIsConsumed(bool is=true) = 0;
    /**
     **********************************************************************
     * Function: GetContentIsConsumed
     *
     *   Author: $author$
     *     Date: 2/27/2006
     **********************************************************************
     */
    virtual bool GetContentIsConsumed() const = 0;

    /**
     **********************************************************************
     * Function: SetContentInputStream
     *
     *   Author: $author$
     *     Date: 2/27/2006
     **********************************************************************
     */
    virtual cInputStreamInterface* SetContentInputStream
    (cInputStreamInterface* input) = 0;
    /**
     **********************************************************************
     * Function: GetContentInputStream
     *
     *   Author: $author$
     *     Date: 2/27/2006
     **********************************************************************
     */
    virtual cInputStreamInterface& GetContentInputStream() const = 0;
};

/**
 **********************************************************************
 *  Class: cHttpRequestInterface
 *
 * Author: $author$
 *   Date: 2/24/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cHttpRequestInterface
: virtual public cHttpRequestInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cHttpRequestImplementT
 *
 * Author: $author$
 *   Date: 2/24/2006
 **********************************************************************
 */
template
<class TIs=cHttpRequestInterface>
class cHttpRequestImplementT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: SetContentType
     *
     *   Author: $author$
     *     Date: 2/24/2006
     **********************************************************************
     */
    virtual int SetContentType
    (const char* chars,
     int length=-1) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: GetContentType
     *
     *   Author: $author$
     *     Date: 2/24/2006
     **********************************************************************
     */
    virtual const char* GetContentType
    (int& length) const 
    {
        const char* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetContentLength
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int SetContentLength
    (int length) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: GetContentLength
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int GetContentLength() const 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }

    /**
     **********************************************************************
     * Function: SetIsChunkedContent
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int SetIsChunkedContent
    (bool is=true) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: GetIsChunkedContent
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual bool GetIsChunkedContent() const 
    {
        bool is = false;
        return is;
    }

    /**
     **********************************************************************
     * Function: SetMethod
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int SetMethod
    (int method) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: GetMethod
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int GetMethod() const 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }

    /**
     **********************************************************************
     * Function: SetPathInfo
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int SetPathInfo
    (const char* chars=0,
     int length=-1) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: GetPathInfo
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual const char* GetPathInfo
    (int& length) const 
    {
        const char* chars = 0;
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetServerName
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int SetServerName
    (const char* chars=0,
     int length=-1) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: GetServerName
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual const char* GetServerName
    (int& length) const 
    {
        const char* chars = 0;
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetServerPort
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int SetServerPort
    (int port) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: GetServerPort
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int GetServerPort() const 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }

    /**
     **********************************************************************
     * Function: SetContentIsConsumed
     *
     *   Author: $author$
     *     Date: 2/27/2006
     **********************************************************************
     */
    virtual int SetContentIsConsumed(bool is=true) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: GetContentIsConsumed
     *
     *   Author: $author$
     *     Date: 2/27/2006
     **********************************************************************
     */
    virtual bool GetContentIsConsumed() const 
    {
        bool is = false;
        return is;
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestImplement
 *
 * Author: $author$
 *   Date: 2/24/2006
 **********************************************************************
 */
class cHttpRequestImplement
: virtual public cHttpRequestImplementT<>
{
public:
};

#endif /* _CHTTPREQUESTINTERFACE_HXX */


