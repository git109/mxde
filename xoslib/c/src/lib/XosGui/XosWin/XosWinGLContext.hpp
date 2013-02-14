///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2011 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: XosWinGLContext.hpp
///
/// Author: $author$
///   Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSWINGLCONTEXT_HPP) || defined(XOSWINGLCONTEXT_MEMBERS_ONLY)
#if !defined(_XOSWINGLCONTEXT_HPP) && !defined(XOSWINGLCONTEXT_MEMBERS_ONLY)
#define _XOSWINGLCONTEXT_HPP
#endif // !defined(_XOSWINGLCONTEXT_HPP) && !defined(XOSWINGLCONTEXT_MEMBERS_ONLY) 

#if !defined(XOSWINGLCONTEXT_MEMBERS_ONLY)
#include "XosWinHGLRCAttached.hpp"

#define GL_BGR GL_BGR_EXT
#define GL_BGRA GL_BGRA_EXT

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinGLContextImplement
///
///  Author: $author$
///    Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
typedef XosWinHGLRCCreatedAttachedImplement
XosWinGLContextImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinGLContextExtend
///
///  Author: $author$
///    Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
typedef XosWinHGLRCCreatedAttached
XosWinGLContextExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinGLContext
///
/// Author: $author$
///   Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosWinGLContext
: virtual public XosWinGLContextImplement,
  public XosWinGLContextExtend
{
public:
    typedef XosWinGLContextImplement Implements;
    typedef XosWinGLContextExtend Extends;

    HDC m_hDC;
    HWND m_hWnd;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinGLContext
    ///
    ///       Author: $author$
    ///         Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    XosWinGLContext
    (HWND hWnd=NULL,
     HDC hDC=NULL,
     HGLRC attached=NULL,
     bool isCreated=false)
    : Extends(attached, isCreated),
      m_hDC(hDC),
      m_hWnd(hWnd)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinGLContext
    ///
    ///      Author: $author$
    ///        Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinGLContext()
    {
        XosError error;
        if ((error = Destroyed()))
            throw(error);
    }
#else // !defined(XOSWINGLCONTEXT_MEMBERS_ONLY) 
#endif // !defined(XOSWINGLCONTEXT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create
    (HWND hWnd)
#if defined(XOSWINGLCONTEXT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSWINGLCONTEXT_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSWINGLCONTEXT_MEMBER_FUNCS_IMPLEMENT)
        HDC hDC;

        if ((error = Destroyed()))
            return error;

        if ((hDC = GetDC(hWnd)))
        {
            if (!(error = Create(hDC)))
            {
                m_hWnd = hWnd;
                return error;
            }
            ReleaseDC(hWnd, hDC);
        }
#else // !defined(XOSWINGLCONTEXT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSWINGLCONTEXT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSWINGLCONTEXT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create
    (HDC hDC)
#if defined(XOSWINGLCONTEXT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSWINGLCONTEXT_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSWINGLCONTEXT_MEMBER_FUNCS_IMPLEMENT)
        HGLRC detached;

        if ((error = Destroyed()))
            return error;

        //-- Set up pixel format for graphics initialization
        PIXELFORMATDESCRIPTOR pfd, *ppfd;
        int pixelformat;

        ppfd = &pfd;

        ppfd->nSize = sizeof(PIXELFORMATDESCRIPTOR);
        ppfd->nVersion = 1;
        ppfd->dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        ppfd->dwLayerMask = PFD_MAIN_PLANE;
        ppfd->iPixelType = PFD_TYPE_COLORINDEX;
        ppfd->cColorBits = 16;
        ppfd->cDepthBits = 16;
        ppfd->cAccumBits = 0;
        ppfd->cStencilBits = 0;

        pixelformat = ChoosePixelFormat(hDC, ppfd);
        SetPixelFormat(hDC, pixelformat, ppfd);
        //-- Pixel format

        if ((detached = wglCreateContext(hDC)))
        {
            if ((wglMakeCurrent(hDC, detached)))
            {
                Attach(detached);
                SetIsCreated();
                m_hDC = hDC;
                return error = XOS_ERROR_NONE;
            }
        }
#else // !defined(XOSWINGLCONTEXT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSWINGLCONTEXT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSWINGLCONTEXT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroy(bool onlyCreated=false)
#if defined(XOSWINGLCONTEXT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSWINGLCONTEXT_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSWINGLCONTEXT_MEMBER_FUNCS_IMPLEMENT)
        HWND hWnd = m_hWnd;
        HDC hDC = m_hDC;
        HGLRC detached;

        m_hWnd = NULL;
        m_hDC = NULL;
        error = XOS_ERROR_NONE;

        if ((detached = Detach()))
        {
            wglMakeCurrent(NULL, NULL);

            if (!(wglDeleteContext(detached)))
                error = XOS_ERROR_FAILED;
        }

        if ((hWnd))
            ReleaseDC(hWnd, hDC);
#else // !defined(XOSWINGLCONTEXT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSWINGLCONTEXT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSWINGLCONTEXT_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSWINGLCONTEXT_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSWINGLCONTEXT_MEMBERS_ONLY) 
#endif // !defined(XOSWINGLCONTEXT_MEMBERS_ONLY) 

#endif // !defined(_XOSWINGLCONTEXT_HPP) || defined(XOSWINGLCONTEXT_MEMBERS_ONLY) 
        

