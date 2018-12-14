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
 *   File: csslserverhellodone.hxx
 *
 * Author: $author$
 *   Date: 1/21/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLSERVERHELLODONE_HXX
#define _CSSLSERVERHELLODONE_HXX

#include "platform.h"
#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cSSLServerHelloDone
 *
 * Author: $author$
 *   Date: 1/21/2005
 **********************************************************************
 */
class cSSLServerHelloDone
{
public:
    /**
     **********************************************************************
     * Constructor: cSSLServerHelloDone
     *
     *      Author: $author$
     *        Date: 1/21/2005
     **********************************************************************
     */
    cSSLServerHelloDone() 
    {
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
        int size = 0;
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
    int Copy(const cSSLServerHelloDone &hello_done)
    {
        int size = Sizeof();

        if (&hello_done == this)
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
        int size = Sizeof();
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
        int size = Sizeof();
        return size;
    }
};

#endif /* _CSSLSERVERHELLODONE_HXX */
