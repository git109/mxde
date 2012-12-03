/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cxslmain.hxx
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
#ifndef _CXSLMAIN_HXX
#define _CXSLMAIN_HXX

#include "cargmain.hxx"
#include "cxmlreaderinterface.hxx"
#include "cxsltransformerinterface.hxx"

#define DEFAULT_XSL_FILENAME "xsl.xsl"
#define DEFAULT_XML_FILENAME "xsl.xml"

/**
 **********************************************************************
 *  Class: cXSLMain
 *
 * Author: $author$
 *   Date: 3/14/2008
 **********************************************************************
 */
class cXSLMain
: public cArgMain
{
public:
    typedef cArgMain cExtends;
    typedef cXSLMain cDerives;

    const char* m_xslFilename;
    const char* m_xmlFilename;
    cXMLReaderInterface* m_xml;
    cXSLTransformerInterface* m_xslt;

    /**
     **********************************************************************
     * Constructor: cXSLMain
     *
     *      Author: $author$
     *        Date: 3/14/2008
     **********************************************************************
     */
    cXSLMain() 
    : m_xslFilename(DEFAULT_XSL_FILENAME),
      m_xmlFilename(DEFAULT_XML_FILENAME)
    {
    }
    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual int Run
    (int argc,
     const char** argv,
     const char** env) 
    {
        int err = 0;
        eError error;

        if ((m_xslt = cXSLTransformerInterface::CreateInstance(error)))
        {
            if ((m_xml = cXMLReaderInterface::CreateInstance(error)))
            {
                if (!(error = m_xml->Initialize()))
                {
                    m_xml->OpenFile(m_stdErr, "fu.xml" /*m_xmlFilename*/);
                    m_xml->Finalize();
                }
                cXMLReaderInterface::DestroyInstance(*m_xml);
            }
            if (!(error = m_xslt->Initialize()))
            {
                m_xslt->SetLiteralParameter("title", "cXSLMain");
                m_xslt->TransformFile
                (m_stdErr, m_stdOut, m_xslFilename, m_xmlFilename);
                m_xslt->Finalize();
            }
            cXSLTransformerInterface::DestroyInstance(*m_xslt);
        }
        return err;
    }
};
#endif /* _CXSLMAIN_HXX */
