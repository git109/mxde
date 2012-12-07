/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: casn1.h
 *
 * Author: $author$
 *   Date: 3/19/2010
 **********************************************************************
 */
#ifndef _CASN1_H
#define _CASN1_H

#include "cplatform.h"

/**
 **********************************************************************
 *   Enum: eASN1Class
 *
 * Author: $author$
 *   Date: 3/19/2010
 **********************************************************************
 */
typedef int eASN1Class;
enum
{
    e_ASN1_CLASS_Bit         = (6),

    e_ASN1_CLASS_Undefined   = (-1),
    e_ASN1_CLASS_Universal   = (0),
    e_ASN1_CLASS_Application = (1 << e_ASN1_CLASS_Bit),
    e_ASN1_CLASS_Context     = (2 << e_ASN1_CLASS_Bit),
    e_ASN1_CLASS_Private     = (3 << e_ASN1_CLASS_Bit),

    e_ASN1_CLASS_Mask        = (3 << e_ASN1_CLASS_Bit)
};

/**
 **********************************************************************
 *   Enum: eASN1Form
 *
 * Author: $author$
 *   Date: 3/19/2010
 **********************************************************************
 */
typedef int eASN1Form;
enum
{
    e_ASN1_FORM_Bit       = (5),

    e_ASN1_FORM_Undefined = (-1),
    e_ASN1_FORM_Primative = (0),
    e_ASN1_FORM_Construct = (1 << e_ASN1_FORM_Bit),

    e_ASN1_FORM_Mask      = (1 << e_ASN1_FORM_Bit)
};

/**
 **********************************************************************
 *   Enum: eASN1Type
 *
 * Author: $author$
 *   Date: 3/19/2010
 **********************************************************************
 */
typedef int eASN1Type;
enum
{
    e_ASN1_TYPE_Bit             = (0),

    e_ASN1_TYPE_Undefined       = (-1),
    e_ASN1_TYPE_Any             = (0),
    e_ASN1_TYPE_Boolean         = (1),
    e_ASN1_TYPE_Integer         = (2),
    e_ASN1_TYPE_BitString       = (3),
    e_ASN1_TYPE_OctetString     = (4),
    e_ASN1_TYPE_Null            = (5),
    e_ASN1_TYPE_ObjectID        = (6),
    e_ASN1_TYPE_Object          = (7),
    e_ASN1_TYPE_External        = (8),
    e_ASN1_TYPE_Real            = (9),
    e_ASN1_TYPE_Enum            = (10),
    e_ASN1_TYPE_Sequence        = (16),
    e_ASN1_TYPE_Set             = (17),
    e_ASN1_TYPE_NumericString   = (18),
    e_ASN1_TYPE_PrintableString = (19),
    e_ASN1_TYPE_TeletexString   = (20),
    e_ASN1_TYPE_VideotexString  = (21),
    e_ASN1_TYPE_IA5String       = (22),
    e_ASN1_TYPE_UTCTime         = (23),
    e_ASN1_TYPE_GeneralizedTime = (24),
    e_ASN1_TYPE_GraphicString   = (25),
    e_ASN1_TYPE_VisibleString   = (26),
    e_ASN1_TYPE_GeneralString   = (27),

    e_ASN1_TYPE_Mask            = (31)
};

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CASN1_H */
