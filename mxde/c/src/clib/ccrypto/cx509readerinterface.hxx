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
 *   File: cx509readerinterface.hxx
 *
 * Author: $author$
 *   Date: 3/28/2010
 **********************************************************************
 */
#if !defined(_CX509READERINTERFACE_HXX) || defined(CX509READERINTERFACE_MEMBERS_ONLY)
#if !defined(_CX509READERINTERFACE_HXX) && !defined(CX509READERINTERFACE_MEMBERS_ONLY)
#define _CX509READERINTERFACE_HXX
#endif /* !defined(_CX509READERINTERFACE_HXX) && !defined(CX509READERINTERFACE_MEMBERS_ONLY) */

#if !defined(CX509READERINTERFACE_MEMBERS_ONLY)
#include "casn1readerinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cX509ReaderInterface
 *
 * Author: $author$
 *   Date: 3/28/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cX509ReaderInterface
: virtual public cASN1ReaderInterface
{
public:
    typedef cASN1ReaderInterface cImplements;
#else /* !defined(CX509READERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CX509READERINTERFACE_MEMBERS_ONLY) */

#if !defined(CX509READERINTERFACE_MEMBERS_ONLY)
};

/**
 **********************************************************************
 *  Class: cX509ReaderImplement
 *
 * Author: $author$
 *   Date: 3/28/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cX509ReaderImplement
: virtual public cX509ReaderInterface
{
public:
    typedef cX509ReaderInterface cImplements;

};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CX509READERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CX509READERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CX509READERINTERFACE_HXX) || defined(CX509READERINTERFACE_MEMBERS_ONLY) */
