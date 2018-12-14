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
 *   File: ccharbufferparameter.hxx
 *
 * Author: $author$
 *   Date: 12/15/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARBUFFERPARAMETER_HXX
#define _CCHARBUFFERPARAMETER_HXX

#include "clistt.hxx"
#include "ccharbuffer.hxx"

/**
 **********************************************************************
 *  Class: cCharBufferParameterT
 *
 * Author: $author$
 *   Date: 12/15/2003
 **********************************************************************
 */
template <class TAs, class TIs=cCharBuffer>
class cCharBufferParameterT
: public cListItemT<TAs, TIs>
{
public:
    typedef cListItemT<TAs, TIs> cIs;

    /**
     **********************************************************************
     *  Class: cList
     *
     * Author: $author$
     *   Date: 12/15/2003
     **********************************************************************
     */
    class cList
    : public cStaticListT<TAs, cList>
    {
    public:
        typedef cStaticListT<TAs, cList> cIs;
    };

    static cList m_list;

    TAs *m_as;
    const char *m_name;
    const char *&m_value;
    const char *m_old_value;
    bool m_changed;

    /**
     **********************************************************************
     * Constructor: cCharBufferParameterT
     *
     *      Author: $author$
     *        Date: 12/15/2003
     **********************************************************************
     */
    cCharBufferParameterT
    (TAs *as, const char *name, const char *&value) 
    : m_as(as),
      m_name(name),
      m_value(value),
      m_old_value(value),
      m_changed(false)
    {
        int count;
        eError error;

        if (value)
        {
            if (0 > (count = Write(value)))
                throw(error = -count);

            value = GetBuffer();
        }

        m_list.Add(m_as);
    }
    /**
     **********************************************************************
     * Constructor: cCharBufferParameterT
     *
     *      Author: $author$
     *        Date: 12/15/2003
     **********************************************************************
     */
    cCharBufferParameterT(TAs *as, const char *name) 
    : m_as(as),
      m_name(name),
      m_value(m_old_value),
      m_old_value(0),
      m_changed(false)
    {
        m_list.Add(m_as);
    }
    /**
     **********************************************************************
     * Destructor: ~cCharBufferParameterT
     *
     *     Author: $author$
     *       Date: 12/15/2003
     **********************************************************************
     */
    virtual ~cCharBufferParameterT()
    {
        m_list.Delete(m_as);

        if (&m_value != &m_old_value)
            m_value = m_old_value;
    }

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    eError SetValue(const char *value, int length=-1)
    {
        eError error = e_ERROR_FAILED;
        int count;

        if (0 <= (count = Copy(value, length)))
            error = UpdateValue();

        return error;
    }
    /**
     **********************************************************************
     * Function: ClearValue
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    eError ClearValue()
    {
        eError error = e_ERROR_FAILED;
        int count;

        if (0 <= (count = Clear()))
            error = UpdateValue();

        return error;
    }
    /**
     **********************************************************************
     * Function: UpdateValue
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    eError UpdateValue()
    {
        eError error = e_ERROR_FAILED;
        const char *value;

        if ((value = GetBuffer()))
        {
            m_value = value;
            error = e_ERROR_NONE;
            SetChanged(true);
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    const char *GetName() const
    {
        return m_name;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    const char *GetValue() const
    {
        return GetBuffer();
    }
    /**
     **********************************************************************
     * Function: SetChanged
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    bool SetChanged(bool changed=true)
    {
        m_changed = changed;
        return m_changed;
    }
    /**
     **********************************************************************
     * Function: GetChanged
     *
     *   Author: $author$
     *     Date: 12/15/2003
     **********************************************************************
     */
    bool GetChanged() const
    {
        return m_changed;
    }
};

/**
 **********************************************************************
 *  Class: cCharBufferParameter
 *
 * Author: $author$
 *   Date: 12/18/2003
 **********************************************************************
 */
class cCharBufferParameter
: public cCharBufferParameterT<cCharBufferParameter>
{
public:
    typedef cCharBufferParameterT<cCharBufferParameter> cIs;

    /**
     **********************************************************************
     * Constructor: cCharBufferParameter
     *
     *      Author: $author$
     *        Date: 12/18/2003
     **********************************************************************
     */
    cCharBufferParameter(const char *name, const char *&value) 
    : cIs(this, name, value) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cCharBufferParameter
     *
     *      Author: $author$
     *        Date: 12/18/2003
     **********************************************************************
     */
    cCharBufferParameter(const char *name) 
    : cIs(this, name) 
    {
    }
};

#endif /* ndef _CCHARBUFFERPARAMETER_HXX */
