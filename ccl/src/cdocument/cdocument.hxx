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
 *   File: cdocument.hxx
 *
 * Author: $author$
 *   Date: 10/12/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENT_HXX
#define _CDOCUMENT_HXX

#include "cdocumentdata.hxx"
#include "cdocumentnodelist.hxx"
#include "cdocumentnode.hxx"
#include "cdocumentartifact.hxx"
#include "cdocumentparserinterface.hxx"
#include "cdocumenteventinterface.hxx"
#include "cdocumentimplement.hxx"
#include "cdocumentartifactimplement.hxx"
#include "cdocumentartifactinterface.hxx"
#include "cavltreet.hxx"
#include "clistt.hxx"
#include "cisdynamicinstance.hxx"
#include "cinstance.hxx"
#include "cccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cDocumentEntityReference
 *
 * Author: $author$
 *   Date: 11/14/2005
 **********************************************************************
 */
class cDocumentEntityReference
: virtual public cDocumentNodeFactoryArtifactImplement,
  virtual public cDocumentEntityReferenceImplement,
  public cDocumentNamedNode
{
public:
    typedef cDocumentNamedNode cIs;

    cDocumentNodeFactoryInterface& m_node_factory;

    /**
     **********************************************************************
     * Constructor: cDocumentEntityReference
     *
     *      Author: $author$
     *        Date: 11/14/2005
     **********************************************************************
     */
    cDocumentEntityReference
    (cDocumentNodeFactoryInterface& node_factory,
     const cChar* chars=0, int length=-1,
     const cChar* prefix_chars=0, int prefix_length=-1) 
    : cIs
      (e_TYPE_ENTITY_REFERENCE, 
       chars, length, prefix_chars, prefix_length),
      m_node_factory(node_factory)
    {
    }
    /**
     **********************************************************************
     * Constructor: cDocumentEntityReference
     *
     *      Author: $author$
     *        Date: 11/14/2005
     **********************************************************************
     */
    cDocumentEntityReference
    (cDocumentNodeFactoryInterface& node_factory,
     const char* chars, int length=-1,
     const char* prefix_chars=0, int prefix_length=-1) 
    : cIs
      (e_TYPE_ENTITY_REFERENCE, 
       chars, length, prefix_chars, prefix_length),
      m_node_factory(node_factory)
    {
    }
    /**
     **********************************************************************
     * Function: AsDocumentEntityReference
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual cDocumentEntityReference& AsDocumentEntityReference() 
    {
        return *this;
    }
    /**
     **********************************************************************
     * Function: GetEntityReferenceInterface
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual cDocumentEntityReferenceInterface* GetEntityReferenceInterface() const
    {
        cDocumentEntityReferenceInterface* node = (cDocumentEntityReferenceInterface*)this;
        return node;
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
};

/**
 **********************************************************************
 *  Class: cDocumentAttribute
 *
 * Author: $author$
 *   Date: 10/19/2005
 **********************************************************************
 */
class cDocumentAttribute
: virtual public cDocumentNodeFactoryArtifactImplement,
  virtual public cDocumentAttributeImplement,
  public cDocumentNamedNode
{
public:
    typedef cDocumentNamedNode cIs;

    cDocumentNodeFactoryInterface& m_node_factory;

    cCCharBuffer m_value;
    bool m_is_namespace_attribute;
    bool m_is_namespace_prefix_attribute;

    /**
     **********************************************************************
     * Constructor: cDocumentAttribute
     *
     *      Author: $author$
     *        Date: 10/19/2005
     **********************************************************************
     */
    cDocumentAttribute
    (cDocumentNodeFactoryInterface& node_factory,
     const cChar* chars=0, int length=-1,
     const cChar* prefix_chars=0, int prefix_length=-1,
     int type=e_TYPE_ATTRIBUTE)
    : cIs
      (type, chars, length, 
       prefix_chars, prefix_length), 
      m_node_factory(node_factory),
      m_is_namespace_attribute(false),
      m_is_namespace_prefix_attribute(false)
    {
    }
    /**
     **********************************************************************
     * Function: AsDocumentAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     *
    virtual cDocumentAttribute& AsDocumentAttribute() 
    {
        return *this;
    }*/
    /**
     **********************************************************************
     * Function: GetAttributeInterface
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetAttributeInterface() const 
    {
        cDocumentAttributeInterface* node = (cDocumentAttributeInterface*)this;
        return node;
    }
    /**
     **********************************************************************
     * Function: SetValueChars
     *
     *   Author: $author$
     *     Date: 19/12/2005
     **********************************************************************
     */
    virtual int SetValueChars
    (const char* chars, int length=-1) 
    {
        length = m_value.Copyc(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: SetValueCChars
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual int SetValueCChars
    (const cChar* chars, int length=-1) 
    {
        length = m_value.Copy(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetValueCChars
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual const cChar* GetValueCChars(int &length) const
    {
        const cChar* chars = m_value.GetBuffer(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer& GetValue() const 
    {
        return m_value;
    }

    /**
     **********************************************************************
     * Function: SetIsNamespaceAttribute
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual eError SetIsNamespaceAttribute(bool is=true) 
    {
        eError error = e_ERROR_NONE;
        m_is_namespace_attribute = is;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetIsNamespaceAttribute
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual bool GetIsNamespaceAttribute() const 
    {
        return m_is_namespace_attribute;
    }

    /**
     **********************************************************************
     * Function: SetIsNamespacePrefixAttribute
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual eError SetIsNamespacePrefixAttribute(bool is=true) 
    {
        eError error = e_ERROR_NONE;
        m_is_namespace_prefix_attribute = is;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetIsNamespacePrefixAttribute
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual bool GetIsNamespacePrefixAttribute() const 
    {
        return m_is_namespace_prefix_attribute;
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
};

/**
 **********************************************************************
 *  Class: cDocumentEndElement
 *
 * Author: $author$
 *   Date: 12/12/2005
 **********************************************************************
 */
class cDocumentEndElement
: virtual public cDocumentEndElementImplement,
  public cDocumentNamedNode
{
public:
    typedef cDocumentNamedNode cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentEndElement
     *
     *      Author: $author$
     *        Date: 12/12/2005
     **********************************************************************
     */
    cDocumentEndElement
    (const cChar* chars=0, int length=-1,
     const cChar* prefix_chars=0, int prefix_length=-1,
     int type=e_TYPE_END_ELEMENT)
    : cIs
      (type, chars, length, 
       prefix_chars, prefix_length) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cDocumentEndElement
     *
     *      Author: $author$
     *        Date: 12/12/2005
     **********************************************************************
     */
    cDocumentEndElement
    (const char* chars, int length=-1,
     const char* prefix_chars=0, int prefix_length=-1,
     int type=e_TYPE_END_ELEMENT)
    : cIs
      (type, chars, length, 
       prefix_chars, prefix_length) 
    {
    }
    /**
     **********************************************************************
     * Function: GetEndElementInterface
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentEndElementInterface* 
    GetEndElementInterface() const 
    {
        cDocumentEndElementInterface* node = (cDocumentEndElementInterface*)this;
        return node;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentBeginElement
 *
 * Author: $author$
 *   Date: 12/12/2005
 **********************************************************************
 */
class cDocumentBeginElement
: virtual public cDocumentEventArtifactImplement,
  virtual public cDocumentAttributeListImplement,
  virtual public cDocumentBeginElementImplement,
  public cDocumentEndElement
{
public:
    typedef cDocumentEndElement cIs;

    cDocumentAttributeList m_attribute_list;

    /**
     **********************************************************************
     * Constructor: cDocumentBeginElement
     *
     *      Author: $author$
     *        Date: 12/12/2005
     **********************************************************************
     */
    cDocumentBeginElement
    (cDocumentEventInterface &event,
     cDocumentNodeFactoryInterface &node_factory,
     const cChar* chars=0, int length=-1,
     const cChar* prefix_chars=0, int prefix_length=-1)
    : cIs
      (chars, length, 
       prefix_chars, prefix_length, 
       e_TYPE_BEGIN_ELEMENT),
      m_attribute_list(event, node_factory, *this) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cDocumentBeginElement
     *
     *      Author: $author$
     *        Date: 12/12/2005
     **********************************************************************
     */
    cDocumentBeginElement
    (cDocumentEventInterface &event,
     cDocumentNodeFactoryInterface &node_factory,
     const char* chars, int length=-1,
     const char* prefix_chars=0, int prefix_length=-1)
    : cIs
      (chars, length, 
       prefix_chars, prefix_length, 
       e_TYPE_BEGIN_ELEMENT),
      m_attribute_list(event, node_factory, *this) 
    {
    }
    /**
     **********************************************************************
     * Function: GetBeginElementInterface
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentBeginElementInterface* 
    GetBeginElementInterface() const 
    {
        cDocumentBeginElementInterface* node = (cDocumentBeginElementInterface*)this;
        return node;
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

        if (!(error = m_attribute_list.AddAttribute(node)))
            error = event.OnAddAttribute(*this, node);
        return error;
    }
    /**
     **********************************************************************
     * Function: GetFirstAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetFirstAttribute() const 
    {
        cDocumentNodeInterface* node = 0;
        cDocumentAttributeInterface* attribute = 0;

        if ((node = m_attribute_list.GetFirstNode()))
        do
        {
            if ((attribute = node->GetAttributeInterface()))
                break;
        }
        while ((node = node->GetNextNode()));
        return attribute;
    }
    /**
     **********************************************************************
     * Function: GetLastAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetLastAttribute() const 
    {
        cDocumentNodeInterface* node = 0;
        cDocumentAttributeInterface* attribute = 0;

        if ((node = m_attribute_list.GetLastNode()))
        do
        {
            if ((attribute = node->GetAttributeInterface()))
                break;
        }
        while ((node = node->GetPreviousNode()));
        return attribute;
    }
    /**
     **********************************************************************
     * Function: GetAttributeListInterface
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual cDocumentAttributeListInterface* 
    GetAttributeListInterface() const 
    {
        return (cDocumentNodeListInterface*)&m_attribute_list;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentElement
 *
 * Author: $author$
 *   Date: 10/13/2005
 **********************************************************************
 */
class cDocumentElement
: virtual public cDocumentBeginElementImplement,
  virtual public cDocumentElementImplement,
  public cDocumentNodeListT
  <cDocumentElement, cDocumentNamedNode>
{
public:
    typedef cDocumentNodeListT
    <cDocumentElement, cDocumentNamedNode> cIs;

    cDocumentAttributeList m_attribute_list;

    /**
     **********************************************************************
     * Constructor: cDocumentElement
     *
     *      Author: $author$
     *        Date: 10/13/2005
     **********************************************************************
     */
    cDocumentElement
    (cDocumentEventInterface &event,
     cDocumentNodeFactoryInterface &node_factory,
     const cChar* chars=0, int length=-1,
     const cChar* prefix_chars=0, int prefix_length=-1)
    : cIs(event, node_factory),
      m_attribute_list(event, node_factory, *this)
    {
        eError error;

        if (chars)
        if (0 > (length = SetNameCChars(chars, length)))
            throw(error = -length);

        if (prefix_chars)
        if (0 > (prefix_length = SetNamespacePrefixCChars
            (prefix_chars, prefix_length)))
            throw(error = -prefix_length);

        m_type = e_TYPE_ELEMENT;
    }
    /**
     **********************************************************************
     * Constructor: cDocumentElement
     *
     *      Author: $author$
     *        Date: 10/13/2005
     **********************************************************************
     */
    cDocumentElement
    (cDocumentEventInterface &event,
     cDocumentNodeFactoryInterface &node_factory,
     const char* chars, int length=-1,
     const char* prefix_chars=0, int prefix_length=-1) 
    : cIs(event, node_factory),
      m_attribute_list(event, node_factory, *this)
    {
        eError error;

        if (chars)
        if (0 > (length = SetNameChars(chars, length)))
            throw(error = -length);

        if (prefix_chars)
        if (0 > (prefix_length = SetNamespacePrefixChars
            (prefix_chars, prefix_length)))
            throw(error = -prefix_length);

        m_type = e_TYPE_ELEMENT;
    }
    /**
     **********************************************************************
     *  Destructor: ~cDocumentElement
     *
     *      Author: $author$
     *        Date: 10/20/2005
     **********************************************************************
     */
    virtual ~cDocumentElement()
    {
        eError error;

        if ((error = m_attribute_list.DeleteAllNodes()))
            throw(error);

        if ((error = DeleteAllNodes()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: AsDocumentElement
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     *
    virtual cDocumentElement& AsDocumentElement()
    {
        return *this;
    }*/
    /**
     **********************************************************************
     * Function: GetElementInterface
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetElementInterface() const 
    {
        cDocumentElementInterface* node = (cDocumentElementInterface*)this;
        return node;
    }
    /**
     **********************************************************************
     * Function: GetNodeListInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* GetNodeListInterface() const 
    {
        return (cDocumentNodeListInterface*)this;
    }
    /**
     **********************************************************************
     * Function: GetAttributeListInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentAttributeListInterface* 
    GetAttributeListInterface() const 
    {
        return (cDocumentNodeListInterface*)&m_attribute_list;
    }

    /**
     **********************************************************************
     * Function: AddElement
     *
     *   Author: $author$
     *     Date: 11/22/2005
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

        if (!(error = m_attribute_list.AddAttribute(node)))
            error = event.OnAddAttribute(*this, node);
        return error;
    }
    /**
     **********************************************************************
     * Function: AddNode
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual eError AddNode
    (cDocumentNodeInterface& node) 
    {
        eError error;

        if (!(error = cIs::AddNode(node)))
            node.SetParentElement(this);
        return error;
    }

    /**
     **********************************************************************
     * Function: GetFirstAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetFirstAttribute() const 
    {
        cDocumentNodeInterface* node = 0;
        cDocumentAttributeInterface* attribute = 0;

        if ((node = m_attribute_list.GetFirstNode()))
        do
        {
            if ((attribute = node->GetAttributeInterface()))
                break;
        }
        while ((node = node->GetNextNode()));
        return attribute;
    }
    /**
     **********************************************************************
     * Function: GetLastAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual cDocumentAttributeInterface* GetLastAttribute() const 
    {
        cDocumentNodeInterface* node = 0;
        cDocumentAttributeInterface* attribute = 0;

        if ((node = m_attribute_list.GetLastNode()))
        do
        {
            if ((attribute = node->GetAttributeInterface()))
                break;
        }
        while ((node = node->GetPreviousNode()));
        return attribute;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentText
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class cDocumentText
: virtual public cDocumentTextImplement,
  public cDocumentTextNode
{
public:
    typedef cDocumentTextNode cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentText
     *
     *      Author: $author$
     *        Date: 10/17/2005
     **********************************************************************
     */
    cDocumentText
    (cDocumentNodeFactoryInterface& node_factory,
     const char* chars=0, int length=-1) 
    : cIs(node_factory, chars, length, e_TYPE_TEXT)
    {
    }
    /**
     **********************************************************************
     * Constructor: cDocumentText
     *
     *      Author: $author$
     *        Date: 10/17/2005
     **********************************************************************
     */
    cDocumentText
    (cDocumentNodeFactoryInterface& node_factory,
     const cChar* chars, int length=-1) 
    : cIs(node_factory, chars, length, e_TYPE_TEXT)
    {
    }
    /**
     **********************************************************************
     * Function: AsDocumentText
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     *
    virtual cDocumentText& AsDocumentText() 
    {
        cDocumentText& node = *this;
        return node;
    }*/
    /**
     **********************************************************************
     * Function: GetTextInterface
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* GetTextInterface() const 
    {
        cDocumentTextInterface* node = (cDocumentTextInterface*)this;
        return node;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentComment
 *
 * Author: $author$
 *   Date: 10/13/2005
 **********************************************************************
 */
class cDocumentComment
: virtual public cDocumentCommentImplement,
  public cDocumentTextNode
{
public:
    typedef cDocumentTextNode cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentComment
     *
     *      Author: $author$
     *        Date: 10/17/2005
     **********************************************************************
     */
    cDocumentComment
    (cDocumentNodeFactoryInterface& node_factory,
     const char* chars=0, int length=-1) 
    : cIs(node_factory, chars, length, e_TYPE_COMMENT)
    {
    }
    /**
     **********************************************************************
     * Constructor: cDocumentComment
     *
     *      Author: $author$
     *        Date: 10/17/2005
     **********************************************************************
     */
    cDocumentComment
    (cDocumentNodeFactoryInterface& node_factory,
     const cChar* chars, int length=-1) 
    : cIs(node_factory, chars, length, e_TYPE_COMMENT)
    {
    }
    /**
     **********************************************************************
     * Function: AsDocumentComment
     *
     *   Author: $author$
     *     Date: 10/13/2005
     **********************************************************************
     */
    virtual cDocumentComment& AsDocumentComment() 
    {
        cDocumentComment& node = *this;
        return node;
    }
    /**
     **********************************************************************
     * Function: GetCommentInterface
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual cDocumentCommentInterface* GetCommentInterface() const 
    {
        cDocumentCommentInterface* node = (cDocumentCommentInterface*)this;
        return node;
    }
};

/**
 **********************************************************************
 *  Class: cDocument
 *
 * Author: $author$
 *   Date: 10/15/2005
 **********************************************************************
 */
class cDocument
: virtual public cDocumentImplement,
  public cDocumentNodeListT
  <cDocument, cDocumentNode>
{
public:
    typedef cDocumentNodeListT
    <cDocument, cDocumentNode> cIs;

    cDocumentFactoryInterface &m_factory;
    cDocumentParserInterface &m_parser;
    const cCCharBuffer &m_ns_attribute_prefix;

    /**
     **********************************************************************
     * Constructor: cDocument
     *
     *      Author: $author$
     *        Date: 10/15/2005
     **********************************************************************
     */
    cDocument
    (cDocumentEventInterface &event,
     cDocumentNodeFactoryInterface &node_factory,
     cDocumentFactoryInterface &factory,
     cDocumentParserInterface &parser,
     const cCCharBuffer &ns_attribute_prefix)
    : cIs(event, node_factory),
      m_factory(factory),
      m_parser(parser),
      m_ns_attribute_prefix(ns_attribute_prefix)
    {
        m_type = e_TYPE_DOCUMENT;
    }
    /**
     **********************************************************************
     *  Destructor: ~cDocument
     *
     *      Author: $author$
     *        Date: 10/15/2005
     **********************************************************************
     */
    virtual ~cDocument()
    {
        eError error;

        if ((error = DeleteAllNodes()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: AsDocument
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual cDocument& AsDocument()
    {
        return *this;
    }
    /**
     **********************************************************************
     * Function: GetDocumentInterface
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual cDocumentInterface* GetDocumentInterface() const 
    {
        return (cDocumentInterface*)this;
    }
    /**
     **********************************************************************
     * Function: GetNodeListInterface
     *
     *   Author: $author$
     *     Date: 12/9/2005
     **********************************************************************
     */
    virtual cDocumentNodeListInterface* GetNodeListInterface() const 
    {
        return (cDocumentNodeListInterface*)this;
    }

    /**
     **********************************************************************
     * Function: ParseFromStream
     *
     *   Author: $author$
     *     Date: 11/8/2005
     **********************************************************************
     */
    virtual eError ParseFromStream
    (cCharStreamInterface &stream, int length=-1) 
    {
        eError error = m_parser.ParseStream(stream, length);
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseFromReader
     *
     *   Author: $author$
     *     Date: 11/7/2005
     **********************************************************************
     */
    virtual eError ParseFromReader
    (cCharReaderInterface &reader, int length=-1) 
    {
        eError error = m_parser.ParseReader(reader, length);
        return error;
    }
    /**
     **********************************************************************
     * Function: GetFactory
     *
     *   Author: $author$
     *     Date: 11/24/2005
     **********************************************************************
     */
    virtual cDocumentFactoryInterface& GetFactory() const 
    {
        return m_factory;
    }
    /**
     **********************************************************************
     * Function: GetParser
     *
     *   Author: $author$
     *     Date: 11/26/2005
     **********************************************************************
     */
    virtual cDocumentParserInterface& GetParser() const 
    {
        return m_parser;
    }
    /**
     **********************************************************************
     * Function: GetNamespaceAttributePrefixCChars
     *
     *   Author: $author$
     *     Date: 11/29/2005
     **********************************************************************
     */
    virtual const cChar* 
    GetNamespaceAttributePrefixCChars(int &length) const 
    {
        const cChar* chars = m_ns_attribute_prefix.GetBuffer(length);
        return chars;
    }

};

#endif /* _CDOCUMENT_HXX */
