/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cdelegateinterface.hxx
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
#ifndef _CDELEGATEINTERFACE_HXX
#define _CDELEGATEINTERFACE_HXX

#include "cinterfacebase.hxx"

class c_INTERFACE_CLASS cDelegateInterface;

#undef CDB_CLASS
#define CDB_CLASS "cDelegateInterfaceT"
/**
 **********************************************************************
 *  Class: cDelegateInterfaceT
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
template
<class TDerives=cDelegateInterface,
 class TDelegated=cDelegateInterface,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>
 
class c_INTERFACE_CLASS cDelegateInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TDelegated tDelegated;

#define CDELEGATE_MEMBER_FUNCS_ONLY
#define CDELEGATE_MEMBER_FUNCS_INTERFACE
#include "cdelegate.hxx"
#undef CDELEGATE_MEMBER_FUNCS_INTERFACE
#undef CDELEGATE_MEMBER_FUNCS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cDelegateInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/1/2009
 **********************************************************************
 */
typedef cDelegateInterfaceT
<cDelegateInterface, cDelegateInterface>
cDelegateInterfaceImplements;
/**
 **********************************************************************
 *  Class: cDelegateInterface
 *
 * Author: $author$
 *   Date: 3/1/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cDelegateInterface
: virtual public cDelegateInterfaceImplements
{
public:
    typedef cDelegateInterfaceImplements cImplements;
    typedef cDelegateInterface cDerives;
};

class cDelegateImplement;

#undef CDB_CLASS
#define CDB_CLASS "cDelegateImplementT"
/**
 **********************************************************************
 *  Class: cDelegateImplementT
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
template
<class TDerives=cDelegateImplement,
 class TDelegated=cDelegateInterface,
 class TDelegateInterface=cDelegateInterface,
 class TImplements=TDelegateInterface>
 
class cDelegateImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TDelegated tDelegated;

#define CDELEGATE_MEMBER_FUNCS_ONLY
#define CDELEGATE_MEMBER_FUNCS_IMPLEMENT
#include "cdelegate.hxx"
#undef CDELEGATE_MEMBER_FUNCS_IMPLEMENT
#undef CDELEGATE_MEMBER_FUNCS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cDelegateImplementImplements
 *
 *  Author: $author$
 *    Date: 3/1/2009
 **********************************************************************
 */
typedef cDelegateImplementT
<cDelegateImplement,cDelegateInterface,cDelegateInterface>
cDelegateImplementImplements;
/**
 **********************************************************************
 *  Class: cDelegateImplement
 *
 * Author: $author$
 *   Date: 3/1/2009
 **********************************************************************
 */
class cDelegateImplement
: virtual public cDelegateImplementImplements
{
public:
    typedef cDelegateImplementImplements cImplements;
    typedef cDelegateImplement cDerives;
};

#endif /* _CDELEGATEINTERFACE_HXX */
