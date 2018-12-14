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
 *   File: casn1objectidentifier.hxx
 *
 * Author: $author$
 *   Date: 1/29/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CASN1OBJECTIDENTIFIER_HXX
#define _CASN1OBJECTIDENTIFIER_HXX

#include "platform.h"
#include "cbytestream.hxx"
#include "cuint32buffer.hxx"

/**
 **********************************************************************
 *  Class: cASN1ObjectIdentifier
 *
 * Author: $author$
 *   Date: 1/29/2005
 **********************************************************************
 */
class cASN1ObjectIdentifier
{
public:
#include "casn1objectidentifiertable.hxx"

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/29/2005
     **********************************************************************
     */
    enum
    {
        e_SIZE = 16
    };

    static cASN1ObjectIdentifier m_table[e_ALL];

    const char *m_name;
    int m_type;
    uint32 m_value[e_SIZE];

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/29/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        uint32 value;
        int byte, length, size;
        cUint32Buffer buffer;
        const uint32 *find;
        const cASN1ObjectIdentifier *id;

        if (0 > (byte = stream.Getb()))
            return byte;

        size = 1;

        if (0 > (length = buffer.Put(byte/40)))
            return length;

        if (0 > (length = buffer.Put(byte%40)))
            return length;

        value = 0;

        while (0 <= (byte = stream.Getb()))
        {
            value <<= 7;
            value |= (byte & 127);

            if (byte < 128)
            {
                if (0 > (length = buffer.Put(value)))
                    return length;

                value = 0;
                size++;
            }
        }

        if (!(find = buffer.GetBuffer(length)))
            return -e_ERROR_FAILED;

        if (!(id = FindIdentifier(find, length)))
            id = m_table+e_undefined;

        m_name = id->m_name;
        m_type = id->m_type;
        memcpy(m_value, id->m_value, sizeof(m_value));
        return size;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/29/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) 
    {
        int length;
        return length;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 1/29/2005
     **********************************************************************
     */
    int Compare(const cASN1ObjectIdentifier &to_id) const
    {
        int unequal = memcmp
        (m_value, to_id.m_value, sizeof(m_value));
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 1/29/2005
     **********************************************************************
     */
    inline const char* GetName() const
    {
        return m_name;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 1/29/2005
     **********************************************************************
     */
    inline int GetType() const 
    {
        return m_type;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 1/29/2005
     **********************************************************************
     */
    inline const uint32 *GetValue() const 
    {
        return m_value;
    }

    /**
     **********************************************************************
     * Function: FindIdentifier
     *
     *   Author: $author$
     *     Date: 1/29/2005
     **********************************************************************
     */
    static const cASN1ObjectIdentifier* FindIdentifier
    (const uint32 value[], int size=-1) 
    {
        const cASN1ObjectIdentifier* found = 0;
        cASN1ObjectIdentifier find;
        int i;

        if (0 > size)
            for (size=0; value[size]; size++);

        if (e_SIZE < size)
            size = e_SIZE;

        for (i=0; i<size; i++)
            find.m_value[i] = value[i];

        for (; i<e_SIZE; i++)
            find.m_value[i] = 0;

        found = (cASN1ObjectIdentifier*)bsearch
        (&find, m_table, e_ALL, sizeof(cASN1ObjectIdentifier),
         (int(*)(const void *,const void*))CompareIdentifiers);

        return found;
    }
    /**
     **********************************************************************
     * Function: SortIdentifiers
     *
     *   Author: $author$
     *     Date: 1/29/2005
     **********************************************************************
     */
    static void SortIdentifiers() 
    {
        qsort
        (m_table, e_ALL, sizeof(cASN1ObjectIdentifier),
         (int(*)(const void *,const void*))CompareIdentifiers);
    }
    /**
     **********************************************************************
     * Function: CompareIdentifiers
     *
     *   Author: $author$
     *     Date: 1/29/2005
     **********************************************************************
     */
    static int CompareIdentifiers
    (const cASN1ObjectIdentifier *id,
     const cASN1ObjectIdentifier *to_id) 
    {
        int unequal = id->Compare(*to_id);
        return unequal;
    }
};

#endif /* _CASN1OBJECTIDENTIFIER_HXX */