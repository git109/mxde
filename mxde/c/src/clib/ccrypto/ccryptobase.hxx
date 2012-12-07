/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: ccryptobase.hxx
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
#ifndef _CCRYPTOBASE_HXX
#define _CCRYPTOBASE_HXX

#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cCryptoBase
 *
 * Author: $author$
 *   Date: 5/1/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cCryptoBase
{
public:
    typedef cCryptoBase cDerives;

    /**
     **********************************************************************
     * Function: MSBToU64
     *
     *   Author: $author$
     *     Date: 11/21/2009
     **********************************************************************
     */
    inline UINT64 MSBToU64
    (const BYTE* bytes) 
    {
        UINT64 value = (((((((((((((((UINT64)bytes[0])<<8)|bytes[1])<<8)|bytes[2])<<8)|bytes[3])<<8)|bytes[4])<<8)|bytes[5])<<8)|bytes[6])<<8)|bytes[7];
        return value;
    }
    /**
     **********************************************************************
     * Function: U64ToMSB
     *
     *   Author: $author$
     *     Date: 11/21/2009
     **********************************************************************
     */
    inline BYTE* U64ToMSB
    (BYTE* bytes,
     UINT64 value) 
    {
        *(bytes+=7)=(BYTE)(value&255);
        *(--bytes)=(BYTE)((value>>=8)&255);
        *(--bytes)=(BYTE)((value>>=8)&255);
        *(--bytes)=(BYTE)((value>>=8)&255);
        *(--bytes)=(BYTE)((value>>=8)&255);
        *(--bytes)=(BYTE)((value>>=8)&255);
        *(--bytes)=(BYTE)((value>>=8)&255);
        *(--bytes)=(BYTE)((value>>=8)&255);
        return bytes;
    }

    /**
     **********************************************************************
     * Function: MSBToU32
     *
     *   Author: $author$
     *     Date: 5/1/2009
     **********************************************************************
     */
    inline UINT32 MSBToU32
    (const BYTE* bytes) 
    {
        UINT32 value = (((((((UINT32)bytes[0])<<8)|bytes[1])<<8)|bytes[2])<<8)|bytes[3];
        return value;
    }
    /**
     **********************************************************************
     * Function: U32ToMSB
     *
     *   Author: $author$
     *     Date: 5/1/2009
     **********************************************************************
     */
    inline BYTE* U32ToMSB
    (BYTE* bytes,
     UINT32 value) 
    {
        *(bytes+=3)=(BYTE)(value&255);
        *(--bytes)=(BYTE)((value>>=8)&255);
        *(--bytes)=(BYTE)((value>>=8)&255);
        *(--bytes)=(BYTE)((value>>=8)&255);
        return bytes;
    }

    /**
     **********************************************************************
     * Function: LSBToU32
     *
     *   Author: $author$
     *     Date: 5/1/2009
     **********************************************************************
     */
    inline UINT32 LSBToU32
    (const BYTE* bytes) 
    {
        UINT32 value = (((((((UINT32)bytes[3])<<8)|bytes[2])<<8)|bytes[1])<<8)|bytes[0];
        return value;
    }
    /**
     **********************************************************************
     * Function: U32ToLSB
     *
     *   Author: $author$
     *     Date: 5/1/2009
     **********************************************************************
     */
    inline BYTE* U32ToLSB
    (BYTE* bytes,
     UINT32 value) 
    {
        *(bytes)=(BYTE)(value&255);
        *(++bytes)=(BYTE)((value>>=8)&255);
        *(++bytes)=(BYTE)((value>>=8)&255);
        *(++bytes)=(BYTE)((value>>=8)&255);
        return bytes;
    }
};
#endif /* _CCRYPTOBASE_HXX */
