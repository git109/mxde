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
 *   File: cdocumentnodefactory.cxx
 *
 * Author: $author$
 *   Date: 11/1/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cdocumentnodefactory.hxx"
#include "cdocumentfactory.hxx"

/**
 **********************************************************************
 *  Class: cNullDocumentNodeFactory
 *
 * Author: $author$
 *   Date: 11/1/2005
 **********************************************************************
 */
class cNullDocumentNodeFactory
: virtual public cDocumentNodeFactoryImplement,
  public cInstance
{
public:
} g_null_document_node_factory;

/**
 **********************************************************************
 *  Class: cDocumentNodeFactoryInterface
 *
 * Author: $author$
 *   Date: 11/1/2005
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cDocumentNodeFactoryInterface::GetNullNodeFactory
 *
 *   Author: $author$
 *     Date: 11/1/2005
 **********************************************************************
 */
cDocumentNodeFactoryInterface& 
cDocumentNodeFactoryInterface::GetNullNodeFactory() 
{
    return g_null_document_node_factory;
}

/**
 **********************************************************************
 *  Class: cDocumentNodeFactory
 *
 * Author: $author$
 *   Date: 11/23/2005
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cDocumentNodeFactory::GetDocumentFactory
 *
 *   Author: $author$
 *     Date: 11/23/2005
 **********************************************************************
 *
cDocumentFactoryInterface& cDocumentNodeFactory::GetDocumentFactory() const 
{
    return cDocumentFactory::m_instance;
}*/
