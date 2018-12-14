/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: cverbosewriter.hxx
 *
 * Author: $author$
 *   Date: 1/4/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CVERBOSEWRITER_HXX
#define _CVERBOSEWRITER_HXX

#include "cverboseinterface.hxx"
#include "ccharwriter.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cVerboseWriter
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class cVerboseWriter
: virtual public cInitializeImplement,
  virtual public cPutcImplement,
  virtual public cCharWriterImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    cVerboseInterface& m_verbose;

    /**
     **********************************************************************
     * Constructor: cVerboseWriter
     *
     *      Author: $author$
     *        Date: 1/4/2006
     **********************************************************************
     */
    cVerboseWriter(cVerboseInterface& verbose) 
    : m_verbose(verbose)
    {
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual int Write(const char *buf, int len=-1) 
    {
        int result = -e_ERROR_FAILED;

        if (0 <= (len = m_verbose.Verbose(buf, len)))
            result = len;
        return result;
    }
};

#endif /* _CVERBOSEWRITER_HXX */
