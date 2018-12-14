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
 *   File: cservletapachemodule.cxx
 *
 * Author: $author$
 *   Date: 1/1/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "capachemodule.hxx"

/**
 **********************************************************************
 *  Class: cServletApacheModule
 *
 * Author: $author$
 *   Date: 1/1/2005
 **********************************************************************
 */
class cServletApacheModule
: public cApacheModule
{
public:
    typedef cApacheModule cIs;

    /**
     **********************************************************************
     * Constructor: cServletApacheModule
     *
     *      Author: $author$
     *        Date: 1/1/2005
     **********************************************************************
     */
    cServletApacheModule
    (module &module, const char *module_name)
    : cIs(module, module_name, e_HANDLER_CONTENT_TYPES) 
    {
    }
    /**
     **********************************************************************
     * Function: GetContentTypeHandlers
     *
     *   Author: $author$
     *     Date: 1/2/2005
     **********************************************************************
     */
    virtual handler_rec *GetContentTypeHandlers()
    {
        static handler_rec handlers[]=
        {{"mod_cservlet"},{0}};
        return handlers;
    }
    /**
     **********************************************************************
     * Function: OnContent
     *
     *   Author: $author$
     *     Date: 1/2/2005
     **********************************************************************
     */
    virtual int OnContent
    (cApacheRequestContentType &content_type,
     cApacheRequestContent &content,
     cApacheRequest &request)
    {
        const char *type;
        int length;

        if (!(type = content_type.GetValue(length)))
            type = "";

        content.WriteL("Content-Type: ", type, 0);
        return OK;
    }
};

CAPACHEMODULE
(cServletApacheModule, 
 g_cservlet_apache_module, mod_cservlet);
