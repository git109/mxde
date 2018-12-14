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
 *   File: des3.cxx
 *
 * Author: $author$
 *   Date: 1/10/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cmainarg.hxx"
#include "cmain.hxx"
#include "cdes.hxx"

/**
 **********************************************************************
 *  Class: c3DESMain
 *
 * Author: $author$
 *   Date: 1/10/2005
 **********************************************************************
 */
class c3DESMain
: public cMain
{
public:
    typedef cMain cIs;

    bool m_usage;
    c3DES m_3des;

    /**
     **********************************************************************
     * Constructor: c3DESMain
     *
     *      Author: $author$
     *        Date: 1/10/2005
     **********************************************************************
     */
    c3DESMain()
    : m_usage(false)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 1/10/2005
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
static unsigned char cbc_key [8*3]={
    0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,
    0xf1,0xe0,0xd3,0xc2,0xb5,0xa4,0x97,0x86,
    0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10
};
static unsigned char cbc_iv  [8]={
    0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10
};
static unsigned char cbc_data[32]={
	0x37,0x36,0x35,0x34,0x33,0x32,0x31,0x20,
	0x4E,0x6F,0x77,0x20,0x69,0x73,0x20,0x74,
	0x68,0x65,0x20,0x74,0x69,0x6D,0x65,0x20,
	0x66,0x6F,0x72,0x20,0x00,0x31,0x00,0x00
};
static unsigned char cbc_ok[32]={
	0x3F,0xE3,0x01,0xC9,0x62,0xAC,0x01,0xD0,
	0x22,0x13,0x76,0x3C,0x1C,0xBD,0x4C,0xDC,
	0x79,0x96,0x57,0xC0,0x64,0xEC,0xF5,0xD4,
	0x1C,0x67,0x38,0x12,0xCF,0xDE,0x96,0x75
};
static unsigned char cbc_cipher[32];
        int i;

        if (m_usage)
            return OnUsage(argc, argv);

        m_3des.Initialize(cbc_key,sizeof(cbc_key),cbc_iv,sizeof(cbc_iv));
        m_3des.Encrypt(cbc_cipher, sizeof(cbc_data), cbc_data, strlen((char*)cbc_data)+1);

        for (i=0; i<sizeof(cbc_cipher); i++)
            printf("%2.2X", cbc_cipher[i]);
        printf("\n");

        m_3des.Initialize(cbc_key,sizeof(cbc_key),cbc_iv,sizeof(cbc_iv));
        m_3des.Decrypt(cbc_cipher, sizeof(cbc_data), cbc_cipher, sizeof(cbc_data));

        for (i=0; i<sizeof(cbc_cipher); i++)
            printf("%2.2X", cbc_cipher[i]);
        printf("\n");

        return 0;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 1/10/2005
     **********************************************************************
     */
    virtual int OnUsage(int argc, char **argv)
    {
        int result=0;
        cMainArg *a;

        printf("usage: %s", argv[0]);

        if ((a = cMainArg::m_list.GetFirst()))
        do
        {
            a->OnUsage();
        }
        while ((a = a->GetNext()));

        printf("\n");
        return result;
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 1/10/2005
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, char *arg, int argc, char **argv)
    {
        cMainArg *a;

        if ((a = cMainArg::m_list.FindFirstByName(arg)))
            return a->OnMainArgSwitch
            (args, argn, arg, argc, argv);

        return argn;
    }
    /**
     **********************************************************************
     * Function: OnMainArgValue
     *
     *   Author: $author$
     *     Date: 1/10/2005
     **********************************************************************
     */
    virtual int OnMainArgValue
    (int args, int argn, char *arg, int argc, char **argv)
    {
        if (!strcmp("?", arg))
            m_usage = true;
        return argn;
    }
} g_3des_main;

/**
 **********************************************************************
 *  Class: c3DESMainArg
 *
 * Author: $author$
 *   Date: 1/10/2005
 **********************************************************************
 */
class c3DESMainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    c3DESMain &m_main;

    /**
     **********************************************************************
     * Constructor: c3DESMainArg
     *
     *      Author: $author$
     *        Date: 1/10/2005
     **********************************************************************
     */
    c3DESMainArg(c3DESMain &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
    {
    }
};
