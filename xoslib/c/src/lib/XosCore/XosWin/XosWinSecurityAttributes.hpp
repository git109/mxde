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
///   File: XosWinSecurityAttributes.hpp
///
/// Author: $author$
///   Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINSECURITYATTRIBUTES_HPP
#define _XOSWINSECURITYATTRIBUTES_HPP

#include "XosInterfaceBase.hpp"
#include "XosExportBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinSecurityAttributesImplement
///
///  Author: $author$
///    Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
typedef XosInterfaceBase
XosWinSecurityAttributesImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinSecurityAttributesExtend
///
///  Author: $author$
///    Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
typedef XosExportBase
XosWinSecurityAttributesExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinSecurityAttributes
///
/// Author: $author$
///   Date: 3/26/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinSecurityAttributes
: virtual public XosWinSecurityAttributesImplement,
  public XosWinSecurityAttributesExtend
{
public:
    typedef XosWinSecurityAttributesImplement Implements;
    typedef XosWinSecurityAttributesExtend Extends;

    SECURITY_ATTRIBUTES m_saDefault;
    SECURITY_ATTRIBUTES& m_sa;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinSecurityAttributes
    ///
    ///       Author: $author$
    ///         Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinSecurityAttributes()
    : m_sa(m_saDefault)
    {
        memset(&m_sa, 0, sizeof(SECURITY_ATTRIBUTES));
        m_sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinSecurityAttributes
    ///
    ///       Author: $author$
    ///         Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinSecurityAttributes
    (SECURITY_ATTRIBUTES& sa, 
     bool alreadyInitialized=false)
    : m_sa(sa)
    {
        if (!(alreadyInitialized))
        {
            memset(&m_sa, 0, sizeof(SECURITY_ATTRIBUTES));
            m_sa.nLength = sizeof(SECURITY_ATTRIBUTES);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinSecurityAttributes
    ///
    ///      Author: $author$
    ///        Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinSecurityAttributes()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: operator SECURITY_ATTRIBUTES&
    ///
    ///    Author: $author$
    ///      Date: 3/26/2012
    ///////////////////////////////////////////////////////////////////////
    virtual operator SECURITY_ATTRIBUTES&() const
    {
        return (SECURITY_ATTRIBUTES&)(m_sa);
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINSECURITYATTRIBUTES_HPP 
        

