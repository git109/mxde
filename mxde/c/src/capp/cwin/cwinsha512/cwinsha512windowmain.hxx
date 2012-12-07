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
 *   File: cwinsha512windowmain.hxx
 *
 * Author: $author$
 *   Date: 8/1/2010
 **********************************************************************
 */
#if !defined(_CWINSHA512WINDOWMAIN_HXX) || defined(CWINSHA512WINDOWMAIN_MEMBERS_ONLY)
#if !defined(_CWINSHA512WINDOWMAIN_HXX) && !defined(CWINSHA512WINDOWMAIN_MEMBERS_ONLY)
#define _CWINSHA512WINDOWMAIN_HXX
#endif /* !defined(_CWINSHA512WINDOWMAIN_HXX) && !defined(CWINSHA512WINDOWMAIN_MEMBERS_ONLY) */

#if !defined(CWINSHA512WINDOWMAIN_MEMBERS_ONLY)
#include "cwincryptohashwindowmain.hxx"
#include "cSHA512.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#define CWINSHA512WINDOWMAIN_CAPTION "WinSHA512"
/**
 **********************************************************************
 * Typedef: cWinSHA512MainWindow
 *
 *  Author: $author$
 *    Date: 8/1/2010
 **********************************************************************
 */
typedef cWinCryptoHashMainWindowDeriveT<cSHA512>
cWinSHA512MainWindow;
/**
 **********************************************************************
 * Typedef: cWinSHA512WindowMain
 *
 *  Author: $author$
 *    Date: 8/1/2010
 **********************************************************************
 */
typedef cWinCryptoHashWindowMainDeriveT<cWinSHA512MainWindow>
cWinSHA512WindowMain;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINSHA512WINDOWMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWINSHA512WINDOWMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CWINSHA512WINDOWMAIN_HXX) || defined(CWINSHA512WINDOWMAIN_MEMBERS_ONLY) */
