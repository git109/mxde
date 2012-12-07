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
 *   File: cattachedsequence.hxx
 *
 * Author: $author$
 *   Date: 8/22/2009
 **********************************************************************
 */
#if !defined(_CATTACHEDSEQUENCE_HXX) || defined(CATTACHEDSEQUENCE_MEMBERS_ONLY)
#if !defined(_CATTACHEDSEQUENCE_HXX) && !defined(CATTACHEDSEQUENCE_MEMBERS_ONLY)
#define _CATTACHEDSEQUENCE_HXX
#endif /* !defined(_CATTACHEDSEQUENCE_HXX) && !defined(CATTACHEDSEQUENCE_MEMBERS_ONLY) */

#if !defined(CATTACHEDSEQUENCE_MEMBERS_ONLY)
#include "cattached.hxx"
#include "csequence.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cAttachedSequenceInterface;
/**
 **********************************************************************
 * Typedef: cAttachedSequenceInterfaceImplements
 *
 *  Author: $author$
 *    Date: 8/22/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cAttachedSequenceInterface, 
 PCCHAR, UINT, NULL, cSequenceInterface>
cAttachedSequenceInterfaceImplements;
/**
 **********************************************************************
 *  Class: cAttachedSequenceInterface
 *
 * Author: $author$
 *   Date: 8/22/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cAttachedSequenceInterface
: virtual public cAttachedSequenceInterfaceImplements
{
public:
    typedef cAttachedSequenceInterfaceImplements cImplements;
    typedef cAttachedSequenceInterface cDerives;
};
class c_IMPLEMENT_CLASS cAttachedSequenceImplement;
/**
 **********************************************************************
 * Typedef: cAttachedSequenceImplementImplements
 *
 *  Author: $author$
 *    Date: 8/22/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cAttachedSequenceImplement, 
 cAttachedSequenceInterface, 
 PCCHAR, UINT, NULL>
cAttachedSequenceImplementImplements;
/**
 **********************************************************************
 *  Class: cAttachedSequenceImplement
 *
 * Author: $author$
 *   Date: 8/22/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cAttachedSequenceImplement
: virtual public cAttachedSequenceImplementImplements
{
public:
    typedef cAttachedSequenceImplementImplements cImplements;
    typedef cAttachedSequenceImplement cDerives;
};
class c_INSTANCE_CLASS cAttachedSequence;
/**
 **********************************************************************
 * Typedef: cAttachedSequenceExtends
 *
 *  Author: $author$
 *    Date: 8/22/2009
 **********************************************************************
 */
typedef cAttachedT
<cAttachedSequence, 
 cAttachedSequenceImplement, 
 cAttachedSequenceInterface,
 PCCHAR, UINT, NULL, cSequence>
cAttachedSequenceExtends;
/**
 **********************************************************************
 *  Class: cAttachedSequence
 *
 * Author: $author$
 *   Date: 8/22/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cAttachedSequence
: public cAttachedSequenceExtends
{
public:
    typedef cAttachedSequenceExtends cExtends;
    typedef cAttachedSequence cDerives;

    /**
     **********************************************************************
     * Constructor: cAttachedSequence
     *
     *      Author: $author$
     *        Date: 8/22/2009
     **********************************************************************
     */
    cAttachedSequence
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CATTACHEDSEQUENCE_MEMBERS_ONLY) */
#endif /* !defined(CATTACHEDSEQUENCE_MEMBERS_ONLY) */

#endif /* !defined(_CATTACHEDSEQUENCE_HXX) || defined(CATTACHEDSEQUENCE_MEMBERS_ONLY) */
