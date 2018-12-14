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
 *   File: des.cxx
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
 *  Class: cDESMain
 *
 * Author: $author$
 *   Date: 1/10/2005
 **********************************************************************
 */
class cDESMain
: public cMain
{
public:
    typedef cMain cIs;

    bool m_usage;
    cDES m_des;

    /**
     **********************************************************************
     * Constructor: cDESMain
     *
     *      Author: $author$
     *        Date: 1/10/2005
     **********************************************************************
     */
    cDESMain()
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
static unsigned char cbc_key [8]={
    0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef
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
	0xcc,0xd1,0x73,0xff,0xab,0x20,0x39,0xf4,
	0xac,0xd8,0xae,0xfd,0xdf,0xd8,0xa1,0xeb,
	0x46,0x8e,0x91,0x15,0x78,0x88,0xba,0x68,
	0x1d,0x26,0x93,0x97,0xf7,0xfe,0x62,0xb4
};
static unsigned char cbc_cipher[32];
        int i;

        if (m_usage)
            return OnUsage(argc, argv);

        m_des.Initialize(cbc_key,sizeof(cbc_key),cbc_iv,sizeof(cbc_iv));
        m_des.Encrypt(cbc_cipher, sizeof(cbc_data), cbc_data, strlen((char*)cbc_data)+1);

        for (i=0; i<sizeof(cbc_cipher); i++)
            printf("%2.2X", cbc_cipher[i]);
        printf("\n");

        m_des.Initialize(cbc_key,sizeof(cbc_key),cbc_iv,sizeof(cbc_iv));
        m_des.Decrypt(cbc_cipher, sizeof(cbc_data), cbc_cipher, sizeof(cbc_data));

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
} g_des_main;

/**
 **********************************************************************
 *  Class: cDESMainArg
 *
 * Author: $author$
 *   Date: 1/10/2005
 **********************************************************************
 */
class cDESMainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cDESMain &m_main;

    /**
     **********************************************************************
     * Constructor: cDESMainArg
     *
     *      Author: $author$
     *        Date: 1/10/2005
     **********************************************************************
     */
    cDESMainArg(cDESMain &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
    {
    }
};
