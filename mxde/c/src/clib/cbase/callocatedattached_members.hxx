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
 *   File: callocatedattached_members.hxx
 *
 * Author: $author$
 *   Date: 6/13/2010
 **********************************************************************
 */

#if defined(CALLOCATEDATTACHED_NOT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cAllocatedAttached
 *
 * Author: $author$
 *   Date: 6/17/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cAllocatedAttached
: virtual public cAllocatedAttachedImplement,
  public cAllocatedAttachedExtend
{
public:
    typedef cAllocatedAttachedImplement cImplements;
    typedef cAllocatedAttachedExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cAllocatedAttached
     *
     *       Author: $author$
     *         Date: 6/17/2010
     **********************************************************************
     */
    cAllocatedAttached
    (tAttachedTo attached = (tAttachedTo)(vUnattached),
     bool isAllocated = false) 
    : cExtends(isAllocated)
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     *  Destructor: ~cAllocatedAttached
     *
     *      Author: $author$
     *        Date: 6/17/2010
     **********************************************************************
     */
    virtual ~cAllocatedAttached()
    {
        eError error;
        if ((error = Freed()))
            throw (error);
    }
#else /* defined(CALLOCATEDATTACHED_NOT_MEMBERS_ONLY) */
#endif /* defined(CALLOCATEDATTACHED_NOT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: AttachAllocated
     *
     *    Author: $author$
     *      Date: 6/17/2010
     **********************************************************************
     */
    virtual tAttachedTo AttachAllocated
    (tAttachedTo detached, 
     bool isAllocated = true,
     bool onlyUnattached = false)
#if defined(CALLOCATEDATTACHED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CALLOCATEDATTACHED_MEMBER_FUNCS_INTERFACE) */
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
#if !defined(CALLOCATEDATTACHED_MEMBER_FUNCS_IMPLEMENT)
        if (detached != (tAttachedTo)(vUnattached))
        if (detached == (cExtends::Attach(detached, onlyUnattached)))
        if ((int)(isAllocated) == (SetIsAllocated(isAllocated)))
            attached = detached;
        else
        cExtends::Detach();
#else /* !defined(CALLOCATEDATTACHED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CALLOCATEDATTACHED_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
    }
#endif /* defined(CALLOCATEDATTACHED_MEMBER_FUNCS_INTERFACE) */

#if !defined(CALLOCATEDATTACHED_MEMBER_FUNCS_INTERFACE)
#if !defined(CALLOCATEDATTACHED_MEMBER_FUNCS_IMPLEMENT)
    /**
     **********************************************************************
     *  Function: Attach
     *
     *    Author: $author$
     *      Date: 6/17/2010
     **********************************************************************
     */
    virtual tAttachedTo Attach
    (tAttachedTo detached,
     bool onlyUnattached = false)
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
        attached = cExtends::Attach(detached, onlyUnattached);
        SetIsAllocated(false);
        return attached;
    }
    /**
     **********************************************************************
     *  Function: Detach
     *
     *    Author: $author$
     *      Date: 6/17/2010
     **********************************************************************
     */
    virtual tAttachedTo Detach()
    {
        tAttachedTo detached = (tAttachedTo)(vUnattached);
        detached = cExtends::Detach();
        SetIsAllocated(false);
        return detached;
    }
#endif /* !defined(CALLOCATEDATTACHED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CALLOCATEDATTACHED_MEMBER_FUNCS_INTERFACE) */

#if defined(CALLOCATEDATTACHED_NOT_MEMBERS_ONLY)
};
#else /* defined(CALLOCATEDATTACHED_NOT_MEMBERS_ONLY) */
#endif /* defined(CALLOCATEDATTACHED_NOT_MEMBERS_ONLY) */
