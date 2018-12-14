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
 *   File: cigesparam.hxx
 *
 * Author: $author$
 *   Date: 7/25/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CIGESPARAM_HXX
#define _CIGESPARAM_HXX

#include "clistt.hxx"
#include "cavltreet.hxx"

class cIGESParam;

/**
 **********************************************************************
 *  Class: cIGESParamItem
 *
 * Author: $author$
 *   Date: 7/25/2005
 **********************************************************************
 */
class cIGESParamItem
: public cDynamicListItemT<cIGESParamItem>
{
public:
    typedef cDynamicListItemT<cIGESParamItem> cIs;

    cIGESParam &m_param;

    /**
     **********************************************************************
     * Constructor: cIGESParamItem
     *
     *      Author: $author$
     *        Date: 7/25/2005
     **********************************************************************
     */
    cIGESParamItem(cIGESParam &param) 
    : m_param(param)
    {
    }
};

/**
 **********************************************************************
 *  Class: cIGESParam
 *
 * Author: $author$
 *   Date: 7/25/2005
 **********************************************************************
 */
class cIGESParam
: public cAVLTreeBranchT<cIGESParam>
{
public:
    typedef cAVLTreeBranchT<cIGESParam> cIs;

    cIGESParamItem m_item;

    int m_recno, m_direct;
    cCharBuffer m_data_buffer;
    const char *m_data;
    int m_data_length;

    /**
     **********************************************************************
     * Constructor: cIGESParam
     *
     *      Author: $author$
     *        Date: 7/25/2005
     **********************************************************************
     */
    cIGESParam()
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
    int Compare(cIGESParam &branch) const
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
 *  Class: cIGESParamTree
 *
 * Author: $author$
 *   Date: 7/25/2005
 **********************************************************************
 */
class cIGESParamTree
: public cAVLTreeT
  <int, cIGESParam, cIGESParamTree>
{
public:
    typedef cAVLTreeT
    <int, cIGESParam, cIGESParamTree> cIs;
};

/**
 **********************************************************************
 *  Class: cIGESParamList
 *
 * Author: $author$
 *   Date: 7/25/2005
 **********************************************************************
 */
class cIGESParamList
: public cDynamicListT
  <cIGESParamItem, cIGESParamList>
{
public:
    typedef cDynamicListT
    <cIGESParamItem, cIGESParamList> cIs;

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
        delete &item->m_param;
        return e_ERROR_NONE;
    }
};

#endif /* _CIGESPARAM_HXX */