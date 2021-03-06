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
 *   File: cdocumentfactory.cxx
 *
 * Author: $author$
 *   Date: 11/8/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cdocumentfactory.hxx"

/**
 **********************************************************************
 *  Class: cNullDocumentFactory
 *
 * Author: $author$
 *   Date: 11/23/2005
 **********************************************************************
 */
class cNullDocumentFactory
: virtual public cDocumentFactoryImplement,
  public cInstance
{
public:
} g_null_document_factory;

/**
 **********************************************************************
 *  Class: cDocumentFactoryInterface
 *
 * Author: $author$
 *   Date: 11/23/2005
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cDocumentFactoryInterface::GetNullFactory
 *
 *   Author: $author$
 *     Date: 11/23/2005
 **********************************************************************
 */
cDocumentFactoryInterface& 
cDocumentFactoryInterface::GetNullFactory() 
{
    return g_null_document_factory;
}

/**
 **********************************************************************
 *  Class: cDocumentFactory
 *
 * Author: $author$
 *   Date: 11/8/2005
 **********************************************************************
 */
cDocumentFactory cDocumentFactory::m_instance;
