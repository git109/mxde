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
 *   File: cdomdocumentparserevent.hxx
 *
 * Author: $author$
 *   Date: 11/30/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOMDOCUMENTPARSEREVENT_HXX
#define _CDOMDOCUMENTPARSEREVENT_HXX

#include <stdio.h>
#include "cdom.hxx"
#include "cdominterface.hxx"
#include "cxmlparserinterface.hxx"

/**
 **********************************************************************
 *  Class: cDOMDocumentParserEvent
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
class cDOMDocumentParserEvent
: public cXMLParserEventImplement
{
public:
    typedef cXMLParserEventImplement cIs;
    typedef cDOMDocumentParserEvent cAs;

    cDOMEventInterface &m_event;
    cDOMNodeFactoryInterface &m_factory;
    cDOMDocumentInterface &m_document;
    cDOMElementInterface *m_parent;
    cDOMElementInterface *m_element;
    cDOMElementInterface *m_end_element;
    cDOMAttrInterface *m_attr;
    cDOMNodeListInterface *m_children;
    int m_depth;

    /**
     **********************************************************************
     * Constructor: cDOMDocumentParserEvent
     *
     *      Author: $author$
     *        Date: 11/28/2004
     **********************************************************************
     */
    cDOMDocumentParserEvent
    (cDOMEventInterface &event,
     cDOMNodeFactoryInterface &factory, 
     cDOMDocumentInterface &document) 
    : m_event(event),
      m_factory(factory),
      m_document(document),
      m_children(&document),
      m_attr(0),
      m_parent(0),
      m_element(0),
      m_end_element(0),
      m_depth(0)
    {
    }

    /**
     **********************************************************************
     * Function: OnNode
     *
     *   Author: $author$
     *     Date: 7/6/2005
     **********************************************************************
     */
    virtual eError OnNode(cDOMNodeInterface &node) 
    {
        eError error = e_ERROR_NONE;
        int node_type = node.GetNodeType();
        cDOMElementInterface *dom_element;
        cDOMCommentInterface *dom_comment;
        cDOMEntityReferenceInterface *dom_entity;
        cDOMTextInterface *dom_text;

        switch(node_type)
        {
        case cDOMNodeInterface::e_TYPE_ELEMENT_NODE:
            if ((dom_element = node.GetElementNode()))
                error = cAs::OnElementNode(*dom_element);
            break;

        case cDOMNodeInterface::e_TYPE_COMMENT_NODE:
            if ((dom_comment = node.GetCommentNode()))
                error = cAs::OnCommentNode(*dom_comment);
            break;

        case cDOMNodeInterface::e_TYPE_TEXT_NODE:
            if ((dom_text = node.GetTextNode()))
                error = cAs::OnTextNode(*dom_text);
            break;

        case cDOMNodeInterface::e_TYPE_ENTITY_REFERENCE_NODE:
            if ((dom_entity = node.GetEntityReferenceNode()))
                error = cAs::OnEntityReferenceNode(*dom_entity);
            break;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnTextNode
     *
     *   Author: $author$
     *     Date: 7/2/2005
     **********************************************************************
     */
    virtual eError OnTextNode(cDOMTextInterface &t) 
    {
        eError error = e_ERROR_NONE;

        t.SetParentElement(m_parent);
        m_children->AppendText(t);
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

        t.SetParentElement(m_parent);
        m_children->AppendEntityReference(t);
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
    virtual eError OnCommentNode(cDOMCommentInterface &e) 
    {
        eError error = e_ERROR_NONE;

        e.SetParentElement(m_parent);
        m_children->AppendComment(e);
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

        e.SetParentElement(m_parent);
        m_children->AppendElement(e);
        m_element = 0;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginElementNode
     *
     *   Author: $author$
     *     Date: 7/5/2005
     **********************************************************************
     */
    virtual eError OnBeginElementNode(cDOMElementInterface &e) 
    {
        eError error = e_ERROR_NONE;

        e.SetParentElement(m_parent);
        m_children->AppendElement(e);
        m_children = &e;
        m_parent = &e;
        m_element = 0;
        error = m_event.OnBeginElement(e);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndElementNode
     *
     *   Author: $author$
     *     Date: 7/5/2005
     **********************************************************************
     */
    virtual eError OnEndElementNode(cDOMElementInterface &e) 
    {
        eError error = e_ERROR_FAILED;

        if (m_parent)
        {
            if ((m_parent = m_parent->GetParentElement()))
            {
                m_children = m_parent;
                error = m_event.OnEndElement(*m_parent);
            }
            else 
            {
                m_children = &m_document;
                error = e_ERROR_NONE;
            }
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: OnText
     *
     *   Author: $author$
     *     Date: 12/17/2004
     **********************************************************************
     */
    virtual int OnText
    (const char *text, int length=-1) 
    {
        length = -e_ERROR_FAILED;
        eError error;
        cDOMTextInterface *t;

        if ((t = m_factory.CreateText(m_parent)))
        {
            if (0 <= (length = t->SetChars(text, length)))
            if (!(error = OnTextNode(*t)))
                return length;
            else length = -error;

            m_factory.DestroyNode(*t);
        }
        return length;
    }

    /**
     **********************************************************************
     * Function: OnEntity
     *
     *   Author: $author$
     *     Date: 7/19/2005
     **********************************************************************
     */
    virtual int OnEntity
    (const char *text, int length=-1) 
    {
        int count = -e_ERROR_FAILED;
        eError error;
        cDOMEntityReferenceInterface *t;

        if ((t = m_factory.CreateEntityReference(m_parent)))
        {
            if (0 <= (count = t->SetName(text, length)))
            if (!(error = OnEntityReferenceNode(*t)))
                return count;
            else count = -error;

            m_factory.DestroyNode(*t);
        }
        return count;
    }

    /**
     **********************************************************************
     * Function: OnComment
     *
     *   Author: $author$
     *     Date: 7/15/2005
     **********************************************************************
     */
    virtual eError OnComment
    (const char *text, int length=-1) 
    {
        eError error = e_ERROR_FAILED;
        cDOMCommentInterface *c;

        if ((c = m_factory.CreateComment(m_parent)))
        {
            if (0 <= (length = c->SetChars(text, length)))
            if (!(error = OnCommentNode(*c)))
                return length;
            else length = -error;

            m_factory.DestroyNode(*c);
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: OnElementPrefix
     *
     *   Author: $author$
     *     Date: 11/24/2004
     **********************************************************************
     */
    virtual int OnElementPrefix
    (const char *text, int length=-1) 
    {
        cDOMElementInterface *e;

        if ((e = GetElement()))
            length = e->SetPrefix(text, length);
        else length = -e_ERROR_FAILED;

        return length;
    }
    /**
     **********************************************************************
     * Function: OnElementName
     *
     *   Author: $author$
     *     Date: 11/24/2004
     **********************************************************************
     */
    virtual int OnElementName
    (const char *text, int length=-1) 
    {
        cDOMElementInterface *e;

        if ((e = GetElement()))
        {
            /*printf("%s", text);*/
            length = e->SetName(text, length);
        }
        else length = -e_ERROR_FAILED;

        return length;
    }

    /**
     **********************************************************************
     * Function: OnEndElementPrefix
     *
     *   Author: $author$
     *     Date: 11/24/2004
     **********************************************************************
     */
    virtual int OnEndElementPrefix
    (const char *text, int length=-1) 
    {
        cDOMElementInterface *e;

        if ((e = GetEndElement()))
            length = e->SetPrefix(text, length);
        else length = -e_ERROR_FAILED;

        return length;
    }
    /**
     **********************************************************************
     * Function: OnEndElementName
     *
     *   Author: $author$
     *     Date: 11/24/2004
     **********************************************************************
     */
    virtual int OnEndElementName
    (const char *text, int length=-1) 
    {
        cDOMElementInterface *e;

        if ((e = GetEndElement()))
        {
            /*printf("%s", text);*/
            length = e->SetName(text, length);
        }
        else length = -e_ERROR_FAILED;

        return length;
    }

    /**
     **********************************************************************
     * Function: OnAttributePrefix
     *
     *   Author: $author$
     *     Date: 11/24/2004
     **********************************************************************
     */
    virtual int OnAttributePrefix
    (const char *text, int length=-1) 
    {
        cDOMAttrInterface *a;

        if ((a = GetAttribute()))
            length = a->SetPrefix(text, length);
        else length = -e_ERROR_FAILED;

        return length;
    }
    /**
     **********************************************************************
     * Function: OnAttributeName
     *
     *   Author: $author$
     *     Date: 11/24/2004
     **********************************************************************
     */
    virtual int OnAttributeName
    (const char *text, int length=-1) 
    {
        cDOMAttrInterface *a;

        if ((a = GetAttribute()))
            length = a->SetName(text, length);
        else length = -e_ERROR_FAILED;

        return length;
    }
    /**
     **********************************************************************
     * Function: OnAttributeValue
     *
     *   Author: $author$
     *     Date: 11/24/2004
     **********************************************************************
     */
    virtual int OnAttributeValue
    (const char *text, int length=-1) 
    {
        cDOMAttrInterface *a;
        cDOMElementInterface *e;

        if ((a = GetAttribute()))
        {
            if (0 <= (length = a->SetValue(text, length)))
            if ((e = GetElement()))
            {
                e->AppendAttribute(*a);
                m_attr = 0;
            }
            else length = -e_ERROR_FAILED;
        }
        else length = -e_ERROR_FAILED;

        return length;
    }

    /**
     **********************************************************************
     * Function: OnElement
     *
     *   Author: $author$
     *     Date: 11/28/2004
     **********************************************************************
     */
    virtual eError OnElement() 
    {
        eError error = e_ERROR_FAILED;
        cDOMElementInterface *e;

        if ((e = GetElement()))
        {
            /*printf("<");
            print(e);
            printf("/>: %d\n",m_depth);*/

            error = OnElementNode(*e);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginElement
     *
     *   Author: $author$
     *     Date: 11/28/2004
     **********************************************************************
     */
    virtual eError OnBeginElement() 
    {
        eError error = e_ERROR_FAILED;
        cDOMElementInterface *e;

        if ((e = GetElement()))
        {
            /*printf("<");
            print(e);
            printf(">: %d\n",m_depth);
            m_depth++;*/

            error = OnBeginElementNode(*e);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndElement
     *
     *   Author: $author$
     *     Date: 11/28/2004
     **********************************************************************
     */
    virtual eError OnEndElement() 
    {
        eError error = e_ERROR_NONE;
        cDOMElementInterface *e;

        if ((e = GetEndElement()))
        {
            /*printf("</");
            print(e);
            printf(">: %d\n",m_depth);
            m_depth++;*/

            error = OnEndElementNode(*e);
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: GetElement
     *
     *   Author: $author$
     *     Date: 11/28/2004
     **********************************************************************
     */
    cDOMElementInterface *GetElement() 
    {
        if (!m_element)
            m_element = m_factory.CreateElement(m_parent);

        return m_element;
    }
    /**
     **********************************************************************
     * Function: GetEndElement
     *
     *   Author: $author$
     *     Date: 7/5/2005
     **********************************************************************
     */
    cDOMElementInterface *GetEndElement() 
    {
        if (!m_end_element)
            m_end_element = m_factory.CreateElement(m_parent);

        return m_end_element;
    }
    /**
     **********************************************************************
     * Function: GetAttribute
     *
     *   Author: $author$
     *     Date: 11/28/2004
     **********************************************************************
     */
    cDOMAttrInterface *GetAttribute() 
    {
        cDOMElementInterface *e;

        if (!m_attr)
        if ((e = GetElement()))
            m_attr = m_factory.CreateAttribute(*e);

        return m_attr;
    }
/*
    void print(cDOMNamedNodeInterface *e)
    {
            const cStringInterface& name = e->GetName();
            const cChar* chars;
            int length;

            if ((chars = name.GetChars(length)))
            for (int i=0; i<length; i++)
                printf("%c", chars[i].ToChar());
    }
*/
};

#endif /* ndef _CDOMDOCUMENTPARSEREVENT_HXX */
