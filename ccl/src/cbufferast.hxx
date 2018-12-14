/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: cbufferast.hxx
 *
 * Author: $author$
 *   Date: 12/10/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CBUFFERAST_HXX
#define _CBUFFERAST_HXX

#include "cbuffert.hxx"

/**
 **********************************************************************
 *  Class: cBufferAsT
 *
 * Author: $author$
 *   Date: 12/10/2005
 **********************************************************************
 */
template 
<class TAs, int VDefaultSize, class TOf,
 int VNull=0, class TIs=cStreamT<TOf,cStream> >

class cBufferAsT
: public cBufferT<VDefaultSize, TOf, VNull, TIs>
{
public:
    typedef cBufferT<VDefaultSize, TOf, VNull, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cBufferAsT
     *
     *      Author: $author$
     *        Date: 12/10/2005
     **********************************************************************
     */
    cBufferAsT
    (const TOf *buffer=0, 
     int size=-1, int length=-1) 
    : cIs(buffer, size, length)
    {
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    int Write(const TAs& buffer, int length=-1) 
    {
        int count = -e_ERROR_FAILED;
        int buffer_length;
        const TOf* buffer_of;

        if ((buffer_of = buffer.GetBuffer(buffer_length)))
        {
            if ((0 > length) || (length > buffer_length))
                length = buffer_length;

            count = cIs::Write(buffer_of, length);
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 12/10/2005
     **********************************************************************
     */
    int Write(const TOf* buffer, int length=-1) 
    {
        int count = cIs::Write(buffer, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 10/30/2005
     **********************************************************************
     */
    int Compare(const TAs& buffer) const 
    {
        int unequal = -e_ERROR_FAILED-1;
        int length;
        const cChar* chars;

        if ((chars = buffer.GetBuffer(length)))
            unequal = cIs::Compare(chars, length);

        return unequal;
    }
};

#endif /* _CBUFFERAST_HXX */
