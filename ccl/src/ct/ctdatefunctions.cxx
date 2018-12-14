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
 *   File: ctdatefunctions.cxx
 *
 * Author: $author$
 *   Date: 8/4/2003
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CTDATEFUNCTIONS_CXX
#define _CTDATEFUNCTIONS_CXX

#include <time.h>
#include <stdlib.h>

#include "ctimplement.hxx"
#include "itoa.h"

/**
 **********************************************************************
 *  Class: cTFunctionDate
 *
 * Author: $author$
 *   Date: 8/4/2003
 **********************************************************************
 */
class cTFunctionDate
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionDate
     *
     *      Author: $author$
     *        Date: 8/4/2003
     **********************************************************************
     */
    cTFunctionDate(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int count;
        time_t tt;
        struct tm *tm;
        char buff[16];

        time(&tt);
        tm=localtime(&tt);

        itoa(tm->tm_mon+1,buff,10);

        if ((count = result.Write(buff)) >= 0)
        if ((count = result.Write("/")) >= 0)
        {
            itoa(tm->tm_mday,buff,10);

            if ((count = result.Write(buff)) >= 0)
            if ((count = result.Write("/")) >= 0)
            {
                itoa(tm->tm_year+1900,buff,10);

                result.Write(buff);
            }
        }
        return e_ERROR_NONE;
    }
} ct_function_date("date","date()");

/**
 **********************************************************************
 *  Class: cTFunctionYear
 *
 * Author: $author$
 *   Date: 1/8/2004
 **********************************************************************
 */
class cTFunctionYear
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionYear
     *
     *      Author: $author$
     *        Date: 1/8/2004
     **********************************************************************
     */
    cTFunctionYear(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/8/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        time_t tt;
        struct tm *tm;
        char buff[16];

        time(&tt);
        tm=localtime(&tt);

        itoa(tm->tm_year+1900,buff,10);

        result.Write(buff);

        return e_ERROR_NONE;
    }
} ct_function_year("year","year()");

#endif
