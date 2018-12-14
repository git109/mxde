/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cwinevcsexplorerviewwindow.cxx
 *
 * Author: $author$
 *   Date: 6/11/2007
 *
 *    $Id$
 **********************************************************************
 */

#include "afxres.h"
#include "resource.h"
#include "cwinevcsexplorerviewwindow.hxx"

/**
 **********************************************************************
 *  Class: cWinEvcsExplorerDirectoryListViewWindow
 *
 * Author: $author$
 *   Date: 6/11/2007
 **********************************************************************
 */
const TCHAR* 
cWinEvcsExplorerDirectoryListViewWindow::
m_column_name[e_DIRECTORY_LIST_COLUMNS] = 
{
    _T(DIRECTORY_LIST_COLUMN_NAME_NAME),
    _T(DIRECTORY_LIST_COLUMN_NAME_SIZE),
    _T(DIRECTORY_LIST_COLUMN_NAME_TYPE),
    _T(DIRECTORY_LIST_COLUMN_NAME_MODIFIED),
};
 
/**
 **********************************************************************
 *  Class: cWinEvcsExplorerFileListViewWindow
 *
 * Author: $author$
 *   Date: 6/11/2007
 **********************************************************************
 */
const TCHAR* 
cWinEvcsExplorerFileListViewWindow::
m_column_name[e_FILE_LIST_COLUMNS] = 
{
    _T(FILE_LIST_COLUMN_NAME_PROPERTY),
    _T(FILE_LIST_COLUMN_NAME_VALUE),
};

/**
 **********************************************************************
 *  Class: cWinEvcsExplorerViewWindow
 *
 * Author: $author$
 *   Date: 6/11/2007
 **********************************************************************
 */
