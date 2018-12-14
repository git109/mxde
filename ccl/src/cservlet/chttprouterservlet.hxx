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
 *   File: chttprouterservlet.hxx
 *
 * Author: $author$
 *   Date: 10/25/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPROUTERSERVLET_HXX
#define _CHTTPROUTERSERVLET_HXX

#include "chttpservlettree.hxx"
#include "chttpservlet.hxx"

/**
 **********************************************************************
 *  Class: cHttpServletPathEntry
 *
 * Author: $author$
 *   Date: 10/26/2004
 **********************************************************************
 */
class cHttpServletPathEntry
{
public:
    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 10/26/2004
     **********************************************************************
     */
    enum
    {
        e_FIRST,
        e_NONE = e_FIRST,

        e_GROUND,
        e_ROOT,
        e_TREE,
        e_LEAF,
        e_BRANCH,

        e_NEXT,
        e_LAST=e_NEXT-1
    };

    int m_type;
    cCharString m_name;

    /**
     **********************************************************************
     * Constructor: cHttpServletPathEntry
     *
     *      Author: $author$
     *        Date: 10/26/2004
     **********************************************************************
     */
    cHttpServletPathEntry
    (int type=e_NONE, const char* chars=0, int length=-1) 
    : m_type(type)
    {
        eError error;

        if (chars)
        if (0 > (length = Set(type, chars, length)))
            throw(error=-length);
    }

    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual int Set
    (int type, const char* chars,  int length=-1) 
    {
        if (0 <= (length = m_name.SetChars(chars, length)))
            m_type = type;
        return length;
    }

    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual const char* GetName(int &length) const
    {
        const char* chars = m_name.GetChars(length);
        return chars;
    }
};

/**
 **********************************************************************
 *  Class: cHttpServletPath
 *
 * Author: $author$
 *   Date: 10/26/2004
 **********************************************************************
 */
class cHttpServletPath
{
public:
    cCharString m_path;
    const char *m_front,*m_rear,*m_pos;

    /**
     **********************************************************************
     * Constructor: cHttpServletPath
     *
     *      Author: $author$
     *        Date: 10/26/2004
     **********************************************************************
     */
    cHttpServletPath
    (const char* chars=0, int length=-1) 
    : m_front(0),
      m_rear(0),
      m_pos(0)
    {
        eError error;

        if (chars)
        if (0 > (length = Set(chars, length)))
            throw(error=-length);
    }

    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual int Set
    (const char* chars, int length=-1) 
    {
        int count;

        m_front = 0;
        m_rear = 0;
        m_pos = 0;

        if (0 <= (count = m_path.SetChars(chars, length)))
        if ((m_pos = (m_front = m_path.GetChars(length))))
        {
            m_rear = m_front+length;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: GetFirstEntry
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual int GetFirstEntry
    (cHttpServletPathEntry &entry) 
    {
        int type = cHttpServletPathEntry::e_NONE;
        m_pos = m_front;
        type = GetNextEntry(entry);
        return type;
    }
    /**
     **********************************************************************
     * Function: GetNextEntry
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual int GetNextEntry
    (cHttpServletPathEntry &entry) 
    {
        int type = cHttpServletPathEntry::e_NONE;
        enum
        {
            e_STATE_NAME,
            e_STATE_DOT,
            e_STATE_DOTDOT,
            e_STATE_SLASH,
            e_STATE_SLASHSLASH
        } state = e_STATE_NAME;
        int length;
        char c;
        const char *pos;

        for (pos = m_pos; pos < m_rear; pos++)
        {
            switch(c = *pos)
            {
            case '.':
                switch(state)
                {
                case e_STATE_DOT:
                    state = e_STATE_DOTDOT;
                    break;

                default:
                    if (pos <= m_pos)
                        state = e_STATE_DOT;

                    else state = e_STATE_NAME;
                }
                break;

            case '/':
                switch(state)
                {
                case e_STATE_DOT:
                    if (0 > (length = entry.Set
                        (type = entry.e_LEAF, m_pos, pos-m_pos)))
                        type = entry.e_NONE;
                    m_pos = pos+1;
                    return type;

                case e_STATE_DOTDOT:
                    if (0 > (length = entry.Set
                        (type = entry.e_TREE, m_pos, pos-m_pos)))
                        type = entry.e_NONE;
                    m_pos = pos+1;
                    return type;

                case e_STATE_SLASH:
                    state = e_STATE_SLASHSLASH;
                    break;

                case e_STATE_SLASHSLASH:
                    if (0 > (length = entry.Set
                        (type = entry.e_GROUND, m_pos, pos-m_pos)))
                        type = entry.e_NONE;
                    m_pos = pos;
                    return type;

                default:
                    if (pos <= m_front)
                        state = e_STATE_SLASH;
                    else
                    {
                        if (0 > (length = entry.Set
                            (type = entry.e_BRANCH, m_pos, pos-m_pos)))
                            type = entry.e_NONE;
                        m_pos = pos+1;
                        return type;
                    }
                }
                break;

            default:
                switch(state)
                {
                case e_STATE_SLASH:
                    if (0 > (length = entry.Set
                        (type = entry.e_ROOT, m_pos, pos-m_pos)))
                        type = entry.e_NONE;
                    m_pos = pos;
                    return type;

                case e_STATE_SLASHSLASH:
                    if (0 > (length = entry.Set
                        (type = entry.e_GROUND, m_pos, pos-m_pos)))
                        type = entry.e_NONE;
                    m_pos = pos;
                    return type;

                case e_STATE_DOT:
                case e_STATE_DOTDOT:
                    state = e_STATE_NAME;
                    break;

                default:
                    state = state;
                }
            }
        }

        switch(state)
        {
        case e_STATE_SLASH:
            if (0 > (length = entry.Set
                (type = entry.e_ROOT, m_pos, pos-m_pos)))
                type = entry.e_NONE;
            break;

        case e_STATE_SLASHSLASH:
            if (0 > (length = entry.Set
                (type = entry.e_GROUND, m_pos, pos-m_pos)))
                type = entry.e_NONE;
            break;

        case e_STATE_DOT:
            if (0 > (length = entry.Set
                (type = entry.e_LEAF, m_pos, pos-m_pos)))
                type = entry.e_NONE;
            break;

        case e_STATE_DOTDOT:
            if (0 > (length = entry.Set
                (type = entry.e_TREE, m_pos, pos-m_pos)))
                type = entry.e_NONE;
            break;

        default:
            if (0 < (length = pos-m_pos))
            if (0 > (length = entry.Set
                (type = entry.e_BRANCH, m_pos, length)))
                type = entry.e_NONE;
        }

        m_pos = pos;
        return type;
    }
};

/**
 **********************************************************************
 *  Class: cHttpRouterServlet
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
class cHttpRouterServlet
: public cHttpServlet
{
public:
    typedef cHttpServlet cIs;

    cHttpServletBranch m_root;
    cHttpServletPath m_path;
    cHttpServletPathEntry m_path_entry;

    /**
     **********************************************************************
     * Constructor: cHttpRouterServlet
     *
     *      Author: $author$
     *        Date: 10/25/2004
     **********************************************************************
     */
    cHttpRouterServlet()
    {
    }

    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError Service
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error = e_ERROR_NONE;
        cCharWriterInterface &writer = response.GetWriter();
        cHttpServletInterface *servlet = 0;
        cHttpServletBranch *branch = 0;
        cHttpServletTree *tree = 0;
        int length, type = cHttpServletPathEntry::e_NONE;
        const char *chars;

        if ((chars = request.GetPathInfo(length)))
        if (length > 0)
        if (0 < (length = m_path.Set(chars, length)))
        if (cHttpServletPathEntry::e_NONE 
            != (type = m_path.GetFirstEntry(m_path_entry)))
        do
        {
            switch(type)
            {
            case cHttpServletPathEntry::e_ROOT:
                branch = &m_root;
                tree = &branch->GetSubTree();
                break;

            case cHttpServletPathEntry::e_BRANCH:
                if (tree)
                if ((chars = m_path_entry.GetName(length)))
                if (length > 0)
                if ((branch = tree->Find(chars)))
                    tree = &branch->GetSubTree();
                break;
            }
            type = m_path.GetNextEntry(m_path_entry);
        }
        while (cHttpServletPathEntry::e_NONE != type);

        if (branch)
        if ((servlet = branch->GetServlet()))
            return error = servlet->Service(request, response);

        if (!(chars = request.GetPathInfo(length)))
            chars = "";

        response.SetStatusOK();
        response.SetContentType("text/plain");
        writer.Write("unable to associate \"");
        writer.Write(chars);
        writer.Write("\" with servlet\n");
        return error;
    }

    /**
     **********************************************************************
     * Function: SetRootServlet
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual cHttpServletInterface* SetRootServlet
    (cHttpServletInterface *servlet) 
    {
        m_root.SetServlet(servlet);
        return servlet;
    }
    /**
     **********************************************************************
     * Function: GetRootServlet
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual cHttpServletInterface* GetRootServlet() const
    {
        cHttpServletInterface* servlet = m_root.GetServlet();
        return servlet;
    }

    /**
     **********************************************************************
     * Function: InsertServlet
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual void InsertServlet(cHttpServlet &servlet) 
    {
        cHttpServletBranch &branch = servlet.GetBranch();
        InsertServlet(branch);
    }
    /**
     **********************************************************************
     * Function: DeleteServlet
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual void DeleteServlet(cHttpServlet &servlet) 
    {
        cHttpServletBranch &branch = servlet.GetBranch();
        DeleteServlet(branch);
    }
    /**
     **********************************************************************
     * Function: InsertServlet
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual void InsertServlet
    (cHttpServletBranch &branch) 
    {
        cHttpServletTree &tree = m_root.GetSubTree();

        tree.Insert(&branch);
    }
    /**
     **********************************************************************
     * Function: DeleteServlet
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual void DeleteServlet
    (cHttpServletBranch &branch) 
    {
        cHttpServletTree &tree = m_root.GetSubTree();

        tree.Delete(&branch);
    }
};

#endif /* ndef _CHTTPROUTERSERVLET_HXX */
