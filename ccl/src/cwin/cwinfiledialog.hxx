/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: cwinfiledialog.hxx
 *
 * Author: $author$
 *   Date: 1/28/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINFILEDIALOG_HXX
#define _CWINFILEDIALOG_HXX

#include "cwinhandle.hxx"
#include "ctcharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cGetOpenFileNameDialog
 *
 * Author: $author$
 *   Date: 3/29/2004
 **********************************************************************
 */
class cGetOpenFileNameDialog
{
public:
    OPENFILENAME m_ofn;
    cTCHARBuffer m_filename;

    /**
     **********************************************************************
     * Constructor: cGetOpenFileNameDialog
     *
     *      Author: $author$
     *        Date: 3/29/2004
     **********************************************************************
     */
    cGetOpenFileNameDialog() 
    {
        memset(&m_ofn, 0, sizeof(m_ofn));
        m_ofn.lStructSize = sizeof(m_ofn);
    }
    /**
     **********************************************************************
     * Destructor: ~cGetOpenFileNameDialog
     *
     *     Author: $author$
     *       Date: 3/29/2004
     **********************************************************************
     */
    virtual ~cGetOpenFileNameDialog()
    {
    }

    /**
     **********************************************************************
     * Function: Modal
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual eError Modal
    (HINSTANCE instance, HWND window, 
     LPCTSTR filename=NULL, int filenamelen=-1)
    {
        eError error=e_ERROR_FAILED;

        if (!(error = Ready
            (instance, window, filename, filenamelen)))
        if (GetOpenFileName(&m_ofn))
        {
            m_filename.SetLength(-1);
            error = e_ERROR_NONE;
        }
        else error=e_ERROR_FAILED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Ready
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual eError Ready
    (HINSTANCE instance, HWND window, 
     LPCTSTR filename=NULL, int filenamelen=-1)
    {
        eError error=e_ERROR_NONE;

        if (NULL != filename)
        {
            if (0 > (filenamelen = m_filename.Copy
                (filename, filenamelen)))
                return error = -filenamelen;
        }

        m_ofn.hwndOwner = window;
        m_ofn.hInstance = instance;
        m_ofn.lpstrFile = m_filename.GetWriteBuffer();
        m_ofn.nMaxFile = m_filename.GetSize()-1;
        m_ofn.lpstrFilter = _T("All Files (*.*)\0*.*\0");
        m_ofn.Flags = OFN_NOCHANGEDIR|OFN_SHOWHELP;
        return error;
    }

    /**
     **********************************************************************
     * Function: Ready
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    LPCTSTR GetFileName(int &length) const
    {
        return m_filename.GetBuffer(length);
    }
};

/**
 **********************************************************************
 *  Class: cGetSaveFileNameDialog
 *
 * Author: $author$
 *   Date: 3/29/2004
 **********************************************************************
 */
class cGetSaveFileNameDialog
: public cGetOpenFileNameDialog
{
public:
    typedef cGetOpenFileNameDialog cIs;

    /**
     **********************************************************************
     * Constructor: cGetSaveFileNameDialog
     *
     *      Author: $author$
     *        Date: 3/29/2004
     **********************************************************************
     */
    cGetSaveFileNameDialog() 
    : cGetOpenFileNameDialog() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cGetSaveFileNameDialog
     *
     *     Author: $author$
     *       Date: 3/29/2004
     **********************************************************************
     */
    virtual ~cGetSaveFileNameDialog()
    {
    }

    /**
     **********************************************************************
     * Function: Modal
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual eError Modal
    (HINSTANCE instance, HWND window, 
     LPCTSTR filename=NULL, int filenamelen=-1)
    {
        eError error=e_ERROR_FAILED;

        if (!(error = Ready
            (instance, window, filename, filenamelen)))
        if (GetSaveFileName(&m_ofn))
        {
            m_filename.SetLength(-1);
            error = e_ERROR_NONE;
        }
        return error;
    }
};

#endif /* _CWINFILEDIALOG_HXX */
