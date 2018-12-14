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
 *   File: cerrort.hxx
 *
 * Author: $author$
 *   Date: 8/25/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CERRORT_HXX
#define _CERRORT_HXX

#include "cbase.hxx"
#include "ccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cErrorT
 *
 * Author: $author$
 *   Date: 8/25/2003
 **********************************************************************
 */
template <class TIs=cBase>
class cErrorT
: public TIs
{
public:
    typedef TIs cIs;

    eError m_error;
    cCharBuffer m_error_description;

    /**
     **********************************************************************
     * Constructor: cErrorT
     *
     *      Author: $author$
     *        Date: 8/25/2003
     **********************************************************************
     */
    cErrorT(eError error=e_ERROR_NONE, const char *description=0)
    : m_error(error) 
    {
        int length;

        if (description)
        if (0 > (length = m_error_description.Write(description)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Function: SetLastError
     *
     *   Author: $author$
     *     Date: 7/16/2003
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
     *     Date: 7/16/2003
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

#endif
