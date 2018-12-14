/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: chttprequestheaderpath.hxx
 *
 * Author: $author$
 *   Date: 2/5/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPREQUESTHEADERPATH_HXX
#define _CHTTPREQUESTHEADERPATH_HXX

#include "chttpheaderversion.hxx"
#include "ccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequestHeaderPath
 *
 * Author: $author$
 *   Date: 2/5/2006
 **********************************************************************
 */
class cHttpRequestHeaderPath
{
public:
    cCharBuffer m_path;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderPath
     *
     *      Author: $author$
     *        Date: 2/5/2006
     **********************************************************************
     */
    cHttpRequestHeaderPath() 
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/20/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        int count;

        if (0 > (count = m_path.Clear()))
            error = -count;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetPath
     *
     *   Author: $author$
     *     Date: 2/20/2006
     **********************************************************************
     */
    virtual int SetPath
    (const char* chars, int length=-1) 
    {
        int count = m_path.Copy(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetPath
     *
     *   Author: $author$
     *     Date: 2/20/2006
     **********************************************************************
     */
    virtual const char* GetPath(int &length) const
    {
        const char* chars = m_path.GetBuffer(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: Putc
     *
     *   Author: $author$
     *     Date: 2/12/2006
     **********************************************************************
     */
    virtual int Putc(int c) 
    {
        int result = m_path.Putc(c);
        return result;
    }
};

#endif /* _CHTTPREQUESTHEADERPATH_HXX */


