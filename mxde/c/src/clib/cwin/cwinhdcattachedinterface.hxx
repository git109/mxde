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
 *   File: cwinhdcattachedinterface.hxx
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
#if !defined(_CWINHDCATTACHEDINTERFACE_HXX) || defined(CWINHDCATTACHEDINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINHDCATTACHEDINTERFACE_HXX) && !defined(CWINHDCATTACHEDINTERFACE_MEMBERS_ONLY)
#define _CWINHDCATTACHEDINTERFACE_HXX
#endif /* !defined(_CWINHDCATTACHEDINTERFACE_HXX) && !defined(CWINHDCATTACHEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINHDCATTACHEDINTERFACE_MEMBERS_ONLY)
#include "cattachedinterface.hxx"
#include "cwininterfacebase.hxx"

/* cWinHDCAttached interface definition
 */
class c_INTERFACE_CLASS cWinHDCAttachedInterface;
/**
 **********************************************************************
 * Typedef: cWinHDCAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/25/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cWinHDCAttachedInterface, 
 HDC, UINT, NULL, cWinInterfaceBase>
cWinHDCAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinHDCAttachedInterface
 *
 * Author: $author$
 *   Date: 5/25/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHDCAttachedInterface
: virtual public cWinHDCAttachedInterfaceImplements
{
public:
    typedef cWinHDCAttachedInterfaceImplements cImplements;
    typedef cWinHDCAttachedInterface cDerives;
};

/* cWinHDCAttached implement definition
 */
class cWinHDCAttachedImplement;
/**
 **********************************************************************
 * Typedef: cWinHDCAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 5/25/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cWinHDCAttachedImplement, 
 cWinHDCAttachedInterface, 
 HDC, UINT, NULL>
cWinHDCAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cWinHDCAttachedImplement
 *
 * Author: $author$
 *   Date: 5/25/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHDCAttachedImplement
: virtual public cWinHDCAttachedImplementImplements
{
public:
    typedef cWinHDCAttachedImplementImplements cImplements;
    typedef cWinHDCAttachedImplement cDerives;
};

#else /* !defined(CWINHDCATTACHEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINHDCATTACHEDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINHDCATTACHEDINTERFACE_HXX) || defined(CWINHDCATTACHEDINTERFACE_MEMBERS_ONLY) */
