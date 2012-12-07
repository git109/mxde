/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: casn1length.hxx
 *
 * Author: $author$
 *   Date: 3/19/2010
 **********************************************************************
 */
#if !defined(_CASN1LENGTH_HXX) || defined(CASN1LENGTH_MEMBERS_ONLY)
#if !defined(_CASN1LENGTH_HXX) && !defined(CASN1LENGTH_MEMBERS_ONLY)
#define _CASN1LENGTH_HXX
#endif /* !defined(_CASN1LENGTH_HXX) && !defined(CASN1LENGTH_MEMBERS_ONLY) */

#if !defined(CASN1LENGTH_MEMBERS_ONLY)
#include "casn1base.hxx"
#include "creader.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cASN1Length
 *
 * Author: $author$
 *   Date: 3/19/2010
 **********************************************************************
 */
class c_ASN1_CLASS cASN1Length
: public cASN1Base
{
public:
    typedef cASN1Base cExtends;

    bool m_isIndefinite;
    TSIZE m_value;
    BYTE m_size;

    /**
     **********************************************************************
     *  Constructor: cASN1Length
     *
     *       Author: $author$
     *         Date: 3/19/2010
     **********************************************************************
     */
    cASN1Length
    (TSIZE value = 0, 
     BYTE size = 1, 
     bool isIndefinite = false)
    : m_value(value), 
      m_size(size), 
      m_isIndefinite(isIndefinite)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cASN1Length
     *
     *       Author: $author$
     *         Date: 3/19/2010
     **********************************************************************
     */
    cASN1Length
    (const cASN1Length& length)
    {
        eError error;
        TLENGTH count;
        if (0 > (count = Copy(length)))
            throw(error = -count);
    }
#else /* !defined(CASN1LENGTH_MEMBERS_ONLY) */
#endif /* !defined(CASN1LENGTH_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Read
     *
     *    Author: $author$
     *      Date: 3/21/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (cBYTEReaderInterface& reader)
#if defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = 0;
        TLENGTH count2;
        BYTE bytes;
        BYTE byte;

        if (0 < (count = reader.Read(&byte, 1)))
        {
            m_isIndefinite = false;
            m_size = 1;

            if (byte < 128)
                m_value = byte;
            else
            {
                m_value = 0;

                if (byte > 128)
                {
                    for (bytes = (byte & 127); 
                         (bytes > 0); --bytes, m_size++, count++)
                    {
                        if  (0 > (count2 = reader.Read(&byte, 1)))
                            return count2;

                        m_value = (m_value << 8) | byte;
                    }
                }
                else 
                m_isIndefinite = true;
            }
        }
#else /* !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Copy
     *
     *    Author: $author$
     *      Date: 3/21/2010
     **********************************************************************
     */
    virtual TLENGTH Copy
    (const cASN1Length& length)
#if defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH value = (TLENGTH)(m_value = length.Value());
        m_size = length.Size();
        m_isIndefinite = length.IsIndefinite();
#else /* !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Value
     *
     *    Author: $author$
     *      Date: 3/21/2010
     **********************************************************************
     */
    virtual TSIZE Value() const
#if defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT)
        TSIZE value = (m_value);
#else /* !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT) */
        TSIZE value = 0;
#endif /* !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Size
     *
     *    Author: $author$
     *      Date: 3/21/2010
     **********************************************************************
     */
    virtual BYTE Size() const
#if defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT)
        BYTE value = (m_size);
#else /* !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT) */
        BYTE value = 0;
#endif /* !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: IsIndefinite
     *
     *    Author: $author$
     *      Date: 3/21/2010
     **********************************************************************
     */
    virtual bool IsIndefinite() const
#if defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT)
        bool isTrue = (m_isIndefinite);
#else /* !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT) */
        bool isTrue = (false);
#endif /* !defined(CASN1LENGTH_MEMBER_FUNCS_IMPLEMENT) */
        return isTrue;
    }
#endif /* defined(CASN1LENGTH_MEMBER_FUNCS_INTERFACE) */

#if !defined(CASN1LENGTH_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CASN1LENGTH_MEMBERS_ONLY) */
#endif /* !defined(CASN1LENGTH_MEMBERS_ONLY) */

#endif /* !defined(_CASN1LENGTH_HXX) || defined(CASN1LENGTH_MEMBERS_ONLY) */
