/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: cdocumentparserinstance.hxx
 *
 * Author: $author$
 *   Date: 11/25/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTPARSERINSTANCE_HXX
#define _CDOCUMENTPARSERINSTANCE_HXX

#include "cdocumentparserimplement.hxx"
#include "cdocumentparserinterface.hxx"
#include "cdocumentfactoryimplement.hxx"
#include "ccharstreamtocharwriter.hxx"
#include "ccharreadertocharwriter.hxx"
#include "ccharfile.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cDocumentParserInstance
 *
 * Author: $author$
 *   Date: 11/25/2005
 **********************************************************************
 */
class cDocumentParserInstance
: virtual public cDocumentFactoryImplement,
  virtual public cDocumentParserImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    cCharFile m_file;

    /**
     **********************************************************************
     * Constructor: cDocumentParserInstance
     *
     *      Author: $author$
     *        Date: 11/25/2005
     **********************************************************************
     */
    cDocumentParserInstance()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDocumentParserInstance
     *
     *      Author: $author$
     *        Date: 11/25/2005
     **********************************************************************
     */
    virtual ~cDocumentParserInstance()
    {
    }
    /**
     **********************************************************************
     * Function: ParseFile
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual eError ParseFile
    (const char* filename, int length=-1) 
    {
        eError error2, error;

        if (!(error = m_file.Open(filename, "r")))
        {
            if ((error2 = ParseStream(m_file, length)))
            if (!error)
                error = error2;

            if ((error2 = m_file.Close()))
            if (!error)
                error = error2;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseStreamToParserWriter
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual eError ParseStreamToParserWriter
    (cCharWriterInterface &char_writer,
     cCharStreamToCharWriter &char_stream_to_char_writer,
     cCharStreamInterface &stream, int length=-1) 
    {
        eError error2, error;

        if (!(error = char_writer.Initialize()))
        {
            if (!(error2 = char_stream_to_char_writer.Initialize()))
            {
                if (0 > (length = char_stream_to_char_writer.
                    WriteStream(stream, length)))
                if (!error)
                    error = -length;

                if ((error2 = char_stream_to_char_writer.Finalize()))
                if (!error)
                    error = error2;
            }
            else if (!error)
                    error = error2;

            if ((error2 = char_writer.Finalize()))
            if (!error)
                error = error2;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseReaderToParserWriter
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual eError ParseReaderToParserWriter
    (cCharWriterInterface &char_writer,
     cCharReaderToCharWriter &char_reader_to_char_writer,
     cCharReaderInterface &reader, int length=-1) 
    {
        eError error2, error;

        if (!(error = char_writer.Initialize()))
        {
            if (!(error2 = char_reader_to_char_writer.Initialize()))
            {
                if (0 > (length = char_reader_to_char_writer.
                    WriteReader(reader, length)))
                if (!error)
                    error = -length;

                if ((error2 = char_reader_to_char_writer.Finalize()))
                if (!error)
                    error = error2;
            }
            else if (!error)
                    error = error2;

            if ((error2 = char_writer.Finalize()))
            if (!error)
                error = error2;
        }
        return error;
    }
};

#endif /* _CDOCUMENTPARSERINSTANCE_HXX */
