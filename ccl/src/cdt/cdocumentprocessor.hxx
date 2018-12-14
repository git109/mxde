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
 *   File: cdocumentprocessor.hxx
 *
 * Author: $author$
 *   Date: 12/7/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTPROCESSOR_HXX
#define _CDOCUMENTPROCESSOR_HXX

#include "cdocument.hxx"
#include "cdocumentnodelist.hxx"
#include "cdocumentprocessorimplement.hxx"
#include "cdocumentprocessorinterface.hxx"
#include "cinstance.hxx"
#include "clistt.hxx"
#include "cavltreet.hxx"
#include "ccchartocharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cNameDocumentElementBranch
 *
 * Author: $author$
 *   Date: 12/19/2005
 **********************************************************************
 */
class cNameDocumentElementBranch
: public cAVLTreeBranchT<cNameDocumentElementBranch>
{
public:
    typedef cAVLTreeBranchT<cNameDocumentElementBranch> cIs;

    const cCCharBuffer &m_name;
    cDocumentElementInterface& m_element;

    /**
     **********************************************************************
     * Constructor: cNameDocumentElementBranch
     *
     *      Author: $author$
     *        Date: 12/19/2005
     **********************************************************************
     */
    cNameDocumentElementBranch
    (const cCCharBuffer &name,
     cDocumentElementInterface& element) 
    : m_name(name),
      m_element(element) 
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    int Compare(cNameDocumentElementBranch &branch) const
    {
        const cCCharBuffer &name = branch.GetName();
        int unequal = Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    int Compare(const cCCharBuffer &name) const
    {
        const cCCharBuffer &toname = GetName();
        int unequal = toname.Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    const cCCharBuffer& GetName() const 
    {
        return m_name;
    }
    /**
     **********************************************************************
     * Function: GetElement
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    cDocumentElementInterface& GetElement() const 
    {
        return (cDocumentElementInterface&)m_element;
    }
};

/**
 **********************************************************************
 *  Class: cNameDocumentElementTree
 *
 * Author: $author$
 *   Date: 12/19/2005
 **********************************************************************
 */
class cNameDocumentElementTree
: public cAVLTreeT
  <const cCCharBuffer, 
   cNameDocumentElementBranch, 
   cNameDocumentElementTree>
{
public:
    typedef cAVLTreeT
    <const cCCharBuffer, 
     cNameDocumentElementBranch, 
     cNameDocumentElementTree> cIs;
};

/**
 **********************************************************************
 *  Class: cNameDocumentElementItem
 *
 * Author: $author$
 *   Date: 12/19/2005
 **********************************************************************
 */
class cNameDocumentElementItem
: public cDynamicListItemT<cNameDocumentElementItem>
{
public:
    typedef cDynamicListItemT<cNameDocumentElementItem> cIs;

    cNameDocumentElementBranch m_branch;

    /**
     **********************************************************************
     * Constructor: cNameDocumentElementItem
     *
     *      Author: $author$
     *        Date: 12/19/2005
     **********************************************************************
     */
    cNameDocumentElementItem
    (const cCCharBuffer& name,
     cDocumentElementInterface& element) 
    : m_branch(name, element) 
    {
    }
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    cNameDocumentElementBranch& GetBranch()
    {
        return m_branch;
    }
};

/**
 **********************************************************************
 *  Class: cNameDocumentElementList
 *
 * Author: $author$
 *   Date: 12/19/2005
 **********************************************************************
 */
class cNameDocumentElementList
: public cDynamicListT
  <cNameDocumentElementItem, cNameDocumentElementList>
{
public:
    typedef cDynamicListT
    <cNameDocumentElementItem, cNameDocumentElementList> cIs;
};

/**
 **********************************************************************
 *  Class: cDocumentNodeListReferenceItem
 *
 * Author: $author$
 *   Date: 12/16/2005
 **********************************************************************
 */
class cDocumentNodeListReferenceItem
: public cDynamicListItemT<cDocumentNodeListReferenceItem>
{
public:
    typedef cDynamicListItemT<cDocumentNodeListReferenceItem> cIs;

    cDocumentNodeListInterface& m_node_list;

    /**
     **********************************************************************
     * Constructor: cDocumentNodeListReferenceItem
     *
     *      Author: $author$
     *        Date: 12/16/2005
     **********************************************************************
     */
    cDocumentNodeListReferenceItem(cDocumentNodeListInterface& node_list) 
    : m_node_list(node_list) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDocumentNodeListReferenceItem
     *
     *     Author: $author$
     *       Date: 12/16/2005
     **********************************************************************
     */
    virtual ~cDocumentNodeListReferenceItem() 
    {
    }
    /**
     **********************************************************************
     * Function: GetNodeList
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    cDocumentNodeListInterface& GetNodeList() const 
    {
        return (cDocumentNodeListInterface&)m_node_list;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNodeListReferenceList
 *
 * Author: $author$
 *   Date: 12/16/2005
 **********************************************************************
 */
class cDocumentNodeListReferenceList
: public cDynamicListT
  <cDocumentNodeListReferenceItem, cDocumentNodeListReferenceList>
{
public:
    typedef cDynamicListT
    <cDocumentNodeListReferenceItem, cDocumentNodeListReferenceList> cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentNodeListReferenceList
     *
     *      Author: $author$
     *        Date: 12/16/2005
     **********************************************************************
     */
    cDocumentNodeListReferenceList() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDocumentNodeListReferenceList
     *
     *     Author: $author$
     *       Date: 12/16/2005
     **********************************************************************
     */
    virtual ~cDocumentNodeListReferenceList() 
    {
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNodeListReferenceListBranch
 *
 * Author: $author$
 *   Date: 12/16/2005
 **********************************************************************
 */
class cDocumentNodeListReferenceListBranch
: public cAVLTreeBranchT<cDocumentNodeListReferenceListBranch>
{
public:
    typedef cAVLTreeBranchT<cDocumentNodeListReferenceListBranch> cIs;

    cCCharBuffer m_name;
    cDocumentNodeListReferenceList m_list;

    /**
     **********************************************************************
     * Constructor: cDocumentNodeListReferenceListBranch
     *
     *      Author: $author$
     *        Date: 12/16/2005
     **********************************************************************
     */
    cDocumentNodeListReferenceListBranch
    (const cCCharBuffer& name) 
    {
        eError error;
        int length;

        if (0 > (length = m_name.Write(name)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Destructor: ~cDocumentNodeListReferenceListBranch
     *
     *     Author: $author$
     *       Date: 12/16/2005
     **********************************************************************
     */
    virtual ~cDocumentNodeListReferenceListBranch()
    {
    }

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    int Compare(cDocumentNodeListReferenceListBranch &branch) const
    {
        const cCCharBuffer& toname = branch.GetName();
        int unequal = Compare(toname);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    int Compare(const cCCharBuffer& toname) const
    {
        int unequal = toname.Compare(m_name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    const cCCharBuffer& GetName() const 
    {
        return m_name;
    }
    /**
     **********************************************************************
     * Function: GetList
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    cDocumentNodeListReferenceList& GetList() const
    {
        return (cDocumentNodeListReferenceList&)m_list;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNodeListReferenceListTree
 *
 * Author: $author$
 *   Date: 12/16/2005
 **********************************************************************
 */
class cDocumentNodeListReferenceListTree
: public cAVLTreeT
  <const cCCharBuffer, 
   cDocumentNodeListReferenceListBranch, 
   cDocumentNodeListReferenceListTree>
{
public:
    typedef cAVLTreeT
    <const cCCharBuffer, 
     cDocumentNodeListReferenceListBranch, 
     cDocumentNodeListReferenceListTree> cIs;

    /**
     **********************************************************************
     * Function: GetList
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    cDocumentNodeListReferenceList* GetList
    (const cCCharBuffer& name)
    {
        cDocumentNodeListReferenceList* list = 0;

        if (!(list = FindList(name)))
            list = AddList(name);
        return list;
    }
    /**
     **********************************************************************
     * Function: AddList
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    cDocumentNodeListReferenceList* AddList
    (const cCCharBuffer& name)
    {
        cDocumentNodeListReferenceList* list = 0;
        cDocumentNodeListReferenceListBranch* branch;

        if (!(branch = new cDocumentNodeListReferenceListBranch(name)))
            return list;

        Insert(branch);
        list = &branch->GetList();
        return list;
    }
    /**
     **********************************************************************
     * Function: FindList
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    cDocumentNodeListReferenceList* FindList
    (const cCCharBuffer& name) const
    {
        cDocumentNodeListReferenceList* list = 0;
        cDocumentNodeListReferenceListBranch* branch;

        if ((branch = Find(name)))
            list = &branch->GetList();
        return list;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNodeProcessorItem
 *
 * Author: $author$
 *   Date: 12/7/2005
 **********************************************************************
 */
class cDocumentNodeProcessorItem
: public cListItemT<cDocumentNodeProcessorItem>
{
public:
    typedef cListItemT<cDocumentNodeProcessorItem> cIs;

    cDocumentNodeProcessorInterface &m_processor;

    /**
     **********************************************************************
     * Constructor: cDocumentNodeProcessorItem
     *
     *      Author: $author$
     *        Date: 12/7/2005
     **********************************************************************
     */
    cDocumentNodeProcessorItem
    (cDocumentNodeProcessorInterface &processor)
    : m_processor(processor)
    {
    }
    /**
     **********************************************************************
     * Function: GetProcessor
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    cDocumentNodeProcessorInterface& GetProcessor() const
    {
        cDocumentNodeProcessorInterface &processor = m_processor;
        return processor;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNodeProcessorList
 *
 * Author: $author$
 *   Date: 12/7/2005
 **********************************************************************
 */
class cDocumentNodeProcessorList
: public cStaticListT
  <cDocumentNodeProcessorItem, cDocumentNodeProcessorList>
{
public:
    typedef cStaticListT
    <cDocumentNodeProcessorItem, cDocumentNodeProcessorList> cIs;
};

/**
 **********************************************************************
 *  Class: cDocumentNodePreprocessorList
 *
 * Author: $author$
 *   Date: 12/19/2005
 **********************************************************************
 */
class cDocumentNodePreprocessorList
: public cStaticListT
  <cDocumentNodeProcessorItem, cDocumentNodePreprocessorList>
{
public:
    typedef cStaticListT
    <cDocumentNodeProcessorItem, cDocumentNodePreprocessorList> cIs;
};

/**
 **********************************************************************
 *  Class: cDocumentElementProcessorBranch
 *
 * Author: $author$
 *   Date: 12/7/2005
 **********************************************************************
 */
class cDocumentElementProcessorBranch
: public cAVLTreeBranchT<cDocumentElementProcessorBranch>
{
public:
    typedef cAVLTreeBranchT<cDocumentElementProcessorBranch> cIs;

    cDocumentElementProcessorInterface &m_processor;

    /**
     **********************************************************************
     * Constructor: cDocumentElementProcessorBranch
     *
     *      Author: $author$
     *        Date: 12/7/2005
     **********************************************************************
     */
    cDocumentElementProcessorBranch
    (cDocumentElementProcessorInterface &processor)
    : m_processor(processor)
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    int Compare(cDocumentElementProcessorBranch &branch) const
    {
        const cCCharBuffer& toname = branch.GetName();
        int unequal = Compare(toname);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    int Compare(const cDocumentElementInterface &element) const
    {
        const cCCharBuffer& toname = element.GetName();
        int unequal = Compare(toname);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    int Compare(const cCCharBuffer& toname) const
    {
        const cCCharBuffer& name = GetName();
        int unequal = toname.Compare(name);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    const cCCharBuffer& GetName() const
    {
        const cCCharBuffer& name = m_processor.GetName();
        return name;
    }
    /**
     **********************************************************************
     * Function: GetProcessor
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    cDocumentElementProcessorInterface& GetProcessor() 
    {
        cDocumentElementProcessorInterface &processor = m_processor;
        return processor;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentElementProcessorTree
 *
 * Author: $author$
 *   Date: 12/7/2005
 **********************************************************************
 */
class cDocumentElementProcessorTree
: public cAVLTreeT
  <cDocumentElementInterface, 
   cDocumentElementProcessorBranch, 
   cDocumentElementProcessorTree>
{
public:
    typedef cAVLTreeT
    <cDocumentElementInterface, 
     cDocumentElementProcessorBranch, 
     cDocumentElementProcessorTree> cIs;

    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    cDocumentElementProcessorInterface* Find
    (const cDocumentElementInterface &element) const
    {
        cDocumentElementProcessorInterface *p = 0;
        cDocumentElementProcessorBranch *b;

        if ((b = cIs::Find(element)))
            p = &b->GetProcessor();

        return p;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNodeProcessor
 *
 * Author: $author$
 *   Date: 12/8/2005
 **********************************************************************
 */
class cDocumentNodeProcessor
: virtual public cDocumentNodeProcessorImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    static cDocumentNodeProcessorList m_list;
    static cDocumentNodePreprocessorList m_prelist;
    cDocumentNodeProcessorItem m_item;
    cDocumentNodeProcessorList *m_list_in;
    cDocumentNodePreprocessorList *m_prelist_in;

    /**
     **********************************************************************
     * Constructor: cDocumentNodeProcessor
     *
     *      Author: $author$
     *        Date: 12/8/2005
     **********************************************************************
     */
    cDocumentNodeProcessor
    (cDocumentNodeProcessorList *list_in=&m_list) 
    : m_item(*this),
      m_list_in(list_in),
      m_prelist_in(0)
    {
        if (m_list_in)
            m_list_in->Add(&m_item);
    }
    /**
     **********************************************************************
     * Constructor: cDocumentNodeProcessor
     *
     *      Author: $author$
     *        Date: 12/8/2005
     **********************************************************************
     */
    cDocumentNodeProcessor
    (cDocumentNodePreprocessorList *prelist_in) 
    : m_item(*this),
      m_list_in(0),
      m_prelist_in(prelist_in)
    {
        if (m_prelist_in)
            m_prelist_in->Add(&m_item);
    }
    /**
     **********************************************************************
     *  Destructor: ~cDocumentNodeProcessor
     *
     *      Author: $author$
     *        Date: 12/8/2005
     **********************************************************************
     */
    virtual ~cDocumentNodeProcessor()
    {
        if (m_prelist_in)
            m_prelist_in->Delete(&m_item);

        if (m_list_in)
            m_list_in->Delete(&m_item);
    }
    /**
     **********************************************************************
     * Function: GetItem
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual cDocumentNodeProcessorItem &GetItem() const
    {
        return (cDocumentNodeProcessorItem&)m_item;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/8/2005
 **********************************************************************
 */
class cDocumentElementProcessor
: virtual public cDocumentElementProcessorImplement,
  public cDocumentNodeProcessor
{
public:
    typedef cDocumentNodeProcessor cIs;

    cDocumentElementProcessorBranch m_branch;
    cCCharBuffer m_name;

    /**
     **********************************************************************
     * Constructor: cDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/8/2005
     **********************************************************************
     */
    cDocumentElementProcessor
    (const char* name, int namelen=-1,
     cDocumentNodeProcessorList *list_in=&m_list)
    : cIs(list_in),
      m_branch(*this)
    {
        eError error;

        if (0 >= (namelen = m_name.Writec(name, namelen)))
            throw(error = -namelen);
    }
    /**
     **********************************************************************
     * Constructor: cDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/8/2005
     **********************************************************************
     */
    cDocumentElementProcessor
    (const char* name, int namelen,
     cDocumentNodePreprocessorList *prelist_in)
    : cIs(prelist_in),
      m_branch(*this)
    {
        eError error;

        if (0 >= (namelen = m_name.Writec(name, namelen)))
            throw(error = -namelen);
    }
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual cDocumentElementProcessorBranch& GetBranch() const 
    {
        return (cDocumentElementProcessorBranch&)m_branch;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetName() const
    {
        return m_name;
    }
    /**
     **********************************************************************
     * Function: GetElementProcessor
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual cDocumentElementProcessorInterface* 
    GetElementProcessor() const
    {
        return (cDocumentElementProcessorInterface*)this;
    }
};

/**
 **********************************************************************
 *  Class: cNullDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/19/2005
 **********************************************************************
 */
class cNullDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cNullDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/19/2005
     **********************************************************************
     */
    cNullDocumentElementProcessor
    (const char *name, int namelen=-1) 
    : cIs(name, namelen)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual eError Process
    (cDocumentProcessorInterface &processor,
     cDocumentNodeListInterface &result, 
     cDocumentElementInterface &function) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDefaultDocumentElementProcessor
 *
 * Author: $author$
 *   Date: 12/8/2005
 **********************************************************************
 */
class cDefaultDocumentElementProcessor
: public cDocumentElementProcessor
{
public:
    typedef cDocumentElementProcessor cIs;

    static cDefaultDocumentElementProcessor m_instance;

    cDocumentElementProcessorInterface* m_old_default;

    /**
     **********************************************************************
     * Constructor: cDefaultDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/8/2005
     **********************************************************************
     */
    cDefaultDocumentElementProcessor(const char *name="*") 
    : cIs(name, -1, (cDocumentNodeProcessorList*)0) 
    {
        m_old_default = m_default;
        m_default = this;
    }
    /**
     **********************************************************************
     *  Destructor: ~cDefaultDocumentElementProcessor
     *
     *      Author: $author$
     *        Date: 12/8/2005
     **********************************************************************
     */
    virtual ~cDefaultDocumentElementProcessor()
    {
        m_default = m_old_default;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentProcessor
 *
 * Author: $author$
 *   Date: 12/7/2005
 **********************************************************************
 */
class cDocumentProcessor
: virtual public cInitializeImplement,
  virtual public cDocumentProcessorImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    cDocumentNodeFactoryInterface& m_node_factory;
    cDocument m_null_document;
    cDocumentInterface* m_document;
    cDocumentNodeList m_null_node_list;
    cDocumentNodeListInterface* m_node_list;
    cDocumentNodeInterface* m_node;
    cDocumentNodeListReferenceListTree m_node_list_tree;
    cDocumentElementProcessorTree m_element_processor_tree;
    cDocumentElementProcessorTree m_element_preprocessor_tree;
    cDocumentNodeProcessorItem *m_item;
    cDocumentNodeProcessorItem *m_preitem;
    cNameDocumentElementTree m_template_element_tree;
    cNameDocumentElementList m_template_element_list;
    int m_depth;


    /**
     **********************************************************************
     * Constructor: cDocumentProcessor
     *
     *      Author: $author$
     *        Date: 12/7/2005
     **********************************************************************
     */
    cDocumentProcessor
    (cDocumentEventInterface& event,
     cDocumentNodeFactoryInterface& node_factory,
     cDocumentFactoryInterface &factory,
     cDocumentParserInterface &parser,
     const cCCharBuffer &ns_attribute_prefix) 
    : m_node_factory(node_factory),
      m_null_document
      (event, node_factory, factory, 
       parser, ns_attribute_prefix),
      m_document(0),
      m_null_node_list(event, node_factory),
      m_node_list(0),
      m_node(0),
      m_item(0),
      m_preitem(0),
      m_depth(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDocumentProcessor
     *
     *      Author: $author$
     *        Date: 12/7/2005
     **********************************************************************
     */
    virtual ~cDocumentProcessor()
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual eError Initialize()
    {
        eError error = e_ERROR_NONE;
        cDocumentElementProcessorInterface *e_processor;

        m_depth = 0;

        if ((m_preitem = cDocumentNodeProcessor::m_prelist.GetFirst()))
        do
        {
            cDocumentNodeProcessorInterface &processor = m_preitem->GetProcessor();

            if ((error = processor.Initialize(*this)))
            {
                Finalize();
                return error;
            }

            if ((e_processor = processor.GetElementProcessor()))
            {
                cDocumentElementProcessorBranch &branch = e_processor->GetBranch();
                m_element_preprocessor_tree.Insert(&branch);
            }
        }
        while ((m_preitem = m_preitem->GetNext()));

        if ((m_item = cDocumentNodeProcessor::m_list.GetFirst()))
        do
        {
            cDocumentNodeProcessorInterface &processor = m_item->GetProcessor();

            if ((error = processor.Initialize(*this)))
            {
                Finalize();
                return error;
            }

            if ((e_processor = processor.GetElementProcessor()))
            {
                cDocumentElementProcessorBranch &branch = e_processor->GetBranch();
                m_element_processor_tree.Insert(&branch);
            }
        }
        while ((m_item = m_item->GetNext()));

        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 12/8/2005
     **********************************************************************
     */
    virtual eError Finalize()
    {
        eError error2, error = e_ERROR_NONE;

        if ((m_preitem = cDocumentNodeProcessor::m_prelist.GetLast()))
        do
        {
            cDocumentNodeProcessorInterface &processor = m_preitem->GetProcessor();

            if ((error2 = processor.Finalize(*this)))
            if (!error)
                error = error2;
        }
        while ((m_preitem = m_preitem->GetPrevious()));

        m_element_preprocessor_tree.Clear();

        if ((m_item = cDocumentNodeProcessor::m_list.GetLast()))
        do
        {
            cDocumentNodeProcessorInterface &processor = m_item->GetProcessor();

            if ((error2 = processor.Finalize(*this)))
            if (!error)
                error = error2;
        }
        while ((m_item = m_item->GetPrevious()));

        m_element_processor_tree.Clear();
        return error;
    }

    /**
     **********************************************************************
     * Function: PreprocessFunctionNode
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual eError PreprocessFunctionNode
    (cDocumentNodeListInterface& result,
     cDocumentNodeInterface& function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterface *e;
        cDocumentElementProcessorInterface *e_p;

        if ((e = function.GetElementInterface()))
        {
            if (!(e_p = m_element_preprocessor_tree.Find(*e)))
                return error;

            error = e_p->Process(*this, result, *e);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: PreprocessFunctionElement
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual eError PreprocessFunctionElement
    (cDocumentNodeListInterface& result,
     cDocumentElementInterface& function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementProcessorInterface *e_p;

        if (!(e_p = m_element_preprocessor_tree.Find(function)))
            return error;

        error = e_p->Process(*this, result, function);
        return error;
    }

    /**
     **********************************************************************
     * Function: ProcessFunctionNode
     *
     *   Author: $author$
     *     Date: 12/7/2005
     **********************************************************************
     */
    virtual eError ProcessFunctionNode
    (cDocumentNodeListInterface& result,
     cDocumentNodeInterface& function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementInterface *e;
        cDocumentElementProcessorInterface *e_p;

        if ((e = function.GetElementInterface()))
        {
            if (!(e_p = m_element_processor_tree.Find(*e)))
            if (!(e_p = cDocumentElementProcessorInterface::m_default))
                return error;

            error = e_p->Process(*this, result, *e);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessFunctionElement
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    virtual eError ProcessFunctionElement
    (cDocumentNodeListInterface& result,
     cDocumentElementInterface& function) 
    {
        eError error = e_ERROR_NONE;
        cDocumentElementProcessorInterface *e_p;

        if (!(e_p = m_element_processor_tree.Find(function)))
        if (!(e_p = cDocumentElementProcessorInterface::m_default))
            return error;

        error = e_p->Process(*this, result, function);
        return error;
    }

    /**
     **********************************************************************
     * Function: GetSetVariable
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* GetSetVariable
    (eError& error,
     const cCCharBuffer& name, 
     cDocumentNodeListInterface* node_list) 
    {
        cDocumentNodeListInterface* old_node_list = 0;
        cDocumentNodeListReferenceList* list;
        cDocumentNodeListReferenceItem* item;

        error = e_ERROR_FAILED;

        if ((list = m_node_list_tree.GetList(name)))
        {
            if (!node_list)
            if (!(node_list = CreateNodeList(error)))
                return old_node_list;

            if ((item = list->Pop()))
            {
                old_node_list = &item->GetNodeList();
                DestroyNodeListReference(*item);
            }

            if ((item = CreateNodeListReference(error, *node_list)))
                list->Push(item);
        }
        return old_node_list;
    }
    /**
     **********************************************************************
     * Function: GetVariable
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* GetVariable
    (const cCCharBuffer& name) const 
    {
        cDocumentNodeListInterface* node_list = 0;
        cDocumentNodeListReferenceList* list;
        cDocumentNodeListReferenceItem* item;

        if ((list = m_node_list_tree.FindList(name)))
        if ((item = list->GetFirst()))
            node_list = &item->GetNodeList();
        return node_list;
    }

    /**
     **********************************************************************
     * Function: CreateNodeListReference
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual cDocumentNodeListReferenceItem* CreateNodeListReference
    (eError &error, cDocumentNodeListInterface& node_list) 
    {
        cDocumentNodeListReferenceItem* item = 0;

        error = e_ERROR_NEW;

        if ((item = new cDocumentNodeListReferenceItem(node_list)))
            error = e_ERROR_NONE;
        return item;
    }
    /**
     **********************************************************************
     * Function: DestroyNodeListReference
     *
     *   Author: $author$
     *     Date: 12/16/2005
     **********************************************************************
     */
    virtual eError DestroyNodeListReference
    (cDocumentNodeListReferenceItem& item) 
    {
        eError error = e_ERROR_DELETE;

        delete &item;
        error = e_ERROR_NONE;
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
        cDocumentNodeListInterface* node_list 
         = m_node_factory.CreateNodeList(error);
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
        eError error = m_node_factory.DestroyNodeList(node_list);
        return error;
    }

    /**
     **********************************************************************
     * Function: SetDocumentInterface
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual cDocumentInterface* SetDocumentInterface
    (cDocumentInterface* document) 
    {
        cDocumentInterface* old_document = m_document;
        m_document = document;
        return old_document;
    }
    /**
     **********************************************************************
     * Function: GetDocumentInterface
     *
     *   Author: $author$
     *     Date: 12/17/2005
     **********************************************************************
     */
    virtual cDocumentInterface& GetDocumentInterface() const 
    {
        if (m_document)
            return *m_document;
        return (cDocumentInterface&)m_null_document;
    }

    /**
     **********************************************************************
     * Function: SetNodeListInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* SetNodeListInterface
    (cDocumentNodeListInterface* node_list) 
    {
        cDocumentNodeListInterface* old_node_list = m_node_list;
        m_node_list = node_list;
        return old_node_list;
    }
    /**
     **********************************************************************
     * Function: GetNodeListInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface& GetNodeListInterface() const 
    {
        if (m_node_list)
            return *m_node_list;

        return (cDocumentNodeListInterface&)m_null_node_list;
    }

    /**
     **********************************************************************
     * Function: SetNodeInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* SetNodeInterface
    (cDocumentNodeInterface* node) 
    {
        cDocumentNodeInterface* old_node = m_node;
        m_node = node;
        return old_node;
    }
    /**
     **********************************************************************
     * Function: GetNodeInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentNodeInterface* GetNodeInterface() const 
    {
        return m_node;
    }

    /**
     **********************************************************************
     * Function: RegisterTemplateElement
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual eError RegisterTemplateElement
    (const cCCharBuffer& name,
     cDocumentElementInterface& element) 
    {
        eError error = e_ERROR_NEW;
        cNameDocumentElementItem* item;

        if ((item = new cNameDocumentElementItem(name, element)))
        {
            cNameDocumentElementBranch& branch = item->GetBranch();
            m_template_element_tree.Insert(&branch);
            m_template_element_list.Add(item);
            error = e_ERROR_NONE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: FindTemplateElement
     *
     *   Author: $author$
     *     Date: 12/19/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* FindTemplateElement
    (const cCCharBuffer& name) const 
    {
        cDocumentElementInterface* element = 0;
        cNameDocumentElementBranch* branch;

        if ((branch = m_template_element_tree.Find(name)))
            element = &branch->GetElement();
        return element;
    }
};

#endif /* _CDOCUMENTPROCESSOR_HXX */
