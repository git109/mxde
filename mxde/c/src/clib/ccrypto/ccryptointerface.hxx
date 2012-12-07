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
 *   File: ccryptointerface.hxx
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
#ifndef _CCRYPTOINTERFACE_HXX
#define _CCRYPTOINTERFACE_HXX

#include "cinterfacebase.hxx"
#include "ccryptoerror.h"

/**
 **********************************************************************
 * Typedef: cCryptoInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/1/2009
 **********************************************************************
 */
typedef cInterfaceBase
cCryptoInterfaceImplements;

/**
 **********************************************************************
 *  Class: cCryptoInterface
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cCryptoInterface
: virtual public cCryptoInterfaceImplements
{
public:
    typedef cCryptoInterfaceImplements cImplements;
    typedef cCryptoInterface cDerives;
};
#endif /* _CCRYPTOINTERFACE_HXX */
