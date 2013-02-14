///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2011 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: XosError.hpp
///
/// Author: $author$
///   Date: 11/22/2011
///////////////////////////////////////////////////////////////////////
#ifndef _XOSERROR_HPP
#define _XOSERROR_HPP

#include "XosPlatform.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///    Enum: XosError
///
///  Author: $author$
///    Date: 11/22/2011
///////////////////////////////////////////////////////////////////////
typedef int XosError;
enum
{
    XOS_ERROR_NONE = 0,
    XOS_ERROR_FAILED = 1,
	XOS_ERROR_NOT_IMPLEMENTED,
	XOS_ERROR_NOT_ALLOWED,
	XOS_ERROR_NOT_ATTACHED,
    XOS_ERROR_NULL_PARAMETER,
    XOS_ERROR_NEW,
    XOS_ERROR_DELETE,

    XOS_NEXT_ERROR,
    XOS_FIRST_ERROR = XOS_ERROR_NONE,
    XOS_LAST_ERROR = (XOS_NEXT_ERROR - 1)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSERROR_HPP 
        

