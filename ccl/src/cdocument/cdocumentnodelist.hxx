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
 *   File: cdocumentnodelist.hxx
 *
 * Author: $author$
 *   Date: 12/2/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTNODELIST_HXX
#define _CDOCUMENTNODELIST_HXX

#include "cdocumentnode.hxx"

/**
 **********************************************************************
 *  Class: cDocumentNodeListT
 *
 * Author: $author$
 *   Date: 10/13/2005
 **********************************************************************
 */
template
<class TAs, class TIs=cInstance>

class cDocumentNodeListT
: virtual public cDocumentNodeFactoryArtifactImplement,
  virtual public cDocumentEventArtifactImplement,
  virtual public cDocumentAttributeListImplement,
  virtual public cDocumentNodeListImplement,
  public cDynamicListT<cDocumentNode, TAs, TIs>
{
public:
    typedef cDynamicListT<cDocumentNode, TAs, TIs> cIs;

    cDocumentNodeFactoryInterface& m_node_factory;
    cDocumentEventInterface* m_event;

    /**
     **********************************************************************
     * Constructor: cDocumentNodeListT
     *
     *      Author: $author$
     *        Date: 10/13/2005
     **********************************************************************
     */
    cDocumentNodeListT
    (cDocumentEventInterface& event,
     cDocumentNodeFactoryInterface& node_factory) 
    : m_node_factory(node_factory),
      m_event(&event)
    {
    }
    /**
     **********************************************************************
     * Constructor: cDocumentNodeListT
     *
     *      Author: $author$
     *        Date: 10/13/2005
     **********************************************************************
     */
    cDocumentNodeListT
    (cDocumentNodeFactoryInterface& node_factory) 
    : m_node_factory(node_factory),
      m_event(0)
    {
    }

    /**
     **********************************************************************
     * Function: AddText
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual eError AddText
    (cDocumentTextInterface& node) 
    {
        cDocumentEventInterface& event = GetEvent();
        eError error;

        if (!(error = AddNode(node)))
            error = event.OnAddText(*this, node);
        return error;
    }
    /**
     **********************************************************************
     * Function: AddComment
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual eError AddComment
    (cDocumentCommentInterface& node) 
    {
        cDocumentEventInterface& event = GetEvent();
        eError error;

        if (!(error = AddNode(node)))
            error = event.OnAddComment(*this, node);
        return error;
    }
    /**
     **********************************************************************
     * Function: AddBeginElement
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual eError AddBeginElement
    (cDocumentBeginElementInterface& node) 
    {
        cDocumentEventInterface& event = GetEvent();
        eError error;

        if (!(error = AddNode(node)))
            error = event.OnAddBeginElement(*this, node);
        return error;
    }
    /**
     **********************************************************************
     * Function: AddEndElement
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual eError AddEndElement
    (cDocumentEndElementInterface& node) 
    {
        cDocumentEventInterface& event = GetEvent();
        eError error;

        if (!(error = AddNode(node)))
            error = event.OnAddEndElement(*this, node);
        return error;
    }
    /**
     **********************************************************************
     * Function: AddElement
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual eError AddElement
    (cDocumentElementInterface& node) 
    {
        cDocumentEventInterface& event = GetEvent();
        eError error;

        if (!(error = AddNode(node)))
            error = event.OnAddElement(*this, node);
        return error;
    }
    /**
     **********************************************************************
     * Function: AddAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual eError AddAttribute
    (cDocumentAttributeInterface& node) 
    {
        cDocumentEventInterface& event = GetEvent();
        eError error;

        if (!(error = AddNode(node)))
            error = event.OnAddAttribute(*this, node);
        return error;
    }
    /**
     **********************************************************************
     * Function: AddEntityReference
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual eError AddEntityReference
    (cDocumentEntityReferenceInterface& node) 
    {
        cDocumentEventInterface& event = GetEvent();
        eError error;

        if (!(error = AddNode(node)))
            error = event.OnAddEntityReference(*this, node);
        return error;
    }

    /**
     **********************************************************************
     * Function: PushNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError PushNode
    (cDocumentNodeInterface& node) 
    {
        cDocumentNode& dnode=node.AsDocumentNode();
        eError error = e_ERROR_NONE;

        Push(&dnode);
        return error;
    }
    /**
     **********************************************************************
     * Function: AddNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError AddNode
    (cDocumentNodeInterface& node) 
    {
        cDocumentNode& dnode=node.AsDocumentNode();
        eError error = e_ERROR_NONE;

        Add(&dnode);
        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError DeleteNode
    (cDocumentNodeInterface& node) 
    {
        cDocumentNode& dnode=node.AsDocumentNode();
        eError error = e_ERROR_NONE;

        Delete(&dnode);
        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteAllNodes
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual eError DeleteAllNodes() 
    {
        eError error = Clear();
        return error;
    }

    /**
     **********************************************************************
     * Function: PopNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* PopNode() 
    {
        cDocumentNode* node = Pop();
        return node;
    }
    /**
     **********************************************************************
     * Function: PullNode
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* PullNode() 
    {
        cDocumentNode* node = Pull();
        return node;
    }

    /**
     **********************************************************************
     * Function: GetFirstNode
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* GetFirstNode(int type=0) const
    {
        cDocumentNodeInterface* node = GetFirst();
        int node_type;

        if (node)
        if (0 < type)
        {
            if (0 < (node_type = node->GetType()))
            if (type & node_type)
                return node;

            node = node->GetNextNode(type);
        }
        return node;
    }
    /**
     **********************************************************************
     * Function: GetLastNode
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* GetLastNode(int type=0) const
    {
        cDocumentNodeInterface* node = GetLast();
        int node_type;

        if (node)
        if (0 < type)
        {
            if (0 < (node_type = node->GetType()))
            if (type & node_type)
                return node;

            node = node->GetPreviousNode(type);
        }
        return node;
    }

    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual eError Free(cOf *item)
    {
        eError error = e_ERROR_NULL_PARAMETER;
        
        if (item)
            error = m_node_factory.DestroyNode(*item);
        return error;
    }

    /**
     **********************************************************************
     * Function: GetNodeFactory
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual cDocumentNodeFactoryInterface& GetNodeFactory() const 
    {
        return m_node_factory;
    }
    /**
     **********************************************************************
     * Function: GetEvent
     *
     *   Author: $author$
     *     Date: 11/24/2005
     **********************************************************************
     */
    virtual cDocumentEventInterface& GetEvent() const 
    {
        if (m_event)
            return *m_event;

        return cDocumentEventInterface::GetNullEvent();
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNodeList
 *
 * Author: $author$
 *   Date: 12/2/2005
 **********************************************************************
 */
class cDocumentNodeList
: public cDocumentNodeListT
  <cDocumentNodeList,cIsDynamicDocumentArtifact>
{
public:
    typedef cDocumentNodeListT
    <cDocumentNodeList,cIsDynamicDocumentArtifact> cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentNodeList
     *
     *      Author: $author$
     *        Date: 12/2/2005
     **********************************************************************
     */
    cDocumentNodeList
    (cDocumentEventInterface &event,
     cDocumentNodeFactoryInterface &node_factory, 
     bool is_dynamic=false) 
    : cIs(event, node_factory)
    {
        m_is_dynamic = is_dynamic;
    }
    /**
     **********************************************************************
     *  Destructor: ~cDocumentNodeList
     *
     *      Author: $author$
     *        Date: 12/2/2005
     **********************************************************************
     */
    virtual ~cDocumentNodeList()
    {
    }
};

/**
 **********************************************************************
 *  Class: cDocumentAttributeList
 *
 * Author: $author$
 *   Date: 10/19/2005
 **********************************************************************
 */
class cDocumentAttributeList
: public cDocumentNodeListT
  <cDocumentAttributeList, cDocumentArtifact>
{
public:
    typedef cDocumentNodeListT
    <cDocumentAttributeList, cDocumentArtifact> cIs;

    cDocumentBeginElementInterface& m_element;

    /**
     **********************************************************************
     * Constructor: cDocumentAttributeList
     *
     *      Author: $author$
     *        Date: 10/19/2005
     **********************************************************************
     */
    cDocumentAttributeList
    (cDocumentEventInterface &event,
     cDocumentNodeFactoryInterface &node_factory,
     cDocumentBeginElementInterface& element) 
    : cIs(event, node_factory),
      m_element(element)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDocumentAttributeList
     *
     *      Author: $author$
     *        Date: 10/19/2005
     **********************************************************************
     */
    virtual ~cDocumentAttributeList()
    {
        eError error;

        if ((error = DeleteAllNodes()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: GetParentElement
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual cDocumentBeginElementInterface *GetParentBeginElement() const
    {
        return &m_element;
    }
};

#endif /* _CDOCUMENTNODELIST_HXX */
