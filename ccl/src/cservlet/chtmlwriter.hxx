/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: chtmlwriter.hxx
 *
 * Author: $author$
 *   Date: 11/13/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTMLWRITER_HXX
#define _CHTMLWRITER_HXX

#include "cxmlwriter.hxx"

/**
 **********************************************************************
 *  Class: cHTMLWriter
 *
 * Author: $author$
 *   Date: 11/13/2005
 **********************************************************************
 */
class cHTMLWriter
: public cXMLWriter
{
public:
    typedef cXMLWriter cIs;

    /**
     **********************************************************************
     * Constructor: cHTMLWriter
     *
     *      Author: $author$
     *        Date: 11/13/2005
     **********************************************************************
     */
    cHTMLWriter(cXMLParserEventInterface &proxy) 
    : cIs(proxy)
    {
    }
};

#endif /* _CHTMLWRITER_HXX */
