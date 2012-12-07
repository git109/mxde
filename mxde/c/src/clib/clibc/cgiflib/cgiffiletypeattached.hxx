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
 *   File: cgiffiletypeattached.hxx
 *
 * Author: $author$
 *   Date: 11/4/2010
 **********************************************************************
 */
#if !defined(_CGIFFILETYPEATTACHED_HXX) || defined(CGIFFILETYPEATTACHED_MEMBERS_ONLY)
#if !defined(_CGIFFILETYPEATTACHED_HXX) && !defined(CGIFFILETYPEATTACHED_MEMBERS_ONLY)
#define _CGIFFILETYPEATTACHED_HXX
#endif /* !defined(_CGIFFILETYPEATTACHED_HXX) && !defined(CGIFFILETYPEATTACHED_MEMBERS_ONLY) */

#if !defined(CGIFFILETYPEATTACHED_MEMBERS_ONLY)
#include "cattached.hxx"
#include "copened.hxx"
#include "gif_lib.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */


class c_INTERFACE_CLASS cGifFileTypeAttachedInterface;
/**
 **********************************************************************
 * Typedef: cGifFileTypeAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 11/4/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cGifFileTypeAttachedInterface, 
 GifFileType*, UINT, NULL, cInterfaceBase>
cGifFileTypeAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cGifFileTypeAttachedInterface
 *
 * Author: $author$
 *   Date: 11/4/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cGifFileTypeAttachedInterface
: virtual public cGifFileTypeAttachedInterfaceImplements
{
public:
    typedef cGifFileTypeAttachedInterfaceImplements cImplements;
    typedef cGifFileTypeAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cGifFileTypeAttachedImplement;
/**
 **********************************************************************
 * Typedef: cGifFileTypeAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 11/4/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cGifFileTypeAttachedImplement, 
 cGifFileTypeAttachedInterface, 
 GifFileType*, UINT, NULL>
cGifFileTypeAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cGifFileTypeAttachedImplement
 *
 * Author: $author$
 *   Date: 11/4/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cGifFileTypeAttachedImplement
: virtual public cGifFileTypeAttachedImplementImplements
{
public:
    typedef cGifFileTypeAttachedImplementImplements cImplements;
    typedef cGifFileTypeAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cGifFileTypeAttached;
/**
 **********************************************************************
 * Typedef: cGifFileTypeAttachedExtends
 *
 *  Author: $author$
 *    Date: 11/4/2010
 **********************************************************************
 */
typedef cAttachedT
<cGifFileTypeAttached, 
 cGifFileTypeAttachedImplement, 
 cGifFileTypeAttachedInterface,
 GifFileType*, UINT, NULL, cBase>
cGifFileTypeAttachedExtends;
/**
 **********************************************************************
 *  Class: cGifFileTypeAttached
 *
 * Author: $author$
 *   Date: 11/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cGifFileTypeAttached
: public cGifFileTypeAttachedExtends
{
public:
    typedef cGifFileTypeAttachedExtends cExtends;
    typedef cGifFileTypeAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cGifFileTypeAttached
     *
     *      Author: $author$
     *        Date: 11/4/2010
     **********************************************************************
     */
    cGifFileTypeAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cGifFileTypeOpenedInterface;
/**
 **********************************************************************
 * Typedef: cGifFileTypeOpenedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 11/4/2010
 **********************************************************************
 */
typedef cOpenedInterfaceT
<cGifFileTypeOpenedInterface, cGifFileTypeAttachedInterface>
cGifFileTypeOpenedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cGifFileTypeOpenedInterface
 *
 * Author: $author$
 *   Date: 11/4/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cGifFileTypeOpenedInterface
: virtual public cGifFileTypeOpenedInterfaceImplements
{
public:
    typedef cGifFileTypeOpenedInterfaceImplements cImplements;
    typedef cGifFileTypeOpenedInterface cDerives;
};
class c_EXPORT_CLASS cGifFileTypeOpenedImplement;
/**
 **********************************************************************
 * Typedef: cGifFileTypeOpenedImplementImplements
 *
 *  Author: $author$
 *    Date: 11/4/2010
 **********************************************************************
 */
typedef cOpenedImplementT
<cGifFileTypeOpenedImplement, cGifFileTypeOpenedInterface>
cGifFileTypeOpenedImplementImplements;
/**
 **********************************************************************
 *  Class: cGifFileTypeOpenedImplement
 *
 * Author: $author$
 *   Date: 11/4/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cGifFileTypeOpenedImplement
: virtual public cGifFileTypeOpenedImplementImplements
{
public:
    typedef cGifFileTypeOpenedImplementImplements cImplements;
    typedef cGifFileTypeOpenedImplement cDerives;
};
class c_EXPORT_CLASS cGifFileTypeOpened;
/**
 **********************************************************************
 * Typedef: cGifFileTypeOpenedExtends
 *
 *  Author: $author$
 *    Date: 11/4/2010
 **********************************************************************
 */
typedef cOpenedT
<cGifFileTypeOpened, 
 cGifFileTypeOpenedImplement, 
 cGifFileTypeAttached>
cGifFileTypeOpenedExtends;
/**
 **********************************************************************
 *  Class: cGifFileTypeOpened
 *
 * Author: $author$
 *   Date: 11/4/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cGifFileTypeOpened
: public cGifFileTypeOpenedExtends
{
public:
    typedef cGifFileTypeOpenedExtends cExtends;
    typedef cGifFileTypeOpened cDerives;

    /**
     **********************************************************************
     * Constructor: cGifFileTypeOpened
     *
     *      Author: $author$
     *        Date: 11/4/2010
     **********************************************************************
     */
    cGifFileTypeOpened
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    : cExtends(isOpen) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cGifFileTypeOpened
     *
     *     Author: $author$
     *       Date: 11/4/2010
     **********************************************************************
     */
    virtual ~cGifFileTypeOpened()
    {
        eError error;
        if ((error = Closed()))
            throw(error);
    }
#include "copenedattached_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CGIFFILETYPEATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILETYPEATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CGIFFILETYPEATTACHED_HXX) || defined(CGIFFILETYPEATTACHED_MEMBERS_ONLY) */
