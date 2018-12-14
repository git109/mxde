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
 *   File: cinputstreamdeserializer.hxx
 *
 * Author: $author$
 *   Date: 2/17/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CINPUTSTREAMDESERIALIZER_HXX
#define _CINPUTSTREAMDESERIALIZER_HXX

#include "cstreamdeserializerinterfacet.hxx"
#include "cinitializerinterface.hxx"
#include "cinputstreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cInputStreamDeserializerInterface
 *
 * Author: $author$
 *   Date: 2/17/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cInputStreamDeserializerInterface
: virtual public cStreamDeserializerInterfaceT
  <cInputStreamInterface, 
   BYTE, int, -1, int, -1, 
   cInitializerInterface>
{
public:
    typedef cStreamDeserializerInterfaceT
    <cInputStreamInterface, 
     BYTE, int, -1, int, -1, 
     cInitializerInterface> cIs;
};

/**
 **********************************************************************
 *  Class: cInputStreamDeserializerImplement
 *
 * Author: $author$
 *   Date: 2/17/2006
 **********************************************************************
 */
class cInputStreamDeserializerImplement
: virtual public cStreamDeserializerImplementT
  <cInputStreamInterface, 
   BYTE, int, -1, int, -1, 
   cInputStreamDeserializerInterface>
{
public:
    typedef cStreamDeserializerImplementT
    <cInputStreamInterface, 
     BYTE, int, -1, int, -1, 
     cInputStreamDeserializerInterface> cIs;
};

/**
 **********************************************************************
 *  Class: cInputStreamDeserializer
 *
 * Author: $author$
 *   Date: 2/17/2006
 **********************************************************************
 */
class cInputStreamDeserializer
: virtual public cInitializerImplement,
  virtual public cInputStreamDeserializerImplement
{
public:
    bool m_done;

    /**
     **********************************************************************
     * Constructor: cInputStreamDeserializer
     *
     *      Author: $author$
     *        Date: 2/17/2006
     **********************************************************************
     */
    cInputStreamDeserializer() 
    : m_done(false)
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        m_done = false;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetIsDone
     *
     *   Author: $author$
     *     Date: 2/17/2006
     **********************************************************************
     */
    virtual bool SetIsDone(bool is_done=true) 
    {
        return m_done = is_done;
    }
    /**
     **********************************************************************
     * Function: GetIsDone
     *
     *   Author: $author$
     *     Date: 2/17/2006
     **********************************************************************
     */
    virtual bool GetIsDone() const
    {
        return m_done;
    }
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual int Put(BYTE& of)
    {
        int result;

        if (0 <= (result = Putb(of)))
            result = sizeof(BYTE);
        return result;
    }
    /**
     **********************************************************************
     * Function: Putb
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual int Putb(BYTE b) 
    {
        int result = b;
        return result;
    }
};

#endif /* _CINPUTSTREAMDESERIALIZER_HXX */


