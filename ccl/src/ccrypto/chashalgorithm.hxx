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
 *   File: chashalgorithm.hxx
 *
 * Author: $author$
 *   Date: 2/7/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHASHALGORITHM_HXX
#define _CHASHALGORITHM_HXX

#include "platform.h"

/**
 **********************************************************************
 *  Class: cHashAlgorithm
 *
 * Author: $author$
 *   Date: 2/7/2005
 **********************************************************************
 */
class cHashAlgorithm
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 2/7/2005
     **********************************************************************
     */
    enum
    {
        e_NONE = -1,
        e_FIRST,

        e_MD5 = e_FIRST, 
        e_SHA1,

        e_ALL,
        e_LAST = e_ALL-1
    };
};

#endif /* _CHASHALGORITHM_HXX */