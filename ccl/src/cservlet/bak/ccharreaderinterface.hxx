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
 *   File: ccharreaderinterface.hxx
 *
 * Author: $author$
 *   Date: 11/7/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARREADERINTERFACE_HXX
#define _CCHARREADERINTERFACE_HXX

#include "creaderinterface.hxx"

/**
 **********************************************************************
 *  Class: cCharReaderInterface
 *
 * Author: $author$
 *   Date: 9/26/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cCharReaderInterface
: virtual public cReaderInterfaceT<char>
{
public:
    /**
     **********************************************************************
     * Function: Getc
     *
     *   Author: $author$
     *     Date: 12/14/2004
     **********************************************************************
     */
    virtual int Getc() = 0;
};

/**
 **********************************************************************
 *  Class: cCharReaderImplement
 *
 * Author: $author$
 *   Date: 9/26/2004
 **********************************************************************
 */
class cCharReaderImplement
: virtual public cReaderImplementT
  <char, cCharReaderInterface>
{
public:
    /**
     **********************************************************************
     * Function: Getc
     *
     *   Author: $author$
     *     Date: 12/14/2004
     **********************************************************************
     */
    virtual int Getc() 
    {
        int count, result = -e_ERROR_FAILED;
        char c;

        if (sizeof(c) == (count = Read(&c, sizeof(c))))
            result = c;
        return result;
    }
};

#endif /* ndef _CCHARREADERINTERFACE_HXX */
