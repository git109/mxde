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
 *   File: cwinbitmapinfo.hxx
 *
 * Author: $author$
 *   Date: 7/23/2009
 **********************************************************************
 */
#if !defined(_CWINBITMAPINFO_HXX) || defined(CWINBITMAPINFO_MEMBERS_ONLY)
#if !defined(_CWINBITMAPINFO_HXX) && !defined(CWINBITMAPINFO_MEMBERS_ONLY)
#define _CWINBITMAPINFO_HXX
#endif /* !defined(_CWINBITMAPINFO_HXX) && !defined(CWINBITMAPINFO_MEMBERS_ONLY) */

#if !defined(CWINBITMAPINFO_MEMBERS_ONLY)
#include "cwinpbitmapinfoattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinBitmapInfo
 *
 * Author: $author$
 *   Date: 7/23/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinBitmapInfo
: public cWinPBITMAPINFOAllocated
{
public:
    typedef cWinPBITMAPINFOAllocated cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinBitmapInfo
     *
     *       Author: $author$
     *         Date: 7/23/2009
     **********************************************************************
     */
    cWinBitmapInfo
    (PBITMAPINFO attached=0,
     bool isAllocated=false)
    : cExtends(attached,isAllocated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinBitmapInfo
     *
     *      Author: $author$
     *        Date: 7/23/2009
     **********************************************************************
     */
    virtual ~cWinBitmapInfo()
    {
        eError error;
        if ((error = Freed()))
            throw(error);
    }
#else /* !defined(CWINBITMAPINFO_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPINFO_MEMBERS_ONLY) */

#if !defined(CWINBITMAPINFO_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINBITMAPINFO_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPINFO_MEMBERS_ONLY) */

#endif /* !defined(_CWINBITMAPINFO_HXX) || defined(CWINBITMAPINFO_MEMBERS_ONLY) */
