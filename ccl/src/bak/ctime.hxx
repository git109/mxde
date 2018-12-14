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
 *   File: ctime.hxx
 *
 * Author: $author$
 *   Date: 4/23/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTIME_HXX
#define _CTIME_HXX

#include "ctimeimplement.hxx"
#include "ctimeinterface.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cDate
 *
 * Author: $author$
 *   Date: 4/23/2004
 **********************************************************************
 */
class cDate
: virtual public cDateImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    int m_year,m_month,m_day;

    /**
     **********************************************************************
     * Constructor: cDate
     *
     *      Author: $author$
     *        Date: 4/23/2004
     **********************************************************************
     */
    cDate(int year=0,int month=0,int day=0) 
    : m_year(year),m_month(month),m_day(day) 
    {
    }

    /**
     **********************************************************************
     * Function: SetYear
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int SetYear(int year)
    {
        return m_year = year;
    }
    /**
     **********************************************************************
     * Function: GetYear
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int GetYear() const
    {
        return m_year;
    }

    /**
     **********************************************************************
     * Function: SetMonth
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int SetMonth(int month)
    {
        return m_month = month;
    }
    /**
     **********************************************************************
     * Function: GetMonth
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int GetMonth() const
    {
        return m_month;
    }

    /**
     **********************************************************************
     * Function: SetDay
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int SetDay(int day)
    {
        return m_day = day;
    }
    /**
     **********************************************************************
     * Function: GetDay
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int GetDay() const
    {
        return m_day;
    }
};

/**
 **********************************************************************
 *  Class: cTime
 *
 * Author: $author$
 *   Date: 4/23/2004
 **********************************************************************
 */
class cTime
: virtual public cTimeImplement,
  public cDate
{
public:
    typedef cDate cIs;

    int m_hour,m_minute,m_second;

    /**
     **********************************************************************
     * Constructor: cTime
     *
     *      Author: $author$
     *        Date: 4/23/2004
     **********************************************************************
     */
    cTime(int hour=0,int minute=0,int second=0)
    : m_hour(hour),m_minute(minute),m_second(second)
    {
    }

    /**
     **********************************************************************
     * Function: SetHour
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int SetHour(int hour,bool is_12=false)
    {
        return m_hour = hour;
    }
    /**
     **********************************************************************
     * Function: GetHour
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int GetHour(bool is_12=false) const
    {
        return m_hour;
    }

    /**
     **********************************************************************
     * Function: SetMinute
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int SetMinute(int minute)
    {
        return m_minute = minute;
    }
    /**
     **********************************************************************
     * Function: GetMinute
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int GetMinute() const
    {
        return m_minute;
    }

    /**
     **********************************************************************
     * Function: SetSecond
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int SetSecond(int second)
    {
        return m_second = second;
    }
    /**
     **********************************************************************
     * Function: GetSecond
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int GetSecond() const
    {
        return m_second;
    }
};

#endif /* ndef _CTIME_HXX */
