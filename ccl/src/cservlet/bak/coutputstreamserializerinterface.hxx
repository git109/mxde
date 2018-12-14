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
 *   File: coutputstreamserializerinterface.hxx
 *
 * Author: $author$
 *   Date: 11/5/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _COUTPUTSTREAMSERIALIZERINTERFACE_HXX
#define _COUTPUTSTREAMSERIALIZERINTERFACE_HXX

#include "coutputstreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cOutputStreamSerializerInterfaceT
 *
 * Author: $author$
 *   Date: 11/5/2004
 **********************************************************************
 */
template 
<class TOutputStream=cOutputStreamInterface,
 class TOf=BYTE, class TIs=cInterfaceBase>

class c_INTERFACE_CLASS cOutputStreamSerializerInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Serialize
     *
     *   Author: $author$
     *     Date: 11/5/2004
     **********************************************************************
     */
    virtual int Serialize
    (TOutputStream& output, 
     const TOf* endchars=0, int endchars_length=-1) = 0;
};

/**
 **********************************************************************
 *  Class: cOutputStreamSerializerInterface
 *
 * Author: $author$
 *   Date: 11/5/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cOutputStreamSerializerInterface
: virtual public cOutputStreamSerializerInterfaceT<>
{
public:
};

#endif /* ndef _COUTPUTSTREAMSERIALIZERINTERFACE_HXX */
