/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: cdocumenttransformcgi.hxx
 *
 * Author: $author$
 *   Date: 10/9/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTTRANSFORMCGI_HXX
#define _CDOCUMENTTRANSFORMCGI_HXX

#include "cdocumentcgi.hxx"

/**
 **********************************************************************
 *  Class: cDocumentTransformCGI
 *
 * Author: $author$
 *   Date: 10/9/2005
 **********************************************************************
 */
class cDocumentTransformCGI
: public cDocumentCGI
{
public:
    typedef cDocumentCGI cIs;

    cDocumentInterface *m_template_document;

    /**
     **********************************************************************
     * Constructor: cDocumentTransformCGI
     *
     *      Author: $author$
     *        Date: 10/9/2005
     **********************************************************************
     */
    cDocumentTransformCGI
    (const char *name="cDocumentTransformCGI") 
    : cIs(name),
      m_template_document(0) 
    {
    }
};

#endif /* _CDOCUMENTTRANSFORMCGI_HXX */