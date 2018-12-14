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

#include "cxtlparser.hxx"
#include "cdocumenttemplatecgi.hxx"
#include "cdomparser.hxx"
#include "cdom.hxx"

cXTLTokenItem* cXTLTokenList::cIs::m_first = 0;
cXTLTokenItem* cXTLTokenList::cIs::m_last = 0;
cXTLTokenList cXTLToken::m_list;

cXTLToken g_output_token("output", XX_OUTPUT);
cXTLToken g_method_token("method", XX_METHOD);
cXTLToken g_include_token("include", XX_INCLUDE);
cXTLToken g_using_token("using", XX_USING);
cXTLToken g_location_token("location", XX_LOCATION);
cXTLToken g_file_token("file", XX_FILE);

cXTLToken g_transform_token("transform", XX_TRANSFORM);
cXTLToken g_template_token("template", XX_TEMPLATE);
cXTLToken g_variable_token("variable", XX_VARIABLE);
cXTLToken g_parameter_token("parameter", XX_PARAMETER);

cXTLToken g_to_token("to", XX_TO);
cXTLToken g_with_token("with", XX_WITH);

cXTLToken g_apply_token("apply", XX_APPLY);
cXTLToken g_if_token("if", XX_IF);
cXTLToken g_then_token("then", XX_THEN);
cXTLToken g_else_token("else", XX_ELSE);
cXTLToken g_elseif_token("else-if", XX_ELSE_IF);
cXTLToken g_do_token("do", XX_DO);
cXTLToken g_is_token("is", XX_IS);
cXTLToken g_while_token("while", XX_WHILE);
cXTLToken g_until_token("until", XX_UNTIL);
cXTLToken g_repeat_token("repeat", XX_REPEAT);
cXTLToken g_foreach_token("for-each", XX_FOR_EACH);
cXTLToken g_switch_token("switch", XX_SWITCH);
cXTLToken g_case_token("case", XX_CASE);
cXTLToken g_default_token("default", XX_DEFAULT);

cXTLToken g_match_token("match", XX_MATCH);
cXTLToken g_name_token("name", XX_NAME);
cXTLToken g_select_token("select", XX_SELECT);
cXTLToken g_test_token("test", XX_TEST);

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

    cContentStream m_content_stream;

    cString m_namespace_uri, 
            m_variable_namespace_uri,
            m_expression_namespace_uri;

    cDOMParser m_template_dom_parser;
    cXTLParser m_template_parser;

    /**
     **********************************************************************
     * Constructor: cXTLCGI
     *
     *      Author: $author$
     *        Date: 12/13/2004
     **********************************************************************
     */
    cXTLCGI
    (const char *name="xtl",
     const char *namespace_uri="XML-Transform-Language",
     const char *variable_namespace_uri="XML-Transform-Variable",
     const char *expression_namespace_uri="XML-Transform-Expression")
    : cIs(name),
      m_content_stream(*this),

      m_namespace_uri(namespace_uri),
      m_variable_namespace_uri(variable_namespace_uri),
      m_expression_namespace_uri(expression_namespace_uri),

      m_template_parser
      (m_err,
       m_template_dom_parser,
       m_template_dom_parser.GetNodeList(),
       m_template_dom_parser.GetNamespace(m_namespace_uri),
       m_template_dom_parser.GetNamespace(m_variable_namespace_uri))
    {
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

        if (!(error = m_template_dom_parser
            .ParseFile(m_input_filename)))
        {
            m_template_parser.Init();
            error = m_template_parser.yyparse();
            m_template_parser.Final();
        }
        return result;
    }
} g_xtlcgi;
