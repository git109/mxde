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
 *   File: csslpad.hxx
 *
 * Author: $author$
 *   Date: 1/25/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLPAD_HXX
#define _CSSLPAD_HXX

#include "cmd5.hxx"
#include "csha1.hxx"

/**
 **********************************************************************
 *  Class: cSSLPad
 *
 * Author: $author$
 *   Date: 1/25/2005
 **********************************************************************
 */
class cSSLPad
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/25/2005
     **********************************************************************
     */
    enum
    {
        e_SHA1 = 40,
        e_MD5  = 48,

        e_ALL  = e_MD5
    };

    uint8 m_pad[e_ALL];

    /**
     **********************************************************************
     * Constructor: cSSLPad
     *
     *      Author: $author$
     *        Date: 1/25/2005
     **********************************************************************
     */
    cSSLPad(uint8 value) 
    {
        memset(m_pad, value, sizeof(m_pad));
    }
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 1/25/2005
     **********************************************************************
     */
    int Put(cMD5 &hash) 
    {
        int length = hash.Hash(m_pad, e_MD5);
        return length;
    }
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 1/25/2005
     **********************************************************************
     */
    int Put(cSHA1 &hash) 
    {
        int length = hash.Hash(m_pad, e_SHA1);
        return length;
    }
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 1/25/2005
     **********************************************************************
     */
    virtual int Put(cHash &hash) = 0;
};

/**
 **********************************************************************
 *  Class: cSSLPad1
 *
 * Author: $author$
 *   Date: 1/25/2005
 **********************************************************************
 */
class cSSLPad1
: public cSSLPad
{
public:
    typedef cSSLPad cIs;

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/25/2005
     **********************************************************************
     */
    enum
    {
        e_VALUE = 0x36
    };

    /**
     **********************************************************************
     * Constructor: cSSLPad1
     *
     *      Author: $author$
     *        Date: 1/25/2005
     **********************************************************************
     */
    cSSLPad1() 
    : cIs(e_VALUE)
    {
    }
};

/**
 **********************************************************************
 *  Class: cSSLMD5Pad1
 *
 * Author: $author$
 *   Date: 1/25/2005
 **********************************************************************
 */
class cSSLMD5Pad1
: public cSSLPad1
{
public:
    typedef cSSLPad1 cIs;

    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 1/25/2005
     **********************************************************************
     */
    virtual int Put(cHash &hash) 
    {
        int length = hash.Hash(m_pad, e_MD5);
        return length;
    }
};

/**
 **********************************************************************
 *  Class: cSSLSHA1Pad1
 *
 * Author: $author$
 *   Date: 1/25/2005
 **********************************************************************
 */
class cSSLSHA1Pad1
: public cSSLPad1
{
public:
    typedef cSSLPad1 cIs;

    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 1/25/2005
     **********************************************************************
     */
    virtual int Put(cHash &hash) 
    {
        int length = hash.Hash(m_pad, e_SHA1);
        return length;
    }
};

/**
 **********************************************************************
 *  Class: cSSLPad2
 *
 * Author: $author$
 *   Date: 1/25/2005
 **********************************************************************
 */
class cSSLPad2
: public cSSLPad
{
public:
    typedef cSSLPad cIs;

    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/25/2005
     **********************************************************************
     */
    enum
    {
        e_VALUE = 0x5c
    };

    /**
     **********************************************************************
     * Constructor: cSSLPad2
     *
     *      Author: $author$
     *        Date: 1/25/2005
     **********************************************************************
     */
    cSSLPad2() 
    : cIs(e_VALUE)
    {
    }
};

/**
 **********************************************************************
 *  Class: cSSLMD5Pad2
 *
 * Author: $author$
 *   Date: 1/25/2005
 **********************************************************************
 */
class cSSLMD5Pad2
: public cSSLPad2
{
public:
    typedef cSSLPad2 cIs;

    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 1/25/2005
     **********************************************************************
     */
    virtual int Put(cHash &hash) 
    {
        int length = hash.Hash(m_pad, e_MD5);
        return length;
    }
};

/**
 **********************************************************************
 *  Class: cSSLSHA1Pad2
 *
 * Author: $author$
 *   Date: 1/25/2005
 **********************************************************************
 */
class cSSLSHA1Pad2
: public cSSLPad2
{
public:
    typedef cSSLPad2 cIs;

    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 1/25/2005
     **********************************************************************
     */
    virtual int Put(cHash &hash) 
    {
        int length = hash.Hash(m_pad, e_SHA1);
        return length;
    }
};

#endif /* _CSSLPAD_HXX */
