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
 *   File: xalan.cxx
 *
 * Author: $author$
 *   Date: 11/2/2003
 *
 *    $Id$
 **********************************************************************
 */

#include <iostream>
#include <strstream>
#include <fstream>

#include "cxalandocumentfactory.hxx"
#include "cxalanvariableset.hxx"
#include "cxalanfunction.hxx"
#include "cxalancharstreamxsltresulttarget.hxx"
#include "cxalancharstreamxsltinputsource.hxx"
#include "cxalantransformer.hxx"
#include "cxalantransformerinitializer.hxx"
#include "cxerceserrorhandler.hxx"
#include "cxercesxmlchbuffer.hxx"
#include "ccharbuffer.hxx"
#include "ccharfile.hxx"
#include "ccgimain.hxx"

/**
 **********************************************************************
 *  Class: cXalanMain
 *
 * Author: $author$
 *   Date: 11/2/2003
 **********************************************************************
 */
class cXalanMain
: public cCGIMain
{
public:
    typedef cCGIMain cIs;

    /**
     **********************************************************************
     * Constructor: cXalanMain
     *
     *      Author: $author$
     *        Date: 11/2/2003
     **********************************************************************
     */
    cXalanMain() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXalanMain
     *
     *     Author: $author$
     *       Date: 11/2/2003
     **********************************************************************
     */
    virtual ~cXalanMain()
    {
    }

    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 11/2/2003
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
        const char *d="<Hi/>";
        const char *t="<By/>";
        std::istrstream in1(d);
        std::istrstream in2(t);
        cCharBuffer bin(d);
        cCharBuffer bout;
        cCharFile fin("/source/ccl/xml/hi.xsl");
        cCharFile fout(stdout);
        cXercesXMLChBuffer xbuffer("file://source/ccl/xml/hi.xsl");
        XSLTInputSource in(&in1);
        XalanCompiledStylesheet *ss;
        cXalanCharStreamXSLTInputSource xin(bin);
        cXalanCharStreamXSLTResultTarget xout(fout);
        //cXalanInitializerInterface *initializer;
        XercesParserLiaison parser;
        XalanDocument *xd = 0;
        XalanElement *xe = 0;
        cXalanVariableSet xvs;
        cXalanDocumentFactory xdf(parser);

        cXalanFunction xf("Hi","()",&xdf,&xvs);
        cXalanFunctionNodeSet xfns("node-set","(...)",&xdf,&xvs);
        cXalanFunctionGetVariable xfgv("get-variable","(string,...)",&xdf,&xvs);

        cXalanTransformer tx;
        cXercesErrorHandler error_handler;
        eError error;
        const char *error_string;

        //if ((initializer = initializer->GetInstance()))
        if (!(error = tx.Initialize()))
        {
            tx.setErrorHandler(&error_handler);

            xd = parser.parseXMLStream(xin);
            //xd = xdf.GetXalanDocument();

            XSLTInputSource din((XalanNode*)xd);

            //in.setNode((XalanNode*)xd);
            din.setSystemId(xbuffer.GetBuffer());
/*
            if ((xd = xdf.GetXalanDocument()))
            if ((xe = xd->createElement(XalanDOMString("Hello"))))
                xvs.Set("Hi", (XalanNode*)xe);
*/
/*
            tx.installExternalFunction(XalanDOMString("http://XSLT-Application-Extensions"),XalanDOMString("hi"),xf);
            tx.installExternalFunction(XalanDOMString("http://XSLT-Application-Extensions"),XalanDOMString("node-set"),xfns);
            tx.installExternalFunction(XalanDOMString("http://XSLT-Application-Extensions"),XalanDOMString("get-variable"),xfgv);
*/
            /*if ((error = tx.compileStylesheet(in, ss)))
                error_string = tx.getLastError();
            else */if ((error = tx.transform(din, /*ss*/"/source/ccl/xml/hi.xsl", xout)))
                error_string = tx.getLastError();
            tx.Finalize();
            //initializer->FreeInstance();
        }

        return 0;
    }
} g_xalan_main;
