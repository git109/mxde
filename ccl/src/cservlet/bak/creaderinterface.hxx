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
 *   File: creaderinterface.hxx
 *
 * Author: $author$
 *   Date: 9/26/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CREADERINTERFACE_HXX
#define _CREADERINTERFACE_HXX

#include "cinterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cReaderInterfaceT
 *
 * Author: $author$
 *   Date: 9/26/2004
 **********************************************************************
 */
template <class TOf, class TIs=cInterface>
class c_INTERFACE_CLASS cReaderInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Reset
     *
     *   Author: $author$
     *     Date: 9/26/2004
     **********************************************************************
     */
    virtual int Reset() = 0;
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 9/26/2004
     **********************************************************************
     */
    virtual int Read(TOf *buf, int len=-1) = 0;
    /**
     **********************************************************************
     * Function: Skip
     *
     *   Author: $author$
     *     Date: 11/11/2004
     **********************************************************************
     */
    virtual int Skip(int len=-1) = 0;
};

/**
 **********************************************************************
 *  Class: cReaderImplementT
 *
 * Author: $author$
 *   Date: 9/26/2004
 **********************************************************************
 */
template <class TOf, class TIs=cReaderInterfaceT<TOf> >
class cReaderImplementT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Reset
     *
     *   Author: $author$
     *     Date: 9/26/2004
     **********************************************************************
     */
    virtual int Reset()
    {
        int len = -e_ERROR_NOT_IMPLEMENTED;
        return len;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 9/26/2004
     **********************************************************************
     */
    virtual int Read(TOf *buf, int len=-1)
    {
        int result = -e_ERROR_NOT_IMPLEMENTED;
        return result;
    }
    /**
     **********************************************************************
     * Function: Skip
     *
     *   Author: $author$
     *     Date: 11/11/2004
     **********************************************************************
     */
    virtual int Skip(int len=-1)
    {
        int count,result = 0;
        TOf c;

        if (len)
        {
            if (((int)sizeof(c)) > (count = Read(&c, sizeof(c))))
                return count;

            do
            {
                result += sizeof(c);

                if (0 < len)
                if (0 >= (len -= sizeof(c)))
                    break;

                if (((int)sizeof(c)) > (count = Read(&c, sizeof(c))))
                    break;
            }
            while (len);
        }

        return result;
    }
};

#endif /* ndef _CREADERINTERFACE_HXX */
