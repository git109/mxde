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
 *   File: ccharfilet.hxx
 *
 * Author: $author$
 *   Date: 7/5/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARFILET_HXX
#define _CCHARFILET_HXX

#include "cfilet.hxx"
#include "ccharstreamt.hxx"
#include "ccharstreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cCharFileT
 *
 * Author: $author$
 *   Date: 7/5/2003
 **********************************************************************
 */
template <class TIs=cCharStreamT<cStream> >
class cCharFileT
: virtual public cCharStreamInterface,
  public cFileT<char, TIs>
{
public:
    typedef cFileT<char, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cCharFileT
     *
     *      Author: $author$
     *        Date: 7/5/2003
     **********************************************************************
     */
    cCharFileT(FILE *handle=NULL, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cCharFileT
     *
     *      Author: $author$
     *        Date: 7/5/2003
     **********************************************************************
     */
    cCharFileT(const char *path, const char *mode="r") 
    : cIs(path, mode) 
    {
    }
    /**
     **********************************************************************
     * Function: VPrintFormatted
     *
     *   Author: $author$
     *     Date: 8/9/2003
     **********************************************************************
     */
    virtual int VPrintFormatted(const char *format, va_list va)
    {
        int count;

        if (!this->m_handle)
            return -e_ERROR_NOT_ATTACHED;

        if ((count = vfprintf(this->m_handle, format, va)) < 0)
            return -e_ERROR_VPRINT_FORMATTED;

        return count;
    }
};


#endif
