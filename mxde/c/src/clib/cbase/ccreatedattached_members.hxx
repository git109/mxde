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
 *   File: ccreatedattached_members.hxx
 *
 * Author: $author$
 *   Date: 6/16/2010
 **********************************************************************
 */

#if defined(CCREATEDATTACHED_NOT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cCreatedAttached
 *
 * Author: $author$
 *   Date: 6/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cCreatedAttached
: virtual public cCreatedAttachedImplement,
  public cCreatedAttachedExtend
{
public:
    typedef cCreatedAttachedImplement cImplements;
    typedef cCreatedAttachedExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cCreatedAttached
     *
     *       Author: $author$
     *         Date: 6/21/2010
     **********************************************************************
     */
    cCreatedAttached
    (tAttachedTo attached = (tAttachedTo)(vUnattached),
     bool isCreated = false) 
    : cExtends(isCreated)
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     *  Destructor: ~cCreatedAttached
     *
     *      Author: $author$
     *        Date: 6/21/2010
     **********************************************************************
     */
    virtual ~cCreatedAttached()
    {
        eError error;
        if ((error = Destroyed()))
            throw (error);
    }
#else /* defined(CCREATEDATTACHED_NOT_MEMBERS_ONLY) */
#endif /* defined(CCREATEDATTACHED_NOT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: AttachCreated
     *
     *    Author: $author$
     *      Date: 6/21/2010
     **********************************************************************
     */
    virtual tAttachedTo AttachCreated
    (tAttachedTo detached, 
     bool isCreated = true,
     bool onlyUnattached = false)
#if defined(CCREATEDATTACHED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CCREATEDATTACHED_MEMBER_FUNCS_INTERFACE) */
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
#if !defined(CCREATEDATTACHED_MEMBER_FUNCS_IMPLEMENT)
        if (detached != (tAttachedTo)(vUnattached))
        if (detached == (cExtends::Attach(detached, onlyUnattached)))
        if ((int)(isCreated) == (SetIsCreated(isCreated)))
            attached = detached;
        else
        cExtends::Detach();
#else /* !defined(CCREATEDATTACHED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCREATEDATTACHED_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
    }
#endif /* defined(CCREATEDATTACHED_MEMBER_FUNCS_INTERFACE) */

#if !defined(CCREATEDATTACHED_MEMBER_FUNCS_INTERFACE)
#if !defined(CCREATEDATTACHED_MEMBER_FUNCS_IMPLEMENT)
    /**
     **********************************************************************
     *  Function: Attach
     *
     *    Author: $author$
     *      Date: 6/21/2010
     **********************************************************************
     */
    virtual tAttachedTo Attach
    (tAttachedTo detached,
     bool onlyUnattached = false)
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
        attached = cExtends::Attach(detached, onlyUnattached);
        SetIsCreated(false);
        return attached;
    }
    /**
     **********************************************************************
     *  Function: Detach
     *
     *    Author: $author$
     *      Date: 6/21/2010
     **********************************************************************
     */
    virtual tAttachedTo Detach()
    {
        tAttachedTo detached = (tAttachedTo)(vUnattached);
        detached = cExtends::Detach();
        SetIsCreated(false);
        return detached;
    }
#endif /* !defined(CCREATEDATTACHED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CCREATEDATTACHED_MEMBER_FUNCS_INTERFACE) */

#if defined(CCREATEDATTACHED_NOT_MEMBERS_ONLY)
};
#else /* defined(CCREATEDATTACHED_NOT_MEMBERS_ONLY) */
#endif /* defined(CCREATEDATTACHED_NOT_MEMBERS_ONLY) */
