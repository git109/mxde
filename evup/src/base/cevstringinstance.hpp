///////////////////////////////////////////////////////////////////////
//   File: cevstringinstance.hpp
//
// Author: $author$
//   Date: 7/5/2009
///////////////////////////////////////////////////////////////////////

#ifndef _CEVSTRINGINSTANCE_HPP
#define _CEVSTRINGINSTANCE_HPP

#include "evstringinstance.hpp"
#include "cevinstance.hpp"
#include "cevstring.hpp"
#include "evcharreader.hpp"
#include "evcharwriter.hpp"

#undef CDB_CLASS
#define CDB_CLASS "CEvStringInstanceT"
///////////////////////////////////////////////////////////////////////
//  Class: CEvStringInstanceT
//
// Author: $author$
//   Date: 5/17/2009
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TReader=EvReader<TChar, TSize, TLength>,
 class TWriter=EvWriter<TChar, TSize, TLength>,
 class TStringImplements=EvStringInstanceT
 <EvStringT<TChar, TSize, TLength>, EvInstance>,
 class TStringExtends=CEvStringT
 <TChar, TSize, TLength, TReader, TWriter,
  TStringImplements, ::std::basic_string<TChar> >,
 class TExtends=CEvInstanceT<TStringExtends> >
 
class CEvStringInstanceT
: public TExtends
{
public:
    typedef TExtends CEvExtends;
    typedef CEvStringInstanceT CEvDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvStringInstanceT
    //
    //      Author: $author$
    //        Date: 5/17/2009
    ///////////////////////////////////////////////////////////////////////
    CEvStringInstanceT
    (const TChar* chars=0, TLength length=-1) 
    {
        EvError error;
        if (chars)
        if (0 > (length = CTHIS Append(chars, length)))
            throw(error = -length);
    }
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvStringInstanceExtends
//
//   Author: $author$
//     Date: 7/5/2009
///////////////////////////////////////////////////////////////////////
typedef CEvStringInstanceT
<char, ULONG, LONG, 
 EvCharReader, EvCharWriter, 
 EvStringInstance, CEvString>
CEvStringInstanceExtends;

///////////////////////////////////////////////////////////////////////
//  Class: CEvStringInstance
//
// Author: $author$
//   Date: 5/17/2009
///////////////////////////////////////////////////////////////////////
class CEvStringInstance
: public CEvStringInstanceExtends
{
public:
    typedef CEvStringInstanceExtends CEvExtends;
    typedef CEvStringInstance CEvDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvStringInstance
    //
    //      Author: $author$
    //        Date: 5/17/2009
    ///////////////////////////////////////////////////////////////////////
    CEvStringInstance
    (const char* chars=0,
     LONG length=-1) 
    : CEvExtends(chars,length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 5/18/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis() 
    {
        EvError error = EV_ERROR_NONE;
        if (!GetIsStaticInstance()) delete this;
        return error;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvTCHARStringInstanceExtends
//
//   Author: $author$
//     Date: 5/16/2009
///////////////////////////////////////////////////////////////////////
typedef CEvStringInstanceT
<TCHAR, ULONG, LONG, 
 EvTCHARReader, EvTCHARWriter, 
 EvTCHARStringInstance, CEvTCHARString>
CEvTCHARStringInstanceExtends;

///////////////////////////////////////////////////////////////////////
//  Class: CEvTCHARStringInstance
//
// Author: $author$
//   Date: 5/18/2009
///////////////////////////////////////////////////////////////////////
class CEvTCHARStringInstance
: public CEvTCHARStringInstanceExtends
{
public:
    typedef CEvTCHARStringInstanceExtends CEvExtends;
    typedef CEvTCHARStringInstance CEvDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvTCHARStringInstance
    //
    //      Author: $author$
    //        Date: 5/18/2009
    ///////////////////////////////////////////////////////////////////////
    CEvTCHARStringInstance
    (const TCHAR* chars=0,
     LONG length=-1) 
    : CEvExtends(chars,length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 5/18/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis() 
    {
        EvError error = EV_ERROR_NONE;
        if (!GetIsStaticInstance()) delete this;
        return error;
    }
};

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvWCHARStringInstanceExtends
//
//   Author: $author$
//     Date: 5/16/2009
///////////////////////////////////////////////////////////////////////
typedef CEvStringInstanceT
<WCHAR, ULONG, LONG, 
 EvWCHARReader, EvWCHARWriter, 
 EvWCHARStringInstance, CEvWCHARString>
CEvWCHARStringInstanceExtends;

///////////////////////////////////////////////////////////////////////
//  Class: CEvWCHARStringInstance
//
// Author: $author$
//   Date: 5/18/2009
///////////////////////////////////////////////////////////////////////
class CEvWCHARStringInstance
: public CEvWCHARStringInstanceExtends
{
public:
    typedef CEvWCHARStringInstanceExtends CEvExtends;
    typedef CEvWCHARStringInstance CEvDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvWCHARStringInstance
    //
    //      Author: $author$
    //        Date: 5/18/2009
    ///////////////////////////////////////////////////////////////////////
    CEvWCHARStringInstance
    (const WCHAR* chars=0,
     LONG length=-1) 
    : CEvExtends(chars,length)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: DeleteThis
    //
    //   Author: $author$
    //     Date: 5/18/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError DeleteThis() 
    {
        EvError error = EV_ERROR_NONE;
        if (!GetIsStaticInstance()) delete this;
        return error;
    }
};

#endif // _CEVSTRINGINSTANCE_HPP
