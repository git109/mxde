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
 *   File: chttpserializer.hxx
 *
 * Author: $author$
 *   Date: 2/8/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPSERIALIZER_HXX
#define _CHTTPSERIALIZER_HXX

#include "cinputstreamdeserializer.hxx"
#include "coutputstreamserializer.hxx"
#include "cinputstream.hxx"
#include "coutputstream.hxx"

/**
 **********************************************************************
 *  Class: cHttpSerializer
 *
 * Author: $author$
 *   Date: 2/8/2006
 **********************************************************************
 */
class cHttpSerializer
: public cOutputStreamSerializer
{
public:
    typedef cOutputStreamSerializer cIs;

    /**
     **********************************************************************
     * Constructor: cHttpSerializer
     *
     *      Author: $author$
     *        Date: 2/8/2006
     **********************************************************************
     */
    cHttpSerializer() 
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttpDeserializer
 *
 * Author: $author$
 *   Date: 2/10/2006
 **********************************************************************
 */
class cHttpDeserializer
: public cInputStreamDeserializer
{
public:
    typedef cInputStreamDeserializer cIs;

    /**
     **********************************************************************
     * Constructor: cHttpDeserializer
     *
     *      Author: $author$
     *        Date: 2/10/2006
     **********************************************************************
     */
    cHttpDeserializer() 
    {
    }
};

#endif /* _CHTTPSERIALIZER_HXX */


