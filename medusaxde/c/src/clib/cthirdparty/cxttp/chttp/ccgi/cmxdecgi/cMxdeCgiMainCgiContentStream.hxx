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
 *   File: cMxdeCgiMainCgiContentStream.hxx
 *
 * Author: $author$
 *   Date: 9/13/2011
 **********************************************************************
 */
#if !defined(_CMXDECGIMAINCGICONTENTSTREAM_HXX) || defined(CMXDECGIMAINCGICONTENTSTREAM_MEMBERS_ONLY)
#if !defined(_CMXDECGIMAINCGICONTENTSTREAM_HXX) && !defined(CMXDECGIMAINCGICONTENTSTREAM_MEMBERS_ONLY)
#define _CMXDECGIMAINCGICONTENTSTREAM_HXX
#endif /* !defined(_CMXDECGIMAINCGICONTENTSTREAM_HXX) && !defined(CMXDECGIMAINCGICONTENTSTREAM_MEMBERS_ONLY) */

#if !defined(CMXDECGIMAINCGICONTENTSTREAM_MEMBERS_ONLY)
#include "cMxdeCgiMainContentStream.hxx"
#include "cCgiContentStream.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cMxdeCgiMainCgiContentStreamExtend
 *
 *  Author: $author$
 *    Date: 9/13/2011
 **********************************************************************
 */
typedef cCgiContentStream
cMxdeCgiMainCgiContentStreamExtend;
/**
 **********************************************************************
 *  Class: cMxdeCgiMainCgiContentStream
 *
 * Author: $author$
 *   Date: 9/13/2011
 **********************************************************************
 */
class c_INSTANCE_CLASS cMxdeCgiMainCgiContentStream
: //virtual public cMxdeCgiMainCgiContentStreamImplement,
  public cMxdeCgiMainCgiContentStreamExtend
{
public:
    //typedef cMxdeCgiMainCgiContentStreamImplement cImplements;
    typedef cMxdeCgiMainCgiContentStreamExtend cExtends;

    cMxdeCgiMainContentStream& m_content;

    /**
     **********************************************************************
     *  Constructor: cMxdeCgiMainCgiContentStream
     *
     *       Author: $author$
     *         Date: 9/13/2011
     **********************************************************************
     */
    cMxdeCgiMainCgiContentStream
    (cMxdeCgiMainContentStream& content)
    : m_content(content)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cMxdeCgiMainCgiContentStream
     *
     *      Author: $author$
     *        Date: 9/13/2011
     **********************************************************************
     */
    virtual ~cMxdeCgiMainCgiContentStream()
    {
    }
#else /* !defined(CMXDECGIMAINCGICONTENTSTREAM_MEMBERS_ONLY) */
#endif /* !defined(CMXDECGIMAINCGICONTENTSTREAM_MEMBERS_ONLY) */

#if !defined(CMXDECGIMAINCGICONTENTSTREAM_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: SetContentType
     *
     *    Author: $author$
     *      Date: 9/13/2011
     **********************************************************************
     */
    virtual ssize_t SetContentType
    (const cString& contentType)
    {
        ssize_t count = m_content.SetContentType(contentType.Chars());
        return count;
    }
    /**
     **********************************************************************
     *  Function: Write
     *
     *    Author: $author$
     *      Date: 9/13/2011
     **********************************************************************
     */
    virtual ssize_t Write
    (const char* chars, ssize_t length=-1)
    {
        ssize_t count = m_content.Write(chars, length);
        return count;
    }
    /**
     **********************************************************************
     *  Function: WriteFormattedV
     *
     *    Author: $author$
     *      Date: 9/13/2011
     **********************************************************************
     */
    virtual ssize_t WriteFormattedV
    (const char_t* format, va_list va)
    {
        ssize_t count = m_content.WriteFormattedV(format, va);
        return count;
    }
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CMXDECGIMAINCGICONTENTSTREAM_MEMBERS_ONLY) */
#endif /* !defined(CMXDECGIMAINCGICONTENTSTREAM_MEMBERS_ONLY) */

#endif /* !defined(_CMXDECGIMAINCGICONTENTSTREAM_HXX) || defined(CMXDECGIMAINCGICONTENTSTREAM_MEMBERS_ONLY) */
        

