///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
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
///   File: XosXHelloMain.hpp
///
/// Author: $author$
///   Date: 5/28/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXHELLOMAIN_HPP
#define _XOSXHELLOMAIN_HPP

#include "XosXWindowMain.hpp"
#include "XosXWindowTexture2DImageRenderer.hpp"

#define XOSMACHELLO_DEFAULT_IMAGE_FILENAME "image.raw"
#define XOSMACHELLO_DEFAULT_IMAGE_WIDTH 352
#define XOSMACHELLO_DEFAULT_IMAGE_HEIGHT 288
#define XOSMACHELLO_DEFAULT_IMAGE_DEPTH 4

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

typedef XosXWindow XosXHelloMainWindowExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXHelloMainWindow
///
/// Author: $author$
///   Date: 6/20/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXHelloMainWindow
: public XosXHelloMainWindowExtend
{
public:
    typedef XosXHelloMainWindowExtend Extends;
    typedef XosXHelloMainWindow Derives;
    typedef void (Derives::*MRender)();

    void* m_image;
    const char* m_imageFile;
    unsigned m_imageWidth, m_imageHeight, m_imageDepth, m_imageSize;
    MRender m_render;
    XosXWindowTexture2DImageRenderer m_glRenderer;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXHelloMainWindow
    ///
    ///       Author: $author$
    ///         Date: 2/7/2013
    ///////////////////////////////////////////////////////////////////////
    XosXHelloMainWindow()
    {
        m_image = 0;
        m_imageSize=0;
        m_imageFile = XOSMACHELLO_DEFAULT_IMAGE_FILENAME;
        m_imageWidth = XOSMACHELLO_DEFAULT_IMAGE_WIDTH; 
        m_imageHeight = XOSMACHELLO_DEFAULT_IMAGE_HEIGHT; 
        m_imageDepth = XOSMACHELLO_DEFAULT_IMAGE_DEPTH;
        m_render = &Derives::RenderIn;
    }
    virtual ~XosXHelloMainWindow()
    {
        FreeImage();
    }

    ///////////////////////////////////////////////////////////////////////
    // Events
    ///////////////////////////////////////////////////////////////////////
    virtual void OnCreate(int argc, char** argv, char** env) 
    {
        if ((optind < argc))
            m_imageFile = argv[optind];

        if (!(LoadImageFile(m_imageFile)))
            return;

        if ((m_glRenderer.Init(m_xDisplay, m_xWindow))) {
            m_glRenderer.Prepare();
        } else {
            XOS_DBE(("() failed on m_glRenderer.Init()\n"));
            FreeImage();
        }
    }
    virtual void OnDestroy(int argc, char** argv, char** env) 
    {
        if (!(m_glRenderer.Finish())) {
            XOS_DBI(("() failed on m_glRenderer.Finish()\n"));
        }
        FreeImage();
    }

    ///////////////////////////////////////////////////////////////////////
    // XEvents
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnButtonReleaseXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
        XOS_DBI(("()...\n"));
        if ((m_render == &Derives::RenderIn)) {
            m_render = &Derives::Render;
            Invalidate();
        } else {
            if ((m_render == &Derives::Render)) {
                m_render = &Derives::RenderRaw;
                Invalidate();
            } else {
                m_render = &Derives::RenderIn;
                Invalidate();
            }
        }
        return error;
    }
    virtual XosError OnConfigureNotifyXEvent(const XEvent& xEvent) 
    {
        const XConfigureEvent& xConfigureEvent = (const XConfigureEvent&)(xEvent);
        XosError error = XOS_ERROR_NONE;
        XOS_DBI(("() width=%d height=%d ...\n", xConfigureEvent.width, xConfigureEvent.height));
        if ((m_image)) {
            m_glRenderer.Reshape(xConfigureEvent.width, xConfigureEvent.height);
            Invalidate(0,0, xConfigureEvent.width, xConfigureEvent.height);
        }
        return error;
    }
    virtual XosError OnExposeXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
        if ((m_render))
            (this->*m_render)();
        else
        RenderIn();
        return error;
    }
    virtual void Render() {
        if ((m_image)) {
            m_glRenderer.Render
            (m_image, m_imageWidth, m_imageHeight);
            m_glRenderer.SwapBuffers();
        }
    }
    virtual void RenderIn() {
        if ((m_image)) {
            m_glRenderer.Render
            (m_image, m_imageWidth, m_imageHeight,
             m_image, m_imageWidth, m_imageHeight);
            m_glRenderer.SwapBuffers();
        }
    }
    virtual void RenderRaw() {
        if ((m_image)) {
            m_glRenderer.RenderRaw
            (m_image, m_imageWidth, m_imageHeight);
            m_glRenderer.SwapBuffers();
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void* LoadImageFile(const char* chars) {
        if ((chars) && (chars != m_imageFile))
            m_imageFile = chars;

        if ((m_imageFile)) {
            m_imageSize = (m_imageWidth*m_imageHeight*m_imageDepth);
            if ((m_image = malloc(m_imageSize))) {
                FILE* file = 0;
                size_t count = 0;
                if ((file = fopen(m_imageFile, "rb"))) {
                    count = fread(m_image, m_imageSize, 1, file);
                    fclose(file);
                    if (1 > (count)) {
                        XOS_DBE(("failed on fread() of \"%s\"\n", m_imageFile));
                        free(m_image);
                        m_image = 0;
                        m_imageSize = 0;
                    }
                } else {
                    XOS_DBE(("failed on fopen(\"%s\",...)\n", m_imageFile));
                    free(m_image);
                    m_image = 0;
                    m_imageSize = 0;
                }
            } else {
                XOS_DBE(("failed on malloc(%d)\n", m_imageSize));
                m_imageSize = 0;
            }
        }
        return m_image;
    }
    virtual void FreeImage() {
        if ((m_image)) {
            free(m_image);
            m_image = 0;
            m_imageSize = 0;
        }
    }
    virtual void Invalidate() {
        XWindowAttributes xWindowAttributes;
        XosError error;
        if (!(error = GetWindowAttributes(xWindowAttributes))) {
            Invalidate(0,0, xWindowAttributes.width,xWindowAttributes.height);
        }
    }
    virtual void Invalidate(int x,int y, int width,int height) {
        XosXExposeEvent xExposeEvent(m_xDisplay, m_xWindow, x,y, width,height);
        xExposeEvent.Send();
    }
};

typedef XosXWindowMainImplement XosXHelloMainImplement;
typedef XosXWindowMain XosXHelloMainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXHelloMain
///
/// Author: $author$
///   Date: 5/28/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXHelloMain
: virtual public XosXHelloMainImplement,
  public XosXHelloMainExtend
{
public:
    typedef XosXHelloMainImplement Implements;
    typedef XosXHelloMainExtend Extends;

    XosXHelloMainWindow m_mainWindow;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXHelloMain
    ///
    ///       Author: $author$
    ///         Date: 5/28/2012
    ///////////////////////////////////////////////////////////////////////
    XosXHelloMain()
    {
    }
    virtual ~XosXHelloMain()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Create/Destroy MainWindow
    ///////////////////////////////////////////////////////////////////////
    virtual XosXWindowInterface* CreateMainWindow
    (Display& xDisplay, Window xWindow, 
     int argc, char** argv, char** env)
    {
        XosXWindowInterface* mainWindow = 0;
        XosError error;
        if (!(error = m_mainWindow.CreateSimple
            (xDisplay, xWindow, 
             m_mainWindowX,m_mainWindowY, m_mainWindowWidth,m_mainWindowHeight, 
             m_mainWindowBorderWidth, m_mainWindowBorderColor, m_mainWindowBackgroundColor))) 
        {
            mainWindow = &m_mainWindow;
            m_mainWindow.OnCreate(argc, argv, env);
        }
        return mainWindow;
    }
    virtual int DestroyMainWindow
    (XosXWindowInterface* mainWindow,
     int argc, char** argv, char** env)
    {
        int err = 1;
        XosError error;
        if ((mainWindow == &m_mainWindow))
        {
            m_mainWindow.OnDestroy(argc, argv, env);
            if (!(error = m_defaultMainWindow.Destroy()))
                err = 0;
        }
        return err;
    }
    virtual Pixel GetMainWindowBackgroundColor() const {
        return RedColor();
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXHELLOMAIN_HPP 
