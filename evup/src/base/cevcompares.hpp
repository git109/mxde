///////////////////////////////////////////////////////////////////////
//   File: cevcompares.hpp
//
// Author: $author$
//   Date: 11/21/2009
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCOMPARES_HPP
#define _CEVCOMPARES_HPP

#include "evcompares.hpp"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvCompares
//
// Author: $author$
//   Date: 11/21/2009
///////////////////////////////////////////////////////////////////////
class CEvCompares
: virtual public EvCompares,
  public CEvBase
{
public:
    typedef EvCompares CImplements;
    typedef CEvBase CExtends;
    typedef CEvCompares CDerives;

    ComparesWhat m_compares;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvCompares
    //
    //       Author: $author$
    //         Date: 11/21/2009
    ///////////////////////////////////////////////////////////////////////
    CEvCompares
    (ComparesWhat compares=EV_COMPARES_FALSE)
    : m_compares(compares)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvCompares
    //
    //      Author: $author$
    //        Date: 11/21/2009
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvCompares()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Compares
    //
    //   Author: $author$
    //     Date: 6/30/2009
    ///////////////////////////////////////////////////////////////////////
    virtual bool Compares(int unequal) 
    {
        bool yes = false;

        switch(m_compares)
        {
        case EV_COMPARES_TRUE:
            yes = true;
            break;
        case EV_COMPARES_GT:
            yes = (0 < unequal);
            break;
        case EV_COMPARES_LT:
            yes = (0 > unequal);
            break;
        case EV_COMPARES_NE:
            yes = (0 != unequal);
            break;
        case EV_COMPARES_EQ:
            yes = (0 == unequal);
            break;
        case EV_COMPARES_GE:
            yes = (0 <= unequal);
            break;
        case EV_COMPARES_LE:
            yes = (0 >= unequal);
            break;
        }
        return yes;
    }
};
#endif // _CEVCOMPARES_HPP
