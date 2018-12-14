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
 *   File: chttpformparameter.hxx
 *
 * Author: $author$
 *   Date: 12/30/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPFORMPARAMETER_HXX
#define _CHTTPFORMPARAMETER_HXX

#include "ccharbufferparameter.hxx"
#include "chttpform.hxx"

/**
 **********************************************************************
 *  Class: cHTTPFormParameter
 *
 * Author: $author$
 *   Date: 12/30/2003
 **********************************************************************
 */
class cHTTPFormParameter
: public cCharBufferParameterT<cHTTPFormParameter>
{
public:
    typedef cCharBufferParameterT<cHTTPFormParameter> cIs;

    int m_min_length;

    /**
     **********************************************************************
     * Constructor: cHTTPFormParameter
     *
     *      Author: $author$
     *        Date: 12/30/2003
     **********************************************************************
     */
    cHTTPFormParameter(const char *name, const char *&value, int min_length=0) 
    : cIs(this, name, value),
      m_min_length(min_length)
    {
    }
    /**
     **********************************************************************
     * Constructor: cHTTPFormParameter
     *
     *      Author: $author$
     *        Date: 12/30/2003
     **********************************************************************
     */
    cHTTPFormParameter(const char *name) 
    : cIs(this, name),
      m_min_length(0)
    {
    }

    /**
     **********************************************************************
     * Function: OnFormField
     *
     *   Author: $author$
     *     Date: 12/30/2003
     **********************************************************************
     */
    virtual eError OnFormField(cHTTPForm::cField &field)
    {
        eError error=0;
        const char *value;
        int length;

        if ((value = field.GetValue()))
        if (m_min_length <= (length = field.GetValueLength()))
            error = SetValue(value, length);

        return error;
    }
};

#endif /* ndef _CHTTPFORMPARAMETER_HXX */
