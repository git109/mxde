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
 *   File: ctfunctions.cxx
 *
 * Author: $author$
 *   Date: 8/4/2003
 *
 *    $Id$
 **********************************************************************
 */

#include <stdlib.h>

#include "ccharfile.hxx"
#include "ctimplement.hxx"

/**
 **********************************************************************
 *  Class: cTFunctionImport
 *
 * Author: $author$
 *   Date: 2/16/2004
 **********************************************************************
 */
class cTFunctionImport
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionImport
     *
     *      Author: $author$
     *        Date: 2/16/2004
     **********************************************************************
     */
    cTFunctionImport(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 2/16/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        eError error;
        cArgument *expr;
        cCharFile file;
        const char *path;
        int pathlen;

        for (expr = arglist.GetFirst(); 
             expr; expr = expr->GetNext())
        {
            if ((path = expr->GetBuffer(pathlen)))
            if (0 < pathlen)
            if (!(error = file.Open(path)))
            {
                result.WriteStream(file);
                file.Close();
            }
        }
        return e_ERROR_NONE;
    }
} ct_function_import("import","import()");

/**
 **********************************************************************
 *  Class: cTFunctionInclude
 *
 * Author: $author$
 *   Date: 6/28/2004
 **********************************************************************
 */
class cTFunctionInclude
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionInclude
     *
     *      Author: $author$
     *        Date: 6/28/2004
     **********************************************************************
     */
    cTFunctionInclude(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 6/28/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        eError error;
        cArgument *expr;
        cCharFile file;
        const char *path;
        int pathlen;

        for (expr = arglist.GetFirst(); 
             expr; expr = expr->GetNext())
        {
            if ((path = expr->GetBuffer(pathlen)))
            if (0 < pathlen)
            if (!(error = file.Open(path)))
            {
                t.Expand(result,file);
                file.Close();
            }
        }
        return e_ERROR_NONE;
    }
} ct_function_include("include","include()");

/**
 **********************************************************************
 *  Class: cTFunctionDo
 *
 * Author: $author$
 *   Date: 8/4/2003
 **********************************************************************
 */
class cTFunctionDo
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionDo
     *
     *      Author: $author$
     *        Date: 8/4/2003
     **********************************************************************
     */
    cTFunctionDo(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        eError error;
        cArgument *expr;

        for (expr = arglist.GetFirst(); 
             expr; expr = expr->GetNext())
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        return e_ERROR_NONE;
    }
} ct_function_do("do","do((expr)...)");

/**
 **********************************************************************
 *  Class: cTFunctionIf
 *
 * Author: $author$
 *   Date: 8/4/2003
 **********************************************************************
 */
class cTFunctionIf
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionIf
     *
     *      Author: $author$
     *        Date: 8/4/2003
     **********************************************************************
     */
    cTFunctionIf(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        eError error;
        cArgument *cond;
        cArgument *expr;

        if ((cond = arglist.GetFirst()))
        if ((expr = cond->GetNext()))
        if (cond->GetLength()>0)
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        else if ((expr = expr->GetNext()))
        {
            do
            {
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while(expr = expr->GetNext());
        }

        return e_ERROR_NONE;
    }
} ct_function_if("if","if(cond,(expr),(expr)...)");

/**
 **********************************************************************
 *  Class: cTFunctionElse
 *
 * Author: $author$
 *   Date: 9/20/2003
 **********************************************************************
 */
class cTFunctionElse
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionElse
     *
     *      Author: $author$
     *        Date: 9/20/2003
     **********************************************************************
     */
    cTFunctionElse(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/20/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        eError error;
        cArgument *cond;
        cArgument *expr;

        if ((cond = arglist.GetFirst()))
        if ((expr = cond->GetNext()))
        if (cond->GetLength()<1)
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        else if ((expr = expr->GetNext()))
        {
            do
            {
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while(expr = expr->GetNext());
        }

        return e_ERROR_NONE;
    }
} ct_function_else("else","else(cond,(expr),(expr)...)");

/**
 **********************************************************************
 *  Class: cTFunctionThenIf
 *
 * Author: $author$
 *   Date: 12/1/2004
 **********************************************************************
 */
class cTFunctionThenIf
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionThenIf
     *
     *      Author: $author$
     *        Date: 12/1/2004
     **********************************************************************
     */
    cTFunctionThenIf(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/1/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int length;
        const char *buffer;
        eError error;
        cArgument *cond;
        cArgument *expr;

        if ((cond = arglist.GetFirst()))
        if ((buffer = cond->GetBuffer(length)))
        if (length > 0)
        {
            if ((expr = cond->GetNext()))
            do
            {
                if (expr->GetLength()>0)
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while(expr = expr->GetNext());

            result.Write(buffer, length);
        }

        return e_ERROR_NONE;
    }
} ct_function_thenif("then-if","then-if(cond,(expr)...)");

/**
 **********************************************************************
 *  Class: cTFunctionIfThen
 *
 * Author: $author$
 *   Date: 9/21/2003
 **********************************************************************
 */
class cTFunctionIfThen
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionIfThen
     *
     *      Author: $author$
     *        Date: 9/21/2003
     **********************************************************************
     */
    cTFunctionIfThen(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/21/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int length;
        const char *buffer;
        eError error;
        cArgument *cond;
        cArgument *expr;

        if ((cond = arglist.GetFirst()))
        if ((buffer = cond->GetBuffer(length)))
        if (length > 0)
        {
            result.Write(buffer, length);

            if ((expr = cond->GetNext()))
            do
            {
                if (expr->GetLength()>0)
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while(expr = expr->GetNext());
        }

        return e_ERROR_NONE;
    }
} ct_function_ifthen("if-then","if-then(cond,(expr)...)");

/**
 **********************************************************************
 *  Class: cTFunctionElseThen
 *
 * Author: $author$
 *   Date: 9/21/2003
 **********************************************************************
 */
class cTFunctionElseThen
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionElseThen
     *
     *      Author: $author$
     *        Date: 9/21/2003
     **********************************************************************
     */
    cTFunctionElseThen(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/21/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int length;
        const char *buffer;
        eError error;
        cArgument *cond;
        cArgument *expr;

        if ((cond = arglist.GetFirst()))
        {
            if ((buffer = cond->GetBuffer(length)))
            if (length > 0)
            {
                result.Write(buffer, length);
                return e_ERROR_NONE;
            }

            if ((expr = cond->GetNext()))
            do
            {
                if (expr->GetLength()>0)
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while(expr = expr->GetNext());
        }

        return e_ERROR_NONE;
    }
} ct_function_elsethen("else-then","else-then(cond,(expr)...)");

/**
 **********************************************************************
 *  Class: cTFunctionApply
 *
 * Author: $author$
 *   Date: 9/23/2003
 **********************************************************************
 */
class cTFunctionApply
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionApply
     *
     *      Author: $author$
     *        Date: 9/23/2003
     **********************************************************************
     */
    cTFunctionApply(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/23/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int length;
        const char *buffer;
        cTInterface::cVariableInterface *variable;
        cArgument *name;
        cArgument *value;
        cArgument *expr = 0;

        if ((expr = (name = arglist.GetFirst())))
        {
            do
            {
                if (!(expr = (value = name->GetNext())))
                    expr = name;

                else if (!(expr = value->GetNext()))
                        expr = value;

                else
                {
                    if ((buffer = name->GetBuffer(length)))
                    if (length > 0)
                    if ((variable = t.GetVariable(buffer,length)))
                    if ((buffer = value->GetBuffer(length)))
                        variable->PushValue(buffer,length);

                    name = expr;
                    continue;
                }

                break;
            }
            while (name);

            if (expr)
            if (expr->GetLength()>0)
                t.Expand(result, *expr);

            if ((expr = (name = arglist.GetFirst())))
            do
            {
                if (!(expr = (value = name->GetNext())))
                    expr = name;

                else if (!(expr = value->GetNext()))
                        expr = value;

                else
                {
                    if ((buffer = name->GetBuffer(length)))
                    if (length > 0)
                    if ((variable = t.GetVariable(buffer,length)))
                        variable->PopValue();

                    name = expr;
                    continue;
                }

                break;
            }
            while (name);
        }
        return e_ERROR_NONE;
    }
} ct_function_apply("apply","apply(name,value,...,(expr))"),
  ct_function_with("with","with(name,value,...,(expr))");

/**
 **********************************************************************
 *  Class: cTFunctionApplyX
 *
 * Author: $author$
 *   Date: 12/1/2004
 **********************************************************************
 */
class cTFunctionApplyX
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionApplyX
     *
     *      Author: $author$
     *        Date: 12/1/2004
     **********************************************************************
     */
    cTFunctionApplyX(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/1/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int length;
        const char *buffer;
        cTInterface::cVariableInterface *variable;
        cArgument *name;
        cArgument *value;
        cArgument *expr = 0;
        cCharBuffer value_result;

        if ((expr = (name = arglist.GetFirst())))
        {
            do
            {
                if (!(expr = (value = name->GetNext())))
                    expr = name;

                else if (!(expr = value->GetNext()))
                        expr = value;

                else
                {
                    if ((buffer = name->GetBuffer(length)))
                    if (length > 0)
                    if ((variable = t.GetVariable(buffer,length)))
                    {
                        value_result.Clear();
                        t.Expand(value_result, *value);
                        if ((buffer = value_result.GetBuffer(length)))
                            variable->PushValue(buffer,length);
                    }
                    name = expr;
                    continue;
                }

                break;
            }
            while (name);

            if (expr)
            if (expr->GetLength()>0)
                t.Expand(result, *expr);

            if ((expr = (name = arglist.GetFirst())))
            do
            {
                if (!(expr = (value = name->GetNext())))
                    expr = name;

                else if (!(expr = value->GetNext()))
                        expr = value;

                else
                {
                    if ((buffer = name->GetBuffer(length)))
                    if (length > 0)
                    if ((variable = t.GetVariable(buffer,length)))
                        variable->PopValue();

                    name = expr;
                    continue;
                }

                break;
            }
            while (name);
        }
        return e_ERROR_NONE;
    }
} ct_function_applyx("apply-x","apply-x(name,(value),...,(expr))");

/**
 **********************************************************************
 *  Class: cTFunctionEnum
 *
 * Author: $author$
 *   Date: 6/14/2004
 **********************************************************************
 */
class cTFunctionEnum
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionEnum
     *
     *      Author: $author$
     *        Date: 6/14/2004
     **********************************************************************
     */
    cTFunctionEnum(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 6/14/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int length,iterate,i;
        const char *name_buffer,*value_buffer;
        cTInterface::cVariableInterface *variable;
        cArgument *name;
        cArgument *value;
        cArgument *expr;
        char buffer[32];

        if ((name = arglist.GetFirst()))
        if ((name_buffer = name->GetBuffer(length)))
        if (length > 0)
        if ((value = name->GetNext()))
        if ((value_buffer = value->GetBuffer(length)))
        if (length > 0)
        if (0 < (iterate = atoi(value_buffer)))
        if ((expr = value->GetNext()))
        if ((variable = t.GetVariable(name_buffer)))
        for (i=0; i<iterate; i++)
        {
            itoa(i, buffer, 10);
            variable->PushValue(buffer);
            t.Expand(result, *expr);
            expr->Seek(0);
            variable->PopValue();
        }
        return e_ERROR_NONE;
    }
} ct_function_enum("enum","enum()");

/**
 **********************************************************************
 *  Class: cTFunctionEqual
 *
 * Author: $author$
 *   Date: 9/18/2003
 **********************************************************************
 */
class cTFunctionEqual
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionEqual
     *
     *      Author: $author$
     *        Date: 9/18/2003
     **********************************************************************
     */
    cTFunctionEqual(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/18/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int length, length2;
        const char *buffer, *buffer2;
        cArgument *arg;

        if ((arg = arglist.GetFirst()))
        if ((buffer = arg->GetBuffer(length)))
        {
            while((arg = arg->GetNext()))
            {
                if ((buffer2 = arg->GetBuffer(length2)))
                if (length == length2)
                if (!strncmp(buffer, buffer2, length))
                    continue;

                return e_ERROR_NONE;
            }

            if (length>0)
                result.Write(buffer, length);
        }

        return e_ERROR_NONE;
    }
} ct_function_equal("equal","equal(string...)");

/**
 **********************************************************************
 *  Class: cTFunctionUnequal
 *
 * Author: $author$
 *   Date: 9/20/2003
 **********************************************************************
 */
class cTFunctionUnequal
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionUnequal
     *
     *      Author: $author$
     *        Date: 9/20/2003
     **********************************************************************
     */
    cTFunctionUnequal(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/20/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int length, length2;
        const char *buffer, *buffer2;
        cArgument *arg;

        if ((arg = arglist.GetFirst()))
        if ((buffer = arg->GetBuffer(length)))
        if ((arg = arg->GetNext()))
        if ((buffer2 = arg->GetBuffer(length2)))
        {
            do
            {
                if (length == length2)
                if (!strncmp(buffer, buffer2, length))
                    return e_ERROR_NONE;

                if ((arg = arg->GetNext()))
                if (!(buffer2 = arg->GetBuffer(length2)))
                    return e_ERROR_NONE;
            }
            while(arg);

            if (length2>0)
                result.Write(buffer2, length2);
        }

        return e_ERROR_NONE;
    }
} ct_function_unequal("unequal","unequal(string...)");

/**
 **********************************************************************
 *  Class: cTFunctionNewline
 *
 * Author: $author$
 *   Date: 2/25/2004
 **********************************************************************
 */
class cTFunctionNewline
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionNewline
     *
     *      Author: $author$
     *        Date: 2/25/2004
     **********************************************************************
     */
    cTFunctionNewline(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 2/25/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int length;
        const char *buffer;
        cArgument *arg;

        if ((arg = arglist.GetFirst()))
        do
        {
            if ((buffer = arg->GetBuffer(length)))
            if (0 < length)
                result.Write(buffer, length);

            result.Putc('\n');
        }
        while((arg = arg->GetNext()));

        return e_ERROR_NONE;
    }
} ct_function_newline("newline","newline(string,...)");

/**
 **********************************************************************
 *  Class: cTFunctionToLower
 *
 * Author: $author$
 *   Date: 9/16/2003
 **********************************************************************
 */
class cTFunctionToLower
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionToLower
     *
     *      Author: $author$
     *        Date: 9/16/2003
     **********************************************************************
     */
    cTFunctionToLower(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/16/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int length;
        const char *buffer;
        cArgument *arg;

        if ((arg = arglist.GetFirst()))
        do
        {
            if ((buffer = arg->GetBuffer(length)))
            while(length>0)
            {
                result.Putc(tolower(*buffer));
                buffer++;
                --length;
            }
        }
        while((arg = arg->GetNext()));

        return e_ERROR_NONE;
    }
} ct_function_tolower("tolower","tolower(string...)");

/**
 **********************************************************************
 *  Class: cTFunctionToUpper
 *
 * Author: $author$
 *   Date: 9/16/2003
 **********************************************************************
 */
class cTFunctionToUpper
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionToUpper
     *
     *      Author: $author$
     *        Date: 9/16/2003
     **********************************************************************
     */
    cTFunctionToUpper(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/16/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int length;
        const char *buffer;
        cArgument *arg;

        if ((arg = arglist.GetFirst()))
        do
        {
            if ((buffer = arg->GetBuffer(length)))
            while(length>0)
            {
                result.Putc(toupper(*buffer));
                buffer++;
                --length;
            }
        }
        while((arg = arg->GetNext()));

        return e_ERROR_NONE;
    }
} ct_function_toupper("toupper","toupper(string...)");

/**
 **********************************************************************
 *  Class: cTFunctionLeft
 *
 * Author: $author$
 *   Date: 6/19/2004
 **********************************************************************
 */
class cTFunctionLeft
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionLeft
     *
     *      Author: $author$
     *        Date: 6/19/2004
     **********************************************************************
     */
    cTFunctionLeft(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 6/19/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int pattern_length,length;
        const char *pattern,*buffer,*found;
        cArgument *arg;

        if ((arg = arglist.GetFirst()))
        if ((buffer = arg->GetBuffer(length)))
        if ((arg = arg->GetNext()))
        if ((pattern = arg->GetBuffer(pattern_length)))
        if ((pattern_length > 0) && (pattern_length < length))
        if ((found = strstr(buffer, pattern)))
        if (found > buffer)
            result.Write(buffer, found-buffer);

        return e_ERROR_NONE;
    }
} ct_function_left("left","left(string,pattern)");

/**
 **********************************************************************
 *  Class: cTFunctionRightLeft
 *
 * Author: $author$
 *   Date: 11/23/2004
 **********************************************************************
 */
class cTFunctionRightLeft
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionRightLeft
     *
     *      Author: $author$
     *        Date: 11/23/2004
     **********************************************************************
     */
    cTFunctionRightLeft(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int pattern_length,left_length,length;
        const char *pattern,*buffer,*found;
        cArgument *arg;

        if ((arg = arglist.GetFirst()))
        if ((buffer = arg->GetBuffer(length)))
        if ((arg = arg->GetNext()))
        if ((pattern = arg->GetBuffer(pattern_length)))
        if ((pattern_length > 0) && (pattern_length < length))
        if ((found = strstr(buffer, pattern)))
        if (length > (left_length = (found-buffer)+pattern_length))
            result.Write(found+pattern_length, length-left_length);

        return e_ERROR_NONE;
    }
} ct_function_rightleft("right-of-left","right-of-left()");

/**
 **********************************************************************
 *  Class: cTFunctionRight
 *
 * Author: $author$
 *   Date: 6/19/2004
 **********************************************************************
 */
class cTFunctionRight
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionRight
     *
     *      Author: $author$
     *        Date: 6/19/2004
     **********************************************************************
     */
    cTFunctionRight(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 6/19/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int pattern_length,left_length,length;
        const char *pattern,*buffer,*found,*found2;
        cArgument *arg;

        if ((arg = arglist.GetFirst()))
        if ((buffer = arg->GetBuffer(length)))
        if ((arg = arg->GetNext()))
        if ((pattern = arg->GetBuffer(pattern_length)))
        if ((pattern_length > 0) && (pattern_length < length))
        if ((found = strstr(buffer, pattern)))
        {
            while ((found2 = strstr
                   (found+pattern_length, pattern)))
                found = found2;

            if (length > (left_length = (found-buffer)+pattern_length))
                result.Write(found+pattern_length, length-left_length);
        }
        return e_ERROR_NONE;
    }
} ct_function_right("right","right(string,pattern)");

/**
 **********************************************************************
 *  Class: cTFunctionLeftRight
 *
 * Author: $author$
 *   Date: 11/23/2004
 **********************************************************************
 */
class cTFunctionLeftRight
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionLeftRight
     *
     *      Author: $author$
     *        Date: 11/23/2004
     **********************************************************************
     */
    cTFunctionLeftRight(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int pattern_length,length;
        const char *pattern,*buffer,*found,*found2;
        cArgument *arg;

        if ((arg = arglist.GetFirst()))
        if ((buffer = arg->GetBuffer(length)))
        if ((arg = arg->GetNext()))
        if ((pattern = arg->GetBuffer(pattern_length)))
        if ((pattern_length > 0) && (pattern_length < length))
        if ((found = strstr(buffer, pattern)))
        {
            while ((found2 = strstr
                   (found+pattern_length, pattern)))
                found = found2;

			if (found > buffer)
				result.Write(buffer, found-buffer);
        }
        return e_ERROR_NONE;
    }
} ct_function_leftright("left-of-right","left-of-right()");

/**
 **********************************************************************
 *  Class: cTFunctionStrLen
 *
 * Author: $author$
 *   Date: 1/5/2004
 **********************************************************************
 */
class cTFunctionStrLen
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionStrLen
     *
     *      Author: $author$
     *        Date: 1/5/2004
     **********************************************************************
     */
    cTFunctionStrLen(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/5/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int count,length;
        const char *buffer;
        cArgument *arg;

        if ((arg = arglist.GetFirst()))
        {
            length = 0;

            do
            {
                if ((buffer = arg->GetBuffer(count)))
                if (count > 0)
                    length += count;
            }
            while ((arg = arg->GetNext()));

            result.WriteInt(length);
        }
        return e_ERROR_NONE;
    }
} ct_function_strlen("strlen","strlen(string,...)");

/**
 **********************************************************************
 *  Class: cTFunctionStrPad
 *
 * Author: $author$
 *   Date: 1/5/2004
 **********************************************************************
 */
class cTFunctionStrPad
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionStrPad
     *
     *      Author: $author$
     *        Date: 1/5/2004
     **********************************************************************
     */
    cTFunctionStrPad(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/5/2004
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int count,length,bufflen,padlen;
        const char *buffer;
        cArgument *arg,*strarg,*padarg,*lenarg;
        cCharBuffer string;

        if ((strarg = arglist.GetFirst()))
        if ((padarg = strarg->GetNext()))
        if ((lenarg = padarg->GetNext()))
        {
            length = 0;

            do
            {
                if ((buffer = strarg->GetBuffer(count)))
                if (count>0)
                if ((count = result.Write(buffer,count)) > 0)
                    length += count;

                if ((arg = lenarg->GetNext()))
                {
                    strarg = padarg;
                    padarg = lenarg;
                    lenarg = arg;
                }
            }
            while (arg);

            if ((buffer = lenarg->GetBuffer(bufflen)))
            if (bufflen > 0)
            if (0 < (padlen = atoi(buffer)))
            if (length < padlen)
            if ((buffer = padarg->GetBuffer(bufflen)))
            if (bufflen > 0)
            {
                if (bufflen > padlen)
                    bufflen = padlen;

                do
                {
                    if (0 >= (count = result.Write(buffer, bufflen)))
                        break;
                }
                while((length += count) < padlen);
            }
        }

        return e_ERROR_NONE;
    }
} ct_function_strpad("strpad","strpad(string,...,padding,padlen)");

/**
 **********************************************************************
 *  Class: cTStringFunction
 *
 * Author: $author$
 *   Date: 9/18/2003
 **********************************************************************
 */
class cTStringFunction
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTStringFunction
     *
     *      Author: $author$
     *        Date: 9/18/2003
     **********************************************************************
     */
    cTStringFunction(const char *name,const char *description)
    : cIs(name,description)
    {
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/18/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int length;
        const char *buffer;
        cArgument *arg;
        cCharBuffer string;

        if ((arg = arglist.GetFirst()))
        do
        {
            if ((buffer = arg->GetBuffer(length)))
            if (length>0)
            if ((length = string.Write(buffer,length)) < 0)
                return e_ERROR_WRITE;
        }
        while((arg = arg->GetNext()));

        if ((buffer = string.GetBuffer(length)))
        if (length>0)
            return Expand(result, t, buffer, length);

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/18/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cTInterface &t,
     const char *buffer, int length) const
    {
        return e_ERROR_NONE;
    }
};

/**
 **********************************************************************
 *  Class: cTFunctionFileName
 *
 * Author: $author$
 *   Date: 9/17/2003
 **********************************************************************
 */
class cTFunctionFileName
: public cTStringFunction
{
public:
    typedef cTStringFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionFileName
     *
     *      Author: $author$
     *        Date: 9/17/2003
     **********************************************************************
     */
    cTFunctionFileName(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/17/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cTInterface &t,
     const char *buffer, int length) const
    {
        const char *delim;

        if (length>0)
        {
            if (!(delim = strrchr(buffer,'/')))
            if (!(delim = strrchr(buffer,'\\')))
                delim = strrchr(buffer,':');

            if (delim)
                delim++;
            else delim = buffer;

            if ((length -= (delim-buffer)) > 0)
                result.Write(delim,length);
        }

        return e_ERROR_NONE;
    }
} ct_function_filename("filename","filename(string...)");

/**
 **********************************************************************
 *  Class: cTFunctionFileBase
 *
 * Author: $author$
 *   Date: 9/17/2003
 **********************************************************************
 */
class cTFunctionFileBase
: public cTStringFunction
{
public:
    typedef cTStringFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionFileBase
     *
     *      Author: $author$
     *        Date: 9/17/2003
     **********************************************************************
     */
    cTFunctionFileBase(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/17/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cTInterface &t,
     const char *buffer, int length) const
    {
        const char *delim;

        if (length>0)
        {
            if (!(delim = strrchr(buffer,'.')))
                delim = buffer+length;

            if ((length = (delim-buffer)) > 0)
                result.Write(buffer,length);
        }

        return e_ERROR_NONE;
    }
} ct_function_filebase("filebase","filebase(string...)");

/**
 **********************************************************************
 *  Class: cTFunctionFileExtension
 *
 * Author: $author$
 *   Date: 9/17/2003
 **********************************************************************
 */
class cTFunctionFileExtension
: public cTStringFunction
{
public:
    typedef cTStringFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionFileExtension
     *
     *      Author: $author$
     *        Date: 9/17/2003
     **********************************************************************
     */
    cTFunctionFileExtension(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/17/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cTInterface &t,
     const char *buffer, int length) const
    {
        const char *delim;

        if (length>0)
        {
            if (!(delim = strrchr(buffer,'.')))
                delim = buffer+length;
            else delim++;

            if ((length -= (delim-buffer)) > 0)
                result.Write(delim,length);
        }

        return e_ERROR_NONE;
    }
} ct_function_fileextension("fileextension","fileextension(string...)");

/**
 **********************************************************************
 *  Class: cTFunctionParse
 *
 * Author: $author$
 *   Date: 9/20/2003
 **********************************************************************
 */
class cTFunctionParse
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionParse
     *
     *      Author: $author$
     *        Date: 9/20/2003
     **********************************************************************
     */
    cTFunctionParse(const char *name,const char *description)
    : cIs(name,description)
    {
        static cParameter parameter[1]={{0,0}};

        m_parameter=parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 9/20/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result,cArgumentList &arglist,cTInterface &t) const
    {
        int length;
        const char *token;
        const char *string = 0;
        const char *delim = 0;
        const char *var = 0;
        cTInterface::cVariableInterface *variable = 0;
        cArgument *before = 0;
        cArgument *between = 0;
        cArgument *expr = 0;
        cArgument *arg;

        if ((arg = arglist.GetFirst()))
        if ((string = arg->GetBuffer()))
        if ((arg = arg->GetNext()))
        if ((delim = arg->GetBuffer(length)))
        if (length > 0)
        {
            if ((before = (arg = arg->GetNext())))
            if ((between = (arg = arg->GetNext())))
            if ((expr = (arg = arg->GetNext())))
            if ((arg = arg->GetNext()))
            if ((var = arg->GetBuffer()))
                variable = t.GetVariable(var);

            while ((token = strstr(string,delim)))
            {
                if (variable)
                    variable->PushValue(string,token-string);

                if (before)
                {
                    t.Expand(result,*before);
                    before->Seek(0);
                }

                if (expr)
                {
                    t.Expand(result,*expr);
                    expr->Seek(0);
                }
                else result.Write(string,token-string);

                if ((string = token+length)[0])
                if (between)
                {
                    t.Expand(result,*between);
                    between->Seek(0);
                }

                if (variable)
                    variable->PopValue();
            }

            if (string[0])
            {
                if (variable)
                    variable->PushValue(string);

                if (before)
                    t.Expand(result,*before);

                if (expr)
                    t.Expand(result,*expr);

                else result.Write(string);

                if (variable)
                    variable->PopValue();
            }
        }
        return e_ERROR_NONE;
    }
} ct_function_parse
  ("parse","parse(string,delim,(before),(between),(expr),var)");

