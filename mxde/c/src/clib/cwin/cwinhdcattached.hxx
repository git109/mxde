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
 *   File: cwinhdcattached.hxx
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
#if !defined(_CWINHDCATTACHED_HXX) || defined(CWINHDCATTACHED_MEMBERS_ONLY)
#if !defined(_CWINHDCATTACHED_HXX) && !defined(CWINHDCATTACHED_MEMBERS_ONLY)
#define _CWINHDCATTACHED_HXX
#endif /* !defined(_CWINHDCATTACHED_HXX) && !defined(CWINHDCATTACHED_MEMBERS_ONLY) */

#if !defined(CWINHDCATTACHED_MEMBERS_ONLY)
#include "cwinhdcattachedinterface.hxx"
#include "cattached.hxx"
#include "cwinbase.hxx"

/* cWinHDCAttached definition
 */
class c_EXPORT_CLASS cWinHDCAttached;

/**
 **********************************************************************
 * Typedef: cWinHDCAttachedExtends
 *
 *  Author: $author$
 *    Date: 5/25/2009
 **********************************************************************
 */
typedef cAttachedT
<cWinHDCAttached, 
 cWinHDCAttachedImplement, 
 cWinHDCAttachedInterface,
 HDC, UINT, NULL, cWinBase>
cWinHDCAttachedExtends;
/**
 **********************************************************************
 *  Class: cWinHDCAttached
 *
 * Author: $author$
 *   Date: 5/25/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHDCAttached
: public cWinHDCAttachedExtends
{
public:
    typedef cWinHDCAttachedExtends cExtends;
    typedef cWinHDCAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cWinHDCAttached
     *
     *      Author: $author$
     *        Date: 5/25/2009
     **********************************************************************
     */
    cWinHDCAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#else /* !defined(CWINHDCATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CWINHDCATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CWINHDCATTACHED_HXX) || defined(CWINHDCATTACHED_MEMBERS_ONLY) */
