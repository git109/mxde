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
 *   File: cpnginterface.hxx
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
#if !defined(_CPNGINTERFACE_HXX) || defined(CPNGINTERFACE_MEMBERS_ONLY)
#if !defined(_CPNGINTERFACE_HXX) && !defined(CPNGINTERFACE_MEMBERS_ONLY)
#define _CPNGINTERFACE_HXX
#endif /* !defined(_CPNGINTERFACE_HXX) && !defined(CPNGINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"
#include "cpng.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cPngInterface
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cPngInterface
: virtual public cInterfaceBase
{
public:
    typedef cInterfaceBase cImplements;
    typedef cPngInterface cDerives;
#else /* !defined(CPNGINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGINTERFACE_MEMBERS_ONLY) 
/* include cPng member functions interface
 */
#define CPNG_MEMBERS_ONLY
#define CPNG_MEMBER_FUNCS_INTERFACE
#include "cpng.hxx"
#undef CPNG_MEMBER_FUNCS_INTERFACE
#undef CPNG_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cPngImplement
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
class cPngImplement
: virtual public cPngInterface
{
public:
    typedef cPngInterface cImplements;
/* include cPng member functions implement
 */
#define CPNG_MEMBERS_ONLY
#define CPNG_MEMBER_FUNCS_IMPLEMENT
#include "cpng.hxx"
#undef CPNG_MEMBER_FUNCS_IMPLEMENT
#undef CPNG_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CPNGINTERFACE_HXX) || defined(CPNGINTERFACE_MEMBERS_ONLY) */
