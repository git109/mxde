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
 *   File: cpngcolor.hxx
 *
 * Author: $author$
 *   Date: 6/15/2009
 **********************************************************************
 */
#if !defined(_CPNGCOLOR_HXX) || defined(CPNGCOLOR_MEMBERS_ONLY)
#if !defined(_CPNGCOLOR_HXX) && !defined(CPNGCOLOR_MEMBERS_ONLY)
#define _CPNGCOLOR_HXX
#endif /* !defined(_CPNGCOLOR_HXX) && !defined(CPNGCOLOR_MEMBERS_ONLY) */

#if !defined(CPNGCOLOR_MEMBERS_ONLY)
#include "cpngcolorinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cPngColor
 *
 * Author: $author$
 *   Date: 6/15/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cPngColor
: virtual public cPngColorImplement,
  public cPngColorAttached
{
public:
    typedef cPngColorAttached cExtends;

    cPngStructInterface& m_pngStruct;
    cPngInfoInterface& m_pngInfo;

    /**
     **********************************************************************
     *  Constructor: cPngColor
     *
     *       Author: $author$
     *         Date: 6/15/2009
     **********************************************************************
     */
    cPngColor
    (cPngStructInterface& pngStruct,
     cPngInfoInterface& pngInfo,
     png_colorp attached=NULL)
    : cExtends(attached),
      m_pngStruct(pngStruct),
      m_pngInfo(pngInfo)
    {
    }
#else /* !defined(CPNGCOLOR_MEMBERS_ONLY) */
#endif /* !defined(CPNGCOLOR_MEMBERS_ONLY) */

#if !defined(CPNGCOLOR_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGCOLOR_MEMBERS_ONLY) */
#endif /* !defined(CPNGCOLOR_MEMBERS_ONLY) */

#endif /* !defined(_CPNGCOLOR_HXX) || defined(CPNGCOLOR_MEMBERS_ONLY) */
