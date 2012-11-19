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
//   File: cXsltProcessorImplemented.hpp
//
// Author: $author$
//   Date: 7/24/2011
///////////////////////////////////////////////////////////////////////
#ifndef _CXSLTPROCESSORIMPLEMENTED_HPP
#define _CXSLTPROCESSORIMPLEMENTED_HPP

#include "cXsltProcessor.hpp"

#if !defined(CXSLTPROCESSORIMPLEMENTED_EXTEND) 
#define CXSLTPROCESSORIMPLEMENTED_EXTEND cXsltProcessor
#else // !defined(CXSLTPROCESSORIMPLEMENTED_EXTEND) 
#endif // !defined(CXSLTPROCESSORIMPLEMENTED_EXTEND) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cXsltProcessorImplementedExtend
//
//  Author: $author$
//    Date: 7/24/2011
///////////////////////////////////////////////////////////////////////
typedef CXSLTPROCESSORIMPLEMENTED_EXTEND
cXsltProcessorImplementedExtend;

///////////////////////////////////////////////////////////////////////
//  Class: cXsltProcessorImplemented
//
// Author: $author$
//   Date: 7/24/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cXsltProcessorImplemented
: public cXsltProcessorImplementedExtend
{
public:
    typedef cXsltProcessorImplementedExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cXsltProcessorImplemented
    //
    //       Author: $author$
    //         Date: 7/24/2011
    ///////////////////////////////////////////////////////////////////////
    cXsltProcessorImplemented()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cXsltProcessorImplemented
    //
    //      Author: $author$
    //        Date: 7/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cXsltProcessorImplemented()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Implemented
    //
    //    Author: $author$
    //      Date: 7/24/2011
    ///////////////////////////////////////////////////////////////////////
    virtual cXsltProcessorImplemented& Implemented() const
    {
        return (cXsltProcessorImplemented&)(*this);
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CXSLTPROCESSORIMPLEMENTED_HPP 
        

