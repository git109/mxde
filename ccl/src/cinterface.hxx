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
 *   File: cinterface.hxx
 *
 * Author: $author$
 *   Date: 7/5/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CINTERFACE_HXX
#define _CINTERFACE_HXX

#include "cerror.h"

#if defined(WIN32)
#define c_INTERFACE_CLASS __declspec(dllexport)
#define c_EXPORT_CLASS __declspec(dllexport)
#define c_EXPORT __declspec(dllexport)
#else
#define c_INTERFACE_CLASS
#define c_EXPORT_CLASS
#define c_EXPORT
#endif

#define c_INTERFACE_VERSION(major,minor) ((major)<<8)|(minor)
#define c_INTERFACE_VERSION_MAJOR(version) ((version)>>8)
#define c_INTERFACE_VERSION_MINOR(version) ((version)&255)

/**
 **********************************************************************
 *  Class: cInterface
 *
 * Author: $author$
 *   Date: 7/5/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cInterface
{
public:
    /**
     **********************************************************************
     *   Enum:
     *
     * Author: $author$
     *   Date: 7/5/2003
     **********************************************************************
     */
    enum
    {
        e_FIRST_ERROR = ::e_NEXT_ERROR,
        e_NEXT_ERROR  = e_FIRST_ERROR,
        e_LAST_ERROR  = e_NEXT_ERROR-1
    };

    /**
     **********************************************************************
     * Function: HoldInstance
     *
     *   Author: $author$
     *     Date: 7/5/2003
     **********************************************************************
     */
    virtual eError HoldInstance()=0;
    /**
     **********************************************************************
     * Function: FreeInstance
     *
     *   Author: $author$
     *     Date: 7/5/2003
     **********************************************************************
     */
    virtual eError FreeInstance()=0;
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual eError DeleteInstance()=0;
    /**
     **********************************************************************
     * Function: SetLastError
     *
     *   Author: $author$
     *     Date: 7/5/2003
     **********************************************************************
     */
    virtual eError SetLastError
    (eError error,const char *description=0)=0;
    /**
     **********************************************************************
     * Function: GetLastError
     *
     *   Author: $author$
     *     Date: 7/5/2003
     **********************************************************************
     */
    virtual eError GetLastError
    (const char *&description) const=0;
};

/**
 **********************************************************************
 *  Class: cInterfaceBase
 *
 * Author: $author$
 *   Date: 11/5/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cInterfaceBase
{
public:
};

#endif
