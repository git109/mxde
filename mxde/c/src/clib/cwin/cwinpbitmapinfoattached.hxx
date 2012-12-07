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
 *   File: cwinpbitmapinfoattached.hxx
 *
 * Author: $author$
 *   Date: 7/23/2009
 **********************************************************************
 */
#if !defined(_CWINPBITMAPINFOATTACHED_HXX) || defined(CWINPBITMAPINFOATTACHED_MEMBERS_ONLY)
#if !defined(_CWINPBITMAPINFOATTACHED_HXX) && !defined(CWINPBITMAPINFOATTACHED_MEMBERS_ONLY)
#define _CWINPBITMAPINFOATTACHED_HXX
#endif /* !defined(_CWINPBITMAPINFOATTACHED_HXX) && !defined(CWINPBITMAPINFOATTACHED_MEMBERS_ONLY) */

#if !defined(CWINPBITMAPINFOATTACHED_MEMBERS_ONLY)
#include "cwinbaseinterface.hxx"
#include "cwinbase.hxx"
#include "cattached.hxx"
#include "callocated.hxx"

#define CWINPBITMAPINFOALLOCATED_BITS 8
#define CWINPBITMAPINFOALLOCATED_PLANES 1
#define CWINPBITMAPINFOALLOCATED_COMPRESSION BI_RGB

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */


class c_INTERFACE_CLASS cWinPBITMAPINFOAttachedInterface;
/**
 **********************************************************************
 * Typedef: cWinPBITMAPINFOAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 7/23/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cWinPBITMAPINFOAttachedInterface, 
 PBITMAPINFO, UINT, NULL, cWinBaseInterface>
cWinPBITMAPINFOAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinPBITMAPINFOAttachedInterface
 *
 * Author: $author$
 *   Date: 7/23/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinPBITMAPINFOAttachedInterface
: virtual public cWinPBITMAPINFOAttachedInterfaceImplements
{
public:
    typedef cWinPBITMAPINFOAttachedInterfaceImplements cImplements;
    typedef cWinPBITMAPINFOAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cWinPBITMAPINFOAttachedImplement;
/**
 **********************************************************************
 * Typedef: cWinPBITMAPINFOAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 7/23/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cWinPBITMAPINFOAttachedImplement, 
 cWinPBITMAPINFOAttachedInterface, 
 PBITMAPINFO, UINT, NULL>
cWinPBITMAPINFOAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cWinPBITMAPINFOAttachedImplement
 *
 * Author: $author$
 *   Date: 7/23/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinPBITMAPINFOAttachedImplement
: virtual public cWinPBITMAPINFOAttachedImplementImplements
{
public:
    typedef cWinPBITMAPINFOAttachedImplementImplements cImplements;
    typedef cWinPBITMAPINFOAttachedImplement cDerives;
};
class c_EXPORT_CLASS cWinPBITMAPINFOAttached;
/**
 **********************************************************************
 * Typedef: cWinPBITMAPINFOAttachedExtends
 *
 *  Author: $author$
 *    Date: 7/23/2009
 **********************************************************************
 */
typedef cAttachedT
<cWinPBITMAPINFOAttached, 
 cWinPBITMAPINFOAttachedImplement, 
 cWinPBITMAPINFOAttachedInterface,
 PBITMAPINFO, UINT, NULL, cWinBase>
cWinPBITMAPINFOAttachedExtends;
/**
 **********************************************************************
 *  Class: cWinPBITMAPINFOAttached
 *
 * Author: $author$
 *   Date: 7/23/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinPBITMAPINFOAttached
: public cWinPBITMAPINFOAttachedExtends
{
public:
    typedef cWinPBITMAPINFOAttachedExtends cExtends;
    typedef cWinPBITMAPINFOAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cWinPBITMAPINFOAttached
     *
     *      Author: $author$
     *        Date: 7/23/2009
     **********************************************************************
     */
    cWinPBITMAPINFOAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cWinPBITMAPINFOAllocatedInterface;
/**
 **********************************************************************
 * Typedef: cWinPBITMAPINFOAllocatedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 7/23/2009
 **********************************************************************
 */
typedef cAllocatedInterfaceT
<cWinPBITMAPINFOAllocatedInterface, cWinPBITMAPINFOAttachedInterface>
cWinPBITMAPINFOAllocatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinPBITMAPINFOAllocatedInterface
 *
 * Author: $author$
 *   Date: 7/23/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinPBITMAPINFOAllocatedInterface
: virtual public cWinPBITMAPINFOAllocatedInterfaceImplements
{
public:
    typedef cWinPBITMAPINFOAllocatedInterfaceImplements cImplements;
    typedef cWinPBITMAPINFOAllocatedInterface cDerives;
};
class c_EXPORT_CLASS cWinPBITMAPINFOAllocatedImplement;
/**
 **********************************************************************
 * Typedef: cWinPBITMAPINFOAllocatedImplementImplements
 *
 *  Author: $author$
 *    Date: 7/23/2009
 **********************************************************************
 */
typedef cAllocatedImplementT
<cWinPBITMAPINFOAllocatedImplement, cWinPBITMAPINFOAllocatedInterface>
cWinPBITMAPINFOAllocatedImplementImplements;
/**
 **********************************************************************
 *  Class: cWinPBITMAPINFOAllocatedImplement
 *
 * Author: $author$
 *   Date: 7/23/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinPBITMAPINFOAllocatedImplement
: virtual public cWinPBITMAPINFOAllocatedImplementImplements
{
public:
    typedef cWinPBITMAPINFOAllocatedImplementImplements cImplements;
    typedef cWinPBITMAPINFOAllocatedImplement cDerives;
};
class c_EXPORT_CLASS cWinPBITMAPINFOAllocated;
/**
 **********************************************************************
 * Typedef: cWinPBITMAPINFOAllocatedExtends
 *
 *  Author: $author$
 *    Date: 7/23/2009
 **********************************************************************
 */
typedef cAllocatedT
<cWinPBITMAPINFOAllocated, 
 cWinPBITMAPINFOAllocatedImplement, 
 cWinPBITMAPINFOAttached>
cWinPBITMAPINFOAllocatedExtends;
/**
 **********************************************************************
 *  Class: cWinPBITMAPINFOAllocated
 *
 * Author: $author$
 *   Date: 7/23/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinPBITMAPINFOAllocated
: public cWinPBITMAPINFOAllocatedExtends
{
public:
    typedef cWinPBITMAPINFOAllocatedExtends cExtends;
    typedef cWinPBITMAPINFOAllocated cDerives;

    /**
     **********************************************************************
     * Constructor: cWinPBITMAPINFOAllocated
     *
     *      Author: $author$
     *        Date: 7/23/2009
     **********************************************************************
     */
    cWinPBITMAPINFOAllocated
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isAllocated=false) 
    : cExtends(isAllocated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cWinPBITMAPINFOAllocated
     *
     *     Author: $author$
     *       Date: 7/23/2009
     **********************************************************************
     */
    virtual ~cWinPBITMAPINFOAllocated()
    {
        eError error;
        if ((error = Freed()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Allocate
     *
     *   Author: $author$
     *     Date: 7/23/2009
     **********************************************************************
     */
    virtual eError Allocate
    (BITMAPINFOHEADER& bmiHeader,
     RGBQUAD* colorTable = 0,
     bool onlyFreed=false) 
#if defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT) 
        error = Allocate
        (bmiHeader.biWidth, bmiHeader.biHeight,
         bmiHeader.biBitCount, bmiHeader.biPlanes,
         colorTable, onlyFreed);
#else /* !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Allocate
     *
     *   Author: $author$
     *     Date: 7/23/2009
     **********************************************************************
     */
    virtual eError Allocate
    (TSIZE width,
     TSIZE height,
     TSIZE bits = CWINPBITMAPINFOALLOCATED_BITS,
     TSIZE planes = CWINPBITMAPINFOALLOCATED_PLANES,
     RGBQUAD* colorTable = 0,
     bool onlyFreed=false) 
#if defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT) 
        eError error2;
        tAttachedTo detached;

        if ((error2 = Freed(onlyFreed)))
            return error2;

        if ((detached = AllocateDetached
            (width, height, bits, planes, colorTable)))
        {
            if (detached == (Attach(detached)))
            if (0 < (SetIsAllocated()))
                return e_ERROR_NONE;
            else Detach();

            FreeDetached(detached);
        }
#else /* !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 7/23/2009
     **********************************************************************
     */
    virtual eError Free
    (bool onlyAllocated=false) 
#if defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT) 
        tAttachedTo detached;

        if ((error = Allocated(onlyAllocated, true)))
            return error;

        if ((detached = Detach()))
            error = FreeDetached(detached);

#else /* !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AllocateDetached
     *
     *   Author: $author$
     *     Date: 7/23/2009
     **********************************************************************
     */
    virtual tAttachedTo AllocateDetached
    (TSIZE width,
     TSIZE height,
     TSIZE bits = CWINPBITMAPINFOALLOCATED_BITS,
     TSIZE planes = CWINPBITMAPINFOALLOCATED_PLANES,
     RGBQUAD* colorTable = 0) 
#if defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE */
    {
        tAttachedTo detached = (tAttachedTo)(vUnattached);
#if !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT)
        TSIZE padded = ((4-(width & 3)) & 3);
        TSIZE imageSize = ((width+padded)*height);
        TSIZE colors = (1 << (bits*planes));
        TSIZE colorSize = ((colors-1)*sizeof(RGBQUAD));
        TSIZE size = (sizeof(BITMAPINFO)+(colorTable?colorSize:0));
        TSIZE color;
        BYTE* byte;

        if ((detached = (tAttachedTo)(byte = new BYTE[size])))
        {
            BITMAPINFO& bmi = *detached;

            memset(byte, 0, size);

            bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
            bmi.bmiHeader.biWidth = width;
            bmi.bmiHeader.biHeight = height;
            bmi.bmiHeader.biBitCount = (WORD)(bits);
            bmi.bmiHeader.biPlanes = (WORD)(planes);
            bmi.bmiHeader.biSizeImage = imageSize;
            bmi.bmiHeader.biCompression = CWINPBITMAPINFOALLOCATED_COMPRESSION;
            bmi.bmiHeader.biClrUsed = (colorTable?colors:0);

            if (colorTable)
            for (color = 0; color < colors; color++)
            {
                bmi.bmiColors[color] = colorTable[color];
            }
        }
#else /* !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: FreeDetached
     *
     *   Author: $author$
     *     Date: 7/23/2009
     **********************************************************************
     */
    virtual eError FreeDetached
    (tAttachedTo detached) 
#if defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
#if !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT) 
        BYTE* byte;
        if ((byte = (BYTE*)(detached)))
        {
            delete[] byte;
            error = e_ERROR_NONE;
        }
#else /* !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINPBITMAPINFOALLOCATED_MEMBER_FUNCS_INTERFACE) */
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINPBITMAPINFOATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CWINPBITMAPINFOATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CWINPBITMAPINFOATTACHED_HXX) || defined(CWINPBITMAPINFOATTACHED_MEMBERS_ONLY) */
