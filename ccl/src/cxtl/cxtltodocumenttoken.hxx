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
 *   File: cxtltodocumenttoken.hxx
 *
 * Author: $author$
 *   Date: 11/20/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CXTLTODOCUMENTTOKEN_HXX
#define _CXTLTODOCUMENTTOKEN_HXX

#include "cxtltodocumenttokenlist.hxx"
#include "cxtltodocumenttokentree.hxx"

/**
 **********************************************************************
 *  Class: cXTLToDocumentToken
 *
 * Author: $author$
 *   Date: 11/20/2005
 **********************************************************************
 */
class cXTLToDocumentToken
: virtual public cXTLToDocumentTokenInterface
{
public:
    int m_type;
    cCCharBuffer m_name;
    cXTLToDocumentTokenItem m_item;
    cXTLToDocumentTokenBranch m_branch;

    /**
     **********************************************************************
     * Constructor: cXTLToDocumentToken
     *
     *      Author: $author$
     *        Date: 11/20/2005
     **********************************************************************
     */
    cXTLToDocumentToken
    (const char *name, int type) 
    : m_name(name),
      m_type(type),
      m_item(*this),
      m_branch(*this) 
    {
        cXTLToDocumentTokenList::m_instance.Add(&m_item);
    }
    /**
     **********************************************************************
     *  Destructor: ~cXTLToDocumentToken
     *
     *      Author: $author$
     *        Date: 11/20/2005
     **********************************************************************
     */
    virtual ~cXTLToDocumentToken()
    {
        cXTLToDocumentTokenList::m_instance.Delete(&m_item);
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual const cCCharBuffer& GetName() const
    {
        return m_name;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual int GetType() const
    {
        return m_type;
    }
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 12/21/2004
     **********************************************************************
     */
    virtual cXTLToDocumentTokenBranch& GetBranch()
    {
        return m_branch;
    }
};

#endif /* _CXTLTODOCUMENTTOKEN_HXX */
