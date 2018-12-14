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
 *   File: crtfparsert.hxx
 *
 * Author: $author$
 *   Date: 3/17/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CRTFPARSERT_HXX
#define _CRTFPARSERT_HXX

#include "cbase.hxx"
#include "ccharstream.hxx"
#include "ccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cRTFParserT
 *
 * Author: $author$
 *   Date: 3/17/2004
 **********************************************************************
 */
template <class TStream, class TAs, class TIs=cBase>
class cRTFParserT
: public TIs
{
public:
    typedef TIs cIs;

    TStream &m_output;
    cCharBuffer m_text;
    cCharBuffer m_control_word;
    cCharBuffer m_control_param;

    /**
     **********************************************************************
     * Constructor: cRTFParserT
     *
     *      Author: $author$
     *        Date: 3/17/2004
     **********************************************************************
     */
    cRTFParserT(TStream &output)
    : m_output(output)
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
    virtual eError Parse(TStream &stream)
    {
        eError error=0;
        int c,count;

        if (0 > (count = m_text.Clear()))
            return -count;

        while (0 <= (c = stream.Getc()))
        {
            switch(c)
            {
            case '\\':
                if (0 < m_text.GetLength())
                if ((error = OnEndText(stream)))
                    return error;

                if ((error = OnBeginControlWord(stream)))
                    return error;
                break;

            case '{':
                if (0 < m_text.GetLength())
                if ((error = OnEndText(stream)))
                    return error;

                if ((error = OnBeginGroup(stream)))
                    return error;
                break;

            case '}':
                if (0 < m_text.GetLength())
                if ((error = OnEndText(stream)))
                    return error;

                if ((error = OnEndGroup(stream)))
                    return error;
                break;

            default:
                if (0 > (c = m_text.Putc(c)))
                    return -c;
            }
            
        }

        if (0 < m_text.GetLength())
            error = OnEndText(stream);

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
    virtual eError OnEndText(TStream &stream)
    {
        eError length,error=0;
        const char *text;

        m_output.Write("OnEndText \"");

        if ((text = m_text.GetBuffer(length)))
        if (0 < length)
        {
            m_output.Write(text, length);

            if (0 > (length = m_text.Clear()))
                return -length;
        }

        m_output.Write("\"\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginControlWord
     *
     *   Author: $author$
     *     Date: 3/17/2004
     **********************************************************************
     */
    virtual eError OnBeginControlWord(TStream &stream)
    {
        enum
        {
            e_STATE_NAME,
            e_STATE_DIGIT
        } state=e_STATE_NAME;
        eError error=0;
        int c,count;

        if (0 > (count = m_control_word.Clear()))
            return -count;

        if (0 > (count = m_control_param.Clear()))
            return -count;

        if (0 > (c = stream.Getc()))
            return error;

        do
        {
            switch(state)
            {
            case e_STATE_NAME:
                do
                {
                    switch(c)
                    {
                    case '{':
                        if (0 < m_control_word.GetLength())
                        {
                            if ((error = OnEndControlWord(stream)))
                                return error;

                            error = OnBeginGroup(stream);
                            return error;
                        }
                        else
                        {
                            if (0 > (c = m_text.Putc(c)))
                                return -c;

                            return error;
                        }
                        break;

                    case '}':
                        if (0 < m_control_word.GetLength())
                        {
                            if ((error = OnEndControlWord(stream)))
                                return error;

                            error = OnEndGroup(stream);
                            return error;
                        }
                        else
                        {
                            if (0 > (c = m_text.Putc(c)))
                                return -c;

                            return error;
                        }
                        break;

                    case ' ':
                        error = OnEndControlWord(stream);
                        return error;
                        break;

                    case '-':
                        if (0 < m_control_word.GetLength())
                        {
                            if (0 > (c = m_control_word.Putc(c)))
                                return -c;

                            if (0 > (c = stream.Getc()))
                                return OnEndControlWord(stream);

                            state = e_STATE_DIGIT;
                        }
                        else
                        {
                            if (0 > (c = m_text.Putc(c)))
                                return -c;

                            return error;
                        }
                        break;

                    case '\\':
                        if (0 < m_control_word.GetLength())
                        {
                            if ((error = OnEndControlWord(stream)))
                                return error;

                            if (0 > (c = stream.Getc()))
                                return error;
                        }
                        else
                        {
                            if (0 > (c = m_text.Putc(c)))
                                return -c;

                            return error;
                        }
                        break;

                    default:
                        if (('a' <= c) && ('z' >= c))
                        {
                            if (0 > (c = m_control_word.Putc(c)))
                                return -c;
                        }
                        else if (('0' <= c) && ('9' >= c))
                        {
                            if (0 > (c = m_control_param.Putc(c)))
                                return -c;

                            state = e_STATE_DIGIT;
                        }
                        else
                        {
                            if ((error = OnEndControlWord(stream)))
                                return error;

                            if (0 > (c = m_text.Putc(c)))
                                return -c;

                            return error;
                        }

                        if (0 >  (c = stream.Getc()))
                            return OnEndControlWord(stream);
                    }
                }
                while (e_STATE_NAME == state);
                break;

            case e_STATE_DIGIT:
                do
                {
                    switch(c)
                    {
                    case '{':
                        if ((error = OnEndControlWord(stream)))
                            return error;

                        error = OnBeginGroup(stream);
                        return error;
                        break;

                    case '}':
                        if ((error = OnEndControlWord(stream)))
                            return error;

                        error = OnEndGroup(stream);
                        return error;
                        break;

                    case '\\':
                        if ((error = OnEndControlWord(stream)))
                            return error;

                        if (0 >  (c = stream.Getc()))
                            return error;

                        state = e_STATE_NAME;
                        break;

                    case ' ':
                        error = OnEndControlWord(stream);
                        return error;
                        break;

                    default:
                        if (('a' <= c) && ('z' >= c))
                        {
                            if (0 > (c = m_control_param.Putc(c)))
                                return -c;
                        }
                        else if (('0' <= c) && ('9' >= c))
                        {
                            if (0 > (c = m_control_param.Putc(c)))
                                return -c;
                        }
                        else
                        {
                            if ((error = OnEndControlWord(stream)))
                                return error;

                            if (0 > (c = m_text.Putc(c)))
                                return -c;

                            return error;
                        }

                        if (0 > (c = stream.Getc()))
                            return OnEndControlWord(stream);
                    }
                }
                while (e_STATE_DIGIT == state);
                break;
            }
        }
        while (0 <= c);

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
    virtual eError OnEndControlWord(TStream &stream)
    {
        eError error=0;
        const char *text;
        int length;

        m_output.Write("OnEndControlWord");

        if ((text = m_control_word.GetBuffer(length)))
        if (0 < length)
            m_output.WriteL(" \"", text, "\"", 0);

        if ((text = m_control_param.GetBuffer(length)))
        if (0 < length)
            m_output.WriteL(" \"", text, "\"", 0);

        m_output.Write("\n");

        if (0 > (length = m_control_word.Clear()))
            return -length;

        if (0 > (length = m_control_param.Clear()))
            return -length;

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
    virtual eError OnBeginGroup(TStream &stream)
    {
        eError error=0;

        m_output.Write("OnBeginGroup\n");
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
    virtual eError OnEndGroup(TStream &stream)
    {
        eError error=0;

        m_output.Write("OnEndGroup\n");
        return error;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 3/17/2004
     **********************************************************************
     */
    virtual eError On(TStream &stream)
    {
        eError error=0;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cRTFParser
 *
 * Author: $author$
 *   Date: 3/17/2004
 **********************************************************************
 */
class cRTFParser
: public cRTFParserT<cCharStream, cRTFParser>
{
public:
    typedef cRTFParserT<cCharStream, cRTFParser> cIs;

    /**
     **********************************************************************
     * Constructor: cRTFParser
     *
     *      Author: $author$
     *        Date: 3/17/2004
     **********************************************************************
     */
    cRTFParser(cCharStream &output)
    : cIs(output)
    {
    }
};

#endif /* ndef _CRTFPARSERT_HXX */
