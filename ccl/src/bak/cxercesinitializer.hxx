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
 *   File: cxercesinitializer.hxx
 *
 * Author: $author$
 *   Date: 11/2/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXERCESINITIALIZER_HXX
#define _CXERCESINITIALIZER_HXX

#include <util/PlatformUtils.hpp>

#include "cimplement.hxx"
#include "cinterface.hxx"
#include "nsxerces.hxx"

/**
 **********************************************************************
 *  Class: cXercesInitializerInterface
 *
 * Author: $author$
 *   Date: 11/3/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cXercesInitializerInterface
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
    static cXercesInitializerInterface *GetInstance
    (unsigned version=c_INTERFACE_VERSION
     (e_INTERFACE_VERSION_MAJOR, e_INTERFACE_VERSION_MINOR));
};

/**
 **********************************************************************
 *  Class: cXercesInitializer
 *
 * Author: $author$
 *   Date: 11/2/2003
 **********************************************************************
 */
class cXercesInitializer
: virtual public cXercesInitializerInterface,
  public cDynamicImplement
{
public:
    static unsigned m_instance_count;
    static cXercesInitializer *m_instance;

    /**
     **********************************************************************
     * Constructor: cXercesInitializer
     *
     *      Author: $author$
     *        Date: 11/2/2003
     **********************************************************************
     */
    cXercesInitializer() 
    {
        eError error;

        if ((++m_instance_count)<2)
        try
        {
            nsXerces::XMLPlatformUtils::Initialize();
        }
        catch(const nsXerces::XMLException &)
        {
            throw(error = e_ERROR_INITIALIZE);
        }

        if (!m_instance)
            m_instance = this;
    }
    /**
     **********************************************************************
     * Destructor: ~cXercesInitializer
     *
     *     Author: $author$
     *       Date: 11/2/2003
     **********************************************************************
     */
    virtual ~cXercesInitializer()
    {
        eError error = e_ERROR_NOT_INSTANTIATED;

        if (this == m_instance)
            m_instance = 0;

        if (m_instance_count<1)
            throw(error);

        if ((--m_instance_count)<1)
        try
        {
            nsXerces::XMLPlatformUtils::Terminate();
        }
        catch(const nsXerces::XMLException &)
        {
            throw(error = e_ERROR_FINALIZE);
        }
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
