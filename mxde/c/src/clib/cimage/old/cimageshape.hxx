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
 *   File: cimageshape.hxx
 *
 * Author: $author$
 *   Date: 8/6/2009
 **********************************************************************
 */
#if !defined(_CIMAGESHAPE_HXX) || defined(CIMAGESHAPE_MEMBERS_ONLY)
#if !defined(_CIMAGESHAPE_HXX) && !defined(CIMAGESHAPE_MEMBERS_ONLY)
#define _CIMAGESHAPE_HXX
#endif /* !defined(_CIMAGESHAPE_HXX) && !defined(CIMAGESHAPE_MEMBERS_ONLY) */

#if !defined(CIMAGESHAPE_MEMBERS_ONLY)
#include "cimageshapeinterface.hxx"
#include "cimageshapeitem.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cImageShape
 *
 * Author: $author$
 *   Date: 8/6/2009
 **********************************************************************
 */
class cImageShape
: virtual public cImageShapeImplement
{
public:
    typedef cImageShapeImplement cImplements;
    
    cImageShapeItem m_item;
    cImageInterface& m_image;
    tSize m_width, m_height;
    
    /**
     **********************************************************************
     *  Constructor: cImageShape
     *
     *       Author: $author$
     *         Date: 8/6/2009
     **********************************************************************
     */
    cImageShape
    (cImageInterface& image,
     tSize width=0,
     tSize height=0)
    : m_item(*this),
      m_image(image), 
      m_width(width), 
      m_height(height)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cImageShape
     *
     *      Author: $author$
     *        Date: 8/6/2009
     **********************************************************************
     */
    ~cImageShape()
    {
    }
#else /* !defined(CIMAGESHAPE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGESHAPE_MEMBERS_ONLY) */

#if !defined(CIMAGESHAPE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGESHAPE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGESHAPE_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGESHAPE_HXX) || defined(CIMAGESHAPE_MEMBERS_ONLY) */
