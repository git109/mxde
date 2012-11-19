/**
 **********************************************************************
 * Copyright (c) 1988-2011 $organization$
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
 *   File: cMxdeCgiMainContentStream.hxx
 *
 * Author: $author$
 *   Date: 9/16/2011
 **********************************************************************
 */
#ifndef _CMXDECGIMAINCONTENTSTREAM_HXX
#define _CMXDECGIMAINCONTENTSTREAM_HXX

#include "cplatform.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cMxdeCgiMainContentStream
 *
 * Author: $author$
 *   Date: 9/16/2011
 **********************************************************************
 */
class c_INTERFACE_CLASS cMxdeCgiMainContentStream
{
public:
    /**
     **********************************************************************
     *  Function: SetContentType
     *
     *    Author: $author$
     *      Date: 9/16/2011
     **********************************************************************
     */
    virtual ssize_t SetContentType
    (const char* type)
    {
        ssize_t count = 0;
        return count;
    }
    /**
     **********************************************************************
     *  Function: Write
     *
     *    Author: $author$
     *      Date: 9/16/2011
     **********************************************************************
     */
    virtual ssize_t Write
    (const char* chars, ssize_t length=-1)
    {
        ssize_t count = 0;
        return count;
    }
    /**
     **********************************************************************
     *  Function: WriteFormattedV
     *
     *    Author: $author$
     *      Date: 9/16/2011
     **********************************************************************
     */
    virtual ssize_t WriteFormattedV
    (const char* format, va_list va)
    {
        ssize_t count = 0;
        return count;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CMXDECGIMAINCONTENTSTREAM_HXX */
