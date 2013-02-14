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
///   File: XosQWindowMain.hpp
///
/// Author: $author$
///   Date: 2/3/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOSQWINDOWMAIN_HPP
#define _XOSQWINDOWMAIN_HPP

#include "XosQApplicationMain.hpp"

#if defined(_NAMESPACE)
namespace _NAMESPACE {
#endif // defined(_NAMESPACE) 

typedef XosQApplicationMain XosQWindowMainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosQWindowMain
///
/// Author: $author$
///   Date: 2/3/2013
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosQWindowMain
: public XosQWindowMainExtend
{
public:
    typedef XosQWindowMainExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosQWindowMain
    ///
    ///       Author: $author$
    ///         Date: 2/3/2013
    ///////////////////////////////////////////////////////////////////////
    XosQWindowMain()
    : m_mainWindow(0)
    {
    }
    virtual ~XosQWindowMain()
    {
        if ((m_mainWindow))
            delete m_mainWindow;
    }

    ///////////////////////////////////////////////////////////////////////
    // main window
    ///////////////////////////////////////////////////////////////////////
    virtual QMainWindow* CreateMainWindow
    (QApplication& qApplication,
     int argc, char** argv, char** env)
    {
        QMainWindow* mainWindow = 0;
        mainWindow = new QMainWindow();
        return mainWindow;
    }
    virtual bool DestroyMainWindow
    (QMainWindow* mainWindow, QApplication& qApplication,
     int argc, char** argv, char** env)
    {
        bool isSuccess = true;
        delete mainWindow;
        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    // exec
    ///////////////////////////////////////////////////////////////////////
    virtual int BeforeExec
    (QApplication& qApplication,
     int argc, char** argv, char** env)
    {
        int err = 0;
        if ((m_mainWindow = CreateMainWindow(qApplication, argc, argv, env))) {
            m_mainWindow->show();
        } else {
            err = 1;
        }
        return err;
    }
    virtual int AfterExec
    (QApplication& qApplication,
     int argc, char** argv, char** env)
    {
        int err = 0;
        if ((m_mainWindow)) {
            if (!(DestroyMainWindow(m_mainWindow, qApplication, argc, argv, env)))
                err = 1;
            m_mainWindow = 0;
        }
        return err;
    }

protected:
    QMainWindow* m_mainWindow;
};

#if defined(_NAMESPACE)
}
#endif // defined(_NAMESPACE) 

#endif // _XOSQWINDOWMAIN_HPP 
