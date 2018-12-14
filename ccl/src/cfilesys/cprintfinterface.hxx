/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: cprintfinterface.hxx
 *
 * Author: $author$
 *   Date: 1/15/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CPRINTFINTERFACE_HXX
#define _CPRINTFINTERFACE_HXX

#include <stdio.h>
#include <stdarg.h>
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cPrintfInterfaceT
 *
 * Author: $author$
 *   Date: 1/15/2006
 **********************************************************************
 */
template
<class TAs, class TIs=cInterface>
class c_INTERFACE_CLASS cPrintfInterfaceT
: virtual public TIs
{
public:
    typedef TAs cAs;

    /**
     **********************************************************************
     * Function: SetPrintf
     *
     *   Author: $author$
     *     Date: 1/15/2006
     **********************************************************************
     */
    virtual cAs* SetPrintf(cAs* p_printf) = 0;
    /**
     **********************************************************************
     * Function: ResetPrintf
     *
     *   Author: $author$
     *     Date: 1/15/2006
     **********************************************************************
     */
    virtual cAs* ResetPrintf(cAs* p_printf) = 0;
    /**
     **********************************************************************
     * Function: GetPrintf
     *
     *   Author: $author$
     *     Date: 1/15/2006
     **********************************************************************
     */
    virtual cAs* GetPrintf() const = 0;
    /**
     **********************************************************************
     * Function: Printf
     *
     *   Author: $author$
     *     Date: 1/15/2006
     **********************************************************************
     */
    virtual int Printf(const char* format, ...) = 0;
    /**
     **********************************************************************
     * Function: VPrintf
     *
     *   Author: $author$
     *     Date: 1/15/2006
     **********************************************************************
     */
    virtual int VPrintf(const char* format, va_list va) = 0;
};

/**
 **********************************************************************
 *  Class: cPrintfInterface
 *
 * Author: $author$
 *   Date: 1/15/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cPrintfInterface
: virtual public cPrintfInterfaceT<cPrintfInterface>
{
public:
};

/**
 **********************************************************************
 *  Class: cPrintfImplementT
 *
 * Author: $author$
 *   Date: 1/15/2006
 **********************************************************************
 */
template
<class TInterfaceIs=cPrintfInterface>
class cPrintfImplementT
: virtual public TInterfaceIs
{
public:
    typedef TInterfaceIs cInterfaceIs;

    cInterfaceIs* m_printf;
    cInterfaceIs* m_old_printf;

    /**
     **********************************************************************
     * Constructor: cPrintfImplementT
     *
     *      Author: $author$
     *        Date: 1/15/2006
     **********************************************************************
     */
    cPrintfImplementT
    (cInterfaceIs* p_printf=0, cInterfaceIs* p_old_printf=0)
    : m_printf(p_printf),
      m_old_printf(p_old_printf)
    {
    }
    /**
     **********************************************************************
     * Function: SetPrintf
     *
     *   Author: $author$
     *     Date: 1/15/2006
     **********************************************************************
     */
    virtual cInterfaceIs* SetPrintf(cInterfaceIs* p_printf) 
    {
        cInterfaceIs* m_printf = p_printf;
        return m_printf;
    }
    /**
     **********************************************************************
     * Function: ResetPrintf
     *
     *   Author: $author$
     *     Date: 1/15/2006
     **********************************************************************
     */
    virtual cInterfaceIs* ResetPrintf(cInterfaceIs* p_printf) 
    {
        cInterfaceIs* m_printf = p_printf;
        return m_printf;
    }
    /**
     **********************************************************************
     * Function: GetPrintf
     *
     *   Author: $author$
     *     Date: 1/15/2006
     **********************************************************************
     */
    virtual cInterfaceIs* GetPrintf() const 
    {
        return m_printf;
    }
    /**
     **********************************************************************
     * Function: Printf
     *
     *   Author: $author$
     *     Date: 1/15/2006
     **********************************************************************
     */
    virtual int Printf(const char* format, ...) 
    {
        int result;
        va_list va;

        va_start(va, format);
        result = VPrintf(format, va);
        va_end(va);
        return result;
    }
    /**
     **********************************************************************
     * Function: VPrintf
     *
     *   Author: $author$
     *     Date: 1/15/2006
     **********************************************************************
     */
    virtual int VPrintf(const char* format, va_list va) 
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;

        if (m_printf)
            result = m_printf->VPrintf(format, va);
        return result;
    }
};

/**
 **********************************************************************
 *  Class: cPrintfImplement
 *
 * Author: $author$
 *   Date: 1/15/2006
 **********************************************************************
 */
class cPrintfImplement
: virtual public cPrintfImplementT<>
{
public:
    typedef cPrintfImplementT<> cIs;

    /**
     **********************************************************************
     * Constructor: cPrintfImplement
     *
     *      Author: $author$
     *        Date: 1/15/2006
     **********************************************************************
     */
    cPrintfImplement
    (cInterfaceIs* p_printf=0, cInterfaceIs* p_old_printf=0)
    : cIs(p_printf, p_old_printf) 
    {
    }
};

#endif /* _CPRINTFINTERFACE_HXX */

