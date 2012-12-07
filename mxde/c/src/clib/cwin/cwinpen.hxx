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
 *   File: cwinpen.hxx
 *
 * Author: $author$
 *   Date: 6/5/2009
 **********************************************************************
 */
#ifndef _CWINPEN_HXX
#define _CWINPEN_HXX

#include "cwinhpen.hxx"

/**
 **********************************************************************
 * Typedef: cWinPenExtends
 *
 *  Author: $author$
 *    Date: 6/5/2009
 **********************************************************************
 */
typedef cWinHPEN
cWinPenExtends;
/**
 **********************************************************************
 *  Class: cWinPen
 *
 * Author: $author$
 *   Date: 6/5/2009
 **********************************************************************
 */
class cWinPen
: public cWinPenExtends
{
public:
    typedef cWinPenExtends cExtends;
    typedef cWinPen cDerives;
    /**
     **********************************************************************
     * Constructor: cWinPen
     *
     *      Author: $author$
     *        Date: 6/5/2009
     **********************************************************************
     */
    cWinPen
    (HPEN attached=NULL,
     bool isCreated=false) 
    : cExtends(attached,isCreated)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinPen
     *
     *     Author: $author$
     *       Date: 6/5/2009
     **********************************************************************
     */
    virtual ~cWinPen()
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
     *     Date: 6/5/2009
     **********************************************************************
     */
    virtual eError Create
    (const COLORREF& color,
     int style=PS_SOLID,
     int width=1,
     bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_FAILED;
        HPEN detached, attached;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        if ((detached = CreateDetached(error, color, style, width)))
        {
            if (detached == (attached = Attach(detached)))
            if (0 < (SetIsCreated()))
                return e_ERROR_NONE;
            else
            Detach();
            DestroyDetached(detached);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 6/5/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
    {
        eError error = e_ERROR_FAILED;
        HPEN detached;

        if ((error = Created(onlyCreated, true)))
            return error;

        SetIsCreated(false);

        if (!(detached = Detach()))
            return e_ERROR_NOT_ATTACHED;

        error = DestroyDetached(detached);
        return error;
    }
};
#endif /* _CWINPEN_HXX */
