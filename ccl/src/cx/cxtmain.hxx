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
 *   File: cxtmain.hxx
 *
 * Author: $author$
 *   Date: 4/27/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXTMAIN_HXX
#define _CXTMAIN_HXX

#include <X11/Intrinsic.h>
#include <X11/Shell.h>

#include "cxtwidget.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Class: cXtMain
 *
 * Author: $author$
 *   Date: 4/27/2004
 **********************************************************************
 */
class cXtMain
: public cMain
{
public:
    typedef cMain cIs;

    String m_display_name;
    String m_class_name;
    String m_name;

    XtAppContext m_xt_context;
    cXDisplay m_display;

    bool m_quit;

    /**
     **********************************************************************
     * Constructor: cXtMain
     *
     *      Author: $author$
     *        Date: 4/27/2004
     **********************************************************************
     */
    cXtMain
    (String display_name=0,
     String name="cXtMain",
     String class_name="cXtMain")
    : m_display_name(display_name),
      m_name(name),
      m_class_name(class_name),
      m_xt_context(0),
      m_quit(false) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXtMain
     *
     *     Author: $author$
     *       Date: 4/27/2004
     **********************************************************************
     */
    virtual ~cXtMain()
    {
    }

    /**
     **********************************************************************
     * Function: OnMain
     *
     *   Author: $author$
     *     Date: 4/27/2004
     **********************************************************************
     */
    virtual int OnMain(int argc, char **argv)
    {
        int result=0;
        eError error;

        if ((error = Create(argc, argv)))
            return 1;

        result = OnRun(argc, argv);

        if ((error = Destroy()))
        if (!result)
            result = 1;

        return result;
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 4/27/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
        int result=0;
        eError error;
        XEvent x_event;

        if ((error = Open(argc,argv)))
            result = 1;

        else
        {
            m_quit = false;

            while(!m_quit)
            {
                if ((error = GetEvent(x_event)))
                {
                    result = 1;
                    break;
                }
                DispatchEvent(x_event);
            }

            if ((error = Close()))
                result = 1;
        }
        return result;
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/27/2004
     **********************************************************************
     */
    virtual eError Create(int argc, char **argv)
    {
        eError error=e_ERROR_FAILED;
        Display *display;

        XtToolkitInitialize();

        if (!(m_xt_context = XtCreateApplicationContext()))
            printf
            ("Unable to create Xt application context\n");

        else
        {
            if (!(display = XtOpenDisplay
                (m_xt_context, m_display_name,
                 m_class_name, m_name, 0, 0, &argc, argv)))
            {
                 printf("Unable to open Xt display ");

                 if (m_display_name)
                     printf("\"%s\"", m_display_name);
                 else printf("0");

                 printf("\n");
            }
            else
            {
                if (!(error = m_display.Attach(display)))
                    return error;

                XtCloseDisplay(display);
            }

            XtDestroyApplicationContext(m_xt_context);
            m_xt_context=0;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 4/27/2004
     **********************************************************************
     */
    virtual eError Destroy()
    {
        eError error=e_ERROR_NONE;
        Display *display;

        if (!(display = m_display.GetHandle()))
            error = e_ERROR_NOT_ATTACHED;
        else
        {
            m_display.Detach();
            XtCloseDisplay(display);
        }

        if (!m_xt_context)
        {
            if (!error)
                error = e_ERROR_NOT_CREATED;
        }
        else
        {
            XtDestroyApplicationContext(m_xt_context);
            m_xt_context=0;
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 4/27/2004
     **********************************************************************
     */
    virtual eError Open(int argc, char **argv)
    {
        eError error;

        error = Quit();
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 4/27/2004
     **********************************************************************
     */
    virtual eError Close()
    {
        eError error=e_ERROR_NONE;

        return error;
    }

    /**
     **********************************************************************
     * Function: Quit
     *
     *   Author: $author$
     *     Date: 4/27/2004
     **********************************************************************
     */
    virtual eError Quit()
    {
        m_quit = true;
        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: GetEvent
     *
     *   Author: $author$
     *     Date: 4/27/2004
     **********************************************************************
     */
    virtual eError GetEvent(XEvent &x_event)
    {
        eError error=e_ERROR_FAILED;

        if (m_xt_context)
        {
            error = e_ERROR_NONE;
            XtAppNextEvent(m_xt_context, &x_event);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: DispatchEvent
     *
     *   Author: $author$
     *     Date: 4/27/2004
     **********************************************************************
     */
    virtual eError DispatchEvent(XEvent &x_event)
    {
        eError error=e_ERROR_FAILED;

        if (XtDispatchEvent(&x_event))
            error = e_ERROR_NONE;
        return error;
    }
};

#endif /* ndef _CXTMAIN_HXX */
