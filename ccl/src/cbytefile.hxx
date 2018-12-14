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
 *   File: cbytefile.hxx
 *
 * Author: $author$
 *   Date: 2/3/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTEFILE_HXX
#define _CBYTEFILE_HXX

#include "cbytefilet.hxx"

/**
 **********************************************************************
 *  Class: cBYTEFile
 *
 * Author: $author$
 *   Date: 2/3/2005
 **********************************************************************
 */
class cBYTEFile
: public cBYTEFileT<>
{
public:
    typedef cBYTEFileT<> cIs;

    /**
     **********************************************************************
     * Constructor: cBYTEFileT
     *
     *      Author: $author$
     *        Date: 2/3/2005
     **********************************************************************
     */
    cBYTEFile(FILE *handle=NULL, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cBYTEFileT
     *
     *      Author: $author$
     *        Date: 2/3/2005
     **********************************************************************
     */
    cBYTEFile(const char *path) 
    : cIs(path) 
    {
    }
};

#endif /* _CBYTEFILE_HXX */