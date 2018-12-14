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
 *   File: cssltofrom.hxx
 *
 * Author: $author$
 *   Date: 1/21/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLTOFROM_HXX
#define _CSSLTOFROM_HXX

#include "platform.h"

/**
 **********************************************************************
 * Operator: toint
 *
 *   Author: $author$
 *     Date: 1/16/2005
 **********************************************************************
 */
inline int toint(const uint24 n24)
{
    int i,n;

    for (n=0,i=0; i<sizeof(uint24); i++)
        n = (n << 8) | n24[i];

    return n;
}

/**
 **********************************************************************
 * Operator: fromint
 *
 *   Author: $author$
 *     Date: 1/16/2005
 **********************************************************************
 */
inline uint24 &fromint(uint24 &n24, int n)
{
    int i,j;

    for (j=sizeof(uint24),i=0; i<sizeof(uint24); i++, n>>=8)
        n24[--j] = (n & 255);

    return n24;
}

#endif /* _CSSLTOFROM_HXX */