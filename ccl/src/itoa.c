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
 *   File: itoa.c
 *
 * Author: $author$
 *   Date: 11/25/2005
 *
 *    $Id$
 **********************************************************************
 */
#include "itoa.h"

#if !defined(WIN32)
/**
 **********************************************************************
 * Function: itoa
 *
 *   Author: $author$
 *     Date: 11/25/2005
 **********************************************************************
 */
char *itoa(int i, char *buff, int radix) 
{
    char *format;
 
    if (buff!=NULL)
    if ((format=(radix==10?"%d":radix==16?"%x":(char*)NULL))!=NULL)
       sprintf(buff, format, i);

    return buff;
}
#endif /* !defined(WIN32) */
