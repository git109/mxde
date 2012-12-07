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
 *   File: cwinbitmapfileinterface.hxx
 *
 * Author: $author$
 *   Date: 7/22/2009
 **********************************************************************
 */
#if !defined(_CWINBITMAPFILEINTERFACE_HXX) || defined(CWINBITMAPFILEINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINBITMAPFILEINTERFACE_HXX) && !defined(CWINBITMAPFILEINTERFACE_MEMBERS_ONLY)
#define _CWINBITMAPFILEINTERFACE_HXX
#endif /* !defined(_CWINBITMAPFILEINTERFACE_HXX) && !defined(CWINBITMAPFILEINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINBITMAPFILEINTERFACE_MEMBERS_ONLY)
#include "cwinbaseinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinBitmapFileInterface
 *
 * Author: $author$
 *   Date: 7/22/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinBitmapFileInterface
: virtual public cWinBaseInterface
{
public:
    typedef cWinBaseInterface cImplements;
#else /* !defined(CWINBITMAPFILEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINBITMAPFILEINTERFACE_MEMBERS_ONLY)
/* include cWinBitmapFile member functions interface
 */
#define CWINBITMAPFILE_MEMBERS_ONLY
#define CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE
#include "cwinbitmapfile.hxx"
#undef CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE
#undef CWINBITMAPFILE_MEMBERS_ONLY
};

class c_IMPLEMENT_CLASS cWinBitmapFileImplement
: virtual public cWinBitmapFileInterface
{
public:
/* include cWinBitmapFile member functions implement
 */
#define CWINBITMAPFILE_MEMBERS_ONLY
#define CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT
#include "cwinbitmapfile.hxx"
#undef CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT
#undef CWINBITMAPFILE_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINBITMAPFILEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINBITMAPFILEINTERFACE_HXX) || defined(CWINBITMAPFILEINTERFACE_MEMBERS_ONLY) */
