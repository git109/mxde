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
 *   File: ctimplement.hxx
 *
 * Author: $author$
 *   Date: 7/7/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTIMPLEMENT_HXX
#define _CTIMPLEMENT_HXX

#include <stdio.h>

#include "cerrorimplement.hxx"
#include "ctinterface.hxx"

/**
 **********************************************************************
 *  Class: cTImplement
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
class cTImplement
: virtual public cTInterface,
  public cImplement
{
public:
    typedef cTInterface::cValueInterface cValueInterface;
    typedef cTInterface::cVariableInterface cVariableInterface;
    typedef cTInterface::cFunctionInterface cFunctionInterface;
    typedef cTInterface::cFunctionItem cFunctionItem;
    typedef cTInterface::cFunctionTree cFunctionTree;

    /**
     **********************************************************************
     *  Class: cFunction
     *
     * Author: $author$
     *   Date: 8/2/2003
     **********************************************************************
     */
    class cFunction
    : virtual public cFunctionInterface,
      public cImplement
    {
    public:
        typedef cImplement cIs;

        cFunctionItem m_item;
        cFunctionBranch m_branch;

        const char *m_name;
        const char *m_description;
        const cParameter *m_parameter;
        int m_parameters;

        /**
         **********************************************************************
         * Constructor: cFunction
         *
         *      Author: $author$
         *        Date: 8/2/2003
         **********************************************************************
         */
        cFunction(const char *name,const char *description)
        : m_item(*this),
          m_branch(*this),
          m_name(name),
          m_description(description),
          m_parameter(0),
          m_parameters(0) 
        {
            cTImplement::m_function_list.Add(&m_item);
        }
        /**
         **********************************************************************
         * Function: 
         *
         *   Author: $author$
         *     Date: 8/2/2003
         **********************************************************************
         */
        virtual eError Initialize(cTInterface &t)
        {
            return e_ERROR_NONE;
        }
        /**
         **********************************************************************
         * Function: 
         *
         *   Author: $author$
         *     Date: 8/2/2003
         **********************************************************************
         */
        virtual eError Finalize(cTInterface &t)
        {
            return e_ERROR_NONE;
        }
        /**
         **********************************************************************
         * Function: 
         *
         *   Author: $author$
         *     Date: 8/2/2003
         **********************************************************************
         */
        virtual eError Expand
        (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
        {
            return e_ERROR_NONE;
        }
        /**
         **********************************************************************
         * Function: 
         *
         *   Author: $author$
         *     Date: 8/2/2003
         **********************************************************************
         */
        virtual const char *GetName() const
        {
            return m_name;
        }
        /**
         **********************************************************************
         * Function: 
         *
         *   Author: $author$
         *     Date: 8/2/2003
         **********************************************************************
         */
        virtual const char *GetDescription
        (const cParameter *&parameter, int &parameters) const
        {
            parameter = m_parameter;
            parameters = m_parameters;
            return m_description;
        }
        /**
         **********************************************************************
         * Function: GetItem
         *
         *   Author: $author$
         *     Date: 8/4/2003
         **********************************************************************
         */
        virtual cFunctionItem &GetItem()
        {
            return m_item;
        }
        /**
         **********************************************************************
         * Function: GetBranch
         *
         *   Author: $author$
         *     Date: 8/4/2003
         **********************************************************************
         */
        virtual cFunctionBranch &GetBranch()
        {
            return m_branch;
        }
    };

    /**
     **********************************************************************
     *  Class: cValue
     *
     * Author: $author$
     *   Date: 8/3/2003
     **********************************************************************
     */
    class cValue
    : virtual public cValueInterface,
      public cDynamicListItemT<cValue, cImplement>
    {
    public:
        typedef cDynamicListItemT<cValue, cImplement> cIs;

        cCharBuffer m_value;

        /**
         **********************************************************************
         * Constructor: cValue
         *
         *      Author: $author$
         *        Date: 8/3/2003
         **********************************************************************
         */
        cValue(const char *value=0,int valuelen=-1) 
        {
            eError error;
            int count;

            if (value)
            if ((count = m_value.Write(value,valuelen)) < 0)
                throw (error = e_ERROR_WRITE);
        }
        /**
         **********************************************************************
         * Function: Set
         *
         *   Author: $author$
         *     Date: 8/3/2003
         **********************************************************************
         */
        virtual eError Set(const char *value,int valuelen=-1)
        {
            int count;

            if ((count = m_value.Copy(value, valuelen)) < 0)
                return e_ERROR_COPY;

            return e_ERROR_NONE;
        }
        /**
         **********************************************************************
         * Function: Get
         *
         *   Author: $author$
         *     Date: 8/3/2003
         **********************************************************************
         */
        virtual const char *Get() const
        {
            return m_value.GetBuffer();
        }
    };

    /**
     **********************************************************************
     *  Class: cValueList
     *
     * Author: $author$
     *   Date: 8/3/2003
     **********************************************************************
     */
    class cValueList
    : public cDynamicListT<cValue,cValueList>
    {
    public:
        typedef cDynamicListT<cValue,cValueList> cIs;

        /**
         **********************************************************************
         * Constructor: cValueList
         *
         *      Author: $author$
         *        Date: 8/3/2003
         **********************************************************************
         */
        cValueList() 
        {
        }
        /**
         **********************************************************************
         * Function: 
         *
         *   Author: $author$
         *     Date: 8/3/2003
         **********************************************************************
         */
    };

    /**
     **********************************************************************
     *  Class: cVariable
     *
     * Author: $author$
     *   Date: 8/3/2003
     **********************************************************************
     */
    class cVariable
    : virtual public cVariableInterface,
      public cAVLTreeBranchT<cVariable, cImplement>
    {
    public:
        typedef cAVLTreeBranchT<cVariable, cImplement> cIs;

        cCharBuffer m_name;
        cValue m_value;
        cValueList m_value_list;
        cValueList m_value_free_list;

        /**
         **********************************************************************
         * Constructor: cVariable
         *
         *      Author: $author$
         *        Date: 8/3/2003
         **********************************************************************
         */
        cVariable
        (const char *name,int namelen=-1,
         const char *value=0,int valuelen=-1)
        : m_value(value,valuelen)
        {
            eError error;
            int count;

            if (name)
            if ((count = m_name.Write(name,namelen)) < 0)
                throw (error = e_ERROR_WRITE);
        }
        /**
         **********************************************************************
         * Function: SetValue
         *
         *   Author: $author$
         *     Date: 8/3/2003
         **********************************************************************
         */
        virtual eError SetValue(const char *value,int valuelen=-1)
        {
            cValue *cvalue;

            if ((cvalue=m_value_list.GetFirst()))
                return cvalue->Set(value,valuelen);

            return m_value.Set(value,valuelen);
        }
        /**
         **********************************************************************
         * Function: GetValue
         *
         *   Author: $author$
         *     Date: 8/3/2003
         **********************************************************************
         */
        virtual const char *GetValue() const
        {
            cValue *value;

            if ((value=m_value_list.GetFirst()))
                return value->Get();

            return m_value.Get();
        }
        /**
         **********************************************************************
         * Function: PushValue
         *
         *   Author: $author$
         *     Date: 8/3/2003
         **********************************************************************
         */
        virtual eError PushValue(const char *value,int valuelen=-1)
        {
            eError error;
            cValue *cvalue;

            if ((cvalue=m_value_free_list.Pop()))
            {
                if ((error=cvalue->Set(value,valuelen)))
                {
                    delete cvalue;
                    return error;
                }
            }
            else if (!(cvalue=new cValue(value,valuelen)))
                    return e_ERROR_NEW;

            m_value_list.Push(cvalue);
            return e_ERROR_NONE;
        }
        /**
         **********************************************************************
         * Function: PopValue
         *
         *   Author: $author$
         *     Date: 8/3/2003
         **********************************************************************
         */
        virtual eError PopValue()
        {
            cValue *cvalue;

            if (!(cvalue=m_value_list.Pop()))
                return e_ERROR_FAILED;

            m_value_free_list.Push(cvalue);
            return e_ERROR_NONE;
        }

        /**
         **********************************************************************
         * Function: Compare
         *
         *   Author: $author$
         *     Date: 8/3/2003
         **********************************************************************
         */
        int Compare(cVariable &branch) const
        {
            return Compare(branch.GetName());
        }
        /**
         **********************************************************************
         * Function: Compare
         *
         *   Author: $author$
         *     Date: 8/3/2003
         **********************************************************************
         */
        int Compare(const char *name) const
        {
            return m_name.Compare(name);
        }
        /**
         **********************************************************************
         * Function: Compare
         *
         *   Author: $author$
         *     Date: 8/3/2003
         **********************************************************************
         */
        int Compare(const char *name,int length) const
        {
            return m_name.Compare(name, length);
        }

        /**
         **********************************************************************
         * Function: GetName
         *
         *   Author: $author$
         *     Date: 8/3/2003
         **********************************************************************
         */
        inline const char *GetName() const
        {
            return m_name.GetBuffer();
        }
    };

    /**
     **********************************************************************
     *  Class: cVariableTree
     *
     * Author: $author$
     *   Date: 8/3/2003
     **********************************************************************
     */
    class cVariableTree
    : public cAVLTreeT<const char *,cVariable,cVariableTree>
    {
    public:
        typedef cAVLTreeT<const char *,cVariable,cVariableTree> cIs;

        /**
         **********************************************************************
         * Constructor: cVariableTree
         *
         *      Author: $author$
         *        Date: 8/3/2003
         **********************************************************************
         */
        cVariableTree() 
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
        eError AddNew
        (cVariable *&variable,
         const char *name,int namelen=-1,
         const char *value=0,int valuelen=-1)
        {
            if (!(variable=new cVariable
                (name,namelen,value,valuelen)))
                return e_ERROR_NEW;

            Insert(variable);
            return e_ERROR_NONE;
        }
        /**
         **********************************************************************
         * Function: 
         *
         *   Author: $author$
         *     Date: 8/3/2003
         **********************************************************************
         */
        cVariable *Find(const char *name,int namelen=-1) const
        {
            if (namelen<0)
                return cIs::Find(name);

            else if (namelen>0)
                    return cIs::Find(name,namelen);

            return 0;
        }
    };

    /*
     **********************************************************************
     * Members
     **********************************************************************
     */

    static cFunctionList m_function_list;

    char m_mark;
    int m_depth;

    cFunctionItem *m_finalize;
    cFunctionBranch *m_function_branch;
    cFunctionTree m_function_tree;

    cCharBuffer m_name;

    /**
     **********************************************************************
     * Constructor: cTImplement
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cTImplement(char mark='%')
    : m_mark(mark),
      m_depth(0),
      m_finalize(0),
      m_function_branch(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cTImplement
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cTImplement()
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual eError Initialize()
    {
        eError error;
        cFunctionItem *function;

        for (function=m_function_list.GetFirst(); 
             function; function=function->GetNext())
        {
            if ((error=function->GetFunction().Initialize(*this)))
                return e_ERROR_FAILED;

            m_finalize=function;
            m_function_tree.Add(function->GetFunction());
        }

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual eError Finalize()
    {
        eError error,error2;
        cFunctionItem *function;

        error = e_ERROR_NONE;

        for (function = m_finalize; function; 
             function = function->GetPrevious())
        {
            if ((error2 = function->GetFunction().Finalize(*this)))
                error = e_ERROR_FAILED;
        }

        m_finalize = 0;
        return error;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    virtual eError Expand(cCharStream &out,cCharStream &in)
    {
        eError error;
        int count;
        int depth;
        char c;

        if ((count = Get(in,c)) < 0)

        if (count != -e_ERROR_ENDOF)
            return e_ERROR_GET;

        else return e_ERROR_NONE;

        depth=m_depth;
        m_depth=0;

        if ((error = Expand(c,out,in,c)))
            error = e_ERROR_EXPAND;

        m_depth=depth;

        return error;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    virtual eError Expand(char &nextchar,cCharStream &out,cCharStream &in,char c)
    {
        enum eState
        {
            e_STATE_LOOK,
            e_STATE_MARK, 
            e_STATE_NAME, 
            e_STATE_COMMENT, 
            e_STATE_LITERAL,
            e_STATE_LITERAL_NEST, 
            e_STATE_LITERAL_UNNEST, 
            e_STATE_UNNEST,            
        } state;

        eError error;
        eError result;
        unsigned nest;
        int count;

        nest = 0;
        state = e_STATE_LOOK;
        error = e_ERROR_NONE;
        result = e_ERROR_NONE;

        do
        {
            switch(state)
            {
            case e_STATE_LOOK:
                switch(c)
                {
                case ',':
                    if (m_depth>0)
                    {
                        nextchar = c;
                        return result;
                    }
                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;
                    break;

                case ')':
                    if (m_depth>0)
                        state = e_STATE_UNNEST;

                    else if ((count = out.Put(c)) < 1)
                            return e_ERROR_PUT;
                    break;

                default:
                    if (c == m_mark)
                        state = e_STATE_MARK;

                    else if ((count = out.Put(c)) < 1)
                            return e_ERROR_PUT;
                }
                if ((count = Get(in,c)) < 1)
                    error = e_ERROR_GET;
                break;

            case e_STATE_MARK:
                switch(c)
                {
                case '(':
                    state = e_STATE_LITERAL;

                    if ((count = Get(in,c)) < 1)
                        error = e_ERROR_GET;
                    break;

                case '#':
                    state = e_STATE_COMMENT;

                    if ((count = Get(in,c)) < 1)
                        error = e_ERROR_GET;
                    break;

                default:
                    if (c == m_mark)
                    {
                        if ((count = out.Put(c)) < 1)
                            return e_ERROR_PUT;

                        state = e_STATE_LOOK;
                    }
                    else
                    {
                        if ((count = m_name.Clear()) < 0)
                            return e_ERROR_CLEAR;

                        else if ((count = m_name.Put(c)) < 1)
                                return e_ERROR_PUT;

                        state = e_STATE_NAME;
                    }
                    if ((count = Get(in,c)) < 1)
                        error = e_ERROR_GET;
                }
                break;

            case e_STATE_LITERAL:
                switch(c)
                {
                case ')':
                    state = e_STATE_LITERAL_UNNEST;
                    break;

                default:
                    if (c == m_mark)
                        state = e_STATE_LITERAL_NEST;

                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;
                }
                if ((count = Get(in,c)) < 1)
                    error = e_ERROR_GET;
                break;

            case e_STATE_LITERAL_NEST:
                switch(c)
                {
                case '(':
                    nest++;
                    state = e_STATE_LITERAL;

                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;
                    break;

                case ')':
                    state = e_STATE_LITERAL_UNNEST;
                    break;

                default:
                    if (c == m_mark)
                        state = e_STATE_LITERAL;

                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;
                }
                if ((count = Get(in,c)) < 1)
                    error = e_ERROR_GET;
                break;

            case e_STATE_LITERAL_UNNEST:
                if (c == m_mark)
                if (nest > 0)
                    --nest;
                else
                {
                    state = e_STATE_LOOK;

                    if ((count = Get(in,c)) < 1)
                        error = e_ERROR_GET;
                    break;
                }

                if ((count = out.Put(')')) < 1)
                     return e_ERROR_PUT;

                else if (c != ')')
                {
                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;

                    state = e_STATE_LITERAL;
                }
                else 
                    state = state;

                if ((count = Get(in,c)) < 1)
                     error = e_ERROR_GET;
                break;

            case e_STATE_COMMENT:
                switch(c)
                {
                case '\n':
                    state = e_STATE_LOOK;
                    break;
                }
                if ((count = Get(in,c)) < 1)
                    error = e_ERROR_GET;
                break;

            case e_STATE_NAME:
                switch(c)
                {
                case '(':
                    state = e_STATE_LOOK;

                    if ((error = ExpandArguments(c,out,in)))
                    if (error == e_ERROR_BREAK)
                    {
                        nextchar = c;
                        return error;
                    }
                    break;

                default:
                    if (c == m_mark)
                    {
                        state = e_STATE_LOOK;
                        error = ExpandReference(c,out,in);
                    }
                    else
                    {
                        if ((count = m_name.Put(c)) < 1)
                            return e_ERROR_PUT;

                        else if ((count = Get(in,c)) < 1)
                                error = e_ERROR_GET;
                    }
                }
                break;

            case e_STATE_UNNEST:
                if (c == m_mark)
                {
                    nextchar = c;
                    return error;
                }

                if ((count = out.Put(')')) < 1)
                     return e_ERROR_PUT;

                else if (c != ')')
                {
                    state = e_STATE_LOOK;

                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;
                }

                if ((count = Get(in,c)) < 1)
                    error = e_ERROR_GET;
                break;

            default:
                return e_ERROR_EXPAND;
            }
        }
        while(!error);

        nextchar = c;

        return result;
    }
    /**
     **********************************************************************
     * Function: ExpandArguments
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual eError ExpandArguments
    (char &nextchar,cCharStream &out,cCharStream &in)
    {
        eError error;
        eError result;
        cCharBuffer function;
        cFunctionInterface::cArgumentList args;
        cFunctionInterface::cArgument *arg;
        const char *name;
        int count;

        result = e_ERROR_NONE;

        if ((count = Get(in,nextchar)) < 1)
            return e_ERROR_GET;

        if (!(name = m_name.GetBuffer()))
            return e_ERROR_GET_BUFFER;

        if ((count = function.Write(name) < 0))
            return e_ERROR_WRITE;

        if (!(name = function.GetBuffer()))
            return e_ERROR_GET_BUFFER;

        m_depth++;

        do
        {
            if (!(arg = new cFunctionInterface::cArgument))
                break;

            args.Add(arg);

            if ((error = Expand(nextchar, *arg, in, nextchar)))
            {
                if (error != e_ERROR_BREAK)
                    break;

                error = e_ERROR_NONE;
            }

            if ((count = arg->Seek(0)) < 0)
            {
                error = e_ERROR_SEEK;
                break;
            }

            if (nextchar == m_mark)
                break;

            if ((count = Get(in,nextchar)) < 1)
            {
                error = e_ERROR_GET;
                break;
            }
        }
        while(!error);

        --m_depth;

        if (error)
            result=error;

        else
        {
            if ((error = ExpandFunction(out,args,name)))
            if (error != e_ERROR_BREAK)
                 error = e_ERROR_EXPAND;
            else
            {
                error = e_ERROR_NONE;
                result = e_ERROR_BREAK;
            }

            if (!error)
            if ((count = Get(in,nextchar)) < 1)
                error = e_ERROR_GET;
        }

        if ((error = args.Clear()))
            result = e_ERROR_CLEAR;

        return result;
    }
    /**
     **********************************************************************
     * Function: ExpandReference
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    virtual eError ExpandReference
    (char &nextchar,cCharStream &out,cCharStream &in)
    {
        eError error;
        int count;
        const char *name;

        if (!(name = m_name.GetBuffer()))
            return e_ERROR_GET_BUFFER;

        if ((error = ExpandVariable(out,name)))
            return error;

        if ((count = Get(in,nextchar)) < 0)
            error = e_ERROR_GET;

        return error;
    }
    /**
     **********************************************************************
     * Function: ExpandFunction
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual eError ExpandFunction
    (cCharStream &out,cFunction::cArgumentList &args,const char *name)
    {
        cFunctionInterface *function;

        if ((function=FindFunction(name)))
            return function->Expand(out,args,*this);

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: FindFunction
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    inline cFunctionInterface *FindFunction(const char *name,int namelen=-1)
    {
        return m_function_tree.Find(name,namelen);
    }
    /**
     **********************************************************************
     * Function: GetFirstFunction
     *
     *   Author: $author$
     *     Date: 8/3/2005
     **********************************************************************
     */
    virtual cFunctionInterface* GetFirstFunction()
    {
        cFunctionInterface* function = 0;
        cFunctionBranch* branch;
        
        if ((m_function_branch = (branch = m_function_tree.GetFirst())))
            function = &branch->m_function;

        return function;
    }
    /**
     **********************************************************************
     * Function: GetNextFunction
     *
     *   Author: $author$
     *     Date: 8/3/2005
     **********************************************************************
     */
    virtual cFunctionInterface* GetNextFunction()
    {
        cFunctionInterface* function = 0;
        cFunctionBranch* branch;
        
        if (m_function_branch)
        if ((m_function_branch = (branch = m_function_tree.GetNext(m_function_branch))))
            function = &branch->m_function;

        return function;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 9/26/2005
     **********************************************************************
     */
    virtual int Get(cCharStream &in, char &c)
    {
        int count = in.Get(c);
        //printf("%c", c);
        return count;
    }
};


#endif
