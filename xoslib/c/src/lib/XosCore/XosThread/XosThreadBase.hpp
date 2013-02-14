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
///   File: XosThreadBase.hpp
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSTHREADBASE_HPP
#define _XOSTHREADBASE_HPP

#include "XosInterfaceBase.hpp"
#include "XosExportBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosThreadBaseImplement
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosInterfaceBase
XosThreadBaseImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosThreadBaseExtend
///
///  Author: $author$
///    Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosExportBase
XosThreadBaseExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosThreadBase
///
/// Author: $author$
///   Date: 3/27/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosThreadBase
: virtual public XosThreadBaseImplement,
  public XosThreadBaseExtend
{
public:
    typedef XosThreadBaseImplement Implements;
    typedef XosThreadBaseExtend Extends;
    enum
    {
        XOS_ERROR_TIMEDOUT = XOS_NEXT_ERROR,
        XOS_ERROR_BUSY,
    };

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosThreadBase
    ///
    ///       Author: $author$
    ///         Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    XosThreadBase
    (bool create=false,
     bool initiallyStopped=false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosThreadBase
    ///
    ///      Author: $author$
    ///        Date: 3/27/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosThreadBase()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Run
    ///
    ///    Author: $author$
    ///      Date: 4/13/2012
    ///////////////////////////////////////////////////////////////////////
    virtual void Run()
    { 
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSTHREADBASE_HPP 
        

