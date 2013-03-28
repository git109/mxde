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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 3/24/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_X11_HELLO_MAIN_HPP
#define _XOS_GUI_X11_HELLO_MAIN_HPP

#include "xos/gui/x11/WindowMain.hpp"
#include "xos/gui/x11/MainWindow.hpp"
#include "xos/gui/x11/Window.hpp"
#include "xos/gui/opengl/x11/Context.hpp"
#include "xos/gui/opengl/x11/ImageRenderer.hpp"
#include "xos/gui/opengl/ImageRenderer.hpp"

#define XOS_GUI_X11_HELLO_DEFAULT_IMAGE_FILENAME "image.raw"
#define XOS_GUI_X11_HELLO_DEFAULT_IMAGE_WIDTH 352
#define XOS_GUI_X11_HELLO_DEFAULT_IMAGE_HEIGHT 288
#define XOS_GUI_X11_HELLO_DEFAULT_IMAGE_DEPTH 4

namespace xos {
namespace x11 {
namespace hello {

typedef x11::MainWindowImplement MainWindowImplement;
typedef x11::MainWindow MainWindowExtend;
///////////////////////////////////////////////////////////////////////
///  Class: MainWindow
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MainWindow
: virtual public MainWindowImplement, public MainWindowExtend {
public:
    typedef MainWindowImplement Implements;
    typedef MainWindowExtend Extends;
    typedef MainWindow Derives;
    typedef void (Derives::*MRender)();
    typedef bool (Derives::*MOnButtonReleaseXEvent)(const XEvent& xEvent);

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: MainWindow
    ///////////////////////////////////////////////////////////////////////
    MainWindow(WindowMain& main)
    : m_main(main), m_onButtonReleaseXEvent(0) {
        m_image = 0;
        m_imageSize = 0;
        m_imageFile = XOS_GUI_X11_HELLO_DEFAULT_IMAGE_FILENAME;
        m_imageWidth = XOS_GUI_X11_HELLO_DEFAULT_IMAGE_WIDTH; 
        m_imageHeight = XOS_GUI_X11_HELLO_DEFAULT_IMAGE_HEIGHT; 
        m_imageDepth = XOS_GUI_X11_HELLO_DEFAULT_IMAGE_DEPTH;
    }
    virtual ~MainWindow() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnCreate(int argc, char** argv, char** env) {
        XDisplay* xDisplay;
        XWindow xWindow;
        if ((xDisplay = m_display) && (xWindow = m_attachedTo)) {
            if ((optind < argc))
                m_imageFile = argv[optind];

            if ((LoadImageFile(m_imageFile))) {
                if ((m_glRenderer.Init(xDisplay, xWindow))) {
                    m_glRenderer.Prepare();
                } else {
                    XOS_LOG_ERROR("failed on m_glRenderer.Init()");
                    FreeImage();
                }
            }
        }
        return 0;
    }
    virtual int OnDestroy(int argc, char** argv, char** env) {
        if (!(m_glRenderer.Finish())) {
            XOS_LOG_ERROR("failed on m_glRenderer.Finish()");
        }
        FreeImage();
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void RenderRaw() {
        if ((m_image)) {
            m_glRenderer.RenderRaw
            (m_image, m_imageWidth, m_imageHeight);
            m_glRenderer.SwapBuffers();
        }
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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool OnConfigureNotifyXEvent(const XEvent& xEvent) {
        const XConfigureEvent& xConfigureEvent = (const XConfigureEvent&)(xEvent);
        bool isHandled = false;
        if ((m_image)) {
            m_glRenderer.Reshape(xConfigureEvent.width, xConfigureEvent.height);
            Invalidate(0,0, xConfigureEvent.width, xConfigureEvent.height);
        }
        isHandled = OnXEventDefault(xEvent);
        return isHandled;
    }
    virtual bool OnExposeXEvent(const XEvent& xEvent) {
        bool isHandled = false;
        if ((xEvent.xany.send_event)) {
            XOS_LOG_DEBUG("...");
        }
        if ((m_render))
            (this->*m_render)();
        else
        RenderRaw();
        isHandled = OnXEventDefault(xEvent);
        return isHandled;
    }
    virtual bool OnButtonPressXEvent(const XEvent& xEvent) {
        bool isHandled = false;
        XOS_LOG_DEBUG("...");
        isHandled = OnXEventDefault(xEvent);
        return isHandled;
    }
    virtual bool OnButtonReleaseXEvent(const XEvent& xEvent) {
        bool isHandled = false;
        XOS_LOG_DEBUG("...");
        if ((m_onButtonReleaseXEvent))
            isHandled = (this->*m_onButtonReleaseXEvent)(xEvent);
        else {
            isHandled = RedOnButtonReleaseXEvent(xEvent);
        }
        if ((m_render == &Derives::RenderRaw)) {
            m_render = &Derives::Render;
            Invalidate();
        } else {
            if ((m_render == &Derives::Render)) {
                m_render = &Derives::RenderIn;
                Invalidate();
            } else {
                m_render = &Derives::RenderRaw;
                Invalidate();
            }
        }
        return isHandled;
    }
    virtual bool RedOnButtonReleaseXEvent(const XEvent& xEvent) {
        bool isHandled = false;
        ChangeBackground(m_main.RedColor());
        Invalidate(true);
        m_onButtonReleaseXEvent = &Derives::GreenOnButtonReleaseXEvent;
        return isHandled;
    }
    virtual bool GreenOnButtonReleaseXEvent(const XEvent& xEvent) {
        bool isHandled = false;
        ChangeBackground(m_main.GreenColor());
        Invalidate(true);
        m_onButtonReleaseXEvent = &Derives::BlueOnButtonReleaseXEvent;
        return isHandled;
    }
    virtual bool BlueOnButtonReleaseXEvent(const XEvent& xEvent) {
        bool isHandled = false;
        ChangeBackground(m_main.BlueColor());
        Invalidate(true);
        m_onButtonReleaseXEvent = &Derives::WhiteOnButtonReleaseXEvent;
        return isHandled;
    }
    virtual bool WhiteOnButtonReleaseXEvent(const XEvent& xEvent) {
        bool isHandled = false;
        ChangeBackground(m_main.WhiteColor());
        Invalidate(true);
        m_onButtonReleaseXEvent = &Derives::BlackOnButtonReleaseXEvent;
        return isHandled;
    }
    virtual bool BlackOnButtonReleaseXEvent(const XEvent& xEvent) {
        bool isHandled = false;
        ChangeBackground(m_main.BlackColor());
        Invalidate(true);
        m_onButtonReleaseXEvent = &Derives::RedOnButtonReleaseXEvent;
        return isHandled;
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
                        XOS_LOG_ERROR("failed on fread() of \"" << m_imageFile << "\"");
                        free(m_image);
                        m_image = 0;
                        m_imageSize = 0;
                    }
                } else {
                    XOS_LOG_ERROR("failed on fopen(\"" << m_imageFile << "\",...)");
                    free(m_image);
                    m_image = 0;
                    m_imageSize = 0;
                }
            } else {
                XOS_LOG_ERROR("failed on malloc(" << m_imageSize << ")");
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

protected:
    WindowMain& m_main;
    MRender m_render;
    MOnButtonReleaseXEvent m_onButtonReleaseXEvent;
    gui::opengl::x11::ImageRenderer m_glRenderer;
    void* m_image;
    const char* m_imageFile;
    unsigned m_imageWidth, m_imageHeight, m_imageDepth, m_imageSize;
};

typedef WindowMainImplement MainImplement;
typedef WindowMain MainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: virtual public MainImplement, public MainExtend {
public:
    typedef MainImplement Implements;
    typedef MainExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: Main
    ///////////////////////////////////////////////////////////////////////
    Main(): m_mainWindow(*this) {
    }
    virtual ~Main() {
    }
    virtual MainWindow& defaultMainWindow() const {
        return (MainWindow&)(m_mainWindow);
    }
protected:
    MainWindow m_mainWindow;
};

} // namespace hello 
} // namespace x11 
} // namespace xos 

#endif // _XOS_GUI_X11_HELLO_MAIN_HPP 
