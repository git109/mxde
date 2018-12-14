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
 *   File: cfiledocumentsource.hxx
 *
 * Author: $author$
 *   Date: 2/5/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILEDOCUMENTSOURCE_HXX
#define _CFILEDOCUMENTSOURCE_HXX

#include "ccharfilet.hxx"
#include "cdocumentsourceinterface.hxx"

/**
 **********************************************************************
 *  Class: cFileDocumentSource
 *
 * Author: $author$
 *   Date: 2/5/2004
 **********************************************************************
 */
class cFileDocumentSource
: public cCharFileT<cDocumentSource>
{
public:
    typedef cCharFileT<cDocumentSource> cIs;

    /**
     **********************************************************************
     * Constructor: cFileDocumentSource
     *
     *      Author: $author$
     *        Date: 2/5/2004
     **********************************************************************
     */
    cFileDocumentSource(FILE *handle=NULL, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cFileDocumentSource
     *
     *      Author: $author$
     *        Date: 2/5/2004
     **********************************************************************
     */
    cFileDocumentSource(const char *path) 
    : cIs(path) 
    {
        eError error;
        int count;

        if (0 > (count = SetPath(path)))
            throw (error = -count);
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 2/5/2004
     **********************************************************************
     */
    virtual eError Open(const char *path, const char *mode="r")
    {
        eError error;
        int count;

        if (!(error = cIs::Open(path, mode)))
        {
            if (0 <= (count = SetPath(path)))
                return error;

            cIs::Close();
            error = -count;
        }
        return error;
    }
};

#endif /* ndef _CFILEDOCUMENTSOURCE_HXX */
