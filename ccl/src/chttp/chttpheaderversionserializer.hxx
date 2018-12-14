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
 *   File: chttpheaderversionserializer.hxx
 *
 * Author: $author$
 *   Date: 2/4/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPHEADERVERSIONSERIALIZER_HXX
#define _CHTTPHEADERVERSIONSERIALIZER_HXX

#include "chttpheaderintserializer.hxx"
#include "chttpnameserializer.hxx"
#include "chttpheaderversion.hxx"

/**
 **********************************************************************
 *  Class: cHttpHeaderVersionSerializer
 *
 * Author: $author$
 *   Date: 2/4/2006
 **********************************************************************
 */
class cHttpHeaderVersionSerializer
: public cHttpNameSerializer
{
public:
    typedef cHttpNameSerializer cIs;

    typedef int (cHttpHeaderVersionSerializer::*mGetb)();

    const cHttpHeaderVersion& m_version;

    cHttpHeaderIntSerializer 
        m_major_serializer, m_minor_serializer;

    mGetb m_getb;
    char m_prefix_separator;
    char m_separator;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderVersionSerializer
     *
     *      Author: $author$
     *        Date: 2/4/2006
     **********************************************************************
     */
    cHttpHeaderVersionSerializer
    (const cHttpHeaderVersion& version) 
    : m_version(version),
      m_major_serializer(version.m_major),
      m_minor_serializer(version.m_minor),
      m_getb(PrefixGetb),
      m_prefix_separator('/'),
      m_separator('.')
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_FAILED;

        if ((error = cIs::Initialize()))
            return error;

        if (!(m_chars = m_version.GetPrefix(m_charslen)))
            return e_ERROR_FAILED;

        m_charspos = 0;

        if ((error = m_major_serializer.Initialize()))
            return error;

        if ((error = m_minor_serializer.Initialize()))
            return error;

        m_separator = m_version.GetSeparator();
        m_prefix_separator = m_version.GetPrefixSeparator();
        m_getb = PrefixGetb;
        return error;
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
        int result = (this->*m_getb)();
        return result;
    }
    /**
     **********************************************************************
     * Function: PrefixGetb
     *
     *   Author: $author$
     *     Date: 2/8/2006
     **********************************************************************
     */
    int PrefixGetb() 
    {
        int result = 0;

        if (m_charspos < m_charslen)
            result = cIs::Getb();
        else
        {
            result = m_prefix_separator;
            m_getb = MajorGetb;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: MajorGetb
     *
     *   Author: $author$
     *     Date: 2/8/2006
     **********************************************************************
     */
    int MajorGetb() 
    {
        int result;

        if (0 > (result = m_major_serializer.Getb()))
        {
            result = m_separator;
            m_getb = MinorGetb;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: MinorGetb
     *
     *   Author: $author$
     *     Date: 2/8/2006
     **********************************************************************
     */
    int MinorGetb() 
    {
        int result = m_minor_serializer.Getb();
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderVersionDeserializer
 *
 * Author: $author$
 *   Date: 2/4/2006
 **********************************************************************
 */
class cHttpHeaderVersionDeserializer
: public cHttpDeserializer
{
public:
    typedef cHttpDeserializer cIs;
    typedef int (cHttpHeaderVersionDeserializer::*mPutb)(BYTE b);

    cHttpHeaderVersion& m_version;

    cHttpHeaderIntDeserializer 
        m_major_deserializer, m_minor_deserializer;

    mPutb m_putb;

    char m_endchar;
    char m_separator;
    char m_prefix_separator;
    const char* m_prefix;
    int m_prefix_length, m_prefix_index;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderVersionDeserializer
     *
     *      Author: $author$
     *        Date: 2/4/2006
     **********************************************************************
     */
    cHttpHeaderVersionDeserializer(cHttpHeaderVersion& version) 
    : m_version(version),
      m_major_deserializer(version.m_major),
      m_minor_deserializer(version.m_minor),
      m_putb(PrefixPutb),
      m_endchar('\n'),
      m_separator('.'),
      m_prefix_separator('/')
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_FAILED;

        if ((error = cIs::Initialize()))
            return error;

        m_separator = m_version.GetSeparator();
        m_prefix_separator = m_version.GetPrefixSeparator();

        if (!(m_prefix = m_version.GetPrefix(m_prefix_length)))
            return error;

        m_prefix_index = 0;

        if (!(error = m_major_deserializer.Initialize()))
        if (!(error = m_minor_deserializer.Initialize()))
            m_putb = PrefixPutb;

        return error;
    }

    /**
     **********************************************************************
     * Function: Putb
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual int Putb(BYTE b) 
    {
        int result = (this->*m_putb)(b);
        return result;
    }
    /**
     **********************************************************************
     * Function: PrefixPutb
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    int PrefixPutb(BYTE b) 
    {
        int result = b;

        if (m_prefix_index < m_prefix_length)
        {
            if (b != m_prefix[m_prefix_index++])
                return -e_ERROR_FAILED;
        }
        else if (b != m_prefix_separator)
                return -e_ERROR_FAILED;
        else m_putb = MajorPutb;

        return result;
    }
    /**
     **********************************************************************
     * Function: MajorPutb
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    int MajorPutb(BYTE b) 
    {
        int result = b;

        if (m_separator == b)
            m_putb = MinorPutb;

        else result = m_major_deserializer.Putb(b);
        return result;
    }
    /**
     **********************************************************************
     * Function: MinorPutb
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    int MinorPutb(BYTE b) 
    {
        int result = b;
        
        if (m_endchar == b)
            m_done = true;

        else result = m_minor_deserializer.Putb(b);
        return result;
    }
};

#endif /* _CHTTPHEADERVERSIONSERIALIZER_HXX */


