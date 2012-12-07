/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: cdisk.hxx
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
#if !defined(_CDISK_HXX) || defined(CDISK_MEMBERS_ONLY)
#if !defined(_CDISK_HXX) && !defined(CDISK_MEMBERS_ONLY)
#define _CDISK_HXX
#endif /* !defined(_CDISK_HXX) && !defined(CDISK_MEMBERS_ONLY) */

#if !defined(CDISK_MEMBERS_ONLY)
#include "cblockdevice.hxx"
#include "cstring.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cDiskExtend
 *
 *  Author: $author$
 *    Date: 4/4/2010
 **********************************************************************
 */
typedef cBlockDevice
cDiskExtend;
/**
 **********************************************************************
 *  Class: cDisk
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cDisk
: public cDiskExtend
{
public:
    typedef cDiskExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cDisk
     *
     *       Author: $author$
     *         Date: 4/4/2010
     **********************************************************************
     */
    cDisk
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    : cExtends(attached, isOpen)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDisk
     *
     *      Author: $author$
     *        Date: 4/4/2010
     **********************************************************************
     */
    virtual ~cDisk()
    {
    }
#else /* !defined(CDISK_MEMBERS_ONLY) */
#endif /* !defined(CDISK_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: OpenDrive
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual eError OpenDrive
    (const CHAR* driveName,
     eOMode oMode=e_O_RDONLY,
     eSMode sMode=e_S_IRWXU,
     bool onlyClosed=true)
#if defined(CDISK_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CDISK_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CDISK_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
#if defined(WINDOWS) 
/* Windows
 */
        cWString wString;
        const WCHAR* wChars;
        if (0 < (wString.AssignCHARS(driveName)))
        if ((wChars = wString.HasChars()))
            error = OpenDrive(wChars, oMode, sMode, onlyClosed);
#else /* defined(WINDOWS) */
/* Otherwise
 */
#endif /* defined(WINDOWS) */
#else /* !defined(CDISK_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDISK_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CDISK_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OpenDrive
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual eError OpenDrive
    (const WCHAR* driveName,
     eOMode oMode=e_O_RDONLY,
     eSMode sMode=e_S_IRWXU,
     bool onlyClosed=true)
#if defined(CDISK_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CDISK_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CDISK_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
#if defined(WINDOWS) 
/* Windows
 */
        cTString deviceName;
        const TCHAR* deviceNameChars;

        if (0 < (deviceName.AssignCHARS("\\\\.\\")))
        if (0 < (deviceName.AppendW(driveName)))
        if (0 < (deviceName.AppendCHARS(":")))
        if ((deviceNameChars = deviceName.HasChars()))
            error = Open(deviceNameChars, oMode, sMode, onlyClosed);
#else /* defined(WINDOWS) */
/* Otherwise
 */
#endif /* defined(WINDOWS) */
#else /* !defined(CDISK_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDISK_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CDISK_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetDriveSize
     *
     *    Author: $author$
     *      Date: 4/4/2010
     **********************************************************************
     */
    virtual INT64 GetDriveSize
    (UINT64& blocks, UINT64& blockSize)
#if defined(CDISK_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CDISK_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CDISK_MEMBER_FUNCS_IMPLEMENT)
        INT64 size = -e_ERROR_NOT_ATTACHED;
        tAttachedTo attached;

        if ((attached = Attached()) != (tAttachedTo)(vUnattached))
        {
#if defined(WINDOWS) 
/* Windows
 */
#if defined(IOCTL_DISK_GET_LENGTH_INFO)
            GET_LENGTH_INFORMATION li;
#endif /* defined(IOCTL_DISK_GET_LENGTH_INFO) */
            DISK_GEOMETRY dg;
            DWORD dgSize;

            if (DeviceIoControl
                (attached, IOCTL_DISK_GET_DRIVE_GEOMETRY,
                 NULL, 0, &dg, sizeof(dg), &dgSize, NULL))
            {
                blockSize = dg.BytesPerSector;
                blocks = dg.SectorsPerTrack;
                blocks *= dg.TracksPerCylinder;
                blocks *= dg.Cylinders.QuadPart;
                size = blockSize*blocks;

#if defined(IOCTL_DISK_GET_LENGTH_INFO) 
                if (DeviceIoControl
                    (attached, IOCTL_DISK_GET_LENGTH_INFO,
                     NULL, 0, &li, sizeof(li), &dgSize, NULL))
                {
                    if (size > (li.Length.QuadPart))
                        size = (li.Length.QuadPart);
                }
#endif /* defined(IOCTL_DISK_GET_LENGTH_INFO) */
            }
            else
            size = -e_ERROR_FAILED;
#else /* defined(WINDOWS) */
/* Otherwise
 */
#endif /* defined(WINDOWS) */
        }
#else /* !defined(CDISK_MEMBER_FUNCS_IMPLEMENT) */
        INT64 size = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDISK_MEMBER_FUNCS_IMPLEMENT) */
        return size;
    }
#endif /* defined(CDISK_MEMBER_FUNCS_INTERFACE) */

#if !defined(CDISK_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CDISK_MEMBERS_ONLY) */
#endif /* !defined(CDISK_MEMBERS_ONLY) */

#endif /* !defined(_CDISK_HXX) || defined(CDISK_MEMBERS_ONLY) */
