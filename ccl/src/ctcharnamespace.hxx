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
 *   File: ctcharnamespace.hxx
 *
 * Author: $author$
 *   Date: 12/10/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTCHARNAMESPACE_HXX
#define _CTCHARNAMESPACE_HXX

#include "cnamespace.hxx"

/**
 **********************************************************************
 *  Class: cTCHARNamedInterface
 *
 * Author: $author$
 *   Date: 12/9/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARNamedInterface
: public cNamedInterfaceT<cTCHARNamedInterface, TCHAR>
{
public:
    typedef cNamedInterfaceT<cTCHARNamedInterface, TCHAR> cIs;
};

/**
 **********************************************************************
 *  Class: cTCHARNamedT
 *
 * Author: $author$
 *   Date: 12/9/2003
 **********************************************************************
 */
template 
<class TAs, class TInterfaceIs,
 class TIs=cNamedT<TAs, TCHAR, TInterfaceIs> >
class cTCHARNamedT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     * Constructor: cTCHARNamedT
     *
     *      Author: $author$
     *        Date: 12/9/2003
     **********************************************************************
     */
    cTCHARNamedT(const TCHAR *name, int length=-1)
    : cIs(name, length)
    {
    }
};

/**
 **********************************************************************
 *  Class: cTCHARNamed
 *
 * Author: $author$
 *   Date: 12/9/2003
 **********************************************************************
 */
class cTCHARNamed
: public cTCHARNamedT<cTCHARNamed, cTCHARNamedInterface>
{
public:
    typedef cTCHARNamedT<cTCHARNamed, cTCHARNamedInterface> cIs;

    /**
     **********************************************************************
     * Constructor: cTCHARNamed
     *
     *      Author: $author$
     *        Date: 12/9/2003
     **********************************************************************
     */
    cTCHARNamed(const TCHAR *name, int length=-1)
    : cIs(name, length)
    {
    }
};

/**
 **********************************************************************
 *  Class: cTCHARNameSpaceInterface
 *
 * Author: $author$
 *   Date: 12/9/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARNameSpaceInterface
: public cNameSpaceInterfaceT
  <cTCHARNameSpaceInterface, cTCHARNamedInterface, const TCHAR *>
{
public:
    typedef cNameSpaceInterfaceT
    <cTCHARNameSpaceInterface, cTCHARNamedInterface, const TCHAR *> cIs;
};

/**
 **********************************************************************
 *  Class: cTCHARNameSpaceT
 *
 * Author: $author$
 *   Date: 12/8/2003
 **********************************************************************
 */
template 
<class TAs, class TOf, class TOfInterfaceIs, class TInterfaceIs,
 class TIs=cNameSpaceT<TAs, TOf, const TCHAR *, TInterfaceIs> >
class cTCHARNameSpaceT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 12/8/2003
     **********************************************************************
     */
    virtual TOfInterfaceIs *Find(const TCHAR *const &name) const
    {
        return cIs::cIs::Find(name);
    }
};

/**
 **********************************************************************
 *  Class: cTCHARNameSpace
 *
 * Author: $author$
 *   Date: 12/8/2003
 **********************************************************************
 */
class cTCHARNameSpace
: public cTCHARNameSpaceT
  <cTCHARNameSpace, cTCHARNamed,
   cTCHARNamedInterface, cTCHARNameSpaceInterface>
{
public:
};

#endif /* ndef _CTCHARNAMESPACE_HXX */
