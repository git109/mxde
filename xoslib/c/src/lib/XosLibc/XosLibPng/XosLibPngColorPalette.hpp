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
///   File: XosLibPngColorPalette.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGCOLORPALETTE_HPP) || defined(XOSLIBPNGCOLORPALETTE_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGCOLORPALETTE_HPP) && !defined(XOSLIBPNGCOLORPALETTE_MEMBERS_ONLY)
#define _XOSLIBPNGCOLORPALETTE_HPP
#endif // !defined(_XOSLIBPNGCOLORPALETTE_HPP) && !defined(XOSLIBPNGCOLORPALETTE_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGCOLORPALETTE_MEMBERS_ONLY)
#include "XosLibPngColorAttached.hpp"
#include "XosLibPngInfoInterface.hpp"
#include "XosLibPngStructInterface.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngColorPaletteExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngColorAttached
XosLibPngColorPaletteExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngColorPalette
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosLibPngColorPalette
: public XosLibPngColorPaletteExtend
{
public:
    typedef XosLibPngColorPaletteExtend Extends;

    XosLibPngStructInterface& m_pngStruct;
    XosLibPngInfoInterface& m_pngInfo;

    int m_paletteColors;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosLibPngColorPalette
    ///
    ///       Author: $author$
    ///         Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosLibPngColorPalette
    (XosLibPngStructInterface& pngStruct,
     XosLibPngInfoInterface& pngInfo,
     tAttachedTo attached=vUnattached)
    : Extends(attached),
      m_pngStruct(pngStruct),
      m_pngInfo(pngInfo),
      m_paletteColors(0)
    {
    }
#else // !defined(XOSLIBPNGCOLORPALETTE_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGCOLORPALETTE_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Get
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int Get()
#if defined(XOSLIBPNGCOLORPALETTE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGCOLORPALETTE_MEMBER_FUNCS_INTERFACE) 
    {
        int count = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGCOLORPALETTE_MEMBER_FUNCS_IMPLEMENT)
        png_int_32 result;
        png_structp structAttached;
        png_infop infoAttached;

        if ((structAttached = m_pngStruct.Attached())
            && (infoAttached = m_pngInfo.Attached()))

        if ((result = png_get_PLTE
             (structAttached, infoAttached, 
              &m_attached, &m_paletteColors)))
            count = m_paletteColors;
        else
        count = -XOS_ERROR_FAILED;
#else // !defined(XOSLIBPNGCOLORPALETTE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGCOLORPALETTE_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSLIBPNGCOLORPALETTE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Put
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int Put()
#if defined(XOSLIBPNGCOLORPALETTE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGCOLORPALETTE_MEMBER_FUNCS_INTERFACE) 
    {
        int count = -XOS_ERROR_NOT_ATTACHED;
#if !defined(XOSLIBPNGCOLORPALETTE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSLIBPNGCOLORPALETTE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGCOLORPALETTE_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSLIBPNGCOLORPALETTE_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSLIBPNGCOLORPALETTE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGCOLORPALETTE_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGCOLORPALETTE_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGCOLORPALETTE_HPP) || defined(XOSLIBPNGCOLORPALETTE_MEMBERS_ONLY) 
        

