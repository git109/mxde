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
 *   File: ccrypto.hxx
 *
 * Author: $author$
 *   Date: 1/9/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCRYPTO_HXX
#define _CCRYPTO_HXX

#include "platform.h"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cCrypto
 *
 * Author: $author$
 *   Date: 1/9/2005
 **********************************************************************
 */
class cCrypto
: public cInstance
{
public:
    typedef cInstance cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 10/19/2007
     **********************************************************************
     */
    enum
    {
        e_FIRST_ERROR = ::e_FIRST_ERROR,

        e_ERROR_KEY_SIZE = e_FIRST_ERROR,
        e_ERROR_KEY_SIZE_UNDER,
        e_ERROR_KEY_SIZE_OVER,

        e_ERROR_IV_SIZE,
        e_ERROR_IV_SIZE_UNDER,
        e_ERROR_IV_SIZE_OVER,

        e_ERROR_BLOCK_SIZE,
        e_ERROR_BLOCK_SIZE_UNDER,
        e_ERROR_BLOCK_SIZE_OVER,

        e_NEXT_ERROR,
        e_LAST_ERROR = e_NEXT_ERROR-1,

        e_ERRORS = e_LAST_ERROR-e_FIRST_ERROR+1
    };

    /**
     **********************************************************************
     * Function: LSBToU32
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    static inline uint32 LSBToU32(const BYTE *buff)
	{
		return (((((((uint32)buff[3])<<8)|buff[2])<<8)|buff[1])<<8)|buff[0];
	}
    /**
     **********************************************************************
     * Function: U32ToLSB
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    static inline BYTE *U32ToLSB(BYTE *buff, uint32 value)
    {
        *(buff)=(BYTE)(value&255);
        *(++buff)=(BYTE)((value>>=8)&255);
        *(++buff)=(BYTE)((value>>=8)&255);
        *(++buff)=(BYTE)((value>>=8)&255);
        return buff;
    }
    /**
     **********************************************************************
     * Function: MSBToU32
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    static inline uint32 MSBToU32(const BYTE *buff)
    {
        return (((((((uint32)buff[0])<<8)|buff[1])<<8)|buff[2])<<8)|buff[3];
    }
    /**
     **********************************************************************
     * Function: U32ToMSB
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    static inline BYTE *U32ToMSB(BYTE *buff, uint32 value)
    {
        *(buff+=3)=(BYTE)(value&255);
        *(--buff)=(BYTE)((value>>=8)&255);
        *(--buff)=(BYTE)((value>>=8)&255);
        *(--buff)=(BYTE)((value>>=8)&255);
        return buff;
    }
    /**
     **********************************************************************
     * Function: Copy8
     *
     *   Author: $author$
     *     Date: 1/9/2005
     **********************************************************************
     */
    static inline BYTE *Copy8(BYTE *to, const BYTE *from)
    {
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        return to;
    }
    /**
     **********************************************************************
     * Function: CopyRepeat
     *
     *   Author: $author$
     *     Date: 1/10/2005
     **********************************************************************
     */
    static inline BYTE *CopyRepeat
    (BYTE *to, int tosize, 
     const BYTE *from, int fromsize)
    {
        for (int i=0; i<tosize; i+=fromsize)
        for (int j=0,k=i; (k<tosize) && (j<fromsize); k++,j++)
            to[k] = from[j];
        return to;
    }
};

#endif /* _CCRYPTO_HXX */