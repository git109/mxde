/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cutctime.hxx
 *
 * Author: $author$
 *   Date: 10/23/2007
 *
 **********************************************************************
 */


#ifndef _CUTCTIME_HXX
#define _CUTCTIME_HXX

#include <time.h>

/**
 **********************************************************************
 *  Class: cUTCTime
 *
 * Author: $author$
 *   Date: 10/23/2007
 **********************************************************************
 */
class cUTCTime
{
public:
    typedef cUTCTime cDerives;

    time_t m_time;

    /**
     **********************************************************************
     * Constructor: cUTCTime
     *
     *      Author: $author$
     *        Date: 10/23/2007
     **********************************************************************
     */
    cUTCTime(bool get_current=false) 
    : m_time(0)
    {
        if (get_current)
            GetCurrent();
    }

    /**
     **********************************************************************
     * Function: GetCurrent
     *
     *   Author: $author$
     *     Date: 10/23/2007
     **********************************************************************
     */
    virtual time_t GetCurrent()
    {
        time(&m_time);
        return m_time;
    }
    /**
     **********************************************************************
     * Function: operator time_t
     *
     *   Author: $author$
     *     Date: 10/23/2007
     **********************************************************************
     */
    virtual operator time_t() const 
    {
        return m_time;
    }
};
#endif /* _CUTCTIME_HXX */
