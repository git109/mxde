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
 *   File: cwinatom.hxx
 *
 * Author: $author$
 *   Date: 1/28/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINATOM_HXX
#define _CWINATOM_HXX

#include "cwinhandle.hxx"

/**
 **********************************************************************
 *  Class: cWinAtom
 *
 * Author: $author$
 *   Date: 1/24/2004
 **********************************************************************
 */
class cWinAtom
: public cHandleT<ATOM, 0>
{
public:
    typedef cHandleT<ATOM, 0> cIs;

    /**
     **********************************************************************
     * Constructor: cWinAtom
     *
     *      Author: $author$
     *        Date: 1/24/2004
     **********************************************************************
     */
    cWinAtom(ATOM atom=0) 
    : cIs(atom) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinAtom
     *
     *     Author: $author$
     *       Date: 1/24/2004
     **********************************************************************
     */
    virtual ~cWinAtom()
    {
    }
};

#endif /* _CWINATOM_HXX */


