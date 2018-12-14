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
 *   File: cccharnamereferencetree.hxx
 *
 * Author: $author$
 *   Date: 11/1/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CCCHARNAMEREFERENCETREE_HXX
#define _CCCHARNAMEREFERENCETREE_HXX

#include "cccharbuffer.hxx"
#include "cavltreet.hxx"

/**
 **********************************************************************
 *  Class: cCCharNameReferenceBranch
 *
 * Author: $author$
 *   Date: 11/1/2005
 **********************************************************************
 */
class cCCharNameReferenceBranch
: public cAVLTreeBranchT<cCCharNameReferenceBranch>
{
public:
    typedef cAVLTreeBranchT<cCCharNameReferenceBranch> cIs;

    const cCCharBuffer& m_name;

    /**
     **********************************************************************
     * Constructor: cCCharNameReferenceBranch
     *
     *      Author: $author$
     *        Date: 11/1/2005
     **********************************************************************
     */
    cCCharNameReferenceBranch(const cCCharBuffer& name) 
    : m_name(name) 
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    int Compare(cCCharNameReferenceBranch &branch) const
    {
        const cCCharBuffer& name = branch.GetName();
        int unequal = Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    int Compare(const cCCharBuffer& name) const
    {
        int unequal = m_name.Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    const cCCharBuffer& GetName() const 
    {
        return m_name;
    }
};
/**
 **********************************************************************
 *  Class: cCCharNameReferenceTree
 *
 * Author: $author$
 *   Date: 11/1/2005
 **********************************************************************
 */
class cCCharNameReferenceTree
: public cAVLTreeT
  <const cCCharBuffer, 
   cCCharNameReferenceBranch, 
   cCCharNameReferenceTree>
{
public:
    typedef cAVLTreeT
    <const cCCharBuffer, 
     cCCharNameReferenceBranch, 
     cCCharNameReferenceTree> cIs;

    /**
     **********************************************************************
     * Constructor: cCCharNameReferenceTree
     *
     *      Author: $author$
     *        Date: 11/1/2005
     **********************************************************************
     */
    cCCharNameReferenceTree() 
    {
    }

    /**
     **********************************************************************
     * Function: FindName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    const cCCharBuffer* FindName
    (const cCCharBuffer& name) const 
    {
        const cCCharBuffer* found_name = 0;
        cCCharNameReferenceBranch* branch;

        if ((branch = cIs::Find(name)))
            found_name = &branch->GetName();

        return found_name;
    }
    /**
     **********************************************************************
     * Function: FindName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    const cCCharBuffer* FindName
    (const cChar* chars, int length=-1) const 
    {
        const cCCharBuffer find_name(chars, length);
        const cCCharBuffer* found_name = 0;
        cCCharNameReferenceBranch* branch;

        if ((branch = cIs::Find(find_name)))
            found_name = &branch->GetName();

        return found_name;
    }
};

#endif /* _CCCHARNAMEREFERENCETREE_HXX */
