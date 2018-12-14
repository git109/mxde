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
 *   File: cdocument.hxx
 *
 * Author: $author$
 *   Date: 8/22/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENT_HXX
#define _CDOCUMENT_HXX

#include "cdocumentimplement.hxx"
#include "cdocumentinterface.hxx"
#include "cinstance.hxx"
#include "clistt.hxx"

/**
 **********************************************************************
 *  Class: cArtifact
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cArtifact
: virtual public cArtifactInterface,
  virtual public cArtifactImplement
{
public:
    typedef cErrorInstance cIs;

    cDocumentInterface *m_parent_document;
    cElementInterface *m_parent_element;

    /**
     **********************************************************************
     * Constructor: cArtifact
     *
     *      Author: $author$
     *        Date: 8/22/2003
     **********************************************************************
     */
    cArtifact
    (cDocumentInterface *parent_document=0,
     cElementInterface *parent_element=0)
    : m_parent_document(parent_document),
      m_parent_element(parent_element) 
    {
    }

    /**
     **********************************************************************
     * Function: SetParentDocument
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual eError SetParentDocument(cDocumentInterface *document)
    {
        m_parent_document=document;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetParentDocument
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual cDocumentInterface *GetParentDocument() const
    {
        return m_parent_document;
    }

    /**
     **********************************************************************
     * Function: SetParentElement
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual eError SetParentElement(cElementInterface *element)
    {
        m_parent_element=element;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetParentElement
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual cElementInterface *GetParentElement() const
    {
        return m_parent_element;
    }
};

/**
 **********************************************************************
 *  Class: cReferenceAtom
 *
 * Author: $author$
 *   Date: 8/28/2003
 **********************************************************************
 */
class cReferenceAtom
: virtual public cArtifactInterface,
  virtual public cArtifactImplement,
  virtual public cAtomInterface,
  virtual public cAtomImplement,
  virtual public cArtifact
{
public:
    cAtomInterface &m_atom;

    /**
     **********************************************************************
     * Constructor: cReferenceAtom
     *
     *      Author: $author$
     *        Date: 8/28/2003
     **********************************************************************
     */
    cReferenceAtom
    (cAtomInterface &atom,
     cDocumentInterface *parent_document=0,
     cElementInterface *parent_element=0) 
    : cArtifact(parent_document,parent_element),
      m_atom(atom)
    {
    }

    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual eError SetType(unsigned type)
    {
        return m_atom.SetType(type);
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual unsigned GetType() const
    {
        return m_atom.GetType();
    }

    /**
     **********************************************************************
     * Function: SetText
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual int SetText(const char *text,int textlen=-1)
    {
        return m_atom.SetText(text, textlen);
    }
    /**
     **********************************************************************
     * Function: GetText
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual const char *GetText(int &length) const
    {
        return m_atom.GetText(length);
    }
    /**
     **********************************************************************
     * Function: GetTextStream
     *
     *   Author: $author$
     *     Date: 2/17/2004
     **********************************************************************
     */
	virtual cCharStream *GetTextStream(int &length)
    {
        return m_atom.GetTextStream(length);
    }
    /**
     **********************************************************************
     * Function: GetTextLength
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual int GetTextLength() const
    {
        return m_atom.GetTextLength();
    }

    /**
     **********************************************************************
     * Function: GetTextNamespacePrefix
     *
     *   Author: $author$
     *     Date: 2/9/2004
     **********************************************************************
     */
	virtual const char *GetTextNamespacePrefix(int &length) const
    {
        return m_atom.GetTextNamespacePrefix(length);
    }
    /**
     **********************************************************************
     * Function: GetTextAfterNamespacePrefix
     *
     *   Author: $author$
     *     Date: 8/14/2004
     **********************************************************************
     */
	virtual const char *GetTextAfterNamespacePrefix(int &length) const
    {
        return m_atom.GetTextAfterNamespacePrefix(length);
    }
    /**
     **********************************************************************
     * Function: GetTextNamespace
     *
     *   Author: $author$
     *     Date: 2/9/2004
     **********************************************************************
     */
	virtual const char *GetTextNamespace(int &length) const
    {
        return m_atom.GetTextNamespace(length);
    }
};

/**
 **********************************************************************
 *  Class: cAtom
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cAtom
: virtual public cArtifactInterface,
  virtual public cArtifactImplement,
  virtual public cAtomInterface,
  virtual public cAtomImplement,
  virtual public cArtifact
{
public:
    unsigned m_type;
    cCharBuffer m_text;

    /**
     **********************************************************************
     * Constructor: cAtom
     *
     *      Author: $author$
     *        Date: 8/22/2003
     **********************************************************************
     */
    cAtom
    (unsigned type=e_TYPE_UNDEFINED,
     const char *text=0, int textlen=-1,
     cDocumentInterface *parent_document=0,
     cElementInterface *parent_element=0) 
    : cArtifact(parent_document,parent_element),
      m_type(type)
    {
        eError error;

        if (text)
        if ((textlen = SetText(text, textlen)) < 0)
            throw(error = e_ERROR_SET_TEXT);
    }

    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual eError SetType(unsigned type)
    {
        if (m_type != type)
        {
            if (m_type)
                return e_ERROR_NOT_ALLOWED;

            m_type=type;
        }
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual unsigned GetType() const
    {
        return m_type;
    }

    /**
     **********************************************************************
     * Function: SetText
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual int SetText(const char *text,int textlen=-1)
    {
        if ((textlen = m_text.Copy(text,textlen)) < 0)
            return -e_ERROR_COPY;

        return textlen;
    }
    /**
     **********************************************************************
     * Function: GetText
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual const char *GetText(int &length) const
    {
        length=m_text.GetLength();
        return m_text.GetBuffer();
    }
    /**
     **********************************************************************
     * Function: GetTextStream
     *
     *   Author: $author$
     *     Date: 2/17/2004
     **********************************************************************
     */
	virtual cCharStream *GetTextStream(int &length)
    {
        length=m_text.GetLength();
        return &m_text;
    }
    /**
     **********************************************************************
     * Function: GetTextLength
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual int GetTextLength() const
    {
        return m_text.GetLength();
    }
    /**
     **********************************************************************
     * Function: GetTextNamespacePrefix
     *
     *   Author: $author$
     *     Date: 2/9/2004
     **********************************************************************
     */
    virtual const char *GetTextNamespacePrefix(int &length) const
    {
        cDocumentInterface *document;
        const char *separator,*text,*prefix;
        int separatorlen,textlen;

        if ((text = GetText(textlen)))
        if (0 < textlen)
        if ((document = GetParentDocument()))
        if ((separator = document->GetNamespaceSeparator(separatorlen)))
        if (0 < separatorlen)
        if ((prefix = strstr(text, separator)))
        {
            length = prefix-text;
            return text;
        }
        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cAttributeItem
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cAttributeItem
: virtual public cAttributeInterface,
  public cDynamicListItemT<cAttributeItem>
{
public:
    typedef cDynamicListItemT<cAttributeItem> cListItemIs;
};

/**
 **********************************************************************
 *  Class: cAttributeList
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cAttributeList
: public cDynamicListT
  <cAttributeItem,cAttributeList>
{
public:
    typedef cDynamicListT
    <cAttributeItem,cAttributeList> cIs;

    /**
     **********************************************************************
     * Destructor: ~cAttributeList
     *
     *     Author: $author$
     *       Date: 8/22/2003
     **********************************************************************
     */
    ~cAttributeList()
    {
        eError error;

        if (!m_is_static)
        if ((error=Clear()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual eError Free(cAttributeItem *item)
    {
        eError error;

        if ((error=item->FreeInstance()))
            return e_ERROR_FREE;

        return e_ERROR_NONE;
    }
};

class cAttribute;

/**
 **********************************************************************
 *  Class: cAttribute
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cAttribute
: virtual public cArtifactInterface,
  virtual public cArtifactImplement,
  virtual public cAttributeInterface,
  virtual public cAttributeImplement,
  virtual public cArtifact,
  public cErrorInstance,
  public cAttributeItem,
  public cAtom
{
public:
    typedef cAtom cIs;
    typedef cAttributeItem cItemIs;

    cCharBuffer m_name;

    /**
     **********************************************************************
     * Constructor: cAttribute
     *
     *      Author: $author$
     *        Date: 8/22/2003
     **********************************************************************
     */
    cAttribute
    (cDocumentInterface *parent_document=0,
     cElementInterface *parent_element=0,
     const char *name=0,int namelen=-1,
     const char *text=0,int textlen=-1)
    : cArtifact(parent_document,parent_element),
      cIs(e_TYPE_ATTRIBUTE, text, textlen)
    {
        eError error;

        if (name)
        if ((namelen = SetName(name,namelen)) < 0)
            throw(error = e_ERROR_SET_NAME);
    }

    /**
     **********************************************************************
     * Function: GetAttribute
     *
     *   Author: $author$
     *     Date: 2/16/2004
     **********************************************************************
     */
    virtual cAttributeInterface *GetAttribute() const
    {
        return (cAttributeInterface*)this;
    }
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual int SetName(const char *name,int namelen=-1)
    {
        if ((namelen = m_name.Copy(name,namelen)) < 0)
            return -e_ERROR_COPY;

        return namelen;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual const char *GetName(int &length) const
    {
        length=m_name.GetLength();
        return m_name.GetBuffer();
    }
    /**
     **********************************************************************
     * Function: GetNameLength
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual int GetNameLength() const
    {
        return m_name.GetLength();
    }

    /**
     **********************************************************************
     * Function: GetNextAttribute
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetNextAttribute() const
    {
        return cListItemIs::GetNext();
    }
    /**
     **********************************************************************
     * Function: GetPreviousAttribute
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetPreviousAttribute() const
    {
        return cListItemIs::GetPrevious();
    }

    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 8/24/2003
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        delete this;
        return e_ERROR_NONE;
    }
};

/**
 **********************************************************************
 *  Class: cReferenceAttributeSet
 *
 * Author: $author$
 *   Date: 8/28/2003
 **********************************************************************
 */
class cReferenceAttributeSet
: virtual public cArtifactInterface,
  virtual public cArtifactImplement,
  virtual public cAttributeSetInterface,
  virtual public cAttributeSetImplement,
  virtual public cArtifact
{
public:
    cAttributeSetInterface &m_attribute_set;

    /**
     **********************************************************************
     * Constructor: cReferenceAttributeSet
     *
     *      Author: $author$
     *        Date: 8/28/2003
     **********************************************************************
     */
    cReferenceAttributeSet
    (cAttributeSetInterface &attribute_set,
     cDocumentInterface *parent_document=0,
     cElementInterface *parent_element=0) 
    : cArtifact(parent_document,parent_element),
      m_attribute_set(attribute_set)
    {
    }

    /**
     **********************************************************************
     * Function: GetFirstAttribute
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetFirstAttribute() const
    {
        return m_attribute_set.GetFirstAttribute();
    }
    /**
     **********************************************************************
     * Function: GetLastAttribute
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetLastAttribute() const
    {
        return m_attribute_set.GetLastAttribute();
    }

    /**
     **********************************************************************
     * Function: AddAttribute
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual cAttributeInterface *AddAttribute
    (const char *name="",int namelen=-1,
     const char *text="",int textlen=-1)
    {
        return m_attribute_set.AddAttribute
        (name, namelen, text, textlen);
    }
    /**
     **********************************************************************
     * Function: DeleteAttribute
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual eError DeleteAttribute(cAttributeInterface *attribute)
    {
        return m_attribute_set.DeleteAttribute(attribute);
    }
    /**
     **********************************************************************
     * Function: DeleteAllAttributes
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual eError DeleteAllAttributes()
    {
        return m_attribute_set.DeleteAllAttributes();
    }
};

/**
 **********************************************************************
 *  Class: cAttributeSet
 *
 * Author: $author$
 *   Date: 8/23/2003
 **********************************************************************
 */
class cAttributeSet
: virtual public cArtifactInterface,
  virtual public cArtifactImplement,
  virtual public cAttributeSetInterface,
  virtual public cAttributeSetImplement,
  virtual public cArtifact
{
public:
    cAttributeList m_attribute_list;

    /**
     **********************************************************************
     * Constructor: cAttributeSet
     *
     *      Author: $author$
     *        Date: 8/23/2003
     **********************************************************************
     */
    cAttributeSet
    (cDocumentInterface *parent_document=0,
     cElementInterface *parent_element=0)
    : cArtifact(parent_document,parent_element) 
    {
    }
    /**
     **********************************************************************
     * Function: GetFirstAttribute
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetFirstAttribute() const
    {
        return m_attribute_list.GetFirst();
    }
    /**
     **********************************************************************
     * Function: GetLastAttribute
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetLastAttribute() const
    {
        return m_attribute_list.GetLast();
    }

    /**
     **********************************************************************
     * Function: AddAttribute
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual cAttributeInterface *AddAttribute
    (const char *name="",int namelen=-1,
     const char *text="",int textlen=-1)
    {
        return AddNewAttribute
        (name,namelen,text,textlen);
    }
    /**
     **********************************************************************
     * Function: DeleteAttribute
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError DeleteAttribute(cAttributeInterface *attribute)
    {
        eError error;
        cAttributeItem *item;

        for (item=m_attribute_list.GetFirst(); item; item=item->GetNext())
        {
            if (item->GetAttribute() == attribute)
            {
                m_attribute_list.Delete(item);

                if ((error = attribute->FreeInstance()))
                    return e_ERROR_FREE_INSTANCE;

                return e_ERROR_NONE;
            }
        }
        return e_ERROR_NOT_MEMBER;
    }
    /**
     **********************************************************************
     * Function: DeleteAllAttributes
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError DeleteAllAttributes()
    {
        eError error;

        if (!(error=m_attribute_list.Clear()))
            return error;

        return e_ERROR_CLEAR;
    }

    /**
     **********************************************************************
     * Function: AddNewAttribute
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    cAttribute *AddNewAttribute
    (const char *name="",int namelen=-1,
     const char *text="",int textlen=-1)
    {
        cAttribute *attribute;

        if ((attribute=new cAttribute
            (m_parent_document,m_parent_element,
             name,namelen,text,textlen)))
            m_attribute_list.Add(attribute);

        else SetLastError(e_ERROR_NEW);

        return attribute;
    }
};

/**
 **********************************************************************
 *  Class: cElementItem
 *
 * Author: $author$
 *   Date: 8/23/2003
 **********************************************************************
 */
class cElementItem
: virtual public cElementInterface,
  public cDynamicListItemT<cElementItem>
{
public:
    typedef cDynamicListItemT<cElementItem> cListItemIs;
};

/**
 **********************************************************************
 *  Class: cElementList
 *
 * Author: $author$
 *   Date: 8/23/2003
 **********************************************************************
 */
class cElementList
: public cDynamicListT
  <cElementItem,cElementList>
{
public:
    typedef cDynamicListT
    <cElementItem,cElementList> cIs;

    /**
     **********************************************************************
     * Destructor: ~cElementList
     *
     *     Author: $author$
     *       Date: 8/23/2003
     **********************************************************************
     */
    virtual ~cElementList()
    {
        eError error;

        if (!m_is_static)
        if ((error=Clear()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError Free(cElementItem *item)
    {
        eError error;

        if ((error=item->FreeInstance()))
            return e_ERROR_FREE;

        return e_ERROR_NONE;
    }
};

/**
 **********************************************************************
 *  Class: cReferenceElementSet
 *
 * Author: $author$
 *   Date: 8/28/2003
 **********************************************************************
 */
class cReferenceElementSet
: virtual public cArtifactInterface,
  virtual public cArtifactImplement,
  virtual public cElementSetInterface,
  virtual public cElementSetImplement,
  virtual public cArtifact
{
public:
    cElementSetInterface &m_element_set;

    /**
     **********************************************************************
     * Constructor: cReferenceElementSet
     *
     *      Author: $author$
     *        Date: 8/28/2003
     **********************************************************************
     */
    cReferenceElementSet
    (cElementSetInterface &element_set,
     cDocumentInterface *parent_document=0,
     cElementInterface *parent_element=0) 
    : cArtifact(parent_document,parent_element),
      m_element_set(element_set)
    {
    }

    /**
     **********************************************************************
     * Function: GetFirstElement
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual cElementInterface *GetFirstElement() const
    {
        return m_element_set.GetFirstElement();
    }
    /**
     **********************************************************************
     * Function: GetLastElement
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual cElementInterface *GetLastElement() const
    {
        return m_element_set.GetLastElement();
    }

    /**
     **********************************************************************
     * Function: CreateElement
     *
     *   Author: $author$
     *     Date: 8/29/2003
     **********************************************************************
     */
    virtual cElementInterface *CreateElement
    (const char *text="",int textlen=-1,
     unsigned type=cAtom::e_TYPE_PARENT_ELEMENT)
    {
        return m_element_set.CreateElement(text, textlen, type);
    }
    /**
     **********************************************************************
     * Function: PushElement
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual cElementInterface *PushElement
    (const char *text="",int textlen=-1,
     unsigned type=cAtom::e_TYPE_PARENT_ELEMENT)
    {
        return m_element_set.PushElement(text, textlen, type);
    }
    /**
     **********************************************************************
     * Function: AddElement
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual cElementInterface *AddElement
    (const char *text="",int textlen=-1,
     unsigned type=cAtom::e_TYPE_PARENT_ELEMENT)
    {
        return m_element_set.AddElement(text, textlen, type);
    }
    /**
     **********************************************************************
     * Function: PushReferenceElement
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual cElementInterface *PushReferenceElement
    (cElementInterface &element)
    {
        return m_element_set.PushReferenceElement(element);
    }
    /**
     **********************************************************************
     * Function: AddReferenceElement
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual cElementInterface *AddReferenceElement
    (cElementInterface &element)
    {
        return m_element_set.AddReferenceElement(element);
    }
    /**
     **********************************************************************
     * Function: DeleteElement
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual eError DeleteElement(cElementInterface *element)
    {
        return m_element_set.DeleteElement(element);
    }
    /**
     **********************************************************************
     * Function: DeleteAllElements
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual eError DeleteAllElements()
    {
        return m_element_set.DeleteAllElements();
    }
};

class cElement;

/**
 **********************************************************************
 *  Class: cElementSet
 *
 * Author: $author$
 *   Date: 8/23/2003
 **********************************************************************
 */
class cElementSet
: virtual public cArtifactInterface,
  virtual public cArtifactImplement,
  virtual public cElementSetInterface,
  virtual public cElementSetImplement,
  virtual public cArtifact,
  public cErrorInstance
{
public:
    cElementList m_element_list;

    /**
     **********************************************************************
     * Constructor: cElementSet
     *
     *      Author: $author$
     *        Date: 8/23/2003
     **********************************************************************
     */
    cElementSet
    (cDocumentInterface *parent_document=0,
     cElementInterface *parent_element=0)
    : cArtifact(parent_document, parent_element) 
    {
    }

    /**
     **********************************************************************
     * Function: GetFirstElement
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual cElementInterface *GetFirstElement() const
    {
        return m_element_list.GetFirst();
    }
    /**
     **********************************************************************
     * Function: GetLastElement
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual cElementInterface *GetLastElement() const
    {
        return m_element_list.GetLast();
    }

    /**
     **********************************************************************
     * Function: CreateElement
     *
     *   Author: $author$
     *     Date: 8/29/2003
     **********************************************************************
     */
    virtual cElementInterface *CreateElement
    (const char *text="",int textlen=-1,
     unsigned type=cAtom::e_TYPE_PARENT_ELEMENT);
    /**
     **********************************************************************
     * Function: PushElement
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual cElementInterface *PushElement
    (const char *text="",int textlen=-1,
     unsigned type=cAtom::e_TYPE_PARENT_ELEMENT);
    /**
     **********************************************************************
     * Function: AddElement
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual cElementInterface *AddElement
    (const char *text="",int textlen=-1,
     unsigned type=cAtom::e_TYPE_PARENT_ELEMENT);
    /**
     **********************************************************************
     * Function: PushReferenceElement
     *
     *   Author: $author$
     *     Date: 2/15/2004
     **********************************************************************
     */
    virtual cElementInterface *PushReferenceElement(cElementInterface &element);
    /**
     **********************************************************************
     * Function: AddReferenceElement
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual cElementInterface *AddReferenceElement(cElementInterface &element);
    /**
     **********************************************************************
     * Function: DeleteElement
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError DeleteElement(cElementInterface *element)
    {
        eError error;
        cElementItem *item;

        for (item=m_element_list.GetFirst(); item; item=item->GetNext())
        {
            if (item->GetElement() == element)
            {
                m_element_list.Delete(item);

                if ((error = element->FreeInstance()))
                    return e_ERROR_FREE_INSTANCE;

                return e_ERROR_NONE;
            }
        }
        return e_ERROR_NOT_MEMBER;
    }
    /**
     **********************************************************************
     * Function: DeleteAllElements
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual eError DeleteAllElements()
    {
        eError error;

        if ((error=m_element_list.Clear()))
            return e_ERROR_CLEAR;

        return e_ERROR_NONE;
    }
};

/**
 **********************************************************************
 *  Class: cReferenceElement
 *
 * Author: $author$
 *   Date: 8/28/2003
 **********************************************************************
 */
class cReferenceElement
: virtual public cArtifactInterface,
  virtual public cArtifactImplement,
  virtual public cAtomInterface,
  virtual public cAtomImplement,
  virtual public cAttributeSetInterface,
  virtual public cAttributeSetImplement,
  virtual public cElementSetInterface,
  virtual public cElementSetImplement,
  virtual public cElementInterface,
  virtual public cElementImplement,
  virtual public cArtifact,
  public cErrorInstance,
  public cElementItem,
  public cReferenceElementSet,
  public cReferenceAttributeSet,
  public cReferenceAtom
{
public:
    typedef cReferenceAtom cIs;

    cElementInterface &m_element;

    /**
     **********************************************************************
     * Constructor: cReferenceElement
     *
     *      Author: $author$
     *        Date: 8/28/2003
     **********************************************************************
     */
    cReferenceElement
    (cElementInterface &element,
     cDocumentInterface *parent_document=0,
     cElementInterface *parent_element=0) 
    : cArtifact(parent_document,parent_element),
      cReferenceElementSet(element),
      cReferenceAttributeSet(element),
      cIs(element),
      m_element(element)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cReferenceElement
     *
     *     Author: $author$
     *       Date: 8/28/2003
     **********************************************************************
     */
    ~cReferenceElement()
    {
        eError error;

        if ((error = m_element.FreeInstance()))
            throw(error=e_ERROR_FREE_INSTANCE);
    }

    /**
     **********************************************************************
     * Function: GetElement
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual cElementInterface *GetElement() const
    {
        return (cElementInterface*)this;
    }

    /**
     **********************************************************************
     * Function: GetNextElement
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual cElementInterface *GetNextElement() const
    {
        return cListItemIs::GetNext();
    }
    /**
     **********************************************************************
     * Function: GetPreviousElement
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual cElementInterface *GetPreviousElement() const
    {
        return cListItemIs::GetPrevious();
    }

    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 8/28/2003
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        delete this;
        return e_ERROR_NONE;
    }
};

/**
 **********************************************************************
 *  Class: cElement
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cElement
: virtual public cArtifactInterface,
  virtual public cArtifactImplement,
  virtual public cAtomInterface,
  virtual public cAtomImplement,
  virtual public cAttributeSetInterface,
  virtual public cAttributeSetImplement,
  virtual public cElementSetInterface,
  virtual public cElementSetImplement,
  virtual public cElementInterface,
  virtual public cElementImplement,
  virtual public cArtifact,
  public cElementItem,
  public cElementSet,
  public cAttributeSet,
  public cAtom
{
public:
    /**
     **********************************************************************
     * Constructor: cElement
     *
     *      Author: $author$
     *        Date: 8/22/2003
     **********************************************************************
     */
    cElement
    (unsigned type=e_TYPE_PARENT_ELEMENT,
     const char *text=0,int textlen=-1,
     cDocumentInterface *parent_document=0,
     cElementInterface *parent_element=0)
    : cArtifact(parent_document,parent_element),
      cElementSet(parent_document, parent_element),
      cAttributeSet(parent_document, parent_element),
      cAtom
      (type, text, textlen, 
       parent_document, parent_element)
    {
    }
    /**
     **********************************************************************
     * Function: GetElement
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual cElementInterface *GetElement() const
    {
        return (cElementInterface *)this;
    }
    /**
     **********************************************************************
     * Function: GetNextElement
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual cElementInterface *GetNextElement() const
    {
        return cListItemIs::GetNext();
    }
    /**
     **********************************************************************
     * Function: GetPreviousElement
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual cElementInterface *GetPreviousElement() const
    {
        return cListItemIs::GetPrevious();
    }

    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        delete this;
        return e_ERROR_NONE;
    }
};

/**
 **********************************************************************
 *  Class: cDocument
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cDocument
: virtual public cArtifactInterface,
  virtual public cArtifactImplement,
  virtual public cElementSetInterface,
  virtual public cElementSetImplement,
  virtual public cDocumentInterface,
  virtual public cDocumentImplement,
  virtual public cArtifact,
  public cElementSet
{
public:
    typedef cElementSet cIs;

    /**
     **********************************************************************
     * Constructor: cDocument
     *
     *      Author: $author$
     *        Date: 8/22/2003
     **********************************************************************
     */
    cDocument()
    : cIs(this)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDocument
     *
     *     Author: $author$
     *       Date: 8/22/2003
     **********************************************************************
     */
    virtual ~cDocument()
    {
    }
};

#endif
