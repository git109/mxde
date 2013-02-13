/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$     
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
 *   File: cxbase.hxx
 *
 * Author: $author$           
 *   Date: 6/20/2009
 **********************************************************************
 */
#if !defined(_CXBASE_HXX) || defined(CXBASE_MEMBERS_ONLY)
#if !defined(_CXBASE_HXX) && !defined(CXBASE_MEMBERS_ONLY)
#define _CXBASE_HXX
#endif /* !defined(_CXBASE_HXX) && !defined(CXBASE_MEMBERS_ONLY) */

#if !defined(CXBASE_MEMBERS_ONLY)
#include "cxbaseinterface.hxx"
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXBase
 *
 * Author: $author$           
 *   Date: 6/20/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cXBase
: virtual public cXBaseImplement,
  public cBase
{
public:
#else /* !defined(CXBASE_MEMBERS_ONLY) */
#endif /* !defined(CXBASE_MEMBERS_ONLY) */

#if !defined(CXBASE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXBASE_MEMBERS_ONLY) */
#endif /* !defined(CXBASE_MEMBERS_ONLY) */

#endif /* !defined(_CXBASE_HXX) || defined(CXBASE_MEMBERS_ONLY) */
