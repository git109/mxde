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
 *   File: chashinterface.hxx
 *
 * Author: $author$
 *   Date: 1/7/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHASHINTERFACE_HXX
#define _CHASHINTERFACE_HXX

#include "ckeyinterface.hxx"
#include "cblocksizeinterface.hxx"

/**
 **********************************************************************
 *  Class: cHashInterface
 *
 * Author: $author$
 *   Date: 1/7/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cHashInterface
: virtual public cKeyInterface,
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
    (const BYTE *key=0, int keylen=-1) = 0;
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 1/8/2005
     **********************************************************************
     */
    virtual int Finalize
    (BYTE *out, int outsize) = 0;
    /**
     **********************************************************************
     * Function: HashFill
     *
     *   Author: $author$
     *     Date: 2/12/2005
     **********************************************************************
     */
    virtual int HashFill
    (BYTE in, int inrepeat=1) = 0;
    /**
     **********************************************************************
     * Function: Hash
     *
     *   Author: $author$
     *     Date: 1/7/2005
     **********************************************************************
     */
    virtual int Hash
    (const BYTE *in, int inlen=-1) = 0;
    /**
     **********************************************************************
     * Function: GetHashSize
     *
     *   Author: $author$
     *     Date: 2/1/2005
     **********************************************************************
     */
    virtual int GetHashSize() const =0;
};

/**
 **********************************************************************
 *  Class: cHashImplement
 *
 * Author: $author$
 *   Date: 1/8/2005
 **********************************************************************
 */
class cHashImplement
: virtual public cHashInterface,
  virtual public cKeyImplement,
  virtual public cBlockSizeImplement
{
public:
    /**
     **********************************************************************
     * Function: GetHashSize
     *
     *   Author: $author$
     *     Date: 2/1/2005
     **********************************************************************
     */
    virtual int GetHashSize() const 
    {
        int size = -e_ERROR_NOT_IMPLEMENTED;
        return size;
    }
};

#endif /* _CHASHINTERFACE_HXX */