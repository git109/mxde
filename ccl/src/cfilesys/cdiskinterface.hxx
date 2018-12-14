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
 *   File: cdiskinterface.hxx
 *
 * Author: $author$
 *   Date: 9/4/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDISKINTERFACE_HXX
#define _CDISKINTERFACE_HXX

#include "cblockdeviceinterface.hxx"

#define CDISKGEOMETRY_DEFAULT_BYTES_PER_SECTOR 512
#define CDISKGEOMETRY_DEFAULT_SECTORS_PER_TRACK 8
#define CDISKGEOMETRY_DEFAULT_TRACKS_PER_CYLINDER 2
 
/**
 **********************************************************************
 *  Class: cDiskGeometry
 *
 * Author: $author$
 *   Date: 9/4/2005
 **********************************************************************
 */
class cDiskGeometry
{
public:

     DWORD m_cylinders,
           m_sectors,
           m_tracks_per_cylinder,
           m_sectors_per_track,
           m_bytes_per_sector;

    /**
     **********************************************************************
     * Constructor: cDiskGeometry
     *
     *      Author: $author$
     *        Date: 9/4/2005
     **********************************************************************
     */
    cDiskGeometry
    (DWORD cylinders = 0,
     DWORD tracks_per_cylinder = CDISKGEOMETRY_DEFAULT_TRACKS_PER_CYLINDER,
     DWORD sectors_per_track = CDISKGEOMETRY_DEFAULT_SECTORS_PER_TRACK,
     DWORD bytes_per_sector = CDISKGEOMETRY_DEFAULT_BYTES_PER_SECTOR) 
    : m_cylinders(cylinders),
      m_tracks_per_cylinder(tracks_per_cylinder),
      m_sectors_per_track(sectors_per_track),
      m_bytes_per_sector(bytes_per_sector),
      m_sectors(cylinders*tracks_per_cylinder*sectors_per_track)
    {
    }
    /**
     **********************************************************************
     * Function: SetKBytes
     *
     *   Author: $author$
     *     Date: 9/5/2005
     **********************************************************************
     */
    virtual eError SetKBytes(DWORD kbytes) 
    {
        eError error = e_ERROR_NONE;
        DWORD tracks;

        m_sectors = (kbytes*1024)/m_bytes_per_sector;
        tracks = m_sectors/m_tracks_per_cylinder;
        m_cylinders = tracks/m_tracks_per_cylinder;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDiskInterfaceT
 *
 * Author: $author$
 *   Date: 9/4/2005
 **********************************************************************
 */
template
<class TIs=cBlockDeviceInterface>
class c_INTERFACE_CLASS cDiskInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: GetDiskGeometry
     *
     *   Author: $author$
     *     Date: 9/4/2005
     **********************************************************************
     */
    virtual eError GetDiskGeometry
    (cDiskGeometry& geometry) = 0;
};

/**
 **********************************************************************
 *  Class: cDiskInterface
 *
 * Author: $author$
 *   Date: 9/5/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDiskInterface
: public cDiskInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cDiskImplementT
 *
 * Author: $author$
 *   Date: 9/4/2005
 **********************************************************************
 */
template
<class TInterfaceIs=cDiskInterface>

class c_INTERFACE_CLASS cDiskImplementT
: virtual public TInterfaceIs
{
public:
    /**
     **********************************************************************
     * Function: GetDiskGeometry
     *
     *   Author: $author$
     *     Date: 9/4/2005
     **********************************************************************
     */
    virtual eError GetDiskGeometry
    (cDiskGeometry& geometry) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDiskImplement
 *
 * Author: $author$
 *   Date: 9/5/2005
 **********************************************************************
 */
class cDiskImplement
: virtual public cDiskImplementT<>
{
public:
    typedef cDiskImplementT<> cIs;
};

/**
 **********************************************************************
 *  Class: cDisk
 *
 * Author: $author$
 *   Date: 1/19/2006
 **********************************************************************
 */
class cDisk
: virtual public cDiskImplement
{
public:
    cDiskGeometry m_geometry;
    bool m_is_open;

    /**
     **********************************************************************
     * Constructor: cDisk
     *
     *      Author: $author$
     *        Date: 1/19/2006
     **********************************************************************
     */
    cDisk(DWORD kbytes=0) 
    : m_is_open(false)
    {
        eError error;

        if (kbytes)
        if ((error = Open(kbytes)))
            throw(error);
    }
    /**
     **********************************************************************
     *  Destructor: ~cDisk
     *
     *      Author: $author$
     *        Date: 1/19/2006
     **********************************************************************
     */
    virtual ~cDisk()
    {
        eError error;

        if (m_is_open)
        if ((error = Close()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 9/5/2005
     **********************************************************************
     */
    virtual eError Open(DWORD kbytes=0) 
    {
        eError error = e_ERROR_FAILED;

        if (kbytes)
            error = m_geometry.SetKBytes(kbytes);
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 9/5/2005
     **********************************************************************
     */
    virtual eError Close() 
    {
        eError error = e_ERROR_FAILED;

        if (m_is_open)
            error = e_ERROR_NONE;

        m_is_open = false;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetIsOpen
     *
     *   Author: $author$
     *     Date: 9/8/2005
     **********************************************************************
     */
    virtual bool GetIsOpen() 
    {
        return m_is_open;
    }

    /**
     **********************************************************************
     * Function: GetDiskGeometry
     *
     *   Author: $author$
     *     Date: 9/5/2005
     **********************************************************************
     */
    virtual eError GetDiskGeometry(cDiskGeometry& geometry) 
    {
        eError error = e_ERROR_NONE;

        geometry = m_geometry;
        return error;
    }
    /**
     **********************************************************************
     * Function: ReadCapacity
     *
     *   Author: $author$
     *     Date: 9/5/2005
     **********************************************************************
     */
    virtual eError ReadCapacity
    (DWORD &length, DWORD &lba, WORD lun) 
    {
        int error = e_ERROR_NONE;

        if (lun)
            return e_ERROR_ENDOF;

        length = m_geometry.m_bytes_per_sector;
        lba = m_geometry.m_sectors-1;
        return error;
    }
    /**
     **********************************************************************
     * Function: ReadBlocks
     *
     *   Author: $author$
     *     Date: 9/5/2005
     **********************************************************************
     */
    virtual int ReadBlocks
    (BYTE* block, DWORD length, DWORD lba, WORD lun) 
    {
        int result = -e_ERROR_FAILED;
        int count = 0;
        int bytes;

        if (lun)
            return -e_ERROR_ENDOF;

        if (m_geometry.m_sectors <= lba)
            return -e_ERROR_ENDOF;

        lba *= m_geometry.m_bytes_per_sector;

        do
        {
            if ((int)m_geometry.m_bytes_per_sector
                != (bytes = ReadBlock
                    (block, m_geometry.m_bytes_per_sector, lba, lun)))
                return result;

            block += m_geometry.m_bytes_per_sector;
            count += m_geometry.m_bytes_per_sector;
            lba++;
        }
        while (--length);

        result = count;
        return result;
    }
    /**
     **********************************************************************
     * Function: WriteBlocks
     *
     *   Author: $author$
     *     Date: 9/5/2005
     **********************************************************************
     */
    virtual int WriteBlocks
    (const BYTE* block, DWORD length, DWORD lba, WORD lun) 
    {
        int result = -e_ERROR_FAILED;
        int count = 0;
        int bytes;

        if (lun)
            return -e_ERROR_ENDOF;

        if (m_geometry.m_sectors <= lba)
            return -e_ERROR_ENDOF;

        lba *= m_geometry.m_bytes_per_sector;

        do
        {
            if ((int)m_geometry.m_bytes_per_sector
                != (bytes = WriteBlock
                    (block, m_geometry.m_bytes_per_sector, lba, lun)))
                return result;

            block += m_geometry.m_bytes_per_sector;
            count += m_geometry.m_bytes_per_sector;
            lba++;
        }
        while (--length);

        result = count;
        return result;
    }

    /**
     **********************************************************************
     * Function: ReadBlock
     *
     *   Author: $author$
     *     Date: 9/5/2005
     **********************************************************************
     */
    virtual int ReadBlock
    (BYTE* block, DWORD length, DWORD lba, WORD lun) 
    {
        int result = length;
        memset(block, 0x86, length);
        return result;
    }
    /**
     **********************************************************************
     * Function: WriteBlock
     *
     *   Author: $author$
     *     Date: 9/5/2005
     **********************************************************************
     */
    virtual int WriteBlock
    (const BYTE* block, DWORD length, DWORD lba, WORD lun) 
    {
        int result = length;
        return result;
    }
};

#endif /* _CDISKINTERFACE_HXX */
