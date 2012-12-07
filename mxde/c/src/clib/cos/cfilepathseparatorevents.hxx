/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cfilepathseparatorevents.hxx
 *
 * Author: $author$
 *   Date: 10/13/2009
 **********************************************************************
 */
#if !defined(_CFILEPATHSEPARATOREVENTS_HXX) || defined(CFILEPATHSEPARATOREVENTS_MEMBERS_ONLY)
#if !defined(_CFILEPATHSEPARATOREVENTS_HXX) && !defined(CFILEPATHSEPARATOREVENTS_MEMBERS_ONLY)
#define _CFILEPATHSEPARATOREVENTS_HXX
#endif /* !defined(_CFILEPATHSEPARATOREVENTS_HXX) && !defined(CFILEPATHSEPARATOREVENTS_MEMBERS_ONLY) */

#if !defined(CFILEPATHSEPARATOREVENTS_MEMBERS_ONLY)
#include "cfilepathseparatoreventsinterface.hxx"
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class cFilePathSeparatorEvents;

#undef CDB_CLASS
#define CDB_CLASS "cFilePathSeparatorEventsT"
/**
 **********************************************************************
 *  Class: cFilePathSeparatorEventsT
 *
 * Author: $author$
 *   Date: 10/13/2009
 **********************************************************************
 */
template
<class TDerives=cFilePathSeparatorEvents,
 class TFilePathSeparatorEventsImplement=cFilePathSeparatorEventsImplement,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TBase=cBase,
 class TImplements=TFilePathSeparatorEventsImplement,
 class TExtends=TBase>

class cFilePathSeparatorEventsT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef cBase cExtends;
    
/* include cFilePathSeparatorEvents interface member definitions
 */
#define CFILEPATHSEPARATOREVENTSINTERFACE_MEMBERS_ONLY
#include "cfilepathseparatoreventsinterface.hxx"
#undef CFILEPATHSEPARATOREVENTSINTERFACE_MEMBERS_ONLY

#else /* !defined(CFILEPATHSEPARATOREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CFILEPATHSEPARATOREVENTS_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: OnPathFileHost
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileHost
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */

        return count;
    }
#endif /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPathFileRootHost
     *
     *   Author: $author$
     *     Date: 10/15/2009
     **********************************************************************
     */
    virtual tLength OnPathFileRootHost
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPathFileVolume
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileVolume
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */

        return count;
    }
#endif /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPathFileDirectory
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileDirectory
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */

        return count;
    }
#endif /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPathFileRootDirectory
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileRootDirectory
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPathFileCurrentDirectory
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileCurrentDirectory
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPathFileRootCurrentDirectory
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileRootCurrentDirectory
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPathFileParentDirectory
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileParentDirectory
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPathFileRootParentDirectory
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileRootParentDirectory
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPathFileBase
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileBase
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */

        return count;
    }
#endif /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPathFileRootBase
     *
     *   Author: $author$
     *     Date: 10/15/2009
     **********************************************************************
     */
    virtual tLength OnPathFileRootBase
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */

        return count;
    }
#endif /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPathFileExtension
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileExtension
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT) */

        return count;
    }
#endif /* defined(CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE) */

#if !defined(CFILEPATHSEPARATOREVENTS_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cFilePathSeparatorEventsExtends
 *
 *  Author: $author$
 *    Date: 10/14/2009
 **********************************************************************
 */
typedef cFilePathSeparatorEventsT<>
cFilePathSeparatorEventsExtends;
/**
 **********************************************************************
 *  Class: cFilePathSeparatorEvents
 *
 * Author: $author$
 *   Date: 10/14/2009
 **********************************************************************
 */
class cFilePathSeparatorEvents
: public cFilePathSeparatorEventsExtends
{
public:
    typedef cFilePathSeparatorEventsExtends cExtends;
};

/*
 * WCHAR
 */
 
class cWFilePathSeparatorEvents;
/**
 **********************************************************************
 * Typedef: cWFilePathSeparatorEventsExtends
 *
 *  Author: $author$
 *    Date: 10/14/2009
 **********************************************************************
 */
typedef cFilePathSeparatorEventsT
<cWFilePathSeparatorEvents, 
 cWFilePathSeparatorEventsImplement, WCHAR>
cWFilePathSeparatorEventsExtends;
/**
 **********************************************************************
 *  Class: cWFilePathSeparatorEvents
 *
 * Author: $author$
 *   Date: 10/14/2009
 **********************************************************************
 */
class cWFilePathSeparatorEvents
: public cWFilePathSeparatorEventsExtends
{
public:
    typedef cWFilePathSeparatorEventsExtends cExtends;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CFILEPATHSEPARATOREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CFILEPATHSEPARATOREVENTS_MEMBERS_ONLY) */

#endif /* !defined(_CFILEPATHSEPARATOREVENTS_HXX) || defined(CFILEPATHSEPARATOREVENTS_MEMBERS_ONLY) */
