///////////////////////////////////////////////////////////////////////
//   File: evdatetime.hpp
//
// Author: $author$
//   Date: 6/21/2009
///////////////////////////////////////////////////////////////////////

#ifndef _EVDATETIME_HPP
#define _EVDATETIME_HPP

#include "evtime.hpp"
#include "evdate.hpp"
#include "evtimezone.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvDateTime
//
// Author: $author$
//   Date: 6/21/2009
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvDateTime
: virtual public EvTime,
  virtual public EvDate
{
public:
    typedef EvDate CImplements;
    typedef EvDateTime CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: CompareDateTime
    //
    //   Author: $author$
    //     Date: 6/27/2009
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareDateTime
    (const EvDateTime& dateTime,
     bool isLocal=false,
     const EvTimezone* timezone=0,
     bool is12=false,
     bool isPM=false) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: SetDateTime
    //
    //   Author: $author$
    //     Date: 6/21/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetDateTime
    (const EvDateTime& dateTime,
     bool isLocal=false,
     const EvTimezone* timezone=0,
     bool is12=false,
     bool isPM=false) = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: CreateInstance
    //
    //   Author: $author$
    //     Date: 5/14/2009
    ///////////////////////////////////////////////////////////////////////
    static EvDateTime* CreateInstance
    (EvError& error);
    ///////////////////////////////////////////////////////////////////////
    // Function: DestroyInstance
    //
    //   Author: $author$
    //     Date: 5/14/2009
    ///////////////////////////////////////////////////////////////////////
    static EvError DestroyInstance
    (EvDateTime& instance);
};
#endif // _EVDATETIME_HPP
