///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
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
///   File: XosMutex.hpp
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSMUTEX_HPP
#define _XOSMUTEX_HPP

#include "XosPlatform.hpp"

#if defined(WINDOWS) 
// Windows 
#include "XosWinMutex.hpp"
#else // defined(WINDOWS) 
// Unix 
#include "XosPThreadMutex.hpp"
#endif // defined(WINDOWS) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosMutexImplement
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
#if defined(WINDOWS) 
// Windows 
typedef XosWinMutexImplement
#else // defined(WINDOWS) 
// Unix 
typedef XosPThreadMutexImplement
#endif // defined(WINDOWS) 
XosMutexImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosMutexExtend
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
#if defined(WINDOWS) 
// Windows 
typedef XosWinMutex
#else // defined(WINDOWS) 
// Unix 
typedef XosPThreadMutex
#endif // defined(WINDOWS) 
XosMutexExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosMutex
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosMutex
: virtual public XosMutexImplement,
  public XosMutexExtend
{
public:
    typedef XosMutexImplement Implements;
    typedef XosMutexExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosMutex
    ///
    ///       Author: $author$
    ///         Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    XosMutex
    (bool create=false,
     bool initiallyLocked=false)
    : Extends(create, initiallyLocked)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosMutex
    ///
    ///      Author: $author$
    ///        Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosMutex()
    {
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSMUTEX_HPP 
        

