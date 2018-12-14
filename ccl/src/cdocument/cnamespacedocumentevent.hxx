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
 *   File: cnamespacedocumentevent.hxx
 *
 * Author: $author$
 *   Date: 10/29/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CNAMESPACEDOCUMENTEVENT_HXX
#define _CNAMESPACEDOCUMENTEVENT_HXX

#include "cdocumentnodefactoryinterface.hxx"
#include "cdocumentnamespacestack.hxx"
#include "cdocumentnamespaceprefixlist.hxx"
#include "cdocumentnamespaceprefixtree.hxx"
#include "cdocumentevent.hxx"

/**
 **********************************************************************
 *  Class: cNamespaceDocumentEvent
 *
 * Author: $author$
 *   Date: 10/29/2005
 **********************************************************************
 */
class cNamespaceDocumentEvent
: public cDocumentEvent
{
public:
    typedef cDocumentEvent cIs;

    const cCCharBuffer &m_namespace_prefix;
    cDocumentNamespacePrefixTree m_prefix_tree;
    cDocumentNamespacePrefixList m_prefix_list;
    cDocumentNamespacePrefixList m_local_prefix_list;
    cDocumentNamespaceStack m_namespace_stack;

    /**
     **********************************************************************
     * Constructor: cNamespaceDocumentEvent
     *
     *      Author: $author$
     *        Date: 10/29/2005
     **********************************************************************
     *
    cNamespaceDocumentEvent
    (const char* namespace_prefix="xmlns", int length=-1) 
    : m_namespace_prefix(namespace_prefix, length)
    {
    }
    /**
     **********************************************************************
     * Constructor: cNamespaceDocumentEvent
     *
     *      Author: $author$
     *        Date: 10/29/2005
     **********************************************************************
     */
    cNamespaceDocumentEvent
    (const cCCharBuffer &namespace_prefix) 
    : m_namespace_prefix(namespace_prefix)
    {
    }

    /**
     **********************************************************************
     * Function: SetNamespacePrefixCChars
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     *
    virtual int SetNamespacePrefixCChars
    (const cChar *chars, int length=-1) 
    {
        length = m_namespace_prefix.Copy(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetNamespacePrefixCChars
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual const cChar* GetNamespacePrefixCChars(int &length) const 
    {
        const cChar* chars = m_namespace_prefix.GetBuffer(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetNamespacePrefix
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     *
    virtual int SetNamespacePrefix
    (const cCCharBuffer& prefix) 
    {
        int length = -e_ERROR_FAILED;
        const cChar* chars;

        if ((chars = prefix.GetBuffer(length)))
            length = SetNamespacePrefixCChars(chars, length);

        return length;
    }
    /**
     **********************************************************************
     * Function: GetNamespacePrefix
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetNamespacePrefix() const 
    {
        return m_namespace_prefix;
    }

    /**
     **********************************************************************
     * Function: OnAddComment
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual eError OnAddComment
    (cDocumentNodeListInterface& list,
     cDocumentCommentInterface& node) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNamespaceInterface &g_ns = cDocumentNamespaceInterface::GetGlobalNamespace();
        cDocumentNamespaceInterface &l_ns = m_namespace_stack.GetTop();

        if (&l_ns != &g_ns)
            error = node.SetNamespace(&l_ns);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnDeleteComment
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual eError OnDeleteComment
    (cDocumentNodeListInterface& list,
     cDocumentCommentInterface& node) 
    {
        eError error = node.SetNamespace(0);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnAddText
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual eError OnAddText
    (cDocumentNodeListInterface& list,
     cDocumentTextInterface& node) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNamespaceInterface &g_ns = cDocumentNamespaceInterface::GetGlobalNamespace();
        cDocumentNamespaceInterface &l_ns = m_namespace_stack.GetTop();

        if (&l_ns != &g_ns)
            error = node.SetNamespace(&l_ns);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnDeleteText
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual eError OnDeleteText
    (cDocumentNodeListInterface& list,
     cDocumentTextInterface& node) 
    {
        eError error = node.SetNamespace(0);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnAddAttribute
     *
     *   Author: $author$
     *     Date: 10/31/2005
     **********************************************************************
     */
    virtual eError OnAddAttribute
    (cDocumentElementInterface& element,
     cDocumentAttributeInterface& node) 
    {
        cDocumentNamespaceInterface &g_ns = cDocumentNamespaceInterface::GetGlobalNamespace();
        cDocumentNamespaceInterface &l_ns = m_namespace_stack.GetTop();
        cDocumentNamespaceInterface &e_ns = element.GetNamespace();
        const cCCharBuffer& prefix = node.GetNamespacePrefix();
        const cCCharBuffer& name = node.GetName();
        eError error = e_ERROR_NONE;
        int prefix_length, name_length;
        cDocumentNamespaceInterface* ns;
        
        if (0 < (name_length = name.GetLength()))
        if (0 < (prefix_length = prefix.GetLength()))
        {
            if (m_namespace_prefix.Compare(prefix))
            {
                if ((ns = m_prefix_tree.FindNamespace(prefix)))
                    error = node.SetNamespace(ns);
            }
            else error = OnAddNamspacePrefixAttribute
            (element, node, prefix, name);
        }
        else if (m_namespace_prefix.Compare(name))
        {
            if (&e_ns != &g_ns)
                error = node.SetNamespace(&e_ns);
            else error = node.SetNamespace(&l_ns);
        }
        else error = OnAddNamspaceAttribute(element, node, name);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnDeleteAttribute
     *
     *   Author: $author$
     *     Date: 10/31/2005
     **********************************************************************
     */
    virtual eError OnDeleteAttribute
    (cDocumentElementInterface& element,
     cDocumentAttributeInterface& node) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: OnAddNamspacePrefixAttribute
     *
     *   Author: $author$
     *     Date: 10/31/2005
     **********************************************************************
     */
    virtual eError OnAddNamspacePrefixAttribute
    (cDocumentElementInterface& element,
     cDocumentAttributeInterface& node,
     const cCCharBuffer& prefix,
     const cCCharBuffer& name) 
    {
        eError error = e_ERROR_NONE;
        const cCCharBuffer& value = node.GetValue();
        const cCCharBuffer& element_prefix = element.GetNamespacePrefix();
        cDocumentNodeFactoryInterface &factory = element.GetNodeFactory();
        cDocumentNamespaceInterface* ns;
        const cCCharBuffer* ns_prefix;
        int value_length;

        if ((error = node.SetIsNamespacePrefixAttribute()))
            return error;

        if (0 < (value_length = value.GetLength()))
        if ((ns = factory.GetNamespace(value)))
        {
            if ((ns_prefix = factory.GetName(prefix)))
            {
                if (!(error = m_local_prefix_list.Add
                    (*ns_prefix, *ns)))
                {
                    if ((element_prefix.Compare(name)))
                    {
                        if (!(error = node.SetNamespace(ns)))
                            return error;
                    }
                    else
                    {
                        if (!(error = element.SetNamespace(ns)))
                        if (!(error = node.SetNamespace(ns)))
                            return error;
                    }
                }
                factory.FreeName(*ns_prefix);
            }
            factory.FreeNamespace(*ns);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddNamspaceAttribute
     *
     *   Author: $author$
     *     Date: 10/31/2005
     **********************************************************************
     */
    virtual eError OnAddNamspaceAttribute
    (cDocumentElementInterface& element,
     cDocumentAttributeInterface& node,
     const cCCharBuffer& name) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNamespaceInterface &g_ns = cDocumentNamespaceInterface::GetGlobalNamespace();
        cDocumentNodeFactoryInterface &factory = element.GetNodeFactory();
        const cCCharBuffer& value = node.GetValue();
        cDocumentNamespaceInterface* ns = &g_ns;
        int value_length;

        if ((error = node.SetIsNamespaceAttribute()))
            return error;

        if (0 < (value_length = value.GetLength()))
        if (!(ns = factory.GetNamespace(value)))
            return error;

        if (!(error = element.SetNamespace(ns)))
        if (!(error = node.SetNamespace(ns)))
            return error;

        if (&g_ns != ns)
            factory.FreeNamespace(*ns);

        return error;
    }

    /**
     **********************************************************************
     * Function: OnBeginElement
     *
     *   Author: $author$
     *     Date: 10/31/2005
     **********************************************************************
     */
    virtual eError OnBeginElement
    (cDocumentElementInterface& node) 
    {
        cDocumentNamespaceInterface& document_namespace = node.GetNamespace();
        eError error = e_ERROR_NONE;
        cDocumentNamespacePrefixItem *item;
        cDocumentNamespacePrefixBranch *branch;
        cDocumentNamespacePrefixList overloaded_prefix_list;

        while ((item = m_local_prefix_list.Pop()))
        {
            const cCCharBuffer &item_prefix = item->GetPrefix();
            cDocumentNamespacePrefixBranch &item_branch = item->GetBranch();

            if ((branch = m_prefix_tree.Find(item_prefix)))
            {
                cDocumentNamespacePrefixNamespaceItem &item_item = item_branch.GetItem();
                branch->m_stack.Push(item_item);
                overloaded_prefix_list.Push(item);
            }
            else 
            {
                m_prefix_tree.Insert(&item_branch);
                m_prefix_list.Push(item);
            }
        }
        error = m_namespace_stack.Push
        (document_namespace, overloaded_prefix_list);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndElement
     *
     *   Author: $author$
     *     Date: 10/31/2005
     **********************************************************************
     */
    virtual eError OnEndElement
    (cDocumentElementInterface& node) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNamespacePrefixItem *item;
        cDocumentNamespacePrefixList overloaded_prefix_list;

        error = m_namespace_stack.Pop(overloaded_prefix_list);

        while ((item = overloaded_prefix_list.Pop()))
        {
            cDocumentNamespacePrefixBranch &item_branch = item->GetBranch();
            cDocumentNamespacePrefixNamespaceItem &item_item = item_branch.GetItem();
            cDocumentNamespacePrefixNamespaceStack *m_stack;

            if ((m_stack = item_item.GetStack()))
                m_stack->Pop();

            m_local_prefix_list.Free(item);
        }
        return error;
    }
};

#endif /* _CNAMESPACEDOCUMENTEVENT_HXX */
