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
 *   File: cwinmdimainframewindow.hxx
 *
 * Author: $author$
 *   Date: 1/3/2010
 **********************************************************************
 */
#if !defined(_CWINMDIMAINFRAMEWINDOW_HXX) || defined(CWINMDIMAINFRAMEWINDOW_MEMBERS_ONLY)
#if !defined(_CWINMDIMAINFRAMEWINDOW_HXX) && !defined(CWINMDIMAINFRAMEWINDOW_MEMBERS_ONLY)
#define _CWINMDIMAINFRAMEWINDOW_HXX
#endif /* !defined(_CWINMDIMAINFRAMEWINDOW_HXX) && !defined(CWINMDIMAINFRAMEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMDIMAINFRAMEWINDOW_MEMBERS_ONLY)
#include "cwinmdiframewindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinMDIMainFrameWindowExtend
 *
 *  Author: $author$
 *    Date: 1/3/2010
 **********************************************************************
 */
typedef cWinMDIMainFrameWindowT<>
cWinMDIMainFrameWindowExtend;
/**
 **********************************************************************
 *  Class: cWinMDIMainFrameWindow
 *
 * Author: $author$
 *   Date: 1/3/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinMDIMainFrameWindow
: public cWinMDIMainFrameWindowExtend
{
public:
    typedef cWinMDIMainFrameWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinMDIMainFrameWindow
     *
     *       Author: $author$
     *         Date: 1/3/2010
     **********************************************************************
     */
    cWinMDIMainFrameWindow()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMDIMainFrameWindow
     *
     *      Author: $author$
     *        Date: 1/3/2010
     **********************************************************************
     */
    virtual ~cWinMDIMainFrameWindow()
    {
    }
#else /* !defined(CWINMDIMAINFRAMEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMDIMAINFRAMEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMDIMAINFRAMEWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINMDIMAINFRAMEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMDIMAINFRAMEWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINMDIMAINFRAMEWINDOW_HXX) || defined(CWINMDIMAINFRAMEWINDOW_MEMBERS_ONLY) */
