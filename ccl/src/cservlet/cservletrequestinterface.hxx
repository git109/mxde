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
 *   File: cservletrequestinterface.hxx
 *
 * Author: $author$
 *   Date: 10/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSERVLETREQUESTINTERFACE_HXX
#define _CSERVLETREQUESTINTERFACE_HXX

#include "ccharreaderinterface.hxx"
#include "cinputstreaminterface.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cServletRequestInterfaceT
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cServletRequestInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: GetContentType
     *
     *   Author: $author$
     *     Date: 10/21/2004
     **********************************************************************
     */
    virtual const char* GetContentType(int &len) const = 0;
    /**
     **********************************************************************
     * Function: GetContentLength
     *
     *   Author: $author$
     *     Date: 10/21/2004
     **********************************************************************
     */
    virtual int GetContentLength() const = 0;

    /**
     **********************************************************************
     * Function: GetParameter
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual const char* GetParameter
    (int &length, const char *name, int namelen=-1) = 0;

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
     * Function: GetInputStream
     *
     *   Author: $author$
     *     Date: 11/6/2004
     **********************************************************************
     */
    virtual cInputStreamInterface& GetInputStream() = 0;
};

/**
 **********************************************************************
 *  Class: cServletRequestInterface
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cServletRequestInterface
: virtual public cServletRequestInterfaceT<>
{
public:
};

#endif /* ndef _CSERVLETREQUESTINTERFACE_HXX */
