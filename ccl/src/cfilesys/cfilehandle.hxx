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
 *   File: cfilehandle.hxx
 *
 * Author: $author$
 *   Date: 1/15/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CFILEHANDLE_HXX
#define _CFILEHANDLE_HXX

#include "cfilehandlet.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cFileHandle
 *
 * Author: $author$
 *   Date: 1/15/2006
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
     *        Date: 1/15/2006
     **********************************************************************
     */
    cFileHandle(FILE *file=0, bool opened=false) 
    : cIs(file, opened) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cFileHandle
     *
     *      Author: $author$
     *        Date: 1/15/2006
     **********************************************************************
     */
    virtual ~cFileHandle()
    {
    }
};

/**
 **********************************************************************
 *  Class: cFileHandleInstance
 *
 * Author: $author$
 *   Date: 1/15/2006
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
     *        Date: 1/15/2006
     **********************************************************************
     */
    cFileHandleInstance(FILE *file=0, bool opened=false) 
    : cIs(file, opened) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cFileHandleInstance
     *
     *      Author: $author$
     *        Date: 1/15/2006
     **********************************************************************
     */
    virtual ~cFileHandleInstance()
    {
    }
};

#endif /* _CFILEHANDLE_HXX */

