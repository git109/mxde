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
 *   File: cdeviceinterface.hxx
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
#if !defined(_CDEVICEINTERFACE_HXX) || defined(CDEVICEINTERFACE_MEMBERS_ONLY)
#if !defined(_CDEVICEINTERFACE_HXX) && !defined(CDEVICEINTERFACE_MEMBERS_ONLY)
#define _CDEVICEINTERFACE_HXX
#endif /* !defined(_CDEVICEINTERFACE_HXX) && !defined(CDEVICEINTERFACE_MEMBERS_ONLY) */

#if !defined(CDEVICEINTERFACE_MEMBERS_ONLY)
#include "cdeviceopenedinterface.hxx"
#include "cstreaminterface.hxx"
#include "cplatform_ioctl.h"
#include "cplatform_io.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cDeviceInterface;

#undef CDB_CLASS
#define CDB_CLASS "cDeviceInterfaceT"
/**
 **********************************************************************
 *  Class: cDeviceInterfaceT
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
template
<class TDerives=cDeviceInterface,
 class TStreamInterface=cStreamInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TUnattached=INVALID_DEVICE_TYPE,
 TUnattached VUnattached=INVALID_DEVICE_TYPE_VALUE,
 class TAttachedTo=DEVICE,
 class TAttachedInterface=cDEVICEOpenedInterface,
 class TAttachedImplements=TAttachedInterface,
 class TImplements=TStreamInterface>

class c_INTERFACE_CLASS cDeviceInterfaceT
: virtual public TImplements,
  virtual public TAttachedImplements
{
public:
    typedef TImplements cImplements;
#else /* !defined(CDEVICEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CDEVICEINTERFACE_MEMBERS_ONLY) */

/* include cStream interface member definitions
 */
#define CSTREAMINTERFACE_MEMBERS_ONLY
#include "cstreaminterface.hxx"
#undef CSTREAMINTERFACE_MEMBERS_ONLY

    typedef TAttachedTo tAttachedTo;
    typedef TAttachedInterface tAttachedInterface;
    typedef TUnattached tUnattached;
    enum { vUnattached = VUnattached };

#if !defined(CDEVICEINTERFACE_MEMBERS_ONLY)
/* include cDevice member functions interface
 */
#define CDEVICE_MEMBERS_ONLY
#define CDEVICE_MEMBER_FUNCS_INTERFACE
#include "cdevice.hxx"
#undef CDEVICE_MEMBER_FUNCS_INTERFACE
#undef CDEVICE_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cDeviceImplement;

#undef CDB_CLASS
#define CDB_CLASS "cDeviceImplementT"
/**
 **********************************************************************
 *  Class: cDeviceImplementT
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
template
<class TDerives=cDeviceImplement,
 class TDeviceInterface=cDeviceInterface,
 class TStreamInterface=cStreamInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TUnattached=INVALID_DEVICE_TYPE,
 TUnattached VUnattached=INVALID_DEVICE_TYPE_VALUE,
 class TAttachedTo=DEVICE,
 class TAttachedInterface=cDEVICEOpenedInterface,
 class TAttachedImplements=TAttachedInterface,
 class TImplements=TDeviceInterface>

class c_IMPLEMENT_CLASS cDeviceImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
/* include cDevice interface member definitions
 */
#define CDEVICEINTERFACE_MEMBERS_ONLY
#include "cdeviceinterface.hxx"
#undef CDEVICEINTERFACE_MEMBERS_ONLY

/* include cDevice member functions implement
 */
#define CDEVICE_MEMBERS_ONLY
#define CDEVICE_MEMBER_FUNCS_IMPLEMENT
#include "cdevice.hxx"
#undef CDEVICE_MEMBER_FUNCS_IMPLEMENT
#undef CDEVICE_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cDeviceInterfaceImplement
 *
 *  Author: $author$
 *    Date: 2/21/2010
 **********************************************************************
 */
typedef cDeviceInterfaceT<>
cDeviceInterfaceImplement;
/**
 **********************************************************************
 *  Class: cDeviceInterface
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cDeviceInterface
: virtual public cDeviceInterfaceImplement
{
public:
    typedef cDeviceInterfaceImplement cImplements;
};
/**
 **********************************************************************
 * Typedef: cDeviceImplementImplement
 *
 *  Author: $author$
 *    Date: 2/21/2010
 **********************************************************************
 */
typedef cDeviceImplementT<>
cDeviceImplementImplement;
/**
 **********************************************************************
 *  Class: cDeviceImplement
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cDeviceImplement
: virtual public cDeviceImplementImplement
{
public:
    typedef cDeviceImplementImplement cImplements;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CDEVICEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CDEVICEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CDEVICEINTERFACE_HXX) || defined(CDEVICEINTERFACE_MEMBERS_ONLY) */
