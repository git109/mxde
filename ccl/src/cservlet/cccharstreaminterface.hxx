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
 *   File: cccharstreaminterface.hxx
 *
 * Author: $author$
 *   Date: 10/29/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CCCHARSTREAMINTERFACE_HXX
#define _CCCHARSTREAMINTERFACE_HXX

#include "cstreaminterface.hxx"
#include "cccharsinterface.hxx"

/**
 **********************************************************************
 *  Class: cCCharStreamInterface
 *
 * Author: $author$
 *   Date: 10/29/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cCCharStreamInterface
: virtual public cStreamInterface
{
public:
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int Get(cChar& c) = 0;
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    virtual int Read
    (cChar* chars, int size=-1) = 0;
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    virtual int Write
    (const cChar* chars, int length=-1) = 0;
};

/**
 **********************************************************************
 *  Class: cCCharStreamImplement
 *
 * Author: $author$
 *   Date: 10/29/2005
 **********************************************************************
 */
class cCCharStreamImplement
: virtual public cCCharStreamInterface
{
public:
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int Get(cChar& c)
    {
        int length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    virtual int Read
    (cChar* chars, int size=-1) 
    {
        int length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    virtual int Write
    (const cChar* chars, int length=-1) 
    {
        length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
};

#endif /* _CCCHARSTREAMINTERFACE_HXX */
