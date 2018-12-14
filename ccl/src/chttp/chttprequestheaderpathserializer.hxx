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
 *   File: chttprequestheaderpathserializer.hxx
 *
 * Author: $author$
 *   Date: 2/5/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPREQUESTHEADERPATHSERIALIZER_HXX
#define _CHTTPREQUESTHEADERPATHSERIALIZER_HXX

#include "chttpnameserializer.hxx"
#include "chttprequestheaderpath.hxx"
#include "chttpheaderversion.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequestHeaderPathSerializer
 *
 * Author: $author$
 *   Date: 2/5/2006
 **********************************************************************
 */
class cHttpRequestHeaderPathSerializer
: public cHttpNameSerializer
{
public:
    typedef cHttpNameSerializer cIs;

    const cHttpRequestHeaderPath& m_path;


    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderPathSerializer
     *
     *      Author: $author$
     *        Date: 2/5/2006
     **********************************************************************
     */
    cHttpRequestHeaderPathSerializer
    (const cHttpRequestHeaderPath& path)
    : m_path(path) 
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_FAILED;

        if ((m_chars = m_path.GetPath(m_charslen)))
        {
            m_charspos = 0;
            error = e_ERROR_NONE;
        }
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestHeaderPathDeserializer
 *
 * Author: $author$
 *   Date: 2/5/2006
 **********************************************************************
 */
class cHttpRequestHeaderPathDeserializer
: public cHttpDeserializer
{
public:
    typedef cHttpDeserializer cIs;

    cHttpRequestHeaderPath& m_path;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderPathDeserializer
     *
     *      Author: $author$
     *        Date: 2/5/2006
     **********************************************************************
     */
    cHttpRequestHeaderPathDeserializer
    (cHttpRequestHeaderPath& path)
    : m_path(path)
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/12/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = m_path.Initialize();
        return error;
    }
    /**
     **********************************************************************
     * Function: Putb
     *
     *   Author: $author$
     *     Date: 2/12/2006
     **********************************************************************
     */
    virtual int Putb(BYTE b) 
    {
        int result = b;

        switch(b)
        {
        case ' ':
            m_done = true;
            break;

        default:
            result = m_path.Putc(b);
        }
        return result;
    }
};

#endif /* _CHTTPREQUESTHEADERPATHSERIALIZER_HXX */


