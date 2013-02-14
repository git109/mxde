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
///   File: XosLibPngInfoReader.cpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#include "XosLibPngInfoReader.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngInfoReaderInterface
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///  Function: XosLibPngInfoReaderInterface::CreateInstance
///
///    Author: $author$
///      Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
XosLibPngInfoReaderInterface* XosLibPngInfoReaderInterface::CreateInstance
(XosError& error)
{
    XosLibPngInfoReaderInterface* 
    pngInfoReader = XosLibPngInfoReader::CreateInstance(error);
    return pngInfoReader;
}
///////////////////////////////////////////////////////////////////////
///  Function: XosLibPngInfoReaderInterface::DestroyInstance
///
///    Author: $author$
///      Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
XosError XosLibPngInfoReaderInterface::DestroyInstance
(XosLibPngInfoReaderInterface* instance)
{
    XosError error = XosLibPngInfoReader::DestroyInstance(instance);
    return error;
}

///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngInfoReader
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 
