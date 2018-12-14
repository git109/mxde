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
 *   File: sha1.cxx
 *
 * Author: $author$
 *   Date: 1/8/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cmainarg.hxx"
#include "cmain.hxx"
#include "csha1.hxx"

/**
 **********************************************************************
 *  Class: cSHA1Main
 *
 * Author: $author$
 *   Date: 1/8/2005
 **********************************************************************
 */
class cSHA1Main
: public cMain
{
public:
    typedef cMain cIs;

    bool m_usage;
    cSHA1 m_sha1;
    BYTE m_hash[cSHA1::e_HASHSIZE];

    /**
     **********************************************************************
     * Constructor: cSHA1Main
     *
     *      Author: $author$
     *        Date: 1/8/2005
     **********************************************************************
     */
    cSHA1Main()
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
	"abc",
	"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
	NULL,
	};
static char *ret[]={
	"a9993e364706816aba3e25717850c26c9cd0d89d",
	"84983e441c3bd26ebaae4aa1f95129e5e54670f1",
	};
        if (m_usage)
            return OnUsage(argc, argv);

        for (int j=0; test[j]; j++)
        {
        m_sha1.Initialize();
        m_sha1.Hash((const BYTE*)test[j]);
        m_sha1.Finalize(m_hash, sizeof(m_hash));
        DumpHash();
        }
        return 0;
    }
    void DumpHash()
    {
        for (int i=0; i<sizeof(m_hash); i++)
            printf("%2.2X", m_hash[i]);
        printf("\n");
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
} g_sha1_main;

/**
 **********************************************************************
 *  Class: cSHA1MainArg
 *
 * Author: $author$
 *   Date: 1/8/2005
 **********************************************************************
 */
class cSHA1MainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cSHA1Main &m_main;

    /**
     **********************************************************************
     * Constructor: cSHA1MainArg
     *
     *      Author: $author$
     *        Date: 1/8/2005
     **********************************************************************
     */
    cSHA1MainArg(cSHA1Main &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
    {
    }
};
