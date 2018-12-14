/**
 **********************************************************************
 *  Class: cDocumentReferenceTextNode
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceTextNode
: public cDocumentReferenceNode
{
public:
    typedef cDocumentReferenceNode cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceTextNode
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceTextNode() 
    {
    }
    /**
     **********************************************************************
     * Function: GetTextNodeInterface
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual cDocumentTextNodeInterface* GetTextNodeInterface() const 
    {
        return this;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceText
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceText
: public cDocumentReferenceTextNode
{
public:
    typedef cDocumentReferenceTextNode cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceText
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceText() 
    {
    }
    /**
     **********************************************************************
     * Function: GetTextInterface
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentTextInterface* GetTextInterface() const 
    {
        return this;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceComment
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceComment
: public cDocumentReferenceTextNode
{
public:
    typedef cDocumentReferenceTextNode cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceComment
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceComment() 
    {
    }
    /**
     **********************************************************************
     * Function: GetCommentInterface
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentCommentInterface* GetCommentInterface() const 
    {
        return this;
    }
};




/**
 **********************************************************************
 *  Class: cDocumentReferenceNamedNode
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceNamedNode
: virtual public cDocumentNamedNodeImplement,
  public cDocumentReferenceNode
{
public:
    typedef cDocumentReferenceNode cIs;

    const cDocumentNamedNodeInterface &m_named_node;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceNamedNode
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceNamedNode
    (const cDocumentNamedNodeInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_named_node(node)
    {
    }
    /**
     **********************************************************************
     * Function: GetNamedNodeInterface
     *
     *   Author: $author$
     *     Date: 12/11/2005
     **********************************************************************
     */
    virtual cDocumentNamedNodeInterface* GetNamedNodeInterface() const 
    {
        return this;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceEndElement
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceEndElement
: public cDocumentReferenceNamedNode
{
public:
    typedef cDocumentReferenceNamedNode cIs;

    const cDocumentEndElementInterface &m_end_element;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceEndElement
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceEndElement
    (const cDocumentEndElementInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_end_element(node) 
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
        return this;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceBeginElement
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceBeginElement
: public cDocumentReferenceEndElement
{
public:
    typedef cDocumentReferenceEndElement cIs;

    const cDocumentBeginElementInterface &m_begin_element;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceBeginElement
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceBeginElement
    (const cDocumentBeginElementInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_begin_element(node) 
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
        return this;
    }
};


/**
 **********************************************************************
 *  Class: cDocumentReferenceElement
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceElement
: public cDocumentReferenceBeginElement
{
public:
    typedef cDocumentReferenceBeginElement cIs;

    const cDocumentElementInterface &m_element;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceElement
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceElement
    (const cDocumentElementInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_element(node)
    {
    }
    /**
     **********************************************************************
     * Function: GetElementInterface
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface* GetElementInterface() const 
    {
        return this;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceAttribute
 *
 * Author: $author$
 *   Date: 12/18/2005
 **********************************************************************
 */
class cDocumentReferenceAttribute
: public cDocumentReferenceNamedNode
{
public:
    typedef cDocumentReferenceNamedNode cIs;

    const cDocumentAttributeInterface &m_attribute;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceAttribute
     *
     *      Author: $author$
     *        Date: 12/18/2005
     **********************************************************************
     */
    cDocumentReferenceAttribute
    (const cDocumentAttributeInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_attribute(node) 
    {
    }
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
        return (cDocumentAttributeInterface*)this;
    }
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 12/14/2005
     **********************************************************************
     */
    virtual int SetValue
    (const cCCharBuffer& value, int length=-1) 
    {
        int count = m_attribute.SetValue(value, length);
        return count;
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
        return m_attribute.GetValue();
    }
    /**
     **********************************************************************
     * Function: SetValueChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetValueChars
    (const char* chars, int length=-1) 
    {
        length = m_attribute.SetValueChars(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: SetValueCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual int SetValueCChars
    (const cChar* chars, int length=-1) 
    {
        length = m_attribute.SetValueCChars(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetValueCChars
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual const cChar* GetValueCChars(int &length) const
    {
        const cChar* chars = m_attribute.GetValueCChars(length);
        return chars;
    }
};


