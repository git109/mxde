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
 *   File: cdocumentelementinterfacetree.hxx
 *
 * Author: $author$
 *   Date: 11/13/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTELEMENTINTERFACETREE_HXX
#define _CDOCUMENTELEMENTINTERFACETREE_HXX

#include "cdocumentinterface.hxx"
#include "cavltreet.hxx"

/**
 **********************************************************************
 *  Class: cDocumentElementInterfaceBranch
 *
 * Author: $author$
 *   Date: 11/13/2005
 **********************************************************************
 */
class cDocumentElementInterfaceBranch
: public cAVLTreeBranchT<cDocumentElementInterfaceBranch>
{
public:
    typedef cAVLTreeBranchT<cDocumentElementInterfaceBranch> cIs;

    cDocumentElementInterface& m_node;

    /**
     **********************************************************************
     * Constructor: cDocumentElementInterfaceBranch
     *
     *      Author: $author$
     *        Date: 11/13/2005
     **********************************************************************
     */
    cDocumentElementInterfaceBranch
    (cDocumentElementInterface& node) 
    : m_node(node) 
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    int Compare(cDocumentElementInterfaceBranch &branch) const
    {
        cDocumentElementInterface& node = branch.GetElement();
        int unequal = Compare(node);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    int Compare(cDocumentElementInterface& node) const
    {
        const cCCharBuffer& name = node.GetName();
        int unequal = Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    int Compare(const cCCharBuffer& name) const
    {
        const cCCharBuffer& toname = m_node.GetName();
        int unequal = toname.Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetElement
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    cDocumentElementInterface& GetElement() const 
    {
        return m_node;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentElementInterfaceTree
 *
 * Author: $author$
 *   Date: 11/13/2005
 **********************************************************************
 */
class cDocumentElementInterfaceTree
: public cAVLTreeT
  <const cCCharBuffer, 
   cDocumentElementInterfaceBranch, 
   cDocumentElementInterfaceTree>
{
public:
    typedef cAVLTreeT
    <const cCCharBuffer, 
     cDocumentElementInterfaceBranch, 
     cDocumentElementInterfaceTree> cIs;
};

#endif /* _CDOCUMENTELEMENTINTERFACETREE_HXX */
