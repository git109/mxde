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
 *   File: curi.hxx
 *
 * Author: $author$
 *   Date: 10/29/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CURI_HXX
#define _CURI_HXX

#include "curiinterface.hxx"
#include "cinstance.hxx"
#include "cccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cURI
 *
 * Author: $author$
 *   Date: 10/29/2005
 **********************************************************************
 */
class cURI
: virtual public cURIImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    cCCharBuffer m_uri_buffer;

    /**
     **********************************************************************
     * Constructor: cURI
     *
     *      Author: $author$
     *        Date: 10/29/2005
     **********************************************************************
     */
    cURI
    (const cChar* chars=0, int length=-1) 
    {
        eError error;

        if (chars)
        if (0 > (length = SetURICChars(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cURI
     *
     *      Author: $author$
     *        Date: 10/29/2005
     **********************************************************************
     */
    cURI
    (const char* chars, int length=-1) 
    {
        eError error;

        if (chars)
        if (0 > (length = SetURIChars(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     *  Destructor: ~cURI
     *
     *      Author: $author$
     *        Date: 10/29/2005
     **********************************************************************
     */
    virtual ~cURI()
    {
    }

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
        length = m_uri_buffer.Copyc(chars, length);
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
        length = m_uri_buffer.Copy(chars, length);
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
        const cChar* chars = m_uri_buffer.GetBuffer(length);
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
    virtual int Compare(const char* chars, int length=-1) const
    {
        int unequal = m_uri_buffer.Comparec(chars, length);
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
        int unequal = m_uri_buffer.Compare(uri);
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
        int unequal = cURIImplement::Compare(uri);
        return unequal;
    }
};

#endif /* _CURI_HXX */
