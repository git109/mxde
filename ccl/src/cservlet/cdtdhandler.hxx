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
 *   File: cdtdhandler.hxx
 *
 * Author: $author$
 *   Date: 10/4/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDTDHANDLER_HXX
#define _CDTDHANDLER_HXX

#include "ccharstring.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cDTDHandlerInterfaceT
 *
 * Author: $author$
 *   Date: 10/4/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cDTDHandlerInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: OnNotationDecl
     *
     *   Author: $author$
     *     Date: 10/4/2004
     **********************************************************************
     */
    virtual eError OnNotationDecl
    (cCharStringInterface* name, cCharStringInterface* public_id, cCharStringInterface* system_id) = 0;
    /**
     **********************************************************************
     * Function: OnUnparsedEntityDecl
     *
     *   Author: $author$
     *     Date: 10/4/2004
     **********************************************************************
     */
    virtual eError OnUnparsedEntityDecl
    (cCharStringInterface* name, cCharStringInterface* public_id, cCharStringInterface* system_id) = 0;
};

/**
 **********************************************************************
 *  Class: cDTDHandlerImplementT
 *
 * Author: $author$
 *   Date: 10/4/2004
 **********************************************************************
 */
template <class TIs=cDTDHandlerInterfaceT<cInterface> >
class c_INTERFACE_CLASS cDTDHandlerImplementT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: OnNotationDecl
     *
     *   Author: $author$
     *     Date: 10/4/2004
     **********************************************************************
     */
    virtual eError OnNotationDecl
    (cCharStringInterface* name, cCharStringInterface* public_id, cCharStringInterface* system_id) 
    {
        eError result = e_ERROR_NONE;
        return result;
    }
    /**
     **********************************************************************
     * Function: OnUnparsedEntityDecl
     *
     *   Author: $author$
     *     Date: 10/4/2004
     **********************************************************************
     */
    virtual eError OnUnparsedEntityDecl
    (cCharStringInterface* name, cCharStringInterface* public_id, cCharStringInterface* system_id) 
    {
        eError result = e_ERROR_NONE;
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cDTDHandlerInterface
 *
 * Author: $author$
 *   Date: 10/5/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDTDHandlerInterface
: virtual public cDTDHandlerInterfaceT<cInterface>
{
public:
};

#endif /* ndef _CDTDHANDLER_HXX */
