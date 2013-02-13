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
 *   File: cxtarg.hxx
 *
 * Author: $author$           
 *   Date: 4/24/2010
 **********************************************************************
 */
#if !defined(_CXTARG_HXX) || defined(CXTARG_MEMBERS_ONLY)
#if !defined(_CXTARG_HXX) && !defined(CXTARG_MEMBERS_ONLY)
#define _CXTARG_HXX
#endif /* !defined(_CXTARG_HXX) && !defined(CXTARG_MEMBERS_ONLY) */

#if !defined(CXTARG_MEMBERS_ONLY)
#include "cplatform_X11_Intrinsic.h"
#include "cxtarginterface.hxx"
#include "cxtstring.hxx"
#include "cxbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtArgExtend
 *
 *  Author: $author$           
 *    Date: 4/24/2010
 **********************************************************************
 */
typedef cXBase
cXtArgExtend;
/**
 **********************************************************************
 *  Class: cXtArg
 *
 * Author: $author$           
 *   Date: 4/24/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtArg
: virtual public cXtArgImplement,
  public cXtArgExtend
{
public:
    typedef cXtArgImplement cImplements;
    typedef cXtArgExtend cExtends;

    Arg& m_xtArg;
    cXtString m_argName;

    /**
     **********************************************************************
     *  Constructor: cXtArg
     *
     *       Author: $author$           
     *         Date: 4/24/2010
     **********************************************************************
     */
    cXtArg
    (Arg& xtArg,
     const XtChar* argName = 0,
     XtArgVal argValue = 0)
    : m_xtArg(xtArg)
    {
        TLENGTH count;
        eError error;

        if (argName)
        if (0 > (count = m_argName.assign(argName)))
            throw (error = -count);

        m_xtArg.name = m_argName.str();
        m_xtArg.value = argValue;
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtArg
     *
     *      Author: $author$           
     *        Date: 4/24/2010
     **********************************************************************
     */
    virtual ~cXtArg()
    {
        m_xtArg.value = 0;
        m_xtArg.name = 0;
    }
#else /* !defined(CXTARG_MEMBERS_ONLY) */
#endif /* !defined(CXTARG_MEMBERS_ONLY) */

#if !defined(CXTARG_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTARG_MEMBERS_ONLY) */
#endif /* !defined(CXTARG_MEMBERS_ONLY) */

#endif /* !defined(_CXTARG_HXX) || defined(CXTARG_MEMBERS_ONLY) */
