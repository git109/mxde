/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: csslcompressionmethods.hxx
 *
 * Author: $author$
 *   Date: 10/15/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CSSLCOMPRESSIONMETHODS_HXX
#define _CSSLCOMPRESSIONMETHODS_HXX

#include "csslcompressionmethod.hxx"

/**
 **********************************************************************
 *  Class: cSSLCompressionMethods
 *
 * Author: $author$
 *   Date: 1/14/2005
 **********************************************************************
 */
class cSSLCompressionMethods
{
protected:
    uint8 m_sizeof;
    uint8 m_methods;
    uint8 m_method_sizeof;
    cSSLCompressionMethod m_method[cSSLCompressionMethod::e_ALL];

public:
    /**
     **********************************************************************
     * Constructor: cSSLCompressionMethods
     *
     *      Author: $author$
     *        Date: 1/14/2005
     **********************************************************************
     */
    cSSLCompressionMethods
    (const cSSLCompressionMethod *method=0, int methods=-1) 
    : m_methods(0),
      m_sizeof(0)
    {
        eError error;
        int size;

        m_method_sizeof = m_method[0].Sizeof();

        if (method)
        if (0 > (size = Set(method, methods)))
            throw(error = -size);
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
        int size = sizeof(m_sizeof)+(m_methods*m_method_sizeof);
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
    int Copy(const cSSLCompressionMethods &methods)
    {
        int size;
        
        if (&methods == this)
            return size = Sizeof();

        size = Set(methods.GetMethod(), methods.GetMethods());
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
    int Set(const cSSLCompressionMethod *method=0, int methods=-1)
    {
        int i,size;

        for (i=0; i<methods; i++)
            if (0 > (size = m_method[i].Copy(method[i])))
                return size;

        m_sizeof = methods*m_method_sizeof;
        m_methods = methods;
        return size = Sizeof();
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
        int i,size,size_of,methods;

        if (0 <= (size = stream.Getb()))
        {
            if (size % m_method_sizeof)
                return -e_ERROR_INVALID_RETURN_SIZE;

            if (cSSLCompressionMethod::e_ALL
                < (methods = size/m_method_sizeof))
                return -e_ERROR_RETURN_SIZE_OVER;

            for (size_of=size, i=0; i<methods; i++)
                if (0 > (size = m_method[i].Read(stream)))
                    return size;

            m_methods = methods;
            m_sizeof = size_of;
            size = Sizeof();
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
        int i,size;

        if (0 <= (size = stream.Putb(m_sizeof)))
        {
            for (i=0; i<m_methods; i++)
                if (0 > (size = m_method[i].Write(stream)))
                    return size;

            size = Sizeof();
        }
        return size;
    }
    /**
     **********************************************************************
     * Function: GetMethods
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    inline uint8 GetMethods() const
    {
        return m_methods;
    }
    /**
     **********************************************************************
     * Function: GetMethod
     *
     *   Author: $author$
     *     Date: 1/14/2005
     **********************************************************************
     */
    inline const cSSLCompressionMethod* GetMethod() const
    {
        return m_method;
    }
};

#endif /* _CSSLCOMPRESSIONMETHODS_HXX */
