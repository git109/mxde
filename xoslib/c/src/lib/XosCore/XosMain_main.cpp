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
///   File: XosMain_main.cpp
///
/// Author: $author$
///   Date: 3/29/2012
///////////////////////////////////////////////////////////////////////
#include "XosMain_main.hpp"

#if !defined(XOSMAIN_NO_MAIN_MAIN) 
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
#else // !defined(XOSMAIN_NO_MAIN_MAIN) 
#endif // !defined(XOSMAIN_NO_MAIN_MAIN) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

        

