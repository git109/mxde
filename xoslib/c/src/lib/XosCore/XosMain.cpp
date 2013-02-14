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
///   File: XosMain.cpp
///
/// Author: $author$
///   Date: 11/25/2011
///////////////////////////////////////////////////////////////////////
#include "XosMain.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///  Class: XosMainInterface
///
/// Author: $author$
///   Date: 11/25/2011
///////////////////////////////////////////////////////////////////////
static XosMainInterface* s_theMain=0;

///////////////////////////////////////////////////////////////////////
///  Function: XosMainInterface::SetTheMain
///
///    Author: $author$
///      Date: 11/25/2011
///////////////////////////////////////////////////////////////////////
XosMainInterface* XosMainInterface::SetTheMain
(XosMainInterface* toTheMain)
{
    XosMainInterface* theMain = s_theMain;
    s_theMain = toTheMain;
    return theMain;
}
///////////////////////////////////////////////////////////////////////
///  Function: XosMainInterface::GetTheMain
///
///    Author: $author$
///      Date: 11/25/2011
///////////////////////////////////////////////////////////////////////
XosMainInterface* XosMainInterface::GetTheMain()
{
    return s_theMain;
}
///////////////////////////////////////////////////////////////////////
///  Function: XosMainInterface::TheMain
///
///    Author: $author$
///      Date: 11/25/2011
///////////////////////////////////////////////////////////////////////
int XosMainInterface::TheMain
(int argc,
 char** argv,
 char** env)
{
    int err = 0;
    XosMainInterface* theMain;
    if ((theMain = GetTheMain()))
        err = theMain->Main(argc, argv, env);
    else
    XOS_DBE(("() 0 == GetTheMain()\n"));
    return err;
}

#if !defined(XOSMAIN_NO_MAIN) 
///////////////////////////////////////////////////////////////////////
///  Function: main
///
///    Author: $author$
///      Date: 11/25/2011
///////////////////////////////////////////////////////////////////////
int main(int argc, char** argv, char** env)
{
    int err = 0;
    err = XosMainInterface::TheMain(argc, argv, env);
    return err;
}
#else // !defined(XOSMAIN_NO_MAIN) 
#endif // !defined(XOSMAIN_NO_MAIN) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

        

