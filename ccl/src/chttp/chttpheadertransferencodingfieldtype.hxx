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
 *   File: chttpheadertransferencodingfieldtype.hxx
 *
 * Author: $author$
 *   Date: 2/13/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPHEADERTRANSFERENCODINGFIELDTYPE_HXX
#define _CHTTPHEADERTRANSFERENCODINGFIELDTYPE_HXX

#include "cnamedenumt.hxx"

/**
 **********************************************************************
 *  Class: cHttpHeaderTransferEncodingFieldType
 *
 * Author: $author$
 *   Date: 2/13/2006
 **********************************************************************
 */
class cHttpHeaderTransferEncodingFieldType
: public cCharNamedEnumValueT
  <int, cHttpHeaderTransferEncodingFieldType>
{
public:
    typedef cCharNamedEnumValueT
    <int, cHttpHeaderTransferEncodingFieldType> cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 10/25/2004
     **********************************************************************
     */
    enum
    {
        e_FIRST,
        e_NONE = e_FIRST,

        e_TRANSFER_ENCODING_NONE = e_NONE,
        e_TRANSFER_ENCODING_CHUNKED,

        e_NEXT,
        e_LAST=e_NEXT-1
    };

    /**
     **********************************************************************
     * Constructor: cHttpHeaderTransferEncodingFieldType
     *
     *      Author: $author$
     *        Date: 2/13/2006
     **********************************************************************
     */
    cHttpHeaderTransferEncodingFieldType
    (int value=e_TRANSFER_ENCODING_NONE) 
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
            "chunked"
        };
        return names;
    }
};

#endif /* _CHTTPHEADERTRANSFERENCODINGFIELDTYPE_HXX */


