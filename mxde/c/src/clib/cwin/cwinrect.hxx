/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cwinrect.hxx
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
#ifndef _CWINRECT_HXX
#define _CWINRECT_HXX

#include "cwinbase.hxx"

/**
 **********************************************************************
 *  Class: cWinRECT
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
class cWinRECT
: public RECT
{
public:
    typedef RECT cExtends;
    typedef cWinRECT cDerives;
    /**
     **********************************************************************
     * Constructor: cWinRECT
     *
     *      Author: $author$
     *        Date: 5/28/2009
     **********************************************************************
     */
    inline cWinRECT
    (LONG p_left=0, LONG p_top=0, 
     LONG p_right=0, LONG p_bottom=0) 
    {
        left = p_left;
        top = p_top;
        right = p_right;
        bottom = p_bottom;
    }
};
#endif /* _CWINRECT_HXX */
