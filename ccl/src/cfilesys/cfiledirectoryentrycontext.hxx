/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: cfiledirectoryentrycontext.hxx
 *
 * Author: $author$
 *   Date: 6/9/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEDIRECTORYENTRYCONTEXT_HXX
#define _CFILEDIRECTORYENTRYCONTEXT_HXX

#if defined(WIN32)
/*
 * Windows
 */
#include <windows.h>
#define DIRECTORY HANDLE
#define INVALID_DIRECTORY_VALUE INVALID_HANDLE_VALUE
#define DIRECTORY_SEPARATOR_CHAR '\\'
#define SECURITY_DESCRIPTOR_DATA_SIZE 4096
#else /* defined(WIN32) */
/*
 * Unix
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#define DIRECTORY DIR*
#define INVALID_DIRECTORY_VALUE NULL
#define DIRECTORY_SEPARATOR_CHAR '/'
#endif /* defined(WIN32) */

#include "chandlet.hxx"
#include "clistt.hxx"

#define DIRECTORY_WILDCARD_CHAR '*'

/**
 **********************************************************************
 *  Class: cFileDirectoryEntryContext
 *
 * Author: $author$
 *   Date: 5/4/2005
 **********************************************************************
 */
class cFileDirectoryEntryContext
: public cHandleT
  <DIRECTORY, (int)INVALID_DIRECTORY_VALUE>
{
public:
    typedef cHandleT
    <DIRECTORY, (int)INVALID_DIRECTORY_VALUE> cIs;

#if defined(WIN32)
/*
 * Windows
 */
	WIN32_FIND_DATA m_ff;
	struct
	{
		SECURITY_DESCRIPTOR m_sd;
		BYTE m_data[SECURITY_DESCRIPTOR_DATA_SIZE];
	} m_sd;
#else /* defined(WIN32) */
/*
 * Unix
 */
    struct stat m_stat;
    struct dirent *m_dirent;
#endif /* defined(WIN32) */

    /**
     **********************************************************************
     * Constructor: cFileDirectoryEntryContext
     *
     *      Author: $author$
     *        Date: 5/4/2005
     **********************************************************************
     */
    cFileDirectoryEntryContext
    (DIRECTORY handle=INVALID_DIRECTORY_VALUE) 
    : cIs(handle)
    {
    }
    /**
     **********************************************************************
     * Function: GetNextEntry
     *
     *   Author: $author$
     *     Date: 5/4/2005
     **********************************************************************
     */
    virtual eError GetNextEntry() 
    {
        eError error = e_ERROR_ENDOF;

#if defined(WIN32)
/*
 * Windows
 */
        if (FindNextFile(m_handle, &m_ff))
            return e_ERROR_NONE;
#else /* defined(WIN32) */
/*
 * Unix
 */
#endif /* defined(WIN32) */

        return error;
    }
};

#define DIRENTRY cFileDirectoryEntryContext*
#define INVALID_DIRENTRY_VALUE NULL

#endif /* _CFILEDIRECTORYENTRYCONTEXT_HXX */