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
 *   File: chttpservletroute.hxx
 *
 * Author: $author$
 *   Date: 11/12/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPSERVLETROUTE_HXX
#define _CHTTPSERVLETROUTE_HXX

#include "chttpservlet.hxx"

class cHttpServletRoute;

/**
 **********************************************************************
 *  Class: cHttpServletRouteItem
 *
 * Author: $author$
 *   Date: 11/13/2004
 **********************************************************************
 */
class cHttpServletRouteItem
: public cListItemT<cHttpServletRouteItem>
{
public:
    typedef cListItemT<cHttpServletRouteItem> cIs;

    cHttpServletRoute &m_servlet;

    /**
     **********************************************************************
     * Constructor: cHttpServletRouteItem
     *
     *      Author: $author$
     *        Date: 11/13/2004
     **********************************************************************
     */
    cHttpServletRouteItem(cHttpServletRoute &servlet)
    : m_servlet(servlet) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttpServletRouteList
 *
 * Author: $author$
 *   Date: 11/13/2004
 **********************************************************************
 */
class cHttpServletRouteList
: public cStaticListT<cHttpServletRouteItem,cHttpServletRouteList>
{
public:
    typedef cStaticListT<cHttpServletRouteItem,cHttpServletRouteList> cIs;
};

/**
 **********************************************************************
 *  Class: cHttpServletRoute
 *
 * Author: $author$
 *   Date: 11/12/2004
 **********************************************************************
 */
class cHttpServletRoute
: public cHttpServlet
{
public:
    typedef cHttpServlet cIs;

    static cHttpServletRouteList m_list;
    cHttpServletRouteItem m_item;

    /**
     **********************************************************************
     * Constructor: cHttpServletRoute
     *
     *      Author: $author$
     *        Date: 11/12/2004
     **********************************************************************
     */
    cHttpServletRoute(const char *name) 
    : cIs(name),
      m_item(*this)
    {
        m_list.Add(&m_item);
    }
};

#endif /* ndef _CHTTPSERVLETROUTE_HXX */
