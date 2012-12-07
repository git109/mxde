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
 *   File: cplatform_io.hxx
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_IO_HXX
#define _CPLATFORM_IO_HXX

#include "cplatform_io.h"
#include "cerror.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Function: OModeToPlatform
 *
 *   Author: $author$
 *     Date: 2/21/2010
 **********************************************************************
 */
eError OModeToPlatform(MODE &pmode, eOMode mode);
/**
 **********************************************************************
 * Function: SModeToPlatform
 *
 *   Author: $author$
 *     Date: 2/21/2010
 **********************************************************************
 */
eError SModeToPlatform(MODE_T &pmode, eSMode mode);

/**
 **********************************************************************
 * Function: FlagsToPlatform
 *
 *   Author: $author$
 *     Date: 2/21/2010
 **********************************************************************
 */
eError FlagsToPlatform(int &pflags, int flags);
/**
 **********************************************************************
 * Function: FlagOnPlatform
 *
 *   Author: $author$
 *     Date: 2/21/2010
 **********************************************************************
 */
int FlagOnPlatform(int flag);
/**
 **********************************************************************
 * Function: FlagToPlatform
 *
 *   Author: $author$
 *     Date: 2/21/2010
 **********************************************************************
 */
int FlagToPlatform(int flag);
/**
 **********************************************************************
 * Function: ModesToPlatform
 *
 *   Author: $author$
 *     Date: 2/21/2010
 **********************************************************************
 */
eError ModesToPlatform(int &pmodes, int modes);
/**
 **********************************************************************
 * Function: ModeOnPlatform
 *
 *   Author: $author$
 *     Date: 2/21/2010
 **********************************************************************
 */
int ModeOnPlatform(int mode);
/**
 **********************************************************************
 * Function: ModeToPlatform
 *
 *   Author: $author$
 *     Date: 2/21/2010
 **********************************************************************
 */
int ModeToPlatform(int mode);

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CPLATFORM_IO_HXX */
