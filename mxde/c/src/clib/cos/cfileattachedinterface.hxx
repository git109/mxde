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
 *   File: cfileattachedinterface.hxx
 *
 * Author: $author$
 *   Date: 3/18/2009
 **********************************************************************
 */
#ifndef _CFILEATTACHEDINTERFACE_HXX
#define _CFILEATTACHEDINTERFACE_HXX

#include "cplatform_stdio.h"
#include "cattachedinterface.hxx"

class c_INTERFACE_CLASS cFILEAttachedInterface;
/**
 **********************************************************************
 * Typedef: cFILEAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/18/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cFILEAttachedInterface, FILE*>
cFILEAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cFILEAttachedInterface
 *
 * Author: $author$
 *   Date: 3/18/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cFILEAttachedInterface
: virtual public cFILEAttachedInterfaceImplements
{
public:
    typedef cFILEAttachedInterfaceImplements cImplements;
    typedef cFILEAttachedInterface cDerives;
};
class c_INSTANCE_CLASS cFILEAttachedImplement;
/**
 **********************************************************************
 * Typedef: cFILEAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 3/18/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cFILEAttachedImplement, cFILEAttachedInterface, FILE*>
cFILEAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cFILEAttachedImplement
 *
 * Author: $author$
 *   Date: 3/18/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cFILEAttachedImplement
: virtual public cFILEAttachedImplementImplements
{
public:
    typedef cFILEAttachedImplementImplements cImplements;
    typedef cFILEAttachedImplement cDerives;
};

#endif /* _CFILEATTACHEDINTERFACE_HXX */
