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
 *   File: cxalaninitializer.hxx
 *
 * Author: $author$
 *   Date: 11/3/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXALANINITIALIZER_HXX
#define _CXALANINITIALIZER_HXX

#include <XalanTransformer/XalanTransformer.hpp>

#include "cxercesinitializer.hxx"
#include "cimplement.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cXalanInitializerInterface
 *
 * Author: $author$
 *   Date: 11/3/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cXalanInitializerInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     *   Enum:
     *
     * Author: $author$
     *   Date: 11/3/2003
     **********************************************************************
     */
    enum
    {
        e_INTERFACE_VERSION_MAJOR = 0,
        e_INTERFACE_VERSION_MINOR = 0
    };

    /**
     **********************************************************************
     * Function: GetInstance
     *
     *   Author: $author$
     *     Date: 11/3/2003
     **********************************************************************
     */
    static cXalanInitializerInterface *GetInstance
    (unsigned version=c_INTERFACE_VERSION
     (e_INTERFACE_VERSION_MAJOR, e_INTERFACE_VERSION_MINOR));
};

/**
 **********************************************************************
 *  Class: cXalanInitializer
 *
 * Author: $author$
 *   Date: 11/3/2003
 **********************************************************************
 */
class cXalanInitializer
: virtual public cXalanInitializerInterface,
  public cDynamicImplement
{
public:
    typedef cDynamicImplement cIs;

    static unsigned m_instance_count;
    static cXalanInitializer *m_instance;

    cXercesInitializerInterface *m_xerces_initializer;

    /**
     **********************************************************************
     * Constructor: cXalanInitializer
     *
     *      Author: $author$
     *        Date: 11/3/2003
     **********************************************************************
     */
    cXalanInitializer() 
    : cDynamicImplement(),
      m_xerces_initializer(0)
    {
        eError error;

        if (!(m_xerces_initializer = m_xerces_initializer->GetInstance()))
            throw(error = e_ERROR_GET_INSTANCE);

        if ((++m_instance_count)<2)
            XalanTransformer::initialize();

        if (!m_instance)
            m_instance = this;
    }
    /**
     **********************************************************************
     * Destructor: ~cXalanInitializer
     *
     *     Author: $author$
     *       Date: 11/3/2003
     **********************************************************************
     */
    virtual ~cXalanInitializer()
    {
        eError error;

        if (this == m_instance)
            m_instance = 0;

        if (m_instance_count<1)
            throw(error = e_ERROR_NOT_INSTANTIATED);

        if ((--m_instance_count)<1)
            XalanTransformer::terminate();

        if (m_xerces_initializer)
        if ((error = m_xerces_initializer->FreeInstance()))
            throw(error = e_ERROR_FREE_INSTANCE);
    }

    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 11/3/2003
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        delete this;
        return e_ERROR_NONE;
    }
};

#endif
