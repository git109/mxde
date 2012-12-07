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
 *   File: cwindc.hxx
 *
 * Author: $author$
 *   Date: 8/4/2010
 **********************************************************************
 */
#if !defined(_CWINDC_HXX) || defined(CWINDC_MEMBERS_ONLY)
#if !defined(_CWINDC_HXX) && !defined(CWINDC_MEMBERS_ONLY)
#define _CWINDC_HXX
#endif /* !defined(_CWINDC_HXX) && !defined(CWINDC_MEMBERS_ONLY) */

#if !defined(CWINDC_MEMBERS_ONLY)
#include "cwindcinterface.hxx"
#include "cwinhdccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinDCExtend
 *
 *  Author: $author$
 *    Date: 8/4/2010
 **********************************************************************
 */
typedef cWinHDCCreated
cWinDCExtend;
/**
 **********************************************************************
 *  Class: cWinDC
 *
 * Author: $author$
 *   Date: 8/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinDC
: virtual public cWinDCImplement,
  public cWinDCExtend
{
public:
    typedef cWinDCImplement cImplements;
    typedef cWinDCExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cWinDC
     *
     *       Author: $author$
     *         Date: 8/4/2010
     **********************************************************************
     */
    cWinDC
    (HDC attached,
     HWND hWndAttached,
     bool isAcquired=false)
    : cExtends(attached, hWndAttached, isAcquired)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cWinDC
     *
     *       Author: $author$
     *         Date: 8/4/2010
     **********************************************************************
     */
    cWinDC
    (HDC attached=NULL,
     bool isCreated=false)
    : cExtends(attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinDC
     *
     *      Author: $author$
     *        Date: 8/4/2010
     **********************************************************************
     */
    virtual ~cWinDC()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
        DBE_THROW_ERROR(error, Released());
    }
#else /* !defined(CWINDC_MEMBERS_ONLY) */
#endif /* !defined(CWINDC_MEMBERS_ONLY) */

#if !defined(CWINDC_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINDC_MEMBERS_ONLY) */
#endif /* !defined(CWINDC_MEMBERS_ONLY) */

#endif /* !defined(_CWINDC_HXX) || defined(CWINDC_MEMBERS_ONLY) */
