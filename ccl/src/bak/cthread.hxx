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
 *   File: cthread.hxx
 *
 * Author: $author$
 *   Date: 11/3/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTHREAD_HXX
#define _CTHREAD_HXX

#include "cthreadt.hxx"

/**
 **********************************************************************
 *  Class: cThread
 *
 * Author: $author$
 *   Date: 11/3/2004
 **********************************************************************
 */
class cThread
: public cThreadT<cThread>
{
public:
    typedef cThreadT<cThread> cIs;

    /**
     **********************************************************************
     * Constructor: cThread
     *
     *      Author: $author$
     *        Date: 11/3/2004
     **********************************************************************
     */
    cThread
    (THREAD handle=INVALID_THREAD, 
     bool opened=false, bool started=false) 
    : cIs(this, handle, opened, started) 
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual void OnRun() 
    {
    }
};

#endif /* ndef _CTHREAD_HXX */
