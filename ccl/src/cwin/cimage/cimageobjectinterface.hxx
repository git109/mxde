/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cimageobjectinterface.hxx
 *
 * Author: $author$
 *   Date: 6/5/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CIMAGEOBJECTINTERFACE_HXX
#define _CIMAGEOBJECTINTERFACE_HXX

#include "cimageinterface.hxx"
#include "cdocumentinterface.hxx"
#include "cinterface.hxx"
#include "cimplement.hxx"

class c_INTERFACE_CLASS cImageObjectInterface;

/**
 **********************************************************************
 *  Class: cImageObjectSetInterface
 *
 * Author: $author$
 *   Date: 3/31/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageObjectSetInterface
: virtual public cInterface
{
public:
    typedef cInterface cIs;

    /**
     **********************************************************************
     * Function: AddObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *AddObject
    (eError &error,cElementInterface &element)=0;
    /**
     **********************************************************************
     * Function: DeleteObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual eError DeleteObject(cImageObjectInterface &object)=0;

    /**
     **********************************************************************
     * Function: GetFirstObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetFirstObject() const=0;
    /**
     **********************************************************************
     * Function: GetLastObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetLastObject() const=0;
};

class c_INTERFACE_CLASS cImageObjectTypeInterface;

/**
 **********************************************************************
 *  Class: cImageObjectInterface
 *
 * Author: $author$
 *   Date: 3/27/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageObjectInterface
: virtual public cImageObjectSetInterface
{
public:
    /**
     **********************************************************************
     * Function: GetObjectType
     *
     *   Author: $author$
     *     Date: 5/14/2004
     **********************************************************************
     */
    virtual cImageObjectTypeInterface *GetObjectType() const=0;
    /**
     **********************************************************************
     * Function: GetNextObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetNextObject() const=0;
    /**
     **********************************************************************
     * Function: GetPreviousObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetPreviousObject() const=0;
    /**
     **********************************************************************
     * Function: Paint
     *
     *   Author: $author$
     *     Date: 3/27/2004
     **********************************************************************
     */
    virtual void Paint
    (cImageInterface &image,
     int x=-1, int y=-1, int state=-1) const=0;
};

/**
 **********************************************************************
 *  Class: cImageObjectTypeInterface
 *
 * Author: $author$
 *   Date: 5/14/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageObjectTypeInterface
{
public:
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 5/14/2004
     **********************************************************************
     */
    virtual const char *GetName() const = 0;
};

/**
 **********************************************************************
 *  Class: cImageObjectSetImplement
 *
 * Author: $author$
 *   Date: 3/31/2004
 **********************************************************************
 */
class cImageObjectSetImplement
: virtual public cImageObjectSetInterface
{
public:
    /**
     **********************************************************************
     * Function: AddObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *AddObject
    (eError &error,cElementInterface &element)
    {
        cImageObjectInterface *object=0;
        error=e_ERROR_NOT_IMPLEMENTED;
        return object;
    }
    /**
     **********************************************************************
     * Function: DeleteObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual eError DeleteObject(cImageObjectInterface &object)
    {
        eError error=e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: GetFirstObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetFirstObject() const
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetLastObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetLastObject() const
    {
        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cImageObjectImplement
 *
 * Author: $author$
 *   Date: 3/27/2004
 **********************************************************************
 */
class cImageObjectImplement
: virtual public cImageObjectInterface,
  virtual public cImageObjectSetImplement
{
public:
    /**
     **********************************************************************
     * Function: GetObjectType
     *
     *   Author: $author$
     *     Date: 5/14/2004
     **********************************************************************
     */
    virtual cImageObjectTypeInterface *GetObjectType() const
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetNextObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetNextObject() const
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetPreviousObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetPreviousObject() const
    {
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetState
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual int SetState(int state)=0;
    /**
     **********************************************************************
     * Function: GetState
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual int GetState() const=0;

    /**
     **********************************************************************
     * Function: Paint
     *
     *   Author: $author$
     *     Date: 3/27/2004
     **********************************************************************
     */
    virtual void Paint
    (cImageInterface &image,
     int x=-1, int y=-1, int state=-1) const
    {
    }
};

#endif /* _CIMAGEOBJECTINTERFACE_HXX */
