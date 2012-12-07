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
 *   File: csplitter.hxx
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
#if !defined(_CSPLITTER_HXX) || defined(CSPLITTER_MEMBERS_ONLY)
#if !defined(_CSPLITTER_HXX) && !defined(CSPLITTER_MEMBERS_ONLY)
#define _CSPLITTER_HXX
#endif /* !defined(_CSPLITTER_HXX) && !defined(CSPLITTER_MEMBERS_ONLY) */

#if !defined(CSPLITTER_MEMBERS_ONLY) 
#include "ccounter.hxx"

#if !defined(CSPLITTER_INTERFACE_CLASS) 
#define CSPLITTER_INTERFACE_CLASS 
#endif /* !defined(CSPLITTER_INTERFACE_CLASS) */

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class CSPLITTER_INTERFACE_CLASS cSplitter;

#undef CDB_CLASS
#define CDB_CLASS "cSplitterT"
/**
 **********************************************************************
 *  Class: cSplitterT
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
template
<class TDerives=cSplitter,
 class TCounter=cCounter,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TExtends=TCounter>
 
class CSPLITTER_INTERFACE_CLASS cSplitterT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

/* include cSequence interface member definitions
 */
#define CSEQUENCEINTERFACE_MEMBERS_ONLY
#include "csequenceinterface.hxx"
#undef CSEQUENCEINTERFACE_MEMBERS_ONLY

#else /* !defined(CSPLITTER_MEMBERS_ONLY) */
#endif /* !defined(CSPLITTER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: LeftOf
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual const tWhat* LeftOf
    (tLength& count,
     tWhat what,
     const tWhat* inWhat,
     tLength length=vUndefinedLength) const 
    {
        const tWhat* part = 0;
        tLength tell;

        count = 0;

        if (0 > length)
        if (0 >= (length = LengthOf(inWhat)))
            return part;

        for (tell=0; tell<length; tell++)
        {
            if (what != inWhat[tell])
                continue;
            part = inWhat;
            count = tell;
            break;
        }
        return part;
    }
    /**
     **********************************************************************
     * Function: RightOf
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual const tWhat* RightOf
    (tLength& count,
     tWhat what,
     const tWhat* inWhat,
     tLength length=vUndefinedLength) const 
    {
        const tWhat* part = 0;
        tLength tell;

        count = 0;

        if (0 > length)
        if (0 >= (length = LengthOf(inWhat)))
            return part;

        for (tell=length; 0<tell; --tell)
        {
            if (what != inWhat[tell-1])
                continue;
            part = inWhat+tell;
            count = length-tell;
            break;
        }
        return part;
    }

#if !defined(CSPLITTER_MEMBERS_ONLY) 
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cSplitter
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
class CSPLITTER_INTERFACE_CLASS cSplitter
: public cSplitterT<cSplitter,cCounter,CHAR>
{
};

/**
 **********************************************************************
 *  Class: cTCHARSplitter
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
typedef
class CSPLITTER_INTERFACE_CLASS cTCHARSplitter
: public cSplitterT<cTCHARSplitter,cTCHARCounter,TCHAR>
{
} cTSplitter;

/**
 **********************************************************************
 *  Class: cWCHARSplitter
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
typedef
class CSPLITTER_INTERFACE_CLASS cWCHARSplitter
: public cSplitterT<cWCHARSplitter,cWCHARCounter,WCHAR>
{
} cWSpiltter;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSPLITTER_MEMBERS_ONLY) */
#endif /* !defined(CSPLITTER_MEMBERS_ONLY) */

#endif /* !defined(_CSPLITTER_HXX) || defined(CSPLITTER_MEMBERS_ONLY) */
