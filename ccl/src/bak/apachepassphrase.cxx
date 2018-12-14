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
 *   File: apachepassphrase.cxx
 *
 * Author: $author$
 *   Date: 6/12/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _APACHEPASSPHRASE_CXX
#define _APACHEPASSPHRASE_CXX

#include "cmain.hxx"

/**
 **********************************************************************
 *  Class: cApachePassPhraseMain
 *
 * Author: $author$
 *   Date: 6/12/2004
 **********************************************************************
 */
class cApachePassPhraseMain
: public cMain
{
public:
    typedef cMain cIs;

    /**
     **********************************************************************
     * Constructor: cApachePassPhraseMain
     *
     *      Author: $author$
     *        Date: 6/12/2004
     **********************************************************************
     */
    cApachePassPhraseMain() 
    {
    }

    /**
     **********************************************************************
     * Function: OnMain
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnMain(int argc, char **argv)
    {
        int result=0;
        return result;
    }
} g_main;

#endif /* ndef _APACHEPASSPHRASE_CXX */
