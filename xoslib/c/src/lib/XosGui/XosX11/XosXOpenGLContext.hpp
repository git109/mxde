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
///   Date: 1/3/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXOPENGLCONTEXT_HPP
#define _XOSXOPENGLCONTEXT_HPP

#include "XosInterfaceBase.hpp"
#include "XosExportBase.hpp"
#include "XosPlatform_X11_Xlib.hpp"
#include "XosPlatform_GL_gl.hpp"
#include "XosPlatform_GL_glu.hpp"
#include "XosPlatform_GL_glx.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

typedef XosInterfaceBase
XosXOpenGLContextImplement;

typedef XosExportBase
XosXOpenGLContextExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXOpenGLContext
///
/// Author: $author$
///   Date: 1/3/2013
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXOpenGLContext
: virtual public XosXOpenGLContextImplement,
  public XosXOpenGLContextExtend
{
public:
    typedef XosXOpenGLContextImplement Implements;
    typedef XosXOpenGLContextExtend Extends;

    XosXOpenGLContext()
    : m_dpy(0),
      m_win(None),
      m_glc(0)
    {
    }
    virtual ~XosXOpenGLContext()
    {
        if (!(Finish()))
            XOS_DBE(("() failed on Finish()\n"));
    }

    virtual bool Init(Display* dpy, Window win)
    {
        Status success;
        int screen;
        GLint* gatt;
        XVisualInfo* vi;
        XWindowAttributes watt;

        XOS_DBT(("()...\n"));

        if ((dpy) && (None != (win)) && (gatt = GetChooseVisualAttributes()))
        {
            if ((!(success = XGetWindowAttributes(dpy, win, &watt))))
            {   XOS_DBE(("() failed on XGetWindowAttributes()\n")); }
            else
            screen = XScreenNumberOfScreen(watt.screen);

            if (!(vi = glXChooseVisual(dpy, screen, gatt)))
            {   XOS_DBE(("() failed on glXChooseVisual()\n")); }
            else
            if (None != (m_glc = glXCreateContext(dpy, vi, NULL, GL_TRUE)))
            {
                if (!(glXMakeCurrent(dpy, win, m_glc)))
                {   XOS_DBE(("() failed on glXMakeCurrent()\n")); }
                else
                {
                    m_dpy = dpy;
                    m_win = win;
                    return true;
                }
                glXDestroyContext(m_dpy, m_glc);
                m_glc = 0;
            }
            else
            {   XOS_DBE(("() failed on glXCreateContext()\n")); }
        }
        return false;
    }
    virtual bool Finish()
    {
        bool isSuccess = !((m_dpy) || (m_glc));

        XOS_DBT(("()...\n"));

        if ((m_dpy) && (m_glc))
        {
            if (!(glXMakeCurrent(m_dpy, None, 0)))
            {   XOS_DBE(("() failed on glXMakeCurrent()\n")); }
            else
            isSuccess = true;
            glXDestroyContext(m_dpy, m_glc);
        }
        m_glc = 0;
        m_win = None;
        m_dpy = 0;
        return isSuccess;
    }

protected:
    virtual GLint* GetChooseVisualAttributes() const
    {
        static GLint glattr[] = 
        { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
        return glattr;
    }

protected:
    Display* m_dpy;
    Window m_win;
    GLXContext m_glc;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXOPENGLCONTEXT_HPP 
