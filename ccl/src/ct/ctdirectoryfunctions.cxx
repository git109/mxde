/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: ctdirectoryfunctions.cxx
 *
 * Author: $author$
 *   Date: 8/4/2005
 *
 *    $Id$
 *
 * cT Directory Functions.
 *
 **********************************************************************
 */

#include "ctimplement.hxx"
#include "cfiledirectory.hxx"

/**
 **********************************************************************
 *  Class: cTFunctionDirectory
 *
 * Author: $author$
 *   Date: 8/4/2005
 **********************************************************************
 */
class cTFunctionDirectory
: public cTImplement::cFunction
{
public:
    typedef cTImplement::cFunction cIs;

    /**
     **********************************************************************
     * Constructor: cTFunctionDirectory
     *
     *      Author: $author$
     *        Date: 8/4/2005
     **********************************************************************
     */
    cTFunctionDirectory(const char *name, const char *description)
    : cIs(name, description)
    {
        static cParameter parameter[1] = {{0,0}};

        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 8/4/2005
     **********************************************************************
     */
    virtual eError Expand
    (cCharStream &result, 
     cArgumentList &arglist, cTInterface &t) const
    {
        const char *name = 0;
        const char *type = 0;
        const char *name_var = 0;
        const char *type_var = 0;
        cTInterface::cVariableInterface *name_variable = 0;
        cTInterface::cVariableInterface *type_variable = 0;
        cArgument *pattern = 0;
        cArgument *before = 0;
        cArgument *between = 0;
        cArgument *expr = 0;
        cArgument *arg;
        int length;
        eError error;
        cFileDirectoryEntryInterface *entry;
        cFileDirectory dir;

        if ((pattern = (arg = arglist.GetFirst())))
        if (0 < pattern->GetLength())
        if ((before = (arg = arg->GetNext())))
        if ((between = (arg = arg->GetNext())))
        if ((expr = (arg = arg->GetNext())))
        if ((arg = arg->GetNext()))
        {
            if ((name_var = arg->GetBuffer()))
                name_variable = t.GetVariable(name_var);

            if ((arg = arg->GetNext()))
            {
                if ((type_var = arg->GetBuffer()))
                    type_variable = t.GetVariable(type_var);
            }
        }

        if (pattern)
        if ((name = pattern->GetBuffer(length)))
        if (0 < length)
        if (!(error = dir.OpenPathc(name, length)))
        if ((entry = dir.GetFirstEntry()))
        do
        {
            if (entry->GetIsCircular())
            {
                error = entry->GetNextEntry();
                continue;
            }

            name = entry->GetEntryNamec(length);
            type = entry->GetIsDirectory()?"d":"f";

            if (name_variable && name)
                name_variable->PushValue(name);

            if (type_variable && type)
                type_variable->PushValue(type);

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
            else
            {
                if (name)
                    result.Write(name);

                if (type)
                    result.WriteL(":", type, 0);
            }

            if (!(error = entry->GetNextEntry()))
            if (between)
            {
                t.Expand(result,*between);
                between->Seek(0);
            }
            else if (!expr)
                    result.Write(";");


            if (type_variable && type)
                type_variable->PopValue();

            if (name_variable && name)
                name_variable->PopValue();
        }
        while(!error);

        return e_ERROR_NONE;
    }
} ct_function_directory
  ("directory","directory(pattern, (before), (between), (expr), name_var, type_var)");
