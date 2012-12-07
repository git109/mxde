/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: ctchartocharreader.hxx
 *
 * Author: $author$
 *   Date: 10/29/2009
 **********************************************************************
 */
#if !defined(_CTCHARTOCHARREADER_HXX) || defined(CTCHARTOCHARREADER_MEMBERS_ONLY)
#if !defined(_CTCHARTOCHARREADER_HXX) && !defined(CTCHARTOCHARREADER_MEMBERS_ONLY)
#define _CTCHARTOCHARREADER_HXX
#endif /* !defined(_CTCHARTOCHARREADER_HXX) && !defined(CTCHARTOCHARREADER_MEMBERS_ONLY) */

#if !defined(CTCHARTOCHARREADER_MEMBERS_ONLY)
#include "creader.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cTCHARToCHARReader
 *
 * Author: $author$
 *   Date: 10/29/2009
 **********************************************************************
 */
class cTCHARToCHARReader
: public cCHARReader
{
public:
    typedef cCHARReader cExtends;
    
    cTCHARReaderInterface& m_tcharReader;
    
    /**
     **********************************************************************
     *  Constructor: cTCHARToCHARReader
     *
     *       Author: $author$
     *         Date: 10/29/2009
     **********************************************************************
     */
    cTCHARToCHARReader
    (cTCHARReaderInterface& tcharReader)
    : m_tcharReader(tcharReader)
    {
    }
#else /* !defined(CTCHARTOCHARREADER_MEMBERS_ONLY) */
#endif /* !defined(CTCHARTOCHARREADER_MEMBERS_ONLY) */

#if !defined(CTCHARTOCHARREADER_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 10/29/2009
     **********************************************************************
     */
    virtual tLength Get
    (tWhat& what) 
    {
        tLength count = 0;
        TCHAR twhat;
        if (0 < (count = m_tcharReader.Get(twhat)))
            what = (tWhat)(twhat);
        return count;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 10/29/2009
     **********************************************************************
     */
    virtual tLength Read
    (tWhat* what,
     tSize size) 
    {
        tLength count = 0;
        tLength count2;
        if (what)
        for (; size; --size, what++, count += count2)
        {
            if (0 >= (count2 = Get(*what)))
            {
                if (0 > count2)
                    count = count2;
                break;
            }
        }
        return count;
    }
};

#if !defined(CTCHARTOCHARTOBYTEREADER_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cTCHARToCHARToBYTEReader
 *
 * Author: $author$
 *   Date: 10/29/2009
 **********************************************************************
 */
class cTCHARToCHARToBYTEReader
: public cBYTEReader
{
public:
    typedef cBYTEReader cExtends;
    
    cTCHARReaderInterface& m_tcharReader;
    
    /**
     **********************************************************************
     *  Constructor: cTCHARToCHARToBYTEReader
     *
     *       Author: $author$
     *         Date: 10/29/2009
     **********************************************************************
     */
    cTCHARToCHARToBYTEReader
    (cTCHARReaderInterface& tcharReader)
    : m_tcharReader(tcharReader)
    {
    }
#else /* !defined(CTCHARTOCHARTOBYTEREADER_MEMBERS_ONLY) */
#endif /* !defined(CTCHARTOCHARTOBYTEREADER_MEMBERS_ONLY) */

#if !defined(CTCHARTOCHARTOBYTEREADER_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 10/29/2009
     **********************************************************************
     */
    virtual tLength Get
    (tWhat& what) 
    {
        tLength count = 0;
        TCHAR twhat;
        if (0 < (count = m_tcharReader.Get(twhat)))
            what = (tWhat)(twhat);
        return count;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 10/29/2009
     **********************************************************************
     */
    virtual tLength Read
    (tWhat* what,
     tSize size) 
    {
        tLength count = 0;
        tLength count2;
        if (what)
        for (; size; --size, what++, count += count2)
        {
            if (0 >= (count2 = Get(*what)))
            {
                if (0 > count2)
                    count = count2;
                break;
            }
        }
        return count;
    }
};
#else /* !defined(CTCHARTOCHARTOBYTEREADER_MEMBERS_ONLY) */
#endif /* !defined(CTCHARTOCHARTOBYTEREADER_MEMBERS_ONLY) */

#if !defined(CTCHARTOBYTEREADER_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cTCHARToBYTEReader
 *
 * Author: $author$
 *   Date: 11/20/2009
 **********************************************************************
 */
class cTCHARToBYTEReader
: public cBYTEReader
{
public:
    typedef cBYTEReader cExtends;
    
    cTCHARReaderInterface& m_tcharReader;
    
    /**
     **********************************************************************
     *  Constructor: cTCHARToBYTEReader
     *
     *       Author: $author$
     *         Date: 11/20/2009
     **********************************************************************
     */
    cTCHARToBYTEReader
    (cTCHARReaderInterface& tcharReader)
    : m_tcharReader(tcharReader)
    {
    }
#else /* !defined(CTCHARTOBYTEREADER_MEMBERS_ONLY) */
#endif /* !defined(CTCHARTOBYTEREADER_MEMBERS_ONLY) */

#if !defined(CTCHARTOBYTEREADER_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 10/29/2009
     **********************************************************************
     */
    virtual tLength Get
    (tWhat& what) 
    {
        tLength count = 0;
        TCHAR twhat;
        if (0 < (count = m_tcharReader.Get(twhat)))
            what = (tWhat)(twhat);
        return count;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/20/2009
     **********************************************************************
     */
    virtual tLength Read
    (tWhat& what) 
    {
        tLength count = 0;
        tLength count2;
        TCHAR twhat;
        if (0 < (count2 = m_tcharReader.Get(twhat)))
        for (;(count < sizeof(TCHAR)); count++)
            (&what)[count] = ((tWhat*)(&twhat))[count];
        return count;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 10/29/2009
     **********************************************************************
     */
    virtual tLength Read
    (tWhat* what,
     tSize size) 
    {
        tLength count = 0;
        tLength count2;
        if (what)
        for (; size >= sizeof(TCHAR); size -= count2, count += count2, what += count2)
        {
            if (0 >= (count2 = Read(*what)))
            {
                if (0 > count2)
                    count = count2;
                break;
            }
        }
        return count;
    }
};
#else /* !defined(CTCHARTOBYTEREADER_MEMBERS_ONLY) */
#endif /* !defined(CTCHARTOBYTEREADER_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTCHARTOCHARREADER_MEMBERS_ONLY) */
#endif /* !defined(CTCHARTOCHARREADER_MEMBERS_ONLY) */

#endif /* !defined(_CTCHARTOCHARREADER_HXX) || defined(CTCHARTOCHARREADER_MEMBERS_ONLY) */
