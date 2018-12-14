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
 *   File: cfilepathwriter.hxx
 *
 * Author: $author$
 *   Date: 12/26/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CFILEPATHWRITER_HXX
#define _CFILEPATHWRITER_HXX

#include "cprintfinterface.hxx"
#include "cfilepathparsereventinterface.hxx"
#include "cccharwriterinterface.hxx"
#include "cccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cFilePathWriter
 *
 * Author: $author$
 *   Date: 12/26/2005
 **********************************************************************
 */
class cFilePathWriter
: virtual public cInitializeImplement,
  virtual public cPutcImplement,
  virtual public cCCharWriterImplement,
  public cFilePathParserEventProxy
{
public:
    typedef cFilePathParserEventProxy cIs;
    typedef int (cFilePathWriter::*mPut)(const cChar &c);
    typedef eError (cFilePathWriter::*mFinalize)();

    mPut m_old_put, m_put;
    mFinalize m_finalize;
    cChar m_dot;
    cCCharBuffer m_dot_buffer;
    cCCharBuffer m_name_buffer;
    cCCharBuffer m_extension_buffer;
    const cChar *m_dot_chars;
    const cChar *m_text;
    int m_length;
    bool m_is_root;

    /**
     **********************************************************************
     * Constructor: cFilePathWriter
     *
     *      Author: $author$
     *        Date: 12/26/2005
     **********************************************************************
     */
    cFilePathWriter
    (cFilePathParserEventInterface& proxy) 
    : cIs(proxy),
      m_old_put(PathPut),
      m_put(PathPut),
      m_finalize(FileFinalize),
      m_dot('.'),
      m_text(0),
      m_length(0),
      m_is_root(false)
    {
        eError error;
        int length;

        if (0 > (length = m_dot_buffer.Put(m_dot)))
            throw(error = -length);

        else if (!(m_dot_chars = m_dot_buffer.GetBuffer(length)))
                throw(error = e_ERROR_FAILED);
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;

        m_old_put = PathPut;
        m_put = PathPut;
        m_finalize = FileFinalize;
        m_is_root = false;

        if (0 > (m_length = m_name_buffer.Clear()))
            return error = -m_length;

        error = m_proxy.Initialize();
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = (this->*m_finalize)();
        return error;
    }
    /**
     **********************************************************************
     * Function: HostFinalize
     *
     *   Author: $author$
     *     Date: 12/26/2005
     *
     * //?<EOF>
     **********************************************************************
     */
    eError HostFinalize() 
    {
        eError error = e_ERROR_NONE;
        int count;

        Printf("HostFinalize();\n");

        if (0 > (count = DoOnHost()))
            error = -count;
        return error;
    }
    /**
     **********************************************************************
     * Function: FileFinalize
     *
     *   Author: $author$
     *     Date: 12/26/2005
     *
     * ?<EOF>
     **********************************************************************
     */
    eError FileFinalize() 
    {
        eError error = e_ERROR_NONE;
        int count;

        Printf("FileFinalize();\n");

        if (0 > (count = DoOnFileName()))
            error = -count;
        return error;
    }
    /**
     **********************************************************************
     * Function: DotFinalize
     *
     *   Author: $author$
     *     Date: 12/26/2005
     *
     * .<EOF>
     **********************************************************************
     */
    eError DotFinalize() 
    {
        eError error = e_ERROR_NONE;
        int count;

        Printf("DotFinalize();\n");

        if (0 > (count = DoOnCurrentDirectory()))
            error = -count;
        return error;
    }
    /**
     **********************************************************************
     * Function: DotDotFinalize
     *
     *   Author: $author$
     *     Date: 12/26/2005
     *
     * ..<EOF>
     **********************************************************************
     */
    eError DotDotFinalize() 
    {
        eError error = e_ERROR_NONE;
        int count;

        Printf("DotDotFinalize();\n");

        if (0 > (count = DoOnParentDirectory()))
            error = -count;
        return error;
    }
    /**
     **********************************************************************
     * Function: FileDotFinalize
     *
     *   Author: $author$
     *     Date: 12/26/2005
     *
     * ?.<EOF>
     **********************************************************************
     */
    eError FileDotFinalize() 
    {
        eError error = e_ERROR_NONE;
        int count;

        Printf("FileDotFinalize();\n");

        if (0 > (count = DoOnFileNameDot()))
            error = -count;
        return error;
    }
    /**
     **********************************************************************
     * Function: FileExtensionFinalize
     *
     *   Author: $author$
     *     Date: 12/26/2005
     *
     * ?.?<EOF>
     **********************************************************************
     */
    eError FileExtensionFinalize() 
    {
        eError error = e_ERROR_NONE;
        int count;

        Printf("FileExtensionFinalize();\n");

        if (0 > (count = DoOnFileName()))
            return error = -count;

        if (0 > (count = DoOnExtension()))
            error = -count;
        return error;
    }
    /**
     **********************************************************************
     * Function: Putc
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual int Putc(int c) 
    {
        cChar cc((char)c);
        int count;
        
        Printf("%c -> ", cc);

        if (0 < (count = Put(cc)))
            count = c;
        return count;
    }
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 12/26/2004
     **********************************************************************
     */
    virtual int Put(const cChar& c) 
    {
        int count = (this->*m_put)(c);        
        return count;
    }
    /**
     **********************************************************************
     * Function: PathPut
     *
     *   Author: $author$
     *     Date: 12/26/2004
     *
     * <BOF>
     **********************************************************************
     */
    int PathPut(const cChar& cc) 
    {
        int count = 0;
        char c = cc.ToChar();

        Printf("PathPut();\n");

        switch(c)
        {
        case '/':
        case '\\':
            m_is_root = true;
            m_put = SlashPathPut;
            m_finalize = FileFinalize;
            return count;

        case '.':
            m_put = DotFilePut;
            m_finalize = DotFinalize;
            return count;
        }
        /* ?
         */
        count = m_name_buffer.Put(cc);
        m_put = DevicePut;
        m_finalize = FileFinalize;
        return count;
    }
    /**
     **********************************************************************
     * Function: SlashPathPut
     *
     *   Author: $author$
     *     Date: 12/26/2004
     *
     * <BOF>/
     **********************************************************************
     */
    int SlashPathPut(const cChar& cc) 
    {
        int count = 0;
        char c = cc.ToChar();

        Printf("SlashPathPut();\n");

        switch(c)
        {
        case '/':
        case '\\':
            m_put = HostPut;
            m_finalize = HostFinalize;
            return count;
        }
        /* /?
         */
        m_put = FilePut;
        m_finalize = FileFinalize;
        count = m_name_buffer.Put(cc);
        return count;
    }
    /**
     **********************************************************************
     * Function: HostPut
     *
     *   Author: $author$
     *     Date: 12/26/2004
     *
     * <BOF>//
     **********************************************************************
     */
    int HostPut(const cChar& cc) 
    {
        int count = 0;
        char c = cc.ToChar();

        Printf("HostPut();\n");

        switch(c)
        {
        case '/':
        case '\\':
            count = DoOnHost();
            m_is_root = true;
            m_put = DevicePut;
            m_finalize = FileFinalize;
            return count;
        }
        /* //?
         */
        count = m_name_buffer.Put(cc);
        return count;
    }
    /**
     **********************************************************************
     * Function: DevicePut
     *
     *   Author: $author$
     *     Date: 12/26/2004
     *
     * <BOF>?
     **********************************************************************
     */
    int DevicePut(const cChar& cc) 
    {
        int count = 0;
        char c = cc.ToChar();

        Printf("DevicePut();\n");

        switch(c)
        {
        case '/':
        case '\\':
            count = DoOnDirectory();
            m_put = SlashFilePut;
            m_finalize = FileFinalize;
            return count;

        case ':':
            count = DoOnDevice();
            m_put = DevicePathPut;
            m_finalize = FileFinalize;
            return count;

        case '.':
            m_put = DotExtensionPut;
            m_finalize = FileDotFinalize;
            return count;
        }
        /* ??
         */
        count = m_name_buffer.Put(cc);
        return count;
    }
    /**
     **********************************************************************
     * Function: DevicePathPut
     *
     *   Author: $author$
     *     Date: 12/26/2004
     *
     * ?:
     **********************************************************************
     */
    int DevicePathPut(const cChar& cc) 
    {
        int count = 0;
        char c = cc.ToChar();

        Printf("DevicePathPut();\n");

        switch(c)
        {
        case '/':
        case '\\':
            m_is_root = true;
            m_put = SlashFilePut;
            m_finalize = FileFinalize;
            return count;

        case '.':
            m_put = DotFilePut;
            m_finalize = DotFinalize;
            return count;
        }
        count = m_name_buffer.Put(cc);
        m_put = FilePut;
        m_finalize = FileFinalize;
        return count;
    }
    /**
     **********************************************************************
     * Function: DotFilePut
     *
     *   Author: $author$
     *     Date: 12/26/2004
     *
     * .
     **********************************************************************
     */
    int DotFilePut(const cChar& cc) 
    {
        int count = 0;
        char c = cc.ToChar();

        Printf("DotFilePut();\n");

        switch(c)
        {
        case '/':
        case '\\':
            count = DoOnCurrentDirectory();
            m_put = FilePut;
            m_finalize = FileFinalize;
            return count;

        case '.':
            m_put = DotDotPut;
            m_finalize = DotDotFinalize;
            return count;
        }
        if (0 < (count = m_name_buffer.Put(m_dot)))
            count = m_name_buffer.Put(cc);
        m_put = FilePut;
        m_finalize = FileFinalize;
        return count;
    }
    /**
     **********************************************************************
     * Function: DotDotPut
     *
     *   Author: $author$
     *     Date: 12/26/2004
     *
     * ..
     **********************************************************************
     */
    int DotDotPut(const cChar& cc) 
    {
        int count = 0;
        char c = cc.ToChar();

        Printf("DotDotPut();\n");

        switch(c)
        {
        case '/':
        case '\\':
            count = DoOnParentDirectory();
            m_put = FilePut;
            m_finalize = FileFinalize;
            return count;

        case '.':
            count = m_name_buffer.WriteL
            (m_dot_chars, m_dot_chars, 0);
            m_put = DotFilePut;
            m_finalize = FileDotFinalize;
            return count;
        }
        if (0 > (count = m_name_buffer.WriteL
            (m_dot_chars, m_dot_chars, 0)))
            return count;

        count = m_name_buffer.Put(cc);
        m_put = FilePut;
        m_finalize = FileFinalize;
        return count;
    }
    /**
     **********************************************************************
     * Function: SlashFilePut
     *
     *   Author: $author$
     *     Date: 12/26/2004
     *
     * ?/
     **********************************************************************
     */
    int SlashFilePut(const cChar& cc) 
    {
        int count = 0;
        char c = cc.ToChar();

        Printf("SlashFilePut();\n");

        switch(c)
        {
        case '/':
        case '\\':
            count = DoOnDirectory();
            return count;

        case '.':
            m_put = DotFilePut;
            m_finalize = DotFinalize;
            return count;
        }
        count = m_name_buffer.Put(cc);
        m_put = FilePut;
        m_finalize = FileFinalize;
        return count;
    }
    /**
     **********************************************************************
     * Function: FilePut
     *
     *   Author: $author$
     *     Date: 12/26/2004
     *
     * ?
     **********************************************************************
     */
    int FilePut(const cChar& cc) 
    {
        int count = 0;
        char c = cc.ToChar();

        Printf("FilePut();\n");

        switch(c)
        {
        case '/':
        case '\\':
            count = DoOnDirectory();
            m_put = SlashFilePut;
            m_finalize = FileFinalize;
            return count;

        case '.':
            m_put = DotExtensionPut;
            m_finalize = FileDotFinalize;
            return count;
        }
        count = m_name_buffer.Put(cc);
        m_finalize = FileFinalize;
        return count;
    }
    /**
     **********************************************************************
     * Function: DotExtensionPut
     *
     *   Author: $author$
     *     Date: 12/26/2004
     *
     * ?.
     **********************************************************************
     */
    int DotExtensionPut(const cChar& cc) 
    {
        int count = 0;
        char c = cc.ToChar();

        Printf("DotExtensionPut();\n");

        switch(c)
        {
        case '/':
        case '\\':
            count = DoOnDirectoryDot();
            m_put = FilePut;
            m_finalize = FileFinalize;
            return count;

        case '.':
            count = m_name_buffer.Write(m_dot_chars);
            return count;
        }

        /* ?.?
         */
        count = m_extension_buffer.Put(cc);
        m_put = ExtensionPut;
        m_finalize = FileExtensionFinalize;
        return count;
    }
    /**
     **********************************************************************
     * Function: ExtensionPut
     *
     *   Author: $author$
     *     Date: 12/26/2004
     *
     * ?.?
     **********************************************************************
     */
    int ExtensionPut(const cChar& cc) 
    {
        int count = 0;
        char c = cc.ToChar();

        Printf("ExtensionPut();\n");

        switch(c)
        {
        case '/':
        case '\\':
            count = DoOnDirectory();
            m_put = SlashFilePut;
            m_finalize = FileFinalize;
            return count;

        case '.':
            count = AppendExtension();
            m_put = DotExtensionPut;
            m_finalize = FileDotFinalize;
            return count;
        }
        count = m_extension_buffer.Put(cc);
        return count;
    }

    /**
     **********************************************************************
     * Function: AppendExtension
     *
     *   Author: $author$
     *     Date: 1/9/2006
     **********************************************************************
     */
    virtual int AppendExtension() 
    {
        int count = 0;

        if ((m_text = m_extension_buffer.GetBuffer(m_length)))
        if (0 < m_length)
        if (0 > (count = m_name_buffer.
            WriteL(m_dot_chars, m_text, 0)))
            return count;
        else m_extension_buffer.Clear();

        return count;
    }

    /**
     **********************************************************************
     * Function: DoOnHost
     *
     *   Author: $author$
     *     Date: 1/9/2006
     **********************************************************************
     */
    virtual int DoOnHost() 
    {
        int count = 0;

        if ((m_text = m_name_buffer.GetBuffer(m_length)))
            count = OnHost(m_text, m_length);
        m_name_buffer.Clear();
        m_is_root = false;
        return count;
    }
    /**
     **********************************************************************
     * Function: DoOnDevice
     *
     *   Author: $author$
     *     Date: 1/9/2006
     **********************************************************************
     */
    virtual int DoOnDevice() 
    {
        int count = 0;

        if ((m_text = m_name_buffer.GetBuffer(m_length)))
            count = OnDevice(m_text, m_length);
        m_name_buffer.Clear();
        m_is_root = false;
        return count;
    }
    /**
     **********************************************************************
     * Function: DoOnDirectory
     *
     *   Author: $author$
     *     Date: 1/9/2006
     **********************************************************************
     */
    virtual int DoOnDirectory() 
    {
        int count = 0;

        if (0 > (count = AppendExtension()))
            return count;

        if ((m_text = m_name_buffer.GetBuffer(m_length)))
        if (m_is_root)
            count = OnRootDirectory(m_text, m_length);
        else count = OnDirectory(m_text, m_length);
        m_name_buffer.Clear();
        m_is_root = false;
        return count;
    }
    /**
     **********************************************************************
     * Function: DoOnDotDirectory
     *
     *   Author: $author$
     *     Date: 1/9/2006
     **********************************************************************
     */
    virtual int DoOnDotDirectory() 
    {
        int count = 0;

        if (0 > (count = m_name_buffer.Write(m_dot_chars)))
            return count;

        if (0 > (count = m_name_buffer.Write(m_extension_buffer)))
            return count;

        if ((m_text = m_name_buffer.GetBuffer(m_length)))
            count = OnDirectory(m_text, m_length);
        m_name_buffer.Clear();
        m_extension_buffer.Clear();
        m_is_root = false;
        return count;
    }
    /**
     **********************************************************************
     * Function: DoOnDirectoryDot
     *
     *   Author: $author$
     *     Date: 1/9/2006
     **********************************************************************
     */
    virtual int DoOnDirectoryDot() 
    {
        int count = 0;

        if (0 > (count = m_name_buffer.Write(m_dot_chars)))
            return count;

        if ((m_text = m_name_buffer.GetBuffer(m_length)))
        if (m_is_root)
            count = OnRootDirectory(m_text, m_length);
        else count = OnDirectory(m_text, m_length);
        m_name_buffer.Clear();
        m_is_root = false;
        return count;
    }
    /**
     **********************************************************************
     * Function: DoOnCurrentDirectory
     *
     *   Author: $author$
     *     Date: 1/9/2006
     **********************************************************************
     */
    virtual int DoOnCurrentDirectory() 
    {
        int count = 0;

        if (0 > (count = m_name_buffer.Write(m_dot_chars)))
            return count;

        if ((m_text = m_name_buffer.GetBuffer(m_length)))
            count = OnCurrentDirectory(m_text, m_length);
        m_name_buffer.Clear();
        m_is_root = false;
        return count;
    }
    /**
     **********************************************************************
     * Function: DoOnParentDirectory
     *
     *   Author: $author$
     *     Date: 1/9/2006
     **********************************************************************
     */
    virtual int DoOnParentDirectory() 
    {
        int count = 0;

        if (0 > (count = m_name_buffer.
            WriteL(m_dot_chars, m_dot_chars, 0)))
            return count;

        if ((m_text = m_name_buffer.GetBuffer(m_length)))
            count = OnParentDirectory(m_text, m_length);
        m_name_buffer.Clear();
        m_is_root = false;
        return count;
    }
    /**
     **********************************************************************
     * Function: DoOnDotFileName
     *
     *   Author: $author$
     *     Date: 1/9/2006
     **********************************************************************
     */
    virtual int DoOnDotFileName() 
    {
        int count = 0;

        if (0 > (count = m_name_buffer.Write(m_dot_chars)))
            return count;

        if (0 > (count = m_name_buffer.Write(m_extension_buffer)))
            return count;

        if ((m_text = m_name_buffer.GetBuffer(m_length)))
            count = OnFileName(m_text, m_length);
        m_name_buffer.Clear();
        m_extension_buffer.Clear();
        m_is_root = false;
        return count;
    }
    /**
     **********************************************************************
     * Function: DoOnFileNameDot
     *
     *   Author: $author$
     *     Date: 1/9/2006
     **********************************************************************
     */
    virtual int DoOnFileNameDot() 
    {
        int count = 0;

        if (0 > (count = m_name_buffer.Write(m_dot_chars)))
            return count;

        if ((m_text = m_name_buffer.GetBuffer(m_length)))
            count = OnFileName(m_text, m_length);
        m_name_buffer.Clear();
        m_is_root = false;
        return count;
    }
    /**
     **********************************************************************
     * Function: DoOnFileName
     *
     *   Author: $author$
     *     Date: 1/9/2006
     **********************************************************************
     */
    virtual int DoOnFileName() 
    {
        int count = 0;

        if ((m_text = m_name_buffer.GetBuffer(m_length)))
        if (m_is_root)
            count = OnRootFileName(m_text, m_length);
        else count = OnFileName(m_text, m_length);
        m_name_buffer.Clear();
        m_is_root = false;
        return count;
    }
    /**
     **********************************************************************
     * Function: DoOnExtension
     *
     *   Author: $author$
     *     Date: 1/9/2006
     **********************************************************************
     */
    virtual int DoOnExtension() 
    {
        int count = 0;

        if ((m_text = m_extension_buffer.GetBuffer(m_length)))
            count = OnExtension(m_text, m_length);
        m_extension_buffer.Clear();
        m_is_root = false;
        return count;
    }
    /**
     **********************************************************************
     * Function: Printf
     *
     *   Author: $author$
     *     Date: 1/9/2006
     **********************************************************************
     *
    int Printf(const char* format, ...)
    {
        int result;
        va_list va;

        va_start(va, format);
        result = vprintf(format, va);
        va_end(va);
        return result;
    }*/
};

#endif /* _CFILEPATHWRITER_HXX */
