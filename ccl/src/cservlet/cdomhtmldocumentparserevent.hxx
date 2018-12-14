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
 *   File: cdomhtmldocumentparserevent.hxx
 *
 * Author: $author$
 *   Date: 7/2/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOMHTMLDOCUMENTPARSEREVENT_HXX
#define _CDOMHTMLDOCUMENTPARSEREVENT_HXX

#include "cdomnodeinterfacelist.hxx"
#include "cdomdocumentparserevent.hxx"

/**
 **********************************************************************
 *  Class: cDOMHTMLDocumentParserEvent
 *
 * Author: $author$
 *   Date: 7/2/2005
 **********************************************************************
 */
class cDOMHTMLDocumentParserEvent
: public cDOMDocumentParserEvent
{
public:
    typedef cDOMDocumentParserEvent cIs;

    cDOMNodeInterfaceList m_node_list;
    cDOMElementInterfaceTree m_element_tree;

    /**
     **********************************************************************
     * Constructor: cDOMHTMLDocumentParserEvent
     *
     *      Author: $author$
     *        Date: 7/2/2005
     **********************************************************************
     */
    cDOMHTMLDocumentParserEvent
    (cDOMEventInterface &event,
     cDOMNodeFactoryInterface &factory, 
     cDOMDocumentInterface &document) 
    : cIs(event, factory, document)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDOMHTMLDocumentParserEvent
     *
     *      Author: $author$
     *        Date: 7/4/2005
     **********************************************************************
     */
    virtual ~cDOMHTMLDocumentParserEvent()
    {
        m_node_list.Clear();
    }

    /**
     **********************************************************************
     * Function: OnDocument
     *
     *   Author: $author$
     *     Date: 7/6/2005
     **********************************************************************
     */
    virtual eError OnDocument() 
    {
        eError error = e_ERROR_NONE;
        cDOMNodeInterfaceItem *item;
        cDOMElementInterface *element;
        int is_element;

        for (item=m_node_list.GetFirst(); item; item=item->GetNext())
        {
            switch((is_element = item->GetIsElement()))
            {
            case cDOMNodeInterfaceItem::e_IS_BEGIN_ELEMENT:
                if ((element = item->m_node.GetElementNode()))
                if ((error = OnBeginElementItem(*element)))
                    return error;
                break;

            case cDOMNodeInterfaceItem::e_IS_END_ELEMENT:
                if ((element = item->m_node.GetElementNode()))
                if ((error = cIs::OnEndElementNode(*element)))
                    return error;
                break;

            case cDOMNodeInterfaceItem::e_IS_ELEMENT:
                if ((element = item->m_node.GetElementNode()))
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
     *     Date: 7/6/2005
     **********************************************************************
     */
    virtual eError OnBeginElementItem(cDOMElementInterface &e) 
    {
        eError error = e_ERROR_NONE;
        const cStringInterface &name_string = e.GetName();
        const cChar *name_chars;
        cDOMElementInterfaceBranch *branch;

        if ((name_chars = name_string.GetChars()))
        if ((branch = m_element_tree.Find(name_chars)))
            return error = cIs::OnBeginElementNode(e);

        error = cIs::OnElementNode(e);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnEntityReferenceNode
     *
     *   Author: $author$
     *     Date: 7/19/2005
     **********************************************************************
     */
    virtual eError OnEntityReferenceNode
    (cDOMEntityReferenceInterface &t) 
    {
        eError error = e_ERROR_NONE;
        cDOMNodeInterfaceItem *item;

        if ((item = new cDOMNodeInterfaceItem(t)))
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
     *     Date: 7/4/2005
     **********************************************************************
     */
    virtual eError OnTextNode(cDOMTextInterface &t) 
    {
        eError error = e_ERROR_NONE;
        cDOMNodeInterfaceItem *item;

        if ((item = new cDOMNodeInterfaceItem(t)))
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
     *     Date: 7/15/2005
     **********************************************************************
     */
    virtual eError OnCommentNode(cDOMCommentInterface &t) 
    {
        eError error = e_ERROR_NONE;
        cDOMNodeInterfaceItem *item;

        if ((item = new cDOMNodeInterfaceItem(t)))
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
     *     Date: 7/6/2005
     **********************************************************************
     */
    virtual eError OnBeginElementNode(cDOMElementInterface &e) 
    {
        eError error = e_ERROR_NONE;
        cDOMElementInterfaceItem *item;

        if ((item = new cDOMElementInterfaceItem
            (e, cDOMNodeInterfaceItem::e_IS_BEGIN_ELEMENT)))
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
     *     Date: 7/6/2005
     **********************************************************************
     */
    virtual eError OnEndElementNode(cDOMElementInterface &e) 
    {
        eError error = e_ERROR_FAILED;
        const cStringInterface &name_string = e.GetName();
        const cChar *name_chars;
        cDOMElementInterfaceItem *item;
        cDOMElementInterfaceBranch *branch;

        if ((item = new cDOMElementInterfaceItem
            (e, cDOMNodeInterfaceItem::e_IS_END_ELEMENT)))
        {
            if ((name_chars = name_string.GetChars()))
            if (!(branch = m_element_tree.Find(name_chars)))
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
     *     Date: 7/5/2005
     **********************************************************************
     */
    virtual eError OnElementNode(cDOMElementInterface &e) 
    {
        eError error = e_ERROR_NONE;
        const cStringInterface &name_string = e.GetName();
        const cChar *name_chars;
        cDOMElementInterfaceItem *item;
        cDOMElementInterfaceBranch *branch;

        if ((item = new cDOMElementInterfaceItem
            (e, cDOMNodeInterfaceItem::e_IS_ELEMENT)))
        {
            if ((name_chars = name_string.GetChars()))
            if (!(branch = m_element_tree.Find(name_chars)))
                m_element_tree.Insert(&item->m_branch);

            m_node_list.Add(item);
            m_element = 0;
            error = e_ERROR_NONE;
        }

        return error;
    }
};

#endif /* _CDOMHTMLDOCUMENTPARSEREVENT_HXX */