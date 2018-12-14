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
 *   File: cxalanfunction.cxx
 *
 * Author: $author$
 *   Date: 12/20/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "cxalanfunction.hxx"

/**
 **********************************************************************
 *    Function: cXalanFunction::cStaticList
 *
 *      Author: $author$
 *        Date: 12/20/2003
 **********************************************************************
 */
cXalanFunction::cListItem *cXalanFunction::cStaticList::cIs::m_first=0;
cXalanFunction::cListItem *cXalanFunction::cStaticList::cIs::m_last=0;

/*
 **********************************************************************
 *  Class: cXalanFunction
 *
 * Author: $author$
 *   Date: 12/20/2003
 **********************************************************************
 */
cXalanFunction::cStaticList cXalanFunction::m_static_list;

/*
 **********************************************************************
 *  Class: cXalanFunctionNodeSet
 *
 * Author: $author$
 *   Date: 12/20/2003
 **********************************************************************
 */
cXalanFunctionNodeSet cXalanFunctionNodeSet::m_static_instance;

/*
 **********************************************************************
 *  Class: cXalanFunctionGetVariable
 *
 * Author: $author$
 *   Date: 12/20/2003
 **********************************************************************
 */
cXalanFunctionGetVariable cXalanFunctionGetVariable::m_static_instance;

