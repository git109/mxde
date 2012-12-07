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
 *   File: cpngcolorpalette.hxx
 *
 * Author: $author$
 *   Date: 6/14/2009
 **********************************************************************
 */
#if !defined(_CPNGCOLORPALETTE_HXX) || defined(CPNGCOLORPALETTE_MEMBERS_ONLY)
#if !defined(_CPNGCOLORPALETTE_HXX) && !defined(CPNGCOLORPALETTE_MEMBERS_ONLY)
#define _CPNGCOLORPALETTE_HXX
#endif /* !defined(_CPNGCOLORPALETTE_HXX) && !defined(CPNGCOLORPALETTE_MEMBERS_ONLY) */

#if !defined(CPNGCOLORPALETTE_MEMBERS_ONLY)
#include "cpngcolorattached.hxx"
#include "cpngcolor.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cPngColorPalette
 *
 * Author: $author$
 *   Date: 6/14/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cPngColorPalette
: public cPngColorAttached
{
public:
    typedef cPngColorAttached cExtends;
    typedef cPngColorPalette cDerives;

    cPngStructInterface& m_pngStruct;
    cPngInfoInterface& m_pngInfo;

    int m_paletteColors;

    /**
     **********************************************************************
     * Constructor: cPngColorPalette
     *
     *      Author: $author$
     *        Date: 6/14/2009
     **********************************************************************
     */
    cPngColorPalette
    (cPngStructInterface& pngStruct,
     cPngInfoInterface& pngInfo,
     png_colorp attached=NULL) 
    : cExtends(attached),
      m_pngStruct(pngStruct),
      m_pngInfo(pngInfo),
      m_paletteColors(0)
    {
    }

    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 6/15/2009
     **********************************************************************
     */
    virtual int Get() 
    {
        int count = -e_ERROR_NOT_ATTACHED;
        png_int_32 result;
        png_structp structAttached;
        png_infop infoAttached;

        if ((structAttached = m_pngStruct.Attached())
            && (infoAttached = m_pngInfo.Attached()))

        if ((result = png_get_PLTE
             (structAttached, infoAttached, 
              &m_attached, &m_paletteColors)))
            count = m_paletteColors;
        else
        count = -e_ERROR_FAILED;
        return count;
    }
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 6/15/2009
     **********************************************************************
     */
    virtual int Put() 
    {
        int count = -e_ERROR_NOT_ATTACHED;
        return count;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGCOLORPALETTE_MEMBERS_ONLY) */
#endif /* !defined(CPNGCOLORPALETTE_MEMBERS_ONLY) */

#endif /* !defined(_CPNGCOLORPALETTE_HXX) || defined(CPNGCOLORPALETTE_MEMBERS_ONLY) */
