///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2010 $organization$  
//
// This software is provided by the author and contributors ``as is''
// and any express or implied warranties, including, but not limited to,
// the implied warranties of merchantability and fitness for a particular
// purpose are disclaimed. In no event shall the author or contributors
// be liable for any direct, indirect, incidental, special, exemplary,
// or consequential damages (including, but not limited to, procurement
// of substitute goods or services; loss of use, data, or profits; or
// business interruption) however caused and on any theory of liability,
// whether in contract, strict liability, or tort (including negligence
// or otherwise) arising in any way out of the use of this software,
// even if advised of the possibility of such damage.
//
//   File: cQtGuiMain.hpp
//
// Author: $author$           
//   Date: 4/6/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CQTGUIMAIN_HPP) || defined(CQTGUIMAIN_MEMBERS_ONLY)
#if !defined(_CQTGUIMAIN_HPP) && !defined(CQTGUIMAIN_MEMBERS_ONLY)
#define _CQTGUIMAIN_HPP
#endif // !defined(_CQTGUIMAIN_HPP) && !defined(CQTGUIMAIN_MEMBERS_ONLY)

#if !defined(CQTGUIMAIN_MEMBERS_ONLY)
#include <QtGui>
#include "cmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE)

typedef QWidget cQtMainWindow;
///////////////////////////////////////////////////////////////////////
// Typedef: cQtGuiMainExtends
//
//  Author: $author$           
//    Date: 4/6/2010
///////////////////////////////////////////////////////////////////////
typedef cMain
cQtGuiMainExtends;
///////////////////////////////////////////////////////////////////////
//  Class: cQtGuiMain
//
// Author: $author$           
//   Date: 4/6/2010
///////////////////////////////////////////////////////////////////////
class cQtGuiMain
: public cQtGuiMainExtends
{
public:
    typedef cQtGuiMainExtends cExtends;
#else // !defined(CQTGUIMAIN_MEMBERS_ONLY)
#endif // !defined(CQTGUIMAIN_MEMBERS_ONLY)

    ///////////////////////////////////////////////////////////////////////
    //  Function: CreateMainWindow
    //
    //    Author: $author$           
    //      Date: 4/6/2010
    ///////////////////////////////////////////////////////////////////////
    virtual cQtMainWindow* CreateMainWindow
    (tInt argc,
     tChar** argv,
     tChar** env)
#if defined(CQTGUIMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CQTGUIMAIN_MEMBER_FUNCS_INTERFACE)
    {
        cQtMainWindow* mainWindow = 0;
#if !defined(CQTGUIMAIN_MEMBER_FUNCS_IMPLEMENT)
        mainWindow = new cQtMainWindow();
#else // !defined(CQTGUIMAIN_MEMBER_FUNCS_IMPLEMENT)
#endif // !defined(CQTGUIMAIN_MEMBER_FUNCS_IMPLEMENT)
        return mainWindow;
    }
#endif // defined(CQTGUIMAIN_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: DestroyMainWindow
    //
    //    Author: $author$           
    //      Date: 4/6/2010
    ///////////////////////////////////////////////////////////////////////
    virtual void DestroyMainWindow
    (cQtMainWindow& mainWindow,
     tInt argc,
     tChar** argv,
     tChar** env)
#if defined(CQTGUIMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CQTGUIMAIN_MEMBER_FUNCS_INTERFACE)
    {
#if !defined(CQTGUIMAIN_MEMBER_FUNCS_IMPLEMENT)
        delete &mainWindow;
#else // !defined(CQTGUIMAIN_MEMBER_FUNCS_IMPLEMENT)
#endif // !defined(CQTGUIMAIN_MEMBER_FUNCS_IMPLEMENT)
    }
#endif // defined(CQTGUIMAIN_MEMBER_FUNCS_INTERFACE)

#if !defined(CQTGUIMAIN_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$           
    //      Date: 4/6/2010
    ///////////////////////////////////////////////////////////////////////
    virtual int Main
    (tInt argc,
     tChar** argv,
     tChar** env)
    {
        int err = 0;
        QApplication app(argc, argv);
        cQtMainWindow* mainWindow;
        if ((mainWindow = CreateMainWindow(argc, argv, env)))
            mainWindow->show();
        err = app.exec();
        if ((mainWindow))
            DestroyMainWindow(*mainWindow, argc, argv, env);
        return err;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE)

#else // !defined(CQTGUIMAIN_MEMBERS_ONLY)
#endif // !defined(CQTGUIMAIN_MEMBERS_ONLY)

#endif // !defined(_CQTGUIMAIN_HPP) || defined(CQTGUIMAIN_MEMBERS_ONLY)
