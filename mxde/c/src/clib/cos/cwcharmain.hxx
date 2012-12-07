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
 *   File: cwcharmain.hxx
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
#if !defined(_CWCHARMAIN_HXX) || defined(CWCHARMAIN_MEMBERS_ONLY)
#if !defined(_CWCHARMAIN_HXX) && !defined(CWCHARMAIN_MEMBERS_ONLY)
#define _CWCHARMAIN_HXX
#endif /* !defined(_CWCHARMAIN_HXX) && !defined(CWCHARMAIN_MEMBERS_ONLY) */

#if !defined(CWCHARMAIN_MEMBERS_ONLY)
#include "cwcharmaininterface.hxx"
#include "cmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWCHARMain;
/**
 **********************************************************************
 * Typedef: cWCHARMainExtend
 *
 *  Author: $author$
 *    Date: 8/7/2010
 **********************************************************************
 */
typedef cMainT
<cWCHARMain, cWCHARMainImplement, cWCHARMainInterface,
 cWCHARFile, cWCHARFileInterface, cWCHARStreamInterface, WCHAR, int>
cWCHARMainExtend;
/**
 **********************************************************************
 *  Class: cWCHARMain
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWCHARMain
: virtual public cWCHARMainImplement,
  public cWCHARMainExtend
{
public:
    typedef cWCHARMainImplement cImplements;
    typedef cWCHARMainExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWCHARMain
     *
     *       Author: $author$
     *         Date: 8/7/2010
     **********************************************************************
     */
    cWCHARMain()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWCHARMain
     *
     *      Author: $author$
     *        Date: 8/7/2010
     **********************************************************************
     */
    virtual ~cWCHARMain()
    {
    }
#else /* !defined(CWCHARMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWCHARMAIN_MEMBERS_ONLY) */

#if !defined(CWCHARMAIN_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWCHARMAIN_MEMBERS_ONLY) */
#endif /* !defined(CWCHARMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CWCHARMAIN_HXX) || defined(CWCHARMAIN_MEMBERS_ONLY) */
