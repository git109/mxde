/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cwindropfiles.hxx
 *
 * Author: $author$
 *   Date: 1/28/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINDROPFILES_HXX
#define _CWINDROPFILES_HXX

#include "cwinhandle.hxx"
#include "ctcharbuffer.hxx"
#include "clistt.hxx"

/**
 **********************************************************************
 *  Class: cWinDropFiles
 *
 * Author: $author$
 *   Date: 3/30/2004
 **********************************************************************
 */
class cWinDropFiles
: public cOpenedHandleT<HDROP,  NULL>
{
public:
    typedef cOpenedHandleT<HDROP,  NULL> cIs;

    /**
     **********************************************************************
     *  Class: cItem
     *
     * Author: $author$
     *   Date: 3/31/2004
     **********************************************************************
     */
    class cItem
    : public cDynamicListItemT<cItem>
    {
    public:
        typedef cDynamicListItemT<cItem> cIs;

        cTCHARBuffer m_name_buffer;

        /**
         **********************************************************************
         * Constructor: cItem
         *
         *      Author: $author$
         *        Date: 3/31/2004
         **********************************************************************
         */
        cItem() 
        {
        }
        /**
         **********************************************************************
         * Function: 
         *
         *   Author: $author$
         *     Date: 3/31/2004
         **********************************************************************
         */
        eError Get(HDROP hdrop, UINT index)
        {
            eError error=e_ERROR_FAILED;
            LPTSTR name;
            UINT length;
            int count;

            length = DragQueryFile(hdrop, index, NULL, 0);

            if ((0 < length) && (((UINT)-1) > length))
            {
                if ((length >= (UINT)m_name_buffer.GetSize()))
                if (0 > (count = m_name_buffer.SetSize(length+2)))
                    return error=-count;

                if (NULL != (name = m_name_buffer.GetWriteBuffer()))
                {
                    length = DragQueryFile(hdrop, index, name, length+1);

                    if ((0 < length) && (((UINT)-1) > length))
                    {
                        if (0 > (count = m_name_buffer.SetLength(length)))
                            return error=-count;

                        error = e_ERROR_NONE;
                    }
                }
            }
            return error;
        }
        /**
         **********************************************************************
         * Function: GetName
         *
         *   Author: $author$
         *     Date: 3/31/2004
         **********************************************************************
         */
        inline LPCTSTR GetName(int &length) const
        {
            return m_name_buffer.GetBuffer(length);
        }
    };

    /**
     **********************************************************************
     *  Class: cList
     *
     * Author: $author$
     *   Date: 3/31/2004
     **********************************************************************
     */
    class cList
    : public cDynamicListT<cItem, cList>
    {
    public:
        typedef cDynamicListT<cItem, cList> cIs;

    };

    UINT m_count;
    cList m_list;

    /**
     **********************************************************************
     * Constructor: cWinDropFiles
     *
     *      Author: $author$
     *        Date: 3/30/2004
     **********************************************************************
     */
    cWinDropFiles(HDROP handle=NULL, bool opened=false) 
    : cIs(handle, opened),
      m_count(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinDropFiles
     *
     *     Author: $author$
     *       Date: 3/30/2004
     **********************************************************************
     */
    virtual ~cWinDropFiles()
    {
        eError error;

        if (m_opened)
        if ((error = Close()))
            throw(error);

        if (NULL != m_handle)
        if ((error = Detach()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 3/30/2004
     **********************************************************************
     */
    virtual eError Open(HDROP hdrop, UINT max_count=0)
    {
        eError error;
        cItem *item;

        if (!(error = Attach(hdrop, true)))
        {
            m_count = DragQueryFile(m_handle, -1, NULL, 0);

            if ((0 < m_count) && (((UINT)-1) > m_count))
            {
                if ((0 < max_count) && (max_count < m_count))
                    m_count = max_count;

                for (UINT i=0; i<m_count; i++)
                {
                    if ((item = NewItem()))
                    {
                        if ((error = item->Get(m_handle, i)))
                        {
                            DeleteItem(*item);
                            return error;
                        }

                        m_list.Add(item);
                    }
                }
            }
        }
        
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 3/30/2004
     **********************************************************************
     */
    virtual eError Close()
    {
        eError error=e_ERROR_NONE;

        if (!m_opened)
            return e_ERROR_NOT_OPEN;

        if (NULL == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if ((error = m_list.Clear()))
            return error;

        DragFinish(m_handle);
        m_opened = false;
        m_handle = NULL;
        return error;
    }

    /**
     **********************************************************************
     * Function: NewItem
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual cItem* NewItem() 
    {
        cItem* item = new cItem();
        return item;
    }
    /**
     **********************************************************************
     * Function: DeleteItem
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual eError DeleteItem(cItem& item) 
    {
        eError error = e_ERROR_NONE;
        delete &item;
        return error;
    }

    /**
     **********************************************************************
     * Function: GetFirstItem
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    inline cItem *GetFirstItem() const
    {
        return m_list.GetFirst();
    }
    /**
     **********************************************************************
     * Function: GetNextItem
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    inline cItem *GetNextItem(cItem& item) const
    {
        return item.GetNext();
    }
    /**
     **********************************************************************
     * Function: GetCount
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    inline UINT GetCount() const
    {
        return m_count;
    }
};

#endif /* _CWINDROPFILES_HXX */
