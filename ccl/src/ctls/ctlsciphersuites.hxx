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
 *   File: ctlsciphersuites.hxx
 *
 * Author: $author$
 *   Date: 10/18/2007
 *
 **********************************************************************
 */

#ifndef _CTLSCIPHERSUITES_HXX
#define _CTLSCIPHERSUITES_HXX

#include "cbytestream.hxx"
/**
 **********************************************************************
 *  Class: cTLSCipherSuites
 *
 * Author: $author$
 *   Date: 10/18/2007
 **********************************************************************
 */
class cTLSCipherSuites
{
public:
    /**
     **********************************************************************
     * Constructor: cTLSCipherSuites
     *
     *      Author: $author$
     *        Date: 10/18/2007
     **********************************************************************
     */
    cTLSCipherSuites()
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 10/18/2007
     **********************************************************************
     */
    int Read(cBYTEStreamInterface &stream) 
    {
        int length = -e_ERROR_FAILED;
        return length;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 10/18/2007
     **********************************************************************
     */
    int Write(cBYTEStreamInterface &stream) 
    {
        int length = -e_ERROR_FAILED;
        return length;
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 10/18/2007
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = 0;
        return size;
    }
};

#endif /* _CTLSCIPHERSUITES_HXX */
