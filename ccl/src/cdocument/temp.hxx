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
 *   File: cdocumenttoxmlcharprinter.hxx
 *
 * Author: $author$
 *   Date: 10/17/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTTOXMLCHARPRINTER_HXX
#define _CDOCUMENTTOXMLCHARPRINTER_HXX

#include "cxmlversion.hxx"
#include "ccchartoxmlcharprinter.hxx"
#include "cdocumentinterface.hxx"
#include "ccharwriterinterface.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cDocumentToXMLCharPrinterT
 *
 * Author: $author$
 *   Date: 10/17/2005
 **********************************************************************
 */
template <class TIs=cBase>
class cDocumentToXMLCharPrinterT
: public TIs
{
public:
    typedef TIs cIs;

    cCCharToXMLCharPrinter m_cchar_to_xml_char;

    /**
     **********************************************************************
     * Constructor: cDocumentToXMLCharPrinterT
     *
     *      Author: $author$
     *        Date: 10/17/2005
     **********************************************************************
     */
    cDocumentToXMLCharPrinterT() 
    {
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDocumentInterface& document,
     cXMLVersionInterface* version=0) 
    {
        cDocumentNodeListInterface& node_list = document;
        int count;
        
        if (version)
        if (0 > (count = Print(writer, *version)))
            return count;

        count = Print(writer, node_list);
        return count;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDocumentElementInterface& element) 
    {
        cDocumentNodeListInterface& node_list = element;
        cDocumentNamedNodeInterface& named_node = element;
        cDocumentAttributeInterface* attribute;
        int count;
        
        if (0 <= (count = writer.Write("\n<")))
        if (0 <= (count = Print(writer, named_node)))
        {
            for (attribute=element.GetFirstAttribute(); 
                 attribute; attribute=attribute->GetNextAttribute())
            {
                if (0 < (count = writer.Write(" ")))
                if (0 < (count = Print(writer, *attribute)))
                    continue;

                return count;
            }
            if (0 <= (count = writer.Write(">\n")))
            if (0 <= (count = Print(writer, node_list)))
            if (0 <= (count = writer.Write("\n</")))
            if (0 <= (count = Print(writer, named_node)))
            if (0 <= (count = writer.Write(">\n")))
            {
            }
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 10/19/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDocumentAttributeInterface& attribute) 
    {
        cDocumentNamedNodeInterface& named_node = attribute;
        const cChar *chars;
        int count;

        if (0 <= (count = Print(writer, named_node)))
        if (0 < (count = writer.Write("=\"")))
        if ((chars = attribute.GetValueCChars(count)))
        if (0 <= (count = Print(writer, chars, count)))
            count = writer.Write("\"");
        return count;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDocumentCommentInterface& comment) 
    {
        cDocumentTextNodeInterface& text_node = comment;
        int count, result = 0;
        
        if (0 < (count = writer.Write("\n<!--")))
        {
            result += count;

            if (0 <= (count = Print(writer, text_node)))
            {
                result += count;

                if (0 < (count = writer.Write("-->\n")))
                    result += count;
            }
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDocumentNamedNodeInterface& named_node) 
    {
        int length, count, result = 0;
        const cChar* name;
        
        if ((name = named_node.GetNamespacePrefixCChars(length)))
        if (0 < length)
        if (0 < (count = Print(writer, name, length)))
        if (0 < writer.Putc(':'))
            result += count+1;

        if ((name = named_node.GetNameCChars(length)))
        if (0 < length)
        if (0 < (count = Print(writer, name, length)))
            result += count;

        return result;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDocumentTextNodeInterface& text_node,
     bool expand_amp=false) 
    {
        int length, count;
        const cChar* text;
        
        if ((text = text_node.GetTextCChars(length)))
            count = Print(writer, text, length, expand_amp);
        return count;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDocumentNodeInterface& node) 
    {
        int count = 0;
        int node_type = node.GetType();
        cDocumentElementInterface *element;
        cDocumentCommentInterface *comment;
        cDocumentTextInterface *text;

        switch(node_type)
        {
        case cDocumentNodeInterface::e_TYPE_ELEMENT:
            if ((element = node.GetElementInterface()))
                count = Print(writer, *element);
            break;

        case cDocumentNodeInterface::e_TYPE_COMMENT:
            if ((comment = node.GetCommentInterface()))
                count = Print(writer, *comment);
            break;

        case cDocumentNodeInterface::e_TYPE_TEXT:
            if ((text = node.GetTextInterface()))
                count = Print(writer, *text, true);
            break;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDocumentNodeListInterface& node_list) 
    {
        int count, result = 0;
        cDocumentNodeInterface *node;

        for (node=node_list.GetFirstNode(); 
             node; node=node->GetNextNode())
        {
            if (0 < (count = Print(writer, *node)))
                result += count;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     const cChar *chars, int length=-1,
     bool expand_amp=false) 
    {
        int count = m_cchar_to_xml_char.Print
        (writer, chars, length, expand_amp);
        return count;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 10/17/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cXMLVersionInterface& version) 
    {
        int c, value, count, length = 0;
        
        if (0 > (count = writer.Write("<?xml version=\"")))
            return count;

        length += count;

        if (0 > (value = version.GetMajor()))
            return value;

        if (0 > (count = writer.WriteInt(value)))
            return count;

        length += count;

        if (0 > (c = writer.Putc('.')))
            return c;

        length ++;

        if (0 > (value = version.GetMinor()))
            return value;

        if (0 > (count = writer.WriteInt(value)))
            return count;

        length += count;

        if (0 > (count = writer.Write("\"?>")))
            return count;

        return length;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentToXMLCharPrinter
 *
 * Author: $author$
 *   Date: 10/17/2005
 **********************************************************************
 */
class cDocumentToXMLCharPrinter
: public cDocumentToXMLCharPrinterT<>
{
public:
    typedef cDocumentToXMLCharPrinterT<> cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentToXMLCharPrinter
     *
     *      Author: $author$
     *        Date: 10/17/2005
     **********************************************************************
     */
    cDocumentToXMLCharPrinter() 
    {
    }
};

#endif /* _CDOCUMENTTOXMLCHARPRINTER_HXX */