/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: cgi.cxx
 *
 * Author: $author$
 *   Date: 12/6/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "ccgimain.hxx"
#include "htmlmacro.h"

/**
 **********************************************************************
 *  Class: cTheCGI
 *
 * Author: $author$
 *   Date: 12/6/2003
 **********************************************************************
 */
class cTheCGI
: public cCGIMain
{
public:
    typedef cCGIMain cIs;

    /**
     **********************************************************************
     * Constructor: cTheCGI
     *
     *      Author: $author$
     *        Date: 12/6/2003
     **********************************************************************
     */
    cTheCGI() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cTheCGI
     *
     *     Author: $author$
     *       Date: 12/6/2003
     **********************************************************************
     */
    virtual ~cTheCGI()
    {
    }

    /**
     **********************************************************************
     * Function: OnCGI
     *
     *   Author: $author$
     *     Date: 12/6/2003
     **********************************************************************
     */
    virtual int OnCGI()
    {
        cHTTPForm::cField *field;
        int env;

        OutputContentType(GetContentTypeHTML());

        OutputL(H1, "cgi", H1_, 0);
        OutputL(BOLD, "Form Content Type", BOLD_, " = \"", GetInputContentType(), "\"", BR, 0);
        OutputL(BR, BOLD, "Form fields", BOLD_, UL, 0);

        if ((field = GetFirstFormField()))
        do
        {
            OutputL
            (BOLD, field->GetName(), BOLD_,
             " = \"", field->GetValue(), "\"", BR, 0);
        }
        while ((field = field->GetNext()));

        OutputL(UL_, BOLD, "Environment Valiables", BOLD_, UL, 0);

        for (env = e_FIRST_ENV; env <= e_LAST_ENV; env++)
            OutputL
            (BOLD, m_env_name[env], BOLD_,
             " = \"", m_env[env], "\"", BR, 0);

        Output(UL_);

        return 0;
    }
} g_the_cgi;
