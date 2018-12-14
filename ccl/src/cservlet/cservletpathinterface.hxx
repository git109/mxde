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
 *   File: cservletpathinterface.hxx
 *
 * Author: $author$
 *   Date: 11/23/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSERVLETPATHINTERFACE_HXX
#define _CSERVLETPATHINTERFACE_HXX

#include "ccharreaderinterface.hxx"

/**
 **********************************************************************
 *  Class: cServletPathInterface
 *
 * Author: $author$
 *   Date: 11/23/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cServletPathInterface
{
public:
    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 11/23/2004
     **********************************************************************
     */
    enum
    {
        e_FIRST_TYPE,

        e_TYPE_NONE = e_FIRST_TYPE,
        e_TYPE_FILE,
        e_TYPE_LOCATION,
        e_TYPE_SERVLET,

        e_NEXT_TYPE,
        e_LAST_TYPE=e_NEXT_TYPE-1
    };

    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int SetType(int type) = 0;
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int GetType() const = 0;

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual cCharReaderInterface* Open
    (eError &error, const char *path=0, int pathlen=-1) = 0;
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual eError Close() = 0;
};

/**
 **********************************************************************
 *  Class: cServletPathImplement
 *
 * Author: $author$
 *   Date: 11/23/2004
 **********************************************************************
 */
class cServletPathImplement
: virtual public cServletPathInterface
{
public:
    int m_type;

    /**
     **********************************************************************
     * Constructor: cServletPathImplement
     *
     *      Author: $author$
     *        Date: 11/23/2004
     **********************************************************************
     */
    cServletPathImplement(int type=e_TYPE_NONE)
    : m_type(type) 
    {
    }
    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int SetType(int type) 
    {
        m_type = type;
        return m_type;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual int GetType() const
    {
        return m_type;
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual cCharReaderInterface* Open
    (eError &error, const char *path=0, int pathlen=-1) 
    {
        cCharReaderInterface* reader = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return reader;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual eError Close() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

#endif /* ndef _CSERVLETPATHINTERFACE_HXX */
