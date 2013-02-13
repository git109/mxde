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
//   File: cQtMD5Main.hpp
//
// Author: $author$           
//   Date: 4/6/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CQTMD5MAIN_HPP) || defined(CQTMD5MAIN_MEMBERS_ONLY)
#if !defined(_CQTMD5MAIN_HPP) && !defined(CQTMD5MAIN_MEMBERS_ONLY)
#define _CQTMD5MAIN_HPP
#endif // !defined(_CQTMD5MAIN_HPP) && !defined(CQTMD5MAIN_MEMBERS_ONLY)

#if !defined(CQTMD5MAIN_MEMBERS_ONLY)
#include "cQtGuiMain.hpp"
#include "cQtMD5MainWindow.hpp"
#include "cQtLineEdit.hpp"
#include "cQCharString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE)

///////////////////////////////////////////////////////////////////////
// Typedef: cQtMD5MainExtend
//
//  Author: $author$           
//    Date: 4/6/2010
///////////////////////////////////////////////////////////////////////
typedef cQtGuiMain
cQtMD5MainExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cQtMD5Main
//
// Author: $author$           
//   Date: 4/6/2010
///////////////////////////////////////////////////////////////////////
class cQtMD5Main
: public cQtMD5MainExtend
{
public:
    typedef cQtMD5MainExtend cExtends;

    cQtMD5MainWindow* m_mainWindow;
    cQtLineEdit m_edit;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cQtMD5Main
    //
    //       Author: $author$           
    //         Date: 4/6/2010
    ///////////////////////////////////////////////////////////////////////
    cQtMD5Main()
    : m_mainWindow(0)
    {
    }
#else // !defined(CQTMD5MAIN_MEMBERS_ONLY)
#endif // !defined(CQTMD5MAIN_MEMBERS_ONLY)

#if !defined(CQTMD5MAIN_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: CreateMainWindow
    //
    //    Author: $author$           
    //      Date: 4/7/2010
    ///////////////////////////////////////////////////////////////////////
    virtual cQtMainWindow* CreateMainWindow
    (tInt argc,
     tChar** argv,
     tChar** env)
#if defined(CQTMD5MAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CQTMD5MAIN_MEMBER_FUNCS_INTERFACE)
    {
        cQCharString cTitle("Qt MD5");
        cQtMainWindow* mainWindow;
        eError error;
        
        if ((mainWindow = (m_mainWindow = new cQtMD5MainWindow)))
        {
            TLENGTH qLength = 0;
            const QChar* qChars = cTitle.c_str(qLength);
            QString title(qChars, qLength);
            QPushButton* button;
            mainWindow->setWindowTitle(title);
            if ((button = new QPushButton(title, mainWindow)))
            {
                button->move(100, 100);
                button->showNormal();
            }
            
            {
                QWidget* edit;
                if ((edit = m_edit.CreateAttached
                    (error, mainWindow)))
                {
                    edit->move(0,0);
                    edit->resize(100, 20);
                    edit->showNormal();
                }
            }
        }
#if !defined(CQTMD5MAIN_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CQTMD5MAIN_MEMBER_FUNCS_IMPLEMENT)
#endif // !defined(CQTMD5MAIN_MEMBER_FUNCS_IMPLEMENT)
        return mainWindow;
    }
#endif // defined(CQTMD5MAIN_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: DestroyMainWindow
    //
    //    Author: $author$           
    //      Date: 4/7/2010
    ///////////////////////////////////////////////////////////////////////
    virtual void DestroyMainWindow
    (cQtMainWindow& mainWindow,
     tInt argc,
     tChar** argv,
     tChar** env)
#if defined(CQTMD5MAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CQTMD5MAIN_MEMBER_FUNCS_INTERFACE)
    {
        if (&mainWindow == (m_mainWindow))
        {
            delete m_mainWindow;
            m_mainWindow = 0;
        }
#if !defined(CQTMD5MAIN_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CQTMD5MAIN_MEMBER_FUNCS_IMPLEMENT)
#endif // !defined(CQTMD5MAIN_MEMBER_FUNCS_IMPLEMENT)
    }
#endif // defined(CQTMD5MAIN_MEMBER_FUNCS_INTERFACE)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE)

#else // !defined(CQTMD5MAIN_MEMBERS_ONLY)
#endif // !defined(CQTMD5MAIN_MEMBERS_ONLY)

#endif // !defined(_CQTMD5MAIN_HPP) || defined(CQTMD5MAIN_MEMBERS_ONLY)
