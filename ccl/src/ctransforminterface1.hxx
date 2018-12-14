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
 *   File: ctransforminterface.hxx
 *
 * Author: $author$
 *   Date: 8/18/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTRANSFORMINTERFACE_HXX
#define _CTRANSFORMINTERFACE_HXX

#include "cdocumentinterface.hxx"
#include "ccontentinterface.hxx"
#include "ccharbuffer.hxx"
#include "ccharstream.hxx"
#include "clistt.hxx"

class c_INTERFACE_CLASS cTInterface;

/**
 **********************************************************************
 *  Class: cTransformInterface
 *
 * Author: $author$
 *   Date: 8/18/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cTransformInterface
: virtual public cContentInterface
{
public:
    class cVariableInterfaceStack;

    /**
     **********************************************************************
     *  Class: cValueInterface
     *
     * Author: $author$
     *   Date: 8/18/2003
     **********************************************************************
     */
    class c_INTERFACE_CLASS cValueInterface
    : virtual public cInterface
    {
    public:
        /**
         **********************************************************************
         * Function: ElementSet
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual cElementSetInterface &ElementSet()=0;
        /**
         **********************************************************************
         * Function: Push
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual eError Push(cVariableInterfaceStack &stack)=0;
        /**
         **********************************************************************
         * Function: Update
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual eError Update()=0;
        /**
         **********************************************************************
         * Function: Release
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual eError Release()=0;
    };

    /**
     **********************************************************************
     *  Class: cVariableInterface
     *
     * Author: $author$
     *   Date: 8/18/2003
     **********************************************************************
     */
    class c_INTERFACE_CLASS cVariableInterface
    : virtual public cInterface
    {
    public:
        /**
         **********************************************************************
         * Function: ElementSet
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual cElementSetInterface &ElementSet()=0;
        /**
         **********************************************************************
         * Function: GetNewValue
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual cValueInterface *GetNewValue()=0;
        /**
         **********************************************************************
         * Function: PopValue
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual eError PopValue()=0;
    };

    /**
     **********************************************************************
     *  Class: cVariableInterfaceItem
     *
     * Author: $author$
     *   Date: 8/18/2003
     **********************************************************************
     */
    class cVariableInterfaceItem
    : public cListItemT<cVariableInterfaceItem>
    {
    public:
        typedef cListItemT<cVariableInterfaceItem> cIs;

        cVariableInterface &m_variable;

        /**
         **********************************************************************
         * Constructor: cVariableInterfaceItem
         *
         *      Author: $author$
         *        Date: 8/18/2003
         **********************************************************************
         */
        cVariableInterfaceItem(cVariableInterface &variable) 
        :  m_variable(variable) 
        {
        }
        /**
         **********************************************************************
         * Function: GetVariable
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        cVariableInterface &GetVariable()
        {
            return m_variable;
        }
    };

    /**
     **********************************************************************
     *  Class: cVariableInterfaceStack
     *
     * Author: $author$
     *   Date: 8/18/2003
     **********************************************************************
     */
    class cVariableInterfaceStack
    : public cListT<cVariableInterfaceItem, cVariableInterfaceStack>
    {
    public:
        typedef cListT<cVariableInterfaceItem, cVariableInterfaceStack> cIs;

        /**
         **********************************************************************
         * Constructor: cVariableInterfaceStack
         *
         *      Author: $author$
         *        Date: 8/18/2003
         **********************************************************************
         */
        cVariableInterfaceStack() 
        {
        }
        /**
         **********************************************************************
         * Function: 
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
    };

    /**
     **********************************************************************
     *  Class: cFunctionInterface
     *
     * Author: $author$
     *   Date: 8/18/2003
     **********************************************************************
     */
    class c_INTERFACE_CLASS cFunctionInterface
    : virtual public cInterface
    {
    public:
        /**
         **********************************************************************
         * Function: Evaluate
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual eError Evaluate
        (cTransformInterface &transform,
         cElementSetInterface &result,
         cElementInterface &element) const = 0;
        /**
         **********************************************************************
         * Function: GetName
         *
         *   Author: $author$
         *     Date: 8/18/2003
         **********************************************************************
         */
        virtual const char *GetName() const = 0;
    };

    /**
     **********************************************************************
     * Function: TransformDocumentToStreamFromFile
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError TransformDocumentToStreamFromFile
    (cCharStream &stream, 
     cDocumentInterface &document,
     const char *template_document_filename,
     const char *template_document_type,
     const char *template_document_uri=0) = 0;
    /**
     **********************************************************************
     * Function: TransformDocumentToStreamFromStream
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError TransformDocumentToStreamFromStream
    (cCharStream &stream, 
     cDocumentInterface &document,
     cCharStream &template_document_stream,
     const char *template_document_type,
     const char *template_document_uri=0) = 0;
    /**
     **********************************************************************
     * Function: TransformToStreamFromStream
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError TransformToStreamFromStream
    (cCharStream &stream,
     cCharStream &template_document_stream,
     const char *template_document_type,
     const char *template_document_uri=0) = 0;
    /**
     **********************************************************************
     * Function: TransformToStream
     *
     *   Author: $author$
     *     Date: 9/5/2003
     **********************************************************************
     */
    virtual eError TransformToStream
    (cCharStream &stream,
     cDocumentInterface &template_document,
     const char *template_document_uri=0) = 0;
    /**
     **********************************************************************
     * Function: EvaluateElementSetToStream
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError EvaluateElementSetToStream
    (cCharStream &stream, cElementSetInterface &element_set)=0;
    /**
     **********************************************************************
     * Function: EvaluateElementToStream
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError EvaluateElementToStream
    (cCharStream &stream, cElementInterface &element)=0;
    /**
     **********************************************************************
     * Function: EvaluateElementSet
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError EvaluateElementSet
    (cElementSetInterface &result,
     cElementSetInterface &element_set)=0;
    /**
     **********************************************************************
     * Function: EvaluateElementChildren
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError EvaluateElementChildren
    (cElementSetInterface &result,
     cElementInterface &element) = 0;
    /**
     **********************************************************************
     * Function: EvaluateElementSiblings
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError EvaluateElementSiblings
    (cElementSetInterface &result,
     cElementInterface &element) = 0;
    /**
     **********************************************************************
     * Function: EvaluateElement
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual eError EvaluateElement
    (cElementSetInterface &result,
     cElementInterface &element)=0;
    /**
     **********************************************************************
     * Function: GetVariable
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cVariableInterface *GetVariable
    (const char *name,int namelen=-1)=0;
    /**
     **********************************************************************
     * Function: GetTemplate
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cElementInterface *GetTemplate
    (const char *name,int namelen=-1) const=0;
    /**
     **********************************************************************
     * Function: SetTemplateDocument
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cDocumentInterface *SetTemplateDocument
    (cDocumentInterface *document)=0;
    /**
     **********************************************************************
     * Function: GetTemplateDocument
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cDocumentInterface *GetTemplateDocument() const=0;
    /**
     **********************************************************************
     * Function: SetDocument
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cDocumentInterface *SetDocument
    (cDocumentInterface *document)=0;
    /**
     **********************************************************************
     * Function: GetDocument
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cDocumentInterface *GetDocument() const=0;
    /**
     **********************************************************************
     * Function: SetElementSet
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cElementSetInterface *SetElementSet
    (cElementSetInterface *element_set)=0;
    /**
     **********************************************************************
     * Function: GetElementSet
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cElementSetInterface *GetElementSet() const=0;
    /**
     **********************************************************************
     * Function: SetElement
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cElementInterface *SetElement
    (cElementInterface *element)=0;
    /**
     **********************************************************************
     * Function: GetElement
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cElementInterface *GetElement() const=0;
    /**
     **********************************************************************
     * Function: GetElementTrue
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cElementInterface *GetElementTrue() const=0;
    /**
     **********************************************************************
     * Function: GetElementLess
     *
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cElementInterface *GetElementLess() const=0;
    /**
     **********************************************************************
     * Function: GetElementGreater
     *
     *   Author: $author$
     *     Date: 9/14/2003
     **********************************************************************
     */
    virtual cElementInterface *GetElementGreater() const=0;
    /**
     **********************************************************************
     * Function: SetAttribute
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cAttributeInterface *SetAttribute
    (cAttributeInterface *attribute)=0;
    /**
     **********************************************************************
     * Function: GetAttribute
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    virtual cAttributeInterface *GetAttribute() const=0;

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    eError SetValue
    (const char *name, int namelen,
     const char *value, int valuelen=-1)
    {
        eError error;
        cElementInterface *element;
        cVariableInterface *var;
        cValueInterface *val;

        if ((var=GetVariable(name,namelen)))
        if ((val=var->GetNewValue()))
        {
            if ((element=val->ElementSet()
                .AddTextElement(value,valuelen)))
            if (!(error=val->Update()))
                return error;

            val->Release();
        }

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 8/19/2003
     **********************************************************************
     */
    const char *GetValue
    (cCharBuffer &buffer, const char *name, int namelen=-1)
    {
        int count;
        cVariableInterface *var;
        cElementSetInterface *val;

        if ((var=GetVariable(name,namelen)))
        if ((val=&var->ElementSet()))
        if ((count=buffer.Clear()) >= 0)
        if ((count=val->PutTextToStream(buffer)) >= 0)
            return buffer.GetBuffer();

        return 0;
    }
};


#endif
