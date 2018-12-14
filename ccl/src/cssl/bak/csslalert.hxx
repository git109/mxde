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
 *   File: csslalert.hxx
 *
 * Author: $author$
 *   Date: 1/15/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLALERT_HXX
#define _CSSLALERT_HXX

#include "platform.h"
#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cSSLAlertLevel
 *
 * Author: $author$
 *   Date: 1/15/2005
 **********************************************************************
 */
class cSSLAlertLevel
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/15/2005
     **********************************************************************
     */
    enum
    {
        e_NONE    = -1,
        e_WARNING = 1,
        e_FATAL   = 2
    };

    uint8 m_code;

    /**
     **********************************************************************
     * Constructor: cSSLAlertLevel
     *
     *      Author: $author$
     *        Date: 1/15/2005
     **********************************************************************
     */
    cSSLAlertLevel(uint8 code=e_NONE) 
    : m_code(code)
    {
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = sizeof(m_code);
        return size;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Copy(const cSSLAlertLevel &level)
    {
        int size;
        
        if (&level == this)
            return size = Sizeof();

        size = Set(level.m_code);
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Set(uint8 code)
    {
        int size = Sizeof();
        m_code = code;
        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;

        if (0 > (size = stream.Getb()))
            return size;

        m_code = size;
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) 
    {
        int size;

        if (0 > (size = stream.Putb(m_code)))
            return size;

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int operator != (const cSSLAlertLevel &level)
    {
        int unequal = m_code-level.m_code;
        return unequal;
    }
};

/**
 **********************************************************************
 *  Class: cSSLAlertDescription
 *
 * Author: $author$
 *   Date: 1/15/2005
 **********************************************************************
 */
class cSSLAlertDescription
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/15/2005
     **********************************************************************
     */
    enum
    {
        e_NONE                    = -1,
        e_CLOSE_NOTIFY            = 0,
        e_UNEXPECTED_MESSAGE      = 10,
        e_BAD_RECORD_MAC          = 20,
        e_DECOMPRESSION_FAILURE   = 30,
        e_HANDSHAKE_FAILURE       = 40,
        e_NO_CERTIFICATE          = 41,
        e_BAD_CERTIFICATE         = 42,
        e_UNSORPORTED_CERTIFICATE = 43,
        e_CERTIFICATE_REVOKED     = 44,
        e_CERTIFICATE_EXPIRED     = 45,
        e_CERTIFICATE_UNKNOWN     = 46,
        e_ILLEGAL_PARAMETER       = 47
    };

    uint8 m_code;

    /**
     **********************************************************************
     * Constructor: cSSLAlertDescription
     *
     *      Author: $author$
     *        Date: 1/15/2005
     **********************************************************************
     */
    cSSLAlertDescription(uint8 code=e_NONE) 
    : m_code(code)
    {
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = sizeof(m_code);
        return size;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Copy(const cSSLAlertDescription &description)
    {
        int size;
        
        if (&description == this)
            return size = Sizeof();

        size = Set(description.m_code);
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Set(uint8 code)
    {
        int size = Sizeof();
        m_code = code;
        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;

        if (0 > (size = stream.Getb()))
            return size;

        m_code = size;
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) 
    {
        int size;

        if (0 > (size = stream.Putb(m_code)))
            return size;

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int operator != (cSSLAlertDescription &description)
    {
        int unequal = m_code-description.m_code;
        return unequal;
    }
};

/**
 **********************************************************************
 *  Class: cSSLAlert
 *
 * Author: $author$
 *   Date: 1/15/2005
 **********************************************************************
 */
class cSSLAlert
{
public:
    cSSLAlertLevel m_level;
    cSSLAlertDescription m_description;

    /**
     **********************************************************************
     * Constructor: cSSLAlert
     *
     *      Author: $author$
     *        Date: 1/15/2005
     **********************************************************************
     */
    cSSLAlert
    (uint8 level=cSSLAlertLevel::e_NONE, 
     uint8 description=cSSLAlertDescription::e_NONE) 
    : m_level(level),
      m_description(description)
    {
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = m_level.Sizeof()+m_description.Sizeof();
        return size;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Copy(const cSSLAlert &alert)
    {
        int size;
        
        if (&alert == this)
            return size = Sizeof();

        size = Set
        (alert.m_level.m_code, 
         alert.m_description.m_code);
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Set(uint8 level, uint8 description)
    {
        int size = Sizeof();
        m_level.Set(level);
        m_description.Set(description);
        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;

        if (0 > (size = m_level.Read(stream)))
            return size;

        if (0 > (size = m_description.Read(stream)))
            return size;

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) 
    {
        int size;

        if (0 > (size = m_level.Write(stream)))
            return size;

        if (0 > (size = m_description.Write(stream)))
            return size;

        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 1/15/2005
     **********************************************************************
     */
    int operator != (const cSSLAlert &alert)
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CSSLALERT_HXX */
