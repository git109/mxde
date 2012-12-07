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
 *   File: cpng.hxx
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
#if !defined(_CPNG_HXX) || defined(CPNG_MEMBERS_ONLY)
#if !defined(_CPNG_HXX) && !defined(CPNG_MEMBERS_ONLY)
#define _CPNG_HXX
#endif /* !defined(_CPNG_HXX) && !defined(CPNG_MEMBERS_ONLY) */

#if !defined(CPNG_MEMBERS_ONLY)
#include "cpnginterface.hxx"
#include "cinstancebase.hxx"
#include "cpnginfo.hxx"
#include "cpngreadstruct.hxx"
#include "cpngwritestruct.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cPngExtend
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cInstanceBase
cPngExtend;
/**
 **********************************************************************
 *  Class: cPng
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
class cPng
: virtual public cPngImplement,
  public cPngExtend
{
public:
    typedef cPngImplement cImplements;
    typedef cPngExtend cExtends;

    cPngReadStruct m_pngReadStruct;
    cPngInfo m_pngReadInfo;

    /**
     **********************************************************************
     * Constructor: cPng
     *
     *      Author: $author$
     *        Date: 6/10/2009
     **********************************************************************
     */
    cPng()
    : m_pngReadInfo(m_pngReadStruct) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cPng
     *
     *     Author: $author$
     *       Date: 6/10/2009
     **********************************************************************
     */
    virtual ~cPng()
    {
    }
#else /* !defined(CPNG_MEMBERS_ONLY) */
#endif /* !defined(CPNG_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual eError DeleteInstance() 
#if defined(CPNG_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNG_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CPNG_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_DELETE;
        delete this;
        error = e_ERROR_NONE;
#else /* !defined(CPNG_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CPNG_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNG_MEMBER_FUNCS_INTERFACE) */

#if !defined(CPNG_MEMBER_FUNCS_IMPLEMENT) 
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    static cPngInterface* CreateInstance
    (eError& error) 
#if defined(CPNG_MEMBER_FUNCS_INTERFACE)
     ;
#else /* defined(CPNG_MEMBER_FUNCS_INTERFACE) */
    {
        cPngInterface* png = 0;
        if ((png = new cPng()))
            error = e_ERROR_NONE;
        else
        error = e_ERROR_NEW;
        return png;
    }
#endif /* defined(CPNG_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DestroyInstance
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    static eError DestroyInstance
    (cPngInterface& png) 
#if defined(CPNG_MEMBER_FUNCS_INTERFACE)
     ;
#else /* defined(CPNG_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = png.DeleteInstance();
        return error;
    }
#endif /* defined(CPNG_MEMBER_FUNCS_INTERFACE) */
#endif /* !defined(CPNG_MEMBER_FUNCS_IMPLEMENT) */

#if !defined(CPNG_MEMBERS_ONLY) 
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNG_MEMBERS_ONLY) */
#endif /* !defined(CPNG_MEMBERS_ONLY) */

#endif /* !defined(_CPNG_HXX) || defined(CPNG_MEMBERS_ONLY) */
