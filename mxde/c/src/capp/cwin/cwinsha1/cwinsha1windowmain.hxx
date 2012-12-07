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
 *   File: cwinsha1windowmain.hxx
 *
 * Author: $author$
 *   Date: 8/1/2010
 **********************************************************************
 */
#if !defined(_CWINSHA1WINDOWMAIN_HXX) || defined(CWINSHA1WINDOWMAIN_MEMBERS_ONLY)
#if !defined(_CWINSHA1WINDOWMAIN_HXX) && !defined(CWINSHA1WINDOWMAIN_MEMBERS_ONLY)
#define _CWINSHA1WINDOWMAIN_HXX
#endif /* !defined(_CWINSHA1WINDOWMAIN_HXX) && !defined(CWINSHA1WINDOWMAIN_MEMBERS_ONLY) */

#if !defined(CWINSHA1WINDOWMAIN_MEMBERS_ONLY)
#include "cwincryptohashwindowmain.hxx"
#include "cSHA1.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#define CWINSHA1WINDOWMAIN_CAPTION "WinSHA1"
/**
 **********************************************************************
 * Typedef: cWinSHA1MainWindow
 *
 *  Author: $author$
 *    Date: 8/1/2010
 **********************************************************************
 */
typedef cWinCryptoHashMainWindowDeriveT<cSHA1>
cWinSHA1MainWindow;
/**
 **********************************************************************
 * Typedef: cWinSHA1WindowMain
 *
 *  Author: $author$
 *    Date: 8/1/2010
 **********************************************************************
 */
typedef cWinCryptoHashWindowMainDeriveT<cWinSHA1MainWindow>
cWinSHA1WindowMain;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINSHA1WINDOWMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINSHA1WINDOWMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CWINSHA1WINDOWMAIN_HXX) || defined(CWINSHA1WINDOWMAIN_MEMBERS_ONLY) */
