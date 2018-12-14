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
 *   File: winapp.cxx
 *
 * Author: $author$
 *   Date: 1/23/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "resource.h"
#include "cimageinterface.hxx"
#include "cimage.hxx"
#include "cwinimage.hxx"
#include "cwinobject.hxx"
#include "cwinmaint.hxx"

/**
 **********************************************************************
 *  Class: cWinApp
 *
 * Author: $author$
 *   Date: 1/23/2004
 **********************************************************************
 */
class cWinApp
: public cWinMain
{
public:
    typedef cWinMain cIs;

    /**
     **********************************************************************
     *  Class: cMainWindow
     *
     * Author: $author$
     *   Date: 2/28/2004
     **********************************************************************
     */
    class cMainWindow
    : public cWinWindow
    {
    public:
        typedef cWinWindow cIs;

        /**
         **********************************************************************
         * Function: OnWMPaint
         *
         *   Author: $author$
         *     Date: 2/28/2004
         **********************************************************************
         */
        virtual LRESULT OnWMPaint(WPARAM wparam, LPARAM lparam)
        {
            HDC hdc;
            PAINTSTRUCT ps;
            cWinRect rect;

            if (rect.GetUpdate(m_handle, true))
            if ((hdc = BeginPaint(m_handle,&ps)))
            {
                cWinDC dc(hdc);
                cWinImage im(dc);

                OnPaint(im);
                EndPaint(m_handle, &ps);
            }
            return 0;
        }
        /**
         **********************************************************************
         * Function: OnPaint
         *
         *   Author: $author$
         *     Date: 2/28/2004
         **********************************************************************
         */
        void OnPaint(cWinImage &im)
        {
            cImageColor color1(1,1,0xbb,0xbb,0xbb);
            cImageColor color2(1,1,0xff,0xff,0xff);

            cImageTab tab
            (color2, color1, 
             100, 10, 100, 24, 1, 1, 1, 2, 10);

            for (int i=0; i<4; i++)
                tab.Paint(im,i*100+100,-1,1==i);
        }
    };

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
     LPSTR cmdline, int cmdshow)
    {
        int result=0;
        eError error;
        cWinIcon icon;
        cWinBrush brush;
        cWinWindowClass window_class;
        cMainWindow window;

        if (!(error = brush.GetStock(WHITE_BRUSH)))
        if (!(error = icon.Create(instance, IDR_MAIN_WINDOW)))
        {
            window_class.SetIcon(icon.GetHandle());
            window_class.SetBackground(brush.GetHandle());

            if (!(error = window_class.Register
                ("myclass", instance, cWinWindow::WindowProc)))
            {
                if (!(error = window.Create("myclass", instance)))
                {
                    window.Show();
                    OnMessageLoop();
                    window.Destroy();
                }
                window_class.Unregister();
            }
        }
        return result;
    }
} g_winapp;
