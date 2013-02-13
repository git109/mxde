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
 *   File: cxpm.hxx
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
#if !defined(_CXPM_HXX) || defined(CXPM_MEMBERS_ONLY)
#if !defined(_CXPM_HXX) && !defined(CXPM_MEMBERS_ONLY)
#define _CXPM_HXX
#endif /* !defined(_CXPM_HXX) && !defined(CXPM_MEMBERS_ONLY) */

#if !defined(CXPM_MEMBERS_ONLY)
#include "cxpminterface.hxx"
#include "cxpmimage.hxx"
#include "cxpminfo.hxx"
#include "cxbase.hxx"
#include "cstringbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXpmExtend
 *
 *  Author: $author$           
 *    Date: 6/4/2010
 **********************************************************************
 */
typedef cXBase
cXpmExtend;
/**
 **********************************************************************
 *  Class: cXpm
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXpm
: virtual public cXpmImplement,
  public cXpmExtend
{
public:
    typedef cXpmImplement cImplements;
    typedef cXpmExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cXpm
     *
     *       Author: $author$           
     *         Date: 6/4/2010
     **********************************************************************
     */
    cXpm()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXpm
     *
     *      Author: $author$           
     *        Date: 6/4/2010
     **********************************************************************
     */
    virtual ~cXpm()
    {
    }
#else /* !defined(CXPM_MEMBERS_ONLY) */
#endif /* !defined(CXPM_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: ReadFileToXpmImage
     *
     *    Author: $author$           
     *      Date: 6/4/2010
     **********************************************************************
     */
    virtual eError ReadFileToXpmImage
    (const char *filename, 
     cXpmImageInterface& xpmImage, 
     cXpmInfoInterface& xpmInfo) const
#if defined(CXPM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPM_MEMBER_FUNCS_IMPLEMENT)
        XpmImage& rXpmImage = (XpmImage&)(xpmImage);
        XpmInfo& rXpmInfo = (XpmInfo&)(xpmInfo);
        eError error = e_ERROR_FAILED;
        int isTrue;

        if (!(error = ReadFileToXpmImage
            (filename, rXpmImage, rXpmInfo)))
        {
            if (0 < (isTrue = xpmImage.SetIsCreated()))
            if (0 < (isTrue = xpmInfo.SetIsCreated()))
                return e_ERROR_NONE;

            xpmImage.SetIsCreated(false);
            xpmInfo.SetIsCreated(false);

            XpmFreeXpmImage(&rXpmImage);
            XpmFreeXpmInfo(&rXpmInfo);
        }
#else /* !defined(CXPM_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPM_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: ReadFileToXpmImage
     *
     *    Author: $author$           
     *      Date: 6/4/2010
     **********************************************************************
     */
    virtual eError ReadFileToXpmImage
    (const char *filename, 
     XpmImage& xpmImage, 
     XpmInfo& xpmInfo) const
#if defined(CXPM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXPM_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        int err;
        char* fileNameStr;
        cStringBase fileName;

        if ((filename))
        if (0 < (fileName.append(filename)))
        if ((fileNameStr = fileName.str()))
        if (!(err = XpmReadFileToXpmImage
            (fileNameStr, &xpmImage, &xpmInfo)))
            error = e_ERROR_NONE;
        else
        DBE
        (("()\n failed err = %d (\"%s\") "
          "on XpmReadFileToXpmImage(\"%s\")\n", 
          err, ErrorName(err), filename));

#else /* !defined(CXPM_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXPM_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXPM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: ErrorName
     *
     *    Author: $author$           
     *      Date: 6/4/2010
     **********************************************************************
     */
    virtual const char* ErrorName(int err) const
#if defined(CXPM_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXPM_MEMBER_FUNCS_INTERFACE) */
    {
        const char* name = "unknown";
#if !defined(CXPM_MEMBER_FUNCS_IMPLEMENT)
        switch(err)
        {
        case XpmColorError:
            name = "XpmColorError";
            break;
        case XpmSuccess:
            name = "XpmSuccess";
            break;
        case XpmOpenFailed:
            name = "XpmOpenFailed";
            break;
        case XpmFileInvalid:
            name = "XpmFileInvalid";
            break;
        case XpmNoMemory:
            name = "XpmNoMemory";
            break;
        case XpmColorFailed:
            name = "XpmColorFailed";
            break;
        }
#else /* !defined(CXPM_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXPM_MEMBER_FUNCS_IMPLEMENT) */
        return name;
    }
#endif /* defined(CXPM_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXPM_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXPM_MEMBERS_ONLY) */
#endif /* !defined(CXPM_MEMBERS_ONLY) */

#endif /* !defined(_CXPM_HXX) || defined(CXPM_MEMBERS_ONLY) */
