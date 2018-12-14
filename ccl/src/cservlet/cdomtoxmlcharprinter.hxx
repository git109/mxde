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
 *   File: cdomtoxmlcharprinter.hxx
 *
 * Author: $author$
 *   Date: 7/1/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOMTOXMLCHARPRINTER_HXX
#define _CDOMTOXMLCHARPRINTER_HXX

#include "cdominterface.hxx"
#include "ccharwriterinterface.hxx"

/**
 **********************************************************************
 *  Class: cDOMToXMLCharPrinter
 *
 * Author: $author$
 *   Date: 7/1/2005
 **********************************************************************
 */
class cDOMToXMLCharPrinter
{
public:
    /**
     **********************************************************************
     * Constructor: cDOMToXMLCharPrinter
     *
     *      Author: $author$
     *        Date: 7/1/2005
     **********************************************************************
     */
    cDOMToXMLCharPrinter() 
    {
    }

    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 7/1/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDOMDocumentInterface& dom_document) 
    {
        cDOMNodeListInterface& dom_node_list = dom_document;
        int count = Print(writer, dom_node_list);
        return count;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 7/1/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDOMElementInterface& dom_element) 
    {
        cDOMNodeListInterface& dom_node_list = dom_element;
        cDOMNamedNodeInterface& dom_named_node = dom_element;
        int count;
        
        if (0 <= (count = writer.Write("\n<")))
        if (0 <= (count = Print(writer, dom_named_node)))
        {
            if (0 <= (count = writer.Write(">\n")))
            if (0 <= (count = Print(writer, dom_node_list)))
            if (0 <= (count = writer.Write("\n</")))
            if (0 <= (count = Print(writer, dom_named_node)))
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
     *     Date: 7/15/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDOMCommentInterface& dom_comment) 
    {
        cDOMCharacterDataInterface& dom_char_data = dom_comment;
        int count;
        
        if (0 <= (count = writer.Write("\n<!--")))
        if (0 <= (count = Print(writer, dom_char_data)))
        if (0 <= (count = writer.Write("-->\n")))
        {
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 7/1/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDOMNamedNodeInterface& dom_named_node) 
    {
        const cStringInterface& name = dom_named_node.GetName();
        int count = Print(writer, name);
        return count;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 7/14/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDOMCharacterDataInterface& dom_char_data,
     bool expand_amp=false) 
    {
        const cStringInterface& data = dom_char_data.GetData();
        int count = Print(writer, data, expand_amp);
        return count;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 7/14/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDOMNodeInterface& dom_node) 
    {
        int count = 0;
        int dom_node_type = dom_node.GetNodeType();
        cDOMElementInterface *dom_element;
        cDOMCommentInterface *dom_comment;
        cDOMCharacterDataInterface *dom_char_data;

        switch(dom_node_type)
        {
        case cDOMNodeInterface::e_TYPE_ELEMENT_NODE:
            if ((dom_element = dom_node.GetElementNode()))
                count = Print(writer, *dom_element);
            break;

        case cDOMNodeInterface::e_TYPE_COMMENT_NODE:
            if ((dom_comment = dom_node.GetCommentNode()))
                count = Print(writer, *dom_comment);
            break;

        case cDOMNodeInterface::e_TYPE_TEXT_NODE:
            if ((dom_char_data = dom_node.GetTextNode()))
                count = Print(writer, *dom_char_data, true);
            break;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 7/1/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     cDOMNodeListInterface& dom_node_list) 
    {
        int count = 0;
        cDOMNodeInterface *dom_node;

        for (dom_node=dom_node_list.GetFirstChild(); 
             dom_node; dom_node=dom_node->GetNextSibling())
        {
            Print(writer, *dom_node);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Print
     *
     *   Author: $author$
     *     Date: 7/14/2005
     **********************************************************************
     */
    virtual int Print
    (cCharWriterInterface& writer,
     const cStringInterface& string,
     bool expand_amp=false) 
    {
        int count = 0;
        char pending = 0;
        const cChar *chars;
        int err, length;

        if ((chars = string.GetChars(length)))
        {
            while (0 < length)
            {
                char c = chars->ToChar();

                if (expand_amp && ('&' == c))
                {
                    if (pending)
                    {
                        if (0 >= (err = writer.Write("&amp;")))
                           return -e_ERROR_FAILED;
                        count += err;
                    }
                    pending = c;
                }
                else 
                {
                    if (expand_amp && pending)
                    {
                        switch(c)
                        {
                        case ' ':
                        case '\n':
                        case '\t':
                            if (0 >= (err = writer.Write("&amp;")))
                               return -e_ERROR_FAILED;
                            count += err;
                            break;

                        default:
                            if (0 > (err = writer.Putc(pending)))
                                return -e_ERROR_FAILED;
                            count++;
                        }
                        pending = 0;
                    }

                    if (0 > (err = writer.Putc(c)))
                        return -e_ERROR_FAILED;
                }

                ++count;
                ++chars;
                --length;
            }

            if (expand_amp && pending)
            {
                if (0 >= (err = writer.Write("&amp;")))
                   return -e_ERROR_FAILED;
                count += err;
            }
        }
        return count;
    }
};

#endif /* _CDOMTOXMLCHARPRINTER_HXX */