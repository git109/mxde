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
 *   File: ctransformtypeinterface.cxx
 *
 * Author: $author$
 *   Date: 2/2/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "ctransformtype.hxx"
#include "ctransformtypeinterface.hxx"

/*
 **********************************************************************
 *  Class: cTransformTypeInterface
 *
 * Author: $author$
 *   Date: 2/2/2004
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: cTransformTypeInterface::GetByName
 *
 *      Author: $author$
 *        Date: 2/2/2004
 **********************************************************************
 */
cTransformTypeInterface *cTransformTypeInterface::GetByName
(const char *name)
{
    cTransformTypeInterface *type=0;

    for (type = GetFirst(); type; type=type->GetNext())
        if (type->IsNamed(name))
            break;

    return type;
}
/**
 **********************************************************************
 *    Function: cTransformTypeInterface::GetFirst
 *
 *      Author: $author$
 *        Date: 2/2/2004
 **********************************************************************
 */
cTransformTypeInterface *cTransformTypeInterface::GetFirst()
{
    cTransformTypeInterface *type=cStaticTransformType::GetFirst();
    return type;
}
/**
 **********************************************************************
 *    Function: cTransformTypeInterface::GetLast
 *
 *      Author: $author$
 *        Date: 2/2/2004
 **********************************************************************
 */
cTransformTypeInterface *cTransformTypeInterface::GetLast()
{
    cTransformTypeInterface *type=cStaticTransformType::GetLast();
    return type;
}

