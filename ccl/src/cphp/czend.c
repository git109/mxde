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
 *   File: czend.c
 *
 * Author: $author$
 *   Date: 6/27/2004
 *
 *    $Id$
 **********************************************************************
 */
#include "czend.h"

/* declaration of functions to be exported */
ZEND_FUNCTION(czend);

/* compiled function list so Zend knows what's in this module */
zend_function_entry czend_functions[] =
{
    ZEND_FE(czend, NULL)
    {NULL, NULL, NULL}
};

/* compiled module information */
zend_module_entry czend_module_entry =
{
    STANDARD_MODULE_HEADER,
    "cZend",
    czend_functions,
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL,
    NO_VERSION_YET,
    STANDARD_MODULE_PROPERTIES
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#if COMPILE_DL_CZEND
ZEND_GET_MODULE(czend)
#endif

/* implement function that is meant to be made available to PHP */
ZEND_FUNCTION(czend)
{
    long parameter=ZEND_NUM_ARGS();

    if (FAILURE == zend_parse_parameters
        (ZEND_NUM_ARGS() TSRMLS_CC, "l", &parameter))
        return;

    RETURN_LONG(parameter+123);
}

/*
WIN32,NDEBUG,_WINDOWS,_MBCS,_USRDLL,ZTS,ZEND_DEBUG,ZEND_WIN32,PHP_WIN32,HAVE_CZEND,COMPILE_DL_CZEND
*/
