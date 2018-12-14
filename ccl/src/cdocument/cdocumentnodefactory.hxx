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
 *   File: cdocumentnodefactory.hxx
 *
 * Author: $author$
 *   Date: 10/15/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTNODEFACTORY_HXX
#define _CDOCUMENTNODEFACTORY_HXX

#include "cdocumentnamespacefactory.hxx"
#include "cdocumentnamespace.hxx"
#include "cdocumentnodefactoryimplement.hxx"
#include "cdocumentartifactimplement.hxx"
#include "cdocumenteventinterface.hxx"
#include "cdocument.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cDocumentNodeFactory
 *
 * Author: $author$
 *   Date: 10/15/2005
 **********************************************************************
 */
class cDocumentNodeFactory
: virtual public cDocumentNodeFactoryImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    cDocumentEventInterface& m_event;
    cDocumentFactoryInterface& m_factory;
    cDocumentNamespaceFactoryInterface& m_ns_factory;

    /**
     **********************************************************************
     * Constructor: cDocumentNodeFactory
     *
     *      Author: $author$
     *        Date: 10/15/2005
     **********************************************************************
     */
    cDocumentNodeFactory
    (cDocumentEventInterface& event,
     cDocumentFactoryInterface& factory,
     cDocumentNamespaceFactoryInterface& ns_factory)
    : m_event(event),
      m_factory(factory),
      m_ns_factory(ns_factory)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDocumentNodeFactory
     *
     *      Author: $author$
     *        Date: 10/15/2005
     **********************************************************************
     */
    virtual ~cDocumentNodeFactory()
    {
    }

    /**
     **********************************************************************
     * Function: GetDocumentFactory
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual cDocumentFactoryInterface& GetDocumentFactory() const
    {
        return m_factory;
    }

    /**
     **********************************************************************
     * Function: CreateElement
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* CreateElement(eError &error) 
    {
        cDocumentElement* node = 0;
        int is_dynamic;

        if ((node = new cDocumentElement(m_event, *this)))
        {
            if (0 < (is_dynamic = node->SetIsDynamic(true)))
            {
                error = e_ERROR_NONE;
                return node;
            }

            error = e_ERROR_FAILED;
            delete node;
            node = 0;
        }
        else error = e_ERROR_NEW;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateBeginElement
     *
     *   Author: $author$
     *     Date: 12/12/2005
     **********************************************************************
     */
    virtual cDocumentBeginElementInterface* 
    CreateBeginElement(eError &error) 
    {
        cDocumentBeginElement* node = 0;
        int is_dynamic;

        if ((node = new cDocumentBeginElement(m_event, *this)))
        {
            if (0 < (is_dynamic = node->SetIsDynamic(true)))
            {
                error = e_ERROR_NONE;
                return node;
            }

            error = e_ERROR_FAILED;
            delete node;
            node = 0;
        }
        else error = e_ERROR_NEW;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateEndElement
     *
     *   Author: $author$
     *     Date: 12/12/2005
     **********************************************************************
     */
    virtual cDocumentEndElementInterface* 
    CreateEndElement(eError &error) 
    {
        cDocumentEndElement* node = 0;
        int is_dynamic;

        if ((node = new cDocumentEndElement()))
        {
            if (0 < (is_dynamic = node->SetIsDynamic(true)))
            {
                error = e_ERROR_NONE;
                return node;
            }

            error = e_ERROR_FAILED;
            delete node;
            node = 0;
        }
        else error = e_ERROR_NEW;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* CreateAttribute(eError &error) 
    {
        cDocumentAttribute* node = 0;
        error = e_ERROR_FAILED;
        int is_dynamic;

        if ((node = new cDocumentAttribute(*this)))
        if (0 >= (is_dynamic = node->SetIsDynamic(true)))
        {
            error = e_ERROR_FAILED;
            delete node;
            return 0;
        }
        else error = e_ERROR_NONE;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateEntityReference
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual cDocumentEntityReferenceInterface* 
    CreateEntityReference(eError &error) 
    {
        cDocumentEntityReference* node = 0;
        int is_dynamic;

        error = e_ERROR_FAILED;

        if ((node = new cDocumentEntityReference(*this)))
        if (0 >= (is_dynamic = node->SetIsDynamic(true)))
        {
            error = e_ERROR_FAILED;
            delete node;
            return 0;
        }
        else error = e_ERROR_NONE;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateComment
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual cDocumentCommentInterface* CreateComment(eError &error) 
    {
        cDocumentComment* node = 0;
        error = e_ERROR_FAILED;
        int is_dynamic;

        if ((node = new cDocumentComment(*this)))
        if (0 >= (is_dynamic = node->SetIsDynamic(true)))
        {
            error = e_ERROR_FAILED;
            delete node;
            return 0;
        }
        else error = e_ERROR_NONE;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataInterface* CreateData(eError &error) 
    {
        cDocumentData* node = 0;
        error = e_ERROR_FAILED;
        int is_dynamic;

        if ((node = new cDocumentData(*this)))
        if (0 >= (is_dynamic = node->SetIsDynamic(true)))
        {
            delete node;
            return 0;
        }
        else error = e_ERROR_NONE;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateText
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* CreateText(eError &error) 
    {
        cDocumentText* node = 0;
        error = e_ERROR_FAILED;
        int is_dynamic;

        if ((node = new cDocumentText(*this)))
        if (0 >= (is_dynamic = node->SetIsDynamic(true)))
        {
            delete node;
            return 0;
        }
        else error = e_ERROR_NONE;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateReferenceNode
     *
     *   Author: $author$
     *     Date: 12/15/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* CreateReferenceNode
    (eError &error, cDocumentNodeInterface& node)
    {
        cDocumentNodeInterface& end_node = node.DereferenceNodeInterface();
        int type = end_node.GetType();
        cDocumentReferenceNode* new_node = 0;
        cDocumentDataInterface* data;
        cDocumentTextInterface* text;
        cDocumentAttributeInterface* attribute;
        cDocumentElementInterface* element;

        error = e_ERROR_NEW;

        switch(type)
        {
        case cDocumentNodeInterface::e_TYPE_DATA:
            if ((data = end_node.GetDataInterface()))
            if ((new_node = new cDocumentReferenceData(*data, true)))
            if ((data = new_node->GetDataInterface()))
                data->GetData();
            break;

        case cDocumentNodeInterface::e_TYPE_TEXT:
            if ((text = end_node.GetTextInterface()))
            if ((new_node = new cDocumentReferenceText(*text, true)))
            if ((text = new_node->GetTextInterface()))
                text->GetText();
            break;

        case cDocumentNodeInterface::e_TYPE_ATTRIBUTE:
            if ((attribute = end_node.GetAttributeInterface()))
            if ((new_node = new cDocumentReferenceAttribute(*attribute, true)))
            if ((attribute = new_node->GetAttributeInterface()))
                attribute->GetName();
            break;

        case cDocumentNodeInterface::e_TYPE_ELEMENT:
            if ((element = end_node.GetElementInterface()))
            if ((new_node = new cDocumentReferenceElement(*element, true)))
            if ((element = new_node->GetElementInterface()))
                element->GetName();
            break;

        default:
            new_node = new cDocumentReferenceNode(end_node, true);
        }

        if (new_node)
        if ((error = HoldNode(end_node)))
        {
            delete new_node;
            new_node = 0;
        }

        return new_node;
    }
    /**
     **********************************************************************
     * Function: HoldNode
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual eError HoldNode
    (cDocumentNodeInterface& node) 
    {
        eError error = node.HoldInstance();
        return error;
    }
    /**
     **********************************************************************
     * Function: FreeNode
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual eError FreeNode
    (cDocumentNodeInterface& node) 
    {
        eError error = DestroyNode(node);
        return error;
    }
    /**
     **********************************************************************
     * Function: DestroyNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError DestroyNode
    (cDocumentNodeInterface& node) 
    {
        eError error = node.FreeInstance();
        return error;
    }

    /**
     **********************************************************************
     * Function: CreateNodeList
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* 
    CreateNodeList(eError &error) 
    {
        cDocumentNodeList* node_list;
        int is_dynamic;

        error = e_ERROR_NEW;

        if ((node_list = new cDocumentNodeList(m_event, *this)))
        if (0 >= (is_dynamic = node_list->SetIsDynamic(true)))
        {
            delete node_list;
            return 0;
        }
        else error = e_ERROR_NONE;
        return node_list;
    }
    /**
     **********************************************************************
     * Function: DestroyNodeList
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual eError DestroyNodeList
    (cDocumentNodeListInterface& node_list) 
    {
        eError error = node_list.FreeInstance();
        return error;
    }

    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface* GetNamespace
    (const cCCharBuffer& name) 
    {
        cDocumentNamespaceInterface* ns = m_ns_factory.GetNamespace(name);
        return ns;
    }
    /**
     **********************************************************************
     * Function: FreeNamespace
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual eError FreeNamespace
    (cDocumentNamespaceInterface& ns) 
    {
        eError error = m_ns_factory.FreeNamespace(ns);
        return error;
    }
};

#endif /* _CDOCUMENTNODEFACTORY_HXX */