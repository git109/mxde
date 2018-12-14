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
 *   File: curiinterface.hxx
 *
 * Author: $author$
 *   Date: 10/29/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CURIINTERFACE_HXX
#define _CURIINTERFACE_HXX

#include "cinterface.hxx"
#include "cccharbuffer.hxx"
#include "cccharsinterface.hxx"

/**
 **********************************************************************
 *  Class: cURIInterface
 *
 * Author: $author$
 *   Date: 10/29/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cURIInterface
: virtual public cInterface,
  virtual public cCCharsInterface
{
public:
    /**
     **********************************************************************
     * Function: SetURIChars
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    virtual int SetURIChars
    (const char* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: SetURICChars
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    virtual int SetURICChars
    (const cChar* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetURICChars
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    virtual const cChar* GetURICChars(int &length) const = 0;
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual int Compare
    (const char* chars, int length=-1) const = 0;
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/3/2005
     **********************************************************************
     */
    virtual int Compare
    (const cCCharBuffer& uri) const = 0;
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    virtual int Compare
    (const cURIInterface& uri) const = 0;
};

/**
 **********************************************************************
 *  Class: cURIImplement
 *
 * Author: $author$
 *   Date: 10/29/2005
 **********************************************************************
 */
class cURIImplement
: virtual public cURIInterface
{
public:
    /**
     **********************************************************************
     * Function: SetURIChars
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    virtual int SetURIChars
    (const char* chars, int length=-1) 
    {
        length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: SetURICChars
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    virtual int SetURICChars
    (const cChar* chars, int length=-1) 
    {
        length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: GetURICChars
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    virtual const cChar* GetURICChars(int &length) const 
    {
        const cChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return chars;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    virtual int Compare
    (const char* chars, int length=-1) const
    {
        int unequal = -e_ERROR_NOT_IMPLEMENTED;
        const cChar *uri_chars;
        int uri_length;

        if ((uri_chars = GetURICChars(uri_length)))
            unequal = CompareCCharsToChars
            (uri_chars, chars, uri_length, length);

        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/3/2005
     **********************************************************************
     */
    virtual int Compare
    (const cCCharBuffer& uri) const
    {
        int unequal = -e_ERROR_NOT_IMPLEMENTED;
        const cChar *chars, *tochars;
        int length, tolength;

        if ((tochars = GetURICChars(tolength)))
        if ((chars = uri.GetBuffer(length)))
            unequal = CompareCChars
            (chars, tochars, length, tolength);

        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 10/29/2005
     **********************************************************************
     */
    virtual int Compare
    (const cURIInterface& uri) const
    {
        int unequal = -e_ERROR_NOT_IMPLEMENTED;
        const cChar *chars, *tochars;
        int length, tolength;

        if ((tochars = GetURICChars(tolength)))
        if ((chars = uri.GetURICChars(length)))
            unequal = CompareCChars
            (chars, tochars, length, tolength);

        return unequal;
    }
};

#endif /* _CURIINTERFACE_HXX */
