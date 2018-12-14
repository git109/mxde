/**
 **********************************************************************
 * Copyright (c) 1988-2014 $author$
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
 *   File: cechohttpservlet.cxx
 *
 * Author: $author$
 *   Date: 5/24/2014
 **********************************************************************
 */


#include "chttpsingleservlet.hxx"

/**
 **********************************************************************
 *  Class: cEchoHttpServlet
 *
 * Author: $author$
 *   Date: 5/24/2014
 **********************************************************************
 */
class c_EXPORT_CLASS cEchoHttpServlet
: public cHttpSingleServlet
{
public:
    typedef cHttpSingleServlet cExtends;
    typedef cEchoHttpServlet cDerives;
    /**
     **********************************************************************
     * Constructor: cEchoHttpServlet
     *
     *      Author: $author$
     *        Date: 5/24/2014
     **********************************************************************
     */
    cEchoHttpServlet(const char* name)
    : cExtends(name)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cEchoHttpServlet
     *
     *     Author: $author$
     *       Date: 5/24/2014
     **********************************************************************
     */
    virtual ~cEchoHttpServlet()
    {
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 5/24/2014
     **********************************************************************
     */
    virtual eError Service
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response)
    {
        cCharWriterInterface &writer = response.GetWriter();
        eError error = e_ERROR_NONE;
        response.SetStatusOK();
        response.SetContentType("text/plain");
        writer.WriteL(request.GetMethodName(), " ", request.GetPathInfo(), "\n", 0);
        return error;
    }
};

static cEchoHttpServlet g_echoHttpServlet("Echo");

        

