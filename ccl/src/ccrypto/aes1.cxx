/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: aes.cxx
 *
 * Author: $author$
 *   Date: 11/4/2007
 *
 **********************************************************************
 */

#include "cmain.hxx"
#include "caes.hxx"

/**
 **********************************************************************
 *  Class: cAESMain
 *
 * Author: $author$
 *   Date: 11/4/2007
 **********************************************************************
 */
class cAESMain
: public cMain
{
public:
    typedef cMain cIs, cExtends;
    typedef cAESMain cAs, cDerives;

    cAES m_aes;
    unsigned char cbc_cipher[8*2];

    /**
     **********************************************************************
     * Constructor: cAESMain
     *
     *      Author: $author$
     *        Date: 11/4/2007
     **********************************************************************
     */
    cAESMain()
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 11/4/2007
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
static unsigned char cbc_key [8*2]={
    0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,
    0xf1,0xe0,0xd3,0xc2,0xb5,0xa4,0x97,0x86/*,
    0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10*/
};
static unsigned char cbc_iv  [8*2]={
    0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10,
    0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef
};
static unsigned char cbc_data[8*2]={
	0x37,0x36,0x35,0x34,0x33,0x32,0x31,0x20,
	0x4E,0x6F,0x77,0x20,0x69,0x73,0x20,0x74/*,
	0x68,0x65,0x20,0x74,0x69,0x6D,0x65,0x20,
	0x66,0x6F,0x72,0x20,0x00,0x31,0x00,0x00*/
};

        memcpy(cbc_cipher, cbc_data, sizeof(cbc_data));
        DumpCipher();

        m_aes.Initialize(cbc_key,sizeof(cbc_key),cbc_iv,sizeof(cbc_iv));
        m_aes.Encrypt(cbc_cipher, sizeof(cbc_data), cbc_data, sizeof(cbc_data));

        DumpCipher();

        m_aes.Initialize(cbc_key,sizeof(cbc_key),cbc_iv,sizeof(cbc_iv));
        m_aes.Decrypt(cbc_cipher, sizeof(cbc_data), cbc_cipher, sizeof(cbc_data));

        DumpCipher();
        return 0;
    }
    void DumpCipher()
    {
        for (int i=0; i<sizeof(cbc_cipher); i++)
            printf("%2.2X", cbc_cipher[i]);
        printf("\n");
    }
} g_aes_main;
