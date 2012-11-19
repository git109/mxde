/**
 **********************************************************************
 * Copyright (c) 1988-2011 $organization$
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
 *   File: cMxdeCgiMainCgiMain.hxx
 *
 * Author: $author$
 *   Date: 9/17/2011
 **********************************************************************
 */
#ifndef _CMXDECGIMAINCGIMAIN_HXX
#define _CMXDECGIMAINCGIMAIN_HXX

#include "cMxdeCgiMainCgi.hxx"
#include "cMxdeCgiMainCgiCgiEnv.hxx"
#include "cMxdeCgiMainCgiContentStream.hxx"
#include "cMxdeCgiMainCgiHttpFormFields.hxx"
#include "cMxdeCgiMainCgiHttpRequest.hpp"
#include "cCgiInterface.hpp"
#include "cDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cMxdeCgiMainCgiMain
 *
 * Author: $author$
 *   Date: 9/17/2011
 **********************************************************************
 */
class c_INSTANCE_CLASS cMxdeCgiMainCgiMain
: virtual public cMxdeCgiMainCgi
{
public:
    typedef cMxdeCgiMainCgi cImplements;
    /**
     **********************************************************************
     *  Constructor: cMxdeCgiMainCgiMain
     *
     *       Author: $author$
     *         Date: 9/17/2011
     **********************************************************************
     */
    cMxdeCgiMainCgiMain()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cMxdeCgiMainCgiMain
     *
     *      Author: $author$
     *        Date: 9/17/2011
     **********************************************************************
     */
    virtual ~cMxdeCgiMainCgiMain()
    {
    }
    /**
     **********************************************************************
     *  Function: Run
     *
     *    Author: $author$
     *      Date: 9/17/2011
     **********************************************************************
     */
    virtual int Run
    (cMxdeCgiMainContentStream& contentOutput,
     cMxdeCgiMainHttpFormFields& formFields,
     cMxdeCgiMainHttpRequest& request,
     cMxdeCgiMainCgiEnv& cgiEnv,
     int argc, 
     char** argv, 
     char** env)
    {
        cMxdeCgiMainCgiContentStream cgiContent(contentOutput);
        cMxdeCgiMainCgiHttpFormFields cgiFormFields(formFields);
        cMxdeCgiMainCgiHttpRequest cgiRequest(request);
        cMxdeCgiMainCgiCgiEnv cgiCgiEnv(cgiEnv);
        cCgiInterface* cgi = 0;
        int err = 0;
        eError error;

        if ((cgi = cCgiInterface::GetTheCgi()))
        {
            if (!(error = cgi->Init
                (&cgiContent, &cgiFormFields, &cgiRequest, &cgiCgiEnv)))
            {
                if (!(err = cgi->BeforeRun(argc, argv, env)))
                {
                    int err2 = 0;

                    err = cgi->Run(argc, argv, env);

                    if ((err2 = cgi->AfterRun(argc, argv, env)) && !(err))
                        err = err2;
                }
                if ((error = cgi->Finish()) && !(err))
                    err = 1;
            }
        }
        else
        c_DB_ERROR("() 0 == cCgiInterface::GetTheCgi()");
        return err;
    }
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CMXDECGIMAINCGIMAIN_HXX */
        

