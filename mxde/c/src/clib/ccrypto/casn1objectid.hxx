/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: casn1objectid.hxx
 *
 * Author: $author$
 *   Date: 3/24/2010
 **********************************************************************
 */
#ifndef _CASN1OBJECTID_HXX
#define _CASN1OBJECTID_HXX

#include "casn1base.hxx"
#include "casn1objectidtable.hxx"
#include "creader.hxx"

#define CASN1OBJECTID_VALUE_SIZE 16

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cASN1ObjectID
 *
 * Author: $author$
 *   Date: 3/24/2010
 **********************************************************************
 */
class c_ASN1_CLASS cASN1ObjectID
{
public:
    const CHAR* m_name;
    eASN1ObjectID m_type;
    UINT32 m_value[CASN1OBJECTID_VALUE_SIZE];

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 3/25/2010
     **********************************************************************
     */
    TLENGTH Read
    (cBYTEReaderInterface& reader) 
    {
        TLENGTH count = 0;
        TLENGTH count2;
        UINT32 value;
        TSIZE size;
        BYTE byte;

        if (0 > (count2 = reader.Read(&byte, 1)))
            return count2;

        count += count2;

        size = 0;
        m_value[size++] = byte/40;
        m_value[size++] = byte%40;

        for (value = 0; 
            (size < CASN1OBJECTID_VALUE_SIZE) 
             && (0 < (count2 = reader.Read(&byte, 1))); 
             count += count2)
        {
            value = (value << 7) | (byte & 127);

            if (128 > byte)
            {
                m_value[size++] = value;
                value = 0;
            }
        }

        while (size < CASN1OBJECTID_VALUE_SIZE)
            m_value[size++] = 0;

        return count;
    }

    /**
     **********************************************************************
     * Function: Name
     *
     *   Author: $author$
     *     Date: 3/24/2010
     **********************************************************************
     */
    const CHAR* Name() const 
    {
        return m_name;
    }
    /**
     **********************************************************************
     * Function: Type
     *
     *   Author: $author$
     *     Date: 3/24/2010
     **********************************************************************
     */
    eASN1ObjectID Type() const 
    {
        return m_type;
    }
    /**
     **********************************************************************
     * Function: Value
     *
     *   Author: $author$
     *     Date: 3/24/2010
     **********************************************************************
     */
    UINT32* Value() const 
    {
        return (UINT32*)(m_value);
    }
    /**
     **********************************************************************
     * Function: Value
     *
     *   Author: $author$
     *     Date: 3/24/2010
     **********************************************************************
     */
    UINT32* Value(TLENGTH& length) const 
    {
        UINT32* value;
        if ((value = Value()))
        for (length = 0; length < CASN1OBJECTID_VALUE_SIZE; length++)
        {
            if (!value[length])
                break;
        }
        return value;
    }

    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 3/24/2010
     **********************************************************************
     */
    static const cASN1ObjectID* Find
    (const UINT32 value[], TLENGTH length=UNDEFINED_LENGTH);
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CASN1OBJECTID_HXX */
