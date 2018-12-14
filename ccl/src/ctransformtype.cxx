/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: ctransformtype.cxx
 *
 * Author: $author$
 *   Date: 2/3/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "ctransformtype.hxx"

/*
 **********************************************************************
 *  Class: cStaticTransformType::cList
 *
 * Author: $author$
 *   Date: 2/3/2004
 **********************************************************************
 */
cStaticTransformType *cStaticTransformType::cList::cIs::m_first=0;
cStaticTransformType *cStaticTransformType::cList::cIs::m_last=0;

/*
 **********************************************************************
 *  Class: cStaticTransformType
 *
 * Author: $author$
 *   Date: 2/3/2004
 **********************************************************************
 */
cStaticTransformType::cList cStaticTransformType::m_list;

/**
 **********************************************************************
 *  Class: cTransformStaticTransformType
 *
 * Author: $author$
 *   Date: 2/3/2004
 **********************************************************************
 */
class cTransformStaticTransformType
: public cTransformType
{
public:
    typedef cTransformType cIs;

    cStaticTransformType m_static_type;

    /**
     **********************************************************************
     * Constructor: cTransformStaticTransformType
     *
     *      Author: $author$
     *        Date: 2/3/2004
     **********************************************************************
     */
    cTransformStaticTransformType(const char *name) 
    : cIs(name),
      m_static_type(*this)
    {
    }
} g_transform_type("dt");
