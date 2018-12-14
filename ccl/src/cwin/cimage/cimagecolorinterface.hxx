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
 *   File: cimagecolorinterface.hxx
 *
 * Author: $author$
 *   Date: 1/22/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CIMAGECOLORINTERFACE_HXX
#define _CIMAGECOLORINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cImageColorInterface
 *
 * Author: $author$
 *   Date: 1/22/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageColorInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: SetRed
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int SetRed
    (int level) = 0;
    /**
     **********************************************************************
     * Function: GetRed
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int GetRed
    () const = 0;
    /**
     **********************************************************************
     * Function: SetGreen
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int SetGreen
    (int level) = 0;
    /**
     **********************************************************************
     * Function: GetGreen
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int GetGreen
    () const = 0;
    /**
     **********************************************************************
     * Function: SetBlue
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int SetBlue
    (int level) = 0;
    /**
     **********************************************************************
     * Function: GetBlue
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int GetBlue
    () const = 0;
    /**
     **********************************************************************
     * Function: SetOpacity
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int SetOpacity
    (int level) = 0;
    /**
     **********************************************************************
     * Function: GetOpacity
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int GetOpacity
    () const = 0;
};

/**
 **********************************************************************
 *  Class: cImageColorImplement
 *
 * Author: $author$
 *   Date: 1/22/2006
 **********************************************************************
 */
class cImageColorImplement
: virtual public cImageColorInterface
{
public:
    /**
     **********************************************************************
     * Function: SetRed
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int SetRed
    (int level) 
    {
        int old_level = -e_ERROR_NOT_IMPLEMENTED;
        return old_level;
    }
    /**
     **********************************************************************
     * Function: GetRed
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int GetRed
    () const 
    {
        int old_level = -e_ERROR_NOT_IMPLEMENTED;
        return old_level;
    }
    /**
     **********************************************************************
     * Function: SetGreen
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int SetGreen
    (int level) 
    {
        int old_level = -e_ERROR_NOT_IMPLEMENTED;
        return old_level;
    }
    /**
     **********************************************************************
     * Function: GetGreen
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int GetGreen
    () const 
    {
        int old_level = -e_ERROR_NOT_IMPLEMENTED;
        return old_level;
    }
    /**
     **********************************************************************
     * Function: SetBlue
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int SetBlue
    (int level) 
    {
        int old_level = -e_ERROR_NOT_IMPLEMENTED;
        return old_level;
    }
    /**
     **********************************************************************
     * Function: GetBlue
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int GetBlue
    () const 
    {
        int old_level = -e_ERROR_NOT_IMPLEMENTED;
        return old_level;
    }
    /**
     **********************************************************************
     * Function: SetOpacity
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int SetOpacity
    (int level) 
    {
        int old_level = -e_ERROR_NOT_IMPLEMENTED;
        return old_level;
    }
    /**
     **********************************************************************
     * Function: GetOpacity
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int GetOpacity
    () const 
    {
        int old_level = -e_ERROR_NOT_IMPLEMENTED;
        return old_level;
    }
};

#endif /* _CIMAGECOLORINTERFACE_HXX */
