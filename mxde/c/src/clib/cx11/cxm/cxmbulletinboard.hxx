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
 *   File: cxmbulletinboard.hxx
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
#if !defined(_CXMBULLETINBOARD_HXX) || defined(CXMBULLETINBOARD_MEMBERS_ONLY)
#if !defined(_CXMBULLETINBOARD_HXX) && !defined(CXMBULLETINBOARD_MEMBERS_ONLY)
#define _CXMBULLETINBOARD_HXX
#endif /* !defined(_CXMBULLETINBOARD_HXX) && !defined(CXMBULLETINBOARD_MEMBERS_ONLY) */

#if !defined(CXMBULLETINBOARD_MEMBERS_ONLY)
#include "cxmbulletinboardinterface.hxx"
#include "cxmmanager.hxx"

#define CXMBULLETINBOARD_WIDGET_CLASS xmBulletinBoardWidgetClass

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmBulletinBoardExtend
 *
 *  Author: $author$           
 *    Date: 6/27/2010
 **********************************************************************
 */
typedef cXmManager
cXmBulletinBoardExtend;
/**
 **********************************************************************
 *  Class: cXmBulletinBoard
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmBulletinBoard
: virtual public cXmBulletinBoardImplement,
  public cXmBulletinBoardExtend
{
public:
    typedef cXmBulletinBoardImplement cImplements;
    typedef cXmBulletinBoardExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXmBulletinBoard
     *
     *       Author: $author$           
     *         Date: 6/27/2010
     **********************************************************************
     */
    cXmBulletinBoard
    (cXDisplayInterface& display,
     const XtChar* name = 0,
     WidgetClass widgetClassAttached = CXMBULLETINBOARD_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false) 
    : cExtends(display, name, widgetClassAttached, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmBulletinBoard
     *
     *      Author: $author$           
     *        Date: 6/27/2010
     **********************************************************************
     */
    virtual ~cXmBulletinBoard()
    {
    }
#else /* !defined(CXMBULLETINBOARD_MEMBERS_ONLY) */
#endif /* !defined(CXMBULLETINBOARD_MEMBERS_ONLY) */

#if !defined(CXMBULLETINBOARD_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMBULLETINBOARD_MEMBERS_ONLY) */
#endif /* !defined(CXMBULLETINBOARD_MEMBERS_ONLY) */

#endif /* !defined(_CXMBULLETINBOARD_HXX) || defined(CXMBULLETINBOARD_MEMBERS_ONLY) */
