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
 *   File: coutputinterface.hxx
 *
 * Author: $author$
 *   Date: 2/2/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _COUTPUTINTERFACE_HXX
#define _COUTPUTINTERFACE_HXX

#include <stdarg.h>

#include "cinterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cOutputInterface
 *
 * Author: $author$
 *   Date: 11/29/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cOutputInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: OutputErrorL
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual int OutputErrorL(const char *buffer, ...)=0;
    /**
     **********************************************************************
     * Function: VOutputError
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual int VOutputError(va_list va)=0;
    /**
     **********************************************************************
     * Function: OutputError
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual int OutputError(const char *buffer, int length=-1)=0;

    /**
     **********************************************************************
     * Function: OutputL
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual int OutputL(const char *buffer, ...)=0;
    /**
     **********************************************************************
     * Function: VOutput
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual int VOutput(va_list va)=0;
    /**
     **********************************************************************
     * Function: Output
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual int Output(const char *buffer, int length=-1)=0;
};

/**
 **********************************************************************
 *  Class: cOutputImplement
 *
 * Author: $author$
 *   Date: 10/8/2004
 **********************************************************************
 */
class cOutputImplement
: virtual public cOutputInterface,
  public cImplement
{
public:
    typedef cImplement cIs;
};

#endif /* ndef _COUTPUTINTERFACE_HXX */
