/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: cblockdeviceinterface.hxx
 *
 * Author: $author$
 *   Date: 9/4/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBLOCKDEVICEINTERFACE_HXX
#define _CBLOCKDEVICEINTERFACE_HXX

#include "platform.h"
#include "cbase.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cBlockDeviceInterfaceT
 *
 * Author: $author$
 *   Date: 9/4/2005
 **********************************************************************
 */
template
<class TIs=cInterfaceBase>
class c_INTERFACE_CLASS cBlockDeviceInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: ReadCapacity
     *
     *   Author: $author$
     *     Date: 9/4/2005
     **********************************************************************
     */
    virtual eError ReadCapacity
    (DWORD &length,
     DWORD &lba,
     WORD lun) = 0;
    /**
     **********************************************************************
     * Function: ReadBlocks
     *
     *   Author: $author$
     *     Date: 9/4/2005
     **********************************************************************
     */
    virtual int ReadBlocks
    (BYTE* block,
     DWORD length,
     DWORD lba,
     WORD lun) = 0;
    /**
     **********************************************************************
     * Function: WriteBlocks
     *
     *   Author: $author$
     *     Date: 9/4/2005
     **********************************************************************
     */
    virtual int WriteBlocks
    (const BYTE* block,
     DWORD length,
     DWORD lba,
     WORD lun) = 0;
};

/**
 **********************************************************************
 *  Class: cBlockDeviceInterface
 *
 * Author: $author$
 *   Date: 9/5/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cBlockDeviceInterface
: public cBlockDeviceInterfaceT<>
{
public:
    typedef cBlockDeviceInterfaceT<> cIs;
};

/**
 **********************************************************************
 *  Class: cBlockDeviceImplementT
 *
 * Author: $author$
 *   Date: 9/4/2005
 **********************************************************************
 */
template
<class TInterfaceIs=cBlockDeviceInterface>

class cBlockDeviceImplementT
: virtual public TInterfaceIs
{
public:
    /**
     **********************************************************************
     * Function: ReadCapacity
     *
     *   Author: $author$
     *     Date: 9/4/2005
     **********************************************************************
     */
    virtual eError ReadCapacity
    (DWORD &length,
     DWORD &lba,
     WORD lun) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: ReadBlocks
     *
     *   Author: $author$
     *     Date: 9/4/2005
     **********************************************************************
     */
    virtual int ReadBlocks
    (BYTE* block,
     DWORD length,
     DWORD lba,
     WORD lun) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: WriteBlocks
     *
     *   Author: $author$
     *     Date: 9/4/2005
     **********************************************************************
     */
    virtual int WriteBlocks
    (const BYTE* block,
     DWORD length,
     DWORD lba,
     WORD lun) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cBlockDeviceImplement
 *
 * Author: $author$
 *   Date: 9/5/2005
 **********************************************************************
 */
class cBlockDeviceImplement
: virtual public cBlockDeviceImplementT<>
{
public:
    typedef cBlockDeviceImplementT<> cIs;
};

#endif /* _CBLOCKDEVICEINTERFACE_HXX */
