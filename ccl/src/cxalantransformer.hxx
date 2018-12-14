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
 *   File: cxalantransformer.hxx
 *
 * Author: $author$
 *   Date: 11/4/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXALANTRANSFORMER_HXX
#define _CXALANTRANSFORMER_HXX

#include <XercesParserLiaison/XercesParserLiaison.hpp>
#include <XalanTransformer/XalanTransformer.hpp>

#include "cxalancharstreamxsltinputsource.hxx"
#include "cxalantransformerinitializer.hxx"
#include "cxalanvariableset.hxx"
#include "cxalandocumentfactory.hxx"
#include "cxerceserrorhandler.hxx"
#include "cxercesxmlchbuffer.hxx"
#include "ccharbuffer.hxx"
#include "nsxalan.hxx"

/**
 **********************************************************************
 *  Class: cXalanTransformer
 *
 * Author: $author$
 *   Date: 11/4/2003
 **********************************************************************
 */
class cXalanTransformer
: public nsXalan::XalanTransformer
{
public:
    typedef nsXalan::XalanTransformer cIs;

    cXalanTransformerInitializerInterface *m_initializer;
    nsXerces::ErrorHandler *m_old_parser_error_handler;
    nsXerces::ErrorHandler *m_old_error_handler;
    cXercesErrorHandler m_error_handler;
    nsXalan::XercesParserLiaison m_parser_liaison;
    cXalanDocumentFactory m_document_factory;
    cXalanVariableSet m_variable_set;

    /**
     **********************************************************************
     * Constructor: cXalanTransformer
     *
     *      Author: $author$
     *        Date: 11/4/2003
     **********************************************************************
     */
    cXalanTransformer() 
    : m_initializer(0),
      m_old_error_handler(0),
      m_old_parser_error_handler(0),
      m_document_factory(m_parser_liaison)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXalanTransformer
     *
     *     Author: $author$
     *       Date: 11/4/2003
     **********************************************************************
     */
    virtual ~cXalanTransformer()
    {
        eError error;

        if (m_initializer)
        if ((error = Finalize()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 11/9/2003
     **********************************************************************
     */
    virtual eError Initialize()
    {
        if (m_initializer)
            return e_ERROR_ALREADY_INITIALIZED;

        if (!(m_initializer = m_initializer->GetInstance()))
            return e_ERROR_GET_INSTANCE;

        m_old_parser_error_handler = m_parser_liaison.getErrorHandler();
        m_parser_liaison.setErrorHandler(&m_error_handler);

        m_old_error_handler = getErrorHandler();
        setErrorHandler(&m_error_handler);
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 11/9/2003
     **********************************************************************
     */
    virtual eError Finalize()
    {
        eError error;

        if (!m_initializer)
            return e_ERROR_NOT_INITIALIZED;

        m_document_factory.Clear();

        setErrorHandler(m_old_error_handler);
        m_old_error_handler = 0;

        m_parser_liaison.setErrorHandler(m_old_parser_error_handler);
        m_old_parser_error_handler = 0;

        m_parser_liaison.reset();

        error = m_initializer->FreeInstance();
        m_initializer = 0;

        if (error)
            return e_ERROR_FREE_INSTANCE;

        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: Transform
     *
     *   Author: $author$
     *     Date: 12/13/2003
     **********************************************************************
     */
    virtual eError Transform
    (const char *stylesheet_input_filename,
     nsXalan::XSLTResultTarget &output, cCharBuffer *error_message=0)
    {
        nsXalan::XSLTInputSource stylesheet_input(stylesheet_input_filename);

        return Transform
        (stylesheet_input, output, error_message);
    }
    /**
     **********************************************************************
     * Function: Transform
     *
     *   Author: $author$
     *     Date: 12/12/2003
     **********************************************************************
     */
    virtual eError Transform
    (const char *input_filename, 
     const char *stylesheet_input_filename,
     nsXalan::XSLTResultTarget &output, cCharBuffer *error_message=0)
    {
        nsXalan::XSLTInputSource input(input_filename);
        nsXalan::XSLTInputSource stylesheet_input(stylesheet_input_filename);

        return Transform
        (input, stylesheet_input, output, error_message);
    }
    /**
     **********************************************************************
     * Function: Transform
     *
     *   Author: $author$
     *     Date: 12/13/2003
     **********************************************************************
     */
    virtual eError Transform
    (const nsXalan::XSLTInputSource &stylesheet_input,
     nsXalan::XSLTResultTarget &output, cCharBuffer *error_message=0)
    {
        cCharBuffer input_buffer("<document/>");
        cXercesXMLChBuffer xbuffer("document");
        cXalanCharStreamXSLTInputSource input(input_buffer);

        input.setSystemId(xbuffer.GetBuffer());

        return Transform
        (input, stylesheet_input, output, error_message);
    }
    /**
     **********************************************************************
     * Function: Transform
     *
     *   Author: $author$
     *     Date: 12/12/2003
     **********************************************************************
     */
    virtual eError Transform
    (const nsXalan::XSLTInputSource &input, 
     const nsXalan::XSLTInputSource &stylesheet_input,
     nsXalan::XSLTResultTarget &output, cCharBuffer *error_message=0)
    {
        int err;
        const char *error_string;
        nsXalan::XalanCompiledStylesheet *stylesheet;

        try
        {
            if (!(err = compileStylesheet
                (stylesheet_input, stylesheet)))
                err = transform(input, stylesheet, output);

            if (err)
            {
                if (error_message)
                if ((error_string = getLastError()))
                    error_message->Write(error_string);

                return e_ERROR_FAILED;
            }
        }
        catch(cXercesErrorHandler::cException &ex)
        {
            if (error_message)
                ex.ToBuffer(*error_message);

            return e_ERROR_FAILED;
        }

        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: SetParameter
     *
     *   Author: $author$
     *     Date: 7/25/2004
     **********************************************************************
     */
    int SetParameter(const char *name, const char *value)
    {
        int length=-1;
        cCharBuffer buffer;

        if (0 <= (length = buffer.WriteL("'",value,"'",0)))
        if ((value = buffer.GetBuffer(length)))
            length = SetParameterExpression(name, value);

        return length;
    }
    /**
     **********************************************************************
     * Function: SetParameterExpression
     *
     *   Author: $author$
     *     Date: 7/25/2004
     **********************************************************************
     */
    int SetParameterExpression(const char *name, const char *value)
    {
        int length=-1;
        setStylesheetParam(name, value);
        return length;
    }

    /**
     **********************************************************************
     * Function: ParseXalanDocument
     *
     *   Author: $author$
     *     Date: 12/14/2003
     **********************************************************************
     */
    virtual nsXalan::XalanDocument *ParseXalanDocument
    (const char *input_filename, cCharBuffer *error_message=0)
    {
        nsXalan::XSLTInputSource input(input_filename);

        return ParseXalanDocument(input, error_message);
    }
    /**
     **********************************************************************
     * Function: ParseXalanDocument
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    virtual nsXalan::XalanDocument *ParseXalanDocument
    (cCharStream &input_stream, cCharBuffer *error_message=0)
    {
        cXalanCharStreamXSLTInputSource input(input_stream);

        return ParseXalanDocument(input, error_message);
    }
    /**
     **********************************************************************
     * Function: ParseXalanDocument
     *
     *   Author: $author$
     *     Date: 12/14/2003
     **********************************************************************
     */
    virtual nsXalan::XalanDocument *ParseXalanDocument
    (const nsXalan::XSLTInputSource &input, cCharBuffer *error_message=0)
    {
        nsXalan::XalanDocument *xalan_document=0;
        eError error;

        try
        {
            if ((xalan_document = m_parser_liaison.parseXMLStream(input)))
            if ((error = m_document_factory.AddXalanDocument(*xalan_document)))
            {
                m_parser_liaison.destroyDocument(xalan_document);
                xalan_document = 0;
            }
        }
        catch(cXercesErrorHandler::cException &ex)
        {
            if (error_message)
                ex.ToBuffer(*error_message);
        }

        return xalan_document;
    }
    /**
     **********************************************************************
     * Function: GetXalanDocument
     *
     *   Author: $author$
     *     Date: 12/14/2003
     **********************************************************************
     */
    virtual nsXalan::XalanDocument *GetXalanDocument()
    {
        return m_document_factory.GetXalanDocument();
    }
    /**
     **********************************************************************
     * Function: FreeXalanDocument
     *
     *   Author: $author$
     *     Date: 12/14/2003
     **********************************************************************
     */
    virtual eError FreeXalanDocument(nsXalan::XalanDocument &xalan_document)
    {
        return m_document_factory.FreeXalanDocument(xalan_document);
    }

    /**
     **********************************************************************
     * Function: GetDocumentFactory
     *
     *   Author: $author$
     *     Date: 12/23/2003
     **********************************************************************
     */
    virtual cXalanDocumentFactoryInterface &GetDocumentFactory()
    {
        return m_document_factory;
    }

    /**
     **********************************************************************
     * Function: GetVariableSet
     *
     *   Author: $author$
     *     Date: 12/23/2003
     **********************************************************************
     */
    virtual cXalanVariableSetInterface &GetVariableSet()
    {
        return m_variable_set;
    }
};

#endif
