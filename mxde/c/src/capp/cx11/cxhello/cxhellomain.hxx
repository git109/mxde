/**
 **********************************************************************
 * Copyright (c) 1988-2013 $organization$
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
 *   File: cxhellomain.hxx
 *
 * Author: $author$
 *   Date: 6/30/2013
 **********************************************************************
 */
#if !defined(_CXHELLOMAIN_HXX) || defined(CXHELLOMAIN_MEMBERS_ONLY)
#if !defined(_CXHELLOMAIN_HXX) && !defined(CXHELLOMAIN_MEMBERS_ONLY)
#define _CXHELLOMAIN_HXX
#endif /* !defined(_CXHELLOMAIN_HXX) && !defined(CXHELLOMAIN_MEMBERS_ONLY) */

#if !defined(CXHELLOMAIN_MEMBERS_ONLY)
#include "cxwindowmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

typedef cXWindowMainImplement cXHelloMainImplement;
typedef cXWindowMain cXHelloMainExtend;
/**
 **********************************************************************
 *  Class: cXHelloMain
 *
 * Author: $author$
 *   Date: 6/30/2013
 **********************************************************************
 */
class c_INSTANCE_CLASS cXHelloMain
: virtual public cXHelloMainImplement,
  public cXHelloMainExtend
{
public:
    typedef cXHelloMainImplement cImplements;
    typedef cXHelloMainExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXHelloMain
     *
     *       Author: $author$
     *         Date: 6/30/2013
     **********************************************************************
     */
    cXHelloMain()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXHelloMain
     *
     *      Author: $author$
     *        Date: 6/30/2013
     **********************************************************************
     */
    virtual ~cXHelloMain()
    {
    }
#else /* !defined(CXHELLOMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXHELLOMAIN_MEMBERS_ONLY) */

#if !defined(CXHELLOMAIN_MEMBERS_ONLY)
    virtual const char* WMName() const {
        return "Hello";
    }
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXHELLOMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXHELLOMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXHELLOMAIN_HXX) || defined(CXHELLOMAIN_MEMBERS_ONLY) */
        

