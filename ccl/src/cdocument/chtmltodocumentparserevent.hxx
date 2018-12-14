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
 *   File: chtmltodocumentparserevent.hxx
 *
 * Author: $author$
 *   Date: 11/12/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTMLTODOCUMENTPARSEREVENT_HXX
#define _CHTMLTODOCUMENTPARSEREVENT_HXX

#include "cdocumentnodeinterfacelist.hxx"
#include "cxmltodocumentparserevent.hxx"

/**
 **********************************************************************
 *  Class: cHTMLToDocumentParserEvent
 *
 * Author: $author$
 *   Date: 11/12/2005
 **********************************************************************
 */
class cHTMLToDocumentParserEvent
: public cXMLToDocumentParserEvent
{
public:
    typedef cXMLToDocumentParserEvent cIs;

    cDocumentNodeInterfaceList m_node_list;
    cDocumentElementInterfaceTree m_element_tree;

    /**
     **********************************************************************
     * Constructor: cHTMLToDocumentParserEvent
     *
     *      Author: $author$
     *        Date: 11/12/2005
     **********************************************************************
     */
    cHTMLToDocumentParserEvent
    (cDocumentEventInterface &event,
     cDocumentNodeFactoryInterface &factory,
     cDocumentInterface &document) 
    : cIs(event, factory, document)
    {
    }
    /**
     **********************************************************************
     * Function: OnDocument
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    virtual eError OnDocument() 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeInterfaceItem *item;
        cDocumentElementInterface *element;
        int is_element;

        for (item=m_node_list.GetFirst(); item; item=item->GetNext())
        {
            switch((is_element = item->GetIsElement()))
            {
            case cDocumentNodeInterfaceItem::e_IS_BEGIN_ELEMENT:
                if ((element = item->m_node.GetElementInterface()))
                if ((error = OnBeginElementItem(*element)))
                    return error;
                break;

            case cDocumentNodeInterfaceItem::e_IS_END_ELEMENT:
                if ((element = item->m_node.GetElementInterface()))
                if ((error = cIs::OnEndElementNode(*element)))
                    return error;
                break;

            case cDocumentNodeInterfaceItem::e_IS_ELEMENT:
                if ((element = item->m_node.GetElementInterface()))
                if ((error = cIs::OnElementNode(*element)))
                    return error;
                break;

            default:
                if ((error = cIs::OnNode(item->m_node)))
                    return error;
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginElementItem
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    virtual eError OnBeginElementItem(cDocumentElementInterface &e) 
    {
        eError error = e_ERROR_NONE;
        const cCCharBuffer &name = e.GetName();
        cDocumentElementInterfaceBranch *branch;

        if ((branch = m_element_tree.Find(name)))
            return error = cIs::OnBeginElementNode(e);

        error = cIs::OnElementNode(e);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEntityReferenceNode
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual eError OnEntityReferenceNode
    (cDocumentEntityReferenceInterface &node) 
    {
        eError error = e_ERROR_FAILED;
        cDocumentNodeInterfaceItem *item;

        if ((item = new cDocumentNodeInterfaceItem(node)))
        {
            m_node_list.Add(item);
            error = e_ERROR_NONE;
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: OnTextNode
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    virtual eError OnTextNode(cDocumentTextInterface &t) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeInterfaceItem *item;

        if ((item = new cDocumentNodeInterfaceItem(t)))
        {
            m_node_list.Add(item);
            error = e_ERROR_NONE;
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: OnCommentNode
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    virtual eError OnCommentNode(cDocumentCommentInterface &t) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeInterfaceItem *item;

        if ((item = new cDocumentNodeInterfaceItem(t)))
        {
            m_node_list.Add(item);
            error = e_ERROR_NONE;
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginElementNode
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    virtual eError OnBeginElementNode(cDocumentElementInterface &e) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterfaceItem *item;

        if ((item = new cDocumentElementInterfaceItem
            (e, cDocumentNodeInterfaceItem::e_IS_BEGIN_ELEMENT)))
        {
            m_node_list.Add(item);
            m_element = 0;
            error = e_ERROR_NONE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndElementNode
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    virtual eError OnEndElementNode(cDocumentElementInterface &e) 
    {
        eError error = e_ERROR_FAILED;
        const cCCharBuffer &name = e.GetName();
        cDocumentElementInterfaceItem *item;
        cDocumentElementInterfaceBranch *branch;

        if ((item = new cDocumentElementInterfaceItem
            (e, cDocumentNodeInterfaceItem::e_IS_END_ELEMENT)))
        {
            if (!(branch = m_element_tree.Find(name)))
                m_element_tree.Insert(&item->m_branch);

            m_node_list.Add(item);
            m_end_element = 0;
            error = e_ERROR_NONE;
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: OnElementNode
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    virtual eError OnElementNode(cDocumentElementInterface &e) 
    {
        eError error = e_ERROR_NONE;
        const cCCharBuffer &name = e.GetName();
        cDocumentElementInterfaceItem *item;
        cDocumentElementInterfaceBranch *branch;

        if ((item = new cDocumentElementInterfaceItem
            (e, cDocumentNodeInterfaceItem::e_IS_ELEMENT)))
        {
            if (!(branch = m_element_tree.Find(name)))
                m_element_tree.Insert(&item->m_branch);

            m_node_list.Add(item);
            m_element = 0;
            error = e_ERROR_NONE;
        }

        return error;
    }

    /**
     **********************************************************************
     * Function: OnEndElementPrefix
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual int OnEndElementPrefix
    (const char *text, int length=-1) 
    {
        eError error=0;
        cDocumentElementInterface *node;

        if ((node = GetEndElement(error)))
            length = node->SetNamespacePrefixChars(text, length);
        else length = -e_ERROR_FAILED;

        return length;
    }
    /**
     **********************************************************************
     * Function: OnEndElementName
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual int OnEndElementName
    (const char *text, int length=-1) 
    {
        eError error=0;
        cDocumentElementInterface *node;

        if ((node = GetEndElement(error)))
            length = node->SetNameChars(text, length);
        else length = -e_ERROR_FAILED;

        return length;
    }
};

#endif /* _CHTMLTODOCUMENTPARSEREVENT_HXX */
