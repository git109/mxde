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
 *   File: tservlet.cxx
 *
 * Author: $author$
 *   Date: 11/5/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "cdomprocessor.hxx"
#include "cservletpathinterface.hxx"
#include "curlencodedformdataparser.hxx"
#include "chttpmainservlet.hxx"
//#include "ct.hxx"

class cServletPathInterface;

/**
 **********************************************************************
 *  Class: cServletPathItem
 *
 * Author: $author$
 *   Date: 11/23/2004
 **********************************************************************
 */
class cServletPathItem
: public cListItemT<cServletPathItem>
{
public:
    typedef cListItemT<cServletPathItem> cIs;

    cServletPathInterface &m_servlet_path;

    /**
     **********************************************************************
     * Constructor: cServletPathItem
     *
     *      Author: $author$
     *        Date: 11/23/2004
     **********************************************************************
     */
    cServletPathItem(cServletPathInterface &servlet_path)
    : m_servlet_path(servlet_path)
    {
    }
};

/**
 **********************************************************************
 *  Class: cServletPathList
 *
 * Author: $author$
 *   Date: 11/23/2004
 **********************************************************************
 */
class cServletPathList
: public cListT
  <cServletPathItem, cServletPathList>
{
public:
    typedef cListT
    <cServletPathItem, cServletPathList> cIs;
};


/**
 **********************************************************************
 *  Class: cServletPathBranch
 *
 * Author: $author$
 *   Date: 11/23/2004
 **********************************************************************
 */
class cServletPathBranch
: public cAVLTreeBranchT<cServletPathBranch>
{
public:
    typedef cAVLTreeBranchT<cServletPathBranch> cIs;

    cServletPathInterface &m_servlet_path;
    cCharString m_name;

    /**
     **********************************************************************
     * Constructor: cServletPathBranch
     *
     *      Author: $author$
     *        Date: 11/23/2004
     **********************************************************************
     */
    cServletPathBranch
    (cServletPathInterface &servlet_path, 
     const char* name, int namelen=-1)
    : m_servlet_path(servlet_path)
    {
        eError error;

        if (name)
        if (0 > (namelen = m_name.SetChars(name, namelen)))
            throw(error = -namelen);
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    int Compare(cServletPathBranch &branch) const
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
     *     Date: 11/23/2004
     **********************************************************************
     */
    int Compare(const char* name) const
    {
        int length2, unequal = -1;
        const char *name2;

        if ((name2 = GetName(length2)))
            unequal = strcmp(name, name2);

        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/23/2004
     **********************************************************************
     */
    const char* GetName(int &length) const
    {
        const char* name = m_name.GetChars(length);
        return name;
    }
};

/**
 **********************************************************************
 *  Class: cServletPathTree
 *
 * Author: $author$
 *   Date: 11/23/2004
 **********************************************************************
 */
class cServletPathTree
: public cAVLTreeT
  <const char*, cServletPathBranch, cServletPathTree>
{
public:
    typedef cAVLTreeT
    <const char*, cServletPathBranch, cServletPathTree> cIs;
};

cDefaultDOMElementProcessor g_processor;

cString g_namespace_hydas("Hydra-Application-Server");

/**
 **********************************************************************
 *  Class: cDirectoryDOMElementProcessor
 *
 * Author: $author$
 *   Date: 12/11/2004
 **********************************************************************
 */
class cDirectoryDOMElementProcessor
: public cDOMElementProcessor
{
public:
    typedef cDOMElementProcessor cIs;

    cString m_name_attr_name;

    /**
     **********************************************************************
     * Constructor: cDirectoryDOMElementProcessor
     *
     *      Author: $author$
     *        Date: 12/11/2004
     **********************************************************************
     */
    cDirectoryDOMElementProcessor
    (const cStringInterface &namespace_uri, const char *name) 
    : cIs(namespace_uri, name)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 12/11/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMElementInterface &element,
     cDOMNodeListInterface &parameter) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
} g_directory_processor
  (g_namespace_hydas,"directory");

/**
 **********************************************************************
 *  Class: cServletDOMElementProcessor
 *
 * Author: $author$
 *   Date: 11/30/2004
 **********************************************************************
 */
class cServletDOMElementProcessor
: public cDOMElementProcessor
{
public:
    typedef cDOMElementProcessor cIs;

    cString m_name_attr_name;

    /**
     **********************************************************************
     * Constructor: cServletDOMElementProcessor
     *
     *      Author: $author$
     *        Date: 11/30/2004
     **********************************************************************
     */
    cServletDOMElementProcessor
    (const cStringInterface &namespace_uri, 
     const char *name, const char *name_attr_name="name") 
    : cIs(namespace_uri, name),
      m_name_attr_name(name_attr_name)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 11/30/2004
     **********************************************************************
     */
    virtual eError Process
    (cDOMProcessorInterface &processor,
     cDOMNodeList &result, 
     cDOMElementInterface &element,
     cDOMNodeListInterface &parameter) 
    {
        eError error = e_ERROR_NONE;
        cHttpServletInterface* servlet;
        const cStringInterface* value;
        const char *chars;
        int length, unequal;
        
        if ((servlet = cHttpMainServlet::GetInstance()))
        {
            if ((value = element.GetAttribute(m_name_attr_name)))
            if ((chars = servlet->GetServletName(length)))
            if ((unequal = value->Compare(chars)))
                return error;
        }
        error = processor
        .Process(result, element, parameter);
        return error;
    }
} g_servlet_processor
  (g_namespace_hydas,"servlet");

/**
 **********************************************************************
 *  Class: cTServlet
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
class cTServlet
: public cHttpMainServlet
{
public:
    typedef cHttpMainServlet cIs;

    const char *m_input_variable_name;
    const char *m_template_variable_name;

    /**
     **********************************************************************
     * Constructor: cTServlet
     *
     *      Author: $author$
     *        Date: 11/4/2004
     **********************************************************************
     */
    cTServlet(const char *name="t")
    : cIs(name),
      m_input_variable_name("input"),
      m_template_variable_name("template")
    {
    }
    /**
     **********************************************************************
     * Function: CreateHttpServlet
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual cHttpServletInterface* 
    CreateHttpServlet(eError &error) 
    {
        cHttpServletInterface* servlet = 0;
        error = e_ERROR_FAILED;

        if ((servlet = new cTServlet()))
            error = e_ERROR_NONE;
        return servlet;
    }
    /**
     **********************************************************************
     * Function: DestroyHttpServlet
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual eError DestroyHttpServlet
    (cHttpServletInterface& servlet) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual eError Service
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error = e_ERROR_NONE;
        cCharReaderInterface &reader = request.GetReader();
        cCharWriterInterface &writer = response.GetWriter();
        const char *input_filename;
        int length;

        response.SetStatusOK();
        response.SetContentType("text/plain");

        if (!(input_filename = request.GetParameter
            (length, m_template_variable_name))
            || (1 > length))

        if (!(input_filename = request.GetParameter
            (length, m_input_variable_name))
            || (1 > length))
        {
            if ((input_filename = request.GetPathInfo
                (length)) && (0 < length))
            {
            }
            writer.WriteL
            ("\"", m_input_variable_name, "\" missing\r\n", 0);
            writer.Flush();
            return error;
        }

        return error;
    }
} g_t_servlet;
