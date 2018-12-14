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
 *   File: chttpform.hxx
 *
 * Author: $author$
 *   Date: 8/7/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPFORM_HXX
#define _CHTTPFORM_HXX

#include <stdlib.h>
#include "csearchstream.hxx"
#include "cbufferedcharstreamt.hxx"
#include "ccharfile.hxx"
#include "ccharbuffer.hxx"
#include "clistt.hxx"
#include "chex.h"

/**
 **********************************************************************
 *  Class: cHTTPForm
 *
 * Author: $author$
 *   Date: 8/7/2003
 **********************************************************************
 */
class cHTTPForm
{
public:

    /**
     **********************************************************************
     *  Class: cField
     *
     * Author: $author$
     *   Date: 8/7/2003
     **********************************************************************
     */
    class cField
    : public cDynamicListItemT<cField>
    {
    public:
        typedef cDynamicListItemT<cField> cIs;

        bool m_from_query_string;
        bool m_binary_value;
        bool m_file_value;

		cCharBuffer m_name;
		cCharBuffer m_value;
		cCharBuffer m_filename;
		cCharBuffer m_filecontent;
		cCharFile m_file;

        /**
         **********************************************************************
         * Constructor: cField
         *
         *      Author: $author$
         *        Date: 8/7/2003
         **********************************************************************
         */
        cField() 
        : m_from_query_string(false),
          m_binary_value(false),
          m_file_value(false)
        {
        }
        /**
         **********************************************************************
         * Function: GetNextByName
         *
         *   Author: $author$
         *     Date: 8/7/2003
         **********************************************************************
         */
	    cField *GetNextByName(const char *name, int namelen=-1) const
	    {
            const char *fieldname;
            int fieldnamelen;
            cField *field;

            if (namelen<0)
                namelen = strlen(name);

            if (namelen>0)
            if ((field = GetNext()))
            do
            {
                if ((fieldname = field->GetName(fieldnamelen)))
                if (fieldnamelen == namelen)
                if (!strncmp(fieldname, name, namelen))
                    return field;
            }
            while ((field = field->GetNext()));

            return 0;
	    }
        /**
         **********************************************************************
         * Function: GetPreviousByName
         *
         *   Author: $author$
         *     Date: 8/7/2003
         **********************************************************************
         */
	    cField *GetPreviousByName(const char *name, int namelen=-1) const
	    {
            const char *fieldname;
            int fieldnamelen;
            cField *field;

            if (namelen<0)
                namelen = strlen(name);

            if (namelen>0)
            if ((field = GetPrevious()))
            do
            {
                if ((fieldname = field->GetName(fieldnamelen)))
                if (fieldnamelen == namelen)
                if (!strncmp(fieldname, name, namelen))
                    return field;
            }
            while ((field = field->GetPrevious()));

            return 0;
	    }
        /**
         **********************************************************************
         * Function: SetName
         *
         *   Author: $author$
         *     Date: 8/8/2003
         **********************************************************************
         */
        const char *SetName(const char *name, int length=-1)
        {
            int count;

            if ((count = m_name.Copy(name, length)) >= 0)
                return m_name.GetBuffer();

            return 0;
        }
        /**
         **********************************************************************
         * Function: GetName
         *
         *   Author: $author$
         *     Date: 8/8/2003
         **********************************************************************
         */
        inline const char *GetName(int &length) const
        {
            length = m_name.GetLength();
            return m_name.GetBuffer();
        }
        /**
         **********************************************************************
         * Function: GetName
         *
         *   Author: $author$
         *     Date: 8/8/2003
         **********************************************************************
         */
        inline const char *GetName() const
        {
            return m_name.GetBuffer();
        }
        /**
         **********************************************************************
         * Function: GetNameLength
         *
         *   Author: $author$
         *     Date: 8/8/2003
         **********************************************************************
         */
        inline int GetNameLength() const
        {
            return m_name.GetLength();
        }
        /**
         **********************************************************************
         * Function: SetValue
         *
         *   Author: $author$
         *     Date: 8/8/2003
         **********************************************************************
         */
        const char *SetValue(const char *value, int length=-1)
        {
            int count;

            if ((count = m_value.Copy(value, length)) >= 0)
                return m_value.GetBuffer();

            return 0;
        }
        /**
         **********************************************************************
         * Function: GetValue
         *
         *   Author: $author$
         *     Date: 8/8/2003
         **********************************************************************
         */
        inline const char *GetValue(int &length) const
        {
            length = m_value.GetLength();
            return m_value.GetBuffer();
        }
        /**
         **********************************************************************
         * Function: GetValue
         *
         *   Author: $author$
         *     Date: 8/8/2003
         **********************************************************************
         */
        inline const char *GetValue() const
        {
            return m_value.GetBuffer();
        }
        /**
         **********************************************************************
         * Function: GetValueLength
         *
         *   Author: $author$
         *     Date: 8/8/2003
         **********************************************************************
         */
        inline int GetValueLength() const
        {
            return m_value.GetLength();
        }
        /**
         **********************************************************************
         * Function: 
         *
         *   Author: $author$
         *     Date: 8/8/2003
         **********************************************************************
         */
    };

    /**
     **********************************************************************
     *  Class: cFieldList
     *
     * Author: $author$
     *   Date: 8/8/2003
     **********************************************************************
     */
    class cFieldList
    : public cDynamicListT<cField,cFieldList>
    {
    public:
        typedef cDynamicListT<cField,cFieldList> cIs;

        /**
         **********************************************************************
         * Constructor: cFieldList
         *
         *      Author: $author$
         *        Date: 8/8/2003
         **********************************************************************
         */
        cFieldList() 
        {
        }
        /**
         **********************************************************************
         * Function: GetFirstByName
         *
         *   Author: $author$
         *     Date: 8/17/2003
         **********************************************************************
         */
	    cField *GetFirstByName
        (const char *name,int namelen=-1) const
	    {
            cField *field;

            if (namelen<0)
                namelen=strlen(name);

            if (namelen>0)
            if ((field=GetFirst()))
            {
                if (namelen == field->GetNameLength())
                if (!strncmp(field->GetName(), name, namelen))
                    return field;

                return field->GetNextByName(name,namelen);
            }

            return 0;
	    }
        /**
         **********************************************************************
         * Function: GetLastByName
         *
         *   Author: $author$
         *     Date: 8/17/2003
         **********************************************************************
         */
	    cField *GetLastByName
        (const char *name,int namelen=-1) const
	    {
            cField *field;

            if (namelen<0)
                namelen=strlen(name);

            if (namelen>0)
            if ((field=GetLast()))
            {
                if (namelen == field->GetNameLength())
                if (!strncmp(field->GetName(), name, namelen))
                    return field;

                return field->GetPreviousByName(name,namelen);
            }

            return 0;
	    }
    };

    static const char *m_multipart_boundary_name;
    static const char *m_multipart_content_disposition_name;
    static const char *m_multipart_content_type_name;
    static const char *m_multipart_content_type_text_name;
    static const char *m_multipart_form_data_name;
    static const char *m_multipart_begin_name_name;
    static const char *m_multipart_begin_filename_name;
    static const char *m_multipart_end_name_name;

	cFieldList m_field_list;
    const char *m_temp_filename_prefix;

    /**
     **********************************************************************
     * Constructor: cHTTPForm
     *
     *      Author: $author$
     *        Date: 8/7/2003
     **********************************************************************
     */
    cHTTPForm(const char *temp_filename_prefix="http_form_data")
	: m_temp_filename_prefix(temp_filename_prefix) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cHTTPForm
     *
     *     Author: $author$
     *       Date: 8/7/2003
     **********************************************************************
     */
    virtual ~cHTTPForm()
    {
    }
    /**
     **********************************************************************
     * Function: AddFieldsFromMultipartInput
     *
     *   Author: $author$
     *     Date: 8/16/2003
     **********************************************************************
     */
    int AddFieldsFromMultipartInput
    (cCharFile &in, int content_length, const char *content_type)
    {
        int count;
        cBufferedCharStreamT<1024> content(in, content_length);

#if defined(WIN32)
        if (_setmode(_fileno(in.GetHandle()),_O_BINARY) < 0)
            return -e_ERROR_SET_MODE;

        content.SetMode(in.e_O_BINARY);

        content.SetEOLChars
        (cCharFile::e_EOL_CHAR_LF | cCharFile::e_EOL_CHAR_CR);
#endif /* defined(WIN32) */

        count = AddFieldsFromMultipartStream(content, content_type);
        return count;
    }
    /**
     **********************************************************************
     * Function: AddFieldsFromMultipartFile
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    int AddFieldsFromMultipartFile
    (const char *filename, const char *content_type)
    {
        int count;
        eError error;
        cCharFile file;

        if ((error = file.Open(filename)))
            return -e_ERROR_OPEN;

#if defined(WIN32)
        if (_setmode(_fileno(file.GetHandle()),_O_BINARY) < 0)
        {
            file.Close();
            return -e_ERROR_SET_MODE;
        }

        file.SetMode(file.e_O_BINARY);

        file.SetEOLChars
        (cCharFile::e_EOL_CHAR_LF | cCharFile::e_EOL_CHAR_CR);
#endif /* defined(WIN32) */

        count = AddFieldsFromMultipartStream(file, content_type);
        file.Close();
        return count;
    }
    /**
     **********************************************************************
     * Function: AddFieldsFromURLEncodedInput
     *
     *   Author: $author$
     *     Date: 8/16/2003
     **********************************************************************
     */
    int AddFieldsFromURLEncodedInput
    (cCharFile &in, int content_length)
    {
        int count;
        cBufferedCharStreamT<1024> content(in, content_length);

        count = AddFieldsFromURLEncodedStream(content);
        return count;
    }
    /**
     **********************************************************************
     * Function: AddFieldsFromURLEncodedFile
     *
     *   Author: $author$
     *     Date: 8/11/2003
     **********************************************************************
     */
    int AddFieldsFromURLEncodedFile(const char *filename)
    {
        int count;
        eError error;
        cCharFile file;

        if ((error = file.Open(filename)))
            return -e_ERROR_OPEN;

        count = AddFieldsFromURLEncodedStream(file);
        file.Close();
        return count;
    }
    /**
     **********************************************************************
     * Function: AddFieldsFromMultipartStream
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
    int AddFieldsFromMultipartStream
    (cCharStream &stream, const char *content_type)
    {
        int mode;
        bool binary;
        int count;
        int result;
        int paddstart;
        int boundary_length;
        int boundary_padding;
        const char *boundary;
        cCharBuffer field_name, field_text;
        cCharBuffer field_filename, field_content;
        cCharBuffer field_temp_filename;
        cCharBuffer padded_boundary;
        cSearchStream bounded(stream);

        binary = (stream.e_O_BINARY == (stream.e_O_BINARY & (mode = stream.GetMode())));

        if (!(boundary=strstr
            (content_type, m_multipart_boundary_name)))
            return -1;

        paddstart=0;

        if (binary)
        {
            padded_boundary.Putc('\r');
            paddstart++;
        }

        padded_boundary.Putc('\n');
        paddstart++;

        boundary+=strlen(m_multipart_boundary_name);
        boundary_length=strlen(boundary);

        if (0 > (boundary_length=bounded.SetPattern(boundary, boundary_length)))
            return -1;

        /* padd the boundary while searching for the first
         * occurrance
         */
        do
        {
            if (0 > (boundary_padding=bounded.Getc()))
            {
                if (boundary_padding != -bounded.e_ERROR_PATTERN_FOUND)
                    return -1;

                /* we found the first boundary
                 */
                break;
            }

            /* ignore leading new lines
             */
            if (boundary_padding != '\n')
                padded_boundary.Putc(boundary_padding);

            else padded_boundary.SetLength(paddstart);
        }
        while (0 < boundary_padding);

        padded_boundary.Write(boundary, boundary_length);
        boundary = padded_boundary.GetBuffer();

        if (0 > (boundary_length=bounded.SetPattern(boundary, boundary_length)))
            return -1;

        result = 0;

        do
        {
            if (0 > (count = AddFieldFromMultipartStream
                (field_name, field_text, field_filename,
                 field_temp_filename, field_content, bounded)))
                return count;

            result += count;

            if (0 < count)
            if (!bounded.GetPatternFound())
                break;
        }
        while (count > 0);

        return  result;
    }
    /**
     **********************************************************************
     * Function: AddFieldFromMultipartStream
     *
     *   Author: $author$
     *     Date: 12/6/2003
     **********************************************************************
     */
    int AddFieldFromMultipartStream
    (cCharBuffer &field_name,
     cCharBuffer &field_text,
     cCharBuffer &field_filename,
     cCharBuffer &field_temp_filename,
     cCharBuffer &field_content,
     cCharStream &stream, 
     bool no_tempfile=false,
     bool no_tempfilename=false)
    {
        int c;
        int count;
        bool binary_text_stream;
        bool binary_value;
        bool file_value;
        const char *tempfilename;
        FILE *tempfile;
        FILE *file;
        cField *field;
        cSearchStream search(stream);

        if (0 <= (count = field_name.Clear()))
        if (0 <= (count = field_text.Clear()))
        if (0 <= (count = field_filename.Clear()))
        if (0 <= (count = field_temp_filename.Clear()))
        if (0 <= (count = field_content.Clear()))

        if (search.FindPattern
            (m_multipart_content_disposition_name))
        if (search.FindPattern
            (m_multipart_form_data_name, -1, "\n"))
        if (search.FindPattern
            (m_multipart_begin_name_name, -1, "\n"))
        if (search.FindPattern
            (field_name, m_multipart_end_name_name, -1, "\n"))
        {
            if (search.FindPattern
                (m_multipart_begin_filename_name, -1, "\n"))
            if (search.FindPattern
                (field_filename, m_multipart_end_name_name, -1, "\n"))
                search.FindEndChar("\n");
            
            if (search.GetPatternFound()
                || search.GetEndCharFound())
            {
                binary_text_stream=false;
                binary_value=false;

                if (search.FindPattern
                    (m_multipart_content_type_name, -1, "\n"))
                if (search.FindPatternOrEndChar
                    (field_content, "\r", -1, "\n"))
                {
                    if (!strstr(field_content.GetBuffer(),
                        m_multipart_content_type_text_name))
                        binary_value=true;

                    else binary_text_stream = 
                         (stream.e_O_BINARY == 
                          (stream.e_O_BINARY & stream.GetMode()));

                    if (search.GetEndCharFound())
                        search.FindEndChar("\n");

                    else if (search.FindEndChar("\n"))
                            search.FindEndChar("\n");
                }

                if (search.GetPatternFound()
                    || search.GetEndCharFound())
                {
                    if (field_filename.GetLength()>0)
                        file_value = GetMultipartFileData
                        (field_temp_filename, tempfilename, tempfile,
                         binary_value, no_tempfile, no_tempfilename);

                    else file_value = false;

                    if (file_value)
                    {
                        if (!(file = tempfile))
                        {
                            if (!(file = fopen
                                (tempfilename, binary_value?"wb":"w")))
                                return -1;
                        }

                        do
                        {
                            if (0 > (c = stream.Getc()))
                            {
                                if (file != tempfile)
                                    fclose(file);

                                else fseek(tempfile, 0, SEEK_SET);

                                if ((field = AddMultipartField
                                    (field_name.GetBuffer(),field_name.GetLength(),
                                     field_text.GetBuffer(),field_text.GetLength(),
                                     field_filename.GetBuffer(),field_filename.GetLength(),
                                     field_content.GetBuffer(),field_content.GetLength(),
                                     binary_value, tempfile)))
                                     return 1;

                                return -1;
                            }

                            if (binary_text_stream)
                            if ('\r' == c)
                                continue;

                            fputc(c,file);
                        }
                        while (c >= 0);
                    }
                    else
                    {
                        do
                        {
                            if (0 > (c = stream.Getc()))
                            {
                                if ((field = AddMultipartField
                                    (field_name.GetBuffer(),field_name.GetLength(),
                                     field_text.GetBuffer(),field_text.GetLength(),
                                     field_filename.GetBuffer(),field_filename.GetLength(),
                                     field_content.GetBuffer(),field_content.GetLength(),
                                     binary_value)))
                                     return 1;

                                return -1;
                            }

                            if (binary_text_stream)
                            if ('\r' == c)
                                continue;

                            field_text.Putc(c);
                        }
                        while (c >= 0);
                    }
                }
            }
        }

        return  0;
    }
    /**
     **********************************************************************
     * Function: GetMultipartFileData
     *
     *   Author: $author$
     *     Date: 12/7/2003
     **********************************************************************
     */
    bool GetMultipartFileData
    (cCharBuffer &filename_buffer,const char *&filename,FILE *&file,
     bool binary=false,bool no_tempfile=false,bool no_tempfilename=false)
    {
        int count;
        char *buffer;

        if (no_tempfile)
        {
            if (no_tempfilename)
                return false;

            if (0 > (count = filename_buffer.Write("_XXXXXX")))
                return false;

            if (!(buffer = filename_buffer.GetWriteBuffer()))
                return false;

#if defined(__linux__)
            int err;

            if ((err = mkstemp(buffer)))
                return false;

            filename = buffer;
#else
            if (!(filename = mktemp(buffer)))
                return false;
#endif

            file=0;
            return true;
        }

        filename="";

        if (!(file = tmpfile()))
            return false;

        return true;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
    int AddFieldsFromURLEncodedStream
    (cCharStream &stream, bool from_query_string=false)
    {
        enum eState
        {
            e_STATE_NAME,
            e_STATE_TEXT,
            e_STATE_HEX1,
            e_STATE_HEX2
        };

        char c, x;
        int count, fields;
        int namelen, textlen;
        const char *name, *text;
        eState state,oldstate;
        cCharBuffer name_buffer;
        cCharBuffer text_buffer;
        cCharBuffer *buffer;
        cField *field;

        if ((count = stream.Get(c)) < 0)
            return 0;

        fields = 0;
        state = e_STATE_NAME;
        buffer = &name_buffer;

        do
        {
            switch(state)
            {
            case e_STATE_HEX1:
                switch(c)
                {
                case '&':
                    if ((count = name_buffer.Clear()) < 0)
                        return -1;

                    state = e_STATE_NAME;
                    buffer = &name_buffer;
                    break;

                default:
                    if (chex_ishex(c))
                    {
                        x = c;
                        state = e_STATE_HEX2;
                    }
                    else
                    {
                        if ((count = buffer->Put('%')) < 1)
                            return -1;

                        if ((count = buffer->Put(c)) < 1)
                            return -1;

                        state = oldstate;
                    }
                }
                break;

            case e_STATE_HEX2:
                switch(c)
                {
                case '&':
                    if ((count = name_buffer.Clear()) < 0)
                        return -1;

                    state = e_STATE_NAME;
                    buffer = &name_buffer;
                    break;

                default:
                    if (chex_ishex(c))
                    {
                        c = (chex_ctohex(x)<<4) | chex_ctohex(c);

                        if ((count = buffer->Put(c)) < 1)
                            return -1;

                        state = oldstate;
                    }
                    else
                    {
                        if ((count = buffer->Put('%')) < 1)
                            return -1;

                        if ((count = buffer->Put(x)) < 1)
                            return -1;

                        if ((count = buffer->Put(c)) < 1)
                            return -1;

                        state = oldstate;
                    }
                }
                break;

            case e_STATE_NAME:
                switch(c)
                {
                case '%':
                    oldstate = state;
                    state = e_STATE_HEX1;
                    break;

                case '&':
                    if ((name = name_buffer.GetBuffer(namelen)))
                    if (namelen > 0)
                    if ((field = AddField
                        (name, namelen, "", 0, from_query_string)))
                        fields++;
                    else return -1;

                    if ((count = name_buffer.Clear()) < 0)
                        return -1;
                    break;

                case '+':
                    if ((count = name_buffer.Put(' ')) < 1)
                        return -1;
                    break;

                case '=':
                    if ((count = text_buffer.Clear()) < 0)
                        return -1;

                    state = e_STATE_TEXT;
                    buffer = &text_buffer;
                    break;

                default:
                    if ((count = name_buffer.Put(c)) < 1)
                        return -1;
                }
                break;

            case e_STATE_TEXT:
                switch(c)
                {
                case '%':
                    oldstate = state;
                    state = e_STATE_HEX1;
                    break;

                case '\n':
                case '&':
                    if ((name = name_buffer.GetBuffer(namelen)))
                    if (namelen > 0)
                    if ((text = text_buffer.GetBuffer(textlen)))
                    if ((field = AddField
                        (name, namelen, text, textlen, from_query_string)))
                        fields++;
                    else return -1;

                    if ((count = name_buffer.Clear()) < 0)
                        return -1;

                    state = e_STATE_NAME;
                    buffer = &name_buffer;
                    break;

                case '+':
                    if ((count = text_buffer.Put(' ')) < 1)
                        return -1;
                    break;

                default:
                    if ((count = text_buffer.Put(c)) < 1)
                        return -1;
                }
                break;

            default:
                return -1;
            }

            count = stream.Get(c);
        }
        while(count > 0);

        switch(state)
        {
        case e_STATE_NAME:
            if ((name = name_buffer.GetBuffer(namelen)))
            if (namelen > 0)
            if ((field = AddField
                ( name, namelen, "", 0, from_query_string)))
                fields++;
            else return -1;
            break;

        case e_STATE_TEXT:
            if ((name = name_buffer.GetBuffer(namelen)))
            if (namelen > 0)
            if ((text = text_buffer.GetBuffer(textlen)))
            if ((field = AddField
                (name, namelen, text, textlen, from_query_string)))
                fields++;
            else return -1;
            break;
        }

        return fields;
    }
    /**
     **********************************************************************
     * Function: AddMultipartField
     *
     *   Author: $author$
     *     Date: 12/7/2003
     **********************************************************************
     */
    cField *AddMultipartField
    (const char *name,int namelen,
     const char *text,int textlen,
     const char *filename,int filenamelen,
     const char *filecontent,int filecontentlen,
     bool binary=false,FILE *file=0)
    {
        eError error;
        cField *field;

        if (filenamelen < 0)
            filenamelen = strlen(filename);

        if (filecontentlen < 0)
            filecontentlen = strlen(filecontent);

        if ((field = AddField(name,namelen,text,textlen)))
        {
            field->m_binary_value = binary;

            if (filenamelen > 0)
            if (0 > (filenamelen = field->m_filename.Copy
                (filename, filenamelen)))
                return 0;

            if (filecontentlen > 0)
            if (0 > (filecontentlen = field->m_filecontent.Copy
                (filecontent, filecontentlen)))
                return 0;

            if ((field->m_file_value = (file != 0)))
            if ((error=field->m_file.Attach(file)))
                return 0;

            return field;
        }

        return 0;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
    cField *AddField
    (const char *name,int namelen,
     const char *value,int valuelen,
     bool from_query_string=false)
    {
        const char *field_name;
        const char *field_value;
        cField *field;

        if ((field=new cField))
        {
            if ((field_name = field->SetName(name,namelen)))
            if ((field_value = field->SetValue(value,valuelen)))
            {
                field->m_from_query_string=from_query_string;
                m_field_list.Add(field);
                return field;
            }
            delete field;
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetFirstFieldByName
     *
     *   Author: $author$
     *     Date: 8/17/2003
     **********************************************************************
     */
	inline cField *GetFirstFieldByName
    (const char *name, int namelen=-1) const
	{
		return m_field_list.GetFirstByName(name, namelen);
	}
    /**
     **********************************************************************
     * Function: GetLastFieldByName
     *
     *   Author: $author$
     *     Date: 8/17/2003
     **********************************************************************
     */
	inline cField *GetLastFieldByName
    (const char *name, int namelen=-1) const
	{
		return m_field_list.GetLastByName(name, namelen);
	}
    /**
     **********************************************************************
     * Function: GetFirstField
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
	inline cField *GetFirstField() const
	{
		return m_field_list.GetFirst();
	}
    /**
     **********************************************************************
     * Function: GetLastField
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
	inline cField *GetLastField() const
	{
		return m_field_list.GetLast();
	}
};


#endif
