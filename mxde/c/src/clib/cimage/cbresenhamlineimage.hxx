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
 *   File: cbresenhamlineimage.hxx
 *
 * Author: $author$
 *   Date: 7/20/2009
 **********************************************************************
 */
#if !defined(_CBRESENHAMLINEIMAGE_HXX) || defined(CBRESENHAMLINEIMAGE_MEMBERS_ONLY)
#if !defined(_CBRESENHAMLINEIMAGE_HXX) && !defined(CBRESENHAMLINEIMAGE_MEMBERS_ONLY)
#define _CBRESENHAMLINEIMAGE_HXX
#endif /* !defined(_CBRESENHAMLINEIMAGE_HXX) && !defined(CBRESENHAMLINEIMAGE_MEMBERS_ONLY) */

#if !defined(CBRESENHAMLINEIMAGE_MEMBERS_ONLY)
#include "cbresenhamline.hxx"
#include "cbaseimage.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cBresenhamLineImage;
/**
 **********************************************************************
 * Typedef: cBresenhamLineImageExtends
 *
 *  Author: $author$
 *    Date: 7/20/2009
 **********************************************************************
 */
typedef cBresenhamLineT
<cBresenhamLineImage, cBaseImage, cImageInterface>
cBresenhamLineImageExtends;
/**
 **********************************************************************
 *  Class: cBresenhamLineImage
 *
 * Author: $author$
 *   Date: 7/20/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cBresenhamLineImage
: public cBresenhamLineImageExtends
{
public:
    typedef cBresenhamLineImageExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cBresenhamLineImage
     *
     *       Author: $author$
     *         Date: 7/20/2009
     **********************************************************************
     */
    cBresenhamLineImage
    (cImageInterface& image) 
    : cExtends(image)
    {
    }
#else /* !defined(CBRESENHAMLINEIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CBRESENHAMLINEIMAGE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: DrawLine
     *
     *   Author: $author$
     *     Date: 7/20/2009
     **********************************************************************
     */
    virtual void DrawLine
    (tImageInterface& image, tInt x1,tInt y1, tInt x2,tInt y2) 
#if defined(CBRESENHAMLINEIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CBRESENHAMLINEIMAGE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CBRESENHAMLINEIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        BresenhamLineT<cExtends, tPixel, tInt>
        (*this, image, x1,y1, x2,y2);
#else /* !defined(CBRESENHAMLINEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBRESENHAMLINEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CBRESENHAMLINEIMAGE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CBRESENHAMLINEIMAGE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CBRESENHAMLINEIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CBRESENHAMLINEIMAGE_MEMBERS_ONLY) */

#endif /* !defined(_CBRESENHAMLINEIMAGE_HXX) || defined(CBRESENHAMLINEIMAGE_MEMBERS_ONLY) */
