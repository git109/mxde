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
 *   File: rc4.cxx
 *
 * Author: $author$
 *   Date: 1/11/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cmainarg.hxx"
#include "cmain.hxx"
#include "crc4.hxx"

/**
 **********************************************************************
 *  Class: cRC4Main
 *
 * Author: $author$
 *   Date: 1/11/2005
 **********************************************************************
 */
class cRC4Main
: public cMain
{
public:
    typedef cMain cIs;

    bool m_usage;
    cRC4 m_rc4;

    BYTE cipher[8];
    BYTE plain[8];

    /**
     **********************************************************************
     * Constructor: cRC4Main
     *
     *      Author: $author$
     *        Date: 1/11/2005
     **********************************************************************
     */
    cRC4Main()
    : m_usage(false)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 1/11/2005
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
static BYTE key[]={
        0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef
	};

static unsigned char data[]={
        0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef
	};

static unsigned char output[]={
        0x75,0xb7,0x87,0x80,0x99,0xe0,0xc5,0x96
	};

        if (m_usage)
            return OnUsage(argc, argv);

        memcpy(cipher, data, sizeof(data));
        memcpy(plain, cipher, sizeof(data));
        DumpCipher();

        m_rc4.Initialize(key, sizeof(key));
        m_rc4.Encrypt(cipher, sizeof(output), plain, sizeof(data));

        DumpCipher();
        memcpy(plain, cipher, sizeof(data));

        m_rc4.Initialize(key, sizeof(key));
        m_rc4.Decrypt(cipher, sizeof(output), plain, sizeof(data));

        DumpCipher();
        return 0;
    }
    void DumpCipher()
    {
        for (int j=0; j<sizeof(cipher); j++)
            printf("%2.2X", cipher[j]);
        printf("\n");
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 1/11/2005
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
     *     Date: 1/11/2005
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
     *     Date: 1/11/2005
     **********************************************************************
     */
    virtual int OnMainArgValue
    (int args, int argn, char *arg, int argc, char **argv)
    {
        if (!strcmp("?", arg))
            m_usage = true;
        return argn;
    }
} g_rc4_main;

/**
 **********************************************************************
 *  Class: cRC4MainArg
 *
 * Author: $author$
 *   Date: 1/11/2005
 **********************************************************************
 */
class cRC4MainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cRC4Main &m_main;

    /**
     **********************************************************************
     * Constructor: cRC4MainArg
     *
     *      Author: $author$
     *        Date: 1/11/2005
     **********************************************************************
     */
    cRC4MainArg(cRC4Main &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
    {
    }
};
