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
 *   File: cjpegdecompressinterface.hxx
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
#if !defined(_CJPEGDECOMPRESSINTERFACE_HXX) || defined(CJPEGDECOMPRESSINTERFACE_MEMBERS_ONLY)
#if !defined(_CJPEGDECOMPRESSINTERFACE_HXX) && !defined(CJPEGDECOMPRESSINTERFACE_MEMBERS_ONLY)
#define _CJPEGDECOMPRESSINTERFACE_HXX
#endif /* !defined(_CJPEGDECOMPRESSINTERFACE_HXX) && !defined(CJPEGDECOMPRESSINTERFACE_MEMBERS_ONLY) */

#if !defined(CJPEGDECOMPRESSINTERFACE_MEMBERS_ONLY)
#include "cjpeginterfacebase.hxx"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cJPEGDecompress;
class c_INTERFACE_CLASS cJPEGDecompressInterface;
/**
 **********************************************************************
 * Typedef: cJPEGDecompressInterfaceImplements
 *
 *  Author: $author$
 *    Date: 11/12/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cJPEGDecompressInterface, cJPEGInterfaceBase>
cJPEGDecompressInterfaceImplements;
/**
 **********************************************************************
 *  Class: cJPEGDecompressInterface
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cJPEGDecompressInterface
: virtual public cJPEGDecompressInterfaceImplements
{
public:
    typedef cJPEGDecompressInterfaceImplements cImplements;
    typedef cJPEGDecompressInterface cDerives;

/* include cJPEGDecompress member functions interface
 */
#define CJPEGDECOMPRESS_MEMBERS_ONLY
#define CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE
#include "cjpegdecompress.hxx"
#undef CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE
#undef CJPEGDECOMPRESS_MEMBERS_ONLY
};
class c_IMPLEMENT_CLASS cJPEGDecompressImplement;
/**
 **********************************************************************
 * Typedef: cJPEGDecompressImplementImplements
 *
 *  Author: $author$
 *    Date: 11/12/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cJPEGDecompressImplement, cJPEGDecompressInterface>
cJPEGDecompressImplementImplements;
/**
 **********************************************************************
 *  Class: cJPEGDecompressImplement
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cJPEGDecompressImplement
: virtual public cJPEGDecompressImplementImplements
{
public:
    typedef cJPEGDecompressImplementImplements cImplements;
    typedef cJPEGDecompressImplement cDerives;

/* include cJPEGDecompress member functions implement
 */
#define CJPEGDECOMPRESS_MEMBERS_ONLY
#define CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT
#include "cjpegdecompress.hxx"
#undef CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT
#undef CJPEGDECOMPRESS_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CJPEGDECOMPRESSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CJPEGDECOMPRESSINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CJPEGDECOMPRESSINTERFACE_HXX) || defined(CJPEGDECOMPRESSINTERFACE_MEMBERS_ONLY) */
