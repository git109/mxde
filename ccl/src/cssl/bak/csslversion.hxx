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
 *   File: csslversion.hxx
 *
 * Author: $author$
 *   Date: 1/12/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLVERSION_HXX
#define _CSSLVERSION_HXX

#include "platform.h"
#include "cbytestream.hxx"


/**
 **********************************************************************
 *  Class: cSSLVersion
 *
 * Author: $author$
 *   Date: 1/12/2005
 **********************************************************************
 */
class cSSLVersion
{
public:
    uint8 m_major,m_minor;

    /**
     **********************************************************************
     * Constructor: cSSLVersion
     *
     *      Author: $author$
     *        Date: 1/12/2005
     **********************************************************************
     */
    cSSLVersion(uint8 major=3, uint8 minor=0) 
    {
        int size;
        eError error;

        if (0 > (size = Set(major, minor)))
            throw(error = -size);
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = sizeof(m_major)+sizeof(m_minor);
        return size;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int Copy(const cSSLVersion &version)
    {
        int size;

        if (&version == this)
            return size = Sizeof();

        size = Set(version.m_major,version.m_minor);
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int Set(uint8 major=3, uint8 minor=0)
    {
        int size = Sizeof();
        m_major = major;
        m_minor = minor;
        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;
        uint8 buffer[2];

        if ((size = stream.Read(buffer, sizeof(buffer))) == sizeof(buffer))
        {
            m_major = buffer[0];
            m_minor = buffer[1];
        }
        else if (0 >= size)
                size = -e_ERROR_FAILED;

        return size;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size;
        uint8 buffer[2];

        buffer[0] = m_major;
        buffer[1] = m_minor;

        if ((size = stream.Write(buffer, sizeof(buffer))) != sizeof(buffer))
        if (0 >= size)
           size = -e_ERROR_FAILED;

        return size;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 1/12/2005
     **********************************************************************
     */
    int operator != (cSSLVersion &version)
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CSSLVERSION_HXX */
