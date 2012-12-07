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
 *   File: cstdstring.hxx
 *
 * Author: $author$
 *   Date: 3/21/2009
 **********************************************************************
 */
#ifndef _CSTDSTRING_HXX
#define _CSTDSTRING_HXX

#include <string>
#include "cplatform.hxx"

#if defined(WINDOWS) 
#include "cplatform_dll_warning_push.h"
#endif /* defined(WINDOWS) */

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cStdStringBaseExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef std::basic_string<CHAR>
cStdStringBaseExtends;
/**
 **********************************************************************
 *  Class: cStdStringBase
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cStdStringBase
: public cStdStringBaseExtends
{
public:
    typedef cStdStringBaseExtends cExtends;
    typedef cStdStringBase cDerives;
};
/**
 **********************************************************************
 * Typedef: cTCHARStdStringBaseExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef std::basic_string<TCHAR>
cTCHARStdStringBaseExtends;
/**
 **********************************************************************
 *  Class: cTCHARStdStringBase
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cTCHARStdStringBase
: public cTCHARStdStringBaseExtends
{
public:
    typedef cTCHARStdStringBaseExtends cExtends;
    typedef cTCHARStdStringBase cDerives;
};
/**
 **********************************************************************
 * Typedef: cWCHARStdStringBaseExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef std::basic_string<WCHAR>
cWCHARStdStringBaseExtends;
/**
 **********************************************************************
 *  Class: cWCHARStdStringBase
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWCHARStdStringBase
: public cWCHARStdStringBaseExtends
{
public:
    typedef cWCHARStdStringBaseExtends cExtends;
    typedef cWCHARStdStringBase cDerives;
};
/**
 **********************************************************************
 * Typedef: cBYTEStdStringBaseExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef std::basic_string<BYTE>
cBYTEStdStringBaseExtends;
/**
 **********************************************************************
 *  Class: cBYTEStdStringBase
 *
 * Author: $author$
 *   Date: 8/23/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cBYTEStdStringBase
: public cBYTEStdStringBaseExtends
{
public:
    typedef cBYTEStdStringBaseExtends cExtends;
    typedef cBYTEStdStringBase cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#if defined(WINDOWS) 
#include "cplatform_dll_warning_pop.h"
#endif /* defined(WINDOWS) */

#endif /* _CSTDSTRING_HXX */
