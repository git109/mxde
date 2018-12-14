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
 *   File: cigeswriter.hxx
 *
 * Author: $author$
 *   Date: 7/23/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CIGESWRITER_HXX
#define _CIGESWRITER_HXX

#include "ccharbuffer.hxx"
#include "cigeseventinterface.hxx"

/**
 **********************************************************************
 *  Class: cIGESWriter
 *
 * Author: $author$
 *   Date: 7/23/2005
 **********************************************************************
 */
class cIGESWriter
{
public:
    enum { e_FIXED_RECORD_SIZE = 80 };
    typedef int (cIGESWriter::*mPutc)(int c);

    cIGESEventInterface &m_event;

    mPutc m_old_putc, m_putc;

    cCharBuffer m_record_buffer1;
    cCharBuffer m_record_buffer;
    const char *m_record;
    int m_record_length;
    int m_record_size;

    /**
     **********************************************************************
     * Constructor: cIGESWriter
     *
     *      Author: $author$
     *        Date: 7/23/2005
     **********************************************************************
     */
    cIGESWriter(cIGESEventInterface &event) 
    : m_event(event),
      m_old_putc(Record1Putc),
      m_putc(Record1Putc),
      m_record_size(0)
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 7/23/2005
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;

        m_old_putc = m_putc = Record1Putc;
        m_record_size = 0;
        m_event.OnInitialize();
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 7/23/2005
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        m_event.OnFinalize();
        return error;
    }

    /**
     **********************************************************************
     * Function: Putc
     *
     *   Author: $author$
     *     Date: 7/23/2005
     **********************************************************************
     */
    virtual int Putc(int c) 
    {
        int count = 1;

        count = (this->*m_putc)(c);
        return count;
    }
    /**
     **********************************************************************
     * Function: Record1Putc
     *
     *   Author: $author$
     *     Date: 7/23/2005
     **********************************************************************
     */
    virtual int Record1Putc(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '\n':
        case '\r':
            if ((m_record = m_record_buffer1.GetBuffer(m_record_length)))
            if (0 < m_record_length)
            {
                m_event.OnRecord(m_record, m_record_length);
                m_record_buffer1.Clear();
            }
            m_putc = RecordPutc;
            break;

        default:
            if (0 > (c = m_record_buffer1.Putc(c)))
                count = c;
            else if (e_FIXED_RECORD_SIZE <= ++m_record_size)
            {
                m_putc = FixedRecord2Putc;
                m_record_size = 0;
            }
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: FixedRecord2Putc
     *
     *   Author: $author$
     *     Date: 7/24/2005
     **********************************************************************
     */
    virtual int FixedRecord2Putc(int c) 
    {
        int count = c;

        switch(c)
        {
        case '\n':
        case '\r':
            if ((m_record = m_record_buffer.GetBuffer(m_record_length)))
            if (0 < m_record_length)
            if (0 > (c = m_record_buffer1.Write(m_record, m_record_length)))
            {
                count = c;
                break;
            }

            if ((m_record = m_record_buffer1.GetBuffer(m_record_length)))
            if (0 < m_record_length)
            {
                m_event.OnRecord(m_record, m_record_length);
                m_record_buffer1.Clear();
            }

            m_putc = RecordPutc;
            break;

        default:
            if (0 > (c = m_record_buffer.Putc(c)))
                count = c;
            else if (e_FIXED_RECORD_SIZE <= ++m_record_size)
            {
                if ((m_record = m_record_buffer1.GetBuffer(m_record_length)))
                if (0 < m_record_length)
                {
                    m_event.OnRecord(m_record, m_record_length);
                    m_record_buffer1.Clear();
                }

                if ((m_record = m_record_buffer.GetBuffer(m_record_length)))
                if (0 < m_record_length)
                {
                    m_event.OnRecord(m_record, m_record_length);
                    m_record_buffer.Clear();
                }

                m_putc = FixedRecordPutc;
                m_record_size = 0;
            }
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: FixedRecordPutc
     *
     *   Author: $author$
     *     Date: 7/24/2005
     **********************************************************************
     */
    virtual int FixedRecordPutc(int c) 
    {
        int count = 1;

        switch(c)
        {
        case '\n':
        case '\r':
            count = -e_ERROR_FAILED;
            break;

        default:
            if (0 > (c = m_record_buffer.Putc(c)))
                count = c;
            else if (e_FIXED_RECORD_SIZE <= ++m_record_size)
            {
                if ((m_record = m_record_buffer.GetBuffer(m_record_length)))
                if (0 < m_record_length)
                {
                    m_event.OnRecord(m_record, m_record_length);
                    m_record_buffer.Clear();
                }
                m_record_size = 0;
            }
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: RecordPutc
     *
     *   Author: $author$
     *     Date: 7/23/2005
     **********************************************************************
     */
    virtual int RecordPutc(int c) 
    {
        int count = c;

        switch(c)
        {
        case '\n':
        case '\r':
            if ((m_record = m_record_buffer.GetBuffer(m_record_length)))
            if (0 < m_record_length)
            {
                m_event.OnRecord(m_record, m_record_length);
                m_record_buffer.Clear();
            }
            break;

        default:
            if (0 > (c = m_record_buffer.Putc(c)))
                count = c;
        }
        return count;
    }
};

#endif /* _CIGESWRITER_HXX */