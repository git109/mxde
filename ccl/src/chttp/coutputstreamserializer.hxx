/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: coutputstreamserializer.hxx
 *
 * Author: $author$
 *   Date: 2/19/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _COUTPUTSTREAMSERIALIZER_HXX
#define _COUTPUTSTREAMSERIALIZER_HXX

#include "cstreamserializerinterfacet.hxx"
#include "cinitializerinterface.hxx"
#include "coutputstreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cOutputStreamSerializerInterface
 *
 * Author: $author$
 *   Date: 2/19/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cOutputStreamSerializerInterface
: virtual public cStreamSerializerInterfaceT
  <cOutputStreamInterface, BYTE, 
   int, -1, cInitializerInterface>
{
public:
    typedef cStreamSerializerInterfaceT
    <cOutputStreamInterface, BYTE, 
     int, -1, cInitializerInterface> cIs;
};

/**
 **********************************************************************
 *  Class: cOutputStreamSerializerImplement
 *
 * Author: $author$
 *   Date: 2/19/2006
 **********************************************************************
 */
class cOutputStreamSerializerImplement
: virtual public cStreamSerializerImplementT
  <cOutputStreamInterface, BYTE, 
   int, -1, cOutputStreamSerializerInterface>
{
public:
    typedef cStreamSerializerImplementT
    <cOutputStreamInterface, BYTE, 
     int, -1, cOutputStreamSerializerInterface> cIs;
};

/**
 **********************************************************************
 *  Class: cOutputStreamSerializer
 *
 * Author: $author$
 *   Date: 2/19/2006
 **********************************************************************
 */
class cOutputStreamSerializer
: virtual public cInitializerImplement,
  virtual public cOutputStreamSerializerImplement
{
public:
    /**
     **********************************************************************
     * Constructor: cOutputStreamSerializer
     *
     *      Author: $author$
     *        Date: 2/19/2006
     **********************************************************************
     */
    cOutputStreamSerializer() 
    {
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual int Get(BYTE& of)
    {
        int result;

        if (0 <= (result = Getb()))
        {
            of = result;
            result = sizeof(BYTE);
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: Getb
     *
     *   Author: $author$
     *     Date: 2/8/2006
     **********************************************************************
     */
    virtual int Getb() 
    {
        int result = -e_ERROR_ENDOF;
        return result;
    }
};

#endif /* _COUTPUTSTREAMSERIALIZER_HXX */
