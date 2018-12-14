/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: cwinmaint.hxx
 *
 * Author: $author$
 *   Date: 1/23/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINMAINT_HXX
#define _CWINMAINT_HXX

#include "cwin_platform.h"
#include "csingleinstancet.hxx"

#if defined(_WIN32_WCE) 
typedef LPWSTR LPCMDLINE;
#else /* defined(_WIN32_WCE) */
typedef LPSTR LPCMDLINE;
#endif /* defined(_WIN32_WCE) */

/**
 **********************************************************************
 *  Class: cWinMainT
 *
 * Author: $author$
 *   Date: 1/23/2004
 **********************************************************************
 */
template <class TAs, class TIs=cBase>
class cWinMainT
: public cSingleInstanceT<TAs, TIs>
{
public:
    typedef cSingleInstanceT<TAs, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cWinMainT
     *
     *      Author: $author$
     *        Date: 1/23/2004
     **********************************************************************
     */
    cWinMainT(TAs *instance) 
    : cIs(instance) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinMainT
     *
     *     Author: $author$
     *       Date: 1/23/2004
     **********************************************************************
     */
    virtual ~cWinMainT()
    {
    }
    /**
     **********************************************************************
     * Function: OnWinMain
     *
     *   Author: $author$
     *     Date: 1/23/2004
     **********************************************************************
     */
    virtual int OnWinMain
    (HINSTANCE instance, HINSTANCE previnst,
     LPCMDLINE cmdline, int cmdshow)
    {
        int result=0;

        return result;
    }
    virtual int OnMessageLoop()
    {
        int result=0;
        MSG msg;

        while(GetMessage(&msg, NULL, NULL, NULL))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        return result;
    }
};

/**
 **********************************************************************
 *  Class: cWinMain
 *
 * Author: $author$
 *   Date: 1/23/2004
 **********************************************************************
 */
class cWinMain
: public cWinMainT<cWinMain>
{
public:
    typedef cWinMainT<cWinMain> cIs;

    /**
     **********************************************************************
     * Constructor: cWinMain
     *
     *      Author: $author$
     *        Date: 1/23/2004
     **********************************************************************
     */
    cWinMain() 
    : cIs(this) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinMain
     *
     *     Author: $author$
     *       Date: 1/23/2004
     **********************************************************************
     */
    virtual ~cWinMain()
    {
    }
};

#endif /* ndef _CWINMAINT_HXX */
