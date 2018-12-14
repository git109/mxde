/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: cigesentity.hxx
 *
 * Author: $author$
 *   Date: 7/25/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CIGESENTITY_HXX
#define _CIGESENTITY_HXX

#include "clistt.hxx"
#include "cavltreet.hxx"

class cIGESEntity;

/**
 **********************************************************************
 *  Class: cIGESEntityItem
 *
 * Author: $author$
 *   Date: 7/25/2005
 **********************************************************************
 */
class cIGESEntityItem
: public cDynamicListItemT<cIGESEntityItem>
{
public:
    typedef cDynamicListItemT<cIGESEntityItem> cIs;

    cIGESEntity &m_entity;

    /**
     **********************************************************************
     * Constructor: cIGESEntityItem
     *
     *      Author: $author$
     *        Date: 7/25/2005
     **********************************************************************
     */
    cIGESEntityItem(cIGESEntity &entity) 
    : m_entity(entity)
    {
    }
};

/**
 **********************************************************************
 *  Class: cIGESEntity
 *
 * Author: $author$
 *   Date: 7/25/2005
 **********************************************************************
 */
class cIGESEntity
: public cAVLTreeBranchT<cIGESEntity>
{
public:
    typedef cAVLTreeBranchT<cIGESEntity> cIs;

    cIGESEntityItem m_item;

    int m_recno, m_type, m_param, m_refer, 
        m_view, m_trans, m_status, 
        m_color, m_params, m_form;

    /**
     **********************************************************************
     * Constructor: cIGESEntity
     *
     *      Author: $author$
     *        Date: 7/25/2005
     **********************************************************************
     */
    cIGESEntity()
    : m_item(*this)
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    int Compare(cIGESEntity &branch) const
    {
        int unequal = Compare(branch.m_recno);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    int Compare(int recno) const
    {
        int unequal = m_recno - recno;
        return unequal;
    }
};
/**
 **********************************************************************
 *  Class: cIGESEntityTree
 *
 * Author: $author$
 *   Date: 7/25/2005
 **********************************************************************
 */
class cIGESEntityTree
: public cAVLTreeT
  <int, cIGESEntity, cIGESEntityTree>
{
public:
    typedef cAVLTreeT
    <int, cIGESEntity, cIGESEntityTree> cIs;
};

/**
 **********************************************************************
 *  Class: cIGESEntityList
 *
 * Author: $author$
 *   Date: 7/25/2005
 **********************************************************************
 */
class cIGESEntityList
: public cDynamicListT
  <cIGESEntityItem, cIGESEntityList>
{
public:
    typedef cDynamicListT
    <cIGESEntityItem, cIGESEntityList> cIs;

    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    virtual eError Free(cOf *item)
    {
        delete &item->m_entity;
        return e_ERROR_NONE;
    }
};

#endif /* ndef _CIGESENTITY_HXX */

