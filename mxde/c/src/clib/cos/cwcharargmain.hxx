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
 *   File: cwcharargmain.hxx
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
#if !defined(_CWCHARARGMAIN_HXX) || defined(CWCHARARGMAIN_MEMBERS_ONLY)
#if !defined(_CWCHARARGMAIN_HXX) && !defined(CWCHARARGMAIN_MEMBERS_ONLY)
#define _CWCHARARGMAIN_HXX
#endif /* !defined(_CWCHARARGMAIN_HXX) && !defined(CWCHARARGMAIN_MEMBERS_ONLY) */

#if !defined(CWCHARARGMAIN_MEMBERS_ONLY)
#include "cwcharargmaininterface.hxx"
#include "cwcharmainarg.hxx"
#include "cwcharmain.hxx"
#include "cargmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWCHARArgMain;
/**
 **********************************************************************
 * Typedef: cWCHARArgMainExtend
 *
 *  Author: $author$
 *    Date: 8/7/2010
 **********************************************************************
 */
typedef cArgMainT
<cWCHARArgMain,
 cWCHARArgMainImplement,
 cWCHARArgMainInterface,
 cWCHARMain,
 cWCHARMainArg,
 cWCHARMainArgList,
 cWCHARMainArgItem,
 cWCHARSplitter,
 cWCHARString,
 cWCHARFileInterface, cWCHARStreamInterface, WCHAR, int>
cWCHARArgMainExtend;
/**
 **********************************************************************
 *  Class: cWCHARArgMain
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWCHARArgMain
: public cWCHARArgMainExtend
{
public:
    typedef cWCHARArgMainExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWCHARArgMain
     *
     *       Author: $author$
     *         Date: 8/7/2010
     **********************************************************************
     */
    cWCHARArgMain()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWCHARArgMain
     *
     *      Author: $author$
     *        Date: 8/7/2010
     **********************************************************************
     */
    virtual ~cWCHARArgMain()
    {
    }
#else /* !defined(CWCHARARGMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWCHARARGMAIN_MEMBERS_ONLY) */

#if !defined(CWCHARARGMAIN_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWCHARARGMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWCHARARGMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CWCHARARGMAIN_HXX) || defined(CWCHARARGMAIN_MEMBERS_ONLY) */
