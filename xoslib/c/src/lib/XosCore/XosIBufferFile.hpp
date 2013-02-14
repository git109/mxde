///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2011 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: XosIBufferFile.hpp
///
/// Author: $author$
///   Date: 11/23/2011
///////////////////////////////////////////////////////////////////////
#ifndef _XOSIBUFFERFILE_HPP
#define _XOSIBUFFERFILE_HPP

#include "XosIBuffer.hpp"
#include <stdio.h>

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosByteIBufferFileExtend
///
///  Author: $author$
///    Date: 11/23/2011
///////////////////////////////////////////////////////////////////////
typedef XosByteIBuffer
XosByteIBufferFileExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosByteIBufferFile
///
/// Author: $author$
///   Date: 11/23/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosByteIBufferFile
: public XosByteIBufferFileExtend
{
public:
    typedef XosByteIBufferFileExtend Extends;

    FILE* m_file;
    bool m_isOpen;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosByteIBufferFile
    ///
    ///       Author: $author$
    ///         Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    XosByteIBufferFile
    (const tWhat* buffer=0,
     tSize size=0,
     tLength length=-1)
    : Extends(buffer, size, length),
      m_file(NULL),
      m_isOpen(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosByteIBufferFile
    ///
    ///      Author: $author$
    ///        Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosByteIBufferFile()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Open
    ///
    ///    Author: $author$
    ///      Date: 11/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Open
    (const char* fileName,
     const char* fileMode="rb")
    {
        XosError error = XOS_ERROR_FAILED;

        if ((m_file) && (m_isOpen))
        if ((error = Close()))
            return error;

        if ((m_isOpen = (NULL != (m_file = fopen(fileName, fileMode)))))
            error = XOS_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Close
    ///
    ///    Author: $author$
    ///      Date: 11/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Close()
    {
        XosError error = XOS_ERROR_FAILED;
        FILE* file = m_file;
        int err;

        m_isOpen = false;
        m_file = NULL;

        if ((file))
        if (!(err = fclose(file)))
            error = XOS_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Read
    ///
    ///    Author: $author$
    ///      Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tLength Read
    (tWhat* buffer, tSize size)
    {
        tLength count = 0;
        FILE* file;

        if (!(file = m_file))
            count = Extends::Read(buffer, size);
        else
        count = fread(buffer, sizeof(tWhat), size, m_file);
        return count;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSIBUFFERFILE_HPP 
        

