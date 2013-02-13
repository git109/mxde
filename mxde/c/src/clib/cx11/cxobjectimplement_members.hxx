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
 *   File: cxobjectimplement_members.hxx
 *
 * Author: $author$           
 *   Date: 6/13/2010
 **********************************************************************
 */

#if defined(CXOBJECTIMPLEMENTEXTEND_NOT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXObjectImplementExtend
 *
 * Author: $author$           
 *   Date: 6/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXObjectImplementExtend
: virtual public cXObjectImplement,
  public cXObjectImplementExtendBase
{
public:
    typedef cXObjectImplement cImplements;
    typedef cXObjectImplementExtendBase cExtends;

    cXDisplayInterface& m_display;

    /**
     **********************************************************************
     *  Constructor: cXObjectImplementExtend
     *
     *       Author: $author$           
     *         Date: 6/13/2010
     **********************************************************************
     */
    cXObjectImplementExtend
    (cXDisplayInterface& display)
    : m_display(display)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXObjectImplementExtend
     *
     *      Author: $author$           
     *        Date: 6/13/2010
     **********************************************************************
     */
    virtual ~cXObjectImplementExtend()
    {
    }
#else /* defined(CXOBJECTIMPLEMENTEXTEND_NOT_MEMBERS_ONLY) */
#endif /* defined(CXOBJECTIMPLEMENTEXTEND_NOT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: DisplayInterface
     *
     *    Author: $author$           
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual cXDisplayInterface& DisplayInterface() const
    {
        return (cXDisplayInterface&)(m_display);
    }
    /**
     **********************************************************************
     *  Function: DisplayAttached
     *
     *    Author: $author$           
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual Display* DisplayAttached() const
    {
        cXDisplayInterface& display = DisplayInterface();
        Display* xDisplay = display.Attached();
        return xDisplay;
    }

#if defined(CXOBJECTIMPLEMENTEXTEND_NOT_MEMBERS_ONLY)
};
#else /* defined(CXOBJECTIMPLEMENTEXTEND_NOT_MEMBERS_ONLY) */
#endif /* defined(CXOBJECTIMPLEMENTEXTEND_NOT_MEMBERS_ONLY) */
