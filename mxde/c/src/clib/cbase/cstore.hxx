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
 *   File: cstore.hxx
 *
 * Author: $author$
 *   Date: 3/18/2009
 **********************************************************************
 */
#if !defined(_CSTORE_HXX) || defined(CSTORE_MEMBERS_ONLY)
#if !defined(_CSTORE_HXX) && !defined(CSTORE_MEMBERS_ONLY)
#define _CSTORE_HXX
#endif /* !defined(_CSTORE_HXX) && !defined(CSTORE_MEMBERS_ONLY) */

#if !defined(CSTORE_MEMBERS_ONLY)
#include "cstoreinterface.hxx"
#include "cstream.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cStore;

#undef CDB_CLASS
#define CDB_CLASS "cStoreT"
/**
 **********************************************************************
 *  Class: cStoreT
 *
 * Author: $author$
 *   Date: 3/18/2009
 **********************************************************************
 */
template
<class TDerives=cStore,
 class TStoreImplement=cStoreImplement,
 class TStream=cStream,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TWhence=eSeek,
 TWhence VWhenceCurrent=e_SEEK_CUR,
 TWhence VWhenceBegin=e_SEEK_SET,
 TWhence VWhenceEnd=e_SEEK_END,
 class TImplements=TStoreImplement,
 class TExtends=TStream>
 
class c_INSTANCE_CLASS cStoreT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;

/* include cStore interface member definitions
 */
#define CSTOREINTERFACE_MEMBERS_ONLY
#include "cstoreinterface.hxx"
#undef CSTOREINTERFACE_MEMBERS_ONLY

#else /* !defined(CSTORE_MEMBERS_ONLY) */
#endif /* !defined(CSTORE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Seek
     *
     *   Author: $author$
     *     Date: 3/18/2009
     **********************************************************************
     */
    virtual tLength Seek
    (tLength count,
     tWhence whence=vWhenceBegin) 
#if defined(CSTORE_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CSTORE_MEMBER_FUNCS_INTERFACE) */
    {
        tLength tell = 0;
#if !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) */
        return tell;
    }
#endif /* defined(CSTORE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Tell
     *
     *   Author: $author$
     *     Date: 3/18/2009
     **********************************************************************
     */
    virtual tLength Tell() const 
#if defined(CSTORE_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CSTORE_MEMBER_FUNCS_INTERFACE) */
    {
        tLength tell = 0;
#if !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) */
        return tell;
    }
#endif /* defined(CSTORE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Size
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tLength Size() const
#if defined(CSTORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CSTORE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) 
        tLength size = 0;
#else /* !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) */
        tLength size = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) */
        return size;
    }
#endif /* defined(CSTORE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetSize
     *
     *   Author: $author$
     *     Date: 5/14/2009
     **********************************************************************
     */
    virtual tLength GetSize() 
#if defined(CSTORE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CSTORE_MEMBER_FUNCS_INTERFACE */
    {
        tLength size = Size();
#if !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) */
        return size;
    }
#endif /* defined(CSTORE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CSTORE_MEMBERS_ONLY) 
    /**
     **********************************************************************
     * Function: Reset
     *
     *   Author: $author$
     *     Date: 9/14/2009
     **********************************************************************
     */
    virtual tLength Reset
    (tLength length=vUndefinedLength) 
#if defined(CSTORE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTORE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = Seek((0>length)?0:length);
#else /* !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTORE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Reread
     *
     *   Author: $author$
     *     Date: 9/14/2009
     **********************************************************************
     */
    virtual tLength Reread
    (tLength length=vUndefinedLength) 
#if defined(CSTORE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTORE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = Reset(length);
#else /* !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTORE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Rewrite
     *
     *   Author: $author$
     *     Date: 9/14/2009
     **********************************************************************
     */
    virtual tLength Rewrite
    (tLength length=vUndefinedLength) 
#if defined(CSTORE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTORE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = Reset(length);
#else /* !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTORE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CSTORE_MEMBER_FUNCS_INTERFACE) */
};
#undef CDB_CLASS

/*
 * CHAR
 */
class c_INSTANCE_CLASS cStore;
/**
 **********************************************************************
 * Typedef: cStoreExtends
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cStoreT
<cStore, cStoreImplement,
 cStream, CHAR>
cStoreExtends;
/**
 **********************************************************************
 *  Class: cStore
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cStore
: public cStoreExtends
{
public:
    typedef cStoreExtends cExtends;
    typedef cStore cDerives;
};
typedef cStore cCHARStore;
/*
 * TCHAR
 */
class c_INSTANCE_CLASS cTCHARStore;
/**
 **********************************************************************
 * Typedef: cTCHARStoreExtends
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cStoreT
<cTCHARStore, cTCHARStoreImplement,
 cTCHARStream, TCHAR>
cTCHARStoreExtends;
/**
 **********************************************************************
 *  Class: cTCHARStore
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cTCHARStore
: public cTCHARStoreExtends
{
public:
    typedef cTCHARStoreExtends cExtends;
    typedef cTCHARStore cDerives;
};

/*
 * WCHAR
 */
class c_INSTANCE_CLASS cWCHARStore;
/**
 **********************************************************************
 * Typedef: cWCHARStoreExtends
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cStoreT
<cWCHARStore, cWCHARStoreImplement,
 cWCHARStream, WCHAR>
cWCHARStoreExtends;
/**
 **********************************************************************
 *  Class: cWCHARStore
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cWCHARStore
: public cWCHARStoreExtends
{
public:
    typedef cWCHARStoreExtends cExtends;
    typedef cWCHARStore cDerives;
};

/*
 * BYTE
 */
class c_INSTANCE_CLASS cBYTEStore;
/**
 **********************************************************************
 * Typedef: cBYTEStoreExtends
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cStoreT
<cBYTEStore, cBYTEStoreImplement,
 cBYTEStream, BYTE>
cBYTEStoreExtends;
/**
 **********************************************************************
 *  Class: cBYTEStore
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cBYTEStore
: public cBYTEStoreExtends
{
public:
    typedef cBYTEStoreExtends cExtends;
    typedef cBYTEStore cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSTORE_MEMBERS_ONLY) */
#endif /* !defined(CSTORE_MEMBERS_ONLY) */

#endif /* !defined(_CSTORE_HXX) || defined(CSTORE_MEMBERS_ONLY) */
