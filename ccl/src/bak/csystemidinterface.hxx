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
 *   File: csystemidinterface.hxx
 *
 * Author: $author$
 *   Date: 11/15/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSYSTEMIDINTERFACE_HXX
#define _CSYSTEMIDINTERFACE_HXX

#if defined(WIN32)
#include <windows.h>
#define INVALID_PSID NULL
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

#include "cattachinterface.hxx"
#include "ccreateinterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cSystemIdInterface
 *
 * Author: $author$
 *   Date: 11/15/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cSystemIdInterface
: virtual public cAttachInterface,
  virtual public cCreateInterface
{
public:
    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 11/15/2003
     **********************************************************************
     */
    virtual eError Attach(PSID handle) = 0;
    /**
     **********************************************************************
     * Function: GetHandle
     *
     *   Author: $author$
     *     Date: 11/15/2003
     **********************************************************************
     */
    virtual PSID GetHandle() const = 0;
};

/**
 **********************************************************************
 *  Class: cSystemIdImplement
 *
 * Author: $author$
 *   Date: 11/16/2003
 **********************************************************************
 */
class cSystemIdImplement
: virtual public cSystemIdInterface,
  public cImplement
{
public:
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 11/16/2003
     **********************************************************************
     */
};

#endif
