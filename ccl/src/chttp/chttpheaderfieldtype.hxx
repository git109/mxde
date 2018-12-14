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
 *   File: chttpheaderfieldtype.hxx
 *
 * Author: $author$
 *   Date: 2/13/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPHEADERFIELDTYPE_HXX
#define _CHTTPHEADERFIELDTYPE_HXX

#include "cnamedenumt.hxx"

/**
 **********************************************************************
 *  Class: cHttpHeaderFieldType
 *
 * Author: $author$
 *   Date: 2/13/2006
 **********************************************************************
 */
class cHttpHeaderFieldType
: public cCharNamedEnumValueT
  <int, cHttpHeaderFieldType>
{
public:
    typedef cCharNamedEnumValueT
    <int, cHttpHeaderFieldType> cIs;

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

        e_FIELD_NONE = e_NONE,
        e_FIELD_CONNECTION,
        e_FIELD_CONTENT_TYPE,
        e_FIELD_CONTENT_LENGTH,
        e_FIELD_FROM,
        e_FIELD_HOST,
        e_FIELD_ACCEPT,
        e_FIELD_TRANSFER_ENCODING,
        e_FIELD_QUERY_STRING,

        e_NEXT,
        e_LAST=e_NEXT-1
    };

    /**
     **********************************************************************
     * Constructor: cHttpHeaderFieldType
     *
     *      Author: $author$
     *        Date: 2/13/2006
     **********************************************************************
     */
    cHttpHeaderFieldType(int value=e_FIELD_NONE)
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
    static const char **GetNames()
    {
        static const char *name[e_NEXT]={
            "",
            "Connection",
            "Content-Type",
            "Content-Length",
            "From",
            "Host",
            "Accept",
            "Transfer-Encoding",
            "Query-String"
        };
        return name;
    }
};

#endif /* _CHTTPHEADERFIELDTYPE_HXX */


