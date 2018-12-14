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
 *   File: cdocumentnamespaceprefixnamespacelist.hxx
 *
 * Author: $author$
 *   Date: 10/30/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTNAMESPACEPREFIXNAMESPACELIST_HXX
#define _CDOCUMENTNAMESPACEPREFIXNAMESPACELIST_HXX

#include "cdocumentnamespaceinterface.hxx"
#include "clistt.hxx"

class cDocumentNamespacePrefixNamespaceStack;

/**
 **********************************************************************
 *  Class: cDocumentNamespacePrefixNamespaceItem
 *
 * Author: $author$
 *   Date: 10/29/2005
 **********************************************************************
 */
class cDocumentNamespacePrefixNamespaceItem
: public cListItemT<cDocumentNamespacePrefixNamespaceItem>
{
public:
    typedef cListItemT<cDocumentNamespacePrefixNamespaceItem> cIs;

    cDocumentNamespaceInterface& m_document_namespace;
    cDocumentNamespacePrefixNamespaceStack* m_stack;

    /**
     **********************************************************************
     * Constructor: cDocumentNamespacePrefixNamespaceItem
     *
     *      Author: $author$
     *        Date: 10/29/2005
     **********************************************************************
     */
    cDocumentNamespacePrefixNamespaceItem
    (cDocumentNamespaceInterface& document_namespace) 
    : m_document_namespace(document_namespace),
      m_stack(0)
    {
    }
    /**
     **********************************************************************
     * Function: SetStack
     *
     *   Author: $author$
     *     Date: 10/30/2005
     **********************************************************************
     */
    cDocumentNamespacePrefixNamespaceStack* 
    SetStack(cDocumentNamespacePrefixNamespaceStack* stack) 
    {
        return m_stack = stack;
    }
    /**
     **********************************************************************
     * Function: GetStack
     *
     *   Author: $author$
     *     Date: 10/30/2005
     **********************************************************************
     */
    cDocumentNamespacePrefixNamespaceStack* GetStack() const
    {
        return m_stack;
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    cDocumentNamespaceInterface& GetNamespace() 
    {
        return m_document_namespace;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNamespacePrefixNamespaceStack
 *
 * Author: $author$
 *   Date: 10/29/2005
 **********************************************************************
 */
class cDocumentNamespacePrefixNamespaceStack
: public cListT
  <cDocumentNamespacePrefixNamespaceItem, 
   cDocumentNamespacePrefixNamespaceStack>
{
public:
    typedef cListT
    <cDocumentNamespacePrefixNamespaceItem, 
     cDocumentNamespacePrefixNamespaceStack> cIs;

    cDocumentNamespaceInterface& m_bottom;

    /**
     **********************************************************************
     * Constructor: cDocumentNamespacePrefixNamespaceStack
     *
     *      Author: $author$
     *        Date: 10/29/2005
     **********************************************************************
     */
    cDocumentNamespacePrefixNamespaceStack
    (cDocumentNamespaceInterface& bottom) 
    : m_bottom(bottom)
    {
    }
    /**
     **********************************************************************
     * Function: Push
     *
     *   Author: $author$
     *     Date: 10/30/2005
     **********************************************************************
     */
    void Push(cDocumentNamespacePrefixNamespaceItem &item) 
    {
        cIs::Push(&item);
        item.SetStack(this);
    }
    /**
     **********************************************************************
     * Function: Pop
     *
     *   Author: $author$
     *     Date: 10/30/2005
     **********************************************************************
     */
    cDocumentNamespacePrefixNamespaceItem* Pop() 
    {
        cDocumentNamespacePrefixNamespaceItem* item;
        
        if ((item = cIs::Pop()))
            item->SetStack(0);

        return item;
    }
    /**
     **********************************************************************
     * Function: GetTop
     *
     *   Author: $author$
     *     Date: 10/30/2005
     **********************************************************************
     */
    cDocumentNamespaceInterface& GetTop() const 
    {
        cDocumentNamespacePrefixNamespaceItem* item;
        
        if ((item = cIs::GetFirst()))
            return item->GetNamespace();

        return m_bottom;
    }
};

#endif /* _CDOCUMENTNAMESPACEPREFIXNAMESPACELIST_HXX */
