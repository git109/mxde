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
 *   File: cpnginforeader.hxx
 *
 * Author: $author$
 *   Date: 1/15/2010
 **********************************************************************
 */
#if !defined(_CPNGINFOREADER_HXX) || defined(CPNGINFOREADER_MEMBERS_ONLY)
#if !defined(_CPNGINFOREADER_HXX) && !defined(CPNGINFOREADER_MEMBERS_ONLY)
#define _CPNGINFOREADER_HXX
#endif /* !defined(_CPNGINFOREADER_HXX) && !defined(CPNGINFOREADER_MEMBERS_ONLY) */

#if !defined(CPNGINFOREADER_MEMBERS_ONLY)
#include "cpnginforeaderinterface.hxx"
#include "cpngreadstruct.hxx"
#include "cpnginfo.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cPngInfoReader
 *
 * Author: $author$
 *   Date: 1/15/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cPngInfoReader
: virtual public cPngInfoReaderImplement,
  public cPngInfo
{
public:
    typedef cPngInfoReaderImplement cImplements;
    typedef cPngInfo cExtends;
    
    cPngReadStruct& m_pngReadStruct;
    bool m_pngReadStructIsCreated;
    
    /**
     **********************************************************************
     *  Constructor: cPngInfoReader
     *
     *       Author: $author$
     *         Date: 1/15/2010
     **********************************************************************
     */
    cPngInfoReader
    (cPngReadStruct& pngReadStruct,
     bool pngReadStructIsCreated=false,
     png_infop attached=0,
     bool isCreated=false)
    : cExtends(pngReadStruct, attached, isCreated),
      m_pngReadStruct(pngReadStruct),
      m_pngReadStructIsCreated(pngReadStructIsCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cPngInfoReader
     *
     *      Author: $author$
     *        Date: 1/15/2010
     **********************************************************************
     */
    virtual ~cPngInfoReader()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
#else /* !defined(CPNGINFOREADER_MEMBERS_ONLY) */
#endif /* !defined(CPNGINFOREADER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 1/15/2010
     **********************************************************************
     */
    virtual eError Create
    (bool onlyDestroyed=false) 
#if defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
        if (!(error = m_pngReadStruct.Create(onlyDestroyed)))
        if ((error = cExtends::Create(onlyDestroyed)))
            m_pngReadStruct.Destroy(true);
#else /* !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 1/15/2010
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
#if defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
        eError error2;
        error = cExtends::Destroy(onlyCreated);
        if ((error2 = m_pngReadStruct.Destroy(onlyCreated)))
        if (!error)
            error = error2;
#else /* !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 1/15/2010
     **********************************************************************
     */
    virtual eError Open
    (const char* fileName) 
#if defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
        eError error = m_pngReadStruct.Open(fileName);
#else /* !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 1/15/2010
     **********************************************************************
     */
    virtual eError Close() 
#if defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
        eError error = m_pngReadStruct.Close();
#else /* !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 1/15/2010
     **********************************************************************
     */
    virtual eError DeleteInstance() 
#if defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_DELETE;
        cPngReadStruct* pngReadStruct=&m_pngReadStruct;
        
        delete this;
        
        if ((m_pngReadStructIsCreated))
            delete pngReadStruct;
            
        error = e_ERROR_NONE;
#else /* !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE) */

#if defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 1/15/2010
     **********************************************************************
     */
    static cPngInfoReaderInterface* CreateInstance
    (eError& error);
    /**
     **********************************************************************
     * Function: DestroyInstance
     *
     *   Author: $author$
     *     Date: 1/15/2010
     **********************************************************************
     */
    static eError DestroyInstance
    (cPngInfoReaderInterface& pngInfoReader);
#endif /* defined(CPNGINFOREADER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CPNGINFOREADER_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGINFOREADER_MEMBERS_ONLY) */
#endif /* !defined(CPNGINFOREADER_MEMBERS_ONLY) */

#endif /* !defined(_CPNGINFOREADER_HXX) || defined(CPNGINFOREADER_MEMBERS_ONLY) */
