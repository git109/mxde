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
 *   File: cinstance.hxx
 *
 * Author: $author$
 *   Date: 8/22/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CINSTANCE_HXX
#define _CINSTANCE_HXX

#include "ccharbuffer.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cInstanceBase
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cInstanceBase
{
public:
};

/**
 **********************************************************************
 *  Class: cInstance
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cInstance
: virtual public cInterface,
  virtual public cImplement
{
public:
    int m_hold_instance;

    /**
     **********************************************************************
     * Constructor: cInstance
     *
     *      Author: $author$
     *        Date: 8/22/2003
     **********************************************************************
     */
    cInstance(int hold_instance=0)
    : m_hold_instance(hold_instance)
    {
    }
    /**
     **********************************************************************
     * Function: HoldInstance
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual eError HoldInstance()
    {
        m_hold_instance++;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: FreeInstance
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual eError FreeInstance()
    {
        if (m_hold_instance>0)
        {
            --m_hold_instance;
            return e_ERROR_NONE;
        }
        return DeleteInstance();
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        return e_ERROR_NOT_ALLOWED;
    }
};

/**
 **********************************************************************
 *  Class: cErrorInstance
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cErrorInstance
: public cInstance
{
public:
    typedef cInstance cIs;

    eError m_error;
    cCharBuffer m_error_description;

    /**
     **********************************************************************
     * Constructor: cErrorInstance
     *
     *      Author: $author$
     *        Date: 8/22/2003
     **********************************************************************
     */
    cErrorInstance(eError error=e_ERROR_NONE, int hold_instance=0)
    : cIs(hold_instance),
      m_error(error) 
    {
    }
    /**
     **********************************************************************
     * Function: SetLastErrorL
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    eError SetLastErrorL
    (eError error, const char *description,...)
    {
        eError error2;
        va_list va;

        va_start(va, description);
        error2 = SetLastErrorV(error, description, va);
        va_end(va);
        return error2;
    }
    /**
     **********************************************************************
     * Function: SetLastErrorV
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    eError SetLastErrorV
    (eError error, const char *description, va_list va)
    {
        int count;
        cCharBuffer buffer;

        do
        {
            if (0 > (count = buffer.Write(description)))
                return count;
        }
        while ((description = va_arg(va, const char *)));

        return SetLastError(error, buffer.GetBuffer());
    }
    /**
     **********************************************************************
     * Function: SetLastError
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual eError SetLastError
    (eError error,const char *description=0)
    {
        int length;

        if (description)
        {
            if (0 > (length = m_error_description.Copy(description)))
                return -e_ERROR_COPY;
        }
        else if ((length = m_error_description.GetLength()) > 0)
        {
            if (0 > (length = m_error_description.Clear()))
                return -e_ERROR_CLEAR;
        }

        return m_error=error;
    }
    /**
     **********************************************************************
     * Function: GetLastError
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual eError GetLastError
    (const char *&description) const
    {
        eError error;
        const char *error_description;

        description = "";

        if ((error = m_error))
        if ((error_description = m_error_description.GetBuffer()))
            description = error_description;

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDynamicErrorInstance
 *
 * Author: $author$
 *   Date: 8/22/2003
 **********************************************************************
 */
class cDynamicErrorInstance
: public cErrorInstance
{
public:
    typedef cErrorInstance cIs;

    /**
     **********************************************************************
     * Constructor: cDynamicErrorInstance
     *
     *      Author: $author$
     *        Date: 8/22/2003
     **********************************************************************
     */
    cDynamicErrorInstance
    (eError error=e_ERROR_NONE, int hold_instance=0)
    : cIs(error, hold_instance) 
    {
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual eError DeleteInstance()=0;
};

#endif
