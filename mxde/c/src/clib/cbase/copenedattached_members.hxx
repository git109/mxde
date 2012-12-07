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
 *   File: copenedattached_members.hxx
 *
 * Author: $author$
 *   Date: 6/16/2010
 **********************************************************************
 */

#if defined(COPENEDATTACHED_NOT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cOpenedAttached
 *
 * Author: $author$
 *   Date: 6/16/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cOpenedAttached
: virtual public cOpenedAttachedImplement,
  public cOpenedAttachedExtend
{
public:
    typedef cOpenedAttachedImplement cImplements;
    typedef cOpenedAttachedExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cOpenedAttached
     *
     *       Author: $author$
     *         Date: 6/16/2010
     **********************************************************************
     */
    cOpenedAttached
    (tAttachedTo attached = (tAttachedTo)(vUnattached),
     bool isOpen = false) 
    : cExtends(isOpen)
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     *  Destructor: ~cOpenedAttached
     *
     *      Author: $author$
     *        Date: 6/16/2010
     **********************************************************************
     */
    virtual ~cOpenedAttached()
    {
        eError error;
        if ((error = Closed()))
            throw (error);
    }
#else /* defined(COPENEDATTACHED_NOT_MEMBERS_ONLY) */
#endif /* defined(COPENEDATTACHED_NOT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: AttachOpened
     *
     *    Author: $author$
     *      Date: 6/16/2010
     **********************************************************************
     */
    virtual tAttachedTo AttachOpened
    (tAttachedTo detached, 
     bool isOpen = true,
     bool onlyUnattached = false)
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
        if (detached != (tAttachedTo)(vUnattached))
        if (detached == (cExtends::Attach(detached, onlyUnattached)))
        if ((int)(isOpen) == (SetIsOpen(isOpen)))
            attached = detached;
        else
        cExtends::Detach();
        return attached;
    }
    /**
     **********************************************************************
     *  Function: Attach
     *
     *    Author: $author$
     *      Date: 6/16/2010
     **********************************************************************
     */
    virtual tAttachedTo Attach
    (tAttachedTo detached,
     bool onlyUnattached = false)
    {
        tAttachedTo attached = cExtends::Attach(detached, onlyUnattached);
        SetIsOpen(false);
        return attached;
    }
    /**
     **********************************************************************
     *  Function: Detach
     *
     *    Author: $author$
     *      Date: 6/16/2010
     **********************************************************************
     */
    virtual tAttachedTo Detach()
    {
        tAttachedTo detached = cExtends::Detach();
        SetIsOpen(false);
        return detached;
    }

#if defined(COPENEDATTACHED_NOT_MEMBERS_ONLY)
};
#else /* defined(COPENEDATTACHED_NOT_MEMBERS_ONLY) */
#endif /* defined(COPENEDATTACHED_NOT_MEMBERS_ONLY) */
