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
 *   File: csslciphersuite.cxx
 *
 * Author: $author$
 *   Date: 1/14/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "csslciphersuite.hxx"

/**
 **********************************************************************
 *  Class: cSSLCipherSuite
 *
 * Author: $author$
 *   Date: 1/14/2005
 **********************************************************************
 */

const char *cSSLCipherSuite::m_names[e_ALL]=
{
    "NULL",
    "RSA_MD5",
    "RSA_SHA1",
    "RSA_EXPORT_RC4_40_MD5",
    "RSA_RC4_128_MD5",
    "RSA_RC4_128_SHA1",
    "RSA_EXPORT_RC2_40_MD5",
    "RSA_IDEA_SHA1",
    "RSA_EXPORT_DES_40_SHA1",
    "RSA_DES_SHA1",
    "RSA_3DES_SHA1",
    "DH_DSS_EXPORT_DES40_SHA1",
    "DH_DSS_DES_SHA1",
    "DH_DSS_3DES_SHA1",
    "DH_RSA_EXPORT_DES40_SHA1",
    "DH_RSA_DES_SHA1",
    "DH_RSA_3DES_SHA1",
    "DHE_DSS_EXPORT_DES40_SHA1",
    "DHE_DSS_DES_SHA1",
    "DHE_DSS_3DES_SHA1",
    "DHE_RSA_EXPORT_DES40_SHA1",
    "DHE_RSA_DES_SHA1",
    "DHE_RSA_3DES_SHA1",
    "DH_ANON_EXPORT_RC4_40_MD5",
    "DH_ANON_RC4_128_MD5",
    "DH_ANON_EXPORT_DES40_SHA1",
    "DH_ANON_DES_SHA1",
    "DH_ANON_3DES_SHA1",
    "FORTEZZA_KEA_SHA1",
    "FORTEZZA_KEA_FORTEZZA_SHA1",
    "FORTEZZA_KEA_RC4_128_SHA1"
};

const cSSLCipherSuite cSSLCipherSuite::m_suites[e_ALL]=
{
  cSSLCipherSuite(0x0000, e_NULL),
  cSSLCipherSuite(0x0001, e_RSA_MD5),                 
  cSSLCipherSuite(0x0002, e_RSA_SHA1),                 
  cSSLCipherSuite(0x0003, e_RSA_EXPORT_RC4_40_MD5),   
  cSSLCipherSuite(0x0004, e_RSA_RC4_128_MD5),         
  cSSLCipherSuite(0x0005, e_RSA_RC4_128_SHA1),         
  cSSLCipherSuite(0x0006, e_RSA_EXPORT_RC2_40_MD5),   
  cSSLCipherSuite(0x0007, e_RSA_IDEA_SHA1),            
  cSSLCipherSuite(0x0008, e_RSA_EXPORT_DES_40_SHA1),   
  cSSLCipherSuite(0x0009, e_RSA_DES_SHA1),             
  cSSLCipherSuite(0x000A, e_RSA_3DES_SHA1),            
  cSSLCipherSuite(0x000B, e_DH_DSS_EXPORT_DES40_SHA1),
  cSSLCipherSuite(0x000C, e_DH_DSS_DES_SHA1), 
  cSSLCipherSuite(0x000D, e_DH_DSS_3DES_SHA1),
  cSSLCipherSuite(0x000E, e_DH_RSA_EXPORT_DES40_SHA1),
  cSSLCipherSuite(0x000F, e_DH_RSA_DES_SHA1), 
  cSSLCipherSuite(0x0010, e_DH_RSA_3DES_SHA1), 
  cSSLCipherSuite(0x0011, e_DHE_DSS_EXPORT_DES40_SHA1),
  cSSLCipherSuite(0x0012, e_DHE_DSS_DES_SHA1),
  cSSLCipherSuite(0x0013, e_DHE_DSS_3DES_SHA1),
  cSSLCipherSuite(0x0014, e_DHE_RSA_EXPORT_DES40_SHA1),
  cSSLCipherSuite(0x0015, e_DHE_RSA_DES_SHA1),
  cSSLCipherSuite(0x0016, e_DHE_RSA_3DES_SHA1),
  cSSLCipherSuite(0x0017, e_DH_ANON_EXPORT_RC4_40_MD5),
  cSSLCipherSuite(0x0018, e_DH_ANON_RC4_128_MD5),
  cSSLCipherSuite(0x0019, e_DH_ANON_EXPORT_DES40_SHA1),
  cSSLCipherSuite(0x001A, e_DH_ANON_DES_SHA1),
  cSSLCipherSuite(0x001B, e_DH_ANON_3DES_SHA1),
  cSSLCipherSuite(0x001C, e_FORTEZZA_KEA_SHA1),
  cSSLCipherSuite(0x001D, e_FORTEZZA_KEA_FORTEZZA_SHA1),
  cSSLCipherSuite(0x001E, e_FORTEZZA_KEA_RC4_128_SHA1) 
};

/**
 **********************************************************************
 * Function: cSSLCipherSuite::GetSuiteByCode
 *
 *   Author: $author$
 *     Date: 1/14/2005
 **********************************************************************
 */
int cSSLCipherSuite::GetSuiteByCode(uint16 code) 
{
    int min = e_FIRST;
    int max = e_LAST;
    int suite = (min+max)/2;
    uint16 code2;

    while (code != (code2 = m_suites[suite].GetCode()))
    {
        if (code > code2)
        {
            if ((min = suite+1) > max)
                return e_NONE;
        }
        else if ((max = suite-1) < min)
                return e_NONE;

        suite = (min+max)/2;
    }
    return suite;
}
/**
 **********************************************************************
 * Function: cSSLCipherSuite::GetCodeBySuite
 *
 *   Author: $author$
 *     Date: 1/14/2005
 **********************************************************************
 */
uint16 cSSLCipherSuite::GetCodeBySuite(int suite) 
{
    uint16 code = -1;

    if ((suite >= e_FIRST) && (suite <= e_LAST))
        code = m_suites[suite].GetCode();
    return code;
}
