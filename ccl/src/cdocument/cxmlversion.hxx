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
 *   File: cxmlversion.hxx
 *
 * Author: $author$
 *   Date: 10/18/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXMLVERSION_HXX
#define _CXMLVERSION_HXX

#include "cinstance.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cXMLVersionInterface
 *
 * Author: $author$
 *   Date: 10/18/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLVersionInterface
: virtual public cInterface
{
public:

    /**
     **********************************************************************
     * Function: SetMajor
     *
     *   Author: $author$
     *     Date: 10/18/2005
     **********************************************************************
     */
    virtual eError SetMajor(unsigned version) = 0;
    /**
     **********************************************************************
     * Function: GetMajor
     *
     *   Author: $author$
     *     Date: 10/18/2005
     **********************************************************************
     */
    virtual int GetMajor() const = 0;

    /**
     **********************************************************************
     * Function: SetMinor
     *
     *   Author: $author$
     *     Date: 10/18/2005
     **********************************************************************
     */
    virtual eError SetMinor(unsigned version) = 0;
    /**
     **********************************************************************
     * Function: GetMinor
     *
     *   Author: $author$
     *     Date: 10/18/2005
     **********************************************************************
     */
    virtual int GetMinor() const = 0;
};

/**
 **********************************************************************
 *  Class: cXMLVersionImplement
 *
 * Author: $author$
 *   Date: 10/18/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMLVersionImplement
: virtual public cXMLVersionInterface
{
public:
    /**
     **********************************************************************
     * Function: SetMajor
     *
     *   Author: $author$
     *     Date: 10/18/2005
     **********************************************************************
     */
    virtual eError SetMajor(unsigned version) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetMajor
     *
     *   Author: $author$
     *     Date: 10/18/2005
     **********************************************************************
     */
    virtual int GetMajor() const 
    {
        int version = -e_ERROR_NOT_IMPLEMENTED;
        return version;
    }

    /**
     **********************************************************************
     * Function: SetMinor
     *
     *   Author: $author$
     *     Date: 10/18/2005
     **********************************************************************
     */
    virtual eError SetMinor(unsigned version) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetMinor
     *
     *   Author: $author$
     *     Date: 10/18/2005
     **********************************************************************
     */
    virtual int GetMinor() const 
    {
        int version = -e_ERROR_NOT_IMPLEMENTED;
        return version;
    }
};

/**
 **********************************************************************
 *  Class: cXMLVersion
 *
 * Author: $author$
 *   Date: 10/18/2005
 **********************************************************************
 */
class cXMLVersion
: virtual public cXMLVersionImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    unsigned m_major;
    unsigned m_minor;

    /**
     **********************************************************************
     * Constructor: cXMLVersion
     *
     *      Author: $author$
     *        Date: 10/18/2005
     **********************************************************************
     */
    cXMLVersion
    (unsigned major=1,
     unsigned minor=0) 
    : m_major(major),
      m_minor(minor)
    {
    }
    /**
     **********************************************************************
     * Function: GetMajor
     *
     *   Author: $author$
     *     Date: 10/18/2005
     **********************************************************************
     */
    virtual int GetMajor() const 
    {
        return m_major;
    }
    /**
     **********************************************************************
     * Function: GetMinor
     *
     *   Author: $author$
     *     Date: 10/18/2005
     **********************************************************************
     */
    virtual int GetMinor() const 
    {
        return m_minor;
    }
};

#endif /* _CXMLVERSION_HXX */
