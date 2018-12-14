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
 *   File: cdocumentevent.cxx
 *
 * Author: $author$
 *   Date: 11/24/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cdocumentevent.hxx"
#include "cdocumenteventimplement.hxx"
#include "cdocumenteventinterface.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cNullDocumentEvent
 *
 * Author: $author$
 *   Date: 11/24/2005
 **********************************************************************
 */
class cNullDocumentEvent
: virtual public cDocumentEventImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

} g_null_document_event;

/**
 **********************************************************************
 *  Class: cDocumentEventInterface
 *
 * Author: $author$
 *   Date: 11/24/2005
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cDocumentEventInterface::GetNullEvent
 *
 *   Author: $author$
 *     Date: 11/24/2005
 **********************************************************************
 */
cDocumentEventInterface& cDocumentEventInterface::GetNullEvent() 
{
    return g_null_document_event;
}

/**
 **********************************************************************
 *  Class: cDocumentEvent
 *
 * Author: $author$
 *   Date: 11/24/2005
 **********************************************************************
 */
cDocumentEvent cDocumentEvent::m_instance;

