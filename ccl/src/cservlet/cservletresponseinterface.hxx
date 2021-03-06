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
 *   File: cservletresponseinterface.hxx
 *
 * Author: $author$
 *   Date: 10/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSERVLETRESPONSEINTERFACE_HXX
#define _CSERVLETRESPONSEINTERFACE_HXX

#include "coutputstreaminterface.hxx"
#include "ccharwriterinterface.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cServletResponseInterfaceT
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cServletResponseInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: SetContentType
     *
     *   Author: $author$
     *     Date: 10/21/2004
     **********************************************************************
     */
    virtual int SetContentType
    (const char *buf,  int len=-1) = 0;
    /**
     **********************************************************************
     * Function: SetContentLength
     *
     *   Author: $author$
     *     Date: 10/21/2004
     **********************************************************************
     */
    virtual int SetContentLength
    (int length=-1) = 0;

    /**
     **********************************************************************
     * Function: SetIsCommitted
     *
     *   Author: $author$
     *     Date: 11/5/2004
     **********************************************************************
     */
    virtual bool SetIsCommitted(bool is=true) = 0;
    /**
     **********************************************************************
     * Function: IsCommitted
     *
     *   Author: $author$
     *     Date: 11/5/2004
     **********************************************************************
     */
    virtual bool IsCommitted() const = 0;

    /**
     **********************************************************************
     * Function: GetWriter
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual cCharWriterInterface& GetWriter() = 0;

    /**
     **********************************************************************
     * Function: GetOutputStream
     *
     *   Author: $author$
     *     Date: 11/6/2004
     **********************************************************************
     */
    virtual cOutputStreamInterface& GetOutputStream() = 0;
};

/**
 **********************************************************************
 *  Class: cServletResponseInterface
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cServletResponseInterface
: virtual public cServletResponseInterfaceT<>
{
public:
};

#endif /* ndef _CSERVLETRESPONSEINTERFACE_HXX */
