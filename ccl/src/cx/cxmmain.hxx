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
 *   File: cxmmain.hxx
 *
 * Author: $author$
 *   Date: 4/28/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXMMAIN_HXX
#define _CXMMAIN_HXX

#include "cxtmain.hxx"

/**
 **********************************************************************
 *  Class: cXmMain
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
class cXmMain
: public cXtMain
{
public:
    typedef cXtMain cIs;

    /**
     **********************************************************************
     * Constructor: cXmMain
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXmMain
    (String display_name=0,
     String name="cXmMain",
     String class_name="cXmMain")
    : cIs(display_name, name, class_name)
    {
    }
};

#endif /* ndef _CXMMAIN_HXX */
