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
 *   File: chttpservletlist.hxx
 *
 * Author: $author$
 *   Date: 11/13/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPSERVLETLIST_HXX
#define _CHTTPSERVLETLIST_HXX

#include "chttpservletinterface.hxx"
#include "clistt.hxx"

/**
 **********************************************************************
 *  Class: cHttpServletItem
 *
 * Author: $author$
 *   Date: 11/13/2004
 **********************************************************************
 */
class cHttpServletItem
: public cListItemT<cHttpServletItem>
{
public:
    typedef cListItemT<cHttpServletItem> cIs;

    cHttpServletInterface *m_servlet;

    /**
     **********************************************************************
     * Constructor: cHttpServletItem
     *
     *      Author: $author$
     *        Date: 11/13/2004
     **********************************************************************
     */
    cHttpServletItem(cHttpServletInterface *servlet=0)
    : m_servlet(servlet) 
    {
    }
};

#endif /* ndef _CHTTPSERVLETLIST_HXX */
