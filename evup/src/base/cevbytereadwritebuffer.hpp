///////////////////////////////////////////////////////////////////////
//   File: cevbytereadwritebuffer.hpp
//
// Author: $author$
//   Date: 12/4/2009
///////////////////////////////////////////////////////////////////////

#ifndef _CEVBYTEREADWRITEBUFFER_HPP
#define _CEVBYTEREADWRITEBUFFER_HPP

#include "cevreadwritebuffer.hpp"
#include "evbytereadwritebuffer.hpp"
#include "cevbytereadwritebase.hpp"

///////////////////////////////////////////////////////////////////////
//  Typedef: CEvBYTEReadWriteBuffer
//
//   Author: $author$
//     Date: 12/4/2009
///////////////////////////////////////////////////////////////////////
typedef CEvReadWriteBuffer
<BYTE, ULONG, DEFAULT_CEVREADWRITEBUFFER_SIZE, LONG, 
 EvBYTEReadWriteBuffer, CEvBYTEReadWriteBase>
CEvBYTEReadWriteBuffer;

#endif // _CEVBYTEREADWRITEBUFFER_HPP
