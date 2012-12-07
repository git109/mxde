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
 *   File: ctiffopened.hxx
 *
 * Author: $author$
 *   Date: 12/24/2009
 **********************************************************************
 */
#if !defined(_CTIFFOPENED_HXX) || defined(CTIFFOPENED_MEMBERS_ONLY)
#if !defined(_CTIFFOPENED_HXX) && !defined(CTIFFOPENED_MEMBERS_ONLY)
#define _CTIFFOPENED_HXX
#endif /* !defined(_CTIFFOPENED_HXX) && !defined(CTIFFOPENED_MEMBERS_ONLY) */

#if !defined(CTIFFOPENED_MEMBERS_ONLY)
#include "ctiffopenedinterface.hxx"
#include "ctiffattached.hxx"
#include "copened.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cTIFFOpened;
/**
 **********************************************************************
 * Typedef: cTIFFOpenedExtends
 *
 *  Author: $author$
 *    Date: 12/24/2009
 **********************************************************************
 */
typedef cOpenedT
<cTIFFOpened, 
 cTIFFOpenedImplement, 
 cTIFFAttached>
cTIFFOpenedExtends;
/**
 **********************************************************************
 *  Class: cTIFFOpened
 *
 * Author: $author$
 *   Date: 12/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cTIFFOpened
: public cTIFFOpenedExtends
{
public:
    typedef cTIFFOpenedExtends cExtends;
    typedef cTIFFOpened cDerives;

    /**
     **********************************************************************
     * Constructor: cTIFFOpened
     *
     *      Author: $author$
     *        Date: 12/24/2009
     **********************************************************************
     */
    cTIFFOpened
    (TIFF* attached=0,
     bool isOpen=false) 
    : cExtends(isOpen) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cTIFFOpened
     *
     *     Author: $author$
     *       Date: 12/24/2009
     **********************************************************************
     */
    virtual ~cTIFFOpened()
    {
        eError error;
        if ((error = Closed()))
            throw(error);
    }
#else /* !defined(CTIFFOPENED_MEMBERS_ONLY) */
#endif /* !defined(CTIFFOPENED_MEMBERS_ONLY) */

#if !defined(CTIFFOPENED_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 12/25/2009
     **********************************************************************
     */
    virtual TIFF* Detach() 
#if defined(CTIFFOPENED_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFOPENED_MEMBER_FUNCS_INTERFACE) */
    {
        TIFF* tiff = 0;
#if !defined(CTIFFOPENED_MEMBER_FUNCS_IMPLEMENT) 
        tiff = m_attached;
        m_isOpen = false;
        m_attached = 0;
#else /* !defined(CTIFFOPENED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTIFFOPENED_MEMBER_FUNCS_IMPLEMENT) */
        return tiff;
    }
#endif /* defined(CTIFFOPENED_MEMBER_FUNCS_INTERFACE) */
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTIFFOPENED_MEMBERS_ONLY) */
#endif /* !defined(CTIFFOPENED_MEMBERS_ONLY) */

#endif /* !defined(_CTIFFOPENED_HXX) || defined(CTIFFOPENED_MEMBERS_ONLY) */
