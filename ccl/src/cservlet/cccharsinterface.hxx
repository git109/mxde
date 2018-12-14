/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: cccharsinterface.hxx
 *
 * Author: $author$
 *   Date: 10/29/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CCCHARSINTERFACE_HXX
#define _CCCHARSINTERFACE_HXX

#include "cinterface.hxx"
#include "cchar.hxx"

/**
 **********************************************************************
 *  Class: cCharsInterface
 *
 * Author: $author$
 *   Date: 11/4/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cCharsInterface
{
public:
    /**
     **********************************************************************
     * Function: GetCharsLength
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    static int GetCharsLength(const char *chars) 
    {
        int length;

        for (length=0; *chars; chars++)
            length++;

        return length;
    }
};

/**
 **********************************************************************
 *  Class: cCCharsInterface
 *
 * Author: $author$
 *   Date: 10/29/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cCCharsInterface
{
public:
    /**
     **********************************************************************
     * Function: GetCCharsLength
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    static int GetCCharsLength(const cChar *chars) 
    {
        int length;

        for (length=0; !chars->IsNull(); chars++)
            length++;

        return length;
    }
    /**
     **********************************************************************
     * Function: CompareCChars
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    static int CompareCChars
    (const cChar* chars,  const cChar* tochars,
     int length=-1, int tolength=-1) 
    {
        int cmplength, unequal = 0;

        if (0 > length)
            length = GetCCharsLength(chars);

        if (0 > tolength)
            tolength = GetCCharsLength(tochars);

        if ((cmplength = length) > tolength)
            cmplength = tolength;

        if (!(unequal = CompareNCChars
            (chars, tochars, cmplength)))
        if (length < tolength)
            unequal = -1;
        else if (length > tolength)
                unequal = 1;

        return unequal;
    }
    /**
     **********************************************************************
     * Function: CompareNCChars
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    static int CompareNCChars
    (const cChar* chars,  const cChar* tochars, int length) 
    {
        int unequal;

        for (unequal=0; 0<length; --length, chars++, tochars++)
        {
            if ((*chars) < (*tochars))
                return unequal = -1;

            if ((*chars) > (*tochars))
                return unequal = 1;
        }
        return unequal;
    }
    /**
     **********************************************************************
     * Function: CompareCCharsToChars
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    static int CompareCCharsToChars
    (const cChar* chars,  const char* tochars,
     int length=-1, int tolength=-1) 
    {
        int cmplength, unequal = 0;

        if (0 > length)
            length = GetCCharsLength(chars);

        if (0 > tolength)
            tolength = cCharsInterface::GetCharsLength(tochars);

        if ((cmplength = length) > tolength)
            cmplength = tolength;

        if (!(unequal = CompareNCCharsToChars
            (chars, tochars, cmplength)))
        if (length < tolength)
            unequal = -1;
        else if (length > tolength)
                unequal = 1;

        return unequal;
    }
    /**
     **********************************************************************
     * Function: CompareNCCharsToChars
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    static int CompareNCCharsToChars
    (const cChar* chars,  const char* tochars, int length) 
    {
        int unequal;

        for (unequal=0; 0<length; --length, chars++, tochars++)
        {
            cChar tochar(*tochars);

            if ((*chars) < (tochar))
                return unequal = -1;

            if ((*chars) > (tochar))
                return unequal = 1;
        }
        return unequal;
    }
};

#endif /* _CCCHARSINTERFACE_HXX */
