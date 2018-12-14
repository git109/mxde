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
 *   File: ccontentresponseinterface.hxx
 *
 * Author: $author$
 *   Date: 10/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCONTENTRESPONSEINTERFACE_HXX
#define _CCONTENTRESPONSEINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cContentResponseInterfaceT
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cContentResponseInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: GetContentType
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual const char* GetContentType(int &length) const = 0;

    /**
     **********************************************************************
     * Function: SetContentLength
     *
     *   Author: $author$
     *     Date: 10/21/2004
     **********************************************************************
     */
    virtual int SetContentLength(int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetContentLength
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual int GetContentLength() const = 0;

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
     * Function: SetWriter
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual cCharWriterInterface& SetWriter
    (cCharWriterInterface* writer) = 0;
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
     * Function: SetOutputStream
     *
     *   Author: $author$
     *     Date: 11/6/2004
     **********************************************************************
     */
    virtual cOutputStreamInterface& SetOutputStream
    (cOutputStreamInterface *output) = 0;
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
 *  Class: cContentResponseInterface
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
class cContentResponseInterface
: virtual public cContentResponseInterfaceT<>
{
public:
};

#endif /* ndef _CCONTENTRESPONSEINTERFACE_HXX */
