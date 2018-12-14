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
 *   File: csslsessionid.hxx
 *
 * Author: $author$
 *   Date: 1/13/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLSESSIONID_HXX
#define _CSSLSESSIONID_HXX

#include "platform.h"
#include "cbytestream.hxx"


/**
 **********************************************************************
 *  Class: cSSLSessionID
 *
 * Author: $author$
 *   Date: 1/13/2005
 **********************************************************************
 */
class cSSLSessionID
{
public:
    enum {e_SIZE = 256};

    uint8 m_sizeof;
    opaque m_id[e_SIZE];

    /**
     **********************************************************************
     * Constructor: cSSLSessionID
     *
     *      Author: $author$
     *        Date: 1/13/2005
     **********************************************************************
     */
    cSSLSessionID(const opaque *id=0, int size=-1) 
    {
        Set(id, size);
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/13/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = sizeof(m_sizeof)+m_sizeof;
        return size;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/13/2005
     **********************************************************************
     */
    int Copy(const cSSLSessionID &session)
    {
        int size;
        
        if (&session == this)
            return size = Sizeof();

        size = Set(session.m_id, session.m_sizeof);
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/13/2005
     **********************************************************************
     */
    int Set(const opaque *id=0, int size=-1)
    {
        m_sizeof = 0;

        if (id)
        {
            if (0 > size)
                size = strlen((const char*)id);

            if (size > sizeof(m_id))
                size = sizeof(m_id);

            memcpy(m_id, id, m_sizeof = (uint8)size);
        }
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/13/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size,size1;

        if (0 > (size = stream.Getb()))
            return size;

        if (size > sizeof(m_id))
            return -e_ERROR_RETURN_SIZE_OVER;

        if (0 <= (size = stream.Read(m_id, size1=size)))
        if (size != size1)
            return -e_ERROR_INVALID_RETURN_SIZE;
        else
        {  
            m_sizeof = (uint8)size;
            size = Sizeof();
        }

        return size;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/13/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size;

        if (0 > (size = stream.Putb(m_sizeof)))
            return size;

        if (0 <= (size = stream.Write(m_id, m_sizeof)))
        if (size != m_sizeof)
            return -e_ERROR_INVALID_RETURN_SIZE;
        else size = Sizeof();

        return size;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 1/13/2005
     **********************************************************************
     */
    int operator != (cSSLSessionID &session)
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CSSLSESSIONID_HXX */
