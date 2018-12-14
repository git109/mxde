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
 *   File: ccchartoxmlcharprinter.hxx
 *
 * Author: $author$
 *   Date: 10/17/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCCHARTOXMLCHARPRINTER_HXX
#define _CCCHARTOXMLCHARPRINTER_HXX

#include "ccharwriterinterface.hxx"
#include "cchar.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cCCharToXMLCharPrinterT
 *
 * Author: $author$
 *   Date: 10/17/2005
 **********************************************************************
 */
template
<class TIs=cBase>
class cCCharToXMLCharPrinterT
{
public:
    /**
     **********************************************************************
     * Constructor: cCCharToXMLCharPrinterT
     *
     *      Author: $author$
     *        Date: 10/17/2005
     **********************************************************************
     */
    cCCharToXMLCharPrinterT() 
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
     const cChar *chars, int length=-1,
     bool expand_amp=false) 
    {
        int count = 0;
        char pending = 0;
        int err;

        while (length)
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
            else if (c || (0 < length))
            {
                if (expand_amp && pending)
                {
                    switch(c)
                    {
                    case 0:
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

                if (c)
                if (0 > (err = writer.Putc(c)))
                    return -e_ERROR_FAILED;
            }
            else break;

            ++count;
            ++chars;

            if (0 < length)
                --length;
        }

        if (expand_amp && pending)
        {
            if (0 >= (err = writer.Write("&amp;")))
               return -e_ERROR_FAILED;
            count += err;
        }
        return count;
    }
};

/**
 **********************************************************************
 *  Class: cCCharToXMLCharPrinter
 *
 * Author: $author$
 *   Date: 10/17/2005
 **********************************************************************
 */
class cCCharToXMLCharPrinter
: public cCCharToXMLCharPrinterT<>
{
public:
    typedef cCCharToXMLCharPrinterT<> cIs;

    /**
     **********************************************************************
     * Constructor: cCCharToXMLCharPrinter
     *
     *      Author: $author$
     *        Date: 10/17/2005
     **********************************************************************
     */
    cCCharToXMLCharPrinter() 
    {
    }
};

#endif /* _CCCHARTOXMLCHARPRINTER_HXX */
