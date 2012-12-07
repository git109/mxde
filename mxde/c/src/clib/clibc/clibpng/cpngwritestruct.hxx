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
 *   File: cpngwritestruct.hxx
 *
 * Author: $author$
 *   Date: 6/12/2009
 **********************************************************************
 */
#if !defined(_CPNGWRITESTRUCT_HXX) || defined(CPNGWRITESTRUCT_MEMBERS_ONLY)
#if !defined(_CPNGWRITESTRUCT_HXX) && !defined(CPNGWRITESTRUCT_MEMBERS_ONLY)
#define _CPNGWRITESTRUCT_HXX
#endif /* !defined(_CPNGWRITESTRUCT_HXX) && !defined(CPNGWRITESTRUCT_MEMBERS_ONLY) */

#include "cpngstruct.hxx"

/**
 **********************************************************************
 *  Class: cPngWriteStruct
 *
 * Author: $author$
 *   Date: 6/12/2009
 **********************************************************************
 */
class cPngWriteStruct
: public cPngStruct
{
public:
    typedef cPngStruct cExtends;
    typedef cPngWriteStruct cDerives;

    cBYTEFile m_out;
    cBYTEWriterInterface* m_write;

    /**
     **********************************************************************
     * Constructor: cPngWriteStruct
     *
     *      Author: $author$
     *        Date: 6/12/2009
     **********************************************************************
     */
    cPngWriteStruct
    (png_structp attached=NULL,
     bool isCreated=false) 
    : cExtends(attached,isCreated) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cPngWriteStruct
     *
     *     Author: $author$
     *       Date: 6/12/2009
     **********************************************************************
     */
    virtual ~cPngWriteStruct()
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
     *     Date: 6/12/2009
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

        if ((isCreated = (NULL != (detached = png_create_write_struct
            (PNG_LIBPNG_VER_STRING, ((png_voidp)this), ErrorFn, WarnFn)))))
        {
            png_set_write_fn
            (detached, ((png_voidp)this), WriteFn, FlushFn);
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
     *     Date: 6/12/2009
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
            png_destroy_write_struct
            (&detached, png_infopp_NULL);
        else
        if (onlyCreated)
            error = e_ERROR_NOT_ATTACHED;

        return error;
    }

    /**
     **********************************************************************
     * Function: OnWrite
     *
     *   Author: $author$
     *     Date: 6/11/2009
     **********************************************************************
     */
    virtual void OnWrite
    (png_structp structp,
     png_bytep bytep,
     png_size_t size) 
    {
        TLENGTH length;
        DBF(("() in...\n"));
        if (m_write)
        if (0 > (length = m_write->Write(bytep, (TSIZE)(size))))
        {
            DBE(("() failed to write %d bytes\n", size));
            m_bytesWritten = length;
        }
        else
        m_bytesWritten += length;
        DBF(("() ...out\n"));
    }
    /**
     **********************************************************************
     * Function: OnFlush
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    virtual void OnFlush
    (png_structp structp) 
    {
        DBF(("() in...\n"));
        DBF(("() ...out\n"));
    }

    /**
     **********************************************************************
     * Function: WriteFn
     *
     *   Author: $author$
     *     Date: 6/11/2009
     **********************************************************************
     */
    static void WriteFn
    (png_structp structp,
     png_bytep bytep,
     png_size_t size) 
    {
        png_voidp error_ptr;
        cPngWriteStruct* pngWriteStruct;
        DBF(("() in...\n"));
        if ((pngWriteStruct = (cPngWriteStruct*)
            (error_ptr = png_get_io_ptr(structp))))
            pngWriteStruct->OnWrite(structp, bytep, size);
        DBF(("() ...out\n"));
    }
    /**
     **********************************************************************
     * Function: FlushFn
     *
     *   Author: $author$
     *     Date: 6/12/2009
     **********************************************************************
     */
    static void FlushFn
    (png_structp structp) 
    {
        png_voidp error_ptr;
        cPngWriteStruct* pngWriteStruct;
        DBF(("() in...\n"));
        if ((pngWriteStruct = (cPngWriteStruct*)
            (error_ptr = png_get_io_ptr(structp))))
            pngWriteStruct->OnFlush(structp);
        DBF(("() ...out\n"));
    }
};

#endif /* !defined(_CPNGWRITESTRUCT_HXX) || defined(CPNGWRITESTRUCT_MEMBERS_ONLY) */
