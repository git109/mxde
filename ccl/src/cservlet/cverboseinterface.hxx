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

class c_INTERFACE_CLASS cVerboseInterface;

/**
 **********************************************************************
 *  Class: cVerboseContainerInterface
 *
 * Author: $author$
 *   Date: 11/13/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cVerboseContainerInterface
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
     * Function: ResetVerbose
     *
     *   Author: $author$
     *     Date: 11/13/2004
     **********************************************************************
     */
    virtual cVerboseInterface *ResetVerbose
    (cVerboseInterface *verbose) = 0;
    /**
     **********************************************************************
     * Function: GetVerbose
     *
     *   Author: $author$
     *     Date: 11/13/2004
     **********************************************************************
     */
    virtual cVerboseInterface *GetVerbose() const = 0;
};

/**
 **********************************************************************
 *  Class: cVerboseContainerImplement
 *
 * Author: $author$
 *   Date: 11/13/2004
 **********************************************************************
 */
class cVerboseContainerImplement
: virtual public cVerboseContainerInterface
{
public:

    cVerboseInterface *m_verbose;
    cVerboseInterface *m_old_verbose;

    /**
     **********************************************************************
     * Constructor: cVerboseContainerImplement
     *
     *      Author: $author$
     *        Date: 11/13/2004
     **********************************************************************
     */
    cVerboseContainerImplement
    (cVerboseInterface *verbose=0,
     cVerboseInterface *old_verbose=0) 
    : m_verbose(verbose),
      m_old_verbose(old_verbose)
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
        m_old_verbose = m_verbose;
        m_verbose = verbose;
        return m_old_verbose;
    }
    /**
     **********************************************************************
     * Function: ResetVerbose
     *
     *   Author: $author$
     *     Date: 11/13/2004
     **********************************************************************
     */
    virtual cVerboseInterface *ResetVerbose
    (cVerboseInterface *verbose) 
    {
        m_old_verbose = m_verbose;
        m_verbose = verbose;
        return m_old_verbose;
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
};

/**
 **********************************************************************
 *  Class: cVerboseInterface
 *
 * Author: $author$
 *   Date: 11/13/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cVerboseInterface
: virtual public cVerboseContainerInterface
{
public:
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
    /**
     **********************************************************************
     * Function: Verbose
     *
     *   Author: $author$
     *     Date: 11/13/2004
     **********************************************************************
     */
    virtual int Verbose
    (const char *buffer, int length=-1) = 0;
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
: virtual public cVerboseInterface,
  public cVerboseContainerImplement
{
public:
    typedef cVerboseContainerImplement cIs;

    /**
     **********************************************************************
     * Constructor: cVerboseImplement
     *
     *      Author: $author$
     *        Date: 11/13/2004
     **********************************************************************
     */
    cVerboseImplement
    (cVerboseInterface *verbose=0,
     cVerboseInterface *old_verbose=0) 
    : cIs(verbose, old_verbose)
    {
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

        if (m_verbose)
            result = m_verbose->VVerboseFormatted(format, va);
        return result;
    }
    /**
     **********************************************************************
     * Function: Verbose
     *
     *   Author: $author$
     *     Date: 11/13/2004
     **********************************************************************
     */
    virtual int Verbose
    (const char *buffer, int length=-1) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;

        if (m_verbose)
            result = m_verbose->Verbose(buffer, length);
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cVerbose
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class cVerbose
: virtual public cVerboseImplement
{
public:
    /**
     **********************************************************************
     * Constructor: cVerbose
     *
     *      Author: $author$
     *        Date: 1/4/2006
     **********************************************************************
     */
    cVerbose
    (cVerboseInterface *verbose=0,
     cVerboseInterface *old_verbose=0) 
    : cVerboseImplement(verbose, old_verbose)
    {
    }
    /**
     **********************************************************************
     * Function: VVerboseFormatted
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual int VVerboseFormatted
    (const char *format, va_list va) 
    {
        int result = 0;

        if (m_verbose)
            result = m_verbose->VVerboseFormatted(format, va);
        return result;
    }
    /**
     **********************************************************************
     * Function: Verbose
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual int Verbose
    (const char *buffer, int length=-1) 
    {
        int result = 0;

        if (m_verbose)
            result = m_verbose->Verbose(buffer, length);
        return result;
    }
};

#endif /* ndef _CVERBOSEINTERFACE_HXX */
