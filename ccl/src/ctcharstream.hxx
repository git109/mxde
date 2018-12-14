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
 *   File: ctcharstream.hxx
 *
 * Author: $author$
 *   Date: 11/25/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTCHARSTREAM_HXX
#define _CTCHARSTREAM_HXX

#include "ctcharstreamt.hxx"

/**
 **********************************************************************
 *  Class: cTCHARStream
 *
 * Author: $author$
 *   Date: 11/25/2003
 **********************************************************************
 */
class cTCHARStream
: public cTCHARStreamT<cStream>
{
public:
    typedef cTCHARStreamT<cStream> cIs;

    /**
     **********************************************************************
     * Constructor: cTCHARStream
     *
     *      Author: $author$
     *        Date: 11/25/2003
     **********************************************************************
     */
    cTCHARStream() 
    : cTCHARStreamT<cStream>() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cTCHARStream
     *
     *     Author: $author$
     *       Date: 11/25/2003
     **********************************************************************
     */
    virtual ~cTCHARStream()
    {
    }

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
};

#endif /* ndef _CTCHARSTREAM_HXX */
