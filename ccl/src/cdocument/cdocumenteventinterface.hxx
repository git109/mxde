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
 *   File: cdocumenteventinterface.hxx
 *
 * Author: $author$
 *   Date: 10/14/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTEVENTINTERFACE_HXX
#define _CDOCUMENTEVENTINTERFACE_HXX

#include "cdocumentartifactinterface.hxx"

/**
 **********************************************************************
 *  Class: cDocumentEventInterface
 *
 * Author: $author$
 *   Date: 10/14/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentEventInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: GetNullEvent
     *
     *   Author: $author$
     *     Date: 11/24/2005
     **********************************************************************
     */
    static cDocumentEventInterface& GetNullEvent();

    /**
     **********************************************************************
     * Function: OnAddText
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual eError OnAddText
    (cDocumentNodeListInterface& list,
     cDocumentTextInterface& node) = 0;
    /**
     **********************************************************************
     * Function: OnDeleteText
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual eError OnDeleteText
    (cDocumentNodeListInterface& list,
     cDocumentTextInterface& node) = 0;

    /**
     **********************************************************************
     * Function: OnAddComment
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual eError OnAddComment
    (cDocumentNodeListInterface& list,
     cDocumentCommentInterface& node) = 0;
    /**
     **********************************************************************
     * Function: OnDeleteComment
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual eError OnDeleteComment
    (cDocumentNodeListInterface& list,
     cDocumentCommentInterface& node) = 0;

    /**
     **********************************************************************
     * Function: OnAddBeginElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnAddBeginElement
    (cDocumentNodeListInterface& list,
     cDocumentBeginElementInterface& node) = 0;
    /**
     **********************************************************************
     * Function: OnDeleteBeginElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnDeleteBeginElement
    (cDocumentNodeListInterface& list,
     cDocumentBeginElementInterface& node) = 0;

    /**
     **********************************************************************
     * Function: OnAddEndElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnAddEndElement
    (cDocumentNodeListInterface& list,
     cDocumentEndElementInterface& node) = 0;
    /**
     **********************************************************************
     * Function: OnDeleteEndElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnDeleteEndElement
    (cDocumentNodeListInterface& list,
     cDocumentEndElementInterface& node) = 0;

    /**
     **********************************************************************
     * Function: OnAddElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnAddElement
    (cDocumentNodeListInterface& list,
     cDocumentElementInterface& node) = 0;
    /**
     **********************************************************************
     * Function: OnDeleteElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnDeleteElement
    (cDocumentNodeListInterface& list,
     cDocumentElementInterface& node) = 0;

    /**
     **********************************************************************
     * Function: OnAddElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnAddElement
    (cDocumentElementInterface& element,
     cDocumentElementInterface& node) = 0;
    /**
     **********************************************************************
     * Function: OnDeleteElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnDeleteElement
    (cDocumentElementInterface& element,
     cDocumentElementInterface& node) = 0;

    /**
     **********************************************************************
     * Function: OnAddAttribute
     *
     *   Author: $author$
     *     Date: 12/12/2005
     **********************************************************************
     */
    virtual eError OnAddAttribute
    (cDocumentAttributeListInterface& list,
     cDocumentAttributeInterface& node) = 0;
    /**
     **********************************************************************
     * Function: OnDeleteAttribute
     *
     *   Author: $author$
     *     Date: 12/12/2005
     **********************************************************************
     */
    virtual eError OnDeleteAttribute
    (cDocumentAttributeListInterface& list,
     cDocumentAttributeInterface& node) = 0;

    /**
     **********************************************************************
     * Function: OnAddAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual eError OnAddAttribute
    (cDocumentNodeListInterface& list,
     cDocumentAttributeInterface& node) = 0;
    /**
     **********************************************************************
     * Function: OnDeleteAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual eError OnDeleteAttribute
    (cDocumentNodeListInterface& list,
     cDocumentAttributeInterface& node) = 0;

    /**
     **********************************************************************
     * Function: OnAddAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual eError OnAddAttribute
    (cDocumentElementInterface& element,
     cDocumentAttributeInterface& node) = 0;
    /**
     **********************************************************************
     * Function: OnDeleteAttribute
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual eError OnDeleteAttribute
    (cDocumentElementInterface& element,
     cDocumentAttributeInterface& node) = 0;

    /**
     **********************************************************************
     * Function: OnAddEntityReference
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual eError OnAddEntityReference
    (cDocumentNodeListInterface& list,
     cDocumentEntityReferenceInterface& node) = 0;
    /**
     **********************************************************************
     * Function: OnDeleteEntityReference
     *
     *   Author: $author$
     *     Date: 11/14/2005
     **********************************************************************
     */
    virtual eError OnDeleteEntityReference
    (cDocumentNodeListInterface& list,
     cDocumentEntityReferenceInterface& node) = 0;

    /**
     **********************************************************************
     * Function: OnBeginElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnBeginElement
    (cDocumentElementInterface& node) = 0;
    /**
     **********************************************************************
     * Function: OnEndElement
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual eError OnEndElement
    (cDocumentElementInterface& node) = 0;
};

#endif /* _CDOCUMENTEVENTINTERFACE_HXX */
