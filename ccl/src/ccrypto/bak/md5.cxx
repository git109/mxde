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
 *   File: md5.cxx
 *
 * Author: $author$
 *   Date: 1/8/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cmainarg.hxx"
#include "cmain.hxx"
#include "cmd5.hxx"

/**
 **********************************************************************
 *  Class: cMD5Main
 *
 * Author: $author$
 *   Date: 1/8/2005
 **********************************************************************
 */
class cMD5Main
: public cMain
{
public:
    typedef cMain cIs;

    bool m_usage;
    cMD5 m_md5;
    BYTE m_hash[cMD5::e_HASHSIZE];

    /**
     **********************************************************************
     * Constructor: cMD5Main
     *
     *      Author: $author$
     *        Date: 1/8/2005
     **********************************************************************
     */
    cMD5Main()
    : m_usage(false)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
static char *test[]={
	"",
	"a",
	"abc",
	"message digest",
	"abcdefghijklmnopqrstuvwxyz",
	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
	"12345678901234567890123456789012345678901234567890123456789012345678901234567890",
	NULL,
	};

static char *ret[]={
	"d41d8cd98f00b204e9800998ecf8427e",
	"0cc175b9c0f1b6a831c399e269772661",
	"900150983cd24fb0d6963f7d28e17f72",
	"f96b697d7cb7938d525a2f31aaf161d0",
	"c3fcd3d76192e4007dfb496cca67e13b",
	"d174ab98d277d9f5a5611c2c9f419d9f",
	"57edf4a22be3c955ac49da2e2107b67a",
	};

        if (m_usage)
            return OnUsage(argc, argv);

        for (int j=0; test[j]; j++)
        {
        m_md5.Initialize();
        m_md5.Hash((const BYTE*)test[j]);
        m_md5.Finalize(m_hash, sizeof(m_hash));

        for (int i=0; i<sizeof(m_hash); i++)
            printf("%2.2x", m_hash[i]);
        printf("\n");
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 1/8/2005
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
     *     Date: 1/8/2005
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
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual int OnMainArgValue
    (int args, int argn, char *arg, int argc, char **argv)
    {
        if (!strcmp("?", arg))
            m_usage = true;
        return argn;
    }
} g_md5_main;

/**
 **********************************************************************
 *  Class: cMD5MainArg
 *
 * Author: $author$
 *   Date: 1/8/2005
 **********************************************************************
 */
class cMD5MainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cMD5Main &m_main;

    /**
     **********************************************************************
     * Constructor: cMD5MainArg
     *
     *      Author: $author$
     *        Date: 1/8/2005
     **********************************************************************
     */
    cMD5MainArg(cMD5Main &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
    {
    }
};
