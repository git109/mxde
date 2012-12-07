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
 *   File: cpngcolorinterface.hxx
 *
 * Author: $author$
 *   Date: 6/15/2009
 **********************************************************************
 */
#if !defined(_CPNGCOLORINTERFACE_HXX) || defined(CPNGCOLORINTERFACE_MEMBERS_ONLY)
#if !defined(_CPNGCOLORINTERFACE_HXX) && !defined(CPNGCOLORINTERFACE_MEMBERS_ONLY)
#define _CPNGCOLORINTERFACE_HXX
#endif /* !defined(_CPNGCOLORINTERFACE_HXX) && !defined(CPNGCOLORINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGCOLORINTERFACE_MEMBERS_ONLY)
#include "cpngcolorattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cPngColorInterface
 *
 * Author: $author$
 *   Date: 6/15/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cPngColorInterface
: virtual public cPngColorAttachedInterface
{
public:
#else /* !defined(CPNGCOLORINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGCOLORINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGCOLORINTERFACE_MEMBERS_ONLY)
/* include cPngColor member functions interface
 */
#define CPNGCOLOR_MEMBERS_ONLY
#define CPNGCOLOR_MEMBER_FUNCS_INTERFACE
#include "cpngcolor.hxx"
#undef CPNGCOLOR_MEMBER_FUNCS_INTERFACE
#undef CPNGCOLOR_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cPngColorImplement
 *
 * Author: $author$
 *   Date: 6/15/2009
 **********************************************************************
 */
class cPngColorImplement
: virtual public cPngColorInterface
{
public:
    typedef cPngColorInterface cImplements;
    typedef cPngColorImplement cDerives;

/* include cPngColor member functions implement
 */
#define CPNGCOLOR_MEMBERS_ONLY
#define CPNGCOLOR_MEMBER_FUNCS_IMPLEMENT
#include "cpngcolor.hxx"
#undef CPNGCOLOR_MEMBER_FUNCS_IMPLEMENT
#undef CPNGCOLOR_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGCOLORINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGCOLORINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CPNGCOLORINTERFACE_HXX) || defined(CPNGCOLORINTERFACE_MEMBERS_ONLY) */
