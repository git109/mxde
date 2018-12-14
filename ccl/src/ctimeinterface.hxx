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

#include "cdateinterface.hxx"

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
    virtual int GetIsPM() const = 0;

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
    virtual int CompareTime(cTimeInterface &to) const = 0;
};

#endif /* ndef _CTIMEINTERFACE_HXX */
