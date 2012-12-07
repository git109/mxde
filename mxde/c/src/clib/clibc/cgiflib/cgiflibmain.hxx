/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: cgiflibmain.hxx
 *
 * Author: $author$
 *   Date: 11/4/2010
 **********************************************************************
 */
#if !defined(_CGIFLIBMAIN_HXX) || defined(CGIFLIBMAIN_MEMBERS_ONLY)
#if !defined(_CGIFLIBMAIN_HXX) && !defined(CGIFLIBMAIN_MEMBERS_ONLY)
#define _CGIFLIBMAIN_HXX
#endif /* !defined(_CGIFLIBMAIN_HXX) && !defined(CGIFLIBMAIN_MEMBERS_ONLY) */

#if !defined(CGIFLIBMAIN_MEMBERS_ONLY)
#include "cargmain.hxx"
#include "cgiffile.hxx"
#include "cgiffileimagereader.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cGifLibMainExtend
 *
 *  Author: $author$
 *    Date: 11/4/2010
 **********************************************************************
 */
typedef cArgMain
cGifLibMainExtend;
/**
 **********************************************************************
 *  Class: cGifLibMain
 *
 * Author: $author$
 *   Date: 11/4/2010
 **********************************************************************
 */
class cGifLibMain
: //virtual public cGifLibMainImplement,
  public cGifLibMainExtend
{
public:
    //typedef cGifLibMainImplement cImplements;
    typedef cGifLibMainExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cGifLibMain
     *
     *       Author: $author$
     *         Date: 11/4/2010
     **********************************************************************
     */
    cGifLibMain()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cGifLibMain
     *
     *      Author: $author$
     *        Date: 11/4/2010
     **********************************************************************
     */
    virtual ~cGifLibMain()
    {
    }
#else /* !defined(CGIFLIBMAIN_MEMBERS_ONLY) */
#endif /* !defined(CGIFLIBMAIN_MEMBERS_ONLY) */

#if !defined(CGIFLIBMAIN_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 11/4/2010
     **********************************************************************
     */
    virtual tInt Run
    (tInt argc,
     const tChar** argv,
     const tChar** env) 
    {
        tInt err = 0;
        cGifFile g;
        cGifFileImageReader r(g);
        if (1 < (argc))
            r.Read(argv[argc-1]);
        return err;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CGIFLIBMAIN_MEMBERS_ONLY) */
#endif /* !defined(CGIFLIBMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CGIFLIBMAIN_HXX) || defined(CGIFLIBMAIN_MEMBERS_ONLY) */
