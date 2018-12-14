/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: casn1classof.hxx
 *
 * Author: $author$
 *   Date: 1/26/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CASN1CLASSOF_HXX
#define _CASN1CLASSOF_HXX

#include "platform.h"
#include "cbytestream.hxx"


/**
 **********************************************************************
 *  Class: cASN1Classof
 *
 * Author: $author$
 *   Date: 1/26/2005
 **********************************************************************
 */
class cASN1Classof
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/26/2005
     **********************************************************************
     */
    enum
    {
        e_Bit         = 6,

        e_Universal   = 0,
        e_Application = 1 << e_Bit,
        e_Context     = 2 << e_Bit,
        e_Private     = 3 << e_Bit,

        e_Mask        = 3 << e_Bit
    };

    unsigned m_value;
    const char *m_name;

    /**
     **********************************************************************
     * Constructor: cASN1Classof
     *
     *      Author: $author$
     *        Date: 1/26/2005
     **********************************************************************
     */
    cASN1Classof(unsigned value=e_Universal)
    : m_value(value) 
    {
        m_name = GetName();
    }
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    unsigned SetValue(unsigned value)
    {
        m_value = value;
        m_name = GetName();
        return m_value;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    unsigned GetValue() const
    {
        return m_value;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    const char *GetName() const 
    {
        switch(m_value)
        {
        case e_Universal:
            return "Universal";

        case e_Application:
            return "Application";

        case e_Context:
            return "Context";

        case e_Private:
            return "Private";
        }
        return "undefined";
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    int operator != (const cASN1Classof &classof) const
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CASN1CLASSOF_HXX */
