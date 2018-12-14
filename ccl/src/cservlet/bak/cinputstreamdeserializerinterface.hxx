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
 *   File: cinputstreamdeserializerinterface.hxx
 *
 * Author: $author$
 *   Date: 11/7/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CINPUTSTREAMDESERIALIZERINTERFACE_HXX
#define _CINPUTSTREAMDESERIALIZERINTERFACE_HXX

#include "cinputstreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cInputStreamDeserializerInterfaceT
 *
 * Author: $author$
 *   Date: 11/7/2004
 **********************************************************************
 */
template 
<class TInputStream=cInputStreamInterface,
 class TOf=BYTE, class TEnd=int, TEnd VNullEnd=-1, 
 class TIs=cInterfaceBase>

class c_INTERFACE_CLASS cInputStreamDeserializerInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Deserialize
     *
     *   Author: $author$
     *     Date: 11/7/2004
     **********************************************************************
     */
    virtual eError Deserialize
    (TInputStream &input, TEnd endchar=VNullEnd) = 0;
};

/**
 **********************************************************************
 *  Class: cInputStreamDeserializerInterface
 *
 * Author: $author$
 *   Date: 11/7/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cInputStreamDeserializerInterface
: virtual public cInputStreamDeserializerInterfaceT<>
{
public:
};

#endif /* ndef _CINPUTSTREAMDESERIALIZERINTERFACE_HXX */
