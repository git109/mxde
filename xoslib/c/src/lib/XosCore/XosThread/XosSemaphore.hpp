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
///   File: XosSemaphore.hpp
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSSEMAPHORE_HPP
#define _XOSSEMAPHORE_HPP

#include "XosPlatform.hpp"

#if defined(WINDOWS) 
// Windows 
#include "XosWinSemaphore.hpp"
#else // defined(WINDOWS) 
// Unix 
#if defined(MACOSX) 
// Mac OSX 
#include "XosMachSemaphore.hpp"
#else // defined(MACOSX) 
// Otherwise 
#include "XosPThreadSemaphore.hpp"
#endif // defined(MACOSX) 
#endif // defined(WINDOWS) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosSemaphoreImplement
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
#if defined(WINDOWS) 
// Windows 
typedef XosWinSemaphoreImplement
#else // defined(WINDOWS) 
// Unix 
#if defined(MACOSX) 
// Mac OSX 
typedef XosMachSemaphoreImplement
#else // defined(MACOSX) 
// Otherwise 
typedef XosPThreadSemaphoreImplement
#endif // defined(MACOSX) 
#endif // defined(WINDOWS) 
XosSemaphoreImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosSemaphoreExtend
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
#if defined(WINDOWS) 
// Windows 
typedef XosWinSemaphore
#else // defined(WINDOWS) 
// Unix 
#if defined(MACOSX) 
// Mac OSX 
typedef XosMachSemaphore
#else // defined(MACOSX) 
// Otherwise 
typedef XosPThreadSemaphore
#endif // defined(MACOSX) 
#endif // defined(WINDOWS) 
XosSemaphoreExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosSemaphore
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosSemaphore
: virtual public XosSemaphoreImplement,
  public XosSemaphoreExtend
{
public:
    typedef XosSemaphoreImplement Implements;
    typedef XosSemaphoreExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosSemaphore
    ///
    ///       Author: $author$
    ///         Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    XosSemaphore
    (bool create=false,
     int initiallyReleased=0)
    : Extends(create, initiallyReleased)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosSemaphore
    ///
    ///      Author: $author$
    ///        Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosSemaphore()
    {
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSSEMAPHORE_HPP 
        

