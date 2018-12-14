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
 *   File: cdomnodeinterfacelist.hxx
 *
 * Author: $author$
 *   Date: 7/4/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOMNODEINTERFACELIST_HXX
#define _CDOMNODEINTERFACELIST_HXX

#include "cdomelementinterfacetree.hxx"
#include "clistt.hxx"

/**
 **********************************************************************
 *  Class: cDOMNodeInterfaceItem
 *
 * Author: $author$
 *   Date: 7/4/2005
 **********************************************************************
 */
class cDOMNodeInterfaceItem
: public cDynamicListItemT<cDOMNodeInterfaceItem>
{
public:
    typedef cDynamicListItemT<cDOMNodeInterfaceItem> cIs;

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 7/5/2005
     **********************************************************************
     */
    enum
    {
        e_IS_NOT_ELEMENT,
        e_IS_ELEMENT,
        e_IS_BEGIN_ELEMENT,
        e_IS_END_ELEMENT
    };

    cDOMNodeInterface& m_node;
    int m_is_element;

    /**
     **********************************************************************
     * Constructor: cDOMNodeInterfaceItem
     *
     *      Author: $author$
     *        Date: 7/4/2005
     **********************************************************************
     */
    cDOMNodeInterfaceItem
    (cDOMNodeInterface& node, 
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
     *     Date: 7/6/2005
     **********************************************************************
     */
    int GetIsElement() const 
    {
        return m_is_element;
    }
};

/**
 **********************************************************************
 *  Class: cDOMElementInterfaceItem
 *
 * Author: $author$
 *   Date: 7/4/2005
 **********************************************************************
 */
class cDOMElementInterfaceItem
: public cDOMNodeInterfaceItem
{
public:
    typedef cDOMNodeInterfaceItem cIs;

    cDOMElementInterfaceBranch m_branch;

    /**
     **********************************************************************
     * Constructor: cDOMElementInterfaceItem
     *
     *      Author: $author$
     *        Date: 7/4/2005
     **********************************************************************
     */
    cDOMElementInterfaceItem
    (cDOMElementInterface& element, 
     int is_element=e_IS_ELEMENT) 
    : cIs(element, is_element),
      m_branch(element)
    {
    }
};

/**
 **********************************************************************
 *  Class: cDOMNodeInterfaceList
 *
 * Author: $author$
 *   Date: 7/4/2005
 **********************************************************************
 */
class cDOMNodeInterfaceList
: public cDynamicListT
  <cDOMNodeInterfaceItem, cDOMNodeInterfaceList>
{
public:
    typedef cDynamicListT
    <cDOMNodeInterfaceItem, cDOMNodeInterfaceList> cIs;
};

#endif /* ndef _CDOMNODEINTERFACELIST_HXX */

