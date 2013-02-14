///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2013 $organization$
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
///   File: XosXOpenGLContext.hpp
///
/// Author: $author$
///   Date: 2/7/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXOPENGLCONTEXT_HPP
#define _XOSXOPENGLCONTEXT_HPP

#include "XosPlatform_X11_Xlib.hpp"
#include "XosPlatform_GL_gl.hpp"
#include "XosPlatform_GL_glu.hpp"
#include "XosPlatform_GL_glx.hpp"
#include "XosOpenGLContext.hpp"

#if defined(_NAMESPACE)
namespace _NAMESPACE {
#endif // defined(_NAMESPACE) 

typedef XosOpenGLContextImplement XosXOpenGLContextImplement;
typedef XosOpenGLContext XosXOpenGLContextExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXOpenGLContext
///
/// Author: $author$
///   Date: 2/7/2013
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXOpenGLContext
: virtual public XosXOpenGLContextImplement,
  public XosXOpenGLContextExtend
{
public:
    typedef XosXOpenGLContextImplement Implements;
    typedef XosXOpenGLContextExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXOpenGLContext
    ///
    ///       Author: $author$
    ///         Date: 2/7/2013
    ///////////////////////////////////////////////////////////////////////
    XosXOpenGLContext()
    : m_xDisplay(0),
      m_xWindow(None),
      m_glxContext(0)
    {
    }
    virtual ~XosXOpenGLContext()
    {
        Finish();
    }

    virtual bool Init(Display* xDisplay, Window xWindow)
    {
        GLint att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
        bool isSuccess = false;
        int screen = 0;
        XVisualInfo* vi;
        Status success;
        XWindowAttributes watt;

        XOS_DBT(("() in...\n"));

        if ((xDisplay) && (None != (xWindow)))
        {
            if (!(success = XGetWindowAttributes(xDisplay, xWindow, &watt)))
            {   XOS_DBE(("() failed on XGetWindowAttributes()\n")); }
            else
            screen = XScreenNumberOfScreen(watt.screen);

            if (!(vi = glXChooseVisual(xDisplay, screen, att)))
            {   XOS_DBE(("() failed on glXChooseVisual()\n")); }
            else
            if (None != (m_glxContext = glXCreateContext(xDisplay, vi, NULL, GL_TRUE)))
            {
                if (!(glXMakeCurrent(xDisplay, xWindow, m_glxContext)))
                {   XOS_DBE(("() failed on glXMakeCurrent()\n")); }
                else
                {
                    m_xDisplay = xDisplay;
                    m_xWindow = xWindow;
                    return true;
                }
                glXDestroyContext(m_xDisplay, m_glxContext);
                m_glxContext = 0;
            }
            else
            {   XOS_DBE(("() failed on glXCreateContext()\n")); }
        }
        XOS_DBT(("() ...out\n"));
        return isSuccess;
    }
    virtual bool Finish()
    {
        bool isSuccess = false;

        XOS_DBT(("()...\n"));

        if ((m_xDisplay) && (m_glxContext))
        {
            if (!(glXMakeCurrent(m_xDisplay, None, 0)))
            {   XOS_DBE(("() failed on glXMakeCurrent()\n")); }
            else
            isSuccess = true;
            glXDestroyContext(m_xDisplay, m_glxContext);
        }
        m_glxContext = 0;
        m_xWindow = None;
        m_xDisplay = 0;
        return isSuccess;
    }
    virtual bool SwapBuffers()
    {
        bool isSuccess = false;

        XOS_DBT(("()...\n"));

        if ((m_xDisplay) && (None != (m_xWindow)))
        {
            glXSwapBuffers(m_xDisplay, m_xWindow);
            isSuccess = true;
        }
        return isSuccess;
    }

protected:
    Display* m_xDisplay;
    Window m_xWindow;
    GLXContext m_glxContext;
};

#if defined(_NAMESPACE)
}
#endif // defined(_NAMESPACE) 

#endif // _XOSXOPENGLCONTEXT_HPP 
