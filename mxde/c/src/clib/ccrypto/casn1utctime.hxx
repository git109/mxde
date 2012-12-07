/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: casn1utctime.hxx
 *
 * Author: $author$
 *   Date: 3/27/2010
 **********************************************************************
 */
#if !defined(_CASN1UTCTIME_HXX) || defined(CASN1UTCTIME_MEMBERS_ONLY)
#if !defined(_CASN1UTCTIME_HXX) && !defined(CASN1UTCTIME_MEMBERS_ONLY)
#define _CASN1UTCTIME_HXX
#endif /* !defined(_CASN1UTCTIME_HXX) && !defined(CASN1UTCTIME_MEMBERS_ONLY) */

#if !defined(CASN1UTCTIME_MEMBERS_ONLY)
#include "casn1base.hxx"
#include "creaderinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cASN1UTCTime
 *
 * Author: $author$
 *   Date: 3/27/2010
 **********************************************************************
 */
class c_ASN1_CLASS cASN1UTCTime
{
public:
    UINT m_year;
    UINT m_month;
    UINT m_day;
    UINT m_hour;
    UINT m_minute;
    UINT m_second;

    /**
     **********************************************************************
     *  Function: Read
     *
     *    Author: $author$
     *      Date: 3/27/2010
     **********************************************************************
     */
    TLENGTH Read
    (cBYTEReaderInterface& reader)
    {
        TLENGTH count = 0;
        TLENGTH count2;

        m_year = (m_month = (m_day = (m_hour = (m_minute = (m_second = 0)))));

        if (1 < (count2 = Read(m_year, reader)))
        if (1900 <= (m_year += ((m_year < 50)?(2000):(1900))))
        if (1 < (count += count2))
        if (1 < (count2 = Read(m_month, reader)))
        if (1 < (count += count2))
        if (1 < (count2 = Read(m_day, reader)))
        if (1 < (count += count2))
        if (1 < (count2 = Read(m_hour, reader)))
        if (1 < (count += count2))
        if (1 < (count2 = Read(m_minute, reader)))
        if (1 < (count += count2))
        if (1 < (count2 = Read(m_second, reader)))
        if (1 < (count += count2))
            return count;

        return count = 0;
    }
    /**
     **********************************************************************
     *  Function: Read
     *
     *    Author: $author$
     *      Date: 3/27/2010
     **********************************************************************
     */
    TLENGTH Read
    (UINT& value, cBYTEReaderInterface& reader)
    {
        TLENGTH count = 0;
        TLENGTH count2;
        BYTE byte;

        if (0 < (count2 = reader.Read(&byte, 1)))
        if ((byte >= '0') && (byte <= '9'))
        if (0 < (count += count2))
        if (0 <= (value = (byte - '0')))
        if (0 < (count2 = reader.Read(&byte, 1)))
        if ((byte >= '0') && (byte <= '9'))
        if (0 < (count += count2))
        if (0 <= (value = (value * 10) + (byte - '0')))
        {
        }
        return count;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CASN1UTCTIME_MEMBERS_ONLY) */
#endif /* !defined(CASN1UTCTIME_MEMBERS_ONLY) */

#endif /* !defined(_CASN1UTCTIME_HXX) || defined(CASN1UTCTIME_MEMBERS_ONLY) */
