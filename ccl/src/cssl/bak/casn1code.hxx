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
 *   File: casn1code.hxx
 *
 * Author: $author$
 *   Date: 1/26/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CASN1CODE_HXX
#define _CASN1CODE_HXX

#include "platform.h"
#include "cbytestream.hxx"


/**
 **********************************************************************
 *  Class: cASN1Code
 *
 * Author: $author$
 *   Date: 1/26/2005
 **********************************************************************
 */
class cASN1Code
{
public:
    /**
     **********************************************************************
     * Enum: 
     *
     * Author: $author$
     *   Date: 1/26/2005
     **********************************************************************
     */
    enum
    {
        e_NONE  = -1,
        e_FIRST = 0,

        e_ALL,
        e_LAST = e_ALL-1
    };
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    int Copy(const cASN1Code &code)
    {
        int size = Sizeof();

        if (&code == this)
            return size = Sizeof();

        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    int Set()
    {
        int size = Sizeof();
        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    int Read(cBYTEStream &stream) 
    {
        int size;
        return size;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size;
        return size;
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size;
        return size;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    const char *GetName() const 
    {
        const char *name = 0;
        return name;
    }
    /**
     **********************************************************************
     * Operator: !=
     *
     *   Author: $author$
     *     Date: 1/26/2005
     **********************************************************************
     */
    int operator != (const cASN1Code &code) const
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CASN1CODE_HXX */
