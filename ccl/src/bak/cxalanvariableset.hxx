/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: cxalanvariableset.hxx
 *
 * Author: $author$
 *   Date: 12/11/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXALANVARIABLESET_HXX
#define _CXALANVARIABLESET_HXX

#include "ccharbuffer.hxx"
#include "ccharnamespace.hxx"
#include "cxalandomstring.hxx"
#include "cxalanvariablesetinterface.hxx"
#include "nsxalan.hxx"

/**
 **********************************************************************
 *  Class: cXalanVariableInterface
 *
 * Author: $author$
 *   Date: 12/11/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cXalanVariableInterface
: public cCharNamedInterfaceT<cXalanVariableInterface>
{
public:
    typedef cCharNamedInterfaceT<cXalanVariableInterface> cIs;

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual eError SetValue(nsXalan::XalanNode *value)=0;
     /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
   virtual nsXalan::XalanNode *GetValue() const=0;
};

/**
 **********************************************************************
 *  Class: cXalanVariable
 *
 * Author: $author$
 *   Date: 12/11/2003
 **********************************************************************
 */
class cXalanVariable
: public cCharNamedT
  <cXalanVariable, cXalanVariableInterface>
{
public:
    typedef cCharNamedT
    <cXalanVariable, cXalanVariableInterface> cIs;

    nsXalan::XalanNode *m_value;

    /**
     **********************************************************************
     * Constructor: cXalanVariable
     *
     *      Author: $author$
     *        Date: 12/11/2003
     **********************************************************************
     */
    cXalanVariable(const char *name, nsXalan::XalanNode *value=0) 
    : cIs(name),
      m_value(value)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXalanVariable
     *
     *     Author: $author$
     *       Date: 12/11/2003
     **********************************************************************
     */
    virtual ~cXalanVariable()
    {
    }

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual eError SetValue(nsXalan::XalanNode *value)
    {
        m_value = value;
        return e_ERROR_NONE;
    }
     /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
   virtual nsXalan::XalanNode *GetValue() const
   {
       return m_value;
   }
};

/**
 **********************************************************************
 *  Class: cXalanVariableSpaceInterface
 *
 * Author: $author$
 *   Date: 12/11/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cXalanVariableSpaceInterface
: public cCharNameSpaceInterfaceT
  <cXalanVariableSpaceInterface, cXalanVariableInterface>
{
public:
    typedef cCharNameSpaceInterfaceT
    <cXalanVariableSpaceInterface, cXalanVariableInterface> cIs;

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
};

/**
 **********************************************************************
 *  Class: cXalanVariableSet
 *
 * Author: $author$
 *   Date: 12/11/2003
 **********************************************************************
 */
class cXalanVariableSet
: virtual public cXalanVariableSetInterface,
  public cCharNameSpaceT
  <cXalanVariableSet, cXalanVariable, 
   cXalanVariableInterface, cXalanVariableSpaceInterface>
{
public:
    typedef cCharNameSpaceT
    <cXalanVariableSet, cXalanVariable, 
     cXalanVariableInterface, cXalanVariableSpaceInterface> cIs;

    /**
     **********************************************************************
     * Constructor: cXalanVariableSet
     *
     *      Author: $author$
     *        Date: 12/11/2003
     **********************************************************************
     */
    cXalanVariableSet() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXalanVariableSet
     *
     *     Author: $author$
     *       Date: 12/11/2003
     **********************************************************************
     */
    virtual ~cXalanVariableSet()
    {
    }

    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual eError Set(const nsXalan::XalanDOMString &name, nsXalan::XalanNode *value)
    {
        cXalanDOMString xalan_string(name);
        cCharBuffer string;
        const char *buffer;
        int count;

        if (0 < (count = xalan_string.ToStream(string)))
        if ((buffer = string.GetBuffer()))
            return Set(buffer, value);

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual nsXalan::XalanNode *Get(const nsXalan::XalanDOMString &name) const
    {
        cXalanDOMString xalan_string(name);
        cCharBuffer string;
        const char *buffer;
        int count;

        if (0 < (count = xalan_string.ToStream(string)))
        if ((buffer = string.GetBuffer()))
            return Get(buffer);

        return 0;
    }

    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual eError Set(const char *name, nsXalan::XalanNode *value)
    {
        eError error;
        cXalanVariable *new_variable;
        cXalanVariableInterface *variable;

        if ((variable = Find(name)))
        {
            if ((error = variable->SetValue(value)))
                return error;
        }
        else
        {
            if (!(new_variable = new  cXalanVariable(name, value)))
                return e_ERROR_NEW;

            Insert(new_variable);
        }

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual nsXalan::XalanNode *Get(const char *name) const
    {
        cXalanVariableInterface *variable;

        if ((variable = Find(name)))
            return variable->GetValue();

        return 0;
    }
};

#endif /* ndef _CXALANVARIABLESET_HXX */
