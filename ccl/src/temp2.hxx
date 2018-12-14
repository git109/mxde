    /**
     **********************************************************************
     * Function: yyparse
     *
     *   Author: $author$
     *     Date: 8/26/2003
     **********************************************************************
     */
    /**
     **********************************************************************
     * Function
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnInclude()
    {
        const char *descr;
        cError error;

        if (!(error=m_lexer.OnInclude()))
            return error;

        if (!(error=m_lexer.GetLastError(error,descr)))
            yyerror(descr);

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnFile
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnFile()
    {
        cError error;
        cElementInterface *element;

        if ((element=PullElement(m_element_list)))
        {
            do
            {
                if (!(error=m_document.GetElementSet().ReferenceElement(*element)))
                if (!(element=PullElement(m_element_list)))
                    return c_ERROR_NONE;
            }
            while(!error);
        }
        return c_ERROR_FAIL;
    }


    /**
     **********************************************************************
     * Function OnIf
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnIf(bool not=false)
    {
        cError error;
        cBuffer buffer;

        if (!(error=buffer.CopyStringL
            (m_element_namespace_prefix,":",(not)?"else":"if",0)))
            return PushElement
            (buffer.GetCharBuffer(),buffer.GetLength());

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnIfNot
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnIfNot()
    {
        return OnIf(true);
    }
    /**
     **********************************************************************
     * Function OnIfThen
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnIfThen()
    {
        return OnFunctionArgs(2);
    }
    /**
     **********************************************************************
     * Function OnIfElse
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnIfElse()
    {
        return OnFunctionArgs(3);
    }
    /**
     **********************************************************************
     * Function OnLoop
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnLoop()
    {
        return OnFunctionArgs(2);
    }
    /**
     **********************************************************************
     * Function OnDoWhile
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnDoWhile()
    {
        cError error;

        if (!(error=OnFunction("do-while")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function OnWhile
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnWhile()
    {
        return OnFunction("while");
    }
    /**
     **********************************************************************
     * Function OnUntil
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnUntil()
    {
        return OnFunction("until");
    }
    /**
     **********************************************************************
     * Function OnDoUntil
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnDoUntil()
    {
        cError error;

        if (!(error=OnFunction("do-until")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function OnWith
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnWith()
    {
        cError error;

        if (!(error=OnFunction("with")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function OnFor
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnFor()
    {
        cError error;

        if (!(error=OnFunction("for")))
            return OnArgsFunction(4);

        return error;
    }
    /**
     **********************************************************************
     * Function OnForEach
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnForEach()
    {
        cError error;

        if (!(error=OnFunction("for-each")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function OnForEachOf
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnForEachOf()
    {
        cError error;

        if (!(error=OnFunction("for-each-of")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function OnForEachAttribute
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnForEachAttribute()
    {
        cError error;

        if (!(error=OnFunction("for-each-attribute")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function OnForEachAttributeOf
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnForEachAttributeOf()
    {
        cError error;

        if (!(error=OnFunction("for-each-attribute-of")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function OnSwitchCondition
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnSwitchCondition()
    {
        cError error;

        if (!(error=OnFunction("case")))
        if (!(error=OnArgsFunction(1)))
            return OnFunction("case-list");

        return error;
    }
    /**
     **********************************************************************
     * Function OnSwitchCaseList
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnSwitchCaseList()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function OnSwitchDefault
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnSwitchDefault()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function OnSwitchCaseStatement
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnSwitchCaseStatement()
    {
        cError error;

        if (!(error=OnFunction("case-do")))
        if (!(error=OnArgsFunction(2)))
            return OnFunctionArgs(1);

        return error;
    }
    /**
     **********************************************************************
     * Function OnSwitchCaseMatch
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnSwitchCaseMatch()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function OnSwitchCase
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnSwitchCase()
    {
        cError error;

        if (!(error=OnFunction("case-when")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function OnCase
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnCase()
    {
        cError error;

        if (!(error=OnFunction("when")))
            return OnFunction("when-list");

        return error;
    }
    /**
     **********************************************************************
     * Function OnCaseList
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnCaseList()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function OnCaseDefault
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnCaseDefault()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnCaseWhenStatement()
    {
        cError error;

        if (!(error=OnFunction("when-do")))
        if (!(error=OnArgsFunction(2)))
            return OnFunctionArgs(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnCaseWhenList()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnCaseWhen()
    {
        cError error;

        if (!(error=OnFunction("when-case")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnCompoundStatementBegin()
    {
        cError error;
        cBuffer buffer;

        if (!(error=buffer.CopyStringL
            (m_element_namespace_prefix,":do",0)))
        if (!(error=PushElement
            (buffer.GetCharBuffer(),buffer.GetLength())))
            return c_ERROR_NONE;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnCompoundStatementItem()
    {
        cError error;
        cElementInterface *op;
        cElementInterface *arg;

        if ((arg=PopElement()))
        {
            if (!(error=!(op=TopElement())))
                error=op->ReferenceElement(*arg);

            arg->FreeInstance();

            if (!error)
                return c_ERROR_NONE;
        }
        return c_ERROR_FAIL;
    }


    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnConditionalExpr()
    {
        cError error;

        if (!(error=OnIf()))
            return OnArgsFunction(3);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElseConditionalExpr()
    {
        cError error;

        if (!(error=OnFunction("if-else")))
            return OnArgsFunction(2);

        return error;
    }


    /**
     **********************************************************************
     * Function OnCall
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnCall()
    {
        return OnArgsFunction(2,"apply-template");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnMethodCall()
    {
        return OnArgsFunction(2,"apply-method");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnMethodOfCall()
    {
        return OnArgsFunction(3,"apply-method-of");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnMethodIdentifierCall()
    {
        return OnArgsFunction(2,"apply-method-template");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnDocumentMethodIdentifierCall()
    {
        return OnArgsFunction(2,"apply-document-class-method-template");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURIMethodCall()
    {
        return OnArgsFunction(3,"get-document-from-service");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURIRequestMethodCall()
    {
        return OnArgsFunction(2,"get-document-from-service-request");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURIMethodIdentifierCall()
    {
        return OnFunctionArgs(2);
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURINativeCall()
    {
        return OnArgsFunction(3,"apply-template-extension");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURIForeignCall()
    {
        return OnArgsFunction(3,"apply-foreign-template-extension");
    }


    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnEmptyArguments()
    {
        cError error;

        if (!(error=OnFunction("arguments")))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnFirstArgument()
    {
        cError error;

        if (!(error=OnFunction("arguments")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnNextArgument()
    {
        cError error;

        if (!(error=OnFunctionArgs(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTypedArgument()
    {
        cError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnReverseArgs(3)))
        if (!(error=OnFunction("argument")))
        if (!(error=OnArgsFunction(3)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTypeArgument()
    {
        cError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunction("is")))
        if (!(error=OnFunction("argument")))
        if (!(error=OnArgsFunction(1)))
        if (!(error=OnArgsFunction(2)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnArgument()
    {
        cError error;

        if (!(error=OnFunction("argument")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return c_ERROR_FAIL;
    }


    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnMethodIdentifierList()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnObjectMethodIdentifierPair()
    {
        cError error;

        if (!(error=OnFunction("select")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnRequestMethodIdentifierList()
    {
        cError error;

        if (!(error=OnFunction("create-service-request")))
        if (!(error=OnFunction("null")))
        if (!(error=OnFunctionArgs(1)))
        if (!(error=OnReverseArgs(2)))
            return error;

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnMethodURI()
    {
        cError error;

        if (!(error=OnFunction("get-document-from-service")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnRequestMethodURI()
    {
        cError error;

        if (!(error=OnFunction("create-service-request")))
            return OnArgsFunction(1);

        return error;
    }


    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnGetMember()
    {
        cError error;

        if (!(error=OnFunction("get-member")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnGetMemberOf()
    {
        cError error;

        if (!(error=OnFunction("get-element-of")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnGetMembersWhere()
    {
        cError error;

        if (!(error=OnFunction("get-members-where")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnGetMembersOfWhere()
    {
        cError error;

        if (!(error=OnFunction("get-elements-of-where")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return c_ERROR_FAIL;
    }


    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnVariable()
    {
        cError error;
        cElementInterface *op;
        cElementInterface *arg;
        cBuffer buffer;

        if ((arg=PopElement()))
        {
            if (!(error=buffer.CopyStringL
                (m_element_namespace_prefix,":get-variable",0)))
            if (!(error=PushElement
                (op,buffer.GetCharBuffer(),buffer.GetLength())))
                error=op->ReferenceElement(*arg);

            arg->FreeInstance();

            if (!error)
                return error;
        }

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnIdentifier()
    {
        cError error;
        cToken *token;

        if ((token=m_lexer.PopToken()))
        if (!(error=PushTextElement(token->Get())))
        if (!(error=OnFunction("id")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return c_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnIdentifierExpr()
    {
        cError error;
        cToken *token;
        cElementInterface *op;
        cElementInterface *arg;
        cBuffer buffer;

        if ((token=m_lexer.PopToken()))
        if (!(error=buffer.CopyStringL
            (m_element_namespace_prefix,":is",0)))
        if (!(error=PushElement
            (op,buffer.GetCharBuffer(),buffer.GetLength())))
        if (!(error=op->AddTextElement(arg,token->Get())))
            return error;

        return c_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnCallIdentifier()
    {
        cError error;
        cToken *token;

        if ((token=m_lexer.PopToken()))
        if (!(error=PushElement(token->Get())))
            return error;

        return c_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURIdentifier()
    {
        cError error;
        cToken *token;

        if ((token=m_lexer.PopToken()))
        if (!(error=PushTextElement(token->Get())))
        if (!(error=OnFunction("uri")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return c_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURIObjectIdentifier()
    {
        cError error;

        if (!(error=OnFunction("select")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnRequestURIObjectIdentifier()
    {
        cError error;

        if (!(error=OnFunction("select")))
        if (!(error=OnArgsFunction(1)))
        if (!(error=OnFunction("create-service-request")))
        if (!(error=OnFunction("null")))
        if (!(error=OnFunctionArgs(1)))
        if (!(error=OnReverseArgs(2)))
            return error;

        return error;
    }


    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURIURITransform()
    {
        cError error;

        if (!(error=OnFunction("transform-document")))
        if (!(error=OnArgsFunction(3)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURIContent()
    {
        cError error;

        if (!(error=OnFunctionArgs(2)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnIdentifierURIContent()
    {
        cError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunctionArgs(3)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURIArguments()
    {
        cError error;

        if (!(error=OnFunctionArgs(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnIdentifierURIExpr()
    {
        cError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunction("get-document")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURIExpr()
    {
        cError error;

        if (!(error=OnFunction("is")))
        if (!(error=OnFunction("get-document")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return c_ERROR_FAIL;
    }


    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementWhereExpr()
    {
        cError error;

        if (!(error=OnFunction("get-elements-of-where")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementRangeExpr()
    {
        cError error;

        if (!(error=OnFunction("get-elements-of-range")))
            return OnArgsFunction(3);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnAllElementsExpr()
    {
        cError error;

        if (!(error=OnFunction("get-elements-of")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementAtExpr()
    {
        cError error;

        if (!(error=OnFunction("get-element-of-at")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnRootElementRange()
    {
        cError error;

        if (!(error=OnFunction("get-root-elements-in")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementRange()
    {
        cError error;

        if (!(error=OnFunction("get-elements-in")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnRootElementAt()
    {
        cError error;

        if (!(error=OnFunction("get-root-element-at")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementAt()
    {
        cError error;

        if (!(error=OnFunction("get-element-at")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnRootElementWhere()
    {
        cError error;

        if (!(error=OnFunction("get-root-elements-where")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementWhere()
    {
        cError error;

        if (!(error=OnFunction("get-elements-where")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnAllRootElements()
    {
        return OnFunction("get-root-elements");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnAllElements()
    {
        return OnFunction("get-elements");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnParentElementExpr()
    {
        cError error;

        if (!(error=OnFunction("get-parent-element-of")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementExpr()
    {
        cError error;

        if (!(error=OnFunction("get-element-of")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnRootElementExpr()
    {
        cError error;

        if (!(error=OnFunction("get-element-of-root")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnRootElement()
    {
        return OnFunction("get-root-element");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementIs()
    {
        return OnFunction("get-element");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnParentElement()
    {
        return OnFunction("element-parent");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementSize()
    {
        return OnFunction("element-count");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementType()
    {
        return OnFunction("element-type");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementPosition()
    {
        return OnFunction("element-position");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementText()
    {
        return OnFunction("element-text");
    }


    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnAttribute()
    {
        cError error;

        if (!(error=OnFunction("get-attribute")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnAttributeOf()
    {
        cError error;

        if (!(error=OnFunction("get-attribute-of")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnAttributesOfWhere()
    {
        cError error;

        if (!(error=OnFunction("get-attributes-of-where")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnAttributeOfAt()
    {
        cError error;

        if (!(error=OnFunction("get-attribute-of-at")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnAttributesOfRange()
    {
        cError error;

        if (!(error=OnFunction("get-attributes-of-in")))
            return OnArgsFunction(3);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnAllAttributesOf()
    {
        cError error;

        if (!(error=OnFunction("get-attributes-of")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnAttributeRange()
    {
        cError error;

        if (!(error=OnFunction("get-attributes-in")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnAttributeAt()
    {
        cError error;

        if (!(error=OnFunction("get-attributes-at")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnAttributeWhere()
    {
        cError error;

        if (!(error=OnFunction("get-attributes-where")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnAllAttributes()
    {
        return OnFunction("get-attributes");
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnAttributeIs()
    {
        return OnFunction("get-attribute");
    }


    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTypeReference()
    {
        cError error;

        if (!(error=OnFunction("reference")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function OnDimentionedTypeReference
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnDimentionedTypeReference()
    {
        cError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunctionArgs(1)))
            return error;

        return error;
    }
    /**
     **********************************************************************
     * Function OnDimentionedTypeDefinition
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnDimentionedTypeDefinition()
    {
        cError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunction("definition")))
        if (!(error=OnArgsFunction(1)))
        if (!(error=OnFunctionArgs(1)))
            return error;

        return error;
    }
    /**
     **********************************************************************
     * Function OnTypeDefinition
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTypeDefinition()
    {
        cError error;

        if (!(error=OnFunction("definition")))
            return OnArgsFunction(1);

        return error;
    }


    /**
     **********************************************************************
     * Function OnDimentions
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnDimentions()
    {
        cError error;

        if (!(error=OnFunction("array")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function OnOfDimentions
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnOfDimentions()
    {
        cError error;

        if (!(error=OnFunctionArgs(1)))
            return error;

        return error;
    }
    /**
     **********************************************************************
     * Function OnDimention
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnDimention()
    {
        cError error;

        if (!(error=OnFunction("dimensions")))
            return OnArgsFunction(1);

        return error;
    }
    /**
     **********************************************************************
     * Function OnDimentionList
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnDimentionList()
    {
        cError error;

        if (!(error=OnFunctionArgs(1)))
            return error;

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnUnboundDimentions()
    {
        cError error;

        if (!(error=OnFunction("dimensions")))
            return error;

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnUnboundDimention()
    {
        cError error;

        if (!(error=OnFunction("dimension")))
        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunction("dimensions")))
            return OnArgsFunction(2);

        return error;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnDimentionExpr()
    {
        cError error;

        if (!(error=OnFunction("dimention")))
            return OnArgsFunction(1);

        return error;
    }


    /**
     **********************************************************************
     * Function OnStruct
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnStruct()
    {
        cError error;

        if (!(error=OnFunction("struct")))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnUnion
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnUnion()
    {
        cError error;

        if (!(error=OnFunction("union")))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnIntrinsicType
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnIntrinsicType(const char *name)
    {
        cError error;
        cElementInterface *op;

        if (!(error=OnFunction("intrinsic")))
        if ((op=TopElement()))
        if (!(error=op->AddElement(op,name)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnMember
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnMember()
    {
        return OnFunctionArgs(1);
    }
    /**
     **********************************************************************
     * Function OnVariableDeclaration
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnVariableDeclaration()
    {
        cError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunction("variable")))
            return OnArgsFunction(2);

        return c_ERROR_FAIL;
    }


    /**
     **********************************************************************
     * Function OnTemplateName
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTemplateName()
    {
        cError error;

        if (!(error=OnFunction("template")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnTypedTemplateName
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTypedTemplateName()
    {
        cError error;

        if (!(error=OnReverseArgs(2)))
        if (!(error=OnFunction("return")))
        if (!(error=OnArgsFunction(1)))
        if (!(error=OnFunction("prototype")))
        if (!(error=OnArgsFunction(2)))
        if (!(error=OnFunction("template")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function On
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTemplateParameters()
    {
        cError error;
        cElementInterface *op;
        cElementInterface *arg;
        cElementInterface *name;

        if ((arg=PopElement()))
        {
            if (!(error=!(op=TopElement())))
            if (!(error=!(name=op->GetFirstParentElement())))
                error=name->ReferenceElement(*arg);

            arg->FreeInstance();

            if (!error)
                return error;
        }

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnTemplateParameter
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnFirstTemplateParameter()
    {
        cError error;

        if (!(error=OnFunction("parameters")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnTemplateParameter
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTemplateParameter()
    {
        cError error;

        if (!(error=OnFunctionArgs(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnTemplateParameterName
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTemplateParameterName()
    {
        cError error;

        if (!(error=OnFunction("parameter")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnTypedTemplateParameterName
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTypedTemplateParameterName()
    {
        cError error;

        if (!(error=OnFunction("is")))
        if (!(error=OnFunction("parameter")))
        if (!(error=OnArgsFunction(2)))
        if (!(error=OnArgsFunction(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnTemplateParameterValue
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTemplateParameterValue()
    {
        cError error;

        if (!(error=OnFunction("parameter")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnTypedTemplateParameterValue
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTypedTemplateParameterValue()
    {
        cError error;

        if (!(error=OnFunction("parameter")))
        if (!(error=OnArgsFunction(2)))
        if (!(error=OnArgsFunction(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnTemplate
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTemplate()
    {
        cError error;
        cElementInterface *op;
        cElementInterface *arg;

        if ((arg=PopElement()))
        {
            if (!(error=!(op=TopElement())))
                error=op->ReferenceElement(*arg);

            arg->FreeInstance();

            if (!error)
                return error;
        }

        return c_ERROR_FAIL;
    }


    /**
     **********************************************************************
     * Function OnInterfaceName
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnInterfaceName()
    {
        cError error;

        if (!(error=OnFunction("named")))
        if (!(error=OnArgsFunction(1)))
        if (!(error=OnFunction("interface")))
            return OnArgsFunction(1);

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnNamespaceName
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnNamespaceName()
    {
        cError error;

        if (!(error=OnFunction("namespace")))
            return OnArgsFunction(1);

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnClassName
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnClassName()
    {
        cError error;

        if (!(error=OnFunction("extends")))
        if (!(error=OnFunction("implements")))
        if (!(error=OnFunction("class")))
            return OnArgsFunction(3);

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnClassIs
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnClassIs()
    {
        cError error;
        cElementInterface *arg;
        cElementInterface *op;

        if (!(error=!(arg=PopElement())))
        {
            if (!(error=!(op=TopElement())))
            if (!(error=!(op=op->GetFirstElement())))
            if (!(error=!(op=op->GetNextParent())))
                error=op->ReferenceElement(*arg);

            arg->FreeInstance();

            if (!error)
                return error;
        }

        return c_ERROR_FAIL;
    }


    /**
     **********************************************************************
     * Function OnURILevelName
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURILevelName()
    {
        cError error;

        if (!(error=OnFunction("location")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnURIQualifiedName
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURIQualifiedName()
    {
        cError error;

        if (!(error=OnFunction("location")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnDocumentLevelName
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnDocumentLevelName()
    {
        cError error;

        if (!(error=OnFunction("document")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnDocumentQualifiedName
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnDocumentQualifiedName()
    {
        cError error;

        if (!(error=OnFunction("document")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnElementLevelName
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementLevelName()
    {
        cError error;

        if (!(error=OnFunction("element")))
        if (!(error=OnArgsFunction(1)))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnElementQualifiedName
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementQualifiedName()
    {
        cError error;

        if (!(error=OnFunctionArgs(1)))
            return error;

        return c_ERROR_FAIL;
    }


    /**
     **********************************************************************
     * Function OnBinaryExpr
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnBinaryExpr()
    {
        cError error;
        cElementInterface *op;
        cElementInterface *arg1;
        cElementInterface *arg2;

        if (!(error=!(arg2=PopElement())))
        {
            if (!(error=!(op=PopElement())))
            {
                if (!(error=!(arg1=PopElement())))
                {
                    if (!(error=op->ReferenceElement(*arg1)))
                    if (!(error=op->ReferenceElement(*arg2)))
                        error=PushElement(op);

                    arg1->FreeInstance();
                }
                if (error)
                    op->FreeInstance();
            }
            arg2->FreeInstance();

            if (!error)
                return error;
        }

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnUnaryExpr
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnUnaryExpr()
    {
        cError error;
        cElementInterface *op;
        cElementInterface *arg;

        if (!(error=!(arg=PopElement())))
        {
            if (!(error=!(op=TopElement())))
                error=op->ReferenceElement(*arg);

            arg->FreeInstance();

            if (!error)
                return error;
        }

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnPostfixExpr
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnPostfixExpr()
    {
        cError error;
        cElementInterface *op;
        cElementInterface *arg;

        if (!(error=!(op=PopElement())))
        {
            if (!(error=!(arg=PopElement())))
            {
                if (!(error=op->ReferenceElement(*arg)))
                    error=PushElement(op);

                arg->FreeInstance();
            }
            if (!error)
                return error;

            op->FreeInstance();
        }
        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnCastExpr
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnCastExpr()
    {
        cError error;

        if (!(error=OnFunction("as-class")))
        if (!(error=OnArgsFunction(2)))
            return error;

        return c_ERROR_FAIL;
    }


    /**
     **********************************************************************
     * Function OnPostfixOperator
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnPostfixOperator()
    {
        cError error;
        cElementInterface *element;
        cBuffer buffer;

        if ((element=TopElement()))
        if (!(error=buffer.CopyStringL
            (element->GetText(),"-after",0)))
        if (!(error=element->SetText
            (buffer.GetCharBuffer(),buffer.GetLength())))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnBinaryOperator
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnBinaryOperator(int yychar)
    {
        return OnArgsFunction(2,GetOperatorName(yychar));
    }
    /**
     **********************************************************************
     * Function OnOperator
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnOperator(int yychar)
    {
        return OnFunction(GetOperatorName(yychar));
    }


    /**
     **********************************************************************
     * Function OnIdentifierURILiteralExpr
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnIdentifierURILiteralExpr()
    {
        cError error;
        cToken *token;
        cElementInterface *op;
        cElementInterface *arg;

        if ((token=m_lexer.PopToken()))
        if (!(error=OnFunction(op,"is")))
        if (!(error=op->AddTextElement(arg,token->Get())))
        if ((token=m_lexer.PopToken()))
        if (!(error=OnFunction("get-document")))
        if (!(error=OnFunctionFunction(op,"is")))
        if (!(error=op->AddTextElement(arg,token->Get())))
        if (!(error=OnArgsFunction(1)))
            return c_ERROR_NONE;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnURILiteralExpr
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURILiteralExpr()
    {
        cError error;
        cToken *token;
        cElementInterface *op;
        cElementInterface *arg;

        if ((token=m_lexer.PopToken()))
        if (!(error=OnFunction("get-document")))
        if (!(error=OnFunctionFunction(op,"is")))
        if (!(error=op->AddTextElement(arg,token->Get())))
        if (!(error=OnFunctionFunction(op,"is")))
            return c_ERROR_NONE;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnIdentifierURILiteral
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnIdentifierURILiteral()
    {
        cError error;
        cToken *token;
        cElementInterface *op;
        cElementInterface *arg;

        if ((token=m_lexer.PopToken()))
        if (!(error=OnURILiteral()))
        if (!(error=OnFunctionFunction(op,"encoding")))
        if (!(error=op->AddTextElement(arg,token->Get())))
            return c_ERROR_NONE;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnURILiteral
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnURILiteral()
    {
        cError error;
        cToken *token;
        cElementInterface *op;
        cElementInterface *arg;

        if ((token=m_lexer.PopToken()))
        if (!(error=OnFunction("document")))
        if (!(error=OnFunctionFunction(op,"location")))
        if (!(error=op->AddTextElement(arg,token->Get())))
            return c_ERROR_NONE;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnTemplateLiteral
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTemplateLiteral()
    {
        cError error;
        cToken *token;
        cElementInterface *op;
        cElementInterface *arg;

        if ((token=m_lexer.PopToken()))
        if (!(error=OnFunction("transform-template-is")))
        if ((op=TopElement()))
        if (!(error=op->AddTextElement(arg,token->Get())))
            return c_ERROR_NONE;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnExternIdentifierLiteral
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnExternIdentifierLiteral()
    {
        cToken *uri_token;
        cToken *identifier_token;

        if ((identifier_token=m_lexer.PopToken()))
        if ((uri_token=m_lexer.PopToken()))
            return OnExternLiteral
            (uri_token->Get(),identifier_token->Get());

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnExternLiteral
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnExternLiteral()
    {
        cToken *token;

        if ((token=m_lexer.PopToken()))
            return OnExternLiteral(token->Get());

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnExternLiteral
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnExternLiteral
    (const char *uri_literal,
     const char *document_type=0)
    {
        cError error;
        cBuffer buffer;
        cURI uri;

        if (!(error=uri.Open(uri_literal)))
            return OnElementLiteral(uri,document_type);

        if (!(error=buffer.CopyStringL
            ("Unable to open URI \"",uri_literal,"\"",0)))
            yyerror(buffer.GetCharBuffer());

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnElementLiteral
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnElementLiteral()
    {
        cError error;
        cToken *token;

        if ((token=m_lexer.PopToken()))
        if (!(error=token->GetStream().Seek(0)))
            return OnElementLiteral(token->GetStream());

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnIdentifierElementLiteral
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnIdentifierElementLiteral()
    {
        cError error;
        cToken *token;
        cToken *identifier_token;

        if ((identifier_token=m_lexer.PopToken()))
        if ((token=m_lexer.PopToken()))
        if (!(error=token->GetStream().Seek(0)))
            return OnElementLiteral
            (token->GetStream(),identifier_token->Get());

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnElementLiteral
     *
     * @author $author$
     * @date   1/29/2003
     **********************************************************************
     */
    virtual cError OnElementLiteral
    (cStream &stream,const char *document_type=0)
    {
        const char *error_description;
        cError error;
        cError error2;
        cDocumentInterface *document;
        cElementInterface *op;
        cBuffer buffer;

        if (!document_type)
            document_type=m_default_document_type;

        if (!(document=m_document_factory.CreateDocumentByType
            (document_type)))
        {
            buffer.WriteStringL
            ("Unable to create \"",document_type,"\" document literal",0);
            yyerror(buffer.GetCharBuffer());
            return c_ERROR_FAIL;
        }

        if ((error=document->ParseFromStream(stream)))
        {
            buffer.WriteStringL
            ("Unable to parse \"",document_type,"\" document literal",0);

            if (!(error2=document->GetLastError
                (error2,error_description)))
                buffer.WriteStringL("(",error_description,")",0);

            yyerror(buffer.GetCharBuffer());
        }
        else
        {
            if (!(error=OnFunction(op,"is")))
                error=op->ReferenceElements(document->GetElementSet());
        }

        m_document_factory.DestroyDocument(document);

        if (!error)
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnConcatTextLiteral
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnConcatTextLiteral()
    {
        cError error;
        cToken *token;
        cToken *token2;

        if ((token2=m_lexer.PullToken()))
        if ((token=m_lexer.BottomToken()))
        if (!(error=token->Add(token2->Get())))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnTextLiteral
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnTextLiteral()
    {
        cError error;
        cToken *token;
        cElementInterface *op;
        cElementInterface *arg;
        cBuffer buffer;

        if ((token=m_lexer.PopToken()))
        if (!(error=buffer.CopyStringL
            (m_element_namespace_prefix,":is",0)))
        if (!(error=PushElement
            (op,buffer.GetCharBuffer(),buffer.GetLength())))
        if (!(error=op->AddTextElement(arg,token->Get())))
            return error;

        return c_ERROR_FAIL;
    }


    /**
     **********************************************************************
     * Function OnArgsFunction
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnArgsFunction(int args,const char *function)
    {
        cError error;

        if (!(error=OnFunction(function)))
            return OnArgsFunction(args);

        return error;
    }
    /**
     **********************************************************************
     * Function OnReverseArgs
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnReverseArgs(int args)
    {
        int argpop;
        cError error;
        cElementInterface *arg;
        cElementList list;

        for (argpop=args; argpop>0; --argpop)
        {
            if (!(error=!(arg=PopElement())))
            {
                if (!(error=PushElement(list,arg)))
                    continue;

                arg->FreeInstance();
            }
            break;
        }

        if (!error)
        {
            for (argpop=0; argpop<args; argpop++)
            {
                if (!(error=!(arg=PullElement(list))))
                {
                    if (!(error=PushElement(arg)))
                        continue;

                    arg->FreeInstance();
                }
                break;
            }

            if (!error)
                return error;
        }

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnArgsFunction
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnArgsFunction(int args)
    {
        int argpop;
        cError error;
        cElementInterface *op;
        cElementInterface *arg;
        cElementList list;

        if ((op=PopElement()))
        {
            for (argpop=args; argpop>0; --argpop)
            {
                if (!(error=!(arg=PopElement())))
                {
                    if (!(error=PushElement(list,arg)))
                        continue;

                    arg->FreeInstance();
                }
                break;
            }

            for (argpop=0; argpop<args; argpop++)
            {
                if (!(error=!(arg=PopElement(list))))
                {
                    if (!(error=op->ReferenceElement(*arg)))
                        continue;

                    arg->FreeInstance();
                }
                break;
            }

            if (!error)
            if (!(error=PushElement(op)))
                return error;

            op->FreeInstance();
        }

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnFunctionArgs
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnFunctionArgs(int args)
    {
        int argpop;
        cError error;
        cElementInterface *op;
        cElementInterface *arg;
        cElementList list;

        for (argpop=args; argpop>0; --argpop)
        {
            if (!(error=!(arg=PopElement())))
            {
                if (!(error=PushElement(list,arg)))
                    continue;

                arg->FreeInstance();
            }
            break;
        }

        if (!error)
        if ((op=TopElement()))
        {
            for (argpop=0; argpop<args; argpop++)
            {
                if (!(error=!(arg=PopElement(list))))
                {
                    if (!(error=op->ReferenceElement(*arg)))
                        continue;

                    arg->FreeInstance();
                }
                break;
            }

            if (!error)
                return error;
        }

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnFunctionFunction
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnFunctionFunction
    (cElementInterface *&arg,const char *name)
    {
        cError error;
        cElementInterface *op;
        cBuffer buffer;

        if ((op=TopElement()))

        if (!(error=buffer.CopyStringL
            (m_element_namespace_prefix,":",name,0)))

        if (!(error=op->AddElement
            (arg,buffer.GetCharBuffer(),buffer.GetLength())))
            return error;

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnFunction
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnFunction(const char *name)
    {
        cError error;
        cBuffer buffer;

        if (!(error=buffer.CopyStringL
            (m_element_namespace_prefix,":",name,0)))
            return PushElement
            (buffer.GetCharBuffer(),buffer.GetLength());

        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function OnFunction
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    virtual cError OnFunction
    (cElementInterface *&element,const char *name)
    {
        cError error;
        cBuffer buffer;

        if (!(error=buffer.CopyStringL
            (m_element_namespace_prefix,":",name,0)))
            return PushElement
            (element,buffer.GetCharBuffer(),buffer.GetLength());

        return c_ERROR_FAIL;
    }


    /**
     **********************************************************************
     * Function GetOperatorName
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    const char *GetOperatorName(int yychar)
    {
        switch(yychar)
        {
        case ',':
            return "do";
        case '+':
            return "add";
        case '-':
            return "subtract";
        case '*':
            return "multiply";
        case '/':
            return "divide";

        case POW_OP:
            return "exponent";
        case ROO_OP:
            return "root";
        case LOG_OP:
            return "log";

        case SIZEOF:
            return "element-count-of";
        case TEXTOF:
            return "element-text-of";
        case TYPEOF:
            return "element-type-of";

        case '!':
        case LNOT_OP:
            return "not";
        case LAND_OP:
            return "and";
        case LOR_OP:
            return "or";

        case '<':
            return "less";
        case '>':
            return "greater";
        case EQ_OP:
            return "equal";
        case NE_OP:
            return "not-equal";
        case LE_OP:
            return "less-or-equal";
        case GE_OP:
            return "greater-or-equal";

        case '=':
            return "set-variable";
        case ASSIGN:
            return "assign-variable";
        case ADD_ASSIGN:
            return "add-variable";
        case SUB_ASSIGN:
            return "subtract-variable";
        case MUL_ASSIGN:
            return "multiply-variable";
        case DIV_ASSIGN:
            return "divide-variable";
        case INC_OP:
            return "increment-variable";
        case DEC_OP:
            return "decrement-variable";
        case COM_OP:
            return "complement-variable";
        case LCOM_OP:
            return "logical-complement-variable";
        case RIGHT_OP:
            return "right-shift-variable";
        case LEFT_OP:
            return "left-shift-variable";
        }
        return "operator";
    }


    /**
     **********************************************************************
     * Function
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    cError PushTextElement
    (const char *text,int textlen=-1)
    {
        return PushElement
        (text,textlen,cElementInterface::c_TYPE_TEXT_ELEMENT);
    }
    /**
     **********************************************************************
     * Function
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    cError PushElement
    (const char *text,int textlen=-1,
     unsigned type=cElementInterface::c_TYPE_PARENT_ELEMENT)
    {
        cElementInterface *element;
        return PushElement(element,text,textlen,type);
    }
    /**
     **********************************************************************
     * Function PushElement
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    cError PushElement
    (cElementInterface *&element,const char *text,int textlen=-1,
     unsigned type=cElementInterface::c_TYPE_PARENT_ELEMENT)
    {
        cError error;

        if (!(error=m_document.GetElementSet().CreateElement
            (element,text,textlen,type)))
        {
            if (!(error=PushElement(element)))
                return error;

            element->FreeInstance();
        }
        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function PushElement
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    cError PushElement(cElementInterface *element)
    {
        return PushElement(m_element_list,element);
    }
    /**
     **********************************************************************
     * Function PopElement
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    cElementInterface *PopElement()
    {
        return PopElement(m_element_list);
    }
    /**
     **********************************************************************
     * Function PullElement
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    cElementInterface *PullElement()
    {
        return PullElement(m_element_list);
    }
    /**
     **********************************************************************
     * Function TopElement
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    cElementInterface *TopElement()
    {
        return TopElement(m_element_list);
    }
    /**
     **********************************************************************
     * Function PushElement
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    cError PushElement
    (cElementList &element_list,cElementInterface *element)
    {
        cElementItem *item;

        if ((item=new cElementItem(element)))
        {
            element_list.Push(item);
            return c_ERROR_NONE;
        }
        return c_ERROR_FAIL;
    }
    /**
     **********************************************************************
     * Function PopElement
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    cElementInterface *PopElement(cElementList &element_list)
    {
        cElementItem *item;
        cElementInterface *element;

        if ((item=element_list.Pop()))
        {
            element=item->m_element;
            item->m_element=0;
            delete item;
            return element;
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function PullElement
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    cElementInterface *PullElement(cElementList &element_list)
    {
        cElementItem *item;
        cElementInterface *element;

        if ((item=element_list.Pull()))
        {
            element=item->m_element;
            item->m_element=0;
            delete item;
            return element;
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function TopElement
     *
     * @author $author$
     * @date   12/27/2001
     **********************************************************************
     */
    cElementInterface *TopElement(cElementList &element_list)
    {
        cElementItem *item;

        if ((item=element_list.GetFirst()))
            return item->m_element;
        return 0;
    }
