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
 *   File: cwincryptohashwindowmain.hxx
 *
 * Author: $author$
 *   Date: 8/1/2010
 **********************************************************************
 */
#if !defined(_CWINCRYPTOHASHWINDOWMAIN_HXX) || defined(CWINCRYPTOHASHWINDOWMAIN_MEMBERS_ONLY)
#if !defined(_CWINCRYPTOHASHWINDOWMAIN_HXX) && !defined(CWINCRYPTOHASHWINDOWMAIN_MEMBERS_ONLY)
#define _CWINCRYPTOHASHWINDOWMAIN_HXX
#endif /* !defined(_CWINCRYPTOHASHWINDOWMAIN_HXX) && !defined(CWINCRYPTOHASHWINDOWMAIN_MEMBERS_ONLY) */

#if !defined(CWINCRYPTOHASHWINDOWMAIN_MEMBERS_ONLY)
#include "cwincryptohashmainwindow.hxx"
#include "cwinwindowmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinCryptoHashWindowMainExtend
 *
 *  Author: $author$
 *    Date: 8/1/2010
 **********************************************************************
 */
typedef cWinWindowMain
cWinCryptoHashWindowMainExtend;
/**
 **********************************************************************
 *  Class: cWinCryptoHashWindowMain
 *
 * Author: $author$
 *   Date: 8/1/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinCryptoHashWindowMain
: public cWinCryptoHashWindowMainExtend
{
public:
    typedef cWinCryptoHashWindowMainExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinCryptoHashWindowMain
     *
     *       Author: $author$
     *         Date: 8/1/2010
     **********************************************************************
     */
    cWinCryptoHashWindowMain()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinCryptoHashWindowMain
     *
     *      Author: $author$
     *        Date: 8/1/2010
     **********************************************************************
     */
    virtual ~cWinCryptoHashWindowMain()
    {
    }
#else /* !defined(CWINCRYPTOHASHWINDOWMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINCRYPTOHASHWINDOWMAIN_MEMBERS_ONLY) */

#if !defined(CWINCRYPTOHASHWINDOWMAIN_MEMBERS_ONLY)
};

#if !defined(CWINCRYPTOHASHWINDOWMAINDERIVE_MEMBERS_ONLY)
#undef CDB_CLASS
#define CDB_CLASS "cWinCryptoHashWindowMainDeriveT"
/**
 **********************************************************************
 *  Class: cWinCryptoHashWindowMainDeriveT
 *
 * Author: $author$
 *   Date: 8/1/2010
 **********************************************************************
 */
template
<class TWinCryptoHashMainWindow,
 class TWinCryptoHashWindowMain=cWinCryptoHashWindowMain,
 class TExtends=TWinCryptoHashWindowMain>

class c_INSTANCE_CLASS cWinCryptoHashWindowMainDeriveT
: public TExtends
{
public:
    typedef TExtends cExtends;
    
    TWinCryptoHashMainWindow m_mainWindow;
    
    /**
     **********************************************************************
     *  Constructor: cWinCryptoHashWindowMainDeriveT
     *
     *       Author: $author$
     *         Date: 8/1/2010
     **********************************************************************
     */
    cWinCryptoHashWindowMainDeriveT
    (const TCHAR* captionChars=_T(CWINCRYPTOHASHMAINWINDOW_CAPTION))
    : m_mainWindow(captionChars)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinCryptoHashWindowMainDeriveT
     *
     *      Author: $author$
     *        Date: 8/1/2010
     **********************************************************************
     */
    virtual ~cWinCryptoHashWindowMainDeriveT()
    {
    }
#else /* !defined(CWINCRYPTOHASHWINDOWMAINDERIVE_MEMBERS_ONLY) */
#endif /* !defined(CWINCRYPTOHASHWINDOWMAINDERIVE_MEMBERS_ONLY) */

#if !defined(CWINCRYPTOHASHWINDOWMAINDERIVE_MEMBERS_ONLY)
#include "cwinwindowmain_members.hxx"
};
#undef CDB_CLASS
#else /* !defined(CWINCRYPTOHASHWINDOWMAINDERIVE_MEMBERS_ONLY) */
#endif /* !defined(CWINCRYPTOHASHWINDOWMAINDERIVE_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCRYPTOHASHWINDOWMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINCRYPTOHASHWINDOWMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CWINCRYPTOHASHWINDOWMAIN_HXX) || defined(CWINCRYPTOHASHWINDOWMAIN_MEMBERS_ONLY) */
