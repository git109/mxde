///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: XosString.hpp
///
/// Author: $author$
///   Date: 1/10/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSSTRING_HPP
#define _XOSSTRING_HPP

#include "XosPlatform.hpp"
#include <string>

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosStringExtend
///
///  Author: $author$
///    Date: 1/10/2012
///////////////////////////////////////////////////////////////////////
typedef std::string
XosStringExtend;

#undef CDB_CLASS
#define CDB_CLASS "XosStringT"
///////////////////////////////////////////////////////////////////////
///  Class: XosStringT
///
/// Author: $author$
///   Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
template
<class TChar=char,
 class TExtend=XosStringExtend>

class _EXPORT_CLASS XosStringT
: public TExtend
{
public:
    typedef TExtend Extends;
    typedef TChar tChar;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosStringT
    ///
    ///       Author: $author$
    ///         Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    XosStringT
    (const XosStringT& copy)
    : Extends(copy)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosStringT
    ///
    ///       Author: $author$
    ///         Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    XosStringT(int value)
    {
        append(value);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosStringT
    ///
    ///       Author: $author$
    ///         Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    XosStringT
    (const std::string& copy)
    {
        append(copy.c_str());
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosStringT
    ///
    ///       Author: $author$
    ///         Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    XosStringT
    (const tChar* chars=0,
     ssize_t length=-1)
    {
        if ((chars))
        append(chars, length);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosStringT
    ///
    ///      Author: $author$
    ///        Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosStringT()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: assign
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    void assign
    (const char* chars,
     ssize_t length = -1)
    {
        this->clear();
        append(chars, length);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: assign
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    void assign
    (const wchar_t* chars,
     ssize_t length = -1)
    {
        this->clear();
        append(chars, length);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: assign
    ///
    ///    Author: $author$
    ///      Date: 5/11/2012
    ///////////////////////////////////////////////////////////////////////
    void assign(int value)
    {
        this->clear();
        append(value);
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: append
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    void append
    (const char* chars,
     ssize_t length = -1)
    {
        tChar c;
        if ((chars))
        if (0 > (length))
        {
            while ((c = (tChar)(*chars++)))
                Extends::append(&c, 1);
        }
        else
        {
            for (; length; --length)
            {
                c = (tChar)(*chars++); 
                Extends::append(&c, 1);
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: append
    ///
    ///    Author: $author$
    ///      Date: 1/28/2012
    ///////////////////////////////////////////////////////////////////////
    void append
    (const wchar_t* chars,
     ssize_t length = -1)
    {
        tChar c;
        if ((chars))
        if (0 > (length))
        {
            while ((c = (tChar)(*chars++)))
                Extends::append(&c, 1);
        }
        else
        {
            for (; length; --length)
            {
                c = (tChar)(*chars++); 
                Extends::append(&c, 1);
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: append
    ///
    ///    Author: $author$
    ///      Date: 2/26/2012
    ///////////////////////////////////////////////////////////////////////
    void append(int value)
    {
        tChar c = ((tChar)('0'));
        tChar s = ((tChar)('-'));
        size_t digits;
        unsigned msdValue;

        if (0 == value)
            append(&c, 1);
        else
        {
            if (0 > value)
            {
                append(&s, 1);
                value = -value;
            }
            for (digits = 0, msdValue = 0; 
                 value; value /= 10, digits++)
                msdValue = (msdValue*10) + (value%10);
            for (; msdValue; msdValue /= 10, --digits)
            {
                tChar d = c + (tChar)(msdValue%10);
                append(&d, 1);
            }
            for (; digits; --digits)
                append(&c, 1);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: operator <<
    ///
    ///    Author: $author$
    ///      Date: 2/26/2012
    ///////////////////////////////////////////////////////////////////////
    XosStringT& operator << (const std::string& s)
    {
        append(s.c_str());
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: operator <<
    ///
    ///    Author: $author$
    ///      Date: 2/26/2012
    ///////////////////////////////////////////////////////////////////////
    XosStringT& operator << (int value)
    {
        append(value);
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: operator >>
    ///
    ///    Author: $author$
    ///      Date: 2/28/2012
    ///////////////////////////////////////////////////////////////////////
    int operator >> (int& value) const
    {
        value = this->to_int();
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: operator int
    ///
    ///    Author: $author$
    ///      Date: 2/28/2012
    ///////////////////////////////////////////////////////////////////////
    int to_int() const
    {
        bool negative = false;
        int value = 0;
        size_t digits, count, length;
        const tChar* chars;
        tChar c, d;

        if (((chars = this->c_str())) && (0 < (length = this->length())))
        for (digits = 0, count = 0; count < length; count++)
        {
            if (((c = chars[count]) >= '0') && (c <= '9'))
            {
                value = (value*10) + (d = (c - '0'));

                if (d || digits)
                    digits++;
            }
            else if ('-' == c)
                    negative = true;
        }
        if (negative)
            return -value;
        return value;
    }
};
#undef CDB_CLASS

///////////////////////////////////////////////////////////////////////
/// Typedef: XosString
///
///  Author: $author$
///    Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
typedef XosStringT<char,XosStringExtend>
XosString;

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWStringExtend
///
///  Author: $author$
///    Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
typedef std::basic_string<wchar_t>
XosWStringExtend;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWString
///
///  Author: $author$
///    Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
typedef XosStringT<wchar_t, XosWStringExtend>
XosWString;

///////////////////////////////////////////////////////////////////////
/// Typedef: XosTStringExtend
///
///  Author: $author$
///    Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
typedef std::basic_string<TCHAR>
XosTStringExtend;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosTString
///
///  Author: $author$
///    Date: 1/28/2012
///////////////////////////////////////////////////////////////////////
typedef XosStringT<TCHAR, XosTStringExtend>
XosTString;

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSSTRING_HPP 
