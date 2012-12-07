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
 *   File: ctiff.cxx
 *
 * Author: $author$
 *   Date: 12/24/2009
 **********************************************************************
 */
#include "ctiff.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cTIFFInterface
 *
 * Author: $author$
 *   Date: 12/27/2009
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cTIFFInterface::CreateInstance
 *
 *   Author: $author$
 *     Date: 12/27/2009
 **********************************************************************
 */
cTIFFInterface* cTIFFInterface::CreateInstance
(eError& error) 
{
    cTIFFInterface* tiff;
    if ((tiff = new cTIFF()))
        error = e_ERROR_NONE;
    else
    error = e_ERROR_NEW;
    return tiff;
}
/**
 **********************************************************************
 * Function: cTIFFInterface::DestroyInstance
 *
 *   Author: $author$
 *     Date: 12/27/2009
 **********************************************************************
 */
eError cTIFFInterface::DestroyInstance
(cTIFFInterface& tiff) 
{
    eError error = tiff.DeleteInstance();
    return error;
}

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */
