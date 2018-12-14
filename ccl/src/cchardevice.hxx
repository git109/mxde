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
 *   File: cchardevice.hxx
 *
 * Author: $author$
 *   Date: 3/1/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARDEVICE_HXX
#define _CCHARDEVICE_HXX

#include "cdevicet.hxx"

/**
 **********************************************************************
 *  Class: cCharDevice
 *
 * Author: $author$
 *   Date: 3/1/2004
 **********************************************************************
 */
class cCharDevice
: public cDeviceT<char>
{
public:
    typedef cDeviceT<char> cIs;

    /**
     **********************************************************************
     * Constructor: cCharDevice
     *
     *      Author: $author$
     *        Date: 3/1/2004
     **********************************************************************
     */
    cCharDevice(DEVICE handle=INVALID_DEVICE, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cCharDevice
     *
     *     Author: $author$
     *       Date: 3/1/2004
     **********************************************************************
     */
    ~cCharDevice()
    {
    }
};

#endif /* ndef _CCHARDEVICE_HXX */
