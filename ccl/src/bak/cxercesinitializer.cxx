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
 *   File: cxercesinitializer.cxx
 *
 * Author: $author$
 *   Date: 11/2/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "cxercesinitializer.hxx"

/*
 **********************************************************************
 *  Class: cXercesInitializerInterface
 *
 * Author: $author$
 *   Date: 11/3/2003
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: cXercesInitializerInterface::GetInstance
 *
 *      Author: $author$
 *        Date: 11/3/2003
 **********************************************************************
 */
cXercesInitializerInterface *
cXercesInitializerInterface::GetInstance(unsigned version)
{
    cXercesInitializer *instance;

    if ((instance = cXercesInitializer::m_instance))
    {
        eError error;

        if ((error = instance->HoldInstance()))
            instance = 0;
    }
    else instance = new cXercesInitializer;

    return instance;
}

/*
 **********************************************************************
 *  Class: cXercesInitializer
 *
 * Author: $author$
 *   Date: 11/2/2003
 **********************************************************************
 */

unsigned cXercesInitializer::m_instance_count = 0;
cXercesInitializer *cXercesInitializer::m_instance = 0;

/**
 **********************************************************************
 *    Function: cXercesInitializer::
 *
 *      Author: $author$
 *        Date: 11/2/2003
 **********************************************************************
 */
