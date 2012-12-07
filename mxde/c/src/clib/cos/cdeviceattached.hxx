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
 *   File: cdeviceattached.hxx
 *
 * Author: $author$
 *   Date: 2/20/2010
 **********************************************************************
 */
#if !defined(_CDEVICEATTACHED_HXX) || defined(CDEVICEATTACHED_MEMBERS_ONLY)
#if !defined(_CDEVICEATTACHED_HXX) && !defined(CDEVICEATTACHED_MEMBERS_ONLY)
#define _CDEVICEATTACHED_HXX
#endif /* !defined(_CDEVICEATTACHED_HXX) && !defined(CDEVICEATTACHED_MEMBERS_ONLY) */

#if !defined(CDEVICEATTACHED_MEMBERS_ONLY)
#include "cdeviceattachedinterface.hxx"
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cDEVICEAttached;
/**
 **********************************************************************
 * Typedef: cDEVICEAttachedExtends
 *
 *  Author: $author$
 *    Date: 2/20/2010
 **********************************************************************
 */
typedef cAttachedT
<cDEVICEAttached, 
 cDEVICEAttachedImplement, 
 cDEVICEAttachedInterface,
 DEVICE, UINT, NULL, cBase>
cDEVICEAttachedExtends;
/**
 **********************************************************************
 *  Class: cDEVICEAttached
 *
 * Author: $author$
 *   Date: 2/20/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cDEVICEAttached
: public cDEVICEAttachedExtends
{
public:
    typedef cDEVICEAttachedExtends cExtends;
    typedef cDEVICEAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cDEVICEAttached
     *
     *      Author: $author$
     *        Date: 2/20/2010
     **********************************************************************
     */
    cDEVICEAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CDEVICEATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CDEVICEATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CDEVICEATTACHED_HXX) || defined(CDEVICEATTACHED_MEMBERS_ONLY) */
