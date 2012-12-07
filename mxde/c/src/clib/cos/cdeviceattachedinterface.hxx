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
 *   File: cdeviceattachedinterface.hxx
 *
 * Author: $author$
 *   Date: 2/20/2010
 **********************************************************************
 */
#if !defined(_CDEVICEATTACHEDINTERFACE_HXX) || defined(CDEVICEATTACHEDINTERFACE_MEMBERS_ONLY)
#if !defined(_CDEVICEATTACHEDINTERFACE_HXX) && !defined(CDEVICEATTACHEDINTERFACE_MEMBERS_ONLY)
#define _CDEVICEATTACHEDINTERFACE_HXX
#endif /* !defined(_CDEVICEATTACHEDINTERFACE_HXX) && !defined(CDEVICEATTACHEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CDEVICEATTACHEDINTERFACE_MEMBERS_ONLY)
#include "cplatform_device.h"
#include "cattachedinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cDEVICEAttachedInterface;
/**
 **********************************************************************
 * Typedef: cDEVICEAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 2/20/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cDEVICEAttachedInterface, 
 DEVICE, UINT, NULL, cInterfaceBase>
cDEVICEAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cDEVICEAttachedInterface
 *
 * Author: $author$
 *   Date: 2/20/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cDEVICEAttachedInterface
: virtual public cDEVICEAttachedInterfaceImplements
{
public:
    typedef cDEVICEAttachedInterfaceImplements cImplements;
    typedef cDEVICEAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cDEVICEAttachedImplement;
/**
 **********************************************************************
 * Typedef: cDEVICEAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 2/20/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cDEVICEAttachedImplement, 
 cDEVICEAttachedInterface, 
 DEVICE, UINT, NULL>
cDEVICEAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cDEVICEAttachedImplement
 *
 * Author: $author$
 *   Date: 2/20/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cDEVICEAttachedImplement
: virtual public cDEVICEAttachedImplementImplements
{
public:
    typedef cDEVICEAttachedImplementImplements cImplements;
    typedef cDEVICEAttachedImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CDEVICEATTACHEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CDEVICEATTACHEDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CDEVICEATTACHEDINTERFACE_HXX) || defined(CDEVICEATTACHEDINTERFACE_MEMBERS_ONLY) */
