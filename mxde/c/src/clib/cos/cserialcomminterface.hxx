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
 *   File: cserialcomminterface.hxx
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
#if !defined(_CSERIALCOMMINTERFACE_HXX) || defined(CSERIALCOMMINTERFACE_MEMBERS_ONLY)
#if !defined(_CSERIALCOMMINTERFACE_HXX) && !defined(CSERIALCOMMINTERFACE_MEMBERS_ONLY)
#define _CSERIALCOMMINTERFACE_HXX
#endif /* !defined(_CSERIALCOMMINTERFACE_HXX) && !defined(CSERIALCOMMINTERFACE_MEMBERS_ONLY) */

#if !defined(CSERIALCOMMINTERFACE_MEMBERS_ONLY)
#include "cdeviceinterface.hxx"
#include "cplatform_serial_comm.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cSerialCommInterface;

#undef CDB_CLASS
#define CDB_CLASS "cSerialCommInterfaceT"
/**
 **********************************************************************
 *  Class: cSerialCommInterfaceT
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
template
<class TDerives=cSerialCommInterface,
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
 class TAttachedInterface=cDEVICEAttachedInterface,
 class TAttachedImplements=TAttachedInterface,
 class TImplements=TDeviceInterface>

class c_INTERFACE_CLASS cSerialCommInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
#else /* !defined(CSERIALCOMMINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSERIALCOMMINTERFACE_MEMBERS_ONLY) */

/* include cDevice interface member definitions
 */
#define CDEVICEINTERFACE_MEMBERS_ONLY
#include "cdeviceinterface.hxx"
#undef CDEVICEINTERFACE_MEMBERS_ONLY

#if !defined(CSERIALCOMMINTERFACE_MEMBERS_ONLY)
/* include cSerialComm member functions interface
 */
#define CSERIALCOMM_MEMBERS_ONLY
#define CSERIALCOMM_MEMBER_FUNCS_INTERFACE
#include "cserialcomm.hxx"
#undef CSERIALCOMM_MEMBER_FUNCS_INTERFACE
#undef CSERIALCOMM_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cSerialCommImplement;

#undef CDB_CLASS
#define CDB_CLASS "cSerialCommImplementT"
/**
 **********************************************************************
 *  Class: cSerialCommImplementT
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
template
<class TDerives=cSerialCommImplement,
 class TSerialCommInterface=cSerialCommInterface,
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
 class TAttachedInterface=cDEVICEAttachedInterface,
 class TAttachedImplements=TAttachedInterface,
 class TImplements=TSerialCommInterface>

class c_IMPLEMENT_CLASS cSerialCommImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    
/* include cSerialComm interface member definitions
 */
#define CSERIALCOMMINTERFACE_MEMBERS_ONLY
#include "cserialcomminterface.hxx"
#undef CSERIALCOMMINTERFACE_MEMBERS_ONLY

/* include cSerialComm member functions implement
 */
#define CSERIALCOMM_MEMBERS_ONLY
#define CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT
#include "cserialcomm.hxx"
#undef CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT
#undef CSERIALCOMM_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cSerialCommInterfaceImplement
 *
 *  Author: $author$
 *    Date: 2/21/2010
 **********************************************************************
 */
typedef cSerialCommInterfaceT<>
cSerialCommInterfaceImplement;
/**
 **********************************************************************
 *  Class: cSerialCommInterface
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cSerialCommInterface
: virtual public cSerialCommInterfaceImplement
{
public:
    typedef cSerialCommInterfaceImplement cImplements;
};
/**
 **********************************************************************
 * Typedef: cSerialCommImplementImplement
 *
 *  Author: $author$
 *    Date: 2/21/2010
 **********************************************************************
 */
typedef cSerialCommImplementT<>
cSerialCommImplementImplement;
/**
 **********************************************************************
 *  Class: cSerialCommImplement
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cSerialCommImplement
: virtual public cSerialCommImplementImplement
{
public:
    typedef cSerialCommImplementImplement cImplements;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSERIALCOMMINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSERIALCOMMINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CSERIALCOMMINTERFACE_HXX) || defined(CSERIALCOMMINTERFACE_MEMBERS_ONLY) */
