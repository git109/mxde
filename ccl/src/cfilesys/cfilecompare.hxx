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
 *   File: cfilecompare.hxx
 *
 * Author: $author$
 *   Date: 6/12/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CFILECOMPARE_HXX
#define _CFILECOMPARE_HXX

#include "cfilecompareimplement.hxx"

/**
 **********************************************************************
 *  Class: cFileCompareT
 *
 * Author: $author$
 *   Date: 6/12/2005
 **********************************************************************
 */
template
<class TIs=cInstance>
class cFileCompareT
: virtual public cFileCompareImplement,
  public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     * Constructor: cFileCompareT
     *
     *      Author: $author$
     *        Date: 6/12/2005
     **********************************************************************
     */
    cFileCompareT() 
    {
    }
    /**
     **********************************************************************
     * Function: CompareByFileTime
     *
     *   Author: $author$
     *     Date: 6/11/2005
     **********************************************************************
     */
    virtual int CompareByFileTime
    (cFileTimeSetInterface &to, 
     int type=cFileTimeInterface::e_TYPE_ANY)
    {
        int unequal = 1;
        return unequal;
    }
};

/**
 **********************************************************************
 *  Class: cFileCompare
 *
 * Author: $author$
 *   Date: 6/12/2005
 **********************************************************************
 */
class cFileCompare
: public cFileCompareT<cInstance>
{
public:
    typedef cFileCompareT<cInstance> cIs;

    /**
     **********************************************************************
     * Constructor: cFileCompare
     *
     *      Author: $author$
     *        Date: 6/12/2005
     **********************************************************************
     */
    cFileCompare() 
    {
    }
};

#endif /* _CFILECOMPARE_HXX */