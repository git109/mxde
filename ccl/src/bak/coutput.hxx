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
 *   File: coutput.hxx
 *
 * Author: $author$
 *   Date: 11/29/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _COUTPUT_HXX
#define _COUTPUT_HXX

#include "coutputt.hxx"
#include "coutputinterface.hxx"

/**
 **********************************************************************
 *  Class: cOutput
 *
 * Author: $author$
 *   Date: 11/29/2003
 **********************************************************************
 */
class cOutput
: virtual public cOutputInterface,
  public cOutputT<cOutputImplement>
{
public:
    typedef cOutputT<cOutputImplement> cIs;

    /**
     **********************************************************************
     * Constructor: cOutput
     *
     *      Author: $author$
     *        Date: 11/29/2003
     **********************************************************************
     */
    cOutput
    (cCharStreamInterface *out=0,
     cCharStreamInterface *err=0)
    : cIs(out, err)
    {
    }
};

#endif /* ndef _COUTPUT_HXX */
