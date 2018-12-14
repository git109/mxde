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
 *   File: cdocumentnamespacefactory.hxx
 *
 * Author: $author$
 *   Date: 11/26/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTNAMESPACEFACTORY_HXX
#define _CDOCUMENTNAMESPACEFACTORY_HXX

#include "cdocumentnamespace.hxx"
#include "cdocumentnamespacetree.hxx"
#include "cccharatomlist.hxx"
#include "cdocumentnamespacefactoryimplement.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cDocumentNamespaceFactory
 *
 * Author: $author$
 *   Date: 11/26/2005
 **********************************************************************
 */
class cDocumentNamespaceFactory
: virtual public cDocumentNamespaceFactoryImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    static cDocumentNamespaceFactory m_instance;

    cDocumentNamespaceTree m_namespace_tree;
    cDocumentNamespaceList m_namespace_list;
    cCCharNameReferenceTree m_name_tree;
    cCCharAtomList m_atom_list;

    /**
     **********************************************************************
     * Constructor: cDocumentNamespaceFactory
     *
     *      Author: $author$
     *        Date: 11/26/2005
     **********************************************************************
     */
    cDocumentNamespaceFactory() 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDocumentNamespaceFactory
     *
     *      Author: $author$
     *        Date: 11/26/2005
     **********************************************************************
     */
    virtual ~cDocumentNamespaceFactory()
    {
    }
    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface* GetNamespace
    (const cCCharBuffer& name) 
    {
        cDocumentNamespaceInterface* ns;
        cDocumentNamespace* new_ns;
        const cChar* chars;
        int length;

        if (!(ns = m_namespace_tree.Find(name)))
        if ((chars = name.GetBuffer(length)))
        if (0 < length)
        if ((new_ns = new cDocumentNamespace()))
        {
            if (0 < (length = new_ns->SetNamespaceURICChars
                (chars, length)))
            {
                m_namespace_list.Add(new_ns);
                m_namespace_tree.Insert(&new_ns->m_branch);
                return new_ns;
            }
            delete new_ns;
        }
        return ns;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer* GetName
    (const cCCharBuffer& name) 
    {
        int length;
        const cCCharBuffer* found_name;
        cCCharAtom* atom;

        if (!(found_name = m_name_tree.FindName(name)))
        if ((atom = new cCCharAtom()))
        {
            if (0 > (length = atom->SetName(name)))
                delete atom;

            else
            {
                m_atom_list.Add(atom);
                m_name_tree.Insert(&atom->GetBranch());
                found_name = &atom->GetName();
            }
        }
        return found_name;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual const cCCharBuffer* GetName
    (const cChar* chars, int length=-1) 
    {
        const cCCharBuffer* name;
        cCCharAtom* atom;

        if (!(name = m_name_tree.FindName(chars, length)))
        if ((atom = new cCCharAtom()))
        {
            if (0 > (length = atom->SetNameCChars(chars, length)))
                delete atom;

            else
            {
                m_atom_list.Add(atom);
                m_name_tree.Insert(&atom->GetBranch());
                name = &atom->GetName();
            }
        }
        return name;
    }
    /**
     **********************************************************************
     * Function: FreeName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    virtual eError FreeName
    (const cCCharBuffer& m_name) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cStaticDocumentNamespaceFactory
 *
 * Author: $author$
 *   Date: 11/26/2005
 **********************************************************************
 */
class cStaticDocumentNamespaceFactory
: virtual public cDocumentNamespaceFactoryImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    /**
     **********************************************************************
     * Function: GetNamespace
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual cDocumentNamespaceInterface* GetNamespace
    (const cCCharBuffer& name) 
    {
        cDocumentNamespaceInterface* ns
        = cDocumentNamespaceFactory::m_instance.GetNamespace(name);
        return ns;
    }
};

#endif /* _CDOCUMENTNAMESPACEFACTORY_HXX */
