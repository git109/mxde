/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cstreamserializerinterfacet.hxx
 *
 * Author: $author$
 *   Date: 2/15/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CSTREAMSERIALIZERINTERFACET_HXX
#define _CSTREAMSERIALIZERINTERFACET_HXX

#include "cinitializerinterface.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cStreamSerializerInterfaceT
 *
 * Author: $author$
 *   Date: 2/15/2006
 **********************************************************************
 */
template
<class TStream, class TStreamOf, 
 class TLength=int, TLength VNullLength=-1,
 class TIs=cInitializerInterface>

class c_INTERFACE_CLASS cStreamSerializerInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Serialize
     *
     *   Author: $author$
     *     Date: 2/13/2006
     **********************************************************************
     */
    virtual int Serialize
    (TStream& output,
     const TStreamOf *endchars=0, 
     TLength endchars_length=VNullLength) = 0;
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual int Get(TStreamOf& of) = 0;
};

/**
 **********************************************************************
 *  Class: cStreamSerializerImplementT
 *
 * Author: $author$
 *   Date: 2/19/2006
 **********************************************************************
 */
template
<class TStream, class TStreamOf, 
 class TLength, TLength VNullLength,
 class TIs>

class cStreamSerializerImplementT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Serialize
     *
     *   Author: $author$
     *     Date: 2/13/2006
     **********************************************************************
     */
    virtual int Serialize
    (TStream& output,
     const TStreamOf *endchars=0, 
     TLength endchars_length=VNullLength)
    {
        int count, length = 0;
        TStreamOf c;
        eError error;

        if ((error = Initialize()))
            return length = -error;

        while (0 <= (count = Get(c)))
        {
            length++;

            if (0 > (count = output.Write(&c, sizeof(TStreamOf))))
                return count;
        }

        if ((0 <= length) && endchars)
        {
            if (0 > (count = output.Write
                (endchars, endchars_length)))
                return count;

            length += count;
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual int Get(TStreamOf& of)
    {
        int result = 0;
        return result;
    }
};

#endif /* _CSTREAMSERIALIZERINTERFACET_HXX */
