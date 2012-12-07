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
 *   File: cwincryptohashmainwindowderive.hxx
 *
 * Author: $author$
 *   Date: 8/4/2010
 **********************************************************************
 */
#if !defined(_CWINCRYPTOHASHMAINWINDOWDERIVE_HXX) || defined(CWINCRYPTOHASHMAINWINDOWDERIVE_MEMBERS_ONLY)
#if !defined(_CWINCRYPTOHASHMAINWINDOWDERIVE_HXX) && !defined(CWINCRYPTOHASHMAINWINDOWDERIVE_MEMBERS_ONLY)
#define _CWINCRYPTOHASHMAINWINDOWDERIVE_HXX
#endif /* !defined(_CWINCRYPTOHASHMAINWINDOWDERIVE_HXX) && !defined(CWINCRYPTOHASHMAINWINDOWDERIVE_MEMBERS_ONLY) */

#if !defined(CWINCRYPTOHASHMAINWINDOWDERIVE_MEMBERS_ONLY)
#include "cwincryptohashmainwindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#undef CDB_CLASS
#define CDB_CLASS "cWinCryptoHashMainWindowDeriveT"
/**
 **********************************************************************
 *  Class: cWinCryptoHashMainWindowDeriveT
 *
 * Author: $author$
 *   Date: 8/1/2010
 **********************************************************************
 */
template
<class THash,
 class TWinCryptoHashMainWindow=cWinCryptoHashMainWindow,
 class TExtends=TWinCryptoHashMainWindow>

class c_INSTANCE_CLASS cWinCryptoHashMainWindowDeriveT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef THash tHash;
    
    tHash m_hash;
    BYTE m_hashed[tHash::HASHSIZE];
    TCHAR m_hashedText[tHash::HASHSIZE*2+1];

    /**
     **********************************************************************
     *  Constructor: cWinCryptoHashMainWindowDeriveT
     *
     *       Author: $author$
     *         Date: 8/1/2010
     **********************************************************************
     */
    cWinCryptoHashMainWindowDeriveT
    (const TCHAR* captionChars=_T(CWINCRYPTOHASHMAINWINDOW_CAPTION),
     COLORREF bgColor=CWINCRYPTOHASHMAINWINDOW_BG_COLOR,
     bool hasDropShadow=true,
     bool isLayeredWindow=false,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINCRYPTOHASHMAINWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (captionChars, bgColor, 
       hasDropShadow, isLayeredWindow,
       hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinCryptoHashMainWindowDeriveT
     *
     *      Author: $author$
     *        Date: 8/1/2010
     **********************************************************************
     */
    virtual ~cWinCryptoHashMainWindowDeriveT()
    {
    }
    /**
     **********************************************************************
     * Function: CryptoHash
     *
     *   Author: $author$
     *     Date: 9/1/2010
     **********************************************************************
     */
    virtual cCryptoHashInterface& CryptoHash
    (TCHAR*& hashedText,
     BYTE*& hashed,
     TSIZE& hashedSize) const
    {
        cCryptoHashInterface& cryptoHash = (cCryptoHashInterface&)(m_hash);
        hashedText = (TCHAR*)(m_hashedText);
        hashed = (BYTE*)(m_hashed);
        hashedSize = (TSIZE)(sizeof(m_hashed));
        return cryptoHash;
    }
#else /* !defined(CWINCRYPTOHASHMAINWINDOWDERIVE_MEMBERS_ONLY) */
#endif /* !defined(CWINCRYPTOHASHMAINWINDOWDERIVE_MEMBERS_ONLY) */

#if !defined(CWINCRYPTOHASHMAINWINDOWDERIVE_MEMBERS_ONLY)
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCRYPTOHASHMAINWINDOWDERIVE_MEMBERS_ONLY) */
#endif /* !defined(CWINCRYPTOHASHMAINWINDOWDERIVE_MEMBERS_ONLY) */

#endif /* !defined(_CWINCRYPTOHASHMAINWINDOWDERIVE_HXX) || defined(CWINCRYPTOHASHMAINWINDOWDERIVE_MEMBERS_ONLY) */
