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
 *   File: cwsa.hxx
 *
 * Author: $author$
 *   Date: 3/3/2010
 **********************************************************************
 */
#if !defined(_CWSA_HXX) || defined(CWSA_MEMBERS_ONLY)
#if !defined(_CWSA_HXX) && !defined(CWSA_MEMBERS_ONLY)
#define _CWSA_HXX
#endif /* !defined(_CWSA_HXX) && !defined(CWSA_MEMBERS_ONLY) */

#if !defined(CWSA_MEMBERS_ONLY)
#include "cwsainterface.hxx"
#include "csingleinstance.hxx"

#define CWSA_VERSION 0x0002

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWSA;
/**
 **********************************************************************
 * Typedef: cWSAExtend
 *
 *  Author: $author$
 *    Date: 3/3/2010
 **********************************************************************
 */
typedef cSingleInstanceT<cWSA>
cWSAExtend;
/**
 **********************************************************************
 *  Class: cWSA
 *
 * Author: $author$
 *   Date: 3/3/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWSA
: virtual public cWSAImplement,
  public cWSAExtend
{
public:
    typedef cWSAImplement cImplements;
    typedef cWSAExtend cExtends;
    
    int m_version;
    int m_startup;
    
#if defined(WINDOWS) 
/* Windows
 */
    WSADATA m_data;
#endif /* defined(WINDOWS) */

    /**
     **********************************************************************
     *  Constructor: cWSA
     *
     *       Author: $author$
     *         Date: 3/3/2010
     **********************************************************************
     */
    cWSA(int version = CWSA_VERSION)
    : cExtends(this),
      m_version(version),
      m_startup(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWSA
     *
     *      Author: $author$
     *        Date: 3/3/2010
     **********************************************************************
     */
    virtual ~cWSA()
    {
    }
#else /* !defined(CWSA_MEMBERS_ONLY) */
#endif /* !defined(CWSA_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Startup
     *
     *    Author: $author$
     *      Date: 3/3/2010
     **********************************************************************
     */
    virtual eError Startup()
#if defined(CWSA_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWSA_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWSA_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
#if defined(WINDOWS) 
/* Windows
 */
        int err;

        if (m_startup >= 0)
        if (++m_startup <= 1)
        if ((err = WSAStartup(m_version, &m_data)))
        {
            --m_startup;
            return e_ERROR_FAILED;
        }
#else /* defined(WINDOWS) */
/* Otherwise
 */
        if (m_startup >= 0)
            ++m_startup;
#endif /* defined(WINDOWS) */

#else /* !defined(CWSA_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWSA_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWSA_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Cleanup
     *
     *    Author: $author$
     *      Date: 3/3/2010
     **********************************************************************
     */
    virtual eError Cleanup()
#if defined(CWSA_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWSA_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWSA_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
#if defined(WINDOWS) 
/* Windows
 */
        int err;

        if (m_startup > 0)
        if (--m_startup < 1)
        if ((err = WSACleanup()))
            return e_ERROR_FAILED;
#else /* defined(WINDOWS) */
/* Otherwise
 */
        if (m_startup > 0)
            --m_startup;
#endif /* defined(WINDOWS) */

#else /* !defined(CWSA_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWSA_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWSA_MEMBER_FUNCS_INTERFACE) */

#if defined(CWSA_MEMBER_FUNCS_INTERFACE)
    /**
     **********************************************************************
     *  Function: GetInstance
     *
     *    Author: $author$
     *      Date: 3/3/2010
     **********************************************************************
     */
    static cWSAInterface* GetInstance();
#endif /* defined(CWSA_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWSA_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWSA_MEMBERS_ONLY) */
#endif /* !defined(CWSA_MEMBERS_ONLY) */

#endif /* !defined(_CWSA_HXX) || defined(CWSA_MEMBERS_ONLY) */
