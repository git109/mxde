/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: cigescgi.cxx
 *
 * Author: $author$
 *   Date: 7/23/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cigesreader.hxx"
#include "cdocumenttemplatecgi.hxx"
#include "ccharfilereader.hxx"
#include "ccharfile.hxx"

/**
 **********************************************************************
 *  Class: cIGESCGI
 *
 * Author: $author$
 *   Date: 7/23/2005
 **********************************************************************
 */
class cIGESCGI
: public cDocumentTemplateCGI
{
public:
    typedef cDocumentTemplateCGI cIs;

    cContentStream m_content_stream;
    cCharFile m_document_file;
    cIGESEvent m_event;
    cIGESReader m_iges_reader;

    /**
     **********************************************************************
     * Constructor: cIGESCGI
     *
     *      Author: $author$
     *        Date: 7/23/2005
     **********************************************************************
     */
    cIGESCGI(const char *name="iges")
    : cIs(name),
      m_content_stream(*this),
      m_iges_reader(m_event)
    {
    }

    /**
     **********************************************************************
     * Function: OnTransform
     *
     *   Author: $author$
     *     Date: 7/23/2005
     **********************************************************************
     */
    virtual int OnTransform() 
    {
        int count,result = 0;
        eError error;

        if ((error = OpenDocumentFile
            (m_document_file, m_document_filename)))
            return result = 1;
        else
        {
            FILE *file = m_document_file.GetHandle();
            cCharFileReader file_reader(file);

            if (0 > (count = m_iges_reader.Read(file_reader)))
                result = 1;
        }

        m_document_file.Close();

        OutputContentType();

        return result;
    }

    /**
     **********************************************************************
     * Function: RequiresDocumentFilename
     *
     *   Author: $author$
     *     Date: 7/23/2005
     **********************************************************************
     */
    virtual bool RequiresDocumentFilename(bool on_cgi) 
    {
        bool on = true;
        return on;
    }
    /**
     **********************************************************************
     * Function: RequiresInputFilename
     *
     *   Author: $author$
     *     Date: 7/23/2005
     **********************************************************************
     */
    virtual bool RequiresInputFilename(bool on_cgi) 
    {
        bool on = false;
        return on;
    }
} g_iges_cgi;
