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
 *   File: cwintextmetric.hxx
 *
 * Author: $author$
 *   Date: 8/3/2010
 **********************************************************************
 */
#if !defined(_CWINTEXTMETRIC_HXX) || defined(CWINTEXTMETRIC_MEMBERS_ONLY)
#if !defined(_CWINTEXTMETRIC_HXX) && !defined(CWINTEXTMETRIC_MEMBERS_ONLY)
#define _CWINTEXTMETRIC_HXX
#endif /* !defined(_CWINTEXTMETRIC_HXX) && !defined(CWINTEXTMETRIC_MEMBERS_ONLY) */

#if !defined(CWINTEXTMETRIC_MEMBERS_ONLY)
#include "cwintextmetricinterface.hxx"
#include "cwinhdcacquired.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinTextMetricExtend
 *
 *  Author: $author$
 *    Date: 8/3/2010
 **********************************************************************
 */
typedef cWinHDCAcquired
cWinTextMetricExtend;
/**
 **********************************************************************
 *  Class: cWinTextMetric
 *
 * Author: $author$
 *   Date: 8/3/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinTextMetric
: virtual public cWinTextMetricImplement,
  public cWinTextMetricExtend
{
public:
    typedef cWinTextMetricImplement cImplements;
    typedef cWinTextMetricExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinTextMetric
     *
     *       Author: $author$
     *         Date: 8/3/2010
     **********************************************************************
     */
    cWinTextMetric
    (HDC attached=NULL,
     HWND hWndAttached=NULL,
     bool isAcquired=false)
    : cExtends(attached, hWndAttached, isAcquired)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinTextMetric
     *
     *      Author: $author$
     *        Date: 8/3/2010
     **********************************************************************
     */
    virtual ~cWinTextMetric()
    {
        eError error;
        DBE_THROW_ERROR(error, Released());
    }
#else /* !defined(CWINTEXTMETRIC_MEMBERS_ONLY) */
#endif /* !defined(CWINTEXTMETRIC_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Get0XExtent
     *
     *    Author: $author$
     *      Date: 8/4/2010
     **********************************************************************
     */
    virtual eError Get0XExtent
    (TSIZE& width, TSIZE& height,
     const TCHAR a=_T('A'),
     const TCHAR d=_T('0')) const
#if defined(CWINTEXTMETRIC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINTEXTMETRIC_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINTEXTMETRIC_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        HDC hDC;
        SIZE sz;
        TCHAR c;
        UINT i;
        
        if ((hDC = Attached()))
        {
            width = 0;
            height = 0;
            
            for (c = d, i = 0; i<10; i++, c++)
            {
                if ((GetTextExtentPoint(hDC, &c, 1, &sz)))
                {
                    if (width < (TSIZE)(sz.cx)) width = sz.cx;
                    if (height < (TSIZE)(sz.cy)) height = sz.cy;
                }
            }
            for (c = a, i = 10; i<16; i++, c++)
            {
                if ((GetTextExtentPoint(hDC, &c, 1, &sz)))
                {
                    if (width < (TSIZE)(sz.cx)) width = sz.cx;
                    if (height < (TSIZE)(sz.cy)) height = sz.cy;
                }
            }
            error = e_ERROR_NONE;
        }
#else /* !defined(CWINTEXTMETRIC_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINTEXTMETRIC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINTEXTMETRIC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetExtent
     *
     *    Author: $author$
     *      Date: 8/4/2010
     **********************************************************************
     */
    virtual eError GetExtent
    (TSIZE& width, TSIZE& height,
     const TCHAR* chars, TSIZE length) const
#if defined(CWINTEXTMETRIC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINTEXTMETRIC_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINTEXTMETRIC_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        HDC hDC;
        SIZE sz;
        
        if ((hDC = Attached()))
        if ((chars) && (length))
        if ((GetTextExtentPoint(hDC, chars, length, &sz)))
        {
            width = sz.cx;
            height = sz.cy;
            error = e_ERROR_NONE;
        }
#else /* !defined(CWINTEXTMETRIC_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINTEXTMETRIC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINTEXTMETRIC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetMetrics
     *
     *    Author: $author$
     *      Date: 8/4/2010
     **********************************************************************
     */
    virtual eError GetMetrics
    (TEXTMETRIC& tm) const
#if defined(CWINTEXTMETRIC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINTEXTMETRIC_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINTEXTMETRIC_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        HDC hDC;
        
        if ((hDC = Attached()))
        if ((GetTextMetrics(hDC, &tm)))
            error = e_ERROR_NONE;
            
#else /* !defined(CWINTEXTMETRIC_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINTEXTMETRIC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINTEXTMETRIC_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINTEXTMETRIC_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINTEXTMETRIC_MEMBERS_ONLY) */
#endif /* !defined(CWINTEXTMETRIC_MEMBERS_ONLY) */

#endif /* !defined(_CWINTEXTMETRIC_HXX) || defined(CWINTEXTMETRIC_MEMBERS_ONLY) */
