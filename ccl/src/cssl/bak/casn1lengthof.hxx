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
 *   File: casn1lengthof.hxx
 *
 * Author: $author$
 *   Date: 1/27/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CASN1LENGTHOF_HXX
#define _CASN1LENGTHOF_HXX

#include "platform.h"
#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cASN1Lengthof
 *
 * Author: $author$
 *   Date: 1/27/2005
 **********************************************************************
 */
class cASN1Lengthof
{
public:
    bool m_is_indefinite;
    unsigned m_value;
    int m_sizeof;

    /**
     **********************************************************************
     * Constructor: cASN1Lengthof
     *
     *      Author: $author$
     *        Date: 1/27/2005
     **********************************************************************
     */
    cASN1Lengthof(unsigned value=0, bool is_indefinite=false) 
    {
        eError error;
        int size;

        if (0 > (size = Set(value, is_indefinite)))
            throw(error = -size);
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    int Copy(const cASN1Lengthof &lengthof)
    {
        int size;

        if (&lengthof == this)
            return size = Sizeof();

        size = Set
        (lengthof.GetValue(), 
         lengthof.GetIsIndefinite());
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    int Set(unsigned value=0, bool is_indefinite=false)
    {
        unsigned native, mask;

        m_value = value;
        m_is_indefinite = is_indefinite;
        m_sizeof = 1;
        mask = -1;
        native = value;

        for (mask<<=7, native&=mask; native>0; native>>=8)
            m_sizeof++;

        return m_sizeof;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int value, size;

        if (0 > (value = stream.Getb()))
            return value;

        m_sizeof = 1;
        m_is_indefinite = false;

        if (value < 128)
            m_value = value;

        else
        {
            m_value = 0;

            if (value > 128)
            {
                for (size=(value & 127); 
                     size>0; size--,m_sizeof++)
                {
                    if  (0 > (value = stream.Getb()))
                        return value;

                    m_value = (m_value << 8) | value;
                }
            }
            else m_is_indefinite = true;
        }
        return m_sizeof;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int value;
        unsigned native, msb;
        BYTE byte, size;

        size = 0;

        if (m_is_indefinite)
            byte = 128;

        else if (m_value < 128)
                byte = (BYTE)m_value;

        else 
        {
            for (native=m_value, msb=0; 
                 native>0; native>>=8, size++)
            {
                msb <<= 8;
                msb |= (native & 255);
            }
            byte = size | 128;
        }

        if (0 > (value = stream.Putb(byte)))
            return value;

        for (; size>0; msb>>=8,size--)
        {
            byte = (BYTE)msb;

            if (0 > (value = stream.Putb(byte)))
                return value;
        }
        return m_sizeof;
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        return m_sizeof;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    inline unsigned GetValue() const 
    {
        return m_value;
    }
    /**
     **********************************************************************
     * Function: GetIsIndefinite
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    inline bool GetIsIndefinite() const 
    {
        return m_is_indefinite;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    int operator != (const cASN1Lengthof &lengthof) const
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CASN1LENGTHOF_HXX */
