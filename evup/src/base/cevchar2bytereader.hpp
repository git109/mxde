///////////////////////////////////////////////////////////////////////
//   File: cevchar2bytereader.hpp
//
// Author: $author$
//   Date: 12/7/2009
///////////////////////////////////////////////////////////////////////

#ifndef _CEVCHAR2BYTEREADER_HPP
#define _CEVCHAR2BYTEREADER_HPP

#include "cevbytereader.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvChar2BYTEReader
//
// Author: $author$
//   Date: 12/7/2009
///////////////////////////////////////////////////////////////////////
class CEvChar2BYTEReader
: public CEvBYTEReader
{
public:
    typedef CEvBYTEReader CExtends;
    typedef CEvChar2BYTEReader CDerives;

    EvCharReader& m_reader;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvChar2BYTEReader
    //
    //       Author: $author$
    //         Date: 12/7/2009
    ///////////////////////////////////////////////////////////////////////
    CEvChar2BYTEReader
    (EvCharReader& reader) 
    : m_reader(reader)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Read
    //
    //   Author: $author$
    //     Date: 12/7/2009
    ///////////////////////////////////////////////////////////////////////
    virtual LONG Read
    (BYTE* chars, ULONG size) 
    {
        LONG count = m_reader.Read((char*)(chars), size);
        return count;
    }
};
#endif // _CEVCHAR2BYTEREADER_HPP
