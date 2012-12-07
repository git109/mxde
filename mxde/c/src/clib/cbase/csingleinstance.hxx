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
 *   File: csingleinstance.hxx
 *
 * Author: $author$
 *   Date: 3/3/2010
 **********************************************************************
 */
#if !defined(_CSINGLEINSTANCE_HXX) || defined(CSINGLEINSTANCE_MEMBERS_ONLY)
#if !defined(_CSINGLEINSTANCE_HXX) && !defined(CSINGLEINSTANCE_MEMBERS_ONLY)
#define _CSINGLEINSTANCE_HXX
#endif /* !defined(_CSINGLEINSTANCE_HXX) && !defined(CSINGLEINSTANCE_MEMBERS_ONLY) */

#if !defined(CSINGLEINSTANCE_MEMBERS_ONLY)
#include "cinstancebase.hxx"
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#undef CDB_CLASS
#define CDB_CLASS "cSingleInstanceT"
/**
 **********************************************************************
 *  Class: cSingleInstanceT
 *
 * Author: $author$
 *   Date: 3/3/2010
 **********************************************************************
 */
template
<class TDerives,
 class TExtend=cInstanceBase,
 class TExtends=TExtend>

class c_INSTANCE_CLASS cSingleInstanceT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives tDerives;
    
    static tDerives* m_instance;
    tDerives* m_oldInstance;

    /**
     **********************************************************************
     *  Constructor: cSingleInstanceT
     *
     *       Author: $author$
     *         Date: 3/3/2010
     **********************************************************************
     */
    cSingleInstanceT
    (tDerives* instance) 
    : m_oldInstance(m_instance)
    {
        eError error;

        if (m_instance)
            throw (error = e_ERROR_ALREADY_INSTANTIATED);

        if (this != instance)
            throw (error = e_ERROR_INSTANTIATE);

        m_instance = instance;
    }
    /**
     **********************************************************************
     *  Destructor: ~cSingleInstanceT
     *
     *      Author: $author$
     *        Date: 3/3/2010
     **********************************************************************
     */
    virtual ~cSingleInstanceT()
    {
        eError error;

        if (this != m_instance)
            throw (error = e_ERROR_NOT_INSTANTIATED);

        m_instance = m_oldInstance;
    }
#else /* !defined(CSINGLEINSTANCE_MEMBERS_ONLY) */
#endif /* !defined(CSINGLEINSTANCE_MEMBERS_ONLY) */

#if !defined(CSINGLEINSTANCE_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: GetInstance
     *
     *   Author: $author$
     *     Date: 3/3/2010
     **********************************************************************
     */
    static inline tDerives* GetInstance()
    {
        return m_instance;
    }
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSINGLEINSTANCE_MEMBERS_ONLY) */
#endif /* !defined(CSINGLEINSTANCE_MEMBERS_ONLY) */

#endif /* !defined(_CSINGLEINSTANCE_HXX) || defined(CSINGLEINSTANCE_MEMBERS_ONLY) */
