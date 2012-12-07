/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cpngreadstruct.hxx
 *
 * Author: $author$
 *   Date: 6/12/2009
 **********************************************************************
 */
#if !defined(_CPNGREADSTRUCT_HXX) || defined(CPNGREADSTRUCT_MEMBERS_ONLY)
#if !defined(_CPNGREADSTRUCT_HXX) && !defined(CPNGREADSTRUCT_MEMBERS_ONLY)
#define _CPNGREADSTRUCT_HXX
#endif /* !defined(_CPNGREADSTRUCT_HXX) && !defined(CPNGREADSTRUCT_MEMBERS_ONLY) */

#if !defined(CPNGREADSTRUCT_MEMBERS_ONLY)
#include "cpngstruct.hxx"
#include "cpnginfo.hxx"
#include "cfile.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cPngReadStruct
 *
 * Author: $author$
 *   Date: 6/11/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cPngReadStruct
: public cPngStruct
{
public:
    typedef cPngStruct cExtends;
    typedef cPngReadStruct cDerives;

    cBYTEFile m_file;
    cBYTEReaderInterface& m_read;

    /**
     **********************************************************************
     * Constructor: cPngReadStruct
     *
     *      Author: $author$
     *        Date: 6/11/2009
     **********************************************************************
     */
    cPngReadStruct
    (png_structp attached=NULL,
     bool isCreated=false) 
    : cExtends(attached, isCreated),
      m_read(m_file)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cPngReadStruct
     *
     *     Author: $author$
     *       Date: 6/11/2009
     **********************************************************************
     */
    virtual ~cPngReadStruct()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 6/11/2009
     **********************************************************************
     */
    virtual eError Create
    (bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_FAILED;
        tAttachedTo detached;
        bool isCreated;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if ((isCreated = (NULL != (detached = png_create_read_struct
            (PNG_LIBPNG_VER_STRING, ((png_voidp)this), ErrorFn, WarnFn)))))
        {
            png_set_read_fn(detached, ((png_voidp)this), ReadFn);
            m_attached = detached;
            m_isCreated = isCreated;
            error = e_ERROR_NONE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 6/11/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
    {
        eError error = e_ERROR_FAILED;
        tAttachedTo detached;

        if ((error = Created(onlyCreated, true)))
            return error;

        SetIsCreated(false);

        if ((detached = Detach()))
            png_destroy_read_struct
            (&detached, png_infopp_NULL, png_infopp_NULL);
        else
        if (onlyCreated)
            error = e_ERROR_NOT_ATTACHED;

        return error;
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual TLENGTH Read
    (cPngInfo& pngInfo,
     const char* fileName) 
    {
        TLENGTH count = 0;
        eError error;

        if (!(Attached()))
            error = e_ERROR_NOT_ATTACHED;
        else
        if ((error = m_file.Open(fileName, "rb", true)))
        {
            DBE(("() failed to open \"%s\"\n", fileName));
            count = -error;
        }
        else
        {
            count = pngInfo.Read();
            if ((error = m_file.Close(true)))
                DBE(("() failed to close \"%s\"\n", fileName));
        }
        return count;
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 1/15/2010
     **********************************************************************
     */
    virtual eError Open
    (const char* fileName) 
    {
        eError error = e_ERROR_NOT_ATTACHED;
        
        if ((Attached()))
        if ((error = m_file.Open(fileName, "rb", true)))
            DBE(("() failed to open file \"%s\"\n", fileName));
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 1/15/2010
     **********************************************************************
     */
    virtual eError Close() 
    {
        eError error = e_ERROR_NOT_ATTACHED;
        
        if ((Attached()))
        if ((error = m_file.Close(true)))
            DBE(("() failed to close file\n"));
        return error;
    }
    
    /**
     **********************************************************************
     * Function: OnReadFn
     *
     *   Author: $author$
     *     Date: 6/11/2009
     **********************************************************************
     */
    virtual void OnReadFn
    (png_structp structp,
     png_bytep bytep,
     png_size_t size) 
    {
        TLENGTH length;
        DBT(("() in...\n"));
        if (0 > (length = m_read.Read(bytep, (TSIZE)(size))))
        {
            DBE(("() failed to read %d bytes\n", size));
            m_bytesRead = length;
        }
        else
        m_bytesRead += length;
        DBT(("() ...out\n"));
    }

    /**
     **********************************************************************
     * Function: ReadFn
     *
     *   Author: $author$
     *     Date: 6/11/2009
     **********************************************************************
     */
    static void ReadFn
    (png_structp structp,
     png_bytep bytep,
     png_size_t size) 
    {
        png_voidp error_ptr;
        cPngReadStruct* pngReadStruct;
        DBT(("() in...\n"));
        if ((pngReadStruct = (cPngReadStruct*)
            (error_ptr = png_get_io_ptr(structp))))
            pngReadStruct->OnReadFn(structp, bytep, size);
        DBT(("() ...out\n"));
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGREADSTRUCT_MEMBERS_ONLY) */
#endif /* !defined(CPNGREADSTRUCT_MEMBERS_ONLY) */

#endif /* !defined(_CPNGREADSTRUCT_HXX) || defined(CPNGREADSTRUCT_MEMBERS_ONLY) */
