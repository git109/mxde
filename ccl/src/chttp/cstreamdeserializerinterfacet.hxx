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
 *   File: cstreamdeserializerinterfacet.hxx
 *
 * Author: $author$
 *   Date: 2/15/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CSTREAMDESERIALIZERINTERFACET_HXX
#define _CSTREAMDESERIALIZERINTERFACET_HXX

#include "cinitializerinterface.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cStreamDeserializerInterfaceT
 *
 * Author: $author$
 *   Date: 2/15/2006
 **********************************************************************
 */
template
<class TStream, class TStreamOf, 
 class TLength=int, TLength VNullLength=-1,
 class TEndChar=int, TEndChar VNullEndChar=-1, 
 class TIs=cInitializerInterface>

class c_INTERFACE_CLASS cStreamDeserializerInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Deserialize
     *
     *   Author: $author$
     *     Date: 2/4/2006
     **********************************************************************
     */
    virtual int Deserialize
    (TStream& input, 
     TLength length=VNullLength, 
     TEndChar endchar=VNullEndChar) = 0;
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual int Put(TStreamOf& of) = 0;

    /**
     **********************************************************************
     * Function: SetIsDone
     *
     *   Author: $author$
     *     Date: 2/17/2006
     **********************************************************************
     */
    virtual bool SetIsDone(bool is_done=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsDone
     *
     *   Author: $author$
     *     Date: 2/17/2006
     **********************************************************************
     */
    virtual bool GetIsDone() const = 0;
};

/**
 **********************************************************************
 *  Class: cStreamDeserializerImplementT
 *
 * Author: $author$
 *   Date: 2/15/2006
 **********************************************************************
 */
template
<class TStream, class TStreamOf, 
 class TLength, TLength VNullLength,
 class TEndChar, TEndChar VNullEndChar, 
 class TIs>

class cStreamDeserializerImplementT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Deserialize
     *
     *   Author: $author$
     *     Date: 2/4/2006
     **********************************************************************
     */
    virtual int Deserialize
    (TStream& input, 
     TLength length=VNullLength, 
     TEndChar endchar=VNullEndChar)
    {
        int result = 0;
        int count;
        TStreamOf c;
        eError error;

        if ((error = Initialize()))
            return result = -error;

        if (VNullLength != length)
        {
            do
            {
                if (0 >= (count = input.Read(&c, sizeof(c))))
                    break;

                if (VNullEndChar != endchar)
                if (c == endchar)
                    break;

                result++;

                if (0 > (count = Put(c)))
                    break;
            }
            while(--length);
        }
        else
        {
            while (0 < (count = input.Read(&c, sizeof(c))))
            {
                if (VNullEndChar != endchar)
                if (c == endchar)
                    break;

                result++;

                if (0 > (count = Put(c)))
                    break;

                if (GetIsDone())
                    break;
            }
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 2/5/2006
     **********************************************************************
     */
    virtual int Put(TStreamOf& of)
    {
        int result = 0;
        return result;
    }

    /**
     **********************************************************************
     * Function: SetIsDone
     *
     *   Author: $author$
     *     Date: 2/17/2006
     **********************************************************************
     */
    virtual bool SetIsDone(bool is_done=true) 
    {
        return is_done;
    }
    /**
     **********************************************************************
     * Function: GetIsDone
     *
     *   Author: $author$
     *     Date: 2/17/2006
     **********************************************************************
     */
    virtual bool GetIsDone() const
    {
        bool is_done = false;
        return is_done;
    }
};

#endif /* _CSTREAMDESERIALIZERINTERFACET_HXX */


