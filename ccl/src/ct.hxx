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
 *   File: ct.hxx
 *
 * Author: $author$
 *   Date: 7/7/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CT_HXX
#define _CT_HXX

#include "ctimplement.hxx"

/**
 **********************************************************************
 *  Class: cT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
class cT
: virtual public cTInterface,
  public cTImplement
{
public:
    typedef cTImplement cIs;

    cVariableTree m_variable_tree;

    /**
     **********************************************************************
     * Constructor: cT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cT(char mark='%')
    : cIs(mark) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cT()
    {
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual cVariableInterface *SetVariable
    (const char *name,int namelen=-1,
     const char *value=0,int valuelen=-1)
    {
        eError error;
        cVariable *variable;

        if (!(variable = m_variable_tree.Find(name, namelen)))
        if ((error = m_variable_tree.AddNew
            (variable, name, namelen, value, valuelen)))
            return 0;

        if ((error = variable->SetValue(value, valuelen)))
            return 0;

        return variable;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual cVariableInterface *GetVariable
    (const char *name,int namelen=-1,
     const char *value=0,int valuelen=-1)
    {
        eError error;
        cVariable *variable;

        if (!(variable = m_variable_tree.Find(name, namelen)))
        if ((error = m_variable_tree.AddNew
            (variable, name, namelen, value, valuelen)))
            return 0;

        return variable;
    }
    /**
     **********************************************************************
     * Function: ExpandVariable
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual eError ExpandVariable(cCharStream &out,const char *name)
    {
        cVariableInterface *variable;
        const char *value;
        int count;

        if ((variable = FindVariable(name)))
        if ((value = variable->GetValue()))
        if ((count = out.Write(value)) < 0)
            return e_ERROR_WRITE;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: FindVariable
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    inline cVariableInterface *FindVariable(const char *name,int namelen=-1)
    {
        return m_variable_tree.Find(name,namelen);
    }
};


#endif
