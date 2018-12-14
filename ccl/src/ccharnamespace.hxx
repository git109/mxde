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
 *   File: ccharnamespace.hxx
 *
 * Author: $author$
 *   Date: 12/10/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARNAMESPACE_HXX
#define _CCHARNAMESPACE_HXX

#include "cnamespace.hxx"

/**
 **********************************************************************
 *  Class: cCharNamedInterfaceT
 *
 * Author: $author$
 *   Date: 12/10/2003
 **********************************************************************
 */
template <class TAs>
class c_INTERFACE_CLASS cCharNamedInterfaceT
: public cNamedInterfaceT<TAs, char>
{
public:
    typedef cNamedInterfaceT<TAs, char> cIs;
};

/**
 **********************************************************************
 *  Class: cCharNamedInterface
 *
 * Author: $author$
 *   Date: 12/10/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cCharNamedInterface
: public cCharNamedInterfaceT<cCharNamedInterface>
{
public:
    typedef cCharNamedInterfaceT<cCharNamedInterface> cIs;
};

/**
 **********************************************************************
 *  Class: cCharNamedT
 *
 * Author: $author$
 *   Date: 12/10/2003
 **********************************************************************
 */
template 
<class TAs, class TInterfaceIs,
 class TIs=cNamedT<TAs, char, TInterfaceIs> >
class cCharNamedT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     * Constructor: cCharNamedT
     *
     *      Author: $author$
     *        Date: 12/10/2003
     **********************************************************************
     */
    cCharNamedT(const char *name, int length=-1)
    : cIs(name, length)
    {
    }
};

/**
 **********************************************************************
 *  Class: cCharNamed
 *
 * Author: $author$
 *   Date: 12/10/2003
 **********************************************************************
 */
class cCharNamed
: public cCharNamedT<cCharNamed, cCharNamedInterface>
{
public:
    typedef cCharNamedT<cCharNamed, cCharNamedInterface> cIs;

    /**
     **********************************************************************
     * Constructor: cCharNamed
     *
     *      Author: $author$
     *        Date: 12/10/2003
     **********************************************************************
     */
    cCharNamed(const char *name, int length=-1)
    : cIs(name, length)
    {
    }
};

/**
 **********************************************************************
 *  Class: cCharNameSpaceInterfaceT
 *
 * Author: $author$
 *   Date: 12/10/2003
 **********************************************************************
 */
template <class TAs, class TOfInterfaceIs>
class c_INTERFACE_CLASS cCharNameSpaceInterfaceT
: public cNameSpaceInterfaceT
  <TAs, TOfInterfaceIs, const char *>
{
public:
    typedef cNameSpaceInterfaceT
    <TAs, TOfInterfaceIs, const char *> cIs;
};

/**
 **********************************************************************
 *  Class: cCharNameSpaceT
 *
 * Author: $author$
 *   Date: 12/8/2003
 **********************************************************************
 */
template 
<class TAs, class TOf, class TOfInterfaceIs, class TInterfaceIs,
 class TIs=cNameSpaceT<TAs, TOf, const char *, TInterfaceIs> >
class cCharNameSpaceT
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
    virtual TOfInterfaceIs *Find(const char *const &name) const
    {
        return cIs::cIs::Find(name);
    }
};

/**
 **********************************************************************
 *  Class: cCharNameSpaceInterface
 *
 * Author: $author$
 *   Date: 12/10/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cCharNameSpaceInterface
: public cNameSpaceInterfaceT
  <cCharNameSpaceInterface, cCharNamedInterface, const char *>
{
public:
    typedef cNameSpaceInterfaceT
    <cCharNameSpaceInterface, cCharNamedInterface, const char *> cIs;
};

/**
 **********************************************************************
 *  Class: cCharNameSpace
 *
 * Author: $author$
 *   Date: 12/10/2003
 **********************************************************************
 */
class cCharNameSpace
: public cCharNameSpaceT
  <cCharNameSpace, cCharNamed,
   cCharNamedInterface, cCharNameSpaceInterface>
{
public:
};

#endif /* ndef _CCHARNAMESPACE_HXX */
