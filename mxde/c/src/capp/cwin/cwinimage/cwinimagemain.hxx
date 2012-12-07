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
 *   File: cwinimagemain.hxx
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
#if !defined(_CWINIMAGEMAIN_HXX) || defined(CWINIMAGEMAIN_MEMBERS_ONLY)
#if !defined(_CWINIMAGEMAIN_HXX) && !defined(CWINIMAGEMAIN_MEMBERS_ONLY)
#define _CWINIMAGEMAIN_HXX
#endif /* !defined(_CWINIMAGEMAIN_HXX) && !defined(CWINIMAGEMAIN_MEMBERS_ONLY) */

#if !defined(CWINIMAGEMAIN_MEMBERS_ONLY)
#include "cwinmainwindowmain.hxx"
#include "cwinimagemainwindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinImageMainExtend
 *
 *  Author: $author$
 *    Date: 11/12/2010
 **********************************************************************
 */
typedef cWinMainWindowMainT
<cWinImageMainWindow>
cWinImageMainExtend;
/**
 **********************************************************************
 *  Class: cWinImageMain
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
class cWinImageMain
: //virtual public cWinImageMainImplement,
  public cWinImageMainExtend
{
public:
    //typedef cWinImageMainImplement cImplements;
    typedef cWinImageMainExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinImageMain
     *
     *       Author: $author$
     *         Date: 11/12/2010
     **********************************************************************
     */
    cWinImageMain()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinImageMain
     *
     *      Author: $author$
     *        Date: 11/12/2010
     **********************************************************************
     */
    virtual ~cWinImageMain()
    {
    }
#else /* !defined(CWINIMAGEMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEMAIN_MEMBERS_ONLY) */

#if !defined(CWINIMAGEMAIN_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINIMAGEMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CWINIMAGEMAIN_HXX) || defined(CWINIMAGEMAIN_MEMBERS_ONLY) */
