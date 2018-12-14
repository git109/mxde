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
 *   File: cfilepathinterface.hxx
 *
 * Author: $author$
 *   Date: 1/16/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CFILEPATHINTERFACE_HXX
#define _CFILEPATHINTERFACE_HXX

#include "ccharbuffer.hxx"
#include "cccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cFilePathInterfaceT
 *
 * Author: $author$
 *   Date: 1/16/2006
 **********************************************************************
 */
template
<class TIs=cInitializeInterface>
class c_INTERFACE_CLASS cFilePathInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/16/2006
     **********************************************************************
     */
    enum
    {
        e_FIRST_TYPE,

        e_TYPE_NONE = e_FIRST_TYPE,
        e_TYPE_CURRENT,
        e_TYPE_PARENT,
        e_TYPE_ROOT,

        e_NEXT_TYPE,
        e_LAST_TYPE = e_NEXT_TYPE-1
    };

    /**
     **********************************************************************
     * Function: SetPath
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual int SetPath(const cChar* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: SetPathc
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual int SetPathc(const char* chars, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetPath
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    virtual const cChar* GetPath(int &length) const = 0;

    /**
     **********************************************************************
     * Function: SetHost
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int SetHost
    (const cChar* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetHost
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual const cChar* GetHost
    (int& length) const = 0;
    /**
     **********************************************************************
     * Function: SetDevice
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int SetDevice
    (const cChar* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetDevice
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual const cChar* GetDevice
    (int& length) const = 0;
    /**
     **********************************************************************
     * Function: WriteDirectory
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int WriteDirectory
    (const cChar* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: SetDirectory
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int SetDirectory
    (const cChar* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetDirectory
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual const cChar* GetDirectory
    (int& length) const = 0;
    /**
     **********************************************************************
     * Function: GetDirectorySeparator
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual const cChar& GetDirectorySeparator
    () const = 0;
    /**
     **********************************************************************
     * Function: GetDirectoryLength
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int GetDirectoryLength
    () const = 0;
    /**
     **********************************************************************
     * Function: SetFile
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int SetFile
    (const cChar* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetFile
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual const cChar* GetFile
    (int& length) const = 0;
    /**
     **********************************************************************
     * Function: SetExtension
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int SetExtension
    (const cChar* chars,
     int length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetExtension
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual const cChar* GetExtension
    (int& length) const = 0;

    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int SetType(int type) = 0;
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 1/16/2006
     **********************************************************************
     */
    virtual int GetType() const = 0;
};

/**
 **********************************************************************
 *  Class: cFilePathInterface
 *
 * Author: $author$
 *   Date: 1/16/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cFilePathInterface
: virtual public cFilePathInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cFilePathImplementT
 *
 * Author: $author$
 *   Date: 1/16/2006
 **********************************************************************
 */
template
<class TIs=cFilePathInterface>
class cFilePathImplementT
: virtual public TIs
{
public:
};

/**
 **********************************************************************
 *  Class: cFilePathImplement
 *
 * Author: $author$
 *   Date: 1/16/2006
 **********************************************************************
 */
class cFilePathImplement
: virtual public cFilePathImplementT<>
{
public:
};


#endif /* _CFILEPATHINTERFACE_HXX */

