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
 *   File: coutputt.hxx
 *
 * Author: $author$
 *   Date: 11/25/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _COUTPUTT_HXX
#define _COUTPUTT_HXX

#include <stdarg.h>

#include "ccharstreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cOutputT
 *
 * Author: $author$
 *   Date: 11/25/2003
 **********************************************************************
 */
template <class TIs=cBase>
class cOutputT
: public TIs
{
public:
    typedef TIs cIs;

    cCharStreamInterface *m_out, *m_err;

    /**
     **********************************************************************
     * Constructor: cOutputT
     *
     *      Author: $author$
     *        Date: 11/25/2003
     **********************************************************************
     */
    cOutputT
    (cCharStreamInterface *out=0,
     cCharStreamInterface *err=0)
    : m_out(out),
      m_err(err)
    {
    }


    /**
     **********************************************************************
     * Function: SetOut
     *
     *   Author: $author$
     *     Date: 10/8/2004
     **********************************************************************
     */
    virtual cCharStreamInterface* SetOut
    (cCharStreamInterface* stream) 
    {
        cCharStreamInterface* old_stream = m_out;
        m_out = stream;
        return old_stream;
    }

    /**
     **********************************************************************
     * Function: GetOut
     *
     *   Author: $author$
     *     Date: 10/8/2004
     **********************************************************************
     */
    virtual cCharStreamInterface* GetOut() const
    {
        cCharStreamInterface* stream = m_out;
        return stream;
    }

    /**
     **********************************************************************
     * Function: SetErr
     *
     *   Author: $author$
     *     Date: 10/8/2004
     **********************************************************************
     */
    virtual cCharStreamInterface* SetErr
    (cCharStreamInterface* stream) 
    {
        cCharStreamInterface* old_stream = m_err;
        m_err = stream;
        return old_stream;
    }
    /**
     **********************************************************************
     * Function: GetErr
     *
     *   Author: $author$
     *     Date: 10/8/2004
     **********************************************************************
     */
    virtual cCharStreamInterface* GetErr() const
    {
        cCharStreamInterface* stream = m_err;
        return stream;
    }

    /**
     **********************************************************************
     * Function: OutputErrorL
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual int OutputErrorL(const char *buffer, ...)
    {
        int count, count2;
        va_list va;

        va_start(va, buffer);

        if (0 <= (count = OutputError(buffer)))
        if (0 <= (count2 = VOutputError(va)))
            count += count2;
        else count = count2;

        va_end(va);
        return count;
    }
    /**
     **********************************************************************
     * Function: VOutputError
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual int VOutputError(va_list va)
    {
        int count, count2;
        const char *buffer;

        for (count = 0; 0 != (buffer = va_arg(va, const char *)); count += count2)
            if (0 > (count2 = OutputError(buffer)))
                return count2;

        return count;
    }
    /**
     **********************************************************************
     * Function: OutputError
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual int OutputError(const char *buffer, int length=-1)
    {
        if (m_err)
            return m_err->Write(buffer, length);

        return -e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: OutputL
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual int OutputL(const char *buffer, ...)
    {
        int count, count2;
        va_list va;

        va_start(va, buffer);

        if (0 <= (count = Output(buffer)))
        if (0 <= (count2 = VOutput(va)))
            count += count2;
        else count = count2;

        va_end(va);
        return count;
    }
    /**
     **********************************************************************
     * Function: VOutput
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual int VOutput(va_list va)
    {
        int count, count2;
        const char *buffer;

        for (count = 0; 0 != (buffer = va_arg(va, const char *)); count += count2)
            if (0 > (count2 = Output(buffer)))
                return count2;

        return count;
    }
    /**
     **********************************************************************
     * Function: Output
     *
     *   Author: $author$
     *     Date: 11/25/2003
     **********************************************************************
     */
    virtual int Output(const char *buffer, int length=-1)
    {
        if (m_out)
            return m_out->Write(buffer, length);

        return -e_ERROR_FAILED;
    }
};

#endif /* ndef _COUTPUTT_HXX */
