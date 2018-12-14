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
 *   File: xalantest.cxx
 *
 * Author: $author$
 *   Date: 1/27/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "cxalandocumentfactory.hxx"
#include "cxalancharstreamxsltresulttarget.hxx"
#include "cxalancharstreamxsltinputsource.hxx"
#include "cxalantransformer.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Class: cXalanTest
 *
 * Author: $author$
 *   Date: 1/27/2004
 **********************************************************************
 */
class cXalanTest
: public cMain
{
public:
    typedef cMain cIs;

    /**
     **********************************************************************
     * Constructor: cXalanTest
     *
     *      Author: $author$
     *        Date: 1/27/2004
     **********************************************************************
     */
    cXalanTest() 
    : cMain() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXalanTest
     *
     *     Author: $author$
     *       Date: 1/27/2004
     **********************************************************************
     */
    virtual ~cXalanTest()
    {
    }

    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 1/27/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        const char *document_filename="..\\xml\\hi.xsl";
        const char *template_filename="..\\xml\\hi.xsl";
        const char *error_string="";

        cCharFile document_fin(document_filename);
        cCharFile template_fin(template_filename);

        nsXalan::XalanDocument *xd = 0;
        cXalanTransformer xt;
        eError error;

        m_out.Write("Content-type: text/plain\n\n");

        if (!(error = xt.Initialize()))
        {
            {
                cXalanCharStreamXSLTInputSource document_csxin(document_fin);
                cXalanCharStreamXSLTInputSource template_csxin(template_fin);
                cXalanCharStreamXSLTResultTarget csxout(m_out);
                cXercesErrorHandler error_handler;
                nsXalan::XercesParserLiaison parser;

                xd = parser.parseXMLStream(template_csxin);

                xt.setErrorHandler(&error_handler);

                nsXalan::XSLTInputSource template_xdxin((nsXalan::XalanNode*)xd);

                if ((error = xt.transform
                    (document_csxin,/*template_xdxin*/"http://localhost/ccl/xml/hi.xsl",csxout)))
                {
                    error_string = xt.getLastError();
                }
            }
            xt.Finalize();
        }
        return 0;
    }
} g_xalan_test;
