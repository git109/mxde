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
 *   File: cfilehandle.hxx
 *
 * Author: $author$
 *   Date: 9/29/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEHANDLE_HXX
#define _CFILEHANDLE_HXX

#include <stdio.h>
#include "chandlet.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cFileHandleT
 *
 * Author: $author$
 *   Date: 9/29/2004
 **********************************************************************
 */
template <class TIs=cBase>
class cFileHandleT
: public cHandleT<FILE*, NULL, TIs>
{
public:
    typedef cHandleT<FILE*, NULL, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cFileHandleT
     *
     *      Author: $author$
     *        Date: 9/29/2004
     **********************************************************************
     */
    cFileHandleT(FILE* handle=NULL) 
    : cIs(handle) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cFileHandle
 *
 * Author: $author$
 *   Date: 9/29/2004
 **********************************************************************
 */
class cFileHandle
: public cFileHandleT<>
{
public:
    typedef cFileHandleT<> cIs;

    /**
     **********************************************************************
     * Constructor: cFileHandle
     *
     *      Author: $author$
     *        Date: 9/29/2004
     **********************************************************************
     */
    cFileHandle(FILE* handle=NULL) 
    : cIs(handle) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cFileHandleInstance
 *
 * Author: $author$
 *   Date: 7/1/2005
 **********************************************************************
 */
class cFileHandleInstance
: public cFileHandleT<cInstance>
{
public:
    typedef cFileHandleT<cInstance> cIs;

    /**
     **********************************************************************
     * Constructor: cFileHandleInstance
     *
     *      Author: $author$
     *        Date: 7/1/2005
     **********************************************************************
     */
    cFileHandleInstance(FILE* handle=NULL) 
    : cIs(handle) 
    {
    }
};

#endif /* ndef _CFILEHANDLE_HXX */
