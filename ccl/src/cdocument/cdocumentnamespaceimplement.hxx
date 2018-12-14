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
 *   File: cdocumentnamespaceimplement.hxx
 *
 * Author: $author$
 *   Date: 10/31/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTNAMESPACEIMPLEMENT_HXX
#define _CDOCUMENTNAMESPACEIMPLEMENT_HXX

#include "cdocumentnamespaceinterface.hxx"
#include "cdocumentartifactimplement.hxx"

/**
 **********************************************************************
 *  Class: cDocumentNamespaceImplement
 *
 * Author: $author$
 *   Date: 10/10/2005
 **********************************************************************
 */
class cDocumentNamespaceImplement
: virtual public cDocumentNamespaceInterface
{
public:
    /**
     **********************************************************************
     * Function: SetNamespaceURIChars
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual int SetNamespaceURIChars
    (const char* chars, int length=-1)
    {
        return length;
    }
    /**
     **********************************************************************
     * Function: SetNamespaceURICChars
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual int SetNamespaceURICChars
    (const cChar* chars, int length=-1)
    {
        return length;
    }
    /**
     **********************************************************************
     * Function: GetNamespaceURICChars
     *
     *   Author: $author$
     *     Date: 10/10/2005
     **********************************************************************
     */
    virtual const cChar* GetNamespaceURICChars(int &length) const 
    {
        const cChar* chars = 0;
        return chars;
    }
};

#endif /* _CDOCUMENTNAMESPACEIMPLEMENT_HXX */
