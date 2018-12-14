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
 *   File: ccharreadwritefilet.hxx
 *
 * Author: $author$
 *   Date: 6/9/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARREADWRITEFILET_HXX
#define _CCHARREADWRITEFILET_HXX

#include "creadwritefilet.hxx"
#include "ccharstreamt.hxx"
#include "ccharstream.hxx"
#include "ccharstreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cCharReadWriteFileT
 *
 * Author: $author$
 *   Date: 6/9/2004
 **********************************************************************
 */
template <class TIs=cCharStreamT<cStream> >
class cCharReadWriteFileT
: virtual public cCharStreamInterface,
  public cReadWriteFileT<char, TIs>
{
public:
    typedef cReadWriteFileT<char, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cCharReadWriteFileT
     *
     *      Author: $author$
     *        Date: 6/9/2004
     **********************************************************************
     */
    cCharReadWriteFileT(FILE *read_file=0, FILE *write_file=0) 
    : cIs(read_file, write_file) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cCharReadWriteFileT
     *
     *     Author: $author$
     *       Date: 6/9/2004
     **********************************************************************
     */
    virtual ~cCharReadWriteFileT()
    {
    }

    /**
     **********************************************************************
     * Function: VPrintFormatted
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    virtual int VPrintFormatted(const char *format, va_list va)
    {
        int count;

        if (!m_write_handle)
            return -e_ERROR_NOT_ATTACHED;

        if ((count = vfprintf(m_write_handle, format, va)) < 0)
            return -e_ERROR_VPRINT_FORMATTED;

        return count;
    }
};

/**
 **********************************************************************
 *  Class: cCharReadWriteFile
 *
 * Author: $author$
 *   Date: 6/9/2004
 **********************************************************************
 */
class cCharReadWriteFile
: virtual public cCharStreamInterface,
  public cCharReadWriteFileT<cCharStream>
{
public:
    typedef cCharReadWriteFileT<cCharStream> cIs;

    /**
     **********************************************************************
     * Constructor: cCharReadWriteFile
     *
     *      Author: $author$
     *        Date: 6/9/2004
     **********************************************************************
     */
    cCharReadWriteFile(FILE *read_file=0, FILE *write_file=0) 
    : cIs(read_file, write_file) 
    {
    }
};

#endif /* ndef _CCHARREADWRITEFILET_HXX */
