/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: cnamespacedomevent.hxx
 *
 * Author: $author$
 *   Date: 12/9/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CNAMESPACEDOMEVENT_HXX
#define _CNAMESPACEDOMEVENT_HXX

#include "cdom.hxx"

/**
 **********************************************************************
 *  Class: cNamespaceDOMEvent
 *
 * Author: $author$
 *   Date: 12/5/2004
 **********************************************************************
 */
class cNamespaceDOMEvent
: public cDOMEvent
{
public:
    typedef cDOMEvent cIs;

    cString m_xmlns;
    cDOMNamespacePrefixTree m_prefix_tree;
    cDOMNamespacePrefixList m_prefix_list;
    cDOMNamespacePrefixList m_local_prefix_list;
    cDOMNamespaceStack m_namespace_stack;

    /**
     **********************************************************************
     * Constructor: cNamespaceDOMEvent
     *
     *      Author: $author$
     *        Date: 12/5/2004
     **********************************************************************
     */
    cNamespaceDOMEvent() 
    : m_xmlns("xmlns")
    {
    }

    /**
     **********************************************************************
     * Function: OnBeginElement
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError OnBeginElement
    (cDOMElementInterface& element) 
    {
        cDOMNamespaceInterface& l_namespace = element.GetNamespace();
        eError error;
        cDOMNamespacePrefixItem *item;
        cDOMNamespacePrefixBranch *branch;
        cDOMNamespacePrefixList overloaded_prefix_list;

        while ((item = m_local_prefix_list.Pop()))
        {
            const cStringInterface &item_prefix = item->GetPrefix();
            cDOMNamespacePrefixBranch &item_branch = item->GetBranch();

            if ((branch = m_prefix_tree.Find(item_prefix)))
            {
                cDOMNamespacePrefixNamespaceItem &item_item = item_branch.GetItem();
                branch->m_stack.Push(&item_item);
                overloaded_prefix_list.Push(item);
            }
            else 
            {
                m_prefix_tree.Insert(&item_branch);
                m_prefix_list.Push(item);
            }
        }
        error = m_namespace_stack.Push
        (l_namespace, overloaded_prefix_list);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndElement
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError OnEndElement
    (cDOMElementInterface& element) 
    {
        cDOMNamespacePrefixList overloaded_prefix_list;
        eError error = m_namespace_stack.Pop(overloaded_prefix_list);
        cDOMNamespacePrefixItem *item;

        while ((item = overloaded_prefix_list.Pop()))
        {
            cDOMNamespacePrefixBranch &item_branch = item->GetBranch();
            cDOMNamespacePrefixNamespaceItem &item_item = item_branch.GetItem();
            cDOMNamespacePrefixNamespaceStack *m_stack;

            if ((m_stack = item_item.m_stack))
                m_stack->Pop();

            m_local_prefix_list.Free(item);
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: OnAppendElement
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError OnAppendElement
    (cDOMNodeListInterface& list,
     cDOMElementInterface& element) 
    {
        eError error = e_ERROR_NONE;
        cDOMNamespaceInterface& g_namespace = cDOMNamespace::GetGlobalNamespace();
        cDOMNamespaceInterface& l_namespace = m_namespace_stack.GetTop();
        cDOMNamespaceInterface& e_namespace = element.GetNamespace();
        const cStringInterface &prefix = element.GetPrefix();
        const cStringInterface &name = element.GetName();
        int length;
        bool has;

        if (&e_namespace == &g_namespace)
        if (!(has = element.GetHasNamespace()))
        if (0 < (length = prefix.Length()))
        {
            cDOMNamespaceInterface* n;

            if ((n = m_prefix_tree.FindNamespace(prefix)))
                error = element.SetNamespace(n);
        }
        else error = element.SetNamespace(&l_namespace);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRemoveElement
     *
     *   Author: $author$
     *     Date: 12/7/2004
     **********************************************************************
     */
    virtual eError OnRemoveElement
    (cDOMNodeListInterface& list,
     cDOMElementInterface& element) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: OnAppendXmlnsPrefixAttribute
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual eError OnAppendXmlnsPrefixAttribute
    (cDOMElementInterface& element,
     cDOMAttrInterface &attr,
     const cStringInterface &prefix,
     const cStringInterface &name,
     const cStringInterface &value) 
    {
        eError error = e_ERROR_NONE;
        cDOMNodeFactoryInterface &factory = element.GetFactory();
        const cStringInterface &element_prefix = element.GetPrefix();
        cDOMNamespaceInterface *l_namespace;
        int is, has;

        if (0 > (is = attr.SetIsXmlns()))
            return error = -is;

        if ((l_namespace = factory.GetNamespace(value)))
        {
            if (!(error = m_local_prefix_list
                .Add(name, *l_namespace)))
            if ((element_prefix.Compare(name)))
            {
                if (!(error = attr.SetNamespace(l_namespace)))
                if (0 > (has = attr.SetHasNamespace()))
                    error = -has;
            }
            else
            {
                if (!(error = element.SetNamespace(l_namespace)))
                if (!(error = attr.SetNamespace(l_namespace)))
                if (0 > (has = element.SetHasNamespace()))
                    error = -has;
                else if (0 > (has = attr.SetHasNamespace()))
                        error = -has;
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAppendXmlnsAttribute
     *
     *   Author: $author$
     *     Date: 12/6/2004
     **********************************************************************
     */
    virtual eError OnAppendXmlnsAttribute
    (cDOMElementInterface& element,
     cDOMAttrInterface &attr,
     const cStringInterface &name,
     const cStringInterface &value) 
    {
        eError error = e_ERROR_NONE;
        cDOMNodeFactoryInterface &factory = element.GetFactory();
        cDOMNamespaceInterface &g_namespace = cDOMNamespaceInterface::GetGlobalNamespace();
        cDOMNamespaceInterface *l_namespace = &g_namespace;
        int is, has, length;

        if (0 > (is = attr.SetIsXmlns()))
            return error = -is;

        if (0 < (length = value.Length()))
            l_namespace = factory.GetNamespace(value);

        if (l_namespace)
        if (!(error = element.SetNamespace(l_namespace)))
        if (!(error = attr.SetNamespace(l_namespace)))
        if (0 > (has = element.SetHasNamespace()))
            error = -has;
        else if (0 > (has = attr.SetHasNamespace()))
                error = -has;

        return error;
    }
    /**
     **********************************************************************
     * Function: OnAppendAttribute
     *
     *   Author: $author$
     *     Date: 12/5/2004
     **********************************************************************
     */
    virtual eError OnAppendAttribute
    (cDOMElementInterface& element,
     cDOMAttrInterface &attr) 
    {
        eError error = e_ERROR_NONE;
        cDOMNamespaceInterface &g_namespace = cDOMNamespace::GetGlobalNamespace();
        cDOMNamespaceInterface &l_namespace = m_namespace_stack.GetTop();
        cDOMNamespaceInterface &e_namespace = element.GetNamespace();
        const cStringInterface &prefix = attr.GetPrefix();
        const cStringInterface &name = attr.GetName();
        const cStringInterface &value = attr.GetValue();
        int length;

        if (0 < (length = name.Length()))
        if (m_xmlns.Compare(prefix))
        {
            if (0 < (length = prefix.Length()))
            {
                cDOMNamespaceInterface* n;

                if ((n = m_prefix_tree.FindNamespace(prefix)))
                    error = attr.SetNamespace(n);
            }
            else if (m_xmlns.Compare(name))
            {
                if (&e_namespace == &g_namespace)
                    error = attr.SetNamespace(&l_namespace);
                else error = attr.SetNamespace(&e_namespace);
                return error;
            }
            else error = OnAppendXmlnsAttribute
                (element, attr, name, value);
        }
        else error = OnAppendXmlnsPrefixAttribute
            (element, attr, prefix, name, value);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnRemoveAttribute
     *
     *   Author: $author$
     *     Date: 12/5/2004
     **********************************************************************
     */
    virtual eError OnRemoveAttribute
    (cDOMElementInterface& element,
     cDOMAttrInterface &attr) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: OnAppendText
     *
     *   Author: $author$
     *     Date: 12/19/2004
     **********************************************************************
     */
    virtual eError OnAppendText
    (cDOMNodeListInterface& list,
     cDOMTextInterface& text) 
    {
        eError error = e_ERROR_NONE;
        cDOMElementInterface* parent;

        if ((parent = text.GetParentElement()))
        {
            cDOMNamespaceInterface& ns = parent->GetNamespace();

            error = text.SetNamespace(&ns);
        }
        return error;
    }
};

#endif /* _CNAMESPACEDOMEVENT_HXX */