/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: cccharwriterinterface.hxx
 *
 * Author: $author$
 *   Date: 12/26/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CCCHARWRITERINTERFACE_HXX
#define _CCCHARWRITERINTERFACE_HXX

#include "ccharwriterinterface.hxx"
#include "cwriterinterface.hxx"
#include "cinitializeinterface.hxx"

/**
 **********************************************************************
 *  Class: cCCharWriterInterface
 *
 * Author: $author$
 *   Date: 12/26/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cCCharWriterInterface
: virtual public cInitializeInterface,
  virtual public cPutcInterface,
  virtual public cWriterInterfaceT<cChar>
{
public:
};

/**
 **********************************************************************
 *  Class: cCCharWriterImplement
 *
 * Author: $author$
 *   Date: 12/26/2005
 **********************************************************************
 */
class cCCharWriterImplement
: virtual public cWriterImplementT
  <cChar, cCCharWriterInterface>
{
public:
    /**
     **********************************************************************
     * Function: Putc
     *
     *   Author: $author$
     *     Date: 6/29/2005
     **********************************************************************
     */
    virtual int Putc(int c)
    {
        cChar cc((char)c);
        int result;
        
        if (0 <= (result = Put(cc)))
            result = c;
        return result;
    }
};

#endif /* _CCCHARWRITERINTERFACE_HXX */
