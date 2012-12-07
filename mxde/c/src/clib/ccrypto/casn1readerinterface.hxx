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
 *   File: casn1readerinterface.hxx
 *
 * Author: $author$
 *   Date: 3/21/2010
 **********************************************************************
 */
#if !defined(_CASN1READERINTERFACE_HXX) || defined(CASN1READERINTERFACE_MEMBERS_ONLY)
#if !defined(_CASN1READERINTERFACE_HXX) && !defined(CASN1READERINTERFACE_MEMBERS_ONLY)
#define _CASN1READERINTERFACE_HXX
#endif /* !defined(_CASN1READERINTERFACE_HXX) && !defined(CASN1READERINTERFACE_MEMBERS_ONLY) */

#if !defined(CASN1READERINTERFACE_MEMBERS_ONLY)
#include "casn1readereventsinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cASN1ReaderInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/21/2010
 **********************************************************************
 */
typedef cASN1ReaderEventsInterface
cASN1ReaderInterfaceImplements;
/**
 **********************************************************************
 *  Class: cASN1ReaderInterface
 *
 * Author: $author$
 *   Date: 3/21/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cASN1ReaderInterface
: virtual public cASN1ReaderInterfaceImplements
{
public:
    typedef cASN1ReaderInterfaceImplements cImplements;
#else /* !defined(CASN1READERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CASN1READERINTERFACE_MEMBERS_ONLY) */

#if !defined(CASN1READERINTERFACE_MEMBERS_ONLY)
};

/**
 **********************************************************************
 *  Class: cASN1ReaderImplement
 *
 * Author: $author$
 *   Date: 3/21/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cASN1ReaderImplement
: virtual public cASN1ReaderInterface
{
public:
    typedef cASN1ReaderInterface cImplements;

};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CASN1READERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CASN1READERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CASN1READERINTERFACE_HXX) || defined(CASN1READERINTERFACE_MEMBERS_ONLY) */
