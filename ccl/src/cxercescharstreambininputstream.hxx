/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: cxercescharstreambininputstream.hxx
 *
 * Author: $author$
 *   Date: 11/6/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXERCESCHARSTREAMBININPUTSTREAM_HXX
#define _CXERCESCHARSTREAMBININPUTSTREAM_HXX

#include <util/BinInputStream.hpp>

#include "ccharstreaminterface.hxx"
#include "nsxerces.hxx"

/**
 **********************************************************************
 *  Class: cXercesCharStreamBinInputStream
 *
 * Author: $author$
 *   Date: 11/6/2003
 **********************************************************************
 */
class cXercesCharStreamBinInputStream
: public nsXerces::BinInputStream
{
public:
    typedef nsXerces::BinInputStream cIs;

    cCharStreamInterface &m_stream;

    /**
     **********************************************************************
     * Constructor: cXercesCharStreamBinInputStream
     *
     *      Author: $author$
     *        Date: 11/6/2003
     **********************************************************************
     */
    cXercesCharStreamBinInputStream(cCharStreamInterface &stream) 
    : m_stream(stream)
    {
    }

    /**
     **********************************************************************
     * Function: curPos
     *
     *   Author: $author$
     *     Date: 11/6/2003
     **********************************************************************
     */
    virtual unsigned int curPos() const
    {
        int told;

        if (0 <= (told = m_stream.Tell()))
            return told;

        return 0;
    }
    /**
     **********************************************************************
     * Function: readBytes
     *
     *   Author: $author$
     *     Date: 11/6/2003
     **********************************************************************
     */
    virtual unsigned int readBytes
    (XMLByte *const toFill, const unsigned int maxToRead)
    {
        int count;

        if (0 <= (count = m_stream.Read((char*)toFill, maxToRead)))
            return count;

        return 0;
    }
};

#endif
