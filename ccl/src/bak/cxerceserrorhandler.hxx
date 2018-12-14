/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: cxerceserrorhandler.hxx
 *
 * Author: $author$
 *   Date: 12/3/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXERCESERRORHANDLER_HXX
#define _CXERCESERRORHANDLER_HXX

#include <util/XMLString.hpp>
#include <sax/ErrorHandler.hpp>
#include <sax/SAXParseException.hpp>

#include "ccharbuffer.hxx"
#include "nsxerces.hxx"

/**
 **********************************************************************
 *  Class: cXercesErrorHandler
 *
 * Author: $author$
 *   Date: 12/3/2003
 **********************************************************************
 */
class cXercesErrorHandler
: public nsXerces::ErrorHandler
{
public:
    typedef nsXerces::ErrorHandler cIs;

    /**
     **********************************************************************
     *  Class: cException
     *
     * Author: $author$
     *   Date: 12/3/2003
     **********************************************************************
     */
    class cException
    {
    public:
        /**
         **********************************************************************
         *   Enum: eType
         *
         * Author: $author$
         *   Date: 12/3/2003
         **********************************************************************
         */
        enum eType
        {
            e_TYPE_WARNING,
            e_TYPE_ERROR,
            e_TYPE_FATAL_ERROR
        };

        eType m_type;
        nsXerces::SAXParseException m_parse_exception;

        /**
         **********************************************************************
         * Constructor: cException
         *
         *      Author: $author$
         *        Date: 12/3/2003
         **********************************************************************
         */
        cException
        (eType type, const nsXerces::SAXParseException &parse_exception)
        : m_type(type),
          m_parse_exception(parse_exception)
        {
        }

        /**
         **********************************************************************
         * Function: ToBuffer
         *
         *   Author: $author$
         *     Date: 12/11/2003
         **********************************************************************
         */
        virtual int ToBuffer(cCharBuffer &buffer) const
        {
            int count;
            const XMLCh *xmlch;
            char *ch;

            if ((xmlch = m_parse_exception.getMessage()))
            {
                count = 0;

                while (xmlch[count])
                    count++;

                if (count <= buffer.SetSize(count+1))
                if ((ch = buffer.GetWriteBuffer()))
                if (nsXerces::XMLString::transcode(xmlch, ch, count))
                    return count;
            }
            return 0;
        }
    };

    /**
     **********************************************************************
     * Constructor: cXercesErrorHandler
     *
     *      Author: $author$
     *        Date: 12/3/2003
     **********************************************************************
     */
    cXercesErrorHandler() 
    : ErrorHandler() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXercesErrorHandler
     *
     *     Author: $author$
     *       Date: 12/3/2003
     **********************************************************************
     */
    virtual ~cXercesErrorHandler()
    {
    }

    /**
     **********************************************************************
     * Function: warning
     *
     *   Author: $author$
     *     Date: 12/3/2003
     **********************************************************************
     */
    virtual void warning(const nsXerces::SAXParseException &exception)
    {
        cException cexception
        (cException::e_TYPE_WARNING, exception);
        throw(cexception);
    }
    /**
     **********************************************************************
     * Function: error
     *
     *   Author: $author$
     *     Date: 12/3/2003
     **********************************************************************
     */
    virtual void error(const nsXerces::SAXParseException &exception)
    {
        cException cexception
        (cException::e_TYPE_ERROR, exception);
        throw(cexception);
    }
    /**
     **********************************************************************
     * Function: fatalError
     *
     *   Author: $author$
     *     Date: 12/3/2003
     **********************************************************************
     */
    virtual void fatalError(const nsXerces::SAXParseException &exception)
    {
        cException cexception
        (cException::e_TYPE_FATAL_ERROR, exception);
        throw(cexception);
    }
    /**
     **********************************************************************
     * Function: resetErrors
     *
     *   Author: $author$
     *     Date: 12/3/2003
     **********************************************************************
     */
    virtual void resetErrors()
    {
    }
};

#endif /* ndef _CXERCESERRORHANDLER_HXX */
