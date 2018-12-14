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
 *   File: cdomelementinterfacetree.hxx
 *
 * Author: $author$
 *   Date: 7/4/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOMELEMENTINTERFACETREE_HXX
#define _CDOMELEMENTINTERFACETREE_HXX

#include "cavltreet.hxx"

/**
 **********************************************************************
 *  Class: cDOMElementInterfaceBranch
 *
 * Author: $author$
 *   Date: 7/4/2005
 **********************************************************************
 */
class cDOMElementInterfaceBranch
: public cAVLTreeBranchT<cDOMElementInterfaceBranch>
{
public:
    typedef cAVLTreeBranchT<cDOMElementInterfaceBranch> cIs;

    cDOMElementInterface& m_element;

    /**
     **********************************************************************
     * Constructor: cDOMElementInterfaceBranch
     *
     *      Author: $author$
     *        Date: 7/4/2005
     **********************************************************************
     */
    cDOMElementInterfaceBranch(cDOMElementInterface& element)
    : m_element(element)
    {
    }

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 7/4/2005
     **********************************************************************
     */
    int Compare(cDOMElementInterfaceBranch &branch) const
    {
        const cStringInterface &ename = branch.m_element.GetName();
        const cChar* name = ename.GetChars();
        int unequal = Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 7/4/2005
     **********************************************************************
     */
    int Compare(const cChar* name) const
    {
        const cStringInterface &this_ename = m_element.GetName();
        const cChar* this_name = this_ename.GetChars();
        int unequal = -1;

        if (this_name && name)
            unequal = cChar::Compare(this_name, name);

        return unequal;
    }
};
/**
 **********************************************************************
 *  Class: cDOMElementInterfaceTree
 *
 * Author: $author$
 *   Date: 7/4/2005
 **********************************************************************
 */
class cDOMElementInterfaceTree
: public cAVLTreeT
  <const cChar*, 
   cDOMElementInterfaceBranch, 
   cDOMElementInterfaceTree>
{
public:
    typedef cAVLTreeT
    <const cChar*, 
     cDOMElementInterfaceBranch, 
     cDOMElementInterfaceTree> cIs;

    /**
     **********************************************************************
     * Constructor: cDOMElementInterfaceTree
     *
     *      Author: $author$
     *        Date: 7/4/2005
     **********************************************************************
     */
    cDOMElementInterfaceTree() 
    {
    }
};

#endif /* ndef _CDOMELEMENTINTERFACETREE_HXX */

