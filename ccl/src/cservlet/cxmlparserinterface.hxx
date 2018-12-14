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
 *   File: cxmlparserinterface.hxx
 *
 * Author: $author$
 *   Date: 9/30/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXMLPARSERINTERFACE_HXX
#define _CXMLPARSERINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cXMLTagParserEventInterfaceT
 *
 * Author: $author$
 *   Date: 11/24/2004
 **********************************************************************
 */
template <class TIs=cInterfaceBase>
class c_INTERFACE_CLASS cXMLTagParserEventInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: OnElementPrefix
     *
     *   Author: $author$
     *     Date: 11/24/2004
     **********************************************************************
     */
    virtual int OnElementPrefix
    (const char *text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnElementName
     *
     *   Author: $author$
     *     Date: 11/24/2004
     **********************************************************************
     */
    virtual int OnElementName
    (const char *text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnEndElementPrefix
     *
     *   Author: $author$
     *     Date: 11/24/2004
     **********************************************************************
     */
    virtual int OnEndElementPrefix
    (const char *text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnElementName
     *
     *   Author: $author$
     *     Date: 11/24/2004
     **********************************************************************
     */
    virtual int OnEndElementName
    (const char *text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnAttributePrefix
     *
     *   Author: $author$
     *     Date: 11/24/2004
     **********************************************************************
     */
    virtual int OnAttributePrefix
    (const char *text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnAttributeName
     *
     *   Author: $author$
     *     Date: 11/24/2004
     **********************************************************************
     */
    virtual int OnAttributeName
    (const char *text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnAttributeValue
     *
     *   Author: $author$
     *     Date: 11/24/2004
     **********************************************************************
     */
    virtual int OnAttributeValue
    (const char *text, int length=-1) = 0;
};

/**
 **********************************************************************
 *  Class: cXMLTagParserEventInterface
 *
 * Author: $author$
 *   Date: 11/24/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLTagParserEventInterface
: virtual public cXMLTagParserEventInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cXMLTagParserEventImplementT
 *
 * Author: $author$
 *   Date: 11/24/2004
 **********************************************************************
 */
template <class TIs=cXMLTagParserEventInterface>
class cXMLTagParserEventImplementT
: virtual public TIs
{
public:
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
        length = 0;
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
        length = 0;
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
        length = 0;
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
        length = 0;
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
        length = 0;
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
        length = 0;
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
        length = 0;
        return length;
    }
};

/**
 **********************************************************************
 *  Class: cXMLTagParserEventImplement
 *
 * Author: $author$
 *   Date: 11/24/2004
 **********************************************************************
 */
class cXMLTagParserEventImplement
: virtual public cXMLTagParserEventImplementT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cXMLTagParserEventProxy
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
class cXMLTagParserEventProxy
: virtual public cXMLTagParserEventInterface
{
public:
    cXMLTagParserEventInterface &m_proxy;

    /**
     **********************************************************************
     * Constructor: cXMLTagParserEventProxy
     *
     *      Author: $author$
     *        Date: 11/28/2004
     **********************************************************************
     */
    cXMLTagParserEventProxy
    (cXMLTagParserEventInterface &proxy) 
    : m_proxy(proxy) 
    {
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
        length = m_proxy.OnElementPrefix(text, length);
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
        length = m_proxy.OnElementName(text, length);
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
        length = m_proxy.OnEndElementPrefix(text, length);
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
        length = m_proxy.OnEndElementName(text, length);
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
        length = m_proxy.OnAttributePrefix(text, length);
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
        length = m_proxy.OnAttributeName(text, length);
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
        length = m_proxy.OnAttributeValue(text, length);
        return length;
    }
};

/**
 **********************************************************************
 *  Class: cXMLElementParserEventInterfaceT
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
template <class TIs=cXMLTagParserEventInterface>
class c_INTERFACE_CLASS cXMLElementParserEventInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: OnElement
     *
     *   Author: $author$
     *     Date: 11/28/2004
     **********************************************************************
     */
    virtual eError OnElement() = 0;
    /**
     **********************************************************************
     * Function: OnBeginElement
     *
     *   Author: $author$
     *     Date: 11/28/2004
     **********************************************************************
     */
    virtual eError OnBeginElement() = 0;
    /**
     **********************************************************************
     * Function: OnEndElement
     *
     *   Author: $author$
     *     Date: 11/28/2004
     **********************************************************************
     */
    virtual eError OnEndElement() = 0;
};

/**
 **********************************************************************
 *  Class: cXMLElementParserEventInterface
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLElementParserEventInterface
: virtual public cXMLElementParserEventInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cXMLElementParserEventImplementT
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
template 
<class TIs=cXMLTagParserEventImplement,
 class TInterfaceIs=cXMLElementParserEventInterface>

class cXMLElementParserEventImplementT
: virtual public TInterfaceIs,
  virtual public TIs
{
public:
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
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cXMLElementParserEventImplement
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
class cXMLElementParserEventImplement
: virtual public cXMLElementParserEventImplementT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cXMLElementParserEventProxy
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
class cXMLElementParserEventProxy
: virtual public cXMLElementParserEventInterface,
  public cXMLTagParserEventProxy
{
public:
    typedef cXMLTagParserEventProxy cIs;

    cXMLElementParserEventInterface &m_proxy;

    /**
     **********************************************************************
     * Constructor: cXMLElementParserEventProxy
     *
     *      Author: $author$
     *        Date: 11/28/2004
     **********************************************************************
     */
    cXMLElementParserEventProxy
    (cXMLElementParserEventInterface &proxy) 
    : cIs(proxy),
      m_proxy(proxy) 
    {
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
        eError error = m_proxy.OnElement();
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
        eError error = m_proxy.OnBeginElement();
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
        eError error = m_proxy.OnEndElement();
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cXMLDocumentParserEventInterfaceT
 *
 * Author: $author$
 *   Date: 11/29/2004
 **********************************************************************
 */
template <class TIs=cXMLElementParserEventInterface>
class c_INTERFACE_CLASS cXMLDocumentParserEventInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: OnDocument
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual eError OnDocument() = 0;
};

/**
 **********************************************************************
 *  Class: cXMLDocumentParserEventInterface
 *
 * Author: $author$
 *   Date: 11/29/2004
 **********************************************************************
 */
class cXMLDocumentParserEventInterface
: virtual public cXMLDocumentParserEventInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cXMLDocumentParserEventImplementT
 *
 * Author: $author$
 *   Date: 11/29/2004
 **********************************************************************
 */
template 
<class TIs=cXMLElementParserEventImplement,
 class TInterfaceIs=cXMLDocumentParserEventInterface>

class cXMLDocumentParserEventImplementT
: virtual public TInterfaceIs,
  virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: OnDocument
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual eError OnDocument() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cXMLDocumentParserEventImplement
 *
 * Author: $author$
 *   Date: 11/29/2004
 **********************************************************************
 */
class cXMLDocumentParserEventImplement
: virtual public cXMLDocumentParserEventImplementT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cXMLDocumentParserEventProxy
 *
 * Author: $author$
 *   Date: 11/28/2004
 **********************************************************************
 */
class cXMLDocumentParserEventProxy
: virtual public cXMLDocumentParserEventInterface,
  public cXMLElementParserEventProxy
{
public:
    typedef cXMLElementParserEventProxy cIs;

    cXMLDocumentParserEventInterface &m_proxy;

    /**
     **********************************************************************
     * Constructor: cXMLDocumentParserEventProxy
     *
     *      Author: $author$
     *        Date: 11/28/2004
     **********************************************************************
     */
    cXMLDocumentParserEventProxy
    (cXMLDocumentParserEventInterface &proxy) 
    : cIs(proxy),
      m_proxy(proxy) 
    {
    }
    /**
     **********************************************************************
     * Function: OnDocument
     *
     *   Author: $author$
     *     Date: 11/29/2004
     **********************************************************************
     */
    virtual eError OnDocument() 
    {
        eError error = m_proxy.OnDocument();
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cXMLParserEventInterfaceT
 *
 * Author: $author$
 *   Date: 9/30/2004
 **********************************************************************
 */
template <class TIs=cXMLDocumentParserEventInterface>
class c_INTERFACE_CLASS cXMLParserEventInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: OnBeginTag
     *
     *   Author: $author$
     *     Date: 9/30/2004
     **********************************************************************
     */
    virtual int OnBeginTag
    (const char* text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnEndTag
     *
     *   Author: $author$
     *     Date: 9/30/2004
     **********************************************************************
     */
    virtual int OnEndTag
    (const char* text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnTag
     *
     *   Author: $author$
     *     Date: 9/30/2004
     **********************************************************************
     */
    virtual int OnTag
    (const char* text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnText
     *
     *   Author: $author$
     *     Date: 9/30/2004
     **********************************************************************
     */
    virtual int OnText
    (const char* text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnComment
     *
     *   Author: $author$
     *     Date: 9/30/2004
     **********************************************************************
     */
    virtual int OnComment
    (const char* text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnProcessor
     *
     *   Author: $author$
     *     Date: 9/30/2004
     **********************************************************************
     */
    virtual int OnProcessor
    (const char* text, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnEntity
     *
     *   Author: $author$
     *     Date: 9/30/2004
     **********************************************************************
     */
    virtual int OnEntity
    (const char* text, int length=-1) = 0;
};

/**
 **********************************************************************
 *  Class: cXMLParserEventInterface
 *
 * Author: $author$
 *   Date: 11/24/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLParserEventInterface
: virtual public cXMLParserEventInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cXMLParserEventImplementT
 *
 * Author: $author$
 *   Date: 11/24/2004
 **********************************************************************
 */
template 
<class TIs=cXMLDocumentParserEventImplement,
 class TInterfaceIs=cXMLParserEventInterface>

class cXMLParserEventImplementT
: virtual public TInterfaceIs,
  virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: OnProcessor
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnProcessor
    (const char *text, int length=-1) 
    {
        length = 0;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnEntity
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnEntity
    (const char *text, int length=-1) 
    {
        length = 0;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnComment
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnComment
    (const char *text, int length=-1) 
    {
        length = 0;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnText
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnText
    (const char *text, int length=-1) 
    {
        length = 0;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnTag
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnTag
    (const char *text, int length=-1) 
    {
        length = 0;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnBeginTag
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnBeginTag
    (const char *text, int length=-1) 
    {
        length = 0;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnEndTag
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnEndTag
    (const char *text, int length=-1) 
    {
        length = 0;
        return length;
    }
};

/**
 **********************************************************************
 *  Class: cXMLParserEventImplement
 *
 * Author: $author$
 *   Date: 11/24/2004
 **********************************************************************
 */
class cXMLParserEventImplement
: virtual public cXMLParserEventImplementT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cXMLParserEventProxy
 *
 * Author: $author$
 *   Date: 12/17/2004
 **********************************************************************
 */
class cXMLParserEventProxy
: virtual public cXMLParserEventInterface,
  public cXMLDocumentParserEventProxy
{
public:
    typedef cXMLDocumentParserEventProxy cIs;

    cXMLParserEventInterface &m_proxy;

    /**
     **********************************************************************
     * Constructor: cXMLParserEventProxy
     *
     *      Author: $author$
     *        Date: 12/17/2004
     **********************************************************************
     */
    cXMLParserEventProxy
    (cXMLParserEventInterface &proxy) 
    : cIs(proxy),
      m_proxy(proxy) 
    {
    }
    /**
     **********************************************************************
     * Function: OnProcessor
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnProcessor
    (const char *text, int length=-1) 
    {
        length = m_proxy.OnProcessor(text, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: OnEntity
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnEntity
    (const char *text, int length=-1) 
    {
        length = m_proxy.OnEntity(text, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: OnComment
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnComment
    (const char *text, int length=-1) 
    {
        length = m_proxy.OnComment(text, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: OnText
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnText
    (const char *text, int length=-1) 
    {
        length = m_proxy.OnText(text, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: OnTag
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnTag
    (const char *text, int length=-1) 
    {
        length = m_proxy.OnTag(text, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: OnBeginTag
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnBeginTag
    (const char *text, int length=-1) 
    {
        length = m_proxy.OnBeginTag(text, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: OnEndTag
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int OnEndTag
    (const char *text, int length=-1) 
    {
        length = m_proxy.OnEndTag(text, length);
        return length;
    }
};

#endif /* ndef _CXMLPARSERINTERFACE_HXX */
