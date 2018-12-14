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
 *   File: cxmltodocumentparserevent.hxx
 *
 * Author: $author$
 *   Date: 10/14/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXMLTODOCUMENTPARSEREVENT_HXX
#define _CXMLTODOCUMENTPARSEREVENT_HXX

#include "cxmlparserinterface.hxx"
#include "cdocumenteventinterface.hxx"
#include "cdocument.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cXMLToDocumentParserEvent
 *
 * Author: $author$
 *   Date: 10/14/2005
 **********************************************************************
 */
class cXMLToDocumentParserEvent
: virtual public cXMLParserEventImplement,
  public cInstance
{
public:
    typedef cInstance cIs;
    typedef cXMLToDocumentParserEvent cAs;

    cDocumentEventInterface &m_event;
    cDocumentNodeFactoryInterface &m_factory;
    cDocumentInterface &m_document;
    cDocumentElementInterface *m_parent;
    cDocumentElementInterface *m_element;
    cDocumentElementInterface *m_end_element;
    cDocumentAttributeInterface *m_attribute;
    cDocumentNodeListInterface *m_children;
    int m_depth;

    /**
     **********************************************************************
     * Constructor: cXMLToDocumentParserEvent
     *
     *      Author: $author$
     *        Date: 10/14/2005
     **********************************************************************
     */
    cXMLToDocumentParserEvent
    (cDocumentEventInterface &event,
     cDocumentNodeFactoryInterface &factory,
     cDocumentInterface &document)
    : m_event(event),
      m_factory(factory),
      m_document(document),
      m_attribute(0),
      m_parent(0),
      m_element(0),
      m_end_element(0),
      m_depth(0),
      m_children(&document)
    {
    }

    /**
     **********************************************************************
     * Function: OnNode
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    virtual eError OnNode(cDocumentNodeInterface &node) 
    {
        eError error = e_ERROR_NONE;
        int node_type = node.GetType();
        cDocumentEntityReferenceInterface *entity;
        cDocumentElementInterface *element;
        cDocumentCommentInterface *comment;
        cDocumentTextInterface *text;

        switch(node_type)
        {
        case cDocumentNodeInterface::e_TYPE_ELEMENT:
            if ((element = node.GetElementInterface()))
                error = cAs::OnElementNode(*element);
            break;

        case cDocumentNodeInterface::e_TYPE_COMMENT:
            if ((comment = node.GetCommentInterface()))
                error = cAs::OnCommentNode(*comment);
            break;

        case cDocumentNodeInterface::e_TYPE_TEXT:
            if ((text = node.GetTextInterface()))
                error = cAs::OnTextNode(*text);
            break;

        case cDocumentNodeInterface::e_TYPE_ENTITY_REFERENCE:
            if ((entity = node.GetEntityReferenceInterface()))
                error = cAs::OnEntityReferenceNode(*entity);
            break;
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: OnAttributeNode
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual eError OnAttributeNode
    (cDocumentAttributeInterface& node) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterface *element;

        if ((element = GetElement(error)))
        if (!(error = element->AddAttribute(node)))
            m_attribute = 0;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnElementNode
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnElementNode
    (cDocumentElementInterface& node) 
    {
        eError error = e_ERROR_NONE;

        if (!(error = node.SetParentElement(m_parent)))
        if (!(error = m_children->AddElement(node)))
            m_element = 0;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginElementNode
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnBeginElementNode
    (cDocumentElementInterface& node) 
    {
        eError error = e_ERROR_NONE;

        if (!(error = node.SetParentElement(m_parent)))
        if (!(error = m_children->AddElement(node)))
        {
            m_children = &node;
            m_parent = &node;
            m_element = 0;
            error = m_event.OnBeginElement(node);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndElementNode
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnEndElementNode
    (cDocumentElementInterface& node) 
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
     * Function: OnEntityReferenceNode
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual eError OnEntityReferenceNode
    (cDocumentEntityReferenceInterface &node) 
    {
        eError error;

        if (!(error = node.SetParentElement(m_parent)))
            error = m_children->AddEntityReference(node);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCommentNode
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnCommentNode(cDocumentCommentInterface &node) 
    {
        eError error;

        if (!(error = node.SetParentElement(m_parent)))
            error = m_children->AddComment(node);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnTextNode
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual eError OnTextNode(cDocumentTextInterface &node) 
    {
        eError error;

        if (!(error = node.SetParentElement(m_parent)))
            error = m_children->AddText(node);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnElement() 
    {
        eError error = e_ERROR_FAILED;
        cDocumentElementInterface *node;

        if ((node = GetElement(error)))
            error = OnElementNode(*node);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnBeginElement() 
    {
        eError error = e_ERROR_FAILED;
        cDocumentElementInterface *node;

        if ((node = GetElement(error)))
            error = OnBeginElementNode(*node);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnEndElement() 
    {
        eError error = e_ERROR_FAILED;
        cDocumentElementInterface *node;

        if ((node = GetEndElement(error)))
            error = OnEndElementNode(*node);
        return error;
    }

    /**
     **********************************************************************
     * Function: OnElementPrefix
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int OnElementPrefix
    (const char *text, int length=-1) 
    {
        eError error=0;
        cDocumentElementInterface *node;

        if ((node = GetElement(error)))
            length = node->SetNamespacePrefixChars(text, length);
        else length = -e_ERROR_FAILED;

        return length;
    }
    /**
     **********************************************************************
     * Function: OnElementName
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int OnElementName
    (const char *text, int length=-1) 
    {
        eError error=0;
        cDocumentElementInterface *node;

        if ((node = GetElement(error)))
            length = node->SetNameChars(text, length);
        else length = -e_ERROR_FAILED;

        return length;
    }

    /**
     **********************************************************************
     * Function: OnAttributePrefix
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int OnAttributePrefix
    (const char *text, int length=-1) 
    {
        eError error=0;
        cDocumentAttributeInterface *node;

        if ((node = GetAttribute(error)))
            length = node->SetNamespacePrefixChars(text, length);
        else length = -e_ERROR_FAILED;

        return length;
    }
    /**
     **********************************************************************
     * Function: OnAttributeName
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int OnAttributeName
    (const char *text, int length=-1) 
    {
        eError error=0;
        cDocumentAttributeInterface *node;

        if ((node = GetAttribute(error)))
            length = node->SetNameChars(text, length);
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
        eError error=0;
        cDocumentAttributeInterface *node;

        if ((node = GetAttribute(error)))
        {
            if (0 <= (length = node->SetValueChars(text, length)))
            if ((error = OnAttributeNode(*node)))
                length = -e_ERROR_FAILED;
        }
        else length = -e_ERROR_FAILED;

        return length;
    }

    /**
     **********************************************************************
     * Function: OnEntity
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual int OnEntity
    (const char *text, int length=-1) 
    {
        length = -e_ERROR_FAILED;
        eError error;
        cDocumentEntityReferenceInterface *node;

        if ((node = m_factory.CreateEntityReference(error)))
        {
            if (0 <= (length = node->SetNameChars(text, length)))
            if ((error = OnEntityReferenceNode(*node)))
               length = -error;
            else return length;

            m_factory.DestroyNode(*node);
        }
        else length = -error;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnComment
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual int OnComment
    (const char *text, int length=-1) 
    {
        length = -e_ERROR_FAILED;
        eError error;
        cDocumentCommentInterface *node;

        if ((node = m_factory.CreateComment(error)))
        {
            if (0 <= (length = node->SetTextChars(text, length)))
            if ((error = OnCommentNode(*node)))
               length = -error;
            else return length;

            m_factory.DestroyNode(*node);
        }
        else length = -error;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnText
     *
     *   Author: $author$
     *     Date: 10/14/2005
     **********************************************************************
     */
    virtual int OnText
    (const char *text, int length=-1) 
    {
        length = -e_ERROR_FAILED;
        eError error;
        cDocumentTextInterface *node;

        if ((node = m_factory.CreateText(error)))
        {
            if (0 <= (length = node->SetTextChars(text, length)))
            if ((error = OnTextNode(*node)))
                length = -error;
            else return length;

            m_factory.DestroyNode(*node);
        }
        else length = -error;
        return length;
    }

    /**
     **********************************************************************
     * Function: GetElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    cDocumentElementInterface *GetElement(eError error) 
    {
        if (!m_element)
            m_element = m_factory.CreateElement(error);

        return m_element;
    }
    /**
     **********************************************************************
     * Function: GetEndElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    cDocumentElementInterface *GetEndElement(eError error) 
    {
        if (!m_end_element)
            m_end_element = m_factory.CreateElement(error);

        return m_end_element;
    }
    /**
     **********************************************************************
     * Function: GetAttribute
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    cDocumentAttributeInterface *GetAttribute(eError error) 
    {
        if (!m_attribute)
            m_attribute = m_factory.CreateAttribute(error);

        return m_attribute;
    }
};

#endif /* _CXMLTODOCUMENTPARSEREVENT_HXX */