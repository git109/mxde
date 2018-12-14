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
 *   File: ckeyinterface.hxx
 *
 * Author: $author$
 *   Date: 1/7/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CKEYINTERFACE_HXX
#define _CKEYINTERFACE_HXX

#include "platform.h"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cKeyInterface
 *
 * Author: $author$
 *   Date: 1/7/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cKeyInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: GetKeyMin
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    virtual int GetKeyMin() const = 0;
    /**
     **********************************************************************
     * Function: GetKeyMax
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    virtual int GetKeyMax() const = 0;
};

/**
 **********************************************************************
 *  Class: cKeyImplement
 *
 * Author: $author$
 *   Date: 1/8/2005
 **********************************************************************
 */
class cKeyImplement
: virtual public cKeyInterface
{
public:
    /**
     **********************************************************************
     * Function: GetKeyMin
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual int GetKeyMin() const 
    {
        int length = 0;
        return length;
    }
    /**
     **********************************************************************
     * Function: GetKeyMax
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual int GetKeyMax() const 
    {
        int length = 0;
        return length;
    }
};

#endif /* _CKEYINTERFACE_HXX */