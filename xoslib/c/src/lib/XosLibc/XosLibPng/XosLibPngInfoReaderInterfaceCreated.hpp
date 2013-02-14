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
///   File: XosLibPngInfoReaderInterfaceCreated.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGINFOREADERINTERFACECREATED_HPP) || defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGINFOREADERINTERFACECREATED_HPP) && !defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY)
#define _XOSLIBPNGINFOREADERINTERFACECREATED_HPP
#endif // !defined(_XOSLIBPNGINFOREADERINTERFACECREATED_HPP) && !defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY)
#include "XosLibPngInfoReaderInterface.hpp"
#include "XosCreatedAttached.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngInfoReaderInterfaceCreatedExtendExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<XosLibPngInfoReaderInterface*, int, 0, XosLibPngInterfaceBase>
XosLibPngInfoReaderInterfaceCreatedExtendExtend;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngInfoReaderInterfaceCreatedExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosCreatedAttachedT
<XosLibPngInfoReaderInterface*, int, 0, XosLibPngInterfaceBase, 
 XosLibPngInfoReaderInterfaceCreatedExtendExtend>
XosLibPngInfoReaderInterfaceCreatedExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngInfoReaderInterfaceCreated
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosLibPngInfoReaderInterfaceCreated
: public XosLibPngInfoReaderInterfaceCreatedExtend
{
public:
    typedef XosLibPngInfoReaderInterfaceCreatedExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosLibPngInfoReaderInterfaceCreated
    ///
    ///       Author: $author$
    ///         Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosLibPngInfoReaderInterfaceCreated()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosLibPngInfoReaderInterfaceCreated
    ///
    ///      Author: $author$
    ///        Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosLibPngInfoReaderInterfaceCreated()
    {
    }
#else // !defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create()
#if defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBER_FUNCS_IMPLEMENT)
        XosLibPngInfoReaderInterface* detached;
        if ((detached = XosLibPngInfoReaderInterface::CreateInstance(error)))
        if (!(error = detached->Create()))
            Attach(detached);
        else
        XosLibPngInfoReaderInterface::DestroyInstance(detached);
#else // !defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroy()
#if defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBER_FUNCS_IMPLEMENT)
        XosLibPngInfoReaderInterface* detached;
        if ((detached = Detach()))
            error = XosLibPngInfoReaderInterface::DestroyInstance(detached);
#else // !defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGINFOREADERINTERFACECREATED_HPP) || defined(XOSLIBPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY) 
        

