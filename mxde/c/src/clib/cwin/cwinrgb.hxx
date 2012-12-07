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
 *   File: cwinrgb.hxx
 *
 * Author: $author$
 *   Date: 5/24/2009
 **********************************************************************
 */
#ifndef _CWINRGB_HXX
#define _CWINRGB_HXX

#include "cwinbase.hxx"

/**
 **********************************************************************
 *  Class: cWinRGB
 *
 * Author: $author$
 *   Date: 5/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRGB
{
public:
    int m_value;

    /**
     **********************************************************************
     * Constructor: cWinRGB
     *
     *      Author: $author$
     *        Date: 5/24/2009
     **********************************************************************
     */
    cWinRGB
    (int value=0) 
    : m_value(value)
    {
    }
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual int SetValue
    (int value) 
    {
        m_value = value;
        return m_value;
    }
    /**
     **********************************************************************
     * Function: Value
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual int Value() const 
    {
        return m_value;
    }
};

/**
 **********************************************************************
 *  Class: cWinRED
 *
 * Author: $author$
 *   Date: 5/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRED
: public cWinRGB
{
public:
    typedef cWinRGB cExtends;
    /**
     **********************************************************************
     * Constructor: cWinRED
     *
     *      Author: $author$
     *        Date: 5/24/2009
     **********************************************************************
     */
    cWinRED
    (int value=0) 
    : cExtends(value)
    {
    }
};
/**
 **********************************************************************
 *  Class: cWinGREEN
 *
 * Author: $author$
 *   Date: 5/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinGREEN
: public cWinRGB
{
public:
    typedef cWinRGB cExtends;
    /**
     **********************************************************************
     * Constructor: cWinGREEN
     *
     *      Author: $author$
     *        Date: 5/24/2009
     **********************************************************************
     */
    cWinGREEN
    (int value=0) 
    : cExtends(value)
    {
    }
};
/**
 **********************************************************************
 *  Class: cWinBLUE
 *
 * Author: $author$
 *   Date: 5/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinBLUE
: public cWinRGB
{
public:
    typedef cWinRGB cExtends;
    /**
     **********************************************************************
     * Constructor: cWinBLUE
     *
     *      Author: $author$
     *        Date: 5/24/2009
     **********************************************************************
     */
    cWinBLUE
    (int value=0) 
    : cExtends(value)
    {
    }
};
#endif /* _CWINRGB_HXX */
