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
///   Date: 6/8/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_QT_HELLO_MAIN_HPP
#define _XOS_APP_GUI_QT_HELLO_MAIN_HPP

#include <QtOpenGL/QtOpenGL>
#include <QtGui/QPushButton>
#include "xos/gui/qt/WindowMain.hpp"
#include "app/gui/opengl/hello/Main.hpp"

#define XOS_APP_GUI_QT_HELLO_DEFAULT_BACKGROUND_RED   255
#define XOS_APP_GUI_QT_HELLO_DEFAULT_BACKGROUND_GREEN 0
#define XOS_APP_GUI_QT_HELLO_DEFAULT_BACKGROUND_BLUE  0

namespace xos {
namespace app {
namespace gui {
namespace qt {
namespace hello {

typedef xos::gui::opengl::ImageRendererImplement GLImageRendererImplement;
typedef xos::gui::opengl::ImageRenderer GLImageRendererExtendExtend;
typedef opengl::hello::MainT
<GLImageRendererImplement, GLImageRendererExtendExtend> GLImageRendererExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS GLImageRenderer: public GLImageRendererExtend {
public:
    typedef GLImageRendererImplement Implements;
    typedef GLImageRendererExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    GLImageRenderer() {
    }
    virtual ~GLImageRenderer() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual xos::gui::opengl::ImageRenderer& GlRenderer() const {
        return (xos::gui::opengl::ImageRenderer&)(*this);
    }
};
typedef QGLWidget GLWidgetExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS GLWidget: public GLWidgetExtend {
public:
    typedef GLWidgetExtend Extends;
    typedef GLWidget Derives;

    typedef void (Derives::*M)();

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    GLWidget
    (QWidget* parent, const QColor& bgColor)
    : Extends(parent), 
      m_sibling(0),
      m_bgColor(bgColor), 
      m_switchRender(0),
      m_render(0) {
    }
    virtual ~GLWidget() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Invalidate() {
        int width = this->width();
        int height = this->height();
        update(0,0, width,height);
    }
    virtual void Resize() {
        int width = this->width();
        int height = this->height();
        resizeGL(width, height);
        update(0,0, width,height);
    }
    virtual void Show() {
        int width = this->width();
        int height = this->height();
        resizeGL(width, height);
        show();
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void SwitchRender() {
        m_switchRender = &Derives::SwitchRenderIn;
        m_render = &Derives::Render;
    }
    virtual void SwitchRenderIn() {
        m_switchRender = &Derives::SwitchRenderRaw;
        m_render = &Derives::RenderIn;
    }
    virtual void SwitchRenderRaw() {
        m_switchRender = &Derives::SwitchRender;
        m_render = &Derives::RenderRaw;
        if ((m_sibling)) {
            hide();
            m_sibling->show();
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void RenderRaw() {
        m_glRenderer.RenderRaw();
    }
    virtual void Render() {
        m_glRenderer.Render();
    }
    virtual void RenderIn() {
        m_glRenderer.RenderIn();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PaintBackground() {
        int width = this->width();
        int height = this->height();
        QPainter qp(this);
        QRect rc(0,0, width, height);
        qp.fillRect(rc, m_bgColor);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void mouseReleaseEvent(QMouseEvent *event) {
        Qt::MouseButton button = Qt::NoButton;
        switch((button = event->button())) {
        case Qt::LeftButton:
            if ((m_switchRender))
                (this->*m_switchRender)();
            else
            SwitchRender();
            Invalidate();
            break;
        case Qt::RightButton:
        default:
            break;
        }
        Extends::mouseReleaseEvent(event);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void initializeGL() {
        m_glRenderer.LoadImageFile();
        m_glRenderer.Prepare();
    }
    virtual void resizeGL(int width, int height) {
        m_glRenderer.Reshape(width, height);
    }
    virtual void paintGL() {
        if ((m_glRenderer.Image())) {
            if ((m_render))
                (this->*m_render)();
            else
            RenderRaw();
        } else {
            PaintBackground();
        }
    }

public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual QWidget* SetSibling(QWidget* sibling) {
        return m_sibling = sibling;
    }
    virtual QWidget* Sibling() const {
        return m_sibling;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    QWidget* m_sibling;
    QColor m_bgColor;
    GLImageRenderer m_glRenderer;
    M m_switchRender;
    M m_render;
};

typedef QWidget FormWidgetExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS FormWidget: public FormWidgetExtend {
Q_OBJECT
public:
    typedef FormWidgetExtend Extends;
    typedef FormWidget Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FormWidget(QWidget* parent)
    : Extends(parent),
      m_sibling(0),
      m_button(0) {
    }
    virtual ~FormWidget() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Init(){
        if ((m_button = new QPushButton("Hello", this))) {
            m_button->resize(width(), height());
            connect(m_button, SIGNAL(released()), this, SLOT(buttonReleased()));
        }
        return true;
    }
    virtual bool Finish(){
        return true;
    }
protected slots:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void buttonReleased() {
        if ((m_sibling)) {
            hide();
            m_sibling->show();
        }
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void resizeEvent(QResizeEvent *event) {
        if ((m_button))
            m_button->resize(width(), height());
        Extends::resizeEvent(event);
    }
    virtual void mouseReleaseEvent(QMouseEvent *event) {
        Qt::MouseButton button = Qt::NoButton;
        switch((button = event->button())) {
        case Qt::LeftButton:
            buttonReleased();
            break;
        case Qt::RightButton:
        default:
            break;
        }
        Extends::mouseReleaseEvent(event);
    }
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual QWidget* SetSibling(QWidget* sibling) {
        return m_sibling = sibling;
    }
    virtual QWidget* Sibling() const {
        return m_sibling;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    QWidget* m_sibling;
    QPushButton *m_button;
};

typedef InterfaceBase MainWindowImplement;
typedef QMainWindow MainWindowExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MainWindow
: virtual public MainWindowImplement, public MainWindowExtend {
public:
    typedef MainWindowImplement Implements;
    typedef MainWindowExtend Extends;
    typedef MainWindow Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainWindow()
    : m_formWidget(0),
      m_openglWidget(0),
      m_bgColor
      (XOS_APP_GUI_QT_HELLO_DEFAULT_BACKGROUND_RED,
       XOS_APP_GUI_QT_HELLO_DEFAULT_BACKGROUND_GREEN,
       XOS_APP_GUI_QT_HELLO_DEFAULT_BACKGROUND_BLUE) {
    }
    virtual ~MainWindow() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Init(){
        if ((m_formWidget = new FormWidget(this))) {
            if ((m_formWidget->Init())) {
                if ((m_openglWidget = new GLWidget(this, m_bgColor))) {
                    m_openglWidget->hide();
                    m_openglWidget->SetSibling(m_formWidget);
                    m_formWidget->SetSibling(m_openglWidget);
                    m_formWidget->show();
                    return true;
                }
                delete m_formWidget;
                m_formWidget = 0;
            }
        }
        return false;
    }
    virtual bool Finish(){
        bool success = false;
        if ((m_openglWidget)) {
            if (m_openglWidget == (centralWidget()))
                setCentralWidget(0);
            else
            delete m_openglWidget;
            m_openglWidget = 0;
            success = true;
        }
        if ((m_formWidget)) {
            if (m_formWidget == (centralWidget()))
                setCentralWidget(0);
            else
            delete m_openglWidget;
            m_openglWidget = 0;
            success = true;
        }
        return success;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void resizeEvent(QResizeEvent *event) {
        if ((m_formWidget))
            m_formWidget->resize(width(), height());
        if ((m_openglWidget))
            m_openglWidget->resize(width(), height());
        Extends::resizeEvent(event);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    FormWidget* m_formWidget;
    GLWidget* m_openglWidget;
    QColor m_bgColor;
};

typedef xos::gui::qt::WindowMainImplement MainImplement;
typedef xos::gui::qt::WindowMain MainExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main
: virtual public MainImplement, public MainExtend {
public:
    typedef MainImplement Implements;
    typedef MainExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main(): m_mainWindow(0) {
    }
    virtual ~Main(){
        if ((m_mainWindow))
            delete m_mainWindow;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual QMainWindow* CreateMainWindow
    (QApplication& qApplication,
     int argc, char** argv, char** env)
    {
        if ((m_mainWindow = new MainWindow())) {
            if (!(m_mainWindow->Init())) {
                delete m_mainWindow;
                m_mainWindow = 0;
            }
        }
        return m_mainWindow;
    }
    virtual bool DestroyMainWindow
    (QMainWindow* mainWindow, QApplication& qApplication,
     int argc, char** argv, char** env)
    {
        bool isSuccess = false;
        if ((mainWindow) && (mainWindow == m_mainWindow)) {
            m_mainWindow->Finish();
            delete m_mainWindow;
            m_mainWindow = 0;
            isSuccess = true;
        }
        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    MainWindow* m_mainWindow;
};

} // namespace hello 
} // namespace qt 
} // namespace gui 
} // namespace app 
} // namespace xos 

#endif // _XOS_APP_GUI_QT_HELLO_MAIN_HPP 
