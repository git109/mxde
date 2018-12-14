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
 *   File: cchar.hxx
 *
 * Author: $author$
 *   Date: 11/27/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHAR_HXX
#define _CCHAR_HXX

#include "platform.h"

/**
 **********************************************************************
 *  Class: cChar
 *
 * Author: $author$
 *   Date: 11/27/2004
 **********************************************************************
 */
class cChar
{
public:
    WCHAR m_char;

    /**
     **********************************************************************
     * Constructor: cChar
     *
     *      Author: $author$
     *        Date: 11/27/2004
     **********************************************************************
     */
    cChar(WCHAR c=0) 
    : m_char(c) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cChar
     *
     *      Author: $author$
     *        Date: 11/27/2004
     **********************************************************************
     */
    cChar(char c) 
    : m_char(c) 
    {
    }
    /**
     **********************************************************************
     * Function: ToWCHAR
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    WCHAR ToWCHAR() const
    {
        WCHAR result = m_char;
        return result;
    }
    /**
     **********************************************************************
     * Function: ToTCHAR
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    TCHAR ToTCHAR() const
    {
        TCHAR result = (TCHAR)m_char;
        return result;
    }
    /**
     **********************************************************************
     * Function: ToChar
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    char ToChar() const
    {
        char result = (char)m_char;
        return result;
    }

    /**
     **********************************************************************
     * Operator: >
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    inline bool operator > (const cChar &c) const
    {
        return m_char > c.m_char;
    }
    /**
     **********************************************************************
     * Operator: <
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    inline bool operator < (const cChar &c) const
    {
        return m_char < c.m_char;
    }
    /**
     **********************************************************************
     * Operator: ==
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    inline bool operator == (const cChar &c) const
    {
        return m_char == c.m_char;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    inline bool operator != (const cChar &c) const
    {
        return m_char != c.m_char;
    }

    /**
     **********************************************************************
     * Operator: <
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    inline bool operator < (int c) const
    {
        return m_char < (WCHAR)c;
    }
    /**
     **********************************************************************
     * Operator: >
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    inline bool operator > (int c) const
    {
        return m_char > (WCHAR)c;
    }
    /**
     **********************************************************************
     * Operator: ==
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    inline bool operator == (int c) const
    {
        return m_char == (WCHAR)c;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    inline bool operator != (int c) const
    {
        return m_char != (WCHAR)c;
    }

    /**
     **********************************************************************
     * Operator: =
     *
     *   Author: $author$
     *     Date: 11/27/2004
     **********************************************************************
     */
    inline cChar& operator = (int c)
    {
        m_char = (WCHAR)c;
        return *this;
    }
};

#endif /* ndef _CCHAR_HXX */
