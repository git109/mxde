/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: chex.h
 *
 * Author: $author$
 *   Date: 8/9/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHEX_H
#define _CHEX_H

#define chex_ishex(x) \
    (((x) >= '0' && (x) <= '9') \
    || ((x) >= 'a' && (x) <= 'f') \
    || ((x) >= 'A' && (x) <= 'F'))

#define chex_ctohex(x) \
    (((x) >= '0' && (x) <= '9')?((x)-'0') \
    :(((x) >= 'a' && (x) <= 'f')?((x)-'a'+10) \
    :((x)-'A'+10)))

#define chex_hextoc(x) \
    (((x) >= 0 && (x) <= 9)?((x)+'0') \
    :(((x) >= 10 && (x) <= 15)?((x)+'a'-10) \
    :'.'))

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif