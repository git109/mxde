/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: chttpheaderversion.hxx
 *
 * Author: $author$
 *   Date: 2/4/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPHEADERVERSION_HXX
#define _CHTTPHEADERVERSION_HXX

#include <string.h>

/**
 **********************************************************************
 *  Class: cHttpHeaderVersion
 *
 * Author: $author$
 *   Date: 2/4/2006
 **********************************************************************
 */
class cHttpHeaderVersion
{
public:
    enum
    {
        e_DEFAULT_MAJOR = 1,
        e_DEFAULT_MINOR = 1
    };

    int m_major, m_minor;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderVersion
     *
     *      Author: $author$
     *        Date: 2/4/2006
     **********************************************************************
     */
    cHttpHeaderVersion
    (int major=e_DEFAULT_MAJOR,  int minor=e_DEFAULT_MINOR) 
    : m_major(major),
      m_minor(minor) 
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 3/1/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        m_major = e_DEFAULT_MAJOR;
        m_minor = e_DEFAULT_MINOR;
        return error;
    }

    /**
     **********************************************************************
     * Function: GetPrefix
     *
     *   Author: $author$
     *     Date: 10/23/2004
     **********************************************************************
     */
    virtual const char* GetPrefix(int &len) const
    {
        static const char* prefix = "HTTP";
        len = strlen(prefix);
        return prefix;
    }
    /**
     **********************************************************************
     * Function: GetPrefixSeparator
     *
     *   Author: $author$
     *     Date: 10/23/2004
     **********************************************************************
     */
    virtual char GetPrefixSeparator() const
    {
        return '/';
    }
    /**
     **********************************************************************
     * Function: GetSeparator
     *
     *   Author: $author$
     *     Date: 10/23/2004
     **********************************************************************
     */
    virtual char GetSeparator() const
    {
        return '.';
    }

};

#endif /* _CHTTPHEADERVERSION_HXX */
