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
 *   File: cimagereaderinterface.hxx
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
#if !defined(_CIMAGEREADERINTERFACE_HXX) || defined(CIMAGEREADERINTERFACE_MEMBERS_ONLY)
#if !defined(_CIMAGEREADERINTERFACE_HXX) && !defined(CIMAGEREADERINTERFACE_MEMBERS_ONLY)
#define _CIMAGEREADERINTERFACE_HXX
#endif /* !defined(_CIMAGEREADERINTERFACE_HXX) && !defined(CIMAGEREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CIMAGEREADERINTERFACE_MEMBERS_ONLY)
#include "cimagereadereventsinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cImageReaderInterfaceImplement
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cImageReaderEventsInterface
cImageReaderInterfaceImplement;
/**
 **********************************************************************
 *  Class: cImageReaderInterface
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageReaderInterface
: virtual public cImageReaderInterfaceImplement
{
public:
    typedef cImageReaderInterfaceImplement cImplements;
#else /* !defined(CIMAGEREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CIMAGEREADERINTERFACE_MEMBERS_ONLY)
/* include cImageReader member functions interface
 */
#define CIMAGEREADER_MEMBERS_ONLY
#define CIMAGEREADER_MEMBER_FUNCS_INTERFACE
#include "cimagereader.hxx"
#undef CIMAGEREADER_MEMBER_FUNCS_INTERFACE
#undef CIMAGEREADER_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cImageReaderImplement
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cImageReaderImplement
: virtual public cImageReaderInterface
{
public:
    typedef cImageReaderInterface cImplements;
/* include cImageReader member functions implement
 */
#define CIMAGEREADER_MEMBERS_ONLY
#define CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT
#include "cimagereader.hxx"
#undef CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT
#undef CIMAGEREADER_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGEREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEREADERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEREADERINTERFACE_HXX) || defined(CIMAGEREADERINTERFACE_MEMBERS_ONLY) */
