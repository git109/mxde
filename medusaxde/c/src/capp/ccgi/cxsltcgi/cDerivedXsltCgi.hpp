///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cDerivedXsltCgi.hpp
//
// Author: $author$
//   Date: 11/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CDERIVEDXSLTCGI_HPP) || defined(_MEMBERS_ONLY)
#if !defined(_CDERIVEDXSLTCGI_HPP) && !defined(_MEMBERS_ONLY)
#define _CDERIVEDXSLTCGI_HPP
#endif // !defined(_CDERIVEDXSLTCGI_HPP) && !defined(_MEMBERS_ONLY) 

#if !defined(_MEMBERS_ONLY)

#if !defined(CXSLTCGIBASE_NAME) 
#define CXSLTCGIBASE_NAME "cXsltCgi"
#else // !defined(CXSLTCGIBASE_NAME) 
#endif // !defined(CXSLTCGIBASE_NAME) 

#if !defined(CXSLTCGI_NAME) 
#define CXSLTCGI_NAME "cXsltCgi"
#else // !defined(CXSLTCGI_NAME) 
#endif // !defined(CXSLTCGI_NAME) 

#if !defined(CXSLTCGI_PATH) 
#define CXSLTCGI_PATH \
    "/medusaxde/xsl" \
    CXSLTCGI_PATH_SEPARATOR \
    CXSLTCGIBASE_NAME
#else // !defined(CXSLTCGI_PATH) 
#endif // !defined(CXSLTCGI_PATH) 

#if !defined(CXSLTCGI_FILEPATH) 
#define CXSLTCGI_FILEPATH \
    "../../../../../mxde/medusaxde/doc/xsl" \
    CXSLTCGI_FILEPATH_SEPARATOR
#else // !defined(CXSLTCGI_FILEPATH) 
#endif // !defined(CXSLTCGI_FILEPATH) 

#if !defined(CXSLTCGI_XSLT_FILEPATH) 
#define CXSLTCGI_XSLT_FILEPATH \
    CXSLTCGI_FILEPATH \
    CXSLTCGIBASE_NAME \
    CXSLTCGI_FILEPATH_SEPARATOR
#else // !defined(CXSLTCGI_XSLT_FILEPATH) 
#endif // !defined(CXSLTCGI_XSLT_FILEPATH) 

#if !defined(CXSLTCGI_XML_FILEPATH) 
#define CXSLTCGI_XML_FILEPATH \
    CXSLTCGI_FILEPATH
#else // !defined(CXSLTCGI_XML_FILEPATH) 
#endif // !defined(CXSLTCGI_XML_FILEPATH) 

#if !defined(CXSLTCGI_XML_FILEBASE) 
#define CXSLTCGI_XML_FILEBASE "medusaxde"
#else // !defined(CXSLTCGI_XML_FILEBASE) 
#endif // !defined(CXSLTCGI_XML_FILEBASE) 

#include "cXsltCgi.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(_MEMBERS_ONLY) 
#endif // !defined(_MEMBERS_ONLY) 

#endif // !defined(_CDERIVEDXSLTCGI_HPP) || defined(_MEMBERS_ONLY) 
