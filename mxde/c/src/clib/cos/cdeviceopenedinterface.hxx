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
 *   File: cdeviceopenedinterface.hxx
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
#if !defined(_CDEVICEOPENEDINTERFACE_HXX) || defined(CDEVICEOPENEDINTERFACE_MEMBERS_ONLY)
#if !defined(_CDEVICEOPENEDINTERFACE_HXX) && !defined(CDEVICEOPENEDINTERFACE_MEMBERS_ONLY)
#define _CDEVICEOPENEDINTERFACE_HXX
#endif /* !defined(_CDEVICEOPENEDINTERFACE_HXX) && !defined(CDEVICEOPENEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CDEVICEOPENEDINTERFACE_MEMBERS_ONLY)
#include "cdeviceattachedinterface.hxx"
#include "copenedinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cDEVICEOpenedInterface;
/**
 **********************************************************************
 * Typedef: cDEVICEOpenedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 2/21/2010
 **********************************************************************
 */
typedef cOpenedInterfaceT
<cDEVICEOpenedInterface, cDEVICEAttachedInterface>
cDEVICEOpenedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cDEVICEOpenedInterface
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cDEVICEOpenedInterface
: virtual public cDEVICEOpenedInterfaceImplements
{
public:
    typedef cDEVICEOpenedInterfaceImplements cImplements;
    typedef cDEVICEOpenedInterface cDerives;
};
class c_EXPORT_CLASS cDEVICEOpenedImplement;
/**
 **********************************************************************
 * Typedef: cDEVICEOpenedImplementImplements
 *
 *  Author: $author$
 *    Date: 2/21/2010
 **********************************************************************
 */
typedef cOpenedImplementT
<cDEVICEOpenedImplement, cDEVICEOpenedInterface>
cDEVICEOpenedImplementImplements;
/**
 **********************************************************************
 *  Class: cDEVICEOpenedImplement
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cDEVICEOpenedImplement
: virtual public cDEVICEOpenedImplementImplements
{
public:
    typedef cDEVICEOpenedImplementImplements cImplements;
    typedef cDEVICEOpenedImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CDEVICEOPENEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CDEVICEOPENEDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CDEVICEOPENEDINTERFACE_HXX) || defined(CDEVICEOPENEDINTERFACE_MEMBERS_ONLY) */
