/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cssl2message.hxx
 *
 * Author: $author$
 *   Date: 10/17/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CSSL2MESSAGE_HXX
#define _CSSL2MESSAGE_HXX

#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cSSL2Message
 *
 * Author: $author$
 *   Date: 10/17/2007
 **********************************************************************
 */
class cSSL2Message
{
public:
    typedef cSSL2Message cDerives;

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 10/17/2007
     **********************************************************************
     */
    enum
    {
        e_FIRST_TYPE,

        e_TYPE_CLIENT_HELLO = 1,
        e_TYPE_CLIENT_MASTER_KEY = 2,
        e_TYPE_CLIENT_FINISHED = 3,

        e_TYPE_SERVER_HELLO = 4,
        e_TYPE_SERVER_VERIFY = 5,
        e_TYPE_SERVER_FINISHED = 6,

        e_TYPE_REQUEST_CERTIFICATE = 7,
        e_TYPE_CLIENT_CERTIFICATE = 8,

        e_NEXT_TYPE,
        e_LAST_TYPE = e_NEXT_TYPE-1
    };

    uint8 m_type;

    /**
     **********************************************************************
     * Constructor: cSSL2Message
     *
     *      Author: $author$
     *        Date: 10/17/2007
     **********************************************************************
     */
    cSSL2Message() 
    {
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 10/17/2007
     **********************************************************************
     */
    int Read(cBYTEStreamInterface &stream) 
    {
        int count, length;

        if (1 <= (count = stream.Read(&m_type, 1)))
        switch(m_type)
        {
        case e_TYPE_CLIENT_HELLO:
            break;
        }
        return count;
    }
};

#endif /* _CSSL2MESSAGE_HXX */
