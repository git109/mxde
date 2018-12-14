/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: cdom.cxx
 *
 * Author: $author$
 *   Date: 12/2/2004
 *
 *    $Id$
 **********************************************************************
 */
#include "cdom.hxx"

/**
 **********************************************************************
 *  Class: cDOMNamespaceInerface
 *
 * Author: $author$
 *   Date: 12/7/2004
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cDOMNamespaceInerface::GetGlobalNamespace
 *
 *   Author: $author$
 *     Date: 11/30/2004
 **********************************************************************
 */
cDOMNamespaceInterface& cDOMNamespaceInterface::GetGlobalNamespace()
{
     return cDOMNamespace::GetGlobalNamespace();
}
/**
 **********************************************************************
 * Function: cDOMNamespaceInerface::GetGlobalNamespaceURI
 *
 *   Author: $author$
 *     Date: 11/30/2004
 **********************************************************************
 */
const cStringInterface& cDOMNamespaceInterface::GetGlobalNamespaceURI()
{
     return cDOMNamespace::GetGlobalNamespaceURI();
}

/**
 **********************************************************************
 *  Class: cDOMNamespace
 *
 * Author: $author$
 *   Date: 12/2/2004
 **********************************************************************
 */

cDOMNamespace cDOMNamespace::m_global_namespace;
cString cDOMNamespace::m_global_namespace_uri;
