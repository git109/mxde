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
 *   File: cdomprocessor.hxx
 *
 * Author: $author$
 *   Date: 11/29/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOMPROCESSOR_HXX
#define _CDOMPROCESSOR_HXX

#include <stdio.h>
#include "cdom.hxx"
#include "cdominterface.hxx"
#include "cavltreet.hxx"

class cDOMNodeProcessorItem;
class cDOMTextProcessorBranch;
class cDOMTextProcessorInterface;
class cDOMElementProcessorBranch;
class cDOMElementProcessorInterface;

/**
 **********************************************************************
 *  Class: cDOMProcessorInterface
 *
 * Author: $author$
 *   Date: 11/29/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMProcessorInterface
{
public:
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMNodeList &result, 
     cDOMNodeListInterface &function, 
     cDOMNodeListInterface &parameter) = 0;
    /**
     **********************************************************************
     * Function: ProcessNode
     *
     *   Author: $author$
     *     Date: 12/20/2004
     **********************************************************************
     */
    virtual eError ProcessNode
    (cDOMNodeList &result, 
     cDOMNodeInterface &function, 
     cDOMNodeListInterface &parameter) = 0;

    /**
     **********************************************************************
     * Function: GetEvent
     *
     *   Author: $author$
     *     Date: 12/19/2004
     **********************************************************************
     */
    virtual cDOMEventInterface& GetEvent() = 0;
    /**
     **********************************************************************
     * Function: GetFactory
     *
     *   Author: $author$
     *     Date: 12/9/2004
     **********************************************************************
     */
    virtual cDOMNodeFactoryInterface& GetFactory() = 0;
};

/**
 **********************************************************************
 *  Class: cDOMNodeProcessorInterface
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMNodeProcessorInterface
{
public:
    static cDOMNodeProcessorInterface *m_default;

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 12/8/2004
     **********************************************************************
     */
    virtual eError Initialize
    (cDOMProcessorInterface &processor) = 0;
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 12/8/2004
     **********************************************************************
     */
    virtual eError Finalize
    (cDOMProcessorInterface &processor) = 0;
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMNodeInterface &node,
     cDOMNodeListInterface &parameter) = 0;
    /**
     **********************************************************************
     * Function: GetItem
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual cDOMNodeProcessorItem &GetItem() = 0;
    /**
     **********************************************************************
     * Function: GetTextProcessor
     *
     *   Author: $author$
     *     Date: 12/15/2004
     **********************************************************************
     */
    virtual cDOMTextProcessorInterface *GetTextProcessor() const = 0;
    /**
     **********************************************************************
     * Function: GetElementProcessor
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual cDOMElementProcessorInterface *GetElementProcessor() const = 0;
};

/**
 **********************************************************************
 *  Class: cDOMNamespaceNodeProcessorInterface
 *
 * Author: $author$
 *   Date: 12/9/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMNamespaceNodeProcessorInterface
: virtual public cDOMNodeProcessorInterface
{
public:
    /**
     **********************************************************************
     * Function: GetNamespaceURI
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetNamespaceURI() const = 0;
};
    
/**
 **********************************************************************
 *  Class: cDOMNamedNodeProcessorInterface
 *
 * Author: $author$
 *   Date: 12/9/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMNamedNodeProcessorInterface
: virtual public cDOMNamespaceNodeProcessorInterface
{
public:
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetName() const = 0;
};
    
/**
 **********************************************************************
 *  Class: cDOMTextProcessorInterface
 *
 * Author: $author$
 *   Date: 12/15/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMTextProcessorInterface
: virtual public cDOMNamespaceNodeProcessorInterface
{
public:
    static cDOMTextProcessorInterface *m_default;

    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/15/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMTextInterface &text,
     cDOMNodeListInterface &parameter) = 0;
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 12/16/2004
     **********************************************************************
     */
    virtual cDOMTextProcessorBranch &GetBranch() = 0;
};

/**
 **********************************************************************
 *  Class: cDOMElementProcessorInterface
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDOMElementProcessorInterface
: virtual public cDOMNamedNodeProcessorInterface
{
public:
    static cDOMElementProcessorInterface *m_default;

    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMElementInterface &element,
     cDOMNodeListInterface &parameter) = 0;
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual cDOMElementProcessorBranch &GetBranch() = 0;
};

/**
 **********************************************************************
 *  Class: cDOMNodeProcessorItem
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMNodeProcessorItem
: public cListItemT<cDOMNodeProcessorItem>
{
public:
    typedef cListItemT<cDOMNodeProcessorItem> cIs;

    cDOMNodeProcessorInterface &m_processor;

    /**
     **********************************************************************
     * Constructor: cDOMNodeProcessorItem
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cDOMNodeProcessorItem
    (cDOMNodeProcessorInterface &processor)
    : m_processor(processor)
    {
    }
    /**
     **********************************************************************
     * Function: GetProcessor
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    cDOMNodeProcessorInterface& GetProcessor() 
    {
        cDOMNodeProcessorInterface &processor = m_processor;
        return processor;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNodeProcessorList
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMNodeProcessorList
: public cStaticListT
  <cDOMNodeProcessorItem, cDOMNodeProcessorList>
{
public:
    typedef cStaticListT
    <cDOMNodeProcessorItem, cDOMNodeProcessorList> cIs;
};

/**
 **********************************************************************
 *  Class: cDOMTextProcessorBranch
 *
 * Author: $author$
 *   Date: 12/15/2004
 **********************************************************************
 */
class cDOMTextProcessorBranch
: public cAVLTreeBranchT<cDOMTextProcessorBranch>
{
public:
    typedef cAVLTreeBranchT<cDOMTextProcessorBranch> cIs;

    cDOMTextProcessorInterface &m_processor;

    /**
     **********************************************************************
     * Constructor: cDOMTextProcessorBranch
     *
     *      Author: $author$
     *        Date: 12/15/2004
     **********************************************************************
     */
    cDOMTextProcessorBranch
    (cDOMTextProcessorInterface &processor)
    : m_processor(processor)
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/15/2004
     **********************************************************************
     */
    int Compare(cDOMTextProcessorBranch &branch) const
    {
        const cStringInterface 
            &ns1 = GetNamespaceURI(),
            &ns2 = branch.GetNamespaceURI();
        int unequal = (&ns1 != &ns2)?((&ns1 > &ns2)?1:-1):0;

        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/15/2004
     **********************************************************************
     */
    int Compare(const cDOMTextInterface &text) const
    {
        const cStringInterface 
            &ns1 = GetNamespaceURI(),
            &ns2 = text.GetNamespaceURI();
        int unequal = (&ns1 != &ns2)?((&ns1 > &ns2)?1:-1):0;

        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetNamespaceURI
     *
     *   Author: $author$
     *     Date: 12/15/2004
     **********************************************************************
     */
    const cStringInterface& GetNamespaceURI() const
    {
        const cStringInterface& name = m_processor.GetNamespaceURI();
        return name;
    }
    /**
     **********************************************************************
     * Function: GetProcessor
     *
     *   Author: $author$
     *     Date: 12/15/2004
     **********************************************************************
     */
    cDOMTextProcessorInterface& GetProcessor() 
    {
        cDOMTextProcessorInterface &processor = m_processor;
        return processor;
    }
};
/**
 **********************************************************************
 *  Class: cDOMTextProcessorTree
 *
 * Author: $author$
 *   Date: 12/15/2004
 **********************************************************************
 */
class cDOMTextProcessorTree
: public cAVLTreeT
  <cDOMTextInterface, 
   cDOMTextProcessorBranch, 
   cDOMTextProcessorTree>
{
public:
    typedef cAVLTreeT
    <cDOMTextInterface, 
     cDOMTextProcessorBranch, 
     cDOMTextProcessorTree> cIs;

    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 12/16/2004
     **********************************************************************
     */
    cDOMTextProcessorInterface* Find
    (const cDOMTextInterface &element) const
    {
        cDOMTextProcessorInterface *p = 0;
        cDOMTextProcessorBranch *b;

        if ((b = cIs::Find(element)))
            p = &b->GetProcessor();

        return p;
    }
};

/**
 **********************************************************************
 *  Class: cDOMElementProcessorBranch
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMElementProcessorBranch
: public cAVLTreeBranchT<cDOMElementProcessorBranch>
{
public:
    typedef cAVLTreeBranchT<cDOMElementProcessorBranch> cIs;

    cDOMElementProcessorInterface &m_processor;

    /**
     **********************************************************************
     * Constructor: cDOMElementProcessorBranch
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cDOMElementProcessorBranch
    (cDOMElementProcessorInterface &processor)
    : m_processor(processor)
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    int Compare(cDOMElementProcessorBranch &branch) const
    {
        const cStringInterface 
            &n1 = GetName(),
            &ns1 = GetNamespaceURI(),
            &n2 = branch.GetName(),
            &ns2 = branch.GetNamespaceURI();

        int unequal = n1.Compare(n2),
            ns_unequal = ns1.Compare(ns2);

        if (ns_unequal)
            return ns_unequal;

        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    int Compare(const cDOMElementInterface &element) const
    {
        const cStringInterface 
            &n1 = GetName(),
            &n2 = element.GetName(),
            &ns1 = GetNamespaceURI(),
            &ns2 = element.GetNamespaceURI();

        int unequal,
            ns_unequal = (&ns1 != &ns2)?((&ns1 > &ns2)?1:-1):0;

        if (ns_unequal)
            return ns_unequal;

        return unequal = n1.Compare(n2);
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    const cStringInterface& GetName() const
    {
        const cStringInterface& name = m_processor.GetName();
        return name;
    }
    /**
     **********************************************************************
     * Function: GetNamespaceURI
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    const cStringInterface& GetNamespaceURI() const
    {
        const cStringInterface& name = m_processor.GetNamespaceURI();
        return name;
    }
    /**
     **********************************************************************
     * Function: GetProcessor
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    cDOMElementProcessorInterface& GetProcessor() 
    {
        cDOMElementProcessorInterface &processor = m_processor;
        return processor;
    }
};

/**
 **********************************************************************
 *  Class: cDOMElementProcessorTree
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMElementProcessorTree
: public cAVLTreeT
  <cDOMElementInterface, 
   cDOMElementProcessorBranch, 
   cDOMElementProcessorTree>
{
public:
    typedef cAVLTreeT
    <cDOMElementInterface, 
     cDOMElementProcessorBranch, 
     cDOMElementProcessorTree> cIs;

    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 12/16/2004
     **********************************************************************
     */
    cDOMElementProcessorInterface* Find
    (const cDOMElementInterface &element) const
    {
        cDOMElementProcessorInterface *p = 0;
        cDOMElementProcessorBranch *b;

        if ((b = cIs::Find(element)))
            p = &b->GetProcessor();

        return p;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNodeProcessor
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMNodeProcessor
: virtual public cDOMNodeProcessorInterface
{
public:
    static cDOMNodeProcessorList m_list;
    cDOMNodeProcessorItem m_item;
    cDOMNodeProcessorList *m_list_in;

    /**
     **********************************************************************
     * Constructor: cDOMNodeProcessor
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cDOMNodeProcessor(cDOMNodeProcessorList *list=&m_list) 
    : m_item(*this)
    {
        if ((m_list_in = list))
            list->Add(&m_item);
    }
    /**
     **********************************************************************
     * Destructor: ~cDOMNodeProcessor
     *
     *     Author: $author$
     *       Date: 11/30/2004
     **********************************************************************
     */
    virtual ~cDOMNodeProcessor()
    {
        if (m_list_in)
            m_list_in->Delete(&m_item);
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 12/8/2004
     **********************************************************************
     */
    virtual eError Initialize
    (cDOMProcessorInterface &processor)
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 12/8/2004
     **********************************************************************
     */
    virtual eError Finalize
    (cDOMProcessorInterface &processor)
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMNodeInterface &node,
     cDOMNodeListInterface &parameter) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetItem
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual cDOMNodeProcessorItem &GetItem()
    {
        return m_item;
    }
    /**
     **********************************************************************
     * Function: GetTextProcessor
     *
     *   Author: $author$
     *     Date: 12/15/2004
     **********************************************************************
     */
    virtual cDOMTextProcessorInterface *GetTextProcessor() const
    {
        cDOMTextProcessorInterface *processor = 0;
        return processor;
    }
    /**
     **********************************************************************
     * Function: GetElementProcessor
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual cDOMElementProcessorInterface *GetElementProcessor() const
    {
        cDOMElementProcessorInterface *processor = 0;
        return processor;
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamespaceNodeProcessor
 *
 * Author: $author$
 *   Date: 12/9/2004
 **********************************************************************
 */
class cDOMNamespaceNodeProcessor
: virtual public cDOMNamespaceNodeProcessorInterface,
  public cDOMNodeProcessor
{
public:
    typedef cDOMNodeProcessor cIs;

    cDOMNamespaceInterface* m_namespace;
    const cStringInterface* m_namespace_uri;

    /**
     **********************************************************************
     * Constructor: cDOMNamespaceNodeProcessor
     *
     *      Author: $author$
     *        Date: 12/9/2004
     **********************************************************************
     */
    cDOMNamespaceNodeProcessor
    (cDOMNodeProcessorList *list=&m_list) 
    : cIs(list),
      m_namespace(0),
      m_namespace_uri(0)
    {
    }
    /**
     **********************************************************************
     * Constructor: cDOMNamespaceNodeProcessor
     *
     *      Author: $author$
     *        Date: 12/9/2004
     **********************************************************************
     */
    cDOMNamespaceNodeProcessor
    (const cStringInterface &namespace_uri,
     cDOMNodeProcessorList *list=&m_list) 
    : cIs(list),
      m_namespace(0),
      m_namespace_uri(&namespace_uri)
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 12/8/2004
     **********************************************************************
     */
    virtual eError Initialize
    (cDOMProcessorInterface &processor)
    {
        eError error = e_ERROR_FAILED;
        cDOMNodeFactoryInterface &factory = processor.GetFactory();

        if ((m_namespace = factory.GetNamespace(*m_namespace_uri)))
            error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 12/8/2004
     **********************************************************************
     */
    virtual eError Finalize
    (cDOMProcessorInterface &processor)
    {
        eError error = e_ERROR_FAILED;

        if (m_namespace)
        {
            m_namespace = 0;
            error = e_ERROR_NONE;
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: GetNamespaceURI
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetNamespaceURI() const
    {
        if (m_namespace)
            return m_namespace->GetNamespaceURI();

        if (m_namespace_uri)
            return *m_namespace_uri;

        return cDOMNamespaceInterface::GetGlobalNamespaceURI();
    }
};

/**
 **********************************************************************
 *  Class: cDOMNamedNodeProcessor
 *
 * Author: $author$
 *   Date: 12/9/2004
 **********************************************************************
 */
class cDOMNamedNodeProcessor
: virtual public cDOMNamedNodeProcessorInterface,
  public cDOMNamespaceNodeProcessor
{
public:
    typedef cDOMNamespaceNodeProcessor cIs;

    cString m_name;

    /**
     **********************************************************************
     * Constructor: cDOMNamedNodeProcessor
     *
     *      Author: $author$
     *        Date: 12/9/2004
     **********************************************************************
     */
    cDOMNamedNodeProcessor
    (const char *name,
     cDOMNodeProcessorList *list=&m_list) 
    : cIs(list),
      m_name(name)
    {
    }
    /**
     **********************************************************************
     * Constructor: cDOMNamedNodeProcessor
     *
     *      Author: $author$
     *        Date: 12/9/2004
     **********************************************************************
     */
    cDOMNamedNodeProcessor
    (const cStringInterface &namespace_uri, const char *name,
     cDOMNodeProcessorList *list=&m_list) 
    : cIs(namespace_uri, list),
      m_name(name)
    {
    }

    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual const cStringInterface& GetName() const
    {
        return m_name;
    }
};

/**
 **********************************************************************
 *  Class: cDOMTextProcessor
 *
 * Author: $author$
 *   Date: 12/15/2004
 **********************************************************************
 */
class cDOMTextProcessor
: virtual public cDOMTextProcessorInterface,
  public cDOMNamespaceNodeProcessor
{
public:
    typedef cDOMNamespaceNodeProcessor cIs;

    cDOMTextProcessorBranch m_branch;

    /**
     **********************************************************************
     * Constructor: cDOMTextProcessor
     *
     *      Author: $author$
     *        Date: 12/15/2004
     **********************************************************************
     */
    cDOMTextProcessor() 
    : m_branch(*this)
    {
    }
    /**
     **********************************************************************
     * Constructor: cDOMTextProcessor
     *
     *      Author: $author$
     *        Date: 12/15/2004
     **********************************************************************
     */
    cDOMTextProcessor(const cStringInterface &namespace_uri)
    : cIs(namespace_uri),
      m_branch(*this)
    {
    }

    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/15/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMTextInterface &text,
     cDOMNodeListInterface &parameter) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetTextProcessor
     *
     *   Author: $author$
     *     Date: 12/15/2004
     **********************************************************************
     */
    virtual cDOMTextProcessorInterface *GetTextProcessor() const
    {
        cDOMTextProcessorInterface *processor = (cDOMTextProcessorInterface*)this;
        return processor;
    }
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 12/16/2004
     **********************************************************************
     */
    virtual cDOMTextProcessorBranch &GetBranch()
    {
        return m_branch;
    }
};

/**
 **********************************************************************
 *  Class: cDefaultDOMTextProcessor
 *
 * Author: $author$
 *   Date: 12/15/2004
 **********************************************************************
 */
class cDefaultDOMTextProcessor
: public cDOMTextProcessor
{
public:
    typedef cDOMTextProcessor cIs;

    cDOMTextProcessorInterface *m_old_default;

    /**
     **********************************************************************
     * Constructor: cDefaultDOMTextProcessor
     *
     *      Author: $author$
     *        Date: 12/15/2004
     **********************************************************************
     */
    cDefaultDOMTextProcessor() 
    {
        m_old_default = m_default;
        m_default = this;
    }
    /**
     **********************************************************************
     *  Destructor: ~cDefaultDOMTextProcessor
     *
     *      Author: $author$
     *        Date: 12/15/2004
     **********************************************************************
     */
    virtual ~cDefaultDOMTextProcessor()
    {
        if (this == m_default)
            m_default = m_old_default;
    }
};

/**
 **********************************************************************
 *  Class: cDOMElementProcessor
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cDOMElementProcessor
: virtual public cDOMElementProcessorInterface,
  public cDOMNamedNodeProcessor
{
public:
    typedef cDOMNamedNodeProcessor cIs;

    cDOMElementProcessorBranch m_branch;

    /**
     **********************************************************************
     * Constructor: cDOMElementProcessor
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cDOMElementProcessor
    (const char *name,
     cDOMNodeProcessorList *list=&m_list) 
    : cIs(name, list),
      m_branch(*this)
    {
    }
    /**
     **********************************************************************
     * Constructor: cDOMElementProcessor
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cDOMElementProcessor
    (const cStringInterface &namespace_uri, const char *name,
     cDOMNodeProcessorList *list=&m_list) 
    : cIs(namespace_uri, name, list),
      m_branch(*this)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMElementInterface &element,
     cDOMNodeListInterface &parameter) 
    {
        eError error = processor.Process
        (result, element, parameter);
        return error;
    }
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual cDOMElementProcessorBranch &GetBranch()
    {
        return m_branch;
    }
    /**
     **********************************************************************
     * Function: GetElementProcessor
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual cDOMElementProcessorInterface *GetElementProcessor() const
    {
        cDOMElementProcessorInterface *processor = (cDOMElementProcessorInterface*)this;
        return processor;
    }
};

/**
 **********************************************************************
 *  Class: cDefaultDOMElementProcessor
 *
 * Author: $author$
 *   Date: 12/4/2004
 **********************************************************************
 */
class cDefaultDOMElementProcessor
: public cDOMElementProcessor
{
public:
    typedef cDOMElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cDefaultDOMElementProcessor
     *
     *      Author: $author$
     *        Date: 12/4/2004
     **********************************************************************
     */
    cDefaultDOMElementProcessor
    (const char *name="*") 
    : cIs(name, 0) 
    {
        m_default = this;
    }
};

/**
 **********************************************************************
 *  Class: cDOMProcessor
 *
 * Author: $author$
 *   Date: 11/29/2004
 **********************************************************************
 */
class cDOMProcessor
: virtual public cDOMProcessorInterface
{
public:
    cDOMTextProcessorTree m_text_processor_tree;
    cDOMElementProcessorTree m_element_processor_tree;
    int m_depth;

    cDOMEventInterface& m_event;
    cDOMNodeFactoryInterface& m_factory;

    /**
     **********************************************************************
     * Constructor: cDOMProcessor
     *
     *      Author: $author$
     *        Date: 12/9/2004
     **********************************************************************
     */
    cDOMProcessor
    (cDOMEventInterface& event,
     cDOMNodeFactoryInterface& factory) 
    : m_event(event),
      m_factory(factory)
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual eError Initialize()
    {
        eError error = e_ERROR_NONE;
        cDOMNodeProcessorItem *item;
        cDOMTextProcessorInterface *t_processor;
        cDOMElementProcessorInterface *e_processor;

        m_depth = 0;

        if ((item = cDOMNodeProcessor::m_list.GetFirst()))
        do
        {
            cDOMNodeProcessorInterface &processor = item->GetProcessor();

            if ((error = processor.Initialize(*this)))
            {
                while ((item = item->GetPrevious()))
                {
                    cDOMNodeProcessorInterface &processor = item->GetProcessor();
                    processor.Finalize(*this);
                };
                break;
            }

            if ((e_processor = processor.GetElementProcessor()))
            {
                cDOMElementProcessorBranch &branch = e_processor->GetBranch();

                m_element_processor_tree.Insert(&branch);
            }
            else if ((t_processor = processor.GetTextProcessor()))
            {
                cDOMTextProcessorBranch &branch = t_processor->GetBranch();

                m_text_processor_tree.Insert(&branch);
            }
        }
        while ((item = item->GetNext()));

        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual eError Finalize()
    {
        eError error2, error = e_ERROR_NONE;
        cDOMNodeProcessorItem *item;

        if ((item = cDOMNodeProcessor::m_list.GetLast()))
        do
        {
            cDOMNodeProcessorInterface &processor = item->GetProcessor();

            if ((error2 = processor.Finalize(*this)))
            if (!error)
                error = error2;
        }
        while ((item = item->GetPrevious()));

        m_element_processor_tree.Clear();
        m_text_processor_tree.Clear();
        return error;
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMNodeList &result,  
     cDOMNodeListInterface &function, 
     cDOMNodeListInterface &parameter) 
    {
        eError error = e_ERROR_NONE;
        cDOMNodeInterface *n;
/*
        cDOMTextInterface *t;
        cDOMTextProcessorInterface *t_p;
        cDOMElementInterface *e;
        cDOMElementProcessorInterface *e_p;
*/
        if ((n = function.GetFirstChild()))
        do
        {
            if ((error = ProcessNode(result, *n, parameter)))
                break;
/*
            if ((e = n->GetElementNode()))
            {
                if (!(e_p = m_element_processor_tree.Find(*e)))
                if (!(e_p = cDOMElementProcessorInterface::m_default))
                    continue;

                if ((error = e_p->Process
                    (*this, result, *e, parameter)))
                    break;
            }
            else if ((t = n->GetTextNode()))
            {
                if (!(t_p = m_text_processor_tree.Find(*t)))
                if (!(t_p = cDOMTextProcessorInterface::m_default))
                    continue;

                if ((error = t_p->Process
                    (*this, result, *t, parameter)))
                    break;
            }
*/
        }
        while ((n = n->GetNextSibling()));

        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessNode
     *
     *   Author: $author$
     *     Date: 12/20/2004
     **********************************************************************
     */
    virtual eError ProcessNode
    (cDOMNodeList &result,  
     cDOMNodeInterface &function, 
     cDOMNodeListInterface &parameter) 
    {
        eError error = e_ERROR_NONE;
        cDOMTextInterface *t;
        cDOMTextProcessorInterface *t_p;
        cDOMElementInterface *e;
        cDOMElementProcessorInterface *e_p;

        if ((e = function.GetElementNode()))
        {
            if (!(e_p = m_element_processor_tree.Find(*e)))
            if (!(e_p = cDOMElementProcessorInterface::m_default))
                return error;

            error = e_p->Process
            (*this, result, *e, parameter);
        }
        else if ((t = function.GetTextNode()))
        {
            if (!(t_p = m_text_processor_tree.Find(*t)))
            if (!(t_p = cDOMTextProcessorInterface::m_default))
                return error;

            error = t_p->Process
            (*this, result, *t, parameter);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: print
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     *
    void print(cDOMNamedNodeInterface *e)
    {
        const cStringInterface& name = e->GetName();
        const cChar* chars;
        int length;

        if ((chars = name.GetChars(length)))
        for (int i=0; i<length; i++)
            printf("%c", chars[i].ToChar());
    }

    /**
     **********************************************************************
     * Function: GetEvent
     *
     *   Author: $author$
     *     Date: 12/19/2004
     **********************************************************************
     */
    virtual cDOMEventInterface& GetEvent() 
    {
        return m_event;
    }
    /**
     **********************************************************************
     * Function: GetFactory
     *
     *   Author: $author$
     *     Date: 12/9/2004
     **********************************************************************
     */
    virtual cDOMNodeFactoryInterface& GetFactory() 
    {
        return m_factory;
    }
};

#endif /* ndef _CDOMPROCESSOR_HXX */
