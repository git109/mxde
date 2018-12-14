/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: cdocumentnodeinterfacelist.hxx
 *
 * Author: $author$
 *   Date: 11/13/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTNODEINTERFACELIST_HXX
#define _CDOCUMENTNODEINTERFACELIST_HXX

#include "cdocumentelementinterfacetree.hxx"
#include "cdocumentinterface.hxx"
#include "clistt.hxx"

/**
 **********************************************************************
 *  Class: cDocumentNodeInterfaceItem
 *
 * Author: $author$
 *   Date: 11/13/2005
 **********************************************************************
 */
class cDocumentNodeInterfaceItem
: public cDynamicListItemT<cDocumentNodeInterfaceItem>
{
public:
    typedef cDynamicListItemT<cDocumentNodeInterfaceItem> cIs;

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 11/13/2005
     **********************************************************************
     */
    enum
    {
        e_IS_NOT_ELEMENT,
        e_IS_ELEMENT,
        e_IS_BEGIN_ELEMENT,
        e_IS_END_ELEMENT
    };

    cDocumentNodeInterface& m_node;
    int m_is_element;

    /**
     **********************************************************************
     * Constructor: cDocumentNodeInterfaceItem
     *
     *      Author: $author$
     *        Date: 11/13/2005
     **********************************************************************
     */
    cDocumentNodeInterfaceItem
    (cDocumentNodeInterface& node, 
     int is_element=e_IS_NOT_ELEMENT) 
    : m_node(node),
      m_is_element(is_element)
    {
    }
    /**
     **********************************************************************
     * Function: GetIsElement
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    int GetIsElement() const 
    {
        return m_is_element;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentElementInterfaceItem
 *
 * Author: $author$
 *   Date: 11/13/2005
 **********************************************************************
 */
class cDocumentElementInterfaceItem
: public cDocumentNodeInterfaceItem
{
public:
    typedef cDocumentNodeInterfaceItem cIs;

    cDocumentElementInterfaceBranch m_branch;

    /**
     **********************************************************************
     * Constructor: cDocumentElementInterfaceItem
     *
     *      Author: $author$
     *        Date: 11/13/2005
     **********************************************************************
     */
    cDocumentElementInterfaceItem
    (cDocumentElementInterface& node, 
     int is_element=e_IS_ELEMENT) 
    : cIs(node, is_element),
      m_branch(node)
    {
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNodeInterfaceList
 *
 * Author: $author$
 *   Date: 11/13/2005
 **********************************************************************
 */
class cDocumentNodeInterfaceList
: public cDynamicListT
  <cDocumentNodeInterfaceItem, cDocumentNodeInterfaceList>
{
public:
    typedef cDynamicListT
    <cDocumentNodeInterfaceItem, cDocumentNodeInterfaceList> cIs;
};

#endif /* _CDOCUMENTNODEINTERFACELIST_HXX */
