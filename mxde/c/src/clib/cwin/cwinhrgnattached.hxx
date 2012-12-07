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
 *   File: cwinhrgnattached.hxx
 *
 * Author: $author$
 *   Date: 11/23/2009
 **********************************************************************
 */
#if !defined(_CWINHRGNATTACHED_HXX) || defined(CWINHRGNATTACHED_MEMBERS_ONLY)
#if !defined(_CWINHRGNATTACHED_HXX) && !defined(CWINHRGNATTACHED_MEMBERS_ONLY)
#define _CWINHRGNATTACHED_HXX
#endif /* !defined(_CWINHRGNATTACHED_HXX) && !defined(CWINHRGNATTACHED_MEMBERS_ONLY) */

#if !defined(CWINHRGNATTACHED_MEMBERS_ONLY)
#include "cwinhrgnattachedinterface.hxx"
#include "cwinbase.hxx"
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinHRGNAttached;
/**
 **********************************************************************
 * Typedef: cWinHRGNAttachedExtends
 *
 *  Author: $author$
 *    Date: 5/20/2009
 **********************************************************************
 */
typedef cAttachedT
<cWinHRGNAttached, 
 cWinHRGNAttachedImplement, 
 cWinHRGNAttachedInterface,
 HRGN, UINT, NULL, cWinBase>
cWinHRGNAttachedExtends;
/**
 **********************************************************************
 *  Class: cWinHRGNAttached
 *
 * Author: $author$
 *   Date: 5/20/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHRGNAttached
: public cWinHRGNAttachedExtends
{
public:
    typedef cWinHRGNAttachedExtends cExtends;
    typedef cWinHRGNAttached cDerives;

    cWinHRGNAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
#else /* !defined(CWINHRGNATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CWINHRGNATTACHED_MEMBERS_ONLY) */

#if !defined(CWINHRGNATTACHED_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINHRGNATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CWINHRGNATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CWINHRGNATTACHED_HXX) || defined(CWINHRGNATTACHED_MEMBERS_ONLY) */
