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
 *   File: casn1primative.hxx
 *
 * Author: $author$
 *   Date: 1/27/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CASN1PRIMATIVE_HXX
#define _CASN1PRIMATIVE_HXX

#include "platform.h"
#include "cbytestream.hxx"
#include "cbytebuffer.hxx"
#include "casn1typeof.hxx"
#include "casn1lengthof.hxx"

/**
 **********************************************************************
 *  Class: cASN1Primative
 *
 * Author: $author$
 *   Date: 1/27/2005
 **********************************************************************
 */
class cASN1Primative
{
public:
    cASN1Typeof m_typeof;
    cASN1Lengthof m_lengthof;
    cBYTEBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cASN1Primative
     *
     *      Author: $author$
     *        Date: 1/27/2005
     **********************************************************************
     */
    cASN1Primative
    (const BYTE *buffer=0, int size=-1, 
     unsigned typeof=cASN1Typeof::e_Any, 
     unsigned formof=cASN1Formof::e_Primative,
     unsigned classof=cASN1Classof::e_Universal) 
    {
        eError error;

        if (buffer)
        if (0 > (size = Set
            (buffer, size, typeof, formof, classof)))
            throw(error = -size);
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    int Copy(const cASN1Primative &primative)
    {
        int size = Sizeof();

        if (&primative == this)
            return size = Sizeof();

        return size;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    int Set
    (const BYTE *buffer, int size, 
     unsigned typeof=cASN1Typeof::e_Any, 
     unsigned formof=cASN1Formof::e_Primative,
     unsigned classof=cASN1Classof::e_Universal)
    {
        int length;

        if (0 > size)
            size = strlen((const char*)buffer);

        if (0 > (length = m_buffer.Copy(buffer, size)))
            return length;

        if (0 > (length = m_typeof.Set(typeof, formof, classof)))
            return length;

        if (0 > (length = m_lengthof.Set(size)))
            return length;

        return size;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/27/2005
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
     *     Date: 1/27/2005
     **********************************************************************
     */
    int Write(cBYTEStream &stream) const
    {
        int size;
        return size = Sizeof();
    }
    /**
     **********************************************************************
     * Function: Sizeof
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    int Sizeof() const 
    {
        int size = m_buffer.GetLength()+m_typeof.Sizeof()+m_lengthof.Sizeof();
        return size;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 1/27/2005
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
     *     Date: 1/27/2005
     **********************************************************************
     */
    int operator != (const cASN1Primative &primative) const
    {
        int unequal = 0;
        return unequal;
    }
};

#endif /* _CASN1PRIMATIVE_HXX */
