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
 *   File: cverboseinterface.hxx
 *
 * Author: $author$
 *   Date: 11/13/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CVERBOSEINTERFACE_HXX
#define _CVERBOSEINTERFACE_HXX

#include <stdarg.h>
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cVerboseInterface
 *
 * Author: $author$
 *   Date: 11/13/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cVerboseInterface
{
public:
    /**
     **********************************************************************
     * Function: SetVerbose
     *
     *   Author: $author$
     *     Date: 11/13/2004
     **********************************************************************
     */
    virtual cVerboseInterface *SetVerbose
    (cVerboseInterface *verbose) = 0;
    /**
     **********************************************************************
     * Function: IsVerbose
     *
     *   Author: $author$
     *     Date: 11/13/2004
     **********************************************************************
     */
    virtual cVerboseInterface *GetVerbose() const = 0;
    /**
     **********************************************************************
     * Function: VerboseFormatted
     *
     *   Author: $author$
     *     Date: 11/13/2004
     **********************************************************************
     */
    virtual int VerboseFormatted(const char *format,...) = 0;
    /**
     **********************************************************************
     * Function: VVerboseFormatted
     *
     *   Author: $author$
     *     Date: 11/13/2004
     **********************************************************************
     */
    virtual int VVerboseFormatted
    (const char *format, va_list va) = 0;
};

/**
 **********************************************************************
 *  Class: cVerboseImplement
 *
 * Author: $author$
 *   Date: 11/13/2004
 **********************************************************************
 */
class cVerboseImplement
: virtual public cVerboseInterface
{
public:

    cVerboseInterface *m_verbose;

    /**
     **********************************************************************
     * Constructor: cVerboseImplement
     *
     *      Author: $author$
     *        Date: 11/13/2004
     **********************************************************************
     */
    cVerboseImplement(cVerboseInterface *verbose=0) 
    : m_verbose(verbose)
    {
    }
    /**
     **********************************************************************
     * Function: SetVerbose
     *
     *   Author: $author$
     *     Date: 11/13/2004
     **********************************************************************
     */
    virtual cVerboseInterface *SetVerbose
    (cVerboseInterface *verbose) 
    {
        m_verbose = verbose;
        return m_verbose;
    }
    /**
     **********************************************************************
     * Function: GetVerbose
     *
     *   Author: $author$
     *     Date: 11/13/2004
     **********************************************************************
     */
    virtual cVerboseInterface *GetVerbose() const
    {
        return m_verbose;
    }
    /**
     **********************************************************************
     * Function: VerboseFormatted
     *
     *   Author: $author$
     *     Date: 11/13/2004
     **********************************************************************
     */
    virtual int VerboseFormatted(const char *format,...) 
    {
        int count;
        va_list va;

        va_start(va,format);
        count = VVerboseFormatted(format, va);
        va_end(va);

        return count;
    }
    /**
     **********************************************************************
     * Function: VVerboseFormatted
     *
     *   Author: $author$
     *     Date: 11/13/2004
     **********************************************************************
     */
    virtual int VVerboseFormatted
    (const char *format, va_list va) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
};

#endif /* ndef _CVERBOSEINTERFACE_HXX */
