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
 *   File: ccryptoblocksizeinterface.hxx
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
#if !defined(_CCRYPTOBLOCKSIZEINTERFACE_HXX) || defined(CCRYPTOBLOCKSIZEINTERFACE_MEMBERS_ONLY)
#if !defined(_CCRYPTOBLOCKSIZEINTERFACE_HXX) && !defined(CCRYPTOBLOCKSIZEINTERFACE_MEMBERS_ONLY)
#define _CCRYPTOBLOCKSIZEINTERFACE_HXX
#endif /* !defined(_CCRYPTOBLOCKSIZEINTERFACE_HXX) && !defined(CCRYPTOBLOCKSIZEINTERFACE_MEMBERS_ONLY) */

#if !defined(CCRYPTOBLOCKSIZEINTERFACE_MEMBERS_ONLY)
#include "ccryptointerfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cCryptoBlockSizeInterfaceImplement
 *
 *  Author: $author$
 *    Date: 4/4/2010
 **********************************************************************
 */
typedef cCryptoInterfaceBase
cCryptoBlockSizeInterfaceImplement;
/**
 **********************************************************************
 *  Class: cCryptoBlockSizeInterface
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cCryptoBlockSizeInterface
: virtual public cCryptoBlockSizeInterfaceImplement
{
public:
    typedef cCryptoBlockSizeInterfaceImplement cImplements;
#else /* !defined(CCRYPTOBLOCKSIZEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOBLOCKSIZEINTERFACE_MEMBERS_ONLY) */

#if !defined(CCRYPTOBLOCKSIZEINTERFACE_MEMBERS_ONLY)
};

/**
 **********************************************************************
 *  Class: cCryptoBlockSizeImplement
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cCryptoBlockSizeImplement
: virtual public cCryptoBlockSizeInterface
{
public:
    typedef cCryptoBlockSizeInterface cImplements;

};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCRYPTOBLOCKSIZEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CCRYPTOBLOCKSIZEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CCRYPTOBLOCKSIZEINTERFACE_HXX) || defined(CCRYPTOBLOCKSIZEINTERFACE_MEMBERS_ONLY) */
