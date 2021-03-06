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
 *   File: ctimeinterface.hxx
 *
 * Author: $author$
 *   Date: 4/17/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTIMEINTERFACE_HXX
#define _CTIMEINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cDateInterface
 *
 * Author: $author$
 *   Date: 4/17/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDateInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 4/17/2004
     **********************************************************************
     */
    enum
    {
        e_MONTH_NONE    = 0,
        e_FIRST_MONTH   = 1,
        e_MONTH_JANUARY = e_FIRST_MONTH,
        e_MONTH_FEBUARY,
        e_MONTH_MARCH,
        e_MONTH_APRIL,
        e_MONTH_MAY,
        e_MONTH_JUNE,
        e_MONTH_JULY,
        e_MONTH_AUGUST,
        e_MONTH_SEPTEMBER,
        e_MONTH_OCTOBER,
        e_MONTH_NOVEMBER,
        e_MONTH_DECEMBER,
        e_NEXT_MONTH,
        e_LAST_MONTH = e_NEXT_MONTH-1
    };

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 4/23/2004
     **********************************************************************
     */
    enum
    {
        e_DAY_OF_WEEK_NONE   = 0,
        e_FIRST_DAY_OF_WEEK  = 1,
        e_DAY_OF_WEEK_SUNDAY = e_FIRST_DAY_OF_WEEK,
        e_DAY_OF_WEEK_MONDAY,
        e_DAY_OF_WEEK_TUESDAY,
        e_DAY_OF_WEEK_WEDNESDAY,
        e_DAY_OF_WEEK_THURSDAY,
        e_DAY_OF_WEEK_FRIDAY,
        e_DAY_OF_WEEK_SATURDAY,
        e_NEXT_DAY_OF_WEEK,
        e_LAST_DAY_OF_WEEK=e_NEXT_DAY_OF_WEEK-1
    };

    /**
     **********************************************************************
     * Function: SetYear
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetYear(int year) = 0;
    /**
     **********************************************************************
     * Function: GetYear
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int GetYear() const = 0;

    /**
     **********************************************************************
     * Function: SetMonth
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetMonth(int month) = 0;
    /**
     **********************************************************************
     * Function: GetMonth
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int GetMonth() const = 0;
    /**
     **********************************************************************
     * Function: GetMonthName
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual const char *GetMonthName() const = 0;

    /**
     **********************************************************************
     * Function: SetDay
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetDay(int day) = 0;
    /**
     **********************************************************************
     * Function: GetDay
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int GetDay() const = 0;

    /**
     **********************************************************************
     * Function: SetDayOfWeek
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int SetDayOfWeek(int day_of_week) = 0;
    /**
     **********************************************************************
     * Function: GetDayOfWeek
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int GetDayOfWeek() const = 0;
    /**
     **********************************************************************
     * Function: GetDayOfWeekName
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual const char *GetDayOfWeekName() const = 0;

    /**
     **********************************************************************
     * Function: SetDate
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual eError SetDate()  = 0;
    /**
     **********************************************************************
     * Function: GetDate
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual eError GetDate()  = 0;

    /**
     **********************************************************************
     * Function: CompareDate
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int CompareDate(cDateInterface &date) const = 0;
};

/**
 **********************************************************************
 *  Class: cTimeInterface
 *
 * Author: $author$
 *   Date: 4/17/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cTimeInterface
: virtual public cDateInterface
{
public:
    /**
     **********************************************************************
     * Function: SetIsPM
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetIsPM(bool is_pm=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsPM
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual bool GetIsPM() const = 0;

    /**
     **********************************************************************
     * Function: SetHour
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetHour(int hour, bool is_12=false) = 0;
    /**
     **********************************************************************
     * Function: GetHour
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int GetHour(bool is_12=false) const = 0;

    /**
     **********************************************************************
     * Function: SetMinute
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetMinute(int minute) = 0;
    /**
     **********************************************************************
     * Function: GetMinute
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int GetMinute() const = 0;

    /**
     **********************************************************************
     * Function: SetSecond
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetSecond(int second) = 0;
    /**
     **********************************************************************
     * Function: GetSecond
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int GetSecond() const = 0;

    /**
     **********************************************************************
     * Function: SetTime
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual eError SetTime() = 0;
    /**
     **********************************************************************
     * Function: GetTime
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual eError GetTime() = 0;

    /**
     **********************************************************************
     * Function: CompareTime
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int CompareTime(cTimeInterface &time) const = 0;
};

#endif /* ndef _CTIMEINTERFACE_HXX */
