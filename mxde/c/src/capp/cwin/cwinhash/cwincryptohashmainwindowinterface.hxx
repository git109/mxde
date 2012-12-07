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
 *   File: cwincryptohashmainwindowinterface.hxx
 *
 * Author: $author$
 *   Date: 8/4/2010
 **********************************************************************
 */
#if !defined(_CWINCRYPTOHASHMAINWINDOWINTERFACE_HXX) || defined(CWINCRYPTOHASHMAINWINDOWINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINCRYPTOHASHMAINWINDOWINTERFACE_HXX) && !defined(CWINCRYPTOHASHMAINWINDOWINTERFACE_MEMBERS_ONLY)
#define _CWINCRYPTOHASHMAINWINDOWINTERFACE_HXX
#endif /* !defined(_CWINCRYPTOHASHMAINWINDOWINTERFACE_HXX) && !defined(CWINCRYPTOHASHMAINWINDOWINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINCRYPTOHASHMAINWINDOWINTERFACE_MEMBERS_ONLY)

#define CWINCRYPTOHASH_BUFFER_SIZE (4096<<4)

#define CWINCRYPTOHASHMAINWINDOW_BG_COLOR_R 0xFF
#define CWINCRYPTOHASHMAINWINDOW_BG_COLOR_G 0xFF
#define CWINCRYPTOHASHMAINWINDOW_BG_COLOR_B 0xDD

#define CWINCRYPTOHASHMAINWINDOW_BG_COLOR \
    RGB(CWINCRYPTOHASHMAINWINDOW_BG_COLOR_R, \
        CWINCRYPTOHASHMAINWINDOW_BG_COLOR_G, \
        CWINCRYPTOHASHMAINWINDOW_BG_COLOR_B)

#define CWINCRYPTOHASHMAINWINDOW_WINDOW_CLASSNAME "cWinCryptoHashMainWindow"

#define CWINCRYPTOHASHMAINWINDOW_CAPTION "WinCryptoHash"
#define CWINCRYPTOHASHMAINWINDOW_OK_TEXT "OK"
#define CWINCRYPTOHASHMAINWINDOW_CANCEL_TEXT "Cancel"
#define CWINCRYPTOHASHMAINWINDOW_UNICODE_TEXT "UNICODE"

#define CWINCRYPTOHASHMAINWINDOW_CONTROL_SPACING 4

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *   Enum:
 *
 * Author: $author$
 *   Date: 7/28/2010
 **********************************************************************
 */
enum
{
    e_HASH_WINDOW_IDC_FIRST = 1100,

    e_HASH_WINDOW_IDC_OK = e_HASH_WINDOW_IDC_FIRST,
    e_HASH_WINDOW_IDC_CANCEL,
    e_HASH_WINDOW_IDC_HASH,
    e_HASH_WINDOW_IDC_FILE,
    e_HASH_WINDOW_IDC_TEXT,
    e_HASH_WINDOW_IDC_UNICODE,

    e_HASH_WINDOW_IDC_NEXT,
    e_HASH_WINDOW_IDC_LAST = e_HASH_WINDOW_IDC_NEXT-1,
    e_HASH_WINDOW_IDC_COUNT = e_HASH_WINDOW_IDC_LAST-e_HASH_WINDOW_IDC_FIRST+1
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCRYPTOHASHMAINWINDOWINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINCRYPTOHASHMAINWINDOWINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINCRYPTOHASHMAINWINDOWINTERFACE_HXX) || defined(CWINCRYPTOHASHMAINWINDOWINTERFACE_MEMBERS_ONLY) */
