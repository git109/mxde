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
 *   File: cbresenhamlinecontext.hxx
 *
 * Author: $author$
 *   Date: 1/26/2010
 **********************************************************************
 */
#if !defined(_CBRESENHAMLINECONTEXT_HXX) || defined(CBRESENHAMLINECONTEXT_MEMBERS_ONLY)
#if !defined(_CBRESENHAMLINECONTEXT_HXX) && !defined(CBRESENHAMLINECONTEXT_MEMBERS_ONLY)
#define _CBRESENHAMLINECONTEXT_HXX
#endif /* !defined(_CBRESENHAMLINECONTEXT_HXX) && !defined(CBRESENHAMLINECONTEXT_MEMBERS_ONLY) */

#if !defined(CBRESENHAMLINECONTEXT_MEMBERS_ONLY)
#include "cexportbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cBresenhamLineContext;

#undef CDB_CLASS
#define CDB_CLASS "cBresenhamLineContextT"
/**
 **********************************************************************
 *  Class: cBresenhamLineContextT
 *
 * Author: $author$
 *   Date: 1/26/2010
 **********************************************************************
 */
template
<class TDerives=cBresenhamLineContext,
 class TExtend=cExportBase,
 class TInt=INT,
 class TExtends=TExtend>

class c_EXPORT_CLASS cBresenhamLineContextT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef cBresenhamLineContextT cDerive;
    
    typedef bool (cDerive::*MFinish)(TInt& x, TInt& y);
    
    MFinish m_finish;
    TInt x1,y1,x2,y2,dx,dy,i1,i2,d;
    
    /**
     **********************************************************************
     *  Constructor: cBresenhamLineContextT
     *
     *       Author: $author$
     *         Date: 1/26/2010
     **********************************************************************
     */
    cBresenhamLineContextT()
    : m_finish(0)
    {
    }
#else /* !defined(CBRESENHAMLINECONTEXT_MEMBERS_ONLY) */
#endif /* !defined(CBRESENHAMLINECONTEXT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Start
     *
     *   Author: $author$
     *     Date: 1/26/2010
     **********************************************************************
     */
    virtual bool Start
    (TInt& x,TInt& y, 
     TInt p_x1,TInt p_y1, TInt p_x2,TInt p_y2) 
#if defined(CBRESENHAMLINECONTEXT_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBRESENHAMLINECONTEXT_MEMBER_FUNCS_INTERFACE) */
    {
        bool isTrue = false;
#if !defined(CBRESENHAMLINECONTEXT_MEMBER_FUNCS_IMPLEMENT) 

        x = (x1 = p_x1);
        y = (y1 = p_y1);
        x2 = p_x2;
        y2 = p_y2;
        
        if (0 > (dx = x2-x1))
            dx = -dx;

        if (0 > (dy = y2-y1))
            dy = -dy;

    if (dx < dy)
    {
        if (y1 > y2)
        {
            x = x2;
            x2 = x1;
            x1 = x;
            y = y2;
            y2 = y1;
            y1 = y;
        }
        else 
        {
            x = x1;
            y = y1;
        }

        d = 2*dx-dy;
        i1 = 2*dx;
        i2 = 2*(dx - dy);
        
        if (x2 < x1)
            m_finish = &cDerive::FinishYminusX;
        else
        m_finish = &cDerive::FinishYplusX;
        
        isTrue = true;
    }
    else
    {
        if (x1 > x2)
        {
            x = x2;
            x2 = x1;
            x1 = x;
            y = y2;
            y2 = y1;
            y1 = y;
        }
        else 
        {
            x = x1;
            y = y1;
        }

        d = 2*dy-dx;
        i1 = 2*dy;
        i2 = 2*(dy - dx);
        
        if (y2 < y1)
            m_finish = &cDerive::FinishXminusY;
        else 
        m_finish = &cDerive::FinishXplusY;
        
        isTrue = true;
    }
#else /* !defined(CBRESENHAMLINECONTEXT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBRESENHAMLINECONTEXT_MEMBER_FUNCS_IMPLEMENT) */
        return isTrue;
    }
#endif /* defined(CBRESENHAMLINECONTEXT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Finish
     *
     *   Author: $author$
     *     Date: 1/26/2010
     **********************************************************************
     */
    virtual bool Finish
    (TInt& x, TInt& y) 
#if defined(CBRESENHAMLINECONTEXT_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBRESENHAMLINECONTEXT_MEMBER_FUNCS_INTERFACE) */
    {
        bool isTrue = false;
#if !defined(CBRESENHAMLINECONTEXT_MEMBER_FUNCS_IMPLEMENT)
        if (m_finish)
            isTrue = (this->*m_finish)(x,y);
#else /* !defined(CBRESENHAMLINECONTEXT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBRESENHAMLINECONTEXT_MEMBER_FUNCS_IMPLEMENT) */
        return isTrue;
    }
#endif /* defined(CBRESENHAMLINECONTEXT_MEMBER_FUNCS_INTERFACE) */

#if !defined(CBRESENHAMLINECONTEXT_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: FinishYminusX
     *
     *   Author: $author$
     *     Date: 1/26/2010
     **********************************************************************
     */
    bool FinishYminusX
    (TInt& x, TInt& y) 
    {
        bool isTrue = false;
        if ((isTrue = ((++y) <= y2)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                --x;
            }
        }
        return isTrue;
    }
    /**
     **********************************************************************
     * Function: FinishYplusX
     *
     *   Author: $author$
     *     Date: 1/26/2010
     **********************************************************************
     */
    bool FinishYplusX
    (TInt& x, TInt& y) 
    {
        bool isTrue = false;
        if ((isTrue = ((++y) <= y2)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                x++;
            }
        }
        return isTrue;
    }
    /**
     **********************************************************************
     * Function: FinishXminusY
     *
     *   Author: $author$
     *     Date: 1/26/2010
     **********************************************************************
     */
    bool FinishXminusY
    (TInt& x, TInt& y) 
    {
        bool isTrue = false;
        if ((isTrue = ((++x) <= x2)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                --y;
            }
        }
        return isTrue;
    }
    /**
     **********************************************************************
     * Function: FinishXplusY
     *
     *   Author: $author$
     *     Date: 1/26/2010
     **********************************************************************
     */
    bool FinishXplusY
    (TInt& x, TInt& y) 
    {
        bool isTrue = false;
        if ((isTrue = ((++x) <= x2)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                y++;
            }
        }
        return isTrue;
    }
};

    /**
     **********************************************************************
     * Function: FinishMinusYminusX
     *
     *   Author: $author$
     *     Date: 1/26/2010
     **********************************************************************
     */
    bool FinishMinusYminusX
    (TInt& x, TInt& y) 
    {
        bool isTrue = false;
        if ((isTrue = ((--y) >= y1)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                --x;
            }
        }
        return isTrue;
    }
    /**
     **********************************************************************
     * Function: FinishMinusYplusX
     *
     *   Author: $author$
     *     Date: 1/26/2010
     **********************************************************************
     */
    bool FinishMinusYplusX
    (TInt& x, TInt& y) 
    {
        bool isTrue = false;
        if ((isTrue = ((--y) >= y1)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                x++;
            }
        }
        return isTrue;
    }
    /**
     **********************************************************************
     * Function: FinishMinusXminusY
     *
     *   Author: $author$
     *     Date: 1/26/2010
     **********************************************************************
     */
    bool FinishMinusXminusY
    (TInt& x, TInt& y) 
    {
        bool isTrue = false;
        if ((isTrue = ((--x) >= x1)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                --y;
            }
        }
        return isTrue;
    }
    /**
     **********************************************************************
     * Function: FinishMinusXplusY
     *
     *   Author: $author$
     *     Date: 1/26/2010
     **********************************************************************
     */
    bool FinishMinusXplusY
    (TInt& x, TInt& y) 
    {
        bool isTrue = false;
        if ((isTrue = ((--x) >= x1)))
        {
            if (d < 0)
                d += i1;
            else
            {
                d += i2;
                y++;
            }
        }
        return isTrue;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cBresenhamLineContextExtend
 *
 *  Author: $author$
 *    Date: 1/27/2010
 **********************************************************************
 */
typedef cBresenhamLineContextT<>
cBresenhamLineContextExtend;
/**
 **********************************************************************
 *  Class: cBresenhamLineContext
 *
 * Author: $author$
 *   Date: 1/27/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cBresenhamLineContext
: public cBresenhamLineContextExtend
{
public:
    typedef cBresenhamLineContextExtend cExtends;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CBRESENHAMLINECONTEXT_MEMBERS_ONLY) */
#endif /* !defined(CBRESENHAMLINECONTEXT_MEMBERS_ONLY) */

#endif /* !defined(_CBRESENHAMLINECONTEXT_HXX) || defined(CBRESENHAMLINECONTEXT_MEMBERS_ONLY) */
