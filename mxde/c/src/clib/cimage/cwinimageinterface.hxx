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
 *   File: cwinimageinterface.hxx
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
#if !defined(_CWINIMAGEINTERFACE_HXX) || defined(CWINIMAGEINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINIMAGEINTERFACE_HXX) && !defined(CWINIMAGEINTERFACE_MEMBERS_ONLY)
#define _CWINIMAGEINTERFACE_HXX
#endif /* !defined(_CWINIMAGEINTERFACE_HXX) && !defined(CWINIMAGEINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINIMAGEINTERFACE_MEMBERS_ONLY)
#include "cimageinterface.hxx"
#include "cwindc.hxx"

/**
 **********************************************************************
 *  Class: cWinImageInterface
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinImageInterface
: virtual public cImageInterface
{
public:
    typedef cImageInterface cImplements;
    typedef cWinImageInterface cDerives;
#else /* !defined(CWINIMAGEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINIMAGEINTERFACE_MEMBERS_ONLY) 
/* include cWinImage member functions interface
 */
#define CWINIMAGE_MEMBERS_ONLY
#define CWINIMAGE_MEMBER_FUNCS_INTERFACE
#include "cwinimage.hxx"
#undef CWINIMAGE_MEMBER_FUNCS_INTERFACE
#undef CWINIMAGE_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cWinImageImplement
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class cWinImageImplement
: virtual public cWinImageInterface
{
public:
    typedef cWinImageInterface cImplements;
    typedef cWinImageImplement cDerives;

/* include cWinImage interface member definitions
 */
#define CWINIMAGEINTERFACE_MEMBERS_ONLY
#include "cwinimageinterface.hxx"
#undef CWINIMAGEINTERFACE_MEMBERS_ONLY

/* include cWinImage member functions implement
 */
#define CWINIMAGE_MEMBERS_ONLY
#define CWINIMAGE_MEMBER_FUNCS_IMPLEMENT
#include "cwinimage.hxx"
#undef CWINIMAGE_MEMBER_FUNCS_IMPLEMENT
#undef CWINIMAGE_MEMBERS_ONLY
};

#else /* !defined(CWINIMAGEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINIMAGEINTERFACE_HXX) || defined(CWINIMAGEINTERFACE_MEMBERS_ONLY) */
