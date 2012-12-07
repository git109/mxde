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
 *   File: cimageshapeinterface.hxx
 *
 * Author: $author$
 *   Date: 8/6/2009
 **********************************************************************
 */
#if !defined(_CIMAGESHAPEINTERFACE_HXX) || defined(CIMAGESHAPEINTERFACE_MEMBERS_ONLY)
#if !defined(_CIMAGESHAPEINTERFACE_HXX) && !defined(CIMAGESHAPEINTERFACE_MEMBERS_ONLY)
#define _CIMAGESHAPEINTERFACE_HXX
#endif /* !defined(_CIMAGESHAPEINTERFACE_HXX) && !defined(CIMAGESHAPEINTERFACE_MEMBERS_ONLY) */

#if !defined(CIMAGESHAPEINTERFACE_MEMBERS_ONLY)
#include "cimageinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cImageShapeInterface
 *
 * Author: $author$
 *   Date: 8/6/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageShapeInterface
: virtual public cImageInterface
{
public:
    typedef cImageInterface cImplements;
#else /* !defined(CIMAGESHAPEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGESHAPEINTERFACE_MEMBERS_ONLY) */

#if !defined(CIMAGESHAPEINTERFACE_MEMBERS_ONLY)
/* include cImageShape member functions interface
 */
#define CIMAGESHAPE_MEMBERS_ONLY
#define CIMAGESHAPE_MEMBER_FUNCS_INTERFACE
#include "cimageshape.hxx"
#undef CIMAGESHAPE_MEMBER_FUNCS_INTERFACE
#undef CIMAGESHAPE_MEMBERS_ONLY
};

class c_IMPLEMENT_CLASS cImageShapeImplement
: virtual public cImageShapeInterface,
  virtual public cImageImplement
{
public:
/* include cImageShape member functions implement
 */
#define CIMAGESHAPE_MEMBERS_ONLY
#define CIMAGESHAPE_MEMBER_FUNCS_IMPLEMENT
#include "cimageshape.hxx"
#undef CIMAGESHAPE_MEMBER_FUNCS_IMPLEMENT
#undef CIMAGESHAPE_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGESHAPEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGESHAPEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGESHAPEINTERFACE_HXX) || defined(CIMAGESHAPEINTERFACE_MEMBERS_ONLY) */
