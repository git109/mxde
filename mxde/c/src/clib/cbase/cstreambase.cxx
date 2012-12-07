/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cstreambase.cxx
 *
 * Author: $author$
 *   Date: 3/2/2009
 **********************************************************************
 */
#include "cstreambase.hxx"

/**
 **********************************************************************
 *  Class: cStreamBaseT
 *
 * Author: $author$
 *   Date: 3/2/2009
 **********************************************************************
 */
#if defined(CSTREAMBASE_INSTANCE_TEST) 
cStreamBase g_cStreamBase;
cTCHARStreamBase g_cTCHARStreamBase;
cWCHARStreamBase g_cWCHARStreamBase;
#endif /* defined(CSTREAMBASE_INSTANCE_TEST) */
