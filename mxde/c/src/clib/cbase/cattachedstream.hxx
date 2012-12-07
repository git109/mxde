/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cattachedstream.hxx
 *
 * Author: $author$
 *   Date: 8/22/2009
 **********************************************************************
 */
#if !defined(_CATTACHEDSTREAM_HXX) || defined(CATTACHEDSTREAM_MEMBERS_ONLY)
#if !defined(_CATTACHEDSTREAM_HXX) && !defined(CATTACHEDSTREAM_MEMBERS_ONLY)
#define _CATTACHEDSTREAM_HXX
#endif /* !defined(_CATTACHEDSTREAM_HXX) && !defined(CATTACHEDSTREAM_MEMBERS_ONLY) */

#if !defined(CATTACHEDSTREAM_MEMBERS_ONLY)
#include "cstream.hxx"
#include "cattachedsequence.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cAttachedStream;
/**
 **********************************************************************
 * Typedef: cAttachedStreamExtends
 *
 *  Author: $author$
 *    Date: 8/22/2009
 **********************************************************************
 */
typedef cStreamT
<cAttachedStream,
 cStreamImplement,
 cStreamInterface,
 cReaderInterface,
 cWriterInterface,
 cAttachedSequence>
cAttachedStreamExtends;
/**
 **********************************************************************
 *  Class: cAttachedStream
 *
 * Author: $author$
 *   Date: 8/22/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cAttachedStream
: public cAttachedStreamExtends
{
public:
    typedef cAttachedStreamExtends cExtends;
    
    tLength m_length;
    tSize m_tell;
    
    /**
     **********************************************************************
     *  Constructor: cAttachedStream
     *
     *       Author: $author$
     *         Date: 8/22/2009
     **********************************************************************
     */
    cAttachedStream
    (const tWhat* attached=(const tWhat*)(vUnattached),
     tLength length=vUndefinedLength,
     tSize tell=0) 
    : m_length(length),
      m_tell(tell)
    {
        m_attached = attached;
    }
#else /* !defined(CATTACHEDSTREAM_MEMBERS_ONLY) */
#endif /* !defined(CATTACHEDSTREAM_MEMBERS_ONLY) */

#if !defined(CATTACHEDSTREAM_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 8/22/2009
     **********************************************************************
     */
    virtual tLength Read
    (tWhat* what,
     tSize size) 
    {
        tLength count = 0;
        tLength count2;
        for (; size; --size)
        {
            if (0 > (count2 = Get(*what)))
                return count2;
            else
            if (0 < (count2))
                count++;
            else
            break;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 8/22/2009
     **********************************************************************
     */
    virtual tLength Get
    (tWhat& what) 
    {
        tLength count = 0;
        tWhat attachedWhat;
        if (m_attached)
        if (0 > m_length)
        {
            if ((tWhat)(vEndWhat) != 
                (attachedWhat = m_attached[m_tell]))
            {
                what = attachedWhat;
                m_tell += (tSize)(count = 1);
            }
        }
        else
        if (m_tell < (tSize)(m_length))
        {
            what = m_attached[m_tell];
            m_tell += (tSize)(count = 1);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 8/22/2009
     **********************************************************************
     */
    virtual tAttachedTo Attach
    (tAttachedTo detached,
     tLength length=vUndefinedLength,
     bool onlyDetached=false) 
    {
        tAttachedTo attached = cExtends::Attach(detached, onlyDetached);
        m_length = length;
        m_tell = 0;
        return attached;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CATTACHEDSTREAM_MEMBERS_ONLY) */
#endif /* !defined(CATTACHEDSTREAM_MEMBERS_ONLY) */

#endif /* !defined(_CATTACHEDSTREAM_HXX) || defined(CATTACHEDSTREAM_MEMBERS_ONLY) */
