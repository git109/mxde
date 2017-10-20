///////////////////////////////////////////////////////////////////////
//   File: evstringt.hpp
//
// Author: $author$
//   Date: 5/6/2009
///////////////////////////////////////////////////////////////////////

#ifndef _EVSTRINGT_HPP
#define _EVSTRINGT_HPP

#include "evbase.hpp"
#include "everror.h"

///////////////////////////////////////////////////////////////////////
//  Class: EvStringT
//
// Author: $author$
//   Date: 5/6/2009
///////////////////////////////////////////////////////////////////////
template
<class TChar=CHAR,
 class TSize=ULONG,
 class TLength=LONG,
 class TImplements=EvBase>

class EV_EXPORT_CLASS EvStringT
: virtual public TImplements
{
public:
    typedef TImplements CImplements;
    typedef EvStringT CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: Clear
    //
    //   Author: $author$
    //     Date: 5/6/2009
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Clear() = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: Assign
    //
    //   Author: $author$
    //     Date: 5/6/2009
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Assign
    (const TChar* chars,
     LONG length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: Append
    //
    //   Author: $author$
    //     Date: 5/6/2009
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Append
    (const TChar* chars,
     LONG length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: CaselessCompare
    //
    //   Author: $author$
    //     Date: 7/25/2009
    ///////////////////////////////////////////////////////////////////////
    virtual int CaselessCompare
    (const TChar* tochars, TLength tolength=-1) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: Compare
    //
    //   Author: $author$
    //     Date: 4/11/2009
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare
    (const TChar* tochars, TLength tolength=-1) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: HasChars
    //
    //   Author: $author$
    //     Date: 4/11/2009
    ///////////////////////////////////////////////////////////////////////
    virtual const TChar* HasChars(TLength &length) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: Chars
    //
    //   Author: $author$
    //     Date: 5/6/2009
    ///////////////////////////////////////////////////////////////////////
    virtual const TChar* Chars
    (LONG& length) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: Length
    //
    //   Author: $author$
    //     Date: 4/20/2009
    ///////////////////////////////////////////////////////////////////////
    virtual TLength Length() const = 0;
};
#endif // _EVSTRINGT_HPP