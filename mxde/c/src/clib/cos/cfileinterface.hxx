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
 *   File: cfileinterface.hxx
 *
 * Author: $author$
 *   Date: 3/15/2009
 **********************************************************************
 */
#if !defined(_CFILEINTERFACE_HXX) || defined(CFILEINTERFACE_MEMBERS_ONLY)
#if !defined(_CFILEINTERFACE_HXX) && !defined(CFILEINTERFACE_MEMBERS_ONLY)
#define _CFILEINTERFACE_HXX
#endif /* !defined(_CFILEINTERFACE_HXX) && !defined(CFILEINTERFACE_MEMBERS_ONLY) */

#if !defined(CFILEINTERFACE_MEMBERS_ONLY)
#include "cfileattachedinterface.hxx"
#include "cstoreinterface.hxx"

#define CFILE_MODE_READ CPLATFORM_FILE_MODE_READ
#define CFILE_MODE_READ_BINARY CPLATFORM_FILE_MODE_READ_BINARY

#define CFILE_MODE_WRITE CPLATFORM_FILE_MODE_WRITE
#define CFILE_MODE_WRITE_BINARY CPLATFORM_FILE_MODE_WRITE_BINARY

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cFileInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFileInterfaceT"
/**
 **********************************************************************
 *  Class: cFileInterfaceT
 *
 * Author: $author$
 *   Date: 3/15/2009
 **********************************************************************
 */
template
<class TDerives=cFileInterface,
 class TStoreInterface=cStoreInterface,
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
 class TUnattached=INT,
 TUnattached VUnattached=0,
 class TAttachedTo=FILE*,
 class TAttachedInterface=cFILEAttachedInterface,
 class TAttachedImplements=TAttachedInterface,
 class TImplements=TStoreInterface>
 
class c_INTERFACE_CLASS cFileInterfaceT
: virtual public TImplements,
  virtual public TAttachedImplements
{
public:
    typedef TImplements cImplements;
    typedef cFileInterfaceT cDerives;
#else /* !defined(CFILEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CFILEINTERFACE_MEMBERS_ONLY) */

#define CSTOREINTERFACE_MEMBERS_ONLY
#include "cstoreinterface.hxx"
#undef CSTOREINTERFACE_MEMBERS_ONLY
    
    typedef TAttachedTo tAttachedTo;
    typedef TAttachedInterface tAttachedInterface;
    typedef TUnattached tUnattached;
    enum { vUnattached = VUnattached };

#if !defined(CFILEINTERFACE_MEMBERS_ONLY) 

#define CFILE_MEMBERS_ONLY
#define CFILE_MEMBER_FUNCS_INTERFACE
#include "cfile.hxx"
#undef CFILE_MEMBER_FUNCS_INTERFACE
#undef CFILE_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS  cFileImplement;

#undef CDB_CLASS
#define CDB_CLASS "cFileImplementT"
/**
 **********************************************************************
 *  Class: cFileImplementT
 *
 * Author: $author$
 *   Date: 3/15/2009
 **********************************************************************
 */
template
<class TDerives=cFileImplement,
 class TFileInterface=cFileInterface,
 class TStoreImplement=cStoreImplement,
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
 class TUnattached=INT,
 TUnattached VUnattached=0,
 class TAttachedTo=FILE*,
 class TAttachedInterface=cFILEAttachedInterface,
 class TAttachedImplement=cFILEAttachedImplement,
 class TAttachedImplements=TAttachedImplement,
 class TStoreImplements=TStoreImplement,
 class TImplements=TFileInterface>
 
class c_IMPLEMENT_CLASS  cFileImplementT
: virtual public TStoreImplements,
  virtual public TAttachedImplements,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cFileImplementT cDerives;

#define CFILEINTERFACE_MEMBERS_ONLY
#include "cfileinterface.hxx"
#undef CFILEINTERFACE_MEMBERS_ONLY

#define CFILE_MEMBERS_ONLY
#define CFILE_MEMBER_FUNCS_IMPLEMENT
#include "cfile.hxx"
#undef CFILE_MEMBER_FUNCS_IMPLEMENT
#undef CFILE_MEMBERS_ONLY
};
#undef CDB_CLASS

/*
 * CHAR
 */
class c_INTERFACE_CLASS cFileInterface;
/**
 **********************************************************************
 * Typedef: cFileInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cFileInterfaceT
<cFileInterface, cStoreInterface, CHAR>
cFileInterfaceImplements;
/**
 **********************************************************************
 *  Class: cFileInterface
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cFileInterface
: virtual public cFileInterfaceImplements
{
public:
    typedef cFileInterfaceImplements cImplements;
    typedef cFileInterface cDerives;
};
class c_IMPLEMENT_CLASS  cFileImplement;
/**
 **********************************************************************
 * Typedef: cFileImplementImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cFileImplementT
<cFileImplement, cFileInterface,
 cStoreImplement, CHAR>
cFileImplementImplements;
/**
 **********************************************************************
 *  Class: cFileImplement
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cFileImplement
: virtual public cFileImplementImplements
{
public:
    typedef cFileImplementImplements cImplements;
    typedef cFileImplement cDerives;
};

/*
 * TCHAR
 */
class c_INTERFACE_CLASS cTCHARFileInterface;
/**
 **********************************************************************
 * Typedef: cTCHARFileInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cFileInterfaceT
<cTCHARFileInterface, cTCHARStoreInterface, TCHAR>
cTCHARFileInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTCHARFileInterface
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARFileInterface
: virtual public cTCHARFileInterfaceImplements
{
public:
    typedef cTCHARFileInterfaceImplements cImplements;
    typedef cTCHARFileInterface cDerives;
};
class c_IMPLEMENT_CLASS  cTCHARFileImplement;
/**
 **********************************************************************
 * Typedef: cTCHARFileImplementImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cFileImplementT
<cTCHARFileImplement, cTCHARFileInterface,
 cTCHARStoreImplement, TCHAR>
cTCHARFileImplementImplements;
/**
 **********************************************************************
 *  Class: cTCHARFileImplement
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cTCHARFileImplement
: virtual public cTCHARFileImplementImplements
{
public:
    typedef cTCHARFileImplementImplements cImplements;
    typedef cTCHARFileImplement cDerives;
};

/*
 * WCHAR
 */
class c_INTERFACE_CLASS cWCHARFileInterface;
/**
 **********************************************************************
 * Typedef: cWCHARFileInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cFileInterfaceT
<cWCHARFileInterface, cWCHARStoreInterface, WCHAR>
cWCHARFileInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWCHARFileInterface
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARFileInterface
: virtual public cWCHARFileInterfaceImplements
{
public:
    typedef cWCHARFileInterfaceImplements cImplements;
    typedef cWCHARFileInterface cDerives;
};
class c_IMPLEMENT_CLASS  cWCHARFileImplement;
/**
 **********************************************************************
 * Typedef: cWCHARFileImplementImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cFileImplementT
<cWCHARFileImplement, cWCHARFileInterface,
 cWCHARStoreImplement, WCHAR>
cWCHARFileImplementImplements;
/**
 **********************************************************************
 *  Class: cWCHARFileImplement
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cWCHARFileImplement
: virtual public cWCHARFileImplementImplements
{
public:
    typedef cWCHARFileImplementImplements cImplements;
    typedef cWCHARFileImplement cDerives;
};

/*
 * BYTE
 */
class c_INTERFACE_CLASS cBYTEFileInterface;
/**
 **********************************************************************
 * Typedef: cBYTEFileInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cFileInterfaceT
<cBYTEFileInterface, cBYTEStoreInterface, BYTE>
cBYTEFileInterfaceImplements;
/**
 **********************************************************************
 *  Class: cBYTEFileInterface
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEFileInterface
: virtual public cBYTEFileInterfaceImplements
{
public:
    typedef cBYTEFileInterfaceImplements cImplements;
    typedef cBYTEFileInterface cDerives;
};
class c_IMPLEMENT_CLASS  cBYTEFileImplement;
/**
 **********************************************************************
 * Typedef: cBYTEFileImplementImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cFileImplementT
<cBYTEFileImplement, cBYTEFileInterface,
 cBYTEStoreImplement, BYTE>
cBYTEFileImplementImplements;
/**
 **********************************************************************
 *  Class: cBYTEFileImplement
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cBYTEFileImplement
: virtual public cBYTEFileImplementImplements
{
public:
    typedef cBYTEFileImplementImplements cImplements;
    typedef cBYTEFileImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CFILEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CFILEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CFILEINTERFACE_HXX) || defined(CFILEINTERFACE_MEMBERS_ONLY) */
