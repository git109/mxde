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
 *   File: ctimeimplement.hxx
 *
 * Author: $author$
 *   Date: 4/20/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTIMEIMPLEMENT_HXX
#define _CTIMEIMPLEMENT_HXX

#include "ctimeinterface.hxx"

/**
 **********************************************************************
 *  Class: cDateImplement
 *
 * Author: $author$
 *   Date: 4/20/2004
 **********************************************************************
 */
class cDateImplement
: virtual public cDateInterface
{
public:
    /**
     **********************************************************************
     * Function: SetYear
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetYear(int year)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetYear
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int GetYear() const
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: SetMonth
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetMonth(int month)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetMonth
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int GetMonth() const
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetMonthName
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual const char *GetMonthName() const
    {
        switch(GetMonth())
        {
        case e_MONTH_JANUARY:
            return "january";
        case e_MONTH_FEBUARY:
            return "febuary";
        case e_MONTH_MARCH:
            return "march";
        case e_MONTH_APRIL:
            return "april";
        case e_MONTH_MAY:
            return "may";
        case e_MONTH_JUNE:
            return "june";
        case e_MONTH_JULY:
            return "july";
        case e_MONTH_AUGUST:
            return "august";
        case e_MONTH_SEPTEMBER:
            return "september";
        case e_MONTH_OCTOBER:
            return "october";
        case e_MONTH_NOVEMBER:
            return "november";
        case e_MONTH_DECEMBER:
            return "december";
        }
        return "";
    }

    /**
     **********************************************************************
     * Function: SetDay
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetDay(int day)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetDay
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int GetDay() const
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: SetDayOfWeek
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int SetDayOfWeek(int day_of_week)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetDayOfWeek
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual int GetDayOfWeek() const
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetDayOfWeekName
     *
     *   Author: $author$
     *     Date: 4/23/2004
     **********************************************************************
     */
    virtual const char *GetDayOfWeekName() const
    {
        switch(GetDayOfWeek())
        {
        case e_DAY_OF_WEEK_SUNDAY:
            return "sunday";

        case e_DAY_OF_WEEK_MONDAY:
            return "monday";

        case e_DAY_OF_WEEK_TUESDAY:
            return "tuesday";

        case e_DAY_OF_WEEK_WEDNESDAY:
            return "wednesday";

        case e_DAY_OF_WEEK_THURSDAY:
            return "thursday";

        case e_DAY_OF_WEEK_FRIDAY:
            return "friday";

        case e_DAY_OF_WEEK_SATURDAY:
            return "saturday";
        }
        return "";
    }

    /**
     **********************************************************************
     * Function: SetDate
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual eError SetDate()
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetDate
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual eError GetDate()
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: CompareDate
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int CompareDate(cDateInterface &date) const
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
};

/**
 **********************************************************************
 *  Class: cTimeImplement
 *
 * Author: $author$
 *   Date: 4/20/2004
 **********************************************************************
 */
class cTimeImplement
: virtual public cTimeInterface,
  virtual public cDateImplement
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
    virtual int SetIsPM(bool is_pm=true)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetIsPM
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual bool GetIsPM() const
    {
        return false;
    }

    /**
     **********************************************************************
     * Function: SetHour
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetHour(int hour, bool is_12=false)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetHour
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int GetHour(bool is_12=false) const
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: SetMinute
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetMinute(int minute)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetMinute
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int GetMinute() const
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: SetSecond
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int SetSecond(int second)
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetSecond
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int GetSecond() const
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: SetTime
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual eError SetTime()
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
    /**
     **********************************************************************
     * Function: GetTime
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual eError GetTime()
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }

    /**
     **********************************************************************
     * Function: CompareTime
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual int CompareTime(cTimeInterface &time) const
    {
        return -e_ERROR_NOT_IMPLEMENTED;
    }
};

#endif /* ndef _CTIMEIMPLEMENT_HXX */
