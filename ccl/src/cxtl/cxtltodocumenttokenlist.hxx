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
 *   File: cxtltodocumenttokenlist.hxx
 *
 * Author: $author$
 *   Date: 11/19/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CXTLTODOCUMENTTOKENLIST_HXX
#define _CXTLTODOCUMENTTOKENLIST_HXX

#include "cxtltodocumenttokeninterface.hxx"
#include "clistt.hxx"

/**
 **********************************************************************
 *  Class: cXTLToDocumentTokenItem
 *
 * Author: $author$
 *   Date: 11/19/2005
 **********************************************************************
 */
class cXTLToDocumentTokenItem
: public cListItemT<cXTLToDocumentTokenItem>
{
public:
    typedef cListItemT<cXTLToDocumentTokenItem> cIs;

    cXTLToDocumentTokenInterface& m_token;

    /**
     **********************************************************************
     * Constructor: cXTLToDocumentTokenItem
     *
     *      Author: $author$
     *        Date: 11/19/2005
     **********************************************************************
     */
    cXTLToDocumentTokenItem(cXTLToDocumentTokenInterface& token) 
    : m_token(token) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXTLToDocumentTokenList
 *
 * Author: $author$
 *   Date: 11/19/2005
 **********************************************************************
 */
class cXTLToDocumentTokenList
: public cStaticListT
  <cXTLToDocumentTokenItem, cXTLToDocumentTokenList>
{
public:
    typedef cStaticListT
    <cXTLToDocumentTokenItem, cXTLToDocumentTokenList> cIs;

    static cXTLToDocumentTokenList m_instance;
};

#endif /* _CXTLTODOCUMENTTOKENLIST_HXX */