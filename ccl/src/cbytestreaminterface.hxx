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
 *   File: cbytestreaminterface.hxx
 *
 * Author: $author$
 *   Date: 11/8/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTESTREAMINTERFACE_HXX
#define _CBYTESTREAMINTERFACE_HXX

#include "cstreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cBYTEStreamInterface
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEStreamInterface
: virtual public cStreamInterface
{
public:
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int Read
    (BYTE *buffer,  int size=-1) = 0;
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int Write
    (const BYTE *buffer,  int size=-1) = 0;

    /**
     **********************************************************************
     * Function: WaitWrite
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int WaitWrite
    (const BYTE *buffer, int size=-1, DWORD miliseconds=0) = 0;
    /**
     **********************************************************************
     * Function: WaitRead
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int WaitRead
    (BYTE *buffer, int size=-1, DWORD miliseconds=0) = 0;

    /**
     **********************************************************************
     * Function: Getb
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int Getb() = 0;
    /**
     **********************************************************************
     * Function: Putb
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int Putb(int b) = 0;
};

/**
 **********************************************************************
 *  Class: cBYTEStreamImplement
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
class cBYTEStreamImplement
: virtual public cBYTEStreamInterface
{
public:
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int Read
    (BYTE *buffer,  int size=-1) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int Write
    (const BYTE *buffer,  int size=-1) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: Getb
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int Getb() 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: Putb
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int Putb(int b) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
};

#endif /* ndef _CBYTESTREAMINTERFACE_HXX */
