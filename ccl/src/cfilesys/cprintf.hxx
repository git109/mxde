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
 *   File: cprintf.hxx
 *
 * Author: $author$
 *   Date: 1/15/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CPRINTF_HXX
#define _CPRINTF_HXX

#include "cprintfinterface.hxx"
#include "cfilehandle.hxx"

/**
 **********************************************************************
 *  Class: cPrintf
 *
 * Author: $author$
 *   Date: 1/15/2006
 **********************************************************************
 */
class cPrintf
: virtual public cPrintfImplement,
  public cFileHandleInstance
{
public:
    typedef cFileHandleInstance cIs;

    /**
     **********************************************************************
     * Constructor: cPrintf
     *
     *      Author: $author$
     *        Date: 1/15/2006
     **********************************************************************
     */
    cPrintf(FILE *file=0, bool opened=false) 
    : cIs(file, opened) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cPrintf
     *
     *      Author: $author$
     *        Date: 1/15/2006
     **********************************************************************
     */
    virtual ~cPrintf()
    {
    }
    /**
     **********************************************************************
     * Function: VPrintf
     *
     *   Author: $author$
     *     Date: 1/15/2006
     **********************************************************************
     */
    virtual int VPrintf(const char* format, va_list va) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;

        if (!m_handle)
            return -e_ERROR_NOT_ATTACHED;

        if (0 > (result = vfprintf(m_handle, format, va)))
            result = -e_ERROR_FAILED;
        return result;
    }
};

#endif /* _CPRINTF_HXX */

