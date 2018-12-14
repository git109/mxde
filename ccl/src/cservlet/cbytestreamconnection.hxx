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
 *   File: cbytestreamconnection.hxx
 *
 * Author: $author$
 *   Date: 9/11/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTESTREAMCONNECTION_HXX
#define _CBYTESTREAMCONNECTION_HXX

#include "cbytestreamiconnectionnterface.hxx"

/**
 **********************************************************************
 *  Class: cBYTEStreamConnectionT
 *
 * Author: $author$
 *   Date: 9/11/2005
 **********************************************************************
 */
template
<class TIs=cConnection,
 class TInterfaceIs=cBYTEStreamConnectionInterface>

class cBYTEStreamConnectionT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    cBYTEStreamInterface &m_stream;

    /**
     **********************************************************************
     * Constructor: cBYTEStreamConnectionT
     *
     *      Author: $author$
     *        Date: 9/11/2005
     **********************************************************************
     */
    cBYTEStreamConnectionT
    (cBYTEStreamInterface &stream, bool keep_alive_on=false) 
    : cIs(keep_alive_on),
      m_stream(stream)
    {
    }
    /**
     **********************************************************************
     * Function: GetStream
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual cBYTEStreamInterface& GetStream() const
    {
        return m_stream;
    }
};

/**
 **********************************************************************
 *  Class: cBYTEStreamConnection
 *
 * Author: $author$
 *   Date: 9/11/2005
 **********************************************************************
 */
class cBYTEStreamConnection
: public cBYTEStreamConnectionT<>
{
public:
    typedef cBYTEStreamConnectionT<> cIs;

    /**
     **********************************************************************
     * Constructor: cBYTEStreamConnection
     *
     *      Author: $author$
     *        Date: 9/11/2005
     **********************************************************************
     */
    cBYTEStreamConnection
    (cBYTEStreamInterface &stream, bool keep_alive_on=false) 
    : cIs(stream, keep_alive_on) 
    {
    }
};

#endif /* _CBYTESTREAMCONNECTION_HXX */