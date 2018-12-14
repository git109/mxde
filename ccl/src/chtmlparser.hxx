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
 *   File: chtmlparser.hxx
 *
 * Author: $author$
 *   Date: 12/30/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTMLPARSER_HXX
#define _CHTMLPARSER_HXX

#include "cxmlparser.hxx"

/**
 **********************************************************************
 *  Class: cHTMLParser
 *
 * Author: $author$
 *   Date: 12/30/2003
 **********************************************************************
 */
class cHTMLParser
: public cXMLParser
{
public:
    typedef cXMLParser cIs;

    cLexicon::cTree m_end_tags;

    /**
     **********************************************************************
     * Constructor: cHTMLParser
     *
     *      Author: $author$
     *        Date: 12/30/2003
     **********************************************************************
     */
    cHTMLParser
    (bool include_multiple_root_elements=false,
     bool include_whitespace=false,
     bool include_comments=false)
    : cIs
      (include_multiple_root_elements, 
       include_whitespace, include_comments)
    {
    }

    /**
     **********************************************************************
     * Function: ParseLexiconsFromStream
     *
     *   Author: $author$
     *     Date: 12/30/2003
     **********************************************************************
     */
    virtual eError ParseLexiconsFromStream(cCharStream &source)
    {
        m_end_tags.Clear();
        return cIs::ParseLexiconsFromStream(source);
    }
    /**
     **********************************************************************
     * Function: OnParseTag
     *
     *   Author: $author$
     *     Date: 12/30/2003
     **********************************************************************
     */
    virtual eError OnParseTag(cLexicon &lexicon)
    {
        eError error;
        cLexicon *found;

        if ((found = m_end_tags.Find(lexicon)))
        {
            if ((error = OnBeginElement(lexicon)))
                return error;

            m_begin_tags.Push(lexicon);
        }
        else error = OnElement(lexicon);

        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndTagLexicon
     *
     *   Author: $author$
     *     Date: 12/30/2003
     **********************************************************************
     */
    virtual eError OnEndTagLexicon(cLexicon &lexicon)
    {
        cLexicon *found;

        if (!(found = m_end_tags.Find(lexicon)))
            m_end_tags.Insert(lexicon);

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: CompareTags
     *
     *   Author: $author$
     *     Date: 8/23/2003
     **********************************************************************
     */
    virtual int CompareTags
    (cCharBuffer &tag1, cCharBuffer &tag2) const
    {
        return stricmp
        (tag1.GetBuffer(), tag2.GetBuffer());
    }
};

#endif /* ndef _CHTMLPARSER_HXX */
