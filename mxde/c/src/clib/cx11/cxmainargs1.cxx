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

/**
 **********************************************************************
 *  Class: cXWidthMainArg
 *
 * Author: $author$           
 *   Date: 6/22/2009
 **********************************************************************
 */
class cXWidthMainArg
: public cXMainArg
{
public:
    typedef cXMainArg cExtends;
    typedef cXWidthMainArg cDerives;
    /**
     **********************************************************************
     * Constructor: cXWidthMainArg
     *
     *      Author: $author$           
     *        Date: 6/22/2009
     **********************************************************************
     */
    cXWidthMainArg
    (const tChar* shortName="w",
     const tChar* name="width",
     const tChar* description="Width",
     const tChar* parameters="width:Width") 
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
        tSize value;
        cXMainInterface* theXMain;
        if ((theXMain = cXMain::TheXMain()))
        if ((arg = MainArgParam(argon, arg, argc, argv)))
        if (0 < (value = (tSize)(tChars::ToUInt(arg))))
        {
            DBI(("() %s: %u\n", Name(), value));
            theXMain->SetWidth(value);
        }
        return argon;
    }
};
cXWidthMainArg g_cXWidthMainArg;

/**
 **********************************************************************
 *  Class: cXHeightMainArg
 *
 * Author: $author$           
 *   Date: 6/22/2009
 **********************************************************************
 */
class cXHeightMainArg
: public cXMainArg
{
public:
    typedef cXMainArg cExtends;
    typedef cXHeightMainArg cDerives;
    /**
     **********************************************************************
     * Constructor: cXHeightMainArg
     *
     *      Author: $author$           
     *        Date: 6/22/2009
     **********************************************************************
     */
    cXHeightMainArg
    (const tChar* shortName="h",
     const tChar* name="height",
     const tChar* description="Height",
     const tChar* parameters="height:Height") 
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
        tSize value;
        cXMainInterface* theXMain;
        if ((theXMain = cXMain::TheXMain()))
        if ((arg = MainArgParam(argon, arg, argc, argv)))
        if (0 < (value = (tSize)(tChars::ToUInt(arg))))
        {
            DBI(("() %s: %u\n", Name(), value));
            theXMain->SetHeight(value);
        }
        return argon;
    }
};
cXHeightMainArg g_cXHeightMainArg;
