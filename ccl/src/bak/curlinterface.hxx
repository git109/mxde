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
 *   File: curlinterface.hxx
 *
 * Author: $author$
 *   Date: 6/8/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CURLINTERFACE_HXX
#define _CURLINTERFACE_HXX

#include "curcinterface.hxx"
#include "ccharstream.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cURLInterface
 *
 * Author: $author$
 *   Date: 6/8/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cURLInterface
: virtual public cURCInterface
{
public:
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 6/10/2004
     **********************************************************************
     */
    virtual eError Open() = 0;
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 6/10/2004
     **********************************************************************
     */
    virtual eError Close() = 0;
};

/**
 **********************************************************************
 *  Class: cURLImplement
 *
 * Author: $author$
 *   Date: 6/8/2004
 **********************************************************************
 */
class cURLImplement
: virtual public cURLInterface,
  virtual public cURCImplement
{
public:
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 6/10/2004
     **********************************************************************
     */
    virtual eError Open()
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 6/10/2004
     **********************************************************************
     */
    virtual eError Close()
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
};

#endif /* ndef _CURLINTERFACE_HXX */
