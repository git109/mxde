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
 *   File: cimageinterfacelist.hxx
 *
 * Author: $author$
 *   Date: 1/22/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CIMAGEINTERFACELIST_HXX
#define _CIMAGEINTERFACELIST_HXX

#include "cimageinterface.hxx"
#include "clistt.hxx"

/**
 **********************************************************************
 *  Class: cImageInterfaceItem
 *
 * Author: $author$
 *   Date: 1/22/2006
 **********************************************************************
 */
class cImageInterfaceItem
: public cListItemT<cImageInterfaceItem>
{
public:
    typedef cListItemT<cImageInterfaceItem> cIs;

    cImageInterface& m_image;

    /**
     **********************************************************************
     * Constructor: cImageInterfaceItem
     *
     *      Author: $author$
     *        Date: 1/22/2006
     **********************************************************************
     */
    cImageInterfaceItem(cImageInterface& image) 
    : m_image(image) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cImageInterfaceItem
     *
     *     Author: $author$
     *       Date: 1/22/2006
     **********************************************************************
     */
    virtual ~cImageInterfaceItem() 
    {
    }
};

/**
 **********************************************************************
 *  Class: cImageInterfaceList
 *
 * Author: $author$
 *   Date: 1/22/2006
 **********************************************************************
 */
class cImageInterfaceList
: public cListT
  <cImageInterfaceItem, cImageInterfaceList>
{
public:
    typedef cListT
    <cImageInterfaceItem, cImageInterfaceList> cIs;

    /**
     **********************************************************************
     * Constructor: cImageInterfaceList
     *
     *      Author: $author$
     *        Date: 1/22/2006
     **********************************************************************
     */
    cImageInterfaceList() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cImageInterfaceList
     *
     *     Author: $author$
     *       Date: 1/22/2006
     **********************************************************************
     */
    virtual ~cImageInterfaceList() 
    {
    }
};

#endif /* _CIMAGEINTERFACELIST_HXX */
