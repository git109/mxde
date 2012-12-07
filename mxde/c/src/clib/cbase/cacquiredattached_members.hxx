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
 *   File: cacquiredattached_members.hxx
 *
 * Author: $author$
 *   Date: 6/16/2010
 **********************************************************************
 */

#if defined(CACQUIREDATTACHED_NOT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cAcquiredAttached
 *
 * Author: $author$
 *   Date: 6/16/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cAcquiredAttached
: virtual public cAcquiredAttachedImplement,
  public cAcquiredAttachedExtend
{
public:
    typedef cAcquiredAttachedImplement cImplements;
    typedef cAcquiredAttachedExtend cExtends;

    bool m_isAcquired;

    /**
     **********************************************************************
     *  Constructor: cAcquiredAttached
     *
     *       Author: $author$
     *         Date: 6/16/2010
     **********************************************************************
     */
    cAcquiredAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isAcquired=false) 
    : m_isAcquired(isAcquired)
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     *  Destructor: ~cAcquiredAttached
     *
     *      Author: $author$
     *        Date: 6/16/2010
     **********************************************************************
     */
    virtual ~cAcquiredAttached()
    {
    }
#else /* defined(CACQUIREDATTACHED_NOT_MEMBERS_ONLY) */
#endif /* defined(CACQUIREDATTACHED_NOT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: AttachAcquired
     *
     *    Author: $author$
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual tAttachedTo AttachAcquired
    (tAttachedTo detached, 
     bool isAcquired=true,
     bool onlyUnattached=false)
#if defined(CACQUIREDATTACHED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CACQUIREDATTACHED_MEMBER_FUNCS_INTERFACE) */
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
#if !defined(CACQUIREDATTACHED_MEMBER_FUNCS_IMPLEMENT)
        if (detached != (tAttachedTo)(vUnattached))
        if (detached == (cExtends::Attach(detached, onlyUnattached)))
        if ((int)(isAcquired) == (SetIsAcquired(isAcquired)))
            attached = detached;
        else
        cExtends::Detach();
#else /* !defined(CACQUIREDATTACHED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CACQUIREDATTACHED_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
    }
#endif /* defined(CACQUIREDATTACHED_MEMBER_FUNCS_INTERFACE) */

#if !defined(CACQUIREDATTACHED_MEMBER_FUNCS_INTERFACE)
#if !defined(CACQUIREDATTACHED_MEMBER_FUNCS_IMPLEMENT)
    /**
     **********************************************************************
     *  Function: Attach
     *
     *    Author: $author$
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual tAttachedTo Attach
    (tAttachedTo detached,
     bool onlyUnattached=false)
    {
        tAttachedTo attached = cExtends::Attach(detached, onlyUnattached);
        SetIsAcquired(false);
        return attached;
    }
    /**
     **********************************************************************
     *  Function: Detach
     *
     *    Author: $author$
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual tAttachedTo Detach()
    {
        tAttachedTo detached = cExtends::Detach();
        SetIsAcquired(false);
        return detached;
    }
#endif /* !defined(CACQUIREDATTACHED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CACQUIREDATTACHED_MEMBER_FUNCS_INTERFACE) */

#if defined(CACQUIREDATTACHED_NOT_MEMBERS_ONLY)
};
#else /* defined(CACQUIREDATTACHED_NOT_MEMBERS_ONLY) */
#endif /* defined(CACQUIREDATTACHED_NOT_MEMBERS_ONLY) */
