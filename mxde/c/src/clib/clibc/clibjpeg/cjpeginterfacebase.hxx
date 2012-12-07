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
 *   File: cjpeginterfacebase.hxx
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
#if !defined(_CJPEGINTERFACEBASE_HXX) || defined(CJPEGINTERFACEBASE_MEMBERS_ONLY)
#if !defined(_CJPEGINTERFACEBASE_HXX) && !defined(CJPEGINTERFACEBASE_MEMBERS_ONLY)
#define _CJPEGINTERFACEBASE_HXX
#endif /* !defined(_CJPEGINTERFACEBASE_HXX) && !defined(CJPEGINTERFACEBASE_MEMBERS_ONLY) */

#if !defined(CJPEGINTERFACEBASE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"
#include "cjpeg.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cJPEGInterfaceBaseImplement
 *
 *  Author: $author$
 *    Date: 11/12/2010
 **********************************************************************
 */
typedef cInterfaceBase
cJPEGInterfaceBaseImplement;
/**
 **********************************************************************
 *  Class: cJPEGInterfaceBase
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cJPEGInterfaceBase
: virtual public cJPEGInterfaceBaseImplement
{
public:
    typedef cJPEGInterfaceBaseImplement cImplements;
#else /* !defined(CJPEGINTERFACEBASE_MEMBERS_ONLY) */
#endif /* !defined(CJPEGINTERFACEBASE_MEMBERS_ONLY) */

#if !defined(CJPEGINTERFACEBASE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CJPEGINTERFACEBASE_MEMBERS_ONLY) */
#endif /* !defined(CJPEGINTERFACEBASE_MEMBERS_ONLY) */

#endif /* !defined(_CJPEGINTERFACEBASE_HXX) || defined(CJPEGINTERFACEBASE_MEMBERS_ONLY) */
