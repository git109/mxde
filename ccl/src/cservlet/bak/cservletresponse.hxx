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
 *   File: cservletresponse.hxx
 *
 * Author: $author$
 *   Date: 11/5/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSERVLETRESPONSE_HXX
#define _CSERVLETRESPONSE_HXX

#include "cservletinterface.hxx"
#include "cservletresponseinterface.hxx"
#include "ccontentresponseinterface.hxx"
#include "cconnectioninterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cServletResponseT
 *
 * Author: $author$
 *   Date: 11/5/2004
 **********************************************************************
 */
template 
<class TResponseInterfaceIs=cContentResponseInterface,
 class TServletResponseInterfaceIs=cServletResponseInterface,
 class TIs=cImplement>

class cServletResponseT
: virtual public TResponseInterfaceIs,
  virtual public TServletResponseInterfaceIs,
  public TIs
{
public:
    typedef TResponseInterfaceIs cResponseInterfaceIs;
    typedef TServletResponseInterfaceIs cServletResponseInterfaceIs;
    typedef TIs cIs;

    bool m_is_committed;

    /**
     **********************************************************************
     * Constructor: cServletResponseT
     *
     *      Author: $author$
     *        Date: 11/5/2004
     **********************************************************************
     */
    cServletResponseT() 
    : m_is_committed(false)
    {
    }
    /**
     **********************************************************************
     * Function: SetIsCommitted
     *
     *   Author: $author$
     *     Date: 11/5/2004
     **********************************************************************
     */
    virtual bool SetIsCommitted(bool is=true) 
    {
        m_is_committed = is;
        return m_is_committed;
    }
    /**
     **********************************************************************
     * Function: IsCommitted
     *
     *   Author: $author$
     *     Date: 11/5/2004
     **********************************************************************
     */
    virtual bool IsCommitted() const
    {
        return m_is_committed;
    }
};

/**
 **********************************************************************
 *  Class: cServletResponse
 *
 * Author: $author$
 *   Date: 11/5/2004
 **********************************************************************
 */
class cServletResponse
: public cServletResponseT<>
{
public:
    typedef cServletResponseT<> cIs;

    /**
     **********************************************************************
     * Constructor: cServletResponse
     *
     *      Author: $author$
     *        Date: 11/5/2004
     **********************************************************************
     */
    cServletResponse() 
    {
    }
};

#endif /* ndef _CSERVLETRESPONSE_HXX */
