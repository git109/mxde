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
 *   File: ctcharbuffer.hxx
 *
 * Author: $author$
 *   Date: 11/24/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTCHARBUFFER_HXX
#define _CTCHARBUFFER_HXX

#include "ctcharbuffert.hxx"
#include "ctcharstream.hxx"

#define CTCHARBUFFER_DEFAULT_SIZE 256

/**
 **********************************************************************
 *  Class: cTCHARBuffer
 *
 * Author: $author$
 *   Date: 11/24/2003
 **********************************************************************
 */
class cTCHARBuffer
: public cTCHARBufferT<CTCHARBUFFER_DEFAULT_SIZE, cTCHARStream>
{
public:
    typedef cTCHARBufferT<CTCHARBUFFER_DEFAULT_SIZE, cTCHARStream> cIs;

    /**
     **********************************************************************
     * Constructor: cTCHARBuffer
     *
     *      Author: $author$
     *        Date: 11/24/2003
     **********************************************************************
     */
    cTCHARBuffer(const TCHAR *buffer=0, int size=-1, int length=-1) 
    : cIs(buffer, size, length) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cTCHARBuffer
     *
     *      Author: $author$
     *        Date: 1/11/2006
     **********************************************************************
     */
    cTCHARBuffer(const char *buffer, int length=-1) 
    {
		eError error;

		if (buffer)
		if (0 > (length = Writec(buffer, length)))
			throw(error = -length);
    }
    /**
     **********************************************************************
     * Function: Copyc
     *
     *   Author: $author$
     *     Date: 1/11/2006
     **********************************************************************
     */
	virtual int Copyc(const char* buffer, int length=-1)
	{
		int count;

		if (0 > (count = Clear()))
			return count;

		length = Writec(buffer, length);
		return length;
	}
    /**
     **********************************************************************
     * Function: Writec
     *
     *   Author: $author$
     *     Date: 1/11/2006
     **********************************************************************
     */
	virtual int Writec(const char* buffer, int length=-1)
	{
		int count, remain;
		TCHAR tc;

		if (0 > length)
			length = strlen(buffer);

		for (remain=length; remain>0; --remain, ++buffer)
		{
			tc=*buffer;

			if (0 > (count = Put(tc)))
				return count;
		}
		return length;
	}
};

#endif /* ndef _CTCHARBUFFER_HXX */
