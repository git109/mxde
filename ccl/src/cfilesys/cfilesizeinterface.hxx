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
 *   File: cfilesizeinterface.hxx
 *
 * Author: $author$
 *   Date: 6/11/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILESIZEINTERFACE_HXX
#define _CFILESIZEINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cFileSizeInterface
 *
 * Author: $author$
 *   Date: 6/11/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cFileSizeInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: SetFileSize
     *
     *   Author: $author$
     *     Date: 6/11/2005
     **********************************************************************
     */
    virtual LONGLONG SetFileSize(LONGLONG size) = 0;
    /**
     **********************************************************************
     * Function: GetFileSize
     *
     *   Author: $author$
     *     Date: 6/11/2005
     **********************************************************************
     */
    virtual LONGLONG GetFileSize() const = 0;
};

#endif /* _CFILESIZEINTERFACE_HXX */