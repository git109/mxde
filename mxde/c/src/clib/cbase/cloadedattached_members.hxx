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
 *   File: cloadedattached_members.hxx
 *
 * Author: $author$
 *   Date: 6/15/2010
 **********************************************************************
 */

#if defined(CLOADEDATTACHED_NOT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cLoadedAttached
 *
 * Author: $author$
 *   Date: 6/15/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cLoadedAttached
: public cLoadedAttachedExtend
{
public:
    typedef cLoadedAttachedExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cLoadedAttached
     *
     *       Author: $author$
     *         Date: 6/15/2010
     **********************************************************************
     */
    cLoadedAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isLoaded=false) 
    : cExtends(isLoaded)
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     *  Destructor: ~cLoadedAttached
     *
     *      Author: $author$
     *        Date: 6/15/2010
     **********************************************************************
     */
    virtual ~cLoadedAttached()
    {
        eError error;
        if ((error = UnLoaded()))
            throw (error);
    }
#else /* defined(CLOADEDATTACHED_NOT_MEMBERS_ONLY) */
#endif /* defined(CLOADEDATTACHED_NOT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: AttachLoaded
     *
     *    Author: $author$
     *      Date: 6/16/2010
     **********************************************************************
     */
    virtual tAttachedTo AttachLoaded
    (tAttachedTo detached, 
     bool isLoaded = true,
     bool onlyUnattached = false)
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
        if (detached != (tAttachedTo)(vUnattached))
        if (detached == (cExtends::Attach(detached, onlyUnattached)))
        if ((int)(isLoaded) == (SetIsLoaded(isLoaded)))
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
        SetIsLoaded(false);
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
        SetIsLoaded(false);
        return detached;
    }

#if defined(CLOADEDATTACHED_NOT_MEMBERS_ONLY)
};
#else /* defined(CLOADEDATTACHED_NOT_MEMBERS_ONLY) */
#endif /* defined(CLOADEDATTACHED_NOT_MEMBERS_ONLY) */
