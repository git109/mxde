/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: cdomelementinterfacelist.hxx
 *
 * Author: $author$
 *   Date: 7/4/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOMELEMENTINTERFACELIST_HXX
#define _CDOMELEMENTINTERFACELIST_HXX

#include "cdomelementinterfacetree.hxx"
#include "clistt.hxx"

/**
 **********************************************************************
 *  Class: cDOMElementInterfaceItem
 *
 * Author: $author$
 *   Date: 7/4/2005
 **********************************************************************
 */
class cDOMElementInterfaceItem
: public cDynamicListItemT<cDOMElementInterfaceItem>
{
public:
    typedef cDynamicListItemT<cDOMElementInterfaceItem> cIs;

    cDOMElementInterfaceBranch m_branch;

    /**
     **********************************************************************
     * Constructor: cDOMElementInterfaceItem
     *
     *      Author: $author$
     *        Date: 7/4/2005
     **********************************************************************
     */
    cDOMElementInterfaceItem(cDOMElementInterface& element) 
    : m_branch(element)
    {
    }
};

/**
 **********************************************************************
 *  Class: cDOMElementInterfaceList
 *
 * Author: $author$
 *   Date: 7/4/2005
 **********************************************************************
 */
class cDOMElementInterfaceList
: public cDynamicListT
  <cDOMElementInterfaceItem, cDOMElementInterfaceList>
{
public:
    typedef cDynamicListT
    <cDOMElementInterfaceItem, cDOMElementInterfaceList> cIs;
};

#endif /* ndef _CDOMELEMENTINTERFACELIST_HXX */

