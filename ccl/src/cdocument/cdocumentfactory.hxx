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
 *   File: cdocumentfactory.hxx
 *
 * Author: $author$
 *   Date: 10/9/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTFACTORY_HXX
#define _CDOCUMENTFACTORY_HXX

#include "cdocument.hxx"
#include "cdocumentparsertype.hxx"
#include "cdocumentparserinterface.hxx"
#include "cdocumentfactoryimplement.hxx"
#include "cdocumentfactoryinterface.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cDocumentFactory
 *
 * Author: $author$
 *   Date: 10/9/2005
 **********************************************************************
 */
class cDocumentFactory
: virtual public cDocumentFactoryImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    static cDocumentFactory m_instance;

    /**
     **********************************************************************
     * Constructor: cDocumentFactory
     *
     *      Author: $author$
     *        Date: 10/9/2005
     **********************************************************************
     */
    cDocumentFactory() 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDocumentFactory
     *
     *      Author: $author$
     *        Date: 10/9/2005
     **********************************************************************
     */
    virtual ~cDocumentFactory()
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 11/8/2005
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = cStaticDocumentParserTypeList::m_instance.Initialize();
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 11/8/2005
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = cStaticDocumentParserTypeList::m_instance.Finalize();
        return error;
    }
    /**
     **********************************************************************
     * Function: CreateDocumentByType
     *
     *   Author: $author$
     *     Date: 11/7/2005
     **********************************************************************
     */
    virtual cDocumentInterface* CreateDocumentByType
    (const char* uri, int length=-1) 
    {
        cDocumentInterface* node = 0;
        cDocumentParserInterface* parser;
        cDocumentParserTypeInterface* parser_type;

        if ((parser_type = cDocumentParserTypeTree::m_instance.Find(uri, length)))
        if ((parser = parser_type->GetParser()))
            node = &parser->GetDocument();

        return node;
    }
    /**
     **********************************************************************
     * Function: CreateDocument
     *
     *   Author: $author$
     *     Date: 11/24/2005
     **********************************************************************
     */
    virtual cDocumentInterface* CreateDocument() 
    {
        cDocumentInterface* node = 0;
        return node;
    }
};

#endif /* _CDOCUMENTFACTORY_HXX */
