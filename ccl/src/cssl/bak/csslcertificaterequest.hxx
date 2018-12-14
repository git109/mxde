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
 *   File: csslcertificaterequest.hxx
 *
 * Author: $author$
 *   Date: 1/21/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLCERTIFICATEREQUEST_HXX
#define _CSSLCERTIFICATEREQUEST_HXX

#include "platform.h"
#include "cbytestream.hxx"


/**
 **********************************************************************
 *  Class: cSSLCertificateRequest
 *
 * Author: $author$
 *   Date: 1/21/2005
 **********************************************************************
 */
class cSSLCertificateRequest
{
public:
    /**
     **********************************************************************
     * Constructor: cSSLCertificateRequest
     *
     *      Author: $author$
     *        Date: 1/21/2005
     **********************************************************************
     */
    cSSLCertificateRequest() 
    {
        eError error;
        int size;

        if (0 > (size = Set()))
            throw(error = -size);
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size;
        return size;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Copy(const cSSLCertificateRequest &certificate_request)
    {
        int size = Sizeof();

        if (&certificate_request == this)
            return size = Sizeof();

        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Set()
    {
        int size = Sizeof();
        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;
        return size;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size;
        return size;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 1/21/2005
     **********************************************************************
     */
    int operator != (const cSSLCertificateRequest &certificate_request) const
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CSSLCERTIFICATEREQUEST_HXX */
