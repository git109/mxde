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
 *   File: cwriterinterface.hxx
 *
 * Author: $author$
 *   Date: 9/27/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWRITERINTERFACE_HXX
#define _CWRITERINTERFACE_HXX

#include <stdarg.h>
#include "cinterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cWriterInterfaceT
 *
 * Author: $author$
 *   Date: 9/27/2004
 **********************************************************************
 */
template <class TOf, class TIs=cInterface>
class c_INTERFACE_CLASS cWriterInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Flush
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual int Flush() = 0;
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual int Write(const TOf *buf,  int len=-1) = 0;
    /**
     **********************************************************************
     * Function: WriteL
     *
     *   Author: $author$
     *     Date: 11/12/2004
     **********************************************************************
     */
    virtual int WriteL(const TOf *buf,...) = 0;
    /**
     **********************************************************************
     * Function: WriteV
     *
     *   Author: $author$
     *     Date: 11/12/2004
     **********************************************************************
     */
    virtual int WriteV(va_list va) = 0;
};

/**
 **********************************************************************
 *  Class: cWriterImplementT
 *
 * Author: $author$
 *   Date: 10/17/2004
 **********************************************************************
 */
template <class TOf, class TIs=cWriterInterfaceT<TOf> >
class cWriterImplementT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Flush
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual int Flush() 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual int Write(const TOf *buf,  int len=-1) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: WriteL
     *
     *   Author: $author$
     *     Date: 11/12/2004
     **********************************************************************
     */
    virtual int WriteL(const TOf *buf,...) 
    {
        int count, result;
        va_list arg;

        va_start(arg,buf);

        if ((count = (result = Write(buf))) >= 0)
        if ((result = WriteV(arg)) >= 0)
            result += count;

        va_end(arg);
        return result;
    }
    /**
     **********************************************************************
     * Function: WriteV
     *
     *   Author: $author$
     *     Date: 11/12/2004
     **********************************************************************
     */
    virtual int WriteV(va_list va) 
    {
        int count, result=0;
        const TOf *buf;

        while ((buf=va_arg(va,const TOf *)))
        {
            if ((count = Write(buf)) < 0)
                return count;

            result += count;
        }

        return result;
    }
};

#endif /* ndef _CWRITERINTERFACE_HXX */
