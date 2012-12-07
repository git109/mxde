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
 *   File: cjpegdecompressinterfaceattached.hxx
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
#if !defined(_CJPEGDECOMPRESSINTERFACEATTACHED_HXX) || defined(CJPEGDECOMPRESSINTERFACEATTACHED_MEMBERS_ONLY)
#if !defined(_CJPEGDECOMPRESSINTERFACEATTACHED_HXX) && !defined(CJPEGDECOMPRESSINTERFACEATTACHED_MEMBERS_ONLY)
#define _CJPEGDECOMPRESSINTERFACEATTACHED_HXX
#endif /* !defined(_CJPEGDECOMPRESSINTERFACEATTACHED_HXX) && !defined(CJPEGDECOMPRESSINTERFACEATTACHED_MEMBERS_ONLY) */

#if !defined(CJPEGDECOMPRESSINTERFACEATTACHED_MEMBERS_ONLY)
#include "cjpegdecompressinterface.hxx"
#include "cjpegbase.hxx"
#include "ccreated.hxx"
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cJPEGDecompressInterfaceAttachedInterface;
/**
 **********************************************************************
 * Typedef: cJPEGDecompressInterfaceAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 11/13/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cJPEGDecompressInterfaceAttachedInterface, 
 cJPEGDecompressInterface*, UINT, NULL, cJPEGInterfaceBase>
cJPEGDecompressInterfaceAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cJPEGDecompressInterfaceAttachedInterface
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cJPEGDecompressInterfaceAttachedInterface
: virtual public cJPEGDecompressInterfaceAttachedInterfaceImplements
{
public:
    typedef cJPEGDecompressInterfaceAttachedInterfaceImplements cImplements;
    typedef cJPEGDecompressInterfaceAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cJPEGDecompressInterfaceAttachedImplement;
/**
 **********************************************************************
 * Typedef: cJPEGDecompressInterfaceAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 11/13/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cJPEGDecompressInterfaceAttachedImplement, 
 cJPEGDecompressInterfaceAttachedInterface, 
 cJPEGDecompressInterface*, UINT, NULL>
cJPEGDecompressInterfaceAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cJPEGDecompressInterfaceAttachedImplement
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cJPEGDecompressInterfaceAttachedImplement
: virtual public cJPEGDecompressInterfaceAttachedImplementImplements
{
public:
    typedef cJPEGDecompressInterfaceAttachedImplementImplements cImplements;
    typedef cJPEGDecompressInterfaceAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cJPEGDecompressInterfaceAttached;
/**
 **********************************************************************
 * Typedef: cJPEGDecompressInterfaceAttachedExtends
 *
 *  Author: $author$
 *    Date: 11/13/2010
 **********************************************************************
 */
typedef cAttachedT
<cJPEGDecompressInterfaceAttached, 
 cJPEGDecompressInterfaceAttachedImplement, 
 cJPEGDecompressInterfaceAttachedInterface,
 cJPEGDecompressInterface*, UINT, NULL, cJPEGBase>
cJPEGDecompressInterfaceAttachedExtends;
/**
 **********************************************************************
 *  Class: cJPEGDecompressInterfaceAttached
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cJPEGDecompressInterfaceAttached
: public cJPEGDecompressInterfaceAttachedExtends
{
public:
    typedef cJPEGDecompressInterfaceAttachedExtends cExtends;
    typedef cJPEGDecompressInterfaceAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cJPEGDecompressInterfaceAttached
     *
     *      Author: $author$
     *        Date: 11/13/2010
     **********************************************************************
     */
    cJPEGDecompressInterfaceAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cJPEGDecompressInterfaceCreatedInterface;
/**
 **********************************************************************
 * Typedef: cJPEGDecompressInterfaceCreatedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 11/13/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cJPEGDecompressInterfaceCreatedInterface, cJPEGDecompressInterfaceAttachedInterface>
cJPEGDecompressInterfaceCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cJPEGDecompressInterfaceCreatedInterface
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cJPEGDecompressInterfaceCreatedInterface
: virtual public cJPEGDecompressInterfaceCreatedInterfaceImplements
{
public:
    typedef cJPEGDecompressInterfaceCreatedInterfaceImplements cImplements;
    typedef cJPEGDecompressInterfaceCreatedInterface cDerives;
};
class c_EXPORT_CLASS cJPEGDecompressInterfaceCreatedImplement;
/**
 **********************************************************************
 * Typedef: cJPEGDecompressInterfaceCreatedImplementImplements
 *
 *  Author: $author$
 *    Date: 11/13/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cJPEGDecompressInterfaceCreatedImplement, cJPEGDecompressInterfaceCreatedInterface>
cJPEGDecompressInterfaceCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cJPEGDecompressInterfaceCreatedImplement
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cJPEGDecompressInterfaceCreatedImplement
: virtual public cJPEGDecompressInterfaceCreatedImplementImplements
{
public:
    typedef cJPEGDecompressInterfaceCreatedImplementImplements cImplements;
    typedef cJPEGDecompressInterfaceCreatedImplement cDerives;
};
class c_EXPORT_CLASS cJPEGDecompressInterfaceCreated;
/**
 **********************************************************************
 * Typedef: cJPEGDecompressInterfaceCreatedExtends
 *
 *  Author: $author$
 *    Date: 11/13/2010
 **********************************************************************
 */
typedef cCreatedT
<cJPEGDecompressInterfaceCreated, 
 cJPEGDecompressInterfaceCreatedImplement, 
 cJPEGDecompressInterfaceAttached>
cJPEGDecompressInterfaceCreatedExtends;
/**
 **********************************************************************
 *  Class: cJPEGDecompressInterfaceCreated
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cJPEGDecompressInterfaceCreated
: public cJPEGDecompressInterfaceCreatedExtends
{
public:
    typedef cJPEGDecompressInterfaceCreatedExtends cExtends;
    typedef cJPEGDecompressInterfaceCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cJPEGDecompressInterfaceCreated
     *
     *      Author: $author$
     *        Date: 11/13/2010
     **********************************************************************
     */
    cJPEGDecompressInterfaceCreated
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cJPEGDecompressInterfaceCreated
     *
     *     Author: $author$
     *       Date: 11/13/2010
     **********************************************************************
     */
    virtual ~cJPEGDecompressInterfaceCreated()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual eError Create
    (bool onlyDestroyed=false)
    {
        eError error = e_ERROR_NONE;
        cJPEGDecompressInterface* jpeg;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if ((jpeg = cJPEGDecompressInterface::CreateInstance(error)))
            AttachCreated(jpeg);
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
    {
        eError error = e_ERROR_NONE;
        cJPEGDecompressInterface* jpeg;
        
        if ((jpeg = Detach()))
            error = cJPEGDecompressInterface::DestroyInstance(*jpeg);
        else
        if ((onlyCreated))
            error = e_ERROR_NOT_CREATED;
        return error;
    }
#include "ccreatedattached_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CJPEGDECOMPRESSINTERFACEATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CJPEGDECOMPRESSINTERFACEATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CJPEGDECOMPRESSINTERFACEATTACHED_HXX) || defined(CJPEGDECOMPRESSINTERFACEATTACHED_MEMBERS_ONLY) */
