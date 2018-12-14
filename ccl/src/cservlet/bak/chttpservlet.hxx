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
 *   File: chttpservlet.hxx
 *
 * Author: $author$
 *   Date: 10/25/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPSERVLET_HXX
#define _CHTTPSERVLET_HXX

#include "cverboseinterface.hxx"
#include "chttpservletlist.hxx"
#include "chttpservlettree.hxx"
#include "chttpservletinterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cHttpServletT
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
template
<class THttpServletInterfaceIs=cHttpServletInterface,
 class THttpServletImplementIs=cHttpServletImplement,
 class TIs=cImplement>

class cHttpServletT
: virtual public THttpServletInterfaceIs,
  virtual public THttpServletImplementIs,
  public TIs
{
public:
    typedef TIs cIs;

    cVerboseInterface *m_verbose;
    cHttpServletItem m_item;
    cHttpServletBranch m_branch;

    /**
     **********************************************************************
     * Constructor: cHttpServletT
     *
     *      Author: $author$
     *        Date: 10/25/2004
     **********************************************************************
     */
    cHttpServletT
    (const char *name=0, int length=-1,
     cVerboseInterface *verbose=0)
    : m_verbose(verbose),
      m_branch(this, name, length),
      m_item(this)
    {
    }
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual cHttpServletBranch& GetBranch() 
    {
        cHttpServletBranch& branch = m_branch;
        return branch;
    }
    /**
     **********************************************************************
     * Function: SetServletName
     *
     *   Author: $author$
     *     Date: 12/10/2004
     **********************************************************************
     */
    virtual int SetServletName(const char* chars, int length=-1)
    {
        length = m_branch.SetName(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetServletName
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual const char* GetServletName(int &length) const
    {
        const char* chars = m_branch.GetName(length);
        return chars;
    }
};

/**
 **********************************************************************
 *  Class: cHttpServlet
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
class cHttpServlet
: public cHttpServletT<>
{
public:
    typedef cHttpServletT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpServlet
     *
     *      Author: $author$
     *        Date: 10/25/2004
     **********************************************************************
     */
    cHttpServlet
    (const char *name=0, int length=-1,
     cVerboseInterface *verbose=0)
    : cIs(name, length, verbose)
    {
    }
};

#endif /* ndef _CHTTPSERVLET_HXX */
