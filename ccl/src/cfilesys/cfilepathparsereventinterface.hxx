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
 *   File: cfilepathparsereventinterface.hxx
 *
 * Author: $author$
 *   Date: 12/26/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CFILEPATHPARSEREVENTINTERFACE_HXX
#define _CFILEPATHPARSEREVENTINTERFACE_HXX

#include <stdio.h>

#include "cinitializeinterface.hxx"
#include "cprintfinterface.hxx"
#include "cinstance.hxx"
#include "cinterface.hxx"
#include "ccchartocharbuffer.hxx"
#include "cchar.hxx"

/**
 **********************************************************************
 *  Class: cFilePathParserEventInterfaceT
 *
 * Author: $author$
 *   Date: 12/26/2005
 **********************************************************************
 */
template
<class TIs=cInitializeInterface, 
 class TPrintfIs=cPrintfInterface>
class c_INTERFACE_CLASS cFilePathParserEventInterfaceT
: virtual public TIs,
  virtual public TPrintfIs
{
public:
    /**
     **********************************************************************
     * Function: OnHost
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnHost
    (const cChar* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnDevice
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnDevice
    (const cChar* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnRootDirectory
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnRootDirectory
    (const cChar* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnParentDirectory
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnParentDirectory
    (const cChar* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnCurrentDirectory
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnCurrentDirectory
    (const cChar* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnDirectory
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnDirectory
    (const cChar* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnRootFileName
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnRootFileName
    (const cChar* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnFileName
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnFileName
    (const cChar* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: OnExtension
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnExtension
    (const cChar* chars,
     int length=-1) = 0;
};

/**
 **********************************************************************
 *  Class: cFilePathParserEventInterface
 *
 * Author: $author$
 *   Date: 12/26/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cFilePathParserEventInterface
: virtual public cFilePathParserEventInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cFilePathParserEventImplementT
 *
 * Author: $author$
 *   Date: 12/26/2005
 **********************************************************************
 */
template
<class TIs=cFilePathParserEventInterface>
class cFilePathParserEventImplementT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: OnHost
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnHost
    (const cChar* chars,
     int length=-1) 
    {

        cCCharToCharBuffer buffer(chars, length);
        const char* chrs = buffer.GetBuffer(length);
        Printf("OnHost(\"%s\", %d)\n", chrs, length); 

        length = e_ERROR_NONE;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnDevice
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnDevice
    (const cChar* chars,
     int length=-1) 
    {

        cCCharToCharBuffer buffer(chars, length);
        const char* chrs = buffer.GetBuffer(length);
        Printf("OnDevice(\"%s\", %d)\n", chrs, length); 

        length = e_ERROR_NONE;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnRootDirectory
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnRootDirectory
    (const cChar* chars,
     int length=-1) 
    {

        cCCharToCharBuffer buffer(chars, length);
        const char* chrs = buffer.GetBuffer(length);
        Printf("OnRootDirectory(\"%s\", %d)\n", chrs, length); 

        length = e_ERROR_NONE;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnParentDirectory
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnParentDirectory
    (const cChar* chars,
     int length=-1) 
    {

        cCCharToCharBuffer buffer(chars, length);
        const char* chrs = buffer.GetBuffer(length);
        Printf("OnParentDirectory(\"%s\", %d)\n", chrs, length); 

        length = e_ERROR_NONE;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnCurrentDirectory
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnCurrentDirectory
    (const cChar* chars,
     int length=-1) 
    {

        cCCharToCharBuffer buffer(chars, length);
        const char* chrs = buffer.GetBuffer(length);
        Printf("OnCurrentDirectory(\"%s\", %d)\n", chrs, length); 

        length = e_ERROR_NONE;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnDirectory
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnDirectory
    (const cChar* chars,
     int length=-1) 
    {

        cCCharToCharBuffer buffer(chars, length);
        const char* chrs = buffer.GetBuffer(length);
        Printf("OnDirectory(\"%s\", %d)\n", chrs, length); 

        length = e_ERROR_NONE;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnRootFileName
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnRootFileName
    (const cChar* chars,
     int length=-1) 
    {

        cCCharToCharBuffer buffer(chars, length);
        const char* chrs = buffer.GetBuffer(length);
        Printf("OnRootFileName(\"%s\", %d)\n", chrs, length); 

        length = e_ERROR_NONE;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnFileName
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnFileName
    (const cChar* chars,
     int length=-1) 
    {

        cCCharToCharBuffer buffer(chars, length);
        const char* chrs = buffer.GetBuffer(length);
        Printf("OnFileName(\"%s\", %d)\n", chrs, length); 

        length = e_ERROR_NONE;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnExtension
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnExtension
    (const cChar* chars,
     int length=-1) 
    {

        cCCharToCharBuffer buffer(chars, length);
        const char* chrs = buffer.GetBuffer(length);
        Printf("OnExtension(\"%s\", %d)\n", chrs, length); 

        length = e_ERROR_NONE;
        return length;
    }
    /**
     **********************************************************************
     * Function: Printf
     *
     *   Author: $author$
     *     Date: 1/9/2006
     **********************************************************************
     *
    int Printf(const char* format, ...)
    {
        int result;
        va_list va;

        va_start(va, format);
        result = vprintf(format, va);
        va_end(va);
        return result;
    }*/
};

/**
 **********************************************************************
 *  Class: cFilePathParserEventImplement
 *
 * Author: $author$
 *   Date: 12/26/2005
 **********************************************************************
 */
class cFilePathParserEventImplement
: virtual public cFilePathParserEventImplementT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cFilePathParserEventProxy
 *
 * Author: $author$
 *   Date: 12/26/2005
 **********************************************************************
 */
class cFilePathParserEventProxy
: virtual public cFilePathParserEventImplement,
  virtual public cInitializeImplement,
  virtual public cPrintfImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    cFilePathParserEventInterface& m_proxy;

    /**
     **********************************************************************
     * Constructor: cFilePathParserEventProxy
     *
     *      Author: $author$
     *        Date: 12/26/2005
     **********************************************************************
     */
    cFilePathParserEventProxy
    (cFilePathParserEventInterface& proxy) 
    : m_proxy(proxy)
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = m_proxy.Initialize();
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = m_proxy.Finalize();
        return error;
    }

    /**
     **********************************************************************
     * Function: OnHost
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnHost
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_proxy.OnHost(chars,length);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnDevice
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnDevice
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_proxy.OnDevice(chars,length);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnRootDirectory
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnRootDirectory
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_proxy.OnRootDirectory(chars,length);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnParentDirectory
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnParentDirectory
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_proxy.OnParentDirectory(chars,length);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnCurrentDirectory
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnCurrentDirectory
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_proxy.OnCurrentDirectory(chars,length);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnDirectory
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnDirectory
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_proxy.OnDirectory(chars,length);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnRootFileName
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnRootFileName
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_proxy.OnRootFileName(chars,length);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnFileName
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnFileName
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_proxy.OnFileName(chars,length);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnExtension
     *
     *   Author: $author$
     *     Date: 12/26/2005
     **********************************************************************
     */
    virtual int OnExtension
    (const cChar* chars,
     int length=-1) 
    {
        int result = m_proxy.OnExtension(chars,length);
        return result;
    }

    /**
     **********************************************************************
     * Function: SetPrintf
     *
     *   Author: $author$
     *     Date: 1/15/2006
     **********************************************************************
     */
    virtual cPrintfInterface* SetPrintf
    (cPrintfInterface* p_printf) 
    {
        cPrintfInterface* old_printf = m_printf;
        m_old_printf = m_proxy.SetPrintf(p_printf);
        m_printf = p_printf;
        return old_printf;
    }
    /**
     **********************************************************************
     * Function: ResetPrintf
     *
     *   Author: $author$
     *     Date: 1/15/2006
     **********************************************************************
     */
    virtual cPrintfInterface* 
    ResetPrintf(cPrintfInterface* p_printf) 
    {
        cPrintfInterface* old_printf = m_printf;
        m_printf = p_printf;
        m_proxy.SetPrintf(m_old_printf);
        return old_printf;
    }
    /**
     **********************************************************************
     * Function: GetPrintf
     *
     *   Author: $author$
     *     Date: 1/15/2006
     **********************************************************************
     */
    virtual cPrintfInterface* GetPrintf() const 
    {
        return m_printf;
    }
};

#endif /* _CFILEPATHPARSEREVENTINTERFACE_HXX */
