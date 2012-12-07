/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: cstaicimagereaderlist.cxx
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
#include "cstaicimagereaderlist.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#if !defined(CSTAICIMAGEREADERLIST_INSTANCE_TEST)
cImageReaderItem* cStaicImageReaderList::cExtends::m_firstItem = 0;
cImageReaderItem* cStaicImageReaderList::cExtends::m_lastItem = 0;
cStaicImageReaderList cStaicImageReaderList::m_instance;
#endif /* defined(CSTAICIMAGEREADERLIST_INSTANCE_TEST) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */
