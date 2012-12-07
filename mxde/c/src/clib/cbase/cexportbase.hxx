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
 *   File: cexportbase.hxx
 *
 * Author: $author$
 *   Date: 7/18/2009
 **********************************************************************
 */
#if !defined(_CEXPORTBASE_HXX) || defined(CEXPORTBASE_MEMBERS_ONLY)
#if !defined(_CEXPORTBASE_HXX) && !defined(CEXPORTBASE_MEMBERS_ONLY)
#define _CEXPORTBASE_HXX
#endif /* !defined(_CEXPORTBASE_HXX) && !defined(CEXPORTBASE_MEMBERS_ONLY) */

#if !defined(CEXPORTBASE_MEMBERS_ONLY)
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cExportBase
 *
 * Author: $author$
 *   Date: 7/18/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cExportBase
{
public:
#else /* !defined(CEXPORTBASE_MEMBERS_ONLY) */
#endif /* !defined(CEXPORTBASE_MEMBERS_ONLY) */

#if !defined(CEXPORTBASE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CEXPORTBASE_MEMBERS_ONLY) */
#endif /* !defined(CEXPORTBASE_MEMBERS_ONLY) */

#endif /* !defined(_CEXPORTBASE_HXX) || defined(CEXPORTBASE_MEMBERS_ONLY) */
