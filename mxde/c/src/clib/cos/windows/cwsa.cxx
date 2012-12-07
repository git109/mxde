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
 *   File: cwsa.cxx
 *
 * Author: $author$
 *   Date: 3/3/2010
 **********************************************************************
 */
#include "cwsa.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWSA
 *
 * Author: $author$
 *   Date: 3/3/2010
 **********************************************************************
 */
template<>
cWSA* cWSA::cExtends::m_instance = 0;

cWSA g_cWSA;

/**
 **********************************************************************
 *  Class: cWSAInterface
 *
 * Author: $author$
 *   Date: 3/3/2010
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cWSAInterface::GetInstance
 *
 *   Author: $author$
 *     Date: 3/3/2010
 **********************************************************************
 */
cWSAInterface* cWSAInterface::GetInstance() 
{
    cWSAInterface* instance = cWSA::cExtends::GetInstance();
    return instance;
}

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */
