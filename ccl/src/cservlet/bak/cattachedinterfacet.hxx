/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: cattachedinterfacet.hxx
 *
 * Author: $author$
 *   Date: 10/15/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CATTACHEDINTERFACET_HXX
#define _CATTACHEDINTERFACET_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cAttachedInterfaceT
 *
 * Author: $author$
 *   Date: 10/15/2004
 **********************************************************************
 */
template 
<class TAttached, TAttached VDetached=0, class TIs=cInterface>
class c_INTERFACE_CLASS cAttachedInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 10/15/2004
     **********************************************************************
     */
    virtual TAttached Attach(TAttached attached) = 0;
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 10/15/2004
     **********************************************************************
     */
    virtual TAttached Detach() = 0;
    /**
     **********************************************************************
     * Function: Attached
     *
     *   Author: $author$
     *     Date: 10/15/2004
     **********************************************************************
     */
    virtual TAttached Attached() = 0;
};

/**
 **********************************************************************
 *  Class: cAttachedImplementT
 *
 * Author: $author$
 *   Date: 10/15/2004
 **********************************************************************
 */
template 
<class TAttached, TAttached VDetached=0, 
 class TIs=cAttachedInterfaceT
 <TAttached, VDetached, cInterface> >
class c_INTERFACE_CLASS cAttachedImplementT
: virtual public TIs
{
public:

    TAttached m_attached;

    /**
     **********************************************************************
     * Constructor: cAttachedImplementT
     *
     *      Author: $author$
     *        Date: 10/16/2004
     **********************************************************************
     */
    cAttachedImplementT(TAttached attached=VDetached) 
    : m_attached(attached)
    {
    }

    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 10/15/2004
     **********************************************************************
     */
    virtual TAttached Attach(TAttached attached) 
    {
        TAttached old_attached = m_attached;
        m_attached = attached;
        return old_attached;
    }
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 10/15/2004
     **********************************************************************
     */
    virtual TAttached Detach() 
    {
        TAttached attached = m_attached;
        m_attached = VDetached;
        return attached;
    }
    /**
     **********************************************************************
     * Function: Attached
     *
     *   Author: $author$
     *     Date: 10/15/2004
     **********************************************************************
     */
    virtual TAttached Attached() 
    {
        TAttached attached = m_attached;
        return attached;
    }
};

#endif /* ndef _CATTACHEDINTERFACET_HXX */
