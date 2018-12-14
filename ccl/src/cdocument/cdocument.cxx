/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: cdocument.cxx
 *
 * Author: $author$
 *   Date: 11/24/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cdocument.hxx"
#include "cdocumentnodelist.hxx"
#include "cdocumentinterface.hxx"
#include "cdocumentartifactimplement.hxx"
#include "cdocumentartifactinterface.hxx"

static cCCharBuffer g_type_none("none");
static cCCharBuffer g_type_text("text");
static cCCharBuffer g_type_comment("comment");
static cCCharBuffer g_type_element("element");

/**
 **********************************************************************
 * Function: cDocumentNode::GetTypeName
 *
 *   Author: $author$
 *     Date: 12/10/2005
 **********************************************************************
 */
const cCCharBuffer& cDocumentNode::GetTypeName() const
{
    int type;

    switch((type = GetType()))
    {
    case e_TYPE_TEXT: return g_type_text;
    case e_TYPE_COMMENT: return g_type_comment;
    case e_TYPE_ELEMENT: return g_type_element;
    }
    return g_type_none;
}
