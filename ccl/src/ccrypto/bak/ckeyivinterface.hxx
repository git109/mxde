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
 *   File: ckeyivinterface.hxx
 *
 * Author: $author$
 *   Date: 1/7/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CKEYIVINTERFACE_HXX
#define _CKEYIVINTERFACE_HXX


#include "ckeyinterface.hxx"
#include "civinterface.hxx"
/**
 **********************************************************************
 *  Class: cKeyIVInterface
 *
 * Author: $author$
 *   Date: 1/7/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cKeyIVInterface
: virtual public cKeyInterface,
  virtual public cIVInterface
{
public:
    /**
     **********************************************************************
     * Function: SetKeyIV
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    virtual int SetKeyIV
    (const BYTE *key,
     int keylen=-1,
     const BYTE *iv=0,
     int ivlen=-1) = 0;
};

#endif /* _CKEYIVINTERFACE_HXX */