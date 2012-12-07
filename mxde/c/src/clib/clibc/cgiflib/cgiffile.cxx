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
 *   File: cgiffile.cxx
 *
 * Author: $author$
 *   Date: 11/4/2010
 **********************************************************************
 */
#include "cgiffile.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

    /**
     **********************************************************************
     * Function: cGifFileInterface::CreateInstance
     *
     *   Author: $author$
     *     Date: 11/14/2010
     **********************************************************************
     */
    cGifFileInterface* cGifFileInterface::CreateInstance
    (eError& error) 
    {
        cGifFileInterface* gif = 0;
        if ((gif = new cGifFile()))
            error = e_ERROR_NONE;
        else
        error = e_ERROR_FAILED;
        return gif;
    }
    /**
     **********************************************************************
     * Function: cGifFileInterface::DestroyInstance
     *
     *   Author: $author$
     *     Date: 11/14/2010
     **********************************************************************
     */
    eError cGifFileInterface::DestroyInstance
    (cGifFileInterface& gif) 
    {
        eError error = e_ERROR_FAILED;
        cGifFile* gifFile;
        if ((gifFile = (cGifFile*)(gif)))
        {
            delete gifFile;
            error = e_ERROR_NONE;
        }
        return error;
    }

#if defined(CGIFFILE_INSTANCE_TEST)
cGifFile g_cGifFile;
#endif /* defined(CGIFFILE_INSTANCE_TEST) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */
