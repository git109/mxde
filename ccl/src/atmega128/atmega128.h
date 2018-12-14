/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: atmega128.h
 *
 * Author: $author$
 *   Date: 10/26/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef ATMEGA128_H
#define ATMEGA128_H

/**
 **********************************************************************
 *   Enum: ATMEGA128_MCUCR_BM
 *
 * Author: $author$
 *   Date: 10/26/2005
 **********************************************************************
 */
enum ATMEGA128_MCUCR_BM
{
    ATMEGA128_MCUCR_BM_SRE   = 0x80, 
    ATMEGA128_MCUCR_BM_SRW10 = 0x40
};
/**
 **********************************************************************
 *   Enum: ATMEGA128_MCUCR_BS
 *
 * Author: $author$
 *   Date: 10/26/2005
 **********************************************************************
 */
enum ATMEGA128_MCUCR_BS
{
    ATMEGA128_MCUCR_BS_SRE   = 7, 
    ATMEGA128_MCUCR_BS_SRW10 = 6
};

/**
 **********************************************************************
 *   Enum: ATMEGA128_XMCRA_BM
 *
 * Author: $author$
 *   Date: 10/26/2005
 **********************************************************************
 */
enum ATMEGA128_XMCRA_BM
{
    ATMEGA128_XMCRA_BM_SRL   = 0x70, 
    ATMEGA128_XMCRA_BM_SRW01 = 0x08, 
    ATMEGA128_XMCRA_BM_SRW00 = 0x04, 
    ATMEGA128_XMCRA_BM_SRW11 = 0x02
};
/**
 **********************************************************************
 *   Enum: ATMEGA128_XMCRA_BS
 *
 * Author: $author$
 *   Date: 10/26/2005
 **********************************************************************
 */
enum ATMEGA128_XMCRA_BS
{
    ATMEGA128_XMCRA_BS_SRL   = 4, 
    ATMEGA128_XMCRA_BS_SRW01 = 3, 
    ATMEGA128_XMCRA_BS_SRW00 = 2, 
    ATMEGA128_XMCRA_BS_SRW11 = 1
};

/**
 **********************************************************************
 *   Enum: ATMEGA128_XMCRA_SRL_BV
 *
 * Author: $author$
 *   Date: 10/26/2005
 **********************************************************************
 */
enum ATMEGA128_XMCRA_SRL_BV
{
    ATMEGA128_XMCRA_SRL_BV_1100 = 0, 
    ATMEGA128_XMCRA_SRL_BV_2000 = 1, 
    ATMEGA128_XMCRA_SRL_BV_4000 = 2, 
    ATMEGA128_XMCRA_SRL_BV_6000 = 3, 
    ATMEGA128_XMCRA_SRL_BV_8000 = 4, 
    ATMEGA128_XMCRA_SRL_BV_A000 = 5, 
    ATMEGA128_XMCRA_SRL_BV_C000 = 6, 
    ATMEGA128_XMCRA_SRL_BV_E000 = 7
};

/**
 **********************************************************************
 *   Enum: ATMEGA128_XMCRB_BM
 *
 * Author: $author$
 *   Date: 10/26/2005
 **********************************************************************
 */
enum ATMEGA128_XMCRB_BM
{
    ATMEGA128_XMCRB_BM_XMBK = 0x80, 
    ATMEGA128_XMCRB_BM_XMM  = 0x07
};
/**
 **********************************************************************
 *   Enum: ATMEGA128_XMCRB_BS
 *
 * Author: $author$
 *   Date: 10/26/2005
 **********************************************************************
 */
enum ATMEGA128_XMCRB_BS
{
    ATMEGA128_XMCRB_BS_XMBK = 7, 
    ATMEGA128_XMCRB_BS_XMM =  0
};

/**
 **********************************************************************
 *   Enum: ATMEGA128_TWCR_BM
 *
 * Author: $author$
 *   Date: 10/26/2005
 **********************************************************************
 */
enum ATMEGA128_TWCR_BM
{
    ATMEGA128_TWCR_BM_TWEN = 0x04
};
/**
 **********************************************************************
 *   Enum: ATMEGA128_TWCR_BS
 *
 * Author: $author$
 *   Date: 10/26/2005
 **********************************************************************
 */
enum ATMEGA128_TWCR_BS
{
    ATMEGA128_TWCR_BS_TWEN = 2
};

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif /* ATMEGA128_H */
