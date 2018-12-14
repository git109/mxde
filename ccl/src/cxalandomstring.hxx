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
 *   File: cxalandomstring.hxx
 *
 * Author: $author$
 *   Date: 12/11/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXALANDOMSTRING_HXX
#define _CXALANDOMSTRING_HXX

#include <XalanDOM/XalanDOMString.hpp>

#include "ccharstream.hxx"
#include "nsxalan.hxx"

/**
 **********************************************************************
 *  Class: cXalanDOMString
 *
 * Author: $author$
 *   Date: 12/11/2003
 **********************************************************************
 */
class cXalanDOMString
: public nsXalan::XalanDOMString
{
public:
    typedef nsXalan::XalanDOMString cIs;

    /**
     **********************************************************************
     * Constructor: cXalanDOMString
     *
     *      Author: $author$
     *        Date: 12/11/2003
     **********************************************************************
     */
    cXalanDOMString(const nsXalan::XalanDOMString &string) 
    : cIs(string) 
    {
    }

    /**
     **********************************************************************
     * Function: ToStream
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual int ToStream(cCharStream &stream) const
    {
        int count, result=0;
        CharVectorType char_vector=transcode();
        CharVectorType::const_iterator cvi=char_vector.begin();

        while (cvi != char_vector.end())
        {
            if (1 != (count = stream.Put(*cvi)))
                return count;

            result++;
            cvi++;
        }
        return result;
    }
};

#endif /* ndef _CXALANDOMSTRING_HXX */
