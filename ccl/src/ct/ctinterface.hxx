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
 *   File: ctinterface.hxx
 *
 * Author: $author$
 *   Date: 7/7/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTINTERFACE_HXX
#define _CTINTERFACE_HXX

#include <string.h>

#include "ccharbuffer.hxx"
#include "cavltreet.hxx"
#include "clistt.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cTInterface
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cTInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 8/2/2003
     **********************************************************************
     */
    enum
    {
        e_FIRST_ERROR=cInterface::e_NEXT_ERROR,
        e_ERROR_EXPAND,
        e_ERROR_BREAK,
        e_NEXT_ERROR,
        e_LAST_ERROR=e_NEXT_ERROR-1
    };

    /**
     **********************************************************************
     *  Class: cValueInterface
     *
     * Author: $author$
     *   Date: 7/8/2003
     **********************************************************************
     */
    class c_INTERFACE_CLASS cValueInterface
    : virtual public cInterface
    {
    public:
        /**
         **********************************************************************
         * Function: Set
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        virtual eError Set(const char *value,int valuelen=-1)=0;
        /**
         **********************************************************************
         * Function: Get
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        virtual const char *Get() const=0;
    };

    /**
     **********************************************************************
     *  Class: cVariableInterface
     *
     * Author: $author$
     *   Date: 7/8/2003
     **********************************************************************
     */
    class c_INTERFACE_CLASS cVariableInterface
    : virtual public cInterface
    {
    public:
        /**
         **********************************************************************
         * Function: SetValue
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        virtual eError SetValue(const char *value,int valuelen=-1)=0;
        /**
         **********************************************************************
         * Function: GetValue
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        virtual const char *GetValue() const=0;
        /**
         **********************************************************************
         * Function: PushValue
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        virtual eError PushValue(const char *value,int valuelen=-1)=0;
        /**
         **********************************************************************
         * Function: PopValue
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        virtual eError PopValue()=0;
    };

    class cFunctionItem;
    class cFunctionBranch;

    /**
     **********************************************************************
     *  Class: cFunctionInterface
     *
     * Author: $author$
     *   Date: 7/7/2003
     **********************************************************************
     */
    class c_INTERFACE_CLASS cFunctionInterface
    : virtual public cInterface
    {
    public:

        /**
         **********************************************************************
         *  Class: cParameter
         *
         * Author: $author$
         *   Date: 7/15/2003
         **********************************************************************
         */
        class cParameter
        {
        public:
            const char *m_name;
            const char *m_description;

            /**
             **********************************************************************
             * Function: GetName
             *
             *   Author: $author$
             *     Date: 7/15/2003
             **********************************************************************
             */
            inline const char *GetName() const
            {
                return m_name;
            }
            /**
             **********************************************************************
             * Function: GetDescription
             *
             *   Author: $author$
             *     Date: 7/15/2003
             **********************************************************************
             */
            inline const char *GetDescription() const
            {
                return m_description;
            }
        };

        /**
         **********************************************************************
         *  Class: cArgument
         *
         * Author: $author$
         *   Date: 7/15/2003
         **********************************************************************
         */
        class cArgument
        : public cDynamicListItemT<cArgument,cCharBuffer>
        {
        public:
            typedef cDynamicListItemT<cArgument,cCharBuffer> cIs;
        };

        /**
         **********************************************************************
         *  Class: cArgumentList
         *
         * Author: $author$
         *   Date: 7/15/2003
         **********************************************************************
         */
        class cArgumentList
        : public cDynamicListT<cArgument,cArgumentList>
        {
        public:
            typedef cDynamicListT<cArgument,cArgumentList> cIs;
        };

        /**
         **********************************************************************
         * Function: Initialize
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        virtual eError Initialize(cTInterface &t)=0;
        /**
         **********************************************************************
         * Function: Finalize
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        virtual eError Finalize(cTInterface &t)=0;
        /**
         **********************************************************************
         * Function: Expand
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        virtual eError Expand
        (cCharStream &result,
         cArgumentList &arglist,cTInterface &t) const=0;
        /**
         **********************************************************************
         * Function: GetName
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        virtual const char *GetName() const=0;
        /**
         **********************************************************************
         * Function: GetDescription
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        virtual const char *GetDescription
        (const cParameter *&parameter, int &parameters) const=0;
        /**
         **********************************************************************
         * Function: GetItem
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        virtual cFunctionItem &GetItem()=0;
        /**
         **********************************************************************
         * Function: GetBranch
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        virtual cFunctionBranch &GetBranch()=0;
    };

    /**
     **********************************************************************
     *  Class: cFunctionItem
     *
     * Author: $author$
     *   Date: 7/7/2003
     **********************************************************************
     */
    class cFunctionItem
    : public cListItemT<cFunctionItem>
    {
    public:
        typedef cListItemT<cFunctionItem> cIs;

        cFunctionInterface &m_function;

        /**
         **********************************************************************
         * Constructor: cFunctionItem
         *
         *      Author: $author$
         *        Date: 7/7/2003
         **********************************************************************
         */
        cFunctionItem(cFunctionInterface &function)
        : m_function(function) 
        {
        }
        /**
         **********************************************************************
         * Function: GetFunction
         *
         *   Author: $author$
         *     Date: 7/7/2003
         **********************************************************************
         */
        inline cFunctionInterface &GetFunction()
        {
            return m_function;
        }
    };

    /**
     **********************************************************************
     *  Class: cFunctionList
     *
     * Author: $author$
     *   Date: 7/15/2003
     **********************************************************************
     */
    class cFunctionList
    : public cStaticListT<cFunctionItem,cFunctionList>
    {
    public:
        typedef cStaticListT<cFunctionItem,cFunctionList> cIs;
    };

    /**
     **********************************************************************
     *  Class: cFunctionBranch
     *
     * Author: $author$
     *   Date: 7/8/2003
     **********************************************************************
     */
    class cFunctionBranch
    : public cAVLTreeBranchT<cFunctionBranch>
    {
    public:
        typedef cAVLTreeBranchT<cFunctionBranch> cIs;

        cFunctionInterface &m_function;

        /**
         **********************************************************************
         * Constructor: cFunctionBranch
         *
         *      Author: $author$
         *        Date: 7/8/2003
         **********************************************************************
         */
        cFunctionBranch(cFunctionInterface &function)
        : m_function(function) 
        {
        }
        /**
         **********************************************************************
         * Function: Compare
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        int Compare(cFunctionBranch &branch) const
        {
            return Compare(branch.m_function.GetName());
        }
        /**
         **********************************************************************
         * Function: Compare
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        int Compare(const char *name) const
        {
            const char *m_name = m_function.GetName();
            return strcmp(m_name, name);
        }
        /**
         **********************************************************************
         * Function: Compare
         *
         *   Author: $author$
         *     Date: 7/8/2003
         **********************************************************************
         */
        int Compare(const char *name, int length) const
        {
            const char *m_name = m_function.GetName();
            int namelen = strlen(m_name);
            int lendiff = namelen-length;
            int result;

            if (0 < lendiff)
                namelen = length;

            if (!(result=strncmp(m_name, name, namelen)))
                return lendiff;

            return result;
        }
    };

    /**
     **********************************************************************
     *  Class: cFunctionTree
     *
     * Author: $author$
     *   Date: 7/15/2003
     **********************************************************************
     */
    class cFunctionTree
    : public cAVLTreeT<const char *,cFunctionBranch,cFunctionTree>
    {
    public:
        typedef cAVLTreeT<const char *,cFunctionBranch,cFunctionTree> cIs;

        /**
         **********************************************************************
         * Function: Add
         *
         *   Author: $author$
         *     Date: 7/15/2003
         **********************************************************************
         */
        void Add(cFunctionInterface &function)
        {
            cIs::Insert(&function.GetBranch());
        }
        /**
         **********************************************************************
         * Function: Find
         *
         *   Author: $author$
         *     Date: 7/15/2003
         **********************************************************************
         */
        cFunctionInterface *Find(const char *name,int namelen=-1) const
        {
            cFunctionBranch *branch;

            if (namelen<0)
            {
                if ((branch=cIs::Find(name)))
                    return &branch->m_function;
            }
            else if (namelen>0)
            {
                if ((branch=cIs::Find(name,namelen)))
                    return &branch->m_function;
            }

            return 0;
        }
    };

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual eError Initialize()
    {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual eError Finalize()
    {
        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual const char *SetValue
    (const char *name,int namelen=-1,
     const char *value=0,int valuelen=-1)
    {
        cVariableInterface *variable;

        if ((variable=SetVariable
            (name,namelen,value,valuelen)))
            return variable->GetValue();

        return 0;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual const char *GetValue
    (const char *name,int namelen=-1)
    {
        cVariableInterface *variable;

        if ((variable=GetVariable(name,namelen)))
            return variable->GetValue();

        return 0;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual eError Expand(cCharStream &out,cCharStream &in)=0;
    /**
     **********************************************************************
     * Function: SetVariable
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual cVariableInterface *SetVariable
    (const char *name,int namelen=-1,
     const char *value=0,int valuelen=-1)=0;
    /**
     **********************************************************************
     * Function: GetVariable
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual cVariableInterface *GetVariable
    (const char *name,int namelen=-1,
     const char *value=0,int valuelen=-1)=0;
    /**
     **********************************************************************
     * Function: ExpandVariable
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual eError ExpandVariable(cCharStream &out,const char *name)=0;
    /**
     **********************************************************************
     * Function: ExpandFunction
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual eError ExpandFunction
    (cCharStream &out,cFunctionInterface::cArgumentList &args,const char *name)=0;

    /**
     **********************************************************************
     * Function: GetFirstFunction
     *
     *   Author: $author$
     *     Date: 8/3/2005
     **********************************************************************
     */
    virtual cFunctionInterface* GetFirstFunction() = 0;
    /**
     **********************************************************************
     * Function: GetNextFunction
     *
     *   Author: $author$
     *     Date: 8/3/2005
     **********************************************************************
     */
    virtual cFunctionInterface* GetNextFunction() = 0;
};


#endif
