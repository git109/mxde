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
 *   File: cxtstring.hxx
 *
 * Author: $author$           
 *   Date: 4/24/2010
 **********************************************************************
 */
#if !defined(_CXTSTRING_HXX) || defined(CXTSTRING_MEMBERS_ONLY)
#if !defined(_CXTSTRING_HXX) && !defined(CXTSTRING_MEMBERS_ONLY)
#define _CXTSTRING_HXX
#endif /* !defined(_CXTSTRING_HXX) && !defined(CXTSTRING_MEMBERS_ONLY) */

#if !defined(CXTSTRING_MEMBERS_ONLY)
#include "cplatform_X11_Intrinsic.h"
#include "cstringbase.hxx"
#include "cxbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: XtChar
 *
 *  Author: $author$           
 *    Date: 4/30/2010
 **********************************************************************
 */
typedef char
XtChar;

class c_INTERFACE_CLASS cXtStringBaseInterface;
/**
 **********************************************************************
 * Typedef: cXtStringBaseInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 4/30/2010
 **********************************************************************
 */
typedef cStringBaseInterfaceT
<cXtStringBaseInterface, XtChar, XtChar>
cXtStringBaseInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtStringBaseInterface
 *
 * Author: $author$           
 *   Date: 4/30/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtStringBaseInterface
: virtual public cXtStringBaseInterfaceImplement
{
public:
    typedef cXtStringBaseInterfaceImplement cImplements;
};
class c_IMPLEMENT_CLASS cXtStringBaseImplement;
/**
 **********************************************************************
 * Typedef: cXtStringBaseImplementImplement
 *
 *  Author: $author$           
 *    Date: 4/30/2010
 **********************************************************************
 */
typedef cStringBaseImplementT
<cXtStringBaseImplement, 
 cXtStringBaseInterface, XtChar, XtChar>
cXtStringBaseImplementImplement;
/**
 **********************************************************************
 *  Class: cXtStringBaseImplement
 *
 * Author: $author$           
 *   Date: 4/24/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtStringBaseImplement
: virtual public cXtStringBaseImplementImplement
{
public:
    typedef cXtStringBaseImplementImplement cImplements;
};
class c_INSTANCE_CLASS cXtStringBase;
/**
 **********************************************************************
 * Typedef: cXtStringBaseExtend
 *
 *  Author: $author$           
 *    Date: 4/30/2010
 **********************************************************************
 */
typedef cStringBaseT
<cXtStringBase, 
 cXtStringBaseImplement, 
 cBase, XtChar, XtChar>
cXtStringBaseExtend;
/**
 **********************************************************************
 *  Class: cXtStringBase
 *
 * Author: $author$           
 *   Date: 4/30/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtStringBase
: public cXtStringBaseExtend
{
public:
    typedef cXtStringBaseExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtStringBase
     *
     *       Author: $author$           
     *         Date: 4/30/2010
     **********************************************************************
     */
    cXtStringBase
    (const tChar* chars = 0,
     tLength length = vUndefinedLength)
    : cExtends(chars, length)
    {
    }
};

/**
 **********************************************************************
 * Typedef: cXtStringExtend
 *
 *  Author: $author$           
 *    Date: 4/24/2010
 **********************************************************************
 */
typedef cXtStringBase
cXtStringExtend;
/**
 **********************************************************************
 *  Class: cXtString
 *
 * Author: $author$           
 *   Date: 4/24/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtString
: public cXtStringExtend
{
public:
    typedef cXtStringExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXtString
     *
     *       Author: $author$           
     *         Date: 4/24/2010
     **********************************************************************
     */
    cXtString
    (const tChar* chars = 0,
     tLength length = vUndefinedLength)
    : cExtends(chars, length)
    {
    }
#else /* !defined(CXTSTRING_MEMBERS_ONLY) */
#endif /* !defined(CXTSTRING_MEMBERS_ONLY) */

#if !defined(CXTSTRING_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTSTRING_MEMBERS_ONLY) */
#endif /* !defined(CXTSTRING_MEMBERS_ONLY) */

#endif /* !defined(_CXTSTRING_HXX) || defined(CXTSTRING_MEMBERS_ONLY) */
