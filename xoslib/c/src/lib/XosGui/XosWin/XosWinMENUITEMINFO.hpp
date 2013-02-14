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
///   File: XosWinMENUITEMINFO.hpp
///
/// Author: $author$
///   Date: 1/30/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINMENUITEMINFO_HPP
#define _XOSWINMENUITEMINFO_HPP

#include "XosWinBase.hpp"
#include "XosString.hpp"
#include <string>

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///  Class: XosWinMENUITEMINFO
///
/// Author: $author$
///   Date: 1/30/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinMENUITEMINFO
{
public:
    MENUITEMINFO m_mii;
    XosTString m_text;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinMENUITEMINFO
    ///
    ///       Author: $author$
    ///         Date: 1/30/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinMENUITEMINFO
    (const std::string& text, UINT id=0)
    : m_text(text)
    {
        size_t cbSize = sizeof(MENUITEMINFO);
        memset(&m_mii, 0, cbSize);
        m_mii.cbSize = cbSize;
        m_mii.fMask = (MIIM_STRING | MIIM_ID);
        m_mii.wID = id;
        m_mii.dwTypeData = (LPTSTR)(m_text.c_str());
        m_mii.cch = m_text.length();
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: operator MENUITEMINFO&
    ///
    ///    Author: $author$
    ///      Date: 1/30/2012
    ///////////////////////////////////////////////////////////////////////
    virtual operator MENUITEMINFO&() const
    {
        return (MENUITEMINFO&)(m_mii);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: operator MENUITEMINFO*
    ///
    ///    Author: $author$
    ///      Date: 2/8/2012
    ///////////////////////////////////////////////////////////////////////
    virtual operator MENUITEMINFO*() const
    {
        return (MENUITEMINFO*)(&m_mii);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: operator &
    ///
    ///    Author: $author$
    ///      Date: 2/8/2012
    ///////////////////////////////////////////////////////////////////////
    virtual MENUITEMINFO* operator &() const
    {
        return (MENUITEMINFO*)(&m_mii);
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINMENUITEMINFO_HPP 
        

