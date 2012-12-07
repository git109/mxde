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
 *   File: cstreamdelegateinterface.hxx
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
#ifndef _CSTREAMDELEGATEINTERFACE_HXX
#define _CSTREAMDELEGATEINTERFACE_HXX

#include "cdelegateinterface.hxx"

class c_INTERFACE_CLASS cStreamDelegateInterface;
/**
 **********************************************************************
 * Typedef: cStreamDelegateInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/1/2009
 **********************************************************************
 */
typedef cDelegateInterfaceT
<cStreamDelegateInterface, cStreamInterface>
cStreamDelegateInterfaceImplements;
/**
 **********************************************************************
 *  Class: cStreamDelegateInterface
 *
 * Author: $author$
 *   Date: 3/1/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cStreamDelegateInterface
: virtual public cStreamDelegateInterfaceImplements
{
public:
    typedef cStreamDelegateInterfaceImplements cImplements;
    typedef cStreamDelegateInterface cDerives;
};

class cStreamDelegateImplement;
/**
 **********************************************************************
 * Typedef: cStreamDelegateImplementImplements
 *
 *  Author: $author$
 *    Date: 3/1/2009
 **********************************************************************
 */
typedef cDelegateImplementT
<cStreamDelegateImplement, cStreamInterface, cStreamDelegateInterface>
cStreamDelegateImplementImplements;
/**
 **********************************************************************
 *  Class: cStreamDelegateImplement
 *
 * Author: $author$
 *   Date: 3/1/2009
 **********************************************************************
 */
class cStreamDelegateImplement
: virtual public cStreamDelegateImplementImplements
{
public:
    typedef cStreamDelegateImplementImplements cImplements;
    typedef cStreamDelegateImplement cDerives;
};

/*
 * TCHAR
 */
class c_INTERFACE_CLASS cTCHARStreamDelegateInterface;
/**
 **********************************************************************
 * Typedef: cTCHARStreamDelegateInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cDelegateInterfaceT
<cTCHARStreamDelegateInterface, cTCHARStreamInterface>
cTCHARStreamDelegateInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTCHARStreamDelegateInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARStreamDelegateInterface
: virtual public cTCHARStreamDelegateInterfaceImplements
{
public:
    typedef cTCHARStreamDelegateInterfaceImplements cImplements;
    typedef cTCHARStreamDelegateInterface cDerives;
};
#endif /* _CSTREAMDELEGATEINTERFACE_HXX */
