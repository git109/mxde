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
 *   File: cpngbase.hxx
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
#if !defined(_CPNGBASE_HXX) || defined(CPNGBASE_MEMBERS_ONLY)
#if !defined(_CPNGBASE_HXX) && !defined(CPNGBASE_MEMBERS_ONLY)
#define _CPNGBASE_HXX
#endif /* !defined(_CPNGBASE_HXX) && !defined(CPNGBASE_MEMBERS_ONLY) */

#if !defined(CPNGBASE_MEMBERS_ONLY)
#include "cpnginterfacebase.hxx"
#include "cexportbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cPngBaseExtend
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cExportBase
cPngBaseExtend;
/**
 **********************************************************************
 *  Class: cPngBase
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cPngBase
: public cPngBaseExtend
{
public:
    typedef cPngBaseExtend cExtends;
#else /* !defined(CPNGBASE_MEMBERS_ONLY) */
#endif /* !defined(CPNGBASE_MEMBERS_ONLY) */

#if !defined(CPNGBASE_MEMBERS_ONLY) 
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGBASE_MEMBERS_ONLY) */
#endif /* !defined(CPNGBASE_MEMBERS_ONLY) */

#endif /* !defined(_CPNGBASE_HXX) || defined(CPNGBASE_MEMBERS_ONLY) */
