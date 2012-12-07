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
 *   File: cwinmain.hxx
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
#ifndef _CWINMAIN_HXX
#define _CWINMAIN_HXX

#include "cwinmaininterface.hxx"
#include "cwininstance.hxx"
#include "cwincmdline.hxx"
#include "cwinbase.hxx"

/**
 **********************************************************************
 *  Class: cWinMain
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinMain
: virtual public cWinMainImplement,
  public cWinBase
{
public:
    typedef cWinMainImplement cImplements;
    typedef cWinBase cExtends;
    typedef cWinMain cDerives;

    cWinMainInterface* m_oldWinMainInterface;

    cWinInstance m_winInstance;

    /**
     **********************************************************************
     * Constructor: cWinMain
     *
     *      Author: $author$
     *        Date: 5/4/2009
     **********************************************************************
     */
    cWinMain() 
    : m_oldWinMainInterface
     (SetWinMainInterface((cWinMainInterface*)(this)))
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinMain
     *
     *     Author: $author$
     *       Date: 5/4/2009
     **********************************************************************
     */
    virtual ~cWinMain()
    {
        cWinMainInterface* theWinMainInterface;
        if ((theWinMainInterface = GetWinMainInterface())
            == (cWinMainInterface*)(this))
            SetWinMainInterface(m_oldWinMainInterface);
    }

    /**
     **********************************************************************
     * Function: WinMain
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    virtual INT WinMain
    (HINSTANCE instance,
     HINSTANCE previnst,
     LPCMDLINE cmdline,
     INT cmdshow) 
    {
        INT result = 0;
        INT result2;
        HINSTANCE attached;

        if ((attached = m_winInstance.Attach(instance)))
        {
            if (!(result = WinMainCmdLine
                (instance, previnst, cmdline, cmdshow)))

            if (!(result = BeforeProcessMessages
                (instance, previnst, cmdline, cmdshow)))
            {
                result = ProcessMessages
                (instance, previnst, cmdline, cmdshow);

                if ((result2 = AfterProcessMessages
                    (instance, previnst, cmdline, cmdshow))
                    && !result)
                    result = result2;
            }
            m_winInstance.Detach();
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: WinMainCmdLine
     *
     *   Author: $author$
     *     Date: 3/21/2010
     **********************************************************************
     */
    virtual INT WinMainCmdLine
    (HINSTANCE instance,
     HINSTANCE previnst,
     LPCMDLINE cmdline,
     INT cmdshow) 
    {
        INT result = 0;
        cWinCmdLine cCmdLine(cmdline);
        INT argn = 0;
        const TCHAR* arg;
        TLENGTH arglen;

        if ((arg = cCmdLine.FirstArg(arglen)))
        do
        {
            if ((result = WinMainCmdLineArg
                (argn++, arg, arglen,
                 instance, previnst, cmdline, cmdshow)))
                 break;
        }
        while ((arg = cCmdLine.NextArg(arglen, arg)));
        return result;
    }
    /**
     **********************************************************************
     * Function: WinMainCmdLineArg
     *
     *   Author: $author$
     *     Date: 3/21/2010
     **********************************************************************
     */
    virtual INT WinMainCmdLineArg
    (INT argn, const TCHAR* arg, TLENGTH arglen,
     HINSTANCE instance,
     HINSTANCE previnst,
     LPCMDLINE cmdline,
     INT cmdshow) 
    {
        INT result = 0;
        return result;
    }
    /**
     **********************************************************************
     * Function: ProcessMessages
     *
     *   Author: $author$
     *     Date: 5/7/2009
     **********************************************************************
     */
    virtual INT ProcessMessages
    (HINSTANCE instance,
     HINSTANCE previnst,
     LPCMDLINE cmdline,
     INT cmdshow) 
    {
        INT result = 0;
        MSG msg;

        while(GetMessage(&msg, NULL, NULL, NULL))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return result;
    }

    /**
     **********************************************************************
     * Function: GetHINSTANCE
     *
     *   Author: $author$
     *     Date: 5/6/2009
     **********************************************************************
     */
    virtual HINSTANCE GetHINSTANCE() const 
    {
        HINSTANCE hInstance = m_winInstance.Attached();
        return hInstance;
    }
};
#endif /* _CWINMAIN_HXX */
