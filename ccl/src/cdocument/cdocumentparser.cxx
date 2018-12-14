/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: cdocumentparser.cxx
 *
 * Author: $author$
 *   Date: 11/4/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cdocumentparsertype.hxx"
#include "cdocumentparserimplement.hxx"
#include "cdocumentparserinterface.hxx"

/**
 **********************************************************************
 *  Class: cNullDocumentParser
 *
 * Author: $author$
 *   Date: 11/25/2005
 **********************************************************************
 *
class cNullDocumentParser
: virtual public cDocumentParserImplement,
  public cInstance
{
public:
    typedef cInstance cIs;
} g_null_document_parser;

/**
 **********************************************************************
 *  Class: cDocumentParserInterface
 *
 * Author: $author$
 *   Date: 11/25/2005
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cDocumentParserInterface::GetNullDocumentParser
 *
 *   Author: $author$
 *     Date: 11/25/2005
 **********************************************************************
 *
cDocumentParserInterface& 
cDocumentParserInterface::GetNullDocumentParser() 
{
    return g_null_document_parser;
}

/**
 **********************************************************************
 *  Class: cDocumentParserTypeTree
 *
 * Author: $author$
 *   Date: 11/4/2005
 **********************************************************************
 */
cDocumentParserTypeTree cDocumentParserTypeTree::m_instance;
 
/**
 **********************************************************************
 *  Class: cStaticDocumentParserType
 *
 * Author: $author$
 *   Date: 11/4/2005
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cStaticDocumentParserType::AddToList
 *
 *   Author: $author$
 *     Date: 11/4/2005
 **********************************************************************
 */
void cStaticDocumentParserType::AddToList() 
{
    cStaticDocumentParserTypeList::m_instance.Add(this);
}
/**
 **********************************************************************
 * Function: cStaticDocumentParserType::DeleteFromList
 *
 *   Author: $author$
 *     Date: 11/4/2005
 **********************************************************************
 */
void cStaticDocumentParserType::DeleteFromList() 
{
    cStaticDocumentParserTypeList::m_instance.Delete(this);
}

/**
 **********************************************************************
 *  Class: cStaticDocumentParserTypeList
 *
 * Author: $author$
 *   Date: 11/4/2005
 **********************************************************************
 */
cStaticDocumentParserType* cStaticDocumentParserTypeList::m_first = 0;
cStaticDocumentParserType* cStaticDocumentParserTypeList::m_last = 0;
cStaticDocumentParserTypeList cStaticDocumentParserTypeList::m_instance;
