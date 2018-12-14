/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: ccharfile.hxx
 *
 * Author: $author$
 *   Date: 7/5/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARFILE_HXX
#define _CCHARFILE_HXX

#include "ccharfilet.hxx"
#include "ccharstream.hxx"

/**
 **********************************************************************
 *  Class: cCharFile
 *
 * Author: $author$
 *   Date: 7/5/2003
 **********************************************************************
 */
class cCharFile
: virtual public cCharStreamInterface,
  public cCharFileT<cCharStream>
{
public:
    typedef cCharFileT<cCharStream> cIs;

    /**
     **********************************************************************
     * Constructor: cCharFile
     *
     *      Author: $author$
     *        Date: 7/5/2003
     **********************************************************************
     */
    cCharFile(FILE *file=NULL, bool opened=false) 
    : cIs(file, opened) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cCharFile
     *
     *      Author: $author$
     *        Date: 7/5/2003
     **********************************************************************
     */
    cCharFile(const char *path, const char *mode="r") 
    : cIs(path, mode) 
    {
    }
};


#endif
