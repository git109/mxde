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
 *   File: cpointerarray.hxx
 *
 * Author: $author$
 *   Date: 11/20/2010
 **********************************************************************
 */
#if !defined(_CPOINTERARRAY_HXX) || defined(CPOINTERARRAY_MEMBERS_ONLY)
#if !defined(_CPOINTERARRAY_HXX) && !defined(CPOINTERARRAY_MEMBERS_ONLY)
#define _CPOINTERARRAY_HXX
#endif /* !defined(_CPOINTERARRAY_HXX) && !defined(CPOINTERARRAY_MEMBERS_ONLY) */

#if !defined(CPOINTERARRAY_MEMBERS_ONLY)
#include "carray.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cWCHARPArrayInterface;
/**
 **********************************************************************
 * Typedef: cWCHARPArrayInterfaceImplement
 *
 *  Author: $author$
 *    Date: 1/27/2010
 **********************************************************************
 */
typedef cArrayInterfaceT
<cWCHARPArrayInterface, const WCHAR*>
cWCHARPArrayInterfaceImplement;
/**
 **********************************************************************
 *  Class: cWCHARPArrayInterface
 *
 * Author: $author$
 *   Date: 1/27/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARPArrayInterface
: virtual public cWCHARPArrayInterfaceImplement
{
public:
    typedef cWCHARPArrayInterfaceImplement cImplements;
};
class c_IMPLEMENT_CLASS cWCHARPArrayImplement;
/**
 **********************************************************************
 * Typedef: cWCHARPArrayImplementImplement
 *
 *  Author: $author$
 *    Date: 1/27/2010
 **********************************************************************
 */
typedef cArrayImplementT
<cWCHARPArrayImplement, 
 cWCHARPArrayInterface,
 const WCHAR*>
cWCHARPArrayImplementImplement;
/**
 **********************************************************************
 *  Class: cWCHARPArrayImplement
 *
 * Author: $author$
 *   Date: 1/27/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWCHARPArrayImplement
: virtual public cWCHARPArrayImplementImplement
{
public:
    typedef cWCHARPArrayImplementImplement cImplements;
};
class c_EXPORT_CLASS cWCHARPArray;
/**
 **********************************************************************
 * Typedef: cWCHARPArrayExtend
 *
 *  Author: $author$
 *    Date: 1/27/2010
 **********************************************************************
 */
typedef cArrayT
<cWCHARPArray,
 cWCHARPArrayImplement,
 cWCHARPArrayInterface,
 const WCHAR*>
cWCHARPArrayExtend;
/**
 **********************************************************************
 *  Class: cWCHARPArray
 *
 * Author: $author$
 *   Date: 1/27/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWCHARPArray
: public cWCHARPArrayExtend
{
public:
    typedef cWCHARPArrayExtend cExtends;
#else /* !defined(CIMAGEPOINTARRAY_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEPOINTARRAY_MEMBERS_ONLY) */

#if !defined(CIMAGEPOINTARRAY_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPOINTERARRAY_MEMBERS_ONLY) */
#endif /* !defined(CPOINTERARRAY_MEMBERS_ONLY) */

#endif /* !defined(_CPOINTERARRAY_HXX) || defined(CPOINTERARRAY_MEMBERS_ONLY) */
