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
 *   File: cxtltodocumenttokentree.hxx
 *
 * Author: $author$
 *   Date: 11/20/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CXTLTODOCUMENTTOKENTREE_HXX
#define _CXTLTODOCUMENTTOKENTREE_HXX

#include "cxtltodocumenttokeninterface.hxx"
#include "cavltreet.hxx"

/**
 **********************************************************************
 *  Class: cXTLToDocumentTokenBranch
 *
 * Author: $author$
 *   Date: 11/20/2005
 **********************************************************************
 */
class cXTLToDocumentTokenBranch
: public cAVLTreeBranchT<cXTLToDocumentTokenBranch>
{
public:
    typedef cAVLTreeBranchT<cXTLToDocumentTokenBranch> cIs;

    cXTLToDocumentTokenInterface& m_token;

    /**
     **********************************************************************
     * Constructor: cXTLToDocumentTokenBranch
     *
     *      Author: $author$
     *        Date: 11/20/2005
     **********************************************************************
     */
    cXTLToDocumentTokenBranch
    (cXTLToDocumentTokenInterface& token) 
    : m_token(token) 
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    int Compare(cXTLToDocumentTokenBranch &branch) const
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
     *     Date: 11/20/2005
     **********************************************************************
     */
    int Compare(const cCCharBuffer& name) const
    {
        const cCCharBuffer& toname = GetName();
        int unequal = toname.Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    const cCCharBuffer& GetName() const 
    {
        const cCCharBuffer& name = m_token.GetName();
        return name;
    }
    /**
     **********************************************************************
     * Function: GetToken
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    cXTLToDocumentTokenInterface& GetToken() const 
    {
        return m_token;
    }
};

/**
 **********************************************************************
 *  Class: cXTLToDocumentTokenTree
 *
 * Author: $author$
 *   Date: 11/20/2005
 **********************************************************************
 */
class cXTLToDocumentTokenTree
: public cAVLTreeT
  <const cCCharBuffer, 
   cXTLToDocumentTokenBranch, 
   cXTLToDocumentTokenTree>
{
public:
    typedef cAVLTreeT
    <const cCCharBuffer, 
     cXTLToDocumentTokenBranch, 
     cXTLToDocumentTokenTree> cIs;

    /**
     **********************************************************************
     * Constructor: cXTLToDocumentTokenTree
     *
     *      Author: $author$
     *        Date: 11/20/2005
     **********************************************************************
     */
    cXTLToDocumentTokenTree() 
    {
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    cXTLToDocumentTokenInterface *Find
    (const cCCharBuffer& name) const
    {
        cXTLToDocumentTokenInterface *token = 0;
        cXTLToDocumentTokenBranch *branch;

        if ((branch = cIs::Find(name)))
            token = &branch->GetToken();

        return token;
    }
};

#endif /* _CXTLTODOCUMENTTOKENTREE_HXX */
