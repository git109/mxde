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
 *   File: cxtbase.hxx
 *
 * Author: $author$           
 *   Date: 5/1/2010
 **********************************************************************
 */
#if !defined(_CXTBASE_HXX) || defined(CXTBASE_MEMBERS_ONLY)
#if !defined(_CXTBASE_HXX) && !defined(CXTBASE_MEMBERS_ONLY)
#define _CXTBASE_HXX
#endif /* !defined(_CXTBASE_HXX) && !defined(CXTBASE_MEMBERS_ONLY) */

#if !defined(CXTBASE_MEMBERS_ONLY)
#include "cxtbaseinterface.hxx"
#include "cxbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtBaseExtend
 *
 *  Author: $author$           
 *    Date: 5/1/2010
 **********************************************************************
 */
typedef cXBase
cXtBaseExtend;
/**
 **********************************************************************
 *  Class: cXtBase
 *
 * Author: $author$           
 *   Date: 5/1/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtBase
: virtual public cXtBaseImplement,
  public cXtBaseExtend
{
public:
    typedef cXtBaseImplement cImplements;
    typedef cXtBaseExtend cExtends;
#else /* !defined(CXTBASE_MEMBERS_ONLY) */
#endif /* !defined(CXTBASE_MEMBERS_ONLY) */

#if !defined(CXTBASE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTBASE_MEMBERS_ONLY) */
#endif /* !defined(CXTBASE_MEMBERS_ONLY) */

#endif /* !defined(_CXTBASE_HXX) || defined(CXTBASE_MEMBERS_ONLY) */
