///////////////////////////////////////////////////////////////////////
//   File: evmainarg.hpp
//
// Author: $author$
//   Date: 4/4/2009
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVMAINARG_HPP
#define _EVMAINARG_HPP

#include "everror.h"
#include "evbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvMainArg
//
// Author: $author$
//   Date: 4/4/2009
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvMainArg
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvMainArg CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 4/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: CompareShortName
    //
    //   Author: $author$
    //     Date: 4/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareShortName
    (const char* tochars,
     int length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: CompareLongName
    //
    //   Author: $author$
    //     Date: 4/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareLongName
    (const char* tochars,
     int length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: SetShortNamei
    //
    //    Author: $author$
    //      Date: 4/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetShortNamei
    (const char* chars,
     int length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetShortNamei
    //
    //    Author: $author$
    //      Date: 4/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetShortNamei
    (int &length) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: SetShortName
    //
    //    Author: $author$
    //      Date: 4/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetShortName
    (const char* chars,
     LONG length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetShortName
    //
    //    Author: $author$
    //      Date: 4/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetShortName
    (LONG &length) const = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: SetLongNamei
    //
    //    Author: $author$
    //      Date: 4/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetLongNamei
    (const char* chars,
     int length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetLongNamei
    //
    //    Author: $author$
    //      Date: 4/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetLongNamei
    (int &length) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: SetLongName
    //
    //    Author: $author$
    //      Date: 4/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetLongName
    (const char* chars,
     LONG length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetLongName
    //
    //    Author: $author$
    //      Date: 4/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetLongName
    (LONG &length) const = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: SetParameters
    //
    //   Author: $author$
    //     Date: 4/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetParameters
    (const char* chars,
     int length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetParameters
    //
    //   Author: $author$
    //     Date: 4/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetParameters
    (int &length) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFirstParameter
    //
    //   Author: $author$
    //     Date: 5/10/2009
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFirstParameter
    (const char*& nextParameter, int &length) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextParameter
    //
    //   Author: $author$
    //     Date: 5/10/2009
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetNextParameter
    (const char*& nextParameter, int &length) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetParameterName
    //
    //   Author: $author$
    //     Date: 5/10/2009
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetParameterName
    (const char* parameter, int &length) const = 0;
};
#endif // _EVMAINARG_HPP
