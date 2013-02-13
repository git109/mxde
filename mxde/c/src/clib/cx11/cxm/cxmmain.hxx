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
 *   File: cxmmain.hxx
 *
 * Author: $author$           
 *   Date: 5/14/2010
 **********************************************************************
 */
#if !defined(_CXMMAIN_HXX) || defined(CXMMAIN_MEMBERS_ONLY)
#if !defined(_CXMMAIN_HXX) && !defined(CXMMAIN_MEMBERS_ONLY)
#define _CXMMAIN_HXX
#endif /* !defined(_CXMMAIN_HXX) && !defined(CXMMAIN_MEMBERS_ONLY) */

#if !defined(CXMMAIN_MEMBERS_ONLY)
#include "cplatform_Xm_Protocols.h"
#include "cxtmain.hxx"
#include "cxtwidget.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmMainExtend
 *
 *  Author: $author$           
 *    Date: 5/14/2010
 **********************************************************************
 */
typedef cXtMain
cXmMainExtend;
/**
 **********************************************************************
 *  Class: cXmMain
 *
 * Author: $author$           
 *   Date: 5/14/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmMain
: /*virtual public cXmMainImplement,
  */public cXmMainExtend
{
public:
    /*typedef cXmMainImplement cImplements;
    */typedef cXmMainExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cXmMain
     *
     *       Author: $author$           
     *         Date: 5/14/2010
     **********************************************************************
     */
    cXmMain
    (const String xtNameChars = DEFAULT_CXTMAIN_NAME,
     const String xtClassNameChars = DEFAULT_CXTMAIN_CLASS_NAME,
     const tChar* displayNameChars=DEFAULT_CXMAIN_DISPLAY_NAME,
     int displayScreen=DEFAULT_CXMAIN_DISPLAY_SCREEN)
    : cExtends
      (xtNameChars, xtClassNameChars, 
       displayNameChars, displayScreen)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmMain
     *
     *      Author: $author$           
     *        Date: 5/14/2010
     **********************************************************************
     */
    virtual ~cXmMain()
    {
    }
#else /* !defined(CXMMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXMMAIN_MEMBERS_ONLY) */

#if !defined(CXMMAIN_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXMMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXMMAIN_HXX) || defined(CXMMAIN_MEMBERS_ONLY) */
