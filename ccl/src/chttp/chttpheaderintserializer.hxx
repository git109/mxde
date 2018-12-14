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
 *   File: chttpheaderintserializer.hxx
 *
 * Author: $author$
 *   Date: 2/4/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPHEADERINTSERIALIZER_HXX
#define _CHTTPHEADERINTSERIALIZER_HXX

#include "coutputstreaminterface.hxx"
#include "cinputstreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cHttpHeaderIntSerializer
 *
 * Author: $author$
 *   Date: 10/27/2004
 **********************************************************************
 */
class cHttpHeaderIntSerializer
: public cHttpSerializer
{
public:
    typedef cHttpSerializer cIs;

    const int &m_value;
    int m_serialized_value;
    int m_serialized_digits;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderIntSerializer
     *
     *      Author: $author$
     *        Date: 10/27/2004
     **********************************************************************
     */
    cHttpHeaderIntSerializer(const int &value) 
    : m_value(value),
      m_serialized_value(0),
      m_serialized_digits(0)
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
        eError error = e_ERROR_NONE;
        int value = m_value;

        for (m_serialized_digits=0, m_serialized_value=0; 
             value>0; value/=10, m_serialized_digits++)
            m_serialized_value = (m_serialized_value * 10) + (value % 10);

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
        int result = -e_ERROR_ENDOF;

        if (m_serialized_digits)
        {
            result = '0' + (m_serialized_value % 10);
            m_serialized_value /= 10;
            m_serialized_digits--;
        }
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderIntDeserializer
 *
 * Author: $author$
 *   Date: 2/4/2006
 **********************************************************************
 */
class cHttpHeaderIntDeserializer
: public cHttpDeserializer
{
public:
    typedef cHttpDeserializer cIs;

    int &m_value;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderIntDeserializer
     *
     *      Author: $author$
     *        Date: 2/4/2006
     **********************************************************************
     */
    cHttpHeaderIntDeserializer(int &value) 
    : m_value(value) 
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
        eError error = e_ERROR_NONE;
        m_value = 0;
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
        int result = b;

        if ((b >= '0') && (b <= '9'))
            m_value = m_value*10+(b-'0');
        return result;
    }
};

#endif /* _CHTTPHEADERINTSERIALIZER_HXX */
