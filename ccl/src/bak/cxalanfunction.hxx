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
 *   File: cxalanfunction.hxx
 *
 * Author: $author$
 *   Date: 11/21/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXALANFUNCTION_HXX
#define _CXALANFUNCTION_HXX

#include <XPath/Function.hpp>
#include <XPath/XObjectFactoryDefault.hpp>

#include "cxalandocumentfactoryinterface.hxx"
#include "cxalanvariablesetinterface.hxx"
#include "ccharbuffer.hxx"
#include "clistt.hxx"
#include "nsxalan.hxx"

#define CXALANFUNCTION_DEFAULT_NAME "cXalanFunction"
#define CXALANFUNCTION_DEFAULT_PARAM "()"

/**
 **********************************************************************
 *  Class: cXalanFunction
 *
 * Author: $author$
 *   Date: 11/21/2003
 **********************************************************************
 */
class cXalanFunction
: public nsXalan::Function
{
public:
    typedef nsXalan::Function cIs;

    /**
     **********************************************************************
     *  Class: cListItem
     *
     * Author: $author$
     *   Date: 12/20/2003
     **********************************************************************
     */
    class cListItem
    : public cListItemT<cListItem>
    {
    public:
        typedef cListItemT<cListItem> cIs;

        cXalanFunction &m_function;

        /**
         **********************************************************************
         * Constructor: cListItem
         *
         *      Author: $author$
         *        Date: 12/20/2003
         **********************************************************************
         */
        cListItem(cXalanFunction &function)
        : m_function(function)
        {
        }

        /**
         **********************************************************************
         * Function: GetFunction
         *
         *   Author: $author$
         *     Date: 12/20/2003
         **********************************************************************
         */
        virtual cXalanFunction &GetFunction()
        {
            return m_function;
        }
    };

    /**
     **********************************************************************
     *  Class: cStaticList
     *
     * Author: $author$
     *   Date: 12/20/2003
     **********************************************************************
     */
    class cStaticList
    : public cStaticListT<cListItem, cStaticList>
    {
    public:
        typedef cStaticListT<cListItem, cStaticList> cIs;

        /**
         **********************************************************************
         * Function: GetFirstByName
         *
         *   Author: $author$
         *     Date: 12/22/2003
         **********************************************************************
         */
        cXalanFunction *GetFirstByName(const char *name) const
        {
            cListItem *item;
            const char *fname;

            if (name)
            if ((item = GetFirst()))
            do
            {
                if ((fname = item->GetFunction().GetName()))
                if (!strcmp(name, fname))
                    return &item->GetFunction();
            }
            while ((item = item->GetNext()));

            return 0;
        }
    };

    /**
     **********************************************************************
     *  Class: cResultNodeSet
     *
     * Author: $author$
     *   Date: 12/4/2003
     **********************************************************************
     */
    class cResultNodeSet
    : public nsXalan::XPathExecutionContext::BorrowReturnMutableNodeRefList
    {
    public:
        typedef nsXalan::XPathExecutionContext::BorrowReturnMutableNodeRefList cIs;

        /**
         **********************************************************************
         * Constructor: cResultNodeSet
         *
         *      Author: $author$
         *        Date: 12/4/2003
         **********************************************************************
         */
        cResultNodeSet(nsXalan::XPathExecutionContext &execution_context)
        : cIs(execution_context) 
        {
        }

        /**
         **********************************************************************
         * Function: AddNode
         *
         *   Author: $author$
         *     Date: 12/4/2003
         **********************************************************************
         */
        eError AddNode(nsXalan::XalanNode *xalan_node)
        {
            get()->addNode(xalan_node);
            return e_ERROR_NONE;
        }
        /**
         **********************************************************************
         * Function: GetLength
         *
         *   Author: $author$
         *     Date: 12/4/2003
         **********************************************************************
         */
        int GetLength() const
        {
            return get()->getLength();
        }
        /**
         **********************************************************************
         * Function: GetXalanNodeSet
         *
         *   Author: $author$
         *     Date: 12/4/2003
         **********************************************************************
         */
        inline nsXalan::MutableNodeRefList *GetXalanNodeSet()
        {
            return get();
        }
    };

    /**
     **********************************************************************
     *  Class: cXObjectFactory
     *
     * Author: $author$
     *   Date: 12/4/2003
     **********************************************************************
     */
    class cXObjectFactory
    {
    public:
        nsXalan::XObjectFactory &m_object_factory;

        /**
         **********************************************************************
         * Constructor: cXObjectFactory
         *
         *      Author: $author$
         *        Date: 12/4/2003
         **********************************************************************
         */
        cXObjectFactory(nsXalan::XPathExecutionContext &execution_context)
        : m_object_factory(execution_context.getXObjectFactory()) 
        {
        }

        /**
         **********************************************************************
         * Function: CreateString
         *
         *   Author: $author$
         *     Date: 12/4/2003
         **********************************************************************
         */
        nsXalan::XObjectPtr CreateString(nsXalan::XalanDOMString &string)
        {
            return m_object_factory.createString(string);
        }
        /**
         **********************************************************************
         * Function: CreateNodeSet
         *
         *   Author: $author$
         *     Date: 12/4/2003
         **********************************************************************
         */
        nsXalan::XObjectPtr CreateNodeSet(cResultNodeSet &node_set)
        {
            return m_object_factory.createNodeSet(node_set);
        }
    };

    static cStaticList m_static_list;
    cListItem m_list_item;

    cCharBuffer m_name;
    cCharBuffer m_param;
    cXalanDocumentFactoryInterface *m_xalan_document_factory;
    cXalanVariableSetInterface *m_xalan_variable_set;

    /**
     **********************************************************************
     * Constructor: cXalanFunction
     *
     *      Author: $author$
     *        Date: 11/21/2003
     **********************************************************************
     */
    cXalanFunction
    (const char *name=CXALANFUNCTION_DEFAULT_NAME,
     const char *param=CXALANFUNCTION_DEFAULT_PARAM,
     cXalanDocumentFactoryInterface *xalan_document_factory=0,
     cXalanVariableSetInterface *xalan_variable_set=0)
     : m_list_item(*this),
       m_xalan_document_factory(xalan_document_factory),
       m_xalan_variable_set(xalan_variable_set)
    {
        int length;
        eError error;

        if (name)
        if (0 > (length=SetName(name)))
            throw(error=-length);

        if (param)
        if (0 > (length=SetParam(param)))
            throw(error=-length);
    }
    /**
     **********************************************************************
     * Destructor: ~cXalanFunction
     *
     *     Author: $author$
     *       Date: 11/21/2003
     **********************************************************************
     */
    virtual ~cXalanFunction()
    {
    }

    /**
     **********************************************************************
     * Function: clone
     *
     *   Author: $author$
     *     Date: 11/21/2003
     **********************************************************************
     */
    virtual nsXalan::Function *clone() const
    {
        return new cXalanFunction
        (m_name.GetBuffer(),
         m_param.GetBuffer(),
         m_xalan_document_factory,
         m_xalan_variable_set);
    }
    /**
     **********************************************************************
     * Function: getError
     *
     *   Author: $author$
     *     Date: 11/21/2003
     **********************************************************************
     */
    virtual const nsXalan::XalanDOMString getError() const
    {
        cCharBuffer error;

        error.WriteL
        (m_name.GetBuffer(),
         m_param.GetBuffer()," failed",0);

        return nsXalan::XalanDOMString(error.GetBuffer());
    }
    /**
     **********************************************************************
     * Function: execute
     *
     *   Author: $author$
     *     Date: 11/21/2003
     **********************************************************************
     */
	virtual nsXalan::XObjectPtr execute
    (nsXalan::XPathExecutionContext &executionContext, nsXalan::XalanNode *context,
     const XObjectArgVectorType &args, const nsXerces::Locator *locator) const
    {
        cXObjectFactory object_factory(executionContext);
        cResultNodeSet result_nodeset(executionContext);
        nsXalan::XalanDOMString name_string(m_name.GetBuffer());
        nsXalan::XalanDocument *xalan_document;
        nsXalan::XalanElement *xalan_element;
        eError error;

        if (m_xalan_document_factory)
        if ((xalan_document = m_xalan_document_factory->GetXalanDocument(error)))
        {
            if ((xalan_element = xalan_document->createElement(name_string)))
                result_nodeset.AddNode((nsXalan::XalanNode*)xalan_element);

            return object_factory.CreateNodeSet(result_nodeset);
        }
        return object_factory.CreateString(name_string);
    }

    /**
     **********************************************************************
     * Function: ExecutionError
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual void ExecutionError
    (nsXalan::XPathExecutionContext &executionContext, 
     nsXalan::XalanNode *context, const char *error_message="") const
    {
        cCharBuffer error_buffer;

        error_buffer.WriteL
        (m_name.GetBuffer(), m_param.GetBuffer(), 
         " ", error_message, 0);

        executionContext.error
        (error_buffer.GetBuffer(), context);
    }

    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 11/21/2003
     **********************************************************************
     */
    virtual int SetName(const char *name, int namelen=-1)
    {
        return m_name.Copy(name, namelen);
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/21/2003
     **********************************************************************
     */
    virtual const char *GetName() const
    {
        return m_name.GetBuffer();
    }

    /**
     **********************************************************************
     * Function: SetParam
     *
     *   Author: $author$
     *     Date: 11/21/2003
     **********************************************************************
     */
    virtual int SetParam(const char *param,int paramlen=-1)
    {
        return m_param.Copy(param, paramlen);
    }
    /**
     **********************************************************************
     * Function: GetParam
     *
     *   Author: $author$
     *     Date: 11/21/2003
     **********************************************************************
     */
    virtual const char *GetParam() const
    {
        return m_param.GetBuffer();
    }

    /**
     **********************************************************************
     * Function: SetDocumentFactory
     *
     *   Author: $author$
     *     Date: 12/23/2003
     **********************************************************************
     */
    virtual cXalanDocumentFactoryInterface *SetDocumentFactory
    (cXalanDocumentFactoryInterface *xalan_document_factory)
    {
        m_xalan_document_factory = xalan_document_factory;
        return m_xalan_document_factory;
    }

    /**
     **********************************************************************
     * Function: SetVariableSet
     *
     *   Author: $author$
     *     Date: 12/23/2003
     **********************************************************************
     */
    virtual cXalanVariableSetInterface *SetVariableSet
    (cXalanVariableSetInterface *xalan_variable_set)
    {
        m_xalan_variable_set = xalan_variable_set;
        return m_xalan_variable_set;
    }
};

#define CXALANFUNCTION_NODESET_DEFAULT_NAME "node-set"
#define CXALANFUNCTION_NODESET_DEFAULT_PARAM "(...)"

/**
 **********************************************************************
 *  Class: cXalanFunctionNodeSet
 *
 * Author: $author$
 *   Date: 12/4/2003
 **********************************************************************
 */
class cXalanFunctionNodeSet
: public cXalanFunction
{
public:
    typedef cXalanFunction cIs;

    static cXalanFunctionNodeSet m_static_instance;

    /**
     **********************************************************************
     * Constructor: cXalanFunctionNodeSet
     *
     *      Author: $author$
     *        Date: 12/4/2003
     **********************************************************************
     */
    cXalanFunctionNodeSet
    (const char *name=CXALANFUNCTION_NODESET_DEFAULT_NAME,
     const char *param=CXALANFUNCTION_NODESET_DEFAULT_PARAM,
     cXalanDocumentFactoryInterface *xalan_document_factory=0,
     cXalanVariableSetInterface *xalan_variable_set=0)
     : cIs(name, param, xalan_document_factory, xalan_variable_set)
    {
        m_static_list.Add(&m_list_item);
    }

    /**
     **********************************************************************
     * Function: clone
     *
     *   Author: $author$
     *     Date: 12/4/2003
     **********************************************************************
     */
    virtual nsXalan::Function *clone() const
    {
        return new cXalanFunctionNodeSet
        (m_name.GetBuffer(), 
         m_param.GetBuffer(), 
         m_xalan_document_factory,
         m_xalan_variable_set);
    }
    /**
     **********************************************************************
     * Function: execute
     *
     *   Author: $author$
     *     Date: 12/4/2003
     **********************************************************************
     */
    virtual nsXalan::XObjectPtr execute
    (nsXalan::XPathExecutionContext &executionContext, nsXalan::XalanNode *context,
     const XObjectArgVectorType &args, const nsXerces::Locator *locator) const
    {
        cXObjectFactory object_factory(executionContext);
        cResultNodeSet result_nodeset(executionContext);
        int args_size, arg;

        if (1 > (args_size = args.size()))
            ExecutionError
            (executionContext, context, 
             "requires at least 1 parameter");

        for (arg = 0; arg < args_size; arg++)
        {
            const nsXalan::XObject &xobject = *args[arg];

            if (nsXalan::XObject::eTypeResultTreeFrag == xobject.getType())
            {
                const nsXalan::ResultTreeFragBase &rtree = xobject.rtree();
                nsXalan::XalanNode *xalan_node;

			    if (0 != (xalan_node = rtree.getFirstChild()))
			    do
				    result_nodeset.AddNode(xalan_node);
			    while (0 != (xalan_node = xalan_node->getNextSibling()));
            }
        }

        return object_factory.CreateNodeSet(result_nodeset);
    }
};

#define CXALANFUNCTION_GETVARIABLE_DEFAULT_NAME "get-variable"
#define CXALANFUNCTION_GETVARIABLE_DEFAULT_PARAM "(string,...)"

/**
 **********************************************************************
 *  Class: cXalanFunctionGetVariable
 *
 * Author: $author$
 *   Date: 12/11/2003
 **********************************************************************
 */
class cXalanFunctionGetVariable
: public cXalanFunction
{
public:
    typedef cXalanFunction cIs;

    static cXalanFunctionGetVariable m_static_instance;

    /**
     **********************************************************************
     * Constructor: cXalanFunctionGetVariable
     *
     *      Author: $author$
     *        Date: 12/11/2003
     **********************************************************************
     */
    cXalanFunctionGetVariable
    (const char *name=CXALANFUNCTION_GETVARIABLE_DEFAULT_NAME,
     const char *param=CXALANFUNCTION_GETVARIABLE_DEFAULT_PARAM,
     cXalanDocumentFactoryInterface *xalan_document_factory=0,
     cXalanVariableSetInterface *xalan_variable_set=0)
     : cIs(name, param, xalan_document_factory, xalan_variable_set)
    {
        m_static_list.Add(&m_list_item);
    }

    /**
     **********************************************************************
     * Function: clone
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual nsXalan::Function *clone() const
    {
        return new cXalanFunctionGetVariable
        (m_name.GetBuffer(), 
         m_param.GetBuffer(), 
         m_xalan_document_factory,
         m_xalan_variable_set);
    }
    /**
     **********************************************************************
     * Function: execute
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual nsXalan::XObjectPtr execute
    (nsXalan::XPathExecutionContext &executionContext, nsXalan::XalanNode *context,
     const XObjectArgVectorType &args, const nsXerces::Locator *locator) const
    {
        cXObjectFactory object_factory(executionContext);
        cResultNodeSet result_nodeset(executionContext);
        int args_size, arg;

        if (!m_xalan_variable_set)
            ExecutionError
            (executionContext, context, 
             "has NULL m_xalan_variable_set");

        if (1 > (args_size = args.size()))
            ExecutionError
            (executionContext, context, 
             "requires at least 1 parameter");

        if (m_xalan_variable_set)
        for (arg = 0; arg < args_size; arg++)
        {
            const nsXalan::XObject &xobject = *args[arg];

            if (nsXalan::XObject::eTypeString != xobject.getType())
            {
                ExecutionError
                (executionContext, context, 
                 "has argument that is not a string");
                break;
            }
            else
            {
                const nsXalan::XalanDOMString &string=xobject.str();
                nsXalan::XalanNode *xalan_node;

			    if (0 != (xalan_node = m_xalan_variable_set->Get(string)))
			    do
				    result_nodeset.AddNode(xalan_node);
			    while (0 != (xalan_node = xalan_node->getNextSibling()));
            }
        }

        return object_factory.CreateNodeSet(result_nodeset);
    }
};

#endif
