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
 *   File: csizedreader.hxx
 *
 * Author: $author$
 *   Date: 3/25/2010
 **********************************************************************
 */
#if !defined(_CSIZEDREADER_HXX) || defined(CSIZEDREADER_MEMBERS_ONLY)
#if !defined(_CSIZEDREADER_HXX) && !defined(CSIZEDREADER_MEMBERS_ONLY)
#define _CSIZEDREADER_HXX
#endif /* !defined(_CSIZEDREADER_HXX) && !defined(CSIZEDREADER_MEMBERS_ONLY) */

#if !defined(CSIZEDREADER_MEMBERS_ONLY)
#include "creader.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#undef CDB_CLASS
#define CDB_CLASS "cSizedReaderT"
/**
 **********************************************************************
 *  Class: cSizedReaderT
 *
 * Author: $author$
 *   Date: 3/25/2010
 **********************************************************************
 */
template
<class TReader=cReader,
 class TReaderInterface=cReaderInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TExtends=TReader>

class c_INSTANCE_CLASS cSizedReaderT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TReaderInterface tReaderInterface;

/* include cReader interface member definitions
 */
#define CREADERINTERFACE_MEMBERS_ONLY
#include "creaderinterface.hxx"
#undef CREADERINTERFACE_MEMBERS_ONLY

    tReaderInterface& m_reader;
    tSize m_size, m_tell;

    /**
     **********************************************************************
     *  Constructor: cSizedReaderT
     *
     *       Author: $author$
     *         Date: 3/25/2010
     **********************************************************************
     */
    cSizedReaderT
    (tReaderInterface& reader, tSize size)
    : m_reader(reader),
      m_size(size),
      m_tell(0)
    {
    }
#else /* !defined(CSIZEDREADER_MEMBERS_ONLY) */
#endif /* !defined(CSIZEDREADER_MEMBERS_ONLY) */

#if !defined(CSIZEDREADER_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 3/25/2010
     **********************************************************************
     */
    virtual tLength Read
    (tWhat* what,
     tSize size)
    {
        tLength count = 0;

        if (m_size < (m_tell+size))
            size = (m_size-m_tell);

        if (m_size)
        if (0 < (count = m_reader.Read(what, size)))
            m_tell += count;

        return count;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cSizedBYTEReader
 *
 *  Author: $author$
 *    Date: 3/25/2010
 **********************************************************************
 */
typedef cSizedReaderT
<cBYTEReader, cBYTEReaderInterface, BYTE>
cSizedBYTEReader;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSIZEDREADER_MEMBERS_ONLY) */
#endif /* !defined(CSIZEDREADER_MEMBERS_ONLY) */

#endif /* !defined(_CSIZEDREADER_HXX) || defined(CSIZEDREADER_MEMBERS_ONLY) */
