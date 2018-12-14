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
 *   File: ccontentrequestinterface.hxx
 *
 * Author: $author$
 *   Date: 10/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCONTENTREQUESTINTERFACE_HXX
#define _CCONTENTREQUESTINTERFACE_HXX

#include "ccharreaderinterface.hxx"
#include "cinputstreaminterface.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cContentRequestInterfaceT
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cContentRequestInterfaceT
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
     * Function: SetParameter
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual int SetParameter
    (const char *name, int namelen=-1, 
     const char *value=0, int valuelen=-1) = 0;

    /**
     **********************************************************************
     * Function: SetReader
     *
     *   Author: $author$
     *     Date: 11/6/2004
     **********************************************************************
     */
    virtual cCharReaderInterface& SetReader
    (cCharReaderInterface *reader) = 0;
    /**
     **********************************************************************
     * Function: GetReader
     *
     *   Author: $author$
     *     Date: 11/6/2004
     **********************************************************************
     */
    virtual cCharReaderInterface& GetReader() = 0;

    /**
     **********************************************************************
     * Function: SetInputStream
     *
     *   Author: $author$
     *     Date: 11/6/2004
     **********************************************************************
     */
    virtual cInputStreamInterface& SetInputStream
    (cInputStreamInterface *input) = 0;
    /**
     **********************************************************************
     * Function: GetInputStream
     *
     *   Author: $author$
     *     Date: 11/6/2004
     **********************************************************************
     */
    virtual cInputStreamInterface& GetInputStream() = 0;

    /**
     **********************************************************************
     * Function: SetIsConsumed
     *
     *   Author: $author$
     *     Date: 11/11/2004
     **********************************************************************
     */
    virtual bool SetIsConsumed(bool is=true) = 0;
    /**
     **********************************************************************
     * Function: IsConsumed
     *
     *   Author: $author$
     *     Date: 11/11/2004
     **********************************************************************
     */
    virtual bool IsConsumed() const = 0;
};

/**
 **********************************************************************
 *  Class: cContentRequestInterface
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cContentRequestInterface
: virtual public cContentRequestInterfaceT<>
{
public:
};

#endif /* ndef _CCONTENTREQUESTINTERFACE_HXX */
