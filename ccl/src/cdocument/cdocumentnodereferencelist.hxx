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
 *   File: cdocumentnodereferencelist.hxx
 *
 * Author: $author$
 *   Date: 11/20/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTNODEREFERENCELIST_HXX
#define _CDOCUMENTNODEREFERENCELIST_HXX


#include "cdocumentartifactinterface.hxx"

/**
 **********************************************************************
 *  Class: cDocumentNodeReferenceItem
 *
 * Author: $author$
 *   Date: 11/20/2005
 **********************************************************************
 */
class cDocumentNodeReferenceItem
: public cDynamicListItemT<cDocumentNodeReferenceItem>
{
public:
    typedef cDynamicListItemT<cDocumentNodeReferenceItem> cIs;

    cDocumentNodeInterface& m_node;

    /**
     **********************************************************************
     * Constructor: cDocumentNodeReferenceItem
     *
     *      Author: $author$
     *        Date: 11/20/2005
     **********************************************************************
     */
    cDocumentNodeReferenceItem(cDocumentNodeInterface& node) 
    : m_node(node) 
    {
    }
    /**
     **********************************************************************
     * Function: GetNode
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    cDocumentNodeInterface& GetNode() const 
    {
        return m_node;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentNodeReferenceList
 *
 * Author: $author$
 *   Date: 11/20/2005
 **********************************************************************
 */
class cDocumentNodeReferenceList
: public cDynamicListT
  <cDocumentNodeReferenceItem, cDocumentNodeReferenceList>
{
public:
    typedef cDynamicListT
    <cDocumentNodeReferenceItem, cDocumentNodeReferenceList> cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentNodeReferenceList
     *
     *      Author: $author$
     *        Date: 11/20/2005
     **********************************************************************
     */
    cDocumentNodeReferenceList() 
    {
    }
    /**
     **********************************************************************
     * Function: Push
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    eError Push(cDocumentNodeInterface& node) 
    {
        eError error = e_ERROR_NONE;
        cDocumentNodeReferenceItem *item;

        if ((item = new cDocumentNodeReferenceItem(node)))
            cIs::Push(item);
        else error = e_ERROR_NEW;

        return error;
    }
    /**
     **********************************************************************
     * Function: Pop
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    cDocumentNodeInterface* Pop(eError &error) 
    {
        cDocumentNodeInterface* node = 0;
        cDocumentNodeReferenceItem *item;

        error = e_ERROR_NONE;

        if ((item = cIs::Pop()))
        {
            node = &item->GetNode();
            delete item;
        }
        return node;
    }
    /**
     **********************************************************************
     * Function: Pull
     *
     *   Author: $author$
     *     Date: 11/30/2005
     **********************************************************************
     */
    cDocumentNodeInterface* Pull(eError &error) 
    {
        cDocumentNodeInterface* node = 0;
        cDocumentNodeReferenceItem *item;

        error = e_ERROR_NONE;

        if ((item = cIs::Pull()))
        {
            node = &item->GetNode();
            delete item;
        }
        return node;
    }
    /**
     **********************************************************************
     * Function: Top
     *
     *   Author: $author$
     *     Date: 11/20/2005
     **********************************************************************
     */
    cDocumentNodeInterface* Top(eError &error) const
    {
        cDocumentNodeInterface* node = 0;
        cDocumentNodeReferenceItem *item;

        error = e_ERROR_NONE;

        if ((item = cIs::GetFirst()))
            node = &item->GetNode();

        return node;
    }
};

#endif /* _CDOCUMENTNODEREFERENCELIST_HXX */
