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
 *   File: ccipherinterface.hxx
 *
 * Author: $author$
 *   Date: 1/7/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCIPHERINTERFACE_HXX
#define _CCIPHERINTERFACE_HXX

#include "ckeyinterface.hxx"
#include "civinterface.hxx"
#include "cblocksizeinterface.hxx"
#include "cbytestreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cCipherInterface
 *
 * Author: $author$
 *   Date: 1/7/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cCipherInterface
: virtual public cKeyInterface,
  virtual public cIVInterface,
  virtual public cBlockSizeInterface
{
public:
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual int Initialize
    (const BYTE *key, int keylen=-1,
     const BYTE *iv=0, int ivlen=-1,
     cBYTEStreamInterface *padding=0) = 0;
    /**
     **********************************************************************
     * Function: Crypt
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    virtual int Crypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1) = 0;
    /**
     **********************************************************************
     * Function: Encrypt
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    virtual int Encrypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1) = 0;
    /**
     **********************************************************************
     * Function: Decrypt
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    virtual int Decrypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1) = 0;
};

/**
 **********************************************************************
 *  Class: cCipherImplement
 *
 * Author: $author$
 *   Date: 1/8/2005
 **********************************************************************
 */
class cCipherImplement
: virtual public cCipherInterface,
  virtual public cKeyImplement,
  virtual public cIVImplement,
  virtual public cBlockSizeImplement
{
public:
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual int Initialize
    (const BYTE *key, int keylen=-1,
     const BYTE *iv=0, int ivlen=-1,
     cBYTEStreamInterface *padding=0)
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: Crypt
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    virtual int Crypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1)
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: Encrypt
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    virtual int Encrypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1)
    {
        int result = Crypt(out, outsize, in , inlen);
        return result;
    }
    /**
     **********************************************************************
     * Function: Decrypt
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    virtual int Decrypt
    (BYTE *out, int outsize, const BYTE *in, int inlen=-1)
    {
        int result = Crypt(out, outsize, in , inlen);
        return result;
    }
};

#endif /* _CCIPHERINTERFACE_HXX */