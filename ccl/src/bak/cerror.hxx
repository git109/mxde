/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: cerror.hxx
 *
 * Author: $author$
 *   Date: 3/13/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CERROR_HXX
#define _CERROR_HXX

#include "cerrort.hxx"

/**
 **********************************************************************
 *  Class: cError
 *
 * Author: $author$
 *   Date: 3/13/2004
 **********************************************************************
 */
class cError
: public cErrorT<>
{
public:
    typedef cErrorT<> cIs;

    /**
     **********************************************************************
     * Constructor: cError
     *
     *      Author: $author$
     *        Date: 3/13/2004
     **********************************************************************
     */
    cError(eError error=e_ERROR_NONE, const char *description=0)
    : cIs(error, description) 
    {
    }
};

#endif /* ndef _CERROR_HXX */
