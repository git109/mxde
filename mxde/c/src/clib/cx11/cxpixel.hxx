/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$  
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
 *   File: cxpixel.hxx
 *
 * Author: $author$           
 *   Date: 6/9/2010
 **********************************************************************
 */
#if !defined(_CXPIXEL_HXX) || defined(CXPIXEL_MEMBERS_ONLY)
#if !defined(_CXPIXEL_HXX) && !defined(CXPIXEL_MEMBERS_ONLY)
#define _CXPIXEL_HXX
#endif /* !defined(_CXPIXEL_HXX) && !defined(CXPIXEL_MEMBERS_ONLY) */

#if !defined(CXPIXEL_MEMBERS_ONLY)
#include "cxpixelinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXPixelExtend
 *
 *  Author: $author$           
 *    Date: 6/9/2010
 **********************************************************************
 */
typedef cXPixelAllocated
cXPixelExtend;
/**
 **********************************************************************
 *  Class: cXPixel
 *
 * Author: $author$           
 *   Date: 6/9/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXPixel
: virtual public cXPixelImplement,
  public cXPixelExtend
{
public:
    typedef cXPixelImplement cImplements;
    typedef cXPixelExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXPixel
     *
     *       Author: $author$           
     *         Date: 6/9/2010
     **********************************************************************
     */
    cXPixel
    (Pixel attached=0,
     bool isAllocated=false)
    : cExtends(attached, isAllocated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXPixel
     *
     *      Author: $author$           
     *        Date: 6/9/2010
     **********************************************************************
     */
    virtual ~cXPixel()
    {
    }
#else /* !defined(CXPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CXPIXEL_MEMBERS_ONLY) */

#if !defined(CXPIXEL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CXPIXEL_MEMBERS_ONLY) */

#endif /* !defined(_CXPIXEL_HXX) || defined(CXPIXEL_MEMBERS_ONLY) */
