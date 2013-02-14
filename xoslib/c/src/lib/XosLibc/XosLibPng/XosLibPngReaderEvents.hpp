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
///   File: XosLibPngReaderEvents.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGREADEREVENTS_HPP) || defined(XOSLIBPNGREADEREVENTS_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGREADEREVENTS_HPP) && !defined(XOSLIBPNGREADEREVENTS_MEMBERS_ONLY)
#define _XOSLIBPNGREADEREVENTS_HPP
#endif // !defined(_XOSLIBPNGREADEREVENTS_HPP) && !defined(XOSLIBPNGREADEREVENTS_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGREADEREVENTS_MEMBERS_ONLY)
#include "XosLibPngReaderEventsInterface.hpp"
#include "XosLibPngInterfaceBase.hpp"
#include "XosLibPngBase.hpp"
#include "XosPixel.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngReaderEventsExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngBase
XosLibPngReaderEventsExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngReaderEvents
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosLibPngReaderEvents
: virtual public XosLibPngReaderEventsImplement,
  public XosLibPngReaderEventsExtend
{
public:
    typedef XosLibPngReaderEventsImplement Implements;
    typedef XosLibPngReaderEventsExtend Extends;

    XosLibPngReaderEventsInterface* m_delegated;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosLibPngReaderEvents
    ///
    ///       Author: $author$
    ///         Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosLibPngReaderEvents
    (XosLibPngReaderEventsInterface* delegated=0)
    : m_delegated(delegated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosLibPngReaderEvents
    ///
    ///      Author: $author$
    ///        Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosLibPngReaderEvents()
    {
    }
#else // !defined(XOSLIBPNGREADEREVENTS_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGREADEREVENTS_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnPNGPixel
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnPNGPixel
    (XosPixel& pixel,
     BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        XosLibPngReaderEventsInterface* delegated = 0;
        XosError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnPNGPixel
            (pixel, colByte, colBytes, col, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#else // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnBeginPNGCol
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnBeginPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        XosLibPngReaderEventsInterface* delegated = 0;
        XosError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBeginPNGCol
            (colByte, colBytes, col, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#else // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnEndPNGCol
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnEndPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        XosLibPngReaderEventsInterface* delegated = 0;
        XosError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnEndPNGCol
            (colByte, colBytes, col, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#else // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnPNGCol
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        XosLibPngReaderEventsInterface* delegated = 0;
        XosError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnPNGCol
            (colByte, colBytes, col, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#else // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnBeginPNGRow
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnBeginPNGRow
    (BYTE* rowByte, TSIZE rowBytes, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        XosLibPngReaderEventsInterface* delegated = 0;
        XosError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBeginPNGRow
            (rowByte, rowBytes, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#else // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnEndPNGRow
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnEndPNGRow
    (BYTE* rowByte, TSIZE rowBytes, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        XosLibPngReaderEventsInterface* delegated = 0;
        XosError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnEndPNGRow
            (rowByte, rowBytes, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#else // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnPNGRow
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnPNGRow
    (BYTE* rowByte, TSIZE rowBytes, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        XosLibPngReaderEventsInterface* delegated = 0;
        XosError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnPNGRow
            (rowByte, rowBytes, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#else // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnBeginPNGImage
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnBeginPNGImage
    (TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        XosLibPngReaderEventsInterface* delegated = 0;
        XosError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBeginPNGImage
            (height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#else // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnEndPNGImage
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnEndPNGImage
    (TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        XosLibPngReaderEventsInterface* delegated = 0;
        XosError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnEndPNGImage
            (height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#else // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnPNGImage
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnPNGImage
    (TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType)
#if defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_NONE;
#if !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        XosLibPngReaderEventsInterface* delegated = 0;
        XosError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnPNGImage
            (height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#else // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Delegate
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosLibPngReaderEventsInterface* Delegate
    (XosLibPngReaderEventsInterface* delegatedTo)
#if defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    {
        XosLibPngReaderEventsInterface* delegated = 0;
#if !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        delegated = m_delegated;
        m_delegated = delegatedTo;
#else // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        return delegated;
    }
#endif // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Delegated
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosLibPngReaderEventsInterface* Delegated
    (XosLibPngReaderEventsInterface*) const
#if defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 
    {
        XosLibPngReaderEventsInterface* delegated = 0;
#if !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        delegated = m_delegated;
#else // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        return delegated;
    }
#endif // defined(XOSLIBPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSLIBPNGREADEREVENTS_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGREADEREVENTS_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGREADEREVENTS_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGREADEREVENTS_HPP) || defined(XOSLIBPNGREADEREVENTS_MEMBERS_ONLY) 
        

