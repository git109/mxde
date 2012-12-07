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
 *   File: cseparatorinterface.hxx
 *
 * Author: $author$
 *   Date: 10/12/2009
 **********************************************************************
 */
#if !defined(_CSEPARATORINTERFACE_HXX) || defined(CSEPARATORINTERFACE_MEMBERS_ONLY)
#if !defined(_CSEPARATORINTERFACE_HXX) && !defined(CSEPARATORINTERFACE_MEMBERS_ONLY)
#define _CSEPARATORINTERFACE_HXX
#endif /* !defined(_CSEPARATORINTERFACE_HXX) && !defined(CSEPARATORINTERFACE_MEMBERS_ONLY) */

#if !defined(CSEPARATORINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *   Enum: eSeparate
 *
 * Author: $author$
 *   Date: 10/12/2009
 **********************************************************************
 */
typedef int eSeparate; 
enum
{
    e_SEPARATE_ALL = -1,
    e_SEPARATE_NONE = 0,

    e_SEPARATE_NEXT,
    e_SEPARATE_LAST = e_SEPARATE_NEXT-1,
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSEPARATORINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSEPARATORINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CSEPARATORINTERFACE_HXX) || defined(CSEPARATORINTERFACE_MEMBERS_ONLY) */
