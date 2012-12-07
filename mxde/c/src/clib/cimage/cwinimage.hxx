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
 *   File: cwinimage.hxx
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
#if !defined(_CWINIMAGE_HXX) || defined(CWINIMAGE_MEMBERS_ONLY)
#if !defined(_CWINIMAGE_HXX) && !defined(CWINIMAGE_MEMBERS_ONLY)
#define _CWINIMAGE_HXX
#endif /* !defined(_CWINIMAGE_HXX) && !defined(CWINIMAGE_MEMBERS_ONLY) */

#if !defined(CWINIMAGE_MEMBERS_ONLY)
#include "cwinimageinterface.hxx"
#include "cimage.hxx"
#include "cwindc.hxx"

/**
 **********************************************************************
 *  Class: cWinImage
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinImage
: virtual public cWinImageImplement,
  public cImage
{
public:
    typedef cWinImageImplement cImplements;
    typedef cImage cExtends;
    typedef cWinImage cDerives;

/* include cWinImage interface member definitions
 */
#define CWINIMAGEINTERFACE_MEMBERS_ONLY
#include "cwinimageinterface.hxx"
#undef CWINIMAGEINTERFACE_MEMBERS_ONLY

    cWinDCInterface& m_dc;

    /**
     **********************************************************************
     * Constructor: cWinImage
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cWinImage
    (cWinDCInterface& dc,
     cImageInterface* image=0) 
    : cExtends(image),
      m_dc(dc)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinImage
     *
     *     Author: $author$
     *       Date: 5/27/2009
     **********************************************************************
     */
    virtual ~cWinImage()
    {
    }
#else /* !defined(CWINIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGE_MEMBERS_ONLY) */

#if !defined(CWINIMAGE_MEMBER_FUNCS_IMPLEMENT) 
    /**
     **********************************************************************
     * Function: DC
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual cWinDCInterface& DC() const 
#if defined(CWINIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        cWinDCInterface& dc = (cWinDCInterface&)(m_dc);
        return dc;
    }
#endif /* defined(CWINIMAGE_MEMBER_FUNCS_INTERFACE) */
#else /* !defined(CWINIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINIMAGE_MEMBER_FUNCS_IMPLEMENT) */

#if !defined(CWINIMAGE_MEMBERS_ONLY) 
};

#else /* !defined(CWINIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGE_MEMBERS_ONLY) */

#endif /* !defined(_CWINIMAGE_HXX) || defined(CWINIMAGE_MEMBERS_ONLY) */
