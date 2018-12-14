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
 *   File: cccharatomlist.hxx
 *
 * Author: $author$
 *   Date: 11/1/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CCCHARATOMLIST_HXX
#define _CCCHARATOMLIST_HXX

#include "cccharnamereferencetree.hxx"
#include "cccharbuffer.hxx"
#include "clistt.hxx"

/**
 **********************************************************************
 *  Class: cCCharAtom
 *
 * Author: $author$
 *   Date: 11/1/2005
 **********************************************************************
 */
class cCCharAtom
: public cDynamicListItemT<cCCharAtom>
{
public:
    typedef cDynamicListItemT<cCCharAtom> cIs;

    cCCharBuffer m_name;
    cCCharNameReferenceBranch m_branch;

    /**
     **********************************************************************
     * Constructor: cCCharAtom
     *
     *      Author: $author$
     *        Date: 11/1/2005
     **********************************************************************
     */
    cCCharAtom
    (const cChar* chars=0, int length=-1) 
    : m_branch(m_name)
    {
        eError error;

        if (chars)
        if (0 > (length = SetNameCChars(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Function: SetNameChars
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual int SetNameChars
    (const char* chars, int length=-1) 
    {
        length = m_name.Copyc(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: SetNameCChars
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual int SetNameCChars
    (const cChar* chars, int length=-1) 
    {
        length = m_name.Copy(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetNameCChars
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual const cChar* GetNameCChars(int &length) const 
    {
        const cChar* chars = m_name.GetBuffer(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 11/1/2005
     **********************************************************************
     */
    virtual int SetName
    (const cCCharBuffer& name) 
    {
        int length;
        const cChar* chars;

        if ((chars = name.GetBuffer(length)))
            length = m_name.Copy(chars, length);

        return length;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    const cCCharBuffer& GetName() const 
    {
        return m_name;
    }

    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 11/2/2005
     **********************************************************************
     */
    cCCharNameReferenceBranch& GetBranch() 
    {
        return m_branch;
    }
};

/**
 **********************************************************************
 *  Class: cCCharAtomList
 *
 * Author: $author$
 *   Date: 11/1/2005
 **********************************************************************
 */
class cCCharAtomList
: public cDynamicListT
  <cCCharAtom, cCCharAtomList>
{
public:
    typedef cDynamicListT
    <cCCharAtom, cCCharAtomList> cIs;

    /**
     **********************************************************************
     * Constructor: cCCharAtomList
     *
     *      Author: $author$
     *        Date: 11/1/2005
     **********************************************************************
     */
    cCCharAtomList() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cCCharAtomList
     *
     *     Author: $author$
     *       Date: 11/2/2005
     **********************************************************************
     */
    virtual ~cCCharAtomList() 
    {
    }
};

#endif /* _CCCHARATOMLIST_HXX */
