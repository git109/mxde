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
 *   File: cpngstruct.hxx
 *
 * Author: $author$
 *   Date: 6/11/2009
 **********************************************************************
 */
#if !defined(_CPNGSTRUCT_HXX) || defined(CPNGSTRUCT_MEMBERS_ONLY)
#if !defined(_CPNGSTRUCT_HXX) && !defined(CPNGSTRUCT_MEMBERS_ONLY)
#define _CPNGSTRUCT_HXX
#endif /* !defined(_CPNGSTRUCT_HXX) && !defined(CPNGSTRUCT_MEMBERS_ONLY) */

#if !defined(CPNGSTRUCT_MEMBERS_ONLY)
#include "cpngstructinterface.hxx"
#include "ccreated.hxx"
#include "cdebug.hxx"

class c_EXPORT_CLASS cPngStruct;
/**
 **********************************************************************
 * Typedef: cPngStructExtends
 *
 *  Author: $author$
 *    Date: 6/11/2009
 **********************************************************************
 */
typedef cCreatedT
<cPngStruct, 
 cPngStructImplement, 
 cPngStructAttached>
cPngStructExtends;
/**
 **********************************************************************
 *  Class: cPngStruct
 *
 * Author: $author$
 *   Date: 6/11/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cPngStruct
: public cPngStructExtends
{
public:
    typedef cPngStructExtends cExtends;
    typedef cPngStruct cDerives;

    png_int_32 m_bytesRead, m_bytesWritten;

    /**
     **********************************************************************
     * Constructor: cPngStruct
     *
     *      Author: $author$
     *        Date: 6/11/2009
     **********************************************************************
     */
    cPngStruct
    (png_structp attached=NULL,
     bool isCreated=false) 
    : cExtends(isCreated),
      m_bytesRead(0), 
      m_bytesWritten(0)
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cPngStruct
     *
     *     Author: $author$
     *       Date: 6/11/2009
     **********************************************************************
     */
    virtual ~cPngStruct()
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
        eError error = e_ERROR_NOT_ALLOWED;
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
        eError error = e_ERROR_NOT_ALLOWED;
        return error;
    }

    /**
     **********************************************************************
     * Function: OnError
     *
     *   Author: $author$
     *     Date: 6/11/2009
     **********************************************************************
     */
    virtual void OnError
    (png_structp structp,
     png_const_charp charp) 
    {
        DBF(("() in...\n"));
        DBF(("() ...out\n"));
    }
    /**
     **********************************************************************
     * Function: OnWarn
     *
     *   Author: $author$
     *     Date: 6/11/2009
     **********************************************************************
     */
    virtual void OnWarn
    (png_structp structp,
     png_const_charp charp) 
    {
        DBF(("() in...\n"));
        DBF(("() ...out\n"));
    }

    /**
     **********************************************************************
     * Function: ErrorFn
     *
     *   Author: $author$
     *     Date: 6/11/2009
     **********************************************************************
     */
    static void ErrorFn
    (png_structp structp,
     png_const_charp charp) 
    {
        png_voidp error_ptr;
        cPngStruct* pngStruct;
        DBF(("() in...\n"));
        if ((pngStruct = (cPngStruct*)
            (error_ptr = png_get_error_ptr(structp))))
            pngStruct->OnError(structp, charp);
        DBF(("() ...out\n"));
    }
    /**
     **********************************************************************
     * Function: WarnFn
     *
     *   Author: $author$
     *     Date: 6/11/2009
     **********************************************************************
     */
    static void WarnFn
    (png_structp structp,
     png_const_charp charp) 
    {
        png_voidp error_ptr;
        cPngStruct* pngStruct;
        DBF(("() in...\n"));
        if ((pngStruct = (cPngStruct*)
            (error_ptr = png_get_error_ptr(structp))))
            pngStruct->OnWarn(structp, charp);
        DBF(("() ...out\n"));
    }
#else /* !defined(CPNGSTRUCT_MEMBERS_ONLY) */
#endif /* !defined(CPNGSTRUCT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: SetBytesRead
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual png_int_32 SetBytesRead
    (png_int_32 toBytes) 
#if defined(CPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CPNGSTRUCT_MEMBER_FUNCS_INTERFACE */
    {
        png_int_32 bytes = 0;
#if !defined(CPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
        bytes = m_bytesRead;
        m_bytesRead = toBytes;
#else /* !defined(CPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return bytes;
    }
#endif /* defined(CPNGSTRUCT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetBytesRead
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual png_int_32 GetBytesRead() const 
#if defined(CPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CPNGSTRUCT_MEMBER_FUNCS_INTERFACE */
    {
        png_int_32 bytes = 0;
#if !defined(CPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
        bytes = m_bytesRead;
#else /* !defined(CPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return bytes;
    }
#endif /* defined(CPNGSTRUCT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetBytesWritten
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual png_int_32 SetBytesWritten
    (png_int_32 toBytes) 
#if defined(CPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CPNGSTRUCT_MEMBER_FUNCS_INTERFACE */
    {
        png_int_32 bytes = 0;
#if !defined(CPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
        bytes = m_bytesWritten;
        m_bytesWritten = toBytes;
#else /* !defined(CPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return bytes;
    }
#endif /* defined(CPNGSTRUCT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetBytesWritten
     *
     *   Author: $author$
     *     Date: 6/13/2009
     **********************************************************************
     */
    virtual png_int_32 GetBytesWritten() const 
#if defined(CPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CPNGSTRUCT_MEMBER_FUNCS_INTERFACE */
    {
        png_int_32 bytes = 0;
#if !defined(CPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
        bytes = m_bytesWritten;
#else /* !defined(CPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return bytes;
    }
#endif /* defined(CPNGSTRUCT_MEMBER_FUNCS_INTERFACE) */

#if !defined(CPNGSTRUCT_MEMBERS_ONLY) 
};
#else /* !defined(CPNGSTRUCT_MEMBERS_ONLY) */
#endif /* !defined(CPNGSTRUCT_MEMBERS_ONLY) */

#endif /* !defined(_CPNGSTRUCT_HXX) || defined(CPNGSTRUCT_MEMBERS_ONLY) */
