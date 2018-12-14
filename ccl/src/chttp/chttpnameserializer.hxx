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
 *   File: chttpnameserializer.hxx
 *
 * Author: $author$
 *   Date: 2/20/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPNAMESERIALIZER_HXX
#define _CHTTPNAMESERIALIZER_HXX

#include "chttpserializer.hxx"

/**
 **********************************************************************
 *  Class: cHttpNameSerializer
 *
 * Author: $author$
 *   Date: 2/20/2006
 **********************************************************************
 */
class cHttpNameSerializer
: public cHttpSerializer
{
public:
    typedef cHttpSerializer cIs;

    const char* m_chars;
    int m_charslen, m_charspos;
    char m_endchar;

    /**
     **********************************************************************
     * Constructor: cHttpNameSerializer
     *
     *      Author: $author$
     *        Date: 2/20/2006
     **********************************************************************
     */
    cHttpNameSerializer() 
    : m_chars(""),
      m_charslen(0),
      m_charspos(1),
      m_endchar(' ')
    {
    }
    /**
     **********************************************************************
     * Function: Getb
     *
     *   Author: $author$
     *     Date: 2/8/2006
     **********************************************************************
     */
    virtual int Getb() 
    {
        int result = -e_ERROR_ENDOF;

        if (m_charspos > m_charslen)
            return result;

        else if (m_charspos < m_charslen)
                result = m_chars[m_charspos];

        else result = m_endchar;

        m_charspos++;
        return result;
    }
};

#endif /* _CHTTPNAMESERIALIZER_HXX */


