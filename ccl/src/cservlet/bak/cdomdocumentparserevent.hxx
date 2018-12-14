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

    cDOMEventInterface &m_event;
    cDOMNodeFactoryInterface &m_factory;
    cDOMDocumentInterface &m_document;
    cDOMElementInterface *m_parent;
    cDOMElementInterface *m_element;
    cDOMAttrInterface *m_attr;
    cDOMNodeListInterface *m_node_list;
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
      m_node_list(&document),
      m_attr(0),
      m_parent(0),
      m_element(0),
      m_depth(0)
    {
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
        cDOMTextInterface *t;

        if ((t = m_factory.CreateText(m_parent)))
        if (0 > (length = t->SetChars(text, length)))
            m_factory.DestroyNode(*t);
        else m_node_list->AppendText(*t);
        return length;
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
        if (m_parent)
        {
        }
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
        if (m_parent)
        {
            //printf("/%s", text);
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
        eError error = e_ERROR_NONE;
        cDOMElementInterface *e;

        if ((e = GetElement()))
        {
            /*printf("<");
            print(e);
            printf("/>: %d\n",m_depth);*/

            m_node_list->AppendElement(*e);
            m_element = 0;
        }
        else error = e_ERROR_FAILED;
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
        eError error = e_ERROR_NONE;
        cDOMElementInterface *e;

        if ((e = GetElement()))
        {
            /*printf("<");
            print(e);
            printf(">: %d\n",m_depth);
            m_depth++;*/

            m_node_list->AppendElement(*e);
            m_node_list = e;
            m_parent = e;
            m_element = 0;
            error = m_event.OnBeginElement(*e);
        }
        else error = e_ERROR_FAILED;
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

        if (m_parent)
        {
            /*--m_depth;
            printf("</");
            print(m_parent);
            printf(">: %d\n",m_depth);*/

            if ((m_parent = (e = m_parent->GetParentElement())))
            {
                m_node_list = m_parent;
                error = m_event.OnEndElement(*e);
            }
            else m_node_list = &m_document;
        }
        else error = e_ERROR_FAILED;
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
