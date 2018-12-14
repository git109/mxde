/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: cnamespace.hxx
 *
 * Author: $author$
 *   Date: 12/8/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CNAMESPACE_HXX
#define _CNAMESPACE_HXX

#include "platform.h"
#include "cavltreet.hxx"
#include "ctcharbuffer.hxx"
#include "cinterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cNamedInterfaceT
 *
 * Author: $author$
 *   Date: 12/8/2003
 **********************************************************************
 */
template <class TAs, class TOf, class TInterfaceIs=cInterface>
class c_INTERFACE_CLASS cNamedInterfaceT
: virtual public TInterfaceIs
{
public:
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 12/8/2003
     **********************************************************************
     */
    virtual eError SetName(const TOf *name, int namelen=-1)=0;
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 12/8/2003
     **********************************************************************
     */
    virtual const TOf *GetName() const=0;

};

/**
 **********************************************************************
 *  Class: cNamedT
 *
 * Author: $author$
 *   Date: 12/8/2003
 **********************************************************************
 */
template 
<class TAs, class TOf, class TInterfaceIs,
 class TIs=cAVLTreeBranchT<TAs, cImplement> >
class cNamedT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    cBufferT<256, TOf> m_name;

    /**
     **********************************************************************
     * Constructor: cNamedT
     *
     *      Author: $author$
     *        Date: 12/8/2003
     **********************************************************************
     */
    cNamedT(const TOf *name=0, int namelen=-1) 
    {
        int count;
        eError error;

        if (name)
        if (0 > (count = SetName(name, namelen)))
            throw(error = -count);
    }

    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 12/8/2003
     **********************************************************************
     */
    virtual eError SetName(const TOf *name, int namelen=-1)
    {
        return m_name.Copy(name, namelen);
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 12/8/2003
     **********************************************************************
     */
    virtual const TOf *GetName() const
    {
        return m_name.GetBuffer();
    }

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/8/2003
     **********************************************************************
     */
    virtual int Compare(TAs &named) const
    {
        return Compare(named.GetName());
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/8/2003
     **********************************************************************
     */
    virtual int Compare(const TOf *const &name) const
    {
        return m_name.Compare(name);
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/8/2003
     **********************************************************************
     */
    virtual int Compare(const TOf *const &name,int length) const
    {
        return m_name.Compare(name, length);
    }
};

/**
 **********************************************************************
 *  Class: cNameSpaceInterfaceT
 *
 * Author: $author$
 *   Date: 12/8/2003
 **********************************************************************
 */
template 
<class TAs, class TOf, class THas, class TInterfaceIs=cInterface>
class c_INTERFACE_CLASS cNameSpaceInterfaceT
: virtual public TInterfaceIs
{
public:
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 12/8/2003
     **********************************************************************
     */
    virtual TOf *Find(const THas &name) const=0;
};

/**
 **********************************************************************
 *  Class: cNameSpaceT
 *
 * Author: $author$
 *   Date: 12/8/2003
 **********************************************************************
 */
template 
<class TAs, class TOf, class THas, class TInterfaceIs,
 class TIs=cAVLTreeT<THas, TOf, TAs, cImplement> >
class c_INTERFACE_CLASS cNameSpaceT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;
};

#endif /* ndef _CNAMESPACE_HXX */
