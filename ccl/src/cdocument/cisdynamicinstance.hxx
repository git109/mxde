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
 *   File: cisdynamicinstance.hxx
 *
 * Author: $author$
 *   Date: 10/20/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CISDYNAMICINSTANCE_HXX
#define _CISDYNAMICINSTANCE_HXX

#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cIsDynamicInstanceT
 *
 * Author: $author$
 *   Date: 10/20/2005
 **********************************************************************
 */
template
<class TIs=cInstance>
class cIsDynamicInstanceT
: public TIs
{
public:
    typedef TIs cIs;

    bool m_is_dynamic;

    /**
     **********************************************************************
     * Constructor: cIsDynamicInstanceT
     *
     *      Author: $author$
     *        Date: 10/20/2005
     **********************************************************************
     */
    cIsDynamicInstanceT(bool is_dynamic=false)
    : m_is_dynamic(is_dynamic) 
    {
    }
    /**
     **********************************************************************
     * Function: SetIsDynamic
     *
     *   Author: $author$
     *     Date: 10/20/2005
     **********************************************************************
     */
    virtual int SetIsDynamic(bool is=true) 
    {
        m_is_dynamic = is;
        return m_is_dynamic;
    }
    /**
     **********************************************************************
     * Function: GetIsDynamic
     *
     *   Author: $author$
     *     Date: 10/20/2005
     **********************************************************************
     */
    virtual int GetIsDynamic() const
    {
        return m_is_dynamic;
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 10/20/2005
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        eError error = e_ERROR_NOT_ALLOWED;
        int is_dynamic;

        if (0 < (is_dynamic = GetIsDynamic()))
        {
            delete this;
            error = e_ERROR_NONE;
        }
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cIsDynamicInstance
 *
 * Author: $author$
 *   Date: 10/20/2005
 **********************************************************************
 */
class cIsDynamicInstance
: public cIsDynamicInstanceT<>
{
public:
    typedef cIsDynamicInstanceT<> cIs;

    /**
     **********************************************************************
     * Constructor: cIsDynamicInstance
     *
     *      Author: $author$
     *        Date: 10/20/2005
     **********************************************************************
     */
    cIsDynamicInstance(bool is_dynamic=false)
    : cIs(is_dynamic)
    {
    }
};

#endif /* _CISDYNAMICINSTANCE_HXX */
