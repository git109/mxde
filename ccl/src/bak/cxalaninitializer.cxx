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
 *   File: cxalaninitializer.cxx
 *
 * Author: $author$
 *   Date: 11/3/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "cxalaninitializer.hxx"

/*
 **********************************************************************
 *  Class: cXalanInitializerInterface
 *
 * Author: $author$
 *   Date: 11/3/2003
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: cXalanInitializerInterface::GetInstance
 *
 *      Author: $author$
 *        Date: 11/3/2003
 **********************************************************************
 */
cXalanInitializerInterface *
cXalanInitializerInterface::GetInstance(unsigned version)
{
    cXalanInitializer *instance;

    if ((instance = cXalanInitializer::m_instance))
    {
        eError error;

        if ((error = instance->HoldInstance()))
            instance = 0;
    }
    else instance = new cXalanInitializer;

    return instance;
}

/*
 **********************************************************************
 *  Class: cXalanInitializer
 *
 * Author: $author$
 *   Date: 11/3/2003
 **********************************************************************
 */

unsigned cXalanInitializer::m_instance_count = 0;
cXalanInitializer *cXalanInitializer::m_instance = 0;

/**
 **********************************************************************
 *    Function: cXalanInitializer::
 *
 *      Author: $author$
 *        Date: 11/3/2003
 **********************************************************************
 */
