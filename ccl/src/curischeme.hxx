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
 *   File: curischeme.hxx
 *
 * Author: $author$
 *   Date: 6/5/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CURISCHEME_HXX
#define _CURISCHEME_HXX

#include "clistt.hxx"
#include "curischemeinterface.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cURIScheme
 *
 * Author: $author$
 *   Date: 6/5/2004
 **********************************************************************
 */
class cURIScheme
: virtual public cURISchemeInterface,
  virtual public cURISchemeImplement,
  public cListItemT<cURIScheme, cErrorInstance>
{
public:
    typedef cListItemT<cURIScheme, cErrorInstance> cIs;

    const char *m_name;
    int m_name_length;

    /**
     **********************************************************************
     * Constructor: cURIScheme
     *
     *      Author: $author$
     *        Date: 6/5/2004
     **********************************************************************
     */
    cURIScheme(const char *name)
    : m_name(name)
    {
        m_name_length = strlen(name);
    }
    /**
     **********************************************************************
     * Destructor: ~cURIScheme
     *
     *     Author: $author$
     *       Date: 6/5/2004
     **********************************************************************
     */
    virtual ~cURIScheme()
    {
    }

    /**
     **********************************************************************
     * Function: GetSchemeName
     *
     *   Author: $author$
     *     Date: 6/1/2004
     **********************************************************************
     */
    virtual const char *GetSchemeName(int &length) const
    {
        length = m_name_length;
        return m_name;
    }
    /**
     **********************************************************************
     * Function: CompareName
     *
     *   Author: $author$
     *     Date: 6/5/2004
     **********************************************************************
     */
    int CompareName(const char *name, int length=-1) const
    {
        int name_length, length_compare, compare;

        if (length < 0)
            return strcmp(name, m_name);

        if ((length_compare = ((name_length = length) > m_name_length)))
            name_length = m_name_length;

        else if ((length_compare = length < m_name_length))
                length_compare = -1;

        if ((compare = strncmp(name, m_name, name_length)))
            return compare;

        return length_compare;
    }
};

/**
 **********************************************************************
 *  Class: cStaticURISchemeSet
 *
 * Author: $author$
 *   Date: 6/7/2004
 **********************************************************************
 */
class cStaticURISchemeSet
: virtual public cURISchemeSetInterface,
  virtual public cURISchemeSetImplement,
  public cStaticListT<cURIScheme, cStaticURISchemeSet, cErrorInstance>
{
public:
    typedef cStaticListT<cURIScheme, cStaticURISchemeSet, cErrorInstance> cIs;

    static cStaticURISchemeSet m_instance;

    /**
     **********************************************************************
     * Function: GetFirstURISchemeByName
     *
     *   Author: $author$
     *     Date: 6/7/2004
     **********************************************************************
     */
    virtual cURISchemeInterface *GetFirstURISchemeByName
    (const char *name, int namelen=-1) const
    {
        cURIScheme *scheme=0;

        for (scheme=GetFirst(); scheme; scheme=scheme->GetNext())
        {
            if (!scheme->CompareName(name, namelen))
                break;
        }
        return scheme;
    }
    /**
     **********************************************************************
     * Function: GetLastURISchemeByName
     *
     *   Author: $author$
     *     Date: 6/7/2004
     **********************************************************************
     */
    virtual cURISchemeInterface *GetLastURISchemeByName
    (const char *name, int namelen=-1) const
    {
        cURIScheme *scheme=0;

        for (scheme=GetLast(); scheme; scheme=scheme->GetPrevious())
        {
            if (!scheme->CompareName(name, namelen))
                break;
        }
        return scheme;
    }
};

/**
 **********************************************************************
 *  Class: cStaticURIScheme
 *
 * Author: $author$
 *   Date: 6/7/2004
 **********************************************************************
 */
class cStaticURIScheme
: public cURIScheme
{
public:
    typedef cURIScheme cIs;

    /**
     **********************************************************************
     * Constructor: cStaticURIScheme
     *
     *      Author: $author$
     *        Date: 6/7/2004
     **********************************************************************
     */
    cStaticURIScheme(const char *name)
    : cIs(name) 
    {
        cStaticURISchemeSet::m_instance.Add(this);
    }
    /**
     **********************************************************************
     * Destructor: ~cStaticURIScheme
     *
     *     Author: $author$
     *       Date: 6/7/2004
     **********************************************************************
     */
    virtual ~cStaticURIScheme()
    {
        cStaticURISchemeSet::m_instance.Delete(this);
    }
};

#endif /* ndef _CURISCHEME_HXX */
