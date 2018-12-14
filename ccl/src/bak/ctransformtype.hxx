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
 *   File: ctransformtype.hxx
 *
 * Author: $author$
 *   Date: 2/2/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTRANSFORMTYPE_HXX
#define _CTRANSFORMTYPE_HXX

#include "clistt.hxx"
#include "ctransform.hxx"
#include "ctransformtypeinterface.hxx"

/**
 **********************************************************************
 *  Class: cStaticTransformType
 *
 * Author: $author$
 *   Date: 2/2/2004
 **********************************************************************
 */
class cStaticTransformType
: virtual public cTransformTypeInterface,
  public cListItemT<cStaticTransformType,cInstance>
{
public:
    typedef cListItemT<cStaticTransformType,cInstance> cIs;

    /**
     **********************************************************************
     *  Class: cList
     *
     * Author: $author$
     *   Date: 2/3/2004
     **********************************************************************
     */
    class cList
    : public cStaticListT<cStaticTransformType, cList>
    {
    public:
        typedef cStaticListT<cStaticTransformType, cList> cIs;
    };

    static cList m_list;

    cTransformTypeInterface &m_type;

    /**
     **********************************************************************
     * Constructor: cStaticTransformType
     *
     *      Author: $author$
     *        Date: 2/2/2004
     **********************************************************************
     */
    cStaticTransformType(cTransformTypeInterface &type) 
    : m_type(type) 
    {
        m_list.Add(this);
    }

    /**
     **********************************************************************
     * Function: GetFirst
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    static cTransformTypeInterface *GetFirst()
    {
        return m_list.GetFirst();
    }
    /**
     **********************************************************************
     * Function: GetLast
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    static cTransformTypeInterface *GetLast()
    {
        return m_list.GetLast();
    }

    /**
     **********************************************************************
     * Function: GetNext
     *
     *   Author: $author$
     *     Date: 2/2/2004
     **********************************************************************
     */
    virtual cTransformTypeInterface *GetNext() const
    {
        return cIs::GetNext();
    }
    /**
     **********************************************************************
     * Function: GetPrevious
     *
     *   Author: $author$
     *     Date: 2/2/2004
     **********************************************************************
     */
    virtual cTransformTypeInterface *GetPrevious() const
    {
        return cIs::GetPrevious();
    }

    /**
     **********************************************************************
     * Function: IsNamed
     *
     *   Author: $author$
     *     Date: 2/1/2004
     **********************************************************************
     */
    virtual bool IsNamed(const char *name) const
    {
        return m_type.IsNamed(name);
    }

    /**
     **********************************************************************
     * Function: GetTransform
     *
     *   Author: $author$
     *     Date: 2/1/2004
     **********************************************************************
     */
    virtual cTransformInterface *GetTransform(eError &error)
    {
        return m_type.GetTransform(error);
    }
    /**
     **********************************************************************
     * Function: FreeTransform
     *
     *   Author: $author$
     *     Date: 2/1/2004
     **********************************************************************
     */
    virtual eError FreeTransform(cTransformInterface &transform)
    {
        return m_type.FreeTransform(transform);
    }
};

/**
 **********************************************************************
 *  Class: cTransformType
 *
 * Author: $author$
 *   Date: 2/2/2004
 **********************************************************************
 */
class cTransformType
: virtual public cTransformTypeInterface,
  virtual public cTransformTypeImplement,
  public cInstance
{
public:
    typedef cTransformTypeImplement cIs;

    const char *m_name;
    cTransform *m_transform;
    cTransform *m_used_transform;

    /**
     **********************************************************************
     * Constructor: cTransformType
     *
     *      Author: $author$
     *        Date: 2/2/2004
     **********************************************************************
     */
    cTransformType(const char *name,cTransform *transform=0)
    : m_name(name),
      m_transform(transform),
      m_used_transform(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cTransformType
     *
     *     Author: $author$
     *       Date: 2/2/2004
     **********************************************************************
     */
    virtual ~cTransformType()
    {
    }

    /**
     **********************************************************************
     * Function: IsNamed
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    virtual bool IsNamed(const char *name) const
    {
        return 0 == strcmp(name,m_name);
    }

    /**
     **********************************************************************
     * Function: GetTransform
     *
     *   Author: $author$
     *     Date: 2/1/2004
     **********************************************************************
     */
    virtual cTransformInterface *GetTransform(eError &error)
    {
        cTransform *transform;

        if ((transform = m_transform))
        {
            m_used_transform = m_transform;
            m_transform = 0;
        }
        else
        {
            if (!(transform = new cTransform(this)))
                error = e_ERROR_NEW;
        }

        return transform;
    }
    /**
     **********************************************************************
     * Function: FreeTransform
     *
     *   Author: $author$
     *     Date: 2/1/2004
     **********************************************************************
     */
    virtual eError FreeTransform(cTransformInterface &transform)
    {
        eError error=e_ERROR_NONE;

        if (&transform != m_used_transform)
        {
            if (transform.GetType() != this)
                error = e_ERROR_FAILED;

            else error = transform.FreeInstance();
        }
        else
        {
            m_transform = m_used_transform;
            m_used_transform = 0;
        }

        return error;
    }
};

#endif /* ndef _CTRANSFORMTYPE_HXX */
