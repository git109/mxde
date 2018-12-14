/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: cxalandocument.hxx
 *
 * Author: $author$
 *   Date: 12/15/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXALANDOCUMENT_HXX
#define _CXALANDOCUMENT_HXX

#include <XalanDOM/XalanDocument.hpp>
#include <XalanDOM/XalanElement.hpp>
#include <XalanDOM/XalanText.hpp>
#include <XalanDOM/XalanAttr.hpp>

#include "cxalandomstring.hxx"
#include "ccharbuffer.hxx"
#include "chandlet.hxx"
#include "nsxalan.hxx"

/**
 **********************************************************************
 *  Class: cXalanNodeT
 *
 * Author: $author$
 *   Date: 12/22/2003
 **********************************************************************
 */
template <class TXalanNode>
class cXalanNodeT
: public cHandleT<TXalanNode *, 0>
{
public:
    typedef cHandleT<TXalanNode *, 0> cIs;

    cCharBuffer m_char_text;

    /**
     **********************************************************************
     * Constructor: cXalanNodeT
     *
     *      Author: $author$
     *        Date: 12/22/2003
     **********************************************************************
     */
    cXalanNodeT(TXalanNode *xalan_node=0) 
    : cIs(xalan_node) 
    {
    }

    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 12/23/2003
     **********************************************************************
     */
    const nsXalan::XalanDOMString *GetName() const
    {
        if (m_handle)
            return &m_handle->getNodeName();

        return 0;
    }
    /**
     **********************************************************************
     * Function: GetText
     *
     *   Author: $author$
     *     Date: 12/22/2003
     **********************************************************************
     */
    const nsXalan::XalanDOMString *GetText() const
    {
        if (m_handle)
            return &m_handle->getNodeValue();

        return 0;
    }
    /**
     **********************************************************************
     * Function: GetCharText
     *
     *   Author: $author$
     *     Date: 12/22/2003
     **********************************************************************
     */
    const char *GetCharText()
    {
        int count;
        const char *text = "";

        if (m_handle)
        {
            cXalanDOMString xalan_string(m_handle->getNodeValue());

            if (0 <= (count = m_char_text.Clear()))
            if (0 <= (count = xalan_string.ToStream(m_char_text)))
            if (!(text = m_char_text.GetBuffer()))
                text = "";
        }

        return text;
    }
};

/**
 **********************************************************************
 *  Class: cXalanAttr
 *
 * Author: $author$
 *   Date: 12/22/2003
 **********************************************************************
 */
class cXalanAttr
: public cXalanNodeT<nsXalan::XalanAttr>
{
public:
    typedef cXalanNodeT<nsXalan::XalanAttr> cIs;

    /**
     **********************************************************************
     * Constructor: cXalanAttr
     *
     *      Author: $author$
     *        Date: 12/22/2003
     **********************************************************************
     */
    cXalanAttr(nsXalan::XalanAttr *xalan_attr=0) 
    : cIs(xalan_attr) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXalanText
 *
 * Author: $author$
 *   Date: 12/15/2003
 **********************************************************************
 */
class cXalanText
: public cHandleT<nsXalan::XalanText *, 0>
{
public:
    typedef cHandleT<nsXalan::XalanText *, 0> cIs;

    cCharBuffer m_char_text;

    /**
     **********************************************************************
     * Constructor: cXalanText
     *
     *      Author: $author$
     *        Date: 12/15/2003
     **********************************************************************
     */
    cXalanText(nsXalan::XalanText *xalan_text=0) 
    : cIs(xalan_text) 
    {
    }

    /**
     **********************************************************************
     * Function: GetCharText
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    const char *GetCharText()
    {
        int count;
        const char *text = "";

        if (m_handle)
        {
            cXalanDOMString xalan_string(m_handle->getNodeValue());

            if (0 <= (count = m_char_text.Clear()))
            if (0 <= (count = xalan_string.ToStream(m_char_text)))
            if (!(text = m_char_text.GetBuffer()))
                text = "";
        }

        return text;
    }
};

/**
 **********************************************************************
 *  Class: cXalanElement
 *
 * Author: $author$
 *   Date: 12/15/2003
 **********************************************************************
 */
class cXalanElement
: public cHandleT<nsXalan::XalanElement *, 0>
{
public:
    typedef cHandleT<nsXalan::XalanElement *, 0> cIs;

    /**
     **********************************************************************
     * Constructor: cXalanElement
     *
     *      Author: $author$
     *        Date: 12/15/2003
     **********************************************************************
     */
    cXalanElement(nsXalan::XalanElement *xalan_element=0) 
    : cIs(xalan_element) 
    {
    }

    /**
     **********************************************************************
     * Function: GetFirstElementByName
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    virtual eError GetFirstElementByName
    (cXalanElement &element, const char *name) const
    {
        eError error=e_ERROR_FAILED;
        nsXalan::XalanDOMString xalan_string(name);

        if (!(error = GetFirstElement(element)))
        do
        {
            if (!xalan_string.compare
                (element.GetHandle()->getNodeName()))
                return error;
        }
        while (!(error = element.GetNextElement(element)));

        return error;
    }
    /**
     **********************************************************************
     * Function: GetAttributeByName
     *
     *   Author: $author$
     *     Date: 12/22/2003
     **********************************************************************
     */
    virtual eError GetAttributeByName
    (cXalanAttr &attribute, const char *name) const
    {
        eError error=e_ERROR_FAILED;
        nsXalan::XalanDOMString xalan_string(name);
        nsXalan::XalanAttr *xalan_attr;

        if ((xalan_attr = m_handle->getAttributeNode(xalan_string)))
            error = attribute.Attach(xalan_attr);

        return error;
    }
    /**
     **********************************************************************
     * Function: GetNextElementByName
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    virtual eError GetNextElementByName
    (cXalanElement &element, const char *name) const
    {
        eError error=e_ERROR_FAILED;
        nsXalan::XalanDOMString xalan_string(name);

        while (!(error = element.GetNextElement(element)))
        {
            if (!xalan_string.compare
                (element.GetHandle()->getNodeName()))
                return error;
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: GetFirstElement
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    virtual eError GetFirstElement(cXalanElement &element) const
    {
        eError error=e_ERROR_FAILED;
        nsXalan::XalanNode *xalan_node;

        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

        if ((xalan_node = m_handle->getFirstChild()))
        do
        {
            if ((nsXalan::XalanNode::ELEMENT_NODE == xalan_node->getNodeType()))
            {
                if ((error = element.Attach
                    ((nsXalan::XalanElement*)xalan_node)))
                    return e_ERROR_ATTACH;

                return e_ERROR_NONE;
            }
        }
        while ((xalan_node = xalan_node->getNextSibling()));

        return error;
    }
    /**
     **********************************************************************
     * Function: GetNextElement
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    virtual eError GetNextElement(cXalanElement &element) const
    {
        eError error=e_ERROR_FAILED;
        nsXalan::XalanNode *xalan_node;

        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

        xalan_node = m_handle;

        while ((xalan_node = xalan_node->getNextSibling()))
        {
            if ((nsXalan::XalanNode::ELEMENT_NODE  == xalan_node->getNodeType()))
            {
                if ((error = element.Attach
                    ((nsXalan::XalanElement*)xalan_node)))
                    return e_ERROR_ATTACH;

                return e_ERROR_NONE;
            }
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: GetFirstTextNode
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    virtual eError GetFirstTextNode(cXalanText &text) const
    {
        eError error=e_ERROR_FAILED;
        nsXalan::XalanNode *xalan_node;

        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

        if ((xalan_node = m_handle->getFirstChild()))
        do
        {
            if ((nsXalan::XalanNode::TEXT_NODE  == xalan_node->getNodeType()))
            {
                if ((error = text.Attach
                    ((nsXalan::XalanText*)xalan_node)))
                    return e_ERROR_ATTACH;

                return e_ERROR_NONE;
            }
        }
        while ((xalan_node = xalan_node->getNextSibling()));

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cXalanDocument
 *
 * Author: $author$
 *   Date: 12/15/2003
 **********************************************************************
 */
class cXalanDocument
: public cHandleT<nsXalan::XalanDocument *, 0>
{
public:
    typedef cHandleT<nsXalan::XalanDocument *, 0> cIs;

    /**
     **********************************************************************
     * Constructor: cXalanDocument
     *
     *      Author: $author$
     *        Date: 12/15/2003
     **********************************************************************
     */
    cXalanDocument(nsXalan::XalanDocument *xalan_document=0) 
    : cIs(xalan_document) 
    {
    }

    /**
     **********************************************************************
     * Function: GetFirstElement
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    virtual eError GetFirstElement(cXalanElement &element) const
    {
        eError error=e_ERROR_FAILED;
        nsXalan::XalanNode *xalan_node;

        if (!m_handle)
            return e_ERROR_NOT_ATTACHED;

        if ((xalan_node = m_handle->getFirstChild()))
        do
        {
            if ((nsXalan::XalanNode::ELEMENT_NODE  == xalan_node->getNodeType()))
            {
                if ((error = element.Attach
                    ((nsXalan::XalanElement*)xalan_node)))
                    return e_ERROR_ATTACH;

                return e_ERROR_NONE;
            }
        }
        while ((xalan_node = xalan_node->getNextSibling()));

        return error;
    }
};

#endif /* ndef _CXALANDOCUMENT_HXX */
