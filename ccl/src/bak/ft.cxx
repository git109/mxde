/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: ft.cxx
 *
 * Author: $author$
 *   Date: 4/20/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "cfileentry.hxx"
#include "cfileentryimplement.hxx"
#include "cfileentryinterface.hxx"
#include "ctimeimplement.hxx"
#include "ctimeinterface.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Main: cFTMain
 *
 * Author: $author$
 *   Date: 4/20/2004
 **********************************************************************
 */
class cFTMain
: public cMain
{
public:
    typedef cMain cIs;

    const char *m_path;
    cDirectory m_directory;

    /**
     **********************************************************************
     * Constructor: cFTMain
     *
     *      Author: $author$
     *        Date: 4/20/2004
     **********************************************************************
     */
    cFTMain(const char *path=".")
    : m_path(path) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cFTMain
     *
     *     Author: $author$
     *       Date: 4/20/2004
     **********************************************************************
     */
    virtual ~cFTMain()
    {
    }

    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 4/20/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        eError error;
        cFileTimeInterface *ft;

        if (!(error = m_directory.Open(m_path)))
        {
            if ((ft = m_directory.GetFirstFileTime()))
            do
            {
                printf
                ("%s: %s/%d/%d\n", ft->GetTimeTypeName(),
                 ft->GetMonthName(), ft->GetDay(), ft->GetYear());
            }
            while ((ft = ft->GetNextFileTime()));
            m_directory.Close();
        }
        return 0;
    }
} g_ft_main;
