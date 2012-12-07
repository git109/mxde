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
 *   File: casn1objectid.cxx
 *
 * Author: $author$
 *   Date: 3/24/2010
 **********************************************************************
 */
#include "casn1objectid.hxx"
#include "ctypes.hxx"

#include "casn1objectidtable.cxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cUINT32S
 *
 *  Author: $author$
 *    Date: 5/2/2009
 **********************************************************************
 */
typedef cTypesT<UINT32> cUINT32S;

/**
 **********************************************************************
 *  Class: cASN1ObjectID
 *
 * Author: $author$
 *   Date: 3/24/2010
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cASN1ObjectIDCompare
 *
 *   Author: $author$
 *     Date: 3/24/2010
 **********************************************************************
 */
int cASN1ObjectIDCompare
(cASN1ObjectID* id,
 cASN1ObjectID* toId) 
{
    int unequal = 0;
    if (id)
        if (toId)
            unequal = memcmp
            ((void*)(id->Value()), (void*)(toId->Value()), 
             CASN1OBJECTID_VALUE_SIZE*sizeof(UINT32));
        else
        unequal = 1;
    else
    if (toId)
        unequal = -1;
    return unequal;
}/**
 **********************************************************************
 * Function: cASN1ObjectID::Find
 *
 *   Author: $author$
 *     Date: 3/24/2010
 **********************************************************************
 */
const cASN1ObjectID* cASN1ObjectID::Find
(const UINT32 value[], TLENGTH length) 
{
    cASN1ObjectID* oid = 0;
    cASN1ObjectID oidFind;
    TLENGTH count;

    if (0 > length)
    for (length = 0; value[length];)
        length++;

    if (CASN1OBJECTID_VALUE_SIZE < length)
        length = CASN1OBJECTID_VALUE_SIZE;

    for (count = 0; count<length; count++)
        oidFind.m_value[count] = value[count];

    for (; count<CASN1OBJECTID_VALUE_SIZE; count++)
        oidFind.m_value[count] = 0;

    oid = (cASN1ObjectID*)bsearch
    (&oidFind, g_cASN1ObjectID, 
     e_ASN1_OBJECTID_ALL, sizeof(cASN1ObjectID),
     (int(*)(const void *,const void*))cASN1ObjectIDCompare);

    return oid;
}

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */
