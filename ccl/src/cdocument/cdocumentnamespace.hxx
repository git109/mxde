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
 *   File: cdocumentnamespace.hxx
 *
 * Author: $author$
 *   Date: 10/20/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTNAMESPACE_HXX
#define _CDOCUMENTNAMESPACE_HXX

#include "cdocumentnamespaceimplement.hxx"
#include "cdocumentnamespacetree.hxx"
#include "curi.hxx"
#include "cdocumentartifactimplement.hxx"
#include "cavltreet.hxx"
#include "clistt.hxx"
#include "cisdynamicinstance.hxx"
#include "cinstance.hxx"
#include "cccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cDocumentNamespace
 *
 * Author: $author$
 *   Date: 10/20/2005
 **********************************************************************
 */
class cDocumentNamespace
: virtual public cDocumentNamespaceImplement,
  public cDynamicListItemT
  <cDocumentNamespace, cIsDynamicInstance>
{
public:
    typedef cDynamicListItemT
    <cDocumentNamespace, cIsDynamicInstance> cIs;

    cDocumentNamespaceBranch m_branch;
    cURI m_uri;

    /**
     **********************************************************************
     * Constructor: cDocumentNamespace
     *
     *      Author: $author$
     *        Date: 10/20/2005
     **********************************************************************
     */
    cDocumentNamespace
    (const cChar* chars=0, int length=-1,
     bool is_dynamic=false) 
    : m_branch(*this)
    {
        eError error;

        m_is_dynamic = is_dynamic;

        if (chars)
        if (0 > (length = SetNamespaceURICChars(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cDocumentNamespace
     *
     *      Author: $author$
     *        Date: 10/20/2005
     **********************************************************************
     */
    cDocumentNamespace
    (const char* chars, int length=-1,
     bool is_dynamic=false) 
    : m_branch(*this)
    {
        eError error;

        m_is_dynamic = is_dynamic;

        if (chars)
        if (0 > (length = SetNamespaceURIChars(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     *  Destructor: ~cDocumentNamespace
     *
     *      Author: $author$
     *        Date: 10/20/2005
     **********************************************************************
     */
    virtual ~cDocumentNamespace()
    {
    }

    /**
     **********************************************************************
     * Function: SetNamespaceURIChars
     *
     *   Author: $author$
     *     Date: 10/20/2005
     **********************************************************************
     */
    virtual int SetNamespaceURIChars
    (const char* chars, int length=-1)
    {
        length = m_uri.SetURIChars(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: SetNamespaceURICChars
     *
     *   Author: $author$
     *     Date: 10/20/2005
     **********************************************************************
     */
    virtual int SetNamespaceURICChars
    (const cChar* chars, int length=-1)
    {
        length = m_uri.SetURICChars(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetNamespaceURICChars
     *
     *   Author: $author$
     *     Date: 10/20/2005
     **********************************************************************
     */
    virtual const cChar* GetNamespaceURICChars(int &length) const 
    {
        const cChar* chars = m_uri.GetURICChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetNamespaceURI
     *
     *   Author: $author$
     *     Date: 11/3/2005
     **********************************************************************
     */
    virtual const cURIInterface& GetNamespaceURI() const 
    {
        return m_uri;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNamespaceList
 *
 * Author: $author$
 *   Date: 10/29/2005
 **********************************************************************
 */
class cDocumentNamespaceList
: public cDynamicListT
  <cDocumentNamespace, cDocumentNamespaceList>
{
public:
    typedef cDynamicListT
    <cDocumentNamespace, cDocumentNamespaceList> cIs;

    /**
     **********************************************************************
     *  Destructor: ~cDocumentNamespaceList
     *
     *      Author: $author$
     *        Date: 10/29/2005
     **********************************************************************
     */
    virtual ~cDocumentNamespaceList()
    {
    }
};

#endif /* _CDOCUMENTNAMESPACE_HXX */
