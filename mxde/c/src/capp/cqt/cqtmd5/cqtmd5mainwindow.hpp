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
//   File: cQtMD5MainWindow.hpp
//
// Author: $author$           
//   Date: 4/7/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CQTMD5MAINWINDOW_HPP) || defined(CQTMD5MAINWINDOW_MEMBERS_ONLY)
#if !defined(_CQTMD5MAINWINDOW_HPP) && !defined(CQTMD5MAINWINDOW_MEMBERS_ONLY)
#define _CQTMD5MAINWINDOW_HPP
#endif // !defined(_CQTMD5MAINWINDOW_HPP) && !defined(CQTMD5MAINWINDOW_MEMBERS_ONLY)

#if !defined(CQTMD5MAINWINDOW_MEMBERS_ONLY)
#include <QtGui>
#include "cmd5.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE)

///////////////////////////////////////////////////////////////////////
// Typedef: cQtMD5MainWindowExtend
//
//  Author: $author$           
//    Date: 4/7/2010
///////////////////////////////////////////////////////////////////////
typedef QWidget
cQtMD5MainWindowExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cQtMD5MainWindow
//
// Author: $author$           
//   Date: 4/7/2010
///////////////////////////////////////////////////////////////////////
class cQtMD5MainWindow
: public cQtMD5MainWindowExtend
{
public:
    typedef cQtMD5MainWindowExtend cExtends;

    cMD5 m_md5;
    cCryptoHashInterface& m_hash;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cQtMD5MainWindow
    //
    //       Author: $author$           
    //         Date: 4/7/2010
    ///////////////////////////////////////////////////////////////////////
    cQtMD5MainWindow()
    : m_hash(m_md5)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cQtMD5MainWindow
    //
    //      Author: $author$           
    //        Date: 4/7/2010
    ///////////////////////////////////////////////////////////////////////
    virtual ~cQtMD5MainWindow()
    {
    }
#else // !defined(CQTMD5MAINWINDOW_MEMBERS_ONLY)
#endif // !defined(CQTMD5MAINWINDOW_MEMBERS_ONLY)

#if !defined(CQTMD5MAINWINDOW_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE)

#else // !defined(CQTMD5MAINWINDOW_MEMBERS_ONLY)
#endif // !defined(CQTMD5MAINWINDOW_MEMBERS_ONLY)

#endif // !defined(_CQTMD5MAINWINDOW_HPP) || defined(CQTMD5MAINWINDOW_MEMBERS_ONLY)
