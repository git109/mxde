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
 *   File: cdocumentnamespaceprefixtree.hxx
 *
 * Author: $author$
 *   Date: 10/29/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTNAMESPACEPREFIXTREE_HXX
#define _CDOCUMENTNAMESPACEPREFIXTREE_HXX

#include "cdocumentnamespaceprefixnamespacelist.hxx"
#include "cavltreet.hxx"
#include "cccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cDocumentNamespacePrefixBranch
 *
 * Author: $author$
 *   Date: 10/29/2005
 **********************************************************************
 */
class cDocumentNamespacePrefixBranch
: public cAVLTreeBranchT<cDocumentNamespacePrefixBranch>
{
public:
    typedef cAVLTreeBranchT<cDocumentNamespacePrefixBranch> cIs;

    const cCCharBuffer& m_prefix;
    cDocumentNamespacePrefixNamespaceItem m_item;
    cDocumentNamespacePrefixNamespaceStack m_stack;

    /**
     **********************************************************************
     * Constructor: cDocumentNamespacePrefixBranch
     *
     *      Author: $author$
     *        Date: 10/29/2005
     **********************************************************************
     */
    cDocumentNamespacePrefixBranch
    (const cCCharBuffer& prefix,
     cDocumentNamespaceInterface& document_namespace) 
    : m_prefix(prefix),
      m_item(document_namespace),
      m_stack(document_namespace)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDocumentNamespacePrefixBranch
     *
     *     Author: $author$
     *       Date: 10/29/2005
     **********************************************************************
     */
    virtual ~cDocumentNamespacePrefixBranch()
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
    int Compare(cDocumentNamespacePrefixBranch &branch) const
    {
        const cCCharBuffer& prefix = branch.GetPrefix();
        int unequal = Compare(prefix);
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
    int Compare(const cCCharBuffer& prefix) const
    {
        int unequal = m_prefix.Compare(prefix);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetPrefix
     *
     *   Author: $author$
     *     Date: 10/30/2005
     **********************************************************************
     */
    const cCCharBuffer& GetPrefix() const 
    {
        return m_prefix;
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 10/30/2005
     **********************************************************************
     */
    cDocumentNamespaceInterface& GetNamespace() const 
    {
        cDocumentNamespaceInterface& document_namespace = m_stack.GetTop();
        return document_namespace;
    }
    /**
     **********************************************************************
     * Function: GetItem
     *
     *   Author: $author$
     *     Date: 10/30/2005
     **********************************************************************
     */
    cDocumentNamespacePrefixNamespaceItem& GetItem() 
    {
        return m_item;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNamespacePrefixTree
 *
 * Author: $author$
 *   Date: 10/29/2005
 **********************************************************************
 */
class cDocumentNamespacePrefixTree
: public cAVLTreeT
  <const cCCharBuffer, 
   cDocumentNamespacePrefixBranch, 
   cDocumentNamespacePrefixTree>
{
public:
    typedef cAVLTreeT
    <const cCCharBuffer, 
     cDocumentNamespacePrefixBranch, 
     cDocumentNamespacePrefixTree> cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentNamespacePrefixTree
     *
     *      Author: $author$
     *        Date: 10/29/2005
     **********************************************************************
     */
    cDocumentNamespacePrefixTree() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cDocumentNamespacePrefixTree
     *
     *     Author: $author$
     *       Date: 10/29/2005
     **********************************************************************
     */
    virtual ~cDocumentNamespacePrefixTree() 
    {
    }

    /**
     **********************************************************************
     * Function: FindNamespace
     *
     *   Author: $author$
     *     Date: 10/30/2005
     **********************************************************************
     */
    cDocumentNamespaceInterface* FindNamespace
    (const cCCharBuffer& prefix) const 
    {
        cDocumentNamespaceInterface* document_namespace = 0;
        cDocumentNamespacePrefixBranch* branch;

        if ((branch = cIs::Find(prefix)))
            document_namespace = &branch->GetNamespace();

        return document_namespace;
    }
    /**
     **********************************************************************
     * Function: FindNamespace
     *
     *   Author: $author$
     *     Date: 10/31/2005
     **********************************************************************
     */
    cDocumentNamespaceInterface* FindNamespace
    (const cChar* prefix, int prefix_length) const 
    {
        cDocumentNamespaceInterface* document_namespace = 0;

        if (prefix)
        if (0 < prefix_length)
        {
            cCCharBuffer buffer
            (prefix, prefix_length+1, prefix_length);

            document_namespace = FindNamespace(buffer);
        }
        return document_namespace;
    }
};

#endif /* _CDOCUMENTNAMESPACEPREFIXTREE_HXX */
