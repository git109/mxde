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
 *   File: casn1typeof.hxx
 *
 * Author: $author$
 *   Date: 1/26/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CASN1TYPEOF_HXX
#define _CASN1TYPEOF_HXX

#include "platform.h"
#include "cbytestream.hxx"
#include "casn1classof.hxx"
#include "casn1formof.hxx"


/**
 **********************************************************************
 *  Class: cASN1Typeof
 *
 * Author: $author$
 *   Date: 1/26/2005
 **********************************************************************
 */
class cASN1Typeof
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/26/2005
     **********************************************************************
     */
    enum
    {
        e_Any             = 0 ,
        e_Boolean         = 1,
        e_Integer         = 2,
        e_BitString       = 3,
        e_OctetString     = 4,
        e_Null            = 5,
        e_ObjectID        = 6,
        e_Object          = 7,
        e_External        = 8,
        e_Real            = 9,
        e_Enum            = 10,
        e_Sequence        = 16,
        e_Set             = 17,
        e_NumericString   = 18,
        e_PrintableString = 19,
        e_TeletexString   = 20,
        e_VideotexString  = 21,
        e_IA5String       = 22,
        e_UTCTime         = 23,
        e_GeneralizedTime = 24,
        e_GraphicString   = 25,
        e_VisibleString   = 26,
        e_GeneralString   = 27
    };

    cASN1Classof m_classof;
    cASN1Formof m_formof;
    unsigned m_value;
    int m_sizeof;
    const char *m_name;

    /**
     **********************************************************************
     * Constructor: cASN1Typeof
     *
     *      Author: $author$
     *        Date: 1/26/2005
     **********************************************************************
     */
    cASN1Typeof
    (unsigned value=e_Any, 
     unsigned formof=cASN1Formof::e_Primative,
     unsigned classof=cASN1Classof::e_Universal) 
    {
        eError error;
        int size;

        if (0 > (size = Set(value, formof, classof)))
            throw(error = -size);
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    int Copy(const cASN1Typeof &typeof)
    {
        int size;

        if (&typeof == this)
            return size = Sizeof();

        size = Set
        (typeof.GetValue(), 
         typeof.GetFormof(), 
         typeof.GetClassof());
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    int Set
    (unsigned value=e_Any, 
     unsigned formof=cASN1Formof::e_Primative,
     unsigned classof=cASN1Classof::e_Universal)
    {
        unsigned native;

        m_sizeof = 1;

        if ((m_value = value) > 31)
        {
            for (native=value; native!=0; native>>=7)
                m_sizeof++;
        }

        m_classof.SetValue(classof);
        m_formof.SetValue(formof);
        m_name = GetName();
        return m_sizeof;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;

        m_sizeof = 0;

        if (0 <= (size = stream.Getb()))
        {
            m_sizeof = 1;
            m_formof.SetValue(size & cASN1Formof::e_Mask);
            m_classof.SetValue(size & cASN1Classof::e_Mask);

            if ((m_value = (size & 31)) != 31)
            {
                m_name = GetName();
                return m_sizeof;
            }

            m_value = 0;

            while (0 <= (size = stream.Getb()))
            {
                m_sizeof++;
                m_value = (m_value << 7) | (size & 127);

                if (size < 128)
                {
                    m_name = GetName();
                    return m_sizeof;
                }
            }
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int bytes, count, size;
        unsigned native, msb;
        BYTE byte;

        bytes = 0;

        if (m_value < 31)
            byte = (BYTE)m_value;
        else 
        {
            byte = 31;

            for (msb=0, native=m_value; 
                 native!=0; native>>=7, bytes++)
            {
                msb <<= 7;
                msb |= (native & 127);
            }
        }

        byte |= m_formof.GetValue();
        byte |= m_classof.GetValue();

        if (0 > (count = stream.Putb(byte)))
            return count;

        for (size=1; bytes>0; msb>>=7, size++, bytes--)
        {
            byte = (BYTE)(msb & 127);

            if (bytes > 0)
                byte |= 128;

            if (0 > (count = stream.Putb(byte)))
                return count;
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        return m_sizeof;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    const char *GetName() const 
    {
        static const char *name0[]
        ={
            "Any",
            "Boolean",
            "Integer",
            "BitString",
            "OctetString",
            "Null",
            "ObjectID",
            "Object",
            "External",
            "Real",
            "Enum",
         };
        static const char *name1[]
        ={
            "Sequence",
            "Set",
            "NumericString",
            "PrintableString",
            "TeletexString",
            "VideotexString",
            "IA5String",
            "UTCTime",
            "GeneralizedTime",
            "GraphicString",
            "VisibleString",
            "GeneralString",
         };

        if ((m_value >= e_Any) && (m_value <= e_Enum))
            return name0[m_value-e_Any];

        if ((m_value >= e_Sequence) && (m_value <= e_GeneralString))
            return name1[m_value-e_Sequence];

        return "Undefined";
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
     * Function: GetFormof
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    inline unsigned GetFormof() const 
    {
        unsigned value = m_formof.GetValue();
        return value;
    }
    /**
     **********************************************************************
     * Function: GetClassof
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    inline unsigned GetClassof() const 
    {
        unsigned value = m_classof.GetValue();
        return value;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    int operator != (const cASN1Typeof &typeof) const
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CASN1TYPEOF_HXX */
