/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: ctiffattached.hxx
 *
 * Author: $author$
 *   Date: 12/24/2009
 **********************************************************************
 */
#if !defined(_CTIFFATTACHED_HXX) || defined(CTIFFATTACHED_MEMBERS_ONLY)
#if !defined(_CTIFFATTACHED_HXX) && !defined(CTIFFATTACHED_MEMBERS_ONLY)
#define _CTIFFATTACHED_HXX
#endif /* !defined(_CTIFFATTACHED_HXX) && !defined(CTIFFATTACHED_MEMBERS_ONLY) */

#if !defined(CTIFFATTACHED_MEMBERS_ONLY)
#include "ctiffattachedinterface.hxx"
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cTIFFAttached;
/**
 **********************************************************************
 * Typedef: cTIFFAttachedExtends
 *
 *  Author: $author$
 *    Date: 12/24/2009
 **********************************************************************
 */
typedef cAttachedT
<cTIFFAttached, 
 cTIFFAttachedImplement, 
 cTIFFAttachedInterface,
 TIFF*, UINT, NULL, cBase>
cTIFFAttachedExtends;
/**
 **********************************************************************
 *  Class: cTIFFAttached
 *
 * Author: $author$
 *   Date: 12/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cTIFFAttached
: public cTIFFAttachedExtends
{
public:
    typedef cTIFFAttachedExtends cExtends;
    typedef cTIFFAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cTIFFAttached
     *
     *      Author: $author$
     *        Date: 12/24/2009
     **********************************************************************
     */
    cTIFFAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
#else /* !defined(CTIFFATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CTIFFATTACHED_MEMBERS_ONLY) */

#if !defined(CTIFFATTACHED_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTIFFATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CTIFFATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CTIFFATTACHED_HXX) || defined(CTIFFATTACHED_MEMBERS_ONLY) */
