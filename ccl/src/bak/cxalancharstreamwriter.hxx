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
 *   File: cxalancharstreamwriter.hxx
 *
 * Author: $author$
 *   Date: 11/18/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXALANCHARSTREAMWRITER_HXX
#define _CXALANCHARSTREAMWRITER_HXX

#include <PlatformSupport/Writer.hpp>

#include "cxalancharstreamoutputstream.hxx"
#include "ccharstreaminterface.hxx"
#include "nsxalan.hxx"

/**
 **********************************************************************
 *  Class: cXalanCharStreamWriter
 *
 * Author: $author$
 *   Date: 11/18/2003
 **********************************************************************
 */
class cXalanCharStreamWriter
: public nsXalan::Writer
{
public:
    typedef nsXalan::Writer cIs;

    cCharStreamInterface &m_stream;
    cXalanCharStreamOutputStream m_output_stream;
    nsXalan::CharVectorType m_char_vector;

    /**
     **********************************************************************
     * Constructor: cXalanCharStreamWriter
     *
     *      Author: $author$
     *        Date: 11/18/2003
     **********************************************************************
     */
    cXalanCharStreamWriter(cCharStreamInterface &stream) 
    : m_stream(stream) ,
      m_output_stream(stream)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXalanCharStreamWriter
     *
     *     Author: $author$
     *       Date: 11/18/2003
     **********************************************************************
     */
    virtual ~cXalanCharStreamWriter()
    {
    }

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 11/18/2003
     **********************************************************************
     */
    virtual nsXalan::XalanOutputStream *getStream() 
    {
        return &m_output_stream;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 11/18/2003
     **********************************************************************
     */
    virtual const nsXalan::XalanOutputStream *getStream() const 
    {
        return &m_output_stream;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 11/18/2003
     **********************************************************************
     */
    virtual void close() {}
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 11/18/2003
     **********************************************************************
     */
    virtual void flush()
    {
        m_stream.Flush();
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 11/18/2003
     **********************************************************************
     */
	virtual void write
    (const char*	s,
	 unsigned int	theOffset = 0,
	 unsigned int	theLength = UINT_MAX)
    {
        char c;

        if (UINT_MAX == theLength)
            theLength=strlen(s);

        for (s+=theOffset; theLength; --theLength)
            if ((c=*s)!='\r')
                m_stream.Putc(c);
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 11/18/2003
     **********************************************************************
     */
	virtual void write(nsXalan::XalanDOMChar	c)
    {
        if (c!='\r')
            m_stream.Putc(c);
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 11/18/2003
     **********************************************************************
     */
	virtual void write
    (const nsXalan::XalanDOMChar*	s,
	 unsigned int			theOffset = 0,
	 unsigned int			theLength = UINT_MAX)
    {
        if (UINT_MAX == theLength)
            theLength=XalanDOMCharLength(s);

        m_char_vector.clear();
        nsXalan::TranscodeToLocalCodePage(s+theOffset,theLength,m_char_vector);
        CharVectorTypeToStream(m_stream,m_char_vector);
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 11/18/2003
     **********************************************************************
     */
	virtual void write
    (const nsXalan::XalanDOMString&		s,
	 unsigned int				theOffset = 0,
	 unsigned int				theLength = UINT_MAX)
    {
        m_char_vector.clear();
        nsXalan::TranscodeToLocalCodePage(s.c_str()+theOffset,m_char_vector);
        CharVectorTypeToStream(m_stream,m_char_vector);
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 11/18/2003
     **********************************************************************
     */
    unsigned int XalanDOMCharLength(const nsXalan::XalanDOMChar *s)
    {
        unsigned int length;

        for (length=0; s[length]; length++);
        return length;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 11/18/2003
     **********************************************************************
     */
    eError CharVectorTypeToStream
    (cCharStreamInterface &stream, nsXalan::CharVectorType &char_vector)
    {
        nsXalan::CharVectorType::const_iterator cvi;
        int result;
        char c;

        for (cvi = char_vector.begin(); cvi != char_vector.end(); cvi++)
        {
            if ((c=*cvi)!='\r')
            if (0 > (result = stream.Putc(c)))
                return -result;
        }
        return e_ERROR_NONE;
    }
};

#endif
