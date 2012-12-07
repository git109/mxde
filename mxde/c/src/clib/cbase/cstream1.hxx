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
 *   File: cstream.hxx
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
#ifndef _CSTREAM_HXX
#define _CSTREAM_HXX

#if !defined(CSTREAM_MEMBER_FUNCS_ONLY) 
#include "cstreambase.hxx"
#include "cstreaminterface.hxx"

class cStream;

#undef CDB_CLASS
#define CDB_CLASS "cStreamT"
/**
 **********************************************************************
 *  Class: cStreamT
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
template
<class TDerives=cStream,
 class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TStreamInterface=cStreamInterface,
 class TStreamImplement=cStreamImplement,
 class TStreamBase=cStreamBase,
 class TImplements=TStreamImplement,
 class TExtends=TStreamBase>
 
class cStreamT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;

#define CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY
#include "cstreaminterfacebase.hxx"
#undef CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY

#else /* !defined(CSTREAM_MEMBER_FUNCS_ONLY) */
#endif /* !defined(CSTREAM_MEMBER_FUNCS_ONLY) */

#if !defined(CSTREAM_MEMBER_FUNCS_ONLY) 
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cStreamExtends
 *
 *  Author: $author$
 *    Date: 2/28/2009
 **********************************************************************
 */
typedef cStreamT<cStream,CHAR>
cStreamExtends;
/**
 **********************************************************************
 *  Class: cStream
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
class cStream
: public cStreamExtends
{
public:
    typedef cStreamExtends cExtends;
    typedef cStream cDerives;
};

/*
 * TCHAR
 */
class cTCHARStream;
/**
 **********************************************************************
 * Typedef: cTCHARStreamExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamT
<cTCHARStream,
 TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 TCHAR, NULL_TCHAR, cTCHARStreamInterface,
 cTCHARStreamImplement, cTCHARStreamBase>
cTCHARStreamExtends;
/**
 **********************************************************************
 *  Class: cTCHARStream
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cTCHARStream
: public cTCHARStreamExtends
{
public:
    typedef cTCHARStreamExtends cExtends;
    typedef cTCHARStream cDerives;
};

/*
 * WCHAR
 */
class cWCHARStream;
/**
 **********************************************************************
 * Typedef: cWCHARStreamExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamT
<cWCHARStream,
 WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 WCHAR, NULL_WCHAR, cWCHARStreamInterface,
 cWCHARStreamImplement, cWCHARStreamBase>
cWCHARStreamExtends;
/**
 **********************************************************************
 *  Class: cWCHARStream
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cWCHARStream
: public cWCHARStreamExtends
{
public:
    typedef cWCHARStreamExtends cExtends;
    typedef cWCHARStream cDerives;
};
#else /* !defined(CSTREAM_MEMBER_FUNCS_ONLY) */
#endif /* !defined(CSTREAM_MEMBER_FUNCS_ONLY) */

#endif /* _CSTREAM_HXX */
