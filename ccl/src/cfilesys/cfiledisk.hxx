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
 *   File: cfiledisk.hxx
 *
 * Author: $author$
 *   Date: 9/5/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEDISK_HXX
#define _CFILEDISK_HXX

#include "cdiskinterface.hxx"
#include "cbytefile.hxx"

/**
 **********************************************************************
 *  Class: cFileDisk
 *
 * Author: $author$
 *   Date: 9/5/2005
 **********************************************************************
 */
class cFileDisk
: public cDiskImplement
{
public:
    typedef cDiskImplement cIs;

    cDiskGeometry m_geometry;
    cBYTEFile m_file;

    /**
     **********************************************************************
     * Constructor: cFileDisk
     *
     *      Author: $author$
     *        Date: 9/5/2005
     **********************************************************************
     */
    cFileDisk(const char *filename=0, DWORD kbytes=0) 
    {
        eError error;

        if (filename)
        if ((error = Open(filename, kbytes)))
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
    virtual eError Open
    (const char *filename, DWORD kbytes=0) 
    {
        eError error2, error = e_ERROR_FAILED;
        long length;
        BYTE kbyte[1024];
        
        if (kbytes)
        if ((error2 = m_geometry.SetKBytes(kbytes)))
            return error;

        if ((error2 = m_file.Open(filename, "rb")))
        {
            if ((error = m_file.Open(filename, "wb")))
                return error;

            memset(kbyte, 0xF6, sizeof(kbyte));

            for (; kbytes; --kbytes)
            {
                if ((length = m_file.Write
                    (kbyte, sizeof(kbyte))) != sizeof(kbyte))
                    break;
            }
            m_file.Close();
        }
        else
        {
            length = m_file.GetLength();
            m_file.Close();

            if (length != ((long)kbytes)*1024)
                return error;
        }
        
        error = m_file.Open(filename, "rb+");
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
        eError error = m_file.Close();
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
        bool is_open = m_file.GetIsOpen();
        return is_open;
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
    (DWORD &length,
     DWORD &lba,
     WORD lun) 
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
    (BYTE* block,
     DWORD length,
     DWORD lba,
     WORD lun) 
    {
        int result = -e_ERROR_FAILED;
        int count = 0;
        long tell;

        if (lun)
            return -e_ERROR_ENDOF;

        if (m_geometry.m_sectors <= lba)
            return -e_ERROR_ENDOF;

        lba *= m_geometry.m_bytes_per_sector;

        if (0 <= (tell = m_file.Seek(lba)))
        {
            do
            {
                if ((long)m_geometry.m_bytes_per_sector
                    != (tell = m_file.Read
                        (block, m_geometry.m_bytes_per_sector)))
                    return result;

                block += m_geometry.m_bytes_per_sector;
                count += m_geometry.m_bytes_per_sector;
            }
            while (--length);

            result = count;
        }
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
    (const BYTE* block,
     DWORD length,
     DWORD lba,
     WORD lun) 
    {
        int result = -e_ERROR_FAILED;
        int count = 0;
        long tell;

        if (lun)
            return -e_ERROR_ENDOF;

        if (m_geometry.m_sectors <= lba)
            return -e_ERROR_ENDOF;

        lba *= m_geometry.m_bytes_per_sector;

        if (0 <= (tell = m_file.Seek(lba)))
        {
            do
            {
                if ((long)m_geometry.m_bytes_per_sector
                    != (tell = m_file.Write
                        (block, m_geometry.m_bytes_per_sector)))
                    return result;

                block += m_geometry.m_bytes_per_sector;
                count += m_geometry.m_bytes_per_sector;
            }
            while (--length);

            m_file.Flush();
            result = count;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: GetDiskGeometry
     *
     *   Author: $author$
     *     Date: 9/5/2005
     **********************************************************************
     */
    virtual eError GetDiskGeometry
    (cDiskGeometry& geometry) 
    {
        eError error = e_ERROR_NONE;

        geometry = m_geometry;
        return error;
    }
};

#endif /* _CFILEDISK_HXX */
