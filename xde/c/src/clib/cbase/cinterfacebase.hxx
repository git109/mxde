/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cinterfacebase.hxx
 *
 * Author: $author$
 *   Date: 11/13/2007
 *
 **********************************************************************
 */
#ifndef _CINTERFACEBASE_HXX
#define _CINTERFACEBASE_HXX

#include "cplatform.h"
#include "cerror.h"

#if defined(WIN32) 
/* Windows
 */
#define c_INTERFACE_CLASS PLATFORM_EXPORT
#define c_EXPORT_CLASS PLATFORM_EXPORT
#define c_EXPORT PLATFORM_EXPORT
#else /* defined(WIN32) */
/* Unix
 */
#define c_INTERFACE_CLASS
#define c_EXPORT_CLASS
#define c_EXPORT
#endif /* defined(WIN32) */

/**
 **********************************************************************
 *  Class: cInterfaceBase
 *
 * Author: $author$
 *   Date: 1/9/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cInterfaceBase
{
public:
#if defined(__GNUC__) 
/* Gcc
 */
    /**
     **********************************************************************
     *  Destructor: ~cInterfaceBase
     *
     *      Author: $author$
     *        Date: 1/16/2007
     **********************************************************************
     */
    virtual ~cInterfaceBase()
    {
    }
#else /* defined(__GNUC__) */
/* Otherwise
 */
#endif /* defined(__GNUC__) */
};

/**
 **********************************************************************
 *  Class: cImplementBase
 *
 * Author: $author$
 *   Date: 3/22/2007
 **********************************************************************
 */
class cImplementBase
: virtual public cInterfaceBase
{
public:
    typedef cInterfaceBase cImplements;
    typedef cImplementBase cDerives;
};
#endif /* _CINTERFACEBASE_HXX */
