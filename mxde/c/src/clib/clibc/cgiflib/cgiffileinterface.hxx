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
 *   File: cgiffileinterface.hxx
 *
 * Author: $author$
 *   Date: 11/11/2010
 **********************************************************************
 */
#if !defined(_CGIFFILEINTERFACE_HXX) || defined(CGIFFILEINTERFACE_MEMBERS_ONLY)
#if !defined(_CGIFFILEINTERFACE_HXX) && !defined(CGIFFILEINTERFACE_MEMBERS_ONLY)
#define _CGIFFILEINTERFACE_HXX
#endif /* !defined(_CGIFFILEINTERFACE_HXX) && !defined(CGIFFILEINTERFACE_MEMBERS_ONLY) */

#if !defined(CGIFFILEINTERFACE_MEMBERS_ONLY)
#include "cgiffiletypeattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cGifFile;
/**
 **********************************************************************
 * Typedef: cGifFileInterfaceImplement
 *
 *  Author: $author$
 *    Date: 11/11/2010
 **********************************************************************
 */
typedef cGifFileTypeOpenedInterface
cGifFileInterfaceImplement;
/**
 **********************************************************************
 *  Class: cGifFileInterface
 *
 * Author: $author$
 *   Date: 11/11/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cGifFileInterface
: virtual public cGifFileInterfaceImplement
{
public:
    typedef cGifFileInterfaceImplement cImplements;
#else /* !defined(CGIFFILEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEINTERFACE_MEMBERS_ONLY) */

#if !defined(CGIFFILEINTERFACE_MEMBERS_ONLY)
/* include cGifFile member functions interface
 */
#define CGIFFILE_MEMBERS_ONLY
#define CGIFFILE_MEMBER_FUNCS_INTERFACE
#include "cgiffile.hxx"
#undef CGIFFILE_MEMBER_FUNCS_INTERFACE
#undef CGIFFILE_MEMBERS_ONLY
};

#if !defined(CGIFFILEIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cGifFileImplementImplement
 *
 *  Author: $author$
 *    Date: 11/11/2010
 **********************************************************************
 */
typedef cGifFileInterface
cGifFileImplementImplement;
/**
 **********************************************************************
 *  Class: cGifFileImplement
 *
 * Author: $author$
 *   Date: 11/11/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cGifFileImplement
: virtual public cGifFileImplementImplement
{
public:
    typedef cGifFileImplementImplement cImplements;
#else /* !defined(CGIFFILEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CGIFFILEIMPLEMENT_MEMBERS_ONLY)
/* include cGifFile member functions implement
 */
#define CGIFFILE_MEMBERS_ONLY
#define CGIFFILE_MEMBER_FUNCS_IMPLEMENT
#include "cgiffile.hxx"
#undef CGIFFILE_MEMBER_FUNCS_IMPLEMENT
#undef CGIFFILE_MEMBERS_ONLY
};
#else /* !defined(CGIFFILEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CGIFFILEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CGIFFILEINTERFACE_HXX) || defined(CGIFFILEINTERFACE_MEMBERS_ONLY) */
