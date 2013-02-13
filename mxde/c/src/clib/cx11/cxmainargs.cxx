/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$     
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
 *   File: cxmainargs.cxx
 *
 * Author: $author$           
 *   Date: 6/22/2009
 **********************************************************************
 */
#include "cxmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXDisplayMainArg
 *
 * Author: $author$           
 *   Date: 6/22/2009
 **********************************************************************
 */
class cXDisplayMainArg
: public cXMainArg
{
public:
    typedef cXMainArg cExtends;
    typedef cXDisplayMainArg cDerives;
    /**
     **********************************************************************
     * Constructor: cXDisplayMainArg
     *
     *      Author: $author$           
     *        Date: 6/22/2009
     **********************************************************************
     */
    cXDisplayMainArg
    (const tChar* shortName="s",
     const tChar* name="display",
     const tChar* description="Display name",
     const tChar* parameters="name:Display name") 
    : cExtends(shortName,name,description,parameters)
    {
    }
    /**
     **********************************************************************
     * Function: MainArg
     *
     *   Author: $author$           
     *     Date: 6/22/2009
     **********************************************************************
     */
    virtual tInt MainArg
    (tInt args,
     tInt argn,
     const tChar* arg,
     tInt argc,
     const tChar** argv,
     const tChar** env) const 
    {
        tInt argon = argn;
        cXMainInterface* theXMain;
        if ((theXMain = cXMain::TheXMain()))
        if ((arg = MainArgParam(argon, arg, argc, argv)))
        {
            DBI(("() %s: \"%s\"\n", Name(), arg));
            theXMain->SetDisplayName(arg);
        }
        return argon;
    }
};
cXDisplayMainArg g_cXDisplayMainArg;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */
