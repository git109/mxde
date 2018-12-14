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
 *   File: cdocumentinterface.cxx
 *
 * Author: $author$
 *   Date: 8/23/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "cdocumentinterface.hxx"

/*
 **********************************************************************
 *  Class: cAtomInterface
 *
 * Author: $author$
 *   Date: 8/19/2003
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: cAtomInterface::GetTypeText
 *
 *   Author: $author$
 *     Date: 2/10/2004
 **********************************************************************
 */
const char *cAtomInterface::GetTypeText(int &length) const
{
    unsigned type=GetType();
    const char *text="";

    switch(type)
    {
    case e_TYPE_ATTRIBUTE:
        text = (CDOCUMENTINTERFACE_TYPE_ATTRIBUTE_TEXT);
        break;

    case e_TYPE_PARENT_ELEMENT:
        text =(CDOCUMENTINTERFACE_TYPE_PARENT_ELEMENT_TEXT);
        break;

    case e_TYPE_TEXT_ELEMENT:
        text =(CDOCUMENTINTERFACE_TYPE_TEXT_ELEMENT_TEXT);
        break;

    case e_TYPE_COMMENT_ELEMENT:
        text = (CDOCUMENTINTERFACE_TYPE_COMMENT_ELEMENT_TEXT);
        break;
    }

    length = strlen(text);
    return text;
}

/**
 **********************************************************************
 * Function: cAtomInterface::PutTypeTextToStream
 *
 *   Author: $author$
 *     Date: 12/31/2003
 **********************************************************************
 */
int cAtomInterface::PutTypeTextToStream(cCharStream &stream) const
{
    unsigned type=GetType();

    switch(type)
    {
    case e_TYPE_ATTRIBUTE:
        return stream.Write(CDOCUMENTINTERFACE_TYPE_ATTRIBUTE_TEXT);

    case e_TYPE_PARENT_ELEMENT:
        return stream.Write(CDOCUMENTINTERFACE_TYPE_PARENT_ELEMENT_TEXT);

    case e_TYPE_TEXT_ELEMENT:
        return stream.Write(CDOCUMENTINTERFACE_TYPE_TEXT_ELEMENT_TEXT);

    case e_TYPE_COMMENT_ELEMENT:
        return stream.Write(CDOCUMENTINTERFACE_TYPE_COMMENT_ELEMENT_TEXT);
    }
    return 0;
}

/*
 **********************************************************************
 *  Class: cAttributeSetInterface
 *
 * Author: $author$
 *   Date: 8/23/2003
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: cAttributeSetInterface::GetFirstAttributeByNameAndValue
 *
 *   Author: $author$
 *     Date: 8/19/2003
 **********************************************************************
 */
cAttributeInterface *cAttributeSetInterface::GetFirstAttributeByNameAndValue
(const char *name, const char *value) const
{
    const char *atvalue;
    cAttributeInterface *at;

    if ((at = GetFirstAttributeByName(name)))
    do
    {
        if ((atvalue = at->GetText()))
        if (!strcmp(atvalue, value))
            return at;
    }
    while((at = at->GetNextAttributeByName(name)));

    return 0;
}

/*
 **********************************************************************
 *  Class: cElementSetInterface
 *
 * Author: $author$
 *   Date: 8/23/2003
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: cElementSetInterface::AddElementCopy
 *
 *   Author: $author$
 *     Date: 2/6/2004
 **********************************************************************
 */
cElementInterface *cElementSetInterface::AddElementCopy
(cElementInterface &element,
 bool exclude_attributes,
 bool exclude_child_elements)
{
    cAttributeInterface *attr;
    cElementInterface *copy;
    cElementInterface *child;
    const char *text;
    int textlen;

    text = element.GetText(textlen);

    if ((copy = AddElement
        (text, textlen, element.GetType())))
    {
        if (!exclude_attributes)
        if ((attr = element.GetFirstAttribute()))
        do
        {
            copy->AddAttribute
            (attr->GetName(), attr->GetNameLength(), 
             attr->GetText(), attr->GetTextLength());
        }
        while ((attr = attr->GetNextAttribute()));

        if (!exclude_child_elements)
        if ((child = element.GetFirstElement()))
        do
        {
            copy->AddElementCopy
            (*child, exclude_attributes, exclude_child_elements);
        }
        while ((child = child->GetNextElement()));
    }
    return copy;
}

/**
 **********************************************************************
 * Function: cElementSetInterface::ReferenceElements
 *
 *   Author: $author$
 *     Date: 8/29/2003
 **********************************************************************
 */
int cElementSetInterface::ReferenceElements(cElementSetInterface &element_set)
{
    cElementInterface *element;
    int count = 0;

    if ((element=element_set.GetFirstElement()))
    do
    {
        const char *text=element->GetText();

        if (!AddReferenceElement(*element))
            return -e_ERROR_FAILED;

        ++count;
    }
    while ((element=element->GetNextElement()));

    return count;
}

/**
 **********************************************************************
 * Function: cElementSetInterface::GetFirstElementByType
 *
 *   Author: $author$
 *     Date: 1/1/2004
 **********************************************************************
 */
cElementInterface *cElementSetInterface::GetFirstElementByType(unsigned type) const
{
    cElementInterface *e;
    const char *etext;

    if ((e = GetFirstElement()))
    {
        etext = e->GetText();

        if (0 != (type & e->GetType()))
            return e;

        return e->GetNextElementByType(type);
    }
    return 0;
}
/**
 **********************************************************************
 * Function: cElementSetInterface::GetLastElementByType
 *
 *   Author: $author$
 *     Date: 1/1/2004
 **********************************************************************
 */
cElementInterface *cElementSetInterface::GetLastElementByType(unsigned type) const
{
    cElementInterface *e;

    if ((e = GetLastElement()))
    {
        if (0 != (type & e->GetType()))
            return e;

        return e->GetPreviousElementByType(type);
    }
    return 0;
}

/**
 **********************************************************************
 * Function: cElementSetInterface::GetFirstElementByText
 *
 *   Author: $author$
 *     Date: 12/31/2003
 **********************************************************************
 */
cElementInterface *cElementSetInterface::GetFirstElementByText
(const char *text, int textlen) const
{
    int etextlen;
    const char *etext;
    cElementInterface *e;

    if ((e = GetFirstElement()))
    {
        if (textlen < 0)
            textlen = strlen(text);
    
        if ((etext = e->GetText(etextlen)))
        if (etextlen == textlen)
        if (!strncmp(etext, text, textlen))
            return e;
    
        return e->GetNextElementByText(text, textlen);
    }
    return 0;
}
/**
 **********************************************************************
 * Function: cElementSetInterface::GetLastElementByText
 *
 *   Author: $author$
 *     Date: 12/31/2003
 **********************************************************************
 */
cElementInterface *cElementSetInterface::GetLastElementByText
(const char *text, int textlen) const
{
    int etextlen;
    const char *etext;
    cElementInterface *e;

    if ((e = GetLastElement()))
    {
        if (textlen < 0)
            textlen = strlen(text);
    
        if ((etext = e->GetText(etextlen)))
        if (etextlen == textlen)
        if (!strncmp(etext, text, textlen))
            return e;
    
        return e->GetPreviousElementByText(text, textlen);
    }
    return 0;
}

/**
 **********************************************************************
 * Function: cElementSetInterface::GetFirstElementByTypeAndText
 *
 *   Author: $author$
 *     Date: 1/1/2004
 **********************************************************************
 */
cElementInterface *cElementSetInterface::GetFirstElementByTypeAndText
(unsigned type, const char *text, int textlen) const
{
    int etextlen;
    const char *etext;
    cElementInterface *e;

    if ((e = GetFirstElementByType(type)))
    {
        if (textlen < 0)
            textlen = strlen(text);
    
        if ((etext = e->GetText(etextlen)))
        if (etextlen == textlen)
        if (!strncmp(etext, text, textlen))
            return e;
    
        return e->GetNextElementByTypeAndText(type, text, textlen);
    }
    return 0;
}
/**
 **********************************************************************
 * Function: cElementSetInterface::GetLastElementByTypeAndText
 *
 *   Author: $author$
 *     Date: 12/31/2003
 **********************************************************************
 */
cElementInterface *cElementSetInterface::GetLastElementByTypeAndText
(unsigned type, const char *text, int textlen) const
{
    int etextlen;
    const char *etext;
    cElementInterface *e;

    if ((e = GetLastElementByType(type)))
    {
        if (textlen < 0)
            textlen = strlen(text);
    
        if ((etext = e->GetText(etextlen)))
        if (etextlen == textlen)
        if (!strncmp(etext, text, textlen))
            return e;
    
        return e->GetPreviousElementByTypeAndText(type, text, textlen);
    }
    return 0;
}

/**
 **********************************************************************
 * Function: cElementSetInterface::GetElementByAttributeValue
 *
 *   Author: $author$
 *     Date: 8/30/2003
 **********************************************************************
 */
 cElementInterface *cElementSetInterface::GetElementByAttributeValue
 (const char *name, const char *value) const
{
    cElementInterface *element;
    cElementInterface *atelement;
    cAttributeInterface *at;

    if ((element=GetFirstElement()))
    do
    {
        switch(element->GetType())
        {
        case cAtomInterface::e_TYPE_PARENT_ELEMENT:
            if ((at = element->GetFirstAttributeByNameAndValue(name,value)))
                return element;

            if ((atelement = element->GetElementByAttributeValue(name,value)))
                return atelement;
            break;
        }
    }
    while ((element=element->GetNextElement()));

    return 0;
}

/**
 **********************************************************************
 * Function: cElementSetInterface::PutTextToStream
 *
 *   Author: $author$
 *     Date: 8/30/2003
 **********************************************************************
 */
int cElementSetInterface::PutTextToStream
(cCharStream &stream,
 bool exclude_whitespace,
 bool include_attributes) const
{
    cElementInterface *element;
    int count,result=0;

    if ((element=GetFirstElement()))
    do
    {
        switch(element->GetType())
        {
        case cAtomInterface::e_TYPE_PARENT_ELEMENT:
        case cAtomInterface::e_TYPE_TEXT_ELEMENT:
            if ((count = element->PutTextToStream
                (stream,exclude_whitespace,include_attributes)) < 0)
                return count;

            result += count;
            break;
        }
    }
    while ((element=element->GetNextElement()));

    return result;
}

/**
 **********************************************************************
 * Function: cElementSetInterface::PutXMLToStream
 *
 *   Author: $author$
 *     Date: 8/23/2003
 **********************************************************************
 */
int cElementSetInterface::PutXMLToStream
(cCharStream &stream,
 bool exclude_whitespace,
 bool exclude_comments,
 bool exclude_multiple_root_elements) const
{
    cElementInterface *element;
    bool exclude_siblings=false;
    bool include_element=false;
    int count,result=0;

    if ((element=GetFirstElement()))
    do
    {
        switch(element->GetType())
        {
        case cAtomInterface::e_TYPE_PARENT_ELEMENT:
            include_element=true;
            exclude_siblings=exclude_multiple_root_elements;
            break;

        case cAtomInterface::e_TYPE_TEXT_ELEMENT:
            include_element=!exclude_multiple_root_elements;
            break;

        case cAtomInterface::e_TYPE_COMMENT_ELEMENT:
            include_element=!exclude_multiple_root_elements;
            break;

        default:
            include_element=false;
        }

        if (include_element)
        {
            if ((count = element->PutXMLToStream
                (stream,exclude_whitespace,exclude_comments)) < 0)
                break;

            result += count;

            if (exclude_siblings)
               break;
        }
    }
    while ((element=element->GetNextElement()));

    return result;
}

/*
 **********************************************************************
 *  Class: cElementInterface
 *
 * Author: $author$
 *   Date: 8/23/2003
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: cElementInterface::GetNextElementByType
 *
 *   Author: $author$
 *     Date: 1/1/2004
 **********************************************************************
 */
cElementInterface *cElementInterface::GetNextElementByType(unsigned type) const
{
    cElementInterface *e;
    const char *etext;
    unsigned etype;

    if ((e = GetNextElement()))
    {
        do
        {
            etext = e->GetText();

            if (0 != (type & (etype = e->GetType())))
                return e;
        }
        while ((e = e->GetNextElement()));
    }
    return 0;
}
/**
 **********************************************************************
 * Function: cElementInterface::GetPreviousElementByType
 *
 *   Author: $author$
 *     Date: 1/1/2004
 **********************************************************************
 */
cElementInterface *cElementInterface::GetPreviousElementByType(unsigned type) const
{
    cElementInterface *e;

    if ((e = GetPreviousElement()))
    {
        do
        {
            if (0 != (type & e->GetType()))
                return e;
        }
        while ((e = e->GetPreviousElement()));
    }
    return 0;
}

/**
 **********************************************************************
 * Function: cElementInterface::GetNextElementByText
 *
 *   Author: $author$
 *     Date: 1/1/2004
 **********************************************************************
 */
cElementInterface *cElementInterface::GetNextElementByText
(const char *text, int textlen) const
{
    int etextlen;
    const char *etext;
    cElementInterface *e;

    if ((e = GetNextElement()))
    {
        if (textlen < 0)
            textlen = strlen(text);
    
        do
        {
            if ((etext = e->GetText(etextlen)))
            if (etextlen == textlen)
            if (!strncmp(etext, text, textlen))
                return e;
        }
        while ((e = e->GetNextElement()));
    }
    return 0;
}
/**
 **********************************************************************
 * Function: cElementInterface::GetPreviousElementByText
 *
 *   Author: $author$
 *     Date: 1/1/2004
 **********************************************************************
 */
cElementInterface *cElementInterface::GetPreviousElementByText
(const char *text, int textlen) const
{
    int etextlen;
    const char *etext;
    cElementInterface *e;

    if ((e = GetPreviousElement()))
    {
        if (textlen < 0)
            textlen = strlen(text);
    
        do
        {
            if ((etext = e->GetText(etextlen)))
            if (etextlen == textlen)
            if (!strncmp(etext, text, textlen))
                return e;
        }
        while ((e = e->GetPreviousElement()));
    }
    return 0;
}

/**
 **********************************************************************
 * Function: cElementInterface::GetNextElementByTypeAndText
 *
 *   Author: $author$
 *     Date: 1/1/2004
 **********************************************************************
 */
cElementInterface *cElementInterface::GetNextElementByTypeAndText
(unsigned type, const char *text, int textlen) const
{
    int etextlen;
    const char *etext;
    cElementInterface *e;

    if ((e = GetNextElementByType(type)))
    {
        if (textlen < 0)
            textlen = strlen(text);
    
        do
        {
            if ((etext = e->GetText(etextlen)))
            if (etextlen == textlen)
            if (!strncmp(etext, text, textlen))
                return e;
        }
        while ((e = e->GetNextElementByType(type)));
    }
    return 0;
}
/**
 **********************************************************************
 * Function: cElementInterface::GetPreviousElementByTypeAndText
 *
 *   Author: $author$
 *     Date: 1/1/2004
 **********************************************************************
 */
cElementInterface *cElementInterface::GetPreviousElementByTypeAndText
(unsigned type, const char *text, int textlen) const
{
    int etextlen;
    const char *etext;
    cElementInterface *e;

    if ((e = GetPreviousElementByType(type)))
    {
        if (textlen < 0)
            textlen = strlen(text);
    
        do
        {
            if ((etext = e->GetText(etextlen)))
            if (etextlen == textlen)
            if (!strncmp(etext, text, textlen))
                return e;
        }
        while ((e = e->GetPreviousElementByType(type)));
    }
    return 0;
}

/**
 **********************************************************************
 *    Function: cElementInterface::PutTextToStream
 *
 *      Author: $author$
 *        Date: 8/30/2003
 **********************************************************************
 */
int cElementInterface::PutTextToStream
(cCharStream &stream,
 bool exclude_whitespace,
 bool include_attributes) const
{
    int textlen;
    const char *text;
    cElementInterface *element;
    cAttributeInterface *attribute;
    unsigned type;
    int count, result=0;

    switch(type=GetType())
    {
    case e_TYPE_TEXT_ELEMENT:
        if ((text = GetText(textlen)))
        {
            if ((count = stream.Write(text, textlen)) < 0)
                return count;

            result += count;
        }
        break;

    case e_TYPE_PARENT_ELEMENT:
        if (include_attributes)
        if ((attribute=GetFirstAttribute()))
        do
        {
            if ((text = attribute->GetText(textlen)))
            if ((count = stream.Write(text, textlen)) < 0)
                return count;

            result += count;
        }
        while(attribute=attribute->GetNextAttribute());

        if ((element=GetFirstElement()))
        do
        {
            switch(type=element->GetType())
            {
            case e_TYPE_PARENT_ELEMENT:
            case e_TYPE_TEXT_ELEMENT:
                if ((count=element->PutTextToStream
                    (stream,exclude_whitespace,include_attributes)) < 0)
                    return count;

                result += count;
                break;
            }
        }
        while(element=element->GetNextElement());
        break;
    }

    return result;
}

/**
 **********************************************************************
 *    Function: cElementInterface::PutXMLToStream
 *
 *      Author: $author$
 *        Date: 8/23/2003
 **********************************************************************
 */
int cElementInterface::PutXMLToStream
(cCharStream &stream,
 bool exclude_whitespace,
 bool exclude_comments) const
{
    cElementInterface *element;
    cAttributeInterface *attribute;
    unsigned type;
    int count, result=0;

    switch(type=GetType())
    {
    case e_TYPE_COMMENT_ELEMENT:
        if (!exclude_comments)
        if ((count = stream.WriteL
            ("<!--",GetText(),"-->\n",0)) < 0)
            return count;
        else result += count;
        break;

    case e_TYPE_PARENT_ELEMENT:
        if ((count = stream.WriteL("<",GetText(),0)) < 0)
            return count;

        result += count;

        if ((attribute=GetFirstAttribute()))
        do
        {
            if ((count = stream.WriteL
                ("\n ",attribute->GetName(),
                 "=\"",attribute->GetText(),"\"",0)) < 0)
                return count;

            result += count;
        }
        while(attribute=attribute->GetNextAttribute());

        if ((element=GetFirstElement()))
        {
            if ((count = stream.Put('>')) < 0)
                return count;

            result += count;

            if ((type=element->GetType())!=e_TYPE_TEXT_ELEMENT)
            if ((count=stream.Put('\n')) < 0)
                return count;
            else result += count;

            do
            {
                if ((count=element->PutXMLToStream
                    (stream,exclude_whitespace,exclude_comments)) < 0)
                    return count;

                result += count;
            }
            while(element=element->GetNextElement());

            if ((count=stream.WriteL("</",GetText(),0)) < 0)
                return count;
        }
        else if ((count = stream.Put('/')) < 0)
                return count;

        result += count;

        if ((count=stream.Put('>')) < 0)
            return count;

        result += count;
        break;

    case e_TYPE_TEXT_ELEMENT:
        if ((count=stream.Write(GetText())) < 0)
            return count;
        result += count;
        break;
    }

    return result;
}


/*
 **********************************************************************
 *  Class: cDocumentInterface
 *
 * Author: $author$
 *   Date: 8/23/2003
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: cDocumentInterface::
 *
 *      Author: $author$
 *        Date: 8/23/2003
 **********************************************************************
 */
