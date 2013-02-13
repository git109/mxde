/**
 **********************************************************************
 * Copyright (c) 1988-2012 $organization$
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
 *   File: cwinwebrtcdroidmain.hxx
 *
 * Author: $author$
 *   Date: 12/11/2012
 **********************************************************************
 */
#ifndef _CWINWEBRTCDROIDMAIN_HXX
#define _CWINWEBRTCDROIDMAIN_HXX

#include "cwindroidmain.hxx"
#include "cwinwebrtcdroidmainwindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinWebRtcDroidMainExtend
 *
 *  Author: $author$
 *    Date: 12/11/2012
 **********************************************************************
 */
typedef cWinDroidMain
cWinWebRtcDroidMainExtend;
/**
 **********************************************************************
 *  Class: cWinWebRtcDroidMain
 *
 * Author: $author$
 *   Date: 12/11/2012
 **********************************************************************
 */
class c_EXPORT_CLASS cWinWebRtcDroidMain
: public cWinWebRtcDroidMainExtend
{
public:
    typedef cWinWebRtcDroidMainExtend cExtends;

    cWinWebRtcDroidMainWindow m_mainWindow;

    /**
     **********************************************************************
     *  Constructor: cWinWebRtcDroidMain
     *
     *       Author: $author$
     *         Date: 12/11/2012
     **********************************************************************
     */
    cWinWebRtcDroidMain()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinWebRtcDroidMain
     *
     *      Author: $author$
     *        Date: 12/11/2012
     **********************************************************************
     */
    virtual ~cWinWebRtcDroidMain()
    {
    }
    /**
     **********************************************************************
     * Function: GetMainWindow
     *
     *   Author: $author$
     *     Date: 12/11/2012
     **********************************************************************
     */
    virtual cWinDroidMainWindow& GetMainWindow()
    {
        return m_mainWindow;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CWINWEBRTCDROIDMAIN_HXX */
