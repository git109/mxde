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
 *   File: cccharstream.hxx
 *
 * Author: $author$
 *   Date: 11/27/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCCHARSTREAM_HXX
#define _CCCHARSTREAM_HXX

#include "cchar.hxx"
#include "cstream.hxx"
#include "cstreamt.hxx"
#include "cstreaminstance.hxx"
#include "cccharstreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cCCharStreamT
 *
 * Author: $author$
 *   Date: 11/27/2004
 **********************************************************************
 */
template <class TIs=cStream>
class cCCharStreamT
: public cStreamT<cChar, TIs>
{
public:
    typedef cStreamT<cChar, TIs> cIs;

};

/**
 **********************************************************************
 *  Class: cCCharStreamIs
 *
 * Author: $author$
 *   Date: 1/16/2006
 **********************************************************************
 */
class cCCharStreamIs
: virtual public cCCharStreamInterface,
  public cStreamInstance
{
public:
    typedef cStreamInstance cIs;
};

/**
 **********************************************************************
 *  Class: cCCharStream
 *
 * Author: $author$
 *   Date: 11/27/2004
 **********************************************************************
 */
class cCCharStream
: public cCCharStreamT<cCCharStreamIs>
{
public:
    typedef cCCharStreamT<cCCharStreamIs> cIs;

};

#endif /* ndef _CCCHARSTREAM_HXX */
