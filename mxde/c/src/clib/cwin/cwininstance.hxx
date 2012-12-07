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
 *   File: cwininstance.hxx
 *
 * Author: $author$
 *   Date: 5/6/2009
 **********************************************************************
 */
#ifndef _CWININSTANCE_HXX
#define _CWININSTANCE_HXX

#include "cwinhinstance.hxx"

/**
 **********************************************************************
 *  Class: cWinInstance
 *
 * Author: $author$
 *   Date: 5/6/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinInstance
: public cWinHINSTANCEAttached
{
public:
    typedef cWinHINSTANCEAttached cExtends;
    typedef cWinInstance cDerives;
    /**
     **********************************************************************
     * Constructor: cWinInstance
     *
     *      Author: $author$
     *        Date: 5/6/2009
     **********************************************************************
     */
    cWinInstance
    (HINSTANCE hInstance=NULL) 
    : cExtends(hInstance)
    {
    }
};
#endif /* _CWININSTANCE_HXX */
