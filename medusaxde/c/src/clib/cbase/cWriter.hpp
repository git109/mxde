///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cWriter.hpp
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CWRITER_HPP) || defined(CWRITERT_MEMBERS_ONLY)
#if !defined(_CWRITER_HPP) && !defined(CWRITERT_MEMBERS_ONLY)
#define _CWRITER_HPP
#endif // !defined(_CWRITER_HPP) && !defined(CWRITERT_MEMBERS_ONLY) 

#if !defined(CWRITERT_MEMBERS_ONLY)
#include "cWriterInterface.hpp"
#include "cInstanceBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#undef CDB_CLASS
#define CDB_CLASS "cWriterT"
///////////////////////////////////////////////////////////////////////
//  Class: cWriterT
//
// Author: $author$
//   Date: 5/15/2011
///////////////////////////////////////////////////////////////////////
template
<class TWriterImplement=cWriterImplement,
 class TWriterInterface=cWriterInterface,
 class TWhat=char,
 class TExtend=cInstanceBase>

class c_INSTANCE_CLASS cWriterT
: virtual public TWriterImplement,
  public TExtend
{
public:
    typedef TWriterImplement cImplements;
    typedef TExtend cExtends;

// include cWriterT interface member definitions
//
#define CWRITERINTERFACET_MEMBERS_ONLY
#include "cWriterInterface.hpp"
#undef CWRITERINTERFACET_MEMBERS_ONLY

    tWriterInterface* m_delegated;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWriterT
    //
    //       Author: $author$
    //         Date: 5/15/2011
    ///////////////////////////////////////////////////////////////////////
    cWriterT
    (tWriterInterface* delegatedTo=0)
    : m_delegated(delegatedTo)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cWriterT
    //
    //      Author: $author$
    //        Date: 5/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWriterT()
    {
    }
#else // !defined(CWRITERT_MEMBERS_ONLY) 
#endif // !defined(CWRITERT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Write
    //
    //    Author: $author$
    //      Date: 5/15/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write
    (const tWhat* what,
     ssize_t length=-1)
#if defined(CWRITERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWRITERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT)
        if ((m_delegated) && ((tWriterInterface*)(this) != m_delegated))
            count = m_delegated->Write(what, length);
#else // !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CWRITERT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: WriteL
    //
    //    Author: $author$
    //      Date: 5/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteL
    (const tWhat* what,
     ...)
#if defined(CWRITERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWRITERT_MEMBER_FUNCS_INTERFACE)
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, what);
        count = WriteV(what, va);
        va_end(va);
#else // !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT)
#endif // !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT)
        return count;
    }
#endif // defined(CWRITERT_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    //  Function: WriteV
    //
    //    Author: $author$
    //      Date: 5/30/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteV
    (const tWhat* what,
     va_list va)
#if defined(CWRITERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWRITERT_MEMBER_FUNCS_INTERFACE)
    {
        ssize_t count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT)
        ssize_t length = 0;
        for (count = 0; what; count += length)
        {
            if (0 > (length = Write(what)))
                return length;
            what = va_arg(va, const tWhat*);
        }
#else // !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT)
#endif // !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT)
        return count;
    }
#endif // defined(CWRITERT_MEMBER_FUNCS_INTERFACE)

    ///////////////////////////////////////////////////////////////////////
    //  Function: Flush
    //
    //    Author: $author$
    //      Date: 7/6/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Flush()
#if defined(CWRITERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWRITERT_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(CWRITERT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: DelegateWrite
    //
    //    Author: $author$
    //      Date: 10/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tWriterInterface* DelegateWrite
    (tWriterInterface* toWriter)
#if defined(CWRITERT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWRITERT_MEMBER_FUNCS_INTERFACE) 
    {
        tWriterInterface* oldWriter = 0;
#if !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT)
        oldWriter = m_delegated;
        m_delegated = toWriter;
#else // !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWRITERT_MEMBER_FUNCS_IMPLEMENT) 
        return oldWriter;
    }
#endif // defined(CWRITERT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CWRITERT_MEMBERS_ONLY)
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
// Typedef: cWriterExtend
//
//  Author: $author$
//    Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
typedef cWriterT
<cWriterImplement,cWriterInterface,char>
cWriterExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWriter
//
// Author: $author$
//   Date: 5/22/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWriter
: public cWriterExtend
{
public:
    typedef cWriterExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWriter
    //
    //       Author: $author$
    //         Date: 5/22/2011
    ///////////////////////////////////////////////////////////////////////
    cWriter(tWriterInterface* delegatedTo=0)
    : cExtends(delegatedTo)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWRITERT_MEMBERS_ONLY) 
#endif // !defined(CWRITERT_MEMBERS_ONLY) 

#endif // !defined(_CWRITER_HPP) || defined(CWRITERT_MEMBERS_ONLY) 
        

