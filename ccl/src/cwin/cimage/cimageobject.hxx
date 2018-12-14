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
 *   File: cimageobject.hxx
 *
 * Author: $author$
 *   Date: 6/5/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CIMAGEOBJECT_HXX
#define _CIMAGEOBJECT_HXX

#include "cproperty.hxx"
#include "cimageobjectinterface.hxx"
#include "cinstance.hxx"
#include "cavltreet.hxx"
#include "clistt.hxx"

class cImageObject;

/**
 **********************************************************************
 *  Class: cImageObjectSet
 *
 * Author: $author$
 *   Date: 3/28/2004
 **********************************************************************
 */
class cImageObjectSet
: virtual public cImageObjectSetInterface,
  virtual public cImageObjectSetImplement,
  public cDynamicListT<cImageObject,cImageObjectSet,cInstance>
{
public:
    typedef cDynamicListT<cImageObject,cImageObjectSet,cInstance> cIs;

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
        return (cImageObjectInterface*)cListIs::GetFirst();
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
        return (cImageObjectInterface*)cListIs::GetLast();
    }
};

/**
 **********************************************************************
 *  Class: cImageObject
 *
 * Author: $author$
 *   Date: 3/27/2004
 **********************************************************************
 */
class cImageObject
: virtual public cImageObjectSetInterface,
  virtual public cImageObjectInterface,
  virtual public cImageObjectSetImplement,
  virtual public cImageObjectImplement,
  public cDynamicListItemT<cImageObject,cImageObjectSet>
{
public:
    typedef cDynamicListItemT<cImageObject,cImageObjectSet> cIs;

    cImageObjectTypeInterface *m_object_type;

    int m_x, m_y, m_width, m_height, m_style, m_state;
    cCharBuffer m_file;

    cPropertyList m_property_list;
    cIntProperty 
        m_property_x, m_property_y, 
        m_property_width, m_property_height, 
        m_property_style, m_property_state;

    /**
     **********************************************************************
     * Constructor: cImageObject
     *
     *      Author: $author$
     *        Date: 3/27/2004
     **********************************************************************
     */
    cImageObject
    (int x=0, int y=0, int width=0, int height=0,
     int style=0, int state=0)
    : cIs(true),

      m_object_type(0),

      m_x(x), 
      m_y(y),
      m_width(width), 
      m_height(height),
      m_style(style),
      m_state(state),

      m_property_x(m_property_list,m_x,"x"), 
      m_property_y(m_property_list,m_y,"y"),
      m_property_width(m_property_list,m_width,"width"), 
      m_property_height(m_property_list,m_height,"height"),
      m_property_style(m_property_list,m_style,"style"),
      m_property_state(m_property_list,m_state,"state")
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cImageObject
     *
     *     Author: $author$
     *       Date: 3/27/2004
     **********************************************************************
     */
    virtual ~cImageObject()
    {
    }

    /**
     **********************************************************************
     * Function: GetFirstProperty
     *
     *   Author: $author$
     *     Date: 4/12/2004
     **********************************************************************
     */
    virtual cProperty *GetFirstProperty() const
    {
        return m_property_list.GetFirst();
    }
    /**
     **********************************************************************
     * Function: GetLastProperty
     *
     *   Author: $author$
     *     Date: 4/12/2004
     **********************************************************************
     */
    virtual cProperty *GetLastProperty() const
    {
        return m_property_list.GetLast();
    }

    /**
     **********************************************************************
     * Function: SetObjectType
     *
     *   Author: $author$
     *     Date: 5/14/2004
     **********************************************************************
     */
    virtual cImageObjectTypeInterface *SetObjectType
    (cImageObjectTypeInterface *object_type)
    {
        return m_object_type = object_type;
    }
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
        return m_object_type;
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
        return cListItemIs::GetNext();
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
        return cListItemIs::GetPrevious();
    }

    /**
     **********************************************************************
     * Function: SetFile
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    virtual eError SetFile(const char *file, int length=-1)
    {
        return m_file.Copy(file, length);
    }
    /**
     **********************************************************************
     * Function: GetFile
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    virtual const char *GetFile(int &length) const
    {
        return m_file.GetBuffer(length);
    }

    /**
     **********************************************************************
     * Function: SetState
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual int SetState(int state)
    {
        int old_state=m_state;

        m_state=state;
        return old_state;
    }
    /**
     **********************************************************************
     * Function: GetState
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual int GetState() const
    {
        return m_state;
    }

    /**
     **********************************************************************
     * Function: Paint
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual void Paint
    (cImageInterface &image,
     int x=-1, int y=-1, int state=-1) const
    {
    }
};

class cImageObjectTypes;

/**
 **********************************************************************
 *  Class: cImageObjectType
 *
 * Author: $author$
 *   Date: 3/31/2004
 **********************************************************************
 */
class cImageObjectType
: virtual public cImageObjectTypeInterface,
  public cAVLTreeBranchT<cImageObjectType>
{
public:
    typedef cAVLTreeBranchT<cImageObjectType> cIs;

    const char *m_name;

    /**
     **********************************************************************
     * Constructor: cImageObjectType
     *
     *      Author: $author$
     *        Date: 3/31/2004
     **********************************************************************
     */
    cImageObjectType(const char *name="")
    : m_name(name) 
    {
    }

    /**
     **********************************************************************
     * Function: CreateObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObject *CreateObject
    (eError &error, cImageObjectSet &object_set, 
     cImageObjectTypes &object_types, cElementInterface &element)
    {
        cImageObject *object=0;
        error=e_ERROR_NOT_IMPLEMENTED;
        return object;
    }

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    int Compare(cImageObjectType &branch) const
    {
        return Compare(branch.GetName());
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    int Compare(const char *name) const
    {
        int result=-1;
        const char *fname;

        if ((fname = GetName()))
            result = strcmp(name, fname);

        return result;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual const char *GetName() const
    {
        return m_name;
    }
};

/**
 **********************************************************************
 *  Class: cImageObjectTypes
 *
 * Author: $author$
 *   Date: 4/1/2004
 **********************************************************************
 */
class cImageObjectTypes
: public cAVLTreeT
  <const char *, cImageObjectType, cImageObjectTypes>
{
public:
    typedef cAVLTreeT
    <const char *, cImageObjectType, cImageObjectTypes> cIs;
};

/**
 **********************************************************************
 *  Class: cStaticImageObjectType
 *
 * Author: $author$
 *   Date: 4/1/2004
 **********************************************************************
 */
class cStaticImageObjectType
: public cListItemT<cStaticImageObjectType>
{
public:
    typedef cListItemT<cStaticImageObjectType> cIs;

    /**
     **********************************************************************
     *  Class: cList
     *
     * Author: $author$
     *   Date: 4/1/2004
     **********************************************************************
     */
    class cList
    : public cStaticListT<cStaticImageObjectType,cList>
    {
    public:
        typedef cStaticListT<cStaticImageObjectType,cList> cIs;
    };

    static cList m_list;

    cImageObjectType &m_object_type;

    /**
     **********************************************************************
     * Constructor: cStaticImageObjectType
     *
     *      Author: $author$
     *        Date: 4/1/2004
     **********************************************************************
     */
    cStaticImageObjectType(cImageObjectType &object_type) 
    : m_object_type(object_type) 
    {
        m_list.Add(this);
    }

    /**
     **********************************************************************
     * Function: GetObjectType
     *
     *   Author: $author$
     *     Date: 4/1/2004
     **********************************************************************
     */
    inline cImageObjectType &GetObjectType()
    {
        return m_object_type;
    }
    /**
     **********************************************************************
     * Function: GetFirst
     *
     *   Author: $author$
     *     Date: 4/1/2004
     **********************************************************************
     */
    static inline cStaticImageObjectType *GetFirst()
    {
        return m_list.GetFirst();
    }
    /**
     **********************************************************************
     * Function: GetLast
     *
     *   Author: $author$
     *     Date: 4/1/2004
     **********************************************************************
     */
    static inline cStaticImageObjectType *GetLast()
    {
        return m_list.GetLast();
    }
};

#endif /* _CIMAGEOBJECT_HXX */
