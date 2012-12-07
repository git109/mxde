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
 *   File: cjpegdecompress.cxx
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
#include "cjpegdecompress.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

    /**
     **********************************************************************
     *  Function: cJPEGDecompressInterface::CreateInstance
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    cJPEGDecompressInterface* 
    cJPEGDecompressInterface::CreateInstance
    (eError& error)
    {
        cJPEGDecompressInterface* jpeg;
        if ((jpeg = new cJPEGDecompress()))
            error = e_ERROR_NONE;
        else
        error = e_ERROR_FAILED;
        return jpeg;
    }
    /**
     **********************************************************************
     *  Function: cJPEGDecompressInterface::DestroyInstance
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    eError cJPEGDecompressInterface::DestroyInstance
    (cJPEGDecompressInterface& jpegInterface)
    {
        eError error = e_ERROR_FAILED;
        cJPEGDecompress* jpeg;
        if ((jpeg = (cJPEGDecompress*)(jpegInterface)))
        {
            delete jpeg;
            error = e_ERROR_NONE;
        }
        return error;
    }
    
#if defined(CJPEGDECOMPRESS_INSTANCE_TEST)
cJPEGDecompress g_cJPEGDecompress;
#endif /* defined(CJPEGDECOMPRESS_INSTANCE_TEST) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

