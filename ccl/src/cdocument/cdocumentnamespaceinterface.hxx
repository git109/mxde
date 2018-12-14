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
 *   File: cdocumentnamespaceinterface.hxx
 *
 * Author: $author$
 *   Date: 10/29/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTNAMESPACEINTERFACE_HXX
#define _CDOCUMENTNAMESPACEINTERFACE_HXX

#include "cdocumentartifactinterface.hxx"
#include "curiinterface.hxx"

/**
 **********************************************************************
 *  Class: cDocumentNamespaceInterface
 *
 * Author: $author$
 *   Date: 10/10/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentNamespaceInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: GetGlobalNamespace
     *
     *   Author: $author$
     *     Date: 10/31/2005
     **********************************************************************
     */
    static cDocumentNamespaceInterface& GetGlobalNamespace();
    /**
     **********************************************************************
     * Function: SetNamespaceURIChars
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual int SetNamespaceURIChars
    (const char* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: SetNamespaceURICChars
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual int SetNamespaceURICChars
    (const cChar* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetNamespaceURICChars
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual const cChar* GetNamespaceURICChars(int &length) const = 0;
    /**
     **********************************************************************
     * Function: GetNamespaceURI
     *
     *   Author: $author$
     *     Date: 11/3/2005
     **********************************************************************
     */
    virtual const cURIInterface& GetNamespaceURI() const = 0;
};

#endif /* _CDOCUMENTNAMESPACEINTERFACE_HXX */
