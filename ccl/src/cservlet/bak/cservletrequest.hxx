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
 *   File: cservletrequest.hxx
 *
 * Author: $author$
 *   Date: 10/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSERVLETREQUEST_HXX
#define _CSERVLETREQUEST_HXX

#include "ccontentrequestinterface.hxx"
#include "cservletrequestinterface.hxx"
#include "cimplement.hxx"
#include "cavltreet.hxx"
#include "clistt.hxx"

class cServletRequestParameter;

/**
 **********************************************************************
 *  Class: cServletRequestParameterFree
 *
 * Author: $author$
 *   Date: 11/18/2004
 **********************************************************************
 */
class cServletRequestParameterFree
{
public:
    /**
     **********************************************************************
     * Function: FreeParameter
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual eError FreeParameter
    (cServletRequestParameter &parameter)
    {
        return e_ERROR_NOT_IMPLEMENTED;
    }
};

/**
 **********************************************************************
 *  Class: cServletRequestParameterItem
 *
 * Author: $author$
 *   Date: 11/18/2004
 **********************************************************************
 */
class cServletRequestParameterItem
: public cDynamicListItemT<cServletRequestParameterItem>
{
public:
    typedef cDynamicListItemT<cServletRequestParameterItem> cIs;

    cServletRequestParameter &m_parameter;
    cServletRequestParameterFree &m_parameter_free;

    /**
     **********************************************************************
     * Constructor: cServletRequestParameterItem
     *
     *      Author: $author$
     *        Date: 11/18/2004
     **********************************************************************
     */
    cServletRequestParameterItem
    (cServletRequestParameter &parameter,
     cServletRequestParameterFree &parameter_free) 
    : m_parameter(parameter),
      m_parameter_free(parameter_free)
    {
    }
    /**
     **********************************************************************
     * Function: FreeInstance
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual eError FreeInstance()
    {
        eError error = m_parameter_free
        .FreeParameter(m_parameter);
        return error;
    }
    /**
     **********************************************************************
     * Function: GetParameter
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual cServletRequestParameter& GetParameter()
    {
        return m_parameter;
    }
};

/**
 **********************************************************************
 *  Class: cServletRequestParameterList
 *
 * Author: $author$
 *   Date: 11/18/2004
 **********************************************************************
 */
class cServletRequestParameterList
: public cDynamicListT
  <cServletRequestParameterItem, cServletRequestParameterList>
{
public:
    typedef cDynamicListT
    <cServletRequestParameterItem, cServletRequestParameterList> cIs;

    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual eError Free
    (cServletRequestParameterItem *item)
    {
        eError error = item->FreeInstance();
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cServletRequestParameterBranch
 *
 * Author: $author$
 *   Date: 11/18/2004
 **********************************************************************
 */
class cServletRequestParameterBranch
: public cAVLTreeBranchT<cServletRequestParameterBranch>
{
public:
    typedef cAVLTreeBranchT<cServletRequestParameterBranch> cIs;

    cCharString m_name;
    cServletRequestParameter& m_parameter;

    /**
     **********************************************************************
     * Constructor: cServletRequestParameterBranch
     *
     *      Author: $author$
     *        Date: 11/18/2004
     **********************************************************************
     */
    cServletRequestParameterBranch
    (cServletRequestParameter& parameter,
     const char *name=0, int length=-1)
    : m_parameter(parameter)
    {
        eError error;

        if (name)
        if (0 > (length = m_name.SetChars(name, length)))
            throw(error = -length);
    }

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    int Compare(cServletRequestParameterBranch &branch) const
    {
        int length1, length2, unequal = -1;
        const char *name1,*name2;

        if ((name1 = branch.GetName(length1)))
        if ((name2 = GetName(length2)))
            unequal = strcmp(name1, name2);

        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    int Compare(const char *name) const
    {
        int length2, unequal = -1;
        const char *name2;

        if ((name2 = GetName(length2)))
            unequal = strcmp(name, name2);

        return unequal;
    }
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    const int SetName
    (const char *chars, int length=-1)
    {
        length = m_name.SetChars(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    const char* GetName(int &length) const
    {
        const char* chars = m_name.GetChars(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: GetParameter
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    cServletRequestParameter& GetParameter()
    {
        return m_parameter;
    }
};

/**
 **********************************************************************
 *  Class: cServletRequestParameterTree
 *
 * Author: $author$
 *   Date: 11/18/2004
 **********************************************************************
 */
class cServletRequestParameterTree
: public cAVLTreeT
  <const char*, cServletRequestParameterBranch, cServletRequestParameterTree>
{
public:
    typedef cAVLTreeT
    <const char*, cServletRequestParameterBranch, cServletRequestParameterTree> cIs;

    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    cServletRequestParameter *Find(const char *name) const
    {
        cServletRequestParameter *parameter = 0;
        cServletRequestParameterBranch *branch;

        if ((branch = cIs::Find(name)))
            parameter = &branch->GetParameter();

        return parameter;
    }
};

/**
 **********************************************************************
 *  Class: cServletRequestParameter
 *
 * Author: $author$
 *   Date: 11/18/2004
 **********************************************************************
 */
class cServletRequestParameter
{
public:
    cServletRequestParameterBranch m_branch;
    cServletRequestParameterItem m_item;
    cCharString m_value;

    /**
     **********************************************************************
     * Constructor: cServletRequestParameter
     *
     *      Author: $author$
     *        Date: 11/18/2004
     **********************************************************************
     */
    cServletRequestParameter
    (cServletRequestParameterFree &free,
     const char *name, int namelen=-1,
     const char *value=0, int length=-1) 
    : m_branch(*this, name, namelen),
      m_item(*this, free)
    {
        eError error;

        if (value)
        if (0 > (length = m_value.SetChars(value, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual int SetValue
    (const char *chars,  int length=-1) 
    {
        length = m_value.SetChars(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual const char *GetValue(int &length) const
    {
        const char *value = m_value.GetChars(length);
        return value;
    }
};

/**
 **********************************************************************
 *  Class: cServletRequestT
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
template 
<class TContentRequestInterfaceIs=cContentRequestInterface, 
 class TServletRequestInterfaceIs=cServletRequestInterface,
 class TServletRequestParameterFree=cServletRequestParameterFree,
 class TIs=cImplement>

class cServletRequestT
: virtual public TContentRequestInterfaceIs,
  virtual public TServletRequestInterfaceIs,
  virtual public TServletRequestParameterFree,
  public TIs
{
public:
    typedef TIs cIs;

    bool m_is_consumed, m_is_unconsumed;
    cServletRequestParameterTree m_parameter_tree;
    cServletRequestParameterList m_parameter_list;

    /**
     **********************************************************************
     * Constructor: cServletRequestT
     *
     *      Author: $author$
     *        Date: 10/21/2004
     **********************************************************************
     */
    cServletRequestT() 
    : m_is_consumed(false)
    {
    }
    /**
     **********************************************************************
     * Constructor: ~cServletRequestT
     *
     *      Author: $author$
     *        Date: 11/19/2004
     **********************************************************************
     */
    virtual ~cServletRequestT() 
    {
        m_parameter_list.Clear();
    }

    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual eError Clear() 
    {
        eError error;

        m_is_consumed = false;
        m_is_unconsumed = true;
        m_parameter_tree.Clear();
        error = m_parameter_list.Clear();
        return error;
    }

    /**
     **********************************************************************
     * Function: SetParameter
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual int SetParameter
    (const char *name, int namelen=-1, 
     const char *value=0, int valuelen=-1) 
    {
        int length = -e_ERROR_FAILED;
        cServletRequestParameter *parameter;

        if ((parameter = m_parameter_tree.Find(name)))
            length = parameter->SetValue(value, valuelen);

        else if ((parameter = new cServletRequestParameter
                  (*this, name, namelen, value, valuelen)))
        {
            m_parameter_tree.Insert(&parameter->m_branch);
            m_parameter_list.Add(&parameter->m_item);
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: GetParameter
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual const char* GetParameter
    (int &length, const char *name, int namelen=-1)
    {
        const char *chars = 0;
        cServletRequestParameter *parameter;

        length = -e_ERROR_FAILED;

        if ((parameter = m_parameter_tree.Find(name)))
            chars = parameter->GetValue(length);

        return chars;
    }
    /**
     **********************************************************************
     * Function: FreeParameter
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual eError FreeParameter
    (cServletRequestParameter &parameter)
    {
        delete &parameter;
        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: SetIsConsumed
     *
     *   Author: $author$
     *     Date: 11/11/2004
     **********************************************************************
     */
    virtual bool SetIsConsumed(bool is=true) 
    {
        m_is_consumed = is;
        return m_is_consumed;
    }
    /**
     **********************************************************************
     * Function: IsConsumed
     *
     *   Author: $author$
     *     Date: 11/11/2004
     **********************************************************************
     */
    virtual bool IsConsumed() const
    {
        return m_is_consumed;
    }
};

/**
 **********************************************************************
 *  Class: cServletRequest
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
class cServletRequest
: public cServletRequestT<>
{
public:
    typedef cServletRequestT<> cIs;

    /**
     **********************************************************************
     * Constructor: cServletRequest
     *
     *      Author: $author$
     *        Date: 10/21/2004
     **********************************************************************
     */
    cServletRequest() 
    {
    }
};

#endif /* ndef _CSERVLETREQUEST_HXX */
