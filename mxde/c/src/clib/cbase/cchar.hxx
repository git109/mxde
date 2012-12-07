/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cchar.hxx
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
#if !defined(_CCHAR_HXX) || defined(CCHAR_MEMBERS_ONLY)
#if !defined(_CCHAR_HXX) && !defined(CCHAR_MEMBERS_ONLY)
#define _CCHAR_HXX
#endif /* !defined(_CCHAR_HXX) && !defined(CCHAR_MEMBERS_ONLY) */

#if !defined(CCHAR_MEMBERS_ONLY)
#include "ccharinterface.hxx"
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cChar;
#undef CDB_CLASS
#define CDB_CLASS "cCharT"
/**
 **********************************************************************
 *  Class: cCharT
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
template
<class TDerives=cChar,
 class TCharImplement=cCharImplement,
 class TCharExtend=cBase,
 class TChar=WCHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TImplements=TCharImplement,
 class TExtends=TCharExtend>

class c_INSTANCE_CLASS cCharT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;

/* include cChar interface member definitions
 */
#define CCHARINTERFACE_MEMBERS_ONLY
#include "ccharinterface.hxx"
#undef CCHARINTERFACE_MEMBERS_ONLY

    tChar m_chr;

    /**
     **********************************************************************
     *  Constructor: cCharT
     *
     *       Author: $author$
     *         Date: 4/7/2010
     **********************************************************************
     */
    cCharT
    (tChar chr = (tChar)(vEndChar))
    : m_chr(chr)
    {
    }
#else /* !defined(CCHAR_MEMBERS_ONLY) */
#endif /* !defined(CCHAR_MEMBERS_ONLY) */

#if !defined(CCHAR_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: operator ==
     *
     *   Author: $author$
     *     Date: 4/7/2010
     **********************************************************************
     */
    bool operator == (const cDerives& to) const
    {
        bool isTrue = (m_chr == to.m_chr);
        return isTrue;
    }
    /**
     **********************************************************************
     * Function: operator !=
     *
     *   Author: $author$
     *     Date: 4/7/2010
     **********************************************************************
     */
    bool operator != (const cDerives& to) const
    {
        bool isTrue = (m_chr != to.m_chr);
        return isTrue;
    }
    /**
     **********************************************************************
     * Function: operator <
     *
     *   Author: $author$
     *     Date: 4/7/2010
     **********************************************************************
     */
    bool operator < (const cDerives& to) const
    {
        bool isTrue = (m_chr < to.m_chr);
        return isTrue;
    }
    /**
     **********************************************************************
     * Function: operator >
     *
     *   Author: $author$
     *     Date: 4/7/2010
     **********************************************************************
     */
    bool operator > (const cDerives& to) const
    {
        bool isTrue = (m_chr > to.m_chr);
        return isTrue;
    }
};
#undef CDB_CLASS

class c_INSTANCE_CLASS cChar;
/**
 **********************************************************************
 * Typedef: cCharExtend
 *
 *  Author: $author$
 *    Date: 4/7/2010
 **********************************************************************
 */
typedef cCharT<>
cCharExtend;
/**
 **********************************************************************
 *  Class: cChar
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cChar
: public cCharExtend
{
public:
    typedef cCharExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cChar
     *
     *       Author: $author$
     *         Date: 4/7/2010
     **********************************************************************
     */
    cChar
    (tChar chr = (tChar)(vEndChar))
    : cExtends(chr)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCHAR_MEMBERS_ONLY) */
#endif /* !defined(CCHAR_MEMBERS_ONLY) */

#endif /* !defined(_CCHAR_HXX) || defined(CCHAR_MEMBERS_ONLY) */
