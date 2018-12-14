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
 *   File: cxtltodocumenttokeninterface.hxx
 *
 * Author: $author$
 *   Date: 11/19/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CXTLTODOCUMENTTOKENINTERFACE_HXX
#define _CXTLTODOCUMENTTOKENINTERFACE_HXX

#include "cccharbuffer.hxx"

class cXTLToDocumentTokenBranch;

/**
 **********************************************************************
 *  Class: cXTLToDocumentTokenInterface
 *
 * Author: $author$
 *   Date: 11/19/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cXTLToDocumentTokenInterface
{
public:
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual const cCCharBuffer& GetName() const = 0;
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual int GetType() const = 0;
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual cXTLToDocumentTokenBranch& GetBranch() = 0;
};

#endif /* _CXTLTODOCUMENTTOKENINTERFACE_HXX */
