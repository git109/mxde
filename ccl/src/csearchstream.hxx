/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: csearchstream.hxx
 *
 * Author: $author$
 *   Date: 8/6/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSEARCHSTREAM_HXX
#define _CSEARCHSTREAM_HXX

#include <stdio.h>

#include "ccharstream.hxx"

/**
 **********************************************************************
 *  Class: cSearchStream
 *
 * Author: $author$
 *   Date: 8/6/2003
 **********************************************************************
 */
class cSearchStream
: public cCharStream
{
public:
    typedef cCharStream cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 8/6/2003
     **********************************************************************
     */
    enum
    {
        e_FIRST_ERROR=cIs::e_NEXT_ERROR,
        e_ERROR_PATTERN_FOUND=e_FIRST_ERROR,
        e_ERROR_STREAM_PATTERN_FOUND,
        e_ERROR_STREAM_ERROR,
        e_NEXT_ERROR,
        e_LAST_ERROR=e_NEXT_ERROR-1
    };

    cCharStream &m_stream;
    const char *m_pattern;
    int m_patternlen;
    bool m_pattern_found;
    bool m_endchar_found;
    int m_matched;
    int m_matchedpos;
    int m_matchedlen;
    int m_stream_count;
    int m_count;
    int m_char;

    /**
     **********************************************************************
     * Constructor: cSearchStream
     *
     *      Author: $author$
     *        Date: 8/6/2003
     **********************************************************************
     */
    cSearchStream
    (cCharStream &stream,
     const char *pattern="",int patternlen=-1)
    :m_stream(stream),
     m_pattern(pattern),
     m_patternlen(patternlen),
     m_pattern_found(false),
     m_endchar_found(false),
     m_matched(0),
     m_matchedpos(0),
     m_matchedlen(0),
     m_stream_count(0),
     m_count(0),
     m_char(-1) 
    {
        if (!m_pattern)
            m_pattern = "";

        if (m_patternlen<0)
            m_patternlen=strlen(m_pattern);
    }
    /**
     **********************************************************************
     * Function: SetPattern
     *
     *   Author: $author$
     *     Date: 8/6/2003
     **********************************************************************
     */
    virtual int SetPattern
    (const char *pattern="", int patternlen=-1)
    {
        m_pattern=pattern;
        m_patternlen=patternlen;
        m_pattern_found=false;
        m_endchar_found=false;
        m_matched=0;
        m_matchedpos=0;
        m_matchedlen=0;
        m_stream_count=0;
        m_count=0;
        m_char=-1;

        if (!m_pattern)
            m_pattern = "";

        if (m_patternlen<0)
            m_patternlen=strlen(m_pattern);

        return m_patternlen;
    }
    /**
     **********************************************************************
     * Function: GetPattern
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
    virtual const char *GetPattern(int &patternlen) const
    {
        patternlen = m_patternlen;
        return m_pattern;
    }
    /**
     **********************************************************************
     * Function: GetMode
     *
     *   Author: $author$
     *     Date: 12/6/2003
     **********************************************************************
     */
    virtual int GetMode() const
    {
        return m_stream.GetMode();
    }
    /**
     **********************************************************************
     * Function: Getc
     *
     *   Author: $author$
     *     Date: 12/6/2003
     **********************************************************************
     */
    virtual int Getc()
    {
        int count;
        unsigned char of;

        if ((count = Read((char*)&of, 1)) > 0)
            return of;

        if (count < 0)
            return count;

        if (m_pattern_found)
            return -e_ERROR_PATTERN_FOUND;

        return -e_ERROR_ENDOF;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
    virtual int Read(char *buffer, int size)
    {
        int count;        
        int length;
        
        m_pattern_found = false;

        if (!buffer)
            return -e_ERROR_NULL_PARAMETER;

        if (size < 0)
            return -e_ERROR_INVALID_PARAMETER_SIZE;

        count = 0;

        for (length = 0; length < size; length++)
        {
            if ((count = Get(buffer[length])) <= 0)
            {
                if (!(m_pattern_found = (-e_ERROR_PATTERN_FOUND == count)))
                    return count;

                break;
            }
        }

        return length;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
    virtual int Get(char &c)
    {
        int i,j,count,matched;

        if (m_matchedpos < m_matchedlen)
        {
            c = m_pattern[m_matchedpos];

            if ((++m_matchedpos) >= m_matchedlen)
            {
                m_matchedpos = 0;
                m_matchedlen = 0;
            }
            return 1;
        }

        if (m_char >= 0)
        {
            c = m_char;
            m_char = -1;
            return 1;
        }

        if ((count = m_count) < 0)
        {
            m_count = 0;
            return count;
        }

        do
        {
            if ((count = (m_stream_count = m_stream.Get(c))) < 1)
            {
                if (-e_ERROR_PATTERN_FOUND == m_stream_count)
                    count = -e_ERROR_STREAM_PATTERN_FOUND;

                if (m_matched)
                {
                    c = m_pattern[0];

                    if (m_matched > 1)
                    {
                        m_matchedpos = 1;
                        m_matchedlen = m_matched;
                    }
                    m_matched = 0;
                    m_count = count;
                    return 1;
                }

                return count;
            }

            if (c == m_pattern[m_matched])
            {
                if ((++m_matched) >= m_patternlen)
                {
                    m_matched = 0;
                    return -e_ERROR_PATTERN_FOUND;
                }
                continue;
            }
            else if (m_matched)
            {
                for (matched = m_matched; matched > 0; --matched)
                {
                    m_matchedlen++;

                    if (c==m_pattern[matched-1])
                    {
                        for (i=matched-1, j=m_matched-1; i>0; --i, --j)
                        {
                            if (m_pattern[i-1] != m_pattern[j])
                                break;
                        }
                        if (i<1)
                            break;
                    }
                }
 
                if ((m_matched = matched) < 1)
                    m_char=((unsigned char)c);

                c = m_pattern[m_matchedpos];

                if ((++m_matchedpos) >= m_matchedlen)
                {
                    m_matchedpos = 0;
                    m_matchedlen = 0;
                }
            }
            return 1;
        }
        while(count > 0);

        return count;
    }
    /**
     **********************************************************************
     * Function: FindEndChar
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
    bool FindEndChar(const char *endchars)
    {
        int count;

        if (0 <= (count = Find(0, 0, endchars)))
            return GetEndCharFound();

        return false;
    }
    /**
     **********************************************************************
     * Function: FindPattern
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
    bool FindPattern
    (const char *pattern,int patternlen=-1, const char *endchars=0)
    {
        int count;

        if (0 <= (count = Find
            (pattern, patternlen, endchars)))
            return GetPatternFound();

        return false;
    }
    /**
     **********************************************************************
     * Function: FindPattern
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
    bool FindPattern
    (cCharStream &scanned, 
     const char *pattern, int patternlen=-1, 
     const char *endchars=0, bool include_endchars=false)
    {
        int count;

        if (0 <= (count = Find
            (&scanned, pattern, patternlen, 
             endchars, include_endchars)))
            return GetPatternFound();

        return false;
    }
    /**
     **********************************************************************
     * Function: FindPatternOrEndChar
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
    bool FindPatternOrEndChar
    (cCharStream &scanned, 
     const char *pattern, int patternlen=-1, 
     const char *endchars=0, bool include_endchars=false)
    {
        int count;

        if (0 <= (count = Find
            (&scanned, pattern, patternlen, 
             endchars, include_endchars)))
            return GetPatternFound() || GetEndCharFound();

        return false;
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
    virtual int Find
    (const char *pattern,int patternlen=-1, const char *endchars=0)
    {
        char c;
        int count;
        int counter = 0;

        m_pattern_found = false;
        m_endchar_found = false;

        if ((count = SetPattern(pattern, patternlen)) < 0)
            return count;

        do 
        {
            if ((count = Get(c)) < 0)
            {
                if (!(m_pattern_found = (-e_ERROR_PATTERN_FOUND == count)))
                    return count;

                counter += m_patternlen;
            }
            else if (count > 0)
            {
                counter++;

                if (endchars)
                if ((m_endchar_found = (0 != strchr(endchars, c))))
                    break;
            }
        }
        while (count > 0);

        return counter;
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
    virtual int Find
    (cCharStream *scanned,
     const char *pattern, int patternlen=-1, 
     const char *endchars=0, bool include_endchars=false)
    {
        char c;
        int count;
        int counter = 0;

        m_pattern_found = false;
        m_endchar_found = false;

        if ((count = SetPattern(pattern, patternlen)) < 0)
            return count;

        do 
        {
            if ((count = Get(c)) < 0)
            {
                if (!(m_pattern_found = (-e_ERROR_PATTERN_FOUND == count)))
                    return count;

                counter += m_patternlen;
            }
            else if (count > 0)
            {
                counter++;

                if (endchars)
                if ((m_endchar_found = (0 != strchr(endchars, c))))
                if (!include_endchars)
                    break;

                if (scanned)
                if ((count = scanned->Put(c)) < 1)
                    return -e_ERROR_STREAM_ERROR;

                if (m_endchar_found)
                    break;
            }
        }
        while (count > 0);

        return counter;
    }
    /**
     **********************************************************************
     * Function: GetPatternFound
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
    inline bool GetPatternFound() const
    {
        return m_pattern_found;
    }
    /**
     **********************************************************************
     * Function: GetEndCharFound
     *
     *   Author: $author$
     *     Date: 8/7/2003
     **********************************************************************
     */
    inline bool GetEndCharFound() const
    {
        return m_endchar_found;
    }
};


#endif
