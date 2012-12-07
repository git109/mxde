/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cwinsecurityattributes.hxx
 *
 * Author: $author$
 *   Date: 10/23/2010
 **********************************************************************
 */
#if !defined(_CWINSECURITYATTRIBUTES_HXX) || defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY)
#if !defined(_CWINSECURITYATTRIBUTES_HXX) && !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY)
#define _CWINSECURITYATTRIBUTES_HXX
#endif /* !defined(_CWINSECURITYATTRIBUTES_HXX) && !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY) */

#if !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY)
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinSecurityAttributes
 *
 * Author: $author$
 *   Date: 10/23/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinSecurityAttributes
{
public:
    SECURITY_ATTRIBUTES m_default_sa;
    SECURITY_ATTRIBUTES& m_sa;
    
    /**
     **********************************************************************
     *  Constructor: cWinSecurityAttributes
     *
     *       Author: $author$
     *         Date: 10/23/2010
     **********************************************************************
     */
    cWinSecurityAttributes
    (SECURITY_ATTRIBUTES& sa)
    : m_sa(sa)
    {
        Clear();
    }
    /**
     **********************************************************************
     *  Constructor: cWinSecurityAttributes
     *
     *       Author: $author$
     *         Date: 10/23/2010
     **********************************************************************
     */
    cWinSecurityAttributes()
    : m_sa(m_default_sa)
    {
        Clear();
    }
#else /* !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY) */
#endif /* !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY) */

#if !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 10/23/2010
     **********************************************************************
     */
    void Clear()
    {
        memset(&m_sa, 0, sizeof(SECURITY_ATTRIBUTES));
        m_sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    }
    /**
     **********************************************************************
     * Function: operator SECURITY_ATTRIBUTES
     *
     *   Author: $author$
     *     Date: 10/23/2010
     **********************************************************************
     */
    operator SECURITY_ATTRIBUTES&() const 
    {
        SECURITY_ATTRIBUTES& sa = (SECURITY_ATTRIBUTES&)(m_sa);
        return sa;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY) */
#endif /* !defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY) */

#endif /* !defined(_CWINSECURITYATTRIBUTES_HXX) || defined(CWINSECURITYATTRIBUTES_MEMBERS_ONLY) */
