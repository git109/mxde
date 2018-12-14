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
 *   File: crtftodocumentparser.hxx
 *
 * Author: $author$
 *   Date: 3/18/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CRTFTODOCUMENTPARSER_HXX
#define _CRTFTODOCUMENTPARSER_HXX

#include "crtfparsert.hxx"
#include "cdocumentinterface.hxx"

/**
 **********************************************************************
 *  Class: cRTFToDocumentParser
 *
 * Author: $author$
 *   Date: 3/18/2004
 **********************************************************************
 */
class cRTFToDocumentParser
: public cRTFParser
{
public:
    typedef cRTFParser cIs;

    cDocumentInterface &m_document;
    cElementSetInterface *m_element_set;

    /**
     **********************************************************************
     * Constructor: cRTFToDocumentParser
     *
     *      Author: $author$
     *        Date: 3/18/2004
     **********************************************************************
     */
    cRTFToDocumentParser(cCharStream &output, cDocumentInterface &document)
    : cIs(output),
      m_document(document),
      m_element_set(&document)
    {
    }
    /**
     **********************************************************************
     * Function: Parse
     *
     *   Author: $author$
     *     Date: 3/17/2004
     **********************************************************************
     */
    virtual eError Parse(cCharStream &stream)
    {
        eError error=0;

        m_element_set = &m_document;

        if (!(error = m_document.DeleteAllElements()))
            error=cIs::Parse(stream);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndText
     *
     *   Author: $author$
     *     Date: 3/17/2004
     **********************************************************************
     */
    virtual eError OnEndText(cCharStream &stream)
    {
        eError length,error=0;
        const char *text;
        cElementInterface *e=0;

        if ((text = m_text.GetBuffer(length)))
        if (0 < length)
        {
            if (m_element_set)
            if ((e = m_element_set->AddElement("text")))
                e->AddTextElement(text, length);

            if (0 > (length = m_text.Clear()))
                return -length;
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndControlWord
     *
     *   Author: $author$
     *     Date: 3/17/2004
     **********************************************************************
     */
    virtual eError OnEndControlWord(cCharStream &stream)
    {
        eError error=0;
        const char *text;
        int length;
        cElementInterface *e=0;

        if ((text = m_control_word.GetBuffer(length)))
        if (0 < length)
        {
            if (m_element_set)
            if ((e = m_element_set->AddElement("control")))
                e->AddTextElement(text, length);

            if (0 > (length = m_control_word.Clear()))
                return -length;
        }

        if ((text = m_control_param.GetBuffer(length)))
        if (0 < length)
        {
            if (e)
                e->AddAttribute("parameter", -1, text, length);

            if (0 > (length = m_control_param.Clear()))
                return -length;
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginGroup
     *
     *   Author: $author$
     *     Date: 3/17/2004
     **********************************************************************
     */
    virtual eError OnBeginGroup(cCharStream &stream)
    {
        eError error=0;
        cElementInterface *e=0;

        if (m_element_set)
        if ((e = m_element_set->AddElement("group")))
            m_element_set = e;

        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndGroup
     *
     *   Author: $author$
     *     Date: 3/17/2004
     **********************************************************************
     */
    virtual eError OnEndGroup(cCharStream &stream)
    {
        eError error=0;
        cElementInterface *e=0;
        cDocumentInterface *d=0;

        if (m_element_set)
        if ((e = m_element_set->GetParentElement()))
            m_element_set = e;
        else if ((d = m_element_set->GetParentDocument()))
                m_element_set = d;

        return error;
    }
};

#endif /* ndef _CRTFTODOCUMENTPARSER_HXX */
