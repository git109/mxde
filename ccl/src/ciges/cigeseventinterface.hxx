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
 *   File: cigeseventinterface.hxx
 *
 * Author: $author$
 *   Date: 7/24/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CIGESEVENTINTERFACE_HXX
#define _CIGESEVENTINTERFACE_HXX

#include <stdio.h>
#include "cigesparam.hxx"
#include "cigesentity.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cIGESEventInterface
 *
 * Author: $author$
 *   Date: 7/24/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cIGESEventInterface
{
public:
    /**
     **********************************************************************
     * Function: OnInitialize
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    virtual eError OnInitialize() = 0;
    /**
     **********************************************************************
     * Function: OnFinalize
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    virtual eError OnFinalize() = 0;
    /**
     **********************************************************************
     * Function: OnRecord
     *
     *   Author: $author$
     *     Date: 7/24/2005
     **********************************************************************
     */
    virtual eError OnRecord
    (const char* chars, int length=-1) = 0;
};

/**
 **********************************************************************
 *  Class: cIGESEventImplement
 *
 * Author: $author$
 *   Date: 7/24/2005
 **********************************************************************
 */
class cIGESEventImplement
: virtual public cIGESEventInterface
{
public:
    /**
     **********************************************************************
     * Function: OnInitialize
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    virtual eError OnInitialize() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnFinalize
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    virtual eError OnFinalize() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnRecord
     *
     *   Author: $author$
     *     Date: 7/24/2005
     **********************************************************************
     */
    virtual eError OnRecord
    (const char* chars, int length=-1)
    {
        eError error = -e_ERROR_NONE;
        return error;
    }
};

#include "ccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cIGESEvent
 *
 * Author: $author$
 *   Date: 7/24/2005
 **********************************************************************
 */
class cIGESEvent
: virtual public cIGESEventImplement
{
public:
    typedef eError (cIGESEvent::*mOnRecord)
    (const char* chars, int length=-1);

    mOnRecord m_on_record;

    cCharBuffer m_start_buffer;
    const char *m_start;
    int m_start_length;

    cCharBuffer m_global_buffer;
    const char *m_global;
    int m_global_length;

    int m_entcount;

    cIGESEntityList m_entity_list;
    cIGESEntityTree m_entity_tree;
    cIGESEntity *m_entity;

    cIGESParamList m_param_list;
    cIGESParamTree m_param_tree;
    cIGESParam *m_param;

    /**
     **********************************************************************
     * Constructor: cIGESEvent
     *
     *      Author: $author$
     *        Date: 7/24/2005
     **********************************************************************
     */
    cIGESEvent() 
    : m_on_record(OnStartRecord)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cIGESEvent
     *
     *      Author: $author$
     *        Date: 7/25/2005
     **********************************************************************
     */
    virtual ~cIGESEvent()
    {
        Finalize();
    }

    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        m_entity_list.Clear();
        m_param_list.Clear();
        return error;
    }

    /**
     **********************************************************************
     * Function: OnInitialize
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    virtual eError OnInitialize() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnFinalize
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    virtual eError OnFinalize() 
    {
        eError error = e_ERROR_NONE;
        cIGESEntityItem *item;

        for (item=m_entity_list.GetFirst(); item; item=item->GetNext())
        {
            cIGESEntity &entity = item->m_entity;
            cIGESParam *param = m_param_tree.Find(entity.m_param);

            switch(entity.m_type)
            {
            case 110:
                printf("line\n");
                break;
            }
        }
        Finalize();
        return error;
    }

    /**
     **********************************************************************
     * Function: OnRecord
     *
     *   Author: $author$
     *     Date: 7/24/2005
     **********************************************************************
     */
    virtual eError OnRecord
    (const char* chars, int length=-1)
    {
        eError error = (this->*m_on_record)(chars, length);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnStartRecord
     *
     *   Author: $author$
     *     Date: 7/24/2005
     **********************************************************************
     */
    eError OnStartRecord
    (const char* chars, int length=-1)
    {
        eError error = -e_ERROR_NONE;
        char c;

        if (72 < length)
        switch(c = chars[72])
        {
        case 'S':
            m_start_buffer.Write(chars, 72);
            break;

        default:
            if ((m_start = m_start_buffer.GetBuffer(m_start_length)))
            if (0 < m_start_length)
            {
            }
            switch(c)
            {
            case 'G':
                m_on_record = OnGlobalRecord;
                error = OnGlobalRecord(chars, length);
                break;

            default:
                error = -e_ERROR_FAILED;
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnGlobalRecord
     *
     *   Author: $author$
     *     Date: 7/24/2005
     **********************************************************************
     */
    eError OnGlobalRecord
    (const char* chars, int length=-1)
    {
        eError error = -e_ERROR_NONE;
        char c;

        if (72 < length)
        switch(c = chars[72])
        {
        case 'G':
            m_global_buffer.Write(chars, 72);
            break;

        default:
            if ((m_global = m_global_buffer.GetBuffer(m_global_length)))
            if (0 < m_global_length)
            {
            }
            switch(c)
            {
            case 'D':
                m_entcount = 0;
                m_on_record = OnDirectoryRecord;
                error = OnDirectoryRecord(chars, length);
                break;

            default:
                error = -e_ERROR_FAILED;
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnDirectoryData
     *
     *   Author: $author$
     *     Date: 7/24/2005
     **********************************************************************
     */
    virtual eError OnDirectoryData
    (const char* chars, int length=-1)
    {
        eError error = e_ERROR_NONE;
        int skip;

        if (!(m_entity = new cIGESEntity))
            return e_ERROR_FAILED;

        m_entity->m_recno = ToInt(chars+73, length-73);
        m_entity->m_type = ToInt(chars, 8);
        m_entity->m_param = ToInt(chars+=8, 8);
        m_entity->m_refer = ToInt(chars+=8, 8);
        skip = ToInt(chars+=8, 8);
        skip = ToInt(chars+=8, 8);
        m_entity->m_view = ToInt(chars+=8, 8);
        m_entity->m_trans = ToInt(chars+=8, 8);
        skip = ToInt(chars+=8, 8);
        m_entity->m_status = ToInt(chars+=8, 8);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnDirectoryData2
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    virtual eError OnDirectoryData2
    (const char* chars, int length=-1)
    {
        eError error = e_ERROR_NONE;
        int recno, type, skip;

        if (!m_entity)
            return e_ERROR_FAILED;

        recno = ToInt(chars+73, length-73);
        type = ToInt(chars, 8);
        skip = ToInt(chars+=8, 8);
        m_entity->m_color = ToInt(chars+=8, 8);
        m_entity->m_params = ToInt(chars+=8, 8);
        m_entity->m_form = ToInt(chars+=8, 8);

        m_entity_tree.Insert(m_entity);
        m_entity_list.Add(&m_entity->m_item);
        m_entity = 0;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnDirectoryRecord
     *
     *   Author: $author$
     *     Date: 7/24/2005
     **********************************************************************
     */
    eError OnDirectoryRecord
    (const char* chars, int length=-1)
    {
        eError error = -e_ERROR_NONE;
        char c;

        if (72 < length)
        switch(c = chars[72])
        {
        case 'D':
            m_on_record = OnDirectoryRecord2;
            error = OnDirectoryData(chars, length);
            break;

        default:
            switch(c)
            {
            case 'P':
                m_on_record = OnParameterRecord;
                error = OnParameterRecord(chars, length);
                break;

            default:
                error = -e_ERROR_FAILED;
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnDirectoryRecord2
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    eError OnDirectoryRecord2
    (const char* chars, int length=-1)
    {
        eError error = -e_ERROR_NONE;
        char c;

        if (72 < length)
        switch(c = chars[72])
        {
        case 'D':
            m_on_record = OnDirectoryRecord;
            error = OnDirectoryData2(chars, length);
            break;

        default:
            switch(c)
            {
            case 'P':
                m_on_record = OnParameterRecord;
                error = OnParameterRecord(chars, length);
                break;

            default:
                error = -e_ERROR_FAILED;
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnParameterData
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    eError OnParameterData
    (const char* chars, int length=-1)
    {
        eError error = e_ERROR_NONE;

        if (!(m_param = new cIGESParam))
            return e_ERROR_FAILED;

        m_param->m_recno = ToInt(chars+73, length-73);
        m_param->m_direct = ToInt(chars+64, 8);
        m_param->m_data_buffer.Write(chars, 64);
        m_on_record = OnParameterRecord2;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnParameterData2
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    eError OnParameterData2
    (const char* chars, int length=-1)
    {
        eError error = e_ERROR_NONE;
        int recno, direct;

        if (!m_param)
            return e_ERROR_FAILED;

        recno = ToInt(chars+73, length-73);
        direct = ToInt(chars+64, 8);

        if (direct != m_param->m_direct)
        {
            m_param->m_data = m_param->m_data_buffer.GetBuffer(m_param->m_data_length);
            m_param_tree.Insert(m_param);
            m_param_list.Add(&m_param->m_item);
            error = OnParameterData(chars, length);
        }
        else
        {
            m_param->m_data_buffer.Write(chars, 64);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnParameterRecord
     *
     *   Author: $author$
     *     Date: 7/24/2005
     **********************************************************************
     */
    eError OnParameterRecord
    (const char* chars, int length=-1)
    {
        eError error = -e_ERROR_NONE;
        char c;

        if (72 < length)
        switch(c = chars[72])
        {
        case 'P':
            error = OnParameterData(chars, length);
            break;

        default:
            switch(c)
            {
            case 'T':
                m_on_record = OnTerminationRecord;
                error = OnTerminationRecord(chars, length);
                break;

            default:
                error = -e_ERROR_FAILED;
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnParameterRecord2
     *
     *   Author: $author$
     *     Date: 7/25/2005
     **********************************************************************
     */
    eError OnParameterRecord2
    (const char* chars, int length=-1)
    {
        eError error = -e_ERROR_NONE;
        char c;

        if (72 < length)
        switch(c = chars[72])
        {
        case 'P':
            error = OnParameterData2(chars, length);
            break;

        default:
            switch(c)
            {
            case 'T':
                m_on_record = OnTerminationRecord;
                error = OnTerminationRecord(chars, length);
                break;

            default:
                error = -e_ERROR_FAILED;
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnTerminationRecord
     *
     *   Author: $author$
     *     Date: 7/24/2005
     **********************************************************************
     */
    eError OnTerminationRecord
    (const char* chars, int length=-1)
    {
        eError error = -e_ERROR_NONE;
        char c;

        if (72 < length)
        switch(c = chars[72])
        {
        case 'T':
            break;

        default:
            error = -e_ERROR_FAILED;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ToInt
     *
     *   Author: $author$
     *     Date: 7/24/2005
     **********************************************************************
     */
    int ToInt(const char* chars, int length)
    {
        int value;

        for (value=0; length>0; ++chars, --length)
        {
            char c = *chars;

            if (('0' <= c) && ('9' >= c))
                value = (value*10) + (c - '0');
        }
        return value;
    }
};

#endif /* _CIGESEVENTINTERFACE_HXX */