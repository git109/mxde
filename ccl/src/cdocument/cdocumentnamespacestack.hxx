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
 *   File: cdocumentnamespacestack.hxx
 *
 * Author: $author$
 *   Date: 10/31/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTNAMESPACESTACK_HXX
#define _CDOCUMENTNAMESPACESTACK_HXX

#include "cdocumentnamespaceprefixlist.hxx"

/**
 **********************************************************************
 *  Class: cDocumentNamespaceStackItem
 *
 * Author: $author$
 *   Date: 10/31/2005
 **********************************************************************
 */
class cDocumentNamespaceStackItem
: public cDynamicListItemT<cDocumentNamespaceStackItem>
{
public:
    typedef cDynamicListItemT<cDocumentNamespaceStackItem> cIs;

    cDocumentNamespaceInterface& m_document_namespace;
    cDocumentNamespacePrefixList m_prefix_list;

    /**
     **********************************************************************
     * Constructor: cDocumentNamespaceStackItem
     *
     *      Author: $author$
     *        Date: 10/31/2005
     **********************************************************************
     */
    cDocumentNamespaceStackItem
    (cDocumentNamespaceInterface& document_namespace,
     cDocumentNamespacePrefixList& prefix_list) 
    : m_document_namespace(document_namespace) 
    {
        cDocumentNamespacePrefixItem *item;

        while ((item = prefix_list.Pop()))
            m_prefix_list.Push(item);
    }
    /**
     **********************************************************************
     * Destructor: ~cDocumentNamespaceStackItem
     *
     *     Author: $author$
     *       Date: 10/31/2005
     **********************************************************************
     */
    virtual ~cDocumentNamespaceStackItem() 
    {
        eError error;

        if ((error = m_prefix_list.Clear()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 10/31/2005
     **********************************************************************
     */
    cDocumentNamespaceInterface& GetNamespace() const 
    {
        return m_document_namespace;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNamespaceStack
 *
 * Author: $author$
 *   Date: 10/31/2005
 **********************************************************************
 */
class cDocumentNamespaceStack
: public cDynamicListT
  <cDocumentNamespaceStackItem, cDocumentNamespaceStack>
{
public:
    typedef cDynamicListT
    <cDocumentNamespaceStackItem, cDocumentNamespaceStack> cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentNamespaceStack
     *
     *      Author: $author$
     *        Date: 10/31/2005
     **********************************************************************
     */
    cDocumentNamespaceStack() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDocumentNamespaceStack
     *
     *     Author: $author$
     *       Date: 10/31/2005
     **********************************************************************
     */
    virtual ~cDocumentNamespaceStack() 
    {
    }

    /**
     **********************************************************************
     * Function: Push
     *
     *   Author: $author$
     *     Date: 10/30/2005
     **********************************************************************
     */
    eError Push
    (cDocumentNamespaceInterface& document_namespace,
     cDocumentNamespacePrefixList& prefix_list) 
    {
        eError error = e_ERROR_NEW;
        cDocumentNamespaceStackItem* item;

        if ((item = new cDocumentNamespaceStackItem
            (document_namespace, prefix_list)))
        {
            cIs::Push(item);
            error = e_ERROR_NONE;
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: Pop
     *
     *   Author: $author$
     *     Date: 10/31/2005
     **********************************************************************
     */
    eError Pop
    (cDocumentNamespacePrefixList& prefix_list) 
    {
        eError error = e_ERROR_FAILED;
        cDocumentNamespaceStackItem* stack_item;
        cDocumentNamespacePrefixItem *prefix_item;

        if ((stack_item = cIs::Pop()))
        {
            while ((prefix_item = stack_item->m_prefix_list.Pop()))
                prefix_list.Push(prefix_item);

            error = cIs::Free(stack_item);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: GetTop
     *
     *   Author: $author$
     *     Date: 10/31/2005
     **********************************************************************
     */
    cDocumentNamespaceInterface& GetTop() const 
    {
        cDocumentNamespaceInterface& document_namespace
            = cDocumentNamespaceInterface::GetGlobalNamespace();
        cDocumentNamespaceStackItem* item;

        if ((item = cIs::GetFirst()))
            return item->GetNamespace();

        return document_namespace;
    }
};

#endif /* _CDOCUMENTNAMESPACESTACK_HXX */
