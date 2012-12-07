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
 *   File: cbaseimage.hxx
 *
 * Author: $author$
 *   Date: 7/18/2009
 **********************************************************************
 */
#if !defined(_CBASEIMAGE_HXX) || defined(CBASEIMAGE_MEMBERS_ONLY)
#if !defined(_CBASEIMAGE_HXX) && !defined(CBASEIMAGE_MEMBERS_ONLY)
#define _CBASEIMAGE_HXX
#endif /* !defined(_CBASEIMAGE_HXX) && !defined(CBASEIMAGE_MEMBERS_ONLY) */

#if !defined(CBASEIMAGE_MEMBERS_ONLY)
#include "cexportbase.hxx"
#include "cimageinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cBaseImage;

#undef CDB_CLASS
#define CDB_CLASS "cBaseImageT"
/**
 **********************************************************************
 *  Class: cBaseImageT
 *
 * Author: $author$
 *   Date: 7/18/2009
 **********************************************************************
 */
template
<class TDerives=cBaseImage,
 class TImageInterface=cImageInterface,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TExportBase=cExportBase,
 class TExtends=TExportBase>

class c_EXPORT_CLASS cBaseImageT
: public TExtends
{
public:
    typedef TExtends cExtends;

    typedef TInt tInt;
    typedef TSize tSize;
    typedef TOffset tOffset;
    typedef TImageInterface tImageInterface;

    tImageInterface& m_image;

    /**
     **********************************************************************
     *  Constructor: cBaseImageT
     *
     *       Author: $author$
     *         Date: 7/18/2009
     **********************************************************************
     */
    cBaseImageT
    (tImageInterface& image)
    : m_image(image)
    {
    }
#else /* !defined(CBASEIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CBASEIMAGE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 7/18/2009
     **********************************************************************
     */
    virtual eError Plot
    (tImageInterface& image,
     tOffset x,tOffset y) 
#if defined(CBASEIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBASEIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = image.Plot(x,y);
#if !defined(CBASEIMAGE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBASEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBASEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CBASEIMAGE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 7/18/2009
     **********************************************************************
     */
    virtual eError Fill
    (tImageInterface& image,
     tOffset x,tOffset y, tSize w,tSize h) 
#if defined(CBASEIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBASEIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = image.Fill(x,y, w,h);
#if !defined(CBASEIMAGE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBASEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBASEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CBASEIMAGE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 8/8/2009
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x,
     tOffset y) 
#if defined(CBASEIMAGE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CBASEIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CBASEIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        error = m_image.Plot(x,y);
#else /* !defined(CBASEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBASEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CBASEIMAGE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 8/8/2009
     **********************************************************************
     */
    virtual eError Fill
    (tOffset x,
     tOffset y, 
     tSize w,
     tSize h) 
#if defined(CBASEIMAGE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CBASEIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CBASEIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        error = m_image.Fill(x,y, w,h);
#else /* !defined(CBASEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBASEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CBASEIMAGE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CBASEIMAGE_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cBaseImageExtends
 *
 *  Author: $author$
 *    Date: 7/18/2009
 **********************************************************************
 */
typedef cBaseImageT<>
cBaseImageExtends;
/**
 **********************************************************************
 *  Class: cBaseImage
 *
 * Author: $author$
 *   Date: 7/18/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cBaseImage
: public cBaseImageExtends
{
public:
    typedef cBaseImageExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cBaseImage
     *
     *       Author: $author$
     *         Date: 7/18/2009
     **********************************************************************
     */
    cBaseImage
    (cImageInterface& image) 
    : cExtends(image)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CBASEIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CBASEIMAGE_MEMBERS_ONLY) */

#endif /* !defined(_CBASEIMAGE_HXX) || defined(CBASEIMAGE_MEMBERS_ONLY) */
