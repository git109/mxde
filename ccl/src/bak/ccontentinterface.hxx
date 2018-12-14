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
 *   File: ccontentinterface.hxx
 *
 * Author: $author$
 *   Date: 8/5/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCONTENTINTERFACE_HXX
#define _CCONTENTINTERFACE_HXX

#include <stdarg.h>

#include "ccharstream.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cContentInterface
 *
 * Author: $author$
 *   Date: 8/5/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cContentInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: OutputContentType
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual int OutputContentType(const char *content_type=0)=0;
    /**
     **********************************************************************
     * Function: OutputErrorFormatted
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual int OutputErrorFormatted(const char *format,...)=0;
    /**
     **********************************************************************
     * Function: VOutputErrorFormatted
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual int VOutputErrorFormatted(const char *format,va_list va)=0;
    /**
     **********************************************************************
     * Function: OutputFormatted
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual int OutputFormatted(const char *format,...)=0;
    /**
     **********************************************************************
     * Function: VOutputFormatted
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual int VOutputFormatted(const char *format,va_list va)=0;
    /**
     **********************************************************************
     * Function: Output
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual int Output(const char *buffer,int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetContentTypeOutput
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual const char *GetOutputContentType() const=0;
    /**
     **********************************************************************
     * Function: GetContentTypeXML
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual const char *GetContentTypeXML() const=0;
    /**
     **********************************************************************
     * Function: GetContentTypeHTML
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual const char *GetContentTypeHTML() const=0;
    /**
     **********************************************************************
     * Function: GetContentTypeText
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual const char *GetContentTypeText() const=0;
    /**
     **********************************************************************
     * Function: GetContentTypeNone
     *
     *   Author: $author$
     *     Date: 8/5/2003
     **********************************************************************
     */
    virtual const char *GetContentTypeNone() const=0;

    /**
     **********************************************************************
     * Function: OutputFromStream
     *
     *   Author: $author$
     *     Date: 8/30/2003
     **********************************************************************
     */
    int OutputFromStream(cCharStream &stream,int length=-1)
    {
        char c;
        int count,result=0;

        while (length != 0)
        {
            if ((count=stream.Get(c)) < 1)
            if (count < 0)
                return e_ERROR_GET;
            else break;

            if ((count=Output(&c,1)) < 0)
                return count;

            result++;

            if (length > 0)
                --length;
        }

        return result;
    }
};


#endif
