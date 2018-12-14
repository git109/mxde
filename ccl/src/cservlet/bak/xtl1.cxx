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
 *   File: xtl.cxx
 *
 * Author: $author$
 *   Date: 12/13/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "cdocumenttemplatecgi.hxx"
#include "cdomtransformer.hxx"

cDefaultDOMElementProcessor g_processor;
cString g_namespace_xtl("XML-Transform-Language");

/**
 **********************************************************************
 *  Class: cDOMXTLTextProcessor
 *
 * Author: $author$
 *   Date: 12/15/2004
 **********************************************************************
 */
class cDOMXTLTextProcessor
: public cDOMTextProcessor
{
public:
    typedef cDOMTextProcessor cIs;

    /**
     **********************************************************************
     * Constructor: cDOMXTLTextProcessor
     *
     *      Author: $author$
     *        Date: 12/15/2004
     **********************************************************************
     */
    cDOMXTLTextProcessor
    (const cStringInterface &namespace_uri) 
    : cIs(namespace_uri)
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
} g_dom_xtl_text_processor(g_namespace_xtl);

/**
 **********************************************************************
 *  Class: cXTLTransformDOMElementProcessor
 *
 * Author: $author$
 *   Date: 12/14/2004
 **********************************************************************
 */
class cXTLTransformDOMElementProcessor
: public cDOMElementProcessor
{
public:
    typedef cDOMElementProcessor cIs;

    cString m_name_attr_name;

    /**
     **********************************************************************
     * Constructor: cXTLTransformDOMElementProcessor
     *
     *      Author: $author$
     *        Date: 12/14/2004
     **********************************************************************
     */
    cXTLTransformDOMElementProcessor
    (const cStringInterface &namespace_uri, const char *name) 
    : cIs(namespace_uri, name)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/14/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMElementInterface &element,
     cDOMNodeListInterface &parameter) 
    {
        eError error = processor.Process(result, element, parameter);
        return error;
    }
} g_xtl_transform_processor
  (g_namespace_xtl,"transform");

/**
 **********************************************************************
 *  Class: cXTLIfDOMElementProcessor
 *
 * Author: $author$
 *   Date: 12/19/2004
 **********************************************************************
 */
class cXTLIfDOMElementProcessor
: public cDOMElementProcessor
{
public:
    typedef cDOMElementProcessor cIs;

    cString m_name_attr_name;

    /**
     **********************************************************************
     * Constructor: cXTLIfDOMElementProcessor
     *
     *      Author: $author$
     *        Date: 12/19/2004
     **********************************************************************
     */
    cXTLIfDOMElementProcessor
    (const cStringInterface &namespace_uri, const char *name) 
    : cIs(namespace_uri, name)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/19/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMElementInterface &element,
     cDOMNodeListInterface &parameter) 
    {
        eError error = e_ERROR_NONE;
        cDOMNodeFactoryInterface &factory = processor.GetFactory();
        cDOMEventInterface &event = processor.GetEvent();
        cDOMNodeList test(event,factory);
        cDOMElementInterface *test_e,*then_e,*else_e;

        if ((test_e = element.GetFirstElement()))
        if ((then_e = test_e->GetNextElement()))
        if (!(error = processor.ProcessNode
            (test, *test_e, parameter)))
        if (test.GetFirstChild())
            error = processor.ProcessNode
            (result, *then_e, parameter);
        else if ((else_e = then_e->GetNextElement()))
        {
            do
            {
                if ((error = processor.ProcessNode
                    (result, *else_e, parameter)))
                    break;
            }
            while ((else_e = else_e->GetNextElement()));
        }
        return error;
    }
} g_xtl_if_processor
  (g_namespace_xtl,"if");

/**
 **********************************************************************
 *  Class: cXTLTextDOMElementProcessor
 *
 * Author: $author$
 *   Date: 12/20/2004
 **********************************************************************
 */
class cXTLTextDOMElementProcessor
: public cDOMElementProcessor
{
public:
    typedef cDOMElementProcessor cIs;

    cString m_name_attr_name;

    /**
     **********************************************************************
     * Constructor: cXTLTextDOMElementProcessor
     *
     *      Author: $author$
     *        Date: 12/20/2004
     **********************************************************************
     */
    cXTLTextDOMElementProcessor
    (const cStringInterface &namespace_uri, const char *name) 
    : cIs(namespace_uri, name)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/20/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMElementInterface &element,
     cDOMNodeListInterface &parameter) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
} g_xtl_text_processor
  (g_namespace_xtl,"text");

/**
 **********************************************************************
 *  Class: cXTLCGI
 *
 * Author: $author$
 *   Date: 12/13/2004
 **********************************************************************
 */
class cXTLCGI
: public cDocumentTemplateCGI
{
public:
    typedef cDocumentTemplateCGI cIs;

    cDOMTransformer m_transformer;

    /**
     **********************************************************************
     * Constructor: cXTLCGI
     *
     *      Author: $author$
     *        Date: 12/13/2004
     **********************************************************************
     */
    cXTLCGI(const char *name="xtl")
    : cIs(name) 
    {
    }

    /**
     **********************************************************************
     * Function: OnCommand
     *
     *   Author: $author$
     *     Date: 12/13/2004
     **********************************************************************
     */
    virtual int OnCommand() 
    {
        m_error_content_type = m_content_type_none;
        m_output_content_type = m_content_type_none;
        return OnCommandOrCGI();
    }
    /**
     **********************************************************************
     * Function: OnCGI
     *
     *   Author: $author$
     *     Date: 12/13/2004
     **********************************************************************
     */
    virtual int OnCGI() 
    {
        m_error_content_type = m_content_type_html;
        m_output_content_type = m_content_type_text;
        return OnCommandOrCGI();
    }
    /**
     **********************************************************************
     * Function: OnCommandOrCGI
     *
     *   Author: $author$
     *     Date: 12/13/2004
     **********************************************************************
     */
    virtual int OnCommandOrCGI() 
    {
        int result=0;

        SetContentType(m_error_content_type);

        if ((result = OnGetFormParameters()))
            return result;

        if (m_content_type)
            m_output_content_type = m_content_type;

        if (!m_input_filename)
            return OnMissingTemplateFilename();

        result = OnTransform();
        return result;
    }
    /**
     **********************************************************************
     * Function: OnTransform
     *
     *   Author: $author$
     *     Date: 12/13/2004
     **********************************************************************
     */
    virtual int OnTransform() 
    {
        int result=0;
        eError error;

        OutputContentType();

        error = m_transformer.Transform(m_input_filename);
        return result;
    }
} g_xtlcgi;
