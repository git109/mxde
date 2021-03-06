///////////////////////////////////////////////////////////////////////
//   File: evfinalizer.hpp
//
// Author: $author$
//   Date: 5/25/2009
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVFINALIZER_HPP
#define _EVFINALIZER_HPP

#include "evbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvFinalizer
//
// Author: $author$
//   Date: 5/25/2009
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvFinalizer
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvFinalizer CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: Finalize
    //
    //   Author: $author$
    //     Date: 5/25/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Finalize() = 0;
};
#endif // _EVFINALIZER_HPP
