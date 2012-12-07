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
 *   File: cwinbrush.hxx
 *
 * Author: $author$
 *   Date: 6/3/2009
 **********************************************************************
 */
#ifndef _CWINBRUSH_HXX
#define _CWINBRUSH_HXX

#include "cwinhbrush.hxx"

/**
 **********************************************************************
 * Typedef: cWinBrushExtends
 *
 *  Author: $author$
 *    Date: 6/3/2009
 **********************************************************************
 */
typedef cWinHBRUSH
cWinBrushExtends;
/**
 **********************************************************************
 *  Class: cWinBrush
 *
 * Author: $author$
 *   Date: 6/3/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinBrush
: public cWinBrushExtends
{
public:
    typedef cWinBrushExtends cExtends;
    typedef cWinBrush cDerives;

    /**
     **********************************************************************
     * Constructor: cWinBrush
     *
     *      Author: $author$
     *        Date: 6/3/2009
     **********************************************************************
     */
    cWinBrush
    (HBRUSH attached=NULL,
     bool isCreated=false) 
    : cExtends(attached,isCreated)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinBrush
     *
     *     Author: $author$
     *       Date: 6/3/2009
     **********************************************************************
     */
    virtual ~cWinBrush()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
        if ((error = Detached()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: CreateSolid
     *
     *   Author: $author$
     *     Date: 6/3/2009
     **********************************************************************
     */
    virtual eError CreateSolid
    (const COLORREF& color,
     bool onlyDestroyed=false) 
#if defined(CWINBRUSH_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBRUSH_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINBRUSH_MEMBER_FUNCS_IMPLEMENT) 
        HBRUSH detached, attached;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if ((detached = CreateDetached(error, color)))
        {
            if (detached == (attached = Attach(detached)))
            if (0 < (SetIsCreated()))
                return e_ERROR_NONE;
            else
            Detach();
            DestroyDetached(detached);
        }
#else /* !defined(CWINBRUSH_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBRUSH_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBRUSH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 6/3/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
#if defined(CWINBRUSH_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBRUSH_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINBRUSH_MEMBER_FUNCS_IMPLEMENT) 
        HBRUSH detached;

        if ((error = Created(onlyCreated, true)))
            return error;

        SetIsCreated(false);

        if ((detached = Detach()))
            error = DestroyDetached(detached);
#else /* !defined(CWINBRUSH_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBRUSH_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBRUSH_MEMBER_FUNCS_INTERFACE) */
};
#endif /* _CWINBRUSH_HXX */
