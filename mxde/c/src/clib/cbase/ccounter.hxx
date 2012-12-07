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
 *   File: ccounter.hxx
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
#if !defined(_CCOUNTER_HXX) || defined(CCOUNTER_MEMBERS_ONLY)
#if !defined(_CCOUNTER_HXX) && !defined(CCOUNTER_MEMBERS_ONLY)
#define _CCOUNTER_HXX
#endif /* !defined(_CCOUNTER_HXX) && !defined(CCOUNTER_MEMBERS_ONLY) */

#if !defined(CCOUNTER_MEMBERS_ONLY)
/* cCounter definition
 */
#include "cbase.hxx"

#if !defined(CCOUNTER_INTERFACE_CLASS) 
#define CCOUNTER_INTERFACE_CLASS 
#endif /* !defined(CCOUNTER_INTERFACE_CLASS) */

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class CCOUNTER_INTERFACE_CLASS cCounter;

#undef CDB_CLASS
#define CDB_CLASS "cCounterT"
/**
 **********************************************************************
 *  Class: cCounterT
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
template
<class TDerives=cCounter,
 class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TBase=cBase,
 class TExtends=TBase>
 
class CCOUNTER_INTERFACE_CLASS cCounterT
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

#else /* !defined(CCOUNTER_MEMBERS_ONLY) */
#endif /* !defined(CCOUNTER_MEMBERS_ONLY) */

#if !defined(CCOUNTER_MEMBERS_ONLY) 
    /**
     **********************************************************************
     * Function: LengthOf
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual tLength LengthOf
    (const tWhat* what,
     tLength length=vUndefinedLength) const
    {
        tLength count = 0;
        if (what)
        while ((*what++) != vEndWhat)
            count++;
        return count;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cCounter
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
class CCOUNTER_INTERFACE_CLASS cCounter
: public cCounterT<cCounter>
{
};

/**
 **********************************************************************
 *  Class: cTCHARCounter
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
typedef
class CCOUNTER_INTERFACE_CLASS cTCHARCounter
: public cCounterT<cTCHARCounter,TCHAR>
{
} cTCounter;

/**
 **********************************************************************
 *  Class: cWCHARCounter
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
typedef
class CCOUNTER_INTERFACE_CLASS cWCHARCounter
: public cCounterT<cWCHARCounter,WCHAR>
{
} cWCounter;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCOUNTER_MEMBERS_ONLY) */
#endif /* !defined(CCOUNTER_MEMBERS_ONLY) */

#endif /* !defined(_CCOUNTER_HXX) || defined(CCOUNTER_MEMBERS_ONLY) */
