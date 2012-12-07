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
 *   File: cwinmd5windowmain.hxx
 *
 * Author: $author$
 *   Date: 8/1/2010
 **********************************************************************
 */
#if !defined(_CWINMD5WINDOWMAIN_HXX) || defined(CWINMD5WINDOWMAIN_MEMBERS_ONLY)
#if !defined(_CWINMD5WINDOWMAIN_HXX) && !defined(CWINMD5WINDOWMAIN_MEMBERS_ONLY)
#define _CWINMD5WINDOWMAIN_HXX
#endif /* !defined(_CWINMD5WINDOWMAIN_HXX) && !defined(CWINMD5WINDOWMAIN_MEMBERS_ONLY) */

#if !defined(CWINMD5WINDOWMAIN_MEMBERS_ONLY)
#include "cwincryptohashwindowmain.hxx"
#include "cMD5.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#define CWINMD5WINDOWMAIN_CAPTION "WinMD5"
/**
 **********************************************************************
 * Typedef: cWinMD5MainWindow
 *
 *  Author: $author$
 *    Date: 8/1/2010
 **********************************************************************
 */
typedef cWinCryptoHashMainWindowDeriveT<cMD5>
cWinMD5MainWindow;
/**
 **********************************************************************
 * Typedef: cWinMD5WindowMain
 *
 *  Author: $author$
 *    Date: 8/1/2010
 **********************************************************************
 */
typedef cWinCryptoHashWindowMainDeriveT<cWinMD5MainWindow>
cWinMD5WindowMain;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINMD5WINDOWMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINMD5WINDOWMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CWINMD5WINDOWMAIN_HXX) || defined(CWINMD5WINDOWMAIN_MEMBERS_ONLY) */
