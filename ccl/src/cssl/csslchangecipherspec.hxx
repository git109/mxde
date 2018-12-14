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
 *   File: csslchangecipherspec.hxx
 *
 * Author: $author$
 *   Date: 2/10/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLCHANGECIPHERSPEC_HXX
#define _CSSLCHANGECIPHERSPEC_HXX

#include "platform.h"
#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cSSLChangeCipherSpec
 *
 * Author: $author$
 *   Date: 2/10/2005
 **********************************************************************
 */
class cSSLChangeCipherSpec
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 2/10/2005
     **********************************************************************
     */
    enum
    {
        e_SPEC_ONE = 1,
    };

    BYTE m_spec;

    /**
     **********************************************************************
     * Constructor: cSSLChangeCipherSpec
     *
     *      Author: $author$
     *        Date: 2/10/2005
     **********************************************************************
     */
    cSSLChangeCipherSpec(BYTE spec=e_SPEC_ONE) 
    : m_spec(spec)
    {
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 2/10/2005
     **********************************************************************
     */
    int Copy(const cSSLChangeCipherSpec &spec)
    {
        int size;

        if (&spec == this)
            return size = sizeof(m_spec);

        size = Set(spec.m_spec);
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 2/10/2005
     **********************************************************************
     */
    int Set(BYTE spec)
    {
        int size = sizeof(m_spec);
        m_spec = spec;
        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/10/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size = stream.Get(m_spec);
        return size;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 2/10/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size = stream.Put(m_spec);
        return size;
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 2/10/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = sizeof(m_spec);
        return size;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 2/10/2005
     **********************************************************************
     */
    int operator != (const cSSLChangeCipherSpec &spec) const
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CSSLCHANGECIPHERSPEC_HXX */
