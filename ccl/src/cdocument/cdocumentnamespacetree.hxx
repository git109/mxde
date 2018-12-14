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
 *   File: cdocumentnamespacetree.hxx
 *
 * Author: $author$
 *   Date: 10/29/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTNAMESPACETREE_HXX
#define _CDOCUMENTNAMESPACETREE_HXX

#include "cdocumentnamespaceinterface.hxx"
#include "curiinterface.hxx"
#include "cavltreet.hxx"

/**
 **********************************************************************
 *  Class: cDocumentNamespaceBranch
 *
 * Author: $author$
 *   Date: 10/29/2005
 **********************************************************************
 */
class cDocumentNamespaceBranch
: public cAVLTreeBranchT<cDocumentNamespaceBranch>
{
public:
    typedef cAVLTreeBranchT<cDocumentNamespaceBranch> cIs;

    cDocumentNamespaceInterface& m_document_namespace;

    /**
     **********************************************************************
     * Constructor: cDocumentNamespaceBranch
     *
     *      Author: $author$
     *        Date: 10/29/2005
     **********************************************************************
     */
    cDocumentNamespaceBranch
    (cDocumentNamespaceInterface& document_namespace) 
    : m_document_namespace(document_namespace) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDocumentNamespaceBranch
     *
     *     Author: $author$
     *       Date: 10/29/2005
     **********************************************************************
     */
    virtual ~cDocumentNamespaceBranch()
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    int Compare(cDocumentNamespaceBranch &branch) const
    {
        const cURIInterface& uri = branch.GetNamespaceURI();
        int unequal = Compare(uri);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    int Compare(const cURIInterface& uri) const
    {
        const cURIInterface& this_uri = GetNamespaceURI();
        int unequal = this_uri.Compare(uri);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/3/2005
     **********************************************************************
     */
    int Compare(const cCCharBuffer& uri) const
    {
        const cURIInterface& this_uri = GetNamespaceURI();
        int unequal = this_uri.Compare(uri);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetNamespaceURI
     *
     *   Author: $author$
     *     Date: 11/3/2005
     **********************************************************************
     */
    const cURIInterface& GetNamespaceURI() const 
    {
        const cURIInterface& m_uri = m_document_namespace.GetNamespaceURI();
        return m_uri;
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    cDocumentNamespaceInterface& GetNamespace() const 
    {
        return m_document_namespace;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNamespaceURINameTree
 *
 * Author: $author$
 *   Date: 11/3/2005
 **********************************************************************
 */
class cDocumentNamespaceURINameTree
: public cAVLTreeT
  <const cCCharBuffer, 
   cDocumentNamespaceBranch, 
   cDocumentNamespaceURINameTree>
{
public:
    typedef cAVLTreeT
    <const cCCharBuffer, 
     cDocumentNamespaceBranch, 
     cDocumentNamespaceURINameTree> cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentNamespaceURINameTree
     *
     *      Author: $author$
     *        Date: 11/3/2005
     **********************************************************************
     */
    cDocumentNamespaceURINameTree() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDocumentNamespaceURINameTree
     *
     *     Author: $author$
     *       Date: 11/3/2005
     **********************************************************************
     */
    virtual ~cDocumentNamespaceURINameTree() 
    {
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 11/3/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface* Find
    (const cCCharBuffer& uri) const
    {
        cDocumentNamespaceInterface* found = 0;
        cDocumentNamespaceBranch* branch;

        if ((branch = cIs::Find(uri)))
            found = &branch->GetNamespace();
        return found;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNamespaceTree
 *
 * Author: $author$
 *   Date: 10/29/2005
 **********************************************************************
 */
class cDocumentNamespaceTree
: public cAVLTreeT
  <const cURIInterface, 
   cDocumentNamespaceBranch, 
   cDocumentNamespaceTree>
{
public:
    typedef cAVLTreeT
    <const cURIInterface, 
     cDocumentNamespaceBranch, 
     cDocumentNamespaceTree> cIs;

    cDocumentNamespaceURINameTree m_uri_name_tree;

    /**
     **********************************************************************
     * Constructor: cDocumentNamespaceTree
     *
     *      Author: $author$
     *        Date: 10/29/2005
     **********************************************************************
     */
    cDocumentNamespaceTree() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cDocumentNamespaceTree
     *
     *     Author: $author$
     *       Date: 10/29/2005
     **********************************************************************
     */
    virtual ~cDocumentNamespaceTree() 
    {
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 11/3/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface* Find
    (const cCCharBuffer& uri) const
    {
        cDocumentNamespaceInterface* found = m_uri_name_tree.Find(uri);
        return found;
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface* Find
    (const cURIInterface& uri) const
    {
        cDocumentNamespaceInterface* found = 0;
        cDocumentNamespaceBranch* branch;

        if ((branch = cIs::Find(uri)))
            found = &branch->GetNamespace();
        return found;
    }

    /**
     **********************************************************************
     * Function: Insert
     *
     *   Author: $author$
     *     Date: 11/3/2005
     **********************************************************************
     */
    void Insert(cDocumentNamespaceBranch* branch) 
    {
        cIs::Insert(branch);
        m_uri_name_tree.SetRoot(GetRoot());
    }
    /**
     **********************************************************************
     * Function: Delete
     *
     *   Author: $author$
     *     Date: 11/3/2005
     **********************************************************************
     */
    void Delete(cDocumentNamespaceBranch* branch) 
    {
        cIs::Delete(branch);
        m_uri_name_tree.SetRoot(GetRoot());
    }
};

#endif /* _CDOCUMENTNAMESPACETREE_HXX */
