/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: csslcomrpessionmethod.hxx
 *
 * Author: $author$
 *   Date: 1/13/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSSLCOMRPESSIONMETHOD_HXX
#define _CSSLCOMRPESSIONMETHOD_HXX

#include <string.h>
#include "platform.h"
#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cSSLCompressionMethod
 *
 * Author: $author$
 *   Date: 1/13/2005
 **********************************************************************
 */
class cSSLCompressionMethod
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/13/2005
     **********************************************************************
     */
    enum
    {
        e_NONE = -1,
        e_FIRST,

        e_NULL = e_FIRST, 

        e_ALL,
        e_LAST = e_ALL-1
    };

protected:
    static const char *m_names[e_ALL];
    static const cSSLCompressionMethod m_methods[e_ALL];

    uint8 m_code;
    int m_method;

public:
    /**
     **********************************************************************
     * Constructor: cSSLCompressionMethod
     *
     *      Author: $author$
     *        Date: 1/14/2005
     **********************************************************************
     */
    cSSLCompressionMethod(int method=e_NONE) 
    {
        eError error;
        int size;

        if (0 > (size = Set(method)))
            throw(error = -size);
    }
    /**
     **********************************************************************
     * Constructor: cSSLCompressionMethod
     *
     *      Author: $author$
     *        Date: 1/14/2005
     **********************************************************************
     */
    cSSLCompressionMethod(uint8 code, int method)
    : m_code(code),
      m_method(method)
    {
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = sizeof(m_code);
        return size;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    int Copy(const cSSLCompressionMethod &method)
    {
        int size;
        
        if (&method == this)
            return size = Sizeof();

        size = Set(method.GetMethod());
        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    int Set(int method)
    {
        int size = Sizeof();

        m_code = GetCodeByMethod(m_method = method);
        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;

        if (0 <= (size = stream.Getb()))
        {
            m_method = GetMethodByCode(m_code = size);
            size = Sizeof();
        }
        else
        {
            m_code = -1;
            m_method = e_NONE;
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size;
        
        if (0 <= (size = stream.Putb(m_code)))
            size = Sizeof();
        return size;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    int operator != (cSSLCompressionMethod &method)
    {
        int unequal = 0;
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    inline const char* GetName() const
    {
        if ((m_method >= e_FIRST) && (m_method <= e_LAST))
            return m_names[m_method];
        return "NONE";
    }
    /**
     **********************************************************************
     * Function: GetCode
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    inline uint8 GetCode() const
    {
        return m_code;
    }
    /**
     **********************************************************************
     * Function: GetMethod
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    inline int GetMethod() const
    {
        return m_method;
    }

protected:
    /**
     **********************************************************************
     * Function: GetMethodByCode
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    static int GetMethodByCode(uint8 code);
    /**
     **********************************************************************
     * Function: GetCodeByMethod
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    static uint8 GetCodeByMethod(int method);
};

#endif /* _CSSLCOMRPESSIONMETHOD_HXX */
