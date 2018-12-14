/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cfilepathparserevent.hxx
 *
 * Author: $author$
 *   Date: 1/15/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CFILEPATHPARSEREVENT_HXX
#define _CFILEPATHPARSEREVENT_HXX

#include "cfilepathparsereventinterface.hxx"
#include "cfilepathinterface.hxx"

/**
 **********************************************************************
 *  Class: cFilePathParserEvent
 *
 * Author: $author$
 *   Date: 12/27/2005
 **********************************************************************
 */
class cFilePathParserEvent
: virtual public cInitializeImplement,
  virtual public cPrintfImplement,
  virtual public cFilePathParserEventImplement,
  public cInstance
{
public:
    typedef cInstance cIs;
    typedef cInitializeImplement cInitializeIs;

    cFilePathInterface& m_path;

    /**
     **********************************************************************
     * Constructor: cFilePathParserEvent
     *
     *      Author: $author$
     *        Date: 12/27/2005
     **********************************************************************
     */
    cFilePathParserEvent(cFilePathInterface& path) 
    : m_path(path)
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
        eError error = e_ERROR_NONE;

        if (!(error = cInitializeIs::Initialize()))
        if ((error = m_path.Initialize()))
            cInitializeIs::Finalize();
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
        eError error = m_path.Finalize();
        eError error2;

        if ((error2 = cInitializeIs::Finalize()))
        if (!error)
            error = error2;
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
        int result = m_path.SetHost(chars, length);
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
        int result = m_path.SetDevice(chars, length);
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
        const cChar& directory_separator = m_path.GetDirectorySeparator();
        int count, result;
        
        if (!m_path.GetType())
            m_path.SetType(m_path.e_TYPE_ROOT);

        if (0 >= (count = m_path.GetDirectoryLength()))
        if (0 > (result =m_path.WriteDirectory
            (&directory_separator,1)))
            return result;

        result = m_path.WriteDirectory(chars, length);
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
        const cChar& directory_separator = m_path.GetDirectorySeparator();
        int count, result;
        
        if (!m_path.GetType())
            m_path.SetType(m_path.e_TYPE_PARENT);

        if (0 < (count = m_path.GetDirectoryLength()))
        if (0 > (result =m_path.WriteDirectory
            (&directory_separator,1)))
            return result;

        result = m_path.WriteDirectory(chars, length);
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
        const cChar& directory_separator = m_path.GetDirectorySeparator();
        int count, result;
        
        if (!m_path.GetType())
            m_path.SetType(m_path.e_TYPE_CURRENT);

        if (0 < (count = m_path.GetDirectoryLength()))
        if (0 > (result =m_path.WriteDirectory
            (&directory_separator,1)))
            return result;

        result = m_path.WriteDirectory(chars, length);
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
        const cChar& directory_separator = m_path.GetDirectorySeparator();
        int count, result;
        
        if (0 < (count = m_path.GetDirectoryLength()))
        if (0 > (result =m_path.WriteDirectory
            (&directory_separator,1)))
            return result;

        result = m_path.WriteDirectory(chars, length);
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
        const cChar& directory_separator = m_path.GetDirectorySeparator();
        int count, result;
        
        if (!m_path.GetType())
            m_path.SetType(m_path.e_TYPE_ROOT);

        if (0 >= (count = m_path.GetDirectoryLength()))
        if (0 > (result =m_path.WriteDirectory
            (&directory_separator,1)))
            return result;

        result = m_path.SetFile(chars, length);
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
        int result;
        
        result = m_path.SetFile(chars, length);
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
        int result;
        
        result = m_path.SetExtension(chars, length);
        return result;
    }
};

#endif /* _CFILEPATHPARSEREVENT_HXX */

