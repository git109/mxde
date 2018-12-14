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
 *   File: csslcompressionmethod.cxx
 *
 * Author: $author$
 *   Date: 1/14/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "csslcompressionmethod.hxx"

/**
 **********************************************************************
 *  Class: cSSLCompressionMethod
 *
 * Author: $author$
 *   Date: 1/14/2005
 **********************************************************************
 */

const char *cSSLCompressionMethod::m_names[e_ALL] =
{
    "NULL",
};

const cSSLCompressionMethod cSSLCompressionMethod::m_methods[e_ALL] =
{
  cSSLCompressionMethod(0x00, e_NULL)                 
};

/**
 **********************************************************************
 * Function: cSSLCompressionMethod::GetMethodByCode
 *
 *   Author: $author$
 *     Date: 1/14/2005
 **********************************************************************
 */
int cSSLCompressionMethod::GetMethodByCode(uint8 code) 
{
    int min = e_FIRST;
    int max = e_LAST;
    int method = (min+max)/2;
    uint16 code2;

    while (code != (code2 = m_methods[method].GetCode()))
    {
        if (code > code2)
        {
            if ((min = method+1) > max)
                return e_NONE;
        }
        else if ((max = method-1) < min)
                return e_NONE;

        method = (min+max)/2;
    }
    return method;
}
/**
 **********************************************************************
 * Function: cSSLCompressionMethod::GetCodeByMethod
 *
 *   Author: $author$
 *     Date: 1/14/2005
 **********************************************************************
 */
uint8 cSSLCompressionMethod::GetCodeByMethod(int method) 
{
    uint8 code = -1;

    if ((method >= e_FIRST) && (method <= e_LAST))
        code = m_methods[method].GetCode();
    return code;
}
