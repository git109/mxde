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
 *   File: cdeviceopened.hxx
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
#if !defined(_CDEVICEOPENED_HXX) || defined(CDEVICEOPENED_MEMBERS_ONLY)
#if !defined(_CDEVICEOPENED_HXX) && !defined(CDEVICEOPENED_MEMBERS_ONLY)
#define _CDEVICEOPENED_HXX
#endif /* !defined(_CDEVICEOPENED_HXX) && !defined(CDEVICEOPENED_MEMBERS_ONLY) */

#if !defined(CDEVICEOPENED_MEMBERS_ONLY)
#include "cdeviceopenedinterface.hxx"
#include "cdeviceattached.hxx"
#include "copened.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cDEVICEOpened;
/**
 **********************************************************************
 * Typedef: cDEVICEOpenedExtends
 *
 *  Author: $author$
 *    Date: 2/21/2010
 **********************************************************************
 */
typedef cOpenedT
<cDEVICEOpened, 
 cDEVICEOpenedImplement, 
 cDEVICEAttached>
cDEVICEOpenedExtends;
/**
 **********************************************************************
 *  Class: cDEVICEOpened
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cDEVICEOpened
: public cDEVICEOpenedExtends
{
public:
    typedef cDEVICEOpenedExtends cExtends;
    typedef cDEVICEOpened cDerives;

    /**
     **********************************************************************
     * Constructor: cDEVICEOpened
     *
     *      Author: $author$
     *        Date: 2/21/2010
     **********************************************************************
     */
    cDEVICEOpened
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    : cExtends(isOpen) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cDEVICEOpened
     *
     *     Author: $author$
     *       Date: 2/21/2010
     **********************************************************************
     */
    virtual ~cDEVICEOpened()
    {
        eError error;
        if ((error = Closed()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 2/23/2010
     **********************************************************************
     */
    virtual tAttachedTo Detach() 
    {
        tAttachedTo detached = cExtends::Detach();
        SetIsOpen(false);
        return detached;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CDEVICEOPENED_MEMBERS_ONLY) */
#endif /* !defined(CDEVICEOPENED_MEMBERS_ONLY) */

#endif /* !defined(_CDEVICEOPENED_HXX) || defined(CDEVICEOPENED_MEMBERS_ONLY) */
