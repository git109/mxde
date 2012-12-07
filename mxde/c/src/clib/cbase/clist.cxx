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
 *   File: clist.cxx
 *
 * Author: $author$
 *   Date: 2/24/2009
 **********************************************************************
 */
#include "clist.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cListItemT
 *
 * Author: $author$
 *   Date: 2/24/2009
 **********************************************************************
 */

#if defined(CLIST_INSTANCE_TEST) 
cListItem g_cListItem;
cList g_cList;

template<>
cExportListItem* cStaticExportList::cExtends::m_firstItem = 0;
template<>
cExportListItem* cStaticExportList::cExtends::m_lastItem = 0;
cStaticExportList g_cStaticExportList;

template<>
cListItem* cStaticList::cExtends::m_firstItem = 0;
template<>
cListItem* cStaticList::cExtends::m_lastItem = 0;
cStaticList g_cStaticList;

cDynamicListItem g_cDynamicListItem;
cDynamicList g_cDynamicList;
#endif /* defined(CLIST_INSTANCE_TEST) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

