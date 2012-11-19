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
 *   File: cMxdeCgiMainCgi.hxx
 *
 * Author: $author$
 *   Date: 9/17/2011
 **********************************************************************
 */
#ifndef _CMXDECGIMAINCGI_HXX
#define _CMXDECGIMAINCGI_HXX

#include "cMxdeCgiMainContentStream.hxx"
#include "cMxdeCgiMainHttpFormFields.hxx"
#include "cMxdeCgiMainHttpRequest.hxx"
#include "cMxdeCgiMainCgiEnv.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cMxdeCgiMainCgi
 *
 * Author: $author$
 *   Date: 9/17/2011
 **********************************************************************
 */
class c_INTERFACE_CLASS cMxdeCgiMainCgi
{
public:
    /**
     **********************************************************************
     *  Function: Run
     *
     *    Author: $author$
     *      Date: 10/29/2011
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
        int err = Run(contentOutput, formFields, cgiEnv, argc, argv, env);
        return err;
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
     cMxdeCgiMainCgiEnv& cgiEnv,
     int argc, 
     char** argv, 
     char** env)
    {
        int err = 0;
        return err;
    }
    /**
     **********************************************************************
     *  Function: GetInstance
     *
     *    Author: $author$
     *      Date: 9/17/2011
     **********************************************************************
     */
    static cMxdeCgiMainCgi* GetInstance();
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CMXDECGIMAINCGI_HXX */
        

