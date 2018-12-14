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
 *   File: cservletinterface.hxx
 *
 * Author: $author$
 *   Date: 10/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSERVLETINTERFACE_HXX
#define _CSERVLETINTERFACE_HXX

#include "cverboseinterface.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cServletInterfaceT
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cServletInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Init
     *
     *   Author: $author$
     *     Date: 11/12/2004
     **********************************************************************
     */
    virtual eError Init() = 0;
    /**
     **********************************************************************
     * Function: Final
     *
     *   Author: $author$
     *     Date: 11/12/2004
     **********************************************************************
     */
    virtual eError Final() = 0;
    /**
     **********************************************************************
     * Function: SetServletName
     *
     *   Author: $author$
     *     Date: 12/10/2004
     **********************************************************************
     */
    virtual int SetServletName(const char* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetServletName
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual const char* GetServletName(int &length) const = 0;
};

/**
 **********************************************************************
 *  Class: cServletInterface
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cServletInterface
: virtual public cServletInterfaceT<>,
  virtual public cVerboseInterface
{
public:
};

/**
 **********************************************************************
 *  Class: cQuietServletInterface
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cQuietServletInterface
: virtual public cServletInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cServletImplementT
 *
 * Author: $author$
 *   Date: 11/12/2004
 **********************************************************************
 */
template <class TIs=cServletInterface>
class cServletImplementT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Init
     *
     *   Author: $author$
     *     Date: 11/12/2004
     **********************************************************************
     */
    virtual eError Init() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Final
     *
     *   Author: $author$
     *     Date: 11/12/2004
     **********************************************************************
     */
    virtual eError Final() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetServletName
     *
     *   Author: $author$
     *     Date: 12/10/2004
     **********************************************************************
     */
    virtual int SetServletName(const char* chars, int length=-1)
    {
        length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: GetServletName
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual const char* GetServletName(int &length) const
    {
        const char* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }
};

/**
 **********************************************************************
 *  Class: cServletImplement
 *
 * Author: $author$
 *   Date: 11/12/2004
 **********************************************************************
 */
class cServletImplement
: virtual public cServletImplementT<>
{
public:
};

#endif /* ndef _CSERVLETINTERFACE_HXX */
