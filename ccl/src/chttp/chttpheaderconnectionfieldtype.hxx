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
 *   File: chttpheaderconnectionfieldtype.hxx
 *
 * Author: $author$
 *   Date: 2/13/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPHEADERCONNECTIONFIELDTYPE_HXX
#define _CHTTPHEADERCONNECTIONFIELDTYPE_HXX

#include "cnamedenumt.hxx"

/**
 **********************************************************************
 *  Class: cHttpHeaderConnectionFieldType
 *
 * Author: $author$
 *   Date: 2/13/2006
 **********************************************************************
 */
class cHttpHeaderConnectionFieldType
: public cCharNamedEnumValueT
  <int, cHttpHeaderConnectionFieldType>
{
public:
    typedef cCharNamedEnumValueT
    <int, cHttpHeaderConnectionFieldType> cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 2/13/2006
     **********************************************************************
     */
    enum
    {
        e_FIRST,
        e_NONE = e_FIRST,

        e_CONNECTION_NONE = e_NONE,
        e_CONNECTION_KEEP_ALIVE,
        e_CONNECTION_CLOSE,
        e_CONNECTION_HOST,

        e_NEXT,
        e_LAST=e_NEXT-1
    };

    /**
     **********************************************************************
     * Constructor: cHttpHeaderConnectionFieldType
     *
     *      Author: $author$
     *        Date: 2/13/2006
     **********************************************************************
     */
    cHttpHeaderConnectionFieldType(int value=e_CONNECTION_NONE) 
    : cIs(value) 
    {
    }
    /**
     **********************************************************************
     * Function: GetNames
     *
     *   Author: $author$
     *     Date: 2/13/2006
     **********************************************************************
     */
    static const char** GetNames() 
    {
        static const char *names[e_NEXT]={
            "",
            "Keep-Alive",
            "close",
            "Host"
        };
        return names;
    }
};

#endif /* _CHTTPHEADERCONNECTIONFIELDTYPE_HXX */


