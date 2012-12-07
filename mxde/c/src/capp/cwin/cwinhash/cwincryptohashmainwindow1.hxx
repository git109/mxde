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
 *   File: cwincryptohashmainwindow.hxx
 *
 * Author: $author$
 *   Date: 7/28/2010
 **********************************************************************
 */
#if !defined(_CWINCRYPTOHASHMAINWINDOW_HXX) || defined(CWINCRYPTOHASHMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINCRYPTOHASHMAINWINDOW_HXX) && !defined(CWINCRYPTOHASHMAINWINDOW_MEMBERS_ONLY)
#define _CWINCRYPTOHASHMAINWINDOW_HXX
#endif /* !defined(_CWINCRYPTOHASHMAINWINDOW_HXX) && !defined(CWINCRYPTOHASHMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINCRYPTOHASHMAINWINDOW_MEMBERS_ONLY)
#include "cwinroundedframemainwindow.hxx"
#include "cwinmainwindow.hxx"
#include "cwineditcontrol.hxx"
#include "cwincheckboxcontrol.hxx"
#include "cwinpushbuttoncontrol.hxx"
#include "cwindropfiles.hxx"
#include "cwinregionimageobject.hxx"
#include "ckeyiconimageobject.hxx"
#include "cmd5.hxx"
#include "ccryptohash.hxx"
#include "cfile.hxx"
#include "cbuffer.hxx"

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

/**
 **********************************************************************
 * Typedef: cWinCryptoHashMainWindowExtend
 *
 *  Author: $author$
 *    Date: 7/28/2010
 **********************************************************************
 */
//typedef cWinMainWindow
typedef cWinRoundedFrameMainWindow
cWinCryptoHashMainWindowExtend;
/**
 **********************************************************************
 *  Class: cWinCryptoHashMainWindow
 *
 * Author: $author$
 *   Date: 7/28/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinCryptoHashMainWindow
: //virtual public cWinCryptoHashMainWindowImplement,
  public cWinCryptoHashMainWindowExtend
{
public:
    //typedef cWinCryptoHashMainWindowImplement cImplements;
    typedef cWinCryptoHashMainWindowExtend cExtends;

    const TCHAR* m_captionChars;
    
    TSIZE m_controlSpacing;
    
    TSIZE m_iconBorder;
    TSIZE m_iconHeight;
    TSIZE m_iconWidth;
    TOFFSET m_iconX;
    TOFFSET m_iconY;
    
    cWinRegion m_objectBrushRegion;
    cWinRegionImage m_objectRegionImage;
    cWinRegionImageObject m_objectRegionBrush;
    
    cWinImageColor m_imageRed;
    cWinImageColor m_imageGreen;
    cWinImageColor m_imageBlue;
    cWinImageColor m_imageBlack;
    cWinImageColor m_imageWhite;
    cWinImageColor m_imageGray;
    
    bool m_quit;
    
    cWinEditControlWindowSuperClass m_editWindowClass;
    cWinCheckBoxControlWindowSuperClass m_checkBoxWindowClass;
    cWinPushButtonControlWindowSuperClass m_pushButtonWindowClass;
    
    cWinEditControl m_hashControl;
    cWinEditControl m_fileControl;
    cWinEditControl m_textControl;
    
    cWinPushButtonControl m_okControl;
    const TCHAR* m_okChars;
    cTCHARString m_ok;
    
    cWinPushButtonControl m_cancelControl;
    const TCHAR* m_cancelChars;
    cTCHARString m_cancel;
    
    cWinCheckBoxControl m_unicodeControl;
    const TCHAR* m_unicodeChars;
    cTCHARString m_unicode;
    
    cWinDropFiles m_dropFiles;

    cBYTEFile m_file;
    cBYTEString m_text;
    cWCHARString m_unicodeText;

    TLENGTH m_bufferSize;
    BYTE m_buffer[CWINCRYPTOHASH_BUFFER_SIZE];

    /*typedef cMD5 tHash;
    tHash m_hash;
    BYTE m_hashed[tHash::HASHSIZE];
    TCHAR m_hashedText[tHash::HASHSIZE*2+1];*/

    /**
     **********************************************************************
     *  Constructor: cWinCryptoHashMainWindow
     *
     *       Author: $author$
     *         Date: 7/28/2010
     **********************************************************************
     */
    cWinCryptoHashMainWindow
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
      (bgColor, hasDropShadow, isLayeredWindow,
       hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),
      
      m_captionChars(captionChars),

      m_controlSpacing(CWINCRYPTOHASHMAINWINDOW_CONTROL_SPACING),
            
      m_iconBorder(1),
      m_iconHeight((m_cornerRadius*2)-1),
      m_iconWidth(m_iconHeight*2),
      m_iconX(m_cornerRadius),
      m_iconY(0),
      
      m_objectRegionImage(m_region),
      m_objectRegionBrush
      (m_objectRegionImage, m_objectBrushRegion, 
       m_iconBorder*2+1, m_iconBorder*2+1),
      
      m_imageRed(m_image, 255,0,0),
      m_imageGreen(m_image, 0,255,0),
      m_imageBlue(m_image, 0,0,255),
      m_imageBlack(m_image, 0,0,0),
      m_imageWhite(m_image, 255,255,255),
      m_imageGray(m_image, 128,128,128),
      
      m_quit(false),
      m_okChars(_T(CWINCRYPTOHASHMAINWINDOW_OK_TEXT)),
      m_ok(m_okChars),
      m_cancelChars(_T(CWINCRYPTOHASHMAINWINDOW_CANCEL_TEXT)),
      m_cancel(m_cancelChars),
      m_unicodeChars(_T(CWINCRYPTOHASHMAINWINDOW_UNICODE_TEXT)),
      m_unicode(m_unicodeChars),
      m_bufferSize(CWINCRYPTOHASH_BUFFER_SIZE)
    {
        m_topMargin = m_cornerRadius;
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinCryptoHashMainWindow
     *
     *      Author: $author$
     *        Date: 7/28/2010
     **********************************************************************
     */
    virtual ~cWinCryptoHashMainWindow()
    {
    }
    /**
     **********************************************************************
     * Function: HashFile
     *
     *   Author: $author$
     *     Date: 7/29/2010
     **********************************************************************
     */
    virtual eError HashFile
    (const CHAR* fileNameChars) 
    {
        eError error;

        if (!(error = m_file.Open(fileNameChars, "rb")))
        {
            error = Hash(m_file);
            m_file.Close();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: HashFile
     *
     *   Author: $author$
     *     Date: 7/29/2010
     **********************************************************************
     */
    virtual eError HashFile
    (const WCHAR* fileNameChars) 
    {
        eError error;

        if (!(error = m_file.Open(fileNameChars, "rb")))
        {
            error = Hash(m_file);
            m_file.Close();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Hash
     *
     *   Author: $author$
     *     Date: 7/29/2010
     **********************************************************************
     */
    virtual eError Hash
    (cBYTEReaderInterface& reader) 
    {
        TCHAR* hashedText = 0;
        BYTE* hashed = 0;
        TSIZE hashedSize = 0;
        cCryptoHashInterface& hash = CryptoHash
        (hashedText, hashed, hashedSize);
        eError error = e_ERROR_NONE;
        TLENGTH count, length;
        MSG msg;

        if (0 <= (count = hash.Initialize()))
        {
            do
            {
                if (0 < (length = reader.Read(m_buffer, m_bufferSize)))
                if (0 > (count = hash.Hash(m_buffer, length)))
                    break;
                    
                if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
                    DispatchMessage(&msg);
                    
                if (m_quit)
                    return error;
            }
            while (0 < length);

            if (0 < (count = hash.Finalize(hashed, hashedSize)))
            {
                cTCHARS::ToX(hashedText, hashed, count);
                m_hashControl.SetText(hashedText);
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Hash
     *
     *   Author: $author$
     *     Date: 8/3/2010
     **********************************************************************
     */
    virtual eError Hash
    (const BYTE* buffer, TSIZE length) 
    {
        TCHAR* hashedText = 0;
        BYTE* hashed = 0;
        TSIZE hashedSize = 0;
        cCryptoHashInterface& hash = CryptoHash
        (hashedText, hashed, hashedSize);
        eError error = e_ERROR_NONE;
        TLENGTH count;
        
        if (0 <= (count = hash.Initialize()))
        {
            if (0 < (length))
                hash.Hash(buffer, length);
            
            if (0 < (count = hash.Finalize(hashed, hashedSize)))
            {
                cTCHARS::ToX(hashedText, hashed, count);
                m_hashControl.SetText(hashedText);
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: CryptoHash
     *
     *   Author: $author$
     *     Date: 7/29/2010
     **********************************************************************
     */
    virtual cCryptoHashInterface& CryptoHash
    (TCHAR*& hashedText,
     BYTE*& hashed,
     TSIZE& hashedSize) const
     = 0;
    /*{
        cCryptoHashInterface& cryptoHash = (cCryptoHashInterface&)(m_hash);
        hashedText = (TCHAR*)(m_hashedText);
        hashed = (BYTE*)(m_hashed);
        hashedSize = (TSIZE)(sizeof(m_hashed));
        return cryptoHash;
    }*/

    /**
     **********************************************************************
     *  Function: OnAfterCreateWindowRegion
     *
     *    Author: $author$
     *      Date: 7/31/2010
     **********************************************************************
     */
    virtual HRGN OnAfterCreateWindowRegion
    (HRGN hRgn, RECT& rect)
    {
        //HRGN hRgnAttached;
        eError error;
        
        //if (hRgn == (hRgnAttached = m_objectRegionImage.Attached()))
        if (!(error = m_objectBrushRegion.CreateRect(0,0, 1,1)))
        {
            cKeyIconImageObject kiio
            (m_objectRegionImage, m_objectRegionBrush, 
             m_objectRegionBrush, m_objectRegionBrush, 
             m_iconWidth, m_iconHeight);
            
            kiio.Plot(m_iconX,m_iconY);
            m_objectBrushRegion.Destroy(true);
        }
        return hRgn;
    }
    /**
     **********************************************************************
     * Function: OnBeforePaintFrame
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual LRESULT OnBeforePaintFrame
    (HWND hWnd, HDC hDC, RECT& rect, RECT& paintRect)
    {
        LRESULT lResult = 0;
        HBRUSH hBrush;
        RECT rectIcon;
        
        if ((hBrush = m_fgBrush.Attached()))
        {
            rectIcon.left = m_iconX;
            rectIcon.top = m_iconY;
            rectIcon.right = m_iconX+m_iconWidth+m_iconBorder*2;
            rectIcon.bottom = m_iconY+m_iconHeight+m_iconBorder*2;
            FillRect(hDC, &rectIcon, hBrush);
        }     
        return lResult;
    }
    /**
     **********************************************************************
     * Function: OnAfterPaintFrame
     *
     *   Author: $author$
     *     Date: 7/31/2010
     **********************************************************************
     */
    virtual LRESULT OnAfterPaintFrame
    (HWND hWnd, HDC hDC, RECT& rect, RECT& paintRect)
    {
        LRESULT lResult = 0;        
        HDC hIDC = m_imageDC.SelectAttached(hDC);
        cKeyIconImageObject kiio
        (m_image, m_imageBlack, m_imageGray, 
         m_imageBlack, m_iconWidth, m_iconHeight);
        const TCHAR* caption;
        TLENGTH captionLength;
        SIZE captionExtent;
        COLORREF bgColor;
        
        kiio.Plot
        (m_iconX+m_iconBorder, 
         m_iconY+m_iconBorder);
        
        if ((caption = GetCaption(captionLength)))
        if ((GetTextExtentPoint
            (hDC, caption, captionLength, &captionExtent)))
        {
            if (captionExtent.cy < (m_cornerRadius-m_borderThickness))
                captionExtent.cy += ((m_cornerRadius-m_borderThickness-captionExtent.cy)/2);
                
            bgColor = SetBkColor(hDC, m_bgColor.Attached());
            
            TextOut
            (hDC, m_iconX+m_iconWidth, 
             m_topMargin+m_cornerRadius-captionExtent.cy, 
             caption, captionLength);
             
            SetBkColor(hDC, bgColor);
        }
        m_imageDC.SelectAttached(hIDC);
        return lResult;
    }
#else /* !defined(CWINCRYPTOHASHMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINCRYPTOHASHMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINCRYPTOHASHMAINWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: On_WM_COMMAND_OK_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/29/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_COMMAND_OK_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = FALSE;
        const TCHAR nullChar = 0;
        const TCHAR* text;
        const BYTE* buffer;
        TLENGTH textLength;
        
        m_hashControl.SetText(&nullChar);
        
        if (!((text = m_textControl.GetText(textLength)) 
              && (0 < (textLength))))
              
        if ((text = m_fileControl.GetText(textLength)) 
             && (0 < (textLength)))
        {
            HashFile(text);
            return lResult;
        }
            
        if ((text = m_textControl.GetText(textLength)))
        {
            m_fileControl.SetText(&nullChar);
            
            if (0 < (m_unicodeControl.GetIsChecked()))
            {
                if (0 <= (m_unicodeText.AssignTChars(text, textLength)))
                if ((buffer = (const BYTE*)(m_unicodeText.Chars(textLength))))
                    Hash(buffer, textLength*sizeof(WCHAR));
            }
            else
            {
                if (0 <= (m_text.AssignTChars(text, textLength)))
                if ((buffer = m_text.Chars(textLength)))
                    Hash(buffer, textLength);
            }
        }            
        //lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_COMMAND_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/29/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_COMMAND_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = FALSE;
        switch(LOWORD(wParam))
        {
        case e_HASH_WINDOW_IDC_OK:
            lResult = On_WM_COMMAND_OK_WindowMessage
            (hWnd, msg, wParam, lParam);
            break;

        case e_HASH_WINDOW_IDC_CANCEL:
            m_quit = true;
            DestroyWindow(hWnd);
            break;
        }
        //lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_DROPFILES_WindowMessage
     *
     *   Author: $author$
     *     Date: 7/29/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_DROPFILES_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = FALSE;
        TCHAR nullChar = 0;
        HDROP hDrop;
        TLENGTH count, length;
        const TCHAR* fileNameTChars;
        const CHAR* fileNameChars;
        eError error;
        
        m_hashControl.SetText(&nullChar);
        m_fileControl.SetText(&nullChar);
        m_textControl.SetText(&nullChar);

        if ((hDrop = (HDROP)(wParam)))
        if (0 < (count = m_dropFiles.Open(hDrop)))
        {
            if ((fileNameTChars = m_dropFiles.GetFirstFileName(length)))
            if (!(error = m_fileControl.SetText(fileNameTChars)))
                PostMessage(hWnd, WM_COMMAND, e_HASH_WINDOW_IDC_OK, 0);

            m_dropFiles.Close();
        }
        //lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: ChangeDefaultWindowPosition
     *
     *   Author: $author$
     *     Date: 7/29/2010
     **********************************************************************
     */
    virtual eError ChangeDefaultWindowPosition
    (int& x, int& y) const
    {
        eError error = e_ERROR_NONE;
        x = 100;
        y = 100;
        return error;
    }
    /**
     **********************************************************************
     * Function: ChangeDefaultWindowSize
     *
     *   Author: $author$
     *     Date: 7/29/2010
     **********************************************************************
     */
    virtual eError ChangeDefaultWindowSize
    (int& width, int& height) const
    {
        eError error = e_ERROR_NONE;
        width = 600;
        height = 200;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnMainWindowCreated
     *
     *   Author: $author$
     *     Date: 7/28/2010
     **********************************************************************
     */
    virtual eError OnMainWindowCreated
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        TCHAR* hashedText = 0;
        BYTE* hashed = 0;
        TSIZE hashedSize = 0;
        cCryptoHashInterface& hash = CryptoHash
        (hashedText, hashed, hashedSize);
        eError error = e_ERROR_NONE;
        eError error2;
        HWND hWnd;
        HWND hCtl;
        HDC hDC;
        RECT r;
        RECT r2;
        SIZE sz;
        TEXTMETRIC tm;
        const CHAR* cmdArgChars;
        TLENGTH cmdArgLength;
        
        if ((hWnd = Attached()))
        if (!(error2 = GetClientRect(r)))
        {
            int x = (r.left);
            int y = (r.top);
            int w = (r.right-r.left);
            int h = (r.bottom-r.top)/2;
            int n;

            if ((m_captionChars))
                SetCaption(m_captionChars);
                
            DragAcceptFiles(hWnd, TRUE);
            
            m_hashControl.AddStyle(ES_READONLY | ES_CENTER);
            if ((hCtl = m_hashControl.CreateAttached
                (error2, hInstance, hWnd, e_HASH_WINDOW_IDC_HASH, x,y, w,h)))
            if ((hDC = GetDC(hCtl)))
            {
                if ((GetTextExtentPoint(hDC, _T("X"),1, &sz)))
                {
                    w = sz.cx*((hashedSize*2)+4);
                    h = sz.cy;
                }
                /*
                if ((GetTextMetrics(hDC, &tm)))
                {
                    w = tm.tmMaxCharWidth*(hashedSize*2);
                    h = tm.tmHeight;
                }
                */
                ReleaseDC(hCtl, hDC);
                
                if (!(error2 = m_hashControl.GetClientBorderRect(r)))
                {
                    w += (r.left + r.right);
                    h += (r.top + r.bottom);
                }
                
                m_hashControl.SizeTo(w,h);
            }
            
            x += (w+m_controlSpacing);
            
            if ((hCtl = m_okControl.CreateAttached
                (error2, hInstance, hWnd, 
                 e_HASH_WINDOW_IDC_OK, x,y, w,h, m_okChars)))
            if (!(error2 = m_okControl.GetClientBorderRect(r)))
            if ((hDC = GetDC(hCtl)))
            {
                if ((GetTextExtentPoint
                    (hDC, m_okChars, m_ok.Length(), &sz)))
                {
                    sz.cx += (r.left+r.right)+10;
                    if (h > (sz.cy += (r.top+r.bottom)+10))
                        sz.cy = h;
                    
                    m_okControl.SizeTo(sz.cx,sz.cy);
                    
                    if (h < sz.cy)
                    {
                        h = sz.cy;
                        m_hashControl.SizeTo(w,h);
                    }
                }
                ReleaseDC(hCtl, hDC);
            }
            
            x -= (w+m_controlSpacing);
            y += (h+m_controlSpacing);
            
            m_fileControl.AddStyle(ES_CENTER);
            if ((hCtl = m_fileControl.CreateAttached
                (error2, hInstance, hWnd, 
                 e_HASH_WINDOW_IDC_FILE, x,y, w,h)))
            {
                if ((cmdArgChars = FirstCmdLineArg(cmdArgLength)))
                if ((0 < cmdArgLength))
                if (!(error2 = m_fileControl.SetText
                    (cmdArgChars, cmdArgLength)))
                    PostMessage
                    (hWnd, WM_COMMAND, e_HASH_WINDOW_IDC_OK, 0);
            }
            
            x += w+m_controlSpacing;
            
            if ((hCtl = m_cancelControl.CreateAttached
                (error2, hInstance, hWnd, 
                 e_HASH_WINDOW_IDC_CANCEL, x,y, w,h, m_cancelChars)))
            if (!(error2 = m_cancelControl.GetClientBorderRect(r)))
            if ((hDC = GetDC(hCtl)))
            {
                if ((GetTextExtentPoint
                    (hDC, m_cancelChars, m_cancel.Length(), &sz)))
                {
                    sz.cx += (r.left+r.right)+10;
                    if (h > (sz.cy += (r.top+r.bottom)+10))
                        sz.cy = h;
                    
                    m_cancelControl.SizeTo(sz.cx,sz.cy);
                    
                    if (!(error2 = m_okControl.GetWindowRect(r)))
                    if (sz.cx > (r.right - r.left))
                        m_okControl.SizeTo(sz.cx,sz.cy);              
                }
                ReleaseDC(hCtl, hDC);
            }
            
            x -= (w+m_controlSpacing);
            y += (h+m_controlSpacing);
            
            m_textControl.AddStyle(ES_MULTILINE);
            if ((hCtl = m_textControl.CreateAttached
                (error2, hInstance, hWnd, 
                 e_HASH_WINDOW_IDC_TEXT, x,y, w,h*2)))
            {
            }
            
            x += w+m_controlSpacing;
            
            if ((hCtl = m_unicodeControl.CreateAttached
                (error2, hInstance, hWnd, 
                 e_HASH_WINDOW_IDC_UNICODE, x,y, w,h, m_unicodeChars)))
            if (!(error2 = m_unicodeControl.GetClientBorderRect(r)))
            if ((hDC = GetDC(hCtl)))
            {
                //sz.cx = GetSystemMetrics(SM_CXEDGE);
                //sz.cy = GetSystemMetrics(SM_CYEDGE);
                
                if ((GetTextExtentPoint
                    (hDC, m_unicodeChars, m_unicode.Length(), &sz)))
                {
                    sz.cx += GetSystemMetrics(SM_CXMENUCHECK);
                    if (sz.cy < (n = GetSystemMetrics(SM_CYMENUCHECK)))
                        sz.cy = n;
                
                    sz.cx += (r.left+r.right);
                    sz.cy += (r.top+r.bottom);
                    
                    m_unicodeControl.SizeTo(sz.cx,sz.cy);
                }
                ReleaseDC(hCtl, hDC);
                
                if (!(error2 = m_unicodeControl.GetWindowRect(r)))
                {
                    sz.cx = (r.right-r.left);
                    
                    if (!(error2 = m_cancelControl.GetWindowRect(r)))
                    if (sz.cx > (sz.cy = (r.right-r.left)))
                    {
                        m_okControl.SizeTo(sz.cx, (r.bottom-r.top));
                        m_cancelControl.SizeTo(sz.cx, (r.bottom-r.top));
                    }
                }
            }
            
            //return error;
            
            if (!(error2 = m_hashControl.GetWindowRect(r)))
            {
                w = (r.right - r.left);
                h = (r.bottom - r.top);
                
                if (!(error2 = m_fileControl.GetWindowRect(r)))
                    h += (r.bottom - r.top)+m_controlSpacing;

                if (!(error2 = m_textControl.GetWindowRect(r)))
                    h += (r.bottom - r.top)+m_controlSpacing;

                if (!(error2 = m_cancelControl.GetWindowRect(r)))
                    w += (r.right - r.left)+m_controlSpacing;

                if (!(error2 = GetClientBorderRect(r)))
                {
                    w += (r.left + r.right);
                    h += (r.top + r.bottom);
                    
                    if (!(error2 = GetWindowRect(r)))
                        Move(r.left,r.top, w,h, TRUE);
                }
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnMainWindowDestroy
     *
     *   Author: $author$
     *     Date: 7/28/2010
     **********************************************************************
     */
    virtual eError OnMainWindowDestroy
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    
    /**
     **********************************************************************
     * Function: OnInitializedMainWindowClass
     *
     *   Author: $author$
     *     Date: 7/28/2010
     **********************************************************************
     */
    virtual eError OnInitializedMainWindowClass
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        m_editWindowClass.Register(hInstance);
        m_checkBoxWindowClass.Register(hInstance);
        m_pushButtonWindowClass.Register(hInstance);
        //m_fgBrush.CreateSolid(m_fgColor.Attached());
        return error;
    }
    /**
     **********************************************************************
     * Function: OnFinalizeMainWindowClass
     *
     *   Author: $author$
     *     Date: 7/28/2010
     **********************************************************************
     */
    virtual eError OnFinalizeMainWindowClass
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        m_pushButtonWindowClass.Unregister();
        m_checkBoxWindowClass.Unregister();
        m_editWindowClass.Unregister();
        return error;
    }
};

#if !defined(CWINCRYPTOHASHMAINWINDOWDERIVE_MEMBERS_ONLY)
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
#else /* !defined(CWINCRYPTOHASHMAINWINDOWDERIVE_MEMBERS_ONLY) */
#endif /* !defined(CWINCRYPTOHASHMAINWINDOWDERIVE_MEMBERS_ONLY) */

#if !defined(CWINMD5MAINWINDOW_MEMBERS_ONLY)
#else /* !defined(CWINMD5MAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMD5MAINWINDOW_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCRYPTOHASHMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINCRYPTOHASHMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINCRYPTOHASHMAINWINDOW_HXX) || defined(CWINCRYPTOHASHMAINWINDOW_MEMBERS_ONLY) */
