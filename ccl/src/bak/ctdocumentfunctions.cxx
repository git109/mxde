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
 *   File: ctdocumentfunctions.cxx
 *
 * Author: $author$
 *   Date: 12/31/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "ctimplement.hxx"

/**
 **********************************************************************
 *  Class: cTFunctionGetAttribute
 *
 * Author: $author$
 *   Date: 12/31/2003
 **********************************************************************
 */
class cTFunctionGetAttribute
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionGetAttribute
     *
     *      Author: $author$
     *        Date: 12/31/2003
     **********************************************************************
     */
    cTFunctionGetAttribute(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        eError error = e_ERROR_NONE;
        cAttributeInterface *attribute;
        cElementInterface *element;
        cArgument *name,*arg;

        if ((element = t.GetElement()))
        if ((name = arglist.GetFirst()))
        if (0 < name->GetLength())
        {
            while ((arg = name->GetNext()))
            {
                if ((element = element->GetFirstParentElementByText
                    (name->GetBuffer(), name->GetLength())))
                    continue;

                return error;
            }

            if ((attribute = element->GetFirstAttributeByName
                (name->GetBuffer(), name->GetLength())))
                result.Write(attribute->GetText(), attribute->GetTextLength());
        }
        return error;
    }
} ct_function_getattribute
  ("get-attribute","get-attribute()");

/**
 **********************************************************************
 *  Class: cTFunctionForEachAttribute
 *
 * Author: $author$
 *   Date: 12/31/2003
 **********************************************************************
 */
class cTFunctionForEachAttribute
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionForEachAttribute
     *
     *      Author: $author$
     *        Date: 12/31/2003
     **********************************************************************
     */
    cTFunctionForEachAttribute(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        eError error = e_ERROR_NONE;
        cAttributeInterface *old_attribute,*attribute;
        cElementInterface *element;
        cArgument *expr,*arg;

        if ((element = t.GetElement()))
        if ((expr = arglist.GetFirst()))
        if (0 < expr->GetLength())
        {
            while ((arg = expr->GetNext()))
            {
                if ((element = element->GetFirstParentElementByText
                    (expr->GetBuffer(), expr->GetLength())))
                    continue;

                return error;
            }

            if ((attribute = element->GetFirstAttribute()))
            {
                old_attribute = t.GetAttribute();

                do
                {
                    t.SetAttribute(attribute);

                    if ((error = t.Expand(result, *expr)))
                        break;

                    expr->Seek(0);
                }
                while ((attribute = attribute->GetNextAttribute()));

                t.SetAttribute(old_attribute);
            }
        }
        return error;
    }
} ct_function_foreachattribute
  ("for-each-attribute","for-each-attribute()");

/**
 **********************************************************************
 *  Class: cTFunctionGetElement
 *
 * Author: $author$
 *   Date: 12/31/2003
 **********************************************************************
 */
class cTFunctionGetElement
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionGetElement
     *
     *      Author: $author$
     *        Date: 12/31/2003
     **********************************************************************
     */
    cTFunctionGetElement(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        eError error = e_ERROR_NONE;
        cElementInterface *element;
        cArgument *arg;

        if ((element = t.GetElement()))
        {
            if ((arg = arglist.GetFirst()))
            if (0 < arg->GetLength())
            do
            {
                if ((element = element->GetFirstParentElementByText
                    (arg->GetBuffer(), arg->GetLength())))
                    continue;

                return error;
            }
            while ((arg = arg->GetNext()));

            element->PutTextToStream(result);
        }
        return error;
    }
} ct_function_getelement
  ("get-element","get-element(tag,...)");

/**
 **********************************************************************
 *  Class: cTFunctionGetElementName
 *
 * Author: $author$
 *   Date: 1/7/2004
 **********************************************************************
 */
class cTFunctionGetElementName
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionGetElementName
     *
     *      Author: $author$
     *        Date: 1/7/2004
     **********************************************************************
     */
    cTFunctionGetElementName(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/7/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        eError error = e_ERROR_NONE;
        cElementInterface *element;
        cArgument *arg;
        const char *text;
        int textlen;

        if ((element = t.GetElement()))
        {
            if ((arg = arglist.GetFirst()))
            if (0 < arg->GetLength())
            do
            {
                if ((element = element->GetFirstElementByText
                    (arg->GetBuffer(), arg->GetLength())))
                    continue;

                return error;
            }
            while ((arg = arg->GetNext()));

            if ((text = element->GetText(textlen)))
            if (0 < textlen)
                result.Write(text, textlen);
        }
        return error;
    }
} ct_function_getelementname
  ("get-element-name","get-element-name(tag,...)"),
  ct_function_getelementtext
  ("get-element-text","get-element-text(tag,...)");

/**
 **********************************************************************
 *  Class: cTFunctionGetElementType
 *
 * Author: $author$
 *   Date: 12/31/2003
 **********************************************************************
 */
class cTFunctionGetElementType
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionGetElementType
     *
     *      Author: $author$
     *        Date: 12/31/2003
     **********************************************************************
     */
    cTFunctionGetElementType(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        eError error = e_ERROR_NONE;
        cElementInterface *element;
        cArgument *arg;

        if ((element = t.GetElement()))
        {
            if ((arg = arglist.GetFirst()))
            if (0 < arg->GetLength())
            do
            {
                if ((element = element->GetFirstElementByText
                    (arg->GetBuffer(), arg->GetLength())))
                    continue;

                return error;
            }
            while ((arg = arg->GetNext()));

            element->PutTypeTextToStream(result);
        }
        return error;
    }
} ct_function_getelementtype
  ("get-element-type","get-element-type(tag,...)");

/**
 **********************************************************************
 *  Class: cTFunctionForEachElement
 *
 * Author: $author$
 *   Date: 12/31/2003
 **********************************************************************
 */
class cTFunctionForEachElement
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionForEachElement
     *
     *      Author: $author$
     *        Date: 12/31/2003
     **********************************************************************
     */
    cTFunctionForEachElement(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }

    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        eError error = e_ERROR_NONE;
        cElementInterface *old_element,*element;
        cArgument *expr,*arg;

        if ((old_element = (element = t.GetElement())))
        if ((expr = arglist.GetFirst()))
        if (0 < expr->GetLength())
        {
            while ((arg = expr->GetNext()))
            {
                if ((element = element->GetFirstParentElementByText
                    (expr->GetBuffer(), expr->GetLength())))
                {
                    expr = arg;
                    continue;
                }
                return error;
            }

            if ((element = element->GetFirstElement()))
            {
                do
                {
                    t.SetElement(element);

                    if ((error = t.Expand(result, *expr)))
                        break;

                    expr->Seek(0);
                }
                while ((element = element->GetNextElement()));

                t.SetElement(old_element);
            }
        }
        return error;
    }
} ct_function_foreachelement
  ("for-each-element","for-each-element(tag,...,(expr))");

/**
 **********************************************************************
 *  Class: cTFunctionForEachElementIs
 *
 * Author: $author$
 *   Date: 12/31/2003
 **********************************************************************
 */
class cTFunctionForEachElementIs
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionForEachElementIs
     *
     *      Author: $author$
     *        Date: 12/31/2003
     **********************************************************************
     */
    cTFunctionForEachElementIs(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }

    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/31/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        eError error = e_ERROR_NONE;
        cElementInterface *old_element,*element;
        cArgument *expr,*tag,*arg;

        if ((old_element = (element = t.GetElement())))
        if ((tag = arglist.GetFirst()))
        if (0 < tag->GetLength())
        if ((expr = tag->GetNext()))
        {
            while ((arg = expr->GetNext()))
            {
                if ((element = element->GetFirstParentElementByText
                    (tag->GetBuffer(), tag->GetLength())))
                {
                    tag = expr;
                    expr = arg;
                    continue;
                }
                return error;
            }

            if ((element = element->GetFirstParentElementByText
                (tag->GetBuffer(), tag->GetLength())))
            {
                do
                {
                    t.SetElement(element);

                    if ((error = t.Expand(result, *expr)))
                        break;

                    expr->Seek(0);
                }
                while ((element = element->GetNextParentElementByText
                       (tag->GetBuffer(), tag->GetLength())));

                t.SetElement(old_element);
            }
        }
        return error;
    }
} ct_function_foreachelementis
  ("for-each-element-is","for-each-element-is(tag,...,(expr))");

/**
 **********************************************************************
 *  Class: cTFunctionWithElementVariable
 *
 * Author: $author$
 *   Date: 1/7/2004
 **********************************************************************
 */
class cTFunctionWithElementVariable
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionWithElementVariable
     *
     *      Author: $author$
     *        Date: 1/7/2004
     **********************************************************************
     */
    cTFunctionWithElementVariable(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/7/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        eError error = e_ERROR_NONE;
        cTInterface::cVariableInterface *variable;
        cElementInterface *old_element,*element;
        cArgument *expr,*arg;
        const char *name;
        int namelen;

        if ((arg = arglist.GetFirst()))
        if ((name = arg->GetBuffer(namelen)))
        if (0 < namelen)
        if ((variable = t.GetVariable(name, namelen)))
        if ((element = variable->GetElement()))
        if ((expr = arg->GetNext()))
        {
            while ((arg = expr->GetNext()))
            {
                if ((name = expr->GetBuffer(namelen)))
                if ((element = element->GetFirstParentElementByText
                    (name, namelen)))
                {
                    expr = arg;
                    continue;
                }
                return error;
            }

            old_element = t.GetElement();

            t.SetElement(element);

            error = t.Expand(result, *expr);

            t.SetElement(old_element);
        }
        return error;
    }
} ct_function_withelementvariable
  ("with-element-variable","with-element-variable(name,tag,...)");

/**
 **********************************************************************
 *  Class: cTFunctionToXMLSource
 *
 * Author: $author$
 *   Date: 1/15/2004
 **********************************************************************
 */
class cTFunctionToXMLSource
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionToXMLSource
     *
     *      Author: $author$
     *        Date: 1/15/2004
     **********************************************************************
     */
    cTFunctionToXMLSource(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/15/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        cArgument *arg;
        const char *text;
        const char *scan;
        int textlen,len;
        char c;

        if ((arg = arglist.GetFirst()))
        do
        {
            if ((text = arg->GetBuffer(textlen)))
            if (0 < textlen)
            {
                for (scan = text; scan < text+textlen; scan++)
                {
                    switch((c = *scan))
                    {
                    case '&':
                        if (0 < (len = scan-text))
                        {
                            result.Write(text, len);
                            result.Write("&amp;");
                        }
                        text = scan+1;
                        textlen -= len+1;
                        break;
                    }
                }

                result.Write(text, textlen);
            }
        }
        while ((arg = arg->GetNext()));
        return e_ERROR_NONE;
    }
} ct_function_toxmlsource
  ("to-xml-source","to-xml-source(string,...)");

