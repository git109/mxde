/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: cblockdeviceinterface.hxx
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
#if !defined(_CBLOCKDEVICEINTERFACE_HXX) || defined(CBLOCKDEVICEINTERFACE_MEMBERS_ONLY)
#if !defined(_CBLOCKDEVICEINTERFACE_HXX) && !defined(CBLOCKDEVICEINTERFACE_MEMBERS_ONLY)
#define _CBLOCKDEVICEINTERFACE_HXX
#endif /* !defined(_CBLOCKDEVICEINTERFACE_HXX) && !defined(CBLOCKDEVICEINTERFACE_MEMBERS_ONLY) */

#if !defined(CBLOCKDEVICEINTERFACE_MEMBERS_ONLY)
#include "cdeviceinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cBYTEDeviceInterface;
/**
 **********************************************************************
 * Typedef: cBYTEDeviceInterfaceImplement
 *
 *  Author: $author$
 *    Date: 2/21/2010
 **********************************************************************
 */
typedef cDeviceInterfaceT
<cBYTEDeviceInterface,
 cBYTEStreamInterface,
 BYTE, BYTE>
cBYTEDeviceInterfaceImplement;
/**
 **********************************************************************
 *  Class: cBYTEDeviceInterface
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEDeviceInterface
: virtual public cBYTEDeviceInterfaceImplement
{
public:
    typedef cBYTEDeviceInterfaceImplement cImplements;
};
class c_IMPLEMENT_CLASS cBYTEDeviceImplement;
/**
 **********************************************************************
 * Typedef: cBYTEDeviceImplementImplement
 *
 *  Author: $author$
 *    Date: 2/21/2010
 **********************************************************************
 */
typedef cDeviceImplementT
<cBYTEDeviceImplement,
 cBYTEDeviceInterface,
 cBYTEStreamInterface,
 BYTE, BYTE>
cBYTEDeviceImplementImplement;
/**
 **********************************************************************
 *  Class: cBYTEDeviceImplement
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cBYTEDeviceImplement
: virtual public cBYTEDeviceImplementImplement
{
public:
    typedef cBYTEDeviceImplementImplement cImplements;
};

/**
 **********************************************************************
 *  Class: cBlockDeviceInterface
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cBlockDeviceInterface
: virtual public cBYTEDeviceInterface
{
public:
    typedef cBYTEDeviceInterface cImplements;
#else /* !defined(CBLOCKDEVICEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CBLOCKDEVICEINTERFACE_MEMBERS_ONLY) */

#if !defined(CBLOCKDEVICEINTERFACE_MEMBERS_ONLY)
};

/**
 **********************************************************************
 *  Class: cBlockDeviceImplement
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cBlockDeviceImplement
: virtual public cBlockDeviceInterface
{
public:
    typedef cBlockDeviceInterface cImplements;

};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CBLOCKDEVICEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CBLOCKDEVICEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CBLOCKDEVICEINTERFACE_HXX) || defined(CBLOCKDEVICEINTERFACE_MEMBERS_ONLY) */
