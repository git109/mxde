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
 *   File: cdocumentparsertype.hxx
 *
 * Author: $author$
 *   Date: 11/24/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTPARSERTYPE_HXX
#define _CDOCUMENTPARSERTYPE_HXX

#include "cdocumentnamespacefactory.hxx"
#include "cdocumentparsertypeinterface.hxx"
#include "cdocumentparserinterface.hxx"
#include "curi.hxx"
#include "clistt.hxx"
#include "cavltreet.hxx"

/**
 **********************************************************************
 *  Class: cDocumentParserTypeBranch
 *
 * Author: $author$
 *   Date: 11/4/2005
 **********************************************************************
 */
class cDocumentParserTypeBranch
: public cAVLTreeBranchT<cDocumentParserTypeBranch>
{
public:
    typedef cAVLTreeBranchT<cDocumentParserTypeBranch> cIs;

    const cURIInterface& m_uri;
    cDocumentParserTypeInterface& m_parser_type;

    /**
     **********************************************************************
     * Constructor: cDocumentParserTypeBranch
     *
     *      Author: $author$
     *        Date: 11/4/2005
     **********************************************************************
     */
    cDocumentParserTypeBranch
    (const cURIInterface& uri,
     cDocumentParserTypeInterface& parser_type) 
    : m_uri(uri),
      m_parser_type(parser_type)
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    int Compare(cDocumentParserTypeBranch &branch) const
    {
        const cURIInterface& uri = branch.GetURI();
        int unequal = Compare(uri);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    int Compare(const cURIInterface& uri) const
    {
        int unequal = m_uri.Compare(uri);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    int Compare(const cCCharBuffer& uri) const
    {
        int unequal = m_uri.Compare(uri);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    int Compare(const char* chars, int length=-1) const
    {
        int unequal = m_uri.Compare(chars, length);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetURI
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    const cURIInterface& GetURI() const 
    {
        return m_uri;
    }
    /**
     **********************************************************************
     * Function: GetParserType
     *
     *   Author: $author$
     *     Date: 11/6/2005
     **********************************************************************
     */
    cDocumentParserTypeInterface& GetParserType() const 
    {
        return m_parser_type;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentParserTypeCharsTree
 *
 * Author: $author$
 *   Date: 11/6/2005
 **********************************************************************
 */
class cDocumentParserTypeCharsTree
: public cAVLTreeT
  <const char*, 
   cDocumentParserTypeBranch, cDocumentParserTypeCharsTree>
{
public:
    typedef cAVLTreeT
    <const char*, 
     cDocumentParserTypeBranch, cDocumentParserTypeCharsTree> cIs;

    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 11/6/2005
     **********************************************************************
     */
    virtual cDocumentParserTypeInterface* Find
    (const char* chars, int length=-1) 
    {
        cDocumentParserTypeInterface* parser_type = 0;
        cDocumentParserTypeBranch* branch;

        if ((branch = cIs::Find(chars, length)))
            parser_type = &branch->GetParserType();

        return parser_type;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentParserTypeTree
 *
 * Author: $author$
 *   Date: 11/4/2005
 **********************************************************************
 */
class cDocumentParserTypeTree
: public cAVLTreeT
  <const cURIInterface, 
   cDocumentParserTypeBranch, cDocumentParserTypeTree>
{
public:
    typedef cAVLTreeT
    <const cURIInterface, 
     cDocumentParserTypeBranch, cDocumentParserTypeTree> cIs;

    static cDocumentParserTypeTree m_instance;

    cDocumentParserTypeCharsTree m_chars_tree;

    /**
     **********************************************************************
     * Constructor: cDocumentParserTypeTree
     *
     *      Author: $author$
     *        Date: 11/4/2005
     **********************************************************************
     */
    cDocumentParserTypeTree() 
    {
    }
    /**
     **********************************************************************
     * Function: Insert
     *
     *   Author: $author$
     *     Date: 11/6/2005
     **********************************************************************
     */
    void Insert(cDocumentParserTypeBranch* branch)
    {
        cIs::Insert(branch);
        m_chars_tree.SetRoot(GetRoot());
    }
    /**
     **********************************************************************
     * Function: Delete
     *
     *   Author: $author$
     *     Date: 11/6/2005
     **********************************************************************
     */
    void Delete(cDocumentParserTypeBranch* branch)
    {
        cIs::Delete(branch);
        m_chars_tree.SetRoot(GetRoot());
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 11/6/2005
     **********************************************************************
     */
    virtual cDocumentParserTypeInterface* Find
    (const char* chars, int length=-1) 
    {
        cDocumentParserTypeInterface* parser_type = m_chars_tree.Find(chars, length);
        return parser_type;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentParserType
 *
 * Author: $author$
 *   Date: 11/4/2005
 **********************************************************************
 */
class cDocumentParserType
: virtual public cDocumentParserTypeImplement,
  public cInstance
{
public:
    cURI m_uri;
    cDocumentParserTypeBranch m_branch;

    /**
     **********************************************************************
     * Constructor: cDocumentParserType
     *
     *      Author: $author$
     *        Date: 11/4/2005
     **********************************************************************
     */
    cDocumentParserType(const char *chars=0, int length=-1) 
    : m_uri(chars, length),
      m_branch(m_uri, *this)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDocumentParserType
     *
     *      Author: $author$
     *        Date: 11/4/2005
     **********************************************************************
     */
    virtual ~cDocumentParserType()
    {
    }
};

/**
 **********************************************************************
 *  Class: cStaticDocumentParserType
 *
 * Author: $author$
 *   Date: 11/4/2005
 **********************************************************************
 */
class cStaticDocumentParserType
: public cListItemT
  <cStaticDocumentParserType, cDocumentParserType>
{
public:
    typedef cListItemT
    <cStaticDocumentParserType, cDocumentParserType> cIs;

    cStaticDocumentNamespaceFactory m_ns_factory;

    /**
     **********************************************************************
     * Constructor: cStaticDocumentParserType
     *
     *      Author: $author$
     *        Date: 11/4/2005
     **********************************************************************
     */
    cStaticDocumentParserType
    (const char *chars=0, int length=-1) 
    {
        eError error;

        if (chars)
        if (0 > (length = m_uri.SetURIChars(chars, length)))
            throw(error = -length);

        AddToList();
    }
    /**
     **********************************************************************
     * Destructor: ~cStaticDocumentParserType
     *
     *     Author: $author$
     *       Date: 11/4/2005
     **********************************************************************
     */
    virtual ~cStaticDocumentParserType() 
    {
        DeleteFromList();
    }

    /**
     **********************************************************************
     * Function: AddToList
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    void AddToList();
    /**
     **********************************************************************
     * Function: DeleteFromList
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    void DeleteFromList();
};

/**
 **********************************************************************
 *  Class: cStaticDocumentParserTypeList
 *
 * Author: $author$
 *   Date: 11/4/2005
 **********************************************************************
 */
class cStaticDocumentParserTypeList
: public cStaticListT
  <cStaticDocumentParserType, cStaticDocumentParserTypeList>
{
public:
    typedef cStaticListT
    <cStaticDocumentParserType, cStaticDocumentParserTypeList> cIs;

    static cStaticDocumentParserTypeList m_instance;

    /**
     **********************************************************************
     * Constructor: cStaticDocumentParserTypeList
     *
     *      Author: $author$
     *        Date: 11/4/2005
     **********************************************************************
     */
    cStaticDocumentParserTypeList() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cStaticDocumentParserTypeList
     *
     *     Author: $author$
     *       Date: 11/4/2005
     **********************************************************************
     */
    virtual ~cStaticDocumentParserTypeList() 
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        cStaticDocumentParserType* type;

        for (type=cStaticDocumentParserTypeList::m_instance.GetFirst(); 
             type; type=type->GetNext())
            cDocumentParserTypeTree::m_instance.Insert(&type->m_branch);

        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 11/4/2005
     **********************************************************************
     */
    eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        cStaticDocumentParserType* type;

        for (type=cStaticDocumentParserTypeList::m_instance.GetLast(); 
             type; type=type->GetPrevious())
            cDocumentParserTypeTree::m_instance.Delete(&type->m_branch);

        return error;
    }
};

#endif /* _CDOCUMENTPARSERTYPE_HXX */
